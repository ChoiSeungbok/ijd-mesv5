/*
**
**  File Name    : MESplusV5-Table-Migration_Table.sql
**  Description  : MESplus V5 Release for Table Migration
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g / 11g
**
**  Period       : 2015.10.30 ~ ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
**  1. 2015.10.30   Aiden   Create
*/


/* Added By YJJung 160217 For The Rule Extended information of Chart */

CREATE TABLE MSPCRULEXT
(
    FACTORY                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHART_ID                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_11                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_12                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_13                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_14                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_15                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_16                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_17                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_18                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_19                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_20                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_11                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_12                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_13                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_14                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_15                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_16                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_17                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_18                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_19                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_20                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSPCRULEXT
ADD CONSTRAINT MSPCRULEXT_PK PRIMARY KEY
(
    FACTORY,
    CHART_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;



/* Added By YJJung 160217 For The Rule Extended History of OOC */
/* MSPCOOCEXT : OOC History (extended) */
CREATE TABLE MSPCOOCEXT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHART_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    X_OOC_MSG_1                 VARCHAR2(100)     DEFAULT(' ')    NOT NULL,
    X_OOC_MSG_2                 VARCHAR2(100)     DEFAULT(' ')    NOT NULL,
    X_OOC_MSG_3                 VARCHAR2(100)     DEFAULT(' ')    NOT NULL,
    R_OOC_MSG_1                 VARCHAR2(100)     DEFAULT(' ')    NOT NULL,
    R_OOC_MSG_2                 VARCHAR2(100)     DEFAULT(' ')    NOT NULL,
    R_OOC_MSG_3                 VARCHAR2(100)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MSPCOOCEXT
ADD CONSTRAINT MSPCOOCEXT_PK PRIMARY KEY
(
    FACTORY,
    CHART_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

