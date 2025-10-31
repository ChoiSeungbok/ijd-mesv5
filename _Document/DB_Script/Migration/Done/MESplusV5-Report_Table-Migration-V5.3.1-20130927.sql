/*
**
**  File Name    : MESplusV5-Reprot Table-Migration.sql
**  Description  : MESplus V5 Release Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g / 11g
**
**  Period       : 2010.12.11 ~ ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
**  Revision History
**  Seq Date        Modifier      Description                        
**  -------------------------------------------------------------------------
**  1   2010.12.11  James Kwon	  Create
*/


ALTER TABLE RWIPSLTLOS ADD LOSS_QTY     NUMBER(10,3)     DEFAULT(0.0)   NOT NULL;
