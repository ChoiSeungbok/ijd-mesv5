/*
**
**  File Name    : MESplusV5-Table-Migration.sql
**  Description  : MESplus V5 Release Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g / 11g
**
**  Period       : 2013.02.18 ~ ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
**  1. 2013.02.18   Aiden   Create
*/

DROP TABLE MWIPQTMDEF_OLD CASCADE CONSTRAINT PURGE;
DROP TABLE MWIPQTMHIS_OLD CASCADE CONSTRAINT PURGE;
DROP TABLE MWIPLOTQTM_OLD CASCADE CONSTRAINT PURGE;

DROP TABLE MWIPBINSHS_OLD CASCADE CONSTRAINT PURGE;
DROP TABLE MWIPBINSSH_OLD CASCADE CONSTRAINT PURGE;

