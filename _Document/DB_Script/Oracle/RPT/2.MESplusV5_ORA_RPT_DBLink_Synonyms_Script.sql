/*
**
**  File Name    : MESplusV5_ORA_RPT_User_Roles_Script.sql
**  Description  : MES Database Creation User & Role Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10
**
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
*/
PROMPT ##### Make Database Link #####

/*==== Database link of MES DB  ====*/
create database link MMESDB /* DATABASE LINK NAME */
connect to mesmgr        /* User Name for MES DB */
identified by mesmgr   /* Password For MESDB */
using 'ORAMES'          /* MES DB Name */
/

PROMPT ##### Make Public Synonyms #####
create synonym MWIPSLTDEF for MWIPSLTDEF@MMESDB;
create synonym MBASGLBDEF for MBASGLBDEF@MMESDB;
create synonym MATRNAMHIS for MATRNAMHIS@MMESDB;
create synonym MATRNAMSTS for MATRNAMSTS@MMESDB;
create synonym MEDCLOTDAT for MEDCLOTDAT@MMESDB;
create synonym MGCMTBLDAT for MGCMTBLDAT@MMESDB;
create synonym MMSGMSGDEF for MMSGMSGDEF@MMESDB;
create synonym MRASCRRHIS for MRASCRRHIS@MMESDB;
create synonym MRASCRRDEF for MRASCRRDEF@MMESDB;
create synonym MRASRESDEF for MRASRESDEF@MMESDB;
create synonym MRASRESHIS for MRASRESHIS@MMESDB;
create synonym MRASRESLTH for MRASRESLTH@MMESDB;
create synonym MRASSRSDEF for MRASSRSDEF@MMESDB;
create synonym MRASSRSHIS for MRASSRSHIS@MMESDB;
create synonym MRASSRSLOT for MRASSRSLOT@MMESDB;
create synonym MRASSRSLTH for MRASSRSLTH@MMESDB;
create synonym MWIPCALDEF for MWIPCALDEF@MMESDB;
create synonym MWIPCYTDEF for MWIPCYTDEF@MMESDB;
create synonym MWIPFACDEF for MWIPFACDEF@MMESDB;
create synonym MWIPFLWDEF for MWIPFLWDEF@MMESDB;
create synonym MWIPFLWOPR for MWIPFLWOPR@MMESDB;
create synonym MWIPLOTBNS for MWIPLOTBNS@MMESDB;
create synonym MWIPLOTCMB for MWIPLOTCMB@MMESDB;
create synonym MWIPLOTHIS for MWIPLOTHIS@MMESDB;
create synonym MWIPLOTHLD for MWIPLOTHLD@MMESDB;
create synonym MWIPLOTLOS for MWIPLOTLOS@MMESDB;
create synonym MWIPLOTLSM for MWIPLOTLSM@MMESDB;
create synonym MWIPLOTBNM for MWIPLOTBNM@MMESDB;
create synonym MWIPLOTMRG for MWIPLOTMRG@MMESDB;
create synonym MWIPLOTRWK for MWIPLOTRWK@MMESDB;
create synonym MWIPLOTSHP for MWIPLOTSHP@MMESDB;
create synonym MWIPLOTSPL for MWIPLOTSPL@MMESDB;
create synonym MWIPLOTSTS for MWIPLOTSTS@MMESDB;
create synonym MWIPMATDEF for MWIPMATDEF@MMESDB;
create synonym MWIPMATFLW for MWIPMATFLW@MMESDB;
create synonym MWIPOPRDEF for MWIPOPRDEF@MMESDB;
create synonym MWIPSLTHIS for MWIPSLTHIS@MMESDB;
create synonym MWIPSLTLOS for MWIPSLTLOS@MMESDB;
create synonym MWIPSLTSTS for MWIPSLTSTS@MMESDB;
create synonym MTMPATRHIS for MTMPATRHIS@MMESDB;
create synonym MTMPCRRHIS for MTMPCRRHIS@MMESDB;
create synonym MTMPLOTHIS for MTMPLOTHIS@MMESDB;
create synonym MTMPRESHIS for MTMPRESHIS@MMESDB;
create synonym MATRNAMDEF for MATRNAMDEF@MMESDB;
create synonym MWIPLOTDEL for MWIPLOTDEL@MMESDB;
create synonym MWIPLOTCVM for MWIPLOTCVM@MMESDB;
create synonym MEDCRESDAT for MEDCRESDAT@MMESDB;
