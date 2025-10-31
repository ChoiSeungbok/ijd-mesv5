/*
**
**  File Name    : MESplusV5-Table-Migration_Drop.sql
**  Description  : MESplus V5 Release Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g
**
**  Period       : 2009.03.04 ~ ****
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


DROP TABLE MWIPFACSHP_OLD CASCADE CONSTRAINT PURGE;

DROP TABLE MRTDLOTPDS_OLD CASCADE CONSTRAINT PURGE;

DROP TABLE MRTDLOTPDH_OLD CASCADE CONSTRAINT PURGE;

DROP TABLE MFMBRESLOC_OLD CASCADE CONSTRAINT PURGE;

DROP TABLE MFMBUDRLOC_OLD CASCADE CONSTRAINT PURGE;   

DROP TABLE MFMBEVTCLR_OLD CASCADE CONSTRAINT PURGE;   

DROP TABLE MFMBENVDEF_OLD CASCADE CONSTRAINT PURGE; 

