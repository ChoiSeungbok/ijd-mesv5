/*
**
**  File Name    : MESplusV5-Table-Migration.sql
**  Description  : MESplus V5 Release Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g
**
**  Period       : 2009.03.20 ~ ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
**
**  Revision History
**  Seq   Date        Modifier      Description                        
**  ---------------------------------------------------------------------------
**  1     2009.03.20  Aiden         Make file
   
*/

DROP TABLE MSVMSVCMBR_OLD CASCADE CONSTRAINT PURGE; 

DROP TABLE MWIPBATDEF_OLD CASCADE CONSTRAINT PURGE; 

DROP TABLE MWIPBATHIS_OLD CASCADE CONSTRAINT PURGE; 

DROP TABLE MWIPBATRSV_OLD CASCADE CONSTRAINT PURGE; 

DROP TABLE MSECFLXHDR_OLD CASCADE CONSTRAINT PURGE; 

