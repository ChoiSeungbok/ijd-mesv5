/*
**
**  File Name    : MESplusV5-Report-Migration_Data.sql
**  Description  : MESplus V5 Release for Report Data Migration
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g / 11g
**
**  Period       : 2012.12.28 ~ ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
*/

CREATE TABLE RRASRESLTH_OLD AS SELECT * FROM RRASRESLTH;
DROP TABLE RRASRESLTH CASCADE CONSTRAINT PURGE;

CREATE TABLE RRASRESLTH
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RES_HIST_DEL_FLAG           CHAR(1),
    EVENT_ID                    VARCHAR2(12),
    TRAN_TIME                   VARCHAR2(14),
    LOT_HIST_SEQ                NUMBER(10),
    LOT_HIST_DEL_FLAG           CHAR(1),
    MAT_ID                      VARCHAR2(30),
    MAT_VER                     NUMBER(6),
    FLOW                        VARCHAR2(20),
    OPER                        VARCHAR2(10),
    LOT_TYPE                    CHAR(1),
    RWK_FLAG                    CHAR(1),
    QTY_1                       NUMBER(10,3),
    QTY_2                       NUMBER(10,3),
    QTY_3                       NUMBER(10,3),
    RES_SEQ                     NUMBER(10),
    SUBRES_ID                   VARCHAR2(20),
    PORT_ID                     VARCHAR2(10),
    CRR_ID                      VARCHAR2(20)
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RRASRESLTH
ADD CONSTRAINT RRASRESLTH_PK PRIMARY KEY
(
    FACTORY, 
    RES_ID, 
    RES_HIST_SEQ, 
    LOT_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;

INSERT INTO RRASRESLTH VALUE ( 
SELECT 
    FACTORY             ,
    RES_ID              ,
    RES_HIST_SEQ        ,
    LOT_ID              ,
    RES_HIST_DEL_FLAG   ,
    EVENT_ID            ,
    TRAN_TIME           ,
    LOT_HIST_SEQ        ,
    LOT_HIST_DEL_FLAG   ,
    MAT_ID              ,
    MAT_VER             ,
    FLOW                ,
    OPER                ,
    LOT_TYPE            ,
    RWK_FLAG            ,
    QTY_1               ,
    QTY_2               ,
    QTY_3               ,
    0                   ,
    ' '                 ,
    ' '                 ,
    ' '           
FROM RRASRESLTH_OLD);
