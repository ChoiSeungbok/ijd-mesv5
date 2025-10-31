/*
**
**  File Name    : MESplusV5_ORA_SPC_Table_Script.sql
**  Description  : MES Database Table Creation SQL Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10
**
**  ==== Table Naming Rule ====
**  M WIP FAC DEF
**  1 234 567 890
**  - --- --- ---
**  1    - Sub System Name - M:MES, R:RPT, C:Customized, I:Interface, B:Backup, L:Log, T:Temporary
**  234  - Module Name
**  567  - Object Name(ex, FAC, MAT, FLW, OPR, RES, LOT, EQP, CST)
**  890  - Second Object Name 
**         or Object Status(ex, STS:Status, HIS:History, DEF:Definition, GRP:Group)
**
**  ==== Module Naming Rule ====
**  1. Basic Module --
**      MSG : Message Module
**      SEC : Security Module
**      GCM : General Code Management Module
**  2. MES Module --
**      WIP : Work In Process Module
**      BOM : Bill Of Material Module
**      INV : Inventory
**      QCM : Quality Control Module
**      RAS : Resource Allocation and Status Module
**      EDC : Engineering Data Collection Module
**      ALM : Alarm Module
**      RCP : Recipe Module
**      RTD : Real-Time Dispatch Module
**      RTS : Real-Time Schedule Module
**  3. Interface Module --
**      TMP : Temporary Tables
**      ERP : ERP Interface Module
**  4. RPT Module --
**      MPI : Manufacturing Performance Indicator
**      RPT : Report Module
**      SUM : Summary Module
**      WEB : Web Security Module
**  ============================
**
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
*/

/*==== ARC(Archive Module) ====*/
/* MARCOPTDEF : */
CREATE TABLE MARCOPTDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MODULE                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TERM                        NUMBER(6)        DEFAULT(0)      NOT NULL,
    DAYS                        NUMBER(6)        DEFAULT(0)      NOT NULL,
    SPD_TIME                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    MOD_TYPE                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    MED_TYPE                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    ROL_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    MAS_DEL_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG1                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG2                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG3                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG4                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG5                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FIELD1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MARCOPTDEF
ADD CONSTRAINT MARCOPTDEF_PK PRIMARY KEY
(
    FACTORY,
    MODULE
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MARCTABDEF : */
CREATE TABLE MARCTABDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TBL_NAME                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TBL_TYPE                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    MODULE                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_FIELD1                  VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    KEY_FIELD2                  VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    KEY_FIELD3                  VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    KEY_FIELD4                  VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    KEY_FIELD5                  VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    TERM_FIELD                  VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    WHERE_CND                   VARCHAR2(500)    DEFAULT(' ')    NOT NULL,
    RESV_FLAG1                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG2                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG3                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG4                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG5                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FIELD1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MARCTABDEF
ADD CONSTRAINT MARCTABDEF_PK PRIMARY KEY
(
    FACTORY,
    TBL_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MARCLOGDEF : */
CREATE TABLE MARCLOGDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MODULE                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOG                         VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    STATUS_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    END_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    RESV_FLAG1                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG2                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG3                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG4                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG5                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FIELD1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MARCLOGDEF
ADD CONSTRAINT MARCLOGDEF_PK PRIMARY KEY
(
    FACTORY,
    MODULE,
    LOG
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MARCLOGHIS : */
CREATE TABLE MARCLOGHIS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MODULE                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOG                         VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    CONTENT                     VARCHAR2(500)    DEFAULT(' ')    NOT NULL,
    RESV_FLAG1                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG2                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG3                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG4                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG5                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FIELD1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MARCLOGHIS
ADD CONSTRAINT MARCLOGHIS_PK PRIMARY KEY
(
    FACTORY,
    MODULE,
    LOG,
    SEQ_NUM    
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MARCRUNDAT : */
CREATE TABLE MARCRUNDAT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MODULE                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    RESV_FLAG1                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG2                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FIELD1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;
