/*
**
**  File Name    : MESplusV5-Table-Create-20081031-Done.sql
**  Description  : MESplus V5 Release Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g
**
**  Period       : 2008.06.02 ~ 2008.10.31 ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
**
**  Revision History
**  Seq   Date        Modifier      Description                        
**  ---------------------------------------------------------------------------
**  1     2008.06.02  Aiden         Add MSVMDFTVER table script
**  2     2008.06.05  Aiden         Add MSVMCIDVER table script
**  3     2008.06.12  Hkyung        Add MWIPIDGDEF, MWIPIDGRUL, MWIPIDGREL, MWIPIDGSKV, MWIPIDGHIS table script
**  4     2008.09.22  Hkyung        Add RTD Table Script
**  5     2008.09.26  HyunJong      Add MSVMSVCDEF, MSVMSVCMBR, MSVMMBRDEF table script
**  6     2008.10.13  Hkyung        Add Batch Management table script
**  7     2008.10.31  Aiden         Close this file
**    
*/

/* Shared Library Pool Default Version List */
CREATE TABLE MSVMDFTVER
(
    LIB_NAME                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LIB_VER                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SERVICE_NAME                VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    SERVICE_VER                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSVMDFTVER
ADD CONSTRAINT MSVMDFTVER_PK PRIMARY KEY
(
    LIB_NAME,
    LIB_VER,
    SERVICE_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* Shared Library Version of Client ID */
CREATE TABLE MSVMKEYVER
(
    KEY_NAME                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_DESC                    VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    KEY_TYPE                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LIB_NAME                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LIB_VER                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SERVICE_NAME                VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    SERVICE_VER                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    DATA_1                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DATA_2                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DATA_3                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DATA_4                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DATA_5                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSVMKEYVER
ADD CONSTRAINT MSVMKEYVER_PK PRIMARY KEY
(
    KEY_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;



/* MWIPIDGDEF : Rule ID Definition Table */
CREATE TABLE MWIPIDGDEF
(
    RULE_ID                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RULE_DESC                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    GEN_TYPE                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    SAVE_POINT                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    FULFILL_SEQ                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPIDGDEF 
ADD CONSTRAINT MWIPIDGDEF_PK PRIMARY KEY
(
    RULE_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MWIPIDGRUL : Rule Definition Table */
CREATE TABLE MWIPIDGRUL
(
    RULE_ID                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RULE_SEQ                    NUMBER(6)        DEFAULT(0)      NOT NULL,  
    RULE_TYPE                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    DATA_1                      VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    DATA_2                      VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    DATA_3                      VARCHAR2(2000)    DEFAULT(' ')    NOT NULL,
    FIELD_TYPE                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    START_POS                   NUMBER(6)        DEFAULT(0)      NOT NULL,  
    LENGTH                      NUMBER(6)        DEFAULT(0)      NOT NULL,
    USE_ALT_DATE                CHAR(1)          DEFAULT(' ')    NOT NULL, 
    OVR_DATE_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,   
    USE_CALENDAR                CHAR(1)          DEFAULT(' ')    NOT NULL,  
    USE_NUMERIC                 CHAR(1)          DEFAULT(' ')    NOT NULL,  
    NUM_INC_ORDER               CHAR(1)          DEFAULT(' ')    NOT NULL,  
    NUM_ODD_EVEN                CHAR(1)          DEFAULT(' ')    NOT NULL,  
    USE_ALPHA                   CHAR(1)          DEFAULT(' ')    NOT NULL, 
    ALP_INC_ORDER               CHAR(1)          DEFAULT(' ')    NOT NULL,   
    ALP_CASE                    CHAR(1)          DEFAULT(' ')    NOT NULL,   
    ALP_ODD_EVEN                CHAR(1)          DEFAULT(' ')    NOT NULL,   
    NUM_ALP_ORDER               CHAR(1)          DEFAULT(' ')    NOT NULL,  
    DEP_RULE_SEQ                NUMBER(6)        DEFAULT(0)      NOT NULL,  
    ALLOW_CYCLE_SEQ             CHAR(1)          DEFAULT(' ')    NOT NULL,  
    CYCLE_INIT_VALUE            VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CREATE_INIT_VALUE           VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SEQ_KEY_1                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SEQ_KEY_2                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPIDGRUL 
ADD CONSTRAINT MWIPIDGRUL_PK PRIMARY KEY
(
    RULE_ID,
    RULE_SEQ
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MWIPIDGREL : Rule Relation Table */
CREATE TABLE MWIPIDGREL
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    REL_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL, 
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RESG_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_CODE                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    KEY_1                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_2                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_3                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_4                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_5                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RULE_ID                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPIDGREL 
ADD CONSTRAINT MWIPIDGREL_PK PRIMARY KEY
(
    FACTORY,
    REL_LEVEL,
    MAT_ID,
    MAT_VER,
    FLOW,
    OPER,
    RES_TYPE,
    RESG_ID,
    RES_ID,
    TRAN_CODE,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5    
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MWIPIDGSKV : Sequence Rule Last Value Table */
CREATE TABLE MWIPIDGSKV
(
    RULE_ID                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RULE_SEQ                    NUMBER(6)        DEFAULT(0)      NOT NULL,  
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL, 
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RESG_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_1                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_2                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_3                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_4                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_5                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_6                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_7                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_8                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_9                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_10                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    GEN_ID_SEQ                  NUMBER(6)        DEFAULT(0)      NOT NULL,  
    GEN_ID                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPIDGSKV 
ADD CONSTRAINT MWIPIDGSKV_PK PRIMARY KEY
(
    RULE_ID,
    RULE_SEQ,
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    OPER,
    RES_TYPE,
    RESG_ID,
    RES_ID,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_10,
    GEN_ID_SEQ    
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MWIPIDGSKV : Gen ID History Table */
CREATE TABLE MWIPIDGHIS
(
    RULE_ID                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL, 
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RESG_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_1                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_2                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_3                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_4                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_5                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_6                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_7                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_8                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_9                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_10                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,  
    GEN_ID                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPIDGHIS 
ADD CONSTRAINT MWIPIDGHIS_PK PRIMARY KEY
(
    RULE_ID,
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    OPER,
    RES_TYPE,
    RESG_ID,
    RES_ID,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_10,
    SEQ_NUM    
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* Add for NEW RTD */
  
/* MRTDRULDEF : Dispatcher-Rule Definition Table */
CREATE TABLE MRTDRULDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')      NOT NULL,
    RULE_ID                     VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    RULE_DESC                   VARCHAR2(50)     DEFAULT(' ')      NOT NULL,
    RULE_TYPE                   CHAR(1)          DEFAULT(' ')      NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')      NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')      NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRTDRULDEF
ADD CONSTRAINT MRTDRULDEF_PK PRIMARY KEY
(
    FACTORY,
    RULE_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;  



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
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')      NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')      NOT NULL
)
TABLESPACE MESPLUS_DATA_TS;

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

    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRTDEVNCON
ADD CONSTRAINT MRTDEVNCON_PK PRIMARY KEY
(
    FACTORY,
    SERVICE_NAME,
    SERVICE_SEQ
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* RTD_EVENT_SEQ : MRTDEVNIFS Table seq (EVENT_SEQ) */
CREATE SEQUENCE RTD_EVENT_SEQ
	MINVALUE 1
	MAXVALUE 2000000000
	INCREMENT BY 1
	CYCLE
	NOORDER
	CACHE 20;
  
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

    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRTDEVNIFS
ADD CONSTRAINT MRTDEVNIFS_PK PRIMARY KEY
(
    EVENT_SEQ
) USING INDEX TABLESPACE MESPLUS_IDX_TS;



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

    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

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



/* replace table MRTDMFORES  */
/* MRTDRESOPR : Set Dsispatcher to  Resource,Operation Table */
CREATE TABLE MRTDRESOPR
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')      NOT NULL,
    /* F:Factory, O:Operation, G:Resource Group, R:Resource */
    RELATION_LEVEL              CHAR(1)          DEFAULT(' ')      NOT NULL,
    RESG_ID                     VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')      NOT NULL,
    DSP_ID                      VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')      NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')      NOT NULL
)
TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRTDRESOPR
ADD CONSTRAINT MMRTDRESOPR_PK PRIMARY KEY
(
    FACTORY,
    RELATION_LEVEL,
    RESG_ID,
    RES_ID,
    OPER   
) USING INDEX TABLESPACE MESPLUS_IDX_TS;  



/* MRTDREFOPR : Set Reference Operation for Batch Table */
CREATE TABLE MRTDREFOPR
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')      NOT NULL,
    /* F:Factory, O:Operation, G:Resource Group, R:Resource */
    RELATION_LEVEL              CHAR(1)          DEFAULT(' ')      NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')      NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)        NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')      NOT NULL,

    REFERENCE_OPER              VARCHAR2(10)     DEFAULT(' ')      NOT NULL,

    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')      NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')      NOT NULL
)
TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRTDREFOPR
ADD CONSTRAINT MRTDREFOPR_PK PRIMARY KEY
(
    FACTORY,
    RELATION_LEVEL,
    MAT_ID,
    MAT_VER,
    FLOW,
    OPER   
) USING INDEX TABLESPACE MESPLUS_IDX_TS;  




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

    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

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

    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

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



/*Flexible Header*/


/* MSECFLXHDR : Flexible Header Table */
CREATE TABLE MSECFLXHDR
(
    SERVICE_NAME                VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    DSP_ID    	                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    ITEM_SEQ                    NUMBER(6)        DEFAULT 0       NOT NULL,
    ITEM_NAME                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DISPLAY_OPT                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SORT_ORDER_1                VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    SORT_ORDER_2                VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    SORT_ORDER_3                VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    SORT_ORDER_4                VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    SORT_ORDER_5                VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
     /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSECFLXHDR
ADD CONSTRAINT MSECFLXHDR_PK PRIMARY KEY
(
    SERVICE_NAME,
    DSP_ID,
    USER_ID,
    ITEM_SEQ
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* Service Management */

/* MSVMMBRDEF : Service Management Member Definition Table */
CREATE TABLE MSVMMBRDEF
(
  MEMBER_NAME                   VARCHAR2(50)     DEFAULT (' ')    NOT NULL,
  MEMBER_DESC_1                 VARCHAR2(1000)   DEFAULT (' ')    NOT NULL,
  MEMBER_DESC_2                 VARCHAR2(1000)   DEFAULT (' ')    NOT NULL,
  MEMBER_DESC_3                 VARCHAR2(1000)   DEFAULT (' ')    NOT NULL,
  MEMBER_TYPE                   VARCHAR2(10)     DEFAULT (' ')    NOT NULL,
  MEMBER_SIZE                   NUMBER(6)        DEFAULT (0)      NOT NULL,
  USE_RANGE_FLAG                CHAR(1)          DEFAULT (' ')    NOT NULL,
  RANGE_MIN                     NUMBER(22,4)     DEFAULT (0)      NOT NULL,
  RANGE_MAX                     NUMBER(22,4)     DEFAULT (0)      NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSVMMBRDEF 
ADD CONSTRAINT MSVMMBRDEF_PK PRIMARY KEY
(
  MEMBER_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSVMMBRDEF : Service Management Service Definition Table */
CREATE TABLE MSVMSVCDEF
(
  MODULE_NAME                  VARCHAR2(30)      DEFAULT (' ')    NOT NULL,
  SERVICE_NAME                 VARCHAR2(100)     DEFAULT (' ')    NOT NULL,
  SERVICE_MODE                 VARCHAR2(2)       DEFAULT (' ')    NOT NULL,
  SERVICE_CATEGORY             CHAR(1)           DEFAULT (' ')    NOT NULL,
  SERVICE_DESC_1               VARCHAR2(1000)    DEFAULT (' ')    NOT NULL,
  SERVICE_DESC_2               VARCHAR2(1000)    DEFAULT (' ')    NOT NULL,
  SERVICE_DESC_3               VARCHAR2(1000)    DEFAULT (' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSVMSVCDEF 
ADD CONSTRAINT MSVMSVCDEF_PK PRIMARY KEY
(
  MODULE_NAME, 
  SERVICE_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSVMMBRDEF : Service Management Service Member Table */
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
  REQ_MEMBER_FLAG              CHAR(1)           DEFAULT (' ')    NOT NULL,
  PARENT_MEMBER_NAME           VARCHAR2(50)      DEFAULT (' ')    NOT NULL,
  OVERRIDE_FLAG                CHAR(1)           DEFAULT (' ')    NOT NULL,
  USE_RANGE_FLAG               CHAR(1)           DEFAULT (' ')    NOT NULL,
  RANGE_MIN                    NUMBER(22,4)      DEFAULT (0)      NOT NULL,
  RANGE_MAX                    NUMBER(22,4)      DEFAULT (0)      NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

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




/*Batch Management*/
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
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPBATRUL 
ADD CONSTRAINT MWIPBATRUL_PK PRIMARY KEY
(
    FACTORY,
    CRT_RULE_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/*MWIPBATREL - Relation of Creation Batch Rule */
CREATE TABLE MWIPBATREL
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    REL_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    RES_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RESG_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL, 
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
	RECIPE                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,   
    CRT_RULE_ID                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPBATREL 
ADD CONSTRAINT MWIPBATREL_PK PRIMARY KEY
(
    FACTORY,
    REL_LEVEL,
    RES_TYPE,
    RESG_ID,
    RES_ID,
    MAT_ID,
    MAT_VER,
    FLOW,
    OPER,
    RECIPE    
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/*MWIPBATRSV - Reservation Batch*/
CREATE TABLE MWIPBATRSV
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL, 
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
	RES_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RESG_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RECIPE                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RSV_BATCH_ID                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,   
    CRT_RULE_ID                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPBATRSV 
ADD CONSTRAINT MWIPBATRSV_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    OPER,
    RES_TYPE,
    RESG_ID,
    RES_ID,
    RECIPE    
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/*MWIPBATRIT - Reserved Batch Items*/
CREATE TABLE MWIPBATRIT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RSV_BATCH_ID                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,   
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL, 
    ITEM_ID                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_TYPE                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPBATRIT 
ADD CONSTRAINT MWIPBATRIT_PK PRIMARY KEY
(
    FACTORY,
    RSV_BATCH_ID,
    SEQ_NUM   
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/*MWIPBATHIS - Batch History*/
CREATE TABLE MWIPBATHIS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BATCH_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,   
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,  
    TRAN_CODE                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,    
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL, 
    ITEM_ID                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_HIST_SEQ               NUMBER(10)       DEFAULT(0)      NOT NULL, 
    ITEM_TYPE                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CRT_RULE_ID                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPBATHIS 
ADD CONSTRAINT MWIPBATHIS_PK PRIMARY KEY
(
    FACTORY,
    BATCH_ID,
    TRAN_TIME,
    TRAN_CODE,
    SEQ_NUM   
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/*MWIPBATDEF - Batch Definition*/
CREATE TABLE MWIPBATDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BATCH_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,   
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL, 
    ITEM_ID                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_TYPE                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPBATDEF 
ADD CONSTRAINT MWIPBATDEF_PK PRIMARY KEY
(
    FACTORY,
    BATCH_ID,
    ITEM_ID,
    SEQ_NUM   
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/*Carrier Event Definition Table*/
CREATE TABLE MRASCEVDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CRR_EVENT_ID                VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    CRR_EVENT_DESC              VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* SYSTEM에서 사용하는 이벤트 ,지울수 없음. 'Y', ' ' */
    SYSTEM_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* EVENT 발생전 CHECK 할 ITEM및 조건 설정 */
    /* CHECK 할 FIELD 명 */
    CHK_ITEM_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_21                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_22                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_23                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_24                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_25                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_26                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_27                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_28                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_29                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_ITEM_30                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* CHECK 방법 '=': ALLOW '!':REJECT 'N'=NOT CHECK '>':크거나   '<' : 같거나, ' '*/
    CHK_FLAG_1                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_2                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_3                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_4                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_5                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_6                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_7                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_8                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_9                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_10                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_11                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_12                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_13                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_14                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_15                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_16                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_17                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_18                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_19                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_20                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_21                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_22                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_23                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_24                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_25                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_26                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_27                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_28                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_29                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_FLAG_30                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* CHECK 할 VALUE */
    CHK_VALUE_1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_6                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_7                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_8                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_9                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_10                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_11                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_12                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_13                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_14                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_15                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_16                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_17                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_18                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_19                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_20                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_21                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_22                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_23                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_24                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_25                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_26                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_27                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_28                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_29                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_VALUE_30                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* CHECK 할 FIELD명 */
    CHK_FIELD_1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_6                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_7                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_8                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_9                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_10                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_11                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_12                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_13                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_14                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_15                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_16                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_17                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_18                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_19                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_20                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_21                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_22                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_23                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_24                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_25                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_26                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_27                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_28                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_29                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_FIELD_30                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* CHANGE 할 FIELD 명 */
    CHG_ITEM_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_21                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_22                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_23                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_24                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_25                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_26                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_27                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_28                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_29                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_ITEM_30                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* 바꿀 방법 'Y' : 다음의 값으로 바꿈, 'N' : 값을 바꾸지 않음,  '+' :다음의 값을 더함  */
    /* '-':다음의 값을 뺌, 'R' : 다음 값으로 무조건 변경, 'T' : Time*/
    CHG_FLAG_1                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_2                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_3                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_4                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_5                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_6                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_7                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_8                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_9                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_10                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_11                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_12                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_13                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_14                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_15                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_16                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_17                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_18                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_19                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_20                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_21                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_22                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_23                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_24                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_25                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_26                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_27                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_28                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_29                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_FLAG_30                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* CHANGE 할 VALUE */
    CHG_VALUE_1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_6                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_7                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_8                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_9                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_10                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_11                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_12                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_13                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_14                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_15                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_16                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_17                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_18                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_19                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_20                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_21                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_22                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_23                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_24                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_25                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_26                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_27                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_28                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_29                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_VALUE_30                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* CHG_FLAG='Y' 일 경우 값을 반드시 입력해야 하는지 여부를 결정. 'Y' - 반드시 입력해야 함. ' ' - 입력하지 않아도 됨 */
    CHG_OPT_1                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_2                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_3                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_4                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_5                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_6                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_7                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_8                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_9                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_10                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_11                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_12                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_13                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_14                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_15                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_16                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_17                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_18                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_19                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_20                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_21                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_22                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_23                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_24                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_25                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_26                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_27                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_28                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_29                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_OPT_30                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASCEVDEF
ADD CONSTRAINT MRASCEVDEF_PK PRIMARY KEY
(
    FACTORY,
    CRR_EVENT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

     