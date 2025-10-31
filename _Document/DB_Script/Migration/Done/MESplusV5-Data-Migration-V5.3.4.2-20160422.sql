/*
**
**  File Name    : MESplusV5-Table-Migration_Data.sql
**  Description  : MESplus V5 Release for Data Migration
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

/* MP_ChangePortStateWithLotTran */
Insert into MBASGLBPMT (OPTION_NAME,OPTION_DESC,MESPLUS_FLAG,VALUE_PMT_1,VALUE_PMT_2,VALUE_PMT_3,VALUE_PMT_4,VALUE_PMT_5,VALUE_FMT_1,VALUE_FMT_2,VALUE_FMT_3,VALUE_FMT_4,VALUE_FMT_5,VALUE_TBL_1,VALUE_TBL_2,VALUE_TBL_3,VALUE_TBL_4,VALUE_TBL_5,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME)
values ('MP_ChangePortStateWithLotTran','Change port state with lot transaction','Y','Yes or No',' ',' ',' ',' ','A',' ',' ',' ',' ','YESNO',' ',' ',' ',' ','ADMIN','20160405124712',' ',' ');
Insert into MBASGLBDEF (FACTORY,OPTION_NAME,OPTION_DESC,VALUE_1,VALUE_2,VALUE_3,VALUE_4,VALUE_5,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME)
values ('SYSTEM','MP_ChangePortStateWithLotTran','Change port state with lot transaction','N',' ',' ',' ',' ','ADMIN','20160405130002',' ',' ');


