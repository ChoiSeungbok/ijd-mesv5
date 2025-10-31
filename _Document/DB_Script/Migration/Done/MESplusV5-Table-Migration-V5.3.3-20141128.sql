/*
**
**  File Name    : MESplusV5-Table-Migration_Table.sql
**  Description  : MESplus V5 Release for Table Migration
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g / 11g
**
**  Period       : 2014.07.25 ~ ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
**  1. 2014.07.25   Aiden   Create
*/

CREATE INDEX MSPCCALDAT_IDX_1 ON MSPCCALDAT
(
    FACTORY,
    CHART_ID,
    LOT_ID
) TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MSPCCALDAT_IDX_2 ON MSPCCALDAT
(
    FACTORY,
    CHART_ID,
    EDC_HIST_SEQ,
    RES_ID,
    SUBRES_ID
) TABLESPACE HISTORY_IDX_TS;

