/*
**
**  File Name    : MESplusV5-Table-Migration_Table.sql
**  Description  : MESplus V5 Release for Table Migration
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g / 11g
**
**  Period       : 2016.04.25 ~ ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
**  1. 2016.04.22   Aiden   Create
*/


/* Create Table : Label Design Extension Table */
CREATE TABLE MPOPLBLDEX
(
    FACTORY                             VARCHAR2(10)        DEFAULT(' ')        NOT NULL,
    LABEL_ID                            VARCHAR2(25)        DEFAULT(' ')        NOT NULL,
    SEQ_NUM                             NUMBER(6)           DEFAULT(0)          NOT NULL,
    DGN_CMF_1                           VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_2                           VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_3                           VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_4                           VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_5                           VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_6                           VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_7                           VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_8                           VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_9                           VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_10                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_11                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_12                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_13                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_14                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_15                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_16                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_17                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_18                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_19                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_20                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_21                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_22                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_23                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_24                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_25                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_26                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_27                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_28                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_29                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_30                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

/* Create Primary Key of MPOPLBLDEX */
ALTER TABLE MPOPLBLDEX
ADD CONSTRAINT MPOPLBLDEX_PK PRIMARY KEY
(
    FACTORY,
    LABEL_ID,
    SEQ_NUM
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* Input Table Comment of MPOPLBLDEX */
COMMENT ON TABLE MPOPLBLDEX                                 IS 'Label Design Extension Table';

COMMENT ON COLUMN MPOPLBLDEX.FACTORY                        IS 'Factory';
COMMENT ON COLUMN MPOPLBLDEX.LABEL_ID                       IS 'The name of label';
COMMENT ON COLUMN MPOPLBLDEX.SEQ_NUM                        IS 'Serial number';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_1                      IS 'User Cmf 1';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_2                      IS 'User Cmf 2';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_3                      IS 'User Cmf 3';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_4                      IS 'User Cmf 4';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_5                      IS 'User Cmf 5';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_6                      IS 'User Cmf 6';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_7                      IS 'User Cmf 7';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_8                      IS 'User Cmf 8';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_9                      IS 'User Cmf 9';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_10                     IS 'User Cmf 10';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_11                     IS 'User Cmf 11';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_12                     IS 'User Cmf 12';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_13                     IS 'User Cmf 13';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_14                     IS 'User Cmf 14';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_15                     IS 'User Cmf 15';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_16                     IS 'User Cmf 16';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_17                     IS 'User Cmf 17';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_18                     IS 'User Cmf 18';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_19                     IS 'User Cmf 19';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_20                     IS 'User Cmf 20';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_21                     IS 'User Cmf 21';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_22                     IS 'User Cmf 22';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_23                     IS 'User Cmf 23';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_24                     IS 'User Cmf 24';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_25                     IS 'User Cmf 25';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_26                     IS 'User Cmf 26';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_27                     IS 'User Cmf 27';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_28                     IS 'User Cmf 28';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_29                     IS 'User Cmf 29';
COMMENT ON COLUMN MPOPLBLDEX.DGN_CMF_30                     IS 'User Cmf 30';
