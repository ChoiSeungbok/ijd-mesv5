/*
**
**  File Name    : MESplusV5-Table-Migration-20081231.sql
**  Description  : MESplus V5 Release Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g
**
**  Period       : 2008.12.16 ~ ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
**
**  Revision History
**  Seq   Date        Modifier      Description                        
**  ---------------------------------------------------------------------------
**  1     2008.12.16  HyunJong         Make file
**  2     2008.12.16  HyunJong         Add ARRAY_TYPE column to MSVMSVCMBR, MSVMMBRDEF
**  3     2008.12.18  HyunJong         Add MSG
**    
*/


/* MSVMSVCMBR 에 ARRAY_TYPE 컬럼 추가 */

RENAME MSVMSVCMBR TO MSVMSVCMBR_OLD;

CREATE TABLE MSVMSVCMBR
(
  MODULE_NAME                  VARCHAR2(30)      DEFAULT (' ')    NOT NULL,
  SERVICE_NAME                 VARCHAR2(100)     DEFAULT (' ')    NOT NULL,
  DIRECTION                    CHAR(1)           DEFAULT (' ')    NOT NULL,
  MEMBER_DEPTH                 NUMBER(6)         DEFAULT (0)      NOT NULL,
  MEMBER_NAME                  VARCHAR2(50)      DEFAULT (' ')    NOT NULL,
  MEMBER_SEQ                   NUMBER(6)         DEFAULT (0)      NOT NULL,
  MEMBER_DESC_1                VARCHAR2(1000)    DEFAULT (' ')    NOT NULL,
  MEMBER_DESC_2                VARCHAR2(1000)    DEFAULT (' ')    NOT NULL,
  MEMBER_DESC_3                VARCHAR2(1000)    DEFAULT (' ')    NOT NULL,
  MEMBER_TYPE                  VARCHAR2(10)      DEFAULT (' ')    NOT NULL,
  MEMBER_SIZE                  NUMBER(6)         DEFAULT (0)      NOT NULL,
  MEMBER_PRT                   VARCHAR2(50)      DEFAULT (' ')    NOT NULL,
  ARRAY_TYPE                  VARCHAR2(10)      DEFAULT (' ')    NOT NULL,
  REQ_MEMBER_FLAG              CHAR(1)           DEFAULT (' ')    NOT NULL,
  PARENT_MEMBER_NAME           VARCHAR2(50)      DEFAULT (' ')    NOT NULL,
  OVERRIDE_FLAG                CHAR(1)           DEFAULT (' ')    NOT NULL,
  USE_RANGE_FLAG               CHAR(1)           DEFAULT (' ')    NOT NULL,
  RANGE_MIN                    NUMBER(22,4)      DEFAULT (0)      NOT NULL,
  RANGE_MAX                    NUMBER(22,4)      DEFAULT (0)      NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

INSERT INTO MSVMSVCMBR VALUE (
SELECT 
	MODULE_NAME           ,
	SERVICE_NAME          ,
	DIRECTION             ,
	MEMBER_DEPTH          ,
	MEMBER_NAME           ,
	MEMBER_SEQ            ,
	MEMBER_DESC_1         ,
	MEMBER_DESC_2         ,
	MEMBER_DESC_3         ,
	MEMBER_TYPE           ,
	MEMBER_SIZE           ,
	MEMBER_PRT            ,
                ' '            ,
	REQ_MEMBER_FLAG       ,
	PARENT_MEMBER_NAME    ,
	OVERRIDE_FLAG         ,
	USE_RANGE_FLAG        ,
	RANGE_MIN             ,
	RANGE_MAX             ,
	CREATE_USER_ID,
	CREATE_TIME,
	UPDATE_USER_ID,
	UPDATE_TIME
FROM MSVMSVCMBR_OLD
);

DROP TABLE MSVMSVCMBR_OLD CASCADE CONSTRAINT PURGE;

ALTER TABLE MSVMSVCMBR 
ADD CONSTRAINT MSVMSVCMBR_PK PRIMARY KEY
(
  MODULE_NAME, 
  SERVICE_NAME, 
  DIRECTION, 
  MEMBER_DEPTH, 
  MEMBER_NAME,
  PARENT_MEMBER_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSVMMBRDEF 에 ARRAY_TYPE 컬럼 추가 */
RENAME MSVMMBRDEF TO MSVMMBRDEF_OLD;

CREATE TABLE MSVMMBRDEF
(
  MEMBER_NAME                   VARCHAR2(50)     DEFAULT (' ')    NOT NULL,
  MEMBER_DESC_1                 VARCHAR2(1000)   DEFAULT (' ')    NOT NULL,
  MEMBER_DESC_2                 VARCHAR2(1000)   DEFAULT (' ')    NOT NULL,
  MEMBER_DESC_3                 VARCHAR2(1000)   DEFAULT (' ')    NOT NULL,
  MEMBER_TYPE                   VARCHAR2(10)     DEFAULT (' ')    NOT NULL,
  MEMBER_SIZE                   NUMBER(6)        DEFAULT (0)      NOT NULL,
  ARRAY_TYPE                  VARCHAR2(10)      DEFAULT (' ')    NOT NULL,
  USE_RANGE_FLAG                CHAR(1)          DEFAULT (' ')    NOT NULL,
  RANGE_MIN                     NUMBER(22,4)     DEFAULT (0)      NOT NULL,
  RANGE_MAX                     NUMBER(22,4)     DEFAULT (0)      NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

INSERT INTO MSVMMBRDEF VALUE (
SELECT 
	MEMBER_NAME    ,
	MEMBER_DESC_1  ,
	MEMBER_DESC_2  ,
	MEMBER_DESC_3  ,
	MEMBER_TYPE    ,
	MEMBER_SIZE    ,
	' '    ,
	USE_RANGE_FLAG ,
	RANGE_MIN      ,
	RANGE_MAX      ,
	CREATE_USER_ID,
	CREATE_TIME,
	UPDATE_USER_ID,
	UPDATE_TIME
FROM MSVMMBRDEF_OLD
);

DROP TABLE MSVMMBRDEF_OLD CASCADE CONSTRAINT PURGE;

ALTER TABLE MSVMMBRDEF 
ADD CONSTRAINT MSVMMBRDEF_PK PRIMARY KEY
(
  MEMBER_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* SVM-0009 메시지 추가 */
Insert into MESMGR.MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM-0009', 'SVM', 'SVM-0009 : This member is used by some services. Can not delete', 'SVM-0009 : 이 멤버는 일부 서비스가 사용하고 있습니다. 삭제할 수 없습니다.', ' ', 'ADMIN', '20081218150208', ' ', ' ');
