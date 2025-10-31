/*
**
**  File Name    : MESplusV5-Table-Migration.sql
**  Description  : MESplus V5 Release Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g / 11g
**
**  Period       : 2011.06.27 ~ 2011.08.12
**  Release Date : 2011.08.12
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
*/

/* add by J.S. 2011.08.04 */
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD-0024', 'RTD', 'RTD-0024 : This event sequence value already exist. Please check oracle sequence.', 'RTD-0024 : 이벤트 시퀀스가 이미 존재합니다. 오라클 시퀀스를 확인하세요.', 'RTD-0024 :RTD-0017 : Der ORACLE SEQUENCE existiert bereits', 'ADMIN', '20081219094711', ' ', ' ');
/* end */