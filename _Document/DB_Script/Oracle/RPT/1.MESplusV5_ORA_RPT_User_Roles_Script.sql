/*
**
**  File Name    : MESplusV5_ORA_RPT_User_Roles_Script.sql
**  Description  : MES Database Creation User & Role Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10
**
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
*/
PROMPT ##### CREATE USER #####

create user rptapp identified by rptapp 
 default tablespace users temporary tablespace temp;
 
create user rptmgr identified by rptmgr
 default tablespace users temporary tablespace temp;
 
 
PROMPT ##### CREATE ROLE and GRANT ROLE #####

create role mp_role_ro;
create role mp_role_rw;
create role mp_role_dba;
grant create session,select any table to mp_role_ro;

grant 
--create trigger, resource, create session, create sequence, create procedure,
--create database link, create view, create materialized view, query rewrite,
--create table, create synonym, 
create trigger, resource, create session,
create sequence, create procedure, create database link, create view,
create materialized view, query rewrite, create table, create synonym,
select any table,insert any table,update any table,
delete any table, lock any table  to mp_role_rw;
 
grant connect,resource,dba  to mp_role_dba;
grant mp_role_rw to rptapp;
grant mp_role_dba to rptmgr;
grant connect,resource,dba to rptmgr;
grant create any table, create any index, drop any table to rptmgr;


grant	CREATE TRIGGER           to rptapp;
grant	RESOURCE                 to rptapp;
grant	CREATE SESSION           to rptapp;
grant	CREATE SEQUENCE          to rptapp;
grant	CREATE PROCEDURE         to rptapp;
grant	CREATE DATABASE LINK     to rptapp;
grant	CREATE VIEW              to rptapp;
grant	CREATE MATERIALIZED VIEW to rptapp;
grant	QUERY REWRITE            to rptapp;
grant	CREATE TABLE             to rptapp;
grant	CREATE SYNONYM           to rptapp;
grant	CREATE TRIGGER           to rptapp;
grant	RESOURCE                 to rptapp;
grant	CREATE SESSION           to rptapp;
grant	CREATE SEQUENCE          to rptapp;
grant	CREATE PROCEDURE         to rptapp;
grant	CREATE DATABASE LINK     to rptapp;
grant	CREATE VIEW              to rptapp;
grant	CREATE MATERIALIZED VIEW to rptapp;
grant	QUERY REWRITE            to rptapp;
grant	CREATE TABLE             to rptapp;
grant	CREATE SYNONYM           to rptapp;

