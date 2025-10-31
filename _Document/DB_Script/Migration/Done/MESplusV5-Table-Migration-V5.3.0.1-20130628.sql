/*
**
**  File Name    : MESplusV5-Table-Migration_Table.sql
**  Description  : MESplus V5 Release for Table Migration
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g / 11g
**
**  Period       : 2013.03.13 ~ ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
**  1. 2013.05.27   IC Bae   Create
*/


ALTER TABLE MALMMSGDEF ADD ALARM_CMF_1          VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_CMF_2          VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_CMF_3          VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_CMF_4          VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_CMF_5          VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_CMF_6          VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_CMF_7          VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_CMF_8          VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_CMF_9          VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_CMF_10         VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_CMF_11         VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_CMF_12         VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_CMF_13         VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_CMF_14         VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_CMF_15         VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_CMF_16         VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_CMF_17         VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_CMF_18         VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_CMF_19         VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_CMF_20         VARCHAR2(30)       DEFAULT(' ')    NOT NULL;

ALTER TABLE MALMMSGDEF ADD ALARM_GRP_1          VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_GRP_2          VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_GRP_3          VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_GRP_4          VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_GRP_5          VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_GRP_6          VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_GRP_7          VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_GRP_8          VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_GRP_9          VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MALMMSGDEF ADD ALARM_GRP_10         VARCHAR2(30)       DEFAULT(' ')    NOT NULL;

COMMENT ON COLUMN MALMMSGDEF.ALARM_CMF_1                                    IS 'Alarm Customized item 1';
COMMENT ON COLUMN MALMMSGDEF.ALARM_CMF_2                                    IS 'Alarm Customized item 2';
COMMENT ON COLUMN MALMMSGDEF.ALARM_CMF_3                                    IS 'Alarm Customized item 3';
COMMENT ON COLUMN MALMMSGDEF.ALARM_CMF_4                                    IS 'Alarm Customized item 4';
COMMENT ON COLUMN MALMMSGDEF.ALARM_CMF_5                                    IS 'Alarm Customized item 5';
COMMENT ON COLUMN MALMMSGDEF.ALARM_CMF_6                                    IS 'Alarm Customized item 6';
COMMENT ON COLUMN MALMMSGDEF.ALARM_CMF_7                                    IS 'Alarm Customized item 7';
COMMENT ON COLUMN MALMMSGDEF.ALARM_CMF_8                                    IS 'Alarm Customized item 8';
COMMENT ON COLUMN MALMMSGDEF.ALARM_CMF_9                                    IS 'Alarm Customized item 9';
COMMENT ON COLUMN MALMMSGDEF.ALARM_CMF_10                                   IS 'Alarm Customized item 10';
COMMENT ON COLUMN MALMMSGDEF.ALARM_CMF_11                                   IS 'Alarm Customized item 11';
COMMENT ON COLUMN MALMMSGDEF.ALARM_CMF_12                                   IS 'Alarm Customized item 12';
COMMENT ON COLUMN MALMMSGDEF.ALARM_CMF_13                                   IS 'Alarm Customized item 13';
COMMENT ON COLUMN MALMMSGDEF.ALARM_CMF_14                                   IS 'Alarm Customized item 14';
COMMENT ON COLUMN MALMMSGDEF.ALARM_CMF_15                                   IS 'Alarm Customized item 15';
COMMENT ON COLUMN MALMMSGDEF.ALARM_CMF_16                                   IS 'Alarm Customized item 16';
COMMENT ON COLUMN MALMMSGDEF.ALARM_CMF_17                                   IS 'Alarm Customized item 17';
COMMENT ON COLUMN MALMMSGDEF.ALARM_CMF_18                                   IS 'Alarm Customized item 18';
COMMENT ON COLUMN MALMMSGDEF.ALARM_CMF_19                                   IS 'Alarm Customized item 19';
COMMENT ON COLUMN MALMMSGDEF.ALARM_CMF_20                                   IS 'Alarm Customized item 20';

COMMENT ON COLUMN MALMMSGDEF.ALARM_GRP_1                                    IS 'Alarm Group item 1';
COMMENT ON COLUMN MALMMSGDEF.ALARM_GRP_2                                    IS 'Alarm Group item 2';
COMMENT ON COLUMN MALMMSGDEF.ALARM_GRP_3                                    IS 'Alarm Group item 3';
COMMENT ON COLUMN MALMMSGDEF.ALARM_GRP_4                                    IS 'Alarm Group item 4';
COMMENT ON COLUMN MALMMSGDEF.ALARM_GRP_5                                    IS 'Alarm Group item 5';
COMMENT ON COLUMN MALMMSGDEF.ALARM_GRP_6                                    IS 'Alarm Group item 6';
COMMENT ON COLUMN MALMMSGDEF.ALARM_GRP_7                                    IS 'Alarm Group item 7';
COMMENT ON COLUMN MALMMSGDEF.ALARM_GRP_8                                    IS 'Alarm Group item 8';
COMMENT ON COLUMN MALMMSGDEF.ALARM_GRP_9                                    IS 'Alarm Group item 9';
COMMENT ON COLUMN MALMMSGDEF.ALARM_GRP_10                                   IS 'Alarm Group item 10';

COMMENT ON COLUMN MSPCSPEHIS.WB_SIGMA_FLAG                  IS 'Indication of  sigma( Within / Between)';
