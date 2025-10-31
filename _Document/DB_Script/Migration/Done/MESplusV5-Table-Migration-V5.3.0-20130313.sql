/*
**
**  File Name    : MESplusV5-Table-Migration_Table.sql
**  Description  : MESplus V5 Release for Table Migration
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g / 11g
**
**  Period       : 2013.02.23 ~ ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
**  1. 2013.02.23   Aiden   Create
*/

CREATE TABLE MWIPQTMDEF_OLD AS SELECT * FROM MWIPQTMDEF;
DROP TABLE MWIPQTMDEF CASCADE CONSTRAINT PURGE;

CREATE TABLE MWIPQTMDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FROM_FACTORY                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FROM_FLOW                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FROM_FLOW_SEQ_NUM           NUMBER(6)        DEFAULT(0)      NOT NULL,
    FROM_OPER                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Queue Time Calculation Start Point. ' ' : Default. Oper Out at from oper, 'I' : Oper in at from oper, 'S' : Start at from oper, 'E' : End at from oper */
    FROM_POINT_FLAG             CHAR(1)          DEFAULT (' ')   NOT NULL,
    /* Check Queue Time Point. ' ' : Anywhere in current oper, 'I' : Oper in at current oper, 'O' : Oper out at current oper, 'S' : Start at current oper, 'E' : End at current oper */
    CHECK_POINT_FLAG            CHAR(1)          DEFAULT (' ')   NOT NULL,
    UPPER_WARN_QUE_TIME         NUMBER(10)        DEFAULT (0)     NOT NULL,
    LOWER_WARN_QUE_TIME         NUMBER(10)        DEFAULT (0)     NOT NULL,
    WARN_ALARM_ID               VARCHAR2(20)     DEFAULT (' ')   NOT NULL,
    /* MIN */
    UPPER_ERR_QUE_TIME          NUMBER(10)        DEFAULT (0)     NOT NULL,
    LOWER_ERR_QUE_TIME          NUMBER(10)        DEFAULT (0)     NOT NULL,
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
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPQTMDEF
ADD CONSTRAINT MWIPQTMDEF_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    FLOW_SEQ_NUM,
    OPER,
    FROM_FACTORY,
    FROM_FLOW,
    FROM_FLOW_SEQ_NUM,
    FROM_OPER,
    FROM_POINT_FLAG,
    CHECK_POINT_FLAG
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

INSERT INTO MWIPQTMDEF VALUE ( 
SELECT 
    FACTORY            ,
    MAT_ID             ,
    MAT_VER            ,
    FLOW               ,
    FLOW_SEQ_NUM       ,
    OPER               ,
    FACTORY            ,
    FROM_FLOW          ,
    FROM_FLOW_SEQ_NUM  ,
    FROM_OPER          ,
    FROM_POINT_FLAG    ,
    CHECK_POINT_FLAG   ,
    UPPER_WARN_QUE_TIME,
    LOWER_WARN_QUE_TIME,
    WARN_ALARM_ID      ,
    UPPER_ERR_QUE_TIME ,
    LOWER_ERR_QUE_TIME ,
    ERROR_ALARM_ID     ,
    PRIORITY           ,
    SUBLOT_FLAG        ,
    VIO_RULE_FLAG      ,
    VIO_LIMIT_NUM      ,
    SEARCH_MRG_HIS_FLAG,
    CMF_1              ,
    CMF_2              ,
    CMF_3              ,
    CMF_4              ,
    CMF_5              ,
    CMF_6              ,
    CMF_7              ,
    CMF_8              ,
    CMF_9              ,
    CMF_10             ,
    CMF_11             ,
    CMF_12             ,
    CMF_13             ,
    CMF_14             ,
    CMF_15             ,
    CMF_16             ,
    CMF_17             ,
    CMF_18             ,
    CMF_19             ,
    CMF_20             ,
    CREATE_USER_ID     ,
    CREATE_TIME        ,
    UPDATE_USER_ID     ,
    UPDATE_TIME        
FROM MWIPQTMDEF_OLD);  

CREATE TABLE MWIPQTMHIS_OLD AS SELECT * FROM MWIPQTMHIS;
DROP TABLE MWIPQTMHIS CASCADE CONSTRAINT PURGE;

CREATE TABLE MWIPQTMHIS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FROM_FACTORY                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FROM_FLOW                   VARCHAR2(20)     DEFAULT (' ')   NOT NULL,
    FROM_FLOW_SEQ_NUM           NUMBER(6)        DEFAULT (0)     NOT NULL,
    FROM_OPER                   VARCHAR2(10)     DEFAULT (' ')   NOT NULL,
    FROM_POINT_FLAG             CHAR(1)          DEFAULT (' ')   NOT NULL,
    CHECK_POINT_FLAG            CHAR(1)          DEFAULT (' ')   NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    PROCESS_LEVEL               CHAR(1)          DEFAULT(' ')    NOT NULL,
    CUR_FLOW                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CUR_FLOW_SEQ_NUM            NUMBER(6)        DEFAULT(0)      NOT NULL,
    CUR_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    QUE_TIME                    NUMBER(10)        DEFAULT(0)      NOT NULL,
    ALARM_ID                    VARCHAR2(20)     DEFAULT (' ')   NOT NULL,
    MSG                         VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    USER_GRP_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPPER_QUE_TIME              NUMBER(10)        DEFAULT (0)     NOT NULL,
    LOWER_QUE_TIME              NUMBER(10)        DEFAULT (0)     NOT NULL,
    DIFF_QUE_TIME               NUMBER(10)        DEFAULT (0)     NOT NULL,
    TRAN_CODE                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    REASON_CODE                 VARCHAR2(10)     DEFAULT (' ')   NOT NULL,
    HOLD_PASSWORD               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HOLD_PRV_GRP_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_TO_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_TO_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,
    TRAN_TO_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RET_FLOW                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RET_FLOW_SEQ_NUM            NUMBER(6)        DEFAULT(0)      NOT NULL,
    RET_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RWK_RET_CLEAR_FLAG          CHAR(1)          DEFAULT(' ')    NOT NULL,
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
    LOT_COMMENT                 VARCHAR2(400)    DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPQTMHIS
ADD CONSTRAINT MWIPQTMHIS_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    FLOW_SEQ_NUM,
    OPER, 
    FROM_FACTORY,
    FROM_FLOW, 
    FROM_FLOW_SEQ_NUM, 
    FROM_OPER,
    FROM_POINT_FLAG,
    CHECK_POINT_FLAG,
    LOT_ID,
    TRAN_TIME
) USING INDEX TABLESPACE HISTORY_IDX_TS;

INSERT INTO MWIPQTMHIS VALUE ( 
SELECT 
    FACTORY              ,
    MAT_ID               ,
    MAT_VER              ,
    FLOW                 ,
    FLOW_SEQ_NUM         ,
    OPER                 ,
    FACTORY              ,
    FROM_FLOW            ,
    FROM_FLOW_SEQ_NUM    ,
    FROM_OPER            ,
    FROM_POINT_FLAG      ,
    CHECK_POINT_FLAG     ,
    LOT_ID               ,
    TRAN_TIME            ,
    HIST_SEQ             ,
    PROCESS_LEVEL        ,
    CUR_FLOW             ,
    CUR_FLOW_SEQ_NUM     ,
    CUR_OPER             ,
    QUE_TIME             ,
    ALARM_ID             ,
    MSG                  ,
    USER_GRP_ID          ,
    UPPER_QUE_TIME       ,
    LOWER_QUE_TIME       ,
    DIFF_QUE_TIME        ,
    TRAN_CODE            ,
    REASON_CODE          ,
    HOLD_PASSWORD        ,
    HOLD_PRV_GRP_ID      ,
    TRAN_TO_FLOW         ,
    TRAN_TO_FLOW_SEQ_NUM ,
    TRAN_TO_OPER         ,
    RET_FLOW             ,
    RET_FLOW_SEQ_NUM     ,
    RET_OPER             ,
    RWK_RET_CLEAR_FLAG   ,
    CMF_1                ,
    CMF_2                ,
    CMF_3                ,
    CMF_4                ,
    CMF_5                ,
    CMF_6                ,
    CMF_7                ,
    CMF_8                ,
    CMF_9                ,
    CMF_10               ,
    CMF_11               ,
    CMF_12               ,
    CMF_13               ,
    CMF_14               ,
    CMF_15               ,
    CMF_16               ,
    CMF_17               ,
    CMF_18               ,
    CMF_19               ,
    CMF_20               ,
    LOT_COMMENT          
FROM MWIPQTMHIS_OLD);  



CREATE TABLE MWIPLOTQTM_OLD AS SELECT * FROM MWIPLOTQTM;
DROP TABLE MWIPLOTQTM CASCADE CONSTRAINT PURGE;

CREATE TABLE MWIPLOTQTM
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    FROM_FACTORY                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FROM_FLOW                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FROM_FLOW_SEQ_NUM           NUMBER(6)        DEFAULT(0)      NOT NULL,
    FROM_OPER                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    QUEUE_TIME                  NUMBER(10)       DEFAULT(0)      NOT NULL,
    NEG_QUEUE_TIME              NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* L-Lot itself, S-Split or Cut, M- Merge or Combine */
    CAL_SOURCE_FLAG             CHAR(1)          DEFAULT (' ')   NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    OPT_LEVEL                   CHAR(1)          DEFAULT (' ')   NOT NULL,
    OPER_IN_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    QUEUE_TIME_FROM_OPER_IN     NUMBER(10)       DEFAULT(0)      NOT NULL,
    NEG_QUEUE_TIME_FROM_OPER_IN NUMBER(10)       DEFAULT(0)      NOT NULL,
    QUEUE_TIME_FROM_START       NUMBER(10)       DEFAULT(0)      NOT NULL,
    NEG_QUEUE_TIME_FROM_START   NUMBER(10)       DEFAULT(0)      NOT NULL,
    QUEUE_TIME_FROM_END         NUMBER(10)       DEFAULT(0)      NOT NULL,
    NEG_QUEUE_TIME_FROM_END     NUMBER(10)       DEFAULT(0)      NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPLOTQTM
ADD CONSTRAINT MWIPLOTQTM_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    FROM_FACTORY,
    FROM_FLOW,
    FROM_FLOW_SEQ_NUM,
    FROM_OPER
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

CREATE INDEX MWIPLOTQTM_IDX_1 ON MWIPLOTQTM
(
    LOT_ID,
    FROM_FACTORY,
    FROM_FLOW,
    FROM_FLOW_SEQ_NUM,
    FROM_OPER,
    OPER
) TABLESPACE MESPLUS_IDX_TS;


INSERT INTO MWIPLOTQTM VALUE ( 
SELECT 
    LOT_ID                      ,
    HIST_SEQ                    ,
    FACTORY                     ,
    FROM_FLOW                   ,
    FROM_FLOW_SEQ_NUM           ,
    FROM_OPER                   ,
    QUEUE_TIME                  ,
    NEG_QUEUE_TIME              ,
    CAL_SOURCE_FLAG             ,
    FACTORY                     ,
    MAT_ID                      ,
    MAT_VER                     ,
    FLOW                        ,
    FLOW_SEQ_NUM                ,
    OPER                        ,
    OPT_LEVEL                   ,
    OPER_IN_TIME                ,
    QUEUE_TIME_FROM_OPER_IN     ,
    NEG_QUEUE_TIME_FROM_OPER_IN ,
    QUEUE_TIME_FROM_START       ,
    NEG_QUEUE_TIME_FROM_START   ,
    QUEUE_TIME_FROM_END         ,
    NEG_QUEUE_TIME_FROM_END
FROM MWIPLOTQTM_OLD);  


CREATE INDEX MWIPLOTMVH_IDX_2 ON MWIPLOTMVH
(
    LOT_ID,
    HIST_DEL_FLAG,
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    FLOW_SEQ_NUM,
    OPER
) TABLESPACE HISTORY_IDX_TS;

ALTER TABLE MEDCCHRDEF ADD CHAR_TYPE    CHAR(1)         DEFAULT(' ')    NOT NULL;
ALTER TABLE MEDCCHRDEF ADD VALID_TABLE  VARCHAR2(20)    DEFAULT(' ')    NOT NULL;


CREATE TABLE MWIPBINSHS_OLD AS SELECT * FROM MWIPBINSHS;
DROP TABLE MWIPBINSHS CASCADE CONSTRAINT PURGE;

CREATE TABLE MWIPBINSHS
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    BIN_COL_SEQ                 NUMBER(5)        DEFAULT(0)      NOT NULL,
    BIN_SEQ                     NUMBER(3)        DEFAULT(0)      NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BIN_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_VERSION                 NUMBER(5)        DEFAULT(0)      NOT NULL,
    BIN_UNIT                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BIN_PROMPT                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_PROMPT_DESC             VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    BIN_QTY                     NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    BIN_TYPE                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOGICAL_BIN_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    SPLIT_TYPE                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SPLIT_BY_BIN_SEQ            NUMBER(3)        DEFAULT(0)      NOT NULL,
    USE_BIN_PROMPT_FAIL_REASON  CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEEP_LOT_QTY_FAIL           CHAR(1)          DEFAULT(' ')    NOT NULL,
    FAIL_REASON_CODE            VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHILD_LOT_ID                VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    CHILD_CUST_LOT_ID           VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    CHILD_MAT_ID                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHILD_MAT_VER               NUMBER(6)        DEFAULT(0)      NOT NULL,
    CHILD_FLOW                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHILD_FLOW_SEQ_NUM          NUMBER(6)        DEFAULT(0)      NOT NULL,
    CHILD_OPER                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHILD_QTY_1                 NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    CHILD_QTY_2                 NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    CHILD_QTY_3                 NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    CHILD_LOT_TYPE              CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHILD_LOT_PRIORITY          CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHILD_CREATE_CODE           VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHILD_OWNER_CODE            VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHILD_CRR_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
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

ALTER TABLE MWIPBINSHS
ADD CONSTRAINT MWIPBINSHS_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    BIN_COL_SEQ,
    BIN_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

INSERT INTO MWIPBINSHS VALUE ( 
SELECT 
    A.LOT_ID                      ,
    A.HIST_SEQ                    ,
    A.BIN_COL_SEQ                 ,
    A.BIN_SEQ                     ,
    A.FACTORY                     ,
    A.BIN_ID                      ,
    A.BIN_VERSION                 ,
    B.BIN_UNIT                    ,
    A.BIN_PROMPT                  ,
    C.BIN_PROMPT_DESC             ,
    A.BIN_QTY                     ,
    A.BIN_TYPE                    ,
    A.LOGICAL_BIN_FLAG            ,
    A.SPLIT_TYPE                  ,
    A.SPLIT_BY_BIN_SEQ            ,
    A.USE_BIN_PROMPT_FAIL_REASON  ,
    A.KEEP_LOT_QTY_FAIL           ,
    A.FAIL_REASON_CODE            ,
    A.CHILD_LOT_ID                ,
    A.CHILD_CUST_LOT_ID           ,
    A.CHILD_MAT_ID                ,
    A.CHILD_MAT_VER               ,
    A.CHILD_FLOW                  ,
    A.CHILD_FLOW_SEQ_NUM          ,
    A.CHILD_OPER                  ,
    A.CHILD_QTY_1                 ,
    A.CHILD_QTY_2                 ,
    A.CHILD_QTY_3                 ,
    A.CHILD_LOT_TYPE              ,
    A.CHILD_LOT_PRIORITY          ,
    A.CHILD_CREATE_CODE           ,
    A.CHILD_OWNER_CODE            ,
    A.CHILD_CRR_ID                ,
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
FROM MWIPBINSHS_OLD A, MWIPBINHIS B, MWIPBINGRD C
WHERE A.LOT_ID = B.LOT_ID AND A.HIST_SEQ = B.HIST_SEQ AND A.BIN_COL_SEQ = B.BIN_COL_SEQ
AND A.FACTORY = C.FACTORY AND A.BIN_ID = C.BIN_ID AND A.BIN_VERSION = C.BIN_VERSION AND A.BIN_SEQ = C.BIN_SEQ AND B.BIN_UNIT = C.BIN_UNIT
);


CREATE TABLE MWIPBINSSH_OLD AS SELECT * FROM MWIPBINSSH;
DROP TABLE MWIPBINSSH CASCADE CONSTRAINT PURGE;

CREATE TABLE MWIPBINSSH
(
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    BIN_COL_SEQ                 NUMBER(5)        DEFAULT(0)      NOT NULL,
    BIN_SEQ                     NUMBER(3)        DEFAULT(0)      NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
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
    A.BIN_ID                      ,
    A.BIN_VERSION                 ,
    B.BIN_UNIT                    ,
    A.BIN_PROMPT                  ,
    C.BIN_PROMPT_DESC             ,
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
FROM MWIPBINSSH_OLD A, MWIPBINHSS B, MWIPBINGRD C
WHERE A.SUBLOT_ID = B.SUBLOT_ID AND A.HIST_SEQ = B.HIST_SEQ AND A.BIN_COL_SEQ = B.BIN_COL_SEQ
AND A.FACTORY = C.FACTORY AND A.BIN_ID = C.BIN_ID AND A.BIN_VERSION = C.BIN_VERSION AND A.BIN_SEQ = C.BIN_SEQ AND B.BIN_UNIT = C.BIN_UNIT
);


ALTER TABLE MWIPBINHIS ADD BIN_RESULT_FLAG  CHAR(1)         DEFAULT(' ')    NOT NULL;

DECLARE
     V_COUNT    NUMBER(6);
BEGIN
	 FOR REC IN (
			SELECT *
			FROM MWIPBINHIS
	 )
     LOOP
        BEGIN
             V_COUNT := 0;
             
            SELECT COUNT(*) INTO V_COUNT FROM (
              SELECT LOW_YIELD_FLAG FROM MWIPBINHIS 
              WHERE LOW_YIELD_FLAG = 'Y' AND TRAN_ALARM_ID <> ' ' 
              AND LOT_ID = REC.LOT_ID AND HIST_SEQ = REC.HIST_SEQ AND BIN_COL_SEQ = REC.BIN_COL_SEQ
            UNION
              SELECT LOW_YIELD_FLAG FROM MWIPBINSHS
              WHERE LOW_YIELD_FLAG = 'Y' AND TRAN_CODE <> ' ' 
              AND LOT_ID = REC.LOT_ID AND HIST_SEQ = REC.HIST_SEQ AND BIN_COL_SEQ = REC.BIN_COL_SEQ
            UNION
              SELECT LOW_YIELD_FLAG FROM MWIPBINHSS
              WHERE LOW_YIELD_FLAG = 'Y' AND TRAN_ALARM_ID <> ' ' 
              AND LOT_ID = REC.LOT_ID AND HIST_SEQ = REC.HIST_SEQ AND BIN_COL_SEQ = REC.BIN_COL_SEQ
            UNION
              SELECT A.LOW_YIELD_FLAG FROM MWIPBINSSH A, MWIPBINHSS B
              WHERE A.LOW_YIELD_FLAG = 'Y' AND A.TRAN_CODE <> ' ' 
              AND A.SUBLOT_ID = B.SUBLOT_ID AND A.HIST_SEQ = B.HIST_SEQ AND A.BIN_COL_SEQ = B.BIN_COL_SEQ
              AND B.LOT_ID = REC.LOT_ID AND B.HIST_SEQ = REC.HIST_SEQ AND B.BIN_COL_SEQ = REC.BIN_COL_SEQ
            );
            
            IF V_COUNT > 0 THEN
                UPDATE MWIPBINHIS SET BIN_RESULT_FLAG = 'F' 
                WHERE LOT_ID = REC.LOT_ID AND HIST_SEQ = REC.HIST_SEQ AND BIN_COL_SEQ = REC.BIN_COL_SEQ;
            ELSE
                UPDATE MWIPBINHIS SET BIN_RESULT_FLAG = 'P' 
                WHERE LOT_ID = REC.LOT_ID AND HIST_SEQ = REC.HIST_SEQ AND BIN_COL_SEQ = REC.BIN_COL_SEQ;
            END IF;
        END;
     END LOOP;
END ;
/

/* MWIPBINSPH : BIN Collection Split History */
CREATE TABLE MWIPBINSPH
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    BIN_LOT_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    BIN_LOT_HIST_SEQ            NUMBER(10)       DEFAULT(0)      NOT NULL,
    BIN_LOT_SPLIT_HIST_SEQ      NUMBER(10)       DEFAULT(0)      NOT NULL,
    BIN_COL_SEQ                 NUMBER(5)        DEFAULT(0)      NOT NULL,
    BIN_SEQ                     NUMBER(3)        DEFAULT(0)      NOT NULL,
    QTY_1                       NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    COPY_FLAG                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPBINSPH
ADD CONSTRAINT MWIPBINSPH_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MWIPBINSPH_IDX_1 ON MWIPBINSPH
(
    BIN_LOT_ID,
    BIN_LOT_HIST_SEQ,
    HIST_DEL_FLAG
) TABLESPACE HISTORY_IDX_TS;

ALTER TABLE MWIPCALDEF ADD CAL_GRP_1    VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_GRP_2    VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_GRP_3    VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_GRP_4    VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_GRP_5    VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_GRP_6    VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_GRP_7    VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_GRP_8    VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_GRP_9    VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_GRP_10   VARCHAR2(30)     DEFAULT(' ')    NOT NULL;

ALTER TABLE MWIPCALDEF ADD CAL_CMF_1    VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_CMF_2    VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_CMF_3    VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_CMF_4    VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_CMF_5    VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_CMF_6    VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_CMF_7    VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_CMF_8    VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_CMF_9    VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_CMF_10   VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_CMF_11   VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_CMF_12   VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_CMF_13   VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_CMF_14   VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_CMF_15   VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_CMF_16   VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_CMF_17   VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_CMF_18   VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_CMF_19   VARCHAR2(30)     DEFAULT(' ')    NOT NULL;
ALTER TABLE MWIPCALDEF ADD CAL_CMF_20   VARCHAR2(30)     DEFAULT(' ')    NOT NULL;

ALTER TABLE MSPMRELCHR MODIFY TARGET_VALUE          VARCHAR2(400)   DEFAULT (' ');
ALTER TABLE MSPMRELCHR MODIFY CUST_TARGET_VALUE     VARCHAR2(400)   DEFAULT (' ');

ALTER TABLE MWIPPRIDEF MODIFY CHECK_ITEM            VARCHAR2(100)   DEFAULT (' ');

ALTER TABLE MATRNAMHIS ADD TRAN_USER_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL;



/* MWIPLYDCOD : Low Yield By Code Definition */
CREATE TABLE MWIPLYDCOD
(
    FACTORY                 VARCHAR2(10)    DEFAULT(' ')    NOT NULL,
    MAT_ID                  VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    MAT_VER                 NUMBER(6,0)     DEFAULT(0)      NOT NULL,
    FLOW                    VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM            NUMBER(6,0)     DEFAULT(0)      NOT NULL,
    OPER                    VARCHAR2(10)    DEFAULT(' ')    NOT NULL,
    RES_ID                  VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    SUBRES_ID               VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    LOT_CMF_1               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    LOT_CMF_2               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    LOT_CMF_3               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    LOT_CMF_4               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    LOT_CMF_5               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    LOT_CMF_6               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    LOT_CMF_7               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    LOT_CMF_8               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    LOT_CMF_9               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    LOT_CMF_10              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    LOT_CMF_11              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    LOT_CMF_12              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    LOT_CMF_13              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    LOT_CMF_14              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    LOT_CMF_15              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    LOT_CMF_16              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    LOT_CMF_17              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    LOT_CMF_18              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    LOT_CMF_19              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    LOT_CMF_20              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    KEY_CODE                VARCHAR2(100)   DEFAULT(' ')    NOT NULL,
    CODE                    VARCHAR2(10)    DEFAULT(' ')    NOT NULL,
    CODE_UPPER_YIELD        NUMBER(10,3)    DEFAULT(0)      NOT NULL,
    CODE_LOW_YIELD          NUMBER(10,3)    DEFAULT(0)      NOT NULL,
    CODE_UNIT_TYPE          VARCHAR2(10)    DEFAULT(' ')    NOT NULL,
    CODE_AQL_TYPE           VARCHAR2(10)    DEFAULT(' ')    NOT NULL,
    CHECK_RANGE             NUMBER(6,0)     DEFAULT(0)      NOT NULL,
    CHECK_BEFORE_DAY        NUMBER(6,0)     DEFAULT(0)      NOT NULL,
    AFFECT_RANGE_BEFORE     NUMBER(6,0)     DEFAULT(0)      NOT NULL,
    AFFECT_RANGE_AFTER      NUMBER(6,0)     DEFAULT(0)      NOT NULL,
    ALARM_ID                VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    PROTECT_END_FLAG        CHAR(1)         DEFAULT(' ')    NOT NULL,
    DESCRIPTION             VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    CREATE_TIME             VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    CREATE_USER             VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    UPDATE_TIME             VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    UPDATE_USER             VARCHAR2(20)    DEFAULT(' ')    NOT NULL
)TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPLYDCOD ADD (
CONSTRAINT MWIPLYDCOD_PK
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
    KEY_CODE,
    CODE
)USING INDEX TABLESPACE MESPLUS_IDX_TS);

/* MWIPLYDDEF : Low Yield Definition */
CREATE TABLE MWIPLYDDEF
(
    FACTORY                 VARCHAR2(10)        DEFAULT(' ')    NOT NULL,
    MAT_ID                  VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    MAT_VER                 NUMBER(6,0)         DEFAULT(0)      NOT NULL,
    FLOW                    VARCHAR2(20)        DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM            NUMBER(6,0)         DEFAULT(0)      NOT NULL,
    OPER                    VARCHAR2(10)        DEFAULT(' ')    NOT NULL,
    RES_ID                  VARCHAR2(20)        DEFAULT(' ')    NOT NULL,
    SUBRES_ID               VARCHAR2(20)        DEFAULT(' ')    NOT NULL,
    LOT_CMF_1               VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOT_CMF_2               VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOT_CMF_3               VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOT_CMF_4               VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOT_CMF_5               VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOT_CMF_6               VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOT_CMF_7               VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOT_CMF_8               VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOT_CMF_9               VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOT_CMF_10              VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOT_CMF_11              VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOT_CMF_12              VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOT_CMF_13              VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOT_CMF_14              VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOT_CMF_15              VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOT_CMF_16              VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOT_CMF_17              VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOT_CMF_18              VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOT_CMF_19              VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOT_CMF_20              VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    KEY_CODE                VARCHAR2(100)       DEFAULT(' ')    NOT NULL,
    YIELD_TYPE              VARCHAR2(10)        DEFAULT(' ')    NOT NULL,
    UNIT                    VARCHAR2(10)        DEFAULT(' ')    NOT NULL,
    UNIT_TYPE               VARCHAR2(10)        DEFAULT(' ')    NOT NULL,
    AQL_TYPE                VARCHAR2(10)        DEFAULT(' ')    NOT NULL,
    YIELD_BASE              VARCHAR2(20)        DEFAULT(' ')    NOT NULL,
    BASE_OPER               VARCHAR2(10)        DEFAULT(' ')    NOT NULL,
    CHECK_TYPE              VARCHAR2(10)        DEFAULT(' ')    NOT NULL,
    TOT_UPPER_YIELD         NUMBER(10,3)        DEFAULT(0)      NOT NULL,
    TOT_LOWER_YIELD         NUMBER(10,3)        DEFAULT(0)      NOT NULL,
    ALARM_ID                VARCHAR2(20)        DEFAULT(' ')    NOT NULL,
    PROTECT_END_FLAG        CHAR(1)             DEFAULT(' ')    NOT NULL,
    DESCRIPTION             VARCHAR2(50)        DEFAULT(' ')    NOT NULL,
    CREATE_TIME             VARCHAR2(14)        DEFAULT(' ')    NOT NULL,
    CREATE_USER             VARCHAR2(20)        DEFAULT(' ')    NOT NULL,
    UPDATE_TIME             VARCHAR2(14)        DEFAULT(' ')    NOT NULL,
    UPDATE_USER             VARCHAR2(20)        DEFAULT(' ')    NOT NULL,
    LOW_YIELD_CMF_1         VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOW_YIELD_CMF_2         VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOW_YIELD_CMF_3         VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOW_YIELD_CMF_4         VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOW_YIELD_CMF_5         VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOW_YIELD_CMF_6         VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOW_YIELD_CMF_7         VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOW_YIELD_CMF_8         VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOW_YIELD_CMF_9         VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOW_YIELD_CMF_10        VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOW_YIELD_CMF_11        VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOW_YIELD_CMF_12        VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOW_YIELD_CMF_13        VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOW_YIELD_CMF_14        VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOW_YIELD_CMF_15        VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOW_YIELD_CMF_16        VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOW_YIELD_CMF_17        VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOW_YIELD_CMF_18        VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOW_YIELD_CMF_19        VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    LOW_YIELD_CMF_20        VARCHAR2(30)        DEFAULT(' ')    NOT NULL
)TABLESPACE MESPLUS_DATA_TS;

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

