/*
**
**  File Name    : MESplusV5_ORA_SPC_Table_Script.sql
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
**  ==== Module Naming Rule ====
**  1. Basic Module --
**      MSG : Message Module
**      SEC : Security Module
**      GCM : General Code Management Module
**  2. MES Module --
**      WIP : Work In Process Module
**      BOM : Bill Of Material Module
**      INV : Inventory
**      QCM : Quality Control Module
**      RAS : Resource Allocation and Status Module
**      EDC : Engineering Data Collection Module
**      ALM : Alarm Module
**      RCP : Recipe Module
**      RTD : Real-Time Dispatch Module
**      RTS : Real-Time Schedule Module
**  3. Interface Module --
**      TMP : Temporary Tables
**      ERP : ERP Interface Module
**  4. RPT Module --
**      MPI : Manufacturing Performance Indicator
**      RPT : Report Module
**      SUM : Summary Module
**      WEB : Web Security Module
**  ============================
**
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
*/


/*==== SPC(Statistical Process Control) ====*/
/* MSPCCHTDEF : SPC Chart Definition */

CREATE TABLE MSPCCHTDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHART_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHART_DESC                  VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    COL_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SYNC_EDC_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHAR_ID                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOT_RES_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Added by HKYUNG */
    MEAS_RES_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PROC_FLOW                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PROC_OPER                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    PROC_RES_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RECIPE_ID                   VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RECIPE_VERSION              NUMBER(3)        DEFAULT(0)      NOT NULL,
    /* End of Add */
    GRAPH_TYPE                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    UNIT_USE_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    UNIT_COUNT                  NUMBER(3)        DEFAULT(0)      NOT NULL,
    SAMPLE_SIZE                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    CONSTANT_1                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CONSTANT_2                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CONSTANT_3                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CONSTANT_4                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SIGMA_CONSTANT              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    AUTO_CL_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    X_RULE_CHECK_TBL            VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    R_RULE_CHECK_TBL            VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    X_ALARM_CODE_TBL            VARCHAR2(500)    DEFAULT(' ')    NOT NULL,
    R_ALARM_CODE_TBL            VARCHAR2(500)    DEFAULT(' ')    NOT NULL,
    PRECISION_LIMIT             NUMBER(2)        DEFAULT(0)      NOT NULL,
    SPEC_CHECK_TYPE             CHAR(1)          DEFAULT(' ')    NOT NULL,
    SPEC_OUT_COUNT              NUMBER(3)        DEFAULT(0)      NOT NULL,
    ACT_RESV_FLAG1              CHAR(1)          DEFAULT(' ')    NOT NULL,
    ACT_RESV_FLAG2              CHAR(1)          DEFAULT(' ')    NOT NULL,
    ACT_RESV_FLAG3              CHAR(1)          DEFAULT(' ')    NOT NULL,
    DELETE_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHARGE_ENGR                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHART_COMMENT               VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    CHT_GRP_1                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHT_GRP_2                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHT_GRP_3                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHT_GRP_4                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHT_GRP_5                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHT_GRP_6                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHT_GRP_7                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHT_GRP_8                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHT_GRP_9                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHT_GRP_10                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHT_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHT_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHT_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHT_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHT_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHT_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHT_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHT_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHT_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHT_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,    
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    WB_SIGMA_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    MIN_TRIAL_NUMBER            VARCHAR2(25)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSPCCHTDEF
ADD CONSTRAINT MSPCCHTDEF_PK PRIMARY KEY
(
    FACTORY,
    CHART_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


CREATE TABLE MSPCCHTUNT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHART_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    UNIT_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    DEF_UNIT_ID                 VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSPCCHTUNT
ADD CONSTRAINT MSPCCHTUNT_PK PRIMARY KEY
(
    FACTORY,
    CHART_ID,
    UNIT_SEQ_NUM
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSPCSPEHIS : SPC Spec Information */
CREATE TABLE MSPCSPEHIS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHART_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    VERSION                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    RELEASE_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    APPLY_START_TIME            VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    APPLY_END_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    AUTO_MANUAL_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    USL                         VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TARGET                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LSL                         VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UCL                         VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CL                          VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LCL                         VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UCL2                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CL2                         VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LCL2                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SPEC_COMMENT                VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    RELEASE_USER_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RELEASE_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    WB_SIGMA_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSPCSPEHIS
ADD CONSTRAINT MSPCSPEHIS_PK PRIMARY KEY
(
    FACTORY,
    CHART_ID,
    VERSION
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSPCEDCDAT : EDC Data Information */
CREATE TABLE MSPCEDCDAT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHART_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LOT_RES_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    PROC_OPER                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PROC_RES_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    EVENT                       VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    CHAR_ID                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    UNIT_ID                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    UNIT_SEQ                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    VALUE_TYPE                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    VALUE_SEQ                   NUMBER(6)        DEFAULT(0)      NOT NULL,
    VALUE_COUNT                 NUMBER(2)        DEFAULT(0)      NOT NULL,
    VALUE_1                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_2                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_3                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_4                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_5                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_6                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_7                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_8                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_9                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_10                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_11                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_12                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_13                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_14                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_15                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_16                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_17                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_18                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_19                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_20                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_21                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_22                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_23                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_24                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VALUE_25                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    NOMINAL                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PROCESS_SIGMA               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    EDC_COMMENT                 VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    EDC_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    EDC_CHAR_SEQ                NUMBER(6)        DEFAULT(0)      NOT NULL,
    EDC_UNIT_SEQ                NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MSPCEDCDAT
ADD CONSTRAINT MSPCEDCDAT_PK PRIMARY KEY
(
    FACTORY,
    CHART_ID,
    HIST_SEQ,
    UNIT_SEQ,
    VALUE_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MSPCCALDAT : EDC Data SPC Calculation */
CREATE TABLE MSPCCALDAT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHART_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    UNIT_SEQ                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LOT_RES_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    VALUE_COUNT                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    WEIGHT_VALUE                VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    AVERAGE                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    STDDEV                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RANGE                       VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    MIN_VALUE                   VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    MAX_VALUE                   VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    USL                         VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TARGET                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LSL                         VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UCL                         VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CL                          VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LCL                         VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UCL2                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CL2                         VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LCL2                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OOC_TYPE                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    OOC_TYPE2                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    EXCLUDE_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    COL_SET_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,          /* LAVERWON - 2008.02.19 Ãß°¡ */
    EDC_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    EDC_COL_SEQ                 NUMBER(10)       DEFAULT(0)      NOT NULL,
    EDC_CHAR_SEQ                NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD6                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD7                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD8                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD9                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD10                VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MSPCCALDAT
ADD CONSTRAINT MSPCCALDAT_PK PRIMARY KEY
(
    FACTORY,
    CHART_ID,
    HIST_SEQ,
    UNIT_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MSPCCALDAT_IDX_1 ON MSPCCALDAT
(
    FACTORY,
    CHART_ID,
    LOT_ID
) TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MSPCCALDAT_IDX_2 ON MSPCCALDAT
(
    FACTORY,
    CHART_ID,
    EDC_HIST_SEQ,
    RES_ID,
    SUBRES_ID
) TABLESPACE HISTORY_IDX_TS;


/* MSPCOOCHIS : EDC Data SPC Calculation */
CREATE TABLE MSPCOOCHIS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHART_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LOT_RES_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    OOC_TYPE                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    OOC_TYPE2                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    TRB_CODE                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRB_USER                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRB_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    TRB_COMMENT                 VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    ACT_CODE                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ACT_USER                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    ACT_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    ACT_COMMENT                 VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    INSPECTOR                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DELETE_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    DELETE_COMMENT              VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    EDC_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    EDC_UNIT_SEQ                NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MSPCOOCHIS
ADD CONSTRAINT MSPCOOCHIS_PK PRIMARY KEY
(
    FACTORY,
    CHART_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MSPCCHTUSR : SPC Chart User */
CREATE TABLE MSPCCHTUSR
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHART_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_DESC                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    SEC_GRP_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    EMAIL_ID                    VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSPCCHTUSR
ADD CONSTRAINT MSPCCHTUSR_PK PRIMARY KEY
(
    FACTORY,
    CHART_ID,
    USER_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSPCSUMDAT : SPC Summary Data History */
CREATE TABLE MSPCSUMDAT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHART_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* D : Day, W : Week, M : Month, Q : Quarter, Y : Year */
    PERIOD_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CAL_YEAR                    VARCHAR2(4)      DEFAULT(' ')    NOT NULL,
    CAL_QUARTER                 VARCHAR2(2)      DEFAULT(' ')    NOT NULL,
    CAL_MONTH                   VARCHAR2(2)      DEFAULT(' ')    NOT NULL,
    CAL_WEEK                    VARCHAR2(2)      DEFAULT(' ')    NOT NULL,
    CAL_DAY                     VARCHAR2(2)      DEFAULT(' ')    NOT NULL,
    STDDEV                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    XBARBAR                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RBAR                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RANGE                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    MIN_VALUE                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    MAX_VALUE                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CP                          VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CPK                         VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CPM                         VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PP                          VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PPK                         VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PPM                         VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OOC_COUNT                   NUMBER(6)        DEFAULT(0)      NOT NULL,
    OOC2_COUNT                  NUMBER(6)        DEFAULT(0)      NOT NULL,
    POINT_COUNT                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    GRADE                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    CAL_START_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    CAL_END_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MSPCSUMDAT
ADD CONSTRAINT MSPCSUMDAT_PK PRIMARY KEY
(
    FACTORY,
    CHART_ID,
    PERIOD_FLAG,
    CAL_YEAR,   
    CAL_QUARTER,
    CAL_MONTH,  
    CAL_WEEK,   
    CAL_DAY    
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MSPCALMHIS : */
CREATE TABLE MSPCALMHIS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHART_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    ALARM_ID                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LOT_RES_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    PROC_OPER                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PROC_RES_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    EVENT_ID                    VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    CHAR_ID                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    UNIT_ID                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    UNIT_SEQ                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    XR_FLAG                     CHAR(1)          DEFAULT(' ')    NOT NULL,
    OOC_TYPE                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    ALARM_LEVEL_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    ALARM_MSG                   VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    ACK_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    ACK_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    ACK_USER_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CLEAR_FLAG                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CLEAR_TIME                  VARCHAR(14)      DEFAULT(' ')    NOT NULL,
    CLEAR_USER_ID               VARCHAR(20)      DEFAULT(' ')    NOT NULL,
    CLEAR_COMMENT               VARCHAR(400)     DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR(20)      DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MSPCALMHIS
ADD CONSTRAINT MSPCALMHIS_PK PRIMARY KEY
(
    FACTORY,
    CHART_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MSPCSETDEF : */
CREATE TABLE MSPCSETDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHART_SET_ID                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHART_SET_DESC              VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LOT_RES_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHART_COMMENT               VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    CHTSET_GRP_1                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHTSET_GRP_2                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHTSET_GRP_3                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHTSET_GRP_4                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHTSET_GRP_5                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHTSET_GRP_6                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHTSET_GRP_7                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHTSET_GRP_8                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHTSET_GRP_9                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHTSET_GRP_10               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHTSET_CMF_1                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHTSET_CMF_2                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHTSET_CMF_3                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHTSET_CMF_4                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHTSET_CMF_5                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHTSET_CMF_6                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHTSET_CMF_7                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHTSET_CMF_8                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHTSET_CMF_9                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHTSET_CMF_10               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,    
   /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSPCSETDEF
ADD CONSTRAINT MSPCSETDEF_PK PRIMARY KEY
(
    FACTORY,
    CHART_SET_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSPCCHTSET : */
CREATE TABLE MSPCCHTSET
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHART_SET_ID                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHART_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSPCCHTSET
ADD CONSTRAINT MSPCCHTSET_PK PRIMARY KEY
(
    FACTORY,
    CHART_SET_ID,
    CHART_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSPCDELHIS : */
CREATE TABLE MSPCDELHIS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHART_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    UNIT_SEQ                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    TRAN_FLAG                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT                VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MSPCDELHIS 
ADD CONSTRAINT MSPCDELHIS_PK PRIMARY KEY 
(
    FACTORY, 
    CHART_ID, 
    HIST_SEQ, 
    UNIT_SEQ,
    TRAN_TIME
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MSPCCHTMFO : */
CREATE TABLE MSPCCHTMFO
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Option Level - '1':M-F-O, '2':F-O, '3':O */
    OPT_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Collection Set ID */
    CHART_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHART_FLAG                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Collection Set Overide Flag */
    OVR_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSPCCHTMFO
ADD CONSTRAINT MSPCCHTMFO_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    OPER
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MSPCPRTDEF : */
CREATE TABLE MSPCPRTDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHART_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_1                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_2                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_3                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_4                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_5                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_6                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_7                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_8                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_9                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_10                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_11                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_12                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_13                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_14                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_15                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_16                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_17                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_18                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_19                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_20                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_21                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_22                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_23                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_24                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_25                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_26                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_27                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_28                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_29                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_30                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_31                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_32                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_33                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_34                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_35                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_36                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_37                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_38                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_39                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_40                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_41                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_42                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_43                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_44                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_45                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_46                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_47                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_48                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_49                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_50                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_51                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_52                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_53                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_54                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_55                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_56                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_57                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_58                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_59                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_60                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_61                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_62                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_63                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_64                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_65                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_66                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_67                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_68                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_69                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_70                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_71                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_72                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_73                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_74                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_75                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_76                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_77                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_78                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_79                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_80                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_81                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_82                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_83                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_84                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_85                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_86                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_87                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_88                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_89                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_90                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_91                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_92                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_93                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_94                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_95                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_96                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_97                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_98                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_99                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRT_100                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL    
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSPCPRTDEF
ADD CONSTRAINT MSPCPRTDEF_PK PRIMARY KEY
(
    FACTORY,
    CHART_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* Added By YJJung 160217 For The Rule Extended information of Chart */

CREATE TABLE MSPCRULEXT
(
    FACTORY                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHART_ID                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_11                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_12                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_13                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_14                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_15                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_16                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_17                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_18                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_19                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    XRULE_20                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_11                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_12                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_13                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_14                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_15                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_16                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_17                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_18                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_19                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RRULE_20                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSPCRULEXT
ADD CONSTRAINT MSPCRULEXT_PK PRIMARY KEY
(
    FACTORY,
    CHART_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;




/* Added By YJJung 160217 For The Rule Extended History of OOC */
/* MSPCOOCEXT : OOC History (extended) */
CREATE TABLE MSPCOOCEXT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHART_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    X_OOC_MSG_1                 VARCHAR2(100)     DEFAULT(' ')    NOT NULL,
    X_OOC_MSG_2                 VARCHAR2(100)     DEFAULT(' ')    NOT NULL,
    X_OOC_MSG_3                 VARCHAR2(100)     DEFAULT(' ')    NOT NULL,
    R_OOC_MSG_1                 VARCHAR2(100)     DEFAULT(' ')    NOT NULL,
    R_OOC_MSG_2                 VARCHAR2(100)     DEFAULT(' ')    NOT NULL,
    R_OOC_MSG_3                 VARCHAR2(100)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MSPCOOCEXT
ADD CONSTRAINT MSPCOOCEXT_PK PRIMARY KEY
(
    FACTORY,
    CHART_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;
