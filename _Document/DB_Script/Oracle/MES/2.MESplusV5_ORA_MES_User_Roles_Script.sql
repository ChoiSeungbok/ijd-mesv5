/*
**
**  File Name    : MESplusV5_ORA_MES_User_Roles_Script.sql
**  Description  : MES Database User Roles Creation SQL Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10
**
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
*/

PROMPT ##### CREATE USER #####

alter session set "_ORACLE_SCRIPT"=true;

create user mesmgr identified by mesmgr
  default tablespace MESPLUS_DATA_TS temporary tablespace temp;


PROMPT ##### CREATE ROLE and GRANT ROLE #####

create role mp_role_ro;
create role mp_role_rw;
create role mp_role_dba;
grant create session,select any table to mp_role_ro;
grant create session,select any table,insert any table,update any table,
 delete any table, lock any table  to mp_role_rw;
grant connect,resource,dba  to mp_role_dba;
grant mp_role_dba to mesmgr;
grant connect,resource,dba to mesmgr;
grant create any table, create any index, drop any table to mesmgr;

