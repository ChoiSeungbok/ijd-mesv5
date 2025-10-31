/*
**
**  File Name    : MESplusV5-Table-Migration.sql
**  Description  : MESplus V5 Release Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g / 11g
**
**  Period       : 2013.03.13 ~ ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
**  1. 2013.03.13   IC.Bae   Create
*/


DROP TABLE MSPMDOCIMG_OLD CASCADE CONSTRAINT PURGE;
DROP TABLE MWIPBINSSH_OLD CASCADE CONSTRAINT PURGE;
DROP TABLE MWIPIDGHIS_OLD CASCADE CONSTRAINT PURGE;
DROP TABLE MWIPIDGSKV_OLD CASCADE CONSTRAINT PURGE;
DROP TABLE MWIPQTMDEF_OLD CASCADE CONSTRAINT PURGE;

