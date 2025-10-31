/*
**
**  File Name    : MESplusV5-Table-Migration_Table.sql
**  Description  : MESplus V5 Release for Table Migration
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g / 11g
**
**  Period       : 2013.03.13 ~ ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
**  1. 2013.05.27   IC Bae   Create
*/

ALTER TABLE MTMPATRHIS ADD TRAN_USER_ID           VARCHAR2(20)       DEFAULT(' ')    NOT NULL;
