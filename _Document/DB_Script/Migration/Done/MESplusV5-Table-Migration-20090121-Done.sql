/*
**
**  File Name    : MESplusV5-Table-Migration.sql
**  Description  : MESplus V5 Release Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g
**
**  Period       : 2009.01.01 ~ ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
**
**  Revision History
**  Seq   Date        Modifier      Description                        
**  ---------------------------------------------------------------------------
**  1     2009.01.02  Aiden         Make file
**  2     2009.01.13  J.S. Jung     For RTD
**  3     2009.01.19  Aiden  		Modify MSVMSVCDEF
**  4     2009.01.20  Aiden  		Add Stop_Process service
   
*/

RENAME MWIPBATRUL TO MWIPBATRUL_OLD;

/*MWIPBATRUL - Creation Batch Rule */
CREATE TABLE MWIPBATRUL
(
	FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CRT_RULE_ID                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_RULE_DESC               VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    GEN_RULE_ID                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OVERRIDE_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    BATCH_TYPE                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    MIX_LOT_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    MIN_QTIME                   NUMBER(6)        DEFAULT(0)      NOT NULL,  
    BATCH_COUNT                 VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    UNDER_FLAG                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    MATCH_ITEM                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    NPW_COUNT                   NUMBER(6)        DEFAULT(0)      NOT NULL,  
    NPW_POSITION                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Add 2009.01.25 */
    CUSTOM_RULE                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CUSTOM_RULE_FOR_CHECK       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SEND_LOT_TO_CUSTOM_RULE_FLAG CHAR(1)         DEFAULT(' ')    NOT NULL,
    MAX_SEND_LOT_COUNT          NUMBER(6)        DEFAULT(0)      NOT NULL,  
	
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;



INSERT INTO MWIPBATRUL VALUE (
SELECT 
	FACTORY                     ,
    CRT_RULE_ID                 ,
    CRT_RULE_DESC               ,
    GEN_RULE_ID                 ,
    OVERRIDE_FLAG               ,
    BATCH_TYPE                  ,
    MIX_LOT_FLAG                ,
    MIN_QTIME                   ,  
    BATCH_COUNT                 ,
    UNDER_FLAG                  ,
    MATCH_ITEM                  ,
    NPW_COUNT                   ,  
    NPW_POSITION                ,
    ' ',
    ' ',
    ' ',
    0  ,  
    CREATE_USER_ID              ,
    CREATE_TIME                 ,
    UPDATE_USER_ID              ,
    UPDATE_TIME                 
	FROM MWIPBATRUL_OLD
);

DROP TABLE MWIPBATRUL_OLD CASCADE CONSTRAINT PURGE;

ALTER TABLE MWIPBATRUL 
ADD CONSTRAINT MWIPBATRUL_PK PRIMARY KEY
(
    FACTORY,
    CRT_RULE_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;








RENAME MRTDRULITM TO MRTDRULITM_OLD;

/* MRTDRULITM : Rule-Item Definition Table */
CREATE TABLE MRTDRULITM
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')      NOT NULL,
    RULE_ID                     VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    RULE_TYPE                   CHAR(1)          DEFAULT(' ')      NOT NULL,
    PRIO_LEVEL                  NUMBER(6)        DEFAULT(0)        NOT NULL,
    PRIO_KEY                    VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    SORTING_TYPE                CHAR(1)          DEFAULT(' ')      NOT NULL,
    CLASS_TYPE                  CHAR(1)          DEFAULT(' ')      NOT NULL,
    KEY_VALUE_1                 VARCHAR2(100)    DEFAULT(' ')      NOT NULL,
    KEY_VALUE_2                 VARCHAR2(100)    DEFAULT(' ')      NOT NULL,
    KEY_POINT                   NUMBER(6)        DEFAULT(0)        NOT NULL,
    LOT_TYPE                    CHAR(1)          DEFAULT(' ')      NOT NULL,
    UNSELECT_FLAG               CHAR(1)          DEFAULT(' ')      NOT NULL,
	/* Add 2009.01.25 */
    CAPABLE_FLAG                CHAR(1)          DEFAULT(' ')      NOT NULL,

    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')      NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')      NOT NULL
)
TABLESPACE MESPLUS_DATA_TS;

INSERT INTO MRTDRULITM VALUE (
SELECT 
    FACTORY                     ,
    RULE_ID                     ,
    RULE_TYPE                   ,
    PRIO_LEVEL                  ,
    PRIO_KEY                    ,
    SORTING_TYPE                ,
    CLASS_TYPE                  ,
    KEY_VALUE_1                 ,
    KEY_VALUE_2                 ,
    KEY_POINT                   ,
    LOT_TYPE                    ,
    UNSELECT_FLAG               ,
    ' ' ,
    CREATE_USER_ID              ,
    CREATE_TIME                 ,
    UPDATE_USER_ID              ,
    UPDATE_TIME                 
	FROM MRTDRULITM_OLD
);

DROP TABLE MRTDRULITM_OLD CASCADE CONSTRAINT PURGE;

ALTER TABLE MRTDRULITM
ADD CONSTRAINT MRTDRULITM_PK PRIMARY KEY
(
    FACTORY,
    RULE_ID,
    RULE_TYPE,
    PRIO_LEVEL,
    PRIO_KEY,
    KEY_VALUE_1,
    KEY_VALUE_2
) USING INDEX TABLESPACE MESPLUS_IDX_TS;  






RENAME MRTDLOTPDS TO MRTDLOTPDS_OLD;

/* MRTDLOTPDS : Lot Pre_Dispatched Status Table */
CREATE TABLE MRTDLOTPDS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_OPER_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,   
    RES_OPER_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SET_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SET_RESG_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SET_RES_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DSP_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RULE_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TEMP_BATCH_ID               VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
	/* Add 2009.01.25 */
    TEMP_BATCH_SEQ              NUMBER(3)        DEFAULT (0)     NOT NULL,
	
    CUR_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    REFERENCE_OPER              VARCHAR2(10)     DEFAULT(' ')    NOT NULL, /* Add */
    UNSELECTED_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOT_RESV_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOT_RESV_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    CAPABLE_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    PRI_ADJUST_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    PRIORITY_SCORE              VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    PRIORITY_SUPPORT            VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT (0)     NOT NULL,
    PRI_ADJUST_REASON           VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    TRIGGER_BY                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DSP_REASON                  VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    /* Add 2009.01.25 */
    UNSELECT_REASON             VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    CAPABLE_REASON              VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,

    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;


INSERT INTO MRTDLOTPDS VALUE (
SELECT 
    FACTORY                     ,
    RES_OPER_FLAG               ,   
    RES_OPER_ID                 ,
    LOT_ID                      ,
    SET_OPER                    ,
    SET_RESG_ID                 ,
    SET_RES_ID                  ,
    DSP_ID                      ,
    RULE_ID                     ,
    TEMP_BATCH_ID               ,
    0,                          
    CUR_OPER                    ,
    REFERENCE_OPER              , 
    UNSELECTED_FLAG             ,
    LOT_RESV_FLAG               ,
    LOT_RESV_TIME               ,
    CAPABLE_FLAG                ,
    PRI_ADJUST_FLAG             ,
    PRIORITY_SCORE              ,
    PRIORITY_SUPPORT            ,
    HIST_SEQ                    ,
    PRI_ADJUST_REASON           ,
    TRIGGER_BY                  ,
    DSP_REASON                  ,
    ' ',
    ' ',
    CREATE_USER_ID              ,
    CREATE_TIME                 ,
    UPDATE_USER_ID              ,
    UPDATE_TIME                 
	FROM MRTDLOTPDS_OLD
);

DROP TABLE MRTDLOTPDS_OLD CASCADE CONSTRAINT PURGE;

ALTER TABLE MRTDLOTPDS
ADD CONSTRAINT MRTDLOTPDS_PK PRIMARY KEY
(
    FACTORY,
    RES_OPER_FLAG,
    RES_OPER_ID,
    LOT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

CREATE INDEX MRTDLOTPDS_IDX_1 ON MRTDLOTPDS
(
    LOT_ID
) TABLESPACE MESPLUS_IDX_TS;










RENAME MRTDLOTPDH TO MRTDLOTPDH_OLD;

/* MRTDLOTPDH : Lot Pre_Dispatched History Table */
CREATE TABLE MRTDLOTPDH
(
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_OPER_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,   
    RES_OPER_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SET_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SET_RESG_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SET_RES_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DSP_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RULE_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TEMP_BATCH_ID               VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
	/* Add 2009.01.25 */
    TEMP_BATCH_SEQ              NUMBER(3)        DEFAULT (0)     NOT NULL,

    CUR_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    REFERENCE_OPER              VARCHAR2(10)     DEFAULT(' ')    NOT NULL, /* Add */
    UNSELECTED_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOT_RESV_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOT_RESV_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    CAPABLE_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    PRI_ADJUST_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    PRIORITY_SCORE              VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    PRIORITY_SUPPORT            VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT (0)     NOT NULL,
    PRI_ADJUST_REASON           VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    TRIGGER_BY                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DSP_REASON                  VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    /* Add 2009.01.25 */
    UNSELECT_REASON             VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    CAPABLE_REASON              VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,

    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

INSERT INTO MRTDLOTPDH VALUE (
SELECT 
    TRAN_TIME                   ,
    FACTORY                     ,
    RES_OPER_FLAG               ,   
    RES_OPER_ID                 ,
    LOT_ID                      ,
    SET_OPER                    ,
    SET_RESG_ID                 ,
    SET_RES_ID                  ,
    DSP_ID                      ,
    RULE_ID                     ,
    TEMP_BATCH_ID               ,
    0,
    CUR_OPER                    ,
    REFERENCE_OPER              , 
    UNSELECTED_FLAG             ,
    LOT_RESV_FLAG               ,
    LOT_RESV_TIME               ,
    CAPABLE_FLAG                ,
    PRI_ADJUST_FLAG             ,
    PRIORITY_SCORE              ,
    PRIORITY_SUPPORT            ,
    HIST_SEQ                    ,
    PRI_ADJUST_REASON           ,
    TRIGGER_BY                  ,
    DSP_REASON                  ,
    ' ',
    ' ',
    CREATE_USER_ID              ,
    CREATE_TIME                 ,
    UPDATE_USER_ID              ,
    UPDATE_TIME                 
	FROM MRTDLOTPDH_OLD
);

DROP TABLE MRTDLOTPDH_OLD CASCADE CONSTRAINT PURGE;

ALTER TABLE MRTDLOTPDH
ADD CONSTRAINT MRTDLOTPDH_PK PRIMARY KEY
(
    FACTORY,
    TRAN_TIME,
    RES_OPER_FLAG,
    RES_OPER_ID,
    LOT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

CREATE INDEX MRTDLOTPDH_IDX_1 ON MRTDLOTPDH
(
    FACTORY,
    TRAN_TIME
) TABLESPACE MESPLUS_IDX_TS;









RENAME MRTDEVNCON TO MRTDEVNCON_OLD;

/* MRTDEVNCON : Dispatch Event Configuration Table */
CREATE TABLE MRTDEVNCON
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SERVICE_NAME                VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    SERVICE_SEQ                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    SERVICE_DESC                VARCHAR2(50)     DEFAULT(' ')    NOT NULL,    
    CHK_MEMBER                  VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* CHECK 방법 '=': ALLOW '!':REJECT 'N'=NOT CHECK '>':크거나   '<' : 같거나 T : UPT Table Check S : SQL */
    CHK_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_STS                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_TBL                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHK_SQL                     VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* 1이상일 경우 다른 항목의 종속 조건 이고 ACTION부분 사용하지 않음. */
    DEPENDENT_SEQ               NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* AND, OR 등의 조건으로 연결된다 */
    DEPENDENT_COMBINATION       VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    ACTION_ARRAY_1              VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    ACTION_ARRAY_2              VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    ACTION_MEMBER_1             VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    ACTION_MEMBER_2             VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    ACTION_MEMBER_3             VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    ACTION_MEMBER_4             VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* LOT(L), RESOURCE(R), RESOURCE_GROUP(G), OPER(O), Material(M), Flow(F), MFO(1), FO(2), MO(3) */
    ACTION_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CUSTOM_ACTION_KEY           VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
	/* Add 2009.01.15 */
    UNSELECT_CAPABLE_ONLY_FLAG  CHAR(1)          DEFAULT(' ')    NOT NULL,
		
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

INSERT INTO MRTDEVNCON VALUE (
SELECT 
    FACTORY                     ,
    SERVICE_NAME                ,
    SERVICE_SEQ                 ,
    SERVICE_DESC                ,    
    CHK_MEMBER                  ,
    CHK_FLAG                    ,
    CHK_STS                     ,
    CHK_TBL                     ,
    CHK_SQL                     ,
    DEPENDENT_SEQ               ,
    DEPENDENT_COMBINATION       ,
    ACTION_ARRAY_1              ,
    ACTION_ARRAY_2              ,
    ACTION_MEMBER_1             ,
    ACTION_MEMBER_2             ,
    ACTION_MEMBER_3             ,
    ACTION_MEMBER_4             ,
    ACTION_FLAG                 ,
    CUSTOM_ACTION_KEY           ,
    ' ',
    CREATE_USER_ID              ,
    CREATE_TIME                 ,
    UPDATE_USER_ID              ,
    UPDATE_TIME                 
	FROM MRTDEVNCON_OLD
);

DROP TABLE MRTDEVNCON_OLD CASCADE CONSTRAINT PURGE;

ALTER TABLE MRTDEVNCON
ADD CONSTRAINT MRTDEVNCON_PK PRIMARY KEY
(
    FACTORY,
    SERVICE_NAME,
    SERVICE_SEQ
) USING INDEX TABLESPACE MESPLUS_IDX_TS;







RENAME MRTDEVNIFS TO MRTDEVNIFS_OLD;

/* MRTDEVNIFS : Dispatch Event Interface Status Table */
CREATE TABLE MRTDEVNIFS
(
    EVENT_SEQ                   NUMBER(10)       DEFAULT(0)      NOT NULL,
    CHANGE_MEMBER               VARCHAR2(50)     DEFAULT(' ')    NOT NULL,    
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    BATCH_ID                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    DSP_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RULE_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RESG_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    ETC_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    ETC_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CUSTOM_ACTION_KEY           VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
	/* Add 2009.01.15 */
    UNSELECT_CAPABLE_ONLY_FLAG  CHAR(1)          DEFAULT(' ')    NOT NULL,

    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;


INSERT INTO MRTDEVNIFS VALUE (
SELECT 
    EVENT_SEQ                   ,
    CHANGE_MEMBER               ,    
    FACTORY                     ,
    LOT_ID                      ,
    BATCH_ID                    ,
    DSP_ID                      ,
    RULE_ID                     ,
    MAT_ID                      ,
    MAT_VER                     ,
    FLOW                        ,
    OPER                        ,
    RESG_ID                     ,
    RES_ID                      ,
    RES_TYPE                    ,
    ETC_TYPE                    ,
    ETC_ID                      ,
    CUSTOM_ACTION_KEY           ,
    ' ',
    CREATE_USER_ID              ,
    CREATE_TIME                 ,
    UPDATE_USER_ID              ,
    UPDATE_TIME                 
	FROM MRTDEVNIFS_OLD
);

DROP TABLE MRTDEVNIFS_OLD CASCADE CONSTRAINT PURGE;

ALTER TABLE MRTDEVNIFS
ADD CONSTRAINT MRTDEVNIFS_PK PRIMARY KEY
(
    EVENT_SEQ
) USING INDEX TABLESPACE MESPLUS_IDX_TS;






RENAME MRTDEVNIFH TO MRTDEVNIFH_OLD;

/* MRTDEVNIFH : Dispatch Event Interface History Table */
CREATE TABLE MRTDEVNIFH
(
    EVENT_SEQ                   NUMBER(10)       DEFAULT(0)      NOT NULL,
    TRAN_CODE                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    CHANGE_MEMBER               VARCHAR2(50)     DEFAULT(' ')    NOT NULL,    
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    BATCH_ID                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    DSP_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RULE_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RESG_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    ETC_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    ETC_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CUSTOM_ACTION_KEY           VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    UNSELECT_CAPABLE_ONLY_FLAG  CHAR(1)          DEFAULT(' ')    NOT NULL,

    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;


INSERT INTO MRTDEVNIFH VALUE (
SELECT 
    EVENT_SEQ                   ,
    TRAN_CODE                   ,
    TRAN_TIME                   ,
    CHANGE_MEMBER               ,    
    FACTORY                     ,
    LOT_ID                      ,
    BATCH_ID                    ,
    DSP_ID                      ,
    RULE_ID                     ,
    MAT_ID                      ,
    MAT_VER                     ,
    FLOW                        ,
    OPER                        ,
    RESG_ID                     ,
    RES_ID                      ,
    RES_TYPE                    ,
    ETC_TYPE                    ,
    ETC_ID                      ,
    CUSTOM_ACTION_KEY           ,
    ' ',
    CREATE_USER_ID              ,
    CREATE_TIME                 ,
    UPDATE_USER_ID              ,
    UPDATE_TIME                  
	FROM MRTDEVNIFH_OLD
);

DROP TABLE MRTDEVNIFH_OLD CASCADE CONSTRAINT PURGE;

ALTER TABLE MRTDEVNIFH
ADD CONSTRAINT MRTDEVNIFH_PK PRIMARY KEY
(
    EVENT_SEQ
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

CREATE INDEX MRTDEVNIFH_IDX_1 ON MRTDEVNIFH
(
    FACTORY,
    TRAN_TIME
) TABLESPACE MESPLUS_IDX_TS;


RENAME MSVMSVCDEF TO MSVMSVCDEF_OLD;

/* MSVMMBRDEF : Service Management Service Definition Table */
CREATE TABLE MSVMSVCDEF
(
    SERVICE_NAME                VARCHAR2(100)    DEFAULT (' ')   NOT NULL,
    MODULE_NAME                 VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
    SERVICE_MODE                VARCHAR2(2)      DEFAULT (' ')   NOT NULL,
    SERVICE_CATEGORY            CHAR(1)          DEFAULT (' ')   NOT NULL,
    SERVICE_DESC_1              VARCHAR2(1000)   DEFAULT (' ')   NOT NULL,
    SERVICE_DESC_2              VARCHAR2(1000)   DEFAULT (' ')   NOT NULL,
    SERVICE_DESC_3              VARCHAR2(1000)   DEFAULT (' ')   NOT NULL,
    SEC_CHK_FLAG                CHAR(1)          DEFAULT (' ')   NOT NULL,
    SHARED_LIB_NAME             VARCHAR2(100)    DEFAULT (' ')   NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

INSERT INTO MSVMSVCDEF VALUE (
SELECT 
    SERVICE_NAME        ,
    MODULE_NAME         ,
    SERVICE_MODE        ,
    SERVICE_CATEGORY    ,
    SERVICE_DESC_1      ,
    SERVICE_DESC_2      ,
    SERVICE_DESC_3      ,
    SEC_CHK_FLAG        ,
    ' '                 ,
    CREATE_USER_ID      ,
    CREATE_TIME         ,
    UPDATE_USER_ID      ,
    UPDATE_TIME
	FROM MSVMSVCDEF_OLD
);

DROP TABLE MSVMSVCDEF_OLD CASCADE CONSTRAINT PURGE;

ALTER TABLE MSVMSVCDEF 
ADD CONSTRAINT MSVMSVCDEF_PK PRIMARY KEY
(
  SERVICE_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

Insert into MSVMSVCDEF
   (SERVICE_NAME, MODULE_NAME, SERVICE_MODE, SERVICE_CATEGORY, SERVICE_DESC_1, SERVICE_DESC_2, SERVICE_DESC_3, SEC_CHK_FLAG, SHARED_LIB_NAME, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('Stop_Process', 'MESplus', 'RN', 'T', 'Stop MESplus processor', ' ', ' ', ' ', ' ', 'ADMIN', '20090120162423', 'ADMIN', '20090120163414');

Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('MESplus', 'Stop_Process', 'I', 0, 'SERVERNAME', 0, 'The server name which stop.', ' ', ' ', 'String', 30, 'Server Name', ' ', 'M', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20090120162942', 'ADMIN', '20090120163415');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('MESplus', 'Stop_Process', 'I', 0, 'SUBNO', 1, 'The process number which will stop', ' ', ' ', 'String', 2, 'SubNo', ' ', 'M', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20090120162942', 'ADMIN', '20090120163415');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('MESplus', 'Stop_Process', 'I', 0, 'MSG', 2, 'Reason message', ' ', ' ', 'String', 100, 'Message', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20090120163415', ' ', ' ');

Insert into MSVMMBRDEF
   (MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, ARRAY_TYPE, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('NEXT_MEMBER_DEPTH', 'Member depth of next query time', ' ', ' ', 'Int', 0, ' ', ' ', 0, 0, 'ADMIN', '20090121221021', ' ', ' ');
Insert into MSVMMBRDEF
   (MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, ARRAY_TYPE, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('KEY_TYPE', 'What kind of key. Client ID or RTD', ' ', ' ', 'String', 10, ' ', ' ', 0, 0, 'ADMIN', '20090121220637', ' ', ' ');

DELETE FROM MSVMSVCDEF WHERE SERVICE_NAME = 'SVM_Update_Default_Function_Version';
DELETE FROM MSVMSVCMBR WHERE SERVICE_NAME = 'SVM_Update_Default_Function_Version';

Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081212104232');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081212104232');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081212104232');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081212104232');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081212104232');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''U'': Modify, ''D'': Delete)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081212132943');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'I', 0, 'PROC_CASE', 6, ' ', ' ', ' ', ' ', 0, 'PROC_CASE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081212104232');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'I', 0, 'KEY_NAME', 7, ' ', ' ', ' ', ' ', 0, 'KEY_NAME', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081212132443', 'ADMIN', '20081216131854');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'I', 0, 'KEY_TYPE', 8, ' ', ' ', ' ', ' ', 0, 'KEY_TYPE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081212132443', 'ADMIN', '20090121220718');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'I', 0, 'LIB_NAME', 9, ' ', ' ', ' ', ' ', 0, 'LIB_NAME', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081212132443', 'ADMIN', '20081216131627');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'I', 0, 'LIB_VER', 10, ' ', ' ', ' ', ' ', 0, 'LIB_VER', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081212132443', 'ADMIN', '20081216131627');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'I', 0, 'SERVICE_NAME', 11, ' ', ' ', ' ', ' ', 0, 'SERVICE_NAME', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081212132443', 'ADMIN', '20081216131627');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'I', 0, 'SERVICE_VER', 12, ' ', ' ', ' ', ' ', 0, 'SERVICE_VER', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081212132443', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'I', 0, 'DATA_1', 13, 'Data value 1', ' ', ' ', 'String', 30, 'DATA_1', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20081212132617', 'ADMIN', '20081212132943');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'I', 0, 'DATA_2', 14, 'Data value 2', ' ', ' ', 'String', 30, 'DATA_2', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20081212132617', 'ADMIN', '20081212132943');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'I', 0, 'DATA_3', 15, 'Data value 3', ' ', ' ', 'String', 30, 'DATA_3', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20081212132617', 'ADMIN', '20081212132943');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'I', 0, 'DATA_4', 16, 'Data value 4', ' ', ' ', 'String', 30, 'DATA_4', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20081212132617', 'ADMIN', '20081212132943');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'I', 0, 'DATA_5', 17, 'Data value 5', ' ', ' ', 'String', 30, 'DATA_5', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20081212132617', 'ADMIN', '20081212132943');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081212104232');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081212104232');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081212104232');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081212104232');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081212104232');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081212104232');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Default_Function_Version', 'O', 0, 'CSTATUS', 6, ' ', ' ', ' ', ' ', 0, 'CSTATUS', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081212104232');

Insert into MSVMSVCDEF
   (SERVICE_NAME, MODULE_NAME, SERVICE_MODE, SERVICE_CATEGORY, SERVICE_DESC_1, SERVICE_DESC_2, SERVICE_DESC_3, SEC_CHK_FLAG, SHARED_LIB_NAME, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM_Update_Default_Function_Version', 'SVM', 'RR', 'S', 'Sets up, version of updates, deletes the default function', ' ', ' ', ' ', ' ', 'ADMIN', '20081210025750', 'ADMIN', '20090121220716');
Insert into MSVMSVCDEF
   (SERVICE_NAME, MODULE_NAME, SERVICE_MODE, SERVICE_CATEGORY, SERVICE_DESC_1, SERVICE_DESC_2, SERVICE_DESC_3, SEC_CHK_FLAG, SHARED_LIB_NAME, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM_Update_Service_User_Routine_List', 'SVM', 'RR', 'S', 'Update service user routine configuration data', ' ', ' ', ' ', ' ', 'ADMIN', '20090121223923', 'ADMIN', '20090121231105');
Insert into MSVMSVCDEF
   (SERVICE_NAME, MODULE_NAME, SERVICE_MODE, SERVICE_CATEGORY, SERVICE_DESC_1, SERVICE_DESC_2, SERVICE_DESC_3, SEC_CHK_FLAG, SHARED_LIB_NAME, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM_View_Service_User_Routine_List', 'SVM', 'RR', 'I', 'View Service user routine list', ' ', ' ', ' ', ' ', 'ADMIN', '20090121221653', 'ADMIN', '20090121222907');


Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service_User_Routine_List', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121223923', 'ADMIN', '20090121231107');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service_User_Routine_List', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121223923', 'ADMIN', '20090121231107');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service_User_Routine_List', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121223923', 'ADMIN', '20090121231107');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service_User_Routine_List', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USERID', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121223923', 'ADMIN', '20090121231107');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service_User_Routine_List', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121223923', 'ADMIN', '20090121231107');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service_User_Routine_List', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''U'': Modify, ''D'': Delete)', ' ', ' ', 'Char', 0, 'PROCSTEP', ' ', 'M', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20090121223923', 'ADMIN', '20090121231107');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service_User_Routine_List', 'I', 0, 'SERVICE_LIST', 6, 'Service user routine list', ' ', ' ', 'List', 0, 'Service List', ' ', 'M', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20090121231107', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service_User_Routine_List', 'I', 1, 'MODULE_NAME', 0, ' ', ' ', ' ', ' ', 0, 'Module Name', ' ', 'O', 'SERVICE_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090121231107', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service_User_Routine_List', 'I', 1, 'SERVICE_NAME', 1, ' ', ' ', ' ', ' ', 0, 'Service Name', ' ', 'O', 'SERVICE_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090121231107', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service_User_Routine_List', 'I', 1, 'BEFORE', 2, 'Indication of whether to enable before user routine (''Y'': Enable before user routine)', ' ', ' ', 'Char', 0, 'Before', ' ', 'O', 'SERVICE_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090121231107', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service_User_Routine_List', 'I', 1, 'AFTER', 3, 'Indication of whether to enable after user routine (''Y'': Enable after user routine)', ' ', ' ', 'Char', 0, 'After', ' ', 'O', 'SERVICE_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090121231107', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service_User_Routine_List', 'I', 1, 'OVERRIDE_FLAG', 4, ' ', ' ', ' ', ' ', 0, 'Override Flag', ' ', 'O', 'SERVICE_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090121231107', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service_User_Routine_List', 'I', 1, 'LIB_NAME', 5, ' ', ' ', ' ', ' ', 0, 'Library Name', ' ', 'O', 'SERVICE_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090121231107', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service_User_Routine_List', 'I', 1, 'LIB_VER', 6, ' ', ' ', ' ', ' ', 0, 'Library Version', ' ', 'O', 'SERVICE_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090121231107', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service_User_Routine_List', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUSVALUE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121223923', 'ADMIN', '20090121231107');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service_User_Routine_List', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSGCODE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121223923', 'ADMIN', '20090121231107');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service_User_Routine_List', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121223923', 'ADMIN', '20090121231107');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service_User_Routine_List', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSGCATE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121223923', 'ADMIN', '20090121231107');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service_User_Routine_List', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELDMSG', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121223923', 'ADMIN', '20090121231107');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service_User_Routine_List', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DBERRMSG', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121223923', 'ADMIN', '20090121231107');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121221653', 'ADMIN', '20090121222909');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121221653', 'ADMIN', '20090121222909');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121221653', 'ADMIN', '20090121222909');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USERID', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121221653', 'ADMIN', '20090121222909');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121221653', 'ADMIN', '20090121222909');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': View service user routine list)', ' ', ' ', 'Char', 0, 'PROCSTEP', ' ', 'M', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20090121221653', 'ADMIN', '20090121222909');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'I', 0, 'MODULE_NAME', 6, ' ', ' ', ' ', ' ', 0, 'Module Name', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121222909', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'I', 0, 'CATEGORY', 7, ' ', ' ', ' ', ' ', 0, 'Service Category', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121222909', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'I', 0, 'SERVICE_NAME', 8, ' ', ' ', ' ', ' ', 0, 'Service Name', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121222909', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'I', 0, 'NEXT_MODULE_NAME', 9, ' ', ' ', ' ', ' ', 0, 'Next Module Name', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121222909', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'I', 0, 'NEXT_SERVICE_NAME', 10, ' ', ' ', ' ', ' ', 0, 'Next Service Name', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121222909', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUSVALUE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121221653', 'ADMIN', '20090121222909');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSGCODE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121221653', 'ADMIN', '20090121222909');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121221653', 'ADMIN', '20090121222909');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSGCATE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121221653', 'ADMIN', '20090121222909');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELDMSG', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121221653', 'ADMIN', '20090121222909');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DBERRMSG', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090121221653', 'ADMIN', '20090121222909');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'O', 0, 'SERVICE_LIST', 6, 'List of services', ' ', ' ', 'List', 30, 'Service List', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20090121222909', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'O', 1, 'MODULE_NAME', 0, ' ', ' ', ' ', ' ', 0, 'Module Name', ' ', 'O', 'SERVICE_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090121222909', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'O', 1, 'SERVICE_NAME', 1, ' ', ' ', ' ', ' ', 0, 'Service Name', ' ', 'O', 'SERVICE_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090121222909', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'O', 1, 'SERVICE_DESC_1', 2, ' ', ' ', ' ', ' ', 0, 'Service Description', ' ', 'O', 'SERVICE_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090121222909', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'O', 1, 'CATEGORY', 3, ' ', ' ', ' ', ' ', 0, 'Service Category', ' ', 'O', 'SERVICE_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090121222909', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'O', 1, 'BEFORE', 4, 'Indication of whether to enable before user routine (''Y'': Enable before user routine)', ' ', ' ', 'Char', 0, 'Before', ' ', 'O', 'SERVICE_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090121222909', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'O', 1, 'AFTER', 5, 'Indication of whether to enable after user routine (''Y'': Enable after user routine)', ' ', ' ', 'Char', 0, 'After', ' ', 'O', 'SERVICE_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090121222909', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'O', 1, 'OVERRIDE_FLAG', 6, ' ', ' ', ' ', ' ', 0, 'Override Flag', ' ', 'O', 'SERVICE_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090121222909', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'O', 1, 'LIB_NAME', 7, ' ', ' ', ' ', ' ', 0, 'Library Name', ' ', 'O', 'SERVICE_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090121222909', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'O', 1, 'LIB_VER', 8, ' ', ' ', ' ', ' ', 0, 'Library Version', ' ', 'O', 'SERVICE_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090121222909', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'O', 1, 'CREATE_TIME', 9, ' ', ' ', ' ', ' ', 0, 'Create Time', ' ', 'O', 'SERVICE_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090121222909', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'O', 1, 'CREATE_USER_ID', 10, ' ', ' ', ' ', ' ', 0, 'Create User ID', ' ', 'O', 'SERVICE_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090121222909', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'O', 1, 'UPDATE_TIME', 11, ' ', ' ', ' ', ' ', 0, 'Update Time', ' ', 'O', 'SERVICE_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090121222909', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_View_Service_User_Routine_List', 'O', 1, 'UPDATE_USER_ID', 12, ' ', ' ', ' ', ' ', 0, 'Update User ID', ' ', 'O', 'SERVICE_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090121222909', ' ', ' ');

