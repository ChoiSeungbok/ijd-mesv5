
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
    "DBC_wipcore_join.pc"
};


static unsigned int sqlctx = 36630907;


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
            void  *sqhstv[142];
   unsigned int   sqhstl[142];
            int   sqhsts[142];
            void  *sqindv[142];
            int   sqinds[142];
   unsigned int   sqharm[142];
   unsigned int   *sqharc[142];
   unsigned short  sqadto[142];
   unsigned short  sqtdso[142];
} sqlstm = {13,142};

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
":b0 and MAT_ID=:b1) and MAT_VER=:b2)\
 and OPT_LEVEL='1')) CD where ((((FOL.FACTORY=CD.FACTORY(+) and FOL.FLOW=CD.F\
LOW(+)) and FOL.FLOW_SEQ=CD.FLOW_SEQ_NUM(+)) and FOL.OPER=CD.OPER(+)) and ((F\
OL.FLOW_SEQ=:b6 and FOL.OPER_SEQ>=:b7) or FOL.FLOW_SEQ>:b6)) order by FOL.FLO\
W_SEQ asc ,FOL.OPER_SEQ asc             ";

 static const char *sq0002 = 
"select NVL(FO.OPER,' ') OPER ,NVL(FO.SEQ_NUM,0) OPER_SEQ ,NVL(OD.OPER_DESC,\
' ') OPER_DESC ,NVL(CD.OPT_LEVEL,' ') OPT_LEVEL ,NVL(CD.QUEUE_TIME,0) QUEUE_T\
IME ,NVL(CD.PROC_TIME,0) PROC_TIME ,NVL(CD.HPU_FLAG,' ') HPU_FLAG ,NVL(CD.HPU\
_PROC_TIME,0) HPU_PROC_TIME ,NVL(CD.UPH_FLAG,' ') UPH_FLAG ,NVL(CD.UPH_PROC_T\
IME,0) UPH_PROC_TIME ,NVL(CD.CREATE_USER_ID,' ') CREATE_USER_ID ,NVL(CD.CREAT\
E_TIME,' ') CREATE_TIME ,NVL(CD.UPDATE_USER_ID,' ') UPDATE_USER_ID ,NVL(CD.UP\
DATE_TIME,' ') UPDATE_TIME  from MWIPOPRDEF OD ,MWIPFLWOPR FO ,(select *  fro\
m MWIPCYTDEF where ((FACTORY=:b0 and FLOW=:b1) and OPT_LEVEL='2')) CD where (\
((((((FO.FACTORY=:b0 and FO.FLOW=:b1) and FO.SEQ_NUM>=:b4) and FO.FACTORY=OD.\
FACTORY) and FO.OPER=OD.OPER) and FO.FACTORY=CD.FACTORY(+)) and FO.FLOW=CD.FL\
OW(+)) and FO.OPER=CD.OPER(+)) order by FO.SEQ_NUM asc             ";

 static const char *sq0003 = 
"select NVL(OD.OPER,' ') OPER ,NVL(OD.OPER_DESC,' ') OPER_DESC ,NVL(CD.OPT_L\
EVEL,' ') OPT_LEVEL ,NVL(CD.QUEUE_TIME,0) QUEUE_TIME ,NVL(CD.PROC_TIME,0) PRO\
C_TIME ,NVL(CD.HPU_FLAG,' ') HPU_FLAG ,NVL(CD.HPU_PROC_TIME,0) HPU_PROC_TIME \
,NVL(CD.UPH_FLAG,' ') UPH_FLAG ,NVL(CD.UPH_PROC_TIME,0) UPH_PROC_TIME ,NVL(CD\
.CREATE_USER_ID,' ') CREATE_USER_ID ,NVL(CD.CREATE_TIME,' ') CREATE_TIME ,NVL\
(CD.UPDATE_USER_ID,' ') UPDATE_USER_ID ,NVL(CD.UPDATE_TIME,' ') UPDATE_TIME  \
from MWIPOPRDEF OD ,(select *  from MWIPCYTDEF where (FACTORY=:b0 and OPT_LEV\
EL='3')) CD where (((OD.FACTORY=:b0 and OD.OPER>=:b2) and OD.FACTORY=CD.FACTO\
RY(+)) and OD.OPER=CD.OPER(+)) order by OD.OPER asc             ";

 static const char *sq0004 = 
":b0 and MAT_ID=:b1) and MAT_VER=:b2)\
 and OPT_LEVEL='1')) CD where (((FOL.FACTORY=CD.FACTORY(+) and FOL.FLOW=CD.FL\
OW(+)) and FOL.OPER=CD.OPER(+)) and ((FOL.FLOW_SEQ=:b6 and FOL.OPER_SEQ>=:b7)\
 or FOL.FLOW_SEQ>:b6)) order by FOL.FLOW_SEQ asc ,FOL.OPER_SEQ asc           \
  ";

 static const char *sq0006 = 
".YIELD_2 ,LT.YIELD_3 ,LT.GOOD_QTY ,L\
T.RESV_FIELD_1 ,LT.RESV_FIELD_2 ,LT.RESV_FIELD_3 ,LT.RESV_FIELD_4 ,LT.RESV_FI\
ELD_5 ,LT.RESV_FLAG_1 ,LT.RESV_FLAG_2 ,LT.RESV_FLAG_3 ,LT.RESV_FLAG_4 ,LT.RES\
V_FLAG_5 ,MT.MAT_DESC ,FT.FLOW_DESC ,OT.OPER_DESC  from MWIPLOTSTS LT ,MWIPMA\
TDEF MT ,MWIPFLWDEF FT ,MWIPOPRDEF OT where (((((((((((LT.FACTORY=MT.FACTORY(\
+) and LT.MAT_ID=MT.MAT_ID(+)) and LT.MAT_VER=MT.MAT_VER(+)) and LT.FACTORY=F\
T.FACTORY(+)) and LT.FLOW=FT.FLOW(+)) and LT.FACTORY=OT.FACTORY(+)) and LT.OP\
ER=OT.OPER(+)) and LT.FACTORY=:b0) and LT.START_RES_ID=:b1) and LT.START_FLAG\
='Y') and LT.LOT_DEL_FLAG=' ') and LT.LOT_ID>=:b2) order by LT.LOT_ID asc    \
         ";

 static const char *sq0007 = 
"select F.FACTORY ,F.FLOW ,F.OPER ,O.OPER_DESC ,F.OPT_OPER_GROUP ,F.OPT_OPER\
_OPTION_FLAG  from MWIPFLWOPR F ,MWIPOPRDEF O where (((F.FACTORY=:b0 and F.FA\
CTORY=O.FACTORY) and F.FLOW=:b1) and F.OPER=O.OPER) order by F.SEQ_NUM asc   \
          ";

 static const char *sq0008 = 
"select LOT.LOT_ID ,LOT.QTY_1 ,LOT.QTY_2 ,LOT.QTY_3 ,sum(DECODE(CRR.CRR_ID,:\
b0,CRR.QTY_1,0)) CRR1_QTY_1 ,sum(DECODE(CRR.CRR_ID,:b0,CRR.QTY_2,0)) CRR1_QTY\
_2 ,sum(DECODE(CRR.CRR_ID,:b0,CRR.QTY_3,0)) CRR1_QTY_3 ,sum(CRR.QTY_1) CRR2_Q\
TY_1 ,sum(CRR.QTY_2) CRR2_QTY_2 ,sum(CRR.QTY_3) CRR2_QTY_3  from MWIPLOTSTS L\
OT ,MWIPCRRLOT CRR where (((CRR.FACTORY=:b3 and LOT.LOT_ID=CRR.LOT_ID) and LO\
T.LOT_DEL_FLAG=' ') and LOT.LOT_ID in (select LOT_ID  from MWIPCRRLOT where (\
CRR_ID=:b0 and LOT_ID>=:b5))) group by LOT.LOT_ID,LOT.QTY_1,LOT.QTY_2,LOT.QTY\
_3 order by LOT.LOT_ID            ";

 static const char *sq0009 = 
"select *  from (select ROWNUM ROWSEQ ,FOL.*  from (select MF.FLOW ,FD.FLOW_\
DESC ,FO.OPER ,OD.OPER_DESC ,min(MF.FLOW_SEQ_NUM) FLOW_SEQ ,min(FO.SEQ_NUM) O\
PER_SEQ  from MWIPOPRDEF OD ,MWIPFLWOPR FO ,MWIPMATFLW MF ,MWIPFLWDEF FD wher\
e ((((((((FO.FACTORY=OD.FACTORY and FO.OPER=OD.OPER) and FO.FACTORY=FD.FACTOR\
Y) and FO.FLOW=FD.FLOW) and MF.FACTORY=FO.FACTORY) and MF.FLOW=FO.FLOW) and M\
F.FACTORY=:b0) and MF.MAT_ID=:b1) and MF.MAT_VER=:b2) group by MF.FLOW,FD.FLO\
W_DESC,FO.OPER,OD.OPER_DESC order by FLOW_SEQ asc ,OPER_SEQ asc  ) FOL ) wher\
e ROWSEQ>=:b3 order by ROWSEQ asc             ";

 static const char *sq0010 = 
"select FO.OPER ,OD.OPER_DESC ,FO.SEQ_NUM ,FO.SEQ_NUM  from MWIPOPRDEF OD ,M\
WIPFLWOPR FO where ((((FO.FACTORY=OD.FACTORY and FO.OPER=OD.OPER) and OD.FACT\
ORY=:b0) and FO.FLOW=:b1) and FO.SEQ_NUM>=:b2) order by FO.SEQ_NUM asc       \
      ";

 static const char *sq0011 = 
"select *  from (select ROWNUM ROWSEQ ,OL.*  from (select OPER ,OPER_DESC  f\
rom MWIPOPRDEF where FACTORY=:b0 order by OPER asc  ) OL ) where ROWSEQ>=:b1 \
order by ROWSEQ asc             ";

 static const char *sq0012 = 
"select *  from (select ROWNUM ROWSEQ ,FOL.*  from (select MF.FLOW ,FD.FLOW_\
DESC ,FO.OPER ,OD.OPER_DESC ,MF.FLOW_SEQ_NUM ,FO.SEQ_NUM  from MWIPOPRDEF OD \
,MWIPFLWOPR FO ,MWIPMATFLW MF ,MWIPFLWDEF FD where ((((((((FO.FACTORY=OD.FACT\
ORY and FO.OPER=OD.OPER) and FO.FACTORY=FD.FACTORY) and FO.FLOW=FD.FLOW) and \
MF.FACTORY=FO.FACTORY) and MF.FLOW=FO.FLOW) and MF.FACTORY=:b0) and MF.MAT_ID\
=:b1) and MF.MAT_VER=:b2) order by MF.FLOW_SEQ_NUM asc ,FO.SEQ_NUM asc  ) FOL\
 ) where ROWSEQ>=:b3 order by ROWSEQ asc             ";

 static const char *sq0013 = 
"select *  from (select ROWNUM ROWSEQ ,FOL.*  from (select MF.FLOW ,FD.FLOW_\
DESC ,FO.OPER ,OD.OPER_DESC ,MF.FLOW_SEQ_NUM ,FO.SEQ_NUM  from MWIPOPRDEF OD \
,MWIPFLWOPR FO ,MWIPMATFLW MF ,MWIPFLWDEF FD where ((((((((((FO.FACTORY=OD.FA\
CTORY and FO.OPER=OD.OPER) and FO.FACTORY=FD.FACTORY) and FO.FLOW=FD.FLOW) an\
d MF.FACTORY=FO.FACTORY) and MF.FLOW=FO.FLOW) and MF.FACTORY=:b0) and MF.MAT_\
ID=:b1) and MF.MAT_VER=:b2) and MF.FLOW=:b3) and MF.FLOW_SEQ_NUM=:b4) order b\
y MF.FLOW_SEQ_NUM asc ,FO.SEQ_NUM asc  ) FOL ) where ROWSEQ>=:b5 order by ROW\
SEQ asc             ";

 static const char *sq0014 = 
"select *  from (select ROWNUM ROWSEQ ,FOL.*  from (select MF.FLOW ,FD.FLOW_\
DESC ,FO.OPER ,OD.OPER_DESC ,MF.FLOW_SEQ_NUM ,FO.SEQ_NUM  from MWIPOPRDEF OD \
,MWIPFLWOPR FO ,MWIPMATFLW MF ,MWIPFLWDEF FD where (((((((FO.FACTORY=OD.FACTO\
RY and FO.OPER=OD.OPER) and FO.FACTORY=FD.FACTORY) and FO.FLOW=FD.FLOW) and M\
F.FACTORY=FO.FACTORY) and MF.FLOW=FO.FLOW) and MF.FACTORY=:b0) and MF.FLOW=:b\
1) order by MF.FLOW_SEQ_NUM asc ,FO.SEQ_NUM asc  ) FOL ) where ROWSEQ>=:b2 or\
der by ROWSEQ asc             ";

 static const char *sq0015 = 
"select *  from (select ROWNUM ROWSEQ ,FOL.*  from (select MF.FLOW ,FD.FLOW_\
DESC ,FO.OPER ,OD.OPER_DESC ,MF.FLOW_SEQ_NUM ,FO.SEQ_NUM  from MWIPOPRDEF OD \
,MWIPFLWOPR FO ,MWIPMATFLW MF ,MWIPFLWDEF FD where ((((((FO.FACTORY=OD.FACTOR\
Y and FO.OPER=OD.OPER) and FO.FACTORY=FD.FACTORY) and FO.FLOW=FD.FLOW) and MF\
.FACTORY=FO.FACTORY) and MF.FLOW=FO.FLOW) and MF.FACTORY=:b0) order by MF.FLO\
W asc ,MF.FLOW_SEQ_NUM asc ,FO.SEQ_NUM asc  ) FOL ) where ROWSEQ>=:b1 order b\
y ROWSEQ asc             ";

 static const char *sq0016 = 
"select *  from (select ROWNUM ROWSEQ ,FOL.*  from (select MF.FLOW ,FD.FLOW_\
DESC ,FO.OPER ,OD.OPER_DESC ,MF.FLOW_SEQ_NUM ,FO.SEQ_NUM  from MWIPOPRDEF OD \
,MWIPFLWOPR FO ,MWIPMATFLW MF ,MWIPFLWDEF FD where ((((((((((FO.FACTORY=OD.FA\
CTORY and FO.OPER=OD.OPER) and FO.FACTORY=FD.FACTORY) and FO.FLOW=FD.FLOW) an\
d MF.FACTORY=FO.FACTORY) and MF.FLOW=FO.FLOW) and MF.FACTORY=:b0) and MF.MAT_\
ID=:b1) and MF.MAT_VER=:b2) and MF.FLOW_SEQ_NUM>=:b3) and FO.SEQ_NUM>=(select\
 SEQ_NUM  from MWIPFLWOPR where ((FACTORY=:b0 and FLOW=:b5) and OPER=:b6))) o\
rder by MF.FLOW_SEQ_NUM asc ,FO.SEQ_NUM asc  ) FOL ) where ROWSEQ>=:b7 order \
by ROWSEQ asc             ";

 static const char *sq0017 = 
"select NVL(FOL.OPER_SEQ,0) OPER_SEQ ,NVL(FOL.OPER,' ') OPER ,NVL(FOL.OPER_D\
ESC,' ') OPER_DESC ,NVL(CD.OPT_LEVEL,' ') OPT_LEVEL ,NVL(CD.COL_SET_ID,' ') C\
OL_SET_ID ,NVL(CD.COLLECTION_MODE,' ') COLLECTION_MODE ,NVL(CD.DEFAULT_FLAG,'\
 ') DEFAULT_FLAG ,NVL(CD.DISABLE_FLAG,' ') DISABLE_FLAG ,NVL(CD.CREATE_USER_I\
D,' ') CREATE_USER_ID ,NVL(CD.CREATE_TIME,' ') CREATE_TIME ,NVL(CD.UPDATE_USE\
R_ID,' ') UPDATE_USER_ID ,NVL(CD.UPDATE_TIME,' ') UPDATE_TIME  from (select F\
O.FACTORY ,FO.FLOW ,FO.SEQ_NUM OPER_SEQ ,FO.OPER ,OD.OPER_DESC  from MWIPFLWO\
PR FO ,MWIPOPRDEF OD where ((((FO.FACTORY=OD.FACTORY and FO.OPER=OD.OPER) and\
 FO.FACTORY=:b0) and FO.FLOW=:b1) and FO.SEQ_NUM>=:b2)) FOL ,(select *  from \
MWIPCOLDEF where ((((FACTORY=:b0 and MAT_ID=:b4) and MAT_VER=:b5) and FLOW=:b\
1) and OPT_LEVEL='1')) CD where ((((FOL.OPER_SEQ>:b2 or (FOL.OPER_SEQ=:b2 and\
 CD.COL_SET_ID>=:b9)) and FOL.FACTORY=CD.FACTORY(+)) and FOL.FLOW=CD.FLOW(+))\
 and FOL.OPER=CD.OPER(+)) order by FOL.OPER_SEQ asc ,CD.COL_SET_ID asc       \
      ";

 static const char *sq0018 = 
"select NVL(FO.SEQ_NUM,0) OPER_SEQ ,NVL(OD.OPER,' ') OPER ,NVL(OD.OPER_DESC,\
' ') OPER_DESC ,NVL(CD.OPT_LEVEL,' ') OPT_LEVEL ,NVL(CD.COL_SET_ID,' ') COL_S\
ET_ID ,NVL(CD.COLLECTION_MODE,' ') COLLECTION_MODE ,NVL(CD.DEFAULT_FLAG,' ') \
DEFAULT_FLAG ,NVL(CD.DISABLE_FLAG,' ') DISABLE_FLAG ,NVL(CD.CREATE_USER_ID,' \
') CREATE_USER_ID ,NVL(CD.CREATE_TIME,' ') CREATE_TIME ,NVL(CD.UPDATE_USER_ID\
,' ') UPDATE_USER_ID ,NVL(CD.UPDATE_TIME,' ') UPDATE_TIME  from MWIPOPRDEF OD\
 ,MWIPFLWOPR FO ,(select *  from MWIPCOLDEF where ((FACTORY=:b0 and FLOW=:b1)\
 and OPT_LEVEL='2')) CD where (((((((FO.FACTORY=OD.FACTORY and FO.OPER=OD.OPE\
R) and FO.FACTORY=:b0) and FO.FLOW=:b1) and (FO.SEQ_NUM>:b4 or (FO.SEQ_NUM=:b\
4 and CD.COL_SET_ID>=:b6))) and FO.FACTORY=CD.FACTORY(+)) and FO.FLOW=CD.FLOW\
(+)) and FO.OPER=CD.OPER(+)) order by FO.SEQ_NUM asc ,CD.COL_SET_ID asc      \
       ";

 static const char *sq0019 = 
"select 0 OPER_SEQ ,NVL(OD.OPER,' ') OPER ,NVL(OD.OPER_DESC,' ') OPER_DESC ,\
NVL(CD.OPT_LEVEL,' ') OPT_LEVEL ,NVL(CD.COL_SET_ID,' ') COL_SET_ID ,NVL(CD.CO\
LLECTION_MODE,' ') COLLECTION_MODE ,NVL(CD.DEFAULT_FLAG,' ') DEFAULT_FLAG ,NV\
L(CD.DISABLE_FLAG,' ') DISABLE_FLAG ,NVL(CD.CREATE_USER_ID,' ') CREATE_USER_I\
D ,NVL(CD.CREATE_TIME,' ') CREATE_TIME ,NVL(CD.UPDATE_USER_ID,' ') UPDATE_USE\
R_ID ,NVL(CD.UPDATE_TIME,' ') UPDATE_TIME  from MWIPOPRDEF OD ,(select *  fro\
m MWIPCOLDEF where (FACTORY=:b0 and OPT_LEVEL='3')) CD where (((OD.FACTORY=:b\
0 and (OD.OPER>:b2 or (OD.OPER=:b2 and CD.COL_SET_ID>=:b4))) and OD.FACTORY=C\
D.FACTORY(+)) and OD.OPER=CD.OPER(+)) order by OD.OPER asc ,CD.COL_SET_ID asc\
             ";

 static const char *sq0020 = 
"select 0 OPER_SEQ ,NVL(OD.OPER,' ') OPER ,NVL(OD.OPER_DESC,' ') OPER_DESC ,\
NVL(CD.OPT_LEVEL,' ') OPT_LEVEL ,NVL(CD.COL_SET_ID,' ') COL_SET_ID ,NVL(CD.CO\
LLECTION_MODE,' ') COLLECTION_MODE ,NVL(CD.DEFAULT_FLAG,' ') DEFAULT_FLAG ,NV\
L(CD.DISABLE_FLAG,' ') DISABLE_FLAG ,NVL(CD.CREATE_USER_ID,' ') CREATE_USER_I\
D ,NVL(CD.CREATE_TIME,' ') CREATE_TIME ,NVL(CD.UPDATE_USER_ID,' ') UPDATE_USE\
R_ID ,NVL(CD.UPDATE_TIME,' ') UPDATE_TIME  from MWIPOPRDEF OD ,(select *  fro\
m MWIPCOLDEF where (((FACTORY=:b0 and MAT_ID=:b1) and MAT_VER=:b2) and OPT_LE\
VEL='4')) CD where (((OD.FACTORY=:b0 and (OD.OPER>:b4 or (OD.OPER=:b4 and CD.\
COL_SET_ID>=:b6))) and OD.FACTORY=CD.FACTORY(+)) and OD.OPER=CD.OPER(+)) orde\
r by OD.OPER asc ,CD.COL_SET_ID asc             ";

 static const char *sq0021 = 
"FLOW) and OD.FACTORY=FO.FACTORY) and\
 OD.OPER=FO.OPER)) FOL ,(select *  from MWIPYLDDEF where (((FACTORY=:b0 and M\
AT_ID=:b1) and MAT_VER=:b2) and OPT_LEVEL='1')) CD where ((((FOL.FACTORY=CD.F\
ACTORY(+) and FOL.FLOW=CD.FLOW(+)) and FOL.FLOW_SEQ=CD.FLOW_SEQ_NUM(+)) and F\
OL.OPER=CD.OPER(+)) and ((FOL.FLOW_SEQ=:b6 and FOL.OPER_SEQ>=:b7) or FOL.FLOW\
_SEQ>:b6)) order by FOL.FLOW_SEQ asc ,FOL.OPER_SEQ asc             ";

 static const char *sq0022 = 
"select NVL(FO.OPER,' ') OPER ,NVL(FO.SEQ_NUM,0) OPER_SEQ ,NVL(OD.OPER_DESC,\
' ') OPER_DESC ,NVL(CD.OPT_LEVEL,' ') OPT_LEVEL ,NVL(CD.STD_YIELD,0) STD_YIEL\
D ,NVL(CD.PLN_YIELD,0) PLN_YIELD ,NVL(CD.UNIT_CHG_YIELD,0) UNIT_CHG_YIELD ,NV\
L(CD.CUSTOM_YIELD_1,0) CUSTOM_YIELD_1 ,NVL(CD.CUSTOM_YIELD_2,0) CUSTOM_YIELD_\
2 ,NVL(CD.CUSTOM_YIELD_3,0) CUSTOM_YIELD_3 ,NVL(CD.CUSTOM_YIELD_4,0) CUSTOM_Y\
IELD_4 ,NVL(CD.CUSTOM_YIELD_5,0) CUSTOM_YIELD_5 ,NVL(CD.CREATE_USER_ID,' ') C\
REATE_USER_ID ,NVL(CD.CREATE_TIME,' ') CREATE_TIME ,NVL(CD.UPDATE_USER_ID,' '\
) UPDATE_USER_ID ,NVL(CD.UPDATE_TIME,' ') UPDATE_TIME  from MWIPOPRDEF OD ,MW\
IPFLWOPR FO ,(select *  from MWIPYLDDEF where ((FACTORY=:b0 and FLOW=:b1) and\
 OPT_LEVEL='2')) CD where (((((((FO.FACTORY=:b0 and FO.FLOW=:b1) and FO.SEQ_N\
UM>=:b4) and FO.FACTORY=OD.FACTORY) and FO.OPER=OD.OPER) and FO.FACTORY=CD.FA\
CTORY(+)) and FO.FLOW=CD.FLOW(+)) and FO.OPER=CD.OPER(+)) order by FO.SEQ_NUM\
 asc             ";

 static const char *sq0023 = 
"select NVL(OD.OPER,' ') OPER ,NVL(OD.OPER_DESC,' ') OPER_DESC ,NVL(CD.OPT_L\
EVEL,' ') OPT_LEVEL ,NVL(CD.STD_YIELD,0) STD_YIELD ,NVL(CD.PLN_YIELD,0) PLN_Y\
IELD ,NVL(CD.UNIT_CHG_YIELD,0) UNIT_CHG_YIELD ,NVL(CD.CUSTOM_YIELD_1,0) CUSTO\
M_YIELD_1 ,NVL(CD.CUSTOM_YIELD_2,0) CUSTOM_YIELD_2 ,NVL(CD.CUSTOM_YIELD_3,0) \
CUSTOM_YIELD_3 ,NVL(CD.CUSTOM_YIELD_4,0) CUSTOM_YIELD_4 ,NVL(CD.CUSTOM_YIELD_\
5,0) CUSTOM_YIELD_5 ,NVL(CD.CREATE_USER_ID,' ') CREATE_USER_ID ,NVL(CD.CREATE\
_TIME,' ') CREATE_TIME ,NVL(CD.UPDATE_USER_ID,' ') UPDATE_USER_ID ,NVL(CD.UPD\
ATE_TIME,' ') UPDATE_TIME  from MWIPOPRDEF OD ,(select *  from MWIPYLDDEF whe\
re (FACTORY=:b0 and OPT_LEVEL='3')) CD where (((OD.FACTORY=:b0 and OD.OPER>=:\
b2) and OD.FACTORY=CD.FACTORY(+)) and OD.OPER=CD.OPER(+)) order by OD.OPER as\
c             ";

 static const char *sq0024 = 
"select NVL(OD.OPER,' ') OPER ,NVL(OD.OPER_DESC,' ') OPER_DESC ,NVL(CD.OPT_L\
EVEL,' ') OPT_LEVEL ,NVL(CD.STD_YIELD,0) STD_YIELD ,NVL(CD.PLN_YIELD,0) PLN_Y\
IELD ,NVL(CD.UNIT_CHG_YIELD,0) UNIT_CHG_YIELD ,NVL(CD.CUSTOM_YIELD_1,0) CUSTO\
M_YIELD_1 ,NVL(CD.CUSTOM_YIELD_2,0) CUSTOM_YIELD_2 ,NVL(CD.CUSTOM_YIELD_3,0) \
CUSTOM_YIELD_3 ,NVL(CD.CUSTOM_YIELD_4,0) CUSTOM_YIELD_4 ,NVL(CD.CUSTOM_YIELD_\
5,0) CUSTOM_YIELD_5 ,NVL(CD.CREATE_USER_ID,' ') CREATE_USER_ID ,NVL(CD.CREATE\
_TIME,' ') CREATE_TIME ,NVL(CD.UPDATE_USER_ID,' ') UPDATE_USER_ID ,NVL(CD.UPD\
ATE_TIME,' ') UPDATE_TIME  from MWIPOPRDEF OD ,(select *  from MWIPYLDDEF whe\
re (((FACTORY=:b0 and MAT_ID=:b1) and MAT_VER=:b2) and OPT_LEVEL='4')) CD whe\
re (((OD.FACTORY=:b0 and OD.OPER>=:b4) and OD.FACTORY=CD.FACTORY(+)) and OD.O\
PER=CD.OPER(+)) order by OD.OPER asc             ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,846,0,0,
5,0,0,1,1331,0,9,115,0,0,9,9,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,0,0,0,1,0,0,0,1,
0,0,0,1,3,0,0,1,3,0,0,1,0,0,0,
56,0,0,2,835,0,9,151,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,0,0,0,1,0,0,0,1,3,0,0,
91,0,0,3,678,0,9,181,0,0,3,3,0,1,0,1,97,0,0,1,0,0,0,1,97,0,0,
118,0,0,4,1293,0,9,233,0,0,9,9,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,0,0,0,1,0,0,0,
1,0,0,0,1,3,0,0,1,3,0,0,1,0,0,0,
169,0,0,1,0,0,13,261,0,0,17,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,
252,0,0,2,0,0,13,282,0,0,14,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,4,0,0,
2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
323,0,0,3,0,0,13,300,0,0,13,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,
2,97,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
390,0,0,4,0,0,13,317,0,0,17,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,0,0,
2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,4,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,
473,0,0,1,0,0,15,363,0,0,0,0,0,1,0,
488,0,0,2,0,0,15,367,0,0,0,0,0,1,0,
503,0,0,3,0,0,15,371,0,0,0,0,0,1,0,
518,0,0,4,0,0,15,375,0,0,0,0,0,1,0,
533,0,0,5,0,0,17,651,0,0,1,1,0,1,0,1,97,0,0,
552,0,0,5,0,0,45,653,0,0,0,0,0,1,0,
567,0,0,6,2709,0,9,814,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,97,0,0,
594,0,0,5,0,0,13,842,0,0,142,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,
0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,1,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,
1177,0,0,6,0,0,13,988,0,0,142,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,
0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,
3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,1,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,3,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,97,0,0,2,97,0,0,2,97,0,0,
1760,0,0,5,0,0,15,1159,0,0,0,0,0,1,0,
1775,0,0,6,0,0,15,1163,0,0,0,0,0,1,0,
1790,0,0,5,0,0,17,1683,0,0,1,1,0,1,0,1,97,0,0,
1809,0,0,5,0,0,45,1685,0,0,0,0,0,1,0,
1824,0,0,5,0,0,13,1712,0,0,30,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,97,0,0,2,3,0,0,2,
97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
1959,0,0,5,0,0,15,1768,0,0,0,0,0,1,0,
1974,0,0,7,239,0,9,1880,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
1997,0,0,7,0,0,13,1907,0,0,6,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,
2036,0,0,7,0,0,15,1939,0,0,0,0,0,1,0,
2051,0,0,8,571,0,9,2022,0,0,6,6,0,1,0,1,97,0,0,1,0,0,0,1,0,0,0,1,97,0,0,1,0,0,
0,1,97,0,0,
2090,0,0,5,0,0,17,2088,0,0,1,1,0,1,0,1,97,0,0,
2109,0,0,5,0,0,45,2090,0,0,0,0,0,1,0,
2124,0,0,8,0,0,13,2119,0,0,10,0,0,1,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2179,0,0,5,0,0,13,2133,0,0,10,0,0,1,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2234,0,0,8,0,0,15,2173,0,0,0,0,0,1,0,
2249,0,0,5,0,0,15,2176,0,0,0,0,0,1,0,
2264,0,0,9,583,0,9,2289,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
2295,0,0,10,235,0,9,2303,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,
2322,0,0,11,184,0,9,2321,0,0,2,2,0,1,0,1,97,0,0,1,3,0,0,
2345,0,0,12,513,0,9,2347,0,0,4,4,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,
2376,0,0,13,557,0,9,2375,0,0,6,6,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,97,0,0,1,3,
0,0,1,3,0,0,
2415,0,0,14,490,0,9,2400,0,0,3,3,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,
2442,0,0,15,485,0,9,2424,0,0,2,2,0,1,0,1,97,0,0,1,3,0,0,
2465,0,0,16,640,0,9,2454,0,0,8,8,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,3,0,0,1,0,0,
0,1,97,0,0,1,97,0,0,1,3,0,0,
2512,0,0,9,0,0,13,2488,0,0,7,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,
0,2,3,0,0,2,3,0,0,
2555,0,0,10,0,0,13,2499,0,0,4,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,3,0,0,
2586,0,0,11,0,0,13,2507,0,0,3,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,
2613,0,0,12,0,0,13,2514,0,0,7,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,3,0,0,
2656,0,0,13,0,0,13,2525,0,0,7,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,3,0,0,
2699,0,0,14,0,0,13,2536,0,0,7,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,3,0,0,
2742,0,0,15,0,0,13,2547,0,0,7,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,3,0,0,
2785,0,0,16,0,0,13,2558,0,0,7,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,3,0,0,2,3,0,0,
2828,0,0,9,0,0,15,2593,0,0,0,0,0,1,0,
2843,0,0,10,0,0,15,2597,0,0,0,0,0,1,0,
2858,0,0,11,0,0,15,2601,0,0,0,0,0,1,0,
2873,0,0,12,0,0,15,2605,0,0,0,0,0,1,0,
2888,0,0,13,0,0,15,2609,0,0,0,0,0,1,0,
2903,0,0,14,0,0,15,2613,0,0,0,0,0,1,0,
2918,0,0,15,0,0,15,2617,0,0,0,0,0,1,0,
2933,0,0,16,0,0,15,2621,0,0,0,0,0,1,0,
2948,0,0,5,0,0,17,2780,0,0,1,1,0,1,0,1,97,0,0,
2967,0,0,5,0,0,45,2782,0,0,0,0,0,1,0,
2982,0,0,5,0,0,17,2821,0,0,1,1,0,1,0,1,97,0,0,
3001,0,0,5,0,0,45,2823,0,0,0,0,0,1,0,
3016,0,0,5,0,0,17,2872,0,0,1,1,0,1,0,1,97,0,0,
3035,0,0,5,0,0,45,2874,0,0,0,0,0,1,0,
3050,0,0,5,0,0,17,2919,0,0,1,1,0,1,0,1,97,0,0,
3069,0,0,5,0,0,45,2921,0,0,0,0,0,1,0,
3084,0,0,5,0,0,13,2949,0,0,1,0,0,1,0,2,3,0,0,
3103,0,0,5,0,0,13,2954,0,0,1,0,0,1,0,2,3,0,0,
3122,0,0,5,0,0,13,2959,0,0,1,0,0,1,0,2,3,0,0,
3141,0,0,5,0,0,13,2964,0,0,1,0,0,1,0,2,3,0,0,
3160,0,0,5,0,0,15,2995,0,0,0,0,0,1,0,
3175,0,0,5,0,0,15,2998,0,0,0,0,0,1,0,
3190,0,0,5,0,0,15,3001,0,0,0,0,0,1,0,
3205,0,0,5,0,0,15,3004,0,0,0,0,0,1,0,
3220,0,0,17,1005,0,9,3068,0,0,10,10,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,0,0,0,1,
97,0,0,1,3,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,97,0,0,
3275,0,0,18,852,0,9,3104,0,0,7,7,0,1,0,1,97,0,0,1,97,0,0,1,0,0,0,1,0,0,0,1,3,0,
0,1,0,0,0,1,97,0,0,
3318,0,0,19,704,0,9,3134,0,0,5,5,0,1,0,1,97,0,0,1,0,0,0,1,97,0,0,1,0,0,0,1,97,
0,0,
3353,0,0,20,739,0,9,3166,0,0,7,7,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,0,0,0,1,97,
0,0,1,0,0,0,1,97,0,0,
3396,0,0,17,0,0,13,3194,0,0,12,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
3459,0,0,18,0,0,13,3210,0,0,12,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
3522,0,0,19,0,0,13,3226,0,0,12,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
3585,0,0,20,0,0,13,3242,0,0,12,0,0,1,0,2,3,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,
0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
3648,0,0,17,0,0,15,3283,0,0,0,0,0,1,0,
3663,0,0,18,0,0,15,3287,0,0,0,0,0,1,0,
3678,0,0,19,0,0,15,3291,0,0,0,0,0,1,0,
3693,0,0,20,0,0,15,3295,0,0,0,0,0,1,0,
3708,0,0,21,1435,0,9,3429,0,0,9,9,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,0,0,0,1,0,
0,0,1,0,0,0,1,3,0,0,1,3,0,0,1,0,0,0,
3759,0,0,22,939,0,9,3467,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,0,0,0,1,0,0,0,1,3,0,
0,
3794,0,0,23,782,0,9,3499,0,0,3,3,0,1,0,1,97,0,0,1,0,0,0,1,97,0,0,
3821,0,0,24,817,0,9,3533,0,0,5,5,0,1,0,1,97,0,0,1,97,0,0,1,3,0,0,1,0,0,0,1,97,
0,0,
3856,0,0,21,0,0,13,3561,0,0,19,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,3,
0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
3947,0,0,22,0,0,13,3584,0,0,16,0,0,1,0,2,97,0,0,2,3,0,0,2,97,0,0,2,97,0,0,2,4,
0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,
4026,0,0,23,0,0,13,3604,0,0,15,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,
0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,
4101,0,0,24,0,0,13,3623,0,0,15,0,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,2,4,0,0,2,4,
0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,97,0,0,
2,97,0,0,
4176,0,0,21,0,0,15,3668,0,0,0,0,0,1,0,
4191,0,0,22,0,0,15,3672,0,0,0,0,0,1,0,
4206,0,0,23,0,0,15,3676,0,0,0,0,0,1,0,
4221,0,0,24,0,0,15,3680,0,0,0,0,0,1,0,
};


/*********************************************************************
**
**    File Name   : DBC_wipcore_join.pc
**    Description : Table Access Function Source File
**    Create date : 2004/12/01 16:36:50
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

/* Direct View ���� */
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
void DBC_add_null_get_cycletime(struct GET_CYCLETIME_N_TAG *GET_CYCLETIME_N, struct GET_CYCLETIME_TAG *GET_CYCLETIME);
void DBC_del_null_get_cycletime(struct GET_CYCLETIME_N_TAG *GET_CYCLETIME_N, struct GET_CYCLETIME_TAG *GET_CYCLETIME);

void DBC_add_null_get_lotdetail(struct GET_LOTDETAIL_N_TAG *GET_LOTDETAIL_N, struct GET_LOTDETAIL_TAG *GET_LOTDETAIL);
void DBC_del_null_get_lotdetail(struct GET_LOTDETAIL_N_TAG *GET_LOTDETAIL_N, struct GET_LOTDETAIL_TAG *GET_LOTDETAIL);

void DBC_add_null_get_lottrace(struct GET_LOT_TRACE_N_TAG *LOT_TRACE_N, struct GET_LOT_TRACE_TAG *LOT_TRACE);
void DBC_del_null_get_lottrace(struct GET_LOT_TRACE_N_TAG *LOT_TRACE_N, struct GET_LOT_TRACE_TAG *LOT_TRACE);

void DBC_add_null_get_operlist(struct GET_OPER_LIST_N_TAG *OPER_LIST_N, struct GET_OPER_LIST_TAG *OPER_LIST);
void DBC_del_null_get_operlist(struct GET_OPER_LIST_N_TAG *OPER_LIST_N, struct GET_OPER_LIST_TAG *OPER_LIST);

void DBC_add_null_get_mfo_sublot(struct GET_MFO_SUBLOT_N_TAG *GET_MFO_SUBLOT_N, struct GET_MFO_SUBLOT_TAG *GET_MFO_SUBLOT);
void DBC_del_null_get_mfo_sublot(struct GET_MFO_SUBLOT_N_TAG *GET_MFO_SUBLOT_N, struct GET_MFO_SUBLOT_TAG *GET_MFO_SUBLOT);

void DBC_add_null_get_mfo_queue_time(struct GET_MFO_QUEUE_TIME_N_TAG *GET_MFO_QUEUE_TIME_N, struct GET_MFO_QUEUE_TIME_TAG *GET_MFO_QUEUE_TIME);
void DBC_del_null_get_mfo_queue_time(struct GET_MFO_QUEUE_TIME_N_TAG *GET_MFO_QUEUE_TIME_N, struct GET_MFO_QUEUE_TIME_TAG *GET_MFO_QUEUE_TIME);

//for Future action condition check
void DBC_add_null_fat_cond_list(struct FAT_COND_LIST_N_TAG *FAT_COND_LIST_N, struct FAT_COND_LIST_TAG *FAT_COND_LIST);
void DBC_del_null_fat_cond_list(struct FAT_COND_LIST_N_TAG *FAT_COND_LIST_N, struct FAT_COND_LIST_TAG *FAT_COND_LIST);

void DBC_add_null_get_mfo_col_set_list(struct GET_MFO_COL_SET_LIST_N_TAG *GET_MFO_COL_SET_LIST_N, struct GET_MFO_COL_SET_LIST_TAG *GET_MFO_COL_SET_LIST);
void DBC_del_null_get_mfo_col_set_list(struct GET_MFO_COL_SET_LIST_N_TAG *GET_MFO_COL_SET_LIST_N, struct GET_MFO_COL_SET_LIST_TAG *GET_MFO_COL_SET_LIST);

void DBC_add_null_get_yield(struct GET_YIELD_N_TAG *GET_YIELD_N, struct GET_YIELD_TAG *GET_YIELD);
void DBC_del_null_get_yield(struct GET_YIELD_N_TAG *GET_YIELD_N, struct GET_YIELD_TAG *GET_YIELD);

/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_get_cycletime(int sel_type, struct GET_CYCLETIME_TAG *GET_CYCLETIME)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct GET_CYCLETIME_N_TAG GET_CYCLETIME_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_get_cycletime(&GET_CYCLETIME_N, GET_CYCLETIME);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBC_GET_CYCLETIME_CUR_1 CURSOR FOR 
                SELECT NVL(FOL.FLOW, ' ') AS FLOW, 
                    NVL(FOL.FLOW_SEQ, 0) AS FLOW_SEQ,
                    NVL(FOL.FLOW_DESC, ' ') AS FLOW_DESC, 
                    NVL(FOL.OPER, ' ') AS OPER, 
                    NVL(FOL.OPER_SEQ, 0) AS OPER_SEQ, 
                    NVL(FOL.OPER_DESC, ' ') AS OPER_DESC, 
                    NVL(CD.OPT_LEVEL, ' ') AS OPT_LEVEL, 
                    NVL(CD.QUEUE_TIME, 0) AS QUEUE_TIME, 
                    NVL(CD.PROC_TIME, 0) AS PROC_TIME, 
                    NVL(CD.HPU_FLAG, ' ') AS HPU_FLAG, 
                    NVL(CD.HPU_PROC_TIME, 0) AS HPU_PROC_TIME, 
                    NVL(CD.UPH_FLAG, ' ') AS UPH_FLAG, 
                    NVL(CD.UPH_PROC_TIME, 0) AS UPH_PROC_TIME, 
                    NVL(CD.CREATE_USER_ID, ' ') AS CREATE_USER_ID, 
                    NVL(CD.CREATE_TIME, ' ') AS CREATE_TIME, 
                    NVL(CD.UPDATE_USER_ID, ' ') AS UPDATE_USER_ID, 
                    NVL(CD.UPDATE_TIME, ' ') AS UPDATE_TIME 
                FROM ( 
                    SELECT MF.FACTORY,
                           MF.FLOW, MF.FLOW_SEQ_NUM AS FLOW_SEQ, FD.FLOW_DESC, 
                           FO.OPER, FO.SEQ_NUM AS OPER_SEQ, OD.OPER_DESC 
                    FROM MWIPMATFLW MF, MWIPFLWOPR FO, MWIPFLWDEF FD, MWIPOPRDEF OD 
                    WHERE MF.FACTORY = :GET_CYCLETIME_N.FACTORY
                        AND MF.MAT_ID = :GET_CYCLETIME_N.MAT_ID
                        AND MF.MAT_VER = :GET_CYCLETIME_N.MAT_VER
                        AND FO.FACTORY = MF.FACTORY
                        AND FO.FLOW = MF.FLOW
                        AND FD.FACTORY = FO.FACTORY 
                        AND FD.FLOW = FO.FLOW
                        AND OD.FACTORY = FO.FACTORY
                        AND OD.OPER = FO.OPER
                    ) FOL, (
                    SELECT *
                    FROM MWIPCYTDEF 
                    WHERE FACTORY = :GET_CYCLETIME_N.FACTORY
                        AND MAT_ID = :GET_CYCLETIME_N.MAT_ID 
                        AND MAT_VER = :GET_CYCLETIME_N.MAT_VER 
                        AND OPT_LEVEL = '1'
                    ) CD 
                WHERE FOL.FACTORY = CD.FACTORY(+)
                    AND FOL.FLOW = CD.FLOW(+) 
                    AND FOL.FLOW_SEQ = CD.FLOW_SEQ_NUM(+) 
                    AND FOL.OPER = CD.OPER(+) 
                    AND ((FOL.FLOW_SEQ = :GET_CYCLETIME_N.FLOW_SEQ_NUM AND FOL.OPER_SEQ >= :GET_CYCLETIME_N.OPER_SEQ) 
                         OR FOL.FLOW_SEQ > :GET_CYCLETIME_N.FLOW_SEQ_NUM)
                ORDER BY FOL.FLOW_SEQ ASC, FOL.OPER_SEQ ASC; */ 
 

            /* EXEC SQL OPEN DBC_GET_CYCLETIME_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 9;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select NVL(FOL.FLOW,' ') FLOW ,NVL(FOL.FLOW_SEQ,0) FLOW_SEQ ,\
NVL(FOL.FLOW_DESC,' ') FLOW_DESC ,NVL(FOL.OPER,' ') OPER ,NVL(FOL.OPER_SEQ,0\
) OPER_SEQ ,NVL(FOL.OPER_DESC,' ') OPER_DESC ,NVL(CD.OPT_LEVEL,' ') OPT_LEVE\
L ,NVL(CD.QUEUE_TIME,0) QUEUE_TIME ,NVL(CD.PROC_TIME,0) PROC_TIME ,NVL(CD.HP\
U_FLAG,' ') HPU_FLAG ,NVL(CD.HPU_PROC_TIME,0) HPU_PROC_TIME ,NVL(CD.UPH_FLAG\
,' ') UPH_FLAG ,NVL(CD.UPH_PROC_TIME,0) UPH_PROC_TIME ,NVL(CD.CREATE_USER_ID\
,' ') CREATE_USER_ID ,NVL(CD.CREATE_TIME,' ') CREATE_TIME ,NVL(CD.UPDATE_USE\
R_ID,' ') UPDATE_USER_ID ,NVL(CD.UPDATE_TIME,' ') UPDATE_TIME  from (select \
MF.FACTORY ,MF.FLOW ,MF.FLOW_SEQ_NUM FLOW_SEQ ,FD.FLOW_DESC ,FO.OPER ,FO.SEQ\
_NUM OPER_SEQ ,OD.OPER_DESC  from MWIPMATFLW MF ,MWIPFLWOPR FO ,MWIPFLWDEF F\
D ,MWIPOPRDEF OD where ((((((((MF.FACTORY=:b0 and MF.MAT_ID=:b1) and MF.MAT_\
VER=:b2) and FO.FACTORY=MF.FACTORY) and FO.FLOW=MF.FLOW) and FD.FACTORY=FO.F\
ACTORY) and FD.FLOW=FO.FLOW) and OD.FACTORY=FO.FACTORY) and OD.OPER=FO.OPER)\
) FOL ,(select *  from MWIPCYTDEF where (((FACTORY=");
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
            sqlstm.sqhstv[0] = (         void  *)(GET_CYCLETIME_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_CYCLETIME_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(GET_CYCLETIME_N.MAT_VER);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_CYCLETIME_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(GET_CYCLETIME_N.MAT_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(GET_CYCLETIME_N.MAT_VER);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(GET_CYCLETIME_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(GET_CYCLETIME_N.OPER_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(GET_CYCLETIME_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
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
            /* EXEC SQL DECLARE DBC_GET_CYCLETIME_CUR_2 CURSOR FOR 
                SELECT NVL(FO.OPER, ' ') AS OPER, 
                    NVL(FO.SEQ_NUM, 0) AS OPER_SEQ, 
                    NVL(OD.OPER_DESC, ' ') AS OPER_DESC, 
                    NVL(CD.OPT_LEVEL,' ') AS OPT_LEVEL, 
                    NVL(CD.QUEUE_TIME, 0) AS QUEUE_TIME, 
                    NVL(CD.PROC_TIME, 0) AS PROC_TIME, 
                    NVL(CD.HPU_FLAG, ' ') AS HPU_FLAG, 
                    NVL(CD.HPU_PROC_TIME, 0) AS HPU_PROC_TIME, 
                    NVL(CD.UPH_FLAG, ' ') AS UPH_FLAG, 
                    NVL(CD.UPH_PROC_TIME, 0) AS UPH_PROC_TIME, 
                    NVL(CD.CREATE_USER_ID, ' ') AS CREATE_USER_ID, 
                    NVL(CD.CREATE_TIME, ' ') AS CREATE_TIME, 
                    NVL(CD.UPDATE_USER_ID, ' ') AS UPDATE_USER_ID, 
                    NVL(CD.UPDATE_TIME, ' ') AS UPDATE_TIME 
                FROM MWIPOPRDEF OD, MWIPFLWOPR  FO, (
                    SELECT *
                    FROM MWIPCYTDEF 
                    WHERE FACTORY = :GET_CYCLETIME_N.FACTORY 
                        AND FLOW = :GET_CYCLETIME_N.FLOW  
                        AND OPT_LEVEL = '2'
                    ) CD 
                WHERE FO.FACTORY = :GET_CYCLETIME_N.FACTORY 
                    AND FO.FLOW = :GET_CYCLETIME_N.FLOW  
                    AND FO.SEQ_NUM >= :GET_CYCLETIME_N.OPER_SEQ 
                    AND FO.FACTORY = OD.FACTORY
                    AND FO.OPER = OD.OPER
                    AND FO.FACTORY = CD.FACTORY(+) 
                    AND FO.FLOW = CD.FLOW(+)
                    AND FO.OPER = CD.OPER(+) 
                ORDER BY FO.SEQ_NUM ASC; */ 
 

            /* EXEC SQL OPEN DBC_GET_CYCLETIME_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 9;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0002;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )56;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(GET_CYCLETIME_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_CYCLETIME_N.FLOW);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_CYCLETIME_N.FACTORY);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_CYCLETIME_N.FLOW);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(GET_CYCLETIME_N.OPER_SEQ);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
            
        case 3:
            /* EXEC SQL DECLARE DBC_GET_CYCLETIME_CUR_3 CURSOR FOR 
                SELECT NVL(OD.OPER, ' ') AS OPER, 
                    NVL(OD.OPER_DESC, ' ') AS OPER_DESC, 
                    NVL(CD.OPT_LEVEL,' ') AS OPT_LEVEL, 
                    NVL(CD.QUEUE_TIME, 0) AS QUEUE_TIME, 
                    NVL(CD.PROC_TIME, 0) AS PROC_TIME, 
                    NVL(CD.HPU_FLAG, ' ') AS HPU_FLAG, 
                    NVL(CD.HPU_PROC_TIME, 0) AS HPU_PROC_TIME, 
                    NVL(CD.UPH_FLAG, ' ') AS UPH_FLAG, 
                    NVL(CD.UPH_PROC_TIME, 0) AS UPH_PROC_TIME, 
                    NVL(CD.CREATE_USER_ID, ' ') AS CREATE_USER_ID, 
                    NVL(CD.CREATE_TIME, ' ') AS CREATE_TIME, 
                    NVL(CD.UPDATE_USER_ID, ' ') AS UPDATE_USER_ID, 
                    NVL(CD.UPDATE_TIME, ' ') AS UPDATE_TIME
                FROM MWIPOPRDEF OD, (
                    SELECT *
                    FROM MWIPCYTDEF 
                    WHERE FACTORY = :GET_CYCLETIME_N.FACTORY 
                        AND OPT_LEVEL = '3'
                    ) CD
                WHERE OD.FACTORY = :GET_CYCLETIME_N.FACTORY 
                    AND OD.OPER >= :GET_CYCLETIME_N.OPER 
                    AND OD.FACTORY = CD.FACTORY(+) 
                    AND OD.OPER = CD.OPER(+) 
                ORDER BY OD.OPER ASC; */ 
 

            /* EXEC SQL OPEN DBC_GET_CYCLETIME_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 9;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0003;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )91;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(GET_CYCLETIME_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_CYCLETIME_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_CYCLETIME_N.OPER);
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

        case 4: /* Not Allow Duplicate Flow Seq Num Case : Against Case 1 */
            /* EXEC SQL DECLARE DBC_GET_CYCLETIME_CUR_4 CURSOR FOR 
                SELECT NVL(FOL.FLOW, ' ') AS FLOW, 
                    NVL(FOL.FLOW_SEQ, 0) AS FLOW_SEQ,
                    NVL(FOL.FLOW_DESC, ' ') AS FLOW_DESC, 
                    NVL(FOL.OPER, ' ') AS OPER, 
                    NVL(FOL.OPER_SEQ, 0) AS OPER_SEQ, 
                    NVL(FOL.OPER_DESC, ' ') AS OPER_DESC, 
                    NVL(CD.OPT_LEVEL, ' ') AS OPT_LEVEL, 
                    NVL(CD.QUEUE_TIME, 0) AS QUEUE_TIME, 
                    NVL(CD.PROC_TIME, 0) AS PROC_TIME, 
                    NVL(CD.HPU_FLAG, ' ') AS HPU_FLAG, 
                    NVL(CD.HPU_PROC_TIME, 0) AS HPU_PROC_TIME, 
                    NVL(CD.UPH_FLAG, ' ') AS UPH_FLAG, 
                    NVL(CD.UPH_PROC_TIME, 0) AS UPH_PROC_TIME, 
                    NVL(CD.CREATE_USER_ID, ' ') AS CREATE_USER_ID, 
                    NVL(CD.CREATE_TIME, ' ') AS CREATE_TIME, 
                    NVL(CD.UPDATE_USER_ID, ' ') AS UPDATE_USER_ID, 
                    NVL(CD.UPDATE_TIME, ' ') AS UPDATE_TIME 
                FROM ( 
                    SELECT MF.FACTORY,
                           MF.FLOW, MF.FLOW_SEQ_NUM AS FLOW_SEQ, FD.FLOW_DESC, 
                           FO.OPER, FO.SEQ_NUM AS OPER_SEQ, OD.OPER_DESC 
                    FROM MWIPMATFLW MF, MWIPFLWOPR FO, MWIPFLWDEF FD, MWIPOPRDEF OD 
                    WHERE MF.FACTORY = :GET_CYCLETIME_N.FACTORY
                        AND MF.MAT_ID = :GET_CYCLETIME_N.MAT_ID
                        AND MF.MAT_VER = :GET_CYCLETIME_N.MAT_VER
                        AND FO.FACTORY = MF.FACTORY
                        AND FO.FLOW = MF.FLOW
                        AND FD.FACTORY = FO.FACTORY 
                        AND FD.FLOW = FO.FLOW
                        AND OD.FACTORY = FO.FACTORY
                        AND OD.OPER = FO.OPER
                    ) FOL, (
                    SELECT *
                    FROM MWIPCYTDEF 
                    WHERE FACTORY = :GET_CYCLETIME_N.FACTORY
                        AND MAT_ID = :GET_CYCLETIME_N.MAT_ID 
                        AND MAT_VER = :GET_CYCLETIME_N.MAT_VER 
                        AND OPT_LEVEL = '1'
                    ) CD 
                WHERE FOL.FACTORY = CD.FACTORY(+)
                    AND FOL.FLOW = CD.FLOW(+) 
                    /o AND FOL.FLOW_SEQ = CD.FLOW_SEQ_NUM(+) o/
                    AND FOL.OPER = CD.OPER(+) 
                    AND ((FOL.FLOW_SEQ = :GET_CYCLETIME_N.FLOW_SEQ_NUM AND FOL.OPER_SEQ >= :GET_CYCLETIME_N.OPER_SEQ) 
                         OR FOL.FLOW_SEQ > :GET_CYCLETIME_N.FLOW_SEQ_NUM)
                ORDER BY FOL.FLOW_SEQ ASC, FOL.OPER_SEQ ASC; */ 
 

            /* EXEC SQL OPEN DBC_GET_CYCLETIME_CUR_4; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 9;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select NVL(FOL.FLOW,' ') FLOW ,NVL(FOL.FLOW_SEQ,0) FLOW_SEQ ,\
NVL(FOL.FLOW_DESC,' ') FLOW_DESC ,NVL(FOL.OPER,' ') OPER ,NVL(FOL.OPER_SEQ,0\
) OPER_SEQ ,NVL(FOL.OPER_DESC,' ') OPER_DESC ,NVL(CD.OPT_LEVEL,' ') OPT_LEVE\
L ,NVL(CD.QUEUE_TIME,0) QUEUE_TIME ,NVL(CD.PROC_TIME,0) PROC_TIME ,NVL(CD.HP\
U_FLAG,' ') HPU_FLAG ,NVL(CD.HPU_PROC_TIME,0) HPU_PROC_TIME ,NVL(CD.UPH_FLAG\
,' ') UPH_FLAG ,NVL(CD.UPH_PROC_TIME,0) UPH_PROC_TIME ,NVL(CD.CREATE_USER_ID\
,' ') CREATE_USER_ID ,NVL(CD.CREATE_TIME,' ') CREATE_TIME ,NVL(CD.UPDATE_USE\
R_ID,' ') UPDATE_USER_ID ,NVL(CD.UPDATE_TIME,' ') UPDATE_TIME  from (select \
MF.FACTORY ,MF.FLOW ,MF.FLOW_SEQ_NUM FLOW_SEQ ,FD.FLOW_DESC ,FO.OPER ,FO.SEQ\
_NUM OPER_SEQ ,OD.OPER_DESC  from MWIPMATFLW MF ,MWIPFLWOPR FO ,MWIPFLWDEF F\
D ,MWIPOPRDEF OD where ((((((((MF.FACTORY=:b0 and MF.MAT_ID=:b1) and MF.MAT_\
VER=:b2) and FO.FACTORY=MF.FACTORY) and FO.FLOW=MF.FLOW) and FD.FACTORY=FO.F\
ACTORY) and FD.FLOW=FO.FLOW) and OD.FACTORY=FO.FACTORY) and OD.OPER=FO.OPER)\
) FOL ,(select *  from MWIPCYTDEF where (((FACTORY=");
            sqlstm.stmt = sq0004;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )118;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(GET_CYCLETIME_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_CYCLETIME_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(GET_CYCLETIME_N.MAT_VER);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_CYCLETIME_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(GET_CYCLETIME_N.MAT_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(GET_CYCLETIME_N.MAT_VER);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(GET_CYCLETIME_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(GET_CYCLETIME_N.OPER_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(GET_CYCLETIME_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
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
    DB_stop_query_timer("DBC_open_get_cycletime", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_get_cycletime(int sel_type, struct GET_CYCLETIME_TAG *GET_CYCLETIME)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct GET_CYCLETIME_N_TAG GET_CYCLETIME_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_GET_CYCLETIME_CUR_1 INTO 
                :GET_CYCLETIME_N.FLOW,
                :GET_CYCLETIME_N.FLOW_SEQ_NUM,
                :GET_CYCLETIME_N.FLOW_DESC,                
                :GET_CYCLETIME_N.OPER,
                :GET_CYCLETIME_N.OPER_SEQ,
                :GET_CYCLETIME_N.OPER_DESC,
                :GET_CYCLETIME_N.OPT_LEVEL,
                :GET_CYCLETIME_N.QUEUE_TIME,
                :GET_CYCLETIME_N.PROC_TIME,
                :GET_CYCLETIME_N.HPU_FLAG,
                :GET_CYCLETIME_N.HPU_PROC_TIME,
                :GET_CYCLETIME_N.UPH_FLAG,
                :GET_CYCLETIME_N.UPH_PROC_TIME,
                :GET_CYCLETIME_N.CREATE_USER_ID,
                :GET_CYCLETIME_N.CREATE_TIME,
                :GET_CYCLETIME_N.UPDATE_USER_ID,
                :GET_CYCLETIME_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 17;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )169;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(GET_CYCLETIME_N.FLOW);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(GET_CYCLETIME_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_CYCLETIME_N.FLOW_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_CYCLETIME_N.OPER);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(GET_CYCLETIME_N.OPER_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(GET_CYCLETIME_N.OPER_DESC);
            sqlstm.sqhstl[5] = (unsigned int  )201;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(GET_CYCLETIME_N.OPT_LEVEL);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(GET_CYCLETIME_N.QUEUE_TIME);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(GET_CYCLETIME_N.PROC_TIME);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(GET_CYCLETIME_N.HPU_FLAG);
            sqlstm.sqhstl[9] = (unsigned int  )2;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(GET_CYCLETIME_N.HPU_PROC_TIME);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(GET_CYCLETIME_N.UPH_FLAG);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(GET_CYCLETIME_N.UPH_PROC_TIME);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(GET_CYCLETIME_N.CREATE_USER_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(GET_CYCLETIME_N.CREATE_TIME);
            sqlstm.sqhstl[14] = (unsigned int  )15;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(GET_CYCLETIME_N.UPDATE_USER_ID);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(GET_CYCLETIME_N.UPDATE_TIME);
            sqlstm.sqhstl[16] = (unsigned int  )15;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBC_GET_CYCLETIME_CUR_2 INTO 
                :GET_CYCLETIME_N.OPER, 
                :GET_CYCLETIME_N.OPER_SEQ,
                :GET_CYCLETIME_N.OPER_DESC, 
                :GET_CYCLETIME_N.OPT_LEVEL, 
                :GET_CYCLETIME_N.QUEUE_TIME,
                :GET_CYCLETIME_N.PROC_TIME,
                :GET_CYCLETIME_N.HPU_FLAG,
                :GET_CYCLETIME_N.HPU_PROC_TIME, 
                :GET_CYCLETIME_N.UPH_FLAG, 
                :GET_CYCLETIME_N.UPH_PROC_TIME,
                :GET_CYCLETIME_N.CREATE_USER_ID,
                :GET_CYCLETIME_N.CREATE_TIME,
                :GET_CYCLETIME_N.UPDATE_USER_ID, 
                :GET_CYCLETIME_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 17;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )252;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(GET_CYCLETIME_N.OPER);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(GET_CYCLETIME_N.OPER_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_CYCLETIME_N.OPER_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_CYCLETIME_N.OPT_LEVEL);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(GET_CYCLETIME_N.QUEUE_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(GET_CYCLETIME_N.PROC_TIME);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(GET_CYCLETIME_N.HPU_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(GET_CYCLETIME_N.HPU_PROC_TIME);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(GET_CYCLETIME_N.UPH_FLAG);
            sqlstm.sqhstl[8] = (unsigned int  )2;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(GET_CYCLETIME_N.UPH_PROC_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(GET_CYCLETIME_N.CREATE_USER_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(GET_CYCLETIME_N.CREATE_TIME);
            sqlstm.sqhstl[11] = (unsigned int  )15;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(GET_CYCLETIME_N.UPDATE_USER_ID);
            sqlstm.sqhstl[12] = (unsigned int  )21;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(GET_CYCLETIME_N.UPDATE_TIME);
            sqlstm.sqhstl[13] = (unsigned int  )15;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBC_GET_CYCLETIME_CUR_3 INTO 
                :GET_CYCLETIME_N.OPER, 
                :GET_CYCLETIME_N.OPER_DESC, 
                :GET_CYCLETIME_N.OPT_LEVEL, 
                :GET_CYCLETIME_N.QUEUE_TIME, 
                :GET_CYCLETIME_N.PROC_TIME, 
                :GET_CYCLETIME_N.HPU_FLAG, 
                :GET_CYCLETIME_N.HPU_PROC_TIME, 
                :GET_CYCLETIME_N.UPH_FLAG, 
                :GET_CYCLETIME_N.UPH_PROC_TIME, 
                :GET_CYCLETIME_N.CREATE_USER_ID, 
                :GET_CYCLETIME_N.CREATE_TIME, 
                :GET_CYCLETIME_N.UPDATE_USER_ID, 
                :GET_CYCLETIME_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 17;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )323;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(GET_CYCLETIME_N.OPER);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_CYCLETIME_N.OPER_DESC);
            sqlstm.sqhstl[1] = (unsigned int  )201;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_CYCLETIME_N.OPT_LEVEL);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(GET_CYCLETIME_N.QUEUE_TIME);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(GET_CYCLETIME_N.PROC_TIME);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(GET_CYCLETIME_N.HPU_FLAG);
            sqlstm.sqhstl[5] = (unsigned int  )2;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(GET_CYCLETIME_N.HPU_PROC_TIME);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(GET_CYCLETIME_N.UPH_FLAG);
            sqlstm.sqhstl[7] = (unsigned int  )2;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(GET_CYCLETIME_N.UPH_PROC_TIME);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(GET_CYCLETIME_N.CREATE_USER_ID);
            sqlstm.sqhstl[9] = (unsigned int  )21;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(GET_CYCLETIME_N.CREATE_TIME);
            sqlstm.sqhstl[10] = (unsigned int  )15;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(GET_CYCLETIME_N.UPDATE_USER_ID);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(GET_CYCLETIME_N.UPDATE_TIME);
            sqlstm.sqhstl[12] = (unsigned int  )15;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
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

        case 4: /* Not Allow Duplicate Flow Seq Num Case : Against Case 1 */
            /* EXEC SQL FETCH DBC_GET_CYCLETIME_CUR_4 INTO 
                :GET_CYCLETIME_N.FLOW,
                :GET_CYCLETIME_N.FLOW_SEQ_NUM,
                :GET_CYCLETIME_N.FLOW_DESC,                
                :GET_CYCLETIME_N.OPER,
                :GET_CYCLETIME_N.OPER_SEQ,
                :GET_CYCLETIME_N.OPER_DESC,
                :GET_CYCLETIME_N.OPT_LEVEL,
                :GET_CYCLETIME_N.QUEUE_TIME,
                :GET_CYCLETIME_N.PROC_TIME,
                :GET_CYCLETIME_N.HPU_FLAG,
                :GET_CYCLETIME_N.HPU_PROC_TIME,
                :GET_CYCLETIME_N.UPH_FLAG,
                :GET_CYCLETIME_N.UPH_PROC_TIME,
                :GET_CYCLETIME_N.CREATE_USER_ID,
                :GET_CYCLETIME_N.CREATE_TIME,
                :GET_CYCLETIME_N.UPDATE_USER_ID,
                :GET_CYCLETIME_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 17;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )390;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(GET_CYCLETIME_N.FLOW);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(GET_CYCLETIME_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_CYCLETIME_N.FLOW_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_CYCLETIME_N.OPER);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(GET_CYCLETIME_N.OPER_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(GET_CYCLETIME_N.OPER_DESC);
            sqlstm.sqhstl[5] = (unsigned int  )201;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(GET_CYCLETIME_N.OPT_LEVEL);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(GET_CYCLETIME_N.QUEUE_TIME);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(GET_CYCLETIME_N.PROC_TIME);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(GET_CYCLETIME_N.HPU_FLAG);
            sqlstm.sqhstl[9] = (unsigned int  )2;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(GET_CYCLETIME_N.HPU_PROC_TIME);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(GET_CYCLETIME_N.UPH_FLAG);
            sqlstm.sqhstl[11] = (unsigned int  )2;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(GET_CYCLETIME_N.UPH_PROC_TIME);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(GET_CYCLETIME_N.CREATE_USER_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(GET_CYCLETIME_N.CREATE_TIME);
            sqlstm.sqhstl[14] = (unsigned int  )15;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(GET_CYCLETIME_N.UPDATE_USER_ID);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(GET_CYCLETIME_N.UPDATE_TIME);
            sqlstm.sqhstl[16] = (unsigned int  )15;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
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
        DBC_del_null_get_cycletime(&GET_CYCLETIME_N, GET_CYCLETIME);
    }
    DB_stop_query_timer("DBC_fetch_get_cycletime", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_get_cycletime(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_GET_CYCLETIME_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 17;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )473;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
            
        case 2:
            /* EXEC SQL CLOSE DBC_GET_CYCLETIME_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 17;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )488;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
            
        case 3:
            /* EXEC SQL CLOSE DBC_GET_CYCLETIME_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 17;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )503;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 4: /* Not Allow Duplicate Flow Seq Num Case : Against Case 1 */
            /* EXEC SQL CLOSE DBC_GET_CYCLETIME_CUR_4; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 17;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )518;
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
    DB_stop_query_timer("DBC_close_get_cycletime", sel_type);
}

/* Initialize Function */
void DBC_init_get_cycletime(struct GET_CYCLETIME_TAG *GET_CYCLETIME)
{
    /* memset by Space */
    memset(GET_CYCLETIME, ' ', sizeof(struct GET_CYCLETIME_TAG));

    GET_CYCLETIME->MAT_VER = 0;
    GET_CYCLETIME->FLOW_SEQ_NUM = 0;
    GET_CYCLETIME->OPER_SEQ = 0;
    GET_CYCLETIME->HPU_PROC_TIME = 0;
    GET_CYCLETIME->UPH_PROC_TIME = 0;
    GET_CYCLETIME->PROC_TIME = 0;
    GET_CYCLETIME->QUEUE_TIME = 0;
}


/* Add Null Function */
void DBC_add_null_get_cycletime(struct GET_CYCLETIME_N_TAG *GET_CYCLETIME_N, struct GET_CYCLETIME_TAG *GET_CYCLETIME)
{ 
    /* memset by NULL */
    memset(GET_CYCLETIME_N, '\0', sizeof(struct GET_CYCLETIME_N_TAG));

    MEMCPY_AN(GET_CYCLETIME_N->FACTORY ,GET_CYCLETIME->FACTORY ,sizeof(GET_CYCLETIME->FACTORY ));
    MEMCPY_AN(GET_CYCLETIME_N->MAT_ID , GET_CYCLETIME->MAT_ID , sizeof(GET_CYCLETIME->MAT_ID ));
    GET_CYCLETIME_N->MAT_VER = GET_CYCLETIME->MAT_VER;
    MEMCPY_AN(GET_CYCLETIME_N->FLOW ,GET_CYCLETIME->FLOW ,sizeof(GET_CYCLETIME->FLOW ));
    GET_CYCLETIME_N->FLOW_SEQ_NUM = GET_CYCLETIME->FLOW_SEQ_NUM;
    MEMCPY_AN(GET_CYCLETIME_N->FLOW_DESC ,GET_CYCLETIME->FLOW_DESC,sizeof(GET_CYCLETIME->FLOW_DESC));
    MEMCPY_AN(GET_CYCLETIME_N->OPER , GET_CYCLETIME->OPER , sizeof(GET_CYCLETIME->OPER ));
    MEMCPY_AN(GET_CYCLETIME_N->OPER_DESC , GET_CYCLETIME->OPER_DESC, sizeof(GET_CYCLETIME->OPER_DESC));
    GET_CYCLETIME_N->OPER_SEQ = GET_CYCLETIME->OPER_SEQ;
    GET_CYCLETIME_N->HPU_FLAG[0]= GET_CYCLETIME->HPU_FLAG;
    GET_CYCLETIME_N->HPU_PROC_TIME = GET_CYCLETIME->HPU_PROC_TIME ;
    GET_CYCLETIME_N->UPH_FLAG[0]= GET_CYCLETIME->UPH_FLAG;
    GET_CYCLETIME_N->UPH_PROC_TIME = GET_CYCLETIME->UPH_PROC_TIME ;
    GET_CYCLETIME_N->OPT_LEVEL[0]= GET_CYCLETIME->OPT_LEVEL;
    GET_CYCLETIME_N->PROC_TIME = GET_CYCLETIME->PROC_TIME ;
    GET_CYCLETIME_N->QUEUE_TIME = GET_CYCLETIME->QUEUE_TIME ;
    MEMCPY_AN(GET_CYCLETIME_N->CREATE_TIME ,GET_CYCLETIME->CREATE_TIME , sizeof(GET_CYCLETIME->CREATE_TIME ));
    MEMCPY_AN(GET_CYCLETIME_N->CREATE_USER_ID ,GET_CYCLETIME->CREATE_USER_ID , sizeof(GET_CYCLETIME->CREATE_USER_ID ));
    MEMCPY_AN(GET_CYCLETIME_N->UPDATE_TIME ,GET_CYCLETIME->UPDATE_TIME , sizeof(GET_CYCLETIME->UPDATE_TIME ));
    MEMCPY_AN(GET_CYCLETIME_N->UPDATE_USER_ID ,GET_CYCLETIME->UPDATE_USER_ID , sizeof(GET_CYCLETIME->UPDATE_USER_ID ));
}


/* Del Null Function */
void DBC_del_null_get_cycletime(struct GET_CYCLETIME_N_TAG *GET_CYCLETIME_N, struct GET_CYCLETIME_TAG *GET_CYCLETIME)
{
    MEMCPY_DN(GET_CYCLETIME->FACTORY ,GET_CYCLETIME_N->FACTORY ,sizeof(GET_CYCLETIME->FACTORY ));
    MEMCPY_DN(GET_CYCLETIME->MAT_ID , GET_CYCLETIME_N->MAT_ID , sizeof(GET_CYCLETIME->MAT_ID ));
    GET_CYCLETIME->MAT_VER = GET_CYCLETIME_N->MAT_VER;
    MEMCPY_DN(GET_CYCLETIME->FLOW ,GET_CYCLETIME_N->FLOW ,sizeof(GET_CYCLETIME->FLOW ));
    GET_CYCLETIME->FLOW_SEQ_NUM = GET_CYCLETIME_N->FLOW_SEQ_NUM;
    MEMCPY_DN(GET_CYCLETIME->FLOW_DESC ,GET_CYCLETIME_N->FLOW_DESC,sizeof(GET_CYCLETIME->FLOW_DESC));
    MEMCPY_DN(GET_CYCLETIME->OPER , GET_CYCLETIME_N->OPER , sizeof(GET_CYCLETIME->OPER ));
    MEMCPY_DN(GET_CYCLETIME->OPER_DESC , GET_CYCLETIME_N->OPER_DESC, sizeof(GET_CYCLETIME->OPER_DESC));
    GET_CYCLETIME->OPER_SEQ = GET_CYCLETIME_N->OPER_SEQ;
    GET_CYCLETIME->HPU_FLAG = GET_CYCLETIME_N->HPU_FLAG[0];
    GET_CYCLETIME->HPU_PROC_TIME = GET_CYCLETIME_N->HPU_PROC_TIME ;
    GET_CYCLETIME->UPH_FLAG = GET_CYCLETIME_N->UPH_FLAG[0] ;
    GET_CYCLETIME->UPH_PROC_TIME = GET_CYCLETIME_N->UPH_PROC_TIME ;
    GET_CYCLETIME->OPT_LEVEL = GET_CYCLETIME_N->OPT_LEVEL[0] ;
    GET_CYCLETIME->PROC_TIME = GET_CYCLETIME_N->PROC_TIME ;
    GET_CYCLETIME->QUEUE_TIME = GET_CYCLETIME_N->QUEUE_TIME ;
    MEMCPY_DN(GET_CYCLETIME->CREATE_TIME ,GET_CYCLETIME_N->CREATE_TIME , sizeof(GET_CYCLETIME->CREATE_TIME ));
    MEMCPY_DN(GET_CYCLETIME->CREATE_USER_ID ,GET_CYCLETIME_N->CREATE_USER_ID , sizeof(GET_CYCLETIME->CREATE_USER_ID ));
    MEMCPY_DN(GET_CYCLETIME->UPDATE_TIME ,GET_CYCLETIME_N->UPDATE_TIME , sizeof(GET_CYCLETIME->UPDATE_TIME ));
    MEMCPY_DN(GET_CYCLETIME->UPDATE_USER_ID ,GET_CYCLETIME_N->UPDATE_USER_ID , sizeof(GET_CYCLETIME->UPDATE_USER_ID ));
} 

/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_get_lotdetail(int sel_type, struct GET_LOTDETAIL_TAG *GET_LOTDETAIL, struct lot_list *s_lot_list)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct GET_LOTDETAIL_N_TAG GET_LOTDETAIL_N;
        char   sql[10000];
        char   s_in_cond[1500];
        char   s_lot_id[26];
        int    i = 0;
        char   ts[26];
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_get_lotdetail(&GET_LOTDETAIL_N, GET_LOTDETAIL);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            memset(sql, 0x00, sizeof(sql));
            memset(s_in_cond, 0x00, sizeof(s_in_cond));
            memset(ts, 0x00, sizeof(ts));
            
            for (i = 0; i < s_lot_list->count; i++)
            {
                memset(s_lot_id, 0x00, sizeof(s_lot_id));
                memset(ts, 0x00, sizeof(ts));

                MEMCPY_AN(s_lot_id, s_lot_list->list_tbl[i].lot_id, sizeof(s_lot_list->list_tbl[i].lot_id));
                make_valid_quote(ts, s_lot_id);
                sprintf(s_in_cond + strlen(s_in_cond), "'%s'", ts);
                if(i < s_lot_list->count - 1)
                {
                   sprintf(s_in_cond + strlen(s_in_cond), ", "); 
                }   
            }
            
            sprintf(sql,               "SELECT ");
            sprintf(sql + strlen(sql),   "LT.LOT_ID, ");
            sprintf(sql + strlen(sql),   "LT.LOT_DESC, ");
            sprintf(sql + strlen(sql),   "LT.FACTORY, ");
            sprintf(sql + strlen(sql),   "LT.MAT_ID, ");
            sprintf(sql + strlen(sql),   "LT.MAT_VER, ");
            sprintf(sql + strlen(sql),   "LT.FLOW, ");
            sprintf(sql + strlen(sql),   "LT.FLOW_SEQ_NUM, ");
            sprintf(sql + strlen(sql),   "LT.OPER, ");
            sprintf(sql + strlen(sql),   "LT.QTY_1, ");
            sprintf(sql + strlen(sql),   "LT.QTY_2, ");
            sprintf(sql + strlen(sql),   "LT.QTY_3, ");
            sprintf(sql + strlen(sql),   "LT.CRR_ID, ");
            sprintf(sql + strlen(sql),   "LT.LOT_TYPE, ");
            sprintf(sql + strlen(sql),   "LT.OWNER_CODE, ");
            sprintf(sql + strlen(sql),   "LT.CREATE_CODE, ");
            sprintf(sql + strlen(sql),   "LT.LOT_PRIORITY, ");
            sprintf(sql + strlen(sql),   "LT.LOT_STATUS, ");
            sprintf(sql + strlen(sql),   "LT.HOLD_FLAG, ");
            sprintf(sql + strlen(sql),   "LT.HOLD_CODE, ");
            sprintf(sql + strlen(sql),   "LT.HOLD_PASSWORD, ");
            sprintf(sql + strlen(sql),   "LT.HOLD_PRV_GRP_ID, ");
            sprintf(sql + strlen(sql),   "LT.OPER_IN_QTY_1, ");
            sprintf(sql + strlen(sql),   "LT.OPER_IN_QTY_2, ");
            sprintf(sql + strlen(sql),   "LT.OPER_IN_QTY_3, ");
            sprintf(sql + strlen(sql),   "LT.CREATE_QTY_1, ");
            sprintf(sql + strlen(sql),   "LT.CREATE_QTY_2, ");
            sprintf(sql + strlen(sql),   "LT.CREATE_QTY_3, ");
            sprintf(sql + strlen(sql),   "LT.START_QTY_1, ");
            sprintf(sql + strlen(sql),   "LT.START_QTY_2, ");
            sprintf(sql + strlen(sql),   "LT.START_QTY_3, ");
            sprintf(sql + strlen(sql),   "LT.INV_FLAG, ");
            sprintf(sql + strlen(sql),   "LT.TRANSIT_FLAG, ");
            sprintf(sql + strlen(sql),   "LT.UNIT_EXIST_FLAG, ");
            sprintf(sql + strlen(sql),   "LT.INV_UNIT, ");
            sprintf(sql + strlen(sql),   "LT.RWK_FLAG, ");
            sprintf(sql + strlen(sql),   "LT.RWK_CODE, ");
            sprintf(sql + strlen(sql),   "LT.RWK_COUNT, ");
            sprintf(sql + strlen(sql),   "LT.RWK_RET_FLOW, ");
            sprintf(sql + strlen(sql),   "LT.RWK_RET_FLOW_SEQ_NUM, ");
            sprintf(sql + strlen(sql),   "LT.RWK_RET_OPER, ");
            sprintf(sql + strlen(sql),   "LT.RWK_END_FLOW, ");
            sprintf(sql + strlen(sql),   "LT.RWK_END_FLOW_SEQ_NUM, ");
            sprintf(sql + strlen(sql),   "LT.RWK_END_OPER, ");
            sprintf(sql + strlen(sql),   "LT.RWK_RET_CLEAR_FLAG, ");
            sprintf(sql + strlen(sql),   "LT.RWK_TIME, ");
            sprintf(sql + strlen(sql),   "LT.NSTD_FLAG, ");
            sprintf(sql + strlen(sql),   "LT.NSTD_RET_FLOW, ");
            sprintf(sql + strlen(sql),   "LT.NSTD_RET_FLOW_SEQ_NUM, ");
            sprintf(sql + strlen(sql),   "LT.NSTD_RET_OPER, ");
            sprintf(sql + strlen(sql),   "LT.NSTD_TIME, ");
            sprintf(sql + strlen(sql),   "LT.REP_FLAG, ");
            sprintf(sql + strlen(sql),   "LT.REP_RET_OPER, ");
            sprintf(sql + strlen(sql),   "LT.STR_RET_FLOW, ");
            sprintf(sql + strlen(sql),   "LT.STR_RET_FLOW_SEQ_NUM, ");
            sprintf(sql + strlen(sql),   "LT.STR_RET_OPER, ");
            sprintf(sql + strlen(sql),   "LT.START_FLAG, ");
            sprintf(sql + strlen(sql),   "LT.START_TIME, ");
            sprintf(sql + strlen(sql),   "LT.START_RES_ID, ");
            sprintf(sql + strlen(sql),   "LT.END_FLAG, ");
            sprintf(sql + strlen(sql),   "LT.END_TIME, ");
            sprintf(sql + strlen(sql),   "LT.END_RES_ID, ");
            sprintf(sql + strlen(sql),   "LT.SAMPLE_FLAG, ");
            sprintf(sql + strlen(sql),   "LT.SAMPLE_WAIT_FLAG, ");
            sprintf(sql + strlen(sql),   "LT.SAMPLE_RESULT, ");
            sprintf(sql + strlen(sql),   "LT.FROM_TO_FLAG, ");
            sprintf(sql + strlen(sql),   "LT.FROM_TO_LOT_ID, ");
            sprintf(sql + strlen(sql),   "LT.SHIP_CODE, ");
            sprintf(sql + strlen(sql),   "LT.SHIP_TIME, ");
            sprintf(sql + strlen(sql),   "LT.ORG_DUE_TIME, ");
            sprintf(sql + strlen(sql),   "LT.SCH_DUE_TIME, ");
            sprintf(sql + strlen(sql),   "LT.CREATE_TIME, ");
            sprintf(sql + strlen(sql),   "LT.FAC_IN_TIME, ");
            sprintf(sql + strlen(sql),   "LT.FLOW_IN_TIME, ");
            sprintf(sql + strlen(sql),   "LT.OPER_IN_TIME, ");
            sprintf(sql + strlen(sql),   "LT.RESERVE_RES_ID, ");
            sprintf(sql + strlen(sql),   "LT.PORT_ID, ");
            sprintf(sql + strlen(sql),   "LT.BATCH_ID, ");
            sprintf(sql + strlen(sql),   "LT.BATCH_SEQ, ");
            sprintf(sql + strlen(sql),   "LT.ORDER_ID, ");
            sprintf(sql + strlen(sql),   "LT.ADD_ORDER_ID_1, ");
            sprintf(sql + strlen(sql),   "LT.ADD_ORDER_ID_2, ");
            sprintf(sql + strlen(sql),   "LT.ADD_ORDER_ID_3, ");
            sprintf(sql + strlen(sql),   "LT.LOT_LOCATION_1, ");
            sprintf(sql + strlen(sql),   "LT.LOT_LOCATION_2, ");
            sprintf(sql + strlen(sql),   "LT.LOT_LOCATION_3, ");
            sprintf(sql + strlen(sql),   "LT.LOT_CMF_1, ");
            sprintf(sql + strlen(sql),   "LT.LOT_CMF_2, ");
            sprintf(sql + strlen(sql),   "LT.LOT_CMF_3, ");
            sprintf(sql + strlen(sql),   "LT.LOT_CMF_4, ");
            sprintf(sql + strlen(sql),   "LT.LOT_CMF_5, ");
            sprintf(sql + strlen(sql),   "LT.LOT_CMF_6, ");
            sprintf(sql + strlen(sql),   "LT.LOT_CMF_7, ");
            sprintf(sql + strlen(sql),   "LT.LOT_CMF_8, ");
            sprintf(sql + strlen(sql),   "LT.LOT_CMF_9, ");
            sprintf(sql + strlen(sql),   "LT.LOT_CMF_10, ");
            sprintf(sql + strlen(sql),   "LT.LOT_CMF_11, ");
            sprintf(sql + strlen(sql),   "LT.LOT_CMF_12, ");
            sprintf(sql + strlen(sql),   "LT.LOT_CMF_13, ");
            sprintf(sql + strlen(sql),   "LT.LOT_CMF_14, ");
            sprintf(sql + strlen(sql),   "LT.LOT_CMF_15, ");
            sprintf(sql + strlen(sql),   "LT.LOT_CMF_16, ");
            sprintf(sql + strlen(sql),   "LT.LOT_CMF_17, ");
            sprintf(sql + strlen(sql),   "LT.LOT_CMF_18, ");
            sprintf(sql + strlen(sql),   "LT.LOT_CMF_19, ");
            sprintf(sql + strlen(sql),   "LT.LOT_CMF_20, ");
            sprintf(sql + strlen(sql),   "LT.LOT_DEL_FLAG, ");
            sprintf(sql + strlen(sql),   "LT.LOT_DEL_CODE, ");
            sprintf(sql + strlen(sql),   "LT.LOT_DEL_TIME, ");
            sprintf(sql + strlen(sql),   "LT.BOM_SET_ID, ");
            sprintf(sql + strlen(sql),   "LT.BOM_SET_VERSION, ");
            sprintf(sql + strlen(sql),   "LT.BOM_ACTIVE_HIST_SEQ, ");
            sprintf(sql + strlen(sql),   "LT.BOM_HIST_SEQ, ");
            sprintf(sql + strlen(sql),   "LT.LAST_TRAN_CODE, ");
            sprintf(sql + strlen(sql),   "LT.LAST_TRAN_TIME, ");
            sprintf(sql + strlen(sql),   "LT.LAST_COMMENT, ");
            sprintf(sql + strlen(sql),   "LT.LAST_ACTIVE_HIST_SEQ, ");
            sprintf(sql + strlen(sql),   "LT.LAST_HIST_SEQ, ");
            sprintf(sql + strlen(sql),   "LT.CRITICAL_RES_ID, ");
            sprintf(sql + strlen(sql),   "LT.CRITICAL_RES_GROUP_ID, ");
            sprintf(sql + strlen(sql),   "LT.SAVE_RES_ID_1, ");
            sprintf(sql + strlen(sql),   "LT.SAVE_RES_ID_2, ");
            sprintf(sql + strlen(sql),   "LT.SUBRES_ID, ");
            sprintf(sql + strlen(sql),   "LT.LOT_GROUP_ID_1, ");
            sprintf(sql + strlen(sql),   "LT.LOT_GROUP_ID_2, ");
            sprintf(sql + strlen(sql),   "LT.LOT_GROUP_ID_3, ");
            sprintf(sql + strlen(sql),   "LT.YIELD_1, ");
            sprintf(sql + strlen(sql),   "LT.YIELD_2, ");
            sprintf(sql + strlen(sql),   "LT.YIELD_3, ");
            sprintf(sql + strlen(sql),   "LT.GOOD_QTY, ");
            sprintf(sql + strlen(sql),   "LT.RESV_FIELD_1, ");
            sprintf(sql + strlen(sql),   "LT.RESV_FIELD_2, ");
            sprintf(sql + strlen(sql),   "LT.RESV_FIELD_3, ");
            sprintf(sql + strlen(sql),   "LT.RESV_FIELD_4, ");
            sprintf(sql + strlen(sql),   "LT.RESV_FIELD_5, ");
            sprintf(sql + strlen(sql),   "LT.RESV_FLAG_1, ");
            sprintf(sql + strlen(sql),   "LT.RESV_FLAG_2, ");
            sprintf(sql + strlen(sql),   "LT.RESV_FLAG_3, ");
            sprintf(sql + strlen(sql),   "LT.RESV_FLAG_4, ");
            sprintf(sql + strlen(sql),   "LT.RESV_FLAG_5, ");
            sprintf(sql + strlen(sql),   "NVL(MT.MAT_DESC, ' '), NVL(FT.FLOW_DESC, ' '), NVL(OT.OPER_DESC, ' ') ");
            sprintf(sql + strlen(sql), "FROM MWIPLOTSTS LT, MWIPMATDEF MT, MWIPFLWDEF FT, MWIPOPRDEF OT "); 
            sprintf(sql + strlen(sql), "WHERE LT.FACTORY = MT.FACTORY(+) ");
            sprintf(sql + strlen(sql), "AND LT.MAT_ID = MT.MAT_ID(+) ");
            sprintf(sql + strlen(sql), "AND LT.MAT_VER = MT.MAT_VER(+) ");
            sprintf(sql + strlen(sql), "AND LT.FACTORY = FT.FACTORY(+) ");
            sprintf(sql + strlen(sql), "AND LT.FLOW = FT.FLOW(+) ");
            sprintf(sql + strlen(sql), "AND LT.FACTORY = OT.FACTORY(+) ");
            sprintf(sql + strlen(sql), "AND LT.OPER = OT.OPER(+) ");
            sprintf(sql + strlen(sql), "AND LT.FACTORY = '%s' ", GET_LOTDETAIL_N.FACTORY);
            make_valid_quote(ts, GET_LOTDETAIL_N.LOT_ID);
            sprintf(sql + strlen(sql), "AND LT.LOT_ID >= '%s' ", ts);
            sprintf(sql + strlen(sql), "AND LT.LOT_ID IN (%s) ", s_in_cond);            
            sprintf(sql + strlen(sql), "ORDER BY LT.LOT_ID ASC");
            
            /* EXEC SQL PREPARE S FROM :sql; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 17;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )533;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)sql;
            sqlstm.sqhstl[0] = (unsigned int  )10000;
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


            /* EXEC SQL DECLARE DBC_GET_LOTDETAIL_CUR_1 CURSOR FOR S; */ 
 
            /* EXEC SQL OPEN DBC_GET_LOTDETAIL_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 17;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )552;
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
            /* EXEC SQL DECLARE DBC_GET_LOTDETAIL_CUR_2 CURSOR FOR 
                SELECT
                    LT.LOT_ID,
                    LT.LOT_DESC,
                    LT.FACTORY,
                    LT.MAT_ID,
                    LT.MAT_VER,
                    LT.FLOW,
                    LT.FLOW_SEQ_NUM,
                    LT.OPER,
                    LT.QTY_1,
                    LT.QTY_2,
                    LT.QTY_3,
                    LT.CRR_ID,
                    LT.LOT_TYPE,
                    LT.OWNER_CODE,
                    LT.CREATE_CODE,
                    LT.LOT_PRIORITY,
                    LT.LOT_STATUS,
                    LT.HOLD_FLAG,
                    LT.HOLD_CODE,
                    LT.HOLD_PASSWORD,
                    LT.HOLD_PRV_GRP_ID,
                    LT.OPER_IN_QTY_1,
                    LT.OPER_IN_QTY_2,
                    LT.OPER_IN_QTY_3,
                    LT.CREATE_QTY_1,
                    LT.CREATE_QTY_2,
                    LT.CREATE_QTY_3,
                    LT.START_QTY_1,
                    LT.START_QTY_2,
                    LT.START_QTY_3,
                    LT.INV_FLAG,
                    LT.TRANSIT_FLAG,
                    LT.UNIT_EXIST_FLAG,
                    LT.INV_UNIT,
                    LT.RWK_FLAG,
                    LT.RWK_CODE,
                    LT.RWK_COUNT,
                    LT.RWK_RET_FLOW,
                    LT.RWK_RET_FLOW_SEQ_NUM,
                    LT.RWK_RET_OPER,
                    LT.RWK_END_FLOW,
                    LT.RWK_END_FLOW_SEQ_NUM,
                    LT.RWK_END_OPER,
                    LT.RWK_RET_CLEAR_FLAG,
                    LT.RWK_TIME,
                    LT.NSTD_FLAG,
                    LT.NSTD_RET_FLOW,
                    LT.NSTD_RET_FLOW_SEQ_NUM,
                    LT.NSTD_RET_OPER,
                    LT.NSTD_TIME,
                    LT.REP_FLAG,
                    LT.REP_RET_OPER,
                    LT.STR_RET_FLOW,
                    LT.STR_RET_FLOW_SEQ_NUM,
                    LT.STR_RET_OPER,
                    LT.START_FLAG,
                    LT.START_TIME,
                    LT.START_RES_ID,
                    LT.END_FLAG,
                    LT.END_TIME,
                    LT.END_RES_ID,
                    LT.SAMPLE_FLAG,
                    LT.SAMPLE_WAIT_FLAG,
                    LT.SAMPLE_RESULT,
                    LT.FROM_TO_FLAG,
                    LT.FROM_TO_LOT_ID,
                    LT.SHIP_CODE,
                    LT.SHIP_TIME,
                    LT.ORG_DUE_TIME,
                    LT.SCH_DUE_TIME,
                    LT.CREATE_TIME,
                    LT.FAC_IN_TIME,
                    LT.FLOW_IN_TIME,
                    LT.OPER_IN_TIME,
                    LT.RESERVE_RES_ID,
                    LT.PORT_ID,
                    LT.BATCH_ID,
                    LT.BATCH_SEQ,
                    LT.ORDER_ID,
                    LT.ADD_ORDER_ID_1,
                    LT.ADD_ORDER_ID_2,
                    LT.ADD_ORDER_ID_3,
                    LT.LOT_LOCATION_1,
                    LT.LOT_LOCATION_2,
                    LT.LOT_LOCATION_3,
                    LT.LOT_CMF_1,
                    LT.LOT_CMF_2,
                    LT.LOT_CMF_3,
                    LT.LOT_CMF_4,
                    LT.LOT_CMF_5,
                    LT.LOT_CMF_6,
                    LT.LOT_CMF_7,
                    LT.LOT_CMF_8,
                    LT.LOT_CMF_9,
                    LT.LOT_CMF_10,
                    LT.LOT_CMF_11,
                    LT.LOT_CMF_12,
                    LT.LOT_CMF_13,
                    LT.LOT_CMF_14,
                    LT.LOT_CMF_15,
                    LT.LOT_CMF_16,
                    LT.LOT_CMF_17,
                    LT.LOT_CMF_18,
                    LT.LOT_CMF_19,
                    LT.LOT_CMF_20,
                    LT.LOT_DEL_FLAG,
                    LT.LOT_DEL_CODE,
                    LT.LOT_DEL_TIME,
                    LT.BOM_SET_ID,
                    LT.BOM_SET_VERSION,
                    LT.BOM_ACTIVE_HIST_SEQ,
                    LT.BOM_HIST_SEQ,
                    LT.LAST_TRAN_CODE,
                    LT.LAST_TRAN_TIME,
                    LT.LAST_COMMENT,
                    LT.LAST_ACTIVE_HIST_SEQ,
                    LT.LAST_HIST_SEQ,
                    LT.CRITICAL_RES_ID,
                    LT.CRITICAL_RES_GROUP_ID,
                    LT.SAVE_RES_ID_1,
                    LT.SAVE_RES_ID_2,
                    LT.SUBRES_ID,
                    LT.LOT_GROUP_ID_1,
                    LT.LOT_GROUP_ID_2,
                    LT.LOT_GROUP_ID_3,
                    LT.YIELD_1,
                    LT.YIELD_2,
                    LT.YIELD_3,
                    LT.GOOD_QTY,
                    LT.RESV_FIELD_1,
                    LT.RESV_FIELD_2,
                    LT.RESV_FIELD_3,
                    LT.RESV_FIELD_4,
                    LT.RESV_FIELD_5,
                    LT.RESV_FLAG_1,
                    LT.RESV_FLAG_2,
                    LT.RESV_FLAG_3,
                    LT.RESV_FLAG_4,
                    LT.RESV_FLAG_5,
                    MT.MAT_DESC, FT.FLOW_DESC, OT.OPER_DESC
                FROM MWIPLOTSTS LT, MWIPMATDEF MT, MWIPFLWDEF FT, MWIPOPRDEF OT 
                WHERE LT.FACTORY = MT.FACTORY(+)
                    AND LT.MAT_ID = MT.MAT_ID(+)
                    AND LT.MAT_VER = MT.MAT_VER(+)
                    AND LT.FACTORY = FT.FACTORY(+)
                    AND LT.FLOW = FT.FLOW(+)
                    AND LT.FACTORY = OT.FACTORY(+)
                    AND LT.OPER = OT.OPER(+)
                    AND LT.FACTORY = :GET_LOTDETAIL_N.FACTORY
                    AND LT.START_RES_ID = :GET_LOTDETAIL_N.START_RES_ID
                    AND LT.START_FLAG = 'Y'
                    AND LT.LOT_DEL_FLAG = ' '
                    AND LT.LOT_ID >= :GET_LOTDETAIL_N.LOT_ID
                ORDER BY LT.LOT_ID ASC; */ 
 

            /* EXEC SQL OPEN DBC_GET_LOTDETAIL_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 17;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select LT.LOT_ID ,LT.LOT_DESC ,LT.FACTORY ,LT.MAT_ID ,LT.MAT_\
VER ,LT.FLOW ,LT.FLOW_SEQ_NUM ,LT.OPER ,LT.QTY_1 ,LT.QTY_2 ,LT.QTY_3 ,LT.CRR\
_ID ,LT.LOT_TYPE ,LT.OWNER_CODE ,LT.CREATE_CODE ,LT.LOT_PRIORITY ,LT.LOT_STA\
TUS ,LT.HOLD_FLAG ,LT.HOLD_CODE ,LT.HOLD_PASSWORD ,LT.HOLD_PRV_GRP_ID ,LT.OP\
ER_IN_QTY_1 ,LT.OPER_IN_QTY_2 ,LT.OPER_IN_QTY_3 ,LT.CREATE_QTY_1 ,LT.CREATE_\
QTY_2 ,LT.CREATE_QTY_3 ,LT.START_QTY_1 ,LT.START_QTY_2 ,LT.START_QTY_3 ,LT.I\
NV_FLAG ,LT.TRANSIT_FLAG ,LT.UNIT_EXIST_FLAG ,LT.INV_UNIT ,LT.RWK_FLAG ,LT.R\
WK_CODE ,LT.RWK_COUNT ,LT.RWK_RET_FLOW ,LT.RWK_RET_FLOW_SEQ_NUM ,LT.RWK_RET_\
OPER ,LT.RWK_END_FLOW ,LT.RWK_END_FLOW_SEQ_NUM ,LT.RWK_END_OPER ,LT.RWK_RET_\
CLEAR_FLAG ,LT.RWK_TIME ,LT.NSTD_FLAG ,LT.NSTD_RET_FLOW ,LT.NSTD_RET_FLOW_SE\
Q_NUM ,LT.NSTD_RET_OPER ,LT.NSTD_TIME ,LT.REP_FLAG ,LT.REP_RET_OPER ,LT.STR_\
RET_FLOW ,LT.STR_RET_FLOW_SEQ_NUM ,LT.STR_RET_OPER ,LT.START_FLAG ,LT.START_\
TIME ,LT.START_RES_ID ,LT.END_FLAG ,LT.END_TIME ,LT.END_RES_ID ,LT.SAMPLE_FL\
AG ,LT.SAMPLE_WAIT_FLAG ,LT.SAMPLE_RESULT ,LT.FROM_");
            sqlbuft((void **)0,
              "TO_FLAG ,LT.FROM_TO_LOT_ID ,LT.SHIP_CODE ,LT.SHIP_TIME ,LT.OR\
G_DUE_TIME ,LT.SCH_DUE_TIME ,LT.CREATE_TIME ,LT.FAC_IN_TIME ,LT.FLOW_IN_TIME\
 ,LT.OPER_IN_TIME ,LT.RESERVE_RES_ID ,LT.PORT_ID ,LT.BATCH_ID ,LT.BATCH_SEQ \
,LT.ORDER_ID ,LT.ADD_ORDER_ID_1 ,LT.ADD_ORDER_ID_2 ,LT.ADD_ORDER_ID_3 ,LT.LO\
T_LOCATION_1 ,LT.LOT_LOCATION_2 ,LT.LOT_LOCATION_3 ,LT.LOT_CMF_1 ,LT.LOT_CMF\
_2 ,LT.LOT_CMF_3 ,LT.LOT_CMF_4 ,LT.LOT_CMF_5 ,LT.LOT_CMF_6 ,LT.LOT_CMF_7 ,LT\
.LOT_CMF_8 ,LT.LOT_CMF_9 ,LT.LOT_CMF_10 ,LT.LOT_CMF_11 ,LT.LOT_CMF_12 ,LT.LO\
T_CMF_13 ,LT.LOT_CMF_14 ,LT.LOT_CMF_15 ,LT.LOT_CMF_16 ,LT.LOT_CMF_17 ,LT.LOT\
_CMF_18 ,LT.LOT_CMF_19 ,LT.LOT_CMF_20 ,LT.LOT_DEL_FLAG ,LT.LOT_DEL_CODE ,LT.\
LOT_DEL_TIME ,LT.BOM_SET_ID ,LT.BOM_SET_VERSION ,LT.BOM_ACTIVE_HIST_SEQ ,LT.\
BOM_HIST_SEQ ,LT.LAST_TRAN_CODE ,LT.LAST_TRAN_TIME ,LT.LAST_COMMENT ,LT.LAST\
_ACTIVE_HIST_SEQ ,LT.LAST_HIST_SEQ ,LT.CRITICAL_RES_ID ,LT.CRITICAL_RES_GROU\
P_ID ,LT.SAVE_RES_ID_1 ,LT.SAVE_RES_ID_2 ,LT.SUBRES_ID ,LT.LOT_GROUP_ID_1 ,L\
T.LOT_GROUP_ID_2 ,LT.LOT_GROUP_ID_3 ,LT.YIELD_1 ,LT");
            sqlstm.stmt = sq0006;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )567;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(GET_LOTDETAIL_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_LOTDETAIL_N.START_RES_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_LOTDETAIL_N.LOT_ID);
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


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }
    DB_stop_query_timer("DBC_open_get_lotdetail", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_get_lotdetail(int sel_type, struct GET_LOTDETAIL_TAG *GET_LOTDETAIL)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct GET_LOTDETAIL_N_TAG GET_LOTDETAIL_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_GET_LOTDETAIL_CUR_1 INTO
                                                        :GET_LOTDETAIL_N.LOT_ID,
                                                        :GET_LOTDETAIL_N.LOT_DESC,
                                                        :GET_LOTDETAIL_N.FACTORY,
                                                        :GET_LOTDETAIL_N.MAT_ID,
                                                        :GET_LOTDETAIL_N.MAT_VER,
                                                        :GET_LOTDETAIL_N.FLOW,
                                                        :GET_LOTDETAIL_N.FLOW_SEQ_NUM,
                                                        :GET_LOTDETAIL_N.OPER,
                                                        :GET_LOTDETAIL_N.QTY_1,
                                                        :GET_LOTDETAIL_N.QTY_2,
                                                        :GET_LOTDETAIL_N.QTY_3,
                                                        :GET_LOTDETAIL_N.CRR_ID,
                                                        :GET_LOTDETAIL_N.LOT_TYPE,
                                                        :GET_LOTDETAIL_N.OWNER_CODE,
                                                        :GET_LOTDETAIL_N.CREATE_CODE,
                                                        :GET_LOTDETAIL_N.LOT_PRIORITY,
                                                        :GET_LOTDETAIL_N.LOT_STATUS,
                                                        :GET_LOTDETAIL_N.HOLD_FLAG,
                                                        :GET_LOTDETAIL_N.HOLD_CODE,
                                                        :GET_LOTDETAIL_N.HOLD_PASSWORD,
                                                        :GET_LOTDETAIL_N.HOLD_PRV_GRP_ID,
                                                        :GET_LOTDETAIL_N.OPER_IN_QTY_1,
                                                        :GET_LOTDETAIL_N.OPER_IN_QTY_2,
                                                        :GET_LOTDETAIL_N.OPER_IN_QTY_3,
                                                        :GET_LOTDETAIL_N.CREATE_QTY_1,
                                                        :GET_LOTDETAIL_N.CREATE_QTY_2,
                                                        :GET_LOTDETAIL_N.CREATE_QTY_3,
                                                        :GET_LOTDETAIL_N.START_QTY_1,
                                                        :GET_LOTDETAIL_N.START_QTY_2,
                                                        :GET_LOTDETAIL_N.START_QTY_3,
                                                        :GET_LOTDETAIL_N.INV_FLAG,
                                                        :GET_LOTDETAIL_N.TRANSIT_FLAG,
                                                        :GET_LOTDETAIL_N.UNIT_EXIST_FLAG,
                                                        :GET_LOTDETAIL_N.INV_UNIT,
                                                        :GET_LOTDETAIL_N.RWK_FLAG,
                                                        :GET_LOTDETAIL_N.RWK_CODE,
                                                        :GET_LOTDETAIL_N.RWK_COUNT,
                                                        :GET_LOTDETAIL_N.RWK_RET_FLOW,
                                                        :GET_LOTDETAIL_N.RWK_RET_FLOW_SEQ_NUM,
                                                        :GET_LOTDETAIL_N.RWK_RET_OPER,
                                                        :GET_LOTDETAIL_N.RWK_END_FLOW,
                                                        :GET_LOTDETAIL_N.RWK_END_FLOW_SEQ_NUM,
                                                        :GET_LOTDETAIL_N.RWK_END_OPER,
                                                        :GET_LOTDETAIL_N.RWK_RET_CLEAR_FLAG,
                                                        :GET_LOTDETAIL_N.RWK_TIME,
                                                        :GET_LOTDETAIL_N.NSTD_FLAG,
                                                        :GET_LOTDETAIL_N.NSTD_RET_FLOW,
                                                        :GET_LOTDETAIL_N.NSTD_RET_FLOW_SEQ_NUM,
                                                        :GET_LOTDETAIL_N.NSTD_RET_OPER,
                                                        :GET_LOTDETAIL_N.NSTD_TIME,
                                                        :GET_LOTDETAIL_N.REP_FLAG,
                                                        :GET_LOTDETAIL_N.REP_RET_OPER,
                                                        :GET_LOTDETAIL_N.STR_RET_FLOW,
                                                        :GET_LOTDETAIL_N.STR_RET_FLOW_SEQ_NUM,
                                                        :GET_LOTDETAIL_N.STR_RET_OPER,
                                                        :GET_LOTDETAIL_N.START_FLAG,
                                                        :GET_LOTDETAIL_N.START_TIME,
                                                        :GET_LOTDETAIL_N.START_RES_ID,
                                                        :GET_LOTDETAIL_N.END_FLAG,
                                                        :GET_LOTDETAIL_N.END_TIME,
                                                        :GET_LOTDETAIL_N.END_RES_ID,
                                                        :GET_LOTDETAIL_N.SAMPLE_FLAG,
                                                        :GET_LOTDETAIL_N.SAMPLE_WAIT_FLAG,
                                                        :GET_LOTDETAIL_N.SAMPLE_RESULT,
                                                        :GET_LOTDETAIL_N.FROM_TO_FLAG,
                                                        :GET_LOTDETAIL_N.FROM_TO_LOT_ID,
                                                        :GET_LOTDETAIL_N.SHIP_CODE,
                                                        :GET_LOTDETAIL_N.SHIP_TIME,
                                                        :GET_LOTDETAIL_N.ORG_DUE_TIME,
                                                        :GET_LOTDETAIL_N.SCH_DUE_TIME,
                                                        :GET_LOTDETAIL_N.CREATE_TIME,
                                                        :GET_LOTDETAIL_N.FAC_IN_TIME,
                                                        :GET_LOTDETAIL_N.FLOW_IN_TIME,
                                                        :GET_LOTDETAIL_N.OPER_IN_TIME,
                                                        :GET_LOTDETAIL_N.RESERVE_RES_ID,
                                                        :GET_LOTDETAIL_N.PORT_ID,
                                                        :GET_LOTDETAIL_N.BATCH_ID,
                                                        :GET_LOTDETAIL_N.BATCH_SEQ,
                                                        :GET_LOTDETAIL_N.ORDER_ID,
                                                        :GET_LOTDETAIL_N.ADD_ORDER_ID_1,
                                                        :GET_LOTDETAIL_N.ADD_ORDER_ID_2,
                                                        :GET_LOTDETAIL_N.ADD_ORDER_ID_3,
                                                        :GET_LOTDETAIL_N.LOT_LOCATION_1,
                                                        :GET_LOTDETAIL_N.LOT_LOCATION_2,
                                                        :GET_LOTDETAIL_N.LOT_LOCATION_3,
                                                        :GET_LOTDETAIL_N.LOT_CMF_1,
                                                        :GET_LOTDETAIL_N.LOT_CMF_2,
                                                        :GET_LOTDETAIL_N.LOT_CMF_3,
                                                        :GET_LOTDETAIL_N.LOT_CMF_4,
                                                        :GET_LOTDETAIL_N.LOT_CMF_5,
                                                        :GET_LOTDETAIL_N.LOT_CMF_6,
                                                        :GET_LOTDETAIL_N.LOT_CMF_7,
                                                        :GET_LOTDETAIL_N.LOT_CMF_8,
                                                        :GET_LOTDETAIL_N.LOT_CMF_9,
                                                        :GET_LOTDETAIL_N.LOT_CMF_10,
                                                        :GET_LOTDETAIL_N.LOT_CMF_11,
                                                        :GET_LOTDETAIL_N.LOT_CMF_12,
                                                        :GET_LOTDETAIL_N.LOT_CMF_13,
                                                        :GET_LOTDETAIL_N.LOT_CMF_14,
                                                        :GET_LOTDETAIL_N.LOT_CMF_15,
                                                        :GET_LOTDETAIL_N.LOT_CMF_16,
                                                        :GET_LOTDETAIL_N.LOT_CMF_17,
                                                        :GET_LOTDETAIL_N.LOT_CMF_18,
                                                        :GET_LOTDETAIL_N.LOT_CMF_19,
                                                        :GET_LOTDETAIL_N.LOT_CMF_20,
                                                        :GET_LOTDETAIL_N.LOT_DEL_FLAG,
                                                        :GET_LOTDETAIL_N.LOT_DEL_CODE,
                                                        :GET_LOTDETAIL_N.LOT_DEL_TIME,
                                                        :GET_LOTDETAIL_N.BOM_SET_ID,
                                                        :GET_LOTDETAIL_N.BOM_SET_VERSION,
                                                        :GET_LOTDETAIL_N.BOM_ACTIVE_HIST_SEQ,
                                                        :GET_LOTDETAIL_N.BOM_HIST_SEQ,
                                                        :GET_LOTDETAIL_N.LAST_TRAN_CODE,
                                                        :GET_LOTDETAIL_N.LAST_TRAN_TIME,
                                                        :GET_LOTDETAIL_N.LAST_COMMENT,
                                                        :GET_LOTDETAIL_N.LAST_ACTIVE_HIST_SEQ,
                                                        :GET_LOTDETAIL_N.LAST_HIST_SEQ,
                                                        :GET_LOTDETAIL_N.CRITICAL_RES_ID,
                                                        :GET_LOTDETAIL_N.CRITICAL_RES_GROUP_ID,
                                                        :GET_LOTDETAIL_N.SAVE_RES_ID_1,
                                                        :GET_LOTDETAIL_N.SAVE_RES_ID_2,
                                                        :GET_LOTDETAIL_N.SUBRES_ID,
                                                        :GET_LOTDETAIL_N.LOT_GROUP_ID_1,
                                                        :GET_LOTDETAIL_N.LOT_GROUP_ID_2,
                                                        :GET_LOTDETAIL_N.LOT_GROUP_ID_3,
                                                        :GET_LOTDETAIL_N.YIELD_1,
                                                        :GET_LOTDETAIL_N.YIELD_2,
                                                        :GET_LOTDETAIL_N.YIELD_3,
                                                        :GET_LOTDETAIL_N.GOOD_QTY,
                                                        :GET_LOTDETAIL_N.RESV_FIELD_1,
                                                        :GET_LOTDETAIL_N.RESV_FIELD_2,
                                                        :GET_LOTDETAIL_N.RESV_FIELD_3,
                                                        :GET_LOTDETAIL_N.RESV_FIELD_4,
                                                        :GET_LOTDETAIL_N.RESV_FIELD_5,
                                                        :GET_LOTDETAIL_N.RESV_FLAG_1,
                                                        :GET_LOTDETAIL_N.RESV_FLAG_2,
                                                        :GET_LOTDETAIL_N.RESV_FLAG_3,
                                                        :GET_LOTDETAIL_N.RESV_FLAG_4,
                                                        :GET_LOTDETAIL_N.RESV_FLAG_5,
                                                        :GET_LOTDETAIL_N.MAT_DESC,
                                                        :GET_LOTDETAIL_N.FLOW_DESC,
                                                        :GET_LOTDETAIL_N.OPER_DESC; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )594;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(GET_LOTDETAIL_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_LOTDETAIL_N.LOT_DESC);
            sqlstm.sqhstl[1] = (unsigned int  )201;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_LOTDETAIL_N.FACTORY);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_LOTDETAIL_N.MAT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(GET_LOTDETAIL_N.MAT_VER);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(GET_LOTDETAIL_N.FLOW);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(GET_LOTDETAIL_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(GET_LOTDETAIL_N.OPER);
            sqlstm.sqhstl[7] = (unsigned int  )11;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(GET_LOTDETAIL_N.QTY_1);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(GET_LOTDETAIL_N.QTY_2);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(GET_LOTDETAIL_N.QTY_3);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(GET_LOTDETAIL_N.CRR_ID);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(GET_LOTDETAIL_N.LOT_TYPE);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(GET_LOTDETAIL_N.OWNER_CODE);
            sqlstm.sqhstl[13] = (unsigned int  )11;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(GET_LOTDETAIL_N.CREATE_CODE);
            sqlstm.sqhstl[14] = (unsigned int  )11;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(GET_LOTDETAIL_N.LOT_PRIORITY);
            sqlstm.sqhstl[15] = (unsigned int  )2;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(GET_LOTDETAIL_N.LOT_STATUS);
            sqlstm.sqhstl[16] = (unsigned int  )11;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(GET_LOTDETAIL_N.HOLD_FLAG);
            sqlstm.sqhstl[17] = (unsigned int  )2;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(GET_LOTDETAIL_N.HOLD_CODE);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(GET_LOTDETAIL_N.HOLD_PASSWORD);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(GET_LOTDETAIL_N.HOLD_PRV_GRP_ID);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(GET_LOTDETAIL_N.OPER_IN_QTY_1);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(GET_LOTDETAIL_N.OPER_IN_QTY_2);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(GET_LOTDETAIL_N.OPER_IN_QTY_3);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(GET_LOTDETAIL_N.CREATE_QTY_1);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(GET_LOTDETAIL_N.CREATE_QTY_2);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(GET_LOTDETAIL_N.CREATE_QTY_3);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(GET_LOTDETAIL_N.START_QTY_1);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(GET_LOTDETAIL_N.START_QTY_2);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(GET_LOTDETAIL_N.START_QTY_3);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(GET_LOTDETAIL_N.INV_FLAG);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(GET_LOTDETAIL_N.TRANSIT_FLAG);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(GET_LOTDETAIL_N.UNIT_EXIST_FLAG);
            sqlstm.sqhstl[32] = (unsigned int  )2;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(GET_LOTDETAIL_N.INV_UNIT);
            sqlstm.sqhstl[33] = (unsigned int  )11;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(GET_LOTDETAIL_N.RWK_FLAG);
            sqlstm.sqhstl[34] = (unsigned int  )2;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(GET_LOTDETAIL_N.RWK_CODE);
            sqlstm.sqhstl[35] = (unsigned int  )11;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(GET_LOTDETAIL_N.RWK_COUNT);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(GET_LOTDETAIL_N.RWK_RET_FLOW);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(GET_LOTDETAIL_N.RWK_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(GET_LOTDETAIL_N.RWK_RET_OPER);
            sqlstm.sqhstl[39] = (unsigned int  )11;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(GET_LOTDETAIL_N.RWK_END_FLOW);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(GET_LOTDETAIL_N.RWK_END_FLOW_SEQ_NUM);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(GET_LOTDETAIL_N.RWK_END_OPER);
            sqlstm.sqhstl[42] = (unsigned int  )11;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(GET_LOTDETAIL_N.RWK_RET_CLEAR_FLAG);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(GET_LOTDETAIL_N.RWK_TIME);
            sqlstm.sqhstl[44] = (unsigned int  )15;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(GET_LOTDETAIL_N.NSTD_FLAG);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(GET_LOTDETAIL_N.NSTD_RET_FLOW);
            sqlstm.sqhstl[46] = (unsigned int  )21;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(GET_LOTDETAIL_N.NSTD_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(GET_LOTDETAIL_N.NSTD_RET_OPER);
            sqlstm.sqhstl[48] = (unsigned int  )11;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(GET_LOTDETAIL_N.NSTD_TIME);
            sqlstm.sqhstl[49] = (unsigned int  )15;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(GET_LOTDETAIL_N.REP_FLAG);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(GET_LOTDETAIL_N.REP_RET_OPER);
            sqlstm.sqhstl[51] = (unsigned int  )11;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(GET_LOTDETAIL_N.STR_RET_FLOW);
            sqlstm.sqhstl[52] = (unsigned int  )21;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(GET_LOTDETAIL_N.STR_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[53] = (unsigned int  )1;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(GET_LOTDETAIL_N.STR_RET_OPER);
            sqlstm.sqhstl[54] = (unsigned int  )11;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(GET_LOTDETAIL_N.START_FLAG);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(GET_LOTDETAIL_N.START_TIME);
            sqlstm.sqhstl[56] = (unsigned int  )15;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(GET_LOTDETAIL_N.START_RES_ID);
            sqlstm.sqhstl[57] = (unsigned int  )21;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(GET_LOTDETAIL_N.END_FLAG);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(GET_LOTDETAIL_N.END_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(GET_LOTDETAIL_N.END_RES_ID);
            sqlstm.sqhstl[60] = (unsigned int  )21;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(GET_LOTDETAIL_N.SAMPLE_FLAG);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(GET_LOTDETAIL_N.SAMPLE_WAIT_FLAG);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(GET_LOTDETAIL_N.SAMPLE_RESULT);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(GET_LOTDETAIL_N.FROM_TO_FLAG);
            sqlstm.sqhstl[64] = (unsigned int  )2;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(GET_LOTDETAIL_N.FROM_TO_LOT_ID);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(GET_LOTDETAIL_N.SHIP_CODE);
            sqlstm.sqhstl[66] = (unsigned int  )11;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(GET_LOTDETAIL_N.SHIP_TIME);
            sqlstm.sqhstl[67] = (unsigned int  )15;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(GET_LOTDETAIL_N.ORG_DUE_TIME);
            sqlstm.sqhstl[68] = (unsigned int  )15;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(GET_LOTDETAIL_N.SCH_DUE_TIME);
            sqlstm.sqhstl[69] = (unsigned int  )15;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(GET_LOTDETAIL_N.CREATE_TIME);
            sqlstm.sqhstl[70] = (unsigned int  )15;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(GET_LOTDETAIL_N.FAC_IN_TIME);
            sqlstm.sqhstl[71] = (unsigned int  )15;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(GET_LOTDETAIL_N.FLOW_IN_TIME);
            sqlstm.sqhstl[72] = (unsigned int  )15;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(GET_LOTDETAIL_N.OPER_IN_TIME);
            sqlstm.sqhstl[73] = (unsigned int  )15;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(GET_LOTDETAIL_N.RESERVE_RES_ID);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(GET_LOTDETAIL_N.PORT_ID);
            sqlstm.sqhstl[75] = (unsigned int  )11;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(GET_LOTDETAIL_N.BATCH_ID);
            sqlstm.sqhstl[76] = (unsigned int  )26;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)&(GET_LOTDETAIL_N.BATCH_SEQ);
            sqlstm.sqhstl[77] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(GET_LOTDETAIL_N.ORDER_ID);
            sqlstm.sqhstl[78] = (unsigned int  )26;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(GET_LOTDETAIL_N.ADD_ORDER_ID_1);
            sqlstm.sqhstl[79] = (unsigned int  )26;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(GET_LOTDETAIL_N.ADD_ORDER_ID_2);
            sqlstm.sqhstl[80] = (unsigned int  )26;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(GET_LOTDETAIL_N.ADD_ORDER_ID_3);
            sqlstm.sqhstl[81] = (unsigned int  )26;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(GET_LOTDETAIL_N.LOT_LOCATION_1);
            sqlstm.sqhstl[82] = (unsigned int  )21;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(GET_LOTDETAIL_N.LOT_LOCATION_2);
            sqlstm.sqhstl[83] = (unsigned int  )21;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(GET_LOTDETAIL_N.LOT_LOCATION_3);
            sqlstm.sqhstl[84] = (unsigned int  )21;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_1);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_2);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_3);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_4);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_5);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_6);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_7);
            sqlstm.sqhstl[91] = (unsigned int  )31;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_8);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_9);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_10);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_11);
            sqlstm.sqhstl[95] = (unsigned int  )31;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_12);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_13);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_14);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_15);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_16);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_17);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_18);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_19);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_20);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(GET_LOTDETAIL_N.LOT_DEL_FLAG);
            sqlstm.sqhstl[105] = (unsigned int  )2;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(GET_LOTDETAIL_N.LOT_DEL_CODE);
            sqlstm.sqhstl[106] = (unsigned int  )11;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(GET_LOTDETAIL_N.LOT_DEL_TIME);
            sqlstm.sqhstl[107] = (unsigned int  )15;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(GET_LOTDETAIL_N.BOM_SET_ID);
            sqlstm.sqhstl[108] = (unsigned int  )26;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)&(GET_LOTDETAIL_N.BOM_SET_VERSION);
            sqlstm.sqhstl[109] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)&(GET_LOTDETAIL_N.BOM_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[110] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)&(GET_LOTDETAIL_N.BOM_HIST_SEQ);
            sqlstm.sqhstl[111] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(GET_LOTDETAIL_N.LAST_TRAN_CODE);
            sqlstm.sqhstl[112] = (unsigned int  )13;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(GET_LOTDETAIL_N.LAST_TRAN_TIME);
            sqlstm.sqhstl[113] = (unsigned int  )15;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(GET_LOTDETAIL_N.LAST_COMMENT);
            sqlstm.sqhstl[114] = (unsigned int  )401;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)&(GET_LOTDETAIL_N.LAST_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[115] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)&(GET_LOTDETAIL_N.LAST_HIST_SEQ);
            sqlstm.sqhstl[116] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(GET_LOTDETAIL_N.CRITICAL_RES_ID);
            sqlstm.sqhstl[117] = (unsigned int  )21;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(GET_LOTDETAIL_N.CRITICAL_RES_GROUP_ID);
            sqlstm.sqhstl[118] = (unsigned int  )21;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(GET_LOTDETAIL_N.SAVE_RES_ID_1);
            sqlstm.sqhstl[119] = (unsigned int  )21;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(GET_LOTDETAIL_N.SAVE_RES_ID_2);
            sqlstm.sqhstl[120] = (unsigned int  )21;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)(GET_LOTDETAIL_N.SUBRES_ID);
            sqlstm.sqhstl[121] = (unsigned int  )21;
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)(GET_LOTDETAIL_N.LOT_GROUP_ID_1);
            sqlstm.sqhstl[122] = (unsigned int  )26;
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
            sqlstm.sqhstv[123] = (         void  *)(GET_LOTDETAIL_N.LOT_GROUP_ID_2);
            sqlstm.sqhstl[123] = (unsigned int  )26;
            sqlstm.sqhsts[123] = (         int  )0;
            sqlstm.sqindv[123] = (         void  *)0;
            sqlstm.sqinds[123] = (         int  )0;
            sqlstm.sqharm[123] = (unsigned int  )0;
            sqlstm.sqadto[123] = (unsigned short )0;
            sqlstm.sqtdso[123] = (unsigned short )0;
            sqlstm.sqhstv[124] = (         void  *)(GET_LOTDETAIL_N.LOT_GROUP_ID_3);
            sqlstm.sqhstl[124] = (unsigned int  )26;
            sqlstm.sqhsts[124] = (         int  )0;
            sqlstm.sqindv[124] = (         void  *)0;
            sqlstm.sqinds[124] = (         int  )0;
            sqlstm.sqharm[124] = (unsigned int  )0;
            sqlstm.sqadto[124] = (unsigned short )0;
            sqlstm.sqtdso[124] = (unsigned short )0;
            sqlstm.sqhstv[125] = (         void  *)&(GET_LOTDETAIL_N.YIELD_1);
            sqlstm.sqhstl[125] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[125] = (         int  )0;
            sqlstm.sqindv[125] = (         void  *)0;
            sqlstm.sqinds[125] = (         int  )0;
            sqlstm.sqharm[125] = (unsigned int  )0;
            sqlstm.sqadto[125] = (unsigned short )0;
            sqlstm.sqtdso[125] = (unsigned short )0;
            sqlstm.sqhstv[126] = (         void  *)&(GET_LOTDETAIL_N.YIELD_2);
            sqlstm.sqhstl[126] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[126] = (         int  )0;
            sqlstm.sqindv[126] = (         void  *)0;
            sqlstm.sqinds[126] = (         int  )0;
            sqlstm.sqharm[126] = (unsigned int  )0;
            sqlstm.sqadto[126] = (unsigned short )0;
            sqlstm.sqtdso[126] = (unsigned short )0;
            sqlstm.sqhstv[127] = (         void  *)&(GET_LOTDETAIL_N.YIELD_3);
            sqlstm.sqhstl[127] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[127] = (         int  )0;
            sqlstm.sqindv[127] = (         void  *)0;
            sqlstm.sqinds[127] = (         int  )0;
            sqlstm.sqharm[127] = (unsigned int  )0;
            sqlstm.sqadto[127] = (unsigned short )0;
            sqlstm.sqtdso[127] = (unsigned short )0;
            sqlstm.sqhstv[128] = (         void  *)&(GET_LOTDETAIL_N.GOOD_QTY);
            sqlstm.sqhstl[128] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[128] = (         int  )0;
            sqlstm.sqindv[128] = (         void  *)0;
            sqlstm.sqinds[128] = (         int  )0;
            sqlstm.sqharm[128] = (unsigned int  )0;
            sqlstm.sqadto[128] = (unsigned short )0;
            sqlstm.sqtdso[128] = (unsigned short )0;
            sqlstm.sqhstv[129] = (         void  *)(GET_LOTDETAIL_N.RESV_FIELD_1);
            sqlstm.sqhstl[129] = (unsigned int  )31;
            sqlstm.sqhsts[129] = (         int  )0;
            sqlstm.sqindv[129] = (         void  *)0;
            sqlstm.sqinds[129] = (         int  )0;
            sqlstm.sqharm[129] = (unsigned int  )0;
            sqlstm.sqadto[129] = (unsigned short )0;
            sqlstm.sqtdso[129] = (unsigned short )0;
            sqlstm.sqhstv[130] = (         void  *)(GET_LOTDETAIL_N.RESV_FIELD_2);
            sqlstm.sqhstl[130] = (unsigned int  )31;
            sqlstm.sqhsts[130] = (         int  )0;
            sqlstm.sqindv[130] = (         void  *)0;
            sqlstm.sqinds[130] = (         int  )0;
            sqlstm.sqharm[130] = (unsigned int  )0;
            sqlstm.sqadto[130] = (unsigned short )0;
            sqlstm.sqtdso[130] = (unsigned short )0;
            sqlstm.sqhstv[131] = (         void  *)(GET_LOTDETAIL_N.RESV_FIELD_3);
            sqlstm.sqhstl[131] = (unsigned int  )31;
            sqlstm.sqhsts[131] = (         int  )0;
            sqlstm.sqindv[131] = (         void  *)0;
            sqlstm.sqinds[131] = (         int  )0;
            sqlstm.sqharm[131] = (unsigned int  )0;
            sqlstm.sqadto[131] = (unsigned short )0;
            sqlstm.sqtdso[131] = (unsigned short )0;
            sqlstm.sqhstv[132] = (         void  *)(GET_LOTDETAIL_N.RESV_FIELD_4);
            sqlstm.sqhstl[132] = (unsigned int  )31;
            sqlstm.sqhsts[132] = (         int  )0;
            sqlstm.sqindv[132] = (         void  *)0;
            sqlstm.sqinds[132] = (         int  )0;
            sqlstm.sqharm[132] = (unsigned int  )0;
            sqlstm.sqadto[132] = (unsigned short )0;
            sqlstm.sqtdso[132] = (unsigned short )0;
            sqlstm.sqhstv[133] = (         void  *)(GET_LOTDETAIL_N.RESV_FIELD_5);
            sqlstm.sqhstl[133] = (unsigned int  )31;
            sqlstm.sqhsts[133] = (         int  )0;
            sqlstm.sqindv[133] = (         void  *)0;
            sqlstm.sqinds[133] = (         int  )0;
            sqlstm.sqharm[133] = (unsigned int  )0;
            sqlstm.sqadto[133] = (unsigned short )0;
            sqlstm.sqtdso[133] = (unsigned short )0;
            sqlstm.sqhstv[134] = (         void  *)(GET_LOTDETAIL_N.RESV_FLAG_1);
            sqlstm.sqhstl[134] = (unsigned int  )2;
            sqlstm.sqhsts[134] = (         int  )0;
            sqlstm.sqindv[134] = (         void  *)0;
            sqlstm.sqinds[134] = (         int  )0;
            sqlstm.sqharm[134] = (unsigned int  )0;
            sqlstm.sqadto[134] = (unsigned short )0;
            sqlstm.sqtdso[134] = (unsigned short )0;
            sqlstm.sqhstv[135] = (         void  *)(GET_LOTDETAIL_N.RESV_FLAG_2);
            sqlstm.sqhstl[135] = (unsigned int  )2;
            sqlstm.sqhsts[135] = (         int  )0;
            sqlstm.sqindv[135] = (         void  *)0;
            sqlstm.sqinds[135] = (         int  )0;
            sqlstm.sqharm[135] = (unsigned int  )0;
            sqlstm.sqadto[135] = (unsigned short )0;
            sqlstm.sqtdso[135] = (unsigned short )0;
            sqlstm.sqhstv[136] = (         void  *)(GET_LOTDETAIL_N.RESV_FLAG_3);
            sqlstm.sqhstl[136] = (unsigned int  )2;
            sqlstm.sqhsts[136] = (         int  )0;
            sqlstm.sqindv[136] = (         void  *)0;
            sqlstm.sqinds[136] = (         int  )0;
            sqlstm.sqharm[136] = (unsigned int  )0;
            sqlstm.sqadto[136] = (unsigned short )0;
            sqlstm.sqtdso[136] = (unsigned short )0;
            sqlstm.sqhstv[137] = (         void  *)(GET_LOTDETAIL_N.RESV_FLAG_4);
            sqlstm.sqhstl[137] = (unsigned int  )2;
            sqlstm.sqhsts[137] = (         int  )0;
            sqlstm.sqindv[137] = (         void  *)0;
            sqlstm.sqinds[137] = (         int  )0;
            sqlstm.sqharm[137] = (unsigned int  )0;
            sqlstm.sqadto[137] = (unsigned short )0;
            sqlstm.sqtdso[137] = (unsigned short )0;
            sqlstm.sqhstv[138] = (         void  *)(GET_LOTDETAIL_N.RESV_FLAG_5);
            sqlstm.sqhstl[138] = (unsigned int  )2;
            sqlstm.sqhsts[138] = (         int  )0;
            sqlstm.sqindv[138] = (         void  *)0;
            sqlstm.sqinds[138] = (         int  )0;
            sqlstm.sqharm[138] = (unsigned int  )0;
            sqlstm.sqadto[138] = (unsigned short )0;
            sqlstm.sqtdso[138] = (unsigned short )0;
            sqlstm.sqhstv[139] = (         void  *)(GET_LOTDETAIL_N.MAT_DESC);
            sqlstm.sqhstl[139] = (unsigned int  )201;
            sqlstm.sqhsts[139] = (         int  )0;
            sqlstm.sqindv[139] = (         void  *)0;
            sqlstm.sqinds[139] = (         int  )0;
            sqlstm.sqharm[139] = (unsigned int  )0;
            sqlstm.sqadto[139] = (unsigned short )0;
            sqlstm.sqtdso[139] = (unsigned short )0;
            sqlstm.sqhstv[140] = (         void  *)(GET_LOTDETAIL_N.FLOW_DESC);
            sqlstm.sqhstl[140] = (unsigned int  )201;
            sqlstm.sqhsts[140] = (         int  )0;
            sqlstm.sqindv[140] = (         void  *)0;
            sqlstm.sqinds[140] = (         int  )0;
            sqlstm.sqharm[140] = (unsigned int  )0;
            sqlstm.sqadto[140] = (unsigned short )0;
            sqlstm.sqtdso[140] = (unsigned short )0;
            sqlstm.sqhstv[141] = (         void  *)(GET_LOTDETAIL_N.OPER_DESC);
            sqlstm.sqhstl[141] = (unsigned int  )201;
            sqlstm.sqhsts[141] = (         int  )0;
            sqlstm.sqindv[141] = (         void  *)0;
            sqlstm.sqinds[141] = (         int  )0;
            sqlstm.sqharm[141] = (unsigned int  )0;
            sqlstm.sqadto[141] = (unsigned short )0;
            sqlstm.sqtdso[141] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBC_GET_LOTDETAIL_CUR_2 INTO
                                                        :GET_LOTDETAIL_N.LOT_ID,
                                                        :GET_LOTDETAIL_N.LOT_DESC,
                                                        :GET_LOTDETAIL_N.FACTORY,
                                                        :GET_LOTDETAIL_N.MAT_ID,
                                                        :GET_LOTDETAIL_N.MAT_VER,
                                                        :GET_LOTDETAIL_N.FLOW,
                                                        :GET_LOTDETAIL_N.FLOW_SEQ_NUM,
                                                        :GET_LOTDETAIL_N.OPER,
                                                        :GET_LOTDETAIL_N.QTY_1,
                                                        :GET_LOTDETAIL_N.QTY_2,
                                                        :GET_LOTDETAIL_N.QTY_3,
                                                        :GET_LOTDETAIL_N.CRR_ID,
                                                        :GET_LOTDETAIL_N.LOT_TYPE,
                                                        :GET_LOTDETAIL_N.OWNER_CODE,
                                                        :GET_LOTDETAIL_N.CREATE_CODE,
                                                        :GET_LOTDETAIL_N.LOT_PRIORITY,
                                                        :GET_LOTDETAIL_N.LOT_STATUS,
                                                        :GET_LOTDETAIL_N.HOLD_FLAG,
                                                        :GET_LOTDETAIL_N.HOLD_CODE,
                                                        :GET_LOTDETAIL_N.HOLD_PASSWORD,
                                                        :GET_LOTDETAIL_N.HOLD_PRV_GRP_ID,
                                                        :GET_LOTDETAIL_N.OPER_IN_QTY_1,
                                                        :GET_LOTDETAIL_N.OPER_IN_QTY_2,
                                                        :GET_LOTDETAIL_N.OPER_IN_QTY_3,
                                                        :GET_LOTDETAIL_N.CREATE_QTY_1,
                                                        :GET_LOTDETAIL_N.CREATE_QTY_2,
                                                        :GET_LOTDETAIL_N.CREATE_QTY_3,
                                                        :GET_LOTDETAIL_N.START_QTY_1,
                                                        :GET_LOTDETAIL_N.START_QTY_2,
                                                        :GET_LOTDETAIL_N.START_QTY_3,
                                                        :GET_LOTDETAIL_N.INV_FLAG,
                                                        :GET_LOTDETAIL_N.TRANSIT_FLAG,
                                                        :GET_LOTDETAIL_N.UNIT_EXIST_FLAG,
                                                        :GET_LOTDETAIL_N.INV_UNIT,
                                                        :GET_LOTDETAIL_N.RWK_FLAG,
                                                        :GET_LOTDETAIL_N.RWK_CODE,
                                                        :GET_LOTDETAIL_N.RWK_COUNT,
                                                        :GET_LOTDETAIL_N.RWK_RET_FLOW,
                                                        :GET_LOTDETAIL_N.RWK_RET_FLOW_SEQ_NUM,
                                                        :GET_LOTDETAIL_N.RWK_RET_OPER,
                                                        :GET_LOTDETAIL_N.RWK_END_FLOW,
                                                        :GET_LOTDETAIL_N.RWK_END_FLOW_SEQ_NUM,
                                                        :GET_LOTDETAIL_N.RWK_END_OPER,
                                                        :GET_LOTDETAIL_N.RWK_RET_CLEAR_FLAG,
                                                        :GET_LOTDETAIL_N.RWK_TIME,
                                                        :GET_LOTDETAIL_N.NSTD_FLAG,
                                                        :GET_LOTDETAIL_N.NSTD_RET_FLOW,
                                                        :GET_LOTDETAIL_N.NSTD_RET_FLOW_SEQ_NUM,
                                                        :GET_LOTDETAIL_N.NSTD_RET_OPER,
                                                        :GET_LOTDETAIL_N.NSTD_TIME,
                                                        :GET_LOTDETAIL_N.REP_FLAG,
                                                        :GET_LOTDETAIL_N.REP_RET_OPER,
                                                        :GET_LOTDETAIL_N.STR_RET_FLOW,
                                                        :GET_LOTDETAIL_N.STR_RET_FLOW_SEQ_NUM,
                                                        :GET_LOTDETAIL_N.STR_RET_OPER,
                                                        :GET_LOTDETAIL_N.START_FLAG,
                                                        :GET_LOTDETAIL_N.START_TIME,
                                                        :GET_LOTDETAIL_N.START_RES_ID,
                                                        :GET_LOTDETAIL_N.END_FLAG,
                                                        :GET_LOTDETAIL_N.END_TIME,
                                                        :GET_LOTDETAIL_N.END_RES_ID,
                                                        :GET_LOTDETAIL_N.SAMPLE_FLAG,
                                                        :GET_LOTDETAIL_N.SAMPLE_WAIT_FLAG,
                                                        :GET_LOTDETAIL_N.SAMPLE_RESULT,
                                                        :GET_LOTDETAIL_N.FROM_TO_FLAG,
                                                        :GET_LOTDETAIL_N.FROM_TO_LOT_ID,
                                                        :GET_LOTDETAIL_N.SHIP_CODE,
                                                        :GET_LOTDETAIL_N.SHIP_TIME,
                                                        :GET_LOTDETAIL_N.ORG_DUE_TIME,
                                                        :GET_LOTDETAIL_N.SCH_DUE_TIME,
                                                        :GET_LOTDETAIL_N.CREATE_TIME,
                                                        :GET_LOTDETAIL_N.FAC_IN_TIME,
                                                        :GET_LOTDETAIL_N.FLOW_IN_TIME,
                                                        :GET_LOTDETAIL_N.OPER_IN_TIME,
                                                        :GET_LOTDETAIL_N.RESERVE_RES_ID,
                                                        :GET_LOTDETAIL_N.PORT_ID,
                                                        :GET_LOTDETAIL_N.BATCH_ID,
                                                        :GET_LOTDETAIL_N.BATCH_SEQ,
                                                        :GET_LOTDETAIL_N.ORDER_ID,
                                                        :GET_LOTDETAIL_N.ADD_ORDER_ID_1,
                                                        :GET_LOTDETAIL_N.ADD_ORDER_ID_2,
                                                        :GET_LOTDETAIL_N.ADD_ORDER_ID_3,
                                                        :GET_LOTDETAIL_N.LOT_LOCATION_1,
                                                        :GET_LOTDETAIL_N.LOT_LOCATION_2,
                                                        :GET_LOTDETAIL_N.LOT_LOCATION_3,
                                                        :GET_LOTDETAIL_N.LOT_CMF_1,
                                                        :GET_LOTDETAIL_N.LOT_CMF_2,
                                                        :GET_LOTDETAIL_N.LOT_CMF_3,
                                                        :GET_LOTDETAIL_N.LOT_CMF_4,
                                                        :GET_LOTDETAIL_N.LOT_CMF_5,
                                                        :GET_LOTDETAIL_N.LOT_CMF_6,
                                                        :GET_LOTDETAIL_N.LOT_CMF_7,
                                                        :GET_LOTDETAIL_N.LOT_CMF_8,
                                                        :GET_LOTDETAIL_N.LOT_CMF_9,
                                                        :GET_LOTDETAIL_N.LOT_CMF_10,
                                                        :GET_LOTDETAIL_N.LOT_CMF_11,
                                                        :GET_LOTDETAIL_N.LOT_CMF_12,
                                                        :GET_LOTDETAIL_N.LOT_CMF_13,
                                                        :GET_LOTDETAIL_N.LOT_CMF_14,
                                                        :GET_LOTDETAIL_N.LOT_CMF_15,
                                                        :GET_LOTDETAIL_N.LOT_CMF_16,
                                                        :GET_LOTDETAIL_N.LOT_CMF_17,
                                                        :GET_LOTDETAIL_N.LOT_CMF_18,
                                                        :GET_LOTDETAIL_N.LOT_CMF_19,
                                                        :GET_LOTDETAIL_N.LOT_CMF_20,
                                                        :GET_LOTDETAIL_N.LOT_DEL_FLAG,
                                                        :GET_LOTDETAIL_N.LOT_DEL_CODE,
                                                        :GET_LOTDETAIL_N.LOT_DEL_TIME,
                                                        :GET_LOTDETAIL_N.BOM_SET_ID,
                                                        :GET_LOTDETAIL_N.BOM_SET_VERSION,
                                                        :GET_LOTDETAIL_N.BOM_ACTIVE_HIST_SEQ,
                                                        :GET_LOTDETAIL_N.BOM_HIST_SEQ,
                                                        :GET_LOTDETAIL_N.LAST_TRAN_CODE,
                                                        :GET_LOTDETAIL_N.LAST_TRAN_TIME,
                                                        :GET_LOTDETAIL_N.LAST_COMMENT,
                                                        :GET_LOTDETAIL_N.LAST_ACTIVE_HIST_SEQ,
                                                        :GET_LOTDETAIL_N.LAST_HIST_SEQ,
                                                        :GET_LOTDETAIL_N.CRITICAL_RES_ID,
                                                        :GET_LOTDETAIL_N.CRITICAL_RES_GROUP_ID,
                                                        :GET_LOTDETAIL_N.SAVE_RES_ID_1,
                                                        :GET_LOTDETAIL_N.SAVE_RES_ID_2,
                                                        :GET_LOTDETAIL_N.SUBRES_ID,
                                                        :GET_LOTDETAIL_N.LOT_GROUP_ID_1,
                                                        :GET_LOTDETAIL_N.LOT_GROUP_ID_2,
                                                        :GET_LOTDETAIL_N.LOT_GROUP_ID_3,
                                                        :GET_LOTDETAIL_N.YIELD_1,
                                                        :GET_LOTDETAIL_N.YIELD_2,
                                                        :GET_LOTDETAIL_N.YIELD_3,
                                                        :GET_LOTDETAIL_N.GOOD_QTY,
                                                        :GET_LOTDETAIL_N.RESV_FIELD_1,
                                                        :GET_LOTDETAIL_N.RESV_FIELD_2,
                                                        :GET_LOTDETAIL_N.RESV_FIELD_3,
                                                        :GET_LOTDETAIL_N.RESV_FIELD_4,
                                                        :GET_LOTDETAIL_N.RESV_FIELD_5,
                                                        :GET_LOTDETAIL_N.RESV_FLAG_1,
                                                        :GET_LOTDETAIL_N.RESV_FLAG_2,
                                                        :GET_LOTDETAIL_N.RESV_FLAG_3,
                                                        :GET_LOTDETAIL_N.RESV_FLAG_4,
                                                        :GET_LOTDETAIL_N.RESV_FLAG_5,
                                                        :GET_LOTDETAIL_N.MAT_DESC,
                                                        :GET_LOTDETAIL_N.FLOW_DESC,
                                                        :GET_LOTDETAIL_N.OPER_DESC; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1177;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(GET_LOTDETAIL_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_LOTDETAIL_N.LOT_DESC);
            sqlstm.sqhstl[1] = (unsigned int  )201;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_LOTDETAIL_N.FACTORY);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_LOTDETAIL_N.MAT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )31;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(GET_LOTDETAIL_N.MAT_VER);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(GET_LOTDETAIL_N.FLOW);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(GET_LOTDETAIL_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(GET_LOTDETAIL_N.OPER);
            sqlstm.sqhstl[7] = (unsigned int  )11;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(GET_LOTDETAIL_N.QTY_1);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(GET_LOTDETAIL_N.QTY_2);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(GET_LOTDETAIL_N.QTY_3);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(GET_LOTDETAIL_N.CRR_ID);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(GET_LOTDETAIL_N.LOT_TYPE);
            sqlstm.sqhstl[12] = (unsigned int  )2;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(GET_LOTDETAIL_N.OWNER_CODE);
            sqlstm.sqhstl[13] = (unsigned int  )11;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(GET_LOTDETAIL_N.CREATE_CODE);
            sqlstm.sqhstl[14] = (unsigned int  )11;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(GET_LOTDETAIL_N.LOT_PRIORITY);
            sqlstm.sqhstl[15] = (unsigned int  )2;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(GET_LOTDETAIL_N.LOT_STATUS);
            sqlstm.sqhstl[16] = (unsigned int  )11;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(GET_LOTDETAIL_N.HOLD_FLAG);
            sqlstm.sqhstl[17] = (unsigned int  )2;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(GET_LOTDETAIL_N.HOLD_CODE);
            sqlstm.sqhstl[18] = (unsigned int  )11;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(GET_LOTDETAIL_N.HOLD_PASSWORD);
            sqlstm.sqhstl[19] = (unsigned int  )21;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)(GET_LOTDETAIL_N.HOLD_PRV_GRP_ID);
            sqlstm.sqhstl[20] = (unsigned int  )21;
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)&(GET_LOTDETAIL_N.OPER_IN_QTY_1);
            sqlstm.sqhstl[21] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(GET_LOTDETAIL_N.OPER_IN_QTY_2);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)&(GET_LOTDETAIL_N.OPER_IN_QTY_3);
            sqlstm.sqhstl[23] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(GET_LOTDETAIL_N.CREATE_QTY_1);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(GET_LOTDETAIL_N.CREATE_QTY_2);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(GET_LOTDETAIL_N.CREATE_QTY_3);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(GET_LOTDETAIL_N.START_QTY_1);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(GET_LOTDETAIL_N.START_QTY_2);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(GET_LOTDETAIL_N.START_QTY_3);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[29] = (         int  )0;
            sqlstm.sqindv[29] = (         void  *)0;
            sqlstm.sqinds[29] = (         int  )0;
            sqlstm.sqharm[29] = (unsigned int  )0;
            sqlstm.sqadto[29] = (unsigned short )0;
            sqlstm.sqtdso[29] = (unsigned short )0;
            sqlstm.sqhstv[30] = (         void  *)(GET_LOTDETAIL_N.INV_FLAG);
            sqlstm.sqhstl[30] = (unsigned int  )2;
            sqlstm.sqhsts[30] = (         int  )0;
            sqlstm.sqindv[30] = (         void  *)0;
            sqlstm.sqinds[30] = (         int  )0;
            sqlstm.sqharm[30] = (unsigned int  )0;
            sqlstm.sqadto[30] = (unsigned short )0;
            sqlstm.sqtdso[30] = (unsigned short )0;
            sqlstm.sqhstv[31] = (         void  *)(GET_LOTDETAIL_N.TRANSIT_FLAG);
            sqlstm.sqhstl[31] = (unsigned int  )2;
            sqlstm.sqhsts[31] = (         int  )0;
            sqlstm.sqindv[31] = (         void  *)0;
            sqlstm.sqinds[31] = (         int  )0;
            sqlstm.sqharm[31] = (unsigned int  )0;
            sqlstm.sqadto[31] = (unsigned short )0;
            sqlstm.sqtdso[31] = (unsigned short )0;
            sqlstm.sqhstv[32] = (         void  *)(GET_LOTDETAIL_N.UNIT_EXIST_FLAG);
            sqlstm.sqhstl[32] = (unsigned int  )2;
            sqlstm.sqhsts[32] = (         int  )0;
            sqlstm.sqindv[32] = (         void  *)0;
            sqlstm.sqinds[32] = (         int  )0;
            sqlstm.sqharm[32] = (unsigned int  )0;
            sqlstm.sqadto[32] = (unsigned short )0;
            sqlstm.sqtdso[32] = (unsigned short )0;
            sqlstm.sqhstv[33] = (         void  *)(GET_LOTDETAIL_N.INV_UNIT);
            sqlstm.sqhstl[33] = (unsigned int  )11;
            sqlstm.sqhsts[33] = (         int  )0;
            sqlstm.sqindv[33] = (         void  *)0;
            sqlstm.sqinds[33] = (         int  )0;
            sqlstm.sqharm[33] = (unsigned int  )0;
            sqlstm.sqadto[33] = (unsigned short )0;
            sqlstm.sqtdso[33] = (unsigned short )0;
            sqlstm.sqhstv[34] = (         void  *)(GET_LOTDETAIL_N.RWK_FLAG);
            sqlstm.sqhstl[34] = (unsigned int  )2;
            sqlstm.sqhsts[34] = (         int  )0;
            sqlstm.sqindv[34] = (         void  *)0;
            sqlstm.sqinds[34] = (         int  )0;
            sqlstm.sqharm[34] = (unsigned int  )0;
            sqlstm.sqadto[34] = (unsigned short )0;
            sqlstm.sqtdso[34] = (unsigned short )0;
            sqlstm.sqhstv[35] = (         void  *)(GET_LOTDETAIL_N.RWK_CODE);
            sqlstm.sqhstl[35] = (unsigned int  )11;
            sqlstm.sqhsts[35] = (         int  )0;
            sqlstm.sqindv[35] = (         void  *)0;
            sqlstm.sqinds[35] = (         int  )0;
            sqlstm.sqharm[35] = (unsigned int  )0;
            sqlstm.sqadto[35] = (unsigned short )0;
            sqlstm.sqtdso[35] = (unsigned short )0;
            sqlstm.sqhstv[36] = (         void  *)&(GET_LOTDETAIL_N.RWK_COUNT);
            sqlstm.sqhstl[36] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[36] = (         int  )0;
            sqlstm.sqindv[36] = (         void  *)0;
            sqlstm.sqinds[36] = (         int  )0;
            sqlstm.sqharm[36] = (unsigned int  )0;
            sqlstm.sqadto[36] = (unsigned short )0;
            sqlstm.sqtdso[36] = (unsigned short )0;
            sqlstm.sqhstv[37] = (         void  *)(GET_LOTDETAIL_N.RWK_RET_FLOW);
            sqlstm.sqhstl[37] = (unsigned int  )21;
            sqlstm.sqhsts[37] = (         int  )0;
            sqlstm.sqindv[37] = (         void  *)0;
            sqlstm.sqinds[37] = (         int  )0;
            sqlstm.sqharm[37] = (unsigned int  )0;
            sqlstm.sqadto[37] = (unsigned short )0;
            sqlstm.sqtdso[37] = (unsigned short )0;
            sqlstm.sqhstv[38] = (         void  *)&(GET_LOTDETAIL_N.RWK_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[38] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[38] = (         int  )0;
            sqlstm.sqindv[38] = (         void  *)0;
            sqlstm.sqinds[38] = (         int  )0;
            sqlstm.sqharm[38] = (unsigned int  )0;
            sqlstm.sqadto[38] = (unsigned short )0;
            sqlstm.sqtdso[38] = (unsigned short )0;
            sqlstm.sqhstv[39] = (         void  *)(GET_LOTDETAIL_N.RWK_RET_OPER);
            sqlstm.sqhstl[39] = (unsigned int  )11;
            sqlstm.sqhsts[39] = (         int  )0;
            sqlstm.sqindv[39] = (         void  *)0;
            sqlstm.sqinds[39] = (         int  )0;
            sqlstm.sqharm[39] = (unsigned int  )0;
            sqlstm.sqadto[39] = (unsigned short )0;
            sqlstm.sqtdso[39] = (unsigned short )0;
            sqlstm.sqhstv[40] = (         void  *)(GET_LOTDETAIL_N.RWK_END_FLOW);
            sqlstm.sqhstl[40] = (unsigned int  )21;
            sqlstm.sqhsts[40] = (         int  )0;
            sqlstm.sqindv[40] = (         void  *)0;
            sqlstm.sqinds[40] = (         int  )0;
            sqlstm.sqharm[40] = (unsigned int  )0;
            sqlstm.sqadto[40] = (unsigned short )0;
            sqlstm.sqtdso[40] = (unsigned short )0;
            sqlstm.sqhstv[41] = (         void  *)&(GET_LOTDETAIL_N.RWK_END_FLOW_SEQ_NUM);
            sqlstm.sqhstl[41] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[41] = (         int  )0;
            sqlstm.sqindv[41] = (         void  *)0;
            sqlstm.sqinds[41] = (         int  )0;
            sqlstm.sqharm[41] = (unsigned int  )0;
            sqlstm.sqadto[41] = (unsigned short )0;
            sqlstm.sqtdso[41] = (unsigned short )0;
            sqlstm.sqhstv[42] = (         void  *)(GET_LOTDETAIL_N.RWK_END_OPER);
            sqlstm.sqhstl[42] = (unsigned int  )11;
            sqlstm.sqhsts[42] = (         int  )0;
            sqlstm.sqindv[42] = (         void  *)0;
            sqlstm.sqinds[42] = (         int  )0;
            sqlstm.sqharm[42] = (unsigned int  )0;
            sqlstm.sqadto[42] = (unsigned short )0;
            sqlstm.sqtdso[42] = (unsigned short )0;
            sqlstm.sqhstv[43] = (         void  *)(GET_LOTDETAIL_N.RWK_RET_CLEAR_FLAG);
            sqlstm.sqhstl[43] = (unsigned int  )2;
            sqlstm.sqhsts[43] = (         int  )0;
            sqlstm.sqindv[43] = (         void  *)0;
            sqlstm.sqinds[43] = (         int  )0;
            sqlstm.sqharm[43] = (unsigned int  )0;
            sqlstm.sqadto[43] = (unsigned short )0;
            sqlstm.sqtdso[43] = (unsigned short )0;
            sqlstm.sqhstv[44] = (         void  *)(GET_LOTDETAIL_N.RWK_TIME);
            sqlstm.sqhstl[44] = (unsigned int  )15;
            sqlstm.sqhsts[44] = (         int  )0;
            sqlstm.sqindv[44] = (         void  *)0;
            sqlstm.sqinds[44] = (         int  )0;
            sqlstm.sqharm[44] = (unsigned int  )0;
            sqlstm.sqadto[44] = (unsigned short )0;
            sqlstm.sqtdso[44] = (unsigned short )0;
            sqlstm.sqhstv[45] = (         void  *)(GET_LOTDETAIL_N.NSTD_FLAG);
            sqlstm.sqhstl[45] = (unsigned int  )2;
            sqlstm.sqhsts[45] = (         int  )0;
            sqlstm.sqindv[45] = (         void  *)0;
            sqlstm.sqinds[45] = (         int  )0;
            sqlstm.sqharm[45] = (unsigned int  )0;
            sqlstm.sqadto[45] = (unsigned short )0;
            sqlstm.sqtdso[45] = (unsigned short )0;
            sqlstm.sqhstv[46] = (         void  *)(GET_LOTDETAIL_N.NSTD_RET_FLOW);
            sqlstm.sqhstl[46] = (unsigned int  )21;
            sqlstm.sqhsts[46] = (         int  )0;
            sqlstm.sqindv[46] = (         void  *)0;
            sqlstm.sqinds[46] = (         int  )0;
            sqlstm.sqharm[46] = (unsigned int  )0;
            sqlstm.sqadto[46] = (unsigned short )0;
            sqlstm.sqtdso[46] = (unsigned short )0;
            sqlstm.sqhstv[47] = (         void  *)&(GET_LOTDETAIL_N.NSTD_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[47] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[47] = (         int  )0;
            sqlstm.sqindv[47] = (         void  *)0;
            sqlstm.sqinds[47] = (         int  )0;
            sqlstm.sqharm[47] = (unsigned int  )0;
            sqlstm.sqadto[47] = (unsigned short )0;
            sqlstm.sqtdso[47] = (unsigned short )0;
            sqlstm.sqhstv[48] = (         void  *)(GET_LOTDETAIL_N.NSTD_RET_OPER);
            sqlstm.sqhstl[48] = (unsigned int  )11;
            sqlstm.sqhsts[48] = (         int  )0;
            sqlstm.sqindv[48] = (         void  *)0;
            sqlstm.sqinds[48] = (         int  )0;
            sqlstm.sqharm[48] = (unsigned int  )0;
            sqlstm.sqadto[48] = (unsigned short )0;
            sqlstm.sqtdso[48] = (unsigned short )0;
            sqlstm.sqhstv[49] = (         void  *)(GET_LOTDETAIL_N.NSTD_TIME);
            sqlstm.sqhstl[49] = (unsigned int  )15;
            sqlstm.sqhsts[49] = (         int  )0;
            sqlstm.sqindv[49] = (         void  *)0;
            sqlstm.sqinds[49] = (         int  )0;
            sqlstm.sqharm[49] = (unsigned int  )0;
            sqlstm.sqadto[49] = (unsigned short )0;
            sqlstm.sqtdso[49] = (unsigned short )0;
            sqlstm.sqhstv[50] = (         void  *)(GET_LOTDETAIL_N.REP_FLAG);
            sqlstm.sqhstl[50] = (unsigned int  )2;
            sqlstm.sqhsts[50] = (         int  )0;
            sqlstm.sqindv[50] = (         void  *)0;
            sqlstm.sqinds[50] = (         int  )0;
            sqlstm.sqharm[50] = (unsigned int  )0;
            sqlstm.sqadto[50] = (unsigned short )0;
            sqlstm.sqtdso[50] = (unsigned short )0;
            sqlstm.sqhstv[51] = (         void  *)(GET_LOTDETAIL_N.REP_RET_OPER);
            sqlstm.sqhstl[51] = (unsigned int  )11;
            sqlstm.sqhsts[51] = (         int  )0;
            sqlstm.sqindv[51] = (         void  *)0;
            sqlstm.sqinds[51] = (         int  )0;
            sqlstm.sqharm[51] = (unsigned int  )0;
            sqlstm.sqadto[51] = (unsigned short )0;
            sqlstm.sqtdso[51] = (unsigned short )0;
            sqlstm.sqhstv[52] = (         void  *)(GET_LOTDETAIL_N.STR_RET_FLOW);
            sqlstm.sqhstl[52] = (unsigned int  )21;
            sqlstm.sqhsts[52] = (         int  )0;
            sqlstm.sqindv[52] = (         void  *)0;
            sqlstm.sqinds[52] = (         int  )0;
            sqlstm.sqharm[52] = (unsigned int  )0;
            sqlstm.sqadto[52] = (unsigned short )0;
            sqlstm.sqtdso[52] = (unsigned short )0;
            sqlstm.sqhstv[53] = (         void  *)&(GET_LOTDETAIL_N.STR_RET_FLOW_SEQ_NUM);
            sqlstm.sqhstl[53] = (unsigned int  )1;
            sqlstm.sqhsts[53] = (         int  )0;
            sqlstm.sqindv[53] = (         void  *)0;
            sqlstm.sqinds[53] = (         int  )0;
            sqlstm.sqharm[53] = (unsigned int  )0;
            sqlstm.sqadto[53] = (unsigned short )0;
            sqlstm.sqtdso[53] = (unsigned short )0;
            sqlstm.sqhstv[54] = (         void  *)(GET_LOTDETAIL_N.STR_RET_OPER);
            sqlstm.sqhstl[54] = (unsigned int  )11;
            sqlstm.sqhsts[54] = (         int  )0;
            sqlstm.sqindv[54] = (         void  *)0;
            sqlstm.sqinds[54] = (         int  )0;
            sqlstm.sqharm[54] = (unsigned int  )0;
            sqlstm.sqadto[54] = (unsigned short )0;
            sqlstm.sqtdso[54] = (unsigned short )0;
            sqlstm.sqhstv[55] = (         void  *)(GET_LOTDETAIL_N.START_FLAG);
            sqlstm.sqhstl[55] = (unsigned int  )2;
            sqlstm.sqhsts[55] = (         int  )0;
            sqlstm.sqindv[55] = (         void  *)0;
            sqlstm.sqinds[55] = (         int  )0;
            sqlstm.sqharm[55] = (unsigned int  )0;
            sqlstm.sqadto[55] = (unsigned short )0;
            sqlstm.sqtdso[55] = (unsigned short )0;
            sqlstm.sqhstv[56] = (         void  *)(GET_LOTDETAIL_N.START_TIME);
            sqlstm.sqhstl[56] = (unsigned int  )15;
            sqlstm.sqhsts[56] = (         int  )0;
            sqlstm.sqindv[56] = (         void  *)0;
            sqlstm.sqinds[56] = (         int  )0;
            sqlstm.sqharm[56] = (unsigned int  )0;
            sqlstm.sqadto[56] = (unsigned short )0;
            sqlstm.sqtdso[56] = (unsigned short )0;
            sqlstm.sqhstv[57] = (         void  *)(GET_LOTDETAIL_N.START_RES_ID);
            sqlstm.sqhstl[57] = (unsigned int  )21;
            sqlstm.sqhsts[57] = (         int  )0;
            sqlstm.sqindv[57] = (         void  *)0;
            sqlstm.sqinds[57] = (         int  )0;
            sqlstm.sqharm[57] = (unsigned int  )0;
            sqlstm.sqadto[57] = (unsigned short )0;
            sqlstm.sqtdso[57] = (unsigned short )0;
            sqlstm.sqhstv[58] = (         void  *)(GET_LOTDETAIL_N.END_FLAG);
            sqlstm.sqhstl[58] = (unsigned int  )2;
            sqlstm.sqhsts[58] = (         int  )0;
            sqlstm.sqindv[58] = (         void  *)0;
            sqlstm.sqinds[58] = (         int  )0;
            sqlstm.sqharm[58] = (unsigned int  )0;
            sqlstm.sqadto[58] = (unsigned short )0;
            sqlstm.sqtdso[58] = (unsigned short )0;
            sqlstm.sqhstv[59] = (         void  *)(GET_LOTDETAIL_N.END_TIME);
            sqlstm.sqhstl[59] = (unsigned int  )15;
            sqlstm.sqhsts[59] = (         int  )0;
            sqlstm.sqindv[59] = (         void  *)0;
            sqlstm.sqinds[59] = (         int  )0;
            sqlstm.sqharm[59] = (unsigned int  )0;
            sqlstm.sqadto[59] = (unsigned short )0;
            sqlstm.sqtdso[59] = (unsigned short )0;
            sqlstm.sqhstv[60] = (         void  *)(GET_LOTDETAIL_N.END_RES_ID);
            sqlstm.sqhstl[60] = (unsigned int  )21;
            sqlstm.sqhsts[60] = (         int  )0;
            sqlstm.sqindv[60] = (         void  *)0;
            sqlstm.sqinds[60] = (         int  )0;
            sqlstm.sqharm[60] = (unsigned int  )0;
            sqlstm.sqadto[60] = (unsigned short )0;
            sqlstm.sqtdso[60] = (unsigned short )0;
            sqlstm.sqhstv[61] = (         void  *)(GET_LOTDETAIL_N.SAMPLE_FLAG);
            sqlstm.sqhstl[61] = (unsigned int  )2;
            sqlstm.sqhsts[61] = (         int  )0;
            sqlstm.sqindv[61] = (         void  *)0;
            sqlstm.sqinds[61] = (         int  )0;
            sqlstm.sqharm[61] = (unsigned int  )0;
            sqlstm.sqadto[61] = (unsigned short )0;
            sqlstm.sqtdso[61] = (unsigned short )0;
            sqlstm.sqhstv[62] = (         void  *)(GET_LOTDETAIL_N.SAMPLE_WAIT_FLAG);
            sqlstm.sqhstl[62] = (unsigned int  )2;
            sqlstm.sqhsts[62] = (         int  )0;
            sqlstm.sqindv[62] = (         void  *)0;
            sqlstm.sqinds[62] = (         int  )0;
            sqlstm.sqharm[62] = (unsigned int  )0;
            sqlstm.sqadto[62] = (unsigned short )0;
            sqlstm.sqtdso[62] = (unsigned short )0;
            sqlstm.sqhstv[63] = (         void  *)(GET_LOTDETAIL_N.SAMPLE_RESULT);
            sqlstm.sqhstl[63] = (unsigned int  )2;
            sqlstm.sqhsts[63] = (         int  )0;
            sqlstm.sqindv[63] = (         void  *)0;
            sqlstm.sqinds[63] = (         int  )0;
            sqlstm.sqharm[63] = (unsigned int  )0;
            sqlstm.sqadto[63] = (unsigned short )0;
            sqlstm.sqtdso[63] = (unsigned short )0;
            sqlstm.sqhstv[64] = (         void  *)(GET_LOTDETAIL_N.FROM_TO_FLAG);
            sqlstm.sqhstl[64] = (unsigned int  )2;
            sqlstm.sqhsts[64] = (         int  )0;
            sqlstm.sqindv[64] = (         void  *)0;
            sqlstm.sqinds[64] = (         int  )0;
            sqlstm.sqharm[64] = (unsigned int  )0;
            sqlstm.sqadto[64] = (unsigned short )0;
            sqlstm.sqtdso[64] = (unsigned short )0;
            sqlstm.sqhstv[65] = (         void  *)(GET_LOTDETAIL_N.FROM_TO_LOT_ID);
            sqlstm.sqhstl[65] = (unsigned int  )26;
            sqlstm.sqhsts[65] = (         int  )0;
            sqlstm.sqindv[65] = (         void  *)0;
            sqlstm.sqinds[65] = (         int  )0;
            sqlstm.sqharm[65] = (unsigned int  )0;
            sqlstm.sqadto[65] = (unsigned short )0;
            sqlstm.sqtdso[65] = (unsigned short )0;
            sqlstm.sqhstv[66] = (         void  *)(GET_LOTDETAIL_N.SHIP_CODE);
            sqlstm.sqhstl[66] = (unsigned int  )11;
            sqlstm.sqhsts[66] = (         int  )0;
            sqlstm.sqindv[66] = (         void  *)0;
            sqlstm.sqinds[66] = (         int  )0;
            sqlstm.sqharm[66] = (unsigned int  )0;
            sqlstm.sqadto[66] = (unsigned short )0;
            sqlstm.sqtdso[66] = (unsigned short )0;
            sqlstm.sqhstv[67] = (         void  *)(GET_LOTDETAIL_N.SHIP_TIME);
            sqlstm.sqhstl[67] = (unsigned int  )15;
            sqlstm.sqhsts[67] = (         int  )0;
            sqlstm.sqindv[67] = (         void  *)0;
            sqlstm.sqinds[67] = (         int  )0;
            sqlstm.sqharm[67] = (unsigned int  )0;
            sqlstm.sqadto[67] = (unsigned short )0;
            sqlstm.sqtdso[67] = (unsigned short )0;
            sqlstm.sqhstv[68] = (         void  *)(GET_LOTDETAIL_N.ORG_DUE_TIME);
            sqlstm.sqhstl[68] = (unsigned int  )15;
            sqlstm.sqhsts[68] = (         int  )0;
            sqlstm.sqindv[68] = (         void  *)0;
            sqlstm.sqinds[68] = (         int  )0;
            sqlstm.sqharm[68] = (unsigned int  )0;
            sqlstm.sqadto[68] = (unsigned short )0;
            sqlstm.sqtdso[68] = (unsigned short )0;
            sqlstm.sqhstv[69] = (         void  *)(GET_LOTDETAIL_N.SCH_DUE_TIME);
            sqlstm.sqhstl[69] = (unsigned int  )15;
            sqlstm.sqhsts[69] = (         int  )0;
            sqlstm.sqindv[69] = (         void  *)0;
            sqlstm.sqinds[69] = (         int  )0;
            sqlstm.sqharm[69] = (unsigned int  )0;
            sqlstm.sqadto[69] = (unsigned short )0;
            sqlstm.sqtdso[69] = (unsigned short )0;
            sqlstm.sqhstv[70] = (         void  *)(GET_LOTDETAIL_N.CREATE_TIME);
            sqlstm.sqhstl[70] = (unsigned int  )15;
            sqlstm.sqhsts[70] = (         int  )0;
            sqlstm.sqindv[70] = (         void  *)0;
            sqlstm.sqinds[70] = (         int  )0;
            sqlstm.sqharm[70] = (unsigned int  )0;
            sqlstm.sqadto[70] = (unsigned short )0;
            sqlstm.sqtdso[70] = (unsigned short )0;
            sqlstm.sqhstv[71] = (         void  *)(GET_LOTDETAIL_N.FAC_IN_TIME);
            sqlstm.sqhstl[71] = (unsigned int  )15;
            sqlstm.sqhsts[71] = (         int  )0;
            sqlstm.sqindv[71] = (         void  *)0;
            sqlstm.sqinds[71] = (         int  )0;
            sqlstm.sqharm[71] = (unsigned int  )0;
            sqlstm.sqadto[71] = (unsigned short )0;
            sqlstm.sqtdso[71] = (unsigned short )0;
            sqlstm.sqhstv[72] = (         void  *)(GET_LOTDETAIL_N.FLOW_IN_TIME);
            sqlstm.sqhstl[72] = (unsigned int  )15;
            sqlstm.sqhsts[72] = (         int  )0;
            sqlstm.sqindv[72] = (         void  *)0;
            sqlstm.sqinds[72] = (         int  )0;
            sqlstm.sqharm[72] = (unsigned int  )0;
            sqlstm.sqadto[72] = (unsigned short )0;
            sqlstm.sqtdso[72] = (unsigned short )0;
            sqlstm.sqhstv[73] = (         void  *)(GET_LOTDETAIL_N.OPER_IN_TIME);
            sqlstm.sqhstl[73] = (unsigned int  )15;
            sqlstm.sqhsts[73] = (         int  )0;
            sqlstm.sqindv[73] = (         void  *)0;
            sqlstm.sqinds[73] = (         int  )0;
            sqlstm.sqharm[73] = (unsigned int  )0;
            sqlstm.sqadto[73] = (unsigned short )0;
            sqlstm.sqtdso[73] = (unsigned short )0;
            sqlstm.sqhstv[74] = (         void  *)(GET_LOTDETAIL_N.RESERVE_RES_ID);
            sqlstm.sqhstl[74] = (unsigned int  )21;
            sqlstm.sqhsts[74] = (         int  )0;
            sqlstm.sqindv[74] = (         void  *)0;
            sqlstm.sqinds[74] = (         int  )0;
            sqlstm.sqharm[74] = (unsigned int  )0;
            sqlstm.sqadto[74] = (unsigned short )0;
            sqlstm.sqtdso[74] = (unsigned short )0;
            sqlstm.sqhstv[75] = (         void  *)(GET_LOTDETAIL_N.PORT_ID);
            sqlstm.sqhstl[75] = (unsigned int  )11;
            sqlstm.sqhsts[75] = (         int  )0;
            sqlstm.sqindv[75] = (         void  *)0;
            sqlstm.sqinds[75] = (         int  )0;
            sqlstm.sqharm[75] = (unsigned int  )0;
            sqlstm.sqadto[75] = (unsigned short )0;
            sqlstm.sqtdso[75] = (unsigned short )0;
            sqlstm.sqhstv[76] = (         void  *)(GET_LOTDETAIL_N.BATCH_ID);
            sqlstm.sqhstl[76] = (unsigned int  )26;
            sqlstm.sqhsts[76] = (         int  )0;
            sqlstm.sqindv[76] = (         void  *)0;
            sqlstm.sqinds[76] = (         int  )0;
            sqlstm.sqharm[76] = (unsigned int  )0;
            sqlstm.sqadto[76] = (unsigned short )0;
            sqlstm.sqtdso[76] = (unsigned short )0;
            sqlstm.sqhstv[77] = (         void  *)&(GET_LOTDETAIL_N.BATCH_SEQ);
            sqlstm.sqhstl[77] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[77] = (         int  )0;
            sqlstm.sqindv[77] = (         void  *)0;
            sqlstm.sqinds[77] = (         int  )0;
            sqlstm.sqharm[77] = (unsigned int  )0;
            sqlstm.sqadto[77] = (unsigned short )0;
            sqlstm.sqtdso[77] = (unsigned short )0;
            sqlstm.sqhstv[78] = (         void  *)(GET_LOTDETAIL_N.ORDER_ID);
            sqlstm.sqhstl[78] = (unsigned int  )26;
            sqlstm.sqhsts[78] = (         int  )0;
            sqlstm.sqindv[78] = (         void  *)0;
            sqlstm.sqinds[78] = (         int  )0;
            sqlstm.sqharm[78] = (unsigned int  )0;
            sqlstm.sqadto[78] = (unsigned short )0;
            sqlstm.sqtdso[78] = (unsigned short )0;
            sqlstm.sqhstv[79] = (         void  *)(GET_LOTDETAIL_N.ADD_ORDER_ID_1);
            sqlstm.sqhstl[79] = (unsigned int  )26;
            sqlstm.sqhsts[79] = (         int  )0;
            sqlstm.sqindv[79] = (         void  *)0;
            sqlstm.sqinds[79] = (         int  )0;
            sqlstm.sqharm[79] = (unsigned int  )0;
            sqlstm.sqadto[79] = (unsigned short )0;
            sqlstm.sqtdso[79] = (unsigned short )0;
            sqlstm.sqhstv[80] = (         void  *)(GET_LOTDETAIL_N.ADD_ORDER_ID_2);
            sqlstm.sqhstl[80] = (unsigned int  )26;
            sqlstm.sqhsts[80] = (         int  )0;
            sqlstm.sqindv[80] = (         void  *)0;
            sqlstm.sqinds[80] = (         int  )0;
            sqlstm.sqharm[80] = (unsigned int  )0;
            sqlstm.sqadto[80] = (unsigned short )0;
            sqlstm.sqtdso[80] = (unsigned short )0;
            sqlstm.sqhstv[81] = (         void  *)(GET_LOTDETAIL_N.ADD_ORDER_ID_3);
            sqlstm.sqhstl[81] = (unsigned int  )26;
            sqlstm.sqhsts[81] = (         int  )0;
            sqlstm.sqindv[81] = (         void  *)0;
            sqlstm.sqinds[81] = (         int  )0;
            sqlstm.sqharm[81] = (unsigned int  )0;
            sqlstm.sqadto[81] = (unsigned short )0;
            sqlstm.sqtdso[81] = (unsigned short )0;
            sqlstm.sqhstv[82] = (         void  *)(GET_LOTDETAIL_N.LOT_LOCATION_1);
            sqlstm.sqhstl[82] = (unsigned int  )21;
            sqlstm.sqhsts[82] = (         int  )0;
            sqlstm.sqindv[82] = (         void  *)0;
            sqlstm.sqinds[82] = (         int  )0;
            sqlstm.sqharm[82] = (unsigned int  )0;
            sqlstm.sqadto[82] = (unsigned short )0;
            sqlstm.sqtdso[82] = (unsigned short )0;
            sqlstm.sqhstv[83] = (         void  *)(GET_LOTDETAIL_N.LOT_LOCATION_2);
            sqlstm.sqhstl[83] = (unsigned int  )21;
            sqlstm.sqhsts[83] = (         int  )0;
            sqlstm.sqindv[83] = (         void  *)0;
            sqlstm.sqinds[83] = (         int  )0;
            sqlstm.sqharm[83] = (unsigned int  )0;
            sqlstm.sqadto[83] = (unsigned short )0;
            sqlstm.sqtdso[83] = (unsigned short )0;
            sqlstm.sqhstv[84] = (         void  *)(GET_LOTDETAIL_N.LOT_LOCATION_3);
            sqlstm.sqhstl[84] = (unsigned int  )21;
            sqlstm.sqhsts[84] = (         int  )0;
            sqlstm.sqindv[84] = (         void  *)0;
            sqlstm.sqinds[84] = (         int  )0;
            sqlstm.sqharm[84] = (unsigned int  )0;
            sqlstm.sqadto[84] = (unsigned short )0;
            sqlstm.sqtdso[84] = (unsigned short )0;
            sqlstm.sqhstv[85] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_1);
            sqlstm.sqhstl[85] = (unsigned int  )31;
            sqlstm.sqhsts[85] = (         int  )0;
            sqlstm.sqindv[85] = (         void  *)0;
            sqlstm.sqinds[85] = (         int  )0;
            sqlstm.sqharm[85] = (unsigned int  )0;
            sqlstm.sqadto[85] = (unsigned short )0;
            sqlstm.sqtdso[85] = (unsigned short )0;
            sqlstm.sqhstv[86] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_2);
            sqlstm.sqhstl[86] = (unsigned int  )31;
            sqlstm.sqhsts[86] = (         int  )0;
            sqlstm.sqindv[86] = (         void  *)0;
            sqlstm.sqinds[86] = (         int  )0;
            sqlstm.sqharm[86] = (unsigned int  )0;
            sqlstm.sqadto[86] = (unsigned short )0;
            sqlstm.sqtdso[86] = (unsigned short )0;
            sqlstm.sqhstv[87] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_3);
            sqlstm.sqhstl[87] = (unsigned int  )31;
            sqlstm.sqhsts[87] = (         int  )0;
            sqlstm.sqindv[87] = (         void  *)0;
            sqlstm.sqinds[87] = (         int  )0;
            sqlstm.sqharm[87] = (unsigned int  )0;
            sqlstm.sqadto[87] = (unsigned short )0;
            sqlstm.sqtdso[87] = (unsigned short )0;
            sqlstm.sqhstv[88] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_4);
            sqlstm.sqhstl[88] = (unsigned int  )31;
            sqlstm.sqhsts[88] = (         int  )0;
            sqlstm.sqindv[88] = (         void  *)0;
            sqlstm.sqinds[88] = (         int  )0;
            sqlstm.sqharm[88] = (unsigned int  )0;
            sqlstm.sqadto[88] = (unsigned short )0;
            sqlstm.sqtdso[88] = (unsigned short )0;
            sqlstm.sqhstv[89] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_5);
            sqlstm.sqhstl[89] = (unsigned int  )31;
            sqlstm.sqhsts[89] = (         int  )0;
            sqlstm.sqindv[89] = (         void  *)0;
            sqlstm.sqinds[89] = (         int  )0;
            sqlstm.sqharm[89] = (unsigned int  )0;
            sqlstm.sqadto[89] = (unsigned short )0;
            sqlstm.sqtdso[89] = (unsigned short )0;
            sqlstm.sqhstv[90] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_6);
            sqlstm.sqhstl[90] = (unsigned int  )31;
            sqlstm.sqhsts[90] = (         int  )0;
            sqlstm.sqindv[90] = (         void  *)0;
            sqlstm.sqinds[90] = (         int  )0;
            sqlstm.sqharm[90] = (unsigned int  )0;
            sqlstm.sqadto[90] = (unsigned short )0;
            sqlstm.sqtdso[90] = (unsigned short )0;
            sqlstm.sqhstv[91] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_7);
            sqlstm.sqhstl[91] = (unsigned int  )31;
            sqlstm.sqhsts[91] = (         int  )0;
            sqlstm.sqindv[91] = (         void  *)0;
            sqlstm.sqinds[91] = (         int  )0;
            sqlstm.sqharm[91] = (unsigned int  )0;
            sqlstm.sqadto[91] = (unsigned short )0;
            sqlstm.sqtdso[91] = (unsigned short )0;
            sqlstm.sqhstv[92] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_8);
            sqlstm.sqhstl[92] = (unsigned int  )31;
            sqlstm.sqhsts[92] = (         int  )0;
            sqlstm.sqindv[92] = (         void  *)0;
            sqlstm.sqinds[92] = (         int  )0;
            sqlstm.sqharm[92] = (unsigned int  )0;
            sqlstm.sqadto[92] = (unsigned short )0;
            sqlstm.sqtdso[92] = (unsigned short )0;
            sqlstm.sqhstv[93] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_9);
            sqlstm.sqhstl[93] = (unsigned int  )31;
            sqlstm.sqhsts[93] = (         int  )0;
            sqlstm.sqindv[93] = (         void  *)0;
            sqlstm.sqinds[93] = (         int  )0;
            sqlstm.sqharm[93] = (unsigned int  )0;
            sqlstm.sqadto[93] = (unsigned short )0;
            sqlstm.sqtdso[93] = (unsigned short )0;
            sqlstm.sqhstv[94] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_10);
            sqlstm.sqhstl[94] = (unsigned int  )31;
            sqlstm.sqhsts[94] = (         int  )0;
            sqlstm.sqindv[94] = (         void  *)0;
            sqlstm.sqinds[94] = (         int  )0;
            sqlstm.sqharm[94] = (unsigned int  )0;
            sqlstm.sqadto[94] = (unsigned short )0;
            sqlstm.sqtdso[94] = (unsigned short )0;
            sqlstm.sqhstv[95] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_11);
            sqlstm.sqhstl[95] = (unsigned int  )31;
            sqlstm.sqhsts[95] = (         int  )0;
            sqlstm.sqindv[95] = (         void  *)0;
            sqlstm.sqinds[95] = (         int  )0;
            sqlstm.sqharm[95] = (unsigned int  )0;
            sqlstm.sqadto[95] = (unsigned short )0;
            sqlstm.sqtdso[95] = (unsigned short )0;
            sqlstm.sqhstv[96] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_12);
            sqlstm.sqhstl[96] = (unsigned int  )31;
            sqlstm.sqhsts[96] = (         int  )0;
            sqlstm.sqindv[96] = (         void  *)0;
            sqlstm.sqinds[96] = (         int  )0;
            sqlstm.sqharm[96] = (unsigned int  )0;
            sqlstm.sqadto[96] = (unsigned short )0;
            sqlstm.sqtdso[96] = (unsigned short )0;
            sqlstm.sqhstv[97] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_13);
            sqlstm.sqhstl[97] = (unsigned int  )31;
            sqlstm.sqhsts[97] = (         int  )0;
            sqlstm.sqindv[97] = (         void  *)0;
            sqlstm.sqinds[97] = (         int  )0;
            sqlstm.sqharm[97] = (unsigned int  )0;
            sqlstm.sqadto[97] = (unsigned short )0;
            sqlstm.sqtdso[97] = (unsigned short )0;
            sqlstm.sqhstv[98] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_14);
            sqlstm.sqhstl[98] = (unsigned int  )31;
            sqlstm.sqhsts[98] = (         int  )0;
            sqlstm.sqindv[98] = (         void  *)0;
            sqlstm.sqinds[98] = (         int  )0;
            sqlstm.sqharm[98] = (unsigned int  )0;
            sqlstm.sqadto[98] = (unsigned short )0;
            sqlstm.sqtdso[98] = (unsigned short )0;
            sqlstm.sqhstv[99] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_15);
            sqlstm.sqhstl[99] = (unsigned int  )31;
            sqlstm.sqhsts[99] = (         int  )0;
            sqlstm.sqindv[99] = (         void  *)0;
            sqlstm.sqinds[99] = (         int  )0;
            sqlstm.sqharm[99] = (unsigned int  )0;
            sqlstm.sqadto[99] = (unsigned short )0;
            sqlstm.sqtdso[99] = (unsigned short )0;
            sqlstm.sqhstv[100] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_16);
            sqlstm.sqhstl[100] = (unsigned int  )31;
            sqlstm.sqhsts[100] = (         int  )0;
            sqlstm.sqindv[100] = (         void  *)0;
            sqlstm.sqinds[100] = (         int  )0;
            sqlstm.sqharm[100] = (unsigned int  )0;
            sqlstm.sqadto[100] = (unsigned short )0;
            sqlstm.sqtdso[100] = (unsigned short )0;
            sqlstm.sqhstv[101] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_17);
            sqlstm.sqhstl[101] = (unsigned int  )31;
            sqlstm.sqhsts[101] = (         int  )0;
            sqlstm.sqindv[101] = (         void  *)0;
            sqlstm.sqinds[101] = (         int  )0;
            sqlstm.sqharm[101] = (unsigned int  )0;
            sqlstm.sqadto[101] = (unsigned short )0;
            sqlstm.sqtdso[101] = (unsigned short )0;
            sqlstm.sqhstv[102] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_18);
            sqlstm.sqhstl[102] = (unsigned int  )31;
            sqlstm.sqhsts[102] = (         int  )0;
            sqlstm.sqindv[102] = (         void  *)0;
            sqlstm.sqinds[102] = (         int  )0;
            sqlstm.sqharm[102] = (unsigned int  )0;
            sqlstm.sqadto[102] = (unsigned short )0;
            sqlstm.sqtdso[102] = (unsigned short )0;
            sqlstm.sqhstv[103] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_19);
            sqlstm.sqhstl[103] = (unsigned int  )31;
            sqlstm.sqhsts[103] = (         int  )0;
            sqlstm.sqindv[103] = (         void  *)0;
            sqlstm.sqinds[103] = (         int  )0;
            sqlstm.sqharm[103] = (unsigned int  )0;
            sqlstm.sqadto[103] = (unsigned short )0;
            sqlstm.sqtdso[103] = (unsigned short )0;
            sqlstm.sqhstv[104] = (         void  *)(GET_LOTDETAIL_N.LOT_CMF_20);
            sqlstm.sqhstl[104] = (unsigned int  )31;
            sqlstm.sqhsts[104] = (         int  )0;
            sqlstm.sqindv[104] = (         void  *)0;
            sqlstm.sqinds[104] = (         int  )0;
            sqlstm.sqharm[104] = (unsigned int  )0;
            sqlstm.sqadto[104] = (unsigned short )0;
            sqlstm.sqtdso[104] = (unsigned short )0;
            sqlstm.sqhstv[105] = (         void  *)(GET_LOTDETAIL_N.LOT_DEL_FLAG);
            sqlstm.sqhstl[105] = (unsigned int  )2;
            sqlstm.sqhsts[105] = (         int  )0;
            sqlstm.sqindv[105] = (         void  *)0;
            sqlstm.sqinds[105] = (         int  )0;
            sqlstm.sqharm[105] = (unsigned int  )0;
            sqlstm.sqadto[105] = (unsigned short )0;
            sqlstm.sqtdso[105] = (unsigned short )0;
            sqlstm.sqhstv[106] = (         void  *)(GET_LOTDETAIL_N.LOT_DEL_CODE);
            sqlstm.sqhstl[106] = (unsigned int  )11;
            sqlstm.sqhsts[106] = (         int  )0;
            sqlstm.sqindv[106] = (         void  *)0;
            sqlstm.sqinds[106] = (         int  )0;
            sqlstm.sqharm[106] = (unsigned int  )0;
            sqlstm.sqadto[106] = (unsigned short )0;
            sqlstm.sqtdso[106] = (unsigned short )0;
            sqlstm.sqhstv[107] = (         void  *)(GET_LOTDETAIL_N.LOT_DEL_TIME);
            sqlstm.sqhstl[107] = (unsigned int  )15;
            sqlstm.sqhsts[107] = (         int  )0;
            sqlstm.sqindv[107] = (         void  *)0;
            sqlstm.sqinds[107] = (         int  )0;
            sqlstm.sqharm[107] = (unsigned int  )0;
            sqlstm.sqadto[107] = (unsigned short )0;
            sqlstm.sqtdso[107] = (unsigned short )0;
            sqlstm.sqhstv[108] = (         void  *)(GET_LOTDETAIL_N.BOM_SET_ID);
            sqlstm.sqhstl[108] = (unsigned int  )26;
            sqlstm.sqhsts[108] = (         int  )0;
            sqlstm.sqindv[108] = (         void  *)0;
            sqlstm.sqinds[108] = (         int  )0;
            sqlstm.sqharm[108] = (unsigned int  )0;
            sqlstm.sqadto[108] = (unsigned short )0;
            sqlstm.sqtdso[108] = (unsigned short )0;
            sqlstm.sqhstv[109] = (         void  *)&(GET_LOTDETAIL_N.BOM_SET_VERSION);
            sqlstm.sqhstl[109] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[109] = (         int  )0;
            sqlstm.sqindv[109] = (         void  *)0;
            sqlstm.sqinds[109] = (         int  )0;
            sqlstm.sqharm[109] = (unsigned int  )0;
            sqlstm.sqadto[109] = (unsigned short )0;
            sqlstm.sqtdso[109] = (unsigned short )0;
            sqlstm.sqhstv[110] = (         void  *)&(GET_LOTDETAIL_N.BOM_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[110] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[110] = (         int  )0;
            sqlstm.sqindv[110] = (         void  *)0;
            sqlstm.sqinds[110] = (         int  )0;
            sqlstm.sqharm[110] = (unsigned int  )0;
            sqlstm.sqadto[110] = (unsigned short )0;
            sqlstm.sqtdso[110] = (unsigned short )0;
            sqlstm.sqhstv[111] = (         void  *)&(GET_LOTDETAIL_N.BOM_HIST_SEQ);
            sqlstm.sqhstl[111] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[111] = (         int  )0;
            sqlstm.sqindv[111] = (         void  *)0;
            sqlstm.sqinds[111] = (         int  )0;
            sqlstm.sqharm[111] = (unsigned int  )0;
            sqlstm.sqadto[111] = (unsigned short )0;
            sqlstm.sqtdso[111] = (unsigned short )0;
            sqlstm.sqhstv[112] = (         void  *)(GET_LOTDETAIL_N.LAST_TRAN_CODE);
            sqlstm.sqhstl[112] = (unsigned int  )13;
            sqlstm.sqhsts[112] = (         int  )0;
            sqlstm.sqindv[112] = (         void  *)0;
            sqlstm.sqinds[112] = (         int  )0;
            sqlstm.sqharm[112] = (unsigned int  )0;
            sqlstm.sqadto[112] = (unsigned short )0;
            sqlstm.sqtdso[112] = (unsigned short )0;
            sqlstm.sqhstv[113] = (         void  *)(GET_LOTDETAIL_N.LAST_TRAN_TIME);
            sqlstm.sqhstl[113] = (unsigned int  )15;
            sqlstm.sqhsts[113] = (         int  )0;
            sqlstm.sqindv[113] = (         void  *)0;
            sqlstm.sqinds[113] = (         int  )0;
            sqlstm.sqharm[113] = (unsigned int  )0;
            sqlstm.sqadto[113] = (unsigned short )0;
            sqlstm.sqtdso[113] = (unsigned short )0;
            sqlstm.sqhstv[114] = (         void  *)(GET_LOTDETAIL_N.LAST_COMMENT);
            sqlstm.sqhstl[114] = (unsigned int  )401;
            sqlstm.sqhsts[114] = (         int  )0;
            sqlstm.sqindv[114] = (         void  *)0;
            sqlstm.sqinds[114] = (         int  )0;
            sqlstm.sqharm[114] = (unsigned int  )0;
            sqlstm.sqadto[114] = (unsigned short )0;
            sqlstm.sqtdso[114] = (unsigned short )0;
            sqlstm.sqhstv[115] = (         void  *)&(GET_LOTDETAIL_N.LAST_ACTIVE_HIST_SEQ);
            sqlstm.sqhstl[115] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[115] = (         int  )0;
            sqlstm.sqindv[115] = (         void  *)0;
            sqlstm.sqinds[115] = (         int  )0;
            sqlstm.sqharm[115] = (unsigned int  )0;
            sqlstm.sqadto[115] = (unsigned short )0;
            sqlstm.sqtdso[115] = (unsigned short )0;
            sqlstm.sqhstv[116] = (         void  *)&(GET_LOTDETAIL_N.LAST_HIST_SEQ);
            sqlstm.sqhstl[116] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[116] = (         int  )0;
            sqlstm.sqindv[116] = (         void  *)0;
            sqlstm.sqinds[116] = (         int  )0;
            sqlstm.sqharm[116] = (unsigned int  )0;
            sqlstm.sqadto[116] = (unsigned short )0;
            sqlstm.sqtdso[116] = (unsigned short )0;
            sqlstm.sqhstv[117] = (         void  *)(GET_LOTDETAIL_N.CRITICAL_RES_ID);
            sqlstm.sqhstl[117] = (unsigned int  )21;
            sqlstm.sqhsts[117] = (         int  )0;
            sqlstm.sqindv[117] = (         void  *)0;
            sqlstm.sqinds[117] = (         int  )0;
            sqlstm.sqharm[117] = (unsigned int  )0;
            sqlstm.sqadto[117] = (unsigned short )0;
            sqlstm.sqtdso[117] = (unsigned short )0;
            sqlstm.sqhstv[118] = (         void  *)(GET_LOTDETAIL_N.CRITICAL_RES_GROUP_ID);
            sqlstm.sqhstl[118] = (unsigned int  )21;
            sqlstm.sqhsts[118] = (         int  )0;
            sqlstm.sqindv[118] = (         void  *)0;
            sqlstm.sqinds[118] = (         int  )0;
            sqlstm.sqharm[118] = (unsigned int  )0;
            sqlstm.sqadto[118] = (unsigned short )0;
            sqlstm.sqtdso[118] = (unsigned short )0;
            sqlstm.sqhstv[119] = (         void  *)(GET_LOTDETAIL_N.SAVE_RES_ID_1);
            sqlstm.sqhstl[119] = (unsigned int  )21;
            sqlstm.sqhsts[119] = (         int  )0;
            sqlstm.sqindv[119] = (         void  *)0;
            sqlstm.sqinds[119] = (         int  )0;
            sqlstm.sqharm[119] = (unsigned int  )0;
            sqlstm.sqadto[119] = (unsigned short )0;
            sqlstm.sqtdso[119] = (unsigned short )0;
            sqlstm.sqhstv[120] = (         void  *)(GET_LOTDETAIL_N.SAVE_RES_ID_2);
            sqlstm.sqhstl[120] = (unsigned int  )21;
            sqlstm.sqhsts[120] = (         int  )0;
            sqlstm.sqindv[120] = (         void  *)0;
            sqlstm.sqinds[120] = (         int  )0;
            sqlstm.sqharm[120] = (unsigned int  )0;
            sqlstm.sqadto[120] = (unsigned short )0;
            sqlstm.sqtdso[120] = (unsigned short )0;
            sqlstm.sqhstv[121] = (         void  *)(GET_LOTDETAIL_N.SUBRES_ID);
            sqlstm.sqhstl[121] = (unsigned int  )21;
            sqlstm.sqhsts[121] = (         int  )0;
            sqlstm.sqindv[121] = (         void  *)0;
            sqlstm.sqinds[121] = (         int  )0;
            sqlstm.sqharm[121] = (unsigned int  )0;
            sqlstm.sqadto[121] = (unsigned short )0;
            sqlstm.sqtdso[121] = (unsigned short )0;
            sqlstm.sqhstv[122] = (         void  *)(GET_LOTDETAIL_N.LOT_GROUP_ID_1);
            sqlstm.sqhstl[122] = (unsigned int  )26;
            sqlstm.sqhsts[122] = (         int  )0;
            sqlstm.sqindv[122] = (         void  *)0;
            sqlstm.sqinds[122] = (         int  )0;
            sqlstm.sqharm[122] = (unsigned int  )0;
            sqlstm.sqadto[122] = (unsigned short )0;
            sqlstm.sqtdso[122] = (unsigned short )0;
            sqlstm.sqhstv[123] = (         void  *)(GET_LOTDETAIL_N.LOT_GROUP_ID_2);
            sqlstm.sqhstl[123] = (unsigned int  )26;
            sqlstm.sqhsts[123] = (         int  )0;
            sqlstm.sqindv[123] = (         void  *)0;
            sqlstm.sqinds[123] = (         int  )0;
            sqlstm.sqharm[123] = (unsigned int  )0;
            sqlstm.sqadto[123] = (unsigned short )0;
            sqlstm.sqtdso[123] = (unsigned short )0;
            sqlstm.sqhstv[124] = (         void  *)(GET_LOTDETAIL_N.LOT_GROUP_ID_3);
            sqlstm.sqhstl[124] = (unsigned int  )26;
            sqlstm.sqhsts[124] = (         int  )0;
            sqlstm.sqindv[124] = (         void  *)0;
            sqlstm.sqinds[124] = (         int  )0;
            sqlstm.sqharm[124] = (unsigned int  )0;
            sqlstm.sqadto[124] = (unsigned short )0;
            sqlstm.sqtdso[124] = (unsigned short )0;
            sqlstm.sqhstv[125] = (         void  *)&(GET_LOTDETAIL_N.YIELD_1);
            sqlstm.sqhstl[125] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[125] = (         int  )0;
            sqlstm.sqindv[125] = (         void  *)0;
            sqlstm.sqinds[125] = (         int  )0;
            sqlstm.sqharm[125] = (unsigned int  )0;
            sqlstm.sqadto[125] = (unsigned short )0;
            sqlstm.sqtdso[125] = (unsigned short )0;
            sqlstm.sqhstv[126] = (         void  *)&(GET_LOTDETAIL_N.YIELD_2);
            sqlstm.sqhstl[126] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[126] = (         int  )0;
            sqlstm.sqindv[126] = (         void  *)0;
            sqlstm.sqinds[126] = (         int  )0;
            sqlstm.sqharm[126] = (unsigned int  )0;
            sqlstm.sqadto[126] = (unsigned short )0;
            sqlstm.sqtdso[126] = (unsigned short )0;
            sqlstm.sqhstv[127] = (         void  *)&(GET_LOTDETAIL_N.YIELD_3);
            sqlstm.sqhstl[127] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[127] = (         int  )0;
            sqlstm.sqindv[127] = (         void  *)0;
            sqlstm.sqinds[127] = (         int  )0;
            sqlstm.sqharm[127] = (unsigned int  )0;
            sqlstm.sqadto[127] = (unsigned short )0;
            sqlstm.sqtdso[127] = (unsigned short )0;
            sqlstm.sqhstv[128] = (         void  *)&(GET_LOTDETAIL_N.GOOD_QTY);
            sqlstm.sqhstl[128] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[128] = (         int  )0;
            sqlstm.sqindv[128] = (         void  *)0;
            sqlstm.sqinds[128] = (         int  )0;
            sqlstm.sqharm[128] = (unsigned int  )0;
            sqlstm.sqadto[128] = (unsigned short )0;
            sqlstm.sqtdso[128] = (unsigned short )0;
            sqlstm.sqhstv[129] = (         void  *)(GET_LOTDETAIL_N.RESV_FIELD_1);
            sqlstm.sqhstl[129] = (unsigned int  )31;
            sqlstm.sqhsts[129] = (         int  )0;
            sqlstm.sqindv[129] = (         void  *)0;
            sqlstm.sqinds[129] = (         int  )0;
            sqlstm.sqharm[129] = (unsigned int  )0;
            sqlstm.sqadto[129] = (unsigned short )0;
            sqlstm.sqtdso[129] = (unsigned short )0;
            sqlstm.sqhstv[130] = (         void  *)(GET_LOTDETAIL_N.RESV_FIELD_2);
            sqlstm.sqhstl[130] = (unsigned int  )31;
            sqlstm.sqhsts[130] = (         int  )0;
            sqlstm.sqindv[130] = (         void  *)0;
            sqlstm.sqinds[130] = (         int  )0;
            sqlstm.sqharm[130] = (unsigned int  )0;
            sqlstm.sqadto[130] = (unsigned short )0;
            sqlstm.sqtdso[130] = (unsigned short )0;
            sqlstm.sqhstv[131] = (         void  *)(GET_LOTDETAIL_N.RESV_FIELD_3);
            sqlstm.sqhstl[131] = (unsigned int  )31;
            sqlstm.sqhsts[131] = (         int  )0;
            sqlstm.sqindv[131] = (         void  *)0;
            sqlstm.sqinds[131] = (         int  )0;
            sqlstm.sqharm[131] = (unsigned int  )0;
            sqlstm.sqadto[131] = (unsigned short )0;
            sqlstm.sqtdso[131] = (unsigned short )0;
            sqlstm.sqhstv[132] = (         void  *)(GET_LOTDETAIL_N.RESV_FIELD_4);
            sqlstm.sqhstl[132] = (unsigned int  )31;
            sqlstm.sqhsts[132] = (         int  )0;
            sqlstm.sqindv[132] = (         void  *)0;
            sqlstm.sqinds[132] = (         int  )0;
            sqlstm.sqharm[132] = (unsigned int  )0;
            sqlstm.sqadto[132] = (unsigned short )0;
            sqlstm.sqtdso[132] = (unsigned short )0;
            sqlstm.sqhstv[133] = (         void  *)(GET_LOTDETAIL_N.RESV_FIELD_5);
            sqlstm.sqhstl[133] = (unsigned int  )31;
            sqlstm.sqhsts[133] = (         int  )0;
            sqlstm.sqindv[133] = (         void  *)0;
            sqlstm.sqinds[133] = (         int  )0;
            sqlstm.sqharm[133] = (unsigned int  )0;
            sqlstm.sqadto[133] = (unsigned short )0;
            sqlstm.sqtdso[133] = (unsigned short )0;
            sqlstm.sqhstv[134] = (         void  *)(GET_LOTDETAIL_N.RESV_FLAG_1);
            sqlstm.sqhstl[134] = (unsigned int  )2;
            sqlstm.sqhsts[134] = (         int  )0;
            sqlstm.sqindv[134] = (         void  *)0;
            sqlstm.sqinds[134] = (         int  )0;
            sqlstm.sqharm[134] = (unsigned int  )0;
            sqlstm.sqadto[134] = (unsigned short )0;
            sqlstm.sqtdso[134] = (unsigned short )0;
            sqlstm.sqhstv[135] = (         void  *)(GET_LOTDETAIL_N.RESV_FLAG_2);
            sqlstm.sqhstl[135] = (unsigned int  )2;
            sqlstm.sqhsts[135] = (         int  )0;
            sqlstm.sqindv[135] = (         void  *)0;
            sqlstm.sqinds[135] = (         int  )0;
            sqlstm.sqharm[135] = (unsigned int  )0;
            sqlstm.sqadto[135] = (unsigned short )0;
            sqlstm.sqtdso[135] = (unsigned short )0;
            sqlstm.sqhstv[136] = (         void  *)(GET_LOTDETAIL_N.RESV_FLAG_3);
            sqlstm.sqhstl[136] = (unsigned int  )2;
            sqlstm.sqhsts[136] = (         int  )0;
            sqlstm.sqindv[136] = (         void  *)0;
            sqlstm.sqinds[136] = (         int  )0;
            sqlstm.sqharm[136] = (unsigned int  )0;
            sqlstm.sqadto[136] = (unsigned short )0;
            sqlstm.sqtdso[136] = (unsigned short )0;
            sqlstm.sqhstv[137] = (         void  *)(GET_LOTDETAIL_N.RESV_FLAG_4);
            sqlstm.sqhstl[137] = (unsigned int  )2;
            sqlstm.sqhsts[137] = (         int  )0;
            sqlstm.sqindv[137] = (         void  *)0;
            sqlstm.sqinds[137] = (         int  )0;
            sqlstm.sqharm[137] = (unsigned int  )0;
            sqlstm.sqadto[137] = (unsigned short )0;
            sqlstm.sqtdso[137] = (unsigned short )0;
            sqlstm.sqhstv[138] = (         void  *)(GET_LOTDETAIL_N.RESV_FLAG_5);
            sqlstm.sqhstl[138] = (unsigned int  )2;
            sqlstm.sqhsts[138] = (         int  )0;
            sqlstm.sqindv[138] = (         void  *)0;
            sqlstm.sqinds[138] = (         int  )0;
            sqlstm.sqharm[138] = (unsigned int  )0;
            sqlstm.sqadto[138] = (unsigned short )0;
            sqlstm.sqtdso[138] = (unsigned short )0;
            sqlstm.sqhstv[139] = (         void  *)(GET_LOTDETAIL_N.MAT_DESC);
            sqlstm.sqhstl[139] = (unsigned int  )201;
            sqlstm.sqhsts[139] = (         int  )0;
            sqlstm.sqindv[139] = (         void  *)0;
            sqlstm.sqinds[139] = (         int  )0;
            sqlstm.sqharm[139] = (unsigned int  )0;
            sqlstm.sqadto[139] = (unsigned short )0;
            sqlstm.sqtdso[139] = (unsigned short )0;
            sqlstm.sqhstv[140] = (         void  *)(GET_LOTDETAIL_N.FLOW_DESC);
            sqlstm.sqhstl[140] = (unsigned int  )201;
            sqlstm.sqhsts[140] = (         int  )0;
            sqlstm.sqindv[140] = (         void  *)0;
            sqlstm.sqinds[140] = (         int  )0;
            sqlstm.sqharm[140] = (unsigned int  )0;
            sqlstm.sqadto[140] = (unsigned short )0;
            sqlstm.sqtdso[140] = (unsigned short )0;
            sqlstm.sqhstv[141] = (         void  *)(GET_LOTDETAIL_N.OPER_DESC);
            sqlstm.sqhstl[141] = (unsigned int  )201;
            sqlstm.sqhsts[141] = (         int  )0;
            sqlstm.sqindv[141] = (         void  *)0;
            sqlstm.sqinds[141] = (         int  )0;
            sqlstm.sqharm[141] = (unsigned int  )0;
            sqlstm.sqadto[141] = (unsigned short )0;
            sqlstm.sqtdso[141] = (unsigned short )0;
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
        DBC_del_null_get_lotdetail(&GET_LOTDETAIL_N, GET_LOTDETAIL);
    }
    DB_stop_query_timer("DBC_fetch_get_lotdetail", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_get_lotdetail(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_GET_LOTDETAIL_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1760;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
            
        case 2:
            /* EXEC SQL CLOSE DBC_GET_LOTDETAIL_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1775;
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
    DB_stop_query_timer("DBC_close_get_lotdetail", sel_type);
}

/* Initialize Function */
void DBC_init_get_lotdetail(struct GET_LOTDETAIL_TAG *GET_LOTDETAIL)
{
    /* memset by Space */
    memset(GET_LOTDETAIL, ' ', sizeof(struct GET_LOTDETAIL_TAG));
    
    GET_LOTDETAIL->MAT_VER = 0;
    GET_LOTDETAIL->FLOW_SEQ_NUM = 0;
    GET_LOTDETAIL->QTY_1 = 0;
    GET_LOTDETAIL->QTY_2 = 0;
    GET_LOTDETAIL->QTY_3 = 0;
    GET_LOTDETAIL->OPER_IN_QTY_1 = 0;
    GET_LOTDETAIL->OPER_IN_QTY_2 = 0;
    GET_LOTDETAIL->OPER_IN_QTY_3 = 0;
    GET_LOTDETAIL->CREATE_QTY_1 = 0;
    GET_LOTDETAIL->CREATE_QTY_2 = 0;
    GET_LOTDETAIL->CREATE_QTY_3 = 0;
    GET_LOTDETAIL->START_QTY_1 = 0;
    GET_LOTDETAIL->START_QTY_2 = 0;
    GET_LOTDETAIL->START_QTY_3 = 0;
    GET_LOTDETAIL->RWK_COUNT = 0;
    GET_LOTDETAIL->RWK_RET_FLOW_SEQ_NUM = 0;
    GET_LOTDETAIL->RWK_END_FLOW_SEQ_NUM = 0;
    GET_LOTDETAIL->NSTD_RET_FLOW_SEQ_NUM = 0;
    GET_LOTDETAIL->STR_RET_FLOW_SEQ_NUM = 0;
    GET_LOTDETAIL->BATCH_SEQ = 0;
    GET_LOTDETAIL->BOM_SET_VERSION = 0;
    GET_LOTDETAIL->BOM_ACTIVE_HIST_SEQ = 0;
    GET_LOTDETAIL->BOM_HIST_SEQ = 0;
    GET_LOTDETAIL->LAST_ACTIVE_HIST_SEQ = 0;
    GET_LOTDETAIL->LAST_HIST_SEQ = 0;
}


/* Add Null Function */
void DBC_add_null_get_lotdetail(struct GET_LOTDETAIL_N_TAG *GET_LOTDETAIL_N, struct GET_LOTDETAIL_TAG *GET_LOTDETAIL)
{
    /* memset by NULL */
    memset(GET_LOTDETAIL_N, '\0', sizeof(struct GET_LOTDETAIL_N_TAG));
    
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_ID, GET_LOTDETAIL->LOT_ID, sizeof(GET_LOTDETAIL->LOT_ID));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_DESC, GET_LOTDETAIL->LOT_DESC, sizeof(GET_LOTDETAIL->LOT_DESC));
    MEMCPY_AN(GET_LOTDETAIL_N->FACTORY, GET_LOTDETAIL->FACTORY, sizeof(GET_LOTDETAIL->FACTORY));
    MEMCPY_AN(GET_LOTDETAIL_N->MAT_ID, GET_LOTDETAIL->MAT_ID, sizeof(GET_LOTDETAIL->MAT_ID));
    GET_LOTDETAIL_N->MAT_VER = GET_LOTDETAIL->MAT_VER;
    MEMCPY_AN(GET_LOTDETAIL_N->FLOW, GET_LOTDETAIL->FLOW, sizeof(GET_LOTDETAIL->FLOW));
    GET_LOTDETAIL_N->FLOW_SEQ_NUM = GET_LOTDETAIL->FLOW_SEQ_NUM;
    MEMCPY_AN(GET_LOTDETAIL_N->OPER, GET_LOTDETAIL->OPER, sizeof(GET_LOTDETAIL->OPER));
    GET_LOTDETAIL_N->QTY_1 = GET_LOTDETAIL->QTY_1;
    GET_LOTDETAIL_N->QTY_2 = GET_LOTDETAIL->QTY_2;
    GET_LOTDETAIL_N->QTY_3 = GET_LOTDETAIL->QTY_3;
    MEMCPY_AN(GET_LOTDETAIL_N->CRR_ID, GET_LOTDETAIL->CRR_ID, sizeof(GET_LOTDETAIL->CRR_ID));
    GET_LOTDETAIL_N->LOT_TYPE[0] = GET_LOTDETAIL->LOT_TYPE;
    MEMCPY_AN(GET_LOTDETAIL_N->OWNER_CODE, GET_LOTDETAIL->OWNER_CODE, sizeof(GET_LOTDETAIL->OWNER_CODE));
    MEMCPY_AN(GET_LOTDETAIL_N->CREATE_CODE, GET_LOTDETAIL->CREATE_CODE, sizeof(GET_LOTDETAIL->CREATE_CODE));
    GET_LOTDETAIL_N->LOT_PRIORITY[0] = GET_LOTDETAIL->LOT_PRIORITY;
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_STATUS, GET_LOTDETAIL->LOT_STATUS, sizeof(GET_LOTDETAIL->LOT_STATUS));
    GET_LOTDETAIL_N->HOLD_FLAG[0] = GET_LOTDETAIL->HOLD_FLAG;
    MEMCPY_AN(GET_LOTDETAIL_N->HOLD_CODE, GET_LOTDETAIL->HOLD_CODE, sizeof(GET_LOTDETAIL->HOLD_CODE));
    MEMCPY_AN(GET_LOTDETAIL_N->HOLD_PASSWORD, GET_LOTDETAIL->HOLD_PASSWORD, sizeof(GET_LOTDETAIL->HOLD_PASSWORD));
    MEMCPY_AN(GET_LOTDETAIL_N->HOLD_PRV_GRP_ID, GET_LOTDETAIL->HOLD_PRV_GRP_ID, sizeof(GET_LOTDETAIL->HOLD_PRV_GRP_ID));
    GET_LOTDETAIL_N->OPER_IN_QTY_1 = GET_LOTDETAIL->OPER_IN_QTY_1;
    GET_LOTDETAIL_N->OPER_IN_QTY_2 = GET_LOTDETAIL->OPER_IN_QTY_2;
    GET_LOTDETAIL_N->OPER_IN_QTY_3 = GET_LOTDETAIL->OPER_IN_QTY_3;
    GET_LOTDETAIL_N->CREATE_QTY_1 = GET_LOTDETAIL->CREATE_QTY_1;
    GET_LOTDETAIL_N->CREATE_QTY_2 = GET_LOTDETAIL->CREATE_QTY_2;
    GET_LOTDETAIL_N->CREATE_QTY_3 = GET_LOTDETAIL->CREATE_QTY_3;
    GET_LOTDETAIL_N->START_QTY_1 = GET_LOTDETAIL->START_QTY_1;
    GET_LOTDETAIL_N->START_QTY_2 = GET_LOTDETAIL->START_QTY_2;
    GET_LOTDETAIL_N->START_QTY_3 = GET_LOTDETAIL->START_QTY_3;
    GET_LOTDETAIL_N->INV_FLAG[0] = GET_LOTDETAIL->INV_FLAG;
    GET_LOTDETAIL_N->TRANSIT_FLAG[0] = GET_LOTDETAIL->TRANSIT_FLAG;
    GET_LOTDETAIL_N->UNIT_EXIST_FLAG[0] = GET_LOTDETAIL->UNIT_EXIST_FLAG;
    MEMCPY_AN(GET_LOTDETAIL_N->INV_UNIT, GET_LOTDETAIL->INV_UNIT, sizeof(GET_LOTDETAIL->INV_UNIT));
    GET_LOTDETAIL_N->RWK_FLAG[0] = GET_LOTDETAIL->RWK_FLAG;
    MEMCPY_AN(GET_LOTDETAIL_N->RWK_CODE, GET_LOTDETAIL->RWK_CODE, sizeof(GET_LOTDETAIL->RWK_CODE));
    GET_LOTDETAIL_N->RWK_COUNT = GET_LOTDETAIL->RWK_COUNT;
    MEMCPY_AN(GET_LOTDETAIL_N->RWK_RET_FLOW, GET_LOTDETAIL->RWK_RET_FLOW, sizeof(GET_LOTDETAIL->RWK_RET_FLOW));
    GET_LOTDETAIL_N->RWK_RET_FLOW_SEQ_NUM = GET_LOTDETAIL->RWK_RET_FLOW_SEQ_NUM;
    MEMCPY_AN(GET_LOTDETAIL_N->RWK_RET_OPER, GET_LOTDETAIL->RWK_RET_OPER, sizeof(GET_LOTDETAIL->RWK_RET_OPER));
    MEMCPY_AN(GET_LOTDETAIL_N->RWK_END_FLOW, GET_LOTDETAIL->RWK_END_FLOW, sizeof(GET_LOTDETAIL->RWK_END_FLOW));
    GET_LOTDETAIL_N->RWK_END_FLOW_SEQ_NUM = GET_LOTDETAIL->RWK_END_FLOW_SEQ_NUM;
    MEMCPY_AN(GET_LOTDETAIL_N->RWK_END_OPER, GET_LOTDETAIL->RWK_END_OPER, sizeof(GET_LOTDETAIL->RWK_END_OPER));
    GET_LOTDETAIL_N->RWK_RET_CLEAR_FLAG[0] = GET_LOTDETAIL->RWK_RET_CLEAR_FLAG;
    MEMCPY_AN(GET_LOTDETAIL_N->RWK_TIME, GET_LOTDETAIL->RWK_TIME, sizeof(GET_LOTDETAIL->RWK_TIME));
    GET_LOTDETAIL_N->NSTD_FLAG[0] = GET_LOTDETAIL->NSTD_FLAG;
    MEMCPY_AN(GET_LOTDETAIL_N->NSTD_RET_FLOW, GET_LOTDETAIL->NSTD_RET_FLOW, sizeof(GET_LOTDETAIL->NSTD_RET_FLOW));
    GET_LOTDETAIL_N->NSTD_RET_FLOW_SEQ_NUM = GET_LOTDETAIL->NSTD_RET_FLOW_SEQ_NUM;
    MEMCPY_AN(GET_LOTDETAIL_N->NSTD_RET_OPER, GET_LOTDETAIL->NSTD_RET_OPER, sizeof(GET_LOTDETAIL->NSTD_RET_OPER));
    MEMCPY_AN(GET_LOTDETAIL_N->NSTD_TIME, GET_LOTDETAIL->NSTD_TIME, sizeof(GET_LOTDETAIL->NSTD_TIME));
    GET_LOTDETAIL_N->REP_FLAG[0] = GET_LOTDETAIL->REP_FLAG;
    MEMCPY_AN(GET_LOTDETAIL_N->REP_RET_OPER, GET_LOTDETAIL->REP_RET_OPER, sizeof(GET_LOTDETAIL->REP_RET_OPER));    
    MEMCPY_AN(GET_LOTDETAIL_N->STR_RET_FLOW, GET_LOTDETAIL->STR_RET_FLOW, sizeof(GET_LOTDETAIL->STR_RET_FLOW));
    GET_LOTDETAIL_N->STR_RET_FLOW_SEQ_NUM = GET_LOTDETAIL->STR_RET_FLOW_SEQ_NUM;
    MEMCPY_AN(GET_LOTDETAIL_N->STR_RET_OPER, GET_LOTDETAIL->STR_RET_OPER, sizeof(GET_LOTDETAIL->STR_RET_OPER));
    GET_LOTDETAIL_N->START_FLAG[0] = GET_LOTDETAIL->START_FLAG;
    MEMCPY_AN(GET_LOTDETAIL_N->START_TIME, GET_LOTDETAIL->START_TIME, sizeof(GET_LOTDETAIL->START_TIME));
    MEMCPY_AN(GET_LOTDETAIL_N->START_RES_ID, GET_LOTDETAIL->START_RES_ID, sizeof(GET_LOTDETAIL->START_RES_ID));
    GET_LOTDETAIL_N->END_FLAG[0] = GET_LOTDETAIL->END_FLAG;
    MEMCPY_AN(GET_LOTDETAIL_N->END_TIME, GET_LOTDETAIL->END_TIME, sizeof(GET_LOTDETAIL->END_TIME));
    MEMCPY_AN(GET_LOTDETAIL_N->END_RES_ID, GET_LOTDETAIL->END_RES_ID, sizeof(GET_LOTDETAIL->END_RES_ID));
    GET_LOTDETAIL_N->SAMPLE_FLAG[0] = GET_LOTDETAIL->SAMPLE_FLAG;
    GET_LOTDETAIL_N->SAMPLE_WAIT_FLAG[0] = GET_LOTDETAIL->SAMPLE_WAIT_FLAG;
    GET_LOTDETAIL_N->SAMPLE_RESULT[0] = GET_LOTDETAIL->SAMPLE_RESULT;
    GET_LOTDETAIL_N->FROM_TO_FLAG[0] = GET_LOTDETAIL->FROM_TO_FLAG;
    MEMCPY_AN(GET_LOTDETAIL_N->FROM_TO_LOT_ID, GET_LOTDETAIL->FROM_TO_LOT_ID, sizeof(GET_LOTDETAIL->FROM_TO_LOT_ID));
    MEMCPY_AN(GET_LOTDETAIL_N->SHIP_CODE, GET_LOTDETAIL->SHIP_CODE, sizeof(GET_LOTDETAIL->SHIP_CODE));
    MEMCPY_AN(GET_LOTDETAIL_N->SHIP_TIME, GET_LOTDETAIL->SHIP_TIME, sizeof(GET_LOTDETAIL->SHIP_TIME));
    MEMCPY_AN(GET_LOTDETAIL_N->ORG_DUE_TIME, GET_LOTDETAIL->ORG_DUE_TIME, sizeof(GET_LOTDETAIL->ORG_DUE_TIME));
    MEMCPY_AN(GET_LOTDETAIL_N->SCH_DUE_TIME, GET_LOTDETAIL->SCH_DUE_TIME, sizeof(GET_LOTDETAIL->SCH_DUE_TIME));
    MEMCPY_AN(GET_LOTDETAIL_N->CREATE_TIME, GET_LOTDETAIL->CREATE_TIME, sizeof(GET_LOTDETAIL->CREATE_TIME));
    MEMCPY_AN(GET_LOTDETAIL_N->FAC_IN_TIME, GET_LOTDETAIL->FAC_IN_TIME, sizeof(GET_LOTDETAIL->FAC_IN_TIME));
    MEMCPY_AN(GET_LOTDETAIL_N->FLOW_IN_TIME, GET_LOTDETAIL->FLOW_IN_TIME, sizeof(GET_LOTDETAIL->FLOW_IN_TIME));
    MEMCPY_AN(GET_LOTDETAIL_N->OPER_IN_TIME, GET_LOTDETAIL->OPER_IN_TIME, sizeof(GET_LOTDETAIL->OPER_IN_TIME));
    MEMCPY_AN(GET_LOTDETAIL_N->RESERVE_RES_ID, GET_LOTDETAIL->RESERVE_RES_ID, sizeof(GET_LOTDETAIL->RESERVE_RES_ID));
    MEMCPY_AN(GET_LOTDETAIL_N->PORT_ID, GET_LOTDETAIL->PORT_ID, sizeof(GET_LOTDETAIL->PORT_ID));
    MEMCPY_AN(GET_LOTDETAIL_N->BATCH_ID, GET_LOTDETAIL->BATCH_ID, sizeof(GET_LOTDETAIL->BATCH_ID));
    GET_LOTDETAIL_N->BATCH_SEQ = GET_LOTDETAIL->BATCH_SEQ;
    MEMCPY_AN(GET_LOTDETAIL_N->ORDER_ID, GET_LOTDETAIL->ORDER_ID, sizeof(GET_LOTDETAIL->ORDER_ID));
    MEMCPY_AN(GET_LOTDETAIL_N->ADD_ORDER_ID_1, GET_LOTDETAIL->ADD_ORDER_ID_1, sizeof(GET_LOTDETAIL->ADD_ORDER_ID_1));
    MEMCPY_AN(GET_LOTDETAIL_N->ADD_ORDER_ID_2, GET_LOTDETAIL->ADD_ORDER_ID_2, sizeof(GET_LOTDETAIL->ADD_ORDER_ID_2));
    MEMCPY_AN(GET_LOTDETAIL_N->ADD_ORDER_ID_3, GET_LOTDETAIL->ADD_ORDER_ID_3, sizeof(GET_LOTDETAIL->ADD_ORDER_ID_3));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_LOCATION_1, GET_LOTDETAIL->LOT_LOCATION_1, sizeof(GET_LOTDETAIL->LOT_LOCATION_1));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_LOCATION_2, GET_LOTDETAIL->LOT_LOCATION_2, sizeof(GET_LOTDETAIL->LOT_LOCATION_2));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_LOCATION_3, GET_LOTDETAIL->LOT_LOCATION_3, sizeof(GET_LOTDETAIL->LOT_LOCATION_3));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_CMF_1, GET_LOTDETAIL->LOT_CMF_1, sizeof(GET_LOTDETAIL->LOT_CMF_1));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_CMF_2, GET_LOTDETAIL->LOT_CMF_2, sizeof(GET_LOTDETAIL->LOT_CMF_2));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_CMF_3, GET_LOTDETAIL->LOT_CMF_3, sizeof(GET_LOTDETAIL->LOT_CMF_3));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_CMF_4, GET_LOTDETAIL->LOT_CMF_4, sizeof(GET_LOTDETAIL->LOT_CMF_4));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_CMF_5, GET_LOTDETAIL->LOT_CMF_5, sizeof(GET_LOTDETAIL->LOT_CMF_5));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_CMF_6, GET_LOTDETAIL->LOT_CMF_6, sizeof(GET_LOTDETAIL->LOT_CMF_6));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_CMF_7, GET_LOTDETAIL->LOT_CMF_7, sizeof(GET_LOTDETAIL->LOT_CMF_7));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_CMF_8, GET_LOTDETAIL->LOT_CMF_8, sizeof(GET_LOTDETAIL->LOT_CMF_8));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_CMF_9, GET_LOTDETAIL->LOT_CMF_9, sizeof(GET_LOTDETAIL->LOT_CMF_9));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_CMF_10, GET_LOTDETAIL->LOT_CMF_10, sizeof(GET_LOTDETAIL->LOT_CMF_10));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_CMF_11, GET_LOTDETAIL->LOT_CMF_11, sizeof(GET_LOTDETAIL->LOT_CMF_11));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_CMF_12, GET_LOTDETAIL->LOT_CMF_12, sizeof(GET_LOTDETAIL->LOT_CMF_12));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_CMF_13, GET_LOTDETAIL->LOT_CMF_13, sizeof(GET_LOTDETAIL->LOT_CMF_13));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_CMF_14, GET_LOTDETAIL->LOT_CMF_14, sizeof(GET_LOTDETAIL->LOT_CMF_14));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_CMF_15, GET_LOTDETAIL->LOT_CMF_15, sizeof(GET_LOTDETAIL->LOT_CMF_15));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_CMF_16, GET_LOTDETAIL->LOT_CMF_16, sizeof(GET_LOTDETAIL->LOT_CMF_16));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_CMF_17, GET_LOTDETAIL->LOT_CMF_17, sizeof(GET_LOTDETAIL->LOT_CMF_17));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_CMF_18, GET_LOTDETAIL->LOT_CMF_18, sizeof(GET_LOTDETAIL->LOT_CMF_18));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_CMF_19, GET_LOTDETAIL->LOT_CMF_19, sizeof(GET_LOTDETAIL->LOT_CMF_19));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_CMF_20, GET_LOTDETAIL->LOT_CMF_20, sizeof(GET_LOTDETAIL->LOT_CMF_20));
    GET_LOTDETAIL_N->LOT_DEL_FLAG[0] = GET_LOTDETAIL->LOT_DEL_FLAG;
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_DEL_CODE, GET_LOTDETAIL->LOT_DEL_CODE, sizeof(GET_LOTDETAIL->LOT_DEL_CODE));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_DEL_TIME, GET_LOTDETAIL->LOT_DEL_TIME, sizeof(GET_LOTDETAIL->LOT_DEL_TIME));
    MEMCPY_AN(GET_LOTDETAIL_N->BOM_SET_ID, GET_LOTDETAIL->BOM_SET_ID, sizeof(GET_LOTDETAIL->BOM_SET_ID));
    GET_LOTDETAIL_N->BOM_SET_VERSION = GET_LOTDETAIL->BOM_SET_VERSION;
    GET_LOTDETAIL_N->BOM_ACTIVE_HIST_SEQ = GET_LOTDETAIL->BOM_ACTIVE_HIST_SEQ;
    GET_LOTDETAIL_N->BOM_HIST_SEQ = GET_LOTDETAIL->BOM_HIST_SEQ;
    MEMCPY_AN(GET_LOTDETAIL_N->LAST_TRAN_CODE, GET_LOTDETAIL->LAST_TRAN_CODE, sizeof(GET_LOTDETAIL->LAST_TRAN_CODE));
    MEMCPY_AN(GET_LOTDETAIL_N->LAST_TRAN_TIME, GET_LOTDETAIL->LAST_TRAN_TIME, sizeof(GET_LOTDETAIL->LAST_TRAN_TIME));
    MEMCPY_AN(GET_LOTDETAIL_N->LAST_COMMENT, GET_LOTDETAIL->LAST_COMMENT, sizeof(GET_LOTDETAIL->LAST_COMMENT));
    GET_LOTDETAIL_N->LAST_ACTIVE_HIST_SEQ = GET_LOTDETAIL->LAST_ACTIVE_HIST_SEQ;
    GET_LOTDETAIL_N->LAST_HIST_SEQ = GET_LOTDETAIL->LAST_HIST_SEQ;
    MEMCPY_AN(GET_LOTDETAIL_N->CRITICAL_RES_ID, GET_LOTDETAIL->CRITICAL_RES_ID, sizeof(GET_LOTDETAIL->CRITICAL_RES_ID));
    MEMCPY_AN(GET_LOTDETAIL_N->CRITICAL_RES_GROUP_ID, GET_LOTDETAIL->CRITICAL_RES_GROUP_ID, sizeof(GET_LOTDETAIL->CRITICAL_RES_GROUP_ID));
    MEMCPY_AN(GET_LOTDETAIL_N->SAVE_RES_ID_1, GET_LOTDETAIL->SAVE_RES_ID_1, sizeof(GET_LOTDETAIL->SAVE_RES_ID_1));
    MEMCPY_AN(GET_LOTDETAIL_N->SAVE_RES_ID_2, GET_LOTDETAIL->SAVE_RES_ID_2, sizeof(GET_LOTDETAIL->SAVE_RES_ID_2));
    MEMCPY_AN(GET_LOTDETAIL_N->SUBRES_ID, GET_LOTDETAIL->SUBRES_ID, sizeof(GET_LOTDETAIL->SUBRES_ID));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_GROUP_ID_1, GET_LOTDETAIL->LOT_GROUP_ID_1, sizeof(GET_LOTDETAIL->LOT_GROUP_ID_1));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_GROUP_ID_2, GET_LOTDETAIL->LOT_GROUP_ID_2, sizeof(GET_LOTDETAIL->LOT_GROUP_ID_2));
    MEMCPY_AN(GET_LOTDETAIL_N->LOT_GROUP_ID_3, GET_LOTDETAIL->LOT_GROUP_ID_3, sizeof(GET_LOTDETAIL->LOT_GROUP_ID_3));
    GET_LOTDETAIL_N->YIELD_1 = GET_LOTDETAIL->YIELD_1;
    GET_LOTDETAIL_N->YIELD_2 = GET_LOTDETAIL->YIELD_2;
    GET_LOTDETAIL_N->YIELD_3 = GET_LOTDETAIL->YIELD_3;
    MEMCPY_AN(GET_LOTDETAIL_N->RESV_FIELD_1, GET_LOTDETAIL->RESV_FIELD_1, sizeof(GET_LOTDETAIL->RESV_FIELD_1));
    MEMCPY_AN(GET_LOTDETAIL_N->RESV_FIELD_2, GET_LOTDETAIL->RESV_FIELD_2, sizeof(GET_LOTDETAIL->RESV_FIELD_2));
    MEMCPY_AN(GET_LOTDETAIL_N->RESV_FIELD_3, GET_LOTDETAIL->RESV_FIELD_3, sizeof(GET_LOTDETAIL->RESV_FIELD_3));
    MEMCPY_AN(GET_LOTDETAIL_N->RESV_FIELD_4, GET_LOTDETAIL->RESV_FIELD_4, sizeof(GET_LOTDETAIL->RESV_FIELD_4));
    MEMCPY_AN(GET_LOTDETAIL_N->RESV_FIELD_5, GET_LOTDETAIL->RESV_FIELD_5, sizeof(GET_LOTDETAIL->RESV_FIELD_5));
    GET_LOTDETAIL_N->RESV_FLAG_1[0] = GET_LOTDETAIL->RESV_FLAG_1;
    GET_LOTDETAIL_N->RESV_FLAG_2[0] = GET_LOTDETAIL->RESV_FLAG_2;
    GET_LOTDETAIL_N->RESV_FLAG_3[0] = GET_LOTDETAIL->RESV_FLAG_3;
    GET_LOTDETAIL_N->RESV_FLAG_4[0] = GET_LOTDETAIL->RESV_FLAG_4;
    GET_LOTDETAIL_N->RESV_FLAG_5[0] = GET_LOTDETAIL->RESV_FLAG_5;
    MEMCPY_AN(GET_LOTDETAIL_N->MAT_DESC, GET_LOTDETAIL->MAT_DESC, sizeof(GET_LOTDETAIL->MAT_DESC));
    MEMCPY_AN(GET_LOTDETAIL_N->FLOW_DESC, GET_LOTDETAIL->FLOW_DESC, sizeof(GET_LOTDETAIL->FLOW_DESC));
    MEMCPY_AN(GET_LOTDETAIL_N->OPER_DESC, GET_LOTDETAIL->OPER_DESC, sizeof(GET_LOTDETAIL->OPER_DESC));
}


/* Del Null Function */
void DBC_del_null_get_lotdetail(struct GET_LOTDETAIL_N_TAG *GET_LOTDETAIL_N, struct GET_LOTDETAIL_TAG *GET_LOTDETAIL)
{
    MEMCPY_DN(GET_LOTDETAIL->LOT_ID, GET_LOTDETAIL_N->LOT_ID, sizeof(GET_LOTDETAIL->LOT_ID));
    MEMCPY_DN(GET_LOTDETAIL->LOT_DESC, GET_LOTDETAIL_N->LOT_DESC, sizeof(GET_LOTDETAIL->LOT_DESC));
    MEMCPY_DN(GET_LOTDETAIL->FACTORY, GET_LOTDETAIL_N->FACTORY, sizeof(GET_LOTDETAIL->FACTORY));
    MEMCPY_DN(GET_LOTDETAIL->MAT_ID, GET_LOTDETAIL_N->MAT_ID, sizeof(GET_LOTDETAIL->MAT_ID));
    GET_LOTDETAIL->MAT_VER = GET_LOTDETAIL_N->MAT_VER;
    MEMCPY_DN(GET_LOTDETAIL->FLOW, GET_LOTDETAIL_N->FLOW, sizeof(GET_LOTDETAIL->FLOW));
    GET_LOTDETAIL->FLOW_SEQ_NUM = GET_LOTDETAIL_N->FLOW_SEQ_NUM;
    MEMCPY_DN(GET_LOTDETAIL->OPER, GET_LOTDETAIL_N->OPER, sizeof(GET_LOTDETAIL->OPER));
    GET_LOTDETAIL->QTY_1 = GET_LOTDETAIL_N->QTY_1;
    GET_LOTDETAIL->QTY_2 = GET_LOTDETAIL_N->QTY_2;
    GET_LOTDETAIL->QTY_3 = GET_LOTDETAIL_N->QTY_3;
    MEMCPY_DN(GET_LOTDETAIL->CRR_ID, GET_LOTDETAIL_N->CRR_ID, sizeof(GET_LOTDETAIL->CRR_ID));
    GET_LOTDETAIL->LOT_TYPE = GET_LOTDETAIL_N->LOT_TYPE[0];
    MEMCPY_DN(GET_LOTDETAIL->OWNER_CODE, GET_LOTDETAIL_N->OWNER_CODE, sizeof(GET_LOTDETAIL->OWNER_CODE));
    MEMCPY_DN(GET_LOTDETAIL->CREATE_CODE, GET_LOTDETAIL_N->CREATE_CODE, sizeof(GET_LOTDETAIL->CREATE_CODE));
    GET_LOTDETAIL->LOT_PRIORITY = GET_LOTDETAIL_N->LOT_PRIORITY[0];
    MEMCPY_DN(GET_LOTDETAIL->LOT_STATUS, GET_LOTDETAIL_N->LOT_STATUS, sizeof(GET_LOTDETAIL->LOT_STATUS));
    GET_LOTDETAIL->HOLD_FLAG = GET_LOTDETAIL_N->HOLD_FLAG[0];
    MEMCPY_DN(GET_LOTDETAIL->HOLD_CODE, GET_LOTDETAIL_N->HOLD_CODE, sizeof(GET_LOTDETAIL->HOLD_CODE));
    MEMCPY_DN(GET_LOTDETAIL->HOLD_PASSWORD, GET_LOTDETAIL_N->HOLD_PASSWORD, sizeof(GET_LOTDETAIL->HOLD_PASSWORD));
    MEMCPY_DN(GET_LOTDETAIL->HOLD_PRV_GRP_ID, GET_LOTDETAIL_N->HOLD_PRV_GRP_ID, sizeof(GET_LOTDETAIL->HOLD_PRV_GRP_ID));
    GET_LOTDETAIL->OPER_IN_QTY_1 = GET_LOTDETAIL_N->OPER_IN_QTY_1;
    GET_LOTDETAIL->OPER_IN_QTY_2 = GET_LOTDETAIL_N->OPER_IN_QTY_2;
    GET_LOTDETAIL->OPER_IN_QTY_3 = GET_LOTDETAIL_N->OPER_IN_QTY_3;
    GET_LOTDETAIL->CREATE_QTY_1 = GET_LOTDETAIL_N->CREATE_QTY_1;
    GET_LOTDETAIL->CREATE_QTY_2 = GET_LOTDETAIL_N->CREATE_QTY_2;
    GET_LOTDETAIL->CREATE_QTY_3 = GET_LOTDETAIL_N->CREATE_QTY_3;
    GET_LOTDETAIL->START_QTY_1 = GET_LOTDETAIL_N->START_QTY_1;
    GET_LOTDETAIL->START_QTY_2 = GET_LOTDETAIL_N->START_QTY_2;
    GET_LOTDETAIL->START_QTY_3 = GET_LOTDETAIL_N->START_QTY_3;
    GET_LOTDETAIL->INV_FLAG = GET_LOTDETAIL_N->INV_FLAG[0];
    GET_LOTDETAIL->TRANSIT_FLAG = GET_LOTDETAIL_N->TRANSIT_FLAG[0];
    GET_LOTDETAIL->UNIT_EXIST_FLAG = GET_LOTDETAIL_N->UNIT_EXIST_FLAG[0];
    MEMCPY_DN(GET_LOTDETAIL->INV_UNIT, GET_LOTDETAIL_N->INV_UNIT, sizeof(GET_LOTDETAIL->INV_UNIT));
    GET_LOTDETAIL->RWK_FLAG = GET_LOTDETAIL_N->RWK_FLAG[0];
    MEMCPY_DN(GET_LOTDETAIL->RWK_CODE, GET_LOTDETAIL_N->RWK_CODE, sizeof(GET_LOTDETAIL->RWK_CODE));
    GET_LOTDETAIL->RWK_COUNT = GET_LOTDETAIL_N->RWK_COUNT;
    MEMCPY_DN(GET_LOTDETAIL->RWK_RET_FLOW, GET_LOTDETAIL_N->RWK_RET_FLOW, sizeof(GET_LOTDETAIL->RWK_RET_FLOW));
    GET_LOTDETAIL->RWK_RET_FLOW_SEQ_NUM = GET_LOTDETAIL_N->RWK_RET_FLOW_SEQ_NUM;
    MEMCPY_DN(GET_LOTDETAIL->RWK_RET_OPER, GET_LOTDETAIL_N->RWK_RET_OPER, sizeof(GET_LOTDETAIL->RWK_RET_OPER));
    MEMCPY_DN(GET_LOTDETAIL->RWK_END_FLOW, GET_LOTDETAIL_N->RWK_END_FLOW, sizeof(GET_LOTDETAIL->RWK_END_FLOW));
    GET_LOTDETAIL->RWK_END_FLOW_SEQ_NUM = GET_LOTDETAIL_N->RWK_END_FLOW_SEQ_NUM;
    MEMCPY_DN(GET_LOTDETAIL->RWK_END_OPER, GET_LOTDETAIL_N->RWK_END_OPER, sizeof(GET_LOTDETAIL->RWK_END_OPER));
    GET_LOTDETAIL->RWK_RET_CLEAR_FLAG = GET_LOTDETAIL_N->RWK_RET_CLEAR_FLAG[0];
    MEMCPY_DN(GET_LOTDETAIL->RWK_TIME, GET_LOTDETAIL_N->RWK_TIME, sizeof(GET_LOTDETAIL->RWK_TIME));
    GET_LOTDETAIL->NSTD_FLAG = GET_LOTDETAIL_N->NSTD_FLAG[0];
    MEMCPY_DN(GET_LOTDETAIL->NSTD_RET_FLOW, GET_LOTDETAIL_N->NSTD_RET_FLOW, sizeof(GET_LOTDETAIL->NSTD_RET_FLOW));
    GET_LOTDETAIL->NSTD_RET_FLOW_SEQ_NUM = GET_LOTDETAIL_N->NSTD_RET_FLOW_SEQ_NUM;
    MEMCPY_DN(GET_LOTDETAIL->NSTD_RET_OPER, GET_LOTDETAIL_N->NSTD_RET_OPER, sizeof(GET_LOTDETAIL->NSTD_RET_OPER));
    MEMCPY_DN(GET_LOTDETAIL->NSTD_TIME, GET_LOTDETAIL_N->NSTD_TIME, sizeof(GET_LOTDETAIL->NSTD_TIME));
    GET_LOTDETAIL->REP_FLAG = GET_LOTDETAIL_N->REP_FLAG[0];
    MEMCPY_DN(GET_LOTDETAIL->REP_RET_OPER, GET_LOTDETAIL_N->REP_RET_OPER, sizeof(GET_LOTDETAIL->REP_RET_OPER));    
    MEMCPY_DN(GET_LOTDETAIL->STR_RET_FLOW, GET_LOTDETAIL_N->STR_RET_FLOW, sizeof(GET_LOTDETAIL->STR_RET_FLOW));
    GET_LOTDETAIL->STR_RET_FLOW_SEQ_NUM = GET_LOTDETAIL_N->STR_RET_FLOW_SEQ_NUM;
    MEMCPY_DN(GET_LOTDETAIL->STR_RET_OPER, GET_LOTDETAIL_N->STR_RET_FLOW, sizeof(GET_LOTDETAIL->STR_RET_OPER));
    GET_LOTDETAIL->START_FLAG = GET_LOTDETAIL_N->START_FLAG[0];
    MEMCPY_DN(GET_LOTDETAIL->START_TIME, GET_LOTDETAIL_N->START_TIME, sizeof(GET_LOTDETAIL->START_TIME));
    MEMCPY_DN(GET_LOTDETAIL->START_RES_ID, GET_LOTDETAIL_N->START_RES_ID, sizeof(GET_LOTDETAIL->START_RES_ID));
    GET_LOTDETAIL->END_FLAG = GET_LOTDETAIL_N->END_FLAG[0];
    MEMCPY_DN(GET_LOTDETAIL->END_TIME, GET_LOTDETAIL_N->END_TIME, sizeof(GET_LOTDETAIL->END_TIME));
    MEMCPY_DN(GET_LOTDETAIL->END_RES_ID, GET_LOTDETAIL_N->END_RES_ID, sizeof(GET_LOTDETAIL->END_RES_ID));
    GET_LOTDETAIL->SAMPLE_FLAG = GET_LOTDETAIL_N->SAMPLE_FLAG[0];
    GET_LOTDETAIL->SAMPLE_WAIT_FLAG = GET_LOTDETAIL_N->SAMPLE_WAIT_FLAG[0];
    GET_LOTDETAIL->SAMPLE_RESULT = GET_LOTDETAIL_N->SAMPLE_RESULT[0];
    GET_LOTDETAIL->FROM_TO_FLAG = GET_LOTDETAIL_N->FROM_TO_FLAG[0];
    MEMCPY_DN(GET_LOTDETAIL->FROM_TO_LOT_ID, GET_LOTDETAIL_N->FROM_TO_LOT_ID, sizeof(GET_LOTDETAIL->FROM_TO_LOT_ID));
    MEMCPY_DN(GET_LOTDETAIL->SHIP_CODE, GET_LOTDETAIL_N->SHIP_CODE, sizeof(GET_LOTDETAIL->SHIP_CODE));
    MEMCPY_DN(GET_LOTDETAIL->SHIP_TIME, GET_LOTDETAIL_N->SHIP_TIME, sizeof(GET_LOTDETAIL->SHIP_TIME));
    MEMCPY_DN(GET_LOTDETAIL->ORG_DUE_TIME, GET_LOTDETAIL_N->ORG_DUE_TIME, sizeof(GET_LOTDETAIL->ORG_DUE_TIME));
    MEMCPY_DN(GET_LOTDETAIL->SCH_DUE_TIME, GET_LOTDETAIL_N->SCH_DUE_TIME, sizeof(GET_LOTDETAIL->SCH_DUE_TIME));
    MEMCPY_DN(GET_LOTDETAIL->CREATE_TIME, GET_LOTDETAIL_N->CREATE_TIME, sizeof(GET_LOTDETAIL->CREATE_TIME));
    MEMCPY_DN(GET_LOTDETAIL->FAC_IN_TIME, GET_LOTDETAIL_N->FAC_IN_TIME, sizeof(GET_LOTDETAIL->FAC_IN_TIME));
    MEMCPY_DN(GET_LOTDETAIL->FLOW_IN_TIME, GET_LOTDETAIL_N->FLOW_IN_TIME, sizeof(GET_LOTDETAIL->FLOW_IN_TIME));
    MEMCPY_DN(GET_LOTDETAIL->OPER_IN_TIME, GET_LOTDETAIL_N->OPER_IN_TIME, sizeof(GET_LOTDETAIL->OPER_IN_TIME));
    MEMCPY_DN(GET_LOTDETAIL->RESERVE_RES_ID, GET_LOTDETAIL_N->RESERVE_RES_ID, sizeof(GET_LOTDETAIL->RESERVE_RES_ID));
    MEMCPY_DN(GET_LOTDETAIL->PORT_ID, GET_LOTDETAIL_N->PORT_ID, sizeof(GET_LOTDETAIL->PORT_ID));
    MEMCPY_DN(GET_LOTDETAIL->BATCH_ID, GET_LOTDETAIL_N->BATCH_ID, sizeof(GET_LOTDETAIL->BATCH_ID));
    GET_LOTDETAIL->BATCH_SEQ = GET_LOTDETAIL_N->BATCH_SEQ;
    MEMCPY_DN(GET_LOTDETAIL->ORDER_ID, GET_LOTDETAIL_N->ORDER_ID, sizeof(GET_LOTDETAIL->ORDER_ID));
    MEMCPY_DN(GET_LOTDETAIL->ADD_ORDER_ID_1, GET_LOTDETAIL_N->ADD_ORDER_ID_1, sizeof(GET_LOTDETAIL->ADD_ORDER_ID_1));
    MEMCPY_DN(GET_LOTDETAIL->ADD_ORDER_ID_2, GET_LOTDETAIL_N->ADD_ORDER_ID_2, sizeof(GET_LOTDETAIL->ADD_ORDER_ID_2));
    MEMCPY_DN(GET_LOTDETAIL->ADD_ORDER_ID_3, GET_LOTDETAIL_N->ADD_ORDER_ID_3, sizeof(GET_LOTDETAIL->ADD_ORDER_ID_3));
    MEMCPY_DN(GET_LOTDETAIL->LOT_LOCATION_1, GET_LOTDETAIL_N->LOT_LOCATION_1, sizeof(GET_LOTDETAIL->LOT_LOCATION_1));
    MEMCPY_DN(GET_LOTDETAIL->LOT_LOCATION_2, GET_LOTDETAIL_N->LOT_LOCATION_2, sizeof(GET_LOTDETAIL->LOT_LOCATION_2));
    MEMCPY_DN(GET_LOTDETAIL->LOT_LOCATION_3, GET_LOTDETAIL_N->LOT_LOCATION_3, sizeof(GET_LOTDETAIL->LOT_LOCATION_3));
    MEMCPY_DN(GET_LOTDETAIL->LOT_CMF_1, GET_LOTDETAIL_N->LOT_CMF_1, sizeof(GET_LOTDETAIL->LOT_CMF_1));
    MEMCPY_DN(GET_LOTDETAIL->LOT_CMF_2, GET_LOTDETAIL_N->LOT_CMF_2, sizeof(GET_LOTDETAIL->LOT_CMF_2));
    MEMCPY_DN(GET_LOTDETAIL->LOT_CMF_3, GET_LOTDETAIL_N->LOT_CMF_3, sizeof(GET_LOTDETAIL->LOT_CMF_3));
    MEMCPY_DN(GET_LOTDETAIL->LOT_CMF_4, GET_LOTDETAIL_N->LOT_CMF_4, sizeof(GET_LOTDETAIL->LOT_CMF_4));
    MEMCPY_DN(GET_LOTDETAIL->LOT_CMF_5, GET_LOTDETAIL_N->LOT_CMF_5, sizeof(GET_LOTDETAIL->LOT_CMF_5));
    MEMCPY_DN(GET_LOTDETAIL->LOT_CMF_6, GET_LOTDETAIL_N->LOT_CMF_6, sizeof(GET_LOTDETAIL->LOT_CMF_6));
    MEMCPY_DN(GET_LOTDETAIL->LOT_CMF_7, GET_LOTDETAIL_N->LOT_CMF_7, sizeof(GET_LOTDETAIL->LOT_CMF_7));
    MEMCPY_DN(GET_LOTDETAIL->LOT_CMF_8, GET_LOTDETAIL_N->LOT_CMF_8, sizeof(GET_LOTDETAIL->LOT_CMF_8));
    MEMCPY_DN(GET_LOTDETAIL->LOT_CMF_9, GET_LOTDETAIL_N->LOT_CMF_9, sizeof(GET_LOTDETAIL->LOT_CMF_9));
    MEMCPY_DN(GET_LOTDETAIL->LOT_CMF_10, GET_LOTDETAIL_N->LOT_CMF_10, sizeof(GET_LOTDETAIL->LOT_CMF_10));
    MEMCPY_DN(GET_LOTDETAIL->LOT_CMF_11, GET_LOTDETAIL_N->LOT_CMF_11, sizeof(GET_LOTDETAIL->LOT_CMF_11));
    MEMCPY_DN(GET_LOTDETAIL->LOT_CMF_12, GET_LOTDETAIL_N->LOT_CMF_12, sizeof(GET_LOTDETAIL->LOT_CMF_12));
    MEMCPY_DN(GET_LOTDETAIL->LOT_CMF_13, GET_LOTDETAIL_N->LOT_CMF_13, sizeof(GET_LOTDETAIL->LOT_CMF_13));
    MEMCPY_DN(GET_LOTDETAIL->LOT_CMF_14, GET_LOTDETAIL_N->LOT_CMF_14, sizeof(GET_LOTDETAIL->LOT_CMF_14));
    MEMCPY_DN(GET_LOTDETAIL->LOT_CMF_15, GET_LOTDETAIL_N->LOT_CMF_15, sizeof(GET_LOTDETAIL->LOT_CMF_15));
    MEMCPY_DN(GET_LOTDETAIL->LOT_CMF_16, GET_LOTDETAIL_N->LOT_CMF_16, sizeof(GET_LOTDETAIL->LOT_CMF_16));
    MEMCPY_DN(GET_LOTDETAIL->LOT_CMF_17, GET_LOTDETAIL_N->LOT_CMF_17, sizeof(GET_LOTDETAIL->LOT_CMF_17));
    MEMCPY_DN(GET_LOTDETAIL->LOT_CMF_18, GET_LOTDETAIL_N->LOT_CMF_18, sizeof(GET_LOTDETAIL->LOT_CMF_18));
    MEMCPY_DN(GET_LOTDETAIL->LOT_CMF_19, GET_LOTDETAIL_N->LOT_CMF_19, sizeof(GET_LOTDETAIL->LOT_CMF_19));
    MEMCPY_DN(GET_LOTDETAIL->LOT_CMF_20, GET_LOTDETAIL_N->LOT_CMF_20, sizeof(GET_LOTDETAIL->LOT_CMF_20));
    GET_LOTDETAIL->LOT_DEL_FLAG = GET_LOTDETAIL_N->LOT_DEL_FLAG[0];
    MEMCPY_DN(GET_LOTDETAIL->LOT_DEL_CODE, GET_LOTDETAIL_N->LOT_DEL_CODE, sizeof(GET_LOTDETAIL->LOT_DEL_CODE));
    MEMCPY_DN(GET_LOTDETAIL->LOT_DEL_TIME, GET_LOTDETAIL_N->LOT_DEL_TIME, sizeof(GET_LOTDETAIL->LOT_DEL_TIME));
    MEMCPY_DN(GET_LOTDETAIL->BOM_SET_ID, GET_LOTDETAIL_N->BOM_SET_ID, sizeof(GET_LOTDETAIL->BOM_SET_ID));
    GET_LOTDETAIL->BOM_SET_VERSION = GET_LOTDETAIL_N->BOM_SET_VERSION;
    GET_LOTDETAIL->BOM_ACTIVE_HIST_SEQ = GET_LOTDETAIL_N->BOM_ACTIVE_HIST_SEQ;
    GET_LOTDETAIL->BOM_HIST_SEQ = GET_LOTDETAIL_N->BOM_HIST_SEQ;
    MEMCPY_DN(GET_LOTDETAIL->LAST_TRAN_CODE, GET_LOTDETAIL_N->LAST_TRAN_CODE, sizeof(GET_LOTDETAIL->LAST_TRAN_CODE));
    MEMCPY_DN(GET_LOTDETAIL->LAST_TRAN_TIME, GET_LOTDETAIL_N->LAST_TRAN_TIME, sizeof(GET_LOTDETAIL->LAST_TRAN_TIME));
    MEMCPY_DN(GET_LOTDETAIL->LAST_COMMENT, GET_LOTDETAIL_N->LAST_COMMENT, sizeof(GET_LOTDETAIL->LAST_COMMENT));
    GET_LOTDETAIL->LAST_ACTIVE_HIST_SEQ = GET_LOTDETAIL_N->LAST_ACTIVE_HIST_SEQ;
    GET_LOTDETAIL->LAST_HIST_SEQ = GET_LOTDETAIL_N->LAST_HIST_SEQ;
    MEMCPY_DN(GET_LOTDETAIL->CRITICAL_RES_ID, GET_LOTDETAIL_N->CRITICAL_RES_ID, sizeof(GET_LOTDETAIL->CRITICAL_RES_ID));
    MEMCPY_DN(GET_LOTDETAIL->CRITICAL_RES_GROUP_ID, GET_LOTDETAIL_N->CRITICAL_RES_GROUP_ID, sizeof(GET_LOTDETAIL->CRITICAL_RES_GROUP_ID));
    MEMCPY_DN(GET_LOTDETAIL->SAVE_RES_ID_1, GET_LOTDETAIL_N->SAVE_RES_ID_1, sizeof(GET_LOTDETAIL->SAVE_RES_ID_1));
    MEMCPY_DN(GET_LOTDETAIL->SAVE_RES_ID_2, GET_LOTDETAIL_N->SAVE_RES_ID_2, sizeof(GET_LOTDETAIL->SAVE_RES_ID_2));
    MEMCPY_DN(GET_LOTDETAIL->SUBRES_ID, GET_LOTDETAIL_N->SUBRES_ID, sizeof(GET_LOTDETAIL->SUBRES_ID));
    MEMCPY_DN(GET_LOTDETAIL->LOT_GROUP_ID_1, GET_LOTDETAIL_N->LOT_GROUP_ID_1, sizeof(GET_LOTDETAIL->LOT_GROUP_ID_1));
    MEMCPY_DN(GET_LOTDETAIL->LOT_GROUP_ID_2, GET_LOTDETAIL_N->LOT_GROUP_ID_2, sizeof(GET_LOTDETAIL->LOT_GROUP_ID_2));
    MEMCPY_DN(GET_LOTDETAIL->LOT_GROUP_ID_3, GET_LOTDETAIL_N->LOT_GROUP_ID_3, sizeof(GET_LOTDETAIL->LOT_GROUP_ID_3));
    GET_LOTDETAIL->YIELD_1 = GET_LOTDETAIL_N->YIELD_1;
    GET_LOTDETAIL->YIELD_2 = GET_LOTDETAIL_N->YIELD_2;
    GET_LOTDETAIL->YIELD_3 = GET_LOTDETAIL_N->YIELD_3;
    MEMCPY_DN(GET_LOTDETAIL->RESV_FIELD_1, GET_LOTDETAIL_N->RESV_FIELD_1, sizeof(GET_LOTDETAIL->RESV_FIELD_1));
    MEMCPY_DN(GET_LOTDETAIL->RESV_FIELD_2, GET_LOTDETAIL_N->RESV_FIELD_2, sizeof(GET_LOTDETAIL->RESV_FIELD_2));
    MEMCPY_DN(GET_LOTDETAIL->RESV_FIELD_3, GET_LOTDETAIL_N->RESV_FIELD_3, sizeof(GET_LOTDETAIL->RESV_FIELD_3));
    MEMCPY_DN(GET_LOTDETAIL->RESV_FIELD_4, GET_LOTDETAIL_N->RESV_FIELD_4, sizeof(GET_LOTDETAIL->RESV_FIELD_4));
    MEMCPY_DN(GET_LOTDETAIL->RESV_FIELD_5, GET_LOTDETAIL_N->RESV_FIELD_5, sizeof(GET_LOTDETAIL->RESV_FIELD_5));
    GET_LOTDETAIL->RESV_FLAG_1 = GET_LOTDETAIL_N->RESV_FLAG_1[0];
    GET_LOTDETAIL->RESV_FLAG_2 = GET_LOTDETAIL_N->RESV_FLAG_2[0];
    GET_LOTDETAIL->RESV_FLAG_3 = GET_LOTDETAIL_N->RESV_FLAG_3[0];
    GET_LOTDETAIL->RESV_FLAG_4 = GET_LOTDETAIL_N->RESV_FLAG_4[0];
    GET_LOTDETAIL->RESV_FLAG_5 = GET_LOTDETAIL_N->RESV_FLAG_5[0];
    MEMCPY_DN(GET_LOTDETAIL->MAT_DESC, GET_LOTDETAIL_N->MAT_DESC, sizeof(GET_LOTDETAIL->MAT_DESC));
    MEMCPY_DN(GET_LOTDETAIL->FLOW_DESC, GET_LOTDETAIL_N->FLOW_DESC, sizeof(GET_LOTDETAIL->FLOW_DESC));
    MEMCPY_DN(GET_LOTDETAIL->OPER_DESC, GET_LOTDETAIL_N->OPER_DESC, sizeof(GET_LOTDETAIL->OPER_DESC));
}

void DBC_init_get_lottrace(struct GET_LOT_TRACE_TAG *LOT_TRACE)
{
    /* memset by Space */
    memset(LOT_TRACE, ' ', sizeof(struct GET_LOT_TRACE_TAG));
    
    LOT_TRACE->P_HIST_SEQ = 0;
    LOT_TRACE->P_OLD_QTY_1 = 0;
    LOT_TRACE->P_QTY_1 = 0;
    LOT_TRACE->P_OLD_QTY_2 = 0;
    LOT_TRACE->P_QTY_2 = 0;
    LOT_TRACE->P_OLD_QTY_3 = 0;
    LOT_TRACE->P_QTY_3 = 0;
    LOT_TRACE->P_MAT_VER = 0;
    LOT_TRACE->P_FLOW_SEQ_NUM = 0;
    LOT_TRACE->C_HIST_SEQ = 0;
    LOT_TRACE->C_OLD_QTY_1 = 0;
    LOT_TRACE->C_QTY_1 = 0;
    LOT_TRACE->C_OLD_QTY_2 = 0;
    LOT_TRACE->C_QTY_2 = 0;
    LOT_TRACE->C_OLD_QTY_3 = 0;
    LOT_TRACE->C_QTY_3 = 0;
    LOT_TRACE->C_MAT_VER = 0;
    LOT_TRACE->C_FLOW_SEQ_NUM = 0;
}

void DBC_open_get_lottrace(int sel_type, struct GET_LOT_TRACE_TAG *LOT_TRACE)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct GET_LOT_TRACE_N_TAG LOT_TRACE_N;
        char   sql[10000];
        char   ts[26];
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_get_lottrace(&LOT_TRACE_N, LOT_TRACE);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            memset( sql, 0x00, sizeof(sql));
            memset( ts, 0x00, sizeof(ts));

            make_valid_quote(ts, LOT_TRACE_N.P_LOT_ID);
            
            sprintf(sql              , "SELECT * FROM ( ");
            sprintf(sql + strlen(sql), " SELECT  PARENT.TRAN_TIME AS P_TRAN_TIME, ");
            sprintf(sql + strlen(sql), "         PARENT.TRAN_CODE AS P_TRAN_CODE, ");
            sprintf(sql + strlen(sql), "         PARENT.FACTORY AS P_FACTORY, ");
            sprintf(sql + strlen(sql), "         PARENT.LOT_ID AS P_LOT_ID, ");
            sprintf(sql + strlen(sql), "         PARENT.HIST_SEQ AS P_HIST_SEQ, ");
            sprintf(sql + strlen(sql), "         PARENT.MAT_ID AS P_MAT_ID, ");
            sprintf(sql + strlen(sql), "         PARENT.MAT_VER AS P_MAT_VER, ");
            sprintf(sql + strlen(sql), "         PARENT.FLOW AS P_FLOW, ");
            sprintf(sql + strlen(sql), "         PARENT.FLOW_SEQ_NUM AS P_FLOW_SEQ_NUM, ");
            sprintf(sql + strlen(sql), "         PARENT.OPER AS P_OPER, ");
            sprintf(sql + strlen(sql), "         PARENT.OLD_QTY_1 AS P_OLD_QTY_1, ");
            sprintf(sql + strlen(sql), "         PARENT.QTY_1 AS P_QTY_1, ");
            sprintf(sql + strlen(sql), "         PARENT.OLD_QTY_2 AS P_OLD_QTY_2, ");
            sprintf(sql + strlen(sql), "         PARENT.QTY_2 AS P_QTY_2, ");
            sprintf(sql + strlen(sql), "         PARENT.OLD_QTY_3 AS P_OLD_QTY_3, ");
            sprintf(sql + strlen(sql), "         PARENT.QTY_3 AS P_QTY_3, ");
            sprintf(sql + strlen(sql), "         PARENT.FROM_TO_FLAG AS FROM_TO_FLAG, ");
            sprintf(sql + strlen(sql), "         CHILD.LOT_ID AS C_LOT_ID, ");
            sprintf(sql + strlen(sql), "         CHILD.HIST_SEQ AS C_HIST_SEQ, ");
            sprintf(sql + strlen(sql), "         CHILD.MAT_ID AS C_MAT_ID, ");
            sprintf(sql + strlen(sql), "         CHILD.MAT_VER AS C_MAT_VER, ");
            sprintf(sql + strlen(sql), "         CHILD.FLOW AS C_FLOW, ");
            sprintf(sql + strlen(sql), "         CHILD.FLOW_SEQ_NUM AS C_FLOW_SEQ_NUM, ");
            sprintf(sql + strlen(sql), "         CHILD.OPER AS C_OPER, ");
            sprintf(sql + strlen(sql), "         CHILD.OLD_QTY_1 AS C_OLD_QTY_1, ");
            sprintf(sql + strlen(sql), "         CHILD.QTY_1 AS C_QTY_1, ");
            sprintf(sql + strlen(sql), "         CHILD.OLD_QTY_2 AS C_OLD_QTY_2, ");
            sprintf(sql + strlen(sql), "         CHILD.QTY_2 AS C_QTY_2, ");
            sprintf(sql + strlen(sql), "         CHILD.OLD_QTY_3 AS C_OLD_QTY_3, ");
            sprintf(sql + strlen(sql), "         CHILD.QTY_3 AS C_QTY_3 ");
            sprintf(sql + strlen(sql), " FROM MWIPLOTSPL SPLT, MWIPLOTHIS PARENT, MWIPLOTHIS CHILD WHERE ");
            sprintf(sql + strlen(sql), "      SPLT.LOT_ID = '%s' AND ", ts);
            sprintf(sql + strlen(sql), "      SPLT.HIST_DEL_FLAG = ' ' AND ");
            sprintf(sql + strlen(sql), "      SPLT.FROM_TO_FLAG = '%c' AND ", LOT_TRACE_N.FROM_TO_FLAG[0]);
            sprintf(sql + strlen(sql), "      SPLT.HIST_SEQ <= %d AND ", LOT_TRACE_N.P_HIST_SEQ);
            sprintf(sql + strlen(sql), "      PARENT.LOT_ID = SPLT.LOT_ID AND ");
            sprintf(sql + strlen(sql), "      PARENT.HIST_SEQ = SPLT.HIST_SEQ AND ");
            sprintf(sql + strlen(sql), "      CHILD.LOT_ID = PARENT.FROM_TO_LOT_ID AND ");
            sprintf(sql + strlen(sql), "      CHILD.HIST_SEQ = PARENT.FROM_TO_HIST_SEQ ");
            sprintf(sql + strlen(sql), "UNION ");
            sprintf(sql + strlen(sql), " SELECT  PARENT.TRAN_TIME AS P_TRAN_TIME, ");
            sprintf(sql + strlen(sql), "         PARENT.TRAN_CODE AS P_TRAN_CODE, ");
            sprintf(sql + strlen(sql), "         PARENT.FACTORY AS P_FACTORY, ");
            sprintf(sql + strlen(sql), "         PARENT.LOT_ID AS P_LOT_ID, ");
            sprintf(sql + strlen(sql), "         PARENT.HIST_SEQ AS P_HIST_SEQ, ");
            sprintf(sql + strlen(sql), "         PARENT.MAT_ID AS P_MAT_ID, ");
            sprintf(sql + strlen(sql), "         PARENT.MAT_VER AS P_MAT_VER, ");
            sprintf(sql + strlen(sql), "         PARENT.FLOW AS P_FLOW, ");
            sprintf(sql + strlen(sql), "         PARENT.FLOW_SEQ_NUM AS P_FLOW_SEQ_NUM, ");
            sprintf(sql + strlen(sql), "         PARENT.OPER AS P_OPER, ");
            sprintf(sql + strlen(sql), "         PARENT.OLD_QTY_1 AS P_OLD_QTY_1, ");
            sprintf(sql + strlen(sql), "         PARENT.QTY_1 AS P_QTY_1, ");
            sprintf(sql + strlen(sql), "         PARENT.OLD_QTY_2 AS P_OLD_QTY_2, ");
            sprintf(sql + strlen(sql), "         PARENT.QTY_2 AS P_QTY_2, ");
            sprintf(sql + strlen(sql), "         PARENT.OLD_QTY_3 AS P_OLD_QTY_3, ");
            sprintf(sql + strlen(sql), "         PARENT.QTY_3 AS P_QTY_3, ");
            sprintf(sql + strlen(sql), "         PARENT.FROM_TO_FLAG AS FROM_TO_FLAG, ");
            sprintf(sql + strlen(sql), "         CHILD.LOT_ID AS C_LOT_ID, ");
            sprintf(sql + strlen(sql), "         CHILD.HIST_SEQ AS C_HIST_SEQ, ");
            sprintf(sql + strlen(sql), "         CHILD.MAT_ID AS C_MAT_ID, ");
            sprintf(sql + strlen(sql), "         CHILD.MAT_VER AS C_MAT_VER, ");
            sprintf(sql + strlen(sql), "         CHILD.FLOW AS C_FLOW, ");
            sprintf(sql + strlen(sql), "         CHILD.FLOW_SEQ_NUM AS C_FLOW_SEQ_NUM, ");
            sprintf(sql + strlen(sql), "         CHILD.OPER AS C_OPER, ");
            sprintf(sql + strlen(sql), "         CHILD.OLD_QTY_1 AS C_OLD_QTY_1, ");
            sprintf(sql + strlen(sql), "         CHILD.QTY_1 AS C_QTY_1, ");
            sprintf(sql + strlen(sql), "         CHILD.OLD_QTY_2 AS C_OLD_QTY_2, ");
            sprintf(sql + strlen(sql), "         CHILD.QTY_2 AS C_QTY_2, ");
            sprintf(sql + strlen(sql), "         CHILD.OLD_QTY_3 AS C_OLD_QTY_3, ");
            sprintf(sql + strlen(sql), "         CHILD.QTY_3 AS C_QTY_3 ");
            sprintf(sql + strlen(sql), " FROM MWIPLOTMRG MRLT, MWIPLOTHIS PARENT, MWIPLOTHIS CHILD WHERE ");
            sprintf(sql + strlen(sql), "      MRLT.LOT_ID = '%s' AND ", ts);
            sprintf(sql + strlen(sql), "      MRLT.HIST_DEL_FLAG = ' ' AND ");
            sprintf(sql + strlen(sql), "      MRLT.FROM_TO_FLAG = '%c' AND ", LOT_TRACE_N.FROM_TO_FLAG[0]);
            sprintf(sql + strlen(sql), "      MRLT.HIST_SEQ <= %d AND ", LOT_TRACE_N.P_HIST_SEQ);
            sprintf(sql + strlen(sql), "      PARENT.LOT_ID = MRLT.LOT_ID AND ");
            sprintf(sql + strlen(sql), "      PARENT.HIST_SEQ = MRLT.HIST_SEQ AND ");
            sprintf(sql + strlen(sql), "      CHILD.LOT_ID = PARENT.FROM_TO_LOT_ID AND ");
            sprintf(sql + strlen(sql), "      CHILD.HIST_SEQ = PARENT.FROM_TO_HIST_SEQ ");
            sprintf(sql + strlen(sql), "UNION ");
            sprintf(sql + strlen(sql), " SELECT  PARENT.TRAN_TIME AS P_TRAN_TIME, ");
            sprintf(sql + strlen(sql), "         PARENT.TRAN_CODE AS P_TRAN_CODE, ");
            sprintf(sql + strlen(sql), "         PARENT.FACTORY AS P_FACTORY, ");
            sprintf(sql + strlen(sql), "         PARENT.LOT_ID AS P_LOT_ID, ");
            sprintf(sql + strlen(sql), "         PARENT.HIST_SEQ AS P_HIST_SEQ, ");
            sprintf(sql + strlen(sql), "         PARENT.MAT_ID AS P_MAT_ID, ");
            sprintf(sql + strlen(sql), "         PARENT.MAT_VER AS P_MAT_VER, ");
            sprintf(sql + strlen(sql), "         PARENT.FLOW AS P_FLOW, ");
            sprintf(sql + strlen(sql), "         PARENT.FLOW_SEQ_NUM AS P_FLOW_SEQ_NUM, ");
            sprintf(sql + strlen(sql), "         PARENT.OPER AS P_OPER, ");
            sprintf(sql + strlen(sql), "         PARENT.OLD_QTY_1 AS P_OLD_QTY_1, ");
            sprintf(sql + strlen(sql), "         PARENT.QTY_1 AS P_QTY_1, ");
            sprintf(sql + strlen(sql), "         PARENT.OLD_QTY_2 AS P_OLD_QTY_2, ");
            sprintf(sql + strlen(sql), "         PARENT.QTY_2 AS P_QTY_2, ");
            sprintf(sql + strlen(sql), "         PARENT.OLD_QTY_3 AS P_OLD_QTY_3, ");
            sprintf(sql + strlen(sql), "         PARENT.QTY_3 AS P_QTY_3, ");
            sprintf(sql + strlen(sql), "         PARENT.FROM_TO_FLAG AS FROM_TO_FLAG, ");
            sprintf(sql + strlen(sql), "         CHILD.LOT_ID AS C_LOT_ID, ");
            sprintf(sql + strlen(sql), "         CHILD.HIST_SEQ AS C_HIST_SEQ, ");
            sprintf(sql + strlen(sql), "         CHILD.MAT_ID AS C_MAT_ID, ");
            sprintf(sql + strlen(sql), "         CHILD.MAT_VER AS C_MAT_VER, ");
            sprintf(sql + strlen(sql), "         CHILD.FLOW AS C_FLOW, ");
            sprintf(sql + strlen(sql), "         CHILD.FLOW_SEQ_NUM AS C_FLOW_SEQ_NUM, ");
            sprintf(sql + strlen(sql), "         CHILD.OPER AS C_OPER, ");
            sprintf(sql + strlen(sql), "         CHILD.OLD_QTY_1 AS C_OLD_QTY_1, ");
            sprintf(sql + strlen(sql), "         CHILD.QTY_1 AS C_QTY_1, ");
            sprintf(sql + strlen(sql), "         CHILD.OLD_QTY_2 AS C_OLD_QTY_2, ");
            sprintf(sql + strlen(sql), "         CHILD.QTY_2 AS C_QTY_2, ");
            sprintf(sql + strlen(sql), "         CHILD.OLD_QTY_3 AS C_OLD_QTY_3, ");
            sprintf(sql + strlen(sql), "         CHILD.QTY_3 AS C_QTY_3 ");
            sprintf(sql + strlen(sql), " FROM MWIPLOTCMB CMLT, MWIPLOTHIS PARENT, MWIPLOTHIS CHILD WHERE ");
            sprintf(sql + strlen(sql), "      CMLT.LOT_ID = '%s' AND ", ts);
            sprintf(sql + strlen(sql), "      CMLT.HIST_DEL_FLAG = ' ' AND ");
            sprintf(sql + strlen(sql), "      CMLT.FROM_TO_FLAG = '%c' AND ", LOT_TRACE_N.FROM_TO_FLAG[0]);
            sprintf(sql + strlen(sql), "      CMLT.HIST_SEQ <= %d AND ", LOT_TRACE_N.P_HIST_SEQ);
            sprintf(sql + strlen(sql), "      PARENT.LOT_ID = CMLT.LOT_ID AND ");
            sprintf(sql + strlen(sql), "      PARENT.HIST_SEQ = CMLT.HIST_SEQ AND ");
            sprintf(sql + strlen(sql), "      CHILD.LOT_ID = PARENT.FROM_TO_LOT_ID AND ");
            sprintf(sql + strlen(sql), "      CHILD.HIST_SEQ = PARENT.FROM_TO_HIST_SEQ ");
            sprintf(sql + strlen(sql), ") SMC ORDER BY P_HIST_SEQ ");

            if(LOT_TRACE_N.FROM_TO_FLAG[0] == 'T')
            {
                sprintf(sql + strlen(sql), "DESC");
            }
            else
            {
                sprintf(sql + strlen(sql), "ASC");
            }

            /* EXEC SQL PREPARE S FROM :sql; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1790;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)sql;
            sqlstm.sqhstl[0] = (unsigned int  )10000;
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


            /* EXEC SQL DECLARE DBC_GET_LOTTRACE_CUR_1 CURSOR FOR S; */ 
 
            /* EXEC SQL OPEN DBC_GET_LOTTRACE_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1809;
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
    DB_stop_query_timer("DBC_open_get_lottrace", sel_type);
}


void DBC_fetch_get_lottrace(int sel_type, struct GET_LOT_TRACE_TAG *LOT_TRACE)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct GET_LOT_TRACE_N_TAG LOT_TRACE_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_GET_LOTTRACE_CUR_1 INTO
                                                    :LOT_TRACE_N.P_TRAN_TIME,
                                                    :LOT_TRACE_N.P_TRAN_CODE,
                                                    :LOT_TRACE_N.P_FACTORY,
                                                    :LOT_TRACE_N.P_LOT_ID,
                                                    :LOT_TRACE_N.P_HIST_SEQ,
                                                    :LOT_TRACE_N.P_MAT_ID,
                                                    :LOT_TRACE_N.P_MAT_VER,
                                                    :LOT_TRACE_N.P_FLOW,
                                                    :LOT_TRACE_N.P_FLOW_SEQ_NUM,
                                                    :LOT_TRACE_N.P_OPER,
                                                    :LOT_TRACE_N.P_OLD_QTY_1,
                                                    :LOT_TRACE_N.P_QTY_1,
                                                    :LOT_TRACE_N.P_OLD_QTY_2,
                                                    :LOT_TRACE_N.P_QTY_2,
                                                    :LOT_TRACE_N.P_OLD_QTY_3,
                                                    :LOT_TRACE_N.P_QTY_3,
                                                    :LOT_TRACE_N.FROM_TO_FLAG,
                                                    :LOT_TRACE_N.C_LOT_ID,
                                                    :LOT_TRACE_N.C_HIST_SEQ,
                                                    :LOT_TRACE_N.C_MAT_ID,
                                                    :LOT_TRACE_N.C_MAT_VER,
                                                    :LOT_TRACE_N.C_FLOW,
                                                    :LOT_TRACE_N.C_FLOW_SEQ_NUM,
                                                    :LOT_TRACE_N.C_OPER,
                                                    :LOT_TRACE_N.C_OLD_QTY_1,
                                                    :LOT_TRACE_N.C_QTY_1,
                                                    :LOT_TRACE_N.C_OLD_QTY_2,
                                                    :LOT_TRACE_N.C_QTY_2,
                                                    :LOT_TRACE_N.C_OLD_QTY_3,
                                                    :LOT_TRACE_N.C_QTY_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1824;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(LOT_TRACE_N.P_TRAN_TIME);
            sqlstm.sqhstl[0] = (unsigned int  )15;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(LOT_TRACE_N.P_TRAN_CODE);
            sqlstm.sqhstl[1] = (unsigned int  )13;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(LOT_TRACE_N.P_FACTORY);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(LOT_TRACE_N.P_LOT_ID);
            sqlstm.sqhstl[3] = (unsigned int  )26;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(LOT_TRACE_N.P_HIST_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(LOT_TRACE_N.P_MAT_ID);
            sqlstm.sqhstl[5] = (unsigned int  )31;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(LOT_TRACE_N.P_MAT_VER);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(LOT_TRACE_N.P_FLOW);
            sqlstm.sqhstl[7] = (unsigned int  )21;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(LOT_TRACE_N.P_FLOW_SEQ_NUM);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(LOT_TRACE_N.P_OPER);
            sqlstm.sqhstl[9] = (unsigned int  )11;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(LOT_TRACE_N.P_OLD_QTY_1);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(LOT_TRACE_N.P_QTY_1);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(LOT_TRACE_N.P_OLD_QTY_2);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(LOT_TRACE_N.P_QTY_2);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(LOT_TRACE_N.P_OLD_QTY_3);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)&(LOT_TRACE_N.P_QTY_3);
            sqlstm.sqhstl[15] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(LOT_TRACE_N.FROM_TO_FLAG);
            sqlstm.sqhstl[16] = (unsigned int  )2;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(LOT_TRACE_N.C_LOT_ID);
            sqlstm.sqhstl[17] = (unsigned int  )26;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)&(LOT_TRACE_N.C_HIST_SEQ);
            sqlstm.sqhstl[18] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
            sqlstm.sqhstv[19] = (         void  *)(LOT_TRACE_N.C_MAT_ID);
            sqlstm.sqhstl[19] = (unsigned int  )31;
            sqlstm.sqhsts[19] = (         int  )0;
            sqlstm.sqindv[19] = (         void  *)0;
            sqlstm.sqinds[19] = (         int  )0;
            sqlstm.sqharm[19] = (unsigned int  )0;
            sqlstm.sqadto[19] = (unsigned short )0;
            sqlstm.sqtdso[19] = (unsigned short )0;
            sqlstm.sqhstv[20] = (         void  *)&(LOT_TRACE_N.C_MAT_VER);
            sqlstm.sqhstl[20] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[20] = (         int  )0;
            sqlstm.sqindv[20] = (         void  *)0;
            sqlstm.sqinds[20] = (         int  )0;
            sqlstm.sqharm[20] = (unsigned int  )0;
            sqlstm.sqadto[20] = (unsigned short )0;
            sqlstm.sqtdso[20] = (unsigned short )0;
            sqlstm.sqhstv[21] = (         void  *)(LOT_TRACE_N.C_FLOW);
            sqlstm.sqhstl[21] = (unsigned int  )21;
            sqlstm.sqhsts[21] = (         int  )0;
            sqlstm.sqindv[21] = (         void  *)0;
            sqlstm.sqinds[21] = (         int  )0;
            sqlstm.sqharm[21] = (unsigned int  )0;
            sqlstm.sqadto[21] = (unsigned short )0;
            sqlstm.sqtdso[21] = (unsigned short )0;
            sqlstm.sqhstv[22] = (         void  *)&(LOT_TRACE_N.C_FLOW_SEQ_NUM);
            sqlstm.sqhstl[22] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[22] = (         int  )0;
            sqlstm.sqindv[22] = (         void  *)0;
            sqlstm.sqinds[22] = (         int  )0;
            sqlstm.sqharm[22] = (unsigned int  )0;
            sqlstm.sqadto[22] = (unsigned short )0;
            sqlstm.sqtdso[22] = (unsigned short )0;
            sqlstm.sqhstv[23] = (         void  *)(LOT_TRACE_N.C_OPER);
            sqlstm.sqhstl[23] = (unsigned int  )11;
            sqlstm.sqhsts[23] = (         int  )0;
            sqlstm.sqindv[23] = (         void  *)0;
            sqlstm.sqinds[23] = (         int  )0;
            sqlstm.sqharm[23] = (unsigned int  )0;
            sqlstm.sqadto[23] = (unsigned short )0;
            sqlstm.sqtdso[23] = (unsigned short )0;
            sqlstm.sqhstv[24] = (         void  *)&(LOT_TRACE_N.C_OLD_QTY_1);
            sqlstm.sqhstl[24] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[24] = (         int  )0;
            sqlstm.sqindv[24] = (         void  *)0;
            sqlstm.sqinds[24] = (         int  )0;
            sqlstm.sqharm[24] = (unsigned int  )0;
            sqlstm.sqadto[24] = (unsigned short )0;
            sqlstm.sqtdso[24] = (unsigned short )0;
            sqlstm.sqhstv[25] = (         void  *)&(LOT_TRACE_N.C_QTY_1);
            sqlstm.sqhstl[25] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[25] = (         int  )0;
            sqlstm.sqindv[25] = (         void  *)0;
            sqlstm.sqinds[25] = (         int  )0;
            sqlstm.sqharm[25] = (unsigned int  )0;
            sqlstm.sqadto[25] = (unsigned short )0;
            sqlstm.sqtdso[25] = (unsigned short )0;
            sqlstm.sqhstv[26] = (         void  *)&(LOT_TRACE_N.C_OLD_QTY_2);
            sqlstm.sqhstl[26] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[26] = (         int  )0;
            sqlstm.sqindv[26] = (         void  *)0;
            sqlstm.sqinds[26] = (         int  )0;
            sqlstm.sqharm[26] = (unsigned int  )0;
            sqlstm.sqadto[26] = (unsigned short )0;
            sqlstm.sqtdso[26] = (unsigned short )0;
            sqlstm.sqhstv[27] = (         void  *)&(LOT_TRACE_N.C_QTY_2);
            sqlstm.sqhstl[27] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[27] = (         int  )0;
            sqlstm.sqindv[27] = (         void  *)0;
            sqlstm.sqinds[27] = (         int  )0;
            sqlstm.sqharm[27] = (unsigned int  )0;
            sqlstm.sqadto[27] = (unsigned short )0;
            sqlstm.sqtdso[27] = (unsigned short )0;
            sqlstm.sqhstv[28] = (         void  *)&(LOT_TRACE_N.C_OLD_QTY_3);
            sqlstm.sqhstl[28] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[28] = (         int  )0;
            sqlstm.sqindv[28] = (         void  *)0;
            sqlstm.sqinds[28] = (         int  )0;
            sqlstm.sqharm[28] = (unsigned int  )0;
            sqlstm.sqadto[28] = (unsigned short )0;
            sqlstm.sqtdso[28] = (unsigned short )0;
            sqlstm.sqhstv[29] = (         void  *)&(LOT_TRACE_N.C_QTY_3);
            sqlstm.sqhstl[29] = (unsigned int  )sizeof(double);
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
        DBC_del_null_get_lottrace(&LOT_TRACE_N, LOT_TRACE);
    }
    DB_stop_query_timer("DBC_fetch_get_lottrace", sel_type);
}

void DBC_close_get_lottrace(int sel_type)
{
    DB_error_code = 0;
    DB_start_query_timer();

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_GET_LOTTRACE_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1959;
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
    DB_stop_query_timer("DBC_close_get_lottrace", sel_type);
}

void DBC_add_null_get_lottrace(struct GET_LOT_TRACE_N_TAG *LOT_TRACE_N, struct GET_LOT_TRACE_TAG *LOT_TRACE)
{
    /* memset by NULL */
    memset(LOT_TRACE_N, '\0', sizeof(struct GET_LOT_TRACE_N_TAG));
    
    MEMCPY_AN(LOT_TRACE_N->P_TRAN_TIME, LOT_TRACE->P_TRAN_TIME, sizeof(LOT_TRACE->P_TRAN_TIME));
    MEMCPY_AN(LOT_TRACE_N->P_TRAN_CODE, LOT_TRACE->P_TRAN_CODE, sizeof(LOT_TRACE->P_TRAN_CODE));
    MEMCPY_AN(LOT_TRACE_N->P_FACTORY, LOT_TRACE->P_FACTORY, sizeof(LOT_TRACE->P_FACTORY));
    MEMCPY_AN(LOT_TRACE_N->P_LOT_ID, LOT_TRACE->P_LOT_ID, sizeof(LOT_TRACE->P_LOT_ID));
    LOT_TRACE_N->P_HIST_SEQ = LOT_TRACE->P_HIST_SEQ;
    MEMCPY_AN(LOT_TRACE_N->P_MAT_ID, LOT_TRACE->P_MAT_ID, sizeof(LOT_TRACE->P_MAT_ID));
    LOT_TRACE_N->P_MAT_VER = LOT_TRACE->P_MAT_VER;
    MEMCPY_AN(LOT_TRACE_N->P_FLOW, LOT_TRACE->P_FLOW, sizeof(LOT_TRACE->P_FLOW));
    LOT_TRACE_N->P_FLOW_SEQ_NUM = LOT_TRACE->P_FLOW_SEQ_NUM;
    MEMCPY_AN(LOT_TRACE_N->P_OPER, LOT_TRACE->P_OPER, sizeof(LOT_TRACE->P_OPER));
    LOT_TRACE_N->P_OLD_QTY_1 = LOT_TRACE->P_OLD_QTY_1;
    LOT_TRACE_N->P_QTY_1 = LOT_TRACE->P_QTY_1;
    LOT_TRACE_N->P_OLD_QTY_2 = LOT_TRACE->P_OLD_QTY_2;
    LOT_TRACE_N->P_QTY_2 = LOT_TRACE->P_QTY_2;
    LOT_TRACE_N->P_OLD_QTY_3 = LOT_TRACE->P_OLD_QTY_3;
    LOT_TRACE_N->P_QTY_3 = LOT_TRACE->P_QTY_3;
    LOT_TRACE_N->FROM_TO_FLAG[0] = LOT_TRACE->FROM_TO_FLAG;
    MEMCPY_AN(LOT_TRACE_N->C_LOT_ID, LOT_TRACE->C_LOT_ID, sizeof(LOT_TRACE->C_LOT_ID));
    LOT_TRACE_N->C_HIST_SEQ = LOT_TRACE->C_HIST_SEQ;
    MEMCPY_AN(LOT_TRACE_N->C_MAT_ID, LOT_TRACE->C_MAT_ID, sizeof(LOT_TRACE->C_MAT_ID));
    LOT_TRACE_N->C_MAT_VER = LOT_TRACE->C_MAT_VER;
    MEMCPY_AN(LOT_TRACE_N->C_FLOW, LOT_TRACE->C_FLOW, sizeof(LOT_TRACE->C_FLOW));
    LOT_TRACE_N->C_FLOW_SEQ_NUM = LOT_TRACE->C_FLOW_SEQ_NUM;
    MEMCPY_AN(LOT_TRACE_N->C_OPER, LOT_TRACE->C_OPER, sizeof(LOT_TRACE->C_OPER));
    LOT_TRACE_N->C_OLD_QTY_1 = LOT_TRACE->C_OLD_QTY_1;
    LOT_TRACE_N->C_QTY_1 = LOT_TRACE->C_QTY_1;
    LOT_TRACE_N->C_OLD_QTY_2 = LOT_TRACE->C_OLD_QTY_2;
    LOT_TRACE_N->C_QTY_2 = LOT_TRACE->C_QTY_2;
    LOT_TRACE_N->C_OLD_QTY_3 = LOT_TRACE->C_OLD_QTY_3;
    LOT_TRACE_N->C_QTY_3 = LOT_TRACE->C_QTY_3;
}

void DBC_del_null_get_lottrace(struct GET_LOT_TRACE_N_TAG *LOT_TRACE_N, struct GET_LOT_TRACE_TAG *LOT_TRACE)
{
    MEMCPY_DN(LOT_TRACE->P_TRAN_TIME, LOT_TRACE_N->P_TRAN_TIME, sizeof(LOT_TRACE->P_TRAN_TIME));
    MEMCPY_DN(LOT_TRACE->P_TRAN_CODE, LOT_TRACE_N->P_TRAN_CODE, sizeof(LOT_TRACE->P_TRAN_CODE));
    MEMCPY_DN(LOT_TRACE->P_FACTORY, LOT_TRACE_N->P_FACTORY, sizeof(LOT_TRACE->P_FACTORY));
    MEMCPY_DN(LOT_TRACE->P_LOT_ID, LOT_TRACE_N->P_LOT_ID, sizeof(LOT_TRACE->P_LOT_ID));
    LOT_TRACE->P_HIST_SEQ = LOT_TRACE_N->P_HIST_SEQ;
    MEMCPY_DN(LOT_TRACE->P_MAT_ID, LOT_TRACE_N->P_MAT_ID, sizeof(LOT_TRACE->P_MAT_ID));
    LOT_TRACE->P_MAT_VER = LOT_TRACE_N->P_MAT_VER;
    MEMCPY_DN(LOT_TRACE->P_FLOW, LOT_TRACE_N->P_FLOW, sizeof(LOT_TRACE->P_FLOW));
    LOT_TRACE->P_FLOW_SEQ_NUM = LOT_TRACE_N->P_FLOW_SEQ_NUM;
    MEMCPY_DN(LOT_TRACE->P_OPER, LOT_TRACE_N->P_OPER, sizeof(LOT_TRACE->P_OPER));
    LOT_TRACE->P_OLD_QTY_1 = LOT_TRACE_N->P_OLD_QTY_1;
    LOT_TRACE->P_QTY_1 = LOT_TRACE_N->P_QTY_1;
    LOT_TRACE->P_OLD_QTY_2 = LOT_TRACE_N->P_OLD_QTY_2;
    LOT_TRACE->P_QTY_2 = LOT_TRACE_N->P_QTY_2;
    LOT_TRACE->P_OLD_QTY_3 = LOT_TRACE_N->P_OLD_QTY_3;
    LOT_TRACE->P_QTY_3 = LOT_TRACE_N->P_QTY_3;
    LOT_TRACE->FROM_TO_FLAG = LOT_TRACE_N->FROM_TO_FLAG[0];
    MEMCPY_DN(LOT_TRACE->C_LOT_ID, LOT_TRACE_N->C_LOT_ID, sizeof(LOT_TRACE->C_LOT_ID));
    LOT_TRACE->C_HIST_SEQ = LOT_TRACE_N->C_HIST_SEQ;
    MEMCPY_DN(LOT_TRACE->C_MAT_ID, LOT_TRACE_N->C_MAT_ID, sizeof(LOT_TRACE->C_MAT_ID));
    LOT_TRACE->C_MAT_VER = LOT_TRACE_N->C_MAT_VER;
    MEMCPY_DN(LOT_TRACE->C_FLOW, LOT_TRACE_N->C_FLOW, sizeof(LOT_TRACE->C_FLOW));
    LOT_TRACE->C_FLOW_SEQ_NUM = LOT_TRACE_N->C_FLOW_SEQ_NUM;
    MEMCPY_DN(LOT_TRACE->C_OPER, LOT_TRACE_N->C_OPER, sizeof(LOT_TRACE->C_OPER));
    LOT_TRACE->C_OLD_QTY_1 = LOT_TRACE_N->C_OLD_QTY_1;
    LOT_TRACE->C_QTY_1 = LOT_TRACE_N->C_QTY_1;
    LOT_TRACE->C_OLD_QTY_2 = LOT_TRACE_N->C_OLD_QTY_2;
    LOT_TRACE->C_QTY_2 = LOT_TRACE_N->C_QTY_2;
    LOT_TRACE->C_OLD_QTY_3 = LOT_TRACE_N->C_OLD_QTY_3;
    LOT_TRACE->C_QTY_3 = LOT_TRACE_N->C_QTY_3;
}

void DBC_init_get_operlist(struct GET_OPER_LIST_TAG *OPER_LIST)
{
    /* memset by Space */
    memset(OPER_LIST, ' ', sizeof(struct GET_OPER_LIST_TAG));
}

void DBC_open_get_operlist(int sel_type, struct GET_OPER_LIST_TAG *OPER_LIST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct GET_OPER_LIST_N_TAG OPER_LIST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_get_operlist(&OPER_LIST_N, OPER_LIST);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBC_GET_OPERLIST_CUR_1 CURSOR FOR
                SELECT F.FACTORY, F.FLOW, F.OPER, O.OPER_DESC, F.OPT_OPER_GROUP, F.OPT_OPER_OPTION_FLAG 
                FROM MWIPFLWOPR F, MWIPOPRDEF O
                WHERE F.FACTORY = :OPER_LIST_N.FACTORY
                AND F.FACTORY = O.FACTORY
                AND F.FLOW = :OPER_LIST_N.FLOW
                AND F.OPER = O.OPER
                ORDER BY F.SEQ_NUM ASC; */ 

            /* EXEC SQL OPEN DBC_GET_OPERLIST_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0007;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1974;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(OPER_LIST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(OPER_LIST_N.FLOW);
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
    DB_stop_query_timer("DBC_open_get_operlist", sel_type);
}


void DBC_fetch_get_operlist(int sel_type, struct GET_OPER_LIST_TAG *OPER_LIST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct GET_OPER_LIST_N_TAG OPER_LIST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_GET_OPERLIST_CUR_1 INTO
                                                    :OPER_LIST_N.FACTORY,
                                                    :OPER_LIST_N.FLOW,
                                                    :OPER_LIST_N.OPER,
                                                    :OPER_LIST_N.OPER_DESC,
                                                    :OPER_LIST_N.OPT_OPER_GROUP,
                                                    :OPER_LIST_N.OPT_OPER_OPTION_FLAG; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1997;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(OPER_LIST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(OPER_LIST_N.FLOW);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(OPER_LIST_N.OPER);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(OPER_LIST_N.OPER_DESC);
            sqlstm.sqhstl[3] = (unsigned int  )201;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(OPER_LIST_N.OPT_OPER_GROUP);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(OPER_LIST_N.OPT_OPER_OPTION_FLAG);
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
        DBC_del_null_get_operlist(&OPER_LIST_N, OPER_LIST);
    }
    DB_stop_query_timer("DBC_fetch_get_operlist", sel_type);
}

void DBC_close_get_operlist(int sel_type)
{
    DB_error_code = 0;
    DB_start_query_timer();

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_GET_OPERLIST_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2036;
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
    DB_stop_query_timer("DBC_close_get_operlist", sel_type);
}

void DBC_add_null_get_operlist(struct GET_OPER_LIST_N_TAG *OPER_LIST_N, struct GET_OPER_LIST_TAG *OPER_LIST)
{
    /* memset by NULL */
    memset(OPER_LIST_N, '\0', sizeof(struct GET_OPER_LIST_N_TAG));
    MEMCPY_AN(OPER_LIST_N->FACTORY, OPER_LIST->FACTORY, sizeof(OPER_LIST->FACTORY));
    MEMCPY_AN(OPER_LIST_N->FLOW, OPER_LIST->FLOW, sizeof(OPER_LIST->FLOW));
    MEMCPY_AN(OPER_LIST_N->OPER, OPER_LIST->OPER, sizeof(OPER_LIST->OPER));
    MEMCPY_AN(OPER_LIST_N->OPER_DESC, OPER_LIST->OPER_DESC, sizeof(OPER_LIST->OPER_DESC));
    MEMCPY_AN(OPER_LIST_N->OPT_OPER_GROUP, OPER_LIST->OPT_OPER_GROUP, sizeof(OPER_LIST->OPT_OPER_GROUP));
    OPER_LIST_N->OPT_OPER_OPTION_FLAG, OPER_LIST->OPT_OPER_OPTION_FLAG;
}

void DBC_del_null_get_operlist(struct GET_OPER_LIST_N_TAG *OPER_LIST_N, struct GET_OPER_LIST_TAG *OPER_LIST)
{
    MEMCPY_DN(OPER_LIST->FACTORY, OPER_LIST_N->FACTORY, sizeof(OPER_LIST->FACTORY));
    MEMCPY_DN(OPER_LIST->FLOW, OPER_LIST_N->FLOW, sizeof(OPER_LIST->FLOW));
    MEMCPY_DN(OPER_LIST->OPER, OPER_LIST_N->OPER, sizeof(OPER_LIST->OPER));
    MEMCPY_DN(OPER_LIST->OPER_DESC, OPER_LIST_N->OPER_DESC, sizeof(OPER_LIST->OPER_DESC));
    MEMCPY_DN(OPER_LIST->OPT_OPER_GROUP, OPER_LIST_N->OPT_OPER_GROUP, sizeof(OPER_LIST->OPT_OPER_GROUP));
    OPER_LIST->OPT_OPER_OPTION_FLAG = OPER_LIST_N->OPT_OPER_OPTION_FLAG[0];
}

/* For Lot on Carrier */
/* Function Declaration */
void DBC_add_null_crr_lot_list(struct CRR_LOT_LIST_N_TAG *CRR_LOT_LIST_N, struct CRR_LOT_LIST_TAG *CRR_LOT_LIST);
void DBC_del_null_crr_lot_list(struct CRR_LOT_LIST_N_TAG *CRR_LOT_LIST_N, struct CRR_LOT_LIST_TAG *CRR_LOT_LIST);

/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_crr_lot_list(int sel_type, struct CRR_LOT_LIST_TAG *CRR_LOT_LIST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CRR_LOT_LIST_N_TAG CRR_LOT_LIST_N;
        char   sql[10000];
        char   ts[1000];
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_crr_lot_list(&CRR_LOT_LIST_N, CRR_LOT_LIST);
    DB_error_code = 0;
    memset(ts, 0x00, sizeof(ts));
 
    switch(sel_type)
    {
        case 1:
            /* LOT.QTY_1, LOT.QTY_2, LOT.QTY_3 : LOT???섎웾 */
            /* CRR1_QTY_1, CRR1_QTY_2, CRR1_QTY_3 : ?낅젰 Carrier???닿꺼吏?LOT???섎웾 */
            /* CRR2_QTY_1, CRR2_QTY_2, CRR2_QTY_3 : ?낅젰 Carrier瑜??ы븿??LOT???닿릿 紐⑤뱺 Carrier?먯꽌??LOT???섎웾 */
            
            /* EXEC SQL DECLARE DBC_CRR_LOT_LIST_CUR_1 CURSOR FOR
                SELECT LOT.LOT_ID, LOT.QTY_1, LOT.QTY_2, LOT.QTY_3,
                    SUM(DECODE(CRR.CRR_ID, :CRR_LOT_LIST_N.CRR_ID, CRR.QTY_1, 0)) CRR1_QTY_1,
                    SUM(DECODE(CRR.CRR_ID, :CRR_LOT_LIST_N.CRR_ID, CRR.QTY_2, 0)) CRR1_QTY_2,
                    SUM(DECODE(CRR.CRR_ID, :CRR_LOT_LIST_N.CRR_ID, CRR.QTY_3, 0)) CRR1_QTY_3,
                    SUM(CRR.QTY_1) CRR2_QTY_1,
                    SUM(CRR.QTY_2) CRR2_QTY_2,
                    SUM(CRR.QTY_3) CRR2_QTY_3
                FROM MWIPLOTSTS LOT, MWIPCRRLOT CRR
                WHERE CRR.FACTORY = :CRR_LOT_LIST_N.FACTORY
                    AND LOT.LOT_ID = CRR.LOT_ID
                    AND LOT.LOT_DEL_FLAG = ' '
                    AND LOT.LOT_ID IN (
                        SELECT LOT_ID 
                        FROM MWIPCRRLOT
                        WHERE CRR_ID = :CRR_LOT_LIST_N.CRR_ID
                          AND LOT_ID >= :CRR_LOT_LIST_N.NEXT_LOT_ID
                        )
                GROUP BY LOT.LOT_ID, LOT.QTY_1, LOT.QTY_2, LOT.QTY_3
                ORDER BY LOT.LOT_ID; */ 

       
            /* EXEC SQL OPEN DBC_CRR_LOT_LIST_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0008;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2051;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(CRR_LOT_LIST_N.CRR_ID);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(CRR_LOT_LIST_N.CRR_ID);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(CRR_LOT_LIST_N.CRR_ID);
            sqlstm.sqhstl[2] = (unsigned int  )21;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(CRR_LOT_LIST_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(CRR_LOT_LIST_N.CRR_ID);
            sqlstm.sqhstl[4] = (unsigned int  )21;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(CRR_LOT_LIST_N.NEXT_LOT_ID);
            sqlstm.sqhstl[5] = (unsigned int  )26;
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
                    
        case 2:
            /* LOT.QTY_1, LOT.QTY_2, LOT.QTY_3 : LOT???섎웾 */
            /* CRR1_QTY_1, CRR1_QTY_2, CRR1_QTY_3 : ?낅젰 Carrier???닿꺼吏?LOT???섎웾 */
            /* CRR2_QTY_1, CRR2_QTY_2, CRR2_QTY_3 : ?낅젰 Carrier瑜??ы븿??LOT???닿릿 紐⑤뱺 Carrier?먯꽌??LOT???섎웾 */

            /* CRR_LOT_LIST_N.LOT_ID??怨듬갚??寃쎌슦 紐⑤뱺 LOT??媛?몄삤怨?*/
            /* 洹몃젃吏 ?딆? 寃쎌슦 ?대떦 LOT瑜?媛?몄삩??*/

            if(strcmp(CRR_LOT_LIST_N.LOT_ID, " ") == 0)
                CRR_LOT_LIST_N.LOT_ID[0] = '%';
                
            memset( sql, 0x00, sizeof(sql));
            sprintf(sql,               "SELECT LOT_ID, SUM(QTY_1), SUM(QTY_2), SUM(QTY_3),");
            sprintf(sql + strlen(sql), " SUM(CRR1_QTY_1), SUM(CRR1_QTY_2), SUM(CRR1_QTY_3),");
            sprintf(sql + strlen(sql), " SUM(CRR2_QTY_1), SUM(CRR2_QTY_2), SUM(CRR2_QTY_3)");
            sprintf(sql + strlen(sql), " FROM (SELECT LOT.LOT_ID,");
            sprintf(sql + strlen(sql), " LOT.QTY_1, LOT.QTY_2, LOT.QTY_3,");
            
            make_valid_quote(ts, CRR_LOT_LIST_N.CRR_ID);
            sprintf(sql + strlen(sql), " SUM(DECODE(CRR.CRR_ID, '%s', CRR.QTY_1, 0)) CRR1_QTY_1,", ts);
            sprintf(sql + strlen(sql), " SUM(DECODE(CRR.CRR_ID, '%s', CRR.QTY_2, 0)) CRR1_QTY_2,", ts);
            sprintf(sql + strlen(sql), " SUM(DECODE(CRR.CRR_ID, '%s', CRR.QTY_3, 0)) CRR1_QTY_3,", ts);
            sprintf(sql + strlen(sql), " SUM(CRR.QTY_1) CRR2_QTY_1,");
            sprintf(sql + strlen(sql), " SUM(CRR.QTY_2) CRR2_QTY_2,");
            sprintf(sql + strlen(sql), " SUM(CRR.QTY_3) CRR2_QTY_3");
            sprintf(sql + strlen(sql), " FROM MWIPLOTSTS LOT, MWIPCRRLOT CRR");
            
            make_valid_quote(ts, CRR_LOT_LIST_N.FACTORY);
            sprintf(sql + strlen(sql), " WHERE LOT.FACTORY = '%s' AND CRR.LOT_ID = LOT.LOT_ID", ts);
            sprintf(sql + strlen(sql), " AND LOT.LOT_DEL_FLAG = ' '");
            
            make_valid_quote(ts, CRR_LOT_LIST_N.LOT_ID);
            sprintf(sql + strlen(sql), " AND LOT.LOT_ID LIKE '%s'", ts);

            if(ISSPACE(CRR_LOT_LIST->NEXT_LOT_ID, sizeof(CRR_LOT_LIST->NEXT_LOT_ID)) == DB_FALSE)
            {
                make_valid_quote(ts, CRR_LOT_LIST_N.NEXT_LOT_ID);
                sprintf(sql + strlen(sql), " AND LOT.LOT_ID >= '%s'", ts);
            }
            sprintf(sql + strlen(sql), " GROUP BY LOT.LOT_ID, LOT.QTY_1, LOT.QTY_2, LOT.QTY_3");
            sprintf(sql + strlen(sql), " UNION");
            sprintf(sql + strlen(sql), " SELECT LOT.LOT_ID,");
            sprintf(sql + strlen(sql), " QTY_1, QTY_2, QTY_3,");
            sprintf(sql + strlen(sql), " 0 CRR1_QTY_1, 0 CRR1_QTY_2, 0 CRR1_QTY_3,");
            sprintf(sql + strlen(sql), " 0 CRR2_QTY_1, 0 CRR2_QTY_2, 0 CRR2_QTY_3");
            sprintf(sql + strlen(sql), " FROM MWIPLOTSTS LOT");
            
            make_valid_quote(ts, CRR_LOT_LIST_N.FACTORY);
            sprintf(sql + strlen(sql), " WHERE LOT.FACTORY = '%s'", ts);
            sprintf(sql + strlen(sql), " AND LOT.LOT_DEL_FLAG = ' '");
            
            sprintf(sql + strlen(sql), " AND NOT EXISTS (SELECT LOT_ID FROM MWIPCRRLOT WHERE LOT_ID = LOT.LOT_ID)");

            make_valid_quote(ts, CRR_LOT_LIST_N.LOT_ID);
            sprintf(sql + strlen(sql), " AND LOT.LOT_ID LIKE '%s'", ts);

            if(ISSPACE(CRR_LOT_LIST->NEXT_LOT_ID, sizeof(CRR_LOT_LIST->NEXT_LOT_ID)) == DB_FALSE)
            {
                make_valid_quote(ts, CRR_LOT_LIST_N.NEXT_LOT_ID);
                sprintf(sql + strlen(sql), " AND LOT.LOT_ID >= '%s'", ts);
            }
            sprintf(sql + strlen(sql), " ) GROUP BY LOT_ID ORDER BY LOT_ID ASC");
            
            /* EXEC SQL PREPARE S FROM :sql; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2090;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)sql;
            sqlstm.sqhstl[0] = (unsigned int  )10000;
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


            /* EXEC SQL DECLARE DBC_CRR_LOT_LIST_CUR_2 CURSOR FOR S; */ 
 
            /* EXEC SQL OPEN DBC_CRR_LOT_LIST_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2109;
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
    DB_stop_query_timer("DBC_open_crr_lot_list", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_crr_lot_list(int sel_type, struct CRR_LOT_LIST_TAG *CRR_LOT_LIST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct CRR_LOT_LIST_N_TAG CRR_LOT_LIST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_CRR_LOT_LIST_CUR_1 
                INTO :CRR_LOT_LIST_N.LOT_ID,
                    :CRR_LOT_LIST_N.QTY_1,
                    :CRR_LOT_LIST_N.QTY_2,
                    :CRR_LOT_LIST_N.QTY_3,
                    :CRR_LOT_LIST_N.CRR1_QTY_1,
                    :CRR_LOT_LIST_N.CRR1_QTY_2,
                    :CRR_LOT_LIST_N.CRR1_QTY_3,
                    :CRR_LOT_LIST_N.CRR2_QTY_1,
                    :CRR_LOT_LIST_N.CRR2_QTY_2,
                    :CRR_LOT_LIST_N.CRR2_QTY_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2124;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CRR_LOT_LIST_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(CRR_LOT_LIST_N.QTY_1);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(CRR_LOT_LIST_N.QTY_2);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CRR_LOT_LIST_N.QTY_3);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CRR_LOT_LIST_N.CRR1_QTY_1);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(CRR_LOT_LIST_N.CRR1_QTY_2);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(CRR_LOT_LIST_N.CRR1_QTY_3);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CRR_LOT_LIST_N.CRR2_QTY_1);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(CRR_LOT_LIST_N.CRR2_QTY_2);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(CRR_LOT_LIST_N.CRR2_QTY_3);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBC_CRR_LOT_LIST_CUR_2 
                INTO :CRR_LOT_LIST_N.LOT_ID,
                    :CRR_LOT_LIST_N.QTY_1,
                    :CRR_LOT_LIST_N.QTY_2,
                    :CRR_LOT_LIST_N.QTY_3,
                    :CRR_LOT_LIST_N.CRR1_QTY_1,
                    :CRR_LOT_LIST_N.CRR1_QTY_2,
                    :CRR_LOT_LIST_N.CRR1_QTY_3,
                    :CRR_LOT_LIST_N.CRR2_QTY_1,
                    :CRR_LOT_LIST_N.CRR2_QTY_2,
                    :CRR_LOT_LIST_N.CRR2_QTY_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2179;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(CRR_LOT_LIST_N.LOT_ID);
            sqlstm.sqhstl[0] = (unsigned int  )26;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(CRR_LOT_LIST_N.QTY_1);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(CRR_LOT_LIST_N.QTY_2);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(CRR_LOT_LIST_N.QTY_3);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(CRR_LOT_LIST_N.CRR1_QTY_1);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(CRR_LOT_LIST_N.CRR1_QTY_2);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(CRR_LOT_LIST_N.CRR1_QTY_3);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(CRR_LOT_LIST_N.CRR2_QTY_1);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(CRR_LOT_LIST_N.CRR2_QTY_2);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(CRR_LOT_LIST_N.CRR2_QTY_3);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
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
        DBC_del_null_crr_lot_list(&CRR_LOT_LIST_N, CRR_LOT_LIST);
    }
    DB_stop_query_timer("DBC_fetch_crr_lot_list", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_crr_lot_list(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_CRR_LOT_LIST_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2234;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
        case 2:
            /* EXEC SQL CLOSE DBC_CRR_LOT_LIST_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2249;
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
    DB_stop_query_timer("DBC_close_crr_lot_list", sel_type);
}


/* Initialize Function */
void DBC_init_crr_lot_list(struct CRR_LOT_LIST_TAG *CRR_LOT_LIST)
{
    /* memset by Space */
    memset(CRR_LOT_LIST, ' ', sizeof(struct CRR_LOT_LIST_TAG));
    CRR_LOT_LIST->QTY_1 = 0;
    CRR_LOT_LIST->QTY_2 = 0;
    CRR_LOT_LIST->QTY_3 = 0;
    CRR_LOT_LIST->CRR1_QTY_1 = 0;
    CRR_LOT_LIST->CRR1_QTY_2 = 0;
    CRR_LOT_LIST->CRR1_QTY_3 = 0;
    CRR_LOT_LIST->CRR2_QTY_1 = 0;
    CRR_LOT_LIST->CRR2_QTY_2 = 0;
    CRR_LOT_LIST->CRR2_QTY_3 = 0;
}

/* Add Null Function */
void DBC_add_null_crr_lot_list(struct CRR_LOT_LIST_N_TAG *CRR_LOT_LIST_N, struct CRR_LOT_LIST_TAG *CRR_LOT_LIST)
{
    /* memset by NULL */
    memset(CRR_LOT_LIST_N, '\0', sizeof(struct CRR_LOT_LIST_N_TAG));
    MEMCPY_AN(CRR_LOT_LIST_N->FACTORY, CRR_LOT_LIST->FACTORY, sizeof(CRR_LOT_LIST->FACTORY));
    MEMCPY_AN(CRR_LOT_LIST_N->CRR_ID, CRR_LOT_LIST->CRR_ID, sizeof(CRR_LOT_LIST->CRR_ID));
    MEMCPY_AN(CRR_LOT_LIST_N->LOT_ID, CRR_LOT_LIST->LOT_ID, sizeof(CRR_LOT_LIST->LOT_ID));
    CRR_LOT_LIST_N->QTY_1 = CRR_LOT_LIST->QTY_1;
    CRR_LOT_LIST_N->QTY_2 = CRR_LOT_LIST->QTY_2;
    CRR_LOT_LIST_N->QTY_3 = CRR_LOT_LIST->QTY_3;
    CRR_LOT_LIST_N->CRR1_QTY_1 = CRR_LOT_LIST->CRR1_QTY_1;
    CRR_LOT_LIST_N->CRR1_QTY_2 = CRR_LOT_LIST->CRR1_QTY_2;
    CRR_LOT_LIST_N->CRR1_QTY_3 = CRR_LOT_LIST->CRR1_QTY_3;
    CRR_LOT_LIST_N->CRR2_QTY_1 = CRR_LOT_LIST->CRR2_QTY_1;
    CRR_LOT_LIST_N->CRR2_QTY_2 = CRR_LOT_LIST->CRR2_QTY_2;
    CRR_LOT_LIST_N->CRR2_QTY_3 = CRR_LOT_LIST->CRR2_QTY_3;
    MEMCPY_AN(CRR_LOT_LIST_N->NEXT_LOT_ID, CRR_LOT_LIST->NEXT_LOT_ID, sizeof(CRR_LOT_LIST->NEXT_LOT_ID));
}


/* Del Null Function */
void DBC_del_null_crr_lot_list(struct CRR_LOT_LIST_N_TAG *CRR_LOT_LIST_N, struct CRR_LOT_LIST_TAG *CRR_LOT_LIST)
{
    MEMCPY_DN(CRR_LOT_LIST->FACTORY, CRR_LOT_LIST_N->FACTORY, sizeof(CRR_LOT_LIST->FACTORY));
    MEMCPY_DN(CRR_LOT_LIST->CRR_ID, CRR_LOT_LIST_N->CRR_ID, sizeof(CRR_LOT_LIST->CRR_ID));
    MEMCPY_DN(CRR_LOT_LIST->LOT_ID, CRR_LOT_LIST_N->LOT_ID, sizeof(CRR_LOT_LIST->LOT_ID));
    CRR_LOT_LIST->QTY_1 = CRR_LOT_LIST_N->QTY_1;
    CRR_LOT_LIST->QTY_2 = CRR_LOT_LIST_N->QTY_2;
    CRR_LOT_LIST->QTY_3 = CRR_LOT_LIST_N->QTY_3;
    CRR_LOT_LIST->CRR1_QTY_1 = CRR_LOT_LIST_N->CRR1_QTY_1;
    CRR_LOT_LIST->CRR1_QTY_2 = CRR_LOT_LIST_N->CRR1_QTY_2;
    CRR_LOT_LIST->CRR1_QTY_3 = CRR_LOT_LIST_N->CRR1_QTY_3;
    CRR_LOT_LIST->CRR2_QTY_1 = CRR_LOT_LIST_N->CRR2_QTY_1;
    CRR_LOT_LIST->CRR2_QTY_2 = CRR_LOT_LIST_N->CRR2_QTY_2;
    CRR_LOT_LIST->CRR2_QTY_3 = CRR_LOT_LIST_N->CRR2_QTY_3;
    MEMCPY_DN(CRR_LOT_LIST->NEXT_LOT_ID, CRR_LOT_LIST_N->NEXT_LOT_ID, sizeof(CRR_LOT_LIST->NEXT_LOT_ID));
}




void DBC_add_null_get_mfo(struct GET_MFO_N_TAG *GET_MFO_N, struct GET_MFO_TAG *GET_MFO);
void DBC_del_null_get_mfo(struct GET_MFO_N_TAG *GET_MFO_N, struct GET_MFO_TAG *GET_MFO);


void DBC_open_get_mfo(int sel_type, struct GET_MFO_TAG *GET_MFO)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct GET_MFO_N_TAG GET_MFO_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_get_mfo(&GET_MFO_N, GET_MFO);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1: /* Material, Version??Flow, Oper. Flow Sequence???곕씪 ???쒕쾲留??섏삤?꾨줉 */
            /* EXEC SQL DECLARE DBC_GET_MFO_CUR_1 CURSOR FOR 
                SELECT *
                FROM (
                    SELECT ROWNUM ROWSEQ, FOL.*
                    FROM (
                        SELECT MF.FLOW, FD.FLOW_DESC, FO.OPER, OD.OPER_DESC, MIN(MF.FLOW_SEQ_NUM) FLOW_SEQ, MIN(FO.SEQ_NUM) OPER_SEQ
                        FROM MWIPOPRDEF OD, MWIPFLWOPR FO, MWIPMATFLW MF, MWIPFLWDEF FD
                        WHERE   FO.FACTORY = OD.FACTORY
                            AND FO.OPER = OD.OPER
                            AND FO.FACTORY = FD.FACTORY
                            AND FO.FLOW = FD.FLOW
                            AND MF.FACTORY = FO.FACTORY
                            AND MF.FLOW = FO.FLOW
                            AND MF.FACTORY = :GET_MFO_N.FACTORY
                            AND MF.MAT_ID = :GET_MFO_N.MAT_ID
                            AND MF.MAT_VER = :GET_MFO_N.MAT_VER
                        GROUP BY MF.FLOW, FD.FLOW_DESC, FO.OPER, OD.OPER_DESC
                        ORDER BY FLOW_SEQ ASC, OPER_SEQ ASC
                    ) FOL
                )
                WHERE ROWSEQ >= :GET_MFO_N.NEXT_SEQ
                ORDER BY ROWSEQ ASC; */ 


            /* EXEC SQL OPEN DBC_GET_MFO_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0009;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2264;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(GET_MFO_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(GET_MFO_N.MAT_VER);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(GET_MFO_N.NEXT_SEQ);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
            
        case 2:
            /* EXEC SQL DECLARE DBC_GET_MFO_CUR_2 CURSOR FOR 
                SELECT FO.OPER, OD.OPER_DESC, FO.SEQ_NUM, FO.SEQ_NUM
                FROM MWIPOPRDEF OD, MWIPFLWOPR FO
                WHERE FO.FACTORY = OD.FACTORY
                      AND FO.OPER = OD.OPER
                      AND OD.FACTORY = :GET_MFO_N.FACTORY
                      AND FO.FLOW = :GET_MFO_N.FLOW
                      AND FO.SEQ_NUM >= :GET_MFO_N.NEXT_SEQ
                ORDER BY FO.SEQ_NUM ASC; */ 


            /* EXEC SQL OPEN DBC_GET_MFO_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0010;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2295;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(GET_MFO_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_N.FLOW);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(GET_MFO_N.NEXT_SEQ);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
                
        case 3:
            /* EXEC SQL DECLARE DBC_GET_MFO_CUR_3 CURSOR FOR 
                SELECT *
                FROM (
                    SELECT ROWNUM ROWSEQ, OL.*
                    FROM (
                        SELECT OPER, OPER_DESC           
                        FROM MWIPOPRDEF                                                       
                        WHERE FACTORY = :GET_MFO_N.FACTORY
                        ORDER BY OPER ASC
                    ) OL
                )
                WHERE ROWSEQ >= :GET_MFO_N.NEXT_SEQ
                ORDER BY ROWSEQ ASC; */ 


            /* EXEC SQL OPEN DBC_GET_MFO_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0011;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2322;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(GET_MFO_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(GET_MFO_N.NEXT_SEQ);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
            
        case 4: /* Material, Version??Flow, Oper. Flow Sequence???곕씪 紐⑤뱺 Flow ?섏삤?꾨줉 */
            /* EXEC SQL DECLARE DBC_GET_MFO_CUR_4 CURSOR FOR 
                SELECT *
                FROM (
                    SELECT ROWNUM ROWSEQ, FOL.*
                    FROM (
                        SELECT MF.FLOW, FD.FLOW_DESC, FO.OPER, OD.OPER_DESC, MF.FLOW_SEQ_NUM, FO.SEQ_NUM
                        FROM MWIPOPRDEF OD, MWIPFLWOPR FO, MWIPMATFLW MF, MWIPFLWDEF FD
                        WHERE   FO.FACTORY = OD.FACTORY
                            AND FO.OPER = OD.OPER
                            AND FO.FACTORY = FD.FACTORY
                            AND FO.FLOW = FD.FLOW
                            AND MF.FACTORY = FO.FACTORY
                            AND MF.FLOW = FO.FLOW
                            AND MF.FACTORY = :GET_MFO_N.FACTORY
                            AND MF.MAT_ID = :GET_MFO_N.MAT_ID
                            AND MF.MAT_VER = :GET_MFO_N.MAT_VER
                        ORDER BY MF.FLOW_SEQ_NUM ASC, FO.SEQ_NUM ASC
                    ) FOL
                )
                WHERE ROWSEQ >= :GET_MFO_N.NEXT_SEQ
                ORDER BY ROWSEQ ASC; */ 


            /* EXEC SQL OPEN DBC_GET_MFO_CUR_4; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0012;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2345;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(GET_MFO_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(GET_MFO_N.MAT_VER);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(GET_MFO_N.NEXT_SEQ);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
            
            case 5: /* Material, Version??Flow, Oper. Flow Sequence???곕씪 紐⑤뱺 Flow ?섏삤?꾨줉 */
            /* EXEC SQL DECLARE DBC_GET_MFO_CUR_5 CURSOR FOR 
                SELECT *
                FROM (
                    SELECT ROWNUM ROWSEQ, FOL.*
                    FROM (
                        SELECT MF.FLOW, FD.FLOW_DESC, FO.OPER, OD.OPER_DESC, MF.FLOW_SEQ_NUM, FO.SEQ_NUM
                        FROM MWIPOPRDEF OD, MWIPFLWOPR FO, MWIPMATFLW MF, MWIPFLWDEF FD
                        WHERE   FO.FACTORY = OD.FACTORY
                            AND FO.OPER = OD.OPER
                            AND FO.FACTORY = FD.FACTORY
                            AND FO.FLOW = FD.FLOW
                            AND MF.FACTORY = FO.FACTORY
                            AND MF.FLOW = FO.FLOW
                            AND MF.FACTORY = :GET_MFO_N.FACTORY
                            AND MF.MAT_ID = :GET_MFO_N.MAT_ID
                            AND MF.MAT_VER = :GET_MFO_N.MAT_VER
                            AND MF.FLOW = :GET_MFO_N.FLOW
                            AND MF.FLOW_SEQ_NUM = :GET_MFO_N.FLOW_SEQ                            
                        ORDER BY MF.FLOW_SEQ_NUM ASC, FO.SEQ_NUM ASC
                    ) FOL
                )
                WHERE ROWSEQ >= :GET_MFO_N.NEXT_SEQ
                ORDER BY ROWSEQ ASC; */ 

                
            /* EXEC SQL OPEN DBC_GET_MFO_CUR_5; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0013;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2376;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(GET_MFO_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(GET_MFO_N.MAT_VER);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_MFO_N.FLOW);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(GET_MFO_N.FLOW_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(GET_MFO_N.NEXT_SEQ);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
                
            case 6: /* Version??Flow, Oper. Flow Sequence???곕씪 紐⑤뱺 Flow ?섏삤?꾨줉 */
            /* EXEC SQL DECLARE DBC_GET_MFO_CUR_6 CURSOR FOR 
                SELECT *
                FROM (
                    SELECT ROWNUM ROWSEQ, FOL.*
                    FROM (
                        SELECT MF.FLOW, FD.FLOW_DESC, FO.OPER, OD.OPER_DESC, MF.FLOW_SEQ_NUM, FO.SEQ_NUM
                        FROM MWIPOPRDEF OD, MWIPFLWOPR FO, MWIPMATFLW MF, MWIPFLWDEF FD
                        WHERE   FO.FACTORY = OD.FACTORY
                            AND FO.OPER = OD.OPER
                            AND FO.FACTORY = FD.FACTORY
                            AND FO.FLOW = FD.FLOW
                            AND MF.FACTORY = FO.FACTORY
                            AND MF.FLOW = FO.FLOW
                            AND MF.FACTORY = :GET_MFO_N.FACTORY
                            AND MF.FLOW = :GET_MFO_N.FLOW
                        ORDER BY MF.FLOW_SEQ_NUM ASC, FO.SEQ_NUM ASC
                    ) FOL
                )
                WHERE ROWSEQ >= :GET_MFO_N.NEXT_SEQ
                ORDER BY ROWSEQ ASC; */ 


            /* EXEC SQL OPEN DBC_GET_MFO_CUR_6; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0014;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2415;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(GET_MFO_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_N.FLOW);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(GET_MFO_N.NEXT_SEQ);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
            
            case 7: /* Version??Flow, Oper. Flow Sequence???곕씪 紐⑤뱺 Flow ?섏삤?꾨줉 */
            /* EXEC SQL DECLARE DBC_GET_MFO_CUR_7 CURSOR FOR 
                SELECT *
                FROM (
                    SELECT ROWNUM ROWSEQ, FOL.*
                    FROM (
                        SELECT MF.FLOW, FD.FLOW_DESC, FO.OPER, OD.OPER_DESC, MF.FLOW_SEQ_NUM, FO.SEQ_NUM
                        FROM MWIPOPRDEF OD, MWIPFLWOPR FO, MWIPMATFLW MF, MWIPFLWDEF FD
                        WHERE   FO.FACTORY = OD.FACTORY
                            AND FO.OPER = OD.OPER
                            AND FO.FACTORY = FD.FACTORY
                            AND FO.FLOW = FD.FLOW
                            AND MF.FACTORY = FO.FACTORY
                            AND MF.FLOW = FO.FLOW
                            AND MF.FACTORY = :GET_MFO_N.FACTORY                           
                        ORDER BY MF.FLOW ASC, MF.FLOW_SEQ_NUM ASC, FO.SEQ_NUM ASC
                    ) FOL
                )
                WHERE ROWSEQ >= :GET_MFO_N.NEXT_SEQ
                ORDER BY ROWSEQ ASC; */ 


            /* EXEC SQL OPEN DBC_GET_MFO_CUR_7; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0015;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2442;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(GET_MFO_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(GET_MFO_N.NEXT_SEQ);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

            case 8: /* Add for RTD */
            /* EXEC SQL DECLARE DBC_GET_MFO_CUR_8 CURSOR FOR 
                SELECT *
                FROM (
                    SELECT ROWNUM ROWSEQ, FOL.*
                    FROM (
                        SELECT MF.FLOW, FD.FLOW_DESC, FO.OPER, OD.OPER_DESC, MF.FLOW_SEQ_NUM, FO.SEQ_NUM
                        FROM MWIPOPRDEF OD, MWIPFLWOPR FO, MWIPMATFLW MF, MWIPFLWDEF FD
                        WHERE   FO.FACTORY = OD.FACTORY
                            AND FO.OPER = OD.OPER
                            AND FO.FACTORY = FD.FACTORY
                            AND FO.FLOW = FD.FLOW
                            AND MF.FACTORY = FO.FACTORY
                            AND MF.FLOW = FO.FLOW
                            AND MF.FACTORY = :GET_MFO_N.FACTORY
                            AND MF.MAT_ID = :GET_MFO_N.MAT_ID
                            AND MF.MAT_VER = :GET_MFO_N.MAT_VER
                            AND MF.FLOW_SEQ_NUM >= :GET_MFO_N.FLOW_SEQ
                            AND FO.SEQ_NUM >= (SELECT SEQ_NUM FROM MWIPFLWOPR WHERE FACTORY= :GET_MFO_N.FACTORY 
                                                                                   AND FLOW = :GET_MFO_N.FLOW
                                                                                   AND OPER = :GET_MFO_N.OPER)
                        ORDER BY MF.FLOW_SEQ_NUM ASC, FO.SEQ_NUM ASC
                    ) FOL
                )
                WHERE ROWSEQ >= :GET_MFO_N.NEXT_SEQ
                ORDER BY ROWSEQ ASC; */ 


            /* EXEC SQL OPEN DBC_GET_MFO_CUR_8; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0016;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2465;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(GET_MFO_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(GET_MFO_N.MAT_VER);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(GET_MFO_N.FLOW_SEQ);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(GET_MFO_N.FACTORY);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(GET_MFO_N.FLOW);
            sqlstm.sqhstl[5] = (unsigned int  )21;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(GET_MFO_N.OPER);
            sqlstm.sqhstl[6] = (unsigned int  )11;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(GET_MFO_N.NEXT_SEQ);
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
    DB_stop_query_timer("DBC_open_get_mfo", sel_type);
}

/* SQL CURSOR FETCH Function */
void DBC_fetch_get_mfo(int sel_type, struct GET_MFO_TAG *GET_MFO)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct GET_MFO_N_TAG GET_MFO_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    
    /*?쇰? ?꾨뱶留?媛吏怨??댁쑝濡?珥덇린??*/
    memset(&GET_MFO_N, ' ', sizeof(struct GET_MFO_N_TAG));
    GET_MFO_N.MAT_VER = 0;
    GET_MFO_N.FLOW_SEQ = 0;
    GET_MFO_N.OPER_SEQ = 0;
    GET_MFO_N.NEXT_SEQ = 0;
    
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_GET_MFO_CUR_1 INTO 
                :GET_MFO_N.NEXT_SEQ,
                :GET_MFO_N.FLOW,
                :GET_MFO_N.FLOW_DESC,
                :GET_MFO_N.OPER,
                :GET_MFO_N.OPER_DESC,
                :GET_MFO_N.FLOW_SEQ,
                :GET_MFO_N.OPER_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2512;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(GET_MFO_N.NEXT_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_N.FLOW);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_MFO_N.FLOW_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_MFO_N.OPER);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(GET_MFO_N.OPER_DESC);
            sqlstm.sqhstl[4] = (unsigned int  )201;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(GET_MFO_N.FLOW_SEQ);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(GET_MFO_N.OPER_SEQ);
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
            /* EXEC SQL FETCH DBC_GET_MFO_CUR_2 INTO 
                :GET_MFO_N.OPER,
                :GET_MFO_N.OPER_DESC,
                :GET_MFO_N.OPER_SEQ,
                :GET_MFO_N.NEXT_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2555;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(GET_MFO_N.OPER);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_N.OPER_DESC);
            sqlstm.sqhstl[1] = (unsigned int  )201;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(GET_MFO_N.OPER_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(GET_MFO_N.NEXT_SEQ);
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

        case 3:
            /* EXEC SQL FETCH DBC_GET_MFO_CUR_3 INTO 
                :GET_MFO_N.NEXT_SEQ,
                :GET_MFO_N.OPER,
                :GET_MFO_N.OPER_DESC; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2586;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(GET_MFO_N.NEXT_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_N.OPER);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_MFO_N.OPER_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
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
 
         case 4:
            /* EXEC SQL FETCH DBC_GET_MFO_CUR_4 INTO 
                :GET_MFO_N.NEXT_SEQ,
                :GET_MFO_N.FLOW,
                :GET_MFO_N.FLOW_DESC,
                :GET_MFO_N.OPER,
                :GET_MFO_N.OPER_DESC,
                :GET_MFO_N.FLOW_SEQ,
                :GET_MFO_N.OPER_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2613;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(GET_MFO_N.NEXT_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_N.FLOW);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_MFO_N.FLOW_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_MFO_N.OPER);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(GET_MFO_N.OPER_DESC);
            sqlstm.sqhstl[4] = (unsigned int  )201;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(GET_MFO_N.FLOW_SEQ);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(GET_MFO_N.OPER_SEQ);
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

         case 5:
            /* EXEC SQL FETCH DBC_GET_MFO_CUR_5 INTO 
                :GET_MFO_N.NEXT_SEQ,
                :GET_MFO_N.FLOW,
                :GET_MFO_N.FLOW_DESC,
                :GET_MFO_N.OPER,
                :GET_MFO_N.OPER_DESC,
                :GET_MFO_N.FLOW_SEQ,
                :GET_MFO_N.OPER_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2656;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(GET_MFO_N.NEXT_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_N.FLOW);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_MFO_N.FLOW_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_MFO_N.OPER);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(GET_MFO_N.OPER_DESC);
            sqlstm.sqhstl[4] = (unsigned int  )201;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(GET_MFO_N.FLOW_SEQ);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(GET_MFO_N.OPER_SEQ);
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

         case 6:
            /* EXEC SQL FETCH DBC_GET_MFO_CUR_6 INTO 
                :GET_MFO_N.NEXT_SEQ,
                :GET_MFO_N.FLOW,
                :GET_MFO_N.FLOW_DESC,
                :GET_MFO_N.OPER,
                :GET_MFO_N.OPER_DESC,
                :GET_MFO_N.FLOW_SEQ,
                :GET_MFO_N.OPER_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2699;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(GET_MFO_N.NEXT_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_N.FLOW);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_MFO_N.FLOW_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_MFO_N.OPER);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(GET_MFO_N.OPER_DESC);
            sqlstm.sqhstl[4] = (unsigned int  )201;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(GET_MFO_N.FLOW_SEQ);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(GET_MFO_N.OPER_SEQ);
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

         case 7:
            /* EXEC SQL FETCH DBC_GET_MFO_CUR_7 INTO 
                :GET_MFO_N.NEXT_SEQ,
                :GET_MFO_N.FLOW,
                :GET_MFO_N.FLOW_DESC,
                :GET_MFO_N.OPER,
                :GET_MFO_N.OPER_DESC,
                :GET_MFO_N.FLOW_SEQ,
                :GET_MFO_N.OPER_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2742;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(GET_MFO_N.NEXT_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_N.FLOW);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_MFO_N.FLOW_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_MFO_N.OPER);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(GET_MFO_N.OPER_DESC);
            sqlstm.sqhstl[4] = (unsigned int  )201;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(GET_MFO_N.FLOW_SEQ);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(GET_MFO_N.OPER_SEQ);
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

         case 8:
            /* EXEC SQL FETCH DBC_GET_MFO_CUR_8 INTO 
                :GET_MFO_N.NEXT_SEQ,
                :GET_MFO_N.FLOW,
                :GET_MFO_N.FLOW_DESC,
                :GET_MFO_N.OPER,
                :GET_MFO_N.OPER_DESC,
                :GET_MFO_N.FLOW_SEQ,
                :GET_MFO_N.OPER_SEQ; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2785;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(GET_MFO_N.NEXT_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_N.FLOW);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_MFO_N.FLOW_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_MFO_N.OPER);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(GET_MFO_N.OPER_DESC);
            sqlstm.sqhstl[4] = (unsigned int  )201;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(GET_MFO_N.FLOW_SEQ);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(GET_MFO_N.OPER_SEQ);
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

    if(DB_error_code == 0)
    {
        DBC_del_null_get_mfo(&GET_MFO_N, GET_MFO);
    }
    DB_stop_query_timer("DBC_fetch_get_mfo", sel_type);
}

/* SQL CURSOR CLOSE Function */
void DBC_close_get_mfo(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_GET_MFO_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2828;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
                    
        case 2:
            /* EXEC SQL CLOSE DBC_GET_MFO_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2843;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 3:
            /* EXEC SQL CLOSE DBC_GET_MFO_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2858;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 4:
            /* EXEC SQL CLOSE DBC_GET_MFO_CUR_4; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2873;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 5:
            /* EXEC SQL CLOSE DBC_GET_MFO_CUR_5; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2888;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
            
        case 6:
            /* EXEC SQL CLOSE DBC_GET_MFO_CUR_6; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2903;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;            

        case 7:
            /* EXEC SQL CLOSE DBC_GET_MFO_CUR_7; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2918;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 8:
            /* EXEC SQL CLOSE DBC_GET_MFO_CUR_8; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2933;
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
    DB_stop_query_timer("DBC_close_get_mfo", sel_type);
}

/* Initialize Function */
void DBC_init_get_mfo(struct GET_MFO_TAG *GET_MFO)
{
    /* memset by Space */
    memset(GET_MFO, ' ', sizeof(struct GET_MFO_TAG));

    GET_MFO->MAT_VER = 0;
    GET_MFO->FLOW_SEQ = 0;
    GET_MFO->OPER_SEQ = 0;
    GET_MFO->NEXT_SEQ = 0;
}

/* Add Null Function */
void DBC_add_null_get_mfo(struct GET_MFO_N_TAG *GET_MFO_N, struct GET_MFO_TAG *GET_MFO)
{ 
    /* memset by NULL */
    memset(GET_MFO_N, '\0', sizeof(struct GET_MFO_N_TAG));

    MEMCPY_AN(GET_MFO_N->FACTORY,GET_MFO->FACTORY,sizeof(GET_MFO->FACTORY));
    MEMCPY_AN(GET_MFO_N->MAT_ID,GET_MFO->MAT_ID,sizeof(GET_MFO->MAT_ID));
    GET_MFO_N->MAT_VER = GET_MFO->MAT_VER;
    MEMCPY_AN(GET_MFO_N->FLOW,GET_MFO->FLOW,sizeof(GET_MFO->FLOW));
    MEMCPY_AN(GET_MFO_N->FLOW_DESC,GET_MFO->FLOW_DESC,sizeof(GET_MFO->FLOW_DESC));
    MEMCPY_AN(GET_MFO_N->OPER, GET_MFO->OPER, sizeof(GET_MFO->OPER));
    MEMCPY_AN(GET_MFO_N->OPER_DESC, GET_MFO->OPER_DESC, sizeof(GET_MFO->OPER_DESC));
    GET_MFO_N->FLOW_SEQ = GET_MFO->FLOW_SEQ;
    GET_MFO_N->OPER_SEQ = GET_MFO->OPER_SEQ;
    GET_MFO_N->NEXT_SEQ = GET_MFO->NEXT_SEQ;
}


/* Del Null Function */
void DBC_del_null_get_mfo(struct GET_MFO_N_TAG *GET_MFO_N, struct GET_MFO_TAG *GET_MFO)
{
    MEMCPY_DN(GET_MFO->FACTORY,GET_MFO_N->FACTORY,sizeof(GET_MFO->FACTORY));
    MEMCPY_DN(GET_MFO->MAT_ID,GET_MFO_N->MAT_ID,sizeof(GET_MFO->MAT_ID));
    GET_MFO->MAT_VER = GET_MFO_N->MAT_VER;
    MEMCPY_DN(GET_MFO->FLOW,GET_MFO_N->FLOW,sizeof(GET_MFO->FLOW));
    MEMCPY_DN(GET_MFO->FLOW_DESC,GET_MFO_N->FLOW_DESC,sizeof(GET_MFO->FLOW_DESC));
    MEMCPY_DN(GET_MFO->OPER, GET_MFO_N->OPER, sizeof(GET_MFO->OPER));
    MEMCPY_DN(GET_MFO->OPER_DESC, GET_MFO_N->OPER_DESC, sizeof(GET_MFO->OPER_DESC));
    GET_MFO->FLOW_SEQ = GET_MFO_N->FLOW_SEQ;
    GET_MFO->OPER_SEQ = GET_MFO_N->OPER_SEQ;
    GET_MFO->NEXT_SEQ = GET_MFO_N->NEXT_SEQ;
}

/* Initialize Function */
void DBC_init_fat_cond_list(struct FAT_COND_LIST_TAG *FAT_COND_LIST)
{
    /* memset by Space */
    memset(FAT_COND_LIST, ' ', sizeof(struct FAT_COND_LIST_TAG));
    FAT_COND_LIST->COUNT = 0;
}

/* Add Null Function */
void DBC_add_null_fat_cond_list(struct FAT_COND_LIST_N_TAG *FAT_COND_LIST_N, struct FAT_COND_LIST_TAG *FAT_COND_LIST)
{
    /* memset by NULL */
    memset(FAT_COND_LIST_N, '\0', sizeof(struct FAT_COND_LIST_N_TAG));
    MEMCPY_AN(FAT_COND_LIST_N->FACTORY, FAT_COND_LIST->FACTORY, sizeof(FAT_COND_LIST->FACTORY));
    MEMCPY_AN(FAT_COND_LIST_N->ATTR_NAME, FAT_COND_LIST->ATTR_NAME, sizeof(FAT_COND_LIST->ATTR_NAME));
    MEMCPY_AN(FAT_COND_LIST_N->LOT_ID, FAT_COND_LIST->LOT_ID, sizeof(FAT_COND_LIST->LOT_ID));
    //MEMCPY_AN(FAT_COND_LIST_N->OPERATOR, FAT_COND_LIST->OPERATOR, sizeof(FAT_COND_LIST->OPERATOR));
    FAT_COND_LIST_N->OPERATOR = FAT_COND_LIST->OPERATOR;
    MEMCPY_AN(FAT_COND_LIST_N->COLUMN_NAME, FAT_COND_LIST->COLUMN_NAME, sizeof(FAT_COND_LIST->COLUMN_NAME));
    MEMCPY_AN(FAT_COND_LIST_N->TABLE_NAME, FAT_COND_LIST->TABLE_NAME, sizeof(FAT_COND_LIST->TABLE_NAME));
    FAT_COND_LIST_N->COUNT = FAT_COND_LIST->COUNT;
}


/* Del Null Function */
void DBC_del_null_fat_cond_list(struct FAT_COND_LIST_N_TAG *FAT_COND_LIST_N, struct FAT_COND_LIST_TAG *FAT_COND_LIST)
{
    MEMCPY_DN(FAT_COND_LIST->FACTORY, FAT_COND_LIST_N->FACTORY, sizeof(FAT_COND_LIST->FACTORY));
    MEMCPY_DN(FAT_COND_LIST->ATTR_NAME, FAT_COND_LIST_N->ATTR_NAME, sizeof(FAT_COND_LIST->ATTR_NAME));
    MEMCPY_DN(FAT_COND_LIST->LOT_ID, FAT_COND_LIST_N->LOT_ID, sizeof(FAT_COND_LIST->LOT_ID));
    //MEMCPY_DN(FAT_COND_LIST->OPERATOR, FAT_COND_LIST_N->OPERATOR, sizeof(FAT_COND_LIST->OPERATOR));
    FAT_COND_LIST->OPERATOR = FAT_COND_LIST_N->OPERATOR;
    MEMCPY_DN(FAT_COND_LIST->COLUMN_NAME, FAT_COND_LIST_N->COLUMN_NAME, sizeof(FAT_COND_LIST->COLUMN_NAME));
    MEMCPY_DN(FAT_COND_LIST->TABLE_NAME, FAT_COND_LIST_N->TABLE_NAME, sizeof(FAT_COND_LIST->TABLE_NAME));
    FAT_COND_LIST->COUNT = FAT_COND_LIST_N->COUNT;
}

/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_fat_cond_list(int sel_type, struct FAT_COND_LIST_TAG *FAT_COND_LIST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct FAT_COND_LIST_N_TAG FAT_COND_LIST_N;
        char   sql[10000];
        char   ts[1000];
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();
    //FILE   *fp;

    DBC_add_null_fat_cond_list(&FAT_COND_LIST_N, FAT_COND_LIST);
    DB_error_code = 0;
    memset(ts, 0x00, sizeof(ts));
 
    switch(sel_type)
    {
        case 1:
            memset( sql, 0x00, sizeof(sql));

            sprintf(sql,"SELECT COUNT(*) FROM MATRNAMSTS ");

            make_valid_quote(ts, FAT_COND_LIST_N.FACTORY);            
            sprintf(sql + strlen(sql), "WHERE FACTORY = '%s' AND ATTR_TYPE = 'LOT' ", ts);

            make_valid_quote(ts, FAT_COND_LIST_N.ATTR_NAME);
            sprintf(sql + strlen(sql), " AND ATTR_NAME = '%s' ", ts);

            make_valid_quote(ts, FAT_COND_LIST_N.LOT_ID);
            sprintf(sql + strlen(sql), " AND ATTR_KEY = '%s' ", ts);

            //make_valid_quote(ts, FAT_COND_LIST_N.OPERATOR);
            sprintf(sql + strlen(sql), " AND ATTR_VALUE %c ", FAT_COND_LIST_N.OPERATOR);

            //that means using table value
            if(ISSPACE(FAT_COND_LIST->TABLE_NAME, sizeof(FAT_COND_LIST->TABLE_NAME)) == DB_FALSE)
            {
                make_valid_quote(ts, FAT_COND_LIST_N.COLUMN_NAME);
                sprintf(sql + strlen(sql), " (SELECT %s FROM ", ts);

                make_valid_quote(ts, FAT_COND_LIST_N.TABLE_NAME);
                sprintf(sql + strlen(sql), " %s ", ts);

                make_valid_quote(ts, FAT_COND_LIST_N.FACTORY);
                sprintf(sql + strlen(sql), " WHERE FACTORY = '%s' ", ts);

                make_valid_quote(ts, FAT_COND_LIST_N.LOT_ID);
                sprintf(sql + strlen(sql), " AND LOT_ID = '%s' )", ts);
            }
            else //fixed value
            {
                make_valid_quote(ts, FAT_COND_LIST_N.COLUMN_NAME);
                sprintf(sql + strlen(sql), "'%s'", ts);
            }


            //Check the sql                                                                                                                
            /*fp=fopen("sql.txt","w");
            fprintf(fp,"%s",sql);
            fclose(fp);*/
           

            /* EXEC SQL PREPARE S FROM :sql; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2948;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)sql;
            sqlstm.sqhstl[0] = (unsigned int  )10000;
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


            /* EXEC SQL DECLARE DBC_FAT_COND_LIST_CUR_1 CURSOR FOR S; */ 
 
            /* EXEC SQL OPEN DBC_FAT_COND_LIST_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2967;
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
                    
        case 2: //For GCM table
            memset( sql, 0x00, sizeof(sql));

            sprintf(sql,"SELECT COUNT(*) FROM MATRNAMSTS ");

            make_valid_quote(ts, FAT_COND_LIST_N.FACTORY);            
            sprintf(sql + strlen(sql), "WHERE FACTORY = '%s' AND ATTR_TYPE = 'LOT' ", ts);

            make_valid_quote(ts, FAT_COND_LIST_N.ATTR_NAME);
            sprintf(sql + strlen(sql), " AND ATTR_NAME = '%s' ", ts);

            make_valid_quote(ts, FAT_COND_LIST_N.LOT_ID);
            sprintf(sql + strlen(sql), " AND ATTR_KEY = '%s' ", ts);

            //make_valid_quote(ts, FAT_COND_LIST_N.OPERATOR);
            sprintf(sql + strlen(sql), " AND ATTR_VALUE %c ", FAT_COND_LIST_N.OPERATOR);

            //that means using table value
            if(ISSPACE(FAT_COND_LIST->TABLE_NAME, sizeof(FAT_COND_LIST->TABLE_NAME)) == DB_FALSE)
            {
                make_valid_quote(ts, FAT_COND_LIST_N.COLUMN_NAME);
                sprintf(sql + strlen(sql), " (SELECT %s FROM MGCMTBLDAT ", ts);

                make_valid_quote(ts, FAT_COND_LIST_N.FACTORY);
                sprintf(sql + strlen(sql), " WHERE FACTORY = '%s' ", ts);

                make_valid_quote(ts, FAT_COND_LIST_N.TABLE_NAME);
                sprintf(sql + strlen(sql), " AND TABLE_NAME = '%s' )", ts);
            }
            else //fixed value
            {
                make_valid_quote(ts, FAT_COND_LIST_N.COLUMN_NAME);
                sprintf(sql + strlen(sql), "'%s'", ts);
            }

            /* EXEC SQL PREPARE S FROM :sql; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )2982;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)sql;
            sqlstm.sqhstl[0] = (unsigned int  )10000;
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


            /* EXEC SQL DECLARE DBC_FAT_COND_LIST_CUR_2 CURSOR FOR S; */ 
 
            /* EXEC SQL OPEN DBC_FAT_COND_LIST_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3001;
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

        case 3: //For Lot status check by another Database table
            memset( sql, 0x00, sizeof(sql));

            sprintf(sql,"SELECT COUNT(*) FROM MWIPLOTSTS ");

            make_valid_quote(ts, FAT_COND_LIST_N.FACTORY);            
            sprintf(sql + strlen(sql), "WHERE FACTORY = '%s' ", ts);

            make_valid_quote(ts, FAT_COND_LIST_N.LOT_ID);
            sprintf(sql + strlen(sql), " AND LOT_ID = '%s' ", ts);

            //ATTR_NAME is the column name
            make_valid_quote(ts, FAT_COND_LIST_N.ATTR_NAME);
            sprintf(sql + strlen(sql), " AND %s ", ts);

            //make_valid_quote(ts, FAT_COND_LIST_N.OPERATOR);
            sprintf(sql + strlen(sql), " %c ", FAT_COND_LIST_N.OPERATOR);

            //that means using table value
            if(ISSPACE(FAT_COND_LIST->TABLE_NAME, sizeof(FAT_COND_LIST->TABLE_NAME)) == DB_FALSE)
            {
                make_valid_quote(ts, FAT_COND_LIST_N.COLUMN_NAME);
                sprintf(sql + strlen(sql), " (SELECT %s FROM ", ts);

                make_valid_quote(ts, FAT_COND_LIST_N.TABLE_NAME);
                sprintf(sql + strlen(sql), " %s ", ts);

                make_valid_quote(ts, FAT_COND_LIST_N.FACTORY);
                sprintf(sql + strlen(sql), " WHERE FACTORY = '%s' ", ts);

                make_valid_quote(ts, FAT_COND_LIST_N.LOT_ID);
                sprintf(sql + strlen(sql), " AND LOT_ID = '%s' AND FLOW=MWIPLOTSTS.FLOW AND OPER=MWIPLOTSTS.OPER)", ts);
            }
            else //fixed value
            {
                make_valid_quote(ts, FAT_COND_LIST_N.COLUMN_NAME);
                sprintf(sql + strlen(sql), "'%s'", ts);
            }


            //Check the sql                                                                                                                
            /*fp=fopen("sql.txt","w");
            fprintf(fp,"%s",sql);
            fclose(fp);*/

            /* EXEC SQL PREPARE S FROM :sql; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3016;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)sql;
            sqlstm.sqhstl[0] = (unsigned int  )10000;
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


            /* EXEC SQL DECLARE DBC_FAT_COND_LIST_CUR_3 CURSOR FOR S; */ 
 
            /* EXEC SQL OPEN DBC_FAT_COND_LIST_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3035;
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

        case 4: //For Lot status check by GCM table
            memset( sql, 0x00, sizeof(sql));

            sprintf(sql,"SELECT COUNT(*) FROM MWIPLOTSTS ");

            make_valid_quote(ts, FAT_COND_LIST_N.FACTORY);            
            sprintf(sql + strlen(sql), "WHERE FACTORY = '%s' ", ts);

            make_valid_quote(ts, FAT_COND_LIST_N.LOT_ID);
            sprintf(sql + strlen(sql), " AND LOT_ID = '%s' ", ts);

            //ATTR_NAME is the column name
            make_valid_quote(ts, FAT_COND_LIST_N.ATTR_NAME);
            sprintf(sql + strlen(sql), " AND %s ", ts);

            //make_valid_quote(ts, FAT_COND_LIST_N.OPERATOR);
            sprintf(sql + strlen(sql), " %c ", FAT_COND_LIST_N.OPERATOR);

            //that means using table value
            if(ISSPACE(FAT_COND_LIST->TABLE_NAME, sizeof(FAT_COND_LIST->TABLE_NAME)) == DB_FALSE)
            {
                make_valid_quote(ts, FAT_COND_LIST_N.COLUMN_NAME);
                sprintf(sql + strlen(sql), " (SELECT %s FROM MGCMTBLDAT ", ts);

                make_valid_quote(ts, FAT_COND_LIST_N.FACTORY);
                sprintf(sql + strlen(sql), " WHERE FACTORY = '%s' ", ts);

                make_valid_quote(ts, FAT_COND_LIST_N.TABLE_NAME);
                sprintf(sql + strlen(sql), " AND TABLE_NAME = '%s' )", ts);
            }
            else //fixed value
            {
                make_valid_quote(ts, FAT_COND_LIST_N.COLUMN_NAME);
                sprintf(sql + strlen(sql), "'%s'", ts);
            }

            //Check the sql                                                                                                                
            /*fp=fopen("loss_sql.txt","w");
            fprintf(fp,"%s",sql);
            fclose(fp);*/

            /* EXEC SQL PREPARE S FROM :sql; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3050;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (         void  *)sql;
            sqlstm.sqhstl[0] = (unsigned int  )10000;
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


            /* EXEC SQL DECLARE DBC_FAT_COND_LIST_CUR_4 CURSOR FOR S; */ 
 
            /* EXEC SQL OPEN DBC_FAT_COND_LIST_CUR_4; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3069;
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
    DB_stop_query_timer("DBC_open_fat_cond_list", sel_type);
}

/* SQL CURSOR FETCH Function */
void DBC_fetch_fat_cond_list(int sel_type, struct FAT_COND_LIST_TAG *FAT_COND_LIST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct FAT_COND_LIST_N_TAG FAT_COND_LIST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_FAT_COND_LIST_CUR_1 
                INTO :FAT_COND_LIST_N.COUNT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3084;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(FAT_COND_LIST_N.COUNT);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
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

        case 2:
            /* EXEC SQL FETCH DBC_FAT_COND_LIST_CUR_2 
                INTO :FAT_COND_LIST_N.COUNT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3103;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(FAT_COND_LIST_N.COUNT);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
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
        
        case 3:
            /* EXEC SQL FETCH DBC_FAT_COND_LIST_CUR_3 
                INTO :FAT_COND_LIST_N.COUNT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3122;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(FAT_COND_LIST_N.COUNT);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
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

        case 4:
            /* EXEC SQL FETCH DBC_FAT_COND_LIST_CUR_4 
                INTO :FAT_COND_LIST_N.COUNT; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3141;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(FAT_COND_LIST_N.COUNT);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
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


    if(DB_error_code == 0)
    {
        DBC_del_null_fat_cond_list(&FAT_COND_LIST_N, FAT_COND_LIST);
    }
    DB_stop_query_timer("DBC_fetch_fat_cond_list", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_fat_cond_list(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_FAT_COND_LIST_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
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
        case 2:
            /* EXEC SQL CLOSE DBC_FAT_COND_LIST_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3175;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
        case 3:
            /* EXEC SQL CLOSE DBC_FAT_COND_LIST_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3190;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
        case 4:
            /* EXEC SQL CLOSE DBC_FAT_COND_LIST_CUR_4; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3205;
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
    DB_stop_query_timer("DBC_close_fat_cond_list", sel_type);
}

/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_get_mfo_col_set_list(int sel_type, struct GET_MFO_COL_SET_LIST_TAG *GET_MFO_COL_SET_LIST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct GET_MFO_COL_SET_LIST_N_TAG GET_MFO_COL_SET_LIST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_get_mfo_col_set_list(&GET_MFO_COL_SET_LIST_N, GET_MFO_COL_SET_LIST);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBC_GET_MFO_COL_SET_LIST_CUR_1 CURSOR FOR 
                SELECT NVL(FOL.OPER_SEQ, 0) AS OPER_SEQ, 
                       NVL(FOL.OPER, ' ') AS OPER, 
                       NVL(FOL.OPER_DESC, ' ') AS OPER_DESC, 
                       NVL(CD.OPT_LEVEL, ' ') AS OPT_LEVEL, 
                       NVL(CD.COL_SET_ID, ' ') AS COL_SET_ID, 
                       NVL(CD.COLLECTION_MODE, ' ') AS COLLECTION_MODE, 
                       NVL(CD.DEFAULT_FLAG, ' ') AS DEFAULT_FLAG, 
                       NVL(CD.DISABLE_FLAG, ' ') AS DISABLE_FLAG, 
                       NVL(CD.CREATE_USER_ID, ' ') AS CREATE_USER_ID, 
                       NVL(CD.CREATE_TIME, ' ') AS CREATE_TIME, 
                       NVL(CD.UPDATE_USER_ID, ' ') AS UPDATE_USER_ID, 
                       NVL(CD.UPDATE_TIME, ' ') AS UPDATE_TIME 
                  FROM (SELECT FO.FACTORY, FO.FLOW, FO.SEQ_NUM AS OPER_SEQ, FO.OPER, OD.OPER_DESC 
                          FROM MWIPFLWOPR FO, MWIPOPRDEF OD 
                         WHERE FO.FACTORY = OD.FACTORY 
                           AND FO.OPER = OD.OPER 
                           AND FO.FACTORY= :GET_MFO_COL_SET_LIST_N.FACTORY
                           AND FO.FLOW = :GET_MFO_COL_SET_LIST_N.FLOW
                           AND FO.SEQ_NUM >= :GET_MFO_COL_SET_LIST_N.OPER_SEQ
                       ) FOL, 
                       (SELECT *
                          FROM MWIPCOLDEF 
                         WHERE FACTORY = :GET_MFO_COL_SET_LIST_N.FACTORY
                           AND MAT_ID = :GET_MFO_COL_SET_LIST_N.MAT_ID 
                           AND MAT_VER = :GET_MFO_COL_SET_LIST_N.MAT_VER 
                           AND FLOW = :GET_MFO_COL_SET_LIST_N.FLOW
                           AND OPT_LEVEL = '1'
                       ) CD 
                 WHERE ((FOL.OPER_SEQ > :GET_MFO_COL_SET_LIST_N.OPER_SEQ) 
                    OR (FOL.OPER_SEQ = :GET_MFO_COL_SET_LIST_N.OPER_SEQ AND CD.COL_SET_ID >= :GET_MFO_COL_SET_LIST_N.COL_SET_ID))
                   AND FOL.FACTORY = CD.FACTORY(+)
                   AND FOL.FLOW = CD.FLOW(+) 
                   AND FOL.OPER = CD.OPER(+) 
                 ORDER BY FOL.OPER_SEQ ASC, CD.COL_SET_ID ASC; */ 
 

            /* EXEC SQL OPEN DBC_GET_MFO_COL_SET_LIST_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0017;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3220;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(GET_MFO_COL_SET_LIST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_COL_SET_LIST_N.FLOW);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(GET_MFO_COL_SET_LIST_N.OPER_SEQ);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_MFO_COL_SET_LIST_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(GET_MFO_COL_SET_LIST_N.MAT_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(GET_MFO_COL_SET_LIST_N.MAT_VER);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(GET_MFO_COL_SET_LIST_N.FLOW);
            sqlstm.sqhstl[6] = (unsigned int  )21;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(GET_MFO_COL_SET_LIST_N.OPER_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(GET_MFO_COL_SET_LIST_N.OPER_SEQ);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(GET_MFO_COL_SET_LIST_N.COL_SET_ID);
            sqlstm.sqhstl[9] = (unsigned int  )26;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
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
            /* EXEC SQL DECLARE DBC_GET_MFO_COL_SET_LIST_CUR_2 CURSOR FOR 
                SELECT NVL(FO.SEQ_NUM, 0) AS OPER_SEQ, 
                       NVL(OD.OPER, ' ') AS OPER, 
                       NVL(OD.OPER_DESC, ' ') AS OPER_DESC, 
                       NVL(CD.OPT_LEVEL,' ') AS OPT_LEVEL, 
                       NVL(CD.COL_SET_ID, ' ') AS COL_SET_ID, 
                       NVL(CD.COLLECTION_MODE, ' ') AS COLLECTION_MODE, 
                       NVL(CD.DEFAULT_FLAG, ' ') AS DEFAULT_FLAG, 
                       NVL(CD.DISABLE_FLAG, ' ') AS DISABLE_FLAG, 
                       NVL(CD.CREATE_USER_ID, ' ') AS CREATE_USER_ID, 
                       NVL(CD.CREATE_TIME, ' ') AS CREATE_TIME, 
                       NVL(CD.UPDATE_USER_ID, ' ') AS UPDATE_USER_ID, 
                       NVL(CD.UPDATE_TIME, ' ') AS UPDATE_TIME 
                  FROM MWIPOPRDEF OD, 
                       MWIPFLWOPR FO, 
                       (SELECT *
                          FROM MWIPCOLDEF 
                         WHERE FACTORY = :GET_MFO_COL_SET_LIST_N.FACTORY 
                           AND FLOW = :GET_MFO_COL_SET_LIST_N.FLOW
                           AND OPT_LEVEL = '2'
                       ) CD 
                 WHERE FO.FACTORY = OD.FACTORY
                   AND FO.OPER = OD.OPER
                   AND FO.FACTORY = :GET_MFO_COL_SET_LIST_N.FACTORY 
                   AND FO.FLOW = :GET_MFO_COL_SET_LIST_N.FLOW  
                   AND ((FO.SEQ_NUM > :GET_MFO_COL_SET_LIST_N.OPER_SEQ) 
                    OR (FO.SEQ_NUM = :GET_MFO_COL_SET_LIST_N.OPER_SEQ AND CD.COL_SET_ID >= :GET_MFO_COL_SET_LIST_N.COL_SET_ID))
                   AND FO.FACTORY = CD.FACTORY(+) 
                   AND FO.FLOW = CD.FLOW(+)
                   AND FO.OPER = CD.OPER(+) 
                 ORDER BY FO.SEQ_NUM ASC, CD.COL_SET_ID ASC; */ 
 

            /* EXEC SQL OPEN DBC_GET_MFO_COL_SET_LIST_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0018;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3275;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(GET_MFO_COL_SET_LIST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_COL_SET_LIST_N.FLOW);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_MFO_COL_SET_LIST_N.FACTORY);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_MFO_COL_SET_LIST_N.FLOW);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(GET_MFO_COL_SET_LIST_N.OPER_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(GET_MFO_COL_SET_LIST_N.OPER_SEQ);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(GET_MFO_COL_SET_LIST_N.COL_SET_ID);
            sqlstm.sqhstl[6] = (unsigned int  )26;
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
            
        case 3:
            /* EXEC SQL DECLARE DBC_GET_MFO_COL_SET_LIST_CUR_3 CURSOR FOR 
                SELECT 0 AS OPER_SEQ,
                       NVL(OD.OPER, ' ') AS OPER, 
                       NVL(OD.OPER_DESC, ' ') AS OPER_DESC, 
                       NVL(CD.OPT_LEVEL,' ') AS OPT_LEVEL, 
                       NVL(CD.COL_SET_ID, ' ') AS COL_SET_ID, 
                       NVL(CD.COLLECTION_MODE, ' ') AS COLLECTION_MODE, 
                       NVL(CD.DEFAULT_FLAG, ' ') AS DEFAULT_FLAG, 
                       NVL(CD.DISABLE_FLAG, ' ') AS DISABLE_FLAG, 
                       NVL(CD.CREATE_USER_ID, ' ') AS CREATE_USER_ID, 
                       NVL(CD.CREATE_TIME, ' ') AS CREATE_TIME, 
                       NVL(CD.UPDATE_USER_ID, ' ') AS UPDATE_USER_ID, 
                       NVL(CD.UPDATE_TIME, ' ') AS UPDATE_TIME
                  FROM MWIPOPRDEF OD, 
                       (SELECT *
                          FROM MWIPCOLDEF 
                         WHERE FACTORY = :GET_MFO_COL_SET_LIST_N.FACTORY 
                           AND OPT_LEVEL = '3'
                       ) CD
                 WHERE OD.FACTORY = :GET_MFO_COL_SET_LIST_N.FACTORY 
                   AND ((OD.OPER > :GET_MFO_COL_SET_LIST_N.OPER) 
                    OR (OD.OPER = :GET_MFO_COL_SET_LIST_N.OPER AND CD.COL_SET_ID >= :GET_MFO_COL_SET_LIST_N.COL_SET_ID))
                   AND OD.FACTORY = CD.FACTORY(+) 
                   AND OD.OPER = CD.OPER(+) 
                 ORDER BY OD.OPER ASC, CD.COL_SET_ID ASC; */ 
 

            /* EXEC SQL OPEN DBC_GET_MFO_COL_SET_LIST_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0019;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3318;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(GET_MFO_COL_SET_LIST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_COL_SET_LIST_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_MFO_COL_SET_LIST_N.OPER);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_MFO_COL_SET_LIST_N.OPER);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(GET_MFO_COL_SET_LIST_N.COL_SET_ID);
            sqlstm.sqhstl[4] = (unsigned int  )26;
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
            /* EXEC SQL DECLARE DBC_GET_MFO_COL_SET_LIST_CUR_4 CURSOR FOR 
                SELECT 0 AS OPER_SEQ,
                       NVL(OD.OPER, ' ') AS OPER, 
                       NVL(OD.OPER_DESC, ' ') AS OPER_DESC, 
                       NVL(CD.OPT_LEVEL,' ') AS OPT_LEVEL, 
                       NVL(CD.COL_SET_ID, ' ') AS COL_SET_ID, 
                       NVL(CD.COLLECTION_MODE, ' ') AS COLLECTION_MODE, 
                       NVL(CD.DEFAULT_FLAG, ' ') AS DEFAULT_FLAG, 
                       NVL(CD.DISABLE_FLAG, ' ') AS DISABLE_FLAG, 
                       NVL(CD.CREATE_USER_ID, ' ') AS CREATE_USER_ID, 
                       NVL(CD.CREATE_TIME, ' ') AS CREATE_TIME, 
                       NVL(CD.UPDATE_USER_ID, ' ') AS UPDATE_USER_ID, 
                       NVL(CD.UPDATE_TIME, ' ') AS UPDATE_TIME
                  FROM MWIPOPRDEF OD, 
                       (SELECT *
                          FROM MWIPCOLDEF 
                         WHERE FACTORY = :GET_MFO_COL_SET_LIST_N.FACTORY 
                           AND MAT_ID = :GET_MFO_COL_SET_LIST_N.MAT_ID 
                           AND MAT_VER = :GET_MFO_COL_SET_LIST_N.MAT_VER 
                           AND OPT_LEVEL = '4'
                       ) CD
                 WHERE OD.FACTORY = :GET_MFO_COL_SET_LIST_N.FACTORY 
                   AND ((OD.OPER > :GET_MFO_COL_SET_LIST_N.OPER) 
                    OR (OD.OPER = :GET_MFO_COL_SET_LIST_N.OPER AND CD.COL_SET_ID >= :GET_MFO_COL_SET_LIST_N.COL_SET_ID))
                   AND OD.FACTORY = CD.FACTORY(+) 
                   AND OD.OPER = CD.OPER(+) 
                 ORDER BY OD.OPER ASC, CD.COL_SET_ID ASC; */ 
 

            /* EXEC SQL OPEN DBC_GET_MFO_COL_SET_LIST_CUR_4; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0020;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3353;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(GET_MFO_COL_SET_LIST_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_COL_SET_LIST_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(GET_MFO_COL_SET_LIST_N.MAT_VER);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_MFO_COL_SET_LIST_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(GET_MFO_COL_SET_LIST_N.OPER);
            sqlstm.sqhstl[4] = (unsigned int  )11;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(GET_MFO_COL_SET_LIST_N.OPER);
            sqlstm.sqhstl[5] = (unsigned int  )11;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(GET_MFO_COL_SET_LIST_N.COL_SET_ID);
            sqlstm.sqhstl[6] = (unsigned int  )26;
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
    DB_stop_query_timer("DBC_open_get_mfo_col_set_list", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_get_mfo_col_set_list(int sel_type, struct GET_MFO_COL_SET_LIST_TAG *GET_MFO_COL_SET_LIST)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct GET_MFO_COL_SET_LIST_N_TAG GET_MFO_COL_SET_LIST_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_GET_MFO_COL_SET_LIST_CUR_1 INTO 
                :GET_MFO_COL_SET_LIST_N.OPER_SEQ,
                :GET_MFO_COL_SET_LIST_N.OPER,
                :GET_MFO_COL_SET_LIST_N.OPER_DESC,
                :GET_MFO_COL_SET_LIST_N.OPT_LEVEL,
                :GET_MFO_COL_SET_LIST_N.COL_SET_ID, 
                :GET_MFO_COL_SET_LIST_N.COLLECTION_MODE, 
                :GET_MFO_COL_SET_LIST_N.DEFAULT_FLAG, 
                :GET_MFO_COL_SET_LIST_N.DISABLE_FLAG, 
                :GET_MFO_COL_SET_LIST_N.CREATE_USER_ID,
                :GET_MFO_COL_SET_LIST_N.CREATE_TIME,
                :GET_MFO_COL_SET_LIST_N.UPDATE_USER_ID,
                :GET_MFO_COL_SET_LIST_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3396;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(GET_MFO_COL_SET_LIST_N.OPER_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_COL_SET_LIST_N.OPER);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_MFO_COL_SET_LIST_N.OPER_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_MFO_COL_SET_LIST_N.OPT_LEVEL);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(GET_MFO_COL_SET_LIST_N.COL_SET_ID);
            sqlstm.sqhstl[4] = (unsigned int  )26;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(GET_MFO_COL_SET_LIST_N.COLLECTION_MODE);
            sqlstm.sqhstl[5] = (unsigned int  )2;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(GET_MFO_COL_SET_LIST_N.DEFAULT_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(GET_MFO_COL_SET_LIST_N.DISABLE_FLAG);
            sqlstm.sqhstl[7] = (unsigned int  )2;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(GET_MFO_COL_SET_LIST_N.CREATE_USER_ID);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(GET_MFO_COL_SET_LIST_N.CREATE_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )15;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(GET_MFO_COL_SET_LIST_N.UPDATE_USER_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(GET_MFO_COL_SET_LIST_N.UPDATE_TIME);
            sqlstm.sqhstl[11] = (unsigned int  )15;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBC_GET_MFO_COL_SET_LIST_CUR_2 INTO 
                :GET_MFO_COL_SET_LIST_N.OPER_SEQ,
                :GET_MFO_COL_SET_LIST_N.OPER, 
                :GET_MFO_COL_SET_LIST_N.OPER_DESC, 
                :GET_MFO_COL_SET_LIST_N.OPT_LEVEL, 
                :GET_MFO_COL_SET_LIST_N.COL_SET_ID, 
                :GET_MFO_COL_SET_LIST_N.COLLECTION_MODE, 
                :GET_MFO_COL_SET_LIST_N.DEFAULT_FLAG, 
                :GET_MFO_COL_SET_LIST_N.DISABLE_FLAG, 
                :GET_MFO_COL_SET_LIST_N.CREATE_USER_ID,
                :GET_MFO_COL_SET_LIST_N.CREATE_TIME,
                :GET_MFO_COL_SET_LIST_N.UPDATE_USER_ID, 
                :GET_MFO_COL_SET_LIST_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3459;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(GET_MFO_COL_SET_LIST_N.OPER_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_COL_SET_LIST_N.OPER);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_MFO_COL_SET_LIST_N.OPER_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_MFO_COL_SET_LIST_N.OPT_LEVEL);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(GET_MFO_COL_SET_LIST_N.COL_SET_ID);
            sqlstm.sqhstl[4] = (unsigned int  )26;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(GET_MFO_COL_SET_LIST_N.COLLECTION_MODE);
            sqlstm.sqhstl[5] = (unsigned int  )2;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(GET_MFO_COL_SET_LIST_N.DEFAULT_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(GET_MFO_COL_SET_LIST_N.DISABLE_FLAG);
            sqlstm.sqhstl[7] = (unsigned int  )2;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(GET_MFO_COL_SET_LIST_N.CREATE_USER_ID);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(GET_MFO_COL_SET_LIST_N.CREATE_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )15;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(GET_MFO_COL_SET_LIST_N.UPDATE_USER_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(GET_MFO_COL_SET_LIST_N.UPDATE_TIME);
            sqlstm.sqhstl[11] = (unsigned int  )15;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBC_GET_MFO_COL_SET_LIST_CUR_3 INTO 
                :GET_MFO_COL_SET_LIST_N.OPER_SEQ,
                :GET_MFO_COL_SET_LIST_N.OPER, 
                :GET_MFO_COL_SET_LIST_N.OPER_DESC, 
                :GET_MFO_COL_SET_LIST_N.OPT_LEVEL, 
                :GET_MFO_COL_SET_LIST_N.COL_SET_ID, 
                :GET_MFO_COL_SET_LIST_N.COLLECTION_MODE, 
                :GET_MFO_COL_SET_LIST_N.DEFAULT_FLAG, 
                :GET_MFO_COL_SET_LIST_N.DISABLE_FLAG, 
                :GET_MFO_COL_SET_LIST_N.CREATE_USER_ID, 
                :GET_MFO_COL_SET_LIST_N.CREATE_TIME, 
                :GET_MFO_COL_SET_LIST_N.UPDATE_USER_ID, 
                :GET_MFO_COL_SET_LIST_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3522;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(GET_MFO_COL_SET_LIST_N.OPER_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_COL_SET_LIST_N.OPER);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_MFO_COL_SET_LIST_N.OPER_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_MFO_COL_SET_LIST_N.OPT_LEVEL);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(GET_MFO_COL_SET_LIST_N.COL_SET_ID);
            sqlstm.sqhstl[4] = (unsigned int  )26;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(GET_MFO_COL_SET_LIST_N.COLLECTION_MODE);
            sqlstm.sqhstl[5] = (unsigned int  )2;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(GET_MFO_COL_SET_LIST_N.DEFAULT_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(GET_MFO_COL_SET_LIST_N.DISABLE_FLAG);
            sqlstm.sqhstl[7] = (unsigned int  )2;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(GET_MFO_COL_SET_LIST_N.CREATE_USER_ID);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(GET_MFO_COL_SET_LIST_N.CREATE_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )15;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(GET_MFO_COL_SET_LIST_N.UPDATE_USER_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(GET_MFO_COL_SET_LIST_N.UPDATE_TIME);
            sqlstm.sqhstl[11] = (unsigned int  )15;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBC_GET_MFO_COL_SET_LIST_CUR_4 INTO 
                :GET_MFO_COL_SET_LIST_N.OPER_SEQ,
                :GET_MFO_COL_SET_LIST_N.OPER,
                :GET_MFO_COL_SET_LIST_N.OPER_DESC,
                :GET_MFO_COL_SET_LIST_N.OPT_LEVEL,
                :GET_MFO_COL_SET_LIST_N.COL_SET_ID, 
                :GET_MFO_COL_SET_LIST_N.COLLECTION_MODE, 
                :GET_MFO_COL_SET_LIST_N.DEFAULT_FLAG, 
                :GET_MFO_COL_SET_LIST_N.DISABLE_FLAG, 
                :GET_MFO_COL_SET_LIST_N.CREATE_USER_ID,
                :GET_MFO_COL_SET_LIST_N.CREATE_TIME,
                :GET_MFO_COL_SET_LIST_N.UPDATE_USER_ID,
                :GET_MFO_COL_SET_LIST_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3585;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)&(GET_MFO_COL_SET_LIST_N.OPER_SEQ);
            sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_MFO_COL_SET_LIST_N.OPER);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_MFO_COL_SET_LIST_N.OPER_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_MFO_COL_SET_LIST_N.OPT_LEVEL);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(GET_MFO_COL_SET_LIST_N.COL_SET_ID);
            sqlstm.sqhstl[4] = (unsigned int  )26;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(GET_MFO_COL_SET_LIST_N.COLLECTION_MODE);
            sqlstm.sqhstl[5] = (unsigned int  )2;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(GET_MFO_COL_SET_LIST_N.DEFAULT_FLAG);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)(GET_MFO_COL_SET_LIST_N.DISABLE_FLAG);
            sqlstm.sqhstl[7] = (unsigned int  )2;
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)(GET_MFO_COL_SET_LIST_N.CREATE_USER_ID);
            sqlstm.sqhstl[8] = (unsigned int  )21;
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)(GET_MFO_COL_SET_LIST_N.CREATE_TIME);
            sqlstm.sqhstl[9] = (unsigned int  )15;
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)(GET_MFO_COL_SET_LIST_N.UPDATE_USER_ID);
            sqlstm.sqhstl[10] = (unsigned int  )21;
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(GET_MFO_COL_SET_LIST_N.UPDATE_TIME);
            sqlstm.sqhstl[11] = (unsigned int  )15;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
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
        DBC_del_null_get_mfo_col_set_list(&GET_MFO_COL_SET_LIST_N, GET_MFO_COL_SET_LIST);
    }
    DB_stop_query_timer("DBC_fetch_get_mfo_col_set_list", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_get_mfo_col_set_list(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_GET_MFO_COL_SET_LIST_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3648;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
            
        case 2:
            /* EXEC SQL CLOSE DBC_GET_MFO_COL_SET_LIST_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3663;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
            
        case 3:
            /* EXEC SQL CLOSE DBC_GET_MFO_COL_SET_LIST_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3678;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 4:
            /* EXEC SQL CLOSE DBC_GET_MFO_COL_SET_LIST_CUR_4; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3693;
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
    DB_stop_query_timer("DBC_close_get_mfo_col_set_list", sel_type);
}

/* Initialize Function */
void DBC_init_get_mfo_col_set_list(struct GET_MFO_COL_SET_LIST_TAG *GET_MFO_COL_SET_LIST)
{
    /* memset by Space */
    memset(GET_MFO_COL_SET_LIST, ' ', sizeof(struct GET_MFO_COL_SET_LIST_TAG));

    GET_MFO_COL_SET_LIST->MAT_VER = 0;
    GET_MFO_COL_SET_LIST->OPER_SEQ = 0;
}


/* Add Null Function */
void DBC_add_null_get_mfo_col_set_list(struct GET_MFO_COL_SET_LIST_N_TAG *GET_MFO_COL_SET_LIST_N, struct GET_MFO_COL_SET_LIST_TAG *GET_MFO_COL_SET_LIST)
{ 
    /* memset by NULL */
    memset(GET_MFO_COL_SET_LIST_N, '\0', sizeof(struct GET_MFO_COL_SET_LIST_N_TAG));

    MEMCPY_AN(GET_MFO_COL_SET_LIST_N->FACTORY ,GET_MFO_COL_SET_LIST->FACTORY ,sizeof(GET_MFO_COL_SET_LIST->FACTORY ));
    MEMCPY_AN(GET_MFO_COL_SET_LIST_N->MAT_ID , GET_MFO_COL_SET_LIST->MAT_ID , sizeof(GET_MFO_COL_SET_LIST->MAT_ID ));
    GET_MFO_COL_SET_LIST_N->MAT_VER = GET_MFO_COL_SET_LIST->MAT_VER;
    MEMCPY_AN(GET_MFO_COL_SET_LIST_N->FLOW ,GET_MFO_COL_SET_LIST->FLOW ,sizeof(GET_MFO_COL_SET_LIST->FLOW ));
    MEMCPY_AN(GET_MFO_COL_SET_LIST_N->OPER , GET_MFO_COL_SET_LIST->OPER , sizeof(GET_MFO_COL_SET_LIST->OPER ));
    MEMCPY_AN(GET_MFO_COL_SET_LIST_N->OPER_DESC , GET_MFO_COL_SET_LIST->OPER_DESC, sizeof(GET_MFO_COL_SET_LIST->OPER_DESC));
    GET_MFO_COL_SET_LIST_N->OPER_SEQ = GET_MFO_COL_SET_LIST->OPER_SEQ;
    GET_MFO_COL_SET_LIST_N->OPT_LEVEL[0]= GET_MFO_COL_SET_LIST->OPT_LEVEL;
    MEMCPY_AN(GET_MFO_COL_SET_LIST_N->COL_SET_ID , GET_MFO_COL_SET_LIST->COL_SET_ID, sizeof(GET_MFO_COL_SET_LIST->COL_SET_ID));
    GET_MFO_COL_SET_LIST_N->COLLECTION_MODE[0]= GET_MFO_COL_SET_LIST->COLLECTION_MODE;
    GET_MFO_COL_SET_LIST_N->DEFAULT_FLAG[0]= GET_MFO_COL_SET_LIST->DEFAULT_FLAG;
    GET_MFO_COL_SET_LIST_N->DISABLE_FLAG[0]= GET_MFO_COL_SET_LIST->DISABLE_FLAG;
    MEMCPY_AN(GET_MFO_COL_SET_LIST_N->CREATE_TIME ,GET_MFO_COL_SET_LIST->CREATE_TIME , sizeof(GET_MFO_COL_SET_LIST->CREATE_TIME ));
    MEMCPY_AN(GET_MFO_COL_SET_LIST_N->CREATE_USER_ID ,GET_MFO_COL_SET_LIST->CREATE_USER_ID , sizeof(GET_MFO_COL_SET_LIST->CREATE_USER_ID ));
    MEMCPY_AN(GET_MFO_COL_SET_LIST_N->UPDATE_TIME ,GET_MFO_COL_SET_LIST->UPDATE_TIME , sizeof(GET_MFO_COL_SET_LIST->UPDATE_TIME ));
    MEMCPY_AN(GET_MFO_COL_SET_LIST_N->UPDATE_USER_ID ,GET_MFO_COL_SET_LIST->UPDATE_USER_ID , sizeof(GET_MFO_COL_SET_LIST->UPDATE_USER_ID ));
}


/* Del Null Function */
void DBC_del_null_get_mfo_col_set_list(struct GET_MFO_COL_SET_LIST_N_TAG *GET_MFO_COL_SET_LIST_N, struct GET_MFO_COL_SET_LIST_TAG *GET_MFO_COL_SET_LIST)
{
    MEMCPY_DN(GET_MFO_COL_SET_LIST->FACTORY ,GET_MFO_COL_SET_LIST_N->FACTORY ,sizeof(GET_MFO_COL_SET_LIST->FACTORY ));
    MEMCPY_DN(GET_MFO_COL_SET_LIST->MAT_ID , GET_MFO_COL_SET_LIST_N->MAT_ID , sizeof(GET_MFO_COL_SET_LIST->MAT_ID ));
    GET_MFO_COL_SET_LIST->MAT_VER = GET_MFO_COL_SET_LIST_N->MAT_VER;
    MEMCPY_DN(GET_MFO_COL_SET_LIST->FLOW ,GET_MFO_COL_SET_LIST_N->FLOW ,sizeof(GET_MFO_COL_SET_LIST->FLOW ));
    MEMCPY_DN(GET_MFO_COL_SET_LIST->OPER , GET_MFO_COL_SET_LIST_N->OPER , sizeof(GET_MFO_COL_SET_LIST->OPER ));
    MEMCPY_DN(GET_MFO_COL_SET_LIST->OPER_DESC , GET_MFO_COL_SET_LIST_N->OPER_DESC, sizeof(GET_MFO_COL_SET_LIST->OPER_DESC));
    GET_MFO_COL_SET_LIST->OPER_SEQ = GET_MFO_COL_SET_LIST_N->OPER_SEQ;
    MEMCPY_DN(GET_MFO_COL_SET_LIST->COL_SET_ID , GET_MFO_COL_SET_LIST_N->COL_SET_ID, sizeof(GET_MFO_COL_SET_LIST->COL_SET_ID));
    GET_MFO_COL_SET_LIST->COLLECTION_MODE = GET_MFO_COL_SET_LIST_N->COLLECTION_MODE[0];
    GET_MFO_COL_SET_LIST->DEFAULT_FLAG = GET_MFO_COL_SET_LIST_N->DEFAULT_FLAG[0];
    GET_MFO_COL_SET_LIST->DISABLE_FLAG = GET_MFO_COL_SET_LIST_N->DISABLE_FLAG[0];
    MEMCPY_DN(GET_MFO_COL_SET_LIST->CREATE_TIME ,GET_MFO_COL_SET_LIST_N->CREATE_TIME , sizeof(GET_MFO_COL_SET_LIST->CREATE_TIME ));
    MEMCPY_DN(GET_MFO_COL_SET_LIST->CREATE_USER_ID ,GET_MFO_COL_SET_LIST_N->CREATE_USER_ID , sizeof(GET_MFO_COL_SET_LIST->CREATE_USER_ID ));
    MEMCPY_DN(GET_MFO_COL_SET_LIST->UPDATE_TIME ,GET_MFO_COL_SET_LIST_N->UPDATE_TIME , sizeof(GET_MFO_COL_SET_LIST->UPDATE_TIME ));
    MEMCPY_DN(GET_MFO_COL_SET_LIST->UPDATE_USER_ID ,GET_MFO_COL_SET_LIST_N->UPDATE_USER_ID , sizeof(GET_MFO_COL_SET_LIST->UPDATE_USER_ID ));
} 

/* SQL CURSOR DECLARE & OPEN Function */
void DBC_open_get_yield(int sel_type, struct GET_YIELD_TAG *GET_YIELD)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct GET_YIELD_N_TAG GET_YIELD_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DBC_add_null_get_yield(&GET_YIELD_N, GET_YIELD);
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL DECLARE DBC_GET_YIELD_CUR_1 CURSOR FOR 
                SELECT NVL(FOL.FLOW, ' ') AS FLOW, 
                    NVL(FOL.FLOW_SEQ, 0) AS FLOW_SEQ,
                    NVL(FOL.FLOW_DESC, ' ') AS FLOW_DESC, 
                    NVL(FOL.OPER, ' ') AS OPER, 
                    NVL(FOL.OPER_SEQ, 0) AS OPER_SEQ, 
                    NVL(FOL.OPER_DESC, ' ') AS OPER_DESC, 
                    NVL(CD.OPT_LEVEL, ' ') AS OPT_LEVEL, 
                    NVL(CD.STD_YIELD, 0) AS STD_YIELD, 
                    NVL(CD.PLN_YIELD, 0) AS PLN_YIELD, 
                    NVL(CD.UNIT_CHG_YIELD, 0) AS UNIT_CHG_YIELD, 
                    NVL(CD.CUSTOM_YIELD_1, 0) AS CUSTOM_YIELD_1, 
                    NVL(CD.CUSTOM_YIELD_2, 0) AS CUSTOM_YIELD_2, 
                    NVL(CD.CUSTOM_YIELD_3, 0) AS CUSTOM_YIELD_3, 
                    NVL(CD.CUSTOM_YIELD_4, 0) AS CUSTOM_YIELD_4, 
                    NVL(CD.CUSTOM_YIELD_5, 0) AS CUSTOM_YIELD_5, 
                    NVL(CD.CREATE_USER_ID, ' ') AS CREATE_USER_ID, 
                    NVL(CD.CREATE_TIME, ' ') AS CREATE_TIME, 
                    NVL(CD.UPDATE_USER_ID, ' ') AS UPDATE_USER_ID, 
                    NVL(CD.UPDATE_TIME, ' ') AS UPDATE_TIME 
                FROM ( 
                    SELECT MF.FACTORY,
                           MF.FLOW, MF.FLOW_SEQ_NUM AS FLOW_SEQ, FD.FLOW_DESC, 
                           FO.OPER, FO.SEQ_NUM AS OPER_SEQ, OD.OPER_DESC 
                    FROM MWIPMATFLW MF, MWIPFLWOPR FO, MWIPFLWDEF FD, MWIPOPRDEF OD 
                    WHERE MF.FACTORY = :GET_YIELD_N.FACTORY
                        AND MF.MAT_ID = :GET_YIELD_N.MAT_ID
                        AND MF.MAT_VER = :GET_YIELD_N.MAT_VER
                        AND FO.FACTORY = MF.FACTORY
                        AND FO.FLOW = MF.FLOW
                        AND FD.FACTORY = FO.FACTORY 
                        AND FD.FLOW = FO.FLOW
                        AND OD.FACTORY = FO.FACTORY
                        AND OD.OPER = FO.OPER
                    ) FOL, (
                    SELECT *
                    FROM MWIPYLDDEF 
                    WHERE FACTORY = :GET_YIELD_N.FACTORY
                        AND MAT_ID = :GET_YIELD_N.MAT_ID 
                        AND MAT_VER = :GET_YIELD_N.MAT_VER 
                        AND OPT_LEVEL = '1'
                    ) CD 
                WHERE FOL.FACTORY = CD.FACTORY(+)
                    AND FOL.FLOW = CD.FLOW(+) 
                    AND FOL.FLOW_SEQ = CD.FLOW_SEQ_NUM(+) 
                    AND FOL.OPER = CD.OPER(+) 
                    AND ((FOL.FLOW_SEQ = :GET_YIELD_N.FLOW_SEQ_NUM AND FOL.OPER_SEQ >= :GET_YIELD_N.OPER_SEQ) 
                         OR FOL.FLOW_SEQ > :GET_YIELD_N.FLOW_SEQ_NUM)
                ORDER BY FOL.FLOW_SEQ ASC, FOL.OPER_SEQ ASC; */ 
 

            /* EXEC SQL OPEN DBC_GET_YIELD_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlbuft((void **)0,
              "select NVL(FOL.FLOW,' ') FLOW ,NVL(FOL.FLOW_SEQ,0) FLOW_SEQ ,\
NVL(FOL.FLOW_DESC,' ') FLOW_DESC ,NVL(FOL.OPER,' ') OPER ,NVL(FOL.OPER_SEQ,0\
) OPER_SEQ ,NVL(FOL.OPER_DESC,' ') OPER_DESC ,NVL(CD.OPT_LEVEL,' ') OPT_LEVE\
L ,NVL(CD.STD_YIELD,0) STD_YIELD ,NVL(CD.PLN_YIELD,0) PLN_YIELD ,NVL(CD.UNIT\
_CHG_YIELD,0) UNIT_CHG_YIELD ,NVL(CD.CUSTOM_YIELD_1,0) CUSTOM_YIELD_1 ,NVL(C\
D.CUSTOM_YIELD_2,0) CUSTOM_YIELD_2 ,NVL(CD.CUSTOM_YIELD_3,0) CUSTOM_YIELD_3 \
,NVL(CD.CUSTOM_YIELD_4,0) CUSTOM_YIELD_4 ,NVL(CD.CUSTOM_YIELD_5,0) CUSTOM_YI\
ELD_5 ,NVL(CD.CREATE_USER_ID,' ') CREATE_USER_ID ,NVL(CD.CREATE_TIME,' ') CR\
EATE_TIME ,NVL(CD.UPDATE_USER_ID,' ') UPDATE_USER_ID ,NVL(CD.UPDATE_TIME,' '\
) UPDATE_TIME  from (select MF.FACTORY ,MF.FLOW ,MF.FLOW_SEQ_NUM FLOW_SEQ ,F\
D.FLOW_DESC ,FO.OPER ,FO.SEQ_NUM OPER_SEQ ,OD.OPER_DESC  from MWIPMATFLW MF \
,MWIPFLWOPR FO ,MWIPFLWDEF FD ,MWIPOPRDEF OD where ((((((((MF.FACTORY=:b0 an\
d MF.MAT_ID=:b1) and MF.MAT_VER=:b2) and FO.FACTORY=MF.FACTORY) and FO.FLOW=\
MF.FLOW) and FD.FACTORY=FO.FACTORY) and FD.FLOW=FO.");
            sqlstm.stmt = sq0021;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3708;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(GET_YIELD_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_YIELD_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(GET_YIELD_N.MAT_VER);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_YIELD_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(GET_YIELD_N.MAT_ID);
            sqlstm.sqhstl[4] = (unsigned int  )31;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(GET_YIELD_N.MAT_VER);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(GET_YIELD_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(GET_YIELD_N.OPER_SEQ);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(GET_YIELD_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
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
            /* EXEC SQL DECLARE DBC_GET_YIELD_CUR_2 CURSOR FOR 
                SELECT NVL(FO.OPER, ' ') AS OPER, 
                    NVL(FO.SEQ_NUM, 0) AS OPER_SEQ, 
                    NVL(OD.OPER_DESC, ' ') AS OPER_DESC, 
                    NVL(CD.OPT_LEVEL,' ') AS OPT_LEVEL, 
                    NVL(CD.STD_YIELD, 0) AS STD_YIELD, 
                    NVL(CD.PLN_YIELD, 0) AS PLN_YIELD, 
                    NVL(CD.UNIT_CHG_YIELD, 0) AS UNIT_CHG_YIELD, 
                    NVL(CD.CUSTOM_YIELD_1, 0) AS CUSTOM_YIELD_1, 
                    NVL(CD.CUSTOM_YIELD_2, 0) AS CUSTOM_YIELD_2, 
                    NVL(CD.CUSTOM_YIELD_3, 0) AS CUSTOM_YIELD_3, 
                    NVL(CD.CUSTOM_YIELD_4, 0) AS CUSTOM_YIELD_4, 
                    NVL(CD.CUSTOM_YIELD_5, 0) AS CUSTOM_YIELD_5, 
                    NVL(CD.CREATE_USER_ID, ' ') AS CREATE_USER_ID, 
                    NVL(CD.CREATE_TIME, ' ') AS CREATE_TIME, 
                    NVL(CD.UPDATE_USER_ID, ' ') AS UPDATE_USER_ID, 
                    NVL(CD.UPDATE_TIME, ' ') AS UPDATE_TIME 
                FROM MWIPOPRDEF OD, MWIPFLWOPR  FO, (
                    SELECT *
                    FROM MWIPYLDDEF 
                    WHERE FACTORY = :GET_YIELD_N.FACTORY 
                        AND FLOW = :GET_YIELD_N.FLOW  
                        AND OPT_LEVEL = '2'
                    ) CD 
                WHERE FO.FACTORY = :GET_YIELD_N.FACTORY 
                    AND FO.FLOW = :GET_YIELD_N.FLOW  
                    AND FO.SEQ_NUM >= :GET_YIELD_N.OPER_SEQ 
                    AND FO.FACTORY = OD.FACTORY
                    AND FO.OPER = OD.OPER
                    AND FO.FACTORY = CD.FACTORY(+) 
                    AND FO.FLOW = CD.FLOW(+)
                    AND FO.OPER = CD.OPER(+) 
                ORDER BY FO.SEQ_NUM ASC; */ 
 

            /* EXEC SQL OPEN DBC_GET_YIELD_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0022;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3759;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(GET_YIELD_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_YIELD_N.FLOW);
            sqlstm.sqhstl[1] = (unsigned int  )21;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_YIELD_N.FACTORY);
            sqlstm.sqhstl[2] = (unsigned int  )11;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_YIELD_N.FLOW);
            sqlstm.sqhstl[3] = (unsigned int  )21;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(GET_YIELD_N.OPER_SEQ);
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
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
            
        case 3:
            /* EXEC SQL DECLARE DBC_GET_YIELD_CUR_3 CURSOR FOR 
                SELECT NVL(OD.OPER, ' ') AS OPER, 
                    NVL(OD.OPER_DESC, ' ') AS OPER_DESC, 
                    NVL(CD.OPT_LEVEL,' ') AS OPT_LEVEL, 
                    NVL(CD.STD_YIELD, 0) AS STD_YIELD, 
                    NVL(CD.PLN_YIELD, 0) AS PLN_YIELD, 
                    NVL(CD.UNIT_CHG_YIELD, 0) AS UNIT_CHG_YIELD, 
                    NVL(CD.CUSTOM_YIELD_1, 0) AS CUSTOM_YIELD_1, 
                    NVL(CD.CUSTOM_YIELD_2, 0) AS CUSTOM_YIELD_2, 
                    NVL(CD.CUSTOM_YIELD_3, 0) AS CUSTOM_YIELD_3, 
                    NVL(CD.CUSTOM_YIELD_4, 0) AS CUSTOM_YIELD_4, 
                    NVL(CD.CUSTOM_YIELD_5, 0) AS CUSTOM_YIELD_5, 
                    NVL(CD.CREATE_USER_ID, ' ') AS CREATE_USER_ID, 
                    NVL(CD.CREATE_TIME, ' ') AS CREATE_TIME, 
                    NVL(CD.UPDATE_USER_ID, ' ') AS UPDATE_USER_ID, 
                    NVL(CD.UPDATE_TIME, ' ') AS UPDATE_TIME
                FROM MWIPOPRDEF OD, (
                    SELECT *
                    FROM MWIPYLDDEF 
                    WHERE FACTORY = :GET_YIELD_N.FACTORY 
                        AND OPT_LEVEL = '3'
                    ) CD
                WHERE OD.FACTORY = :GET_YIELD_N.FACTORY 
                    AND OD.OPER >= :GET_YIELD_N.OPER 
                    AND OD.FACTORY = CD.FACTORY(+) 
                    AND OD.OPER = CD.OPER(+) 
                ORDER BY OD.OPER ASC; */ 
 

            /* EXEC SQL OPEN DBC_GET_YIELD_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0023;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3794;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(GET_YIELD_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_YIELD_N.FACTORY);
            sqlstm.sqhstl[1] = (unsigned int  )11;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_YIELD_N.OPER);
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

        case 4:
            /* EXEC SQL DECLARE DBC_GET_YIELD_CUR_4 CURSOR FOR 
                SELECT NVL(OD.OPER, ' ') AS OPER, 
                    NVL(OD.OPER_DESC, ' ') AS OPER_DESC, 
                    NVL(CD.OPT_LEVEL,' ') AS OPT_LEVEL, 
                    NVL(CD.STD_YIELD, 0) AS STD_YIELD, 
                    NVL(CD.PLN_YIELD, 0) AS PLN_YIELD, 
                    NVL(CD.UNIT_CHG_YIELD, 0) AS UNIT_CHG_YIELD, 
                    NVL(CD.CUSTOM_YIELD_1, 0) AS CUSTOM_YIELD_1, 
                    NVL(CD.CUSTOM_YIELD_2, 0) AS CUSTOM_YIELD_2, 
                    NVL(CD.CUSTOM_YIELD_3, 0) AS CUSTOM_YIELD_3, 
                    NVL(CD.CUSTOM_YIELD_4, 0) AS CUSTOM_YIELD_4, 
                    NVL(CD.CUSTOM_YIELD_5, 0) AS CUSTOM_YIELD_5, 
                    NVL(CD.CREATE_USER_ID, ' ') AS CREATE_USER_ID, 
                    NVL(CD.CREATE_TIME, ' ') AS CREATE_TIME, 
                    NVL(CD.UPDATE_USER_ID, ' ') AS UPDATE_USER_ID, 
                    NVL(CD.UPDATE_TIME, ' ') AS UPDATE_TIME
                FROM MWIPOPRDEF OD, (
                    SELECT *
                    FROM MWIPYLDDEF 
                    WHERE FACTORY = :GET_YIELD_N.FACTORY 
                        AND MAT_ID = :GET_YIELD_N.MAT_ID 
                        AND MAT_VER = :GET_YIELD_N.MAT_VER 
                        AND OPT_LEVEL = '4'
                    ) CD
                WHERE OD.FACTORY = :GET_YIELD_N.FACTORY 
                    AND OD.OPER >= :GET_YIELD_N.OPER 
                    AND OD.FACTORY = CD.FACTORY(+) 
                    AND OD.OPER = CD.OPER(+) 
                ORDER BY OD.OPER ASC; */ 
 

            /* EXEC SQL OPEN DBC_GET_YIELD_CUR_4; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = sq0024;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3821;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqcmod = (unsigned int )0;
            sqlstm.sqhstv[0] = (         void  *)(GET_YIELD_N.FACTORY);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_YIELD_N.MAT_ID);
            sqlstm.sqhstl[1] = (unsigned int  )31;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)&(GET_YIELD_N.MAT_VER);
            sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_YIELD_N.FACTORY);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)(GET_YIELD_N.OPER);
            sqlstm.sqhstl[4] = (unsigned int  )11;
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


        default:
            DB_error_code = 9999;
            memset(DB_error_msg, ' ', sizeof(DB_error_msg));
            memcpy(DB_error_msg, "Error : Invalid Argument(sel_type)", 34);
            break;
    }
    DB_stop_query_timer("DBC_open_get_yield", sel_type);
}


/* SQL CURSOR FETCH Function */
void DBC_fetch_get_yield(int sel_type, struct GET_YIELD_TAG *GET_YIELD)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

        struct GET_YIELD_N_TAG GET_YIELD_N;
    /* EXEC SQL END DECLARE SECTION; */ 


    DB_start_query_timer();

    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL FETCH DBC_GET_YIELD_CUR_1 INTO 
                :GET_YIELD_N.FLOW,
                :GET_YIELD_N.FLOW_SEQ_NUM,
                :GET_YIELD_N.FLOW_DESC,                
                :GET_YIELD_N.OPER,
                :GET_YIELD_N.OPER_SEQ,
                :GET_YIELD_N.OPER_DESC,
                :GET_YIELD_N.OPT_LEVEL,
                :GET_YIELD_N.STD_YIELD,
                :GET_YIELD_N.PLN_YIELD,
                :GET_YIELD_N.UNIT_CHG_YIELD,
                :GET_YIELD_N.CUSTOM_YIELD_1,
                :GET_YIELD_N.CUSTOM_YIELD_2,
                :GET_YIELD_N.CUSTOM_YIELD_3,
                :GET_YIELD_N.CUSTOM_YIELD_4,
                :GET_YIELD_N.CUSTOM_YIELD_5,
                :GET_YIELD_N.CREATE_USER_ID,
                :GET_YIELD_N.CREATE_TIME,
                :GET_YIELD_N.UPDATE_USER_ID,
                :GET_YIELD_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3856;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(GET_YIELD_N.FLOW);
            sqlstm.sqhstl[0] = (unsigned int  )21;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(GET_YIELD_N.FLOW_SEQ_NUM);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_YIELD_N.FLOW_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_YIELD_N.OPER);
            sqlstm.sqhstl[3] = (unsigned int  )11;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(GET_YIELD_N.OPER_SEQ);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)(GET_YIELD_N.OPER_DESC);
            sqlstm.sqhstl[5] = (unsigned int  )201;
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)(GET_YIELD_N.OPT_LEVEL);
            sqlstm.sqhstl[6] = (unsigned int  )2;
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(GET_YIELD_N.STD_YIELD);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(GET_YIELD_N.PLN_YIELD);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(GET_YIELD_N.UNIT_CHG_YIELD);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(GET_YIELD_N.CUSTOM_YIELD_1);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(GET_YIELD_N.CUSTOM_YIELD_2);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)&(GET_YIELD_N.CUSTOM_YIELD_3);
            sqlstm.sqhstl[12] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)&(GET_YIELD_N.CUSTOM_YIELD_4);
            sqlstm.sqhstl[13] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)&(GET_YIELD_N.CUSTOM_YIELD_5);
            sqlstm.sqhstl[14] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(GET_YIELD_N.CREATE_USER_ID);
            sqlstm.sqhstl[15] = (unsigned int  )21;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
            sqlstm.sqhstv[16] = (         void  *)(GET_YIELD_N.CREATE_TIME);
            sqlstm.sqhstl[16] = (unsigned int  )15;
            sqlstm.sqhsts[16] = (         int  )0;
            sqlstm.sqindv[16] = (         void  *)0;
            sqlstm.sqinds[16] = (         int  )0;
            sqlstm.sqharm[16] = (unsigned int  )0;
            sqlstm.sqadto[16] = (unsigned short )0;
            sqlstm.sqtdso[16] = (unsigned short )0;
            sqlstm.sqhstv[17] = (         void  *)(GET_YIELD_N.UPDATE_USER_ID);
            sqlstm.sqhstl[17] = (unsigned int  )21;
            sqlstm.sqhsts[17] = (         int  )0;
            sqlstm.sqindv[17] = (         void  *)0;
            sqlstm.sqinds[17] = (         int  )0;
            sqlstm.sqharm[17] = (unsigned int  )0;
            sqlstm.sqadto[17] = (unsigned short )0;
            sqlstm.sqtdso[17] = (unsigned short )0;
            sqlstm.sqhstv[18] = (         void  *)(GET_YIELD_N.UPDATE_TIME);
            sqlstm.sqhstl[18] = (unsigned int  )15;
            sqlstm.sqhsts[18] = (         int  )0;
            sqlstm.sqindv[18] = (         void  *)0;
            sqlstm.sqinds[18] = (         int  )0;
            sqlstm.sqharm[18] = (unsigned int  )0;
            sqlstm.sqadto[18] = (unsigned short )0;
            sqlstm.sqtdso[18] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBC_GET_YIELD_CUR_2 INTO 
                :GET_YIELD_N.OPER, 
                :GET_YIELD_N.OPER_SEQ,
                :GET_YIELD_N.OPER_DESC, 
                :GET_YIELD_N.OPT_LEVEL, 
                :GET_YIELD_N.STD_YIELD,
                :GET_YIELD_N.PLN_YIELD,
                :GET_YIELD_N.UNIT_CHG_YIELD,
                :GET_YIELD_N.CUSTOM_YIELD_1,
                :GET_YIELD_N.CUSTOM_YIELD_2,
                :GET_YIELD_N.CUSTOM_YIELD_3,
                :GET_YIELD_N.CUSTOM_YIELD_4,
                :GET_YIELD_N.CUSTOM_YIELD_5,
                :GET_YIELD_N.CREATE_USER_ID,
                :GET_YIELD_N.CREATE_TIME,
                :GET_YIELD_N.UPDATE_USER_ID, 
                :GET_YIELD_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )3947;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(GET_YIELD_N.OPER);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)&(GET_YIELD_N.OPER_SEQ);
            sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_YIELD_N.OPER_DESC);
            sqlstm.sqhstl[2] = (unsigned int  )201;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)(GET_YIELD_N.OPT_LEVEL);
            sqlstm.sqhstl[3] = (unsigned int  )2;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(GET_YIELD_N.STD_YIELD);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(GET_YIELD_N.PLN_YIELD);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(GET_YIELD_N.UNIT_CHG_YIELD);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(GET_YIELD_N.CUSTOM_YIELD_1);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(GET_YIELD_N.CUSTOM_YIELD_2);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(GET_YIELD_N.CUSTOM_YIELD_3);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(GET_YIELD_N.CUSTOM_YIELD_4);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)&(GET_YIELD_N.CUSTOM_YIELD_5);
            sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(GET_YIELD_N.CREATE_USER_ID);
            sqlstm.sqhstl[12] = (unsigned int  )21;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(GET_YIELD_N.CREATE_TIME);
            sqlstm.sqhstl[13] = (unsigned int  )15;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(GET_YIELD_N.UPDATE_USER_ID);
            sqlstm.sqhstl[14] = (unsigned int  )21;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
            sqlstm.sqhstv[15] = (         void  *)(GET_YIELD_N.UPDATE_TIME);
            sqlstm.sqhstl[15] = (unsigned int  )15;
            sqlstm.sqhsts[15] = (         int  )0;
            sqlstm.sqindv[15] = (         void  *)0;
            sqlstm.sqinds[15] = (         int  )0;
            sqlstm.sqharm[15] = (unsigned int  )0;
            sqlstm.sqadto[15] = (unsigned short )0;
            sqlstm.sqtdso[15] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBC_GET_YIELD_CUR_3 INTO 
                :GET_YIELD_N.OPER, 
                :GET_YIELD_N.OPER_DESC, 
                :GET_YIELD_N.OPT_LEVEL, 
                :GET_YIELD_N.STD_YIELD,
                :GET_YIELD_N.PLN_YIELD,
                :GET_YIELD_N.UNIT_CHG_YIELD,
                :GET_YIELD_N.CUSTOM_YIELD_1,
                :GET_YIELD_N.CUSTOM_YIELD_2,
                :GET_YIELD_N.CUSTOM_YIELD_3,
                :GET_YIELD_N.CUSTOM_YIELD_4,
                :GET_YIELD_N.CUSTOM_YIELD_5,
                :GET_YIELD_N.CREATE_USER_ID, 
                :GET_YIELD_N.CREATE_TIME, 
                :GET_YIELD_N.UPDATE_USER_ID, 
                :GET_YIELD_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )4026;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(GET_YIELD_N.OPER);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_YIELD_N.OPER_DESC);
            sqlstm.sqhstl[1] = (unsigned int  )201;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_YIELD_N.OPT_LEVEL);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(GET_YIELD_N.STD_YIELD);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(GET_YIELD_N.PLN_YIELD);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(GET_YIELD_N.UNIT_CHG_YIELD);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(GET_YIELD_N.CUSTOM_YIELD_1);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(GET_YIELD_N.CUSTOM_YIELD_2);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(GET_YIELD_N.CUSTOM_YIELD_3);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(GET_YIELD_N.CUSTOM_YIELD_4);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(GET_YIELD_N.CUSTOM_YIELD_5);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(GET_YIELD_N.CREATE_USER_ID);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(GET_YIELD_N.CREATE_TIME);
            sqlstm.sqhstl[12] = (unsigned int  )15;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(GET_YIELD_N.UPDATE_USER_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(GET_YIELD_N.UPDATE_TIME);
            sqlstm.sqhstl[14] = (unsigned int  )15;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
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
            /* EXEC SQL FETCH DBC_GET_YIELD_CUR_4 INTO 
                :GET_YIELD_N.OPER, 
                :GET_YIELD_N.OPER_DESC, 
                :GET_YIELD_N.OPT_LEVEL, 
                :GET_YIELD_N.STD_YIELD,
                :GET_YIELD_N.PLN_YIELD,
                :GET_YIELD_N.UNIT_CHG_YIELD,
                :GET_YIELD_N.CUSTOM_YIELD_1,
                :GET_YIELD_N.CUSTOM_YIELD_2,
                :GET_YIELD_N.CUSTOM_YIELD_3,
                :GET_YIELD_N.CUSTOM_YIELD_4,
                :GET_YIELD_N.CUSTOM_YIELD_5,
                :GET_YIELD_N.CREATE_USER_ID, 
                :GET_YIELD_N.CREATE_TIME, 
                :GET_YIELD_N.UPDATE_USER_ID, 
                :GET_YIELD_N.UPDATE_TIME; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )4101;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.sqlpfmem = (unsigned int  )0;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqfoff = (           int )0;
            sqlstm.sqfmod = (unsigned int )2;
            sqlstm.sqhstv[0] = (         void  *)(GET_YIELD_N.OPER);
            sqlstm.sqhstl[0] = (unsigned int  )11;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         void  *)0;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned int  )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (         void  *)(GET_YIELD_N.OPER_DESC);
            sqlstm.sqhstl[1] = (unsigned int  )201;
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         void  *)0;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned int  )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (         void  *)(GET_YIELD_N.OPT_LEVEL);
            sqlstm.sqhstl[2] = (unsigned int  )2;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         void  *)0;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned int  )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (         void  *)&(GET_YIELD_N.STD_YIELD);
            sqlstm.sqhstl[3] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         void  *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned int  )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (         void  *)&(GET_YIELD_N.PLN_YIELD);
            sqlstm.sqhstl[4] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         void  *)0;
            sqlstm.sqinds[4] = (         int  )0;
            sqlstm.sqharm[4] = (unsigned int  )0;
            sqlstm.sqadto[4] = (unsigned short )0;
            sqlstm.sqtdso[4] = (unsigned short )0;
            sqlstm.sqhstv[5] = (         void  *)&(GET_YIELD_N.UNIT_CHG_YIELD);
            sqlstm.sqhstl[5] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[5] = (         int  )0;
            sqlstm.sqindv[5] = (         void  *)0;
            sqlstm.sqinds[5] = (         int  )0;
            sqlstm.sqharm[5] = (unsigned int  )0;
            sqlstm.sqadto[5] = (unsigned short )0;
            sqlstm.sqtdso[5] = (unsigned short )0;
            sqlstm.sqhstv[6] = (         void  *)&(GET_YIELD_N.CUSTOM_YIELD_1);
            sqlstm.sqhstl[6] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[6] = (         int  )0;
            sqlstm.sqindv[6] = (         void  *)0;
            sqlstm.sqinds[6] = (         int  )0;
            sqlstm.sqharm[6] = (unsigned int  )0;
            sqlstm.sqadto[6] = (unsigned short )0;
            sqlstm.sqtdso[6] = (unsigned short )0;
            sqlstm.sqhstv[7] = (         void  *)&(GET_YIELD_N.CUSTOM_YIELD_2);
            sqlstm.sqhstl[7] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[7] = (         int  )0;
            sqlstm.sqindv[7] = (         void  *)0;
            sqlstm.sqinds[7] = (         int  )0;
            sqlstm.sqharm[7] = (unsigned int  )0;
            sqlstm.sqadto[7] = (unsigned short )0;
            sqlstm.sqtdso[7] = (unsigned short )0;
            sqlstm.sqhstv[8] = (         void  *)&(GET_YIELD_N.CUSTOM_YIELD_3);
            sqlstm.sqhstl[8] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[8] = (         int  )0;
            sqlstm.sqindv[8] = (         void  *)0;
            sqlstm.sqinds[8] = (         int  )0;
            sqlstm.sqharm[8] = (unsigned int  )0;
            sqlstm.sqadto[8] = (unsigned short )0;
            sqlstm.sqtdso[8] = (unsigned short )0;
            sqlstm.sqhstv[9] = (         void  *)&(GET_YIELD_N.CUSTOM_YIELD_4);
            sqlstm.sqhstl[9] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[9] = (         int  )0;
            sqlstm.sqindv[9] = (         void  *)0;
            sqlstm.sqinds[9] = (         int  )0;
            sqlstm.sqharm[9] = (unsigned int  )0;
            sqlstm.sqadto[9] = (unsigned short )0;
            sqlstm.sqtdso[9] = (unsigned short )0;
            sqlstm.sqhstv[10] = (         void  *)&(GET_YIELD_N.CUSTOM_YIELD_5);
            sqlstm.sqhstl[10] = (unsigned int  )sizeof(double);
            sqlstm.sqhsts[10] = (         int  )0;
            sqlstm.sqindv[10] = (         void  *)0;
            sqlstm.sqinds[10] = (         int  )0;
            sqlstm.sqharm[10] = (unsigned int  )0;
            sqlstm.sqadto[10] = (unsigned short )0;
            sqlstm.sqtdso[10] = (unsigned short )0;
            sqlstm.sqhstv[11] = (         void  *)(GET_YIELD_N.CREATE_USER_ID);
            sqlstm.sqhstl[11] = (unsigned int  )21;
            sqlstm.sqhsts[11] = (         int  )0;
            sqlstm.sqindv[11] = (         void  *)0;
            sqlstm.sqinds[11] = (         int  )0;
            sqlstm.sqharm[11] = (unsigned int  )0;
            sqlstm.sqadto[11] = (unsigned short )0;
            sqlstm.sqtdso[11] = (unsigned short )0;
            sqlstm.sqhstv[12] = (         void  *)(GET_YIELD_N.CREATE_TIME);
            sqlstm.sqhstl[12] = (unsigned int  )15;
            sqlstm.sqhsts[12] = (         int  )0;
            sqlstm.sqindv[12] = (         void  *)0;
            sqlstm.sqinds[12] = (         int  )0;
            sqlstm.sqharm[12] = (unsigned int  )0;
            sqlstm.sqadto[12] = (unsigned short )0;
            sqlstm.sqtdso[12] = (unsigned short )0;
            sqlstm.sqhstv[13] = (         void  *)(GET_YIELD_N.UPDATE_USER_ID);
            sqlstm.sqhstl[13] = (unsigned int  )21;
            sqlstm.sqhsts[13] = (         int  )0;
            sqlstm.sqindv[13] = (         void  *)0;
            sqlstm.sqinds[13] = (         int  )0;
            sqlstm.sqharm[13] = (unsigned int  )0;
            sqlstm.sqadto[13] = (unsigned short )0;
            sqlstm.sqtdso[13] = (unsigned short )0;
            sqlstm.sqhstv[14] = (         void  *)(GET_YIELD_N.UPDATE_TIME);
            sqlstm.sqhstl[14] = (unsigned int  )15;
            sqlstm.sqhsts[14] = (         int  )0;
            sqlstm.sqindv[14] = (         void  *)0;
            sqlstm.sqinds[14] = (         int  )0;
            sqlstm.sqharm[14] = (unsigned int  )0;
            sqlstm.sqadto[14] = (unsigned short )0;
            sqlstm.sqtdso[14] = (unsigned short )0;
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
        DBC_del_null_get_yield(&GET_YIELD_N, GET_YIELD);
    }
    DB_stop_query_timer("DBC_fetch_get_yield", sel_type);
}


/* SQL CURSOR CLOSE Function */
void DBC_close_get_yield(int sel_type)
{

    DB_start_query_timer();
    DB_error_code = 0;

    switch(sel_type)
    {
        case 1:
            /* EXEC SQL CLOSE DBC_GET_YIELD_CUR_1; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )4176;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
            
        case 2:
            /* EXEC SQL CLOSE DBC_GET_YIELD_CUR_2; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )4191;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;
            
        case 3:
            /* EXEC SQL CLOSE DBC_GET_YIELD_CUR_3; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )4206;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
            if (sqlca.sqlcode < 0) DB_usr_error();
}


            break;

        case 4:
            /* EXEC SQL CLOSE DBC_GET_YIELD_CUR_4; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 13;
            sqlstm.arrsiz = 142;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )4221;
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
    DB_stop_query_timer("DBC_close_get_yield", sel_type);
}

/* Initialize Function */
void DBC_init_get_yield(struct GET_YIELD_TAG *GET_YIELD)
{
    /* memset by Space */
    memset(GET_YIELD, ' ', sizeof(struct GET_YIELD_TAG));

    GET_YIELD->MAT_VER = 0;
    GET_YIELD->FLOW_SEQ_NUM = 0;
    GET_YIELD->OPER_SEQ = 0;
    GET_YIELD->STD_YIELD = 0;
    GET_YIELD->PLN_YIELD = 0;
    GET_YIELD->UNIT_CHG_YIELD = 0;
    GET_YIELD->CUSTOM_YIELD_1 = 0;
    GET_YIELD->CUSTOM_YIELD_2 = 0;
    GET_YIELD->CUSTOM_YIELD_3 = 0;
    GET_YIELD->CUSTOM_YIELD_4 = 0;
    GET_YIELD->CUSTOM_YIELD_5 = 0;
}

/* Add Null Function */
void DBC_add_null_get_yield(struct GET_YIELD_N_TAG *GET_YIELD_N, struct GET_YIELD_TAG *GET_YIELD)
{ 
    /* memset by NULL */
    memset(GET_YIELD_N, '\0', sizeof(struct GET_YIELD_N_TAG));

    MEMCPY_AN(GET_YIELD_N->FACTORY ,GET_YIELD->FACTORY ,sizeof(GET_YIELD->FACTORY ));
    MEMCPY_AN(GET_YIELD_N->MAT_ID , GET_YIELD->MAT_ID , sizeof(GET_YIELD->MAT_ID ));
    GET_YIELD_N->MAT_VER = GET_YIELD->MAT_VER;
    MEMCPY_AN(GET_YIELD_N->FLOW ,GET_YIELD->FLOW ,sizeof(GET_YIELD->FLOW ));
    GET_YIELD_N->FLOW_SEQ_NUM = GET_YIELD->FLOW_SEQ_NUM;
    MEMCPY_AN(GET_YIELD_N->FLOW_DESC ,GET_YIELD->FLOW_DESC,sizeof(GET_YIELD->FLOW_DESC));
    MEMCPY_AN(GET_YIELD_N->OPER , GET_YIELD->OPER , sizeof(GET_YIELD->OPER ));
    MEMCPY_AN(GET_YIELD_N->OPER_DESC , GET_YIELD->OPER_DESC, sizeof(GET_YIELD->OPER_DESC));
    GET_YIELD_N->OPER_SEQ = GET_YIELD->OPER_SEQ;
    GET_YIELD_N->OPT_LEVEL[0] = GET_YIELD->OPT_LEVEL;
    GET_YIELD_N->STD_YIELD = GET_YIELD->STD_YIELD ;
    GET_YIELD_N->PLN_YIELD = GET_YIELD->PLN_YIELD ;
    GET_YIELD_N->UNIT_CHG_YIELD = GET_YIELD->UNIT_CHG_YIELD ;
    GET_YIELD_N->CUSTOM_YIELD_1 = GET_YIELD->CUSTOM_YIELD_1 ;
    GET_YIELD_N->CUSTOM_YIELD_2 = GET_YIELD->CUSTOM_YIELD_2 ;
    GET_YIELD_N->CUSTOM_YIELD_3 = GET_YIELD->CUSTOM_YIELD_3 ;
    GET_YIELD_N->CUSTOM_YIELD_4 = GET_YIELD->CUSTOM_YIELD_4 ;
    GET_YIELD_N->CUSTOM_YIELD_5 = GET_YIELD->CUSTOM_YIELD_5 ;
    MEMCPY_AN(GET_YIELD_N->CREATE_TIME ,GET_YIELD->CREATE_TIME , sizeof(GET_YIELD->CREATE_TIME ));
    MEMCPY_AN(GET_YIELD_N->CREATE_USER_ID ,GET_YIELD->CREATE_USER_ID , sizeof(GET_YIELD->CREATE_USER_ID ));
    MEMCPY_AN(GET_YIELD_N->UPDATE_TIME ,GET_YIELD->UPDATE_TIME , sizeof(GET_YIELD->UPDATE_TIME ));
    MEMCPY_AN(GET_YIELD_N->UPDATE_USER_ID ,GET_YIELD->UPDATE_USER_ID , sizeof(GET_YIELD->UPDATE_USER_ID ));
}


/* Del Null Function */
void DBC_del_null_get_yield(struct GET_YIELD_N_TAG *GET_YIELD_N, struct GET_YIELD_TAG *GET_YIELD)
{
    MEMCPY_DN(GET_YIELD->FACTORY ,GET_YIELD_N->FACTORY ,sizeof(GET_YIELD->FACTORY ));
    MEMCPY_DN(GET_YIELD->MAT_ID , GET_YIELD_N->MAT_ID , sizeof(GET_YIELD->MAT_ID ));
    GET_YIELD->MAT_VER = GET_YIELD_N->MAT_VER;
    MEMCPY_DN(GET_YIELD->FLOW ,GET_YIELD_N->FLOW ,sizeof(GET_YIELD->FLOW ));
    GET_YIELD->FLOW_SEQ_NUM = GET_YIELD_N->FLOW_SEQ_NUM;
    MEMCPY_DN(GET_YIELD->FLOW_DESC ,GET_YIELD_N->FLOW_DESC,sizeof(GET_YIELD->FLOW_DESC));
    MEMCPY_DN(GET_YIELD->OPER , GET_YIELD_N->OPER , sizeof(GET_YIELD->OPER ));
    MEMCPY_DN(GET_YIELD->OPER_DESC , GET_YIELD_N->OPER_DESC, sizeof(GET_YIELD->OPER_DESC));
    GET_YIELD->OPER_SEQ = GET_YIELD_N->OPER_SEQ;
    GET_YIELD->OPT_LEVEL = GET_YIELD_N->OPT_LEVEL[0];
    GET_YIELD->STD_YIELD = GET_YIELD_N->STD_YIELD ;
    GET_YIELD->PLN_YIELD = GET_YIELD_N->PLN_YIELD ;
    GET_YIELD->UNIT_CHG_YIELD = GET_YIELD_N->UNIT_CHG_YIELD ;
    GET_YIELD->CUSTOM_YIELD_1 = GET_YIELD_N->CUSTOM_YIELD_1 ;
    GET_YIELD->CUSTOM_YIELD_2 = GET_YIELD_N->CUSTOM_YIELD_2 ;
    GET_YIELD->CUSTOM_YIELD_3 = GET_YIELD_N->CUSTOM_YIELD_3 ;
    GET_YIELD->CUSTOM_YIELD_4 = GET_YIELD_N->CUSTOM_YIELD_4 ;
    GET_YIELD->CUSTOM_YIELD_5 = GET_YIELD_N->CUSTOM_YIELD_5 ;
    MEMCPY_DN(GET_YIELD->CREATE_TIME ,GET_YIELD_N->CREATE_TIME , sizeof(GET_YIELD->CREATE_TIME ));
    MEMCPY_DN(GET_YIELD->CREATE_USER_ID ,GET_YIELD_N->CREATE_USER_ID , sizeof(GET_YIELD->CREATE_USER_ID ));
    MEMCPY_DN(GET_YIELD->UPDATE_TIME ,GET_YIELD_N->UPDATE_TIME , sizeof(GET_YIELD->UPDATE_TIME ));
    MEMCPY_DN(GET_YIELD->UPDATE_USER_ID ,GET_YIELD_N->UPDATE_USER_ID , sizeof(GET_YIELD->UPDATE_USER_ID ));
} 
