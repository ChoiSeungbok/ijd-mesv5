/*
**
**  File Name    : MESplusV5-Table-Migration.sql
**  Description  : MESplus V5 Release Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g
**
**  Period       : 2009.02.09 ~ ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
**
**  Revision History
**  Seq   Date        Modifier      Description                        
**  ---------------------------------------------------------------------------
**  1     2009.02.09  Aiden         Make file
**  2     2009.02.19  Aiden         Modify MSVMSVCDEF
**  3     2009.02.23  Aiden         Add 'IsUseCellGrade' global option
**  4     2009.02.25  Aiden         Modify 'WIP_Loss_Lot_Ext', 'SVM_Update_Service' service member
**  5     2009.02.25  Phillip       Add LOT_CONDITION GCM Table
**  6     2009.03.02  HKYUNG        Added FMB Service Member, GCM Table Script
**  7     2009.03.02  Aiden         Added RAS-0282
   
*/
Insert into msecfundef
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ADM1007', '[ADM] Replication Database', 'F', 'ADMIN', 'Admin.RPTCore.dll', 'Admin.RPTCore.frmDBReplicator', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20090205154428', ' ', ' ');
Insert into msecfundef
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ADM1009', '[ADM] Create View Trigger', 'F', 'ADMIN', 'Admin.RPTCore.dll', 'Admin.RPTCore.frmDBViewTrig', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20090205154544', ' ', ' ');

delete from msecgrpfun
where FUNC_NAME like 'ADM%' and factory = 'SYSTEM' and PROGRAM_ID = 'ADMINClient';

Insert into msecgrpfun
   (FACTORY, PROGRAM_ID, SEC_GRP_ID, FUNC_NAME, DISP_LEVEL, SEPARATOR, SHORT_CUT, ADD_TOOL_BAR, CTL_EN_FLAG_1, CTL_EN_FLAG_2, CTL_EN_FLAG_3, CTL_EN_FLAG_4, CTL_EN_FLAG_5, CTL_EN_FLAG_6, CTL_EN_FLAG_7, CTL_EN_FLAG_8, CTL_EN_FLAG_9, CTL_EN_FLAG_10, TAB_DS_FLAG_1, TAB_DS_FLAG_2, TAB_DS_FLAG_3, TAB_DS_FLAG_4, TAB_DS_FLAG_5, TAB_DS_FLAG_6, TAB_DS_FLAG_7, TAB_DS_FLAG_8, TAB_DS_FLAG_9, TAB_DS_FLAG_10, OPT_VALUE_1, OPT_VALUE_2, OPT_VALUE_3, OPT_VALUE_4, OPT_VALUE_5, OPT_VALUE_6, OPT_VALUE_7, OPT_VALUE_8, OPT_VALUE_9, OPT_VALUE_10, FLD_EN_ALL_FLAG, FLD_EN_MASK, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'ADMINClient', 'DEFAULT_ADMIN_FUNC', 'ADM1000', '!', ' ', ' ', 'N', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20090212174507', ' ', ' ');
Insert into msecgrpfun
   (FACTORY, PROGRAM_ID, SEC_GRP_ID, FUNC_NAME, DISP_LEVEL, SEPARATOR, SHORT_CUT, ADD_TOOL_BAR, CTL_EN_FLAG_1, CTL_EN_FLAG_2, CTL_EN_FLAG_3, CTL_EN_FLAG_4, CTL_EN_FLAG_5, CTL_EN_FLAG_6, CTL_EN_FLAG_7, CTL_EN_FLAG_8, CTL_EN_FLAG_9, CTL_EN_FLAG_10, TAB_DS_FLAG_1, TAB_DS_FLAG_2, TAB_DS_FLAG_3, TAB_DS_FLAG_4, TAB_DS_FLAG_5, TAB_DS_FLAG_6, TAB_DS_FLAG_7, TAB_DS_FLAG_8, TAB_DS_FLAG_9, TAB_DS_FLAG_10, OPT_VALUE_1, OPT_VALUE_2, OPT_VALUE_3, OPT_VALUE_4, OPT_VALUE_5, OPT_VALUE_6, OPT_VALUE_7, OPT_VALUE_8, OPT_VALUE_9, OPT_VALUE_10, FLD_EN_ALL_FLAG, FLD_EN_MASK, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'ADMINClient', 'DEFAULT_ADMIN_FUNC', 'ADM1001', '!.!', ' ', ' ', 'N', 'Y', 'Y', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20090212174507', ' ', ' ');
Insert into msecgrpfun
   (FACTORY, PROGRAM_ID, SEC_GRP_ID, FUNC_NAME, DISP_LEVEL, SEPARATOR, SHORT_CUT, ADD_TOOL_BAR, CTL_EN_FLAG_1, CTL_EN_FLAG_2, CTL_EN_FLAG_3, CTL_EN_FLAG_4, CTL_EN_FLAG_5, CTL_EN_FLAG_6, CTL_EN_FLAG_7, CTL_EN_FLAG_8, CTL_EN_FLAG_9, CTL_EN_FLAG_10, TAB_DS_FLAG_1, TAB_DS_FLAG_2, TAB_DS_FLAG_3, TAB_DS_FLAG_4, TAB_DS_FLAG_5, TAB_DS_FLAG_6, TAB_DS_FLAG_7, TAB_DS_FLAG_8, TAB_DS_FLAG_9, TAB_DS_FLAG_10, OPT_VALUE_1, OPT_VALUE_2, OPT_VALUE_3, OPT_VALUE_4, OPT_VALUE_5, OPT_VALUE_6, OPT_VALUE_7, OPT_VALUE_8, OPT_VALUE_9, OPT_VALUE_10, FLD_EN_ALL_FLAG, FLD_EN_MASK, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'ADMINClient', 'DEFAULT_ADMIN_FUNC', 'ADM1002', '!."', ' ', ' ', 'N', 'Y', 'Y', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20090212174507', ' ', ' ');
Insert into msecgrpfun
   (FACTORY, PROGRAM_ID, SEC_GRP_ID, FUNC_NAME, DISP_LEVEL, SEPARATOR, SHORT_CUT, ADD_TOOL_BAR, CTL_EN_FLAG_1, CTL_EN_FLAG_2, CTL_EN_FLAG_3, CTL_EN_FLAG_4, CTL_EN_FLAG_5, CTL_EN_FLAG_6, CTL_EN_FLAG_7, CTL_EN_FLAG_8, CTL_EN_FLAG_9, CTL_EN_FLAG_10, TAB_DS_FLAG_1, TAB_DS_FLAG_2, TAB_DS_FLAG_3, TAB_DS_FLAG_4, TAB_DS_FLAG_5, TAB_DS_FLAG_6, TAB_DS_FLAG_7, TAB_DS_FLAG_8, TAB_DS_FLAG_9, TAB_DS_FLAG_10, OPT_VALUE_1, OPT_VALUE_2, OPT_VALUE_3, OPT_VALUE_4, OPT_VALUE_5, OPT_VALUE_6, OPT_VALUE_7, OPT_VALUE_8, OPT_VALUE_9, OPT_VALUE_10, FLD_EN_ALL_FLAG, FLD_EN_MASK, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'ADMINClient', 'DEFAULT_ADMIN_FUNC', 'ADM1003', '!.#', ' ', ' ', 'N', 'Y', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20090212174507', ' ', ' ');
Insert into msecgrpfun
   (FACTORY, PROGRAM_ID, SEC_GRP_ID, FUNC_NAME, DISP_LEVEL, SEPARATOR, SHORT_CUT, ADD_TOOL_BAR, CTL_EN_FLAG_1, CTL_EN_FLAG_2, CTL_EN_FLAG_3, CTL_EN_FLAG_4, CTL_EN_FLAG_5, CTL_EN_FLAG_6, CTL_EN_FLAG_7, CTL_EN_FLAG_8, CTL_EN_FLAG_9, CTL_EN_FLAG_10, TAB_DS_FLAG_1, TAB_DS_FLAG_2, TAB_DS_FLAG_3, TAB_DS_FLAG_4, TAB_DS_FLAG_5, TAB_DS_FLAG_6, TAB_DS_FLAG_7, TAB_DS_FLAG_8, TAB_DS_FLAG_9, TAB_DS_FLAG_10, OPT_VALUE_1, OPT_VALUE_2, OPT_VALUE_3, OPT_VALUE_4, OPT_VALUE_5, OPT_VALUE_6, OPT_VALUE_7, OPT_VALUE_8, OPT_VALUE_9, OPT_VALUE_10, FLD_EN_ALL_FLAG, FLD_EN_MASK, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'ADMINClient', 'DEFAULT_ADMIN_FUNC', 'ADM1004', '!.$', 'Y', ' ', 'N', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20090212174507', ' ', ' ');
Insert into msecgrpfun
   (FACTORY, PROGRAM_ID, SEC_GRP_ID, FUNC_NAME, DISP_LEVEL, SEPARATOR, SHORT_CUT, ADD_TOOL_BAR, CTL_EN_FLAG_1, CTL_EN_FLAG_2, CTL_EN_FLAG_3, CTL_EN_FLAG_4, CTL_EN_FLAG_5, CTL_EN_FLAG_6, CTL_EN_FLAG_7, CTL_EN_FLAG_8, CTL_EN_FLAG_9, CTL_EN_FLAG_10, TAB_DS_FLAG_1, TAB_DS_FLAG_2, TAB_DS_FLAG_3, TAB_DS_FLAG_4, TAB_DS_FLAG_5, TAB_DS_FLAG_6, TAB_DS_FLAG_7, TAB_DS_FLAG_8, TAB_DS_FLAG_9, TAB_DS_FLAG_10, OPT_VALUE_1, OPT_VALUE_2, OPT_VALUE_3, OPT_VALUE_4, OPT_VALUE_5, OPT_VALUE_6, OPT_VALUE_7, OPT_VALUE_8, OPT_VALUE_9, OPT_VALUE_10, FLD_EN_ALL_FLAG, FLD_EN_MASK, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'ADMINClient', 'DEFAULT_ADMIN_FUNC', 'ADM1005', '!.%', ' ', ' ', 'N', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20090212174507', ' ', ' ');
Insert into msecgrpfun
   (FACTORY, PROGRAM_ID, SEC_GRP_ID, FUNC_NAME, DISP_LEVEL, SEPARATOR, SHORT_CUT, ADD_TOOL_BAR, CTL_EN_FLAG_1, CTL_EN_FLAG_2, CTL_EN_FLAG_3, CTL_EN_FLAG_4, CTL_EN_FLAG_5, CTL_EN_FLAG_6, CTL_EN_FLAG_7, CTL_EN_FLAG_8, CTL_EN_FLAG_9, CTL_EN_FLAG_10, TAB_DS_FLAG_1, TAB_DS_FLAG_2, TAB_DS_FLAG_3, TAB_DS_FLAG_4, TAB_DS_FLAG_5, TAB_DS_FLAG_6, TAB_DS_FLAG_7, TAB_DS_FLAG_8, TAB_DS_FLAG_9, TAB_DS_FLAG_10, OPT_VALUE_1, OPT_VALUE_2, OPT_VALUE_3, OPT_VALUE_4, OPT_VALUE_5, OPT_VALUE_6, OPT_VALUE_7, OPT_VALUE_8, OPT_VALUE_9, OPT_VALUE_10, FLD_EN_ALL_FLAG, FLD_EN_MASK, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'ADMINClient', 'DEFAULT_ADMIN_FUNC', 'ADM1006', '!.&', ' ', ' ', 'N', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20090212174507', ' ', ' ');
Insert into msecgrpfun
   (FACTORY, PROGRAM_ID, SEC_GRP_ID, FUNC_NAME, DISP_LEVEL, SEPARATOR, SHORT_CUT, ADD_TOOL_BAR, CTL_EN_FLAG_1, CTL_EN_FLAG_2, CTL_EN_FLAG_3, CTL_EN_FLAG_4, CTL_EN_FLAG_5, CTL_EN_FLAG_6, CTL_EN_FLAG_7, CTL_EN_FLAG_8, CTL_EN_FLAG_9, CTL_EN_FLAG_10, TAB_DS_FLAG_1, TAB_DS_FLAG_2, TAB_DS_FLAG_3, TAB_DS_FLAG_4, TAB_DS_FLAG_5, TAB_DS_FLAG_6, TAB_DS_FLAG_7, TAB_DS_FLAG_8, TAB_DS_FLAG_9, TAB_DS_FLAG_10, OPT_VALUE_1, OPT_VALUE_2, OPT_VALUE_3, OPT_VALUE_4, OPT_VALUE_5, OPT_VALUE_6, OPT_VALUE_7, OPT_VALUE_8, OPT_VALUE_9, OPT_VALUE_10, FLD_EN_ALL_FLAG, FLD_EN_MASK, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'ADMINClient', 'DEFAULT_ADMIN_FUNC', 'ADM1007', '!.''', 'Y', ' ', ' ', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20090212174507', ' ', ' ');
Insert into msecgrpfun
   (FACTORY, PROGRAM_ID, SEC_GRP_ID, FUNC_NAME, DISP_LEVEL, SEPARATOR, SHORT_CUT, ADD_TOOL_BAR, CTL_EN_FLAG_1, CTL_EN_FLAG_2, CTL_EN_FLAG_3, CTL_EN_FLAG_4, CTL_EN_FLAG_5, CTL_EN_FLAG_6, CTL_EN_FLAG_7, CTL_EN_FLAG_8, CTL_EN_FLAG_9, CTL_EN_FLAG_10, TAB_DS_FLAG_1, TAB_DS_FLAG_2, TAB_DS_FLAG_3, TAB_DS_FLAG_4, TAB_DS_FLAG_5, TAB_DS_FLAG_6, TAB_DS_FLAG_7, TAB_DS_FLAG_8, TAB_DS_FLAG_9, TAB_DS_FLAG_10, OPT_VALUE_1, OPT_VALUE_2, OPT_VALUE_3, OPT_VALUE_4, OPT_VALUE_5, OPT_VALUE_6, OPT_VALUE_7, OPT_VALUE_8, OPT_VALUE_9, OPT_VALUE_10, FLD_EN_ALL_FLAG, FLD_EN_MASK, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'ADMINClient', 'DEFAULT_ADMIN_FUNC', 'ADM1009', '!.(', ' ', ' ', ' ', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20090212174507', ' ', ' ');
Insert into msecgrpfun
   (FACTORY, PROGRAM_ID, SEC_GRP_ID, FUNC_NAME, DISP_LEVEL, SEPARATOR, SHORT_CUT, ADD_TOOL_BAR, CTL_EN_FLAG_1, CTL_EN_FLAG_2, CTL_EN_FLAG_3, CTL_EN_FLAG_4, CTL_EN_FLAG_5, CTL_EN_FLAG_6, CTL_EN_FLAG_7, CTL_EN_FLAG_8, CTL_EN_FLAG_9, CTL_EN_FLAG_10, TAB_DS_FLAG_1, TAB_DS_FLAG_2, TAB_DS_FLAG_3, TAB_DS_FLAG_4, TAB_DS_FLAG_5, TAB_DS_FLAG_6, TAB_DS_FLAG_7, TAB_DS_FLAG_8, TAB_DS_FLAG_9, TAB_DS_FLAG_10, OPT_VALUE_1, OPT_VALUE_2, OPT_VALUE_3, OPT_VALUE_4, OPT_VALUE_5, OPT_VALUE_6, OPT_VALUE_7, OPT_VALUE_8, OPT_VALUE_9, OPT_VALUE_10, FLD_EN_ALL_FLAG, FLD_EN_MASK, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'ADMINClient', 'DEFAULT_ADMIN_FUNC', 'ADM3001', '"', ' ', ' ', 'N', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20090212174507', ' ', ' ');


RENAME MWIPSLTSTS TO MWIPSLTSTS_OLD;

/* MWIPSLTSTS : Sub Lot Status Table */
CREATE TABLE MWIPSLTSTS 
(
    /* Lot ID는 모든 Factory에서 Unique */
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
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
    SLOT_NO                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Quantity 2 ~ 3 */
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* 캐리어 ID */
    CRR_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Owner Code, Create Code */
    OWNER_CODE                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CREATE_CODE                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Lot Status - PROC:In Process, WAIT:Wait, MOVE : Moving */
    SUBLOT_STATUS               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Hold Info. */
    HOLD_FLAG                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    HOLD_CODE                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    HOLD_PASSWORD               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Release 권한을 가지는 권한 그룹 */
    HOLD_PRV_GRP_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    /* Oper In Quantity 2 ~ 3 */
    OPER_IN_QTY_2               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OPER_IN_QTY_3               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Create Qty 1~3 */
    CREATE_QTY_2                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CREATE_QTY_3                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Start Quantity 2 ~ 3 */
    START_QTY_2                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,  /* Add For V42 */
    START_QTY_3                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,  /* Add For V42 */
    /* Inventory Operation에 들어 있음. MOVE 불가능 */
    INV_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* RECEIVING 대기 */
    TRANSIT_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Unit Exist Flag */
    UNIT_EXIST_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,  /* Add For V42 tracking flag 대치*/
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
    /* Non Standard Info. */
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
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FAC_IN_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FLOW_IN_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OPER_IN_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
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
    /* Reserve 된 Resource ID */
    RESERVE_RES_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PORT_ID                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SUBLOT_LOCATION_1           VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBLOT_LOCATION_2           VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBLOT_LOCATION_3           VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* LOT 생성시 SET, ADAPT로 수정 가능 */
    SUBLOT_CMF_1                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_2                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_3                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_4                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_5                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_6                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_7                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_8                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_9                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_10               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_11               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_12               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_13               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_14               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_15               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_16               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_17               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_18               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_19               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_20               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* LOT 이 지워졌을때 SETTING */
    SUBLOT_DEL_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    SUBLOT_DEL_CODE             VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SUBLOT_DEL_TIME             VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    GRADE                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    GRADE_CODE                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CELL_GRADE                  VARCHAR2(500)    DEFAULT(' ')    NOT NULL, /* Mod For BOE 2009.02 */
    CELL_JUDGE                  VARCHAR2(500)    DEFAULT(' ')    NOT NULL, /* Add For BOE 2009.02 */   
    /* Transaction lot으로 진행 되었는지 sublot으로 진행 되었는지 구분 */
    LOT_BASE                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOT_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Last Tran Info. */
    /* Last Active History Seq(Requested by Fred) */
    /* History가 지워진 경우 마지막 Active History Seq Number 필요 */
    LAST_TRAN_CODE              VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    LAST_TRAN_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LAST_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    LAST_ACTIVE_HIST_SEQ        NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Last History Sequence Number(Only Increase) */
    LAST_HIST_SEQ               NUMBER(10)       DEFAULT(0)      NOT NULL
) TABLESPACE MESPLUS_DATA_TS;


INSERT INTO MWIPSLTSTS VALUE (
SELECT 
    SUBLOT_ID                   ,
    LOT_ID                      ,
    FACTORY                     ,
    MAT_ID                      ,
    MAT_VER                     ,
    FLOW                        ,
    FLOW_SEQ_NUM                ,
    OPER                        ,
    SLOT_NO                     ,
    QTY_2                       ,
    QTY_3                       ,
    CRR_ID                      ,
    OWNER_CODE                  ,
    CREATE_CODE                 ,
    SUBLOT_STATUS               ,
    HOLD_FLAG                   ,
    HOLD_CODE                   ,
    HOLD_PASSWORD               ,
    HOLD_PRV_GRP_ID             ,
    OPER_IN_QTY_2               ,
    OPER_IN_QTY_3               ,
    CREATE_QTY_2                ,
    CREATE_QTY_3                ,
    START_QTY_2                 ,
    START_QTY_3                 ,
    INV_FLAG                    ,
    TRANSIT_FLAG                ,
    UNIT_EXIST_FLAG             ,
    INV_UNIT                    ,
    RWK_FLAG                    ,
    RWK_CODE                    ,
    RWK_COUNT                   ,
    RWK_RET_FLOW                ,
    RWK_RET_FLOW_SEQ_NUM        ,
    RWK_RET_OPER                ,
    RWK_END_FLOW                ,
    RWK_END_FLOW_SEQ_NUM        ,
    RWK_END_OPER                ,
    RWK_RET_CLEAR_FLAG          ,
    RWK_TIME                    ,
    NSTD_FLAG                   ,
    NSTD_RET_FLOW               ,
    NSTD_RET_FLOW_SEQ_NUM       ,
    NSTD_RET_OPER               ,
    NSTD_TIME                   ,
    REP_FLAG                    ,
    REP_RET_OPER                ,
    STR_RET_FLOW                ,
    STR_RET_FLOW_SEQ_NUM        ,
    STR_RET_OPER                ,
    CREATE_TIME                 ,
    FAC_IN_TIME                 ,
    FLOW_IN_TIME                ,
    OPER_IN_TIME                ,
    START_FLAG                  ,
    START_TIME                  ,
    START_RES_ID                ,
    END_FLAG                    ,
    END_TIME                    ,
    END_RES_ID                  ,
    SAMPLE_FLAG                 ,
    SAMPLE_WAIT_FLAG            ,
    SAMPLE_RESULT               ,
    RESERVE_RES_ID              ,
    PORT_ID                     ,
    SUBLOT_LOCATION_1           ,
    SUBLOT_LOCATION_2           ,
    SUBLOT_LOCATION_3           ,
    SUBRES_ID                   ,
    SUBLOT_CMF_1                ,
    SUBLOT_CMF_2                ,
    SUBLOT_CMF_3                ,
    SUBLOT_CMF_4                ,
    SUBLOT_CMF_5                ,
    SUBLOT_CMF_6                ,
    SUBLOT_CMF_7                ,
    SUBLOT_CMF_8                ,
    SUBLOT_CMF_9                ,
    SUBLOT_CMF_10               ,
    SUBLOT_CMF_11               ,
    SUBLOT_CMF_12               ,
    SUBLOT_CMF_13               ,
    SUBLOT_CMF_14               ,
    SUBLOT_CMF_15               ,
    SUBLOT_CMF_16               ,
    SUBLOT_CMF_17               ,
    SUBLOT_CMF_18               ,
    SUBLOT_CMF_19               ,
    SUBLOT_CMF_20               ,
    SUBLOT_DEL_FLAG             ,
    SUBLOT_DEL_CODE             ,
    SUBLOT_DEL_TIME             ,
    GRADE                       ,
    GRADE_CODE                  ,
    CELL_GRADE                  ,
    ' '                         ,
    LOT_BASE                    ,
    LOT_HIST_SEQ                ,
    LAST_TRAN_CODE              ,
    LAST_TRAN_TIME              ,
    LAST_COMMENT                ,
    LAST_ACTIVE_HIST_SEQ        ,
    LAST_HIST_SEQ               
    FROM MWIPSLTSTS_OLD
    );



DROP TABLE MWIPSLTSTS_OLD CASCADE CONSTRAINT PURGE;

ALTER TABLE MWIPSLTSTS
ADD CONSTRAINT MWIPSLTSTS_PK PRIMARY KEY
(
    SUBLOT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

CREATE INDEX MWIPSLTSTS_IDX_1 ON MWIPSLTSTS
(
    LOT_ID, 
    SLOT_NO
) TABLESPACE MESPLUS_IDX_TS; 

CREATE INDEX MWIPSLTSTS_IDX_2 ON MWIPSLTSTS
(
    FACTORY,
    SUBLOT_DEL_FLAG,
    CRR_ID,
    SLOT_NO
) TABLESPACE MESPLUS_IDX_TS; 









RENAME MWIPSLTHIS TO MWIPSLTHIS_OLD;

/* MWIPSLTHIS : Sub Lot History Table */
CREATE TABLE MWIPSLTHIS 
(
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    SYS_TRAN_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    TRAN_CODE                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SLOT_NO                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CRR_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OWNER_CODE                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CREATE_CODE                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SUBLOT_STATUS               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    HOLD_FLAG                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    HOLD_CODE                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    HOLD_PASSWORD               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Release 권한을 가지는 권한 그룹 */
    HOLD_PRV_GRP_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    OPER_IN_QTY_2               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OPER_IN_QTY_3               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CREATE_QTY_2                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CREATE_QTY_3                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Start Quantity 1 ~ 3 */
    START_QTY_2                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,  /* Add For V42 */
    START_QTY_3                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,  /* Add For V42 */
    INV_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    TRANSIT_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Unit Exist Flag */
    UNIT_EXIST_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,  /* Add For V42 tracking flag 대치*/
    INV_UNIT                    VARCHAR2(10)     DEFAULT(0.0)    NOT NULL,
    RWK_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    RWK_CODE                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RWK_COUNT                   NUMBER(6)        DEFAULT(0)      NOT NULL,
    RWK_RET_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RWK_RET_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    RWK_RET_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RWK_END_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RWK_END_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    RWK_END_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RWK_RET_CLEAR_FLAG          CHAR(1)          DEFAULT(' ')    NOT NULL,
    RWK_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    NSTD_FLAG                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    NSTD_RET_FLOW               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    NSTD_RET_FLOW_SEQ_NUM       NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    NSTD_RET_OPER               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    NSTD_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    REP_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    REP_RET_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Store Return Info. */
    STR_RET_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,  /* Add For V5 */
    STR_RET_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V5 */
    STR_RET_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,  /* Add For V5 */
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FAC_IN_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FLOW_IN_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OPER_IN_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    START_FLAG                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    START_TIME                  VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    START_RES_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    END_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    END_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    END_RES_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SAMPLE_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    SAMPLE_WAIT_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    SAMPLE_RESULT               CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESERVE_RES_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PORT_ID                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SUBLOT_LOCATION_1           VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBLOT_LOCATION_2           VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBLOT_LOCATION_3           VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_1                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_2                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_3                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_4                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_5                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_6                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_7                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_8                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_9                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_10               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_11               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_12               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_13               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_14               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_15               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_16               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_17               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_18               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_19               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_CMF_20               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_DEL_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    SUBLOT_DEL_CODE             VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SUBLOT_DEL_TIME             VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    GRADE                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    GRADE_CODE                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CELL_GRADE                  VARCHAR2(500)    DEFAULT(' ')    NOT NULL, /* Mod For BOE 2009.02 */
    CELL_JUDGE                  VARCHAR2(500)    DEFAULT(' ')    NOT NULL, /* Add For BOE 2009.02 */   
    LOT_BASE                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOT_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    OLD_FACTORY                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    OLD_MAT_ID                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_MAT_VER                 NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    OLD_FLOW                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OLD_FLOW_SEQ_NUM            NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 */
    OLD_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    OLD_QTY_2                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OLD_QTY_3                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OLD_CRR_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OLD_OWNER_CODE              VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    OLD_CREATE_CODE             VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    OLD_FAC_IN_TIME             VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OLD_FLOW_IN_TIME            VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OLD_OPER_IN_TIME            VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
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
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    PREV_ACTIVE_HIST_SEQ        NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* - Multi Transaction을 한번에 삭제할 경우 */
    MULTI_TR_KEY                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 HIST_START_SEQ 대치*/
    MULTI_TR_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,  /* Add For V42 */
    /* For additional extended table */
    EXT_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,  /* Add For V5 */
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    HIST_DEL_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_COMMENT            VARCHAR2(400)    DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;



INSERT INTO MWIPSLTHIS VALUE (
SELECT 
    SUBLOT_ID                   ,
    HIST_SEQ                    ,
    TRAN_TIME                   ,
    SYS_TRAN_TIME               ,
    TRAN_CODE                   ,
    LOT_ID                      ,
    FACTORY                     ,
    MAT_ID                      ,
    MAT_VER                     ,
    FLOW                        ,
    FLOW_SEQ_NUM                ,
    OPER                        ,
    SLOT_NO                     ,
    QTY_2                       ,
    QTY_3                       ,
    CRR_ID                      ,
    OWNER_CODE                  ,
    CREATE_CODE                 ,
    SUBLOT_STATUS               ,
    HOLD_FLAG                   ,
    HOLD_CODE                   ,
    HOLD_PASSWORD               ,
    HOLD_PRV_GRP_ID             ,
    OPER_IN_QTY_2               ,
    OPER_IN_QTY_3               ,
    CREATE_QTY_2                ,
    CREATE_QTY_3                ,
    START_QTY_2                 ,
    START_QTY_3                 ,
    INV_FLAG                    ,
    TRANSIT_FLAG                ,
    UNIT_EXIST_FLAG             ,
    INV_UNIT                    ,
    RWK_FLAG                    ,
    RWK_CODE                    ,
    RWK_COUNT                   ,
    RWK_RET_FLOW                ,
    RWK_RET_FLOW_SEQ_NUM        ,
    RWK_RET_OPER                ,
    RWK_END_FLOW                ,
    RWK_END_FLOW_SEQ_NUM        ,
    RWK_END_OPER                ,
    RWK_RET_CLEAR_FLAG          ,
    RWK_TIME                    ,
    NSTD_FLAG                   ,
    NSTD_RET_FLOW               ,
    NSTD_RET_FLOW_SEQ_NUM       ,
    NSTD_RET_OPER               ,
    NSTD_TIME                   ,
    REP_FLAG                    ,
    REP_RET_OPER                ,
    STR_RET_FLOW                ,
    STR_RET_FLOW_SEQ_NUM        ,
    STR_RET_OPER                ,
    CREATE_TIME                 ,
    FAC_IN_TIME                 ,
    FLOW_IN_TIME                ,
    OPER_IN_TIME                ,
    START_FLAG                  ,
    START_TIME                  ,
    START_RES_ID                ,
    END_FLAG                    ,
    END_TIME                    ,
    END_RES_ID                  ,
    SAMPLE_FLAG                 ,
    SAMPLE_WAIT_FLAG            ,
    SAMPLE_RESULT               ,
    RESERVE_RES_ID              ,
    PORT_ID                     ,
    SUBLOT_LOCATION_1           ,
    SUBLOT_LOCATION_2           ,
    SUBLOT_LOCATION_3           ,
    SUBRES_ID                   ,
    SUBLOT_CMF_1                ,
    SUBLOT_CMF_2                ,
    SUBLOT_CMF_3                ,
    SUBLOT_CMF_4                ,
    SUBLOT_CMF_5                ,
    SUBLOT_CMF_6                ,
    SUBLOT_CMF_7                ,
    SUBLOT_CMF_8                ,
    SUBLOT_CMF_9                ,
    SUBLOT_CMF_10               ,
    SUBLOT_CMF_11               ,
    SUBLOT_CMF_12               ,
    SUBLOT_CMF_13               ,
    SUBLOT_CMF_14               ,
    SUBLOT_CMF_15               ,
    SUBLOT_CMF_16               ,
    SUBLOT_CMF_17               ,
    SUBLOT_CMF_18               ,
    SUBLOT_CMF_19               ,
    SUBLOT_CMF_20               ,
    SUBLOT_DEL_FLAG             ,
    SUBLOT_DEL_CODE             ,
    SUBLOT_DEL_TIME             ,
    GRADE                       ,
    GRADE_CODE                  ,
    CELL_GRADE                  ,
    ' '                  ,
    LOT_BASE                    ,
    LOT_HIST_SEQ                ,
    OLD_FACTORY                 ,
    OLD_MAT_ID                  ,
    OLD_MAT_VER                 ,
    OLD_FLOW                    ,
    OLD_FLOW_SEQ_NUM            ,
    OLD_OPER                    ,
    OLD_QTY_2                   ,
    OLD_QTY_3                   ,
    OLD_CRR_ID                  ,
    OLD_OWNER_CODE              ,
    OLD_CREATE_CODE             ,
    OLD_FAC_IN_TIME             ,
    OLD_FLOW_IN_TIME            ,
    OLD_OPER_IN_TIME            ,
    TRAN_CMF_1                  ,
    TRAN_CMF_2                  ,
    TRAN_CMF_3                  ,
    TRAN_CMF_4                  ,
    TRAN_CMF_5                  ,
    TRAN_CMF_6                  ,
    TRAN_CMF_7                  ,
    TRAN_CMF_8                  ,
    TRAN_CMF_9                  ,
    TRAN_CMF_10                 ,
    TRAN_CMF_11                 ,
    TRAN_CMF_12                 ,
    TRAN_CMF_13                 ,
    TRAN_CMF_14                 ,
    TRAN_CMF_15                 ,
    TRAN_CMF_16                 ,
    TRAN_CMF_17                 ,
    TRAN_CMF_18                 ,
    TRAN_CMF_19                 ,
    TRAN_CMF_20                 ,
    TRAN_USER_ID                ,
    TRAN_COMMENT                ,
    PREV_ACTIVE_HIST_SEQ        ,
    MULTI_TR_KEY                ,
    MULTI_TR_SEQ                ,
    EXT_HIST_SEQ                ,
    HIST_DEL_FLAG               ,
    HIST_DEL_TIME               ,
    HIST_DEL_USER_ID            ,
    HIST_DEL_COMMENT            
    FROM MWIPSLTHIS_OLD
    );
    

DROP TABLE MWIPSLTHIS_OLD CASCADE CONSTRAINT PURGE;

ALTER TABLE MWIPSLTHIS
ADD CONSTRAINT MWIPSLTHIS_PK PRIMARY KEY
(
    SUBLOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MWIPSLTHIS_IDX_1 ON MWIPSLTHIS
(
    SUBLOT_ID,
    HIST_DEL_FLAG,
    TRAN_CODE
) TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MWIPSLTHIS_IDX_2 ON MWIPSLTHIS
(
    TRAN_TIME,
    SUBLOT_ID,
    HIST_DEL_FLAG,
    TRAN_CODE
) TABLESPACE HISTORY_IDX_TS;


RENAME MWIPSLTLOS TO MWIPSLTLOS_OLD;

/* MWIPSLTLOS : Sub Lot Loss History Table */
CREATE TABLE MWIPSLTLOS
(
  SUBLOT_ID      VARCHAR2(30 BYTE)              DEFAULT (' ')                 NOT NULL,
  LOT_ID         VARCHAR2(25 BYTE)              DEFAULT (' ')                 NOT NULL,
  HIST_SEQ       NUMBER(10)                     DEFAULT (0)                   NOT NULL,
  LOT_HIST_SEQ       NUMBER(10)                     DEFAULT (0)                   NOT NULL,
  QTY_FLAG       CHAR(1 BYTE)                   DEFAULT ('1')                 NOT NULL,
  GRADE          CHAR(1 BYTE)                   DEFAULT (' ')                 NOT NULL,
  LOSS_CODE      VARCHAR2(10 BYTE)              DEFAULT (' ')                 NOT NULL,
  TRAN_TIME      VARCHAR2(14 BYTE)              DEFAULT (' ')                 NOT NULL,
  HIST_DEL_FLAG  CHAR(1 BYTE)                   DEFAULT (' ')                 NOT NULL,
  FACTORY        VARCHAR2(10 BYTE)              DEFAULT (' ')                 NOT NULL,
  MAT_ID         VARCHAR2(30 BYTE)              DEFAULT (' ')                 NOT NULL,
  MAT_VER        NUMBER(6)                      DEFAULT (0)                   NOT NULL,
  FLOW           VARCHAR2(20 BYTE)              DEFAULT (' ')                 NOT NULL,
  FLOW_SEQ_NUM   NUMBER(6)                      DEFAULT (0)                   NOT NULL,
  OPER           VARCHAR2(10 BYTE)              DEFAULT (' ')                 NOT NULL,
  RES_ID         VARCHAR2(20 BYTE)              DEFAULT (' ')                 NOT NULL,
  CAUSE_FLOW     VARCHAR2(20 BYTE)              DEFAULT (' ')                 NOT NULL,
  CAUSE_OPER     VARCHAR2(10 BYTE)              DEFAULT (' ')                 NOT NULL,
  CAUSE_RES_ID   VARCHAR2(20 BYTE)              DEFAULT (' ')                 NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

INSERT INTO MWIPSLTLOS VALUE (
SELECT 
    A.SUBLOT_ID          ,
    A.LOT_ID             ,
    A.HIST_SEQ           ,
    (SELECT LOT_HIST_SEQ FROM MWIPSLTHIS WHERE A.SUBLOT_ID = SUBLOT_ID AND A.HIST_SEQ =  HIST_SEQ)    ,
    A.QTY_FLAG           ,
    A.GRADE              ,
    A.LOSS_CODE          ,
    A.TRAN_TIME          ,
    A.HIST_DEL_FLAG      ,
    A.FACTORY            ,
    A.MAT_ID             ,
    A.MAT_VER            ,
    A.FLOW               ,
    A.FLOW_SEQ_NUM       ,
    A.OPER               ,
    A.RES_ID             ,
    A.CAUSE_FLOW         ,
    A.CAUSE_OPER         ,
    A.CAUSE_RES_ID       
    FROM MWIPSLTLOS_OLD A
    );


DROP TABLE MWIPSLTLOS_OLD CASCADE CONSTRAINT PURGE;

ALTER TABLE MWIPSLTLOS
ADD CONSTRAINT MWIPSLTLOS_PK PRIMARY KEY
(
   SUBLOT_ID, LOT_ID, HIST_SEQ, QTY_FLAG, LOSS_CODE
) USING INDEX TABLESPACE MESPLUS_IDX_TS;



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
    SHARED_LIB_NAME             VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
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
    SHARED_LIB_NAME     ,
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


Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'GLOBAL_OPTION', 'IsUseCellGrade', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'N', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20090223113912', ' ', ' ');

BEGIN
	 FOR REC IN (
				SELECT DISTINCT FACTORY FROM MWIPFACDEF
				MINUS
				SELECT DISTINCT FACTORY FROM MGCMTBLDAT 
				WHERE TABLE_NAME = 'GLOBAL_OPTION'
					AND KEY_1 = 'IsUseCellGrade'
				) 
	  LOOP

		Insert into MGCMTBLDAT
		   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
		 Values
		   (REC.FACTORY, 'GLOBAL_OPTION', 'IsUseCellGrade', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'N', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20090223113912', ' ', ' ');

	  END LOOP;			
END ;
/

Delete from MSVMSVCMBR where service_name = 'WIP_Loss_Lot_Ext';

Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'' : Loss lot extension)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030452');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'BACK_TIME', 6, ' ', ' ', ' ', ' ', 0, 'BACK_TIME', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_ID', 7, ' ', ' ', ' ', ' ', 0, 'LOT_ID', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LAST_ACTIVE_HIST_SEQ', 8, ' ', ' ', ' ', ' ', 0, 'LAST_ACTIVE_HIST_SEQ', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'MAT_ID', 9, ' ', ' ', ' ', ' ', 0, 'MAT_ID', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'MAT_VER', 10, ' ', ' ', ' ', ' ', 0, 'MAT_VER', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'FLOW', 11, ' ', ' ', ' ', ' ', 0, 'FLOW', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'FLOW_SEQ_NUM', 12, ' ', ' ', ' ', ' ', 0, 'FLOW_SEQ_NUM', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'OPER', 13, ' ', ' ', ' ', ' ', 0, 'OPER', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'CRR_ID', 14, ' ', ' ', ' ', ' ', 0, 'CRR_ID', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'OUT_QTY_1', 15, ' ', ' ', ' ', ' ', 0, 'OUT_QTY_1', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'OUT_QTY_2', 16, ' ', ' ', ' ', ' ', 0, 'OUT_QTY_2', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'OUT_QTY_3', 17, ' ', ' ', ' ', ' ', 0, 'OUT_QTY_3', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'RES_ID', 18, ' ', ' ', ' ', ' ', 0, 'RES_ID', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'CAUSE_FLOW', 19, ' ', ' ', ' ', ' ', 0, 'CAUSE_FLOW', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'CAUSE_OPER', 20, ' ', ' ', ' ', ' ', 0, 'CAUSE_OPER', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'CAUSE_RES_ID', 21, ' ', ' ', ' ', ' ', 0, 'CAUSE_RES_ID', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'CHECK_USER_1', 22, ' ', ' ', ' ', ' ', 0, 'CHECK_USER_1', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'CHECK_USER_2', 23, ' ', ' ', ' ', ' ', 0, 'CHECK_USER_2', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'CHECK_USER_3', 24, ' ', ' ', ' ', ' ', 0, 'CHECK_USER_3', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT1_QTY_1', 25, ' ', ' ', ' ', ' ', 0, 'UNIT1_QTY_1', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT1_QTY_2', 26, ' ', ' ', ' ', ' ', 0, 'UNIT1_QTY_2', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT1_QTY_3', 27, ' ', ' ', ' ', ' ', 0, 'UNIT1_QTY_3', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT1_QTY_4', 28, ' ', ' ', ' ', ' ', 0, 'UNIT1_QTY_4', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT1_QTY_5', 29, ' ', ' ', ' ', ' ', 0, 'UNIT1_QTY_5', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT1_QTY_6', 30, ' ', ' ', ' ', ' ', 0, 'UNIT1_QTY_6', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT1_QTY_7', 31, ' ', ' ', ' ', ' ', 0, 'UNIT1_QTY_7', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT1_QTY_8', 32, ' ', ' ', ' ', ' ', 0, 'UNIT1_QTY_8', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT1_QTY_9', 33, ' ', ' ', ' ', ' ', 0, 'UNIT1_QTY_9', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT1_QTY_10', 34, ' ', ' ', ' ', ' ', 0, 'UNIT1_QTY_10', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT2_QTY_1', 35, ' ', ' ', ' ', ' ', 0, 'UNIT2_QTY_1', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT2_QTY_2', 36, ' ', ' ', ' ', ' ', 0, 'UNIT2_QTY_2', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT2_QTY_3', 37, ' ', ' ', ' ', ' ', 0, 'UNIT2_QTY_3', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT2_QTY_4', 38, ' ', ' ', ' ', ' ', 0, 'UNIT2_QTY_4', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT2_QTY_5', 39, ' ', ' ', ' ', ' ', 0, 'UNIT2_QTY_5', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT2_QTY_6', 40, ' ', ' ', ' ', ' ', 0, 'UNIT2_QTY_6', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT2_QTY_7', 41, ' ', ' ', ' ', ' ', 0, 'UNIT2_QTY_7', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT2_QTY_8', 42, ' ', ' ', ' ', ' ', 0, 'UNIT2_QTY_8', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT2_QTY_9', 43, ' ', ' ', ' ', ' ', 0, 'UNIT2_QTY_9', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT2_QTY_10', 44, ' ', ' ', ' ', ' ', 0, 'UNIT2_QTY_10', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT1_CODE_1', 45, ' ', ' ', ' ', ' ', 0, 'UNIT1_CODE_1', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT1_CODE_2', 46, ' ', ' ', ' ', ' ', 0, 'UNIT1_CODE_2', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT1_CODE_3', 47, ' ', ' ', ' ', ' ', 0, 'UNIT1_CODE_3', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT1_CODE_4', 48, ' ', ' ', ' ', ' ', 0, 'UNIT1_CODE_4', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT1_CODE_5', 49, ' ', ' ', ' ', ' ', 0, 'UNIT1_CODE_5', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT1_CODE_6', 50, ' ', ' ', ' ', ' ', 0, 'UNIT1_CODE_6', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT1_CODE_7', 51, ' ', ' ', ' ', ' ', 0, 'UNIT1_CODE_7', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT1_CODE_8', 52, ' ', ' ', ' ', ' ', 0, 'UNIT1_CODE_8', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT1_CODE_9', 53, ' ', ' ', ' ', ' ', 0, 'UNIT1_CODE_9', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT1_CODE_10', 54, ' ', ' ', ' ', ' ', 0, 'UNIT1_CODE_10', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT2_CODE_1', 55, ' ', ' ', ' ', ' ', 0, 'UNIT2_CODE_1', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT2_CODE_2', 56, ' ', ' ', ' ', ' ', 0, 'UNIT2_CODE_2', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT2_CODE_3', 57, ' ', ' ', ' ', ' ', 0, 'UNIT2_CODE_3', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT2_CODE_4', 58, ' ', ' ', ' ', ' ', 0, 'UNIT2_CODE_4', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT2_CODE_5', 59, ' ', ' ', ' ', ' ', 0, 'UNIT2_CODE_5', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT2_CODE_6', 60, ' ', ' ', ' ', ' ', 0, 'UNIT2_CODE_6', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT2_CODE_7', 61, ' ', ' ', ' ', ' ', 0, 'UNIT2_CODE_7', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT2_CODE_8', 62, ' ', ' ', ' ', ' ', 0, 'UNIT2_CODE_8', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT2_CODE_9', 63, ' ', ' ', ' ', ' ', 0, 'UNIT2_CODE_9', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'UNIT2_CODE_10', 64, ' ', ' ', ' ', ' ', 0, 'UNIT2_CODE_10', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_TRAN_CMF_1', 65, ' ', ' ', ' ', ' ', 0, 'LOT_TRAN_CMF_1', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_TRAN_CMF_2', 66, ' ', ' ', ' ', ' ', 0, 'LOT_TRAN_CMF_2', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_TRAN_CMF_3', 67, ' ', ' ', ' ', ' ', 0, 'LOT_TRAN_CMF_3', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_TRAN_CMF_4', 68, ' ', ' ', ' ', ' ', 0, 'LOT_TRAN_CMF_4', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_TRAN_CMF_5', 69, ' ', ' ', ' ', ' ', 0, 'LOT_TRAN_CMF_5', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_TRAN_CMF_6', 70, ' ', ' ', ' ', ' ', 0, 'LOT_TRAN_CMF_6', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_TRAN_CMF_7', 71, ' ', ' ', ' ', ' ', 0, 'LOT_TRAN_CMF_7', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_TRAN_CMF_8', 72, ' ', ' ', ' ', ' ', 0, 'LOT_TRAN_CMF_8', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_TRAN_CMF_9', 73, ' ', ' ', ' ', ' ', 0, 'LOT_TRAN_CMF_9', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_TRAN_CMF_10', 74, ' ', ' ', ' ', ' ', 0, 'LOT_TRAN_CMF_10', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_TRAN_CMF_11', 75, ' ', ' ', ' ', ' ', 0, 'LOT_TRAN_CMF_11', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_TRAN_CMF_12', 76, ' ', ' ', ' ', ' ', 0, 'LOT_TRAN_CMF_12', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_TRAN_CMF_13', 77, ' ', ' ', ' ', ' ', 0, 'LOT_TRAN_CMF_13', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_TRAN_CMF_14', 78, ' ', ' ', ' ', ' ', 0, 'LOT_TRAN_CMF_14', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_TRAN_CMF_15', 79, ' ', ' ', ' ', ' ', 0, 'LOT_TRAN_CMF_15', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_TRAN_CMF_16', 80, ' ', ' ', ' ', ' ', 0, 'LOT_TRAN_CMF_16', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_TRAN_CMF_17', 81, ' ', ' ', ' ', ' ', 0, 'LOT_TRAN_CMF_17', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_TRAN_CMF_18', 82, ' ', ' ', ' ', ' ', 0, 'LOT_TRAN_CMF_18', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_TRAN_CMF_19', 83, ' ', ' ', ' ', ' ', 0, 'LOT_TRAN_CMF_19', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOT_TRAN_CMF_20', 84, ' ', ' ', ' ', ' ', 0, 'LOT_TRAN_CMF_20', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TRAN_CMF_1', 85, ' ', ' ', ' ', ' ', 0, 'SUBLOT_TRAN_CMF_1', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TRAN_CMF_2', 86, ' ', ' ', ' ', ' ', 0, 'SUBLOT_TRAN_CMF_2', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TRAN_CMF_3', 87, ' ', ' ', ' ', ' ', 0, 'SUBLOT_TRAN_CMF_3', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TRAN_CMF_4', 88, ' ', ' ', ' ', ' ', 0, 'SUBLOT_TRAN_CMF_4', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TRAN_CMF_5', 89, ' ', ' ', ' ', ' ', 0, 'SUBLOT_TRAN_CMF_5', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TRAN_CMF_6', 90, ' ', ' ', ' ', ' ', 0, 'SUBLOT_TRAN_CMF_6', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TRAN_CMF_7', 91, ' ', ' ', ' ', ' ', 0, 'SUBLOT_TRAN_CMF_7', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TRAN_CMF_8', 92, ' ', ' ', ' ', ' ', 0, 'SUBLOT_TRAN_CMF_8', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TRAN_CMF_9', 93, ' ', ' ', ' ', ' ', 0, 'SUBLOT_TRAN_CMF_9', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TRAN_CMF_10', 94, ' ', ' ', ' ', ' ', 0, 'SUBLOT_TRAN_CMF_10', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TRAN_CMF_11', 95, ' ', ' ', ' ', ' ', 0, 'SUBLOT_TRAN_CMF_11', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TRAN_CMF_12', 96, ' ', ' ', ' ', ' ', 0, 'SUBLOT_TRAN_CMF_12', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TRAN_CMF_13', 97, ' ', ' ', ' ', ' ', 0, 'SUBLOT_TRAN_CMF_13', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TRAN_CMF_14', 98, ' ', ' ', ' ', ' ', 0, 'SUBLOT_TRAN_CMF_14', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TRAN_CMF_15', 99, ' ', ' ', ' ', ' ', 0, 'SUBLOT_TRAN_CMF_15', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TRAN_CMF_16', 100, ' ', ' ', ' ', ' ', 0, 'SUBLOT_TRAN_CMF_16', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TRAN_CMF_17', 101, ' ', ' ', ' ', ' ', 0, 'SUBLOT_TRAN_CMF_17', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TRAN_CMF_18', 102, ' ', ' ', ' ', ' ', 0, 'SUBLOT_TRAN_CMF_18', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TRAN_CMF_19', 103, ' ', ' ', ' ', ' ', 0, 'SUBLOT_TRAN_CMF_19', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TRAN_CMF_20', 104, ' ', ' ', ' ', ' ', 0, 'SUBLOT_TRAN_CMF_20', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'COMMENT', 105, ' ', ' ', ' ', ' ', 0, 'COMMENT', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'LOSS_COMMENT', 106, ' ', ' ', ' ', ' ', 0, 'LOSS_COMMENT', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'NO_AUTOMATIC_TERMINATE_LOT', 107, ' ', ' ', ' ', ' ', 0, 'NO_AUTOMATIC_TERMINATE_LOT', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 0, 'SUBLOT_TBL', 108, 'Sublot list', ' ', ' ', 'List', 0, ' ', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210185125');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 1, 'REASON_CODE_LIST', 0, 'Sublot reason code list', ' ', ' ', 'List', 0, ' ', ' ', 'O', 'SUBLOT_TBL', 'Y', ' ', 0, 0, 'ADMIN', '20081210073945', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 1, 'SLOT_NO', 1, ' ', ' ', ' ', ' ', 0, 'SLOT_NO', ' ', 'O', 'SUBLOT_TBL', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 1, 'SUBLOT_ID', 2, ' ', ' ', ' ', ' ', 0, 'SUBLOT_ID', ' ', 'O', 'SUBLOT_TBL', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 1, 'GRADE', 3, ' ', ' ', ' ', ' ', 0, 'GRADE', ' ', 'O', 'SUBLOT_TBL', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 1, 'LOSS_CODE', 4, ' ', ' ', ' ', ' ', 0, 'LOSS_CODE', ' ', 'O', 'SUBLOT_TBL', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 1, 'CELL_GRADE', 5, ' ', ' ', ' ', ' ', 0, 'CELL_GRADE', ' ', 'O', 'SUBLOT_TBL', ' ', ' ', 0, 0, 'ADMIN', '20090223193545', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 1, 'OUT_QTY_2', 6, ' ', ' ', ' ', ' ', 0, 'CELL_GRADE', ' ', 'O', 'SUBLOT_TBL', ' ', ' ', 0, 0, 'ADMIN', '20090223193545', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 1, 'CELL_JUDGE', 7, ' ', ' ', ' ', ' ', 0, 'CELL_JUDGE', ' ', 'O', 'SUBLOT_TBL', ' ', ' ', 0, 0, 'ADMIN', '20090223193545', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'I', 2, 'REASON_CODE', 0, ' ', ' ', ' ', ' ', 0, 'REASON_CODE', ' ', 'O', 'REASON_CODE_LIST', ' ', ' ', 0, 0, 'ADMIN', '20081210184651', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'O', 0, 'CSTATUS', 6, ' ', ' ', ' ', 'List', 0, ' ', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20081201010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'O', 1, 'MAT_ID', 0, ' ', ' ', ' ', ' ', 0, 'MAT_ID', ' ', 'O', 'CSTATUS', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'O', 1, 'MAT_VER', 1, ' ', ' ', ' ', ' ', 0, 'MAT_VER', ' ', 'O', 'CSTATUS', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'O', 1, 'FLOW', 2, ' ', ' ', ' ', ' ', 0, 'FLOW', ' ', 'O', 'CSTATUS', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'O', 1, 'FLOW_SEQ_NUM', 3, ' ', ' ', ' ', ' ', 0, 'FLOW_SEQ_NUM', ' ', 'O', 'CSTATUS', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'O', 1, 'OPER', 4, ' ', ' ', ' ', ' ', 0, 'OPER', ' ', 'O', 'CSTATUS', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'O', 1, 'QTY_1', 5, ' ', ' ', ' ', ' ', 0, 'QTY_1', ' ', 'O', 'CSTATUS', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'O', 1, 'QTY_2', 6, ' ', ' ', ' ', ' ', 0, 'QTY_2', ' ', 'O', 'CSTATUS', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_Loss_Lot_Ext', 'O', 1, 'QTY_3', 7, ' ', ' ', ' ', ' ', 0, 'QTY_3', ' ', 'O', 'CSTATUS', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20081210030429');

Delete from MSVMSVCMBR where service_name = 'SVM_Update_Service';

Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''I'': Create, ''U'': Modify, ''D'': Delete, ''C'' : Copy)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20090223184830');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'I', 0, 'MODULE_NAME', 6, ' ', ' ', ' ', ' ', 0, 'MODULE_NAME', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'I', 0, 'SERVICE_NAME', 7, ' ', ' ', ' ', ' ', 0, 'SERVICE_NAME', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'I', 0, 'SERVICE_MODE', 8, ' ', ' ', ' ', ' ', 0, 'SERVICE_MODE', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'I', 0, 'SERVICE_CATEGORY', 9, ' ', ' ', ' ', ' ', 0, 'SERVICE_CATEGORY', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'I', 0, 'SERVICE_DESC_1', 10, ' ', ' ', ' ', ' ', 0, 'SERVICE_DESC_1', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'I', 0, 'SERVICE_DESC_2', 11, ' ', ' ', ' ', ' ', 0, 'SERVICE_DESC_2', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'I', 0, 'SERVICE_DESC_3', 12, ' ', ' ', ' ', ' ', 0, 'SERVICE_DESC_3', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'I', 0, 'FROM_MODULE_NAME', 13, 'From module name for copy', ' ', ' ', 'String', 30, 'FROM_MODULE_NAME', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20090223184830', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'I', 0, 'FROM_SERVICE_NAME', 14, 'From service name for copy', ' ', ' ', 'String', 100, 'FROM_SERVICE_NAME', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20090223184830', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CAT', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM', 'SVM_Update_Service', 'O', 0, 'CSTATUS', 6, ' ', ' ', ' ', ' ', 0, 'CSTATUS', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081201010101', ' ', ' ');

Insert into MSVMMBRDEF
   (MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, ARRAY_TYPE, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('CELL_JUDGE', 'A set of Judge for each Cell (FPD industry)', ' ', ' ', 'String', 500, ' ', ' ', 0, 0, 'ADMIN', '20090223193528', ' ', ' ');

Delete from MSVMMBRDEF where member_name = 'CELL_GRADE';

Insert into MSVMMBRDEF
   (MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, ARRAY_TYPE, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('CELL_GRADE', 'A set of Grade for each Cell (FPD industry)', ' ', ' ', 'String', 500, ' ', ' ', 0, 0, 'ADMIN', '20081201010101', 'ADMIN', '20090223193504');

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0381', 'WIP', 'WIP-0381 : Can''t change unit 1 quantity, if lot have sublots.', 'WIP-0381 : SUBLOT이 존재하는 경우에는 UNIT 1의 수량을 변경할 수 없습니다.', 'WIP-0381', 'ADMIN', '20090224174929', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0382', 'WIP', 'WIP-0382 : Can''t do loss or bonus transaction by this unit. Check operation setup.', 'WIP-0382 : Loss/Bonus 하려는 UNIT이 존재하지 않습니다. 공정 설정을 확인하십시오.', 'WIP-0382', 'ADMIN', '20090225084833', ' ', ' ');


/* Add LOT_CONDITION GCM Table */
Insert into MGCMTBLDEF
   (FACTORY, TABLE_NAME, TABLE_DESC, SYS_TBL_FLAG, CENTRAL_FLAG, TABLE_TYPE, USE_SQL_FLAG, TABLE_GROUP, KEY_1_PRT, KEY_1_FMT, KEY_1_SIZE, KEY_2_PRT, KEY_2_FMT, KEY_2_SIZE, KEY_3_PRT, KEY_3_FMT, KEY_3_SIZE, KEY_4_PRT, KEY_4_FMT, KEY_4_SIZE, KEY_5_PRT, KEY_5_FMT, KEY_5_SIZE, KEY_6_PRT, KEY_6_FMT, KEY_6_SIZE, KEY_7_PRT, KEY_7_FMT, KEY_7_SIZE, KEY_8_PRT, KEY_8_FMT, KEY_8_SIZE, KEY_9_PRT, KEY_9_FMT, KEY_9_SIZE, KEY_10_PRT, KEY_10_FMT, KEY_10_SIZE, DATA_1_PRT, DATA_1_FMT, DATA_1_SIZE, DATA_2_PRT, DATA_2_FMT, DATA_2_SIZE, DATA_3_PRT, DATA_3_FMT, DATA_3_SIZE, DATA_4_PRT, DATA_4_FMT, DATA_4_SIZE, DATA_5_PRT, DATA_5_FMT, DATA_5_SIZE, DATA_6_PRT, DATA_6_FMT, DATA_6_SIZE, DATA_7_PRT, DATA_7_FMT, DATA_7_SIZE, DATA_8_PRT, DATA_8_FMT, DATA_8_SIZE, DATA_9_PRT, DATA_9_FMT, DATA_9_SIZE, DATA_10_PRT, DATA_10_FMT, DATA_10_SIZE, SQL_1, SQL_2, SQL_3, SQL_4, SQL_5, TABLE_PASSWORD, SEC_CHK_FLAG, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'Flexible Condition For Lot', 'Y', ' ', ' ', ' ', 'WIP', 'COLUMN NAME', 'A', 30, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, 'ALIAS', 'A', 50, 'USED FLAG', 'A', 1, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20071005081615', ' ', ' ');

Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'ADD_ORDER_ID_1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADD_ORDER_ID_1', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'ADD_ORDER_ID_2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADD_ORDER_ID_2', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'ADD_ORDER_ID_3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADD_ORDER_ID_3', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'BATCH_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'BATCH_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'BATCH_SEQ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'BATCH_SEQ', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'BOM_ACTIVE_HIST_SEQ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'BOM_ACTIVE_HIST_SEQ', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'BOM_HIST_SEQ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'BOM_HIST_SEQ', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'BOM_SET_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'BOM_SET_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'BOM_SET_VERSION', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'BOM_SET_VERSION', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'CREATE_CODE', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'CREATE_CODE', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20071009092357', 'MES23', '20071009092444');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'CREATE_QTY_1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'CREATE_QTY_1', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'CREATE_QTY_2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'CREATE_QTY_2', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'CREATE_QTY_3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'CREATE_QTY_3', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'CREATE_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'CREATE_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'CRITICAL_RES_GROUP_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'CRITICAL_RES_GROUP_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'CRITICAL_RES_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'CRITICAL_RES_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'CRR_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'CRR_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'END_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'END_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'END_RES_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'END_RES_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'END_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'END_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'FACTORY', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'FACTORY', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'FAC_IN_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'FAC_IN_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'FLOW', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'FLOW', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'FLOW_IN_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'FLOW_IN_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'FLOW_SEQ_NUM', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'FLOW_SEQ_NUM', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'FROM_TO_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'FROM_TO_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'FROM_TO_LOT_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'FROM_TO_LOT_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'HOLD_CODE', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'HOLD_CODE', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20080219174932');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'HOLD_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'HOLD_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20080219174932');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'HOLD_PASSWORD', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'HOLD_PASSWORD', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'HOLD_PRV_GRP_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'HOLD_PRV_GRP_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'INV_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'INV_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'INV_UNIT', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'INV_UNIT', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LAST_ACTIVE_HIST_SEQ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LAST_ACTIVE_HIST_SEQ', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LAST_COMMENT', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LAST_COMMENT', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LAST_HIST_SEQ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LAST_HIST_SEQ', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LAST_TRAN_CODE', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LAST_TRAN_CODE', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LAST_TRAN_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LAST_TRAN_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_CMF_1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_1', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20080219174932');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_CMF_10', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_10', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_CMF_11', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_11', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_CMF_12', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_12', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_CMF_13', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_13', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_CMF_14', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_14', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_CMF_15', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_15', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_CMF_16', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_16', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_CMF_17', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_17', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_CMF_18', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_18', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_CMF_19', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_19', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_CMF_2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_2', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_CMF_20', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_20', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_CMF_3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_3', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_CMF_4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_4', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_CMF_5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_5', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_CMF_6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_6', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_CMF_7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_7', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_CMF_8', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_8', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_CMF_9', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_9', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_DEL_CODE', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_DEL_CODE', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_DEL_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_DEL_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_DEL_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_DEL_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_DESC', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_DESC', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_GROUP_ID_1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_GROUP_ID_1', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_GROUP_ID_2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_GROUP_ID_2', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_GROUP_ID_3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_GROUP_ID_3', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_LOCATION', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_LOCATION', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_PRIORITY', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_PRIORITY', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_STATUS', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_STATUS', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'LOT_TYPE', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_TYPE', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'MAT_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'MAT_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'MAT_VER', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'MAT_VER', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'NSTD_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'NSTD_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'NSTD_RET_FLOW', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'NSTD_RET_FLOW', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'NSTD_RET_FLOW_SEQ_NUM', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'NSTD_RET_FLOW_SEQ_NUM', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'NSTD_RET_OPER', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'NSTD_RET_OPER', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'NSTD_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'NSTD_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'OPER', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'OPER', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'OPER_IN_QTY_1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'OPER_IN_QTY_1', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'OPER_IN_QTY_2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'OPER_IN_QTY_2', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'OPER_IN_QTY_3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'OPER_IN_QTY_3', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'OPER_IN_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'OPER_IN_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'ORDER_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ORDER_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'ORG_DUE_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ORG_DUE_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'OWNER_CODE', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'OWNER_CODE', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20071009092357', 'MES23', '20071009092444');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'QTY_1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'QTY_1', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20080219174932');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'QTY_2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'QTY_2', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'QTY_3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'QTY_3', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'REP_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'REP_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'REP_RET_OPER', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'REP_RET_OPER', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RESERVE_RES_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESERVE_RES_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RESV_FIELD_1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESV_FIELD_1', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RESV_FIELD_2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESV_FIELD_2', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RESV_FIELD_3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESV_FIELD_3', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RESV_FIELD_4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESV_FIELD_4', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RESV_FIELD_5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESV_FIELD_5', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RESV_FLAG_1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESV_FLAG_1', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RESV_FLAG_2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESV_FLAG_2', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RESV_FLAG_3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESV_FLAG_3', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RESV_FLAG_4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESV_FLAG_4', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RESV_FLAG_5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESV_FLAG_5', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RWK_CODE', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_CODE', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RWK_COUNT', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_COUNT', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RWK_END_FLOW', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_END_FLOW', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RWK_END_FLOW_SEQ_NUM', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_END_FLOW_SEQ_NUM', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RWK_END_OPER', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_END_OPER', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RWK_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RWK_RET_CLEAR_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_RET_CLEAR_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RWK_RET_FLOW', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_RET_FLOW', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RWK_RET_FLOW_SEQ_NUM', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_RET_FLOW_SEQ_NUM', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RWK_RET_OPER', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_RET_OPER', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'RWK_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'SAMPLE_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'SAMPLE_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'SAMPLE_RESULT', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'SAMPLE_RESULT', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'SAMPLE_WAIT_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'SAMPLE_WAIT_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'SAVE_RES_ID_1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'SAVE_RES_ID_1', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'SAVE_RES_ID_2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'SAVE_RES_ID_2', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'SCH_DUE_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'SCH_DUE_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'SHIP_CODE', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'SHIP_CODE', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'SHIP_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'SHIP_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'START_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'START_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'START_QTY_1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'START_QTY_1', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'START_QTY_2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'START_QTY_2', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'START_QTY_3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'START_QTY_3', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'START_RES_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'START_RES_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'START_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'START_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'SUBRES_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'SUBRES_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'TRANSIT_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'TRANSIT_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'LOT_CONDITION', 'UNIT_EXIST_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'UNIT_EXIST_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');

BEGIN
	 FOR REC IN (
				SELECT FACTORY FROM MWIPFACDEF
				MINUS
				SELECT FACTORY FROM MGCMTBLDEF 
				WHERE TABLE_NAME = 'LOT_CONDITION'
				) 
	  LOOP
			Insert into MGCMTBLDEF
			   (FACTORY, TABLE_NAME, TABLE_DESC, SYS_TBL_FLAG, CENTRAL_FLAG, TABLE_TYPE, USE_SQL_FLAG, TABLE_GROUP, KEY_1_PRT, KEY_1_FMT, KEY_1_SIZE, KEY_2_PRT, KEY_2_FMT, KEY_2_SIZE, KEY_3_PRT, KEY_3_FMT, KEY_3_SIZE, KEY_4_PRT, KEY_4_FMT, KEY_4_SIZE, KEY_5_PRT, KEY_5_FMT, KEY_5_SIZE, KEY_6_PRT, KEY_6_FMT, KEY_6_SIZE, KEY_7_PRT, KEY_7_FMT, KEY_7_SIZE, KEY_8_PRT, KEY_8_FMT, KEY_8_SIZE, KEY_9_PRT, KEY_9_FMT, KEY_9_SIZE, KEY_10_PRT, KEY_10_FMT, KEY_10_SIZE, DATA_1_PRT, DATA_1_FMT, DATA_1_SIZE, DATA_2_PRT, DATA_2_FMT, DATA_2_SIZE, DATA_3_PRT, DATA_3_FMT, DATA_3_SIZE, DATA_4_PRT, DATA_4_FMT, DATA_4_SIZE, DATA_5_PRT, DATA_5_FMT, DATA_5_SIZE, DATA_6_PRT, DATA_6_FMT, DATA_6_SIZE, DATA_7_PRT, DATA_7_FMT, DATA_7_SIZE, DATA_8_PRT, DATA_8_FMT, DATA_8_SIZE, DATA_9_PRT, DATA_9_FMT, DATA_9_SIZE, DATA_10_PRT, DATA_10_FMT, DATA_10_SIZE, SQL_1, SQL_2, SQL_3, SQL_4, SQL_5, TABLE_PASSWORD, SEC_CHK_FLAG, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'Flexible Condition For Lot', 'Y', ' ', ' ', ' ', 'WIP', 'COLUMN NAME', 'A', 30, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, 'ALIAS', 'A', 50, 'USED FLAG', 'A', 1, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20071005081615', ' ', ' ');
			
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'ADD_ORDER_ID_1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADD_ORDER_ID_1', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'ADD_ORDER_ID_2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADD_ORDER_ID_2', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'ADD_ORDER_ID_3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADD_ORDER_ID_3', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'BATCH_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'BATCH_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'BATCH_SEQ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'BATCH_SEQ', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'BOM_ACTIVE_HIST_SEQ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'BOM_ACTIVE_HIST_SEQ', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'BOM_HIST_SEQ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'BOM_HIST_SEQ', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'BOM_SET_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'BOM_SET_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'BOM_SET_VERSION', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'BOM_SET_VERSION', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'CREATE_CODE', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'CREATE_CODE', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20071009092357', 'MES23', '20071009092444');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'CREATE_QTY_1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'CREATE_QTY_1', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'CREATE_QTY_2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'CREATE_QTY_2', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'CREATE_QTY_3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'CREATE_QTY_3', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'CREATE_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'CREATE_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'CRITICAL_RES_GROUP_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'CRITICAL_RES_GROUP_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'CRITICAL_RES_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'CRITICAL_RES_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'CRR_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'CRR_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'END_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'END_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'END_RES_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'END_RES_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'END_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'END_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'FACTORY', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'FACTORY', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'FAC_IN_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'FAC_IN_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'FLOW', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'FLOW', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'FLOW_IN_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'FLOW_IN_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'FLOW_SEQ_NUM', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'FLOW_SEQ_NUM', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'FROM_TO_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'FROM_TO_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'FROM_TO_LOT_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'FROM_TO_LOT_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'HOLD_CODE', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'HOLD_CODE', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20080219174932');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'HOLD_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'HOLD_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20080219174932');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'HOLD_PASSWORD', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'HOLD_PASSWORD', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'HOLD_PRV_GRP_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'HOLD_PRV_GRP_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'INV_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'INV_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'INV_UNIT', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'INV_UNIT', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LAST_ACTIVE_HIST_SEQ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LAST_ACTIVE_HIST_SEQ', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LAST_COMMENT', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LAST_COMMENT', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LAST_HIST_SEQ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LAST_HIST_SEQ', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LAST_TRAN_CODE', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LAST_TRAN_CODE', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LAST_TRAN_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LAST_TRAN_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_CMF_1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_1', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20080219174932');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_CMF_10', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_10', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_CMF_11', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_11', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_CMF_12', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_12', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_CMF_13', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_13', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_CMF_14', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_14', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_CMF_15', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_15', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_CMF_16', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_16', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_CMF_17', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_17', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_CMF_18', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_18', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_CMF_19', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_19', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_CMF_2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_2', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_CMF_20', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_20', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_CMF_3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_3', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_CMF_4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_4', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_CMF_5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_5', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_CMF_6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_6', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_CMF_7', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_7', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_CMF_8', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_8', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_CMF_9', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_CMF_9', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_DEL_CODE', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_DEL_CODE', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_DEL_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_DEL_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_DEL_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_DEL_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_DESC', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_DESC', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_GROUP_ID_1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_GROUP_ID_1', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_GROUP_ID_2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_GROUP_ID_2', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_GROUP_ID_3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_GROUP_ID_3', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_LOCATION', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_LOCATION', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_PRIORITY', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_PRIORITY', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_STATUS', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_STATUS', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'LOT_TYPE', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'LOT_TYPE', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'MAT_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'MAT_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'MAT_VER', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'MAT_VER', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'NSTD_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'NSTD_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'NSTD_RET_FLOW', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'NSTD_RET_FLOW', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'NSTD_RET_FLOW_SEQ_NUM', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'NSTD_RET_FLOW_SEQ_NUM', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'NSTD_RET_OPER', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'NSTD_RET_OPER', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'NSTD_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'NSTD_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'OPER', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'OPER', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'OPER_IN_QTY_1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'OPER_IN_QTY_1', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'OPER_IN_QTY_2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'OPER_IN_QTY_2', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'OPER_IN_QTY_3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'OPER_IN_QTY_3', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'OPER_IN_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'OPER_IN_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'ORDER_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ORDER_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'ORG_DUE_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ORG_DUE_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'OWNER_CODE', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'OWNER_CODE', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20071009092357', 'MES23', '20071009092444');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'QTY_1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'QTY_1', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20080219174932');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'QTY_2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'QTY_2', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'QTY_3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'QTY_3', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'REP_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'REP_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'REP_RET_OPER', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'REP_RET_OPER', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RESERVE_RES_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESERVE_RES_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RESV_FIELD_1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESV_FIELD_1', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RESV_FIELD_2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESV_FIELD_2', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RESV_FIELD_3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESV_FIELD_3', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RESV_FIELD_4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESV_FIELD_4', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RESV_FIELD_5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESV_FIELD_5', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RESV_FLAG_1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESV_FLAG_1', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RESV_FLAG_2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESV_FLAG_2', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RESV_FLAG_3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESV_FLAG_3', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RESV_FLAG_4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESV_FLAG_4', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RESV_FLAG_5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RESV_FLAG_5', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RWK_CODE', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_CODE', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RWK_COUNT', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_COUNT', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RWK_END_FLOW', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_END_FLOW', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RWK_END_FLOW_SEQ_NUM', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_END_FLOW_SEQ_NUM', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RWK_END_OPER', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_END_OPER', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RWK_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RWK_RET_CLEAR_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_RET_CLEAR_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RWK_RET_FLOW', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_RET_FLOW', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RWK_RET_FLOW_SEQ_NUM', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_RET_FLOW_SEQ_NUM', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RWK_RET_OPER', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_RET_OPER', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'RWK_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RWK_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'SAMPLE_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'SAMPLE_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'SAMPLE_RESULT', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'SAMPLE_RESULT', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'SAMPLE_WAIT_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'SAMPLE_WAIT_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'SAVE_RES_ID_1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'SAVE_RES_ID_1', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'SAVE_RES_ID_2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'SAVE_RES_ID_2', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'SCH_DUE_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'SCH_DUE_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'SHIP_CODE', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'SHIP_CODE', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'SHIP_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'SHIP_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'START_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'START_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'START_QTY_1', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'START_QTY_1', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'START_QTY_2', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'START_QTY_2', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'START_QTY_3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'START_QTY_3', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'START_RES_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'START_RES_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'START_TIME', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'START_TIME', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'SUBRES_ID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'SUBRES_ID', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'TRANSIT_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'TRANSIT_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
			Insert into MGCMTBLDAT
			   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
			 Values
			   (REC.FACTORY, 'LOT_CONDITION', 'UNIT_EXIST_FLAG', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'UNIT_EXIST_FLAG', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');

	  END LOOP;			
END ;
/

Insert into MGCMTBLDEF
   (FACTORY, TABLE_NAME, TABLE_DESC, SYS_TBL_FLAG, CENTRAL_FLAG, TABLE_TYPE, USE_SQL_FLAG, TABLE_GROUP, KEY_1_PRT, KEY_1_FMT, KEY_1_SIZE, KEY_2_PRT, KEY_2_FMT, KEY_2_SIZE, KEY_3_PRT, KEY_3_FMT, KEY_3_SIZE, KEY_4_PRT, KEY_4_FMT, KEY_4_SIZE, KEY_5_PRT, KEY_5_FMT, KEY_5_SIZE, KEY_6_PRT, KEY_6_FMT, KEY_6_SIZE, KEY_7_PRT, KEY_7_FMT, KEY_7_SIZE, KEY_8_PRT, KEY_8_FMT, KEY_8_SIZE, KEY_9_PRT, KEY_9_FMT, KEY_9_SIZE, KEY_10_PRT, KEY_10_FMT, KEY_10_SIZE, DATA_1_PRT, DATA_1_FMT, DATA_1_SIZE, DATA_2_PRT, DATA_2_FMT, DATA_2_SIZE, DATA_3_PRT, DATA_3_FMT, DATA_3_SIZE, DATA_4_PRT, DATA_4_FMT, DATA_4_SIZE, DATA_5_PRT, DATA_5_FMT, DATA_5_SIZE, DATA_6_PRT, DATA_6_FMT, DATA_6_SIZE, DATA_7_PRT, DATA_7_FMT, DATA_7_SIZE, DATA_8_PRT, DATA_8_FMT, DATA_8_SIZE, DATA_9_PRT, DATA_9_FMT, DATA_9_SIZE, DATA_10_PRT, DATA_10_FMT, DATA_10_SIZE, SQL_1, SQL_2, SQL_3, SQL_4, SQL_5, TABLE_PASSWORD, SEC_CHK_FLAG, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'FMB_SUBRES_TYPE', 'FMB Sub Resource Type Table', ' ', 'Y', ' ', ' ', 'SYSTEM', 'TYPE', 'A', 10, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, 'DESCRIPTION', 'A', 50, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20081204174320', ' ', ' ');

Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'FMB_SUBRES_TYPE', 'RES', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Resource', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20081204174410', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'FMB_SUBRES_TYPE', 'SUBRES', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Sub Resource', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20081204174410', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'FMB_SUBRES_TYPE', 'PORT', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Port', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20081204174410', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'FMB_SUBRES_TYPE', 'TOOL', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Tool', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20081204174410', ' ', ' ');

Insert into MSVMSVCDEF
   (SERVICE_NAME, MODULE_NAME, SERVICE_MODE, SERVICE_CATEGORY, SERVICE_DESC_1, SERVICE_DESC_2, SERVICE_DESC_3, SEC_CHK_FLAG, SHARED_LIB_NAME, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB_View_Event_Color_List', 'FMB', 'RR', 'I', 'Views color of event list.', ' ', ' ', ' ', ' ', 'ADMIN', '20090220102631', 'ADMIN', '20090220103341');

Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_Event_Color_List', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081217111936', 'ADMIN', '20090220102701');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_Event_Color_List', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081217111936', 'ADMIN', '20090220102701');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_Event_Color_List', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081217111936', 'ADMIN', '20090220102701');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_Event_Color_List', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USERID', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081217111936', 'ADMIN', '20090220102701');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_Event_Color_List', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081217111936', 'ADMIN', '20090220102701');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_Event_Color_List', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': View Event Color List)', ' ', ' ', 'Char', 1, 'PROCSTEP', ' ', 'M', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20081217111936', 'ADMIN', '20090220103008');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_Event_Color_List', 'I', 0, 'NEXT_EVENT', 6, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090220102824', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_Event_Color_List', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUSVALUE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081217111936', 'ADMIN', '20090220102701');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_Event_Color_List', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSGCODE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081217111936', 'ADMIN', '20090220102701');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_Event_Color_List', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081217111936', 'ADMIN', '20090220102701');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_Event_Color_List', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSGCATE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081217111936', 'ADMIN', '20090220102701');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_Event_Color_List', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELDMSG', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081217111936', 'ADMIN', '20090220102701');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_Event_Color_List', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DBERRMSG', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20081217111936', 'ADMIN', '20090220102701');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_Event_Color_List', 'O', 0, 'NEXT_EVENT', 6, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090220103343', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_Event_Color_List', 'O', 0, 'COLOR_LIST', 7, 'Color List', ' ', ' ', 'List', 0, ' ', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20090220103343', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_Event_Color_List', 'O', 1, 'COLOR', 0, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'COLOR_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220103343', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_Event_Color_List', 'O', 1, 'EVENT_ID', 1, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'COLOR_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220103343', ' ', ' ');

Insert into MSVMSVCDEF
   (SERVICE_NAME, MODULE_NAME, SERVICE_MODE, SERVICE_CATEGORY, SERVICE_DESC_1, SERVICE_DESC_2, SERVICE_DESC_3, SEC_CHK_FLAG, SHARED_LIB_NAME, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB_View_ResDetail_List', 'FMB', 'RR', 'I', 'Views the resource list.', ' ', ' ', ' ', ' ', 'ADMIN', '20090220135908', 'ADMIN', '20090220142527');

Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090216172646', 'ADMIN', '20090220135942');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090216172646', 'ADMIN', '20090220135942');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090216172646', 'ADMIN', '20090220135942');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USERID', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090216172646', 'ADMIN', '20090220135942');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090216172646', 'ADMIN', '20090220135942');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'I', 0, 'PROCSTEP', 5, ' ', ' ', ' ', ' ', 0, 'PROCSTEP', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090216172646', 'ADMIN', '20090220135942');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'I', 0, 'RES_TYPE', 6, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'I', 0, 'RES_GRP', 7, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'I', 0, 'AREA_ID', 8, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'I', 0, 'SUB_AREA_ID', 9, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'I', 0, 'FILTER', 10, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'I', 0, 'INCLUDE_DEL_RES', 11, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'I', 0, 'NEXT_RES_ID', 12, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUSVALUE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090216172646', 'ADMIN', '20090220135942');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSGCODE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090216172646', 'ADMIN', '20090220135942');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090216172646', 'ADMIN', '20090220135942');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSGCATE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090216172646', 'ADMIN', '20090220135942');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELDMSG', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090216172646', 'ADMIN', '20090220135942');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DBERRMSG', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090216172646', 'ADMIN', '20090220135942');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 0, 'NEXT_RES_ID', 6, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 0, 'RES_LIST', 7, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_ID', 0, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_DESC', 1, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_UP_DOWN_FLAG', 2, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'DELETE_FLAG', 3, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'FACTORY', 4, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_TYPE', 5, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_PRI_STS', 6, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_STS_1', 7, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_STS_2', 8, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_STS_3', 9, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_STS_4', 10, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_STS_5', 11, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_STS_6', 12, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_STS_7', 13, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_STS_8', 14, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_STS_9', 15, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_STS_10', 16, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'USE_FAC_PRT_FLAG', 17, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_STS_PRT_1', 18, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_STS_PRT_2', 19, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_STS_PRT_3', 20, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_STS_PRT_4', 21, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_STS_PRT_5', 22, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_STS_PRT_6', 23, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_STS_PRT_7', 24, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_STS_PRT_8', 25, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_STS_PRT_9', 26, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_STS_PRT_10', 27, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'AREA_ID', 28, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'SUB_AREA_ID', 29, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_LOCATION', 30, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'PROC_RULE', 31, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'MAX_PROC_COUNT', 32, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'PM_SCH_ENABLE_FLAG', 33, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'UNIT_BASE_ST_FLAG', 34, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'SEC_CHK_FLAG', 35, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'DELETE_USER_ID', 36, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'DELETE_TIME', 37, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'CREATE_USER_ID', 38, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'CREATE_TIME', 39, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'UPDATE_USER_ID', 40, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'UPDATE_TIME', 41, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_CTRL_MODE', 42, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_PROC_MODE', 43, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'LAST_RECIPE_ID', 44, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'PROC_COUNT', 45, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'LAST_START_TIME', 46, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'LAST_END_TIME', 47, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'LAST_DOWN_TIME', 48, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'LAST_DOWN_HIST_SEQ', 49, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'LAST_EVENT_ID', 50, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'LAST_EVENT_TIME', 51, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'LAST_ACTIVE_HIST_SEQ', 52, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'LAST_HIST_SEQ', 53, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'RES_TAG_FLAG', 54, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'LAYOUT_ID', 55, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'LOC_X', 56, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'LOC_Y', 57, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'LOC_WIDTH', 58, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'LOC_HEIGHT', 59, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'TEXT', 60, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'TEXT_SIZE', 61, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'TEXT_COLOR', 62, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'TEXT_STYLE', 63, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'TAG_TYPE', 64, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'BACK_COLOR', 65, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB', 'FMB_View_ResDetail_List', 'O', 1, 'SEQ', 66, ' ', ' ', ' ', ' ', 0, ' ', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090220142528', ' ', ' ');

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS-0282', 'RAS', 'RAS-0282 : The resource already has resource group. The resource can have only one resource group.', 'RAS-0282 : 장비에는 이미 장비그룹이 할당되어 있습니다. 장비는 한개의 장비그룹만을 가질수 있습니다.', ' ', 'ADMIN', '20090303153310', ' ', ' ');
