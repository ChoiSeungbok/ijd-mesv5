/*
**
**  File Name    : MESplusV5_ORA_MES_Tablespace_Script.sql
**  Description  : MES Database Tablespace Creation SQL Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10
**
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
*/

/* 1.MESPLUS_DATA_TS */
CREATE TABLESPACE MESPLUS_DATA_TS DATAFILE
    'C:\oracle\oradata\MESDB\mesplus_data.dbf' SIZE 50M AUTOEXTEND ON;

/* 2.MESPLUS_IDX_TS */
CREATE TABLESPACE MESPLUS_IDX_TS DATAFILE
    'C:\oracle\oradata\MESDB\mesplus_idx.dbf' SIZE 25M AUTOEXTEND ON;

/* 3.HISTORY_DATA_TS */
CREATE TABLESPACE HISTORY_DATA_TS DATAFILE
    'C:\oracle\oradata\MESDB\history_data.dbf' SIZE 50M AUTOEXTEND ON;

/* 4.HISTORY_IDX_TS */
CREATE TABLESPACE HISTORY_IDX_TS DATAFILE
    'C:\oracle\oradata\MESDB\history_idx.dbf' SIZE 25M AUTOEXTEND ON;

/* 5.REPORT_DATA_TS */
CREATE TABLESPACE REPORT_DATA_TS DATAFILE
    'C:\oracle\oradata\MESDB\report_data.dbf' SIZE 50M AUTOEXTEND ON;

/* 6.REPORT_IDX_TS */
CREATE TABLESPACE REPORT_IDX_TS DATAFILE
    'C:\oracle\oradata\MESDB\report_idx.dbf' SIZE 25M AUTOEXTEND ON;
