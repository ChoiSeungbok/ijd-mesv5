/*
**
**  File Name    : MESplusV5-Table-Migration_Table.sql
**  Description  : MESplus V5 Release for Table Migration
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g / 11g
**
**  Period       : 2010.12.11 ~ ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
*/


/* MWIPSTPDEF */
CREATE TABLE MWIPSTPDEF
(
  FACTORY             VARCHAR2(10 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP                VARCHAR2(10 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_DESC           VARCHAR2(50 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_GRP_1          VARCHAR2(20 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_GRP_2          VARCHAR2(20 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_GRP_3          VARCHAR2(20 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_GRP_4          VARCHAR2(20 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_GRP_5          VARCHAR2(20 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_GRP_6          VARCHAR2(20 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_GRP_7          VARCHAR2(20 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_GRP_8          VARCHAR2(20 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_GRP_9          VARCHAR2(20 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_GRP_10         VARCHAR2(20 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_CMF_1          VARCHAR2(30 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_CMF_2          VARCHAR2(30 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_CMF_3          VARCHAR2(30 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_CMF_4          VARCHAR2(30 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_CMF_5          VARCHAR2(30 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_CMF_6          VARCHAR2(30 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_CMF_7          VARCHAR2(30 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_CMF_8          VARCHAR2(30 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_CMF_9          VARCHAR2(30 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_CMF_10         VARCHAR2(30 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_CMF_11         VARCHAR2(30 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_CMF_12         VARCHAR2(30 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_CMF_13         VARCHAR2(30 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_CMF_14         VARCHAR2(30 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_CMF_15         VARCHAR2(30 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_CMF_16         VARCHAR2(30 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_CMF_17         VARCHAR2(30 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_CMF_18         VARCHAR2(30 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_CMF_19         VARCHAR2(30 BYTE)         DEFAULT (' ')                 NOT NULL,
  STEP_CMF_20         VARCHAR2(30 BYTE)         DEFAULT (' ')                 NOT NULL,
  CREATE_USER_ID      VARCHAR2(20 BYTE)         DEFAULT (' ')                 NOT NULL,
  CREATE_TIME         VARCHAR2(14 BYTE)         DEFAULT (' ')                 NOT NULL,
  UPDATE_USER_ID      VARCHAR2(20 BYTE)         DEFAULT (' ')                 NOT NULL,
  UPDATE_TIME         VARCHAR2(14 BYTE)         DEFAULT (' ')                 NOT NULL
) TABLESPACE MESPLUS_DATA_TS;


ALTER TABLE MWIPSTPDEF ADD (
  CONSTRAINT MWIPSTPDEF_PK
 PRIMARY KEY
 (FACTORY, STEP) USING INDEX TABLESPACE MESPLUS_IDX_TS);

 
/* MWIPSTPMFO */
CREATE TABLE MWIPSTPMFO
(
  FACTORY           VARCHAR2(10 BYTE)           DEFAULT (' ')                 NOT NULL,
  MAT_ID            VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  MAT_VER           NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  FLOW              VARCHAR2(20 BYTE)           DEFAULT (' ')                 NOT NULL,
  OPER              VARCHAR2(10 BYTE)           DEFAULT (' ')                 NOT NULL,
  STEP              VARCHAR2(10 BYTE)           DEFAULT (' ')                 NOT NULL,
  CREATE_USER_ID    VARCHAR2(20 BYTE)           DEFAULT (' ')                 NOT NULL,
  CREATE_TIME       VARCHAR2(14 BYTE)           DEFAULT (' ')                 NOT NULL,
  UPDATE_USER_ID    VARCHAR2(20 BYTE)           DEFAULT (' ')                 NOT NULL,
  UPDATE_TIME       VARCHAR2(14 BYTE)           DEFAULT (' ')                 NOT NULL,
  REL_LEVEL         CHAR(1 BYTE)                DEFAULT (' ')                 NOT NULL,
  SEQ_NUM           NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  PREV_STEP         VARCHAR2(10 BYTE)           DEFAULT (' ')                 NOT NULL,
  NEXT_STEP         VARCHAR2(10 BYTE)           DEFAULT (' ')                 NOT NULL,
  AUTO_START_FLAG   CHAR(1 BYTE)                DEFAULT (' ')                 NOT NULL,
  AUTO_END_FLAG     CHAR(1 BYTE)                DEFAULT (' ')                 NOT NULL,
  START_REQ_FLAG    CHAR(1 BYTE)                DEFAULT (' ')                 NOT NULL,
  END_REQ_FLAG      CHAR(1 BYTE)                DEFAULT (' ')                 NOT NULL,
  SERIAL_PROC_FLAG  CHAR(1 BYTE)                DEFAULT (' ')                 NOT NULL,
  RESV_FIELD_1      VARCHAR2(50 BYTE)           DEFAULT (' ')                 NOT NULL,
  RESV_FIELD_2      VARCHAR2(50 BYTE)           DEFAULT (' ')                 NOT NULL,
  RESV_FIELD_3      VARCHAR2(50 BYTE)           DEFAULT (' ')                 NOT NULL,
  RESV_FIELD_4      VARCHAR2(50 BYTE)           DEFAULT (' ')                 NOT NULL,
  RESV_FIELD_5      VARCHAR2(50 BYTE)           DEFAULT (' ')                 NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPSTPMFO ADD (
  CONSTRAINT MWIPSTPMFO_PK
 PRIMARY KEY
 (FACTORY, MAT_ID, MAT_VER, FLOW, OPER, STEP) USING INDEX TABLESPACE MESPLUS_IDX_TS);

 
/* MWIPSTPSTS */
CREATE TABLE MWIPSTPSTS
(
  LOT_ID                 VARCHAR2(25 BYTE)      DEFAULT (' ')                 NOT NULL,
  FACTORY                VARCHAR2(10 BYTE)      DEFAULT (' ')                 NOT NULL,
  MAT_ID                 VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  MAT_VER                NUMBER(6)              DEFAULT (0)                   NOT NULL,
  FLOW                   VARCHAR2(20 BYTE)      DEFAULT (' ')                 NOT NULL,
  FLOW_SEQ_NUM           NUMBER(6)              DEFAULT (0)                   NOT NULL,
  OPER                   VARCHAR2(10 BYTE)      DEFAULT (' ')                 NOT NULL,
  STEP                   VARCHAR2(10 BYTE)      DEFAULT (' ')                 NOT NULL,
  START_FLAG             CHAR(1 BYTE)           DEFAULT (' ')                 NOT NULL,
  END_FLAG               CHAR(1 BYTE)           DEFAULT (' ')                 NOT NULL,
  LAST_TRAN_CODE         VARCHAR2(12 BYTE)      DEFAULT (' ')                 NOT NULL,
  LAST_TRAN_TIME         VARCHAR2(14 BYTE)      DEFAULT (' ')                 NOT NULL,
  LAST_TRAN_COMMENT      VARCHAR2(400 BYTE)     DEFAULT (' ')                 NOT NULL,
  LAST_ACTIVE_HIST_SEQ   NUMBER(10)             DEFAULT (0)                   NOT NULL,
  LAST_HIST_SEQ          NUMBER(10)             DEFAULT (0)                   NOT NULL  
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPSTPSTS ADD (
  CONSTRAINT MWIPSTPSTS_PK
 PRIMARY KEY
 (LOT_ID) USING INDEX TABLESPACE MESPLUS_IDX_TS);

 
/* MWIPSTPHIS */
CREATE TABLE MWIPSTPHIS
(
  LOT_ID                 VARCHAR2(25 BYTE)      DEFAULT (' ')                 NOT NULL,
  HIST_SEQ               NUMBER(10)             DEFAULT (0)                   NOT NULL,
  TRAN_CMF_1             VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_2             VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_3             VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_4             VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_5             VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_6             VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_7             VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_8             VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_9             VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_10            VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_11            VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_12            VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_13            VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_14            VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_15            VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_16            VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_17            VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_18            VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_19            VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_20            VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_TIME              VARCHAR2(14 BYTE)      DEFAULT (' ')                 NOT NULL,
  SYS_TRAN_TIME          VARCHAR2(14 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_CODE              VARCHAR2(12 BYTE)      DEFAULT (' ')                 NOT NULL,
  FACTORY                VARCHAR2(10 BYTE)      DEFAULT (' ')                 NOT NULL,
  MAT_ID                 VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  MAT_VER                NUMBER(6)              DEFAULT (0)                   NOT NULL,
  FLOW                   VARCHAR2(20 BYTE)      DEFAULT (' ')                 NOT NULL,
  FLOW_SEQ_NUM           NUMBER(6)              DEFAULT (0)                   NOT NULL,
  OPER                   VARCHAR2(10 BYTE)      DEFAULT (' ')                 NOT NULL,
  STEP                   VARCHAR2(10 BYTE)      DEFAULT (' ')                 NOT NULL,
  START_FLAG             CHAR(1 BYTE)           DEFAULT (' ')                 NOT NULL,
  END_FLAG               CHAR(1 BYTE)           DEFAULT (' ')                 NOT NULL,
  LOT_HIST_SEQ           NUMBER(10)             DEFAULT (0)                   NOT NULL,
  OPER_TRAN_FLAG         CHAR(1 BYTE)           DEFAULT (' ')                 NOT NULL,
  TRAN_USER_ID           VARCHAR2(20 BYTE)      DEFAULT (' ')                 NOT NULL,
  TRAN_COMMENT           VARCHAR2(400 BYTE)     DEFAULT (' ')                 NOT NULL,
  HIST_DEL_FLAG          CHAR(1 BYTE)           DEFAULT (' ')                 NOT NULL,
  HIST_DEL_TIME          VARCHAR2(14 BYTE)      DEFAULT (' ')                 NOT NULL,
  HIST_DEL_USER_ID       VARCHAR2(20 BYTE)      DEFAULT (' ')                 NOT NULL,
  HIST_DEL_COMMENT       VARCHAR2(400 BYTE)     DEFAULT (' ')                 NOT NULL    
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPSTPHIS ADD (
  CONSTRAINT MWIPSTPHIS_PK
 PRIMARY KEY
 (LOT_ID, HIST_SEQ) USING INDEX TABLESPACE HISTORY_IDX_TS);
   

/* MALMMSGDEF */
ALTER TABLE MALMMSGDEF ADD(ALARM_COMMENT_1          VARCHAR2(1000)  DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMSGDEF ADD(ALARM_COMMENT_2          VARCHAR2(1000)  DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMSGDEF ADD(ALARM_COMMENT_3          VARCHAR2(1000)  DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMSGDEF ADD(ALARM_COMMENT_4          VARCHAR2(1000)  DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMSGDEF ADD(ALARM_COMMENT_5          VARCHAR2(1000)  DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMSGDEF ADD(PDF_FILE_NAME            VARCHAR2(50)    DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMSGDEF ADD(IMAGE_FILE_NAME          VARCHAR2(50)    DEFAULT (' ')  NOT NULL);

/* MALMMFORES */
ALTER TABLE MALMMFORES ADD(OVERRIDE_MSG_FLAG        CHAR(1)         DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMFORES ADD(ALARM_SUBJECT            VARCHAR2(200)  	DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMFORES ADD(ALARM_MSG_1              VARCHAR2(1000)  DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMFORES ADD(ALARM_MSG_2              VARCHAR2(1000)  DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMFORES ADD(ALARM_MSG_3              VARCHAR2(1000)  DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMFORES ADD(OVERRIDE_COMMENT_FLAG    CHAR(1)         DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMFORES ADD(ALARM_COMMENT_1          VARCHAR2(1000)  DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMFORES ADD(ALARM_COMMENT_2          VARCHAR2(1000)  DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMFORES ADD(ALARM_COMMENT_3          VARCHAR2(1000)  DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMFORES ADD(ALARM_COMMENT_4          VARCHAR2(1000)  DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMFORES ADD(ALARM_COMMENT_5          VARCHAR2(1000)  DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMFORES ADD(OVERRIDE_PDF_FLAG        CHAR(1)         DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMFORES ADD(PDF_FILE_NAME            VARCHAR2(50)    DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMFORES ADD(OVERRIDE_IMAGE_FLAG      CHAR(1)         DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMFORES ADD(IMAGE_FILE_NAME          VARCHAR2(50)    DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMFORES ADD(FILE_NAME_KEY            VARCHAR2(20)    DEFAULT (' ')  NOT NULL);

/* MALMMSGHIS */
ALTER TABLE MALMMSGHIS ADD(ALARM_COMMENT_1          VARCHAR2(1000)  DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMSGHIS ADD(ALARM_COMMENT_2          VARCHAR2(1000)  DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMSGHIS ADD(ALARM_COMMENT_3          VARCHAR2(1000)  DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMSGHIS ADD(ALARM_COMMENT_4          VARCHAR2(1000)  DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMSGHIS ADD(ALARM_COMMENT_5          VARCHAR2(1000)  DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMSGHIS ADD(PDF_FILE_NAME            VARCHAR2(50)    DEFAULT (' ')  NOT NULL);
ALTER TABLE MALMMSGHIS ADD(IMAGE_FILE_NAME          VARCHAR2(50)    DEFAULT (' ')  NOT NULL);

/* MWIPOPRINV */
CREATE TABLE MWIPOPRINV
(
  FACTORY           VARCHAR2(10 BYTE)           DEFAULT (' ')                 NOT NULL,
  REL_LEVEL         CHAR(1 BYTE)                DEFAULT (' ')                 NOT NULL,
  MAT_ID            VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  MAT_VER           NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  FLOW              VARCHAR2(20 BYTE)           DEFAULT (' ')                 NOT NULL,
  OPER              VARCHAR2(10 BYTE)           DEFAULT (' ')                 NOT NULL,
  POINT_TYPE        CHAR(1 BYTE)                DEFAULT (' ')                 NOT NULL,
  SEQ               NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  VALUE_TYPE        CHAR(1 BYTE)                DEFAULT (' ')                 NOT NULL,
  DATA_1            VARCHAR2(100 BYTE)          DEFAULT (' ')                 NOT NULL,
  DATA_2            VARCHAR2(100 BYTE)          DEFAULT (' ')                 NOT NULL,
  DATA_3            VARCHAR2(100 BYTE)          DEFAULT (' ')                 NOT NULL,
  DATA_4            VARCHAR2(4000 BYTE)         DEFAULT (' ')                 NOT NULL,
  DATA_5            VARCHAR2(4000 BYTE)         DEFAULT (' ')                 NOT NULL,
  DISPLAY_TYPE      CHAR(1 BYTE)                DEFAULT (' ')                 NOT NULL,
  INPUT_TYPE        CHAR(1 BYTE)                DEFAULT (' ')                 NOT NULL,
  REQUIRE_FLAG      CHAR(1 BYTE)                DEFAULT (' ')                 NOT NULL,
  BACK_COLOR        NUMBER(10)                  DEFAULT (0)                   NOT NULL,
  INPUT_VALUE_TYPE  VARCHAR2(10 BYTE)           DEFAULT (' ')                 NOT NULL,
  CMF_1        	    VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CMF_2             VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CMF_3             VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CMF_4             VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CMF_5             VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CMF_6             VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CMF_7             VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CMF_8             VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CMF_9             VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CMF_10            VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CMF_11            VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CMF_12            VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CMF_13            VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CMF_14            VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CMF_15            VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CMF_16            VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CMF_17            VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CMF_18            VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CMF_19            VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CMF_20            VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CREATE_USER_ID    VARCHAR2(20 BYTE)           DEFAULT (' ')                 NOT NULL,
  CREATE_TIME       VARCHAR2(14 BYTE)           DEFAULT (' ')                 NOT NULL,
  UPDATE_USER_ID    VARCHAR2(20 BYTE)           DEFAULT (' ')                 NOT NULL,
  UPDATE_TIME       VARCHAR2(14 BYTE)           DEFAULT (' ')                 NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPOPRINV ADD (
  CONSTRAINT MWIPOPRINV_PK
 PRIMARY KEY
 (FACTORY, REL_LEVEL, MAT_ID, MAT_VER, FLOW, OPER, POINT_TYPE, SEQ) USING INDEX TABLESPACE MESPLUS_IDX_TS);


/* MWIPTOLLTH */
CREATE TABLE MWIPTOLLTH
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TOOL_ID                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_HIST_SEQ               NUMBER(10)       DEFAULT(0)      NOT NULL,
    TOOL_HIST_DEL_FLAG          CHAR(1)          DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPTOLLTH
ADD CONSTRAINT MWIPTOLLTH_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    FACTORY,
    TOOL_ID,
    TOOL_HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE TABLE MRASTOLRSH
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    TOOL_ID                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_HIST_SEQ               NUMBER(10)       DEFAULT(0)      NOT NULL,
    TOOL_HIST_DEL_FLAG          CHAR(1)          DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MRASTOLRSH
ADD CONSTRAINT MRASTOLRSH_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    HIST_SEQ,
    TOOL_ID,
    TOOL_HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MWIPCRRLOT */
ALTER TABLE MWIPCRRLOT ADD(CRR_SEQ          NUMBER(6)    DEFAULT(0)     NOT NULL);

DECLARE
     V_CRR_SEQ    NUMBER(6);
BEGIN
	 FOR REC IN (
			SELECT LOT_ID, COUNT(CRR_ID) as CRR_COUNT 
			FROM MWIPCRRLOT
			GROUP BY LOT_ID
	 )
     LOOP
        BEGIN
             V_CRR_SEQ := 0;
             FOR REC2 IN (
                    SELECT *
                    FROM MWIPCRRLOT
                    WHERE LOT_ID = REC.LOT_ID
                    ORDER BY CRR_ID
             )
             LOOP
                BEGIN
                    V_CRR_SEQ := V_CRR_SEQ + 1;
                    
                    UPDATE MWIPCRRLOT 
                    SET CRR_SEQ = V_CRR_SEQ
                    WHERE LOT_ID = REC2.LOT_ID
                        AND CRR_ID = REC2.CRR_ID;

                    EXCEPTION
                        WHEN NO_DATA_FOUND THEN  -- catches all 'no data found' errors
                            DBMS_OUTPUT.PUT_LINE (' exception no_data_found' );
                END;
             END LOOP;
        END;
     END LOOP;
END ;
/

CREATE TABLE MWIPCRRLTH
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    CRR_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    QTY_1                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CRR_SEQ                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPCRRLTH
ADD CONSTRAINT MWIPCRRLTH_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    CRR_ID 
) USING INDEX TABLESPACE MESPLUS_IDX_TS;  


/* MBASINQDEF */
CREATE TABLE MBASINQDEF
(
    INQUIRY_ID              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID          VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    CREATE_TIME             VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID          VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    UPDATE_TIME             VARCHAR2(14)    DEFAULT(' ')    NOT NULL,  
    INQUIRY_TITLE           VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    INQUIRY_DESC1           VARCHAR2(1000)  DEFAULT(' ')    NOT NULL,  
    INQUIRY_DESC2           VARCHAR2(1000)  DEFAULT(' ')    NOT NULL,
    INQUIRY_DESC3           VARCHAR2(1000)  DEFAULT(' ')    NOT NULL,
    INQUIRY_GROUP           VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    SYS_INQ_FLAG            CHAR(1)         DEFAULT(' ')    NOT NULL,
    SEC_CHK_FLAG            CHAR(1)         DEFAULT(' ')    NOT NULL,  
    SQL_ID_1                VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    SQL_ID_2                VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    SQL_ID_3                VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    SQL_ID_4                VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    SQL_ID_5                VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    PRT_1                   VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    PRT_2                   VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    PRT_3                   VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    PRT_4                   VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    PRT_5                   VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    PRT_6                   VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    PRT_7                   VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    PRT_8                   VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    PRT_9                   VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    PRT_10                  VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    FMT_1                   CHAR(1)         DEFAULT('A')    NOT NULL,  
    FMT_2                   CHAR(1)         DEFAULT('A')    NOT NULL,  
    FMT_3                   CHAR(1)         DEFAULT('A')    NOT NULL,  
    FMT_4                   CHAR(1)         DEFAULT('A')    NOT NULL, 
    FMT_5                   CHAR(1)         DEFAULT('A')    NOT NULL,  
    FMT_6                   CHAR(1)         DEFAULT('A')    NOT NULL,  
    FMT_7                   CHAR(1)         DEFAULT('A')    NOT NULL,  
    FMT_8                   CHAR(1)         DEFAULT('A')    NOT NULL,  
    FMT_9                   CHAR(1)         DEFAULT('A')    NOT NULL,  
    FMT_10                  CHAR(1)         DEFAULT('A')    NOT NULL,  
    SIZE_1                  NUMBER(2)       DEFAULT('0')    NOT NULL,
    SIZE_2                  NUMBER(2)       DEFAULT('0')    NOT NULL,
    SIZE_3                  NUMBER(2)       DEFAULT('0')    NOT NULL,
    SIZE_4                  NUMBER(2)       DEFAULT('0')    NOT NULL,
    SIZE_5                  NUMBER(2)       DEFAULT('0')    NOT NULL,
    SIZE_6                  NUMBER(2)       DEFAULT('0')    NOT NULL,
    SIZE_7                  NUMBER(2)       DEFAULT('0')    NOT NULL,
    SIZE_8                  NUMBER(2)       DEFAULT('0')    NOT NULL,
    SIZE_9                  NUMBER(2)       DEFAULT('0')    NOT NULL,
    SIZE_10                 NUMBER(2)       DEFAULT('0')    NOT NULL,
    REQ_1                   CHAR(1)         DEFAULT(' ')    NOT NULL,  
    REQ_2                   CHAR(1)         DEFAULT(' ')    NOT NULL,  
    REQ_3                   CHAR(1)         DEFAULT(' ')    NOT NULL,  
    REQ_4                   CHAR(1)         DEFAULT(' ')    NOT NULL, 
    REQ_5                   CHAR(1)         DEFAULT(' ')    NOT NULL,  
    REQ_6                   CHAR(1)         DEFAULT(' ')    NOT NULL,  
    REQ_7                   CHAR(1)         DEFAULT(' ')    NOT NULL,  
    REQ_8                   CHAR(1)         DEFAULT(' ')    NOT NULL,  
    REQ_9                   CHAR(1)         DEFAULT(' ')    NOT NULL,  
    REQ_10                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    TBL_1                   VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    TBL_2                   VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    TBL_3                   VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    TBL_4                   VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    TBL_5                   VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    TBL_6                   VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    TBL_7                   VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    TBL_8                   VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    TBL_9                   VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    TBL_10                  VARCHAR2(20)    DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBASINQDEF
ADD CONSTRAINT MBASINQDEF_PK PRIMARY KEY
(
    INQUIRY_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MBASSQLDEF */
CREATE TABLE MBASSQLDEF
(
    SQL_ID                  VARCHAR2(30)        DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID          VARCHAR2(20)        DEFAULT(' ')    NOT NULL,
    CREATE_TIME             VARCHAR2(14)        DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID          VARCHAR2(20)        DEFAULT(' ')    NOT NULL,
    UPDATE_TIME             VARCHAR2(14)        DEFAULT(' ')    NOT NULL,    
    SQL_ID_DESC_1           VARCHAR2(1000)      DEFAULT(' ')    NOT NULL,
    SQL_ID_DESC_2           VARCHAR2(1000)      DEFAULT(' ')    NOT NULL,
    SQL_ID_DESC_3           VARCHAR2(1000)      DEFAULT(' ')    NOT NULL,  
    SQL_GROUP               VARCHAR2(20)        DEFAULT(' ')    NOT NULL,
	SYS_SQL_FLAG            CHAR(1)             DEFAULT(' ')    NOT NULL,  
    SQL_1                   VARCHAR2(4000)      DEFAULT(' ')    NOT NULL,
    SQL_2                   VARCHAR2(4000)      DEFAULT(' ')    NOT NULL,
    SQL_3                   VARCHAR2(4000)      DEFAULT(' ')    NOT NULL,
    SQL_4                   VARCHAR2(4000)      DEFAULT(' ')    NOT NULL,
    SQL_5                   VARCHAR2(4000)      DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBASSQLDEF
ADD CONSTRAINT MBASSQLDEF_PK PRIMARY KEY
(
    SQL_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


ALTER TABLE MWIPSLTSTS ADD(SUBLOT_TYPE CHAR(1) DEFAULT(' ') NOT NULL);
ALTER TABLE MWIPSLTSTS ADD(RESV_FIELD_1 VARCHAR2(30) DEFAULT(' ') NOT NULL);
ALTER TABLE MWIPSLTSTS ADD(RESV_FIELD_2 VARCHAR2(30) DEFAULT(' ') NOT NULL);
ALTER TABLE MWIPSLTSTS ADD(RESV_FIELD_3 VARCHAR2(30) DEFAULT(' ') NOT NULL);
ALTER TABLE MWIPSLTSTS ADD(RESV_FIELD_4 VARCHAR2(30) DEFAULT(' ') NOT NULL);
ALTER TABLE MWIPSLTSTS ADD(RESV_FIELD_5 VARCHAR2(30) DEFAULT(' ') NOT NULL);
ALTER TABLE MWIPSLTSTS ADD(RESV_FLAG_1 CHAR(1) DEFAULT(' ') NOT NULL);
ALTER TABLE MWIPSLTSTS ADD(RESV_FLAG_2 CHAR(1) DEFAULT(' ') NOT NULL);
ALTER TABLE MWIPSLTSTS ADD(RESV_FLAG_3 CHAR(1) DEFAULT(' ') NOT NULL);
ALTER TABLE MWIPSLTSTS ADD(RESV_FLAG_4 CHAR(1) DEFAULT(' ') NOT NULL);
ALTER TABLE MWIPSLTSTS ADD(RESV_FLAG_5 CHAR(1) DEFAULT(' ') NOT NULL);


ALTER TABLE MWIPSLTHIS ADD(SUBLOT_TYPE CHAR(1) DEFAULT(' ') NOT NULL);
ALTER TABLE MWIPSLTHIS ADD(RESV_FIELD_1 VARCHAR2(30) DEFAULT(' ') NOT NULL);
ALTER TABLE MWIPSLTHIS ADD(RESV_FIELD_2 VARCHAR2(30) DEFAULT(' ') NOT NULL);
ALTER TABLE MWIPSLTHIS ADD(RESV_FIELD_3 VARCHAR2(30) DEFAULT(' ') NOT NULL);
ALTER TABLE MWIPSLTHIS ADD(RESV_FIELD_4 VARCHAR2(30) DEFAULT(' ') NOT NULL);
ALTER TABLE MWIPSLTHIS ADD(RESV_FIELD_5 VARCHAR2(30) DEFAULT(' ') NOT NULL);
ALTER TABLE MWIPSLTHIS ADD(RESV_FLAG_1 CHAR(1) DEFAULT(' ') NOT NULL);
ALTER TABLE MWIPSLTHIS ADD(RESV_FLAG_2 CHAR(1) DEFAULT(' ') NOT NULL);
ALTER TABLE MWIPSLTHIS ADD(RESV_FLAG_3 CHAR(1) DEFAULT(' ') NOT NULL);
ALTER TABLE MWIPSLTHIS ADD(RESV_FLAG_4 CHAR(1) DEFAULT(' ') NOT NULL);
ALTER TABLE MWIPSLTHIS ADD(RESV_FLAG_5 CHAR(1) DEFAULT(' ') NOT NULL);


/* MWIPLOTLNR : Not Loss History(Multiple Record) Table */
CREATE TABLE MWIPLOTLNR
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* QTY Flag - '1':Qty 1, '2':Qty 2, '3':Qty 3 */
    QTY_FLAG                    CHAR(1)          DEFAULT('1')    NOT NULL,
    /* Sequence Number */
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Transaction Time - Backdate °¡´É */
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Delete Info. */
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Factory */
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Resource ID */
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Reason Code/Qty */
    REASON_CODE                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    REASON_QTY                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTLNR
ADD CONSTRAINT MWIPLOTLNR_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    QTY_FLAG,
    SEQ_NUM
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MEDCCOLCHE : Collection Set Version-Character Extended Table */
CREATE TABLE MEDCCOLCHE
(
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    COL_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    COL_SET_VERSION             NUMBER(3)        DEFAULT(0)      NOT NULL,
    CHAR_ID                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Optional Unit Flag -  _:Essential, Y:Optional */
    OPT_UNIT_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Minimum Unit/Value Count */
    MIN_UNIT_COUNT          	NUMBER(3)        DEFAULT(0)      NOT NULL,
    MIN_VALUE_COUNT         	NUMBER(4)        DEFAULT(0)      NOT NULL,
    /* Minimum Unit/Value Count by Lot QTY Flag -  _:Not use, Y:Use */
    MIN_UNIT_BY_LOT_QTY         CHAR(1)          DEFAULT(' ')    NOT NULL,
    MIN_VALUE_BY_LOT_QTY        CHAR(1)          DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MEDCCOLCHE
ADD CONSTRAINT MEDCCOLCHE_PK PRIMARY KEY
(
    FACTORY,
    COL_SET_ID,
    COL_SET_VERSION,
    CHAR_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* Add by J.S. 2011.10.20 for Collect service data */
-- For SVM Service Performance Log
CREATE SEQUENCE MSVMPFMLOG_SEQ
	MINVALUE 1
	MAXVALUE 2000000000
	INCREMENT BY 1
	CYCLE
	NOORDER
	CACHE 20;

-- For SVM Service Error Log
CREATE SEQUENCE MSVMERRLOG_SEQ
	MINVALUE 1
	MAXVALUE 2000000000
	INCREMENT BY 1
	CYCLE
	NOORDER
	CACHE 20;

	
/* Add by J.S. 2011.10.20 */
/* MSVMPFMLOG : Service Performance Log Table */
CREATE TABLE MSVMPFMLOG
(
    SEQ_NUM                     NUMBER(10)       DEFAULT(0)      NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,	
    SYSTEM_NODE                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SERVER_NAME                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL, /* MESServer ... */
    SUBNO                       VARCHAR2(2)      DEFAULT(' ')    NOT NULL,
    SERVICE_NAME                VARCHAR2(100)    DEFAULT (' ')   NOT NULL,
    SERVICE_COUNT               NUMBER(10)       DEFAULT(0)      NOT NULL,
    TOTAL_CONSUME_SEC           NUMBER(15,3)     DEFAULT(0)      NOT NULL,
    MIN_CONSUME_SEC             NUMBER(15,3)     DEFAULT(0)      NOT NULL,
    MAX_CONSUME_SEC             NUMBER(15,3)     DEFAULT(0)      NOT NULL,
    PFM_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PFM_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PFM_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PFM_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PFM_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PFM_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PFM_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PFM_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PFM_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PFM_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
     /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;


ALTER TABLE MSVMPFMLOG
ADD CONSTRAINT MSVMPFMLOG_PK PRIMARY KEY
(
	SEQ_NUM
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE UNIQUE INDEX MSVMPFMLOG_IDX_1 ON MSVMPFMLOG
(
    TRAN_TIME,
    SYSTEM_NODE,
    SERVER_NAME,
    SUBNO,
    SERVICE_NAME
) TABLESPACE HISTORY_IDX_TS;



/* MSVMERRLOG : Service Error Log Table */
CREATE TABLE MSVMERRLOG
(
    SEQ_NUM                     NUMBER(10)       DEFAULT(0)      NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,	
    SYSTEM_NODE                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SERVER_NAME                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL, /* MESServer ... */
    SUBNO                       VARCHAR2(2)      DEFAULT(' ')    NOT NULL,
    SERVICE_NAME                VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    MSG_ID                      VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    STATUS_VALUE                CHAR(1)          DEFAULT(' ')    NOT NULL,
    ERROR_MSG                   VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    DB_ERROR_MSG                VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    ERROR_MSG_DETAIL            VARCHAR2(2000)   DEFAULT(' ')    NOT NULL,
    IN_MSG                      VARCHAR2(2000)   DEFAULT(' ')    NOT NULL,
    CONSUME_SEC                 NUMBER(15,3)     DEFAULT(0)      NOT NULL,
    ERR_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ERR_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ERR_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ERR_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ERR_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ERR_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ERR_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ERR_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ERR_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ERR_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
     /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;


ALTER TABLE MSVMERRLOG
ADD CONSTRAINT MSVMERRLOG_PK PRIMARY KEY
(
	SEQ_NUM
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MSVMERRLOG_IDX_1 ON MSVMERRLOG
(
    TRAN_TIME,
    RES_ID
) TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MSVMERRLOG_IDX_2 ON MSVMERRLOG
(
    TRAN_TIME,
    MSG_ID
) TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MSVMERRLOG_IDX_3 ON MSVMERRLOG
(
    TRAN_TIME,
    SERVER_NAME,
	SERVICE_NAME
) TABLESPACE HISTORY_IDX_TS;
/* End */


ALTER TABLE MATRNAMDEF ADD(KEY_HIST_INDEPENDENT_FLAG  CHAR(1)  DEFAULT (' ')  NOT NULL);


/* Flexible Screen Definition Table */
CREATE TABLE MBASSCRDEF
(
    FACTORY                     VARCHAR2(10)    DEFAULT (' ')   NOT NULL,
    SCREEN_ID                   VARCHAR2(30)    DEFAULT (' ')   NOT NULL,
    SCREEN_DESC              VARCHAR2(100)    DEFAULT (' ')   NOT NULL,
    SCREEN_GROUP            VARCHAR2(10)    DEFAULT (' ')   NOT NULL,
    MODULE_NAME              VARCHAR2(20)    DEFAULT (' ')   NOT NULL,
    SERVICE_NAME              VARCHAR2(100)    DEFAULT (' ')   NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')   NOT NULL,
    CREATE_TIME                VARCHAR2(14)    DEFAULT (' ')   NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')   NOT NULL,
    UPDATE_TIME                VARCHAR2(14)    DEFAULT (' ')   NOT NULL 
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBASSCRDEF
ADD CONSTRAINT MBASSCRDEF_PK PRIMARY KEY
(
    SCREEN_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

COMMENT ON TABLE	MBASSCRDEF IS 'Flexible Screen Definition Table';


/* MBASSCRREL: Screen Relation Definition Table */
CREATE TABLE MBASSCRREL
(
    RELATION_KEY                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPT_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,  
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RESG_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SCREEN_ID                   VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBASSCRREL
ADD CONSTRAINT MBASSCRREL_PK PRIMARY KEY
(
    RELATION_KEY
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

ALTER TABLE MBASSCRREL 
ADD CONSTRAINT MBASSCRREL_UK UNIQUE 
(
    FACTORY, 
    MAT_ID, 
    MAT_VER, 
    FLOW, 
    FLOW_SEQ_NUM, 
    OPER, 
    RES_ID, 
    RES_TYPE, 
    RESG_ID
);

/* MWIPFATCND : Condition by Action Key */
CREATE TABLE MBASSCRCND
(
    RELATION_KEY                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SEQ_NO                      NUMBER(6)        DEFAULT(0)      NOT NULL,
    AND_OR                      VARCHAR2(3)      DEFAULT(' ')    NOT NULL,
    L_BRACKET                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* LS : Lot Status, LA : Lot Attribute, SS : Sublot Status, SA : Sublot Attribute */
    COND_TYPE                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FIELD_NAME                  VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    OPERATOR                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* FV : Fixed Value, GT : GCM Table, US : User Sql */
    VALUE_TYPE                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    VALUE_1                     VARCHAR2(4000)   DEFAULT(' ')    NOT NULL,
    VALUE_2                     VARCHAR2(4000)   DEFAULT(' ')    NOT NULL,
    R_BRACKET                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBASSCRCND
ADD CONSTRAINT MBASSCRCND_PK PRIMARY KEY
(
    RELATION_KEY,
    SEQ_NO
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

COMMENT ON TABLE	MBASSCRREL IS 'Flexible Screen Relation Table';
COMMENT ON TABLE	MBASSCRCND IS 'Flexible Screen Relation Condition Table';


/* Master table of formula for automatic calculation at character. */
CREATE TABLE MEDCCHRFML
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    COL_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    COL_SET_VERSION             NUMBER(3)        DEFAULT(0)      NOT NULL,
    CHAR_ID                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* CC : Use Current Collection Set, OC : Use Other Collection Set, CV : Constant Value, OT : Operator, LB : Left Bracket, RB : Right Bracket */
    VALUE_TYPE                  VARCHAR2(2)      DEFAULT(' ')    NOT NULL,
    USE_COL_SET_ID              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    USE_COL_SET_VERSION         NUMBER(3)        DEFAULT(0)      NOT NULL,
    USE_CHAR_ID                 VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    USE_UNIT_SEQ                NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* AV : Average, SM : Sum, MN : Minimum, MX : Maximum, VC : Value Count, OV : One Value */
    CALC_TYPE                   VARCHAR2(2)      DEFAULT(' ')    NOT NULL,
    USE_VALUE_SEQ               NUMBER(6)        DEFAULT(0)      NOT NULL,
    CONST_VALUE                 VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    USE_FIRST_DATA              CHAR(1)          DEFAULT(' ')    NOT NULL,
    USE_LAST_DATA               CHAR(1)          DEFAULT(' ')    NOT NULL,
    OVERRIDE_LOT                CHAR(1)          DEFAULT(' ')    NOT NULL,
    OVERRIDE_RES                CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPERATOR                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BRACKET                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_1                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_2                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_3                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_4                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_5                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MEDCCHRFML
ADD CONSTRAINT MEDCCHRFML_PK PRIMARY KEY
(
    FACTORY,
    COL_SET_ID,
    COL_SET_VERSION,
    CHAR_ID,
    SEQ_NUM
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* Added by Aiden 2012.01.11 */
/* MWIPFATACT TABLE - COLUMN ADD */
ALTER TABLE MWIPFATACT ADD(DEPENDENT_ACTION_KEY     VARCHAR2(20)    DEFAULT (' ')  NOT NULL);
ALTER TABLE MWIPFATACT ADD(LONG_DATA_1              VARCHAR2(1000)  DEFAULT (' ')  NOT NULL);
ALTER TABLE MWIPFATACT ADD(LONG_DATA_2              VARCHAR2(1000)  DEFAULT (' ')  NOT NULL);

/* Added by ICBAE 2012.01.12 */
ALTER TABLE MRASRESLTH ADD(RES_SEQ  NUMBER(10)  DEFAULT(1)  NOT NULL);