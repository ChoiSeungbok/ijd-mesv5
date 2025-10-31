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
**  1. 2013.03.13   IC.Bae   Create
*/

ALTER TABLE MWIPTSTPGM MODIFY TEST_PGM_NAME              VARCHAR2(60)     DEFAULT (' ');

CREATE TABLE MSPMDOCIMG_OLD AS SELECT * FROM MSPMDOCIMG;
DROP TABLE MSPMDOCIMG CASCADE CONSTRAINT PURGE;

CREATE TABLE MSPMDOCIMG
(
    SPEC_REL_ID              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    SPEC_REL_VER             NUMBER(3,0)     DEFAULT(0)      NOT NULL,
    CHAR_ID                  VARCHAR2(25)    DEFAULT(' ')    NOT NULL,
    DOC_NAME_1               VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    DOC_NAME_2               VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    DOC_NAME_3               VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    DOC_NAME_4               VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    DOC_NAME_5               VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    IMG_NAME_1               VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    IMG_NAME_2               VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    IMG_NAME_3               VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    IMG_NAME_4               VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    IMG_NAME_5               VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    ATTACH_FILE_DIR          VARCHAR2(1000)  DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    CREATE_TIME              VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSPMDOCIMG
ADD CONSTRAINT MSPMDOCIMG_PK PRIMARY KEY
(
    SPEC_REL_ID,
    SPEC_REL_VER,
    CHAR_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

INSERT INTO MSPMDOCIMG VALUE ( 
SELECT 
    SPEC_REL_ID       ,
    SPEC_REL_VER      ,
    ' '               ,
    DOC_NAME_1        ,
    DOC_NAME_2        ,
    DOC_NAME_3        ,
    DOC_NAME_4        ,
    DOC_NAME_5        ,
    IMG_NAME_1        ,
    IMG_NAME_2        ,
    IMG_NAME_3        ,
    IMG_NAME_4        ,
    IMG_NAME_5        ,
    SPEC_REL_ID||'_'||TO_CHAR(SPEC_REL_VER),
    CREATE_USER_ID    ,
    CREATE_TIME       ,
    UPDATE_USER_ID    ,
    UPDATE_TIME       
FROM MSPMDOCIMG_OLD);  

ALTER TABLE MEDCCHRDEF ADD ATTACH_FILE_DIR  VARCHAR2(1000)     DEFAULT(' ')    NOT NULL;

/* For Flexible Inquiry */
ALTER TABLE MBASINQDEF MODIFY FMT_1            CHAR(1)            DEFAULT(' ');
ALTER TABLE MBASINQDEF MODIFY FMT_2            CHAR(1)            DEFAULT(' ');
ALTER TABLE MBASINQDEF MODIFY FMT_3            CHAR(1)            DEFAULT(' ');
ALTER TABLE MBASINQDEF MODIFY FMT_4            CHAR(1)            DEFAULT(' ');
ALTER TABLE MBASINQDEF MODIFY FMT_5            CHAR(1)            DEFAULT(' ');
ALTER TABLE MBASINQDEF MODIFY FMT_6            CHAR(1)            DEFAULT(' ');
ALTER TABLE MBASINQDEF MODIFY FMT_7            CHAR(1)            DEFAULT(' ');
ALTER TABLE MBASINQDEF MODIFY FMT_8            CHAR(1)            DEFAULT(' ');
ALTER TABLE MBASINQDEF MODIFY FMT_9            CHAR(1)            DEFAULT(' ');
ALTER TABLE MBASINQDEF MODIFY FMT_10           CHAR(1)            DEFAULT(' ');
ALTER TABLE MBASINQDEF MODIFY SIZE_1           NUMBER(2)          DEFAULT(0)  ;
ALTER TABLE MBASINQDEF MODIFY SIZE_2           NUMBER(2)          DEFAULT(0)  ;
ALTER TABLE MBASINQDEF MODIFY SIZE_3           NUMBER(2)          DEFAULT(0)  ;
ALTER TABLE MBASINQDEF MODIFY SIZE_4           NUMBER(2)          DEFAULT(0)  ;
ALTER TABLE MBASINQDEF MODIFY SIZE_5           NUMBER(2)          DEFAULT(0)  ;
ALTER TABLE MBASINQDEF MODIFY SIZE_6           NUMBER(2)          DEFAULT(0)  ;
ALTER TABLE MBASINQDEF MODIFY SIZE_7           NUMBER(2)          DEFAULT(0)  ;
ALTER TABLE MBASINQDEF MODIFY SIZE_8           NUMBER(2)          DEFAULT(0)  ;
ALTER TABLE MBASINQDEF MODIFY SIZE_9           NUMBER(2)          DEFAULT(0)  ;
ALTER TABLE MBASINQDEF MODIFY SIZE_10          NUMBER(2)          DEFAULT(0)  ;

ALTER TABLE MBASINQDEF ADD PRT_11           VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD PRT_12           VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD PRT_13           VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD PRT_14           VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD PRT_15           VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD PRT_16           VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD PRT_17           VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD PRT_18           VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD PRT_19           VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD PRT_20           VARCHAR2(30)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD FMT_11           CHAR(1)            DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD FMT_12           CHAR(1)            DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD FMT_13           CHAR(1)            DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD FMT_14           CHAR(1)            DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD FMT_15           CHAR(1)            DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD FMT_16           CHAR(1)            DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD FMT_17           CHAR(1)            DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD FMT_18           CHAR(1)            DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD FMT_19           CHAR(1)            DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD FMT_20           CHAR(1)            DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD SIZE_11          NUMBER(2)          DEFAULT(0)      NOT NULL;
ALTER TABLE MBASINQDEF ADD SIZE_12          NUMBER(2)          DEFAULT(0)      NOT NULL;
ALTER TABLE MBASINQDEF ADD SIZE_13          NUMBER(2)          DEFAULT(0)      NOT NULL;
ALTER TABLE MBASINQDEF ADD SIZE_14          NUMBER(2)          DEFAULT(0)      NOT NULL;
ALTER TABLE MBASINQDEF ADD SIZE_15          NUMBER(2)          DEFAULT(0)      NOT NULL;
ALTER TABLE MBASINQDEF ADD SIZE_16          NUMBER(2)          DEFAULT(0)      NOT NULL;
ALTER TABLE MBASINQDEF ADD SIZE_17          NUMBER(2)          DEFAULT(0)      NOT NULL;
ALTER TABLE MBASINQDEF ADD SIZE_18          NUMBER(2)          DEFAULT(0)      NOT NULL;
ALTER TABLE MBASINQDEF ADD SIZE_19          NUMBER(2)          DEFAULT(0)      NOT NULL;
ALTER TABLE MBASINQDEF ADD SIZE_20          NUMBER(2)          DEFAULT(0)      NOT NULL;
ALTER TABLE MBASINQDEF ADD REQ_11           CHAR(1)            DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD REQ_12           CHAR(1)            DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD REQ_13           CHAR(1)            DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD REQ_14           CHAR(1)            DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD REQ_15           CHAR(1)            DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD REQ_16           CHAR(1)            DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD REQ_17           CHAR(1)            DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD REQ_18           CHAR(1)            DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD REQ_19           CHAR(1)            DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD REQ_20           CHAR(1)            DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD TBL_11           VARCHAR2(20)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD TBL_12           VARCHAR2(20)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD TBL_13           VARCHAR2(20)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD TBL_14           VARCHAR2(20)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD TBL_15           VARCHAR2(20)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD TBL_16           VARCHAR2(20)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD TBL_17           VARCHAR2(20)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD TBL_18           VARCHAR2(20)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD TBL_19           VARCHAR2(20)       DEFAULT(' ')    NOT NULL;
ALTER TABLE MBASINQDEF ADD TBL_20           VARCHAR2(20)       DEFAULT(' ')    NOT NULL;

ALTER TABLE MSPMRELCHR ADD USE_CHAR_DIR                    CHAR(1)         DEFAULT(' ')    NOT NULL;
ALTER TABLE MSPMRELCHR ADD TARGET_VALUE_WITH_DIR           CHAR(1)         DEFAULT(' ')    NOT NULL;
ALTER TABLE MSPMRELCHR ADD TARGET_VALUE_WITH_FILE          CHAR(1)         DEFAULT(' ')    NOT NULL;
ALTER TABLE MSPMRELCHR ADD TARGET_FILE_EXT                 VARCHAR2(10)    DEFAULT(' ')    NOT NULL;
ALTER TABLE MSPMRELCHR ADD USE_LATEST_FILE_VER             CHAR(1)         DEFAULT(' ')    NOT NULL;



CREATE TABLE MWIPBINSSH_OLD AS SELECT * FROM MWIPBINSSH;
DROP TABLE MWIPBINSSH CASCADE CONSTRAINT PURGE;

CREATE TABLE MWIPBINSSH
(
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    BIN_COL_SEQ                 NUMBER(5)        DEFAULT(0)      NOT NULL,
    BIN_SEQ                     NUMBER(3)        DEFAULT(0)      NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOT_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    BIN_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_VERSION                 NUMBER(5)        DEFAULT(0)      NOT NULL,
    BIN_UNIT                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BIN_PROMPT                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_PROMPT_DESC             VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    BIN_QTY                     NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    BIN_TYPE                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOGICAL_BIN_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    USE_BIN_PROMPT_FAIL_REASON  CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEEP_LOT_QTY_FAIL           CHAR(1)          DEFAULT(' ')    NOT NULL,
    FAIL_REASON_CODE            VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOW_YIELD_FLAG              CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHECK_RESULT                VARCHAR2(4000)   DEFAULT(' ')    NOT NULL,
    TRAN_CODE                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_KEY_CODE_1             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_KEY_CODE_2             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_KEY_CODE_3             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_KEY_CODE_4             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_KEY_CODE_5             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_KEY_CODE_6             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_KEY_CODE_7             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_KEY_CODE_8             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_KEY_CODE_9             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_KEY_CODE_10            VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_COMMENT_1               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    BIN_COMMENT_2               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    BIN_COMMENT_3               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT_1              VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT_2              VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT_3              VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    RESV_FIELD_1                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_2                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_3                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_4                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_5                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_6                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_7                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_8                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_9                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_10               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    HIST_DEL_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_COMMENT            VARCHAR2(400)    DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPBINSSH
ADD CONSTRAINT MWIPBINSSH_PK PRIMARY KEY
(
    SUBLOT_ID,
    HIST_SEQ,
    BIN_COL_SEQ,
    BIN_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

INSERT INTO MWIPBINSSH VALUE ( 
SELECT 
    A.SUBLOT_ID                   ,
    A.HIST_SEQ                    ,
    A.BIN_COL_SEQ                 ,
    A.BIN_SEQ                     ,
    A.FACTORY                     ,
    B.LOT_ID                      ,
    B.LOT_HIST_SEQ                ,
    A.BIN_ID                      ,
    A.BIN_VERSION                 ,
    A.BIN_UNIT                    ,
    A.BIN_PROMPT                  ,
    A.BIN_PROMPT_DESC             ,
    A.BIN_QTY                     ,
    A.BIN_TYPE                    ,
    A.LOGICAL_BIN_FLAG            ,
    A.USE_BIN_PROMPT_FAIL_REASON  ,
    A.KEEP_LOT_QTY_FAIL           ,
    A.FAIL_REASON_CODE            ,
    A.LOW_YIELD_FLAG              ,
    A.CHECK_RESULT                ,
    A.TRAN_CODE                   ,
    A.TRAN_KEY_CODE_1             ,
    A.TRAN_KEY_CODE_2             ,
    A.TRAN_KEY_CODE_3             ,
    A.TRAN_KEY_CODE_4             ,
    A.TRAN_KEY_CODE_5             ,
    A.TRAN_KEY_CODE_6             ,
    A.TRAN_KEY_CODE_7             ,
    A.TRAN_KEY_CODE_8             ,
    A.TRAN_KEY_CODE_9             ,
    A.TRAN_KEY_CODE_10            ,
    A.BIN_COMMENT_1               ,
    A.BIN_COMMENT_2               ,
    A.BIN_COMMENT_3               ,
    A.TRAN_COMMENT_1              ,
    A.TRAN_COMMENT_2              ,
    A.TRAN_COMMENT_3              ,
    A.RESV_FIELD_1                ,
    A.RESV_FIELD_2                ,
    A.RESV_FIELD_3                ,
    A.RESV_FIELD_4                ,
    A.RESV_FIELD_5                ,
    A.RESV_FIELD_6                ,
    A.RESV_FIELD_7                ,
    A.RESV_FIELD_8                ,
    A.RESV_FIELD_9                ,
    A.RESV_FIELD_10               ,
    A.HIST_DEL_FLAG               ,
    A.HIST_DEL_TIME               ,
    A.HIST_DEL_USER_ID            ,
    A.HIST_DEL_COMMENT
FROM MWIPBINSSH_OLD A, MWIPBINHSS B
WHERE A.SUBLOT_ID = B.SUBLOT_ID AND A.HIST_SEQ = B.HIST_SEQ AND A.BIN_COL_SEQ = B.BIN_COL_SEQ
);


ALTER TABLE MWIPIDGDEF ADD NOT_USED_ID_SEARCH_OPTION CHAR(1) DEFAULT(' ') NOT NULL;

UPDATE MWIPIDGDEF SET SAVE_POINT = '1' WHERE SAVE_POINT > '1';

CREATE TABLE MWIPIDGHIS_OLD AS SELECT * FROM MWIPIDGHIS;
DROP TABLE MWIPIDGHIS CASCADE CONSTRAINT PURGE;

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
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DATETIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
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
    SEQ_NUM                     NUMBER(10)       DEFAULT(0)      NOT NULL,
    GEN_ID                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    SEQ_POSITION                VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    CONFIRM_KEY                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ID_USED_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

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
    LOT_ID,
    SUBLOT_ID,
    DATETIME,
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
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MWIPIDGHIS_IDX_1 ON MWIPIDGHIS
(GEN_ID, CONFIRM_KEY) TABLESPACE HISTORY_IDX_TS;

INSERT INTO MWIPIDGHIS VALUE ( 
SELECT 
    RULE_ID        ,
    FACTORY        ,
    MAT_ID         ,
    MAT_VER        ,
    FLOW           ,
    OPER           ,
    RES_TYPE       ,
    RESG_ID        ,
    RES_ID         ,
    ' '            ,
    ' '            ,
    ' '            ,
    KEY_1          ,
    KEY_2          ,
    KEY_3          ,
    KEY_4          ,
    KEY_5          ,
    KEY_6          ,
    KEY_7          ,
    KEY_8          ,
    KEY_9          ,
    KEY_10         ,
    SEQ_NUM        ,
    GEN_ID         ,
    CREATE_USER_ID ,
    CREATE_TIME    ,
    SEQ_POSITION   ,
    ' '            ,
    ' '
FROM MWIPIDGHIS_OLD);  


ALTER TABLE MWIPIDGRUL MODIFY SEQ_KEY_1              VARCHAR2(20)     DEFAULT (' ');

CREATE TABLE MWIPIDGSKV_OLD AS SELECT * FROM MWIPIDGSKV;
DROP TABLE MWIPIDGSKV CASCADE CONSTRAINT PURGE;

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
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DATETIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
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
    GEN_ID_SEQ                  NUMBER(10)       DEFAULT(0)      NOT NULL,
    GEN_ID                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    SEQ_CONFIRM_KEY             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CYCLE_INIT_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    ID_USED_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    FRONT_SEQ_CONFIRM_KEY_1     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FRONT_SEQ_CONFIRM_KEY_2     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FRONT_SEQ_CONFIRM_KEY_3     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FRONT_SEQ_CONFIRM_KEY_4     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FRONT_SEQ_CONFIRM_KEY_5     VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

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
    LOT_ID,
    SUBLOT_ID,
    DATETIME,
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
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MWIPIDGSKV_IDX_1 ON MWIPIDGSKV
(
    SEQ_CONFIRM_KEY
) TABLESPACE HISTORY_IDX_TS;

INSERT INTO MWIPIDGSKV VALUE ( 
SELECT 
    RULE_ID          ,
    RULE_SEQ         ,
    FACTORY          ,
    MAT_ID           ,
    MAT_VER          ,
    FLOW             ,
    OPER             ,
    RES_TYPE         ,
    RESG_ID          ,
    RES_ID           ,
    ' '              ,
    ' '              ,
    ' '              ,
    KEY_1            ,
    KEY_2            ,
    KEY_3            ,
    KEY_4            ,
    KEY_5            ,
    KEY_6            ,
    KEY_7            ,
    KEY_8            ,
    KEY_9            ,
    KEY_10           ,
    GEN_ID_SEQ       ,
    GEN_ID           ,
    UPDATE_USER_ID   ,
    UPDATE_TIME      ,
    ' '              ,
    ' '              ,
    ' '              ,
    ' '              ,
    ' '              ,
    ' '              ,
    ' '              ,
    ' '
FROM MWIPIDGSKV_OLD);  

CREATE TABLE MWIPIDGSCF
(
    GEN_ID                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CONFIRM_KEY                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RULE_ID                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RULE_SEQ                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    SEQ_CONFIRM_KEY             VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPIDGSCF
ADD CONSTRAINT MWIPIDGSCF_PK PRIMARY KEY
(
    GEN_ID,
    CONFIRM_KEY,
    RULE_ID,
    RULE_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* Queue Time by Priority Control */
CREATE TABLE MWIPQTMDEF_OLD AS SELECT * FROM MWIPQTMDEF;
DROP TABLE MWIPQTMDEF CASCADE CONSTRAINT PURGE;

CREATE TABLE MWIPQTMDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FROM_FACTORY                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FROM_FLOW                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FROM_FLOW_SEQ_NUM           NUMBER(6)        DEFAULT(0)      NOT NULL,
    FROM_OPER                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FROM_POINT_FLAG             CHAR(1)          DEFAULT (' ')   NOT NULL,
    CHECK_POINT_FLAG            CHAR(1)          DEFAULT (' ')   NOT NULL,
    UPPER_WARN_QUE_TIME         NUMBER(10)       DEFAULT (0)     NOT NULL,
    LOWER_WARN_QUE_TIME         NUMBER(10)       DEFAULT (0)     NOT NULL,
    WARN_ALARM_ID               VARCHAR2(20)     DEFAULT (' ')   NOT NULL,
    UPPER_ERR_QUE_TIME          NUMBER(10)       DEFAULT (0)     NOT NULL,
    LOWER_ERR_QUE_TIME          NUMBER(10)       DEFAULT (0)     NOT NULL,
    ERROR_ALARM_ID              VARCHAR2(20)     DEFAULT (' ')   NOT NULL,
    PRIORITY                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    SUBLOT_FLAG                 CHAR(1)          DEFAULT (' ')   NOT NULL,
    VIO_RULE_FLAG               CHAR(1)          DEFAULT (' ')   NOT NULL,
    VIO_LIMIT_NUM               NUMBER(6)        DEFAULT (0)     NOT NULL,
    SEARCH_MRG_HIS_FLAG         CHAR(1)          DEFAULT (' ')   NOT NULL,
    CMF_1                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_2                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_3                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_4                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_5                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_6                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_7                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_8                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_9                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_10                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_11                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_12                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_13                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_14                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_15                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_16                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_17                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_18                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_19                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_20                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LOT_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_CMF_11                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_CMF_12                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_CMF_13                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_CMF_14                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_CMF_15                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_CMF_16                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_CMF_17                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_CMF_18                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_CMF_19                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_CMF_20                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPQTMDEF
ADD CONSTRAINT MWIPQTMDEF_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    FROM_FACTORY,
    FLOW,
    FLOW_SEQ_NUM,
    OPER,
    FROM_FLOW,
    FROM_FLOW_SEQ_NUM,
    FROM_OPER,
    FROM_POINT_FLAG,
    CHECK_POINT_FLAG,
    LOT_CMF_1,
    LOT_CMF_2,
    LOT_CMF_3,
    LOT_CMF_4,
    LOT_CMF_5,
    LOT_CMF_6,
    LOT_CMF_7,
    LOT_CMF_8,
    LOT_CMF_9,
    LOT_CMF_10,
    LOT_CMF_11,
    LOT_CMF_12,
    LOT_CMF_13,
    LOT_CMF_14,
    LOT_CMF_15,
    LOT_CMF_16,
    LOT_CMF_17,
    LOT_CMF_18,
    LOT_CMF_19,
    LOT_CMF_20
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

INSERT INTO MWIPQTMDEF VALUE ( 
SELECT 
    FACTORY                  ,
    MAT_ID                   ,
    MAT_VER                  ,
    FLOW                     ,
    FLOW_SEQ_NUM             ,
    OPER                     ,
    FROM_FACTORY             ,
    FROM_FLOW                ,
    FROM_FLOW_SEQ_NUM        ,
    FROM_OPER                ,
    FROM_POINT_FLAG          ,
    CHECK_POINT_FLAG         ,
    UPPER_WARN_QUE_TIME      ,
    LOWER_WARN_QUE_TIME      ,
    WARN_ALARM_ID            ,
    UPPER_ERR_QUE_TIME       ,
    LOWER_ERR_QUE_TIME       ,
    ERROR_ALARM_ID           ,
    PRIORITY                 ,
    SUBLOT_FLAG              ,
    VIO_RULE_FLAG            ,
    VIO_LIMIT_NUM            ,
    SEARCH_MRG_HIS_FLAG      ,
    CMF_1                    ,
    CMF_2                    ,
    CMF_3                    ,
    CMF_4                    ,
    CMF_5                    ,
    CMF_6                    ,
    CMF_7                    ,
    CMF_8                    ,
    CMF_9                    ,
    CMF_10                   ,
    CMF_11                   ,
    CMF_12                   ,
    CMF_13                   ,
    CMF_14                   ,
    CMF_15                   ,
    CMF_16                   ,
    CMF_17                   ,
    CMF_18                   ,
    CMF_19                   ,
    CMF_20                   ,
    CREATE_USER_ID           ,
    CREATE_TIME              ,
    UPDATE_USER_ID           ,
    UPDATE_TIME              ,
    ' '                      ,
    ' '                      ,
    ' '                      ,
    ' '                      ,
    ' '                      ,
    ' '                      ,
    ' '                      ,
    ' '                      ,
    ' '                      ,
    ' '                      ,
    ' '                      ,
    ' '                      ,
    ' '                      ,
    ' '                      ,
    ' '                      ,
    ' '                      ,
    ' '                      ,
    ' '                      ,
    ' '                      ,
    ' '
FROM MWIPQTMDEF_OLD);  


ALTER TABLE MWIPQTMHIS ADD LOT_CMF_1    VARCHAR2(30)    DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPQTMHIS ADD LOT_CMF_2    VARCHAR2(30)    DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPQTMHIS ADD LOT_CMF_3    VARCHAR2(30)    DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPQTMHIS ADD LOT_CMF_4    VARCHAR2(30)    DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPQTMHIS ADD LOT_CMF_5    VARCHAR2(30)    DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPQTMHIS ADD LOT_CMF_6    VARCHAR2(30)    DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPQTMHIS ADD LOT_CMF_7    VARCHAR2(30)    DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPQTMHIS ADD LOT_CMF_8    VARCHAR2(30)    DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPQTMHIS ADD LOT_CMF_9    VARCHAR2(30)    DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPQTMHIS ADD LOT_CMF_10   VARCHAR2(30)    DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPQTMHIS ADD LOT_CMF_11   VARCHAR2(30)    DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPQTMHIS ADD LOT_CMF_12   VARCHAR2(30)    DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPQTMHIS ADD LOT_CMF_13   VARCHAR2(30)    DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPQTMHIS ADD LOT_CMF_14   VARCHAR2(30)    DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPQTMHIS ADD LOT_CMF_15   VARCHAR2(30)    DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPQTMHIS ADD LOT_CMF_16   VARCHAR2(30)    DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPQTMHIS ADD LOT_CMF_17   VARCHAR2(30)    DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPQTMHIS ADD LOT_CMF_18   VARCHAR2(30)    DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPQTMHIS ADD LOT_CMF_19   VARCHAR2(30)    DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPQTMHIS ADD LOT_CMF_20   VARCHAR2(30)    DEFAULT(' ')    NOT NULL;

/* MWIPSLTBOS : History of Sub Lot multi Bonus Definition Table */
CREATE TABLE MWIPSLTBOS
(
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    LOT_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    QTY_FLAG                    CHAR(1)          DEFAULT('1')    NOT NULL,
    BONUS_CODE                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CAUSE_FLOW                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CAUSE_OPER                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CAUSE_RES_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    BONUS_QTY                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPSLTBOS
ADD CONSTRAINT MWIPSLTBOS_PK PRIMARY KEY
(
    SUBLOT_ID,
    LOT_ID,
    HIST_SEQ,
    QTY_FLAG,
    BONUS_CODE
) USING INDEX TABLESPACE HISTORY_IDX_TS;

/* MWIPSLTCVH : History of Sub Lot multi CV Definition Table */
CREATE TABLE MWIPSLTCVH
(
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOT_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CAUSE_FLOW                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CAUSE_OPER                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CAUSE_RES_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    QTY_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    CV_CODE                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CV_QTY                      NUMBER(10,3)     DEFAULT(0.0)    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPSLTCVH
ADD CONSTRAINT MWIPSLTCVH_PK PRIMARY KEY
(
    SUBLOT_ID,
    HIST_SEQ,
    LOT_ID,
    QTY_FLAG,
    CV_CODE
) USING INDEX TABLESPACE HISTORY_IDX_TS;


ALTER TABLE MWIPSLTLOS ADD LOSS_QTY     NUMBER(10,3)     DEFAULT(0.0)   NOT NULL;


/*==== WEM(Work process Event Management Module) ====*/
/* MWEMTYEDEF : Work Process Type Definition */
CREATE TABLE MWEMTYEDEF
(
    CREATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    WORK_PROC_TYPE           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    WORK_PROC_TYPE_DESC      VARCHAR2(200)   DEFAULT (' ')    NOT NULL,
    SYSTEM_FLAG              CHAR(1)         DEFAULT (' ')    NOT NULL
)TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWEMTYEDEF ADD (
CONSTRAINT MWEMTYEDEF_PK
PRIMARY KEY
(
    FACTORY,
    WORK_PROC_TYPE
)USING INDEX TABLESPACE MESPLUS_IDX_TS);

/* MWEMSTSDEF : Work Process Status Definition */
CREATE TABLE MWEMSTSDEF
(
    CREATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    WORK_PROC_TYPE           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STATUS                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STATUS_DESC              VARCHAR2(200)   DEFAULT (' ')    NOT NULL,
    STATUS_TYPE              CHAR(1)         DEFAULT (' ')    NOT NULL,
    ST_FORMAT                CHAR(1)         DEFAULT (' ')    NOT NULL,
    ST_SIZE                  NUMBER(4)       DEFAULT (0)      NOT NULL,
    DATA_1                   VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_2                   VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_3                   VARCHAR2(4000)  DEFAULT (' ')    NOT NULL
)TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWEMSTSDEF ADD (
CONSTRAINT MWEMSTSDEF_PK
PRIMARY KEY
(
    FACTORY,
    WORK_PROC_TYPE,
    STATUS
)USING INDEX TABLESPACE MESPLUS_IDX_TS);

/* MWEMSTPDEF : Work Process Step Definition */
CREATE TABLE MWEMSTPDEF
(
    CREATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    WORK_PROC_TYPE           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_ID                  VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_DESC                VARCHAR2(200)   DEFAULT (' ')    NOT NULL,
    SCREEN_ID                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    COL_SET_ID               VARCHAR2(25)    DEFAULT (' ')    NOT NULL
)TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWEMSTPDEF ADD (
CONSTRAINT MWEMSTPDEF_PK
PRIMARY KEY
(
    FACTORY,
    WORK_PROC_TYPE,
    STEP_ID
)USING INDEX TABLESPACE MESPLUS_IDX_TS);

/* MWEMSTPSTS : Work Process Step and Status Relation */
CREATE TABLE MWEMSTPSTS
(
    CREATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    WORK_PROC_TYPE           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_ID                  VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STATUS                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    INPUT_TYPE               CHAR(1)         DEFAULT (' ')    NOT NULL,
    BACK_COLOR               NUMBER(10)      DEFAULT (0)      NOT NULL,
    REQUIRED_FLAG            CHAR(1)         DEFAULT (' ')    NOT NULL
)TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWEMSTPSTS ADD (
CONSTRAINT MWEMSTPSTS_PK
PRIMARY KEY
(
    FACTORY,
    WORK_PROC_TYPE,
    STEP_ID,
    STATUS
)USING INDEX TABLESPACE MESPLUS_IDX_TS);

/* MWEMSTPACT : Work Process Step and Action Relation */
CREATE TABLE MWEMSTPACT
(
    CREATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    WORK_PROC_TYPE           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_ID                  VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    POINT_TYPE               CHAR(1)         DEFAULT (' ')    NOT NULL,
    ACTION_ID                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    PARENT_PATH              VARCHAR2(1000)  DEFAULT (' ')    NOT NULL,
    ACT_DEPTH                NUMBER(2)       DEFAULT (0)      NOT NULL,
    ACT_SEQ                  NUMBER(2)       DEFAULT (0)      NOT NULL,
    CONTINUE_TYPE            CHAR(1)         DEFAULT (' ')    NOT NULL
)TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWEMSTPACT ADD (
CONSTRAINT MWEMSTPACT_PK
PRIMARY KEY
(
    FACTORY,
    WORK_PROC_TYPE,
    STEP_ID,
    POINT_TYPE,
    ACTION_ID,
    PARENT_PATH
)USING INDEX TABLESPACE MESPLUS_IDX_TS);

/* MWEMACTDEF : Work Process Action Definition */
CREATE TABLE MWEMACTDEF
(
    CREATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    WORK_PROC_TYPE           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    ACTION_ID                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    ACTION_DESC              VARCHAR2(200)   DEFAULT (' ')    NOT NULL,
    ACTION_TYPE              CHAR(1)         DEFAULT (' ')    NOT NULL
)TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWEMACTDEF ADD (
CONSTRAINT MWEMACTDEF_PK
PRIMARY KEY
(
    FACTORY,
    WORK_PROC_TYPE,
    ACTION_ID
)USING INDEX TABLESPACE MESPLUS_IDX_TS);

/* MWEMACTACT : Work Process Action ID and Action Relation */
CREATE TABLE MWEMACTACT
(
    CREATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    WORK_PROC_TYPE           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    ACTION_ID                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TF_FLAG                  CHAR(1)         DEFAULT (' ')    NOT NULL,
    TRAN_CODE                VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    TRAN_COMMENT             VARCHAR2(400)   DEFAULT (' ')    NOT NULL,
    MULTI_TR_FLAG            CHAR(1)         DEFAULT (' ')    NOT NULL,
    DATA_1                   VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_2                   VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_3                   VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_4                   VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_5                   VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_6                   VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_7                   VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_8                   VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_9                   VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_10                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_11                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_12                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_13                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_14                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_15                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_16                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_17                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_18                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_19                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_20                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_21                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_22                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_23                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_24                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_25                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_26                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_27                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_28                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_29                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_30                  VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    LONG_DATA_1              VARCHAR2(1000)  DEFAULT (' ')    NOT NULL,
    LONG_DATA_2              VARCHAR2(1000)  DEFAULT (' ')    NOT NULL,
    LONG_DATA_3              VARCHAR2(1000)  DEFAULT (' ')    NOT NULL
)TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWEMACTACT ADD (
CONSTRAINT MWEMACTACT_PK
PRIMARY KEY
(
    FACTORY,
    WORK_PROC_TYPE,
    ACTION_ID,
    TF_FLAG
)USING INDEX TABLESPACE MESPLUS_IDX_TS);

/* MWEMACTCND : Work Process Action Condition */
CREATE TABLE MWEMACTCND
(
    CREATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    WORK_PROC_TYPE           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    ACTION_ID                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    SEQ_NO                   NUMBER(6)       DEFAULT(0)       NOT NULL,
    AND_OR                   VARCHAR2(3)     DEFAULT(' ')     NOT NULL,
    L_BRACKET                VARCHAR2(10)    DEFAULT(' ')     NOT NULL,
    COND_TYPE                VARCHAR2(10)    DEFAULT(' ')     NOT NULL,
    FIELD_NAME_1             VARCHAR2(100)   DEFAULT(' ')     NOT NULL,
    FIELD_NAME_2             VARCHAR2(100)   DEFAULT(' ')     NOT NULL,
    SQL_FIELD                VARCHAR2(4000)  DEFAULT(' ')     NOT NULL,
    OPERATOR                 VARCHAR2(10)    DEFAULT(' ')     NOT NULL,
    VALUE_TYPE               VARCHAR2(10)    DEFAULT(' ')     NOT NULL,
    VALUE_1                  VARCHAR2(4000)  DEFAULT(' ')     NOT NULL,
    VALUE_2                  VARCHAR2(4000)  DEFAULT(' ')     NOT NULL,
    R_BRACKET                VARCHAR2(10)    DEFAULT(' ')     NOT NULL
)TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWEMACTCND ADD (
CONSTRAINT MWEMACTCND_PK
PRIMARY KEY
(
    FACTORY,
    WORK_PROC_TYPE,
    ACTION_ID,
    SEQ_NO
)USING INDEX TABLESPACE MESPLUS_IDX_TS);

/* MWEMPRCDEF : Work Process Definition */
CREATE TABLE MWEMPRCDEF
(
    CREATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    WORK_PROC_TYPE           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    PROC_ID                  VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    PROC_DESC                VARCHAR2(200)   DEFAULT (' ')    NOT NULL,
    TITLE                    VARCHAR2(50)    DEFAULT (' ')    NOT NULL,
    ID_GEN_RULE              VARCHAR2(30)    DEFAULT (' ')    NOT NULL
)TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWEMPRCDEF ADD (
CONSTRAINT MWEMPRCDEF_PK
PRIMARY KEY
(
    FACTORY,
    WORK_PROC_TYPE,
    PROC_ID
)USING INDEX TABLESPACE MESPLUS_IDX_TS);

/* MWEMPRCSTP : Work Process and Step Relation */
CREATE TABLE MWEMPRCSTP
(
    CREATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    WORK_PROC_TYPE           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    PROC_ID                  VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_ID                  VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_SEQ                 NUMBER(2)       DEFAULT (0)      NOT NULL,
    OPTIONAL_FLAG            CHAR(1)         DEFAULT (' ')    NOT NULL,
    ARBITRARY_FLAG           CHAR(1)         DEFAULT (' ')    NOT NULL,
    INPUT_APPROVER_FLAG      CHAR(1)         DEFAULT (' ')    NOT NULL,
    STEP_GROUP               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    MIN_PROC_STEP_COUNT      NUMBER(2)       DEFAULT (0)      NOT NULL,
    NOTIFY_ALARM_ID          VARCHAR2(30)    DEFAULT (' ')    NOT NULL
)TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWEMPRCSTP ADD (
CONSTRAINT MWEMPRCSTP_PK
PRIMARY KEY
(
    FACTORY,
    WORK_PROC_TYPE,
    PROC_ID,
    STEP_ID
)USING INDEX TABLESPACE MESPLUS_IDX_TS);

/* MWEMPRCUSR : Work Process Step and User Relation */
CREATE TABLE MWEMPRCUSR
(
    CREATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    WORK_PROC_TYPE           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    PROC_ID                  VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_ID                  VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    USER_TYPE                CHAR(1)         DEFAULT (' ')    NOT NULL,
    USER_ID                  VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    ASSIGN_OPTION            VARCHAR2(30)    DEFAULT (' ')    NOT NULL
)TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWEMPRCUSR ADD (
CONSTRAINT MWEMPRCUSR_PK
PRIMARY KEY
(
    FACTORY,
    WORK_PROC_TYPE,
    PROC_ID,
    STEP_ID,
    USER_TYPE,
    USER_ID
)USING INDEX TABLESPACE MESPLUS_IDX_TS);

/* MWEMEVNSTS : Work Process Event Status */
CREATE TABLE MWEMEVNSTS
(
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    PROC_EVENT_ID            VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    PROC_EVENT_DESC          VARCHAR2(200)   DEFAULT (' ')    NOT NULL,
    WORK_PROC_TYPE           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    PROC_ID                  VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_ID                  VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    /* C - Create, P - Processing, L - Close, A - Arbitrary */
    PROC_STATUS              CHAR(1)         DEFAULT (' ')    NOT NULL,
    REPORT_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    REPORT_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    LAST_STEP_ID             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LAST_STEP_APPROVER       VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    LAST_STEP_FINISH_TIME    VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    STEP_APPROVER_TYPE       CHAR(1)         DEFAULT (' ')    NOT NULL,
    STEP_APPROVER            VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LAST_TRAN_TIME           VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    LAST_TRAN_USER_ID        VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    LAST_COMMENT             VARCHAR2(400)   DEFAULT (' ')    NOT NULL,
    LAST_HIST_SEQ            NUMBER(10)      DEFAULT (0)      NOT NULL,
    LAST_ACTIVE_HIST_SEQ     NUMBER(10)      DEFAULT (0)      NOT NULL
)TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWEMEVNSTS ADD (
CONSTRAINT MWEMEVNSTS_PK
PRIMARY KEY
(
    FACTORY,
    PROC_EVENT_ID
)USING INDEX TABLESPACE MESPLUS_IDX_TS);

/* MWEMEVNSVL : Work Process Event Status Value */
CREATE TABLE MWEMEVNSVL
(
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    PROC_EVENT_ID            VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STATUS                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    ST_VALUE                 VARCHAR2(4000)  DEFAULT (' ')    NOT NULL
)TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWEMEVNSVL ADD (
CONSTRAINT MWEMEVNSVL_PK
PRIMARY KEY
(
    FACTORY,
    PROC_EVENT_ID,
    STATUS
)USING INDEX TABLESPACE MESPLUS_IDX_TS);

/* MWEMEVNHIS : Work Process Event History */
CREATE TABLE MWEMEVNHIS
(
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    PROC_EVENT_ID            VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    HIST_SEQ                 NUMBER(10)      DEFAULT (0)      NOT NULL,
    PROC_EVENT_DESC          VARCHAR2(200)   DEFAULT (' ')    NOT NULL,
    WORK_PROC_TYPE           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    PROC_ID                  VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_ID                  VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    /* C - Create, P - Processing, L - Close, A - Arbitrary, S - Skip */
    PROC_STATUS              CHAR(1)         DEFAULT (' ')    NOT NULL,
    REPORT_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    REPORT_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    LAST_STEP_ID             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LAST_STEP_APPROVER       VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    LAST_STEP_FINISH_TIME    VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    STEP_APPROVER_TYPE       CHAR(1)         DEFAULT (' ')    NOT NULL,
    STEP_APPROVER            VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_TIME                VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    TRAN_USER_ID             VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    TRAN_COMMENT             VARCHAR2(400)   DEFAULT (' ')    NOT NULL,
    PREV_ACTIVE_HIST_SEQ     NUMBER(10)      DEFAULT (0)      NOT NULL,
    HIST_DEL_FLAG            CHAR(1)         DEFAULT (' ')    NOT NULL,
    HIST_DEL_TIME            VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    HIST_DEL_USER_ID         VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    HIST_DEL_COMMENT         VARCHAR2(400)   DEFAULT (' ')    NOT NULL
)TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWEMEVNHIS ADD (
CONSTRAINT MWEMEVNHIS_PK
PRIMARY KEY
(
    FACTORY,
    PROC_EVENT_ID,
    HIST_SEQ
)USING INDEX TABLESPACE HISTORY_IDX_TS);

/* MWEMEVNSVH : Work Process Event Status Value History */
CREATE TABLE MWEMEVNSVH
(
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    PROC_EVENT_ID            VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    HIST_SEQ                 NUMBER(10)      DEFAULT (0)      NOT NULL,
    STATUS                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    ST_VALUE                 VARCHAR2(4000)  DEFAULT (' ')    NOT NULL
)TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWEMEVNSVH ADD (
CONSTRAINT MWEMEVNSVH_PK
PRIMARY KEY
(
    FACTORY,
    PROC_EVENT_ID,
    HIST_SEQ,
    STATUS
)USING INDEX TABLESPACE HISTORY_IDX_TS);


DROP TABLE MWIPLYDDEF CASCADE CONSTRAINT PURGE;
/* MWIPLYDDEF : Low Yield Definition */
CREATE TABLE MWIPLYDDEF
(
    FACTORY                   VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    MAT_ID                    VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    MAT_VER                   NUMBER(6)       DEFAULT (0)      NOT NULL,
    FLOW                      VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    FLOW_SEQ_NUM              NUMBER(6)       DEFAULT (0)      NOT NULL,
    OPER                      VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    RES_ID                    VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    SUBRES_ID                 VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    LOT_CMF_1                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOT_CMF_2                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOT_CMF_3                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOT_CMF_4                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOT_CMF_5                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOT_CMF_6                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOT_CMF_7                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOT_CMF_8                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOT_CMF_9                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOT_CMF_10                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOT_CMF_11                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOT_CMF_12                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOT_CMF_13                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOT_CMF_14                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOT_CMF_15                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOT_CMF_16                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOT_CMF_17                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOT_CMF_18                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOT_CMF_19                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOT_CMF_20                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    KEY_CODE                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    YIELD_TYPE                VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    CV_TYPE                   VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    UNIT                      VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    UNIT_TYPE                 VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    AQL_TYPE                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    YIELD_BASE                VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    BASE_OPER                 VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    BASE_COLUMN               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CHECK_TYPE                VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    TOT_UPPER_YIELD           NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    TOT_LOWER_YIELD           NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    ALARM_ID                  VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    PROTECT_END_FLAG          CHAR(1 )        DEFAULT (' ')    NOT NULL,
    DESCRIPTION               VARCHAR2(200)   DEFAULT (' ')    NOT NULL,
    CREATE_TIME               VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    CREATE_USER               VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    UPDATE_TIME               VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    UPDATE_USER               VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    LOW_YIELD_CMF_1           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOW_YIELD_CMF_2           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOW_YIELD_CMF_3           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOW_YIELD_CMF_4           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOW_YIELD_CMF_5           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOW_YIELD_CMF_6           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOW_YIELD_CMF_7           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOW_YIELD_CMF_8           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOW_YIELD_CMF_9           VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOW_YIELD_CMF_10          VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOW_YIELD_CMF_11          VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOW_YIELD_CMF_12          VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOW_YIELD_CMF_13          VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOW_YIELD_CMF_14          VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOW_YIELD_CMF_15          VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOW_YIELD_CMF_16          VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOW_YIELD_CMF_17          VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOW_YIELD_CMF_18          VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOW_YIELD_CMF_19          VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    LOW_YIELD_CMF_20          VARCHAR2(30)    DEFAULT (' ')    NOT NULL
)
TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPLYDDEF ADD (
CONSTRAINT MWIPLYDDEF_PK
PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    FLOW_SEQ_NUM,
    OPER,
    RES_ID,
    SUBRES_ID,
    LOT_CMF_1,
    LOT_CMF_2,
    LOT_CMF_3,
    LOT_CMF_4,
    LOT_CMF_5,
    LOT_CMF_6,
    LOT_CMF_7,
    LOT_CMF_8,
    LOT_CMF_9,
    LOT_CMF_10,
    LOT_CMF_11,
    LOT_CMF_12,
    LOT_CMF_13,
    LOT_CMF_14,
    LOT_CMF_15,
    LOT_CMF_16,
    LOT_CMF_17,
    LOT_CMF_18,
    LOT_CMF_19,
    LOT_CMF_20,
    KEY_CODE
)USING INDEX TABLESPACE MESPLUS_IDX_TS);


ALTER TABLE MTMPATRHIS ADD TRAN_USER_ID           VARCHAR2(20)       DEFAULT(' ')    NOT NULL;


/*==== BAT(Batch Process Management) ====*/
/* MBATPRCDEF : Batch Process Definition */
CREATE TABLE MBATPRCDEF
(
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    JOB_PROC_ID               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    JOB_PROC_DESC             VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* same crontab definition */
    PROC_CYCLE                  VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    SERVICE_MODULE              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SERVICE_NAME                VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    /* S : Single Process, M : Multi Process */
    PROC_METHOD                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    COMPLETE_ALARM_ID           VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    JOB_PRIORITY               NUMBER(3)        DEFAULT(0)      NOT NULL,
    MES_CHANNEL                 VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    ACTIVATE_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    APPLY_START_TIME            VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    APPLY_END_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    JOB_RUN_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBATPRCDEF
ADD CONSTRAINT MBATPRCDEF_PK PRIMARY KEY
(
    JOB_PROC_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

CREATE INDEX MBATPRCDEF_IDX_1 ON MBATPRCDEF
(
    ACTIVATE_FLAG,
    APPLY_START_TIME,
    APPLY_END_TIME
) TABLESPACE MESPLUS_IDX_TS; 

/* MBATPRCSTS : Batch Process Status */
CREATE TABLE MBATPRCSTS
(
    JOB_PROC_ID               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PROC_RUN_SUBNO              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LAST_HIST_SEQ               NUMBER(10)       DEFAULT(0)      NOT NULL,
    START_TIME                  VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    END_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    ELAPSED_TIME                NUMBER(10, 3)    DEFAULT(0)      NOT NULL,
    /* P : Process, S : Success, F : Fail */
    STATUS_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    ERROR_MSG                   VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    DB_ERROR_MSG                VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    PROC_KEY_1                  VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    PROC_KEY_2                  VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    PROC_KEY_3                  VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    PROC_KEY_4                  VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    PROC_KEY_5                  VARCHAR2(100)    DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBATPRCSTS
ADD CONSTRAINT MBATPRCSTS_PK PRIMARY KEY
(
    JOB_PROC_ID,
    PROC_RUN_SUBNO
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MBATPRCHIS : Batch Process History */
CREATE TABLE MBATPRCHIS
(
    JOB_PROC_ID               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PROC_RUN_SUBNO              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    START_TIME                  VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    END_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    ELAPSED_TIME                NUMBER(10, 3)    DEFAULT(0)      NOT NULL,
    /* P : Process, S : Success, F : Fail */
    STATUS_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    ERROR_MSG                   VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    DB_ERROR_MSG                VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    PROC_KEY_1                  VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    PROC_KEY_2                  VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    PROC_KEY_3                  VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    PROC_KEY_4                  VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    PROC_KEY_5                  VARCHAR2(100)    DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MBATPRCHIS
ADD CONSTRAINT MBATPRCHIS_PK PRIMARY KEY
(
    JOB_PROC_ID,
    PROC_RUN_SUBNO,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

