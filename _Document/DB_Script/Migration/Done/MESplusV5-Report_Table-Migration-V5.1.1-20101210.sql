/*
**
**  File Name    : MESplusV5-Reprot Table-Migration.sql
**  Description  : MESplus V5 Release Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g / 11g
**
**  Period       : 2010.09.06 ~ ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
*/

CREATE TABLE RATRNAMHIS_OLD AS SELECT * FROM RATRNAMHIS;
DROP TABLE RATRNAMHIS CASCADE CONSTRAINT PURGE;

CREATE TABLE RATRNAMHIS
(
    FACTORY                VARCHAR2(10 BYTE) DEFAULT (' ') NOT NULL,
    ATTR_TYPE             VARCHAR2(20 BYTE) DEFAULT (' ') NOT NULL,
    ATTR_NAME             VARCHAR2(100 BYTE) DEFAULT (' ') NOT NULL,
    ATTR_KEY                VARCHAR2(30 BYTE) DEFAULT (' ') NOT NULL,
    HIST_SEQ                NUMBER(10,0) DEFAULT (0) NOT NULL,
    ATTR_OLD_VALUE    VARCHAR2(1000 BYTE),
    ATTR_NEW_VALUE   VARCHAR2(1000 BYTE),
    NULL_FLAG               CHAR(1 BYTE),
    TRAN_TIME               DATE,
    SYS_TRAN_TIME       DATE,
    KEY_HIST_SEQ         NUMBER(10,0),
    PREV_ACTIVE_HIST_SEQ NUMBER(10,0),
    HIST_START_SEQ      NUMBER(10,0),
    HIST_DEL_FLAG         CHAR(1 BYTE),
    HIST_DEL_TIME          DATE,
    HIST_DEL_USER_ID    VARCHAR2(20 BYTE),
    HIST_DEL_COMMENT VARCHAR2(400 BYTE)
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RATRNAMHIS
ADD CONSTRAINT RATRNAMHIS_PK PRIMARY KEY
(
    FACTORY,
    ATTR_TYPE,
    ATTR_NAME,
    ATTR_KEY,
    HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;

INSERT INTO RATRNAMHIS VALUE ( 
SELECT 
    FACTORY,
    ATTR_TYPE,
    ATTR_NAME,
    ATTR_KEY,
    HIST_SEQ,
    ATTR_OLD_VALUE,
    ATTR_NEW_VALUE,
    ' ',
    TRAN_TIME,
    SYS_TRAN_TIME,
    KEY_HIST_SEQ,                
    PREV_ACTIVE_HIST_SEQ,
    HIST_START_SEQ,
    HIST_DEL_FLAG,
    HIST_DEL_TIME,
    HIST_DEL_USER_ID,
    HIST_DEL_COMMENT 
FROM RATRNAMHIS_OLD);

CREATE TABLE RWIPLOTSPL_OLD AS SELECT * FROM RWIPLOTSPL;
DROP TABLE RWIPLOTSPL CASCADE CONSTRAINT PURGE;

CREATE TABLE RWIPLOTSPL
(
    LOT_ID               VARCHAR2(25 BYTE) DEFAULT (' ') NOT NULL,
    HIST_SEQ             NUMBER(10,0) DEFAULT (0) NOT NULL,
    TRAN_TIME            VARCHAR2(14 BYTE) DEFAULT (' ') NOT NULL,
    HIST_DEL_FLAG        CHAR(1 BYTE) DEFAULT (' ') NOT NULL,
    FACTORY              VARCHAR2(10 BYTE) DEFAULT (' ') NOT NULL,
    MAT_ID               VARCHAR2(30 BYTE) DEFAULT (' ') NOT NULL,
    MAT_VER              NUMBER(6,0) DEFAULT (0) NOT NULL,
    FLOW                 VARCHAR2(20 BYTE) DEFAULT (' ') NOT NULL,
    FLOW_SEQ_NUM         NUMBER(6,0) DEFAULT (0) NOT NULL,
    OPER                 VARCHAR2(10 BYTE) DEFAULT (' ') NOT NULL,
    FROM_TO_FLAG         CHAR(1 BYTE) DEFAULT (' ') NOT NULL,
    FROM_TO_LOT_ID       VARCHAR2(25 BYTE) DEFAULT (' ') NOT NULL,
    FROM_TO_MAT_ID       VARCHAR2(30 BYTE) DEFAULT (' ') NOT NULL,
    FROM_TO_MAT_VER      NUMBER(6,0) DEFAULT (0) NOT NULL,
    FROM_TO_FLOW         VARCHAR2(20 BYTE) DEFAULT (' ') NOT NULL,
    FROM_TO_FLOW_SEQ_NUM NUMBER(6,0) DEFAULT (0) NOT NULL,
    FROM_TO_OPER         VARCHAR2(10 BYTE) DEFAULT (' ') NOT NULL,
    FROM_TO_QTY_1        NUMBER(10,3) DEFAULT (0.0) NOT NULL,
    FROM_TO_QTY_2        NUMBER(10,3) DEFAULT (0.0) NOT NULL,
    FROM_TO_QTY_3        NUMBER(10,3) DEFAULT (0.0) NOT NULL,
    FROM_TO_HIST_SEQ            NUMBER(10)       DEFAULT(0)      NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPLOTSPL
ADD CONSTRAINT RWIPLOTSPL_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;

INSERT INTO RWIPLOTSPL VALUE ( 
SELECT 
    LOT_ID              ,
    HIST_SEQ            ,
    TRAN_TIME           ,
    HIST_DEL_FLAG       ,
    FACTORY             ,
    MAT_ID              ,
    MAT_VER             ,
    FLOW                ,
    FLOW_SEQ_NUM        ,
    OPER                ,
    FROM_TO_FLAG        ,
    FROM_TO_LOT_ID      ,
    FROM_TO_MAT_ID      ,
    FROM_TO_MAT_VER     ,
    FROM_TO_FLOW        ,
    FROM_TO_FLOW_SEQ_NUM,
    FROM_TO_OPER        ,
    FROM_TO_QTY_1       ,
    FROM_TO_QTY_2       ,
    FROM_TO_QTY_3       ,
    0
FROM RWIPLOTSPL_OLD);


DECLARE
     V_FROM_HIST_SEQ    NUMBER(10);
BEGIN
	 FOR REC IN (
			SELECT * 
			FROM RWIPLOTSPL
			ORDER BY LOT_ID, HIST_SEQ
	 )
     LOOP


        BEGIN
            SELECT FROM_TO_HIST_SEQ 
            INTO V_FROM_HIST_SEQ
            FROM MWIPLOTHIS
            WHERE LOT_ID = REC.LOT_ID
                AND HIST_SEQ = REC.HIST_SEQ;
    
            UPDATE RWIPLOTSPL 
            SET FROM_TO_HIST_SEQ = V_FROM_HIST_SEQ 
            WHERE LOT_ID = REC.LOT_ID
                AND HIST_SEQ = REC.HIST_SEQ;

            EXCEPTION
                WHEN NO_DATA_FOUND THEN  -- catches all 'no data found' errors
                    DBMS_OUTPUT.PUT_LINE (' exception no_data_found' );
        END;
     END LOOP;
END ;
/


CREATE TABLE RWIPLOTMRG_OLD AS SELECT * FROM RWIPLOTMRG;
DROP TABLE RWIPLOTMRG CASCADE CONSTRAINT PURGE;

CREATE TABLE RWIPLOTMRG
(
    LOT_ID               VARCHAR2(25 BYTE) DEFAULT (' ') NOT NULL,
    HIST_SEQ             NUMBER(10,0) DEFAULT (0) NOT NULL,
    TRAN_TIME            VARCHAR2(14 BYTE) DEFAULT (' ') NOT NULL,
    HIST_DEL_FLAG        CHAR(1 BYTE) DEFAULT (' ') NOT NULL,
    FACTORY              VARCHAR2(10 BYTE) DEFAULT (' ') NOT NULL,
    MAT_ID               VARCHAR2(30 BYTE) DEFAULT (' ') NOT NULL,
    MAT_VER              NUMBER(6,0) DEFAULT (0) NOT NULL,
    FLOW                 VARCHAR2(20 BYTE) DEFAULT (' ') NOT NULL,
    FLOW_SEQ_NUM         NUMBER(6,0) DEFAULT (0) NOT NULL,
    OPER                 VARCHAR2(10 BYTE) DEFAULT (' ') NOT NULL,
    FROM_TO_FLAG         CHAR(1 BYTE) DEFAULT (' ') NOT NULL,
    FROM_TO_LOT_ID       VARCHAR2(25 BYTE) DEFAULT (' ') NOT NULL,
    FROM_TO_MAT_ID       VARCHAR2(30 BYTE) DEFAULT (' ') NOT NULL,
    FROM_TO_MAT_VER      NUMBER(6,0) DEFAULT (0) NOT NULL,
    FROM_TO_FLOW         VARCHAR2(20 BYTE) DEFAULT (' ') NOT NULL,
    FROM_TO_FLOW_SEQ_NUM NUMBER(6,0) DEFAULT (0) NOT NULL,
    FROM_TO_OPER         VARCHAR2(10 BYTE) DEFAULT (' ') NOT NULL,
    FROM_TO_QTY_1        NUMBER(10,3) DEFAULT (0.0) NOT NULL,
    FROM_TO_QTY_2        NUMBER(10,3) DEFAULT (0.0) NOT NULL,
    FROM_TO_QTY_3        NUMBER(10,3) DEFAULT (0.0) NOT NULL,
    FROM_TO_HIST_SEQ            NUMBER(10)       DEFAULT(0)      NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPLOTMRG
ADD CONSTRAINT RWIPLOTMRG_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;

INSERT INTO RWIPLOTMRG VALUE ( 
SELECT 
    LOT_ID              ,
    HIST_SEQ            ,
    TRAN_TIME           ,
    HIST_DEL_FLAG       ,
    FACTORY             ,
    MAT_ID              ,
    MAT_VER             ,
    FLOW                ,
    FLOW_SEQ_NUM        ,
    OPER                ,
    FROM_TO_FLAG        ,
    FROM_TO_LOT_ID      ,
    FROM_TO_MAT_ID      ,
    FROM_TO_MAT_VER     ,
    FROM_TO_FLOW        ,
    FROM_TO_FLOW_SEQ_NUM,
    FROM_TO_OPER        ,
    FROM_TO_QTY_1       ,
    FROM_TO_QTY_2       ,
    FROM_TO_QTY_3       ,
    0
FROM RWIPLOTMRG_OLD);


DECLARE
     V_FROM_HIST_SEQ    NUMBER(10);
BEGIN
	 FOR REC IN (
			SELECT * 
			FROM RWIPLOTMRG
			ORDER BY LOT_ID, HIST_SEQ
	 )
     LOOP


        BEGIN
            SELECT FROM_TO_HIST_SEQ 
            INTO V_FROM_HIST_SEQ
            FROM MWIPLOTHIS
            WHERE LOT_ID = REC.LOT_ID
                AND HIST_SEQ = REC.HIST_SEQ;
    
            UPDATE RWIPLOTMRG 
            SET FROM_TO_HIST_SEQ = V_FROM_HIST_SEQ 
            WHERE LOT_ID = REC.LOT_ID
                AND HIST_SEQ = REC.HIST_SEQ;

            EXCEPTION
                WHEN NO_DATA_FOUND THEN  -- catches all 'no data found' errors
                    DBMS_OUTPUT.PUT_LINE (' exception no_data_found' );
        END;
     END LOOP;
END ;
/


CREATE TABLE RWIPLOTCMB_OLD AS SELECT * FROM RWIPLOTCMB;
DROP TABLE RWIPLOTCMB CASCADE CONSTRAINT PURGE;

CREATE TABLE RWIPLOTCMB
(
    LOT_ID               VARCHAR2(25 BYTE) DEFAULT (' ') NOT NULL,
    HIST_SEQ             NUMBER(10,0) DEFAULT (0) NOT NULL,
    TRAN_TIME            VARCHAR2(14 BYTE) DEFAULT (' ') NOT NULL,
    HIST_DEL_FLAG        CHAR(1 BYTE) DEFAULT (' ') NOT NULL,
    FACTORY              VARCHAR2(10 BYTE) DEFAULT (' ') NOT NULL,
    MAT_ID               VARCHAR2(30 BYTE) DEFAULT (' ') NOT NULL,
    MAT_VER              NUMBER(6,0) DEFAULT (0) NOT NULL,
    FLOW                 VARCHAR2(20 BYTE) DEFAULT (' ') NOT NULL,
    FLOW_SEQ_NUM         NUMBER(6,0) DEFAULT (0) NOT NULL,
    OPER                 VARCHAR2(10 BYTE) DEFAULT (' ') NOT NULL,
    FROM_TO_FLAG         CHAR(1 BYTE) DEFAULT (' ') NOT NULL,
    FROM_TO_LOT_ID       VARCHAR2(25 BYTE) DEFAULT (' ') NOT NULL,
    FROM_TO_MAT_ID       VARCHAR2(30 BYTE) DEFAULT (' ') NOT NULL,
    FROM_TO_MAT_VER      NUMBER(6,0) DEFAULT (0) NOT NULL,
    FROM_TO_FLOW         VARCHAR2(20 BYTE) DEFAULT (' ') NOT NULL,
    FROM_TO_FLOW_SEQ_NUM NUMBER(6,0) DEFAULT (0) NOT NULL,
    FROM_TO_OPER         VARCHAR2(10 BYTE) DEFAULT (' ') NOT NULL,
    FROM_TO_QTY_1        NUMBER(10,3) DEFAULT (0.0) NOT NULL,
    FROM_TO_QTY_2        NUMBER(10,3) DEFAULT (0.0) NOT NULL,
    FROM_TO_QTY_3        NUMBER(10,3) DEFAULT (0.0) NOT NULL,
    FROM_TO_HIST_SEQ            NUMBER(10)       DEFAULT(0)      NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPLOTCMB
ADD CONSTRAINT RWIPLOTCMB_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;

INSERT INTO RWIPLOTCMB VALUE ( 
SELECT 
    LOT_ID              ,
    HIST_SEQ            ,
    TRAN_TIME           ,
    HIST_DEL_FLAG       ,
    FACTORY             ,
    MAT_ID              ,
    MAT_VER             ,
    FLOW                ,
    FLOW_SEQ_NUM        ,
    OPER                ,
    FROM_TO_FLAG        ,
    FROM_TO_LOT_ID      ,
    FROM_TO_MAT_ID      ,
    FROM_TO_MAT_VER     ,
    FROM_TO_FLOW        ,
    FROM_TO_FLOW_SEQ_NUM,
    FROM_TO_OPER        ,
    FROM_TO_QTY_1       ,
    FROM_TO_QTY_2       ,
    FROM_TO_QTY_3       ,
    0
FROM RWIPLOTCMB_OLD);


DECLARE
     V_FROM_HIST_SEQ    NUMBER(10);
BEGIN
	 FOR REC IN (
			SELECT * 
			FROM RWIPLOTCMB
			ORDER BY LOT_ID, HIST_SEQ
	 )
     LOOP


        BEGIN
            SELECT FROM_TO_HIST_SEQ 
            INTO V_FROM_HIST_SEQ
            FROM MWIPLOTHIS
            WHERE LOT_ID = REC.LOT_ID
                AND HIST_SEQ = REC.HIST_SEQ;
    
            UPDATE RWIPLOTCMB 
            SET FROM_TO_HIST_SEQ = V_FROM_HIST_SEQ 
            WHERE LOT_ID = REC.LOT_ID
                AND HIST_SEQ = REC.HIST_SEQ;

            EXCEPTION
                WHEN NO_DATA_FOUND THEN  -- catches all 'no data found' errors
                    DBMS_OUTPUT.PUT_LINE (' exception no_data_found' );
        END;
     END LOOP;
END ;
/


CREATE TABLE RWIPLOTRWK_OLD AS SELECT * FROM RWIPLOTRWK;
DROP TABLE RWIPLOTRWK CASCADE CONSTRAINT PURGE;

CREATE TABLE RWIPLOTRWK
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
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
    QTY_1                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    RWK_CODE                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RWK_COUNT                   NUMBER(6)        DEFAULT(0)      NOT NULL,
    RWK_DEPTH                   NUMBER(6)        DEFAULT(0)      NOT NULL,
    RWK_FLOW                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RWK_FLOW_SEQ_NUM            NUMBER(6)        DEFAULT(0)      NOT NULL,
    RWK_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RWK_STOP_OPER               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RWK_RET_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RWK_RET_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,
    RWK_RET_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RWK_END_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RWK_END_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,
    RWK_END_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RWK_RET_CLEAR_FLAG          CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOCAL_REWORK_FLAG           CHAR(1)          DEFAULT(' ')    NOT NULL,
    RWK_USER_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RWK_COMMENT                 VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    USER_ID_1                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_TIME_1                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    USER_COMMENT_1              VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    USER_ID_2                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_TIME_2                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    USER_COMMENT_2              VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    USER_ID_3                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_TIME_3                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    USER_COMMENT_3              VARCHAR2(400)    DEFAULT(' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPLOTRWK
ADD CONSTRAINT RWIPLOTRWK_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;

INSERT INTO RWIPLOTRWK VALUE ( 
SELECT 
    LOT_ID                ,
    HIST_SEQ              ,
    TRAN_TIME             ,
    HIST_DEL_FLAG         ,
    FACTORY               ,
    MAT_ID                ,
    MAT_VER               ,
    FLOW                  ,
    FLOW_SEQ_NUM          ,
    OPER                  ,
    RES_ID                ,
    CAUSE_FLOW            ,
    CAUSE_OPER            ,
    CAUSE_RES_ID          ,
    QTY_1                 ,
    QTY_2                 ,
    QTY_3                 ,
    RWK_CODE              ,
    RWK_COUNT             ,
	0                     ,
    FLOW                  ,
    FLOW_SEQ_NUM          ,
    OPER                  ,
	' '                   ,
    RWK_RET_FLOW          ,
    RWK_RET_FLOW_SEQ_NUM  ,
    RWK_RET_OPER          ,
    RWK_END_FLOW          ,
    RWK_END_FLOW_SEQ_NUM  ,
    RWK_END_OPER          ,
    RWK_RET_CLEAR_FLAG    ,
	' '                   ,
    RWK_USER_ID           ,
    RWK_COMMENT           ,
    USER_ID_1             ,
    USER_TIME_1           ,
    USER_COMMENT_1        ,
    USER_ID_2             ,
    USER_TIME_2           ,
    USER_COMMENT_2        ,
    USER_ID_3             ,
    USER_TIME_3           ,
    USER_COMMENT_3
FROM RWIPLOTRWK_OLD);


DECLARE
     V_FLOW    		VARCHAR2(20);
     V_FLOW_SEQ    	NUMBER(10);
     V_OPER    		VARCHAR2(10);
BEGIN
	 FOR REC IN (
			SELECT * 
			FROM MWIPLOTRWK
			ORDER BY LOT_ID, HIST_SEQ
	 )
     LOOP


        BEGIN
            SELECT OLD_FLOW, OLD_FLOW_SEQ_NUM, OLD_OPER 
            INTO V_FLOW, V_FLOW_SEQ, V_OPER
            FROM MWIPLOTHIS
            WHERE LOT_ID = REC.LOT_ID
                AND HIST_SEQ = REC.HIST_SEQ;
    
            UPDATE MWIPLOTRWK 
            SET FLOW = V_FLOW, FLOW_SEQ_NUM = V_FLOW_SEQ, OPER = V_OPER
            WHERE LOT_ID = REC.LOT_ID
                AND HIST_SEQ = REC.HIST_SEQ;

            EXCEPTION
                WHEN NO_DATA_FOUND THEN  -- catches all 'no data found' errors
                    DBMS_OUTPUT.PUT_LINE (' exception no_data_found' );
        END;
     END LOOP;
END ;
/


