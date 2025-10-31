/*
**
**  File Name    : MESplusV5-Table-Create-20081231.sql
**  Description  : MESplus V5 Release Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g
**
**  Period       : 2008.11.01 ~ ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
**
**  Revision History
**  Seq   Date        Modifier      Description                        
**  ---------------------------------------------------------------------------
**  1     2008.11.01  Aiden         Make file
**  2     2008.11.11  Aiden         Add MSVMSVCURT table
**    
*/

/* MSVMSVCURT : Service Management Service User Routine Table */
CREATE TABLE MSVMSVCURT
(
    MODULE_NAME                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SERVICE_NAME                VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    BEFORE                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    AFTER                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    OVERRIDE_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    LIB_NAME                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LIB_VER                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
     /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSVMSVCURT 
ADD CONSTRAINT MSVMSVCURT_PK PRIMARY KEY
(
  MODULE_NAME, 
  SERVICE_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

CREATE TABLE MTMPRESHIS
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
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MTMPRESHIS
ADD CONSTRAINT MTMPRESHIS_PK PRIMARY KEY
(
    TABLE_UPDATE_SEQ
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


DROP TABLE MTMPLOTHIS CASCADE CONSTRAINT PURGE;

/*==== MES --> Report Interface Table ====*/
CREATE TABLE MTMPLOTHIS 
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
    LOT_DESC                    VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
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
    YIELD_1                     NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    YIELD_2                     NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    YIELD_3                     NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
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
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MTMPLOTHIS
ADD CONSTRAINT MTMPLOTHIS_PK PRIMARY KEY
(
    TABLE_UPDATE_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


-- For RAS Loader
 CREATE SEQUENCE MTMPRESHIS_SEQ
  START WITH 1
  MAXVALUE 999999999999
  MINVALUE 1
  CYCLE
  CACHE 20
  NOORDER;
