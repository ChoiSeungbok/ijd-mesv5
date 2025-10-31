/*
**
**  File Name    : MESplusV5-Table-Migration_Table.sql
**  Description  : MESplus V5 Release for Table Migration
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g / 11g
**
**  Period       : 2013.09.30 ~ ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
**  1. 2013.09.30   Aiden   Create
*/

/* MWIPLOTFQT : From Queue Time for Lot */
CREATE TABLE MWIPLOTFQT
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SEQ_NUM                     NUMBER(10)       DEFAULT(0)      NOT NULL,
    FROM_HIST_SEQ               NUMBER(10)       DEFAULT(0)      NOT NULL,
    FROM_TRAN_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FROM_FACTORY                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FROM_MAT_ID                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FROM_MAT_VER                NUMBER(6)        DEFAULT(0)      NOT NULL,
    FROM_FLOW                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FROM_FLOW_SEQ_NUM           NUMBER(6)        DEFAULT(0)      NOT NULL,
    FROM_OPER                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Queue Time Calculation Start Point. ' ' : Default. Oper Out at from oper, 'I' : Oper in at from oper, 'S' : Start at from oper, 'E' : End at from oper */
    FROM_POINT_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    OPT_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Check Queue Time Point. ' ' : Anywhere in current oper, 'I' : Oper in at current oper, 'O' : Oper out at current oper, 'S' : Start at current oper, 'E' : End at current oper */
    CHECK_POINT_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
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
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTFQT
ADD CONSTRAINT MWIPLOTFQT_PK PRIMARY KEY
(
    LOT_ID,
    SEQ_NUM
) USING INDEX TABLESPACE HISTORY_IDX_TS;

-- MWIPLOTFQT Table Comment Script --
COMMENT ON TABLE  MWIPLOTFQT                                IS 'Queue Time From Point Lot Information';
COMMENT ON COLUMN MWIPLOTFQT.LOT_ID IS 'Lot ID'; 
COMMENT ON COLUMN MWIPLOTFQT.SEQ_NUM IS 'Number of passed queue time from point for Lot'; 
COMMENT ON COLUMN MWIPLOTFQT.FROM_HIST_SEQ IS 'Lot history sequence at passed from point'; 
COMMENT ON COLUMN MWIPLOTFQT.FROM_TRAN_TIME IS 'Transaction time at passed from point'; 
COMMENT ON COLUMN MWIPLOTFQT.FROM_FACTORY IS 'Factory  at passed from point'; 
COMMENT ON COLUMN MWIPLOTFQT.FROM_MAT_ID IS 'Material ID  at passed from point'; 
COMMENT ON COLUMN MWIPLOTFQT.FROM_MAT_VER IS 'Material Version  at passed from point'; 
COMMENT ON COLUMN MWIPLOTFQT.FROM_FLOW IS 'Flow  at passed from point'; 
COMMENT ON COLUMN MWIPLOTFQT.FROM_FLOW_SEQ_NUM IS 'Flow sequence number at passed from point'; 
COMMENT ON COLUMN MWIPLOTFQT.FROM_OPER IS 'Operation  at passed from point'; 
COMMENT ON COLUMN MWIPLOTFQT.FROM_POINT_FLAG IS 'From Point value of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.FACTORY IS 'Factory to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.MAT_ID IS 'Material ID to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.MAT_VER IS 'Material Version to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.FLOW IS 'Flow  to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.FLOW_SEQ_NUM IS 'Flow sequence number to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.OPER IS 'Operation to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.OPT_LEVEL IS 'Relation level to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.CHECK_POINT_FLAG IS 'Check Point value of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.LOT_CMF_1 IS 'Lot Customized Field Value to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.LOT_CMF_2 IS 'Lot Customized Field Value to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.LOT_CMF_3 IS 'Lot Customized Field Value to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.LOT_CMF_4 IS 'Lot Customized Field Value to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.LOT_CMF_5 IS 'Lot Customized Field Value to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.LOT_CMF_6 IS 'Lot Customized Field Value to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.LOT_CMF_7 IS 'Lot Customized Field Value to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.LOT_CMF_8 IS 'Lot Customized Field Value to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.LOT_CMF_9 IS 'Lot Customized Field Value to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.LOT_CMF_10 IS 'Lot Customized Field Value to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.LOT_CMF_11 IS 'Lot Customized Field Value to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.LOT_CMF_12 IS 'Lot Customized Field Value to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.LOT_CMF_13 IS 'Lot Customized Field Value to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.LOT_CMF_14 IS 'Lot Customized Field Value to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.LOT_CMF_15 IS 'Lot Customized Field Value to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.LOT_CMF_16 IS 'Lot Customized Field Value to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.LOT_CMF_17 IS 'Lot Customized Field Value to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.LOT_CMF_18 IS 'Lot Customized Field Value to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.LOT_CMF_19 IS 'Lot Customized Field Value to check queue time of Queue time definition'; 
COMMENT ON COLUMN MWIPLOTFQT.LOT_CMF_20 IS 'Lot Customized Field Value to check queue time of Queue time definition'; 
