/*
**
**  File Name    : MESplusV5_ORA_RPT_Create_Table_Script.sql
**  Description  : MES Database Table Creation SQL Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10
**
**  ==== Table Naming Rule ====
**  M WIP FAC DEF
**  1 234 567 890
**  - --- --- ---
**  1    - Sub System Name - M:MES, R:RPT, C:Customized, I:Interface, B:Backup, L:Log, T:Temporary
**  234  - Module Name
**  567  - Object Name(ex, FAC, MAT, FLW, OPR, RES, LOT, EQP, CST)
**  890  - Second Object Name 
**         or Object Status(ex, STS:Status, HIS:History, DEF:Definition, GRP:Group)
**
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
*/

/*==== RPT System ====*/
/* RWIPLOTSTS : Lot Status Table */
CREATE TABLE RWIPLOTSTS 
(
    /* MWIPLOTSTS와 동일 */
  LOT_ID                 VARCHAR2(25 BYTE)      DEFAULT (' ')                 NOT NULL,
  LOT_DESC               VARCHAR2(200 BYTE),
  FACTORY                VARCHAR2(10 BYTE),
  MAT_ID                 VARCHAR2(30 BYTE),
  MAT_VER                NUMBER(6),
  FLOW                   VARCHAR2(20 BYTE),
  FLOW_SEQ_NUM           NUMBER(6),
  OPER                   VARCHAR2(10 BYTE),
  QTY_1                  NUMBER(10,3),
  QTY_2                  NUMBER(10,3),
  QTY_3                  NUMBER(10,3),
  CRR_ID                 VARCHAR2(20 BYTE),
  LOT_TYPE               VARCHAR2(1 BYTE)       DEFAULT ('P')                 NOT NULL,
  OWNER_CODE             VARCHAR2(10 BYTE),
  CREATE_CODE            VARCHAR2(10 BYTE),
  LOT_PRIORITY           VARCHAR2(1 BYTE)       DEFAULT ('5')                 NOT NULL,
  LOT_STATUS             VARCHAR2(10 BYTE),
  HOLD_FLAG              VARCHAR2(1 BYTE),
  HOLD_CODE              VARCHAR2(10 BYTE),
  HOLD_PASSWORD          VARCHAR2(20 BYTE),
  HOLD_PRV_GRP_ID        VARCHAR2(20 BYTE),
  OPER_IN_QTY_1          NUMBER(10,3),
  OPER_IN_QTY_2          NUMBER(10,3),
  OPER_IN_QTY_3          NUMBER(10,3),
  CREATE_QTY_1           NUMBER(10,3),
  CREATE_QTY_2           NUMBER(10,3),
  CREATE_QTY_3           NUMBER(10,3),
  START_QTY_1            NUMBER(10,3),
  START_QTY_2            NUMBER(10,3),
  START_QTY_3            NUMBER(10,3),
  INV_FLAG               VARCHAR2(1 BYTE),
  TRANSIT_FLAG           VARCHAR2(1 BYTE),
  UNIT_EXIST_FLAG        VARCHAR2(1 BYTE),
  INV_UNIT               VARCHAR2(10 BYTE),
  RWK_FLAG               VARCHAR2(1 BYTE),
  RWK_CODE               VARCHAR2(10 BYTE),
  RWK_COUNT              NUMBER(6),
  RWK_RET_FLOW           VARCHAR2(20 BYTE),
  RWK_RET_FLOW_SEQ_NUM   NUMBER(6),
  RWK_RET_OPER           VARCHAR2(10 BYTE),
  RWK_END_FLOW           VARCHAR2(20 BYTE),
  RWK_END_FLOW_SEQ_NUM   NUMBER(6),
  RWK_END_OPER           VARCHAR2(10 BYTE),
  RWK_RET_CLEAR_FLAG     VARCHAR2(1 BYTE),
  RWK_TIME               DATE,
  NSTD_FLAG              VARCHAR2(1 BYTE),
  NSTD_RET_FLOW          VARCHAR2(20 BYTE),
  NSTD_RET_FLOW_SEQ_NUM  NUMBER(6),
  NSTD_RET_OPER          VARCHAR2(10 BYTE),
  NSTD_TIME              DATE,
  REP_FLAG               VARCHAR2(1 BYTE),
  REP_RET_OPER           VARCHAR2(10 BYTE),
  STR_RET_FLOW           VARCHAR2(20 BYTE),
  STR_RET_FLOW_SEQ_NUM   NUMBER(6),
  STR_RET_OPER           VARCHAR2(10 BYTE),
  START_FLAG             VARCHAR2(1 BYTE),
  START_TIME             DATE,
  START_RES_ID           VARCHAR2(20 BYTE),
  END_FLAG               VARCHAR2(1 BYTE),
  END_TIME               DATE,
  END_RES_ID             VARCHAR2(20 BYTE),
  SAMPLE_FLAG            VARCHAR2(1 BYTE),
  SAMPLE_WAIT_FLAG       VARCHAR2(1 BYTE),
  SAMPLE_RESULT          VARCHAR2(1 BYTE),
  FROM_TO_FLAG           VARCHAR2(1 BYTE),
  FROM_TO_LOT_ID         VARCHAR2(25 BYTE),
  SHIP_CODE              VARCHAR2(10 BYTE),
  SHIP_TIME              DATE,
  ORG_DUE_TIME           DATE,
  SCH_DUE_TIME           DATE,
  CREATE_TIME            DATE,
  FAC_IN_TIME            DATE,
  FLOW_IN_TIME           DATE,
  OPER_IN_TIME           DATE,
  RESERVE_RES_ID         VARCHAR2(20 BYTE),
  PORT_ID                VARCHAR2(10 BYTE),
  BATCH_ID               VARCHAR2(25 BYTE),
  BATCH_SEQ              NUMBER(3),
  ORDER_ID               VARCHAR2(25 BYTE),
  ADD_ORDER_ID_1         VARCHAR2(25 BYTE),
  ADD_ORDER_ID_2         VARCHAR2(25 BYTE),
  ADD_ORDER_ID_3         VARCHAR2(25 BYTE),
  LOT_LOCATION_1         VARCHAR2(20 BYTE),
  LOT_LOCATION_2         VARCHAR2(20 BYTE),
  LOT_LOCATION_3         VARCHAR2(20 BYTE),
  LOT_CMF_1              VARCHAR2(30 BYTE),
  LOT_CMF_2              VARCHAR2(30 BYTE),
  LOT_CMF_3              VARCHAR2(30 BYTE),
  LOT_CMF_4              VARCHAR2(30 BYTE),
  LOT_CMF_5              VARCHAR2(30 BYTE),
  LOT_CMF_6              VARCHAR2(30 BYTE),
  LOT_CMF_7              VARCHAR2(30 BYTE),
  LOT_CMF_8              VARCHAR2(30 BYTE),
  LOT_CMF_9              VARCHAR2(30 BYTE),
  LOT_CMF_10             VARCHAR2(30 BYTE),
  LOT_CMF_11             VARCHAR2(30 BYTE),
  LOT_CMF_12             VARCHAR2(30 BYTE),
  LOT_CMF_13             VARCHAR2(30 BYTE),
  LOT_CMF_14             VARCHAR2(30 BYTE),
  LOT_CMF_15             VARCHAR2(30 BYTE),
  LOT_CMF_16             VARCHAR2(30 BYTE),
  LOT_CMF_17             VARCHAR2(30 BYTE),
  LOT_CMF_18             VARCHAR2(30 BYTE),
  LOT_CMF_19             VARCHAR2(30 BYTE),
  LOT_CMF_20             VARCHAR2(30 BYTE),
  LOT_DEL_FLAG           VARCHAR2(1 BYTE),
  LOT_DEL_CODE           VARCHAR2(10 BYTE),
  LOT_DEL_TIME           DATE,
  BOM_SET_ID             VARCHAR2(25 BYTE),
  BOM_SET_VERSION        NUMBER(3),
  BOM_ACTIVE_HIST_SEQ    NUMBER(10),
  BOM_HIST_SEQ           NUMBER(10),
  LAST_TRAN_CODE         VARCHAR2(12 BYTE),
  LAST_TRAN_TIME         DATE,
  LAST_COMMENT           VARCHAR2(400 BYTE),
  LAST_ACTIVE_HIST_SEQ   NUMBER(10),
  LAST_HIST_SEQ          NUMBER(10),
  CRITICAL_RES_ID        VARCHAR2(20 BYTE),
  CRITICAL_RES_GROUP_ID  VARCHAR2(20 BYTE),
  SAVE_RES_ID_1          VARCHAR2(20 BYTE),
  SAVE_RES_ID_2          VARCHAR2(20 BYTE),
  SUBRES_ID              VARCHAR2(20 BYTE),
  LOT_GROUP_ID_1         VARCHAR2(25 BYTE),
  LOT_GROUP_ID_2         VARCHAR2(25 BYTE),
  LOT_GROUP_ID_3         VARCHAR2(25 BYTE),
  YIELD_1                NUMBER(20,10),
  YIELD_2                NUMBER(20,10),
  YIELD_3                NUMBER(20,10),
  GOOD_QTY               NUMBER(10,3),
  RESV_FIELD_1           VARCHAR2(30 BYTE),
  RESV_FIELD_2           VARCHAR2(30 BYTE),
  RESV_FIELD_3           VARCHAR2(30 BYTE),
  RESV_FIELD_4           VARCHAR2(30 BYTE),
  RESV_FIELD_5           VARCHAR2(30 BYTE),
  RESV_FLAG_1            VARCHAR2(1 BYTE),
  RESV_FLAG_2            VARCHAR2(1 BYTE),
  RESV_FLAG_3            VARCHAR2(1 BYTE),
  RESV_FLAG_4            VARCHAR2(1 BYTE),
  RESV_FLAG_5            VARCHAR2(1 BYTE),
  PRODUCT_GRP            VARCHAR2(1 BYTE),
  UNIT_1                 VARCHAR2(10 BYTE),
  UNIT_2                 VARCHAR2(10 BYTE),
  UNIT_3                 VARCHAR2(10 BYTE),
  ORIG_OPER              VARCHAR2(10 BYTE),
  DATE_CREATE            DATE,
  DATE_UPDATE            DATE
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPLOTSTS
ADD CONSTRAINT RWIPLOTSTS_PK PRIMARY KEY
(
    LOT_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;

/* RWIPLOTDEL : Lot Delete Status */
CREATE TABLE RWIPLOTDEL
(
  LOT_ID                VARCHAR2(25 BYTE)       DEFAULT (' ')                 NOT NULL ENABLE,
  HIST_SEQ              NUMBER(10,0)            DEFAULT (0)                   NOT NULL ENABLE,
  TRAN_TIME             DATE,
  SYS_TRAN_TIME         DATE       					                 		  NOT NULL ENABLE,
  TRAN_CODE             VARCHAR2(12 BYTE),
  LOT_DESC              VARCHAR2(200 BYTE),
  FACTORY               VARCHAR2(10 BYTE),
  MAT_ID                VARCHAR2(30 BYTE),
  MAT_VER               NUMBER(6,0),
  FLOW                  VARCHAR2(20 BYTE),
  FLOW_SEQ_NUM          NUMBER(6,0),
  OPER                  VARCHAR2(10 BYTE),
  QTY_1                 NUMBER(10,3),
  QTY_2                 NUMBER(10,3),
  QTY_3                 NUMBER(10,3),
  CRR_ID                VARCHAR2(20 BYTE),
  LOT_TYPE              CHAR(1 BYTE)            DEFAULT ('P')                 NOT NULL ENABLE,
  OWNER_CODE            VARCHAR2(10 BYTE),
  CREATE_CODE           VARCHAR2(10 BYTE),
  LOT_PRIORITY          CHAR(1 BYTE)            DEFAULT ('5')                 NOT NULL ENABLE,
  LOT_STATUS            VARCHAR2(10 BYTE),
  HOLD_FLAG             CHAR(1 BYTE),
  HOLD_CODE             VARCHAR2(10 BYTE),
  HOLD_PASSWORD         VARCHAR2(20 BYTE),
  HOLD_PRV_GRP_ID       VARCHAR2(20 BYTE),
  OPER_IN_QTY_1         NUMBER(10,3),
  OPER_IN_QTY_2         NUMBER(10,3),
  OPER_IN_QTY_3         NUMBER(10,3),
  CREATE_QTY_1          NUMBER(10,3),
  CREATE_QTY_2          NUMBER(10,3),
  CREATE_QTY_3          NUMBER(10,3),
  START_QTY_1           NUMBER(10,3),
  START_QTY_2           NUMBER(10,3),
  START_QTY_3           NUMBER(10,3),
  INV_FLAG              CHAR(1 BYTE),
  TRANSIT_FLAG          CHAR(1 BYTE),
  UNIT_EXIST_FLAG       CHAR(1 BYTE),
  INV_UNIT              VARCHAR2(10 BYTE),
  RWK_FLAG              CHAR(1 BYTE),
  RWK_CODE              VARCHAR2(10 BYTE),
  RWK_COUNT             NUMBER(6,0),
  RWK_RET_FLOW          VARCHAR2(20 BYTE),
  RWK_RET_FLOW_SEQ_NUM  NUMBER(6,0),
  RWK_RET_OPER          VARCHAR2(10 BYTE),
  RWK_END_FLOW          VARCHAR2(20 BYTE),
  RWK_END_FLOW_SEQ_NUM  NUMBER(6,0),
  RWK_END_OPER          VARCHAR2(10 BYTE),
  RWK_RET_CLEAR_FLAG    CHAR(1 BYTE),
  RWK_TIME              DATE,
  NSTD_FLAG             CHAR(1 BYTE),
  NSTD_RET_FLOW         VARCHAR2(20 BYTE),
  NSTD_RET_FLOW_SEQ_NUM NUMBER(6,0),
  NSTD_RET_OPER         VARCHAR2(10 BYTE),
  NSTD_TIME             DATE,
  REP_FLAG              CHAR(1 BYTE),
  REP_RET_OPER          VARCHAR2(10 BYTE),
  STR_RET_FLOW          VARCHAR2(20 BYTE),
  STR_RET_FLOW_SEQ_NUM  NUMBER(6,0),
  STR_RET_OPER          VARCHAR2(10 BYTE),
  START_FLAG            CHAR(1 BYTE),
  START_TIME            DATE,
  START_RES_ID          VARCHAR2(20 BYTE),
  END_FLAG              CHAR(1 BYTE),
  END_TIME              DATE,
  END_RES_ID            VARCHAR2(20 BYTE),
  SAMPLE_FLAG           CHAR(1 BYTE),
  SAMPLE_WAIT_FLAG      CHAR(1 BYTE),
  SAMPLE_RESULT         CHAR(1 BYTE),
  FROM_TO_FLAG          CHAR(1 BYTE),
  FROM_TO_LOT_ID        VARCHAR2(25 BYTE),
  SHIP_CODE             VARCHAR2(10 BYTE),
  SHIP_TIME             DATE,
  ORG_DUE_TIME          DATE,
  SCH_DUE_TIME          DATE,
  CREATE_TIME           DATE,
  FAC_IN_TIME           DATE,
  FLOW_IN_TIME          DATE,
  OPER_IN_TIME          DATE,
  RESERVE_RES_ID        VARCHAR2(20 BYTE),
  PORT_ID               VARCHAR2(10 BYTE),
  BATCH_ID              VARCHAR2(25 BYTE),
  BATCH_SEQ             NUMBER(3,0),
  ORDER_ID              VARCHAR2(25 BYTE),
  ADD_ORDER_ID_1        VARCHAR2(25 BYTE),
  ADD_ORDER_ID_2        VARCHAR2(25 BYTE),
  ADD_ORDER_ID_3        VARCHAR2(25 BYTE),
  LOT_LOCATION_1        VARCHAR2(20 BYTE),
  LOT_LOCATION_2        VARCHAR2(20 BYTE),
  LOT_LOCATION_3        VARCHAR2(20 BYTE),
  LOT_CMF_1             VARCHAR2(30 BYTE),
  LOT_CMF_2             VARCHAR2(30 BYTE),
  LOT_CMF_3             VARCHAR2(30 BYTE),
  LOT_CMF_4             VARCHAR2(30 BYTE),
  LOT_CMF_5             VARCHAR2(30 BYTE),
  LOT_CMF_6             VARCHAR2(30 BYTE),
  LOT_CMF_7             VARCHAR2(30 BYTE),
  LOT_CMF_8             VARCHAR2(30 BYTE),
  LOT_CMF_9             VARCHAR2(30 BYTE),
  LOT_CMF_10            VARCHAR2(30 BYTE),
  LOT_CMF_11            VARCHAR2(30 BYTE),
  LOT_CMF_12            VARCHAR2(30 BYTE),
  LOT_CMF_13            VARCHAR2(30 BYTE),
  LOT_CMF_14            VARCHAR2(30 BYTE),
  LOT_CMF_15            VARCHAR2(30 BYTE),
  LOT_CMF_16            VARCHAR2(30 BYTE),
  LOT_CMF_17            VARCHAR2(30 BYTE),
  LOT_CMF_18            VARCHAR2(30 BYTE),
  LOT_CMF_19            VARCHAR2(30 BYTE),
  LOT_CMF_20            VARCHAR2(30 BYTE),
  LOT_DEL_FLAG          CHAR(1 BYTE),
  LOT_DEL_CODE          VARCHAR2(10 BYTE),
  LOT_DEL_TIME          DATE,
  BOM_SET_ID            VARCHAR2(25 BYTE),
  BOM_SET_VERSION       NUMBER(3,0),
  BOM_ACTIVE_HIST_SEQ   NUMBER(10,0),
  BOM_HIST_SEQ          NUMBER(10,0),
  CRITICAL_RES_ID       VARCHAR2(20 BYTE),
  CRITICAL_RES_GROUP_ID VARCHAR2(20 BYTE),
  SAVE_RES_ID_1         VARCHAR2(20 BYTE),
  SAVE_RES_ID_2         VARCHAR2(20 BYTE),
  SUBRES_ID             VARCHAR2(20 BYTE),
  LOT_GROUP_ID_1        VARCHAR2(25 BYTE),
  LOT_GROUP_ID_2        VARCHAR2(25 BYTE),
  LOT_GROUP_ID_3        VARCHAR2(25 BYTE),
  YIELD_1               NUMBER(20,10),
  YIELD_2               NUMBER(20,10),
  YIELD_3               NUMBER(20,10),
  GOOD_QTY              NUMBER(10,3),
  RESV_FIELD_1          VARCHAR2(30 BYTE),
  RESV_FIELD_2          VARCHAR2(30 BYTE),
  RESV_FIELD_3          VARCHAR2(30 BYTE),
  RESV_FIELD_4          VARCHAR2(30 BYTE),
  RESV_FIELD_5          VARCHAR2(30 BYTE),
  RESV_FLAG_1           CHAR(1 BYTE),
  RESV_FLAG_2           CHAR(1 BYTE),
  RESV_FLAG_3           CHAR(1 BYTE),
  RESV_FLAG_4           CHAR(1 BYTE),
  RESV_FLAG_5           CHAR(1 BYTE),
  FROM_TO_MAT_ID        VARCHAR2(30 BYTE),
  FROM_TO_MAT_VER       NUMBER(6,0),
  FROM_TO_FLOW          VARCHAR2(20 BYTE),
  FROM_TO_FLOW_SEQ_NUM  NUMBER(6,0),
  FROM_TO_OPER          VARCHAR2(10 BYTE),
  FROM_TO_QTY_1         NUMBER(10,3),
  FROM_TO_QTY_2         NUMBER(10,3),
  FROM_TO_QTY_3         NUMBER(10,3),
  FROM_TO_HIST_SEQ      NUMBER(10,0),
  OLD_FACTORY           VARCHAR2(10 BYTE),
  OLD_MAT_ID            VARCHAR2(30 BYTE),
  OLD_MAT_VER           NUMBER(6,0),
  OLD_FLOW              VARCHAR2(20 BYTE),
  OLD_FLOW_SEQ_NUM      NUMBER(6,0),
  OLD_OPER              VARCHAR2(10 BYTE),
  OLD_QTY_1             NUMBER(10,3),
  OLD_QTY_2             NUMBER(10,3),
  OLD_QTY_3             NUMBER(10,3),
  OLD_LOT_TYPE          CHAR(1 BYTE) DEFAULT ('P') NOT NULL ENABLE,
  OLD_OWNER_CODE        VARCHAR2(10 BYTE),
  OLD_CREATE_CODE       VARCHAR2(10 BYTE),
  OLD_FAC_IN_TIME       DATE,
  OLD_FLOW_IN_TIME      DATE,
  OLD_OPER_IN_TIME      DATE,
  TRAN_CMF_1            VARCHAR2(30 BYTE),
  TRAN_CMF_2            VARCHAR2(30 BYTE),
  TRAN_CMF_3            VARCHAR2(30 BYTE),
  TRAN_CMF_4            VARCHAR2(30 BYTE),
  TRAN_CMF_5            VARCHAR2(30 BYTE),
  TRAN_CMF_6            VARCHAR2(30 BYTE),
  TRAN_CMF_7            VARCHAR2(30 BYTE),
  TRAN_CMF_8            VARCHAR2(30 BYTE),
  TRAN_CMF_9            VARCHAR2(30 BYTE),
  TRAN_CMF_10           VARCHAR2(30 BYTE),
  TRAN_CMF_11           VARCHAR2(30 BYTE),
  TRAN_CMF_12           VARCHAR2(30 BYTE),
  TRAN_CMF_13           VARCHAR2(30 BYTE),
  TRAN_CMF_14           VARCHAR2(30 BYTE),
  TRAN_CMF_15           VARCHAR2(30 BYTE),
  TRAN_CMF_16           VARCHAR2(30 BYTE),
  TRAN_CMF_17           VARCHAR2(30 BYTE),
  TRAN_CMF_18           VARCHAR2(30 BYTE),
  TRAN_CMF_19           VARCHAR2(30 BYTE),
  TRAN_CMF_20           VARCHAR2(30 BYTE),
  TRAN_USER_ID          VARCHAR2(20 BYTE),
  TRAN_COMMENT          VARCHAR2(400 BYTE),
  PREV_ACTIVE_HIST_SEQ  NUMBER(10,0),
  MULTI_TR_KEY          VARCHAR2(30 BYTE),
  MULTI_TR_SEQ          NUMBER(10,0),
  EXT_HIST_SEQ          NUMBER(10,0),
  HIST_DEL_FLAG         CHAR(1 BYTE),
  HIST_DEL_TIME         DATE,
  HIST_DEL_USER_ID      VARCHAR2(20 BYTE),
  HIST_DEL_COMMENT      VARCHAR2(400 BYTE),
  DATE_CREATE DATE,
  DATE_UPDATE DATE
) TABLESPACE REPORT_DATA_TS;
  
ALTER TABLE RWIPLOTDEL
ADD CONSTRAINT RWIPLOTDEL_PK PRIMARY KEY
(
    LOT_ID, HIST_SEQ, SYS_TRAN_TIME
) USING INDEX TABLESPACE REPORT_IDX_TS;
  
/* RWIPSLTSTS : Sub Lot Status Table */
CREATE TABLE RWIPSLTSTS
(
  SUBLOT_ID              VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  LOT_ID                 VARCHAR2(25 BYTE),
  FACTORY                VARCHAR2(10 BYTE),
  MAT_ID                 VARCHAR2(30 BYTE),
  MAT_VER                NUMBER(6),
  FLOW                   VARCHAR2(20 BYTE),
  FLOW_SEQ_NUM           NUMBER(6),
  OPER                   VARCHAR2(10 BYTE),
  SLOT_NO                NUMBER(6),
  QTY_2                  NUMBER(10,3),
  QTY_3                  NUMBER(10,3),
  CRR_ID                 VARCHAR2(20 BYTE),
  OWNER_CODE             VARCHAR2(10 BYTE),
  CREATE_CODE            VARCHAR2(10 BYTE),
  SUBLOT_STATUS          VARCHAR2(10 BYTE),
  HOLD_FLAG              VARCHAR2(1 BYTE),
  HOLD_CODE              VARCHAR2(10 BYTE),
  HOLD_PASSWORD          VARCHAR2(20 BYTE),
  HOLD_PRV_GRP_ID        VARCHAR2(20 BYTE),
  OPER_IN_QTY_2          NUMBER(10,3),
  OPER_IN_QTY_3          NUMBER(10,3),
  CREATE_QTY_2           NUMBER(10,3),
  CREATE_QTY_3           NUMBER(10,3),
  START_QTY_2            NUMBER(10,3),
  START_QTY_3            NUMBER(10,3),
  INV_FLAG               VARCHAR2(1 BYTE),
  TRANSIT_FLAG           VARCHAR2(1 BYTE),
  UNIT_EXIST_FLAG        VARCHAR2(1 BYTE),
  INV_UNIT               VARCHAR2(10 BYTE),
  RWK_FLAG               VARCHAR2(1 BYTE),
  RWK_CODE               VARCHAR2(10 BYTE),
  RWK_COUNT              NUMBER(6),
  RWK_RET_FLOW           VARCHAR2(20 BYTE),
  RWK_RET_FLOW_SEQ_NUM   NUMBER(6),
  RWK_RET_OPER           VARCHAR2(10 BYTE),
  RWK_END_FLOW           VARCHAR2(20 BYTE),
  RWK_END_FLOW_SEQ_NUM   NUMBER(6),
  RWK_END_OPER           VARCHAR2(10 BYTE),
  RWK_RET_CLEAR_FLAG     VARCHAR2(1 BYTE),
  RWK_TIME               DATE,
  NSTD_FLAG              VARCHAR2(1 BYTE),
  NSTD_RET_FLOW          VARCHAR2(20 BYTE),
  NSTD_RET_FLOW_SEQ_NUM  NUMBER(6),
  NSTD_RET_OPER          VARCHAR2(10 BYTE),
  NSTD_TIME              DATE,
  REP_FLAG               VARCHAR2(1 BYTE),
  REP_RET_OPER           VARCHAR2(10 BYTE),
  STR_RET_FLOW           VARCHAR2(20 BYTE),
  STR_RET_FLOW_SEQ_NUM   NUMBER(6),
  STR_RET_OPER           VARCHAR2(10 BYTE),
  CREATE_TIME            DATE,
  FAC_IN_TIME            DATE,
  FLOW_IN_TIME           DATE,
  OPER_IN_TIME           DATE,
  START_FLAG             VARCHAR2(1 BYTE),
  START_TIME             DATE,
  START_RES_ID           VARCHAR2(20 BYTE),
  END_FLAG               VARCHAR2(1 BYTE),
  END_TIME               DATE,
  END_RES_ID             VARCHAR2(20 BYTE),
  SAMPLE_FLAG            VARCHAR2(1 BYTE),
  SAMPLE_WAIT_FLAG       VARCHAR2(1 BYTE),
  SAMPLE_RESULT          VARCHAR2(1 BYTE),
  RESERVE_RES_ID         VARCHAR2(20 BYTE),
  PORT_ID                VARCHAR2(10 BYTE),
  SUBLOT_LOCATION_1      VARCHAR2(20 BYTE),
  SUBLOT_LOCATION_2      VARCHAR2(20 BYTE),
  SUBLOT_LOCATION_3      VARCHAR2(20 BYTE),
  SUBRES_ID              VARCHAR2(20 BYTE),
  SUBLOT_CMF_1           VARCHAR2(30 BYTE),
  SUBLOT_CMF_2           VARCHAR2(30 BYTE),
  SUBLOT_CMF_3           VARCHAR2(30 BYTE),
  SUBLOT_CMF_4           VARCHAR2(30 BYTE),
  SUBLOT_CMF_5           VARCHAR2(30 BYTE),
  SUBLOT_CMF_6           VARCHAR2(30 BYTE),
  SUBLOT_CMF_7           VARCHAR2(30 BYTE),
  SUBLOT_CMF_8           VARCHAR2(30 BYTE),
  SUBLOT_CMF_9           VARCHAR2(30 BYTE),
  SUBLOT_CMF_10          VARCHAR2(30 BYTE),
  SUBLOT_CMF_11          VARCHAR2(30 BYTE),
  SUBLOT_CMF_12          VARCHAR2(30 BYTE),
  SUBLOT_CMF_13          VARCHAR2(30 BYTE),
  SUBLOT_CMF_14          VARCHAR2(30 BYTE),
  SUBLOT_CMF_15          VARCHAR2(30 BYTE),
  SUBLOT_CMF_16          VARCHAR2(30 BYTE),
  SUBLOT_CMF_17          VARCHAR2(30 BYTE),
  SUBLOT_CMF_18          VARCHAR2(30 BYTE),
  SUBLOT_CMF_19          VARCHAR2(30 BYTE),
  SUBLOT_CMF_20          VARCHAR2(30 BYTE),
  SUBLOT_DEL_FLAG        VARCHAR2(1 BYTE),
  SUBLOT_DEL_CODE        VARCHAR2(10 BYTE),
  SUBLOT_DEL_TIME        DATE,
  GRADE                  VARCHAR2(1 BYTE),
  GRADE_CODE             VARCHAR2(10 BYTE),
  CELL_GRADE             VARCHAR2(500 BYTE),
  CELL_JUDGE             VARCHAR2(500 BYTE),
  LOT_BASE               VARCHAR2(1 BYTE),
  LOT_HIST_SEQ           NUMBER(10),
  LAST_TRAN_CODE         VARCHAR2(12 BYTE),
  LAST_TRAN_TIME         DATE,
  LAST_COMMENT           VARCHAR2(400 BYTE),
  LAST_ACTIVE_HIST_SEQ   NUMBER(10),
  LAST_HIST_SEQ          NUMBER(10),
  SUBLOT_TYPE            CHAR(1),
  RESV_FIELD_1           VARCHAR2(30),
  RESV_FIELD_2           VARCHAR2(30),
  RESV_FIELD_3           VARCHAR2(30),
  RESV_FIELD_4           VARCHAR2(30),
  RESV_FIELD_5           VARCHAR2(30),
  RESV_FLAG_1            CHAR(1),
  RESV_FLAG_2            CHAR(1),
  RESV_FLAG_3            CHAR(1),
  RESV_FLAG_4            CHAR(1),
  RESV_FLAG_5            CHAR(1)
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPSLTSTS
ADD CONSTRAINT RWIPSLTSTS_PK PRIMARY KEY
(
    SUBLOT_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;



/* RWIPLOTDUE : Lot Forecast Due Date Table */
CREATE TABLE RWIPLOTDUE
(
    /* Lot ID는 모든 Factory에서 Unique */
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Current Factory */
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    /* Flow, Oper */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Quantity 1 ~ 3 */
    QTY_1                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* LOT의 우선순위 - '0'-->'9' LOW-->HIGH, 기본값:'5' */ 
    LOT_PRIORITY                CHAR(1)          DEFAULT('5')    NOT NULL,
    /* Lot Status - PROC:In Process, WAIT:Wait, MOVE : Moving */
    LOT_STATUS                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Hold Info. */
    HOLD_FLAG                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Inventory Operation에 들어 있음. MOVE 불가능 */
    INV_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* RECEIVING 대기 */
    TRANSIT_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Rework Info. */
    RWK_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Due Time(Original, Scheduled) */
    ORG_DUE_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    SCH_DUE_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Remain Queue Time, Process Time */
    REMAIN_QUEUE_TIME           NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    REMAIN_PROC_TIME            NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Forecast Due Time */
    FORECAST_DUE_TIME           VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Create Time */
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPLOTDUE
ADD CONSTRAINT RWIPLOTDUE_PK PRIMARY KEY
(
    LOT_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* WIP Loader History Table */
CREATE TABLE RSUMWIPLDR
(
    /* Factory */
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Work Date - YYYYMMDD */
    WORK_DATE                   CHAR(8)          DEFAULT(' ')    NOT NULL,
    WORK_SHIFT                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    LAST_TRAN_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RSUMWIPLDR
ADD CONSTRAINT RSUMWIPLDR_PK PRIMARY KEY
(
    FACTORY,
    WORK_DATE,
    WORK_SHIFT
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* WIP BOH, EOH Summary Table */
CREATE TABLE RSUMWIPEOH
(
  WORK_DATE         CHAR(8 BYTE)                DEFAULT (' ')                 NOT NULL,
  SHIFT             CHAR(1 BYTE)                DEFAULT (' ')                 NOT NULL,
  FACTORY           VARCHAR2(10 BYTE)           DEFAULT (' ')                 NOT NULL,
  MAT_ID            VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  MAT_VER           NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  FLOW              VARCHAR2(20 BYTE)           DEFAULT (' ')                 NOT NULL,
  FLOW_SEQ_NUM      NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  OPER              VARCHAR2(10 BYTE)           DEFAULT (' ')                 NOT NULL,
  LOT_TYPE          CHAR(1 BYTE)                DEFAULT ('P')                 NOT NULL,
  ORDER_ID          VARCHAR2(25 BYTE)           DEFAULT (' ')                 NOT NULL,
  CM_KEY_1          VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CM_KEY_2          VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CM_KEY_3          VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CM_KEY_4          VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  CM_KEY_5          VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  WORK_MONTH        CHAR(6 BYTE)                DEFAULT (' ')                 NOT NULL,
  WORK_WEEK         CHAR(6 BYTE)                DEFAULT (' ')                 NOT NULL,
  WORK_DAYS         CHAR(3 BYTE)                DEFAULT (' ')                 NOT NULL,
  WORK_DAY_OF_WEEK  CHAR(1 BYTE)                DEFAULT (' ')                 NOT NULL,
  EOH_LOT           NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  EOH_QTY_1         NUMBER(15,3)                DEFAULT (0.0)                 NOT NULL,
  EOH_QTY_2         NUMBER(15,3)                DEFAULT (0.0)                 NOT NULL,
  EOH_QTY_3         NUMBER(15,3)                DEFAULT (0.0)                 NOT NULL,
  EOH_HOLD_LOT      NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  EOH_HOLD_QTY_1    NUMBER(15,3)                DEFAULT (0.0)                 NOT NULL,
  EOH_HOLD_QTY_2    NUMBER(15,3)                DEFAULT (0.0)                 NOT NULL,
  EOH_HOLD_QTY_3    NUMBER(15,3)                DEFAULT (0.0)                 NOT NULL,
  EOH_RWK_LOT       NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  EOH_RWK_QTY_1     NUMBER(15,3)                DEFAULT (0.0)                 NOT NULL,
  EOH_RWK_QTY_2     NUMBER(15,3)                DEFAULT (0.0)                 NOT NULL,
  EOH_RWK_QTY_3     NUMBER(15,3)                DEFAULT (0.0)                 NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RSUMWIPEOH
ADD CONSTRAINT RSUMWIPEOH_PK PRIMARY KEY
(
    WORK_DATE, 
    SHIFT, 
    FACTORY, 
    MAT_ID, 
    MAT_VER, 
    FLOW, 
    FLOW_SEQ_NUM, 
    OPER, 
    LOT_TYPE, 
    ORDER_ID, 
    CM_KEY_1, 
    CM_KEY_2, 
    CM_KEY_3, 
    CM_KEY_4, 
    CM_KEY_5
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE OR REPLACE VIEW RSUMWIPBOH
(WORK_DATE, FACTORY, MAT_ID, MAT_VER, FLOW, 
 FLOW_SEQ_NUM, OPER, LOT_TYPE, ORDER_ID, CM_KEY_1, 
 CM_KEY_2, CM_KEY_3, CM_KEY_4, CM_KEY_5, WORK_MONTH, 
 WORK_WEEK, WORK_DAYS, WORK_DAY_OF_WEEK, S1_BOH_LOT, S2_BOH_LOT, 
 S3_BOH_LOT, S4_BOH_LOT, S1_BOH_QTY_1, S2_BOH_QTY_1, S3_BOH_QTY_1, 
 S4_BOH_QTY_1, S1_BOH_QTY_2, S2_BOH_QTY_2, S3_BOH_QTY_2, S4_BOH_QTY_2, 
 S1_BOH_HOLD_LOT, S2_BOH_HOLD_LOT, S3_BOH_HOLD_LOT, S4_BOH_HOLD_LOT, S1_BOH_HOLD_QTY_1, 
 S2_BOH_HOLD_QTY_1, S3_BOH_HOLD_QTY_1, S4_BOH_HOLD_QTY_1, S1_BOH_HOLD_QTY_2, S2_BOH_HOLD_QTY_2, 
 S3_BOH_HOLD_QTY_2, S4_BOH_HOLD_QTY_2, S1_BOH_RWK_LOT, S2_BOH_RWK_LOT, S3_BOH_RWK_LOT, 
 S4_BOH_RWK_LOT, S1_BOH_RWK_QTY_1, S2_BOH_RWK_QTY_1, S3_BOH_RWK_QTY_1, S4_BOH_RWK_QTY_1, 
 S1_BOH_RWK_QTY_2, S2_BOH_RWK_QTY_2, S3_BOH_RWK_QTY_2, S4_BOH_RWK_QTY_2, S1_EOH_LOT, 
 S2_EOH_LOT, S3_EOH_LOT, S4_EOH_LOT, S1_EOH_QTY_1, S2_EOH_QTY_1, 
 S3_EOH_QTY_1, S4_EOH_QTY_1, S1_EOH_QTY_2, S2_EOH_QTY_2, S3_EOH_QTY_2, 
 S4_EOH_QTY_2, S1_EOH_HOLD_LOT, S2_EOH_HOLD_LOT, S3_EOH_HOLD_LOT, S4_EOH_HOLD_LOT, 
 S1_EOH_HOLD_QTY_1, S2_EOH_HOLD_QTY_1, S3_EOH_HOLD_QTY_1, S4_EOH_HOLD_QTY_1, S1_EOH_HOLD_QTY_2, 
 S2_EOH_HOLD_QTY_2, S3_EOH_HOLD_QTY_2, S4_EOH_HOLD_QTY_2, S1_EOH_RWK_LOT, S2_EOH_RWK_LOT, 
 S3_EOH_RWK_LOT, S4_EOH_RWK_LOT, S1_EOH_RWK_QTY_1, S2_EOH_RWK_QTY_1, S3_EOH_RWK_QTY_1, 
 S4_EOH_RWK_QTY_1, S1_EOH_RWK_QTY_2, S2_EOH_RWK_QTY_2, S3_EOH_RWK_QTY_2, S4_EOH_RWK_QTY_2)
AS 
SELECT
WORK_DATE         ,FACTORY           ,MAT_ID            ,MAT_VER           ,FLOW              ,FLOW_SEQ_NUM      ,OPER              ,
LOT_TYPE          ,ORDER_ID          ,CM_KEY_1          ,CM_KEY_2          ,CM_KEY_3          ,CM_KEY_4          ,CM_KEY_5          ,
MAX(WORK_MONTH)        ,MAX(WORK_WEEK)         ,MAX(WORK_DAYS)         ,MAX(WORK_DAY_OF_WEEK),
SUM(S1_BOH_LOT         ) AS S1_BOH_LOT         ,
SUM(S2_BOH_LOT         ) AS S2_BOH_LOT         ,
SUM(S3_BOH_LOT         ) AS S3_BOH_LOT         ,
SUM(S4_BOH_LOT         ) AS S4_BOH_LOT         ,
SUM(S1_BOH_QTY_1       ) AS S1_BOH_QTY_1       ,
SUM(S2_BOH_QTY_1       ) AS S2_BOH_QTY_1       ,
SUM(S3_BOH_QTY_1       ) AS S3_BOH_QTY_1       ,
SUM(S4_BOH_QTY_1       ) AS S4_BOH_QTY_1       ,
SUM(S1_BOH_QTY_2       ) AS S1_BOH_QTY_2       ,
SUM(S2_BOH_QTY_2       ) AS S2_BOH_QTY_2       ,
SUM(S3_BOH_QTY_2       ) AS S3_BOH_QTY_2       ,
SUM(S4_BOH_QTY_2       ) AS S4_BOH_QTY_2       ,
SUM(S1_BOH_HOLD_LOT    ) AS S1_BOH_HOLD_LOT    ,
SUM(S2_BOH_HOLD_LOT    ) AS S2_BOH_HOLD_LOT    ,
SUM(S3_BOH_HOLD_LOT    ) AS S3_BOH_HOLD_LOT    ,
SUM(S4_BOH_HOLD_LOT    ) AS S4_BOH_HOLD_LOT    ,
SUM(S1_BOH_HOLD_QTY_1  ) AS S1_BOH_HOLD_QTY_1  ,
SUM(S2_BOH_HOLD_QTY_1  ) AS S2_BOH_HOLD_QTY_1  ,
SUM(S3_BOH_HOLD_QTY_1  ) AS S3_BOH_HOLD_QTY_1  ,
SUM(S4_BOH_HOLD_QTY_1  ) AS S4_BOH_HOLD_QTY_1  ,
SUM(S1_BOH_HOLD_QTY_2  ) AS S1_BOH_HOLD_QTY_2  ,
SUM(S2_BOH_HOLD_QTY_2  ) AS S2_BOH_HOLD_QTY_2  ,
SUM(S3_BOH_HOLD_QTY_2  ) AS S3_BOH_HOLD_QTY_2  ,
SUM(S4_BOH_HOLD_QTY_2  ) AS S4_BOH_HOLD_QTY_2  ,
SUM(S1_BOH_RWK_LOT     ) AS S1_BOH_RWK_LOT     ,
SUM(S2_BOH_RWK_LOT     ) AS S2_BOH_RWK_LOT     ,
SUM(S3_BOH_RWK_LOT     ) AS S3_BOH_RWK_LOT     ,
SUM(S4_BOH_RWK_LOT     ) AS S4_BOH_RWK_LOT     ,
SUM(S1_BOH_RWK_QTY_1   ) AS S1_BOH_RWK_QTY_1   ,
SUM(S2_BOH_RWK_QTY_1   ) AS S2_BOH_RWK_QTY_1   ,
SUM(S3_BOH_RWK_QTY_1   ) AS S3_BOH_RWK_QTY_1   ,
SUM(S4_BOH_RWK_QTY_1   ) AS S4_BOH_RWK_QTY_1   ,
SUM(S1_BOH_RWK_QTY_2   ) AS S1_BOH_RWK_QTY_2   ,
SUM(S2_BOH_RWK_QTY_2   ) AS S2_BOH_RWK_QTY_2   ,
SUM(S3_BOH_RWK_QTY_2   ) AS S3_BOH_RWK_QTY_2   ,
SUM(S4_BOH_RWK_QTY_2   ) AS S4_BOH_RWK_QTY_2   ,
SUM(S1_EOH_LOT         ) AS S1_EOH_LOT         ,
SUM(S2_EOH_LOT         ) AS S2_EOH_LOT         ,
SUM(S3_EOH_LOT         ) AS S3_EOH_LOT         ,
SUM(S4_EOH_LOT         ) AS S4_EOH_LOT         ,
SUM(S1_EOH_QTY_1       ) AS S1_EOH_QTY_1       ,
SUM(S2_EOH_QTY_1       ) AS S2_EOH_QTY_1       ,
SUM(S3_EOH_QTY_1       ) AS S3_EOH_QTY_1       ,
SUM(S4_EOH_QTY_1       ) AS S4_EOH_QTY_1       ,
SUM(S1_EOH_QTY_2       ) AS S1_EOH_QTY_2       ,
SUM(S2_EOH_QTY_2       ) AS S2_EOH_QTY_2       ,
SUM(S3_EOH_QTY_2       ) AS S3_EOH_QTY_2       ,
SUM(S4_EOH_QTY_2       ) AS S4_EOH_QTY_2       ,
SUM(S1_EOH_HOLD_LOT    ) AS S1_EOH_HOLD_LOT    ,
SUM(S2_EOH_HOLD_LOT    ) AS S2_EOH_HOLD_LOT    ,
SUM(S3_EOH_HOLD_LOT    ) AS S3_EOH_HOLD_LOT    ,
SUM(S4_EOH_HOLD_LOT    ) AS S4_EOH_HOLD_LOT    ,
SUM(S1_EOH_HOLD_QTY_1  ) AS S1_EOH_HOLD_QTY_1  ,
SUM(S2_EOH_HOLD_QTY_1  ) AS S2_EOH_HOLD_QTY_1  ,
SUM(S3_EOH_HOLD_QTY_1  ) AS S3_EOH_HOLD_QTY_1  ,
SUM(S4_EOH_HOLD_QTY_1  ) AS S4_EOH_HOLD_QTY_1  ,
SUM(S1_EOH_HOLD_QTY_2  ) AS S1_EOH_HOLD_QTY_2  ,
SUM(S2_EOH_HOLD_QTY_2  ) AS S2_EOH_HOLD_QTY_2  ,
SUM(S3_EOH_HOLD_QTY_2  ) AS S3_EOH_HOLD_QTY_2  ,
SUM(S4_EOH_HOLD_QTY_2  ) AS S4_EOH_HOLD_QTY_2  ,
SUM(S1_EOH_RWK_LOT     ) AS S1_EOH_RWK_LOT     ,
SUM(S2_EOH_RWK_LOT     ) AS S2_EOH_RWK_LOT     ,
SUM(S3_EOH_RWK_LOT     ) AS S3_EOH_RWK_LOT     ,
SUM(S4_EOH_RWK_LOT     ) AS S4_EOH_RWK_LOT     ,
SUM(S1_EOH_RWK_QTY_1   ) AS S1_EOH_RWK_QTY_1   ,
SUM(S2_EOH_RWK_QTY_1   ) AS S2_EOH_RWK_QTY_1   ,
SUM(S3_EOH_RWK_QTY_1   ) AS S3_EOH_RWK_QTY_1   ,
SUM(S4_EOH_RWK_QTY_1   ) AS S4_EOH_RWK_QTY_1   ,
SUM(S1_EOH_RWK_QTY_2   ) AS S1_EOH_RWK_QTY_2   ,
SUM(S2_EOH_RWK_QTY_2   ) AS S2_EOH_RWK_QTY_2   ,
SUM(S3_EOH_RWK_QTY_2   ) AS S3_EOH_RWK_QTY_2   ,
SUM(S4_EOH_RWK_QTY_2   ) AS S4_EOH_RWK_QTY_2   
  FROM (  
        SELECT
        WORK_DATE         ,FACTORY           ,MAT_ID            ,MAT_VER           ,FLOW              ,FLOW_SEQ_NUM      ,OPER              ,
        LOT_TYPE          ,ORDER_ID          ,CM_KEY_1          ,CM_KEY_2          ,CM_KEY_3          ,CM_KEY_4          ,CM_KEY_5          ,
        WORK_MONTH        ,WORK_WEEK         ,WORK_DAYS         ,
        ' ' AS WORK_DAY_OF_WEEK  ,
        0 AS S1_BOH_LOT         ,
        SUM(DECODE(SHIFT,'1', EOH_LOT        ,0)) AS S2_BOH_LOT         ,
        SUM(DECODE(SHIFT,'2', EOH_LOT        ,0)) AS S3_BOH_LOT         ,
        SUM(DECODE(SHIFT,'3', EOH_LOT        ,0)) AS S4_BOH_LOT         ,
        0 AS S1_BOH_QTY_1       ,
        SUM(DECODE(SHIFT,'1', EOH_QTY_1      ,0)) AS S2_BOH_QTY_1       ,
        SUM(DECODE(SHIFT,'2', EOH_QTY_1      ,0)) AS S3_BOH_QTY_1       ,
        SUM(DECODE(SHIFT,'3', EOH_QTY_1      ,0)) AS S4_BOH_QTY_1       ,
        0 AS S1_BOH_QTY_2       ,
        SUM(DECODE(SHIFT,'1', EOH_QTY_2      ,0)) AS S2_BOH_QTY_2       ,
        SUM(DECODE(SHIFT,'2', EOH_QTY_2      ,0)) AS S3_BOH_QTY_2       ,
        SUM(DECODE(SHIFT,'3', EOH_QTY_2      ,0)) AS S4_BOH_QTY_2       ,
        0 AS S1_BOH_HOLD_LOT    ,
        SUM(DECODE(SHIFT,'1', EOH_HOLD_LOT   ,0)) AS S2_BOH_HOLD_LOT    ,
        SUM(DECODE(SHIFT,'2', EOH_HOLD_LOT   ,0)) AS S3_BOH_HOLD_LOT    ,
        SUM(DECODE(SHIFT,'3', EOH_HOLD_LOT   ,0)) AS S4_BOH_HOLD_LOT    ,
        0 AS S1_BOH_HOLD_QTY_1  ,
        SUM(DECODE(SHIFT,'1', EOH_HOLD_QTY_1 ,0)) AS S2_BOH_HOLD_QTY_1  ,
        SUM(DECODE(SHIFT,'2', EOH_HOLD_QTY_1 ,0)) AS S3_BOH_HOLD_QTY_1  ,
        SUM(DECODE(SHIFT,'3', EOH_HOLD_QTY_1 ,0)) AS S4_BOH_HOLD_QTY_1  ,
        0 AS S1_BOH_HOLD_QTY_2  ,
        SUM(DECODE(SHIFT,'1', EOH_HOLD_QTY_2 ,0)) AS S2_BOH_HOLD_QTY_2  ,
        SUM(DECODE(SHIFT,'2', EOH_HOLD_QTY_2 ,0)) AS S3_BOH_HOLD_QTY_2  ,
        SUM(DECODE(SHIFT,'3', EOH_HOLD_QTY_2 ,0)) AS S4_BOH_HOLD_QTY_2  ,
        0 AS S1_BOH_RWK_LOT     ,
        SUM(DECODE(SHIFT,'1', EOH_RWK_LOT    ,0)) AS S2_BOH_RWK_LOT     ,
        SUM(DECODE(SHIFT,'2', EOH_RWK_LOT    ,0)) AS S3_BOH_RWK_LOT     ,
        SUM(DECODE(SHIFT,'3', EOH_RWK_LOT    ,0)) AS S4_BOH_RWK_LOT     ,
        0 AS S1_BOH_RWK_QTY_1   ,
        SUM(DECODE(SHIFT,'1', EOH_RWK_QTY_1  ,0)) AS S2_BOH_RWK_QTY_1   ,
        SUM(DECODE(SHIFT,'2', EOH_RWK_QTY_1  ,0)) AS S3_BOH_RWK_QTY_1   ,
        SUM(DECODE(SHIFT,'3', EOH_RWK_QTY_1  ,0)) AS S4_BOH_RWK_QTY_1   ,
        0 AS S1_BOH_RWK_QTY_2   ,
        SUM(DECODE(SHIFT,'1', EOH_RWK_QTY_2  ,0)) AS S2_BOH_RWK_QTY_2   ,
        SUM(DECODE(SHIFT,'2', EOH_RWK_QTY_2  ,0)) AS S3_BOH_RWK_QTY_2   ,
        SUM(DECODE(SHIFT,'3', EOH_RWK_QTY_2  ,0)) AS S4_BOH_RWK_QTY_2   ,
        SUM(DECODE(SHIFT,'1',EOH_LOT        ,0)) AS S1_EOH_LOT         ,
        SUM(DECODE(SHIFT,'2',EOH_LOT        ,0)) AS S2_EOH_LOT         ,
        SUM(DECODE(SHIFT,'3',EOH_LOT        ,0)) AS S3_EOH_LOT         ,
        SUM(DECODE(SHIFT,'4',EOH_LOT        ,0)) AS S4_EOH_LOT         ,
        SUM(DECODE(SHIFT,'1',EOH_QTY_1      ,0)) AS S1_EOH_QTY_1       ,
        SUM(DECODE(SHIFT,'2',EOH_QTY_1      ,0)) AS S2_EOH_QTY_1       ,
        SUM(DECODE(SHIFT,'3',EOH_QTY_1      ,0)) AS S3_EOH_QTY_1       ,
        SUM(DECODE(SHIFT,'4',EOH_QTY_1      ,0)) AS S4_EOH_QTY_1       ,
        SUM(DECODE(SHIFT,'1',EOH_QTY_2      ,0)) AS S1_EOH_QTY_2       ,
        SUM(DECODE(SHIFT,'2',EOH_QTY_2      ,0)) AS S2_EOH_QTY_2       ,
        SUM(DECODE(SHIFT,'3',EOH_QTY_2      ,0)) AS S3_EOH_QTY_2       ,
        SUM(DECODE(SHIFT,'4',EOH_QTY_2      ,0)) AS S4_EOH_QTY_2       ,
        SUM(DECODE(SHIFT,'1',EOH_HOLD_LOT   ,0)) AS S1_EOH_HOLD_LOT    ,
        SUM(DECODE(SHIFT,'2',EOH_HOLD_LOT   ,0)) AS S2_EOH_HOLD_LOT    ,
        SUM(DECODE(SHIFT,'3',EOH_HOLD_LOT   ,0)) AS S3_EOH_HOLD_LOT    ,
        SUM(DECODE(SHIFT,'4',EOH_HOLD_LOT   ,0)) AS S4_EOH_HOLD_LOT    ,
        SUM(DECODE(SHIFT,'1',EOH_HOLD_QTY_1 ,0)) AS S1_EOH_HOLD_QTY_1  ,
        SUM(DECODE(SHIFT,'2',EOH_HOLD_QTY_1 ,0)) AS S2_EOH_HOLD_QTY_1  ,
        SUM(DECODE(SHIFT,'3',EOH_HOLD_QTY_1 ,0)) AS S3_EOH_HOLD_QTY_1  ,
        SUM(DECODE(SHIFT,'4',EOH_HOLD_QTY_1 ,0)) AS S4_EOH_HOLD_QTY_1  ,
        SUM(DECODE(SHIFT,'1',EOH_HOLD_QTY_2 ,0)) AS S1_EOH_HOLD_QTY_2  ,
        SUM(DECODE(SHIFT,'2',EOH_HOLD_QTY_2 ,0)) AS S2_EOH_HOLD_QTY_2  ,
        SUM(DECODE(SHIFT,'3',EOH_HOLD_QTY_2 ,0)) AS S3_EOH_HOLD_QTY_2  ,
        SUM(DECODE(SHIFT,'4',EOH_HOLD_QTY_2 ,0)) AS S4_EOH_HOLD_QTY_2  ,
        SUM(DECODE(SHIFT,'1',EOH_RWK_LOT    ,0)) AS S1_EOH_RWK_LOT     ,
        SUM(DECODE(SHIFT,'2',EOH_RWK_LOT    ,0)) AS S2_EOH_RWK_LOT     ,
        SUM(DECODE(SHIFT,'3',EOH_RWK_LOT    ,0)) AS S3_EOH_RWK_LOT     ,
        SUM(DECODE(SHIFT,'4',EOH_RWK_LOT    ,0)) AS S4_EOH_RWK_LOT     ,
        SUM(DECODE(SHIFT,'1',EOH_RWK_QTY_1  ,0)) AS S1_EOH_RWK_QTY_1   ,
        SUM(DECODE(SHIFT,'2',EOH_RWK_QTY_1  ,0)) AS S2_EOH_RWK_QTY_1   ,
        SUM(DECODE(SHIFT,'3',EOH_RWK_QTY_1  ,0)) AS S3_EOH_RWK_QTY_1   ,
        SUM(DECODE(SHIFT,'4',EOH_RWK_QTY_1  ,0)) AS S4_EOH_RWK_QTY_1   ,
        SUM(DECODE(SHIFT,'1',EOH_RWK_QTY_2  ,0)) AS S1_EOH_RWK_QTY_2   ,
        SUM(DECODE(SHIFT,'2',EOH_RWK_QTY_2  ,0)) AS S2_EOH_RWK_QTY_2   ,
        SUM(DECODE(SHIFT,'3',EOH_RWK_QTY_2  ,0)) AS S3_EOH_RWK_QTY_2   ,
        SUM(DECODE(SHIFT,'4',EOH_RWK_QTY_2  ,0)) AS S4_EOH_RWK_QTY_2
        FROM RSUMWIPEOH   
        GROUP BY WORK_DATE         ,FACTORY           ,MAT_ID            ,MAT_VER           ,FLOW              ,FLOW_SEQ_NUM      ,OPER              ,
        LOT_TYPE          ,ORDER_ID          ,CM_KEY_1          ,CM_KEY_2          ,CM_KEY_3          ,CM_KEY_4          ,CM_KEY_5          ,
        WORK_MONTH        ,WORK_WEEK         ,WORK_DAYS         
        UNION ALL
        SELECT
        TO_CHAR(TO_DATE(WORK_DATE,'YYYYMMDD')+1,'YYYYMMDD') AS WORK_DATE
        ,FACTORY           ,MAT_ID            ,MAT_VER           ,FLOW              ,FLOW_SEQ_NUM      ,OPER              ,
        LOT_TYPE          ,ORDER_ID          ,CM_KEY_1          ,CM_KEY_2          ,CM_KEY_3          ,CM_KEY_4          ,CM_KEY_5          ,
        ' ' AS WORK_MONTH        ,' ' AS WORK_WEEK         ,' ' AS WORK_DAYS         ,
        ' ' AS WORK_DAY_OF_WEEK  ,
        SUM(EOH_LOT) AS S1_BOH_LOT         ,0 AS S2_BOH_LOT         ,0 AS S3_BOH_LOT         ,0 AS S4_BOH_LOT         ,
        SUM(EOH_QTY_1) AS S1_BOH_QTY_1       ,0 AS S2_BOH_QTY_1       ,0 AS S3_BOH_QTY_1       ,0 AS S4_BOH_QTY_1       ,
        SUM(EOH_QTY_2) AS S1_BOH_QTY_2       ,0 AS S2_BOH_QTY_2       ,0 AS S3_BOH_QTY_2       ,0 AS S4_BOH_QTY_2       ,
        SUM(EOH_HOLD_LOT) AS S1_BOH_HOLD_LOT    ,0 AS S2_BOH_HOLD_LOT    ,0 AS S3_BOH_HOLD_LOT    ,0 AS S4_BOH_HOLD_LOT    ,
        SUM(EOH_HOLD_QTY_1) AS S1_BOH_HOLD_QTY_1  ,0 AS S2_BOH_HOLD_QTY_1  ,0 AS S3_BOH_HOLD_QTY_1  ,0 AS S4_BOH_HOLD_QTY_1  ,
        SUM(EOH_HOLD_QTY_2) AS S1_BOH_HOLD_QTY_2  ,0 AS S2_BOH_HOLD_QTY_2  ,0 AS S3_BOH_HOLD_QTY_2  ,0 AS S4_BOH_HOLD_QTY_2  ,
        SUM(EOH_RWK_LOT) AS S1_BOH_RWK_LOT     ,0 AS S2_BOH_RWK_LOT     ,0 AS S3_BOH_RWK_LOT     ,0 AS S4_BOH_RWK_LOT     ,
        SUM(EOH_RWK_QTY_1) AS S1_BOH_RWK_QTY_1   ,0 AS S2_BOH_RWK_QTY_1   ,0 AS S3_BOH_RWK_QTY_1   ,0 AS S4_BOH_RWK_QTY_1   ,
        SUM(EOH_RWK_QTY_2) AS S1_BOH_RWK_QTY_2   ,0 AS S2_BOH_RWK_QTY_2   ,0 AS S3_BOH_RWK_QTY_2   ,0 AS S4_BOH_RWK_QTY_2   ,
        0 AS S1_EOH_LOT         ,0 AS S2_EOH_LOT         ,0 AS S3_EOH_LOT         ,0 AS S4_EOH_LOT         ,
        0 AS S1_EOH_QTY_1       ,0 AS S2_EOH_QTY_1       ,0 AS S3_EOH_QTY_1       ,0 AS S4_EOH_QTY_1       ,
        0 AS S1_EOH_QTY_2       ,0 AS S2_EOH_QTY_2       ,0 AS S3_EOH_QTY_2       ,0 AS S4_EOH_QTY_2       ,
        0 AS S1_EOH_HOLD_LOT    ,0 AS S2_EOH_HOLD_LOT    ,0 AS S3_EOH_HOLD_LOT    ,0 AS S4_EOH_HOLD_LOT    ,
        0 AS S1_EOH_HOLD_QTY_1  ,0 AS S2_EOH_HOLD_QTY_1  ,0 AS S3_EOH_HOLD_QTY_1  ,0 AS S4_EOH_HOLD_QTY_1  ,
        0 AS S1_EOH_HOLD_QTY_2  ,0 AS S2_EOH_HOLD_QTY_2  ,0 AS S3_EOH_HOLD_QTY_2  ,0 AS S4_EOH_HOLD_QTY_2  ,
        0 AS S1_EOH_RWK_LOT     ,0 AS S2_EOH_RWK_LOT     ,0 AS S3_EOH_RWK_LOT     ,0 AS S4_EOH_RWK_LOT     ,
        0 AS S1_EOH_RWK_QTY_1   ,0 AS S2_EOH_RWK_QTY_1   ,0 AS S3_EOH_RWK_QTY_1   ,0 AS S4_EOH_RWK_QTY_1   ,
        0 AS S1_EOH_RWK_QTY_2   ,0 AS S2_EOH_RWK_QTY_2   ,0 AS S3_EOH_RWK_QTY_2   ,0 AS S4_EOH_RWK_QTY_2
        FROM RSUMWIPEOH
        WHERE SHIFT=WORK_DAY_OF_WEEK
        GROUP BY WORK_DATE         ,FACTORY           ,MAT_ID            ,MAT_VER           ,FLOW              ,FLOW_SEQ_NUM      ,OPER              ,
        LOT_TYPE          ,ORDER_ID          ,CM_KEY_1          ,CM_KEY_2          ,CM_KEY_3          ,CM_KEY_4          ,CM_KEY_5          
        )
GROUP BY 
WORK_DATE         ,FACTORY           ,MAT_ID            ,MAT_VER           ,FLOW              ,FLOW_SEQ_NUM      ,OPER              ,
LOT_TYPE          ,ORDER_ID          ,CM_KEY_1          ,CM_KEY_2          ,CM_KEY_3          ,CM_KEY_4          ,CM_KEY_5;


/* WIP Movement Summary Table */
CREATE TABLE RSUMWIPMOV
(
    /* Work Date - YYYYMMDD */
    WORK_DATE                   CHAR(8)          DEFAULT(' ')    NOT NULL,
    /* Factory */
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 SEQ_NUM -> FLOW_SEQ_NUM */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Lot Type - 'P':Production, 'T':Test, 'E':Engineer, 'D':Dummy, 'M':Monitoring */
    LOT_TYPE                    CHAR(1)          DEFAULT('P')    NOT NULL,
    ORDER_ID                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* For additional Key 1 ~ 5 */
    CM_KEY_1                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_2                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_3                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_4                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_5                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Work Month - YYYY01 ~ YYYY12 */
    WORK_MONTH                  CHAR(6)          DEFAULT(' ')    NOT NULL,
    /* Work Week - YYYYWW */
    WORK_WEEK                   CHAR(6)          DEFAULT(' ')    NOT NULL,
    /* Work Week - 001 ~ 365 */
    WORK_DAYS                   CHAR(3)          DEFAULT(' ')    NOT NULL,
    /* 요일(Day of the week) - 0:일요일 1:월요일 ~ 6:금요일 */
    WORK_DAY_OF_WEEK            CHAR(1)          DEFAULT(' ')    NOT NULL,
    /** IN/OUT Data **/
    /* OPER IN LOT */
    S1_OPER_IN_LOT              NUMBER(6)        DEFAULT(0)      NOT NULL,
    S2_OPER_IN_LOT              NUMBER(6)        DEFAULT(0)      NOT NULL,
    S3_OPER_IN_LOT              NUMBER(6)        DEFAULT(0)      NOT NULL,
    S4_OPER_IN_LOT              NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* OPER IN QTY 1 ~ 3 */
    S1_OPER_IN_QTY_1            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_OPER_IN_QTY_1            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_OPER_IN_QTY_1            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_OPER_IN_QTY_1            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_OPER_IN_QTY_2            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_OPER_IN_QTY_2            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_OPER_IN_QTY_2            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_OPER_IN_QTY_2            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_OPER_IN_QTY_3            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_OPER_IN_QTY_3            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_OPER_IN_QTY_3            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_OPER_IN_QTY_3            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* OPER IN REWORK LOT */
    S1_OPER_IN_RWK_LOT          NUMBER(6)        DEFAULT(0)      NOT NULL,
    S2_OPER_IN_RWK_LOT          NUMBER(6)        DEFAULT(0)      NOT NULL,
    S3_OPER_IN_RWK_LOT          NUMBER(6)        DEFAULT(0)      NOT NULL,
    S4_OPER_IN_RWK_LOT          NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* OPER IN REWORK QTY 1 ~ 3 */
    S1_OPER_IN_RWK_QTY_1        NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_OPER_IN_RWK_QTY_1        NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_OPER_IN_RWK_QTY_1        NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_OPER_IN_RWK_QTY_1        NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_OPER_IN_RWK_QTY_2        NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_OPER_IN_RWK_QTY_2        NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_OPER_IN_RWK_QTY_2        NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_OPER_IN_RWK_QTY_2        NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_OPER_IN_RWK_QTY_3        NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_OPER_IN_RWK_QTY_3        NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_OPER_IN_RWK_QTY_3        NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_OPER_IN_RWK_QTY_3        NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* START LOT */
    S1_START_LOT                NUMBER(6)        DEFAULT(0)      NOT NULL,
    S2_START_LOT                NUMBER(6)        DEFAULT(0)      NOT NULL,
    S3_START_LOT                NUMBER(6)        DEFAULT(0)      NOT NULL,
    S4_START_LOT                NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* START QTY 1 ~ 3 */
    S1_START_QTY_1              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_START_QTY_1              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_START_QTY_1              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_START_QTY_1              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_START_QTY_2              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_START_QTY_2              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_START_QTY_2              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_START_QTY_2              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_START_QTY_3              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_START_QTY_3              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_START_QTY_3              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_START_QTY_3              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* START REWORK LOT */
    S1_START_RWK_LOT            NUMBER(6)        DEFAULT(0)      NOT NULL,
    S2_START_RWK_LOT            NUMBER(6)        DEFAULT(0)      NOT NULL,
    S3_START_RWK_LOT            NUMBER(6)        DEFAULT(0)      NOT NULL,
    S4_START_RWK_LOT            NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* START REWORK QTY 1 ~ 3 */
    S1_START_RWK_QTY_1          NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_START_RWK_QTY_1          NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_START_RWK_QTY_1          NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_START_RWK_QTY_1          NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_START_RWK_QTY_2          NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_START_RWK_QTY_2          NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_START_RWK_QTY_2          NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_START_RWK_QTY_2          NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_START_RWK_QTY_3          NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_START_RWK_QTY_3          NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_START_RWK_QTY_3          NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_START_RWK_QTY_3          NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* END LOT */
    S1_END_LOT                  NUMBER(6)        DEFAULT(0)      NOT NULL,
    S2_END_LOT                  NUMBER(6)        DEFAULT(0)      NOT NULL,
    S3_END_LOT                  NUMBER(6)        DEFAULT(0)      NOT NULL,
    S4_END_LOT                  NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* END QTY 1 ~ 3 */
    S1_END_QTY_1                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_END_QTY_1                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_END_QTY_1                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_END_QTY_1                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_END_QTY_2                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_END_QTY_2                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_END_QTY_2                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_END_QTY_2                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_END_QTY_3                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_END_QTY_3                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_END_QTY_3                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_END_QTY_3                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* END REWORK LOT */
    S1_END_RWK_LOT              NUMBER(6)        DEFAULT(0)      NOT NULL,
    S2_END_RWK_LOT              NUMBER(6)        DEFAULT(0)      NOT NULL,
    S3_END_RWK_LOT              NUMBER(6)        DEFAULT(0)      NOT NULL,
    S4_END_RWK_LOT              NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* END REWORK QTY 1 ~ 3 */
    S1_END_RWK_QTY_1            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_END_RWK_QTY_1            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_END_RWK_QTY_1            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_END_RWK_QTY_1            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_END_RWK_QTY_2            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_END_RWK_QTY_2            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_END_RWK_QTY_2            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_END_RWK_QTY_2            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_END_RWK_QTY_3            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_END_RWK_QTY_3            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_END_RWK_QTY_3            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_END_RWK_QTY_3           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* MOVE LOT */
    S1_MOVE_LOT                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    S2_MOVE_LOT                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    S3_MOVE_LOT                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    S4_MOVE_LOT                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* MOVE QTY 1 ~ 3 */
    S1_MOVE_QTY_1               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_MOVE_QTY_1               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_MOVE_QTY_1               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_MOVE_QTY_1               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_MOVE_QTY_2               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_MOVE_QTY_2               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_MOVE_QTY_2               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_MOVE_QTY_2               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_MOVE_QTY_3               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_MOVE_QTY_3               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_MOVE_QTY_3               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_MOVE_QTY_3               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* MOVE REWORK LOT */
    S1_MOVE_RWK_LOT             NUMBER(6)        DEFAULT(0)      NOT NULL,
    S2_MOVE_RWK_LOT             NUMBER(6)        DEFAULT(0)      NOT NULL,
    S3_MOVE_RWK_LOT             NUMBER(6)        DEFAULT(0)      NOT NULL,
    S4_MOVE_RWK_LOT             NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* MOVE REWORK QTY 1 ~ 3 */
    S1_MOVE_RWK_QTY_1           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_MOVE_RWK_QTY_1           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_MOVE_RWK_QTY_1           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_MOVE_RWK_QTY_1           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_MOVE_RWK_QTY_2           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_MOVE_RWK_QTY_2           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_MOVE_RWK_QTY_2           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_MOVE_RWK_QTY_2           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_MOVE_RWK_QTY_3           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_MOVE_RWK_QTY_3           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_MOVE_RWK_QTY_3           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_MOVE_RWK_QTY_3           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* TO REWORK LOT */
    S1_TO_RWK_LOT               NUMBER(6)        DEFAULT(0)      NOT NULL,
    S2_TO_RWK_LOT               NUMBER(6)        DEFAULT(0)      NOT NULL,
    S3_TO_RWK_LOT               NUMBER(6)        DEFAULT(0)      NOT NULL,
    S4_TO_RWK_LOT               NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* TO REWORK QTY 1 ~ 3 */
    S1_TO_RWK_QTY_1             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_TO_RWK_QTY_1             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_TO_RWK_QTY_1             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_TO_RWK_QTY_1             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_TO_RWK_QTY_2             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_TO_RWK_QTY_2             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_TO_RWK_QTY_2             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_TO_RWK_QTY_2             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_TO_RWK_QTY_3             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_TO_RWK_QTY_3             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_TO_RWK_QTY_3             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_TO_RWK_QTY_3             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* TO HOLD LOT */
    S1_TO_HOLD_LOT              NUMBER(6)        DEFAULT(0)      NOT NULL,
    S2_TO_HOLD_LOT              NUMBER(6)        DEFAULT(0)      NOT NULL,
    S3_TO_HOLD_LOT              NUMBER(6)        DEFAULT(0)      NOT NULL,
    S4_TO_HOLD_LOT              NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* TO HOLD QTY 1 ~ 3 */
    S1_TO_HOLD_QTY_1            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_TO_HOLD_QTY_1            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_TO_HOLD_QTY_1            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_TO_HOLD_QTY_1            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_TO_HOLD_QTY_2            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_TO_HOLD_QTY_2            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_TO_HOLD_QTY_2            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_TO_HOLD_QTY_2            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_TO_HOLD_QTY_3            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_TO_HOLD_QTY_3            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_TO_HOLD_QTY_3            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_TO_HOLD_QTY_3            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* LOSS QTY 1 ~ 3 */                        
    S1_LOSS_QTY_1               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_LOSS_QTY_1               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_LOSS_QTY_1               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_LOSS_QTY_1               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_LOSS_QTY_2               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_LOSS_QTY_2               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_LOSS_QTY_2               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_LOSS_QTY_2               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_LOSS_QTY_3               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_LOSS_QTY_3               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_LOSS_QTY_3               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_LOSS_QTY_3               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* LOSS REWORK QTY 1 ~ 3 */                        
    S1_LOSS_RWK_QTY_1           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_LOSS_RWK_QTY_1           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_LOSS_RWK_QTY_1           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_LOSS_RWK_QTY_1           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_LOSS_RWK_QTY_2           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_LOSS_RWK_QTY_2           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_LOSS_RWK_QTY_2           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_LOSS_RWK_QTY_2           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_LOSS_RWK_QTY_3           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_LOSS_RWK_QTY_3           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_LOSS_RWK_QTY_3           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_LOSS_RWK_QTY_3           NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* BONUS QTY 1 ~ 3 */                       
    S1_BONUS_QTY_1              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_BONUS_QTY_1              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_BONUS_QTY_1              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_BONUS_QTY_1              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_BONUS_QTY_2              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_BONUS_QTY_2              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_BONUS_QTY_2              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_BONUS_QTY_2              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_BONUS_QTY_3              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_BONUS_QTY_3              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_BONUS_QTY_3              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_BONUS_QTY_3              NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* CV QTY 1 ~ 3 */        
    S1_CV_QTY_1                 NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_CV_QTY_1                 NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_CV_QTY_1                 NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_CV_QTY_1                 NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_CV_QTY_2                 NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_CV_QTY_2                 NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_CV_QTY_2                 NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_CV_QTY_2                 NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_CV_QTY_3                 NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_CV_QTY_3                 NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_CV_QTY_3                 NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_CV_QTY_3                 NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* CHANGE QTY 1 ~ 3 - Adopted Qty */        
    S1_CHG_QTY_1                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_CHG_QTY_1                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_CHG_QTY_1                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_CHG_QTY_1                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_CHG_QTY_2                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_CHG_QTY_2                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_CHG_QTY_2                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_CHG_QTY_2                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_CHG_QTY_3                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_CHG_QTY_3                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_CHG_QTY_3                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_CHG_QTY_3                NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* QUEUE TIME(단위는 초) */
    S1_QUEUE_TIME               NUMBER(15)       DEFAULT(0)      NOT NULL,
    S2_QUEUE_TIME               NUMBER(15)       DEFAULT(0)      NOT NULL,
    S3_QUEUE_TIME               NUMBER(15)       DEFAULT(0)      NOT NULL,
    S4_QUEUE_TIME               NUMBER(15)       DEFAULT(0)      NOT NULL,
    /* HOLD TIME(단위는 초) */
    S1_HOLD_TIME                NUMBER(15)       DEFAULT(0)      NOT NULL,
    S2_HOLD_TIME                NUMBER(15)       DEFAULT(0)      NOT NULL,
    S3_HOLD_TIME                NUMBER(15)       DEFAULT(0)      NOT NULL,
    S4_HOLD_TIME                NUMBER(15)       DEFAULT(0)      NOT NULL,
    /* PROC TIME(단위는 초) */
    S1_PROC_TIME                NUMBER(15)       DEFAULT(0)      NOT NULL,
    S2_PROC_TIME                NUMBER(15)       DEFAULT(0)      NOT NULL,
    S3_PROC_TIME                NUMBER(15)       DEFAULT(0)      NOT NULL,
    S4_PROC_TIME                NUMBER(15)       DEFAULT(0)      NOT NULL,
    /* PULL TIME(단위는 초) */
    S1_PULL_TIME                NUMBER(15)       DEFAULT(0)      NOT NULL,
    S2_PUll_TIME                NUMBER(15)       DEFAULT(0)      NOT NULL,
    S3_PULL_TIME                NUMBER(15)       DEFAULT(0)      NOT NULL,
    S4_PULL_TIME                NUMBER(15)       DEFAULT(0)      NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RSUMWIPMOV
ADD CONSTRAINT RSUMWIPMOV_PK PRIMARY KEY
(
    WORK_DATE,
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    FLOW_SEQ_NUM,
    OPER,
    LOT_TYPE,
    ORDER_ID,
    CM_KEY_1,
    CM_KEY_2,
    CM_KEY_3,
    CM_KEY_4,
    CM_KEY_5
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* WIP Movement Group by Resource Summary Table */
CREATE TABLE RSUMRESMOV
(
    /* Work Date - YYYYMMDD */
    WORK_DATE                   CHAR(8)          DEFAULT(' ')    NOT NULL,
    /* Factory */
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Resource ID */
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 SEQ_NUM -> FLOW_SEQ_NUM */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Lot Type - 'P':Production, 'T':Test, 'E':Engineer, 'D':Dummy, 'M':Monitoring */
    LOT_TYPE                    CHAR(1)          DEFAULT('P')    NOT NULL,
    /* For additional Key 1 ~ 5 */
    CM_KEY_1                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_2                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_3                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_4                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_5                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Work Month - YYYY01 ~ YYYY12 */
    WORK_MONTH                  CHAR(6)          DEFAULT(' ')    NOT NULL,
    /* Work Week - YYYYWW */
    WORK_WEEK                   CHAR(6)          DEFAULT(' ')    NOT NULL,
    /* Work Week - 001 ~ 365 */
    WORK_DAYS                   CHAR(3)          DEFAULT(' ')    NOT NULL,
    /* 요일(Day of the week) - 0:일요일 1:월요일 ~ 6:금요일 */
    WORK_DAY_OF_WEEK            CHAR(1)          DEFAULT(' ')    NOT NULL,
    /** Start/End Data **/
    /* START LOT */
    START_LOT                   NUMBER(6)        DEFAULT(0)      NOT NULL,
    START_QTY_1                 NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    START_QTY_2                 NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    START_QTY_3                 NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* START REWORK LOT - 예비 필드 */          
    START_RWK_LOT               NUMBER(6)        DEFAULT(0)      NOT NULL,
    START_RWK_QTY_1             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    START_RWK_QTY_2             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    START_RWK_QTY_3             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* END LOT */                               
    END_LOT                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    END_QTY_1                   NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    END_QTY_2                   NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    END_QTY_3                   NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* END REWORK LOT - 예비 필드 */            
    END_RWK_LOT                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    END_RWK_QTY_1               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    END_RWK_QTY_2               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    END_RWK_QTY_3               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RSUMRESMOV
ADD CONSTRAINT RSUMRESMOV_PK PRIMARY KEY
(
    WORK_DATE,
    FACTORY,
    RES_ID,
    MAT_ID,
    MAT_VER,
    FLOW,
    FLOW_SEQ_NUM,
    OPER,
    LOT_TYPE,
    CM_KEY_1,
    CM_KEY_2,
    CM_KEY_3,
    CM_KEY_4,
    CM_KEY_5
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* Factory In, Out Summary Table */
CREATE TABLE RSUMFACMOV
(
    /* Work Date - YYYYMMDD */                 
    WORK_DATE                   CHAR(8)          DEFAULT(' ')    NOT NULL,
    /* Factory */
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 SEQ_NUM -> FLOW_SEQ_NUM */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Lot Type - 'P':Production, 'T':Test, 'E':Engineer, 'D':Dummy, 'M':Monitoring */
    LOT_TYPE                    CHAR(1)          DEFAULT('P')    NOT NULL,
    ORDER_ID                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* For additional Key 1 ~ 5 */
    CM_KEY_1                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_2                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_3                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_4                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_5                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Work Month - YYYY01 ~ YYYY12 */         
    WORK_MONTH                  CHAR(6)          DEFAULT(' ')    NOT NULL,
    /* Work Week - YYYYWW */                   
    WORK_WEEK                   CHAR(6)          DEFAULT(' ')    NOT NULL,
    /* Work Week - 001 ~ 365 */                
    WORK_DAYS                   CHAR(3)          DEFAULT(' ')    NOT NULL,
    /* 요일(Day of the week) - 0:일요일 1:월요일 ~ 6:금요일 */
    WORK_DAY_OF_WEEK            CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* FAC IN LOT */
    S1_FAC_IN_LOT               NUMBER(6)        DEFAULT(0)      NOT NULL,
    S2_FAC_IN_LOT               NUMBER(6)        DEFAULT(0)      NOT NULL,
    S3_FAC_IN_LOT               NUMBER(6)        DEFAULT(0)      NOT NULL,
    S4_FAC_IN_LOT               NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* FAC IN QTY 1 ~ 3 */
    S1_FAC_IN_QTY_1             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_FAC_IN_QTY_1             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_FAC_IN_QTY_1             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_FAC_IN_QTY_1             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_FAC_IN_QTY_2             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_FAC_IN_QTY_2             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_FAC_IN_QTY_2             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_FAC_IN_QTY_2             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_FAC_IN_QTY_3             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_FAC_IN_QTY_3             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_FAC_IN_QTY_3             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_FAC_IN_QTY_3             NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* FAC OUT LOT */
    S1_FAC_OUT_LOT              NUMBER(6)        DEFAULT(0)      NOT NULL,
    S2_FAC_OUT_LOT              NUMBER(6)        DEFAULT(0)      NOT NULL,
    S3_FAC_OUT_LOT              NUMBER(6)        DEFAULT(0)      NOT NULL,
    S4_FAC_OUT_LOT              NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* FAC OUT QTY 1 ~ 3 */
    S1_FAC_OUT_QTY_1            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_FAC_OUT_QTY_1            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_FAC_OUT_QTY_1            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_FAC_OUT_QTY_1            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_FAC_OUT_QTY_2            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_FAC_OUT_QTY_2            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_FAC_OUT_QTY_2            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_FAC_OUT_QTY_2            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S1_FAC_OUT_QTY_3            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S2_FAC_OUT_QTY_3            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S3_FAC_OUT_QTY_3            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    S4_FAC_OUT_QTY_3            NUMBER(15,3)     DEFAULT(0.0)    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RSUMFACMOV
ADD CONSTRAINT RSUMFACMOV_PK PRIMARY KEY
(
    WORK_DATE,
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    FLOW_SEQ_NUM,
    OPER,
    LOT_TYPE,
    ORDER_ID,
    CM_KEY_1,
    CM_KEY_2,
    CM_KEY_3,
    CM_KEY_4,
    CM_KEY_5
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE TABLE RSUMFACLOT
(
  FACTORY        VARCHAR2(10 BYTE)  DEFAULT (' ')   NOT NULL,
  LOT_ID         VARCHAR2(25 BYTE)  DEFAULT (' ')   NOT NULL,
  MAT_ID         VARCHAR2(30 BYTE)  DEFAULT (' ')   NOT NULL,
  MAT_VER        NUMBER(6)          DEFAULT (0)     NOT NULL,
  LOT_TYPE       CHAR(1 BYTE)       DEFAULT ('P')   NOT NULL,
  ORDER_ID       VARCHAR2(25 BYTE)  DEFAULT (' ')   NOT NULL,
  CM_KEY_1       VARCHAR2(30 BYTE)  DEFAULT (' ')   NOT NULL,
  CM_KEY_2       VARCHAR2(30 BYTE)  DEFAULT (' ')   NOT NULL,
  CM_KEY_3       VARCHAR2(30 BYTE)  DEFAULT (' ')   NOT NULL,
  CM_KEY_4       VARCHAR2(30 BYTE)  DEFAULT (' ')   NOT NULL,
  CM_KEY_5       VARCHAR2(30 BYTE)  DEFAULT (' ')   NOT NULL,
  FAC_IN_TIME    VARCHAR2(14 BYTE)  DEFAULT (' ')   NOT NULL,
  FAC_IN_QTY_1   NUMBER(15,3)       DEFAULT (0.0)   NOT NULL,
  FAC_IN_QTY_2   NUMBER(15,3)       DEFAULT (0.0)   NOT NULL,
  FAC_OUT_TIME   VARCHAR2(14 BYTE)  DEFAULT (' ')   NOT NULL,  
  FAC_OUT_QTY_1  NUMBER(15,3)       DEFAULT (0.0)   NOT NULL,
  FAC_OUT_QTY_2  NUMBER(15,3)       DEFAULT (0.0)   NOT NULL,
  LOSS_QTY_1     NUMBER(15,3)       DEFAULT (0.0)   NOT NULL,
  LOSS_QTY_2     NUMBER(15,3)       DEFAULT (0.0)   NOT NULL,
  SPLIT_QTY_1    NUMBER(15,3)       DEFAULT (0.0)   NOT NULL,
  SPLIT_QTY_2    NUMBER(15,3)       DEFAULT (0.0)   NOT NULL,
  MERGE_QTY_1    NUMBER(15,3)       DEFAULT (0.0)   NOT NULL,
  MERGE_QTY_2    NUMBER(15,3)       DEFAULT (0.0)   NOT NULL,
  COMBINE_QTY_1  NUMBER(15,3)       DEFAULT (0.0)   NOT NULL,
  COMBINE_QTY_2  NUMBER(15,3)       DEFAULT (0.0)   NOT NULL,
  ADAPT_QTY_1    NUMBER(15,3)       DEFAULT (0.0)   NOT NULL,
  ADAPT_QTY_2    NUMBER(15,3)       DEFAULT (0.0)   NOT NULL,
  QUEUE_TIME     NUMBER(15)         DEFAULT (0.0)   NOT NULL,
  PROC_TIME      NUMBER(15)         DEFAULT (0.0)   NOT NULL,
  HOLD_TIME      NUMBER(15)         DEFAULT (0.0)   NOT NULL      
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RSUMFACLOT 
ADD CONSTRAINT RSUMFACLOT_PK PRIMARY KEY
(
    FACTORY, 
    LOT_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* WIP History Summary Table */
CREATE TABLE RSUMWIPLTH
(
    OPER_IN_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Factory */
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 SEQ_NUM -> FLOW_SEQ_NUM */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* 캐리어 ID */
    CRR_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    /* Lot Type - 'P':Production, 'T':Test, 'E':Engineer, 'D':Dummy, 'M':Monitoring */
    LOT_TYPE                    CHAR(1)          DEFAULT('P')    NOT NULL,
    /* LOT의 우선순위 - '0'-->'9' LOW-->HIGH, 기본값:'5' */
    LOT_PRIORITY                CHAR(1)          DEFAULT('5')    NOT NULL,
    /* Order Info. */
    ORDER_ID                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Oper In Quantity 1 ~ 3 */
    OPER_IN_QTY_1               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OPER_IN_QTY_2               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OPER_IN_QTY_3               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    START_TIME                  VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    START_RES_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    START_QTY_1                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    START_QTY_2                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    START_QTY_3                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    END_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    END_RES_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    END_QTY_1                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    END_QTY_2                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    END_QTY_3                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    MOVE_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    MOVE_QTY_1                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    MOVE_QTY_2                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    MOVE_QTY_3                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    LOSS_QTY_1                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    LOSS_QTY_2                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    LOSS_QTY_3                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    BONUS_QTY_1                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    BONUS_QTY_2                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    BONUS_QTY_3                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CV_QTY_1                    NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CV_QTY_2                    NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CV_QTY_3                    NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CHG_QTY_1                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CHG_QTY_2                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CHG_QTY_3                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    TO_RWK_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    TO_RWK_QTY_1                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    TO_RWK_QTY_2                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    TO_RWK_QTY_3                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    RWK_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOT_YIELD_1                 NUMBER(20,10)     DEFAULT(0.0)    NOT NULL,
    LOT_YIELD_2                 NUMBER(20,10)     DEFAULT(0.0)    NOT NULL,
    LOT_YIELD_3                 NUMBER(20,10)     DEFAULT(0.0)    NOT NULL,
    QUEUE_TIME                  NUMBER(15,0)     DEFAULT(0.0)    NOT NULL,
    PULL_TIME                   NUMBER(15,0)     DEFAULT(0.0)    NOT NULL,
    HOLD_TIME                   NUMBER(15,0)     DEFAULT(0.0)    NOT NULL,
    PROC_TIME                   NUMBER(15,0)     DEFAULT(0.0)    NOT NULL,
    CUM_QUEUE_TIME              NUMBER(15,0)     DEFAULT(0.0)    NOT NULL,
    CUM_PULL_TIME               NUMBER(15,0)     DEFAULT(0.0)    NOT NULL,
    CUM_HOLD_TIME               NUMBER(15,0)     DEFAULT(0.0)    NOT NULL,
    CUM_PROC_TIME               NUMBER(15,0)     DEFAULT(0.0)    NOT NULL,
    /* For additional Field 1 ~ 5 */
    CM_FIELD_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_FIELD_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_FIELD_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_FIELD_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_FIELD_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RSUMWIPLTH
ADD CONSTRAINT RSUMWIPLTH_PK PRIMARY KEY
(
    OPER_IN_TIME,
    LOT_ID,
    OPER
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* WIP Status Summary Table */
CREATE OR REPLACE VIEW RSUMWIPSTS
(FACTORY, MAT_ID, MAT_VER, FLOW, FLOW_SEQ_NUM, 
 OPER, LOT_TYPE, ORDER_ID, RES_ID, CM_KEY_1, 
 CM_KEY_2, CM_KEY_3, CM_KEY_4, CM_KEY_5, TOT_LOT, 
 TOT_QTY_1, TOT_QTY_2, START_LOT, START_QTY_1, START_QTY_2, 
 END_LOT, END_QTY_1, END_QTY_2, HOLD_LOT, HOLD_QTY_1, 
 HOLD_QTY_2, RWK_LOT, RWK_QTY_1, RWK_QTY_2)
AS 
SELECT
FACTORY      ,MAT_ID       ,MAT_VER      ,FLOW         ,FLOW_SEQ_NUM ,OPER         ,LOT_TYPE     ,ORDER_ID     ,START_RES_ID  AS RES_ID,
' ' AS CM_KEY_1     ,
' ' AS CM_KEY_2     ,
' ' AS CM_KEY_3     ,
' ' AS CM_KEY_4     ,
' ' AS CM_KEY_5     ,
SUM(1) AS TOT_LOT      ,
SUM(QTY_1) AS TOT_QTY_1    ,
SUM(QTY_2) AS TOT_QTY_2    ,
SUM(DECODE(START_FLAG,'Y', 1    ,0)) AS START_LOT    ,
SUM(DECODE(START_FLAG,'Y', QTY_1,0)) AS START_QTY_1  ,
SUM(DECODE(START_FLAG,'Y', QTY_2,0)) AS START_QTY_2  ,
SUM(DECODE(END_FLAG,'Y', 1    ,0))END_LOT      ,
SUM(DECODE(END_FLAG,'Y', QTY_1,0))END_QTY_1    ,
SUM(DECODE(END_FLAG,'Y', QTY_2,0))END_QTY_2    ,
SUM(DECODE(HOLD_FLAG,'Y', 1    ,0))HOLD_LOT     ,
SUM(DECODE(HOLD_FLAG,'Y', QTY_1,0))HOLD_QTY_1   ,
SUM(DECODE(HOLD_FLAG,'Y', QTY_2,0))HOLD_QTY_2   ,
SUM(DECODE(RWK_FLAG,'Y', 1    ,0))RWK_LOT      ,
SUM(DECODE(RWK_FLAG,'Y', QTY_1,0))RWK_QTY_1    ,
SUM(DECODE(RWK_FLAG,'Y', QTY_2,0))RWK_QTY_2  
FROM MWIPLOTSTS
WHERE LOT_DEL_FLAG=' '  
GROUP BY FACTORY      ,MAT_ID       ,MAT_VER      ,FLOW         ,FLOW_SEQ_NUM ,OPER         ,LOT_TYPE     ,ORDER_ID     ,START_RES_ID;


/* RSUMRESTMH : Resource Time History Table */
CREATE TABLE RSUMRESTMH
(
    /* Transaction Time - Backdated 가능 */
    WORK_DATE                   VARCHAR2(8)      DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Resource Availibility - U:Up, D:Down */ 
    RES_UP_DOWN_FLAG            CHAR(1)          DEFAULT('U')    NOT NULL,
    /* Resource Primary Status - WAIT:Wait, PROC:Process, PM ... */
    RES_PRI_STS                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Time Summary(단위 : 초) */
    TIME_SUM                    NUMBER(15)        DEFAULT(0)      NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RSUMRESTMH
ADD CONSTRAINT RSUMRESTMH_PK PRIMARY KEY
(
    WORK_DATE,
    FACTORY,
    RES_ID,
    RES_UP_DOWN_FLAG,
    RES_PRI_STS
) USING INDEX TABLESPACE REPORT_IDX_TS;


/*==== Interface System ====*/
/* ISUMWIPMOV : ERP Interface WIP Movement Summary Table */
CREATE TABLE ISUMWIPMOV
(
    /* Work Date - YYYYMMDD */
    WORK_DATE                   CHAR(8)          DEFAULT(' ')    NOT NULL,
    /* Factory */
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 SEQ_NUM -> FLOW_SEQ_NUM */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Lot Type - 'P':Production, 'T':Test, 'E':Engineer, 'D':Dummy, 'M':Monitoring */
    LOT_TYPE                    CHAR(1)          DEFAULT('P')    NOT NULL,
    /** IN/OUT Data **/
    /* END LOT */
    END_LOT                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* END QTY 1 ~ 2 */
    END_QTY_1                   NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    END_QTY_2                   NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* END REWORK LOT */
    END_RWK_LOT                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* END REWORK QTY 1 ~ 2 */
    END_RWK_QTY_1               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    END_RWK_QTY_2               NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* LOSS QTY 1 ~ 2 */
    LOSS_QTY_1                  NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    LOSS_QTY_2                  NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    /* BONUS QTY 1 ~ 2 */
    BONUS_QTY_1                 NUMBER(15,3)     DEFAULT(0.0)    NOT NULL,
    BONUS_QTY_2                 NUMBER(15,3)     DEFAULT(0.0)    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE ISUMWIPMOV
ADD CONSTRAINT ISUMWIPMOV_PK PRIMARY KEY
(
    WORK_DATE,
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    FLOW_SEQ_NUM,
    OPER,
    LOT_TYPE
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* IWIPORDSTS : ERP Interface Order Status Table */
CREATE TABLE IWIPORDSTS 
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /** Order Info. **/
    ORDER_ID                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    /* Flow */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    /* Order Qty */
    ORD_QTY                     NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Resource ID */
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* WIP <--> BOM */
    BOM_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    BOM_SET_VERSION             NUMBER(3)        DEFAULT(0)      NOT NULL,
    /* Customer ID, Customer Material ID */
    CUSTOMER_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CUSTOMER_MAT_ID             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Work Date - YYYYMMDD */
    WORK_DATE                   CHAR(8)          DEFAULT(' ')    NOT NULL,
    /* Time Info. */
    PLAN_DUE_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    PLAN_START_TIME             VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    PLAN_END_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* CMF 1 ~ 10 */
    ORD_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ORD_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ORD_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ORD_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ORD_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ORD_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ORD_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ORD_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ORD_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ORD_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ORD_CMF_11                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    ORD_CMF_12                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    ORD_CMF_13                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    ORD_CMF_14                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    ORD_CMF_15                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    ORD_CMF_16                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    ORD_CMF_17                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    ORD_CMF_18                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    ORD_CMF_19                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    ORD_CMF_20                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    /* Quantity 1 ~ 3 */
    QTY                         NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Lot Type - 'P':Production, 'T':Test, 'E':Engineer, 'D':Dummy, 'M':Monitoring */
    LOT_TYPE                    CHAR(1)          DEFAULT('P')    NOT NULL,
    /* Owner Code, Create Code */
    OWNER_CODE                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CREATE_CODE                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* LOT의 우선순위 - '0'-->'9' LOW-->HIGH, 기본값:'5' */ 
    LOT_PRIORITY                CHAR(1)          DEFAULT('5')    NOT NULL,
    /* Due Time(Original, Scheduled) */
    ORG_DUE_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /** Order Status **/
    /* Order Status - O:Open, C:Close, D:Delete or Cancel, F:Finish */
    ORD_STATUS_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Order Ship Flag - Y: */
    ORD_SHIP_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    ORD_START_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    ORD_END_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    ORD_IN_QTY                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    ORD_OUT_QTY                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    ORD_LOSS_QTY                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    ORD_RWK_QTY                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE IWIPORDSTS 
ADD CONSTRAINT IWIPORDSTS_PK PRIMARY KEY
(
    FACTORY,
    ORDER_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* IWIPPLNDEF : ERP Interface WIP Production Plan Table */
CREATE TABLE IWIPPLNDEF
(
    /* Work Date - YYYYMMDD */
    WORK_DATE                   CHAR(8)          DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    /* Resource ID */
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* PLAN Qty */
    PLAN_QTY                    NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /** Create Info. **/
    /* Quantity */
    QTY                         NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Lot Type - 'P':Production, 'T':Test, 'E':Engineer, 'D':Dummy, 'M':Monitoring */
    LOT_TYPE                    CHAR(1)          DEFAULT('P')    NOT NULL,
    /* Owner Code, Create Code */
    OWNER_CODE                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CREATE_CODE                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* LOT의 우선순위 - '0'-->'9' LOW-->HIGH, 기본값:'5' */ 
    LOT_PRIORITY                CHAR(1)          DEFAULT('5')    NOT NULL,
    /* Due Time(Original, Scheduled) */
    ORG_DUE_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /** Plan Status **/
    CREATE_LOT_COUNT            NUMBER(6)        DEFAULT(0)      NOT NULL,
    CREATE_QTY                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE IWIPPLNDEF 
ADD CONSTRAINT IWIPPLNDEF_PK PRIMARY KEY
(
    WORK_DATE,
    FACTORY,
    MAT_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;


/*==== WEB(Web Security Tables) ====*/
/* RWEBGRPDEF : Security Group Definition Table */
CREATE TABLE RWEBGRPDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SEC_GRP_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SEC_GRP_DESC                VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWEBGRPDEF
ADD CONSTRAINT RWEBGRPDEF_PK PRIMARY KEY
(
    FACTORY,
    SEC_GRP_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* RWEBUSRDEF : User Definition Table */
CREATE TABLE RWEBUSRDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_DESC                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* Password */
    PASSWORD                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Change Password Enable Flag - 'Y':Enable, ' ':Disable */
    CHG_PASS_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* GRP 1 ~ 10 */
    USER_GRP_1                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_GRP_2                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_GRP_3                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_GRP_4                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_GRP_5                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_GRP_6                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_GRP_7                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_GRP_8                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_GRP_9                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_GRP_10                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* CMF 1 ~ 10 */
    USER_CMF_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    USER_CMF_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    USER_CMF_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    USER_CMF_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    USER_CMF_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    USER_CMF_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    USER_CMF_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    USER_CMF_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    USER_CMF_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    USER_CMF_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Security Group */
    SEC_GRP_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Phone */
    PHONE_OFFICE                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PHONE_MOBILE                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PHONE_HOME                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PHONE_OTHER                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* ENTER_DATE, RETIRE_DATE */
    ENTER_DATE                  VARCHAR2(8)      DEFAULT(' ')    NOT NULL,
    RETIRE_DATE                 VARCHAR2(8)      DEFAULT(' ')    NOT NULL,
    /* E-Mail ID */
    EMAIL_ID                    VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* 생일 */
    BIRTHDAY                    VARCHAR2(8)      DEFAULT(' ')    NOT NULL,
    /* SEX - 'M':Male(남자) NOT NULL, 'F':Female(여자) */
    SEX_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWEBUSRDEF
ADD CONSTRAINT RWEBUSRDEF_PK PRIMARY KEY
(
    FACTORY,
    USER_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* RWEBFUNDEF : Function Group Definition Table */
CREATE TABLE RWEBFUNDEF
(
    FUNC_NAME                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    FUNC_DESC                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* Function Type - 'F':Client Function, 'P':Program, 'M':Menu */
    FUNC_TYPE_FLAG              CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* FLEXIBLE Type - 'F':FLEXIBLE Function, ' ':Default*/
    FUNC_FLEX_TYPE              CHAR(1)          DEFAULT(' ')    NOT NULL,
    FUNC_URL                    VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    /* Help URL */
    /* Help Web Site는 GCM Table에 정의 */
    HELP_URL                    VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWEBFUNDEF
ADD CONSTRAINT RWEBFUNDEF_PK PRIMARY KEY
(
    FUNC_NAME
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* RWEBGRPDEF : Security Group Definition Table */
CREATE TABLE RWEBGRPFUN
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SEC_GRP_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FUNC_GRP_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FUNC_GRP_SEQ                NUMBER(6)        DEFAULT(0)      NOT NULL,
    FUNC_NAME                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    FUNC_SEQ                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWEBGRPFUN
ADD CONSTRAINT RWEBGRPFUN_PK PRIMARY KEY
(
    FACTORY,
    SEC_GRP_ID,
    FUNC_GRP_ID,
    FUNC_NAME
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* RWEBUSRREG : User Registration data Table */
CREATE TABLE RWEBUSRREG
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FUNC_NAME                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    CTL_NAME_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CTL_NAME_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CTL_NAME_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CTL_NAME_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CTL_NAME_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CTL_NAME_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CTL_NAME_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CTL_NAME_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CTL_NAME_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CTL_NAME_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CTL_NAME_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CTL_NAME_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CTL_NAME_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CTL_NAME_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CTL_NAME_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CTL_NAME_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CTL_NAME_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CTL_NAME_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CTL_NAME_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CTL_NAME_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CTL_VALUE_1                 VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CTL_VALUE_2                 VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CTL_VALUE_3                 VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CTL_VALUE_4                 VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CTL_VALUE_5                 VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CTL_VALUE_6                 VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CTL_VALUE_7                 VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CTL_VALUE_8                 VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CTL_VALUE_9                 VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CTL_VALUE_10                VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CTL_VALUE_11                VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CTL_VALUE_12                VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CTL_VALUE_13                VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CTL_VALUE_14                VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CTL_VALUE_15                VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CTL_VALUE_16                VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CTL_VALUE_17                VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CTL_VALUE_18                VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CTL_VALUE_19                VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    CTL_VALUE_20                VARCHAR2(50)     DEFAULT(' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWEBUSRREG
ADD CONSTRAINT RWEBUSRREG_PK PRIMARY KEY
(
    FACTORY,
    USER_ID,
    FUNC_NAME
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* RWEBCLIREG : User Registration Option data Table */
CREATE TABLE RWEBCLIREG
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    ITEM_NAME                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    IP                          VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWEBCLIREG
ADD CONSTRAINT RWEBCLIREG_PK PRIMARY KEY
(
    FACTORY,
    USER_ID,
    ITEM_NAME
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* RWEBFUNCOL : Define Function Column */
CREATE TABLE RWEBFUNCOL
(
    FUNC_NAME                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    TBL_NAME                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    COL_SEQ                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    COL_NAME                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COL_HEAD                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HEAD_DESC                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* COL TYPE - 'M':Mandatory, 'S':Standard , 'O':Option */
    COL_TYPE                    CHAR(1)          DEFAULT('O')    NOT NULL,
    COL_SIZE                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* SIZE UNIT - ' ':Pixel, '%': Percent */
    COL_UNIT                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWEBFUNCOL
ADD CONSTRAINT RWEBFUNCOL_PK PRIMARY KEY
(
    FUNC_NAME,
    TBL_NAME,
    COL_SEQ,
    COL_NAME
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* RWEBUSRCOL : Define User Function Column*/
CREATE TABLE RWEBUSRCOL
(   
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Security Group ID or User ID */
    USER_ITEM                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* USER FLAG - 'G':Security Group, 'U': User */
    USER_FLAG                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    FUNC_NAME                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    TBL_NAME                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    COL_SEQ                     NUMBER(10)       DEFAULT(0)      NOT NULL,
    COL_NAME                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COL_HEAD                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HEAD_DESC                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* COL TYPE - 'M':Mandatory, 'S':Standard , 'O':Option */
    COL_TYPE                    CHAR(1)          DEFAULT('O')    NOT NULL,
    COL_SIZE                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* SIZE UNIT - ' ':Pixel, '%': Percent */
    COL_UNIT                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWEBUSRCOL
ADD CONSTRAINT RWEBUSRCOL_PK PRIMARY KEY
(
    FACTORY,
    USER_ITEM,
    FUNC_NAME,
    TBL_NAME,
    COL_SEQ,
    COL_NAME
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* RWEBUSRLOG : User LOG Table */
CREATE TABLE RWEBUSRLOG
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FUNC_NAME                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /* Start Time, End Time - YYYYMMDDHHMMSSmmm */
    START_TIME                  VARCHAR2(17)     DEFAULT(' ')    NOT NULL,
    END_TIME                    VARCHAR2(17)     DEFAULT(' ')    NOT NULL,
    /* Time Interval : 소수점 이하는 Millisecond */
    TIME_INTERVAL               NUMBER(12,4)     DEFAULT(0.0)    NOT NULL,
    UPDATE_TIME                 VARCHAR2(17)     DEFAULT(' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWEBUSRLOG
ADD CONSTRAINT RWEBUSRLOG_PK PRIMARY KEY
(
    FACTORY,
    USER_ID,
    FUNC_NAME,
    UPDATE_TIME
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* RWEBFUNITM : View Group Item Table */
CREATE TABLE RWEBFUNITM
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Report Function Name */
    FUNC_NAME                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /* Oper, Oper Group, Etc */
    ITEM_TYPE                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* View Seq */
    ITEM_SEQ                    NUMBER(3)        DEFAULT( 0 )    NOT NULL,
    ITEM_NAME                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_DESC                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWEBFUNITM
ADD CONSTRAINT RWEBFUNITM_PK PRIMARY KEY
(
    FACTORY,
    FUNC_NAME,
    ITEM_TYPE,
    ITEM_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* RSUMUSRLOG : User LOG Summary Table */
CREATE TABLE RSUMUSRLOG
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FUNC_NAME                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /* Tran Date - YYYYMMDD */
    TRAN_DATE                   VARCHAR2(8)      DEFAULT(' ')    NOT NULL,
    /* ACCESS_COUNT - 일별 누적 */
    ACCESS_COUNT                NUMBER(12)       DEFAULT(0)      NOT NULL,
     /* Time Interval : 소수점 이하는 Millisecond */
    TIME_INTERVAL               NUMBER(12,4)     DEFAULT(0.0)    NOT NULL,
     /* UPDATE TIME */
    UPDATE_TIME                 VARCHAR2(17)     DEFAULT(' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RSUMUSRLOG
ADD CONSTRAINT RSUMUSRLOG_PK PRIMARY KEY
(
    FACTORY,
    USER_ID,
    FUNC_NAME,
    TRAN_DATE
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE TABLE RSUMPRCLOG
(
  FACTORY         VARCHAR2(10)             DEFAULT (' ')                 NOT NULL,
  FUNCTION_NAME   VARCHAR2(100)            DEFAULT (' ')                 NOT NULL,
  WORK_DATE       CHAR(8)                  DEFAULT (' ')                 NOT NULL,
  WORK_SHIFT      CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  LAST_TRAN_TIME  VARCHAR2(14)             DEFAULT (' ')                 NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RSUMPRCLOG
ADD CONSTRAINT RSUMPRCLOG_PK PRIMARY KEY
(
    FACTORY, 
    FUNCTION_NAME
) USING INDEX TABLESPACE REPORT_IDX_TS;


CREATE TABLE RSUMFUNLOG
(
  FUNC_NAME      VARCHAR2(12 BYTE)              DEFAULT (' ')                 NOT NULL,
  TRAN_DATE      VARCHAR2(8 BYTE)               DEFAULT (' ')                 NOT NULL,
  TRAN_HOUR      VARCHAR2(2 BYTE)               DEFAULT (' ')                 NOT NULL,
  ACCESS_COUNT   NUMBER(12)                     DEFAULT (0)                   NOT NULL,
  TIME_INTERVAL  NUMBER(12,4)                   DEFAULT (0.0)                 NOT NULL,
  UPDATE_TIME    VARCHAR2(17 BYTE)              DEFAULT (' ')                 NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RSUMFUNLOG 
ADD CONSTRAINT RSUMFUNLOG_PK PRIMARY KEY
(
 FUNC_NAME, 
 TRAN_DATE, 
 TRAN_HOUR, 
 UPDATE_TIME
) USING INDEX TABLESPACE REPORT_IDX_TS;



/* RWEBUSRFUN : */
CREATE TABLE RWEBUSRFUN
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FUNC_NAME                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    COL_NAME                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWEBUSRFUN
ADD CONSTRAINT RWEBUSRFUN_PK PRIMARY KEY
(
    FACTORY,
    USER_ID,
    FUNC_NAME
) USING INDEX TABLESPACE REPORT_IDX_TS;

/* RWIPLOTHIS : MWIPLOTHIS Table Replication in WIPLoader */
CREATE TABLE RWIPLOTHIS 
(
  LOT_ID                 VARCHAR2(25 BYTE)      DEFAULT (' ')                 NOT NULL,
  HIST_SEQ               NUMBER(10)             DEFAULT (0)                   NOT NULL,
  TRAN_TIME              DATE,
  SYS_TRAN_TIME          DATE,
  TRAN_CODE              VARCHAR2(12 BYTE),
  LOT_DESC               VARCHAR2(200 BYTE),
  FACTORY                VARCHAR2(10 BYTE),
  MAT_ID                 VARCHAR2(30 BYTE),
  MAT_VER                NUMBER(6),
  FLOW                   VARCHAR2(20 BYTE),
  FLOW_SEQ_NUM           NUMBER(6),
  OPER                   VARCHAR2(10 BYTE),
  QTY_1                  NUMBER(10,3),
  QTY_2                  NUMBER(10,3),
  QTY_3                  NUMBER(10,3),
  UNIT_1                 VARCHAR2(10 BYTE),
  UNIT_2                 VARCHAR2(10 BYTE),
  UNIT_3                 VARCHAR2(10 BYTE),
  CRR_ID                 VARCHAR2(20 BYTE),
  LOT_TYPE               VARCHAR2(1 BYTE),
  OWNER_CODE             VARCHAR2(10 BYTE),
  CREATE_CODE            VARCHAR2(10 BYTE),
  LOT_PRIORITY           VARCHAR2(1 BYTE),
  LOT_STATUS             VARCHAR2(10 BYTE),
  HOLD_FLAG              VARCHAR2(1 BYTE),
  HOLD_CODE              VARCHAR2(10 BYTE),
  HOLD_PASSWORD          VARCHAR2(20 BYTE),
  HOLD_PRV_GRP_ID        VARCHAR2(20 BYTE),
  OPER_IN_QTY_1          NUMBER(10,3),
  OPER_IN_QTY_2          NUMBER(10,3),
  OPER_IN_QTY_3          NUMBER(10,3),
  CREATE_QTY_1           NUMBER(10,3),
  CREATE_QTY_2           NUMBER(10,3),
  CREATE_QTY_3           NUMBER(10,3),
  START_QTY_1            NUMBER(10,3),
  START_QTY_2            NUMBER(10,3),
  START_QTY_3            NUMBER(10,3),
  INV_FLAG               VARCHAR2(1 BYTE),
  TRANSIT_FLAG           VARCHAR2(1 BYTE),
  UNIT_EXIST_FLAG        VARCHAR2(1 BYTE),
  INV_UNIT               VARCHAR2(10 BYTE),
  RWK_FLAG               VARCHAR2(1 BYTE),
  RWK_CODE               VARCHAR2(10 BYTE),
  RWK_COUNT              NUMBER(6),
  RWK_RET_FLOW           VARCHAR2(20 BYTE),
  RWK_RET_FLOW_SEQ_NUM   NUMBER(6),
  RWK_RET_OPER           VARCHAR2(10 BYTE),
  RWK_END_FLOW           VARCHAR2(20 BYTE),
  RWK_END_FLOW_SEQ_NUM   NUMBER(6),
  RWK_END_OPER           VARCHAR2(10 BYTE),
  RWK_RET_CLEAR_FLAG     VARCHAR2(1 BYTE),
  RWK_TIME               DATE,
  NSTD_FLAG              VARCHAR2(1 BYTE),
  NSTD_RET_FLOW          VARCHAR2(20 BYTE),
  NSTD_RET_FLOW_SEQ_NUM  NUMBER(6),
  NSTD_RET_OPER          VARCHAR2(10 BYTE),
  NSTD_TIME              DATE,
  REP_FLAG               VARCHAR2(1 BYTE),
  REP_RET_OPER           VARCHAR2(10 BYTE),
  STR_RET_FLOW           VARCHAR2(20 BYTE),
  STR_RET_FLOW_SEQ_NUM   NUMBER(6),
  STR_RET_OPER           VARCHAR2(10 BYTE),
  START_FLAG             VARCHAR2(1 BYTE),
  START_TIME             DATE,
  START_RES_ID           VARCHAR2(20 BYTE),
  END_FLAG               VARCHAR2(1 BYTE),
  END_TIME               DATE,
  END_RES_ID             VARCHAR2(20 BYTE),
  SAMPLE_FLAG            VARCHAR2(1 BYTE),
  SAMPLE_WAIT_FLAG       VARCHAR2(1 BYTE),
  SAMPLE_RESULT          VARCHAR2(1 BYTE),
  FROM_TO_FLAG           VARCHAR2(1 BYTE),
  FROM_TO_LOT_ID         VARCHAR2(25 BYTE),
  SHIP_CODE              VARCHAR2(10 BYTE),
  SHIP_TIME              DATE,
  ORG_DUE_TIME           DATE,
  SCH_DUE_TIME           DATE,
  CREATE_TIME            DATE,
  FAC_IN_TIME            DATE,
  FLOW_IN_TIME           DATE,
  OPER_IN_TIME           DATE,
  RESERVE_RES_ID         VARCHAR2(20 BYTE),
  PORT_ID                VARCHAR2(10 BYTE),
  BATCH_ID               VARCHAR2(25 BYTE),
  BATCH_SEQ              NUMBER(3),
  ORDER_ID               VARCHAR2(25 BYTE),
  ADD_ORDER_ID_1         VARCHAR2(25 BYTE),
  ADD_ORDER_ID_2         VARCHAR2(25 BYTE),
  ADD_ORDER_ID_3         VARCHAR2(25 BYTE),
  LOT_LOCATION_1         VARCHAR2(20 BYTE),
  LOT_LOCATION_2         VARCHAR2(20 BYTE),
  LOT_LOCATION_3         VARCHAR2(20 BYTE),
  LOT_CMF_1              VARCHAR2(30 BYTE),
  LOT_CMF_2              VARCHAR2(30 BYTE),
  LOT_CMF_3              VARCHAR2(30 BYTE),
  LOT_CMF_4              VARCHAR2(30 BYTE),
  LOT_CMF_5              VARCHAR2(30 BYTE),
  LOT_CMF_6              VARCHAR2(30 BYTE),
  LOT_CMF_7              VARCHAR2(30 BYTE),
  LOT_CMF_8              VARCHAR2(30 BYTE),
  LOT_CMF_9              VARCHAR2(30 BYTE),
  LOT_CMF_10             VARCHAR2(30 BYTE),
  LOT_CMF_11             VARCHAR2(30 BYTE),
  LOT_CMF_12             VARCHAR2(30 BYTE),
  LOT_CMF_13             VARCHAR2(30 BYTE),
  LOT_CMF_14             VARCHAR2(30 BYTE),
  LOT_CMF_15             VARCHAR2(30 BYTE),
  LOT_CMF_16             VARCHAR2(30 BYTE),
  LOT_CMF_17             VARCHAR2(30 BYTE),
  LOT_CMF_18             VARCHAR2(30 BYTE),
  LOT_CMF_19             VARCHAR2(30 BYTE),
  LOT_CMF_20             VARCHAR2(30 BYTE),
  LOT_DEL_FLAG           VARCHAR2(1 BYTE),
  LOT_DEL_CODE           VARCHAR2(10 BYTE),
  LOT_DEL_TIME           DATE,
  BOM_SET_ID             VARCHAR2(25 BYTE),
  BOM_SET_VERSION        NUMBER(3),
  BOM_ACTIVE_HIST_SEQ    NUMBER(10),
  BOM_HIST_SEQ           NUMBER(10),
  CRITICAL_RES_ID        VARCHAR2(20 BYTE),
  CRITICAL_RES_GROUP_ID  VARCHAR2(20 BYTE),
  SAVE_RES_ID_1          VARCHAR2(20 BYTE),
  SAVE_RES_ID_2          VARCHAR2(20 BYTE),
  SUBRES_ID              VARCHAR2(20 BYTE),
  LOT_GROUP_ID_1         VARCHAR2(25 BYTE),
  LOT_GROUP_ID_2         VARCHAR2(25 BYTE),
  LOT_GROUP_ID_3         VARCHAR2(25 BYTE),
  YIELD_1                NUMBER(20,10),
  YIELD_2                NUMBER(20,10),
  YIELD_3                NUMBER(20,10),
  GOOD_QTY               NUMBER(10,3),
  RESV_FIELD_1           VARCHAR2(30 BYTE),
  RESV_FIELD_2           VARCHAR2(30 BYTE),
  RESV_FIELD_3           VARCHAR2(30 BYTE),
  RESV_FIELD_4           VARCHAR2(30 BYTE),
  RESV_FIELD_5           VARCHAR2(30 BYTE),
  RESV_FLAG_1            VARCHAR2(1 BYTE),
  RESV_FLAG_2            VARCHAR2(1 BYTE),
  RESV_FLAG_3            VARCHAR2(1 BYTE),
  RESV_FLAG_4            VARCHAR2(1 BYTE),
  RESV_FLAG_5            VARCHAR2(1 BYTE),
  FROM_TO_MAT_ID         VARCHAR2(30 BYTE),
  FROM_TO_MAT_VER        NUMBER(6),
  FROM_TO_FLOW           VARCHAR2(20 BYTE),
  FROM_TO_FLOW_SEQ_NUM   NUMBER(6),
  FROM_TO_OPER           VARCHAR2(10 BYTE),
  FROM_TO_QTY_1          NUMBER(10,3),
  FROM_TO_QTY_2          NUMBER(10,3),
  FROM_TO_QTY_3          NUMBER(10,3),
  FROM_TO_HIST_SEQ       NUMBER(10),
  OLD_FACTORY            VARCHAR2(10 BYTE),
  OLD_MAT_ID             VARCHAR2(30 BYTE),
  OLD_MAT_VER            NUMBER(6),
  OLD_FLOW               VARCHAR2(20 BYTE),
  OLD_FLOW_SEQ_NUM       NUMBER(6),
  OLD_OPER               VARCHAR2(10 BYTE),
  OLD_QTY_1              NUMBER(10,3),
  OLD_QTY_2              NUMBER(10,3),
  OLD_QTY_3              NUMBER(10,3),
  OLD_LOT_TYPE           VARCHAR2(1 BYTE),
  OLD_OWNER_CODE         VARCHAR2(10 BYTE),
  OLD_CREATE_CODE        VARCHAR2(10 BYTE),
  OLD_FAC_IN_TIME        DATE,
  OLD_FLOW_IN_TIME       DATE,
  OLD_OPER_IN_TIME       DATE,
  TRAN_CMF_1             VARCHAR2(30 BYTE),
  TRAN_CMF_2             VARCHAR2(30 BYTE),
  TRAN_CMF_3             VARCHAR2(30 BYTE),
  TRAN_CMF_4             VARCHAR2(30 BYTE),
  TRAN_CMF_5             VARCHAR2(30 BYTE),
  TRAN_CMF_6             VARCHAR2(30 BYTE),
  TRAN_CMF_7             VARCHAR2(30 BYTE),
  TRAN_CMF_8             VARCHAR2(30 BYTE),
  TRAN_CMF_9             VARCHAR2(30 BYTE),
  TRAN_CMF_10            VARCHAR2(30 BYTE),
  TRAN_CMF_11            VARCHAR2(30 BYTE),
  TRAN_CMF_12            VARCHAR2(30 BYTE),
  TRAN_CMF_13            VARCHAR2(30 BYTE),
  TRAN_CMF_14            VARCHAR2(30 BYTE),
  TRAN_CMF_15            VARCHAR2(30 BYTE),
  TRAN_CMF_16            VARCHAR2(30 BYTE),
  TRAN_CMF_17            VARCHAR2(30 BYTE),
  TRAN_CMF_18            VARCHAR2(30 BYTE),
  TRAN_CMF_19            VARCHAR2(30 BYTE),
  TRAN_CMF_20            VARCHAR2(30 BYTE),
  TRAN_USER_ID           VARCHAR2(20 BYTE),
  TRAN_COMMENT           VARCHAR2(400 BYTE),
  PREV_ACTIVE_HIST_SEQ   NUMBER(10),
  MULTI_TR_KEY           VARCHAR2(30 BYTE),
  MULTI_TR_SEQ           NUMBER(10),
  EXT_HIST_SEQ           NUMBER(10),
  HIST_DEL_FLAG          VARCHAR2(1 BYTE),
  HIST_DEL_TIME          DATE,
  HIST_DEL_USER_ID       VARCHAR2(20 BYTE),
  HIST_DEL_COMMENT       VARCHAR2(400 BYTE),
  SHIFT                  VARCHAR2(1 BYTE),
  PRODUCT_GRP            VARCHAR2(1 BYTE),
  YIELD_WORK_CELL        VARCHAR2(30 BYTE),
  YIELD_SECTION          VARCHAR2(30 BYTE),
  DATE_CREATED           DATE,
  DATE_UPDATED           DATE
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPLOTHIS
ADD CONSTRAINT RWIPLOTHIS_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;

/* RWIPSLTHIS : MWIPSLTHIS Table Replication in WIPLoader */
CREATE TABLE RWIPSLTHIS
(
  SUBLOT_ID              VARCHAR2(30 BYTE)      DEFAULT (' ')                 NOT NULL,
  HIST_SEQ               NUMBER(10)             DEFAULT (0)                   NOT NULL,
  TRAN_TIME              DATE,
  SYS_TRAN_TIME          DATE,
  TRAN_CODE              VARCHAR2(12 BYTE),
  LOT_ID                 VARCHAR2(25 BYTE),
  FACTORY                VARCHAR2(10 BYTE),
  MAT_ID                 VARCHAR2(30 BYTE),
  MAT_VER                NUMBER(6),
  FLOW                   VARCHAR2(20 BYTE),
  FLOW_SEQ_NUM           NUMBER(6),
  OPER                   VARCHAR2(10 BYTE),
  SLOT_NO                NUMBER(6),
  QTY_2                  NUMBER(10,3),
  QTY_3                  NUMBER(10,3),
  CRR_ID                 VARCHAR2(20 BYTE),
  OWNER_CODE             VARCHAR2(10 BYTE),
  CREATE_CODE            VARCHAR2(10 BYTE),
  SUBLOT_STATUS          VARCHAR2(10 BYTE),
  HOLD_FLAG              VARCHAR2(1 BYTE),
  HOLD_CODE              VARCHAR2(10 BYTE),
  HOLD_PASSWORD          VARCHAR2(20 BYTE),
  HOLD_PRV_GRP_ID        VARCHAR2(20 BYTE),
  OPER_IN_QTY_2          NUMBER(10,3),
  OPER_IN_QTY_3          NUMBER(10,3),
  CREATE_QTY_2           NUMBER(10,3),
  CREATE_QTY_3           NUMBER(10,3),
  START_QTY_2            NUMBER(10,3),
  START_QTY_3            NUMBER(10,3),
  INV_FLAG               VARCHAR2(1 BYTE),
  TRANSIT_FLAG           VARCHAR2(1 BYTE),
  UNIT_EXIST_FLAG        VARCHAR2(1 BYTE),
  INV_UNIT               VARCHAR2(10 BYTE),
  RWK_FLAG               VARCHAR2(1 BYTE),
  RWK_CODE               VARCHAR2(10 BYTE),
  RWK_COUNT              NUMBER(6),
  RWK_RET_FLOW           VARCHAR2(20 BYTE),
  RWK_RET_FLOW_SEQ_NUM   NUMBER(6),
  RWK_RET_OPER           VARCHAR2(10 BYTE),
  RWK_END_FLOW           VARCHAR2(20 BYTE),
  RWK_END_FLOW_SEQ_NUM   NUMBER(6),
  RWK_END_OPER           VARCHAR2(10 BYTE),
  RWK_RET_CLEAR_FLAG     VARCHAR2(1 BYTE),
  RWK_TIME               DATE,
  NSTD_FLAG              VARCHAR2(1 BYTE),
  NSTD_RET_FLOW          VARCHAR2(20 BYTE),
  NSTD_RET_FLOW_SEQ_NUM  NUMBER(6),
  NSTD_RET_OPER          VARCHAR2(10 BYTE),
  NSTD_TIME              DATE,
  REP_FLAG               VARCHAR2(1 BYTE),
  REP_RET_OPER           VARCHAR2(10 BYTE),
  STR_RET_FLOW           VARCHAR2(20 BYTE),
  STR_RET_FLOW_SEQ_NUM   NUMBER(6),
  STR_RET_OPER           VARCHAR2(10 BYTE),
  CREATE_TIME            DATE,
  FAC_IN_TIME            DATE,
  FLOW_IN_TIME           DATE,
  OPER_IN_TIME           DATE,
  START_FLAG             VARCHAR2(1 BYTE),
  START_TIME             DATE,
  START_RES_ID           VARCHAR2(20 BYTE),
  END_FLAG               VARCHAR2(1 BYTE),
  END_TIME               DATE,
  END_RES_ID             VARCHAR2(20 BYTE),
  SAMPLE_FLAG            VARCHAR2(1 BYTE),
  SAMPLE_WAIT_FLAG       VARCHAR2(1 BYTE),
  SAMPLE_RESULT          VARCHAR2(1 BYTE),
  RESERVE_RES_ID         VARCHAR2(20 BYTE),
  PORT_ID                VARCHAR2(10 BYTE),
  SUBLOT_LOCATION_1      VARCHAR2(20 BYTE),
  SUBLOT_LOCATION_2      VARCHAR2(20 BYTE),
  SUBLOT_LOCATION_3      VARCHAR2(20 BYTE),
  SUBRES_ID              VARCHAR2(20 BYTE),
  SUBLOT_CMF_1           VARCHAR2(30 BYTE),
  SUBLOT_CMF_2           VARCHAR2(30 BYTE),
  SUBLOT_CMF_3           VARCHAR2(30 BYTE),
  SUBLOT_CMF_4           VARCHAR2(30 BYTE),
  SUBLOT_CMF_5           VARCHAR2(30 BYTE),
  SUBLOT_CMF_6           VARCHAR2(30 BYTE),
  SUBLOT_CMF_7           VARCHAR2(30 BYTE),
  SUBLOT_CMF_8           VARCHAR2(30 BYTE),
  SUBLOT_CMF_9           VARCHAR2(30 BYTE),
  SUBLOT_CMF_10          VARCHAR2(30 BYTE),
  SUBLOT_CMF_11          VARCHAR2(30 BYTE),
  SUBLOT_CMF_12          VARCHAR2(30 BYTE),
  SUBLOT_CMF_13          VARCHAR2(30 BYTE),
  SUBLOT_CMF_14          VARCHAR2(30 BYTE),
  SUBLOT_CMF_15          VARCHAR2(30 BYTE),
  SUBLOT_CMF_16          VARCHAR2(30 BYTE),
  SUBLOT_CMF_17          VARCHAR2(30 BYTE),
  SUBLOT_CMF_18          VARCHAR2(30 BYTE),
  SUBLOT_CMF_19          VARCHAR2(30 BYTE),
  SUBLOT_CMF_20          VARCHAR2(30 BYTE),
  SUBLOT_DEL_FLAG        VARCHAR2(1 BYTE),
  SUBLOT_DEL_CODE        VARCHAR2(10 BYTE),
  SUBLOT_DEL_TIME        DATE,
  GRADE                  VARCHAR2(1 BYTE),
  GRADE_CODE             VARCHAR2(10 BYTE),
  CELL_GRADE             VARCHAR2(500 BYTE),
  CELL_JUDGE             VARCHAR2(500 BYTE),
  LOT_BASE               VARCHAR2(1 BYTE),
  LOT_HIST_SEQ           NUMBER(10),
  OLD_FACTORY            VARCHAR2(10 BYTE),
  OLD_MAT_ID             VARCHAR2(30 BYTE),
  OLD_MAT_VER            NUMBER(6),
  OLD_FLOW               VARCHAR2(20 BYTE),
  OLD_FLOW_SEQ_NUM       NUMBER(6),
  OLD_OPER               VARCHAR2(10 BYTE),
  OLD_QTY_2              NUMBER(10,3),
  OLD_QTY_3              NUMBER(10,3),
  OLD_CRR_ID             VARCHAR2(20 BYTE),
  OLD_OWNER_CODE         VARCHAR2(10 BYTE),
  OLD_CREATE_CODE        VARCHAR2(10 BYTE),
  OLD_FAC_IN_TIME        DATE,
  OLD_FLOW_IN_TIME       DATE,
  OLD_OPER_IN_TIME       DATE,
  TRAN_CMF_1             VARCHAR2(30 BYTE),
  TRAN_CMF_2             VARCHAR2(30 BYTE),
  TRAN_CMF_3             VARCHAR2(30 BYTE),
  TRAN_CMF_4             VARCHAR2(30 BYTE),
  TRAN_CMF_5             VARCHAR2(30 BYTE),
  TRAN_CMF_6             VARCHAR2(30 BYTE),
  TRAN_CMF_7             VARCHAR2(30 BYTE),
  TRAN_CMF_8             VARCHAR2(30 BYTE),
  TRAN_CMF_9             VARCHAR2(30 BYTE),
  TRAN_CMF_10            VARCHAR2(30 BYTE),
  TRAN_CMF_11            VARCHAR2(30 BYTE),
  TRAN_CMF_12            VARCHAR2(30 BYTE),
  TRAN_CMF_13            VARCHAR2(30 BYTE),
  TRAN_CMF_14            VARCHAR2(30 BYTE),
  TRAN_CMF_15            VARCHAR2(30 BYTE),
  TRAN_CMF_16            VARCHAR2(30 BYTE),
  TRAN_CMF_17            VARCHAR2(30 BYTE),
  TRAN_CMF_18            VARCHAR2(30 BYTE),
  TRAN_CMF_19            VARCHAR2(30 BYTE),
  TRAN_CMF_20            VARCHAR2(30 BYTE),
  TRAN_USER_ID           VARCHAR2(20 BYTE),
  TRAN_COMMENT           VARCHAR2(400 BYTE),
  PREV_ACTIVE_HIST_SEQ   NUMBER(10),
  MULTI_TR_KEY           VARCHAR2(30 BYTE),
  MULTI_TR_SEQ           NUMBER(10),
  EXT_HIST_SEQ           NUMBER(10),
  HIST_DEL_FLAG          VARCHAR2(1 BYTE),
  HIST_DEL_TIME          DATE,
  HIST_DEL_USER_ID       VARCHAR2(20 BYTE),
  HIST_DEL_COMMENT       VARCHAR2(400 BYTE),
  OLD_GRADE              VARCHAR2(1 BYTE),
  OLD_LOT_ID             VARCHAR2(25 BYTE),
  OLD_SLOT_NO            NUMBER(6),
  SUBLOT_TYPE            CHAR(1),
  RESV_FIELD_1           VARCHAR2(30),
  RESV_FIELD_2           VARCHAR2(30),
  RESV_FIELD_3           VARCHAR2(30),
  RESV_FIELD_4           VARCHAR2(30),
  RESV_FIELD_5           VARCHAR2(30),
  RESV_FLAG_1            CHAR(1),
  RESV_FLAG_2            CHAR(1),
  RESV_FLAG_3            CHAR(1),
  RESV_FLAG_4            CHAR(1),
  RESV_FLAG_5            CHAR(1)
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPSLTHIS
ADD CONSTRAINT RWIPSLTHIS_PK PRIMARY KEY
(
    SUBLOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE INDEX RWIPSLTHIS_IDX_1 ON RWIPSLTHIS
(SUBLOT_ID, HIST_DEL_FLAG, TRAN_CODE)
TABLESPACE REPORT_IDX_TS;


CREATE INDEX RWIPSLTHIS_IDX_2 ON RWIPSLTHIS
(TRAN_TIME, SUBLOT_ID, HIST_DEL_FLAG, TRAN_CODE)
TABLESPACE REPORT_IDX_TS;


CREATE INDEX RWIPSLTHIS_IDX_3 ON RWIPSLTHIS
(LOT_ID, LOT_HIST_SEQ, LOT_BASE)
TABLESPACE REPORT_IDX_TS;


/* RWIPLOTLOS : MWIPLOTLOS Table Replication in WIPLoader */
CREATE TABLE RWIPLOTLOS
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* QTY Flag - '1':Qty 1, '2':Qty 2, '3':Qty 3 */
    QTY_FLAG                    CHAR(1)          DEFAULT('1')    NOT NULL,
    /* Transaction Time - Backdate 가능 */
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
    /* 원인 Flow, 공정, 장비 */
    CAUSE_FLOW                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CAUSE_OPER                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Resource ID */
    CAUSE_RES_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* New Quantity */
    NEW_QTY                     NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Old Quantity */
    OLD_QTY                     NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Total Loss Qty */
    TOTAL_LOSS_QTY              NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Loss Code/Qty */
    LOSS_CODE_1                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOSS_CODE_2                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOSS_CODE_3                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOSS_CODE_4                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOSS_CODE_5                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOSS_CODE_6                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOSS_CODE_7                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOSS_CODE_8                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOSS_CODE_9                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOSS_CODE_10                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOSS_QTY_1                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    LOSS_QTY_2                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    LOSS_QTY_3                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    LOSS_QTY_4                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    LOSS_QTY_5                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    LOSS_QTY_6                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    LOSS_QTY_7                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    LOSS_QTY_8                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    LOSS_QTY_9                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    LOSS_QTY_10                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Loss Comment */
    LOSS_COMMENT_1              VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    LOSS_COMMENT_2              VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    LOSS_COMMENT_3              VARCHAR2(400)    DEFAULT(' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPLOTLOS
ADD CONSTRAINT RWIPLOTLOS_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    QTY_FLAG
) USING INDEX TABLESPACE REPORT_IDX_TS;

/* RWIPSLTLOS : MWIPSLTLOS Table Replication in WIPLoader */
CREATE TABLE RWIPSLTLOS
(
  SUBLOT_ID      VARCHAR2(30 BYTE)              DEFAULT (' ')                 NOT NULL,
  LOT_ID         VARCHAR2(25 BYTE)              DEFAULT (' ')                 NOT NULL,
  HIST_SEQ       NUMBER(10)                     DEFAULT (0)                   NOT NULL,
  LOT_HIST_SEQ   NUMBER(10)                     DEFAULT (0)                   NOT NULL,
  QTY_FLAG       VARCHAR2(1 BYTE)               DEFAULT (' ')                 NOT NULL,
  GRADE          VARCHAR2(1 BYTE),
  LOSS_CODE      VARCHAR2(10 BYTE)              DEFAULT (' ')                 NOT NULL,
  TRAN_TIME      DATE,
  HIST_DEL_FLAG  VARCHAR2(1 BYTE),
  FACTORY        VARCHAR2(10 BYTE),
  MAT_ID         VARCHAR2(30 BYTE),
  MAT_VER        NUMBER(6),
  FLOW           VARCHAR2(20 BYTE),
  FLOW_SEQ_NUM   NUMBER(6),
  OPER           VARCHAR2(10 BYTE),
  RES_ID         VARCHAR2(20 BYTE),
  CAUSE_FLOW     VARCHAR2(20 BYTE),
  CAUSE_OPER     VARCHAR2(10 BYTE),
  CAUSE_RES_ID   VARCHAR2(20 BYTE),
  LOSS_QTY                    NUMBER(10,3)     DEFAULT(0.0)    NOT NULL

) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPSLTLOS
ADD CONSTRAINT RWIPSLTLOS_PK PRIMARY KEY
(
    SUBLOT_ID, 
    LOT_ID, 
    HIST_SEQ, 
    QTY_FLAG, 
    LOSS_CODE
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE TABLE RWIPLOTLSM
(
  LOT_ID         VARCHAR2(25 BYTE)              DEFAULT (' ')                 NOT NULL,
  HIST_SEQ       NUMBER(10)                     DEFAULT (0)                   NOT NULL,
  QTY_FLAG       VARCHAR2(1 BYTE),
  TRAN_TIME      DATE,
  HIST_DEL_FLAG  VARCHAR2(1 BYTE),
  FACTORY        VARCHAR2(10 BYTE),
  MAT_ID         VARCHAR2(30 BYTE),
  MAT_VER        NUMBER(6),
  FLOW           VARCHAR2(20 BYTE),
  FLOW_SEQ_NUM   NUMBER(6),
  OPER           VARCHAR2(10 BYTE),
  RES_ID         VARCHAR2(20 BYTE),
  SEQ_NUM        NUMBER(6)                      DEFAULT (0)                   NOT NULL,
  LOSS_CODE      VARCHAR2(10 BYTE),
  LOSS_QTY       NUMBER(10,3),
  RWK_FLAG       VARCHAR2(1 BYTE),
  HIST_DEL_TIME  DATE,
  UNIT         VARCHAR2(20 BYTE)
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPLOTLSM 
ADD CONSTRAINT RWIPLOTLSM_PK PRIMARY KEY
(
    LOT_ID, 
    HIST_SEQ, 
    QTY_FLAG, 
    SEQ_NUM
) USING INDEX TABLESPACE REPORT_IDX_TS;

/* RWIPLOTBNS : MWIPLOTBNS Table Replication in WIPLoader */
CREATE TABLE RWIPLOTBNS
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* QTY Flag - '1':Qty 1, '2':Qty 2, '3':Qty 3 */
    QTY_FLAG                    CHAR(1)          DEFAULT('1')    NOT NULL,
    /* Transaction Time - Backdate 가능 */
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
    /* 원인 Flow, 공정, 장비 */
    CAUSE_FLOW                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CAUSE_OPER                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Resource ID */
    CAUSE_RES_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* New Quantity */
    NEW_QTY                     NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Old Quantity */
    OLD_QTY                     NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Total Bonus Qty */
    TOTAL_BONUS_QTY             NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Bonus Code/Qty */
    BONUS_CODE_1                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BONUS_CODE_2                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BONUS_CODE_3                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BONUS_CODE_4                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BONUS_CODE_5                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BONUS_CODE_6                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BONUS_CODE_7                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BONUS_CODE_8                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BONUS_CODE_9                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BONUS_CODE_10               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BONUS_QTY_1                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    BONUS_QTY_2                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    BONUS_QTY_3                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    BONUS_QTY_4                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    BONUS_QTY_5                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    BONUS_QTY_6                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    BONUS_QTY_7                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    BONUS_QTY_8                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    BONUS_QTY_9                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    BONUS_QTY_10                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Bonus Comment 처리 */
    BONUS_COMMENT_1             VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    BONUS_COMMENT_2             VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    BONUS_COMMENT_3             VARCHAR2(400)    DEFAULT(' ')    NOT NULL 
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPLOTBNS
ADD CONSTRAINT RWIPLOTBNS_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    QTY_FLAG
) USING INDEX TABLESPACE REPORT_IDX_TS;

/* RWIPLOTHLD : MWIPLOTHLD Table Replication in WIPLoader */
CREATE TABLE RWIPLOTHLD
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Transaction Time - Backdate 가능 */
    HOLD_TRAN_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Release Time */
    RELEASE_TRAN_TIME           VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Delete Info. */
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Release History Sequence */
    RELEASE_HIST_SEQ            NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Factory */
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Resource ID */
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* 원인 Flow, 공정, 장비 */
    CAUSE_FLOW                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CAUSE_OPER                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Resource ID */
    CAUSE_RES_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Quantity 1 ~ 3 */
    QTY_1                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* CMF 1~10 */
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
    CMF_11                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    CMF_12                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    CMF_13                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    CMF_14                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    CMF_15                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    CMF_16                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    CMF_17                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    CMF_18                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    CMF_19                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    CMF_20                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    /* Hold Comment */
    HOLD_CODE                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    HOLD_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HOLD_PRV_GRP_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HOLD_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* Release Comment */
    RELEASE_CODE                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RELEASE_USER_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RELEASE_COMMENT             VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* User ID/Time/Comment 1~3 */
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

ALTER TABLE RWIPLOTHLD
ADD CONSTRAINT RWIPLOTHLD_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;

/* RWIPLOTSHP : MWIPLOTSHP Table Replication in WIPLoader */
CREATE TABLE RWIPLOTSHP
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Transaction Time - Backdate 가능 */
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
    /* Quantity 1 ~ 3 */
    QTY_1                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Shipping Info. */
    /* CMF 1~10 */
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
    CMF_11                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    CMF_12                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    CMF_13                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    CMF_14                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    CMF_15                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    CMF_16                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    CMF_17                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    CMF_18                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    CMF_19                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    CMF_20                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL   /* Add For V42 */
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPLOTSHP
ADD CONSTRAINT RWIPLOTSHP_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* RWIPLOTSPL : MWIPLOTSPL Table Replication in WIPLoader */
CREATE TABLE RWIPLOTSPL
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Transaction Time - Backdate 가능 */
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Delete Info. */
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Factory */
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* From/To Info. */
    FROM_TO_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    FROM_TO_LOT_ID              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    FROM_TO_MAT_ID              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FROM_TO_MAT_VER             NUMBER(6)        DEFAULT(0)      NOT NULL,
    FROM_TO_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FROM_TO_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,
    FROM_TO_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FROM_TO_QTY_1               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_QTY_2               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_QTY_3               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_HIST_SEQ            NUMBER(10)       DEFAULT(0)      NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPLOTSPL
ADD CONSTRAINT RWIPLOTSPL_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* RWIPLOTMRG : MWIPLOTMRG Table Replication in WIPLoader */
CREATE TABLE RWIPLOTMRG
(
     LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Transaction Time - Backdate 가능 */
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Delete Info. */
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Factory */
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* From/To Info. */
    FROM_TO_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    FROM_TO_LOT_ID              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    FROM_TO_MAT_ID              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FROM_TO_MAT_VER             NUMBER(6)        DEFAULT(0)      NOT NULL,
    FROM_TO_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FROM_TO_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,
    FROM_TO_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FROM_TO_QTY_1               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_QTY_2               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_QTY_3               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_HIST_SEQ            NUMBER(10)       DEFAULT(0)      NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPLOTMRG
ADD CONSTRAINT RWIPLOTMRG_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* RWIPLOTCMB : MWIPLOTCMB Table Replication in WIPLoader */
CREATE TABLE RWIPLOTCMB
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Transaction Time - Backdate 가능 */
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
    /* From/To Info. */
    FROM_TO_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    FROM_TO_LOT_ID              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    FROM_TO_MAT_ID              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FROM_TO_MAT_VER             NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    FROM_TO_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FROM_TO_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    FROM_TO_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FROM_TO_QTY_1               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_QTY_2               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_QTY_3               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_HIST_SEQ            NUMBER(10)       DEFAULT(0)      NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPLOTCMB
ADD CONSTRAINT RWIPLOTCMB_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;


/* RWIPLOTRWK : MWIPLOTRWK Table Replication in WIPLoader */
CREATE TABLE RWIPLOTRWK
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Transaction Time - Backdate 가능 */
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Delete Info. */
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Factory */
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* REWORK을 보내는 공정 */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Resource ID */
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* 원인 Flow, 공정, 장비 */
    CAUSE_FLOW                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CAUSE_OPER                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Resource ID */
    CAUSE_RES_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Quantity 1 ~ 3 */
    QTY_1                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Rework Info. */
    RWK_CODE                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* LOT의 Rework 누적 횟수 */
    RWK_COUNT                   NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* LOT Rework Depth */
    RWK_DEPTH                   NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* REWORK 공정 */
    RWK_FLOW                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RWK_FLOW_SEQ_NUM            NUMBER(6)        DEFAULT(0)      NOT NULL,
    RWK_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RWK_STOP_OPER               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* REWORK후 돌아올 공정 */
    RWK_RET_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RWK_RET_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,
    RWK_RET_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* REWORK이 끝나는 공정 REWROK을 보낼때 현재 공정을 넣는다.*/
    RWK_END_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RWK_END_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,
    RWK_END_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* RETUREN 시 REWROK FLAG CLEAR */
    RWK_RET_CLEAR_FLAG          CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOCAL_REWORK_FLAG           CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Rework Comment */
    RWK_USER_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RWK_COMMENT                 VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* User ID/Time/Comment 1~3 */
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


/* RWEBFLXINQ : Flexible Inquiry Definition Table */
CREATE TABLE RWEBFLXINQ
(
	FACTORY						VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
	INQUIRY_NAME				VARCHAR2(30)	DEFAULT (' ')    NOT NULL,
	INQUIRY_DESC				VARCHAR2(50)    DEFAULT (' ')    NOT NULL,
	INQUIRY_GROUP				VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
	/* 필수 조회 조건과 값 */
	SELECT_ITEM					VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
	SELECT_VALUE				VARCHAR2(30)	DEFAULT (' ')    NOT NULL,
	/* Group By 아이템 */
	GROUP_ITEM					VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
	/* Flter할 Query */
	FILTER_QUERY				VARCHAR2(1000)  DEFAULT (' ')    NOT NULL,
	RESV_FIELD_1				VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
	RESV_FIELD_2				VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
	RESV_FIELD_3				VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
	RESV_FIELD_4				VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
	RESV_FIELD_5				VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
	RESV_FLAG_1					CHAR(1)         DEFAULT (' ')    NOT NULL,
	RESV_FLAG_2					CHAR(1)         DEFAULT (' ')    NOT NULL,
	RESV_FLAG_3					CHAR(1)         DEFAULT (' ')    NOT NULL,
	RESV_FLAG_4					CHAR(1)         DEFAULT (' ')    NOT NULL,
	RESV_FLAG_5					CHAR(1)         DEFAULT (' ')    NOT NULL,
	CREATE_USER_ID				VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
	CREATE_TIME					VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
	UPDATE_USER_ID				VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
	UPDATE_TIME					VARCHAR2(14)    DEFAULT (' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWEBFLXINQ
ADD CONSTRAINT RWEBFLXINQ_PK PRIMARY KEY
(
    FACTORY,
    INQUIRY_NAME
) USING INDEX TABLESPACE REPORT_IDX_TS;

/* RWEBFLXINQ : Column Definition Table for Flexible Inquiry*/
CREATE TABLE RWEBFLXCOL
(
	FACTORY						VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
	INQUIRY_NAME				VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
	COLUMN_SEQ					NUMBER(3)       DEFAULT (0)      NOT NULL,
	COLUMN_NAME					VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
	COLUMN_PERIOD				VARCHAR2(3)     DEFAULT (' ')    NOT NULL,
	COLUMN_ALIAS_1				VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
	COLUMN_ALIAS_2				VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
	RESV_FIELD_1				VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
	RESV_FIELD_2				VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
	RESV_FIELD_3				VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
	RESV_FIELD_4				VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
	RESV_FIELD_5				VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
	RESV_FLAG_1					CHAR(1)         DEFAULT (' ')    NOT NULL,
	RESV_FLAG_2					CHAR(1)         DEFAULT (' ')    NOT NULL,
	RESV_FLAG_3					CHAR(1)         DEFAULT (' ')    NOT NULL,
	RESV_FLAG_4					CHAR(1)         DEFAULT (' ')    NOT NULL,
	RESV_FLAG_5					CHAR(1)         DEFAULT (' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWEBFLXCOL
ADD CONSTRAINT RWEBFLXCOL_PK PRIMARY KEY
(
    FACTORY, 
    INQUIRY_NAME, 
    COLUMN_SEQ, 
    COLUMN_NAME
) USING INDEX TABLESPACE REPORT_IDX_TS;


CREATE TABLE RRASRESDEF
(
  FACTORY               VARCHAR2(10 BYTE)       DEFAULT (' ')                 NOT NULL,
  RES_ID                VARCHAR2(20 BYTE)       DEFAULT (' ')                 NOT NULL,
  RES_DESC              VARCHAR2(200 BYTE),
  RES_TYPE              VARCHAR2(20 BYTE),
  RES_GRP_1             VARCHAR2(30 BYTE),
  RES_GRP_2             VARCHAR2(30 BYTE),
  RES_GRP_3             VARCHAR2(30 BYTE),
  RES_GRP_4             VARCHAR2(30 BYTE),
  RES_GRP_5             VARCHAR2(30 BYTE),
  RES_GRP_6             VARCHAR2(30 BYTE),
  RES_GRP_7             VARCHAR2(30 BYTE),
  RES_GRP_8             VARCHAR2(30 BYTE),
  RES_GRP_9             VARCHAR2(30 BYTE),
  RES_GRP_10            VARCHAR2(30 BYTE),
  USE_FAC_PRT_FLAG      VARCHAR2(1 BYTE),
  RES_STS_PRT_1         VARCHAR2(30 BYTE),
  RES_STS_PRT_2         VARCHAR2(30 BYTE),
  RES_STS_PRT_3         VARCHAR2(30 BYTE),
  RES_STS_PRT_4         VARCHAR2(30 BYTE),
  RES_STS_PRT_5         VARCHAR2(30 BYTE),
  RES_STS_PRT_6         VARCHAR2(30 BYTE),
  RES_STS_PRT_7         VARCHAR2(30 BYTE),
  RES_STS_PRT_8         VARCHAR2(30 BYTE),
  RES_STS_PRT_9         VARCHAR2(30 BYTE),
  RES_STS_PRT_10        VARCHAR2(30 BYTE),
  RES_CMF_1             VARCHAR2(30 BYTE),
  RES_CMF_2             VARCHAR2(30 BYTE),
  RES_CMF_3             VARCHAR2(30 BYTE),
  RES_CMF_4             VARCHAR2(30 BYTE),
  RES_CMF_5             VARCHAR2(30 BYTE),
  RES_CMF_6             VARCHAR2(30 BYTE),
  RES_CMF_7             VARCHAR2(30 BYTE),
  RES_CMF_8             VARCHAR2(30 BYTE),
  RES_CMF_9             VARCHAR2(30 BYTE),
  RES_CMF_10            VARCHAR2(30 BYTE),
  RES_CMF_11            VARCHAR2(30 BYTE),
  RES_CMF_12            VARCHAR2(30 BYTE),
  RES_CMF_13            VARCHAR2(30 BYTE),
  RES_CMF_14            VARCHAR2(30 BYTE),
  RES_CMF_15            VARCHAR2(30 BYTE),
  RES_CMF_16            VARCHAR2(30 BYTE),
  RES_CMF_17            VARCHAR2(30 BYTE),
  RES_CMF_18            VARCHAR2(30 BYTE),
  RES_CMF_19            VARCHAR2(30 BYTE),
  RES_CMF_20            VARCHAR2(30 BYTE),
  AREA_ID               VARCHAR2(20 BYTE),
  SUB_AREA_ID           VARCHAR2(20 BYTE),
  RES_LOCATION          VARCHAR2(20 BYTE),
  PROC_RULE             VARCHAR2(1 BYTE),
  MAX_PROC_COUNT        NUMBER(3),
  BATCH_COND_1          VARCHAR2(12 BYTE),
  BATCH_COND_2          VARCHAR2(12 BYTE),
  PM_SCH_ENABLE_FLAG    VARCHAR2(1 BYTE),
  UNIT_BASE_ST_FLAG     VARCHAR2(1 BYTE),
  SEC_CHK_FLAG          VARCHAR2(1 BYTE),
  GATHER_ALARM_FLAG     VARCHAR2(1 BYTE),
  DELETE_FLAG           VARCHAR2(1 BYTE),
  DELETE_USER_ID        VARCHAR2(20 BYTE),
  DELETE_TIME           DATE,
  CREATE_USER_ID        VARCHAR2(20 BYTE),
  CREATE_TIME           DATE,
  UPDATE_USER_ID        VARCHAR2(20 BYTE),
  UPDATE_TIME           DATE,
  RES_UP_DOWN_FLAG      VARCHAR2(1 BYTE),
  RES_PRI_STS           VARCHAR2(30 BYTE),
  RES_STS_1             VARCHAR2(30 BYTE),
  RES_STS_2             VARCHAR2(30 BYTE),
  RES_STS_3             VARCHAR2(30 BYTE),
  RES_STS_4             VARCHAR2(30 BYTE),
  RES_STS_5             VARCHAR2(30 BYTE),
  RES_STS_6             VARCHAR2(30 BYTE),
  RES_STS_7             VARCHAR2(30 BYTE),
  RES_STS_8             VARCHAR2(30 BYTE),
  RES_STS_9             VARCHAR2(30 BYTE),
  RES_STS_10            VARCHAR2(30 BYTE),
  LOT_ID                VARCHAR2(25 BYTE),
  SUBLOT_ID             VARCHAR2(30 BYTE),
  CRR_ID                VARCHAR2(20 BYTE),
  RES_CTRL_MODE         VARCHAR2(2 BYTE),
  RES_PROC_MODE         VARCHAR2(10 BYTE),
  LAST_RECIPE_ID        VARCHAR2(30 BYTE),
  PROC_COUNT            NUMBER(3),
  LAST_START_TIME       DATE,
  LAST_END_TIME         DATE,
  LAST_DOWN_TIME        DATE,
  LAST_DOWN_HIST_SEQ    NUMBER(10),
  LAST_EVENT_ID         VARCHAR2(12 BYTE),
  LAST_EVENT_TIME       DATE,
  LAST_ACTIVE_HIST_SEQ  NUMBER(10),
  LAST_HIST_SEQ         NUMBER(10),
  MES_ERASE_TIME        DATE,
  RES_SHORT_DESC        VARCHAR2(50 BYTE)
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RRASRESDEF
ADD CONSTRAINT RRASRESDEF_PK PRIMARY KEY
(
    FACTORY, 
    RES_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;


CREATE TABLE RRASRESHIS
(
  FACTORY             VARCHAR2(10 BYTE)         DEFAULT (' ')                 NOT NULL,
  RES_ID              VARCHAR2(20 BYTE)         DEFAULT (' ')                 NOT NULL,
  HIST_SEQ            NUMBER(10)                DEFAULT (0)                   NOT NULL,
  EVENT_ID            VARCHAR2(12 BYTE),
  TRAN_TIME           DATE,
  SYS_TRAN_TIME       DATE,
  OLD_EVENT_ID        VARCHAR2(12 BYTE),
  OLD_HIST_SEQ        NUMBER(10),
  OLD_TRAN_TIME       DATE,
  OLD_SYS_TRAN_TIME   DATE,
  OLD_UP_DOWN_FLAG    VARCHAR2(1 BYTE),
  OLD_PRI_STS         VARCHAR2(30 BYTE),
  OLD_STS_1           VARCHAR2(30 BYTE),
  OLD_STS_2           VARCHAR2(30 BYTE),
  OLD_STS_3           VARCHAR2(30 BYTE),
  OLD_STS_4           VARCHAR2(30 BYTE),
  OLD_STS_5           VARCHAR2(30 BYTE),
  OLD_STS_6           VARCHAR2(30 BYTE),
  OLD_STS_7           VARCHAR2(30 BYTE),
  OLD_STS_8           VARCHAR2(30 BYTE),
  OLD_STS_9           VARCHAR2(30 BYTE),
  OLD_STS_10          VARCHAR2(30 BYTE),
  NEW_UP_DOWN_FLAG    VARCHAR2(1 BYTE),
  NEW_PRI_STS         VARCHAR2(30 BYTE),
  NEW_STS_1           VARCHAR2(30 BYTE),
  NEW_STS_2           VARCHAR2(30 BYTE),
  NEW_STS_3           VARCHAR2(30 BYTE),
  NEW_STS_4           VARCHAR2(30 BYTE),
  NEW_STS_5           VARCHAR2(30 BYTE),
  NEW_STS_6           VARCHAR2(30 BYTE),
  NEW_STS_7           VARCHAR2(30 BYTE),
  NEW_STS_8           VARCHAR2(30 BYTE),
  NEW_STS_9           VARCHAR2(30 BYTE),
  NEW_STS_10          VARCHAR2(30 BYTE),
  LOT_ID              VARCHAR2(25 BYTE),
  SUBLOT_ID           VARCHAR2(30 BYTE),
  CRR_ID              VARCHAR2(20 BYTE),
  RES_CTRL_MODE       VARCHAR2(2 BYTE),
  RES_PROC_MODE       VARCHAR2(10 BYTE),
  LOT_EXIST_FLAG      VARCHAR2(1 BYTE),
  COL_SET_ID          VARCHAR2(25 BYTE),
  COL_SET_VERSION     NUMBER(3),
  TRAN_CMF_1          VARCHAR2(30 BYTE),
  TRAN_CMF_2          VARCHAR2(30 BYTE),
  TRAN_CMF_3          VARCHAR2(30 BYTE),
  TRAN_CMF_4          VARCHAR2(30 BYTE),
  TRAN_CMF_5          VARCHAR2(30 BYTE),
  TRAN_CMF_6          VARCHAR2(30 BYTE),
  TRAN_CMF_7          VARCHAR2(30 BYTE),
  TRAN_CMF_8          VARCHAR2(30 BYTE),
  TRAN_CMF_9          VARCHAR2(30 BYTE),
  TRAN_CMF_10         VARCHAR2(30 BYTE),
  TRAN_CMF_11         VARCHAR2(30 BYTE),
  TRAN_CMF_12         VARCHAR2(30 BYTE),
  TRAN_CMF_13         VARCHAR2(30 BYTE),
  TRAN_CMF_14         VARCHAR2(30 BYTE),
  TRAN_CMF_15         VARCHAR2(30 BYTE),
  TRAN_CMF_16         VARCHAR2(30 BYTE),
  TRAN_CMF_17         VARCHAR2(30 BYTE),
  TRAN_CMF_18         VARCHAR2(30 BYTE),
  TRAN_CMF_19         VARCHAR2(30 BYTE),
  TRAN_CMF_20         VARCHAR2(30 BYTE),
  TRAN_USER_ID        VARCHAR2(20 BYTE),
  TRAN_COMMENT        VARCHAR2(400 BYTE),
  LAST_DOWN_TIME      DATE,
  LAST_DOWN_HIST_SEQ  NUMBER(10),
  HIST_START_SEQ      NUMBER(10),
  HIST_DEL_FLAG       VARCHAR2(1 BYTE),
  HIST_DEL_TIME       DATE,
  HIST_DEL_USER_ID    VARCHAR2(20 BYTE),
  HIST_DEL_COMMENT    VARCHAR2(400 BYTE),
  END_DATE            DATE,
  EDC_DETAILS         VARCHAR2(12 BYTE),
  REPAIR_PRIOR        VARCHAR2(1 BYTE)
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RRASRESHIS
ADD CONSTRAINT RRASRESHIS_PK PRIMARY KEY
(
    FACTORY, 
    RES_ID, 
    HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;


CREATE TABLE RRASRESLTH
(
  FACTORY            VARCHAR2(10 BYTE)          DEFAULT (' ')                 NOT NULL,
  RES_ID             VARCHAR2(20 BYTE)          DEFAULT (' ')                 NOT NULL,
  RES_HIST_SEQ       NUMBER(10)                 DEFAULT (0)                   NOT NULL,
  LOT_ID             VARCHAR2(25 BYTE)          DEFAULT (' ')                 NOT NULL,
  RES_HIST_DEL_FLAG  CHAR(1 BYTE),
  EVENT_ID           VARCHAR2(12 BYTE),
  TRAN_TIME          DATE,
  LOT_HIST_SEQ       NUMBER(10),
  LOT_HIST_DEL_FLAG  CHAR(1 BYTE),
  MAT_ID             VARCHAR2(30 BYTE),
  MAT_VER            NUMBER(6),
  FLOW               VARCHAR2(20 BYTE),
  OPER               VARCHAR2(10 BYTE),
  LOT_TYPE           CHAR(1 BYTE),
  RWK_FLAG           CHAR(1 BYTE),
  QTY_1              NUMBER(10,3),
  QTY_2              NUMBER(10,3),
  QTY_3              NUMBER(10,3),
  RES_SEQ            NUMBER(10),
  SUBRES_ID          VARCHAR2(20),
  PORT_ID            VARCHAR2(10),
  CRR_ID             VARCHAR2(20)
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RRASRESLTH
ADD CONSTRAINT RRASRESLTH_PK PRIMARY KEY
(
    FACTORY, 
    RES_ID, 
    RES_HIST_SEQ, 
    LOT_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;


CREATE TABLE RRASSRSDEF
(
  FACTORY               VARCHAR2(10 BYTE)       DEFAULT (' ')                 NOT NULL,
  RES_ID                VARCHAR2(20 BYTE)       DEFAULT (' ')                 NOT NULL,
  SUBRES_ID             VARCHAR2(20 BYTE)       DEFAULT (' ')                 NOT NULL,
  SUBRES_DESC           VARCHAR2(200 BYTE),
  PARENTS_SUBRES_ID     VARCHAR2(20 BYTE),
  SUBRES_TYPE           VARCHAR2(20 BYTE),
  USE_FAC_PRT_FLAG      CHAR(1 BYTE),
  RES_STS_PRT_1         VARCHAR2(30 BYTE),
  RES_STS_PRT_2         VARCHAR2(30 BYTE),
  RES_STS_PRT_3         VARCHAR2(30 BYTE),
  RES_STS_PRT_4         VARCHAR2(30 BYTE),
  RES_STS_PRT_5         VARCHAR2(30 BYTE),
  RES_STS_PRT_6         VARCHAR2(30 BYTE),
  RES_STS_PRT_7         VARCHAR2(30 BYTE),
  RES_STS_PRT_8         VARCHAR2(30 BYTE),
  RES_STS_PRT_9         VARCHAR2(30 BYTE),
  RES_STS_PRT_10        VARCHAR2(30 BYTE),
  SUBRES_CMF_1          VARCHAR2(30 BYTE),
  SUBRES_CMF_2          VARCHAR2(30 BYTE),
  SUBRES_CMF_3          VARCHAR2(30 BYTE),
  SUBRES_CMF_4          VARCHAR2(30 BYTE),
  SUBRES_CMF_5          VARCHAR2(30 BYTE),
  SUBRES_CMF_6          VARCHAR2(30 BYTE),
  SUBRES_CMF_7          VARCHAR2(30 BYTE),
  SUBRES_CMF_8          VARCHAR2(30 BYTE),
  SUBRES_CMF_9          VARCHAR2(30 BYTE),
  SUBRES_CMF_10         VARCHAR2(30 BYTE),
  SUBRES_CMF_11         VARCHAR2(30 BYTE),
  SUBRES_CMF_12         VARCHAR2(30 BYTE),
  SUBRES_CMF_13         VARCHAR2(30 BYTE),
  SUBRES_CMF_14         VARCHAR2(30 BYTE),
  SUBRES_CMF_15         VARCHAR2(30 BYTE),
  SUBRES_CMF_16         VARCHAR2(30 BYTE),
  SUBRES_CMF_17         VARCHAR2(30 BYTE),
  SUBRES_CMF_18         VARCHAR2(30 BYTE),
  SUBRES_CMF_19         VARCHAR2(30 BYTE),
  SUBRES_CMF_20         VARCHAR2(30 BYTE),
  CHAMBER_TYPE_FLAG     CHAR(1 BYTE),
  CHAMBER_GRP_ID        VARCHAR2(20 BYTE),
  SUBRES_LOCATION       VARCHAR2(20 BYTE),
  DELETE_FLAG           CHAR(1 BYTE),
  DELETE_USER_ID        VARCHAR2(20 BYTE),
  DELETE_TIME           DATE,
  CREATE_USER_ID        VARCHAR2(20 BYTE),
  CREATE_TIME           DATE,
  UPDATE_USER_ID        VARCHAR2(20 BYTE),
  UPDATE_TIME           DATE,
  SUBRES_UP_DOWN_FLAG   CHAR(1 BYTE),
  SUBRES_PRI_STS        VARCHAR2(30 BYTE),
  SUBRES_STS_1          VARCHAR2(30 BYTE),
  SUBRES_STS_2          VARCHAR2(30 BYTE),
  SUBRES_STS_3          VARCHAR2(30 BYTE),
  SUBRES_STS_4          VARCHAR2(30 BYTE),
  SUBRES_STS_5          VARCHAR2(30 BYTE),
  SUBRES_STS_6          VARCHAR2(30 BYTE),
  SUBRES_STS_7          VARCHAR2(30 BYTE),
  SUBRES_STS_8          VARCHAR2(30 BYTE),
  SUBRES_STS_9          VARCHAR2(30 BYTE),
  SUBRES_STS_10         VARCHAR2(30 BYTE),
  LOT_ID                VARCHAR2(25 BYTE),
  SUBLOT_ID             VARCHAR2(30 BYTE),
  CRR_ID                VARCHAR2(20 BYTE),
  LAST_EVENT_ID         VARCHAR2(12 BYTE),
  LAST_EVENT_TIME       DATE,
  LAST_ACTIVE_HIST_SEQ  NUMBER(10),
  LAST_HIST_SEQ         NUMBER(10)
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RRASSRSDEF
ADD CONSTRAINT RRASSRSDEF_PK PRIMARY KEY
(
    FACTORY, 
    RES_ID, 
    SUBRES_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;


CREATE TABLE RRASSRSHIS
(
  FACTORY             VARCHAR2(10 BYTE)         DEFAULT (' ')                 NOT NULL,
  RES_ID              VARCHAR2(20 BYTE)         DEFAULT (' ')                 NOT NULL,
  SUBRES_ID           VARCHAR2(20 BYTE)         DEFAULT (' ')                 NOT NULL,
  HIST_SEQ            NUMBER(10)                DEFAULT (0)                   NOT NULL,
  EVENT_ID            VARCHAR2(12 BYTE),
  TRAN_TIME           DATE,
  SYS_TRAN_TIME       DATE,
  PARENTS_SUBRES_ID   VARCHAR2(20 BYTE),
  MAIN_HIST_SEQ       NUMBER(10),
  OLD_EVENT_ID        VARCHAR2(12 BYTE),
  OLD_HIST_SEQ        NUMBER(10),
  OLD_TRAN_TIME       DATE,
  OLD_SYS_TRAN_TIME   DATE,
  OLD_UP_DOWN_FLAG    CHAR(1 BYTE),
  OLD_PRI_STS         VARCHAR2(30 BYTE),
  OLD_STS_1           VARCHAR2(30 BYTE),
  OLD_STS_2           VARCHAR2(30 BYTE),
  OLD_STS_3           VARCHAR2(30 BYTE),
  OLD_STS_4           VARCHAR2(30 BYTE),
  OLD_STS_5           VARCHAR2(30 BYTE),
  OLD_STS_6           VARCHAR2(30 BYTE),
  OLD_STS_7           VARCHAR2(30 BYTE),
  OLD_STS_8           VARCHAR2(30 BYTE),
  OLD_STS_9           VARCHAR2(30 BYTE),
  OLD_STS_10          VARCHAR2(30 BYTE),
  NEW_UP_DOWN_FLAG    CHAR(1 BYTE),
  NEW_PRI_STS         VARCHAR2(30 BYTE),
  NEW_STS_1           VARCHAR2(30 BYTE),
  NEW_STS_2           VARCHAR2(30 BYTE),
  NEW_STS_3           VARCHAR2(30 BYTE),
  NEW_STS_4           VARCHAR2(30 BYTE),
  NEW_STS_5           VARCHAR2(30 BYTE),
  NEW_STS_6           VARCHAR2(30 BYTE),
  NEW_STS_7           VARCHAR2(30 BYTE),
  NEW_STS_8           VARCHAR2(30 BYTE),
  NEW_STS_9           VARCHAR2(30 BYTE),
  NEW_STS_10          VARCHAR2(30 BYTE),
  LOT_EXIST_FLAG      CHAR(1 BYTE),
  TRAN_CMF_1          VARCHAR2(30 BYTE),
  TRAN_CMF_2          VARCHAR2(30 BYTE),
  TRAN_CMF_3          VARCHAR2(30 BYTE),
  TRAN_CMF_4          VARCHAR2(30 BYTE),
  TRAN_CMF_5          VARCHAR2(30 BYTE),
  TRAN_CMF_6          VARCHAR2(30 BYTE),
  TRAN_CMF_7          VARCHAR2(30 BYTE),
  TRAN_CMF_8          VARCHAR2(30 BYTE),
  TRAN_CMF_9          VARCHAR2(30 BYTE),
  TRAN_CMF_10         VARCHAR2(30 BYTE),
  TRAN_CMF_11         VARCHAR2(30 BYTE),
  TRAN_CMF_12         VARCHAR2(30 BYTE),
  TRAN_CMF_13         VARCHAR2(30 BYTE),
  TRAN_CMF_14         VARCHAR2(30 BYTE),
  TRAN_CMF_15         VARCHAR2(30 BYTE),
  TRAN_CMF_16         VARCHAR2(30 BYTE),
  TRAN_CMF_17         VARCHAR2(30 BYTE),
  TRAN_CMF_18         VARCHAR2(30 BYTE),
  TRAN_CMF_19         VARCHAR2(30 BYTE),
  TRAN_CMF_20         VARCHAR2(30 BYTE),
  LOT_ID              VARCHAR2(25 BYTE),
  SUBLOT_ID           VARCHAR2(30 BYTE),
  CRR_ID              VARCHAR2(20 BYTE),
  TRAN_USER_ID        VARCHAR2(20 BYTE),
  TRAN_COMMENT        VARCHAR2(400 BYTE),
  LAST_DOWN_TIME      DATE,
  LAST_DOWN_HIST_SEQ  NUMBER(10),
  HIST_START_SEQ      NUMBER(10),
  HIST_DEL_FLAG       CHAR(1 BYTE),
  HIST_DEL_TIME       DATE,
  HIST_DEL_USER_ID    VARCHAR2(20 BYTE),
  HIST_DEL_COMMENT    VARCHAR2(200 BYTE),
  END_DATE            DATE,
  EDC_DETAILS         VARCHAR2(12 BYTE),
  REPAIR_PRIOR        VARCHAR2(1 BYTE)
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RRASSRSHIS
ADD CONSTRAINT RRASSRSHIS_PK PRIMARY KEY
(
    FACTORY, RES_ID, SUBRES_ID, HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;


CREATE TABLE RRASSRSLOT
(
  FACTORY            VARCHAR2(10 BYTE)          DEFAULT (' ')                 NOT NULL,
  RES_ID             VARCHAR2(20 BYTE)          DEFAULT (' ')                 NOT NULL,
  SUBRES_ID          VARCHAR2(20 BYTE)          DEFAULT (' ')                 NOT NULL,
  LOT_ID             VARCHAR2(25 BYTE)          DEFAULT (' ')                 NOT NULL,
  SUBLOT_ID          VARCHAR2(30 BYTE)          DEFAULT (' ')                 NOT NULL,
  PARENTS_SUBRES_ID  VARCHAR2(20 BYTE),
  EVENT_ID           VARCHAR2(12 BYTE),
  TRAN_TIME          DATE,
  CREATE_USER_ID     VARCHAR2(20 BYTE),
  CREATE_TIME        DATE,
  UPDATE_USER_ID     VARCHAR2(20 BYTE),
  UPDATE_TIME        DATE
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RRASSRSLOT
ADD CONSTRAINT RRASSRSLOT_PK PRIMARY KEY
(
    FACTORY, 
    RES_ID, 
    SUBRES_ID, 
    LOT_ID, 
    SUBLOT_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;


CREATE TABLE RRASSRSLTH
(
  FACTORY            VARCHAR2(10 BYTE)          DEFAULT (' ')                 NOT NULL,
  RES_ID             VARCHAR2(20 BYTE)          DEFAULT (' ')                 NOT NULL,
  SUBRES_ID          VARCHAR2(20 BYTE)          DEFAULT (' ')                 NOT NULL,
  HIST_SEQ           NUMBER(10)                 DEFAULT (0)                   NOT NULL,
  LOT_ID             VARCHAR2(25 BYTE)          DEFAULT (' ')                 NOT NULL,
  SUBLOT_ID          VARCHAR2(30 BYTE)          DEFAULT (' ')                 NOT NULL,
  PARENTS_SUBRES_ID  VARCHAR2(20 BYTE),
  RES_HIST_SEQ       NUMBER(10),
  EVENT_ID           VARCHAR2(12 BYTE),
  TRAN_TIME          DATE,
  LOT_HIST_SEQ       NUMBER(10),
  SUBLOT_HIST_SEQ    NUMBER(10),
  MAT_ID             VARCHAR2(30 BYTE),
  MAT_VER            NUMBER(6),
  FLOW               VARCHAR2(20 BYTE),
  OPER               VARCHAR2(10 BYTE),
  LOT_TYPE           CHAR(1 BYTE),
  RWK_FLAG           CHAR(1 BYTE),
  QTY_1              NUMBER(10,3),
  QTY_2              NUMBER(10,3),
  QTY_3              NUMBER(10,3),
  HIST_DEL_FLAG      CHAR(1 BYTE)
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RRASSRSLTH
ADD CONSTRAINT RRASSRSLTH_PK PRIMARY KEY
(
    FACTORY, 
    RES_ID, 
    SUBRES_ID, 
    HIST_SEQ, 
    LOT_ID,
    SUBLOT_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;


CREATE TABLE REDCLOTDAT
(
  LOT_ID           VARCHAR2(25 BYTE)            DEFAULT (' ')                 NOT NULL,
  HIST_SEQ         NUMBER(10)                   DEFAULT (0)                   NOT NULL,
  COL_SEQ          NUMBER(10)                   DEFAULT (0)                   NOT NULL,
  TRAN_TIME        DATE,
  HIST_DEL_FLAG    VARCHAR2(1 BYTE),
  FACTORY          VARCHAR2(10 BYTE),
  MAT_ID           VARCHAR2(30 BYTE),
  MAT_VER          NUMBER(6),
  FLOW             VARCHAR2(20 BYTE),
  OPER             VARCHAR2(10 BYTE),
  MEAS_RES_ID      VARCHAR2(20 BYTE),
  PROC_FLOW        VARCHAR2(20 BYTE),
  PROC_OPER        VARCHAR2(10 BYTE),
  PROC_RES_ID      VARCHAR2(20 BYTE),
  RECIPE_ID        VARCHAR2(25 BYTE),
  RECIPE_VERSION   NUMBER(3),
  COL_SET_ID       VARCHAR2(25 BYTE),
  COL_SET_VERSION  NUMBER(3),
  CHAR_SEQ_NUM     NUMBER(6)                    DEFAULT (0)                   NOT NULL,
  CHAR_ID          VARCHAR2(25 BYTE),
  UNIT_SEQ_NUM     NUMBER(6)                    DEFAULT (0)                   NOT NULL,
  UNIT_ID          VARCHAR2(25 BYTE),
  VALUE_SEQ_NUM    NUMBER(6)                    DEFAULT (0)                   NOT NULL,
  VALUE_TYPE       VARCHAR2(1 BYTE),
  VALUE_COUNT      NUMBER(2),
  VALUE_1          VARCHAR2(25 BYTE),
  VALUE_2          VARCHAR2(25 BYTE),
  VALUE_3          VARCHAR2(25 BYTE),
  VALUE_4          VARCHAR2(25 BYTE),
  VALUE_5          VARCHAR2(25 BYTE),
  VALUE_6          VARCHAR2(25 BYTE),
  VALUE_7          VARCHAR2(25 BYTE),
  VALUE_8          VARCHAR2(25 BYTE),
  VALUE_9          VARCHAR2(25 BYTE),
  VALUE_10         VARCHAR2(25 BYTE),
  VALUE_11         VARCHAR2(25 BYTE),
  VALUE_12         VARCHAR2(25 BYTE),
  VALUE_13         VARCHAR2(25 BYTE),
  VALUE_14         VARCHAR2(25 BYTE),
  VALUE_15         VARCHAR2(25 BYTE),
  VALUE_16         VARCHAR2(25 BYTE),
  VALUE_17         VARCHAR2(25 BYTE),
  VALUE_18         VARCHAR2(25 BYTE),
  VALUE_19         VARCHAR2(25 BYTE),
  VALUE_20         VARCHAR2(25 BYTE),
  VALUE_21         VARCHAR2(25 BYTE),
  VALUE_22         VARCHAR2(25 BYTE),
  VALUE_23         VARCHAR2(25 BYTE),
  VALUE_24         VARCHAR2(25 BYTE),
  VALUE_25         VARCHAR2(25 BYTE),
  SAMPLE_COUNT     NUMBER(6),
  NOMINAL          VARCHAR2(25 BYTE),
  PROCESS_SIGMA    VARCHAR2(25 BYTE),
  SPEC_OUT_MASK    VARCHAR2(25 BYTE),
  CREATE_USER_ID   VARCHAR2(20 BYTE),
  CREATE_TIME      DATE,
  UPDATE_USER_ID   VARCHAR2(20 BYTE),
  UPDATE_TIME      DATE,
  DELETE_USER_ID   VARCHAR2(20 BYTE),
  DELETE_TIME      DATE,
  DEL_HIST_DATE    DATE
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE REDCLOTDAT 
ADD CONSTRAINT REDCLOTDAT_PK PRIMARY KEY
(LOT_ID, 
 HIST_SEQ, 
 CHAR_SEQ_NUM, 
 UNIT_SEQ_NUM, 
 VALUE_SEQ_NUM
) USING INDEX TABLESPACE REPORT_IDX_TS;

/* REDCRESDAT : EDC Resource Data Table */
CREATE TABLE REDCRESDAT
(
  FACTORY          VARCHAR2(10 BYTE)            DEFAULT (' ')                 NOT NULL,
  RES_ID           VARCHAR2(20 BYTE)            DEFAULT (' ')                 NOT NULL,
  SUBRES_ID        VARCHAR2(20 BYTE)            DEFAULT (' ')                 NOT NULL,
  HIST_SEQ         NUMBER(10)                   DEFAULT (0)                   NOT NULL,
  COL_SEQ          NUMBER(10)                   DEFAULT (0)                   NOT NULL,
  EVENT_ID         VARCHAR2(12 BYTE),
  TRAN_TIME        DATE,
  RECIPE_ID        VARCHAR2(25 BYTE),
  RECIPE_VERSION   NUMBER(3),
  HIST_DEL_FLAG    CHAR(1 BYTE),
  COL_SET_ID       VARCHAR2(25 BYTE),
  COL_SET_VERSION  NUMBER(3),
  CHAR_SEQ_NUM     NUMBER(6)                    DEFAULT (0)                   NOT NULL,
  CHAR_ID          VARCHAR2(25 BYTE),
  UNIT_SEQ_NUM     NUMBER(6)                    DEFAULT (0)                   NOT NULL,
  UNIT_ID          VARCHAR2(25 BYTE),
  VALUE_SEQ_NUM    NUMBER(6)                    DEFAULT (0)                   NOT NULL,
  VALUE_TYPE       CHAR(1 BYTE),
  VALUE_COUNT      NUMBER(2),
  VALUE_1          VARCHAR2(25 BYTE),
  VALUE_2          VARCHAR2(25 BYTE),
  VALUE_3          VARCHAR2(25 BYTE),
  VALUE_4          VARCHAR2(25 BYTE),
  VALUE_5          VARCHAR2(25 BYTE),
  VALUE_6          VARCHAR2(25 BYTE),
  VALUE_7          VARCHAR2(25 BYTE),
  VALUE_8          VARCHAR2(25 BYTE),
  VALUE_9          VARCHAR2(25 BYTE),
  VALUE_10         VARCHAR2(25 BYTE),
  VALUE_11         VARCHAR2(25 BYTE),
  VALUE_12         VARCHAR2(25 BYTE),
  VALUE_13         VARCHAR2(25 BYTE),
  VALUE_14         VARCHAR2(25 BYTE),
  VALUE_15         VARCHAR2(25 BYTE),
  VALUE_16         VARCHAR2(25 BYTE),
  VALUE_17         VARCHAR2(25 BYTE),
  VALUE_18         VARCHAR2(25 BYTE),
  VALUE_19         VARCHAR2(25 BYTE),
  VALUE_20         VARCHAR2(25 BYTE),
  VALUE_21         VARCHAR2(25 BYTE),
  VALUE_22         VARCHAR2(25 BYTE),
  VALUE_23         VARCHAR2(25 BYTE),
  VALUE_24         VARCHAR2(25 BYTE),
  VALUE_25         VARCHAR2(25 BYTE),
  SAMPLE_COUNT     NUMBER(6),
  NOMINAL          VARCHAR2(25 BYTE),
  PROCESS_SIGMA    VARCHAR2(25 BYTE),
  SPEC_OUT_MASK    VARCHAR2(25 BYTE),
  CREATE_USER_ID   VARCHAR2(20 BYTE),
  CREATE_TIME      DATE,
  UPDATE_USER_ID   VARCHAR2(20 BYTE),
  UPDATE_TIME      DATE,
  DELETE_USER_ID   VARCHAR2(20 BYTE),
  DELETE_TIME      DATE,
  DATE_CREATED     DATE,
  DATE_UPDATED     DATE
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE REDCRESDAT 
ADD CONSTRAINT REDCRESDAT_PK PRIMARY KEY
(FACTORY, 
 RES_ID, 
 SUBRES_ID, 
 HIST_SEQ, 
 CHAR_SEQ_NUM, 
 UNIT_SEQ_NUM, 
 VALUE_SEQ_NUM
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE TABLE RINVSUMDAT
(
  OPER_DATE     DATE                            NOT NULL,
  FACTORY       VARCHAR2(10 BYTE),
  PRODUCT_GRP   VARCHAR2(1 BYTE),
  MAT_ID        VARCHAR2(30 BYTE),
  MAT_VER       NUMBER(6),
  OPER          VARCHAR2(10 BYTE),
  OWNER_CODE    VARCHAR2(10 BYTE),
  RWK_FLAG      VARCHAR2(1 BYTE),
  HOLD_FLAG     VARCHAR2(1 BYTE),
  QTY_1         NUMBER(10,3),
  QTY_2         NUMBER(10,3),
  QTY_3         NUMBER(10,3),
  DATE_CREATED  DATE
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RINVSUMDAT 
ADD CONSTRAINT RINVSUMDAT_PK PRIMARY KEY
(
 OPER_DATE, 
 FACTORY, 
 PRODUCT_GRP, 
 MAT_ID, 
 MAT_VER, 
 OPER, 
 OWNER_CODE, 
 RWK_FLAG
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE TABLE RINVVALSUM
(
  INV_DATE         DATE                         NOT NULL,
  LOT_ID           VARCHAR2(25 BYTE)            NOT NULL,
  LOT_DESC         VARCHAR2(50 BYTE),
  FACTORY          VARCHAR2(10 BYTE),
  MAT_ID           VARCHAR2(30 BYTE),
  MAT_VER          NUMBER(6),
  FLOW             VARCHAR2(20 BYTE),
  FLOW_SEQ_NUM     NUMBER(6),
  OPER             VARCHAR2(10 BYTE),
  QTY_1            NUMBER(10,3),
  QTY_2            NUMBER(10,3),
  QTY_3            NUMBER(10,3),
  LOT_TYPE         VARCHAR2(1 BYTE),
  OWNER_CODE       VARCHAR2(10 BYTE),
  CREATE_CODE      VARCHAR2(10 BYTE),
  LOT_PRIORITY     VARCHAR2(1 BYTE),
  HOLD_FLAG        VARCHAR2(1 BYTE),
  HOLD_CODE        VARCHAR2(10 BYTE),
  OPER_IN_QTY_1    NUMBER(10,3),
  OPER_IN_QTY_2    NUMBER(10,3),
  OPER_IN_QTY_3    NUMBER(10,3),
  CREATE_QTY_1     NUMBER(10,3),
  CREATE_QTY_2     NUMBER(10,3),
  CREATE_QTY_3     NUMBER(10,3),
  START_QTY_1      NUMBER(10,3),
  START_QTY_2      NUMBER(10,3),
  START_QTY_3      NUMBER(10,3),
  INV_FLAG         VARCHAR2(1 BYTE),
  RWK_FLAG         VARCHAR2(1 BYTE),
  RWK_CODE         VARCHAR2(10 BYTE),
  RWK_COUNT        NUMBER(6),
  START_FLAG       VARCHAR2(1 BYTE),
  START_TIME       DATE,
  START_RES_ID     VARCHAR2(20 BYTE),
  END_FLAG         VARCHAR2(1 BYTE),
  END_TIME         DATE,
  END_RES_ID       VARCHAR2(20 BYTE),
  CREATE_TIME      DATE,
  FAC_IN_TIME      DATE,
  FLOW_IN_TIME     DATE,
  OPER_IN_TIME     DATE,
  LOT_CMF_1        VARCHAR2(30 BYTE),
  LOT_CMF_2        VARCHAR2(30 BYTE),
  LOT_CMF_3        VARCHAR2(30 BYTE),
  LOT_CMF_4        VARCHAR2(30 BYTE),
  LOT_CMF_5        VARCHAR2(30 BYTE),
  LOT_CMF_6        VARCHAR2(30 BYTE),
  LOT_CMF_7        VARCHAR2(30 BYTE),
  LOT_CMF_8        VARCHAR2(30 BYTE),
  LOT_CMF_9        VARCHAR2(30 BYTE),
  LOT_CMF_10       VARCHAR2(30 BYTE),
  LOT_CMF_11       VARCHAR2(30 BYTE),
  LOT_CMF_12       VARCHAR2(30 BYTE),
  LOT_CMF_13       VARCHAR2(30 BYTE),
  LOT_CMF_14       VARCHAR2(30 BYTE),
  LOT_CMF_15       VARCHAR2(30 BYTE),
  LOT_CMF_16       VARCHAR2(30 BYTE),
  LOT_CMF_17       VARCHAR2(30 BYTE),
  LOT_CMF_18       VARCHAR2(30 BYTE),
  LOT_CMF_19       VARCHAR2(30 BYTE),
  LOT_CMF_20       VARCHAR2(30 BYTE),
  LAST_TRAN_CODE   VARCHAR2(12 BYTE),
  LAST_TRAN_TIME   DATE,
  PRODUCT_GRP      VARCHAR2(1 BYTE),
  UNIT_1           VARCHAR2(10 BYTE),
  UNIT_2           VARCHAR2(10 BYTE),
  UNIT_3           VARCHAR2(10 BYTE),
  YIELD_WORK_CELL  VARCHAR2(30 BYTE),
  YIELD_SECTION    VARCHAR2(30 BYTE)
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RINVVALSUM 
ADD CONSTRAINT RINVVALSUM_PK PRIMARY KEY
(
 INV_DATE, 
 LOT_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE TABLE RINVVALUES
(
  INV_DATE         DATE                         NOT NULL,
  LOT_ID           VARCHAR2(25 BYTE)            NOT NULL,
  LOT_DESC         VARCHAR2(50 BYTE),
  FACTORY          VARCHAR2(10 BYTE),
  MAT_ID           VARCHAR2(30 BYTE),
  MAT_VER          NUMBER(6),
  FLOW             VARCHAR2(20 BYTE),
  FLOW_SEQ_NUM     NUMBER(6),
  OPER             VARCHAR2(10 BYTE),
  QTY_1            NUMBER(10,3),
  QTY_2            NUMBER(10,3),
  QTY_3            NUMBER(10,3),
  LOT_TYPE         VARCHAR2(1 BYTE),
  OWNER_CODE       VARCHAR2(10 BYTE),
  CREATE_CODE      VARCHAR2(10 BYTE),
  LOT_PRIORITY     VARCHAR2(1 BYTE),
  HOLD_FLAG        VARCHAR2(1 BYTE),
  HOLD_CODE        VARCHAR2(10 BYTE),
  OPER_IN_QTY_1    NUMBER(10,3),
  OPER_IN_QTY_2    NUMBER(10,3),
  OPER_IN_QTY_3    NUMBER(10,3),
  CREATE_QTY_1     NUMBER(10,3),
  CREATE_QTY_2     NUMBER(10,3),
  CREATE_QTY_3     NUMBER(10,3),
  START_QTY_1      NUMBER(10,3),
  START_QTY_2      NUMBER(10,3),
  START_QTY_3      NUMBER(10,3),
  INV_FLAG         VARCHAR2(1 BYTE),
  RWK_FLAG         VARCHAR2(1 BYTE),
  RWK_CODE         VARCHAR2(10 BYTE),
  RWK_COUNT        NUMBER(6),
  START_FLAG       VARCHAR2(1 BYTE),
  START_TIME       DATE,
  START_RES_ID     VARCHAR2(20 BYTE),
  END_FLAG         VARCHAR2(1 BYTE),
  END_TIME         DATE,
  END_RES_ID       VARCHAR2(20 BYTE),
  CREATE_TIME      DATE,
  FAC_IN_TIME      DATE,
  FLOW_IN_TIME     DATE,
  OPER_IN_TIME     DATE,
  LOT_CMF_1        VARCHAR2(30 BYTE),
  LOT_CMF_2        VARCHAR2(30 BYTE),
  LOT_CMF_3        VARCHAR2(30 BYTE),
  LOT_CMF_4        VARCHAR2(30 BYTE),
  LOT_CMF_5        VARCHAR2(30 BYTE),
  LOT_CMF_6        VARCHAR2(30 BYTE),
  LOT_CMF_7        VARCHAR2(30 BYTE),
  LOT_CMF_8        VARCHAR2(30 BYTE),
  LOT_CMF_9        VARCHAR2(30 BYTE),
  LOT_CMF_10       VARCHAR2(30 BYTE),
  LOT_CMF_11       VARCHAR2(30 BYTE),
  LOT_CMF_12       VARCHAR2(30 BYTE),
  LOT_CMF_13       VARCHAR2(30 BYTE),
  LOT_CMF_14       VARCHAR2(30 BYTE),
  LOT_CMF_15       VARCHAR2(30 BYTE),
  LOT_CMF_16       VARCHAR2(30 BYTE),
  LOT_CMF_17       VARCHAR2(30 BYTE),
  LOT_CMF_18       VARCHAR2(30 BYTE),
  LOT_CMF_19       VARCHAR2(30 BYTE),
  LOT_CMF_20       VARCHAR2(30 BYTE),
  LAST_TRAN_CODE   VARCHAR2(12 BYTE),
  LAST_TRAN_TIME   DATE,
  PRODUCT_GRP      VARCHAR2(1 BYTE),
  UNIT_1           VARCHAR2(10 BYTE),
  UNIT_2           VARCHAR2(10 BYTE),
  UNIT_3           VARCHAR2(10 BYTE),
  YIELD_WORK_CELL  VARCHAR2(30 BYTE),
  YIELD_SECTION    VARCHAR2(30 BYTE)
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RINVVALUES 
ADD CONSTRAINT RINVVALUES_PK PRIMARY KEY
(
 INV_DATE, 
 LOT_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE TABLE RRASCRRDEF
(
  CRR_ID               VARCHAR2(20 BYTE)        DEFAULT (' ')                 NOT NULL,
  CRR_DESC             VARCHAR2(200 BYTE),
  FACTORY              VARCHAR2(10 BYTE),
  CRR_GROUP            VARCHAR2(20 BYTE),
  CRR_STATUS           VARCHAR2(10 BYTE),
  CRR_STATUS_FLAG      VARCHAR2(1 BYTE),
  CRR_TYPE1            VARCHAR2(10 BYTE),
  CRR_TYPE2            VARCHAR2(10 BYTE),
  CRR_TYPE3            VARCHAR2(10 BYTE),
  CRR_MATERIAL         VARCHAR2(10 BYTE),
  CRR_SIZE             NUMBER(6),
  USE_AREA_ID          VARCHAR2(20 BYTE),
  USE_SUB_AREA_ID      VARCHAR2(10 BYTE),
  USE_RES_ID           VARCHAR2(20 BYTE),
  USAGE_LIMIT_COUNT    NUMBER(6),
  USAGE_LIMIT_TIME     NUMBER(6),
  USAGE_COUNT          NUMBER(6),
  CLEAN_LIMIT_COUNT    NUMBER(6),
  CLEAN_COUNT          NUMBER(6),
  RES_ID               VARCHAR2(20 BYTE),
  SUBRES_ID            VARCHAR2(20 BYTE),
  PORT_ID              VARCHAR2(10 BYTE),
  LOCATION_1           VARCHAR2(20 BYTE),
  LOCATION_2           VARCHAR2(20 BYTE),
  LOCATION_3           VARCHAR2(20 BYTE),
  LOCATION_4           VARCHAR2(20 BYTE),
  LOCATION_5           VARCHAR2(20 BYTE),
  OLD_RES_ID           VARCHAR2(20 BYTE),
  OLD_SUBRES_ID        VARCHAR2(20 BYTE),
  OLD_PORT_ID          VARCHAR2(10 BYTE),
  OLD_LOCATION_1       VARCHAR2(20 BYTE),
  OLD_LOCATION_2       VARCHAR2(20 BYTE),
  OLD_LOCATION_3       VARCHAR2(20 BYTE),
  OLD_LOCATION_4       VARCHAR2(20 BYTE),
  OLD_LOCATION_5       VARCHAR2(20 BYTE),
  NEED_CLEAN_FLAG      CHAR(1),
  FINISH_CLEAN_FLAG    VARCHAR2(1 BYTE),
  LAST_CLEAN_TIME      DATE,
  LOT_ID               VARCHAR2(25 BYTE),
  LOT_HIST_SEQ         NUMBER(10),
  QTY_1                NUMBER(12,3),
  QTY_2                NUMBER(12,3),
  QTY_3                NUMBER(12,3),
  TBL_SLOT             VARCHAR2(100 BYTE),
  MOVE_FLAG            VARCHAR2(1 BYTE),
  EMPTY_FLAG           VARCHAR2(1 BYTE),
  STOCK_IN_TIME        DATE,
  PLAN_TERMINATE_TIME  DATE,
  CRR_CMF_1            VARCHAR2(30 BYTE),
  CRR_CMF_2            VARCHAR2(30 BYTE),
  CRR_CMF_3            VARCHAR2(30 BYTE),
  CRR_CMF_4            VARCHAR2(30 BYTE),
  CRR_CMF_5            VARCHAR2(30 BYTE),
  CRR_CMF_6            VARCHAR2(30 BYTE),
  CRR_CMF_7            VARCHAR2(30 BYTE),
  CRR_CMF_8            VARCHAR2(30 BYTE),
  CRR_CMF_9            VARCHAR2(30 BYTE),
  CRR_CMF_10           VARCHAR2(30 BYTE),
  CRR_CMF_11           VARCHAR2(30 BYTE),
  CRR_CMF_12           VARCHAR2(30 BYTE),
  CRR_CMF_13           VARCHAR2(30 BYTE),
  CRR_CMF_14           VARCHAR2(30 BYTE),
  CRR_CMF_15           VARCHAR2(30 BYTE),
  CRR_CMF_16           VARCHAR2(30 BYTE),
  CRR_CMF_17           VARCHAR2(30 BYTE),
  CRR_CMF_18           VARCHAR2(30 BYTE),
  CRR_CMF_19           VARCHAR2(30 BYTE),
  CRR_CMF_20           VARCHAR2(30 BYTE),
  LAST_HIST_SEQ        NUMBER(10),
  LAST_TRAN_TIME       DATE,
  LAST_TRAN_CODE       VARCHAR2(12 BYTE),
  CREATE_USER_ID       VARCHAR2(20 BYTE),
  CREATE_TIME          DATE,
  UPDATE_USER_ID       VARCHAR2(20 BYTE),
  UPDATE_TIME          DATE,
  USAGE_LIMIT_ALARM    VARCHAR2(20 BYTE),
  CLEAN_LIMIT_ALARM    VARCHAR2(20 BYTE)
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RRASCRRDEF 
ADD CONSTRAINT RRASCRRDEF_PK PRIMARY KEY
(
 CRR_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE TABLE RRASCRRHIS
(
  CRR_ID             VARCHAR2(20 BYTE)          DEFAULT (' ')                 NOT NULL,
  HIST_SEQ           NUMBER(10)                 DEFAULT (0)                   NOT NULL,
  TRAN_TIME          DATE,
  SYS_TRAN_TIME      DATE,
  TRAN_CODE          VARCHAR2(12 BYTE),
  FACTORY            VARCHAR2(10 BYTE),
  CRR_STATUS         VARCHAR2(10 BYTE),
  CRR_STATUS_FLAG    VARCHAR2(1 BYTE),
  USAGE_COUNT        NUMBER(6),
  CLEAN_COUNT        NUMBER(6),
  RES_ID             VARCHAR2(20 BYTE),
  SUBRES_ID          VARCHAR2(20 BYTE),
  PORT_ID            VARCHAR2(10 BYTE),
  LOCATION_1         VARCHAR2(20 BYTE),
  LOCATION_2         VARCHAR2(20 BYTE),
  LOCATION_3         VARCHAR2(20 BYTE),
  LOCATION_4         VARCHAR2(20 BYTE),
  LOCATION_5         VARCHAR2(20 BYTE),
  NEED_CLEAN_FLAG      CHAR(1),
  FINISH_CLEAN_FLAG  VARCHAR2(1 BYTE),
  LAST_CLEAN_TIME    DATE,
  LOT_ID             VARCHAR2(25 BYTE),
  LOT_HIST_SEQ       NUMBER(10),
  QTY_1              NUMBER(12,3),
  QTY_2              NUMBER(12,3),
  QTY_3              NUMBER(12,3),
  TBL_SLOT           VARCHAR2(100 BYTE),
  MOVE_FLAG          VARCHAR2(1 BYTE),
  EMPTY_FLAG         VARCHAR2(1 BYTE),
  STOCK_IN_TIME      DATE,
  TRAN_CMF_1         VARCHAR2(30 BYTE),
  TRAN_CMF_2         VARCHAR2(30 BYTE),
  TRAN_CMF_3         VARCHAR2(30 BYTE),
  TRAN_CMF_4         VARCHAR2(30 BYTE),
  TRAN_CMF_5         VARCHAR2(30 BYTE),
  TRAN_CMF_6         VARCHAR2(30 BYTE),
  TRAN_CMF_7         VARCHAR2(30 BYTE),
  TRAN_CMF_8         VARCHAR2(30 BYTE),
  TRAN_CMF_9         VARCHAR2(30 BYTE),
  TRAN_CMF_10        VARCHAR2(30 BYTE),
  TRAN_CMF_11        VARCHAR2(30 BYTE),
  TRAN_CMF_12        VARCHAR2(30 BYTE),
  TRAN_CMF_13        VARCHAR2(30 BYTE),
  TRAN_CMF_14        VARCHAR2(30 BYTE),
  TRAN_CMF_15        VARCHAR2(30 BYTE),
  TRAN_CMF_16        VARCHAR2(30 BYTE),
  TRAN_CMF_17        VARCHAR2(30 BYTE),
  TRAN_CMF_18        VARCHAR2(30 BYTE),
  TRAN_CMF_19        VARCHAR2(30 BYTE),
  TRAN_CMF_20        VARCHAR2(30 BYTE),
  TRAN_USER_ID       VARCHAR2(20 BYTE),
  TRAN_COMMENT       VARCHAR2(400 BYTE)
) TABLESPACE REPORT_DATA_TS;


ALTER TABLE RRASCRRHIS 
ADD CONSTRAINT RRASCRRHIS_PK PRIMARY KEY
(
 CRR_ID, 
 HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;


CREATE TABLE RRWKCLSHIS
(
  LOT_ID                VARCHAR2(25 BYTE)       DEFAULT (' ')                 NOT NULL,
  HIST_SEQ              NUMBER(10)              DEFAULT (0)                   NOT NULL,
  FACTORY               VARCHAR2(10 BYTE)       DEFAULT (' ')                 NOT NULL,
  C_WORKCELL_REWORK     CHAR(1 BYTE)            DEFAULT (' ')                 NOT NULL,
  CYCLETIME_WORKCELL    VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  F_CYCLETIME_WORKCELL  VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  C_SECTION_REWORK      CHAR(1 BYTE)            DEFAULT (' ')                 NOT NULL,
  CYCLETIME_SECTION     VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  F_CYCLETIME_SECTION   VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  C_LINE_REWORK         CHAR(1 BYTE)            DEFAULT (' ')                 NOT NULL,
  CYCLETIME_LINE        VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  F_CYCLETIME_LINE      VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  Y_WORKCELL_REWORK     CHAR(1 BYTE)            DEFAULT (' ')                 NOT NULL,
  YIELD_WORKCELL        VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  F_YIELD_WORKCELL      VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  Y_SECTION_REWORK      CHAR(1 BYTE)            DEFAULT (' ')                 NOT NULL,
  YIELD_SECTION         VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  F_YIELD_SECTION       VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  Y_LINE_REWORK         CHAR(1 BYTE)            DEFAULT (' ')                 NOT NULL,
  YIELD_LINE            VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  F_YIELD_LINE          VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  REWORK_DIRECTION      CHAR(1 BYTE)            DEFAULT (' ')                 NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RRWKCLSHIS 
ADD CONSTRAINT RRWKCLSHIS_PK PRIMARY KEY
(
 LOT_ID, 
 HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE TABLE RRWKLOTSTS
(
  LOT_ID                VARCHAR2(25 BYTE)       DEFAULT (' ')                 NOT NULL,
  FACTORY               VARCHAR2(10 BYTE)       DEFAULT (' ')                 NOT NULL,
  C_WORKCELL_REWORK     CHAR(1 BYTE)            DEFAULT (' ')                 NOT NULL,
  CYCLETIME_WORKCELL    VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  F_CYCLETIME_WORKCELL  VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  C_SECTION_REWORK      CHAR(1 BYTE)            DEFAULT (' ')                 NOT NULL,
  CYCLETIME_SECTION     VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  F_CYCLETIME_SECTION   VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  C_LINE_REWORK         CHAR(1 BYTE)            DEFAULT (' ')                 NOT NULL,
  CYCLETIME_LINE        VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  F_CYCLETIME_LINE      VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  Y_WORKCELL_REWORK     CHAR(1 BYTE)            DEFAULT (' ')                 NOT NULL,
  YIELD_WORKCELL        VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  F_YIELD_WORKCELL      VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  Y_SECTION_REWORK      CHAR(1 BYTE)            DEFAULT (' ')                 NOT NULL,
  YIELD_SECTION         VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  F_YIELD_SECTION       VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  Y_LINE_REWORK         CHAR(1 BYTE)            DEFAULT (' ')                 NOT NULL,
  YIELD_LINE            VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  F_YIELD_LINE          VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL,
  REWORK_DIRECTION      CHAR(1 BYTE)            DEFAULT (' ')                 NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RRWKLOTSTS 
ADD CONSTRAINT RRWKLOTSTS_PK PRIMARY KEY
(
 LOT_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;





CREATE TABLE RSUMLINCYC
(
  LOT_ID                 VARCHAR2(25 BYTE)      DEFAULT (' ')                 NOT NULL,
  HIST_SEQ               NUMBER(10)             DEFAULT (0)                   NOT NULL,
  TRAN_TIME              DATE,
  PARENT_LOT_ID          VARCHAR2(30 BYTE),
  CYCLETIME_LINE         VARCHAR2(30 BYTE),
  CYCLETIME_SECTION      VARCHAR2(30 BYTE),
  OPER                   VARCHAR2(10 BYTE),
  RWK_FLAG               VARCHAR2(1 BYTE),
  OWNER_CODE             VARCHAR2(10 BYTE),
  MAT_ID                 VARCHAR2(30 BYTE),
  MAT_VER                NUMBER(6),
  REPORTABLE_YN          VARCHAR2(1 BYTE),
  LINE_START_TIME        DATE,
  LINE_CYCLETIME         NUMBER(12,6),
  LINE_PROC_TIME         NUMBER(12,6),
  LINE_WAIT_TIME         NUMBER(12,6),
  LINE_STORE_TIME        NUMBER(12,6),
  CYCLETIME_SECTION_NEW  VARCHAR2(30 BYTE),
  FACTORY                VARCHAR2(10 BYTE),
  DATE_CREATE            DATE,
  DATE_UPDATE            DATE
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RSUMLINCYC 
ADD CONSTRAINT RSUMLINCYC_PK PRIMARY KEY
(
 LOT_ID, 
 HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;


CREATE TABLE RSUMLINMOV
(
  LOT_ID              VARCHAR2(25 BYTE)         DEFAULT (' ')                 NOT NULL,
  HIST_SEQ            NUMBER(10)                DEFAULT (0)                   NOT NULL,
  TRAN_TIME           DATE,
  PARENT_LOT_ID       VARCHAR2(30 BYTE),
  YIELD_LINE          VARCHAR2(30 BYTE),
  YIELD_SECTION       VARCHAR2(30 BYTE),
  OPER                VARCHAR2(10 BYTE),
  RWK_FLAG            VARCHAR2(1 BYTE),
  OWNER_CODE          VARCHAR2(10 BYTE),
  MAT_ID              VARCHAR2(30 BYTE),
  MAT_VER             NUMBER(6),
  REPORTABLE_YN       VARCHAR2(1 BYTE),
  LINE_END_QTY_1      NUMBER(10,3),
  LINE_END_QTY_2      NUMBER(10,3),
  LINE_END_QTY_3      NUMBER(10,3),
  UNIT_1              VARCHAR2(10 BYTE),
  UNIT_2              VARCHAR2(10 BYTE),
  UNIT_3              VARCHAR2(10 BYTE),
  CALC_LINE_MVIN_QTY  NUMBER(12,6),
  LINE_END_QTY        NUMBER(10,3),
  UNIT                VARCHAR2(10 BYTE),
  CALC_LINE_YIELD     NUMBER(12,6),
  YIELD_SECTION_NEW   VARCHAR2(30 BYTE),
  FACTORY             VARCHAR2(10 BYTE),
  NONPROD_MVOU_QTY    NUMBER(10,3),
  NONPROD_MVIN_QTY    NUMBER(10,3),
  LINE_DIRECTION      CHAR(1 BYTE),
  DATE_CREATE         DATE,
  DATE_UPDATE         DATE,
  COMPONENT_FLAG      VARCHAR2(1 BYTE)
) TABLESPACE REPORT_DATA_TS;


ALTER TABLE RSUMLINMOV 
ADD CONSTRAINT RSUMLINMOV_PK PRIMARY KEY
(
 LOT_ID, 
 HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;


CREATE TABLE RSUMSECCYC
(
  LOT_ID                 VARCHAR2(25 BYTE)      DEFAULT (' ')                 NOT NULL,
  HIST_SEQ               NUMBER(10)             DEFAULT (0)                   NOT NULL,
  TRAN_TIME              DATE,
  PARENT_LOT_ID          VARCHAR2(30 BYTE),
  CYCLETIME_SECTION      VARCHAR2(30 BYTE),
  OPER                   VARCHAR2(10 BYTE),
  RWK_FLAG               VARCHAR2(1 BYTE),
  OWNER_CODE             VARCHAR2(10 BYTE),
  MAT_ID                 VARCHAR2(30 BYTE),
  MAT_VER                NUMBER(6),
  REPORTABLE_YN          VARCHAR2(1 BYTE),
  SECTION_START_TIME     DATE,
  SECTION_CYCLETIME      NUMBER(12,6),
  SECTION_PROC_TIME      NUMBER(12,6),
  SECTION_WAIT_TIME      NUMBER(12,6),
  SECTION_STORE_TIME     NUMBER(12,6),
  CYCLETIME_SECTION_NEW  VARCHAR2(30 BYTE),
  FACTORY                VARCHAR2(10 BYTE),
  DATE_CREATE            DATE,
  DATE_UPDATE            DATE
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RSUMSECCYC 
ADD CONSTRAINT RSUMSECCYC_PK PRIMARY KEY
(
 LOT_ID,
 HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE TABLE RSUMSECMOV
(
  LOT_ID                 VARCHAR2(25 BYTE)      DEFAULT (' ')                 NOT NULL,
  HIST_SEQ               NUMBER(10)             DEFAULT (0)                   NOT NULL,
  TRAN_TIME              DATE,
  PARENT_LOT_ID          VARCHAR2(30 BYTE),
  YIELD_SECTION          VARCHAR2(30 BYTE),
  OPER                   VARCHAR2(10 BYTE),
  RWK_FLAG               VARCHAR2(1 BYTE),
  OWNER_CODE             VARCHAR2(10 BYTE),
  MAT_ID                 VARCHAR2(30 BYTE),
  MAT_VER                NUMBER(6),
  REPORTABLE_YN          VARCHAR2(1 BYTE),
  SECTION_END_QTY_1      NUMBER(10,3),
  SECTION_END_QTY_2      NUMBER(10,3),
  SECTION_END_QTY_3      NUMBER(10,3),
  UNIT_1              	 VARCHAR2(10 BYTE),
  UNIT_2              	 VARCHAR2(10 BYTE),
  UNIT_3              	 VARCHAR2(10 BYTE),
  CALC_SECTION_MVIN_QTY  NUMBER(12,6),
  SECTION_END_QTY      	 NUMBER(10,3),
  UNIT                	 VARCHAR2(10 BYTE),
  CALC_SECTION_YIELD     NUMBER(12,6),
  YIELD_SECTION_NEW      VARCHAR2(30 BYTE),
  FACTORY                VARCHAR2(10 BYTE),
  NONPROD_MVOU_QTY       NUMBER(10,3),
  NONPROD_MVIN_QTY       NUMBER(10,3),
  SECTION_DIRECTION      VARCHAR2(1 BYTE),
  DATE_CREATE            DATE,
  DATE_UPDATE            DATE
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RSUMSECMOV 
ADD CONSTRAINT RSUMSECMOV_PK PRIMARY KEY
(
 LOT_ID, 
 HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;


CREATE TABLE RSUMWRKCYC
(
  LOT_ID                  VARCHAR2(25 BYTE)     DEFAULT (' ')                 NOT NULL,
  HIST_SEQ                NUMBER(10)            DEFAULT (0)                   NOT NULL,
  TRAN_TIME               DATE,
  PARENT_LOT_ID           VARCHAR2(30 BYTE),
  CYCLETIME_WORKCELL      VARCHAR2(30 BYTE),
  OPER                    VARCHAR2(10 BYTE),
  RWK_FLAG                VARCHAR2(1 BYTE),
  OWNER_CODE              VARCHAR2(10 BYTE),
  MAT_ID                  VARCHAR2(30 BYTE),
  MAT_VER                 NUMBER(6),
  REPORTABLE_YN           VARCHAR2(1 BYTE),
  WC_START_TIME           DATE,
  WC_CYCLETIME            NUMBER(12,6),
  WC_PROC_TIME            NUMBER(12,6),
  WC_WAIT_TIME            NUMBER(12,6),
  WC_STORE_TIME           NUMBER(12,6),
  CYCLETIME_WORKCELL_NEW  VARCHAR2(30 BYTE),
  FACTORY                 VARCHAR2(10 BYTE),
  DATE_CREATE             DATE,
  DATE_UPDATE             DATE
) TABLESPACE REPORT_DATA_TS;


ALTER TABLE RSUMWRKCYC 
ADD CONSTRAINT RSUMWRKCYC_PK PRIMARY KEY
(
 LOT_ID, 
 HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE TABLE RSUMWRKMOV
(
  LOT_ID              VARCHAR2(25 BYTE)         DEFAULT (' ')                 NOT NULL,
  HIST_SEQ            NUMBER(10)                DEFAULT (0)                   NOT NULL,
  RWK_FLAG            VARCHAR2(1 BYTE)          DEFAULT (' ')                 NOT NULL,
  TRAN_TIME           DATE                      NOT NULL,
  PARENT_LOT_ID       VARCHAR2(30 BYTE),
  YIELD_WORKCELL      VARCHAR2(30 BYTE),
  OPER                VARCHAR2(10 BYTE),
  OWNER_CODE          VARCHAR2(10 BYTE),
  MAT_ID              VARCHAR2(30 BYTE),
  MAT_VER             NUMBER(6),
  REPORTABLE_YN       VARCHAR2(1 BYTE),
  WC_END_QTY_1        NUMBER(10,3),
  WC_END_QTY_2        NUMBER(10,3),
  WC_END_QTY_3        NUMBER(10,3),
  UNIT_1              VARCHAR2(10 BYTE),
  UNIT_2              VARCHAR2(10 BYTE),
  UNIT_3              VARCHAR2(10 BYTE),
  CALC_WC_MVIN_QTY    NUMBER(12,6),
  WC_END_QTY          NUMBER(10,3),
  UNIT                VARCHAR2(10 BYTE),
  CALC_WC_YIELD       NUMBER(12,6),
  YIELD_WORKCELL_NEW  VARCHAR2(30 BYTE),
  FACTORY             VARCHAR2(10 BYTE),
  NONPROD_MVOU_QTY    NUMBER(10,3),
  NONPROD_MVIN_QTY    NUMBER(10,3),
  WC_DIRECTION        VARCHAR2(1 BYTE),
  DATE_CREATE         DATE,
  DATE_UPDATE         DATE
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RSUMWRKMOV 
ADD CONSTRAINT RSUMWRKMOV_PK PRIMARY KEY
(
 LOT_ID, 
 HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;


CREATE TABLE RTMPDSMHIS
(
  LOT_ID          VARCHAR2(25 BYTE)             DEFAULT (' ')                 NOT NULL,
  HIST_SEQ        NUMBER(10)                    DEFAULT (0)                   NOT NULL,
  PERIOD_TYPE     CHAR(1 BYTE)                  DEFAULT (' ')                 NOT NULL,
  PERIOD_NAME     VARCHAR2(30 BYTE)             DEFAULT (' ')                 NOT NULL,
  SUBLOT_ID       VARCHAR2(30 BYTE)             DEFAULT (' ')                 NOT NULL,
  FROM_TO_LOT_ID  VARCHAR2(25 BYTE)             DEFAULT (' ')                 NOT NULL,
  OPER            VARCHAR2(10 BYTE)             DEFAULT (' ')                 NOT NULL,
  TRAN_TIME       VARCHAR2(14 BYTE)             DEFAULT (' ')                 NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RTMPDSMHIS 
ADD CONSTRAINT RTMPDSMHIS_PK PRIMARY KEY
(
 LOT_ID, 
 HIST_SEQ, 
 PERIOD_TYPE, 
 PERIOD_NAME, 
 SUBLOT_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE TABLE RWIPLOTCVR
(
  LOT_ID         VARCHAR2(25 BYTE)              DEFAULT (' ')                 NOT NULL,
  HIST_SEQ       NUMBER(10)                     DEFAULT (0)                   NOT NULL,
  TRAN_TIME      DATE,
  SYS_TRAN_TIME  DATE,
  TRANS_TYPE     VARCHAR2(1 BYTE),
  FACTORY        VARCHAR2(10 BYTE),
  OPER           VARCHAR2(10 BYTE),
  MAT_ID         VARCHAR2(30 BYTE),
  MAT_VER        NUMBER(6),
  OWNER_CODE     VARCHAR2(12 BYTE),
  CV_CODE        VARCHAR2(12 BYTE),
  UNIT_1         VARCHAR2(10 BYTE),
  UNIT_2         VARCHAR2(10 BYTE),
  UNIT_3         VARCHAR2(10 BYTE),
  QTY_1          NUMBER(10,3),
  QTY_2          NUMBER(10,3),
  QTY_3          NUMBER(10,3),
  OLD_QTY_1      NUMBER(10,3),
  OLD_QTY_2      NUMBER(10,3),
  OLD_QTY_3      NUMBER(10,3),
  END_RES_ID     VARCHAR2(20),
  LOT_DEL_CODE   VARCHAR2(10 BYTE),
  HIST_DEL_FLAG  VARCHAR2(1 BYTE),
  HIST_DEL_TIME  DATE,
  DATE_CREATED   DATE,
  DATE_UPDATED   DATE
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPLOTCVR 
ADD CONSTRAINT RWIPLOTCVR_PK PRIMARY KEY
(
 LOT_ID, 
 HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE TABLE RWIPLOTSPM
(
  LOT_ID                VARCHAR2(25 BYTE)       DEFAULT (' ')                 NOT NULL,
  HIST_SEQ              NUMBER(10)              DEFAULT (0)                   NOT NULL,
  TRAN_TIME             DATE,
  HIST_DEL_FLAG         VARCHAR2(1 BYTE),
  FACTORY               VARCHAR2(10 BYTE),
  MAT_ID                VARCHAR2(30 BYTE),
  MAT_VER               NUMBER(6),
  FLOW                  VARCHAR2(20 BYTE),
  FLOW_SEQ_NUM          NUMBER(6),
  OPER                  VARCHAR2(10 BYTE),
  FROM_TO_FLAG          VARCHAR2(1 BYTE),
  FROM_TO_LOT_ID        VARCHAR2(25 BYTE),
  FROM_TO_MAT_ID        VARCHAR2(30 BYTE),
  FROM_TO_MAT_VER       NUMBER(6),
  FROM_TO_FLOW          VARCHAR2(20 BYTE),
  FROM_TO_FLOW_SEQ_NUM  NUMBER(6),
  FROM_TO_OPER          VARCHAR2(10 BYTE),
  FROM_TO_QTY_1         NUMBER(10,3),
  FROM_TO_QTY_2         NUMBER(10,3),
  FROM_TO_QTY_3         NUMBER(10,3),
  TRAN_CODE             VARCHAR2(12 BYTE),
  HIST_DEL_TIME         DATE,
  FROM_TO_OLD_QTY_1     NUMBER(10,3),
  FROM_TO_OLD_QTY_2     NUMBER(10,3),
  FROM_TO_OLD_QTY_3     NUMBER(10,3),
  UNIT_1         			  VARCHAR2(20 BYTE),
  UNIT_2         			  VARCHAR2(20 BYTE),
  UNIT_3         			  VARCHAR2(20 BYTE)
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPLOTSPM 
ADD CONSTRAINT RWIPLOTSPM_PK PRIMARY KEY
(
 LOT_ID, 
 HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE TABLE RWIPLOTTXT
(
  LOT_ID         VARCHAR2(25 BYTE)              DEFAULT (' ')                 NOT NULL,
  HIST_SEQ       NUMBER(10)                     DEFAULT (0)                   NOT NULL,
  TRAN_TIME      DATE,
  SYS_TRAN_TIME  DATE,
  TRAN_CODE      VARCHAR2(12 BYTE),
  MAT_ID         VARCHAR2(30 BYTE),
  MAT_VER        NUMBER(6),
  FACTORY        VARCHAR2(10 BYTE),
  OPER           VARCHAR2(10 BYTE),
  TRAN_COMMENT   VARCHAR2(400 BYTE),
  TRAN_USER_ID   VARCHAR2(20 BYTE),
  HIST_DEL_FLAG  VARCHAR2(1 BYTE),
  HIST_DEL_TIME  DATE,
  TRAN_CMF_1     VARCHAR2(30 BYTE),
  TRAN_CMF_2     VARCHAR2(30 BYTE),
  TRAN_CMF_3     VARCHAR2(30 BYTE),
  TRAN_CMF_4     VARCHAR2(30 BYTE),
  TRAN_CMF_5     VARCHAR2(30 BYTE)
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPLOTTXT 
ADD CONSTRAINT RWIPLOTTXT_PK PRIMARY KEY
(
 LOT_ID, 
 HIST_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE TABLE RWIPPLTSTS
(
  LOT_ID            VARCHAR2(25 BYTE)           DEFAULT (' ')                 NOT NULL,
  LOT_DEL_FLAG      VARCHAR2(1 BYTE),
  PRODUCT_GRP       VARCHAR2(1 BYTE),
  ORIG_PRODUCT      VARCHAR2(30 BYTE),
  ORIG_MAT_ID       VARCHAR2(30 BYTE),
  ORIG_MAT_VER      NUMBER(6),
  ORIG_OWNER_CODE   VARCHAR2(10 BYTE),
  ORIG_OPER         VARCHAR2(10 BYTE),
  ORIG_CREATE_CODE  VARCHAR2(10 BYTE),
  CREATE_TIME       DATE,
  CREATE_QTY_1      NUMBER(10,3),
  CREATE_QTY_2      NUMBER(10,3),
  CREATE_QTY_3      NUMBER(10,3),
  SCH_DUE_TIME      DATE,
  LOT_DEL_TIME      DATE,
  LOT_DEL_QTY_1     NUMBER(10,3),
  LOT_DEL_QTY_2     NUMBER(10,3),
  LOT_DEL_QTY_3     NUMBER(10,3),
  SHIP_CODE         VARCHAR2(12 BYTE),
  ORIG_UNIT_1       VARCHAR2(10 BYTE),
  ORIG_UNIT_2       VARCHAR2(10 BYTE),
  ORIG_UNIT_3       VARCHAR2(10 BYTE),
  FACTORY           VARCHAR2(10 BYTE)
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RWIPPLTSTS 
ADD CONSTRAINT RWIPPLTSTS_PK PRIMARY KEY
(
 LOT_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE TABLE RSUMTMPWCT
(
  SUBLOT_ID       VARCHAR2(30 BYTE)             DEFAULT (' ')                 NOT NULL,
  HIST_SEQ        NUMBER(10)                    DEFAULT (0)                   NOT NULL,
  PERIOD_TYPE     CHAR(1 BYTE)                  DEFAULT (' ')                 NOT NULL,
  PERIOD_NAME     VARCHAR2(30 BYTE)             DEFAULT (' ')                 NOT NULL,
  SEQ             NUMBER(10)                    DEFAULT (0)                   NOT NULL,
  REWORK_FLAG     CHAR(1 BYTE)                  DEFAULT (' ')                 NOT NULL,
  NO_WAFER_FLAG   CHAR(1 BYTE)                  DEFAULT (' ')                 NOT NULL,
  LOT_ID          VARCHAR2(25 BYTE)             DEFAULT (' ')                 NOT NULL,
  FACTORY         VARCHAR2(10 BYTE)             DEFAULT (' ')                 NOT NULL,
  OPER            VARCHAR2(10 BYTE)             DEFAULT (' ')                 NOT NULL,
  WAITING_TIME    NUMBER(10,2)                  DEFAULT (0)                   NOT NULL,
  PROCESS_TIME    NUMBER(10,2)                  DEFAULT (0)                   NOT NULL,
  STORE_TIME      NUMBER(10,2)                  DEFAULT (0)                   NOT NULL,
  CREATE_USER_ID  VARCHAR2(20 BYTE)             DEFAULT (' ')                 NOT NULL,
  CREATE_TIME     VARCHAR2(14 BYTE)             DEFAULT (' ')                 NOT NULL,
  UPDATE_USER_ID  VARCHAR2(20 BYTE)             DEFAULT (' ')                 NOT NULL,
  UPDATE_TIME     VARCHAR2(14 BYTE)             DEFAULT (' ')                 NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RSUMTMPWCT 
ADD CONSTRAINT RSUMTMPWCT_PK PRIMARY KEY
(
 SUBLOT_ID, 
 HIST_SEQ, 
 PERIOD_TYPE, 
 PERIOD_NAME, 
 SEQ,
 LOT_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE INDEX RSUMTMPWCT_IDX2 ON RSUMTMPWCT
(SUBLOT_ID, PERIOD_TYPE, PERIOD_NAME, SEQ, LOT_ID)
TABLESPACE REPORT_IDX_TS;


CREATE INDEX RSUMTMPWCT_IDX1 ON RSUMTMPWCT
(PERIOD_TYPE, PERIOD_NAME, SEQ, REWORK_FLAG, FACTORY, 
LOT_ID)
TABLESPACE REPORT_IDX_TS;

CREATE TABLE RSUMTMPWYD
(
  SUBLOT_ID    VARCHAR2(30 BYTE)                DEFAULT (' ')                 NOT NULL,
  PERIOD_TYPE  CHAR(1 BYTE)                     DEFAULT (' ')                 NOT NULL,
  PERIOD_NAME  VARCHAR2(30 BYTE)                DEFAULT (' ')                 NOT NULL,
  SEQ          NUMBER(10)                       DEFAULT (0)                   NOT NULL,
  END_FLAG     CHAR(1 BYTE)                     DEFAULT (' ')                 NOT NULL,
  END_SEQ      NUMBER(10)                       DEFAULT (0)                   NOT NULL,
  LOT_ID       VARCHAR2(25 BYTE)                DEFAULT (' ')                 NOT NULL,
  HIST_SEQ     NUMBER(10)                       DEFAULT (0)                   NOT NULL,
  TRAN_TIME    VARCHAR2(14 BYTE)                DEFAULT (' ')                 NOT NULL,
  FACTORY      VARCHAR2(10 BYTE)                DEFAULT (' ')                 NOT NULL,
  OPER         VARCHAR2(10 BYTE)                DEFAULT (' ')                 NOT NULL,
  GRADE        CHAR(1 BYTE)                     DEFAULT (' ')                 NOT NULL,
  IN_QTY       NUMBER(10)                       DEFAULT (0)                   NOT NULL,
  OUT_QTY      NUMBER(10)                       DEFAULT (0)                   NOT NULL,
  CREATE_TIME  VARCHAR2(14 BYTE)                DEFAULT (' ')                 NOT NULL,
  UPDATE_TIME  VARCHAR2(14 BYTE)                DEFAULT (' ')                 NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RSUMTMPWYD 
ADD CONSTRAINT RSUMTMPWYD_PK PRIMARY KEY
(
 SUBLOT_ID, 
 PERIOD_TYPE, 
 PERIOD_NAME, 
 SEQ,
 LOT_ID
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE TABLE RSUMTMPLYD
(
  SUBLOT_ID    VARCHAR2(30 BYTE)                DEFAULT (' ')                 NOT NULL,
  LOT_ID       VARCHAR2(25 BYTE)                DEFAULT (' ')                 NOT NULL,
  PERIOD_TYPE  CHAR(1 BYTE)                     DEFAULT (' ')                 NOT NULL,
  PERIOD_NAME  VARCHAR2(30 BYTE)                DEFAULT (' ')                 NOT NULL,
  SEQ          NUMBER(10)                       DEFAULT (0)                   NOT NULL,
  END_FLAG     CHAR(1 BYTE)                     DEFAULT (' ')                 NOT NULL,
  END_SEQ      NUMBER(10)                       DEFAULT (0)                   NOT NULL,
  FACTORY      VARCHAR2(10 BYTE)                DEFAULT (' ')                 NOT NULL,
  TRAN_CODE    VARCHAR2(12 BYTE)                DEFAULT (' ')                 NOT NULL,
  HIST_SEQ     NUMBER(10)                       DEFAULT (0)                   NOT NULL,
  TRAN_TIME    VARCHAR2(14 BYTE)                DEFAULT (' ')                 NOT NULL,
  OPER_NEW     VARCHAR2(10 BYTE)                DEFAULT (' ')                 NOT NULL,
  OPER_OLD     VARCHAR2(10 BYTE)                DEFAULT (' ')                 NOT NULL,
  GRADE_NEW    CHAR(1 BYTE)                     DEFAULT (' ')                 NOT NULL,
  GRADE_OLD    CHAR(1 BYTE)                     DEFAULT (' ')                 NOT NULL,
  IN_QTY       NUMBER(10,3)                     DEFAULT (0)                   NOT NULL,
  OUT_QTY      NUMBER(10,3)                     DEFAULT (0)                   NOT NULL,
  ORIG_GRADE   CHAR(1 BYTE)                     DEFAULT (' ')                 NOT NULL,
  CREATE_TIME  VARCHAR2(14 BYTE)                DEFAULT (' ')                 NOT NULL,
  UPDATE_TIME  VARCHAR2(14 BYTE)                DEFAULT (' ')                 NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RSUMTMPLYD 
ADD CONSTRAINT RSUMTMPLYD_PK PRIMARY KEY
(
 SUBLOT_ID, 
 LOT_ID, 
 PERIOD_TYPE, 
 PERIOD_NAME, 
 SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;

/* RSUMTMPLLC : Temerature Table for calculating Cycle time base on Lot */
CREATE TABLE RSUMTMPLLC
(
  LOT_ID                VARCHAR2(25 BYTE)       DEFAULT (' ')                 NOT NULL ENABLE,
  HIST_SEQ              NUMBER(10,0)            DEFAULT (0)                   NOT NULL ENABLE,
  PERIOD_TYPE           CHAR(1 BYTE)            DEFAULT (' ')                 NOT NULL ENABLE,
  PERIOD_NAME           VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL ENABLE,
  SEQ                   NUMBER(10,0)            DEFAULT (0)                   NOT NULL ENABLE,
  REWORK_FLAG           CHAR(1 BYTE)            DEFAULT (' ')                 NOT NULL ENABLE,
  FACTORY               VARCHAR2(10 BYTE)       DEFAULT (' ')                 NOT NULL ENABLE,
  OPER                  VARCHAR2(10 BYTE)       DEFAULT (' ')                 NOT NULL ENABLE,
  WAITING_TIME          NUMBER(10,2)            DEFAULT (0)                   NOT NULL ENABLE,
  PROCESS_TIME          NUMBER(10,2)            DEFAULT (0)                   NOT NULL ENABLE,
  STORE_TIME            NUMBER(10,2)            DEFAULT (0)                   NOT NULL ENABLE,
  CREATE_USER_ID        VARCHAR2(20 BYTE)       DEFAULT (' ')                 NOT NULL ENABLE,
  CREATE_TIME           VARCHAR2(14 BYTE)       DEFAULT (' ')                 NOT NULL ENABLE,
  UPDATE_USER_ID        VARCHAR2(20 BYTE)       DEFAULT (' ')                 NOT NULL ENABLE,
  UPDATE_TIME           VARCHAR2(14 BYTE)       DEFAULT (' ')                 NOT NULL ENABLE
) TABLESPACE REPORT_DATA_TS ;

ALTER TABLE RSUMTMPLLC 
ADD CONSTRAINT RSUMTMPLLC_PK PRIMARY KEY
(
 LOT_ID, HIST_SEQ, PERIOD_TYPE, PERIOD_NAME, SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE INDEX RSUMTMPLLC_IDX1 ON RSUMTMPLLC
(
    LOT_ID,
    PERIOD_TYPE,
    PERIOD_NAME,
    SEQ
) TABLESPACE REPORT_IDX_TS ;

/* RSUMTMPLLY : Temerature Table for calculating yield base on Lot */
CREATE TABLE RSUMTMPLLY
(
  LOT_ID                VARCHAR2(25 BYTE)       DEFAULT (' ')                 NOT NULL ENABLE,
  HIST_SEQ              NUMBER(10,0)            DEFAULT (0)                   NOT NULL ENABLE,
  PERIOD_TYPE           CHAR(1 BYTE)            DEFAULT (' ')                 NOT NULL ENABLE,
  PERIOD_NAME           VARCHAR2(30 BYTE)       DEFAULT (' ')                 NOT NULL ENABLE,
  END_FLAG              CHAR(1 BYTE)            DEFAULT (' ')                 NOT NULL ENABLE,
  FACTORY               VARCHAR2(10 BYTE)       DEFAULT (' ')                 NOT NULL ENABLE,
  TRAN_CODE             VARCHAR2(12 BYTE)       DEFAULT (' ')                 NOT NULL ENABLE,
  TRAN_TIME             VARCHAR2(14 BYTE)       DEFAULT (' ')                 NOT NULL ENABLE,
  OPER_NEW              VARCHAR2(10 BYTE)       DEFAULT (' ')                 NOT NULL ENABLE,
  OPER_OLD              VARCHAR2(10 BYTE)       DEFAULT (' ')                 NOT NULL ENABLE,
  REWORK_FLAG           CHAR(1 BYTE)            DEFAULT (' ')                 NOT NULL ENABLE,
  IN_QTY                NUMBER(10,3)            DEFAULT (0)                   NOT NULL ENABLE,
  OUT_QTY               NUMBER(10,3)            DEFAULT (0)                   NOT NULL ENABLE,
  YIELD                 NUMBER(20,10)           DEFAULT (0)                   NOT NULL ENABLE,
  CREATE_TIME           VARCHAR2(14 BYTE)       DEFAULT (' ')                 NOT NULL ENABLE,
  UPDATE_TIME           VARCHAR2(14 BYTE)       DEFAULT (' ')                 NOT NULL ENABLE
) TABLESPACE REPORT_DATA_TS ;

ALTER TABLE RSUMTMPLLY 
ADD CONSTRAINT RSUMTMPLLY_PK PRIMARY KEY
(
 LOT_ID, HIST_SEQ, PERIOD_TYPE, PERIOD_NAME
) USING INDEX TABLESPACE REPORT_IDX_TS;
  
CREATE TABLE RATRNAMHIS
(
  FACTORY               VARCHAR2(10 BYTE)       DEFAULT (' ')                 NOT NULL,
  ATTR_TYPE             VARCHAR2(20 BYTE)       DEFAULT (' ')                 NOT NULL,
  ATTR_NAME             VARCHAR2(100 BYTE)      DEFAULT (' ')                 NOT NULL,
  ATTR_KEY              VARCHAR2(100 BYTE)       DEFAULT (' ')                 NOT NULL,
  HIST_SEQ              NUMBER(10)              DEFAULT (0)                   NOT NULL,
  ATTR_OLD_VALUE        VARCHAR2(1000 BYTE),
  ATTR_NEW_VALUE        VARCHAR2(1000 BYTE),
  NULL_FLAG             CHAR(1)         DEFAULT (' '),
  TRAN_TIME             DATE,
  SYS_TRAN_TIME         DATE,
  KEY_HIST_SEQ          NUMBER(10),
  PREV_ACTIVE_HIST_SEQ  NUMBER(10),
  HIST_START_SEQ        NUMBER(10),
  HIST_DEL_FLAG         CHAR(1 BYTE),
  HIST_DEL_TIME         DATE,
  HIST_DEL_USER_ID      VARCHAR2(20 BYTE),
  HIST_DEL_COMMENT      VARCHAR2(400 BYTE),
  TRAN_USER_ID		VARCHAR2(20 BYTE)
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

CREATE INDEX RATRNAMHIS_IDX_1 ON RATRNAMHIS
(FACTORY, ATTR_TYPE, ATTR_KEY, KEY_HIST_SEQ)
TABLESPACE REPORT_IDX_TS;

CREATE TABLE RATRNAMSTS
(
  FACTORY               VARCHAR2(10 BYTE)       DEFAULT (' ')                 NOT NULL,
  ATTR_TYPE             VARCHAR2(20 BYTE)       DEFAULT (' ')                 NOT NULL,
  ATTR_NAME             VARCHAR2(100 BYTE)      DEFAULT (' ')                 NOT NULL,
  ATTR_KEY              VARCHAR2(100 BYTE)       DEFAULT (' ')                 NOT NULL,
  KEY_HIST_SEQ          NUMBER(10),
  ATTR_FMT          		VARCHAR2(1),
  ATTR_SIZE          		NUMBER(6),
  ATTR_VALUE            VARCHAR2(1000 BYTE),
  NULL_FLAG                   CHAR(1)         DEFAULT (' '),
  LAST_TRAN_TIME        DATE,
  LAST_ACTIVE_HIST_SEQ  NUMBER(10),
  LAST_HIST_SEQ         NUMBER(10)
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RATRNAMSTS 
ADD CONSTRAINT RATRNAMSTS_PK PRIMARY KEY
(
 FACTORY, 
 ATTR_TYPE, 
 ATTR_NAME, 
 ATTR_KEY
) USING INDEX TABLESPACE REPORT_IDX_TS;

CREATE TABLE RPRCPRCSTP
(
  PROC_NAME    VARCHAR2(30 BYTE)                DEFAULT (' ')                 NOT NULL,
  STOP_FLAG    CHAR(1 BYTE)                     DEFAULT (' ')                 NOT NULL,
  CREATE_TIME  VARCHAR2(14 BYTE)                DEFAULT (' ')                 NOT NULL,
  UPDATE_TIME  VARCHAR2(14 BYTE)                DEFAULT (' ')                 NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE RPRCPRCSTP 
ADD CONSTRAINT RPRCPRCSTP_PK PRIMARY KEY
(
 PROC_NAME
) USING INDEX TABLESPACE REPORT_IDX_TS;


/*==== MES --> Report Interface Table ====*/
CREATE TABLE MTMPLOTHIS_BAK 
(
    TABLE_UPDATE_SEQ            NUMBER(12)       DEFAULT(0)      NOT NULL,
    CM_KEY_1                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_2                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_3                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_4                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_5                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SUB_LOT_ID                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUB_LOT_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Transaction Time - Backdated 가능 */
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* System Time */
    SYS_TRAN_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Transaction Code */
    TRAN_CODE                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /******** Mod For V42 Status  *********/
    LOT_DESC                    VARCHAR2(200)     DEFAULT(' ')    NOT NULL,
    /* Current Factory */
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    /* Flow, Oper */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Quantity 1 ~ 3 */
    QTY_1                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* 캐리어 ID */
    CRR_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    /* Lot Type - 'P':Production, 'T':Test, 'E':Engineer, 'D':Dummy, 'M':Monitoring */
    LOT_TYPE                    CHAR(1)          DEFAULT('P')    NOT NULL,
    /* Owner Code, Create Code */
    OWNER_CODE                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CREATE_CODE                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* LOT의 우선순위 - '0'-->'9' LOW-->HIGH, 기본값:'5' */
    LOT_PRIORITY                CHAR(1)          DEFAULT('5')    NOT NULL,
    /* Lot Status - PROC:In Process, WAIT:Wait, MOVE : Moving */
    LOT_STATUS                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Hold Info. */
    HOLD_FLAG                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    HOLD_CODE                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    HOLD_PASSWORD               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Release 권한을 가지는 권한 그룹 */
    HOLD_PRV_GRP_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    /* Oper In Quantity 1 ~ 3 */
    OPER_IN_QTY_1               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OPER_IN_QTY_2               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OPER_IN_QTY_3               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Create Qty 1~3 */
    CREATE_QTY_1                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CREATE_QTY_2                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CREATE_QTY_3                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Start Quantity 1 ~ 3 */
    START_QTY_1                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,  /* Add For V42 */
    START_QTY_2                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,  /* Add For V42 */
    START_QTY_3                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,  /* Add For V42 */
    /* Inventory Operation에 들어 있음. MOVE 불가능 */
    INV_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* RECEIVING 대기 */
    TRANSIT_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Unit Exist Flag */
    UNIT_EXIST_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Inventory Unit*/
    INV_UNIT                    VARCHAR2(10)     DEFAULT(0.0)    NOT NULL,
    /* Rework Info. */
    RWK_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    RWK_CODE                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* LOT의 Rework 누적 횟수 */
    RWK_COUNT                   NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* REWORK후 돌아올 공정 */
    RWK_RET_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RWK_RET_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    RWK_RET_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* REWORK이 끝나는 공정 REWROK을 보낼때 현재 공정을 넣는다.*/
    RWK_END_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RWK_END_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    RWK_END_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* RETUREN 시 REWROK FLAG CLEAR */
    RWK_RET_CLEAR_FLAG          CHAR(1)          DEFAULT(' ')    NOT NULL,
    RWK_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Non Standard Move Info. */
    NSTD_FLAG                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    NSTD_RET_FLOW               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    NSTD_RET_FLOW_SEQ_NUM       NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    NSTD_RET_OPER               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    NSTD_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Repair Info. */
    REP_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    REP_RET_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Store Return Info. */
    STR_RET_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,  /* Add For V5 */
    STR_RET_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V5 */
    STR_RET_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,  /* Add For V5 */
    /* Start/End Flag */
    START_FLAG                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    START_TIME                  VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    START_RES_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    END_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    END_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    END_RES_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* SAMPLE M: Mother  C: Child */
    SAMPLE_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Sample Wait Flag */
    SAMPLE_WAIT_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Sample Result - ' ':Not decision 'Y': Good  'N': No Good */
    SAMPLE_RESULT               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* From To Flag - ' ':None, 'F':From, 'T':To */
    FROM_TO_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    FROM_TO_LOT_ID              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,  /* Mod For V42 */
    /* Ship Info. */
    SHIP_CODE                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SHIP_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Due Time(Original, Scheduled) */
    ORG_DUE_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    SCH_DUE_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Time Info. */
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FAC_IN_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FLOW_IN_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OPER_IN_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Reserve 된 Resource ID */
    RESERVE_RES_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PORT_ID                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Batch Info. */
    BATCH_ID                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    BATCH_SEQ                   NUMBER(3)        DEFAULT(0)      NOT NULL,
    /* Order Info. */
    ORDER_ID                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    ADD_ORDER_ID_1              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    ADD_ORDER_ID_2              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    ADD_ORDER_ID_3              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* LOT LOCATION */
    LOT_LOCATION_1              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,  /* Add For V5 */
    LOT_LOCATION_2              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,  /* Add For V5 */
    LOT_LOCATION_3              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,  /* Add For V5 */
    /* LOT 생성시 SET, ADAPT로 수정 가능 */
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
    LOT_CMF_20                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* LOT 이 지워졌을때 SETTING */
    LOT_DEL_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOT_DEL_CODE                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,  /* Mod For V42 */
    LOT_DEL_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* LOT-BOM Info. */
    /** BOM Info. **/
    BOM_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    BOM_SET_VERSION             NUMBER(3)        DEFAULT(0)      NOT NULL,
    /* BOM History Sequence */
    BOM_ACTIVE_HIST_SEQ         NUMBER(10)       DEFAULT(0)      NOT NULL,
    BOM_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    CRITICAL_RES_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    /* 크리티칼 레이어의 장비 그룹을 사용할 경우 경우를 대비 */
    CRITICAL_RES_GROUP_ID       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    SAVE_RES_ID_1               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    SAVE_RES_ID_2               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    LOT_GROUP_ID_1              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    LOT_GROUP_ID_2              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    LOT_GROUP_ID_3              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    /* Lot Yield Info. */
    YIELD_1                     NUMBER(15,10)    DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    YIELD_2                     NUMBER(15,10)    DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    YIELD_3                     NUMBER(15,10)    DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    GOOD_QTY                    NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    RESV_FIELD_1                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    RESV_FIELD_2                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */ 
    RESV_FIELD_3                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */ 
    RESV_FIELD_4                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    RESV_FIELD_5                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    RESV_FLAG_1                 CHAR(1)          DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    RESV_FLAG_2                 CHAR(1)          DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    RESV_FLAG_3                 CHAR(1)          DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    RESV_FLAG_4                 CHAR(1)          DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    RESV_FLAG_5                 CHAR(1)          DEFAULT(' ')    NOT NULL,  /* Add For V42 */
	/******** Mod For V42 Status  *********/    
    FROM_TO_MAT_ID              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FROM_TO_MAT_VER             NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    FROM_TO_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FROM_TO_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    FROM_TO_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FROM_TO_QTY_1               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_QTY_2               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_QTY_3               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_HIST_SEQ            NUMBER(10)       DEFAULT(0)      NOT NULL,
    /** Old Lot Info. **/
    OLD_TRAN_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OLD_SYS_TRAN_TIME           VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OLD_TRAN_CODE               VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
	  OLD_FACTORY                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    OLD_MAT_ID                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_MAT_VER                 NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    /* Flow, Oper */
    OLD_FLOW                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OLD_FLOW_SEQ_NUM            NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    OLD_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    OLD_CM_KEY_1                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_CM_KEY_2                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_CM_KEY_3                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_CM_KEY_4                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_CM_KEY_5                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Quantity 1 ~ 3 */
    OLD_QTY_1                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OLD_QTY_2                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OLD_QTY_3                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OLD_CRR_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    /* Lot Type - 'P':Production, 'T':Test, 'E':Engineer, 'D':Dummy, 'M':Monitoring */
    OLD_LOT_TYPE                CHAR(1)          DEFAULT('P')    NOT NULL,
    OLD_LOT_PRIORITY            CHAR(1)          DEFAULT('5')    NOT NULL,
    OLD_ORDER_ID                VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Owner Code, Create Code */
    OLD_OWNER_CODE              VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    OLD_CREATE_CODE             VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    OLD_FAC_IN_TIME             VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OLD_FLOW_IN_TIME            VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OLD_OPER_IN_TIME            VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OLD_RWK_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    OLD_START_FLAG              CHAR(1)          DEFAULT(' ')    NOT NULL,
    OLD_START_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OLD_START_RES_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OLD_END_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    OLD_END_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OLD_END_RES_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Transaction CMF 1~20, Transaction User ID, Transaction Comment */
    TRAN_CMF_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    /* Transaction User ID/Comment */
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* Previous Active History Sequence */
    PREV_ACTIVE_HIST_SEQ        NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* History Block Number(Requested by Fred) */
    /* - Multi Transaction을 한번에 삭제할 경우 */
    MULTI_TR_KEY                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    MULTI_TR_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,  /* Add For V42 */
    /* For additional extended table */
    EXT_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,  /* Add For V5 */
    /* Delete Info. */
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    HIST_DEL_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_COMMENT            VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    PROCESS_FLAG                CHAR(1)          DEFAULT (' ')   NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE MTMPLOTHIS_BAK
ADD CONSTRAINT MTMPLOTHIS_BAK_PK PRIMARY KEY
(
    TABLE_UPDATE_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;


CREATE TABLE MTMPRESHIS_BAK
(
    TABLE_UPDATE_SEQ            NUMBER(12)       DEFAULT(0)      NOT NULL,  
    CM_KEY_1                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_2                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_3                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_4                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_5                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAIN_SUB_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    EVENT_ID                    VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /* Transaction Time - Backdated 가능 */
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    PARENTS_SUBRES_ID           VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    MAIN_HIST_SEQ               NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* System Time */
    SYS_TRAN_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Old Event */
    OLD_EVENT_ID                VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    OLD_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    OLD_TRAN_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OLD_SYS_TRAN_TIME           VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OLD_CM_KEY_1                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_CM_KEY_2                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_CM_KEY_3                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_CM_KEY_4                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_CM_KEY_5                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* EVENT에서 사용하는 USER DEFINE PROMPT */
    OLD_UP_DOWN_FLAG            CHAR(1)          DEFAULT('U')    NOT NULL,
    OLD_PRI_STS                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_STS_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_STS_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_STS_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_STS_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_STS_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_STS_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_STS_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_STS_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_STS_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_STS_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* EVENT 에서 사용하는 USER DEFINE PROMPT */
    NEW_UP_DOWN_FLAG            CHAR(1)          DEFAULT('U')    NOT NULL,
    NEW_PRI_STS                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    NEW_STS_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    NEW_STS_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    NEW_STS_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    NEW_STS_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    NEW_STS_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    NEW_STS_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    NEW_STS_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    NEW_STS_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    NEW_STS_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    NEW_STS_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Lot ID, Carrier ID */
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* 장비 제어 모드 - OL: ON LINE, OR: ON LINE REAL, OF: OFF LINE */
    RES_CTRL_MODE               CHAR(2)          DEFAULT(' ')    NOT NULL,
    /* 장비 진행 모드 - M:MANUAL, S:SEMI AUTO, F: FULL AUTO */
    RES_PROC_MODE               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* RAS-WIP 연결 */
    LOT_EXIST_FLAG              CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* RAS-EDC 연결 */
    COL_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    COL_SET_VERSION             NUMBER(3)        DEFAULT(0)      NOT NULL,
    /* CUSTOMIZED FIELD FOR EVENT*/
    TRAN_CMF_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    /* 이벤트 COMMENT는 400 */
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* Last Down Time, Last Down Hist Seq */
    LAST_DOWN_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LAST_DOWN_HIST_SEQ          NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* History Block Number(Requested by Fred) */
    /* - Multi Transaction을 한번에 삭제할 경우 */
    HIST_START_SEQ              NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Delete Info. */
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    HIST_DEL_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_COMMENT            VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    PROCESS_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE MTMPRESHIS_BAK
ADD CONSTRAINT MTMPRESHIS_BAK_PK PRIMARY KEY
(
    TABLE_UPDATE_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;


/*==== MES --> Report Attribute Interface Table ====*/
CREATE TABLE MTMPATRHIS_BAK 
(
    TABLE_UPDATE_SEQ            NUMBER(12)       DEFAULT(0)      NOT NULL,
    CM_KEY_1                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_2                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_3                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_4                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_5                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)    DEFAULT (' ')   NOT NULL,
    ATTR_TYPE                   VARCHAR2(20)    DEFAULT (' ')   NOT NULL,
    ATTR_NAME                   VARCHAR2(100)    DEFAULT (' ')   NOT NULL,
    ATTR_KEY                    VARCHAR2(100)    DEFAULT (' ')   NOT NULL,
    HIST_SEQ                    NUMBER(10)      DEFAULT (0)     NOT NULL,
    ATTR_OLD_VALUE              VARCHAR2(1000)    DEFAULT (' ')   NOT NULL,
    ATTR_NEW_VALUE              VARCHAR2(1000)    DEFAULT (' ')   NOT NULL,
    NULL_FLAG                   CHAR(1)         DEFAULT (' ')   NOT NULL,
    TRAN_TIME                   VARCHAR2(14)    DEFAULT (' ')   NOT NULL,
    SYS_TRAN_TIME               VARCHAR2(14)    DEFAULT (' ')   NOT NULL,
    KEY_HIST_SEQ                NUMBER(10)      DEFAULT (0)     NOT NULL,                
    PREV_ACTIVE_HIST_SEQ        NUMBER(10)      DEFAULT (0)     NOT NULL,
    HIST_START_SEQ              NUMBER(10)      DEFAULT (0)     NOT NULL,
    HIST_DEL_FLAG               CHAR(1)         DEFAULT (' ')   NOT NULL,
    HIST_DEL_TIME               VARCHAR2(14)    DEFAULT (' ')   NOT NULL,
    HIST_DEL_USER_ID            VARCHAR2(20)    DEFAULT (' ')   NOT NULL,
    HIST_DEL_COMMENT            VARCHAR2(400)   DEFAULT (' ')   NOT NULL,
    PROCESS_FLAG                CHAR(1)          DEFAULT (' ')   NOT NULL,
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE MTMPATRHIS_BAK
ADD CONSTRAINT MTMPATRHIS_BAK_PK PRIMARY KEY
(
    TABLE_UPDATE_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;

/*==== MES --> Report Cassette Interface Table ====*/
CREATE TABLE MTMPCRRHIS_BAK 
(
    TABLE_UPDATE_SEQ            NUMBER(12)       DEFAULT(0)      NOT NULL,
    CM_KEY_1                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_2                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_3                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_4                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_5                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Transaction Time - Backdated 가능 */
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* System Time */
    SYS_TRAN_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Transaction Code */
    TRAN_CODE                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CRR_STATUS                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CRR_STATUS_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* 사용횟수 */
    USAGE_COUNT                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    CLEAN_COUNT                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* 현재 위치, 리소스 */
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PORT_ID                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Current location. (Stocker, Vehicle ...) */
    LOCATION_1                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LOCATION_2                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LOCATION_3                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LOCATION_4                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LOCATION_5                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* 세정 완료등 */
    FINISH_CLEAN_FLAG           CHAR(1)          DEFAULT(' ')    NOT NULL,
    LAST_CLEAN_TIME             VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Current Lot Information */
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOT_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    QTY_1                       NUMBER(12,3)     DEFAULT(0)      NOT NULL,
    QTY_2                       NUMBER(12,3)     DEFAULT(0)      NOT NULL,
    QTY_3                       NUMBER(12,3)     DEFAULT(0)      NOT NULL,
    TBL_SLOT                    VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    /* 반송 장비 관련 필드 */
    MOVE_FLAG                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    EMPTY_FLAG                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    STOCK_IN_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* TRAN_CMF_1 ~ 10 */
    TRAN_CMF_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    TRAN_CMF_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    /* Transaction User ID/Comment */
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    PROCESS_FLAG                CHAR(1)          DEFAULT (' ')   NOT NULL
) TABLESPACE REPORT_DATA_TS;

ALTER TABLE MTMPCRRHIS_BAK
ADD CONSTRAINT MTMPCRRHIS_BAK_PK PRIMARY KEY
(
    TABLE_UPDATE_SEQ
) USING INDEX TABLESPACE REPORT_IDX_TS;

--CREATE TABLE TRIG_ERR_TAB 
--(
--	ERR_DATE     DATE,
--	ERR_NUM      NUMBER,
--	ERR_TAB_NAM  VARCHAR2(100),
--	ERR_ORA_MSG  VARCHAR2(200),
--	ERR_USR_MSG  VARCHAR2(2000)
--) TABLESPACE REPORT_DATA_TS;
--
--CREATE TABLE mppdb_log_data
--(
--  ltdo_id                    NUMBER(10) NOT NULL,
--  ltdo_table_name            VARCHAR2(30) NOT NULL,
--  ltdo_table_key             VARCHAR2(2000) NOT NULL,
--  ltdo_dml_stat              VARCHAR2(1) NOT NULL,
--  ltdo_date_inserted         DATE NOT NULL,
--  ltdo_date_updated          DATE,
--  ltdo_err_text              VARCHAR2(2000)
--) TABLESPACE REPORT_DATA_TS;
--
--CREATE INDEX ltdo_mppdb_i1 ON mppdb_log_data
--(ltdo_date_updated, ltdo_table_name)
--TABLESPACE REPORT_IDX_TS;
-- 
--ALTER TABLE mppdb_log_data
-- ADD CONSTRAINT ltdo_pk PRIMARY KEY (ltdo_id) USING INDEX TABLESPACE REPORT_IDX_TS;
--
--CREATE GLOBAL TEMPORARY TABLE mppdb_log_data_templog (ts DATE,err_text VARCHAR2(2000),id NUMBER(10)) ON COMMIT DELETE ROWS
--/
--ALTER TABLE mppdb_log_data_templog ADD(
--CONSTRAINT mldtemplog_pk
--PRIMARY KEY (id)
--USING INDEX
--)
--/
-- 
--CREATE SEQUENCE ltdo_id_seq
--/
-- 
--CREATE
--PACKAGE MPPDB_LOG_DATA_INS_PKG
--IS
--/* Package name   : MPPDB_LOG_DATA_INS_PKG
--   Author(s)      : Gebhardt
--   Date written   : 29101999
--   Last update    : 070400 FG Performance tuning (enhancements MPPDB)
--   Script         :  SAME for Singapore and Burghausen !
--   Last update    : 100400 FG/WH Bgh
--   Purpose        :
--   copy of MPPDBS_LOG_DATA_INS_PKG
--   To fill MPPDB_LOG_DATA table when INSERT/UPDATE/DELETE.
--   The procedure is written to speed up the triggers
--*/
--   PROCEDURE MPPDB_LOG_DATA_INS_PRC(v_ltdo_table_name IN VARCHAR2,
--   v_ltdo_table_key IN VARCHAR2, v_ltdo_dml_stat IN VARCHAR2);
--END MPPDB_LOG_DATA_INS_PKG;
--/
-- CREATE
--PACKAGE BODY MPPDB_LOG_DATA_INS_PKG
--IS
--        PROCEDURE MPPDB_LOG_DATA_INS_PRC
--        (v_ltdo_table_name IN VARCHAR2, v_ltdo_table_key IN VARCHAR2,
--         v_ltdo_dml_stat IN VARCHAR2) IS
--        BEGIN
--
--  -- 070400 FG : to_date('19000101','YYYYMMDD') Index use ! see also new index ltdo_tabdate_i
--                INSERT INTO MPPDB_LOG_DATA
--                 (LTDO_ID
--                 ,LTDO_TABLE_NAME
--                 ,LTDO_TABLE_KEY
--                 ,LTDO_DML_STAT
--                 ,LTDO_DATE_INSERTED
--                 ,LTDO_DATE_UPDATED
--                 ,LTDO_ERR_TEXT)
--                VALUES
--                 (ltdo_id_seq.nextval
--                 ,v_ltdo_table_name
--                 ,v_ltdo_table_key
--                 ,v_ltdo_dml_stat
--                 ,sysdate
--                 ,to_date('19000101','YYYYMMDD')
--                 ,NULL);
--        END MPPDB_LOG_DATA_INS_PRC;
--END MPPDB_LOG_DATA_INS_PKG;
--/

