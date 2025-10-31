/*
**
**  File Name    : MESplusV5_ORA_MES_Create_Table_Script.sql
**  Description  : MES Database Table Creation SQL Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10,11
**
**  ==== Table Naming Rule ====
**  M WIP FAC DEF
**  1 234 567 890
**  - --- --- ---
**  1    - Sub System Name - M:MES, R:RPT, C:Customized, I:Interface, B:Backup, L:Log, T:Temporary
**  234  - Module Name
**  567  - Object Name(ex, FAC, MAT, FLW, OPR, RES, LOT, EQP, CST, ...)
**  890  - Second Object Name
**         or Object Status(ex, STS:Status, HIS:History, DEF:Definition, GRP:Group)
**
**  ==== Module Naming Rule ====
**  1. Basic Module --
**      BAS : Basic Module
**      MSG : Message Module
**      SEC : Security Module
**      GCM : General Code Management Module
**      ATR : Attribute Module
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
**      SPC : Statistical Process Control Module
**      SPM : Specification Management Module
**      SVM : Service Management Module
**      WEM : Work process Event Management Module
**  3. Interface Module --
**      TMP : Temporary Tables
**      ERP : ERP Interface Module
**  4. RPT Module --
**      MPI : Manufacturing Performance Indicator
**      RPT : Report Module
**      SUM : Summary Module
**      WEB : Web Security Module
**
**  5. WIP,RAS CMF 10 -> 20
**  ============================
**
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
*/

/*==== MSG(Message Module) ====*/
/* MMSGMSGDEF : Message Definition Table */
CREATE TABLE MMSGMSGDEF
(
    /* Format of Message ID : "WIP-0001" */
    MSG_ID                      VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MSG_GRP                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    MSG_1                       VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    MSG_2                       VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    MSG_3                       VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MMSGMSGDEF
ADD CONSTRAINT MMSGMSGDEF_PK PRIMARY KEY
(
    MSG_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* Add by J.S. 2009.04 */
/* MMSGBBSSEQ : Bulletin Board System Sequence Table */
CREATE TABLE MMSGBBSSEQ
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAIN_MENU_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUB_MENU_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    BBS_SEQ                     NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MMSGBBSSEQ
ADD CONSTRAINT MMSGBBSSEQ_PK PRIMARY KEY
(
    FACTORY,
    MAIN_MENU_ID,
    SUB_MENU_ID
) USING INDEX TABLESPACE HISTORY_IDX_TS;



/* MMSGBBSHIS : Bulletin Board System History Table */
CREATE TABLE MMSGBBSHIS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAIN_MENU_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUB_MENU_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    BBS_SEQ                     NUMBER(10)       DEFAULT(0)      NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Normal, Urgent, notice */
    MSG_TYPE                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MSG_TITLE                   VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    MSG_TAG                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* CMF 1 ~ 10 */
    BBS_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BBS_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BBS_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BBS_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BBS_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BBS_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BBS_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BBS_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BBS_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BBS_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    REPLY_COUNT                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    DELETE_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* For Inform Note */
    SYS_MSG_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    POPUP_CYCLE                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    PRIORITY                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    APPLY_SHIFT                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    APPLY_START_TIME            VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    APPLY_END_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    AREA_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUB_AREA_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RESG_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RCV_USER_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SEC_GRP_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRV_GRP_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    MODAL_FLAG                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    AUTO_CLOSE_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    AUTO_CLOSE_TIME             NUMBER(3, 0)     DEFAULT(0)      NOT NULL,
    ACK_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    ACK_TIME                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    ACK_USER_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RCV_FACTORY                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;


ALTER TABLE MMSGBBSHIS
ADD CONSTRAINT MMSGBBSHIS_PK PRIMARY KEY
(
    FACTORY,
    MAIN_MENU_ID,
    SUB_MENU_ID,
    BBS_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


CREATE INDEX MMSGBBSHIS_IDX_1 ON MMSGBBSHIS
(
    TRAN_TIME,
    FACTORY,
    MAIN_MENU_ID,
    SUB_MENU_ID,
    MSG_TYPE,
    RES_ID
) TABLESPACE HISTORY_IDX_TS;


/* MMSGBBSTXT : Bulletin Board System Text Table */
CREATE TABLE MMSGBBSTXT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAIN_MENU_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUB_MENU_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    BBS_SEQ                     NUMBER(10)       DEFAULT(0)      NOT NULL,
    TEXT_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    MSG_TEXT                    VARCHAR2(2000)   DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;


ALTER TABLE MMSGBBSTXT
ADD CONSTRAINT MMSGBBSTXT_PK PRIMARY KEY
(
    FACTORY,
    MAIN_MENU_ID,
    SUB_MENU_ID,
    BBS_SEQ,
    TEXT_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* Add by J.S. 2012.04.17 */
/* MMSGBBSFIL: Bulletin Board System Attached File Table */
CREATE TABLE MMSGBBSFIL
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAIN_MENU_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUB_MENU_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    BBS_SEQ                     NUMBER(10)       DEFAULT(0)      NOT NULL,
    FILE_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    SAVE_FILE_NAME              VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    ORG_FILE_NAME               VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;


ALTER TABLE MMSGBBSFIL
ADD CONSTRAINT MMSGBBSFIL_PK PRIMARY KEY
(
    FACTORY,
    MAIN_MENU_ID,
    SUB_MENU_ID,
    BBS_SEQ,
    FILE_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;










/*==== SEC(Security Module) ====*/
/* MSECFUNDEF : Function Definition Table */
CREATE TABLE MSECFUNDEF
(
    FUNC_NAME                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    FUNC_DESC                   VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Function Type - 'F':Client Function, 'P':Program, 'M':Menu */
    FUNC_TYPE_FLAG              CHAR(1)          DEFAULT(' ')    NOT NULL,
    FUNC_GROUP                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Form Class full name. "namespace.class" */
    ASSEMBLY_FILE               VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    /* Form Class full name. "namespace.class" */
    ASSEMBLY_NAME               VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    /* Short cut key */
    SHORT_CUT                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Display icon index */
    ICON_INDEX                  NUMBER(6)        DEFAULT(-1)     NOT NULL,
    /* Control Name 1~10(일반적으로 Button Control Name) */
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
    /* Tab Page Name 1~10 */
    TAB_NAME_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TAB_NAME_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TAB_NAME_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TAB_NAME_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TAB_NAME_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TAB_NAME_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TAB_NAME_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TAB_NAME_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TAB_NAME_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TAB_NAME_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Option Name 1~10 */
    OPT_NAME_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPT_NAME_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPT_NAME_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPT_NAME_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPT_NAME_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPT_NAME_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPT_NAME_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPT_NAME_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPT_NAME_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPT_NAME_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Field Enable Mask Use Flag */
    FLD_EN_MASK_USE_FLAG        CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Help URL */
    /* Help Web Site는 GCM Table에 정의 */
    HELP_URL                    VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSECFUNDEF
ADD CONSTRAINT MSECFUNDEF_PK PRIMARY KEY
(
    FUNC_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSECUSRDEF : User Definition Table */
CREATE TABLE MSECUSRDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_DESC                   VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Password */
    PASSWORD                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Change Password Enable Flag - 'Y':Enable, ' ':Disable */
    CHG_PASS_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* GRP 1 ~ 10 */
    USER_GRP_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    USER_GRP_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    USER_GRP_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    USER_GRP_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    USER_GRP_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    USER_GRP_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    USER_GRP_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    USER_GRP_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    USER_GRP_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    USER_GRP_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
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
    EXPIRE_DATE                 VARCHAR2(8)      DEFAULT(' ')    NOT NULL,
    PASS_EXPIRE_DATE            VARCHAR2(8)      DEFAULT(' ')    NOT NULL,
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
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSECUSRDEF
ADD CONSTRAINT MSECUSRDEF_PK PRIMARY KEY
(
    FACTORY,
    USER_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSECGRPDEF : Security Group Definition Table */
CREATE TABLE MSECGRPDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SEC_GRP_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SEC_GRP_DESC                VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSECGRPDEF
ADD CONSTRAINT MSECGRPDEF_PK PRIMARY KEY
(
    FACTORY,
    SEC_GRP_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSECGRPFUN : Security Group-Function Attach Table */
CREATE TABLE MSECGRPFUN
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    PROGRAM_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SEC_GRP_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FUNC_NAME                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /* The level which is indicated in the menu. The general function which when is a space. */
    DISP_LEVEL                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* 'Y' - The front menu and the case which it separates. */
    SEPARATOR                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Short cut key */
    SHORT_CUT                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    ADD_TOOL_BAR                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Control Enable Flag 1~10(일반적으로 Button Control Name) */
    CTL_EN_FLAG_1               CHAR(1)          DEFAULT(' ')    NOT NULL,
    CTL_EN_FLAG_2               CHAR(1)          DEFAULT(' ')    NOT NULL,
    CTL_EN_FLAG_3               CHAR(1)          DEFAULT(' ')    NOT NULL,
    CTL_EN_FLAG_4               CHAR(1)          DEFAULT(' ')    NOT NULL,
    CTL_EN_FLAG_5               CHAR(1)          DEFAULT(' ')    NOT NULL,
    CTL_EN_FLAG_6               CHAR(1)          DEFAULT(' ')    NOT NULL,
    CTL_EN_FLAG_7               CHAR(1)          DEFAULT(' ')    NOT NULL,
    CTL_EN_FLAG_8               CHAR(1)          DEFAULT(' ')    NOT NULL,
    CTL_EN_FLAG_9               CHAR(1)          DEFAULT(' ')    NOT NULL,
    CTL_EN_FLAG_10              CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Tab Page Disable Flag */
    TAB_DS_FLAG_1               CHAR(1)          DEFAULT(' ')    NOT NULL,
    TAB_DS_FLAG_2               CHAR(1)          DEFAULT(' ')    NOT NULL,
    TAB_DS_FLAG_3               CHAR(1)          DEFAULT(' ')    NOT NULL,
    TAB_DS_FLAG_4               CHAR(1)          DEFAULT(' ')    NOT NULL,
    TAB_DS_FLAG_5               CHAR(1)          DEFAULT(' ')    NOT NULL,
    TAB_DS_FLAG_6               CHAR(1)          DEFAULT(' ')    NOT NULL,
    TAB_DS_FLAG_7               CHAR(1)          DEFAULT(' ')    NOT NULL,
    TAB_DS_FLAG_8               CHAR(1)          DEFAULT(' ')    NOT NULL,
    TAB_DS_FLAG_9               CHAR(1)          DEFAULT(' ')    NOT NULL,
    TAB_DS_FLAG_10              CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Option Value 1~10 */
    OPT_VALUE_1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPT_VALUE_2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPT_VALUE_3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPT_VALUE_4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPT_VALUE_5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPT_VALUE_6                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPT_VALUE_7                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPT_VALUE_8                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPT_VALUE_9                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPT_VALUE_10                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Field Enable All Flag - 'Y':All, _:Mask Use */
    FLD_EN_ALL_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Field Enable Mask 50s */
    FLD_EN_MASK                 VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSECGRPFUN
ADD CONSTRAINT MSECGRPFUN_PK PRIMARY KEY
(
    FACTORY,
    PROGRAM_ID,
    SEC_GRP_ID,
    FUNC_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSECUSRFUN : User-Function(Favorites) Table */
CREATE TABLE MSECUSRFUN
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    PROGRAM_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FUNC_NAME                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /* User가 지정한 Function Description(SPACE 이면 Function의 Description 사용) */
    USER_FUNC_DESC              VARCHAR2(200)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSECUSRFUN
ADD CONSTRAINT MSECUSRFUN_PK PRIMARY KEY
(
    FACTORY,
    PROGRAM_ID,
    USER_ID,
    SEQ_NUM
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSECPRVGRP : Privilege Group Definition Table */
CREATE TABLE MSECPRVGRP
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    PRV_GRP_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRV_GRP_DESC                VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSECPRVGRP
ADD CONSTRAINT MSECPRVGRP_PK PRIMARY KEY
(
    FACTORY,
    PRV_GRP_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSECPRVUSR : Privilege Group-User Relation Table */
CREATE TABLE MSECPRVUSR
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    PRV_GRP_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSECPRVUSR
ADD CONSTRAINT MSECPRVUSR_PK PRIMARY KEY
(
    FACTORY,
    PRV_GRP_ID,
    USER_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSECPRVDEF : Privilege Definition Table */
CREATE TABLE MSECPRVDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    PRV_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRV_ITEM1                   VARCHAR2(100)     DEFAULT(' ')   NOT NULL,
    PRV_ITEM2                   VARCHAR2(100)     DEFAULT(' ')   NOT NULL,
    PRV_ITEM3                   VARCHAR2(100)     DEFAULT(' ')   NOT NULL,
    PRV_GRP_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSECPRVDEF
ADD CONSTRAINT MSECPRVDEF_PK PRIMARY KEY
(
    FACTORY,
    PRV_TYPE,
    PRV_ITEM1,
    PRV_ITEM2,
    PRV_ITEM3,
    PRV_GRP_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* User Group Definition table */
CREATE TABLE MSECUGPDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    USER_GRP_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_GRP_DESC               VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSECUGPDEF
ADD CONSTRAINT MSECUGPDEF_PK PRIMARY KEY
(
    FACTORY,
    USER_GRP_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* User Group User Relation table */
CREATE TABLE MSECUGPUSR
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    USER_GRP_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSECUGPUSR
ADD CONSTRAINT MSECUGPUSR_PK PRIMARY KEY
(
    FACTORY,
    USER_GRP_ID,
    USER_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* Add by J.S. 2006/01/10 for Advanced Security Control */
/* MSECUSREXT : User Definition for Advanced Security Control Table */
CREATE TABLE MSECUSREXT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Encoded Password */
    ENCODE_PASSWORD             VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* 수정된 날짜 */
    PASSWORD_CHANGE_DATE        VARCHAR2(8)      DEFAULT(' ')    NOT NULL,
    /* Password를 주정해야 하는 주기 */
    PASSWORD_CHANGE_PERIOD      NUMBER(6)        DEFAULT 0       NOT NULL,
    /* Y이면 Password를 바로 수정 해야 한다 */
    CHANGE_PASSWORD_FLAG        CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* 연속으로 틀린 횟수 */
    PASSWORD_FAIL_COUNT         NUMBER(6)        DEFAULT 0       NOT NULL,
    /* 이전 Password */
    OLD_PASSWORD_1              VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    OLD_PASSWORD_2              VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    OLD_PASSWORD_3              VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    OLD_PASSWORD_4              VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    OLD_PASSWORD_5              VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSECUSREXT
ADD CONSTRAINT MSECUSREXT_PK PRIMARY KEY
(
    FACTORY,
    USER_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* Add by J.S. 2006/04/11  */
/* MSECLICKEY : License Control Table */
CREATE TABLE MSECLICKEY
(
    LICENSE_ID                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LICENSE_ID_DESC             VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* 발행 시간 */
    LICENSE_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* 제품 이름 */
    PRODUCT                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* 고객 회사명 */
    CUSTOMER_COMPANY            VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* 동시 사용자 수 */
    CONCURRENT_USER_LIMIT       VARCHAR2(24)     DEFAULT(' ')    NOT NULL,
    CONCURRENT_USER_LIMIT_DESC  VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* 등록 사용자 수 */
    NAMED_USER_LIMIT            VARCHAR2(24)     DEFAULT(' ')    NOT NULL,
    NAMED_USER_LIMIT_DESC       VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* EXPIRE TIME */
    EXPIRE_TIME                 VARCHAR2(45)     DEFAULT(' ')    NOT NULL,
    EXPIRE_TIME_DESC            VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* 서버 IP ADDRESS */
    SERVER_IP_ADDRESS           VARCHAR2(48)     DEFAULT(' ')    NOT NULL,
    SERVER_IP_ADDRESS_DESC      VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* 모듈 */
    ENABLE_MODULE               VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    ENABLE_MODULE_DESC          VARCHAR2(200)    DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSECLICKEY
ADD CONSTRAINT MSECLICKEY_PK PRIMARY KEY
(
    LICENSE_TIME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSECFLXHDR : Flexible Header Table */
CREATE TABLE MSECFLXHDR
(
    SERVICE_NAME                VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    DSP_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    MEMBER_SEQ                  NUMBER(6)        DEFAULT 0       NOT NULL,
    MEMBER_NAME                 VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    MEMBER_PATH                 VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
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
    MEMBER_SEQ
) USING INDEX TABLESPACE MESPLUS_IDX_TS;














/*==== GCM(General Code Management Module) ====*/
/* MGCMTBLDEF : Code Table Definition Table */
CREATE TABLE MGCMTBLDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TABLE_NAME                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TABLE_DESC                  VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* System Table Flag - Y:System Table, _:User Table */
    SYS_TBL_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Central Flag - Y:Central Table, _:User Table */
    CENTRAL_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Table Type - _:General(Use Key_1 and Key_2), E:Extended(Use Key_1 ~ 10), L:Large Data(Use 100 Bytes Key and 1000 Bytes Data) */
    TABLE_TYPE                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Use Sql Flag - Y:sql 데이터 , _:MGCMTBLDAT 데이터 */
    USE_SQL_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Table Group */
    TABLE_GROUP                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_1_PRT                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Data Type - A:Ascii, N:Number, F:Float, T:Table */
    /* 소수자리수 관리 안함 - NUMBER Places */
    KEY_1_FMT                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEY_1_SIZE                  NUMBER(6)        DEFAULT(0)      NOT NULL,
    KEY_2_PRT                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_2_FMT                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEY_2_SIZE                  NUMBER(6)        DEFAULT(0)      NOT NULL,
    KEY_3_PRT                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_3_FMT                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEY_3_SIZE                  NUMBER(6)        DEFAULT(0)      NOT NULL,
    KEY_4_PRT                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_4_FMT                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEY_4_SIZE                  NUMBER(6)        DEFAULT(0)      NOT NULL,
    KEY_5_PRT                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_5_FMT                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEY_5_SIZE                  NUMBER(6)        DEFAULT(0)      NOT NULL,
    KEY_6_PRT                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_6_FMT                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEY_6_SIZE                  NUMBER(6)        DEFAULT(0)      NOT NULL,
    KEY_7_PRT                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_7_FMT                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEY_7_SIZE                  NUMBER(6)        DEFAULT(0)      NOT NULL,
    KEY_8_PRT                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_8_FMT                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEY_8_SIZE                  NUMBER(6)        DEFAULT(0)      NOT NULL,
    KEY_9_PRT                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_9_FMT                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEY_9_SIZE                  NUMBER(6)        DEFAULT(0)      NOT NULL,
    KEY_10_PRT                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_10_FMT                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEY_10_SIZE                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    DATA_1_PRT                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DATA_1_FMT                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    DATA_1_SIZE                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    DATA_2_PRT                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DATA_2_FMT                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    DATA_2_SIZE                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    DATA_3_PRT                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DATA_3_FMT                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    DATA_3_SIZE                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    DATA_4_PRT                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DATA_4_FMT                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    DATA_4_SIZE                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    DATA_5_PRT                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DATA_5_FMT                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    DATA_5_SIZE                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    DATA_6_PRT                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DATA_6_FMT                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    DATA_6_SIZE                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    DATA_7_PRT                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DATA_7_FMT                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    DATA_7_SIZE                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    DATA_8_PRT                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DATA_8_FMT                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    DATA_8_SIZE                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    DATA_9_PRT                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DATA_9_FMT                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    DATA_9_SIZE                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    DATA_10_PRT                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DATA_10_FMT                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    DATA_10_SIZE                NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* USE_SQL_FLAG -> Y일 경우 SQL문*/
    SQL_1                       VARCHAR2(2000)   DEFAULT(' ')    NOT NULL,
    SQL_2                       VARCHAR2(2000)   DEFAULT(' ')    NOT NULL,
    SQL_3                       VARCHAR2(2000)   DEFAULT(' ')    NOT NULL,
    SQL_4                       VARCHAR2(2000)   DEFAULT(' ')    NOT NULL,
    SQL_5                       VARCHAR2(2000)   DEFAULT(' ')    NOT NULL,
    /* Table Password */
    TABLE_PASSWORD              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Security Check Flag - _:No, Y:Security Control */
    SEC_CHK_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* #753 Use GCM Table Reference (2012.04.04 by JYPARK) */
    KEY_1_TBL                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_1_COL                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_2_TBL                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_2_COL                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_3_TBL                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_3_COL                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_4_TBL                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_4_COL                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_5_TBL                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_5_COL                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_6_TBL                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_6_COL                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_7_TBL                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_7_COL                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_8_TBL                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_8_COL                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_9_TBL                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_9_COL                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    KEY_10_TBL                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_10_COL                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DATA_1_TBL                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DATA_1_COL                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DATA_2_TBL                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DATA_2_COL                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DATA_3_TBL                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DATA_3_COL                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DATA_4_TBL                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DATA_4_COL                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DATA_5_TBL                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DATA_5_COL                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DATA_6_TBL                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DATA_6_COL                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DATA_7_TBL                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DATA_7_COL                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DATA_8_TBL                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DATA_8_COL                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DATA_9_TBL                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DATA_9_COL                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DATA_10_TBL                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DATA_10_COL                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MGCMTBLDEF
ADD CONSTRAINT MGCMTBLDEF_PK PRIMARY KEY
(
    FACTORY,
    TABLE_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MGCMTBLDAT : General Code Table Data Table */
CREATE TABLE MGCMTBLDAT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TABLE_NAME                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
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
    DATA_1                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_2                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_3                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_4                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_5                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_6                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_7                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_8                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_9                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_10                     VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MGCMTBLDAT
ADD CONSTRAINT MGCMTBLDAT_PK PRIMARY KEY
(
    FACTORY,
    TABLE_NAME,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_10
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MGCMLAGDAT : General Code Large Data Table */
CREATE TABLE MGCMLAGDAT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TABLE_NAME                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    KEY_1                       VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    KEY_2                       VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    KEY_3                       VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    KEY_4                       VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    KEY_5                       VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    KEY_6                       VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    KEY_7                       VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    KEY_8                       VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    KEY_9                       VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    KEY_10                      VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    DATA_1                      VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    DATA_2                      VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    DATA_3                      VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    DATA_4                      VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    DATA_5                      VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    DATA_6                      VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    DATA_7                      VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    DATA_8                      VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    DATA_9                      VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    DATA_10                     VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MGCMLAGDAT
ADD CONSTRAINT MGCMLAGDAT_PK PRIMARY KEY
(
    FACTORY,
    TABLE_NAME,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_10
) USING INDEX TABLESPACE MESPLUS_IDX_TS;



















/*==== ATR(Attribute Module) ====*/
/* MATRNAMDEF : Attribute Name Definition Table */
CREATE TABLE MATRNAMDEF
(
    FACTORY                     VARCHAR2(10)    DEFAULT (' ')   NOT NULL,
    /* ATTR_TYPE - FACTORY, MATERIAL, FLOW, OPER, LOT, SUBLOT, BOM, RESOURCE, user_defined */
    ATTR_TYPE                   VARCHAR2(20)    DEFAULT (' ')   NOT NULL,
    ATTR_NAME                   VARCHAR2(100)   DEFAULT (' ')   NOT NULL,
    ATTR_DESC                   VARCHAR2(200)   DEFAULT (' ')   NOT NULL,
    ATTR_SEQ                    NUMBER(10)      DEFAULT (0)     NOT NULL,
    ATTR_FMT                    CHAR(1)         DEFAULT (' ')   NOT NULL,
    ATTR_SIZE                   NUMBER(6)       DEFAULT (0)     NOT NULL,
    /* VALID_TBL_TYPE - A: Allowd, N:Not Allowed, Q:Query Result */
    VALID_TBL_TYPE              CHAR(1)         DEFAULT (' ')   NOT NULL,
    VALID_TBL                   VARCHAR2(20)    DEFAULT (' ')   NOT NULL,
    ALLOW_BLANK                 CHAR(1)         DEFAULT (' ')   NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)    DEFAULT (' ')   NOT NULL,
    CREATE_TIME                 VARCHAR2(14)    DEFAULT (' ')   NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)    DEFAULT (' ')   NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)    DEFAULT (' ')   NOT NULL,
    SEC_CHK_FLAG                CHAR(1)         DEFAULT (' ')   NOT NULL,
    KEY_HIST_INDEPENDENT_FLAG   CHAR(1)         DEFAULT (' ')   NOT NULL,
    /* #995 Enhancement Attribute User Control (2012.04.13 by JYPARK) */
    NO_HISTORY_FLAG             CHAR(1)         DEFAULT (' ')   NOT NULL,
    /* #1017 System Attribute (2012.04.25 by JYPARK) */
    SYS_ATR_FLAG                CHAR(1)         DEFAULT (' ')   NOT NULL,
    /* #1088 System Attribute (2012.11.13 by KSSKIM) */
    ARRAY_SEPARATOR             CHAR(1)         DEFAULT (' ')   NOT NULL,
    ARRAY_TYPE_FLAG             CHAR(1)         DEFAULT (' ')   NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MATRNAMDEF
ADD CONSTRAINT MATRNAMDEF_PK PRIMARY KEY
(
    FACTORY,
    ATTR_TYPE,
    ATTR_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MATRNAMSTS : Attribute Name Status Table */
CREATE TABLE MATRNAMSTS
(
    FACTORY                     VARCHAR2(10)    DEFAULT (' ')   NOT NULL,
    ATTR_TYPE                   VARCHAR2(20)    DEFAULT (' ')   NOT NULL,
    ATTR_NAME                   VARCHAR2(100)   DEFAULT (' ')   NOT NULL,
    /* ATTR_KEY - 실제 Material Name, Lot Number, Operation 등이 입력됨 */
    ATTR_KEY                    VARCHAR2(100)   DEFAULT (' ')   NOT NULL,
    KEY_HIST_SEQ                NUMBER(10)      DEFAULT (0)     NOT NULL,
    ATTR_VALUE                  VARCHAR2(1000)  DEFAULT (' ')   NOT NULL,
    NULL_FLAG                   CHAR(1)         DEFAULT (' ')   NOT NULL,
    LAST_TRAN_TIME              VARCHAR2(14)    DEFAULT (' ')   NOT NULL,
    LAST_ACTIVE_HIST_SEQ        NUMBER(10)      DEFAULT (0)     NOT NULL,
    LAST_HIST_SEQ               NUMBER(10)      DEFAULT (0)     NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MATRNAMSTS
ADD CONSTRAINT MATRNAMSTS_PK PRIMARY KEY
(
    FACTORY,
    ATTR_TYPE,
    ATTR_NAME,
    ATTR_KEY
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* Multi factory 인 경우 아래 인덱스를 사용하고 */
CREATE INDEX MATRNAMSTS_IDX_1 ON MATRNAMSTS
(
    FACTORY,
    ATTR_KEY,
    ATTR_TYPE,
    ATTR_NAME
) TABLESPACE MESPLUS_IDX_TS;

/* one factory 인 경우 아래 인덱스를 사용한다 */
/*
CREATE INDEX MATRNAMSTS_IDX_1 ON MATRNAMSTS
(
    ATTR_KEY,
    ATTR_TYPE,
    FACTORY,
    ATTR_NAME
) TABLESPACE MESPLUS_IDX_TS;
*/

CREATE INDEX MATRNAMSTS_IDX_2 ON MATRNAMSTS
(
    ATTR_TYPE,
    ATTR_KEY,
    ATTR_NAME
) TABLESPACE MESPLUS_IDX_TS;

/* MATRNAMHIS : Attribute Name History Table */
CREATE TABLE MATRNAMHIS
(
    FACTORY                     VARCHAR2(10)    DEFAULT (' ')   NOT NULL,
    ATTR_TYPE                   VARCHAR2(20)    DEFAULT (' ')   NOT NULL,
    ATTR_NAME                   VARCHAR2(100)   DEFAULT (' ')   NOT NULL,
    ATTR_KEY                    VARCHAR2(100)   DEFAULT (' ')   NOT NULL,
    HIST_SEQ                    NUMBER(10)      DEFAULT (0)     NOT NULL,
    ATTR_OLD_VALUE              VARCHAR2(1000)  DEFAULT (' ')   NOT NULL,
    ATTR_NEW_VALUE              VARCHAR2(1000)  DEFAULT (' ')   NOT NULL,
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
    TRAN_USER_ID                VARCHAR2(20)    DEFAULT (' ')   NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MATRNAMHIS
ADD CONSTRAINT MATRNAMHIS_PK PRIMARY KEY
(
    FACTORY,
    ATTR_TYPE,
    ATTR_NAME,
    ATTR_KEY,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

/* Multi factory 인 경우 아래 인덱스를 사용하고 */
CREATE INDEX MATRNAMHIS_IDX_1 ON MATRNAMHIS
(
    FACTORY,
    ATTR_TYPE,
    ATTR_KEY,
    KEY_HIST_SEQ
) TABLESPACE HISTORY_IDX_TS;

/* one factory 인 경우 아래 인덱스를 사용한다 */
/*
CREATE INDEX MATRNAMHIS_IDX_1 ON MATRNAMHIS
(
    ATTR_KEY,
    KEY_HIST_SEQ,
    ATTR_TYPE,
    FACTORY
) TABLESPACE HISTORY_IDX_TS;
*/








/*==== ALM(Alam Management Module) ====*/
/* MALMMSGDEF : Alarm Message Definition Table */
CREATE TABLE MALMMSGDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* 만약 ALARM_ID가 MES ERROR MSG와 동일하면 MES에러가 발생될때 동작한다 */
    ALARM_ID                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    ALARM_DESC                  VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* 'N':Normal   'R':Resource   'A':Automatic gathered */
    ALARM_TYPE                  CHAR(1)          DEFAULT('N')    NOT NULL,
    /* 'I':INFORMATION 'W':WARNING   'E':ERROR */
    ALARM_LEVEL_FLAG            CHAR(1)          DEFAULT('I')    NOT NULL,
    SEND_TO_USER_FLAG           CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* UI 화면에 보냄 */
    ACTION_DISPLAY_FLAG         CHAR(1)          DEFAULT(' ')    NOT NULL,
    ACTION_MAIL_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* PASER,SMS..로 보냄 */
    ACTION_MSG_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* 대상 LOT을 HOLD 시킴 */
    ALARM_LOT_ACTION            VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    HOLD_CODE                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    HOLD_PASSWORD               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Release 권한을 가지는 권한 그룹 */
    HOLD_PRV_GRP_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT (0)     NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT (' ')   NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT (0)     NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT (' ')   NOT NULL,
    RWK_CODE                    VARCHAR2(10)     DEFAULT (' ')   NOT NULL,
    RWK_FLOW                    VARCHAR2(20)     DEFAULT (' ')   NOT NULL,
    RWK_FLOW_SEQ_NUM            NUMBER(6)        DEFAULT (0)     NOT NULL,
    RWK_OPER                    VARCHAR2(10)     DEFAULT (' ')   NOT NULL,
    RWK_STOP_OPER               VARCHAR2(10)     DEFAULT (' ')   NOT NULL,
    RET_FLOW                    VARCHAR2(20)     DEFAULT (' ')   NOT NULL,
    RET_FLOW_SEQ_NUM            NUMBER(6)        DEFAULT (0)     NOT NULL,
    RET_OPER                    VARCHAR2(10)     DEFAULT (' ')   NOT NULL,
    RET_CLEAR_FLAG              CHAR(1)          DEFAULT (' ')   NOT NULL,
    /* Hold, Rework등의 TRAN CMF */
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
    /* 일반 코멘트 */
    LOT_COMMENT                 VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* Alarm Message */
    ALARM_SUBJECT               VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    ALARM_MSG_1                 VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    ALARM_MSG_2                 VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    ALARM_MSG_3                 VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    /* Alarm이 발생 했을 때 장비 이벤트 발생 */
    EVENT_ID                    VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /* Change to Status Value */
    CHG_STS_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_STS_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_STS_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_STS_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_STS_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_STS_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_STS_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_STS_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_STS_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_STS_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_COMMENT                 VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* Alarm이 Clear 했을 때 장비 이벤트 발생 */
    CLEAR_EVENT_ID              VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /* Change to Status Value */
    CLEAR_CHG_STS_1             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CLEAR_CHG_STS_2             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CLEAR_CHG_STS_3             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CLEAR_CHG_STS_4             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CLEAR_CHG_STS_5             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CLEAR_CHG_STS_6             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CLEAR_CHG_STS_7             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CLEAR_CHG_STS_8             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CLEAR_CHG_STS_9             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CLEAR_CHG_STS_10            VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CLEAR_RES_COMMENT           VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Alarm Comment */
    ALARM_COMMENT_1             VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    ALARM_COMMENT_2             VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    ALARM_COMMENT_3             VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    ALARM_COMMENT_4             VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    ALARM_COMMENT_5             VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    /* PDF File */
    PDF_FILE_NAME               VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* Image(JPEG) File */
    IMAGE_FILE_NAME             VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* Alarm CMF Field */
    ALARM_CMF_1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_CMF_2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_CMF_3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_CMF_4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_CMF_5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_CMF_6                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_CMF_7                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_CMF_8                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_CMF_9                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_CMF_10                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_CMF_11                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_CMF_12                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_CMF_13                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_CMF_14                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_CMF_15                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_CMF_16                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_CMF_17                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_CMF_18                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_CMF_19                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_CMF_20                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Alarm Group Field */
    ALARM_GRP_1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_GRP_2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_GRP_3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_GRP_4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_GRP_5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_GRP_6                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_GRP_7                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_GRP_8                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_GRP_9                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_GRP_10                VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MALMMSGDEF
ADD CONSTRAINT MALMMSGDEF_PK PRIMARY KEY
(
    FACTORY,
    ALARM_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MALMMSGHIS : Alarm Message History Table */
CREATE TABLE MALMMSGHIS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    ALARM_ID                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* 'N':Normal   'R':Resource   'A':Automatic gathered */
    ALARM_TYPE                  CHAR(1)          DEFAULT('N')    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOT_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    AREA_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUB_AREA_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SOURCE_ID_1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SOURCE_DESC_1               VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    SOURCE_ID_2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SOURCE_DESC_2               VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    SOURCE_ID_3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SOURCE_DESC_3               VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    ALARM_LEVEL_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    ALARM_SUBJECT               VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    ALARM_MSG                   VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    ACK_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    ACK_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    ACK_USER_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CLEAR_FLAG                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CLEAR_TIME                  VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    CLEAR_USER_ID               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CLEAR_COMMENT               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Alarm Comment */
    ALARM_COMMENT_1             VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    ALARM_COMMENT_2             VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    ALARM_COMMENT_3             VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    ALARM_COMMENT_4             VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    ALARM_COMMENT_5             VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    /* PDF File */
    PDF_FILE_NAME               VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* Image(JPEG) File */
    IMAGE_FILE_NAME             VARCHAR2(50)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MALMMSGHIS
ADD CONSTRAINT MALMMSGHIS_PK PRIMARY KEY
(
    FACTORY,
    TRAN_TIME,
    SOURCE_ID_1
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MALMMSGHIS_IDX_1 ON MALMMSGHIS
(
    FACTORY,
    TRAN_TIME,
    ALARM_ID
) TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MALMMSGHIS_IDX_2 ON MALMMSGHIS
(
    FACTORY,
    RES_ID,
    RES_HIST_SEQ,
    ALARM_ID,
    SOURCE_ID_1
) TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MALMMSGHIS_IDX_3 ON MALMMSGHIS
(
    FACTORY,
    LOT_ID,
    LOT_HIST_SEQ,
    ALARM_ID,
    SOURCE_ID_1
) TABLESPACE HISTORY_IDX_TS;



/* MALMRCVDEF : Alarm Message Receiver Definition Table */
CREATE TABLE MALMRCVDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    ALARM_ID                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* 'U': User, 'S': Seurity Group, 'P': Privilege Group */
    REL_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    RCVR_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* _X__ : shift1, ____ : All shift, XXXX : Can't Input */
    RCV_SHIFT                   CHAR(4)          DEFAULT('_')    NOT NULL,
    /* Create Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MALMRCVDEF
ADD CONSTRAINT MALMRCVDEF_PK PRIMARY KEY
(
    FACTORY,
    ALARM_ID,
    REL_LEVEL,
    RCVR_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MALMMFORES : Alarm Relate MFO and Resource Definition Table */
CREATE TABLE MALMMFORES
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* '1': MFO, '2': FO, '3': O, '4': MO, 'F': Factory, 'T': Resource Type, 'G': Resource Group, 'R': Resource */
    REL_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RESG_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    ALARM_ID                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    APPLY_FROM_TIME             VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    APPLY_TO_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    INHERIT_CHILD_FLAG          CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* 'S': Start, 'P': sPlit, 'E': End, 'R': Rework */
    TRAN_POINT                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_ID                    VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    NEED_CONFIRM_FLAG           CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Override Alarm */
    OVERRIDE_MSG_FLAG           CHAR(1)          DEFAULT(' ')    NOT NULL,
    ALARM_SUBJECT               VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    ALARM_MSG_1                 VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    ALARM_MSG_2                 VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    ALARM_MSG_3                 VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    OVERRIDE_COMMENT_FLAG       CHAR(1)          DEFAULT(' ')    NOT NULL,
    ALARM_COMMENT_1             VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    ALARM_COMMENT_2             VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    ALARM_COMMENT_3             VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    ALARM_COMMENT_4             VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    ALARM_COMMENT_5             VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    OVERRIDE_PDF_FLAG           CHAR(1)          DEFAULT(' ')    NOT NULL,
    PDF_FILE_NAME               VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    OVERRIDE_IMAGE_FLAG         CHAR(1)          DEFAULT(' ')    NOT NULL,
    IMAGE_FILE_NAME             VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    FILE_NAME_KEY               VARCHAR2(20)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MALMMFORES
ADD CONSTRAINT MALMMFORES_PK PRIMARY KEY
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
    ALARM_ID,
    LOT_ID,
    TRAN_POINT,
    EVENT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

















/*==== MESplus Global Option Table ====*/
/* MBASGLBDEF : MESplus Global Option Definition Table */
CREATE TABLE MBASGLBDEF
(
  FACTORY                       VARCHAR2(10)     DEFAULT (' ')      NOT NULL,
  OPTION_NAME                   VARCHAR2(30)     DEFAULT (' ')      NOT NULL,
  OPTION_DESC                   VARCHAR2(200)    DEFAULT (' ')      NOT NULL,
  VALUE_1                       VARCHAR2(30)     DEFAULT (' ')      NOT NULL,
  VALUE_2                       VARCHAR2(30)     DEFAULT (' ')      NOT NULL,
  VALUE_3                       VARCHAR2(30)     DEFAULT (' ')      NOT NULL,
  VALUE_4                       VARCHAR2(30)     DEFAULT (' ')      NOT NULL,
  VALUE_5                       VARCHAR2(30)     DEFAULT (' ')      NOT NULL,
  CREATE_USER_ID                VARCHAR2(20)     DEFAULT (' ')      NOT NULL,
  CREATE_TIME                   VARCHAR2(14)     DEFAULT (' ')      NOT NULL,
  UPDATE_USER_ID                VARCHAR2(20)     DEFAULT (' ')      NOT NULL,
  UPDATE_TIME                   VARCHAR2(14)     DEFAULT (' ')      NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBASGLBDEF
ADD CONSTRAINT MBASGLBDEF_PK PRIMARY KEY
(
    FACTORY,
    OPTION_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;



/* MBASGLBPMT : Global Option Prompt Table */
CREATE TABLE MBASGLBPMT
(
  OPTION_NAME     VARCHAR2(30)             DEFAULT (' ')                 NOT NULL,
  OPTION_DESC     VARCHAR2(200)            DEFAULT (' ')                 NOT NULL,
    /* MESplus pre defined prompt Flag - Y:MESplus Core prompt, _:User prompt */
  MESPLUS_FLAG    CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  VALUE_PMT_1     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  VALUE_PMT_2     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  VALUE_PMT_3     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  VALUE_PMT_4     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  VALUE_PMT_5     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  VALUE_FMT_1     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  VALUE_FMT_2     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  VALUE_FMT_3     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  VALUE_FMT_4     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  VALUE_FMT_5     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  VALUE_TBL_1     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  VALUE_TBL_2     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  VALUE_TBL_3     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  VALUE_TBL_4     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  VALUE_TBL_5     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  CREATE_USER_ID  VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  CREATE_TIME     VARCHAR2(14)             DEFAULT (' ')                 NOT NULL,
  UPDATE_USER_ID  VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  UPDATE_TIME     VARCHAR2(14)             DEFAULT (' ')                 NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBASGLBPMT
ADD CONSTRAINT MBASGLBPMT_PK PRIMARY KEY
(
    OPTION_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MBASSCRDEF : Flexible Screen Definition Table */
CREATE TABLE MBASSCRDEF
(
    FACTORY                 VARCHAR2(10)    DEFAULT (' ')   NOT NULL,
    SCREEN_ID               VARCHAR2(30)    DEFAULT (' ')   NOT NULL,
    SCREEN_DESC             VARCHAR2(200)   DEFAULT (' ')   NOT NULL,
    SCREEN_GROUP            VARCHAR2(10)    DEFAULT (' ')   NOT NULL,
    MODULE_NAME             VARCHAR2(20)    DEFAULT (' ')   NOT NULL,
    SERVICE_NAME            VARCHAR2(100)   DEFAULT (' ')   NOT NULL,
    CREATE_USER_ID          VARCHAR2(20)    DEFAULT (' ')   NOT NULL,
    CREATE_TIME             VARCHAR2(14)    DEFAULT (' ')   NOT NULL,
    UPDATE_USER_ID          VARCHAR2(20)    DEFAULT (' ')   NOT NULL,
    UPDATE_TIME             VARCHAR2(14)    DEFAULT (' ')   NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBASSCRDEF
ADD CONSTRAINT MBASSCRDEF_PK PRIMARY KEY
(
    SCREEN_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MBASSCRREL : Screen and MFO Relation */
CREATE TABLE MBASSCRREL
(
    RELATION_KEY                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPT_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
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
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MBASSCRCND : Condition of Screen */
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
    FMT_1                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    FMT_2                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    FMT_3                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    FMT_4                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    FMT_5                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    FMT_6                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    FMT_7                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    FMT_8                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    FMT_9                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    FMT_10                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    SIZE_1                  NUMBER(2)       DEFAULT(0)      NOT NULL,
    SIZE_2                  NUMBER(2)       DEFAULT(0)      NOT NULL,
    SIZE_3                  NUMBER(2)       DEFAULT(0)      NOT NULL,
    SIZE_4                  NUMBER(2)       DEFAULT(0)      NOT NULL,
    SIZE_5                  NUMBER(2)       DEFAULT(0)      NOT NULL,
    SIZE_6                  NUMBER(2)       DEFAULT(0)      NOT NULL,
    SIZE_7                  NUMBER(2)       DEFAULT(0)      NOT NULL,
    SIZE_8                  NUMBER(2)       DEFAULT(0)      NOT NULL,
    SIZE_9                  NUMBER(2)       DEFAULT(0)      NOT NULL,
    SIZE_10                 NUMBER(2)       DEFAULT(0)      NOT NULL,
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
    TBL_10                  VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    PRT_11                  VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    PRT_12                  VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    PRT_13                  VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    PRT_14                  VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    PRT_15                  VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    PRT_16                  VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    PRT_17                  VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    PRT_18                  VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    PRT_19                  VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    PRT_20                  VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    FMT_11                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    FMT_12                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    FMT_13                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    FMT_14                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    FMT_15                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    FMT_16                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    FMT_17                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    FMT_18                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    FMT_19                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    FMT_20                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    SIZE_11                 NUMBER(2)       DEFAULT(0)      NOT NULL,
    SIZE_12                 NUMBER(2)       DEFAULT(0)      NOT NULL,
    SIZE_13                 NUMBER(2)       DEFAULT(0)      NOT NULL,
    SIZE_14                 NUMBER(2)       DEFAULT(0)      NOT NULL,
    SIZE_15                 NUMBER(2)       DEFAULT(0)      NOT NULL,
    SIZE_16                 NUMBER(2)       DEFAULT(0)      NOT NULL,
    SIZE_17                 NUMBER(2)       DEFAULT(0)      NOT NULL,
    SIZE_18                 NUMBER(2)       DEFAULT(0)      NOT NULL,
    SIZE_19                 NUMBER(2)       DEFAULT(0)      NOT NULL,
    SIZE_20                 NUMBER(2)       DEFAULT(0)      NOT NULL,
    REQ_11                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    REQ_12                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    REQ_13                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    REQ_14                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    REQ_15                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    REQ_16                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    REQ_17                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    REQ_18                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    REQ_19                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    REQ_20                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    TBL_11                  VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    TBL_12                  VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    TBL_13                  VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    TBL_14                  VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    TBL_15                  VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    TBL_16                  VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    TBL_17                  VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    TBL_18                  VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    TBL_19                  VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    TBL_20                  VARCHAR2(20)    DEFAULT(' ')    NOT NULL
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

CREATE TABLE MBASDODDEF
(
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    DOF_ID                   VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    DOT_ID                   VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    DOT_SEQ                  NUMBER(6)       DEFAULT (0)      NOT NULL,
    LEFT_POSITION            NUMBER(10)      DEFAULT (0)      NOT NULL,
    SPACE_COUNT              NUMBER(10)      DEFAULT (0)      NOT NULL,
    START_PAGE               NUMBER(10)      DEFAULT (0)      NOT NULL,
    STOP_PAGE                NUMBER(10)      DEFAULT (0)      NOT NULL,
    HEADER_FLAG              CHAR(1)         DEFAULT (' ')    NOT NULL,
    KEEP_LINE_FLAG           CHAR(1)         DEFAULT (' ')    NOT NULL,
    KEEP_LINE                NUMBER(10)      DEFAULT (0)      NOT NULL,
    PAGE_BREAK               CHAR(1)         DEFAULT (' ')    NOT NULL,
    ROW_DATA_INC             CHAR(1)         DEFAULT (' ')    NOT NULL,
    COL_DATA_INC             CHAR(1)         DEFAULT (' ')    NOT NULL,
    ARR_CELL_SIZE            CHAR(1)         DEFAULT (' ')    NOT NULL,
    ARR_CELL_FONT            CHAR(1)         DEFAULT (' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    CREATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_1             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_2             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_3             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_4             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_5             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FLAG_1              CHAR(1)         DEFAULT (' ')    NOT NULL,
    RESV_FLAG_2              CHAR(1)         DEFAULT (' ')    NOT NULL,
    RESV_FLAG_3              CHAR(1)         DEFAULT (' ')    NOT NULL,
    RESV_FLAG_4              CHAR(1)         DEFAULT (' ')    NOT NULL,
    RESV_FLAG_5              CHAR(1)         DEFAULT (' ')    NOT NULL
)
TABLESPACE MESPLUS_DATA_TS;

CREATE UNIQUE INDEX MBASDODDEF_PK ON MBASDODDEF
(FACTORY, DOF_ID, DOT_ID, DOT_SEQ)
LOGGING
TABLESPACE MESPLUS_IDX_TS;

CREATE TABLE MBASDOFDEF
(
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    DOF_ID                   VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    DOF_DESC                 VARCHAR2(200)   DEFAULT (' ')    NOT NULL,
    MODULE_NAME              VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    SERVICE_NAME             VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    PAGE_WIDTH               NUMBER(10)      DEFAULT (0)      NOT NULL,
    PAGE_HEIGHT              NUMBER(10)      DEFAULT (0)      NOT NULL,
    PAPER_TYPE               VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    DIRECTION_TYPE           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    TOP_SPACE                NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    BOTTOM_SPACE             NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    LEFT_SPACE               NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    RIGHT_SPACE              NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    DOF_GRP_1                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOF_GRP_2                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOF_GRP_3                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOF_GRP_4                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOF_GRP_5                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOF_GRP_6                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOF_GRP_7                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOF_GRP_8                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOF_GRP_9                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOF_GRP_10               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOF_CMF_1                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOF_CMF_2                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOF_CMF_3                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOF_CMF_4                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOF_CMF_5                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOF_CMF_6                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOF_CMF_7                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOF_CMF_8                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOF_CMF_9                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOF_CMF_10               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    CREATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_1             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_2             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_3             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_4             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_5             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FLAG_1              CHAR(1)         DEFAULT (' ')    NOT NULL,
    RESV_FLAG_2              CHAR(1)         DEFAULT (' ')    NOT NULL,
    RESV_FLAG_3              CHAR(1)         DEFAULT (' ')    NOT NULL,
    RESV_FLAG_4              CHAR(1)         DEFAULT (' ')    NOT NULL,
    RESV_FLAG_5              CHAR(1)         DEFAULT (' ')    NOT NULL
)
TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBASDOFDEF ADD (
  CONSTRAINT MBASDOFDEF_PK
 PRIMARY KEY
 (FACTORY, DOF_ID)
    USING INDEX
    TABLESPACE MESPLUS_IDX_TS);

CREATE TABLE MBASDOTDEF
(
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    DOT_ID                   VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    DOT_DESC                 VARCHAR2(200)   DEFAULT (' ')    NOT NULL,
    DOC_TYPE                 VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    ROW_COUNT                NUMBER(10)      DEFAULT (0)      NOT NULL,
    ROW_HEIGHT               NUMBER(10)      DEFAULT (0)      NOT NULL,
    COLUMN_COUNT             NUMBER(10)      DEFAULT (0)      NOT NULL,
    COLUMN_WIDTH             NUMBER(10)      DEFAULT (0)      NOT NULL,
    DOT_GRP_1                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOT_GRP_2                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOT_GRP_3                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOT_GRP_4                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOT_GRP_5                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOT_GRP_6                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOT_GRP_7                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOT_GRP_8                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOT_GRP_9                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOT_GRP_10               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOT_CMF_1                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOT_CMF_2                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOT_CMF_3                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOT_CMF_4                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOT_CMF_5                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOT_CMF_6                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOT_CMF_7                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOT_CMF_8                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOT_CMF_9                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    DOT_CMF_10               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    CREATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_1             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_2             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_3             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_4             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_5             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FLAG_1              CHAR(1)         DEFAULT (' ')    NOT NULL,
    RESV_FLAG_2              CHAR(1)         DEFAULT (' ')    NOT NULL,
    RESV_FLAG_3              CHAR(1)         DEFAULT (' ')    NOT NULL,
    RESV_FLAG_4              CHAR(1)         DEFAULT (' ')    NOT NULL,
    RESV_FLAG_5              CHAR(1)         DEFAULT (' ')    NOT NULL
)
TABLESPACE MESPLUS_DATA_TS;

CREATE INDEX MBASDOTDEF_IDX_1 ON MBASDOTDEF
(FACTORY, DOC_TYPE)
LOGGING
TABLESPACE MESPLUS_IDX_TS;

ALTER TABLE MBASDOTDEF ADD (
  CONSTRAINT MBASDOTDEF_PK
 PRIMARY KEY
 (FACTORY, DOT_ID)
    USING INDEX
    TABLESPACE MESPLUS_IDX_TS);



CREATE TABLE MBASCHKQRY
(
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    QUERY_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    QUERY_TYPE                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    QUERY                       VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    ANSWER_FMT                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    ANSWER_SIZE                 NUMBER(4)        DEFAULT(0)      NOT NULL,
    VALID_TBL_TYPE              CHAR(1)          DEFAULT(' ')    NOT NULL,
    VALID_TBL_NAME              VARCHAR2(20)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBASCHKQRY
ADD CONSTRAINT MBASCHKQRY_PK PRIMARY KEY
(
    FACTORY,
    QUERY_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


CREATE TABLE MBASCHKLST
(
    /* Create/Update Info. */                   
    CREATE_USER_ID              VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)    DEFAULT(' ')    NOT NULL,
    CHKLIST_ID                  VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CHKLIST_DESC                VARCHAR2(200)   DEFAULT(' ')    NOT NULL,
    CHKLIST_TYPE                VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    LOT_OR_RES_FLAG             CHAR(1)         DEFAULT(' ')    NOT NULL,
    CHKLIST_GRP_1               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CHKLIST_GRP_2               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CHKLIST_GRP_3               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CHKLIST_GRP_4               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CHKLIST_GRP_5               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CHKLIST_GRP_6               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CHKLIST_GRP_7               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CHKLIST_GRP_8               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CHKLIST_GRP_9               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CHKLIST_GRP_10              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CHKLIST_CMF_1               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CHKLIST_CMF_2               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CHKLIST_CMF_3               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CHKLIST_CMF_4               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CHKLIST_CMF_5               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CHKLIST_CMF_6               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CHKLIST_CMF_7               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CHKLIST_CMF_8               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CHKLIST_CMF_9               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CHKLIST_CMF_10              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    KEY_1_PMT                   VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    KEY_2_PMT                   VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    KEY_3_PMT                   VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    KEY_4_PMT                   VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    KEY_5_PMT                   VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    KEY_6_PMT                   VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    KEY_7_PMT                   VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    KEY_8_PMT                   VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    KEY_9_PMT                   VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    KEY_10_PMT                  VARCHAR2(50)    DEFAULT(' ')    NOT NULL,
    KEY_1_REQ                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    KEY_2_REQ                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    KEY_3_REQ                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    KEY_4_REQ                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    KEY_5_REQ                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    KEY_6_REQ                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    KEY_7_REQ                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    KEY_8_REQ                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    KEY_9_REQ                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    KEY_10_REQ                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    KEY_1_FMT                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    KEY_2_FMT                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    KEY_3_FMT                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    KEY_4_FMT                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    KEY_5_FMT                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    KEY_6_FMT                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    KEY_7_FMT                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    KEY_8_FMT                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    KEY_9_FMT                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    KEY_10_FMT                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    KEY_1_TBL                   VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    KEY_2_TBL                   VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    KEY_3_TBL                   VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    KEY_4_TBL                   VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    KEY_5_TBL                   VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    KEY_6_TBL                   VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    KEY_7_TBL                   VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    KEY_8_TBL                   VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    KEY_9_TBL                   VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    KEY_10_TBL                  VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    KEY_1_ITEM                  VARCHAR2(100)   DEFAULT(' ')    NOT NULL,
    KEY_2_ITEM                  VARCHAR2(100)   DEFAULT(' ')    NOT NULL,
    KEY_3_ITEM                  VARCHAR2(100)   DEFAULT(' ')    NOT NULL,
    KEY_4_ITEM                  VARCHAR2(100)   DEFAULT(' ')    NOT NULL,
    KEY_5_ITEM                  VARCHAR2(100)   DEFAULT(' ')    NOT NULL,
    KEY_6_ITEM                  VARCHAR2(100)   DEFAULT(' ')    NOT NULL,
    KEY_7_ITEM                  VARCHAR2(100)   DEFAULT(' ')    NOT NULL,
    KEY_8_ITEM                  VARCHAR2(100)   DEFAULT(' ')    NOT NULL,
    KEY_9_ITEM                  VARCHAR2(100)   DEFAULT(' ')    NOT NULL,
    KEY_10_ITEM                 VARCHAR2(100)   DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBASCHKLST
ADD CONSTRAINT MBASCHKLST_PK PRIMARY KEY
(
    FACTORY,
    CHKLIST_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


CREATE TABLE MBASCHKLSQ
(
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHKLIST_ID                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    QUERY_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DISP_SEQ                    NUMBER(3)        DEFAULT(0)      NOT NULL,
    REQUIRE_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBASCHKLSQ
ADD CONSTRAINT MBASCHKLSQ_PK PRIMARY KEY
(
    FACTORY,
    CHKLIST_ID,
    QUERY_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

CREATE TABLE MBASCHKLSR
(
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    REL_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BA_POINT                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    TRAN_CODE                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    RESG_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    EVENT_ID                    VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    CHKLIST_ID                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    REL_KEY                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    APPLY_FROM_TIME             VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    APPLY_TO_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    REQ_COMPLETE_FLAG           CHAR(1)          DEFAULT(' ')    NOT NULL,
    COMPLETE_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    INHERIT_CHILD_FLAG          CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEY_1_REQ                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEY_2_REQ                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEY_3_REQ                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEY_4_REQ                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEY_5_REQ                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEY_6_REQ                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEY_7_REQ                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEY_8_REQ                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEY_9_REQ                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEY_10_REQ                  CHAR(1)          DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBASCHKLSR
ADD CONSTRAINT MBASCHKLSR_PK PRIMARY KEY
(
    FACTORY,          
    REL_LEVEL,        
    MAT_ID,            
    MAT_VER,        
    FLOW,            
    OPER,  
    BA_POINT,          
    LOT_ID,           
    TRAN_CODE,        
    RESG_ID,          
    RES_TYPE,         
    RES_ID,           
    EVENT_ID,    
    CHKLIST_ID    
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

CREATE TABLE MBASCHKLSH
(
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHKLIST_ID                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    REL_KEY                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    COMPLETE_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    COMPLETE_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    COMPLETE_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DELETE_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    DELETE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    DELETE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    BASE_OBJ_ID                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BASE_OBJ_HIST_SEQ           NUMBER(6)        DEFAULT(0)      NOT NULL,
    KEY_1_VALUE                 VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    KEY_2_VALUE                 VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    KEY_3_VALUE                 VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    KEY_4_VALUE                 VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    KEY_5_VALUE                 VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    KEY_6_VALUE                 VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    KEY_7_VALUE                 VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    KEY_8_VALUE                 VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    KEY_9_VALUE                 VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    KEY_10_VALUE                VARCHAR2(100)    DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBASCHKLSH
ADD CONSTRAINT MBASCHKLSH_PK PRIMARY KEY
(
    FACTORY,
    CHKLIST_ID,
    HIST_SEQ
) USING INDEX TABLESPACE MESPLUS_IDX_TS;




CREATE TABLE MBASCHKLSA
(
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHKLIST_ID                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    REL_KEY                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    QUERY_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    ANSWER                      VARCHAR2(4000)   DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBASCHKLSA
ADD CONSTRAINT MBASCHKLSA_PK PRIMARY KEY
(
    FACTORY,
    CHKLIST_ID,
    HIST_SEQ,
    QUERY_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;






/*==== SVM(Service Management) ====*/
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
  ARRAY_TYPE                    VARCHAR2(10)     DEFAULT (' ')    NOT NULL,
  USE_RANGE_FLAG                CHAR(1)          DEFAULT (' ')    NOT NULL,
  RANGE_MIN                     NUMBER(22,4)     DEFAULT (0)      NOT NULL,
  RANGE_MAX                     NUMBER(22,4)     DEFAULT (0)      NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSVMMBRDEF
ADD CONSTRAINT MSVMMBRDEF_PK PRIMARY KEY
(
  MEMBER_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


CREATE TABLE MSVMSVCDEF
(
    SERVICE_NAME                VARCHAR2(100)    DEFAULT (' ')   NOT NULL,
    MODULE_NAME                 VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
    SERVICE_MODE                VARCHAR2(2)      DEFAULT (' ')   NOT NULL,
    SERVICE_CATEGORY            CHAR(1)          DEFAULT (' ')   NOT NULL,
    SERVICE_TYPE                CHAR(1)          DEFAULT (' ')   NOT NULL,
    SERVICE_DESC_1              VARCHAR2(1000)   DEFAULT (' ')   NOT NULL,
    SERVICE_DESC_2              VARCHAR2(1000)   DEFAULT (' ')   NOT NULL,
    SERVICE_DESC_3              VARCHAR2(1000)   DEFAULT (' ')   NOT NULL,
    SEC_CHK_FLAG                CHAR(1)          DEFAULT (' ')   NOT NULL,
    LOG_LEVEL                   CHAR(1)          DEFAULT (' ')   NOT NULL,
    SHARED_LIB_NAME             VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
    SERVICE_CMF_1               VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
    SERVICE_CMF_2               VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
    SERVICE_CMF_3               VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
    SERVICE_CMF_4               VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
    SERVICE_CMF_5               VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
    SERVICE_CMF_6               VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
    SERVICE_CMF_7               VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
    SERVICE_CMF_8               VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
    SERVICE_CMF_9               VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
    SERVICE_CMF_10              VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSVMSVCDEF
ADD CONSTRAINT MSVMSVCDEF_PK PRIMARY KEY
(
  SERVICE_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSVMMBRDEF : Service Management Service Member Table */
CREATE TABLE MSVMSVCMBR
(
  MODULE_NAME                  VARCHAR2(30)      DEFAULT (' ')    NOT NULL,
  SERVICE_NAME                 VARCHAR2(100)     DEFAULT (' ')    NOT NULL,
  DIRECTION                    CHAR(1)           DEFAULT (' ')    NOT NULL,
  MEMBER_PATH                  VARCHAR2(1000)    DEFAULT (' ')    NOT NULL,
  MEMBER_DEPTH                 NUMBER(6)         DEFAULT (0)      NOT NULL,
  MEMBER_SEQ                   NUMBER(6)         DEFAULT (0)      NOT NULL,
  PARENT_MEMBER_PATH           VARCHAR2(1000)    DEFAULT (' ')    NOT NULL,
  MEMBER_NAME                  VARCHAR2(50)      DEFAULT (' ')    NOT NULL,
  MEMBER_DESC_1                VARCHAR2(1000)    DEFAULT (' ')    NOT NULL,
  MEMBER_DESC_2                VARCHAR2(1000)    DEFAULT (' ')    NOT NULL,
  MEMBER_DESC_3                VARCHAR2(1000)    DEFAULT (' ')    NOT NULL,
  MEMBER_TYPE                  VARCHAR2(10)      DEFAULT (' ')    NOT NULL,
  MEMBER_SIZE                  NUMBER(6)         DEFAULT (0)      NOT NULL,
  MEMBER_PRT                   VARCHAR2(50)      DEFAULT (' ')    NOT NULL,
  ARRAY_TYPE                   VARCHAR2(10)      DEFAULT (' ')    NOT NULL,
  REQ_MEMBER_FLAG              CHAR(1)           DEFAULT (' ')    NOT NULL,
  OVERRIDE_FLAG                CHAR(1)           DEFAULT (' ')    NOT NULL,
  USE_RANGE_FLAG               CHAR(1)           DEFAULT (' ')    NOT NULL,
  RANGE_MIN                    NUMBER(22,4)      DEFAULT (0)      NOT NULL,
  RANGE_MAX                    NUMBER(22,4)      DEFAULT (0)      NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSVMSVCMBR
ADD CONSTRAINT MSVMSVCMBR_PK PRIMARY KEY
(
  MODULE_NAME,
  SERVICE_NAME,
  DIRECTION,
  MEMBER_PATH
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* Shared Library Pool Default Version List */
CREATE TABLE MSVMDFTVER
(
    LIB_NAME                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LIB_VER                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SERVICE_NAME                VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    SERVICE_VER                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    LOAD_ONLY_FLAG              CHAR(1)          DEFAULT(' ')    NOT NULL,
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
    KEY_NAME                    VARCHAR2(250)    DEFAULT(' ')    NOT NULL,
    KEY_DESC                    VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
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
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    CONSUME_SEC_1               NUMBER(15,3)     DEFAULT(0)      NOT NULL,
    CONSUME_SEC_2               NUMBER(15,3)     DEFAULT(0)      NOT NULL,
    CONSUME_SEC_3               NUMBER(15,3)     DEFAULT(0)      NOT NULL,
    CONSUME_SEC_4               NUMBER(15,3)     DEFAULT(0)      NOT NULL,
    CONSUME_SEC_5               NUMBER(15,3)     DEFAULT(0)      NOT NULL
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
























/*==== RTD(Real-Time Dispatch Module) ====*/
/* MRTDDSPDEF : Dispatcher Definition Table */
CREATE TABLE MRTDDSPDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    DSP_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DSP_DESC                    VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    RES_OR_OPER                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    PRV_GRP_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    MAX_COUNT                   NUMBER(4)        DEFAULT(0)      NOT NULL,
    LOT_RULE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RESOURCE_RULE               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRTDDSPDEF
ADD CONSTRAINT MRTDDSPDEF_PK PRIMARY KEY
(
    FACTORY,
    DSP_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;



/* MRTDDSPRES : Dispatcher-Resource Attach Table */
CREATE TABLE MRTDDSPRES
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    DSP_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRTDDSPRES
ADD CONSTRAINT MRTDDSPRES_PK PRIMARY KEY
(
    FACTORY,
    DSP_ID,
    RES_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;



/* MRTDDSPOPR : Dispatcher-Operation Attach Table */
CREATE TABLE MRTDDSPOPR
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    DSP_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRTDDSPOPR
ADD CONSTRAINT MRTDDSPOPR_PK PRIMARY KEY
(
    FACTORY,
    DSP_ID,
    OPER
) USING INDEX TABLESPACE MESPLUS_IDX_TS;



/* MRTDRULDEF : Dispatcher-Rule Definition Table */
CREATE TABLE MRTDRULDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')      NOT NULL,
    RULE_ID                     VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    RULE_DESC                   VARCHAR2(200)    DEFAULT(' ')      NOT NULL,
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
    /* Add 2009.01.25 */
    CAPABLE_FLAG                CHAR(1)          DEFAULT(' ')      NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')      NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')      NOT NULL,
    RULE_ITEM_DESC              VARCHAR2(200)    DEFAULT (' ')     NOT NULL
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


/* MRTDRULEXT: Rule-Item Definition Table (Extended) */
CREATE TABLE MRTDRULEXT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')      NOT NULL,
    RULE_ID                     VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    RULE_TYPE                   CHAR(1)          DEFAULT(' ')      NOT NULL,
    PRIO_LEVEL                  NUMBER(6)        DEFAULT(0)        NOT NULL,
    PRIO_KEY                    VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    KEY_VALUE_1                 VARCHAR2(100)    DEFAULT(' ')      NOT NULL,
    KEY_VALUE_2                 VARCHAR2(100)    DEFAULT(' ')      NOT NULL,
    OPERATOR                    VARCHAR2(10)     DEFAULT(' ')      NOT NULL,
    TABLE_NAME                  VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')      NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')      NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')      NOT NULL
)
TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRTDRULEXT
ADD CONSTRAINT MRTDRULEXT_PK PRIMARY KEY
(
    FACTORY,
    RULE_ID,
    RULE_TYPE,
    PRIO_LEVEL,
    PRIO_KEY,
    KEY_VALUE_1,
    KEY_VALUE_2
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* Add for NEW RTD */
/* MRTDEVNCON : Dispatch Event Configuration Table */
CREATE TABLE MRTDEVNCON
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SERVICE_NAME                VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    SERVICE_SEQ                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    SERVICE_DESC                VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
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
    /* Add 2009.01.15 */
    UNSELECT_CAPABLE_ONLY_FLAG  CHAR(1)          DEFAULT(' ')    NOT NULL,
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
    /* Add 2009.01.15 */
    UNSELECT_CAPABLE_ONLY_FLAG  CHAR(1)          DEFAULT(' ')    NOT NULL,
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
    UNSELECT_CAPABLE_ONLY_FLAG  CHAR(1)          DEFAULT(' ')    NOT NULL,
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
    /* Add 2009.01.25 */
    TEMP_BATCH_SEQ              NUMBER(3)        DEFAULT (0)     NOT NULL,
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
    /* Add 2009.01.25 */
    UNSELECT_REASON             VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    CAPABLE_REASON              VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    /* Add 2009.03.12 CMF 1 ~ 10 */
    PDS_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PDS_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PDS_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PDS_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PDS_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PDS_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PDS_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PDS_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PDS_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PDS_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
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
    /* Add 2009.01.25 */
    TEMP_BATCH_SEQ              NUMBER(3)        DEFAULT (0)     NOT NULL,
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
    /* Add 2009.01.25 */
    UNSELECT_REASON             VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    CAPABLE_REASON              VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    /* Add 2009.03.12 CMF 1 ~ 10 */
    PDS_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PDS_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PDS_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PDS_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PDS_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PDS_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PDS_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PDS_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PDS_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PDS_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
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

























/*==== RCP(Recipe Management Module) ====*/
/* MRCPRCPDEF : Recipe Definition Table */
CREATE TABLE MRCPRCPDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RECIPE                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RECIPE_DESC                 VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Group 1 ~ 10 */
    RCP_GRP_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RCP_GRP_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RCP_GRP_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RCP_GRP_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RCP_GRP_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RCP_GRP_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RCP_GRP_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RCP_GRP_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RCP_GRP_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RCP_GRP_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* CMF 1 ~ 10 */
    RCP_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RCP_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RCP_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RCP_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RCP_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RCP_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RCP_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RCP_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RCP_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RCP_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Approval Info. */
    APPROVAL_REQUIRE_FLAG       CHAR(1)          DEFAULT(' ')    NOT NULL,
    APPROVAL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Delete Info. */
    DELETE_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    DELETE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DELETE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRCPRCPDEF
ADD CONSTRAINT MRCPRCPDEF_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    SUBRES_ID,
    RECIPE
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRCPRCPVER : Recipe Version  */
CREATE TABLE MRCPRCPVER
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RECIPE                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RECIPE_VERSION              NUMBER(3)        DEFAULT(0)      NOT NULL,
    PP_ID                       VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    COAT_PP_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RETICLE_ID                  VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    COL_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* RECIPE PRECESSING TIME */
    PROC_TIME                   VARCHAR2(6)      DEFAULT(' ')    NOT NULL,
    MODIFY_FLAG                 CHAR(1)          DEFAULT('N')    NOT NULL,
    /* Apply Start/End Time */
    APPLY_START_TIME            VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    APPLY_END_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Approval Info. */
    APPROVAL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    APPROVAL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    APPROVAL_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Release Info.*/
    RELEASE_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    RELEASE_USER_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RELEASE_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRCPRCPVER
ADD CONSTRAINT MRCPRCPVER_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    SUBRES_ID,
    RECIPE,
    RECIPE_VERSION
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRCPMFODEF : MFO Recipe Setting */
CREATE TABLE MRCPMFODEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Option Level - '1':M-F-O, '2':F-O, '3':O */
    OPT_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Recipe */
    RECIPE                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRCPMFODEF
ADD CONSTRAINT MRCPMFODEF_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    OPER,
    RES_ID,
    SUBRES_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

CREATE INDEX MRCPMFODEF_IDX_1 ON MRCPMFODEF
(
    FACTORY,
    RECIPE
) TABLESPACE MESPLUS_IDX_TS;


/* MRCPPRAVER : Recipe Parameter Version  */
CREATE TABLE MRCPPRAVER
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RECIPE                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RECIPE_VERSION              NUMBER(3)        DEFAULT(0)      NOT NULL,
    PARA_SEQ                    NUMBER(3)        DEFAULT(0)      NOT NULL,
    PARA_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PARA_VALUE                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PARA_DESC                   VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    MODIFY_FLAG                 CHAR(1)          DEFAULT('N')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRCPPRAVER
ADD CONSTRAINT MRCPPRAVER_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    SUBRES_ID,
    RECIPE,
    RECIPE_VERSION,
    PARA_SEQ
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRCPLOTRCP: Lot Current Recipe   */
CREATE TABLE MRCPLOTRCP
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RECIPE                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RECIPE_VERSION              NUMBER(3)        DEFAULT(0)      NOT NULL,
    PP_ID                       VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    COAT_PP_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RETICLE_ID                  VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    COL_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* RECIPE PRECESSING TIME */
    PROC_TIME                   VARCHAR2(6)      DEFAULT(' ')    NOT NULL,
    MODIFY_FLAG                 CHAR(1)          DEFAULT('N')    NOT NULL,
    INLINE_MODIFY               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRCPLOTRCP
ADD CONSTRAINT MRCPLOTRCP_PK PRIMARY KEY
(
    LOT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRCPLOTPRA : Lot Current Parameter */
CREATE TABLE MRCPLOTPRA
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RECIPE                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RECIPE_VERSION              NUMBER(3)        DEFAULT(0)      NOT NULL,
    PARA_SEQ                    NUMBER(3)        DEFAULT(0)      NOT NULL,
    PARA_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PARA_VALUE                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PARA_DESC                   VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    MODIFY_FLAG                 CHAR(1)          DEFAULT('N')    NOT NULL,
    /* Create/Update Info. */
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRCPLOTPRA
ADD CONSTRAINT MRCPLOTPRA_PK PRIMARY KEY
(
    LOT_ID,
    PARA_SEQ
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRCPLOTHIS: Lot Recipe History */
CREATE TABLE MRCPLOTHIS
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    TRAN_CODE                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RECIPE                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RECIPE_VERSION              NUMBER(3)        DEFAULT(0)      NOT NULL,
    PP_ID                       VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    COAT_PP_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RETICLE_ID                  VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    COL_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* RECIPE PRECESSING TIME */
    PROC_TIME                   VARCHAR2(6)      DEFAULT(' ')    NOT NULL,
    MODIFY_FLAG                 CHAR(1)          DEFAULT('N')    NOT NULL,
    INLINE_MODIFY               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MRCPLOTHIS
ADD CONSTRAINT MRCPLOTHIS_PK PRIMARY KEY
(
    LOT_ID,
    TRAN_TIME
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MRCPLOTHIS_IDX_1 ON MRCPLOTHIS
(
    LOT_ID,
    HIST_SEQ
) TABLESPACE HISTORY_IDX_TS;


/* MRCPPRAHIS : Lot Parameter History  */
CREATE TABLE MRCPPRAHIS
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    TRAN_CODE                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RECIPE                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RECIPE_VERSION              NUMBER(3)        DEFAULT(0)      NOT NULL,
    PARA_SEQ                    NUMBER(3)        DEFAULT(0)      NOT NULL,
    PARA_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PARA_VALUE                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PARA_DESC                   VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    MODIFY_FLAG                 CHAR(1)          DEFAULT('N')    NOT NULL,
    /* Create/Update Info. */
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MRCPPRAHIS
ADD CONSTRAINT MRCPPRAHIS_PK PRIMARY KEY
(
    LOT_ID,
    TRAN_TIME,
    PARA_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MRCPPRAHIS_IDX_1 ON MRCPPRAHIS
(
    LOT_ID,
    HIST_SEQ,
    PARA_SEQ
) TABLESPACE HISTORY_IDX_TS;


/* MRCPSLTRCP: Sublot Current Recipe */
CREATE TABLE MRCPSLTRCP
(
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RECIPE                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RECIPE_VERSION              NUMBER(3)        DEFAULT(0)      NOT NULL,
    PP_ID                       VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    COAT_PP_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RETICLE_ID                  VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    COL_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* RECIPE PRECESSING TIME */
    PROC_TIME                   VARCHAR2(6)      DEFAULT(' ')    NOT NULL,
    MODIFY_FLAG                 CHAR(1)          DEFAULT('N')    NOT NULL,
    INLINE_MODIFY               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRCPSLTRCP
ADD CONSTRAINT MRCPSLTRCP_PK PRIMARY KEY
(
    SUBLOT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

CREATE INDEX MRCPSLTRCP_IDX_1 ON MRCPSLTRCP
(
    LOT_ID
) TABLESPACE MESPLUS_IDX_TS;


/* MRCPSLTPRA : Sublot Current Parameter */
CREATE TABLE MRCPSLTPRA
(
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RECIPE                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RECIPE_VERSION              NUMBER(3)        DEFAULT(0)      NOT NULL,
    PARA_SEQ                    NUMBER(3)        DEFAULT(0)      NOT NULL,
    PARA_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PARA_VALUE                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PARA_DESC                   VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    MODIFY_FLAG                 CHAR(1)          DEFAULT('N')    NOT NULL,
    /* Create/Update Info. */
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRCPSLTPRA
ADD CONSTRAINT MRCPSLTPRA_PK PRIMARY KEY
(
    SUBLOT_ID,
    PARA_SEQ
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

CREATE INDEX MRCPSLTPRA_IDX_1 ON MRCPSLTPRA
(
    LOT_ID
) TABLESPACE MESPLUS_IDX_TS;


/* MRCPSLTHIS: Sublot Recipe History */
CREATE TABLE MRCPSLTHIS
(
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    TRAN_CODE                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RECIPE                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RECIPE_VERSION              NUMBER(3)        DEFAULT(0)      NOT NULL,
    PP_ID                       VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    COAT_PP_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RETICLE_ID                  VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    COL_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* RECIPE PRECESSING TIME */
    PROC_TIME                   VARCHAR2(6)      DEFAULT(' ')    NOT NULL,
    MODIFY_FLAG                 CHAR(1)          DEFAULT('N')    NOT NULL,
    INLINE_MODIFY               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MRCPSLTHIS
ADD CONSTRAINT MRCPSLTHIS_PK PRIMARY KEY
(
    SUBLOT_ID,
    TRAN_TIME
) USING INDEX TABLESPACE HISTORY_IDX_TS;


CREATE INDEX MRCPSLTHIS_IDX_1 ON MRCPSLTHIS
(
    SUBLOT_ID,
    HIST_SEQ
) TABLESPACE HISTORY_IDX_TS;


/* MRCPSLPHIS : Subot Parameter History */
CREATE TABLE MRCPSLPHIS
(
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    TRAN_CODE                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RECIPE                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RECIPE_VERSION              NUMBER(3)        DEFAULT(0)      NOT NULL,
    PARA_SEQ                    NUMBER(3)        DEFAULT(0)      NOT NULL,
    PARA_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PARA_VALUE                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PARA_DESC                   VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    MODIFY_FLAG                 CHAR(1)          DEFAULT('N')    NOT NULL,
    /* Create/Update Info. */
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MRCPSLPHIS
ADD CONSTRAINT MRCPSLPHIS_PK PRIMARY KEY
(
    SUBLOT_ID,
    TRAN_TIME,
    PARA_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MRCPSLPHIS_IDX_1 ON MRCPSLPHIS
(
    SUBLOT_ID,
    HIST_SEQ,
    PARA_SEQ
) TABLESPACE HISTORY_IDX_TS;




















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























/*** Add SPM Module (2012.04.20 by JYPARK) ***/
/*==== SPM(SPecification Management Module) ====*/
/* MSPMRELDEF : SPM Relation Definition */
CREATE TABLE MSPMRELDEF
(
    FACTORY                  VARCHAR2(10)    DEFAULT(' ')    NOT NULL,
    REL_LEVEL                CHAR(1)         DEFAULT(' ')    NOT NULL,
    MAT_ID                   VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    MAT_VER                  NUMBER(6,0)     DEFAULT(0)      NOT NULL,
    FLOW                     VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    OPER                     VARCHAR2(10)    DEFAULT(' ')    NOT NULL,
    SPEC_REL_ID              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    CREATE_TIME              VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSPMRELDEF
ADD CONSTRAINT MSPMRELDEF_PK PRIMARY KEY
(
    FACTORY,
    REL_LEVEL,
    MAT_ID,
    MAT_VER,
    FLOW,
    OPER
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSPMRELVER : SPM Relation Version */
CREATE TABLE MSPMRELVER
(
    SPEC_REL_ID              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    SPEC_REL_VER             NUMBER(3,0)     DEFAULT(0)      NOT NULL,
    APPLY_START_TIME         VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    APPLY_END_TIME           VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    APPROVAL_FLAG            CHAR(1)         DEFAULT(' ')    NOT NULL,
    APPROVAL_USER_ID         VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    APPROVAL_TIME            VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    RELEASE_FLAG             CHAR(1)         DEFAULT(' ')    NOT NULL,
    RELEASE_USER_ID          VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    RELEASE_TIME             VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    CREATE_TIME              VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSPMRELVER
ADD CONSTRAINT MSPMRELVER_PK PRIMARY KEY
(
    SPEC_REL_ID,
    SPEC_REL_VER
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSPMRELCHR : SPM Relation Characters */
CREATE TABLE MSPMRELCHR
(
    SPEC_REL_ID                     VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    SPEC_REL_VER                    NUMBER(3,0)     DEFAULT(0)      NOT NULL,
    CHAR_ID                         VARCHAR2(25)    DEFAULT(' ')    NOT NULL,
    /* M:Manufacture Spec, C:Customer Spec */
    SPEC_REF_TYPE                   CHAR(1)         DEFAULT(' ')    NOT NULL,
    /* B:Both Limit, U:Upper Limit, L:Lower Limit, T:Table Data Limit, F:Attached File */
    SPEC_TYPE                       CHAR(1)         DEFAULT(' ')    NOT NULL,
    VALID_TABLE                     VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    TARGET_VALUE                    VARCHAR2(400)   DEFAULT(' ')    NOT NULL,
    SPEC_OUT_COUNT                  NUMBER(3,0)     DEFAULT(0)      NOT NULL,
    UPPER_SPEC_LIMIT                VARCHAR2(25)    DEFAULT(' ')    NOT NULL,
    LOWER_SPEC_LIMIT                VARCHAR2(25)    DEFAULT(' ')    NOT NULL,
    UPPER_WARN_LIMIT                VARCHAR2(25)    DEFAULT(' ')    NOT NULL,
    LOWER_WARN_LIMIT                VARCHAR2(25)    DEFAULT(' ')    NOT NULL,
    SPEC_OUT_ALARM                  VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    WARN_OUT_ALARM                  VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    CUST_SPEC_TYPE                  CHAR(1)         DEFAULT(' ')    NOT NULL,
    CUST_VALID_TABLE                VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    CUST_TARGET_VALUE               VARCHAR2(400)   DEFAULT(' ')    NOT NULL,
    CUST_SPEC_OUT_COUNT             NUMBER(3,0)     DEFAULT(0)      NOT NULL,
    CUST_UPPER_SPEC_LIMIT           VARCHAR2(25)    DEFAULT(' ')    NOT NULL,
    CUST_LOWER_SPEC_LIMIT           VARCHAR2(25)    DEFAULT(' ')    NOT NULL,
    CUST_UPPER_WARN_LIMIT           VARCHAR2(25)    DEFAULT(' ')    NOT NULL,
    CUST_LOWER_WARN_LIMIT           VARCHAR2(25)    DEFAULT(' ')    NOT NULL,
    CUST_SPEC_OUT_ALARM             VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    CUST_WARN_OUT_ALARM             VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID                  VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    CREATE_TIME                     VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID                  VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                     VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    USE_CHAR_DIR                    CHAR(1)         DEFAULT(' ')    NOT NULL,
    TARGET_VALUE_WITH_DIR           CHAR(1)         DEFAULT(' ')    NOT NULL,
    TARGET_VALUE_WITH_FILE          CHAR(1)         DEFAULT(' ')    NOT NULL,
    TARGET_FILE_EXT                 VARCHAR2(10)    DEFAULT(' ')    NOT NULL,
    USE_LATEST_FILE_VER             CHAR(1)         DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSPMRELCHR
ADD CONSTRAINT MSPMRELCHR_PK PRIMARY KEY
(
    SPEC_REL_ID,
    SPEC_REL_VER,
    CHAR_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSPMCHRDSV : SPM Character Default Specification Limit by Valid Table */
CREATE TABLE MSPMCHRDSV
(
    SPEC_REL_ID              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    SPEC_REL_VER             NUMBER(3,0)     DEFAULT(0)      NOT NULL,
    CHAR_ID                  VARCHAR2(25)    DEFAULT(' ')    NOT NULL,
    SPEC_REF_TYPE            CHAR(1)         DEFAULT(' ')    NOT NULL,
    VALUE                    VARCHAR2(25)    DEFAULT(' ')    NOT NULL,
    LIMIT_TYPE               CHAR(1)         DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    CREATE_TIME              VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSPMCHRDSV
ADD CONSTRAINT MSPMCHRDSV_PK PRIMARY KEY
(
    SPEC_REL_ID,
    SPEC_REL_VER,
    CHAR_ID,
    SPEC_REF_TYPE,
    VALUE
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSPMDOCIMG : SPM Document and Image store Table */
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


/* MEDCSPMVER : SPM Character Default Specification Limit by Valid Table */
CREATE TABLE MEDCSPMVER
(
    FACTORY                  VARCHAR2(10)    DEFAULT(' ')    NOT NULL,
    OBJ_ID                   VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    OBJ_HIST_SEQ             NUMBER(10,0)    DEFAULT(0)      NOT NULL,
    COL_SET_ID               VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    COL_SET_VER              NUMBER(3,0)     DEFAULT(0)      NOT NULL,
    COL_SEQ                  NUMBER(10,0)    DEFAULT(0)      NOT NULL,
    SPEC_REL_ID              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    SPEC_REL_VER             NUMBER(3,0)     DEFAULT(0)      NOT NULL,
    CHAR_ID                  VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    CREATE_TIME              VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MEDCSPMVER
ADD CONSTRAINT MEDCSPMVER_PK PRIMARY KEY
(
    FACTORY,
    OBJ_ID,
    OBJ_HIST_SEQ,
    COL_SET_ID,
    COL_SET_VER,
    COL_SEQ,
    SPEC_REL_ID,
    SPEC_REL_VER,
    CHAR_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSPMATRSTS : Specification Attribute Value Status */
CREATE TABLE MSPMATRSTS
(
    SPEC_REL_ID              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    SPEC_REL_VER             NUMBER(3,0)     DEFAULT(0)      NOT NULL,
    CHAR_ID                  VARCHAR2(25)    DEFAULT(' ')    NOT NULL,
    ATTR_NAME                VARCHAR2(100)   DEFAULT(' ')    NOT NULL,
    ATTR_VALUE               VARCHAR2(1000)  DEFAULT(' ')    NOT NULL,
    NULL_FLAG                CHAR(1)         DEFAULT(' ')    NOT NULL,
    LAST_TRAN_TIME           VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    LAST_ACTIVE_HIST_SEQ     NUMBER(10,0)    DEFAULT(0)      NOT NULL,
    LAST_HIST_SEQ            NUMBER(10,0)    DEFAULT(0)      NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    CREATE_TIME              VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSPMATRSTS
ADD CONSTRAINT MSPMATRSTS_PK PRIMARY KEY
(
    SPEC_REL_ID,
    SPEC_REL_VER,
    CHAR_ID,
    ATTR_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MSPMATRHIS : Specification Attribute Value History */
CREATE TABLE MSPMATRHIS
(
    SPEC_REL_ID              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    SPEC_REL_VER             NUMBER(3,0)     DEFAULT(0)      NOT NULL,
    CHAR_ID                  VARCHAR2(25)    DEFAULT(' ')    NOT NULL,
    ATTR_NAME                VARCHAR2(100)   DEFAULT(' ')    NOT NULL,
    HIST_SEQ                 NUMBER(10,0)    DEFAULT(0)      NOT NULL,
    ATTR_OLD_VALUE           VARCHAR2(1000)  DEFAULT(' ')    NOT NULL,
    ATTR_VALUE               VARCHAR2(1000)  DEFAULT(' ')    NOT NULL,
    NULL_FLAG                CHAR(1)         DEFAULT(' ')    NOT NULL,
    TRAN_TIME                VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    SYS_TRAN_TIME            VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    PREV_ACTIVE_HIST_SEQ     NUMBER(10,0)    DEFAULT(0)      NOT NULL,
    HIST_DEL_FLAG            CHAR(1)         DEFAULT(' ')    NOT NULL,
    HIST_DEL_TIME            VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    HIST_DEL_USER_ID         VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    HIST_DEL_COMMENT         VARCHAR2(400)   DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    CREATE_TIME              VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MSPMATRHIS
ADD CONSTRAINT MSPMATRHIS_PK PRIMARY KEY
(
    SPEC_REL_ID,
    SPEC_REL_VER,
    CHAR_ID,
    ATTR_NAME,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

/*** End of Add (2012.04.20) ***/
























/*==== EDC(Engineering Data Collection Module) ====*/
/* MEDCCHRDEF : EDC Characteristics Definition Table */
CREATE TABLE MEDCCHRDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHAR_ID                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    CHAR_DESC                   VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* A : ASCII, N : NUMBER */
    VALUE_TYPE                  CHAR(1)          DEFAULT('N')    NOT NULL,
    /* Added by LAVERWON (08/01/11) - Unit, Specification/Warning Limit */
    UNIT                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TARGET_VALUE                VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    UPPER_SPEC_LIMIT            VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOWER_SPEC_LIMIT            VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    UPPER_WARN_LIMIT            VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOWER_WARN_LIMIT            VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    UPPER_CUST_LIMIT            VARCHAR2(25)     DEFAULT(' ')    NOT NULL,  /* Unused */
    LOWER_CUST_LIMIT            VARCHAR2(25)     DEFAULT(' ')    NOT NULL,  /* Unused */
    /* Character Group 1 ~ 10 */
    CHAR_GRP_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHAR_GRP_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHAR_GRP_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHAR_GRP_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHAR_GRP_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHAR_GRP_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHAR_GRP_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHAR_GRP_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHAR_GRP_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHAR_GRP_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* CMF 1 ~ 25 */
    CHAR_CMF_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHAR_CMF_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHAR_CMF_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHAR_CMF_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHAR_CMF_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHAR_CMF_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHAR_CMF_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHAR_CMF_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHAR_CMF_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHAR_CMF_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Character Type: 'E' or ' ' - EDC Only, 'S' - Spec Only, 'B' - Both */
    CHAR_TYPE                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Value Validation Table Name */
    VALID_TABLE                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    ATTACH_FILE_DIR             VARCHAR2(1000)   DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MEDCCHRDEF
ADD CONSTRAINT MEDCCHRDEF_PK PRIMARY KEY
(
    FACTORY,
    CHAR_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MEDCCOLDEF : EDC Collection Set Definition Table */
CREATE TABLE MEDCCOLDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    COL_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    COL_SET_DESC                VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Character Group 1 ~ 10 */
    COL_GRP_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COL_GRP_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COL_GRP_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COL_GRP_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COL_GRP_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COL_GRP_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COL_GRP_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COL_GRP_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COL_GRP_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COL_GRP_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* CMF 1 ~ 25 */
    COL_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COL_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COL_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COL_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COL_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COL_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COL_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COL_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COL_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COL_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Added by LAVERWON (08/01/11) - Unit, Specification/Warning Limit */
    DEFAULT_COL_MODE_FLAG       CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* LOT or Resource Flag - 'L':Lot, 'R':Resource, 'B':Both */
    LOT_OR_RES_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Approval Info. */
    APPROVAL_REQUIRE_FLAG       CHAR(1)          DEFAULT(' ')    NOT NULL,
    APPROVAL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Delete Info. */
    DELETE_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    DELETE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DELETE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MEDCCOLDEF
ADD CONSTRAINT MEDCCOLDEF_PK PRIMARY KEY
(
    FACTORY,
    COL_SET_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MEDCCOLVER : EDC Collection Set Version Definition Table */
CREATE TABLE MEDCCOLVER
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    COL_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    COL_SET_VERSION             NUMBER(3)        DEFAULT(0)      NOT NULL,
    /* Apply Start/End Time */
    APPLY_START_TIME            VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    APPLY_END_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Approval Info. */
    APPROVAL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    APPROVAL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    APPROVAL_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Release Info.*/
    RELEASE_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    RELEASE_USER_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RELEASE_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MEDCCOLVER
ADD CONSTRAINT MEDCCOLVER_PK PRIMARY KEY
(
    FACTORY,
    COL_SET_ID,
    COL_SET_VERSION
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MEDCCOLCHR : Collection Set Version-Character Attach Table */
CREATE TABLE MEDCCOLCHR
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    COL_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    COL_SET_VERSION             NUMBER(3)        DEFAULT(0)      NOT NULL,
    CHAR_ID                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Unit Count/Value Count(ex, Wafer 3 Unit에서 1 Wafer 당 5 Value) */
    UNIT_COUNT                  NUMBER(3)        DEFAULT(0)      NOT NULL,
    VALUE_COUNT                 NUMBER(4)        DEFAULT(0)      NOT NULL,
    /* Optional Input Flag -  _:Essential, Y:Optional */
    OPT_INPUT_FLAG              CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Blank Record Save Flag  - _:Not Save, Y:Save */
    BLANK_REC_SAVE_FLAG         CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Display Precision */
    DISPLAY_PRECISION           NUMBER(1)        DEFAULT(0)      NOT NULL,
    /* Default Unit ID - _:Not Use, Y:Use */
    DEF_UNIT_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Default Unit ID Override Flag - _:Fixed, Y:Override */
    DEF_UNIT_OVR_FLAG           CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Default Value */
    DEF_VALUE                   VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Unit ID Check Table(GCM Table) */
    UNIT_TBL                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Value Check Table(GCM Table) */
    VALUE_TBL                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Spec. Out Count */
    SPEC_OUT_COUNT              NUMBER(3)        DEFAULT(0)      NOT NULL,
    /* Spec. Info. */
    /* Spec Type - B:Both Side, U:Upper Side, L:Lower Side */
    SPEC_TYPE                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Target Value */
    TARGET_VALUE                VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Specification Limit */
    UPPER_SPEC_LIMIT            VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOWER_SPEC_LIMIT            VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Warning Limit */
    UPPER_WARN_LIMIT            VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOWER_WARN_LIMIT            VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Customer Limit */
    UPPER_CUST_LIMIT            VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOWER_CUST_LIMIT            VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Specification Information */
    SPEC_INFO                   VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Specification / Warning Limit Out - Alarm Code */
    SPEC_OUT_ALARM              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    WARN_OUT_ALARM              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
     /* Derived Parameter */
    DERIVED_PARAM_FLAG          CHAR(1)          DEFAULT(' ')    NOT NULL,
    DERIVED_PARAMETER           VARCHAR2(2000)   DEFAULT(' ')    NOT NULL,
    /* Data Type for SPC - 20080130 */
    DATA_TYPE                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    NO_USE_SPM_VALUE_FLAG       CHAR(1)          DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MEDCCOLCHR
ADD CONSTRAINT MEDCCOLCHR_PK PRIMARY KEY
(
    FACTORY,
    COL_SET_ID,
    COL_SET_VERSION,
    CHAR_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MEDCCOLUNT : Collection Set Default Unit ID Table */
CREATE TABLE MEDCCOLUNT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    COL_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    COL_SET_VERSION             NUMBER(3)        DEFAULT(0)      NOT NULL,
    CHAR_ID                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Unit Seq Number */
    UNIT_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Null Data Flag */
    NULL_FLAG                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Default Unit ID */
    DEF_UNIT_ID                 VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* Create Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MEDCCOLUNT
ADD CONSTRAINT MEDCCOLUNT_PK PRIMARY KEY
(
    FACTORY,
    COL_SET_ID,
    COL_SET_VERSION,
    CHAR_ID,
    UNIT_SEQ_NUM
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MEDCLOTDAT : EDC Lot Data Table */
CREATE TABLE MEDCLOTDAT
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    COL_SEQ                     NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Transaction Time - Backdate 가능 */
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Delete Info. */
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Factory */
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Measurement Resource */
    MEAS_RES_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Processed Flow, Oper, Resource */
    PROC_FLOW                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PROC_OPER                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    PROC_RES_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Added by LAVERWON */
    RECIPE_ID                   VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RECIPE_VERSION              NUMBER(3)        DEFAULT(0)      NOT NULL,
    /* Collection Set, Version */
    COL_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    COL_SET_VERSION             NUMBER(3)        DEFAULT(0)      NOT NULL,
    /* Character ID */
    CHAR_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    CHAR_ID                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Unit ID */
    UNIT_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    UNIT_ID                     VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* Value Sequence Number */
    VALUE_SEQ_NUM               NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* A : ASCII   N : NUMBER */
    VALUE_TYPE                  CHAR(1)          DEFAULT('N')    NOT NULL,
    VALUE_COUNT                 NUMBER(2)        DEFAULT(0)      NOT NULL,
    /* Value 1 ~ 25 */
    VALUE_1                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_2                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_3                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_4                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_5                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_6                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_7                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_8                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_9                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_10                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_11                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_12                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_13                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_14                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_15                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_16                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_17                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_18                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_19                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_20                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_21                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_22                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_23                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_24                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_25                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* P, C, ZBAR, DELTA-S CHART - 20080130 */
    SAMPLE_COUNT                NUMBER(6)        DEFAULT(0)      NOT NULL,
    NOMINAL                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    PROCESS_SIGMA               VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Spec Out Mask - S : Spec Limit Out, W : Warning Limit Out */
    /* "1" - USL OUT, "2" - UWL OUT, "3" - LWL Out, "4" - LSL Out */
    SPEC_OUT_MASK               VARCHAR2(25)   DEFAULT(' ')    NOT NULL,
    /* Create Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Update Info. */
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Delete Info. */
    DELETE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DELETE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MEDCLOTDAT
ADD CONSTRAINT MEDCLOTDAT_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    COL_SEQ,
    COL_SET_ID,             /* LAVERWON - 2008.02.19 추가 */
    CHAR_SEQ_NUM,
    UNIT_SEQ_NUM,
    VALUE_SEQ_NUM
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MEDCRESDAT : EDC Resource Data Table */
CREATE TABLE MEDCRESDAT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    COL_SEQ                     NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Event ID */
    EVENT_ID                    VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /* Transaction Time - Backdated 가능 */
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    RECIPE_ID                   VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RECIPE_VERSION              NUMBER(3 )       DEFAULT(0)      NOT NULL,
    /* Delete Info. */
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Collection Set, Version */
    COL_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    COL_SET_VERSION             NUMBER(3)        DEFAULT(0)      NOT NULL,
    /* Character ID */
    CHAR_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    CHAR_ID                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Unit ID */
    UNIT_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    UNIT_ID                     VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* Value Sequence Number */
    VALUE_SEQ_NUM               NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* A : ASCII   N : NUMBER */
    VALUE_TYPE                  CHAR(1)          DEFAULT('N')    NOT NULL,
    VALUE_COUNT                 NUMBER(2)        DEFAULT(0)      NOT NULL,
    /* Value 1 ~ 25 */
    VALUE_1                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_2                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_3                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_4                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_5                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_6                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_7                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_8                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_9                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_10                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_11                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_12                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_13                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_14                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_15                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_16                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_17                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_18                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_19                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_20                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_21                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_22                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_23                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_24                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    VALUE_25                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* P, C, ZBAR, DELTA-S CHART - 20080130 */
    SAMPLE_COUNT                NUMBER(6)        DEFAULT(0)      NOT NULL,
    NOMINAL                     VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    PROCESS_SIGMA               VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Spec Out Mask - S : Spec Limit Out, W : Warning Limit Out */
    /* "1" - USL OUT, "2" - UWL OUT, "3" - LWL Out, "4" - LSL Out */
    SPEC_OUT_MASK               VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Create Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Update Info. */
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Delete Info. */
    DELETE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DELETE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MEDCRESDAT
ADD CONSTRAINT MEDCRESDAT_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    SUBRES_ID,
    HIST_SEQ,
    CHAR_SEQ_NUM,
    UNIT_SEQ_NUM,
    VALUE_SEQ_NUM
) USING INDEX TABLESPACE HISTORY_IDX_TS;


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
    MIN_UNIT_COUNT              NUMBER(3)        DEFAULT(0)      NOT NULL,
    MIN_VALUE_COUNT             NUMBER(4)        DEFAULT(0)      NOT NULL,
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

/* Add By JU.Heo 2012.12.04 */
/* MEDCPRTDEF : Collection Set 별 Value Prompt를 지정하기 위한 테이블*/
CREATE TABLE MEDCPRTDEF
(
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    COL_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    COL_SET_VERSION             NUMBER(3)        DEFAULT (0)     NOT NULL,
    DEFAULT_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    PRT_1                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_2                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_3                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_4                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_5                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_6                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_7                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_8                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_9                       VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_10                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_11                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_12                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_13                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_14                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_15                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_16                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_17                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_18                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_19                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_20                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_21                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_22                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_23                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_24                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_25                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_26                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_27                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_28                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_29                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_30                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_31                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_32                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_33                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_34                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_35                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_36                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_37                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_38                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_39                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_40                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_41                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_42                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_43                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_44                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_45                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_46                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_47                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_48                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_49                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_50                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_51                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_52                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_53                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_54                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_55                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_56                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_57                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_58                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_59                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_60                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_61                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_62                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_63                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_64                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_65                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_66                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_67                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_68                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_69                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_70                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_71                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_72                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_73                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_74                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_75                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_76                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_77                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_78                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_79                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_80                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_81                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_82                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_83                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_84                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_85                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_86                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_87                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_88                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_89                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_90                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_91                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_92                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_93                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_94                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_95                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_96                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_97                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_98                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_99                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PRT_100                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MEDCPRTDEF
ADD CONSTRAINT MEDCPRTDEF_PK PRIMARY KEY
(
    FACTORY,
    COL_SET_ID,
    COL_SET_VERSION
) USING INDEX TABLESPACE MESPLUS_IDX_TS;
/* End Add */



























/*==== BOM(Bill Of Materials Module) ====*/
/* MBOMSETDEF : BOM Set Definition Table */
CREATE TABLE MBOMSETDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BOM_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    BOM_SET_DESC                VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Group 1 ~ 10 */
    BOM_GRP_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BOM_GRP_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BOM_GRP_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BOM_GRP_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BOM_GRP_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BOM_GRP_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BOM_GRP_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BOM_GRP_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BOM_GRP_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BOM_GRP_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* CMF 1 ~ 20 */
    BOM_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BOM_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BOM_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BOM_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BOM_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BOM_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BOM_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BOM_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BOM_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BOM_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Material or Order Flag - 'M':Material, 'O':Order */
    MAT_OR_ORD_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Approval Info. */
    APPROVAL_REQUIRE_FLAG       CHAR(1)          DEFAULT(' ')    NOT NULL,
    APPROVAL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Delete Info. */
    DELETE_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    DELETE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DELETE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBOMSETDEF
ADD CONSTRAINT MBOMSETDEF_PK PRIMARY KEY
(
    FACTORY,
    BOM_SET_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MBOMSETVER : BOM Set Version Definition Table */
CREATE TABLE MBOMSETVER
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BOM_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    BOM_SET_VERSION             NUMBER(3)        DEFAULT(0)      NOT NULL,
    /* Apply Start/End Time */
    APPLY_START_TIME            VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    APPLY_END_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Approval Info. */
    APPROVAL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    APPROVAL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    APPROVAL_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Release Info.*/
    RELEASE_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    RELEASE_USER_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RELEASE_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBOMSETVER
ADD CONSTRAINT MBOMSETVER_PK PRIMARY KEY
(
    FACTORY,
    BOM_SET_ID,
    BOM_SET_VERSION
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MBOMSETMAT : Set Version-Material Attach Table(MO Base) */
CREATE TABLE MBOMSETMAT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BOM_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    BOM_SET_VERSION             NUMBER(3)        DEFAULT(0)      NOT NULL,
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Part Group */
    PART_GRP                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Alternate Material Flag - _:Normal, 'Y':Alternate */
    ALT_MAT_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Material Qty */
    MAT_QTY                     NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Lot의 Operation 진행 단위 */
    MAT_UNIT                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Optional Input Flag - _:Essential, 'Y':Optional */
    OPT_INPUT_FLAG              CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Auto Input Flag - _:Normal, 'Y':Auto Inputed */
    AUTO_INPUT_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Serial Input Flag */
    SERIAL_INPUT_FLAG           CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Serial Type - L:Lot ID, M:Material, S:Sub Component */
    SERIAL_TYPE                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Check Serial Flag - _:Not Check, 'Y':Check */
    CHK_SERIAL_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Flow */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Operation */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Inventory Operation */
    INV_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* CMF 1 ~ 10 */
    PART_CMF_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PART_CMF_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PART_CMF_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PART_CMF_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PART_CMF_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PART_CMF_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PART_CMF_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PART_CMF_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PART_CMF_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PART_CMF_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBOMSETMAT
ADD CONSTRAINT MBOMSETMAT_PK PRIMARY KEY
(
    FACTORY,
    BOM_SET_ID,
    BOM_SET_VERSION,
    SEQ_NUM
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MBOMSETMTL : Set Version-Material List Attach Table(MFO Base) */
/* 현재 사용하지 않음 */
CREATE TABLE MBOMSETMTL
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BOM_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    BOM_SET_VERSION             NUMBER(3)        DEFAULT(0)      NOT NULL,
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Part Group */
    PART_GRP                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Alternate Material Flag - _:Normal, 'Y':Alternate */
    ALT_MAT_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Material Qty */
    MAT_QTY                     NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Lot의 Operation 진행 단위 */
    MAT_UNIT                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Optional Input Flag - _:Essential, 'Y':Optional */
    OPT_INPUT_FLAG              CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Auto Input Flag - _:Normal, 'Y':Auto Inputed */
    AUTO_INPUT_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Serial Input Flag */
    SERIAL_INPUT_FLAG           CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Serial Type - L:Lot ID, M:Material, S:Sub Component */
    SERIAL_TYPE                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Check Serial Flag - _:Not Check, 'Y':Check */
    CHK_SERIAL_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Flow */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Operation */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Inventory Operation */
    INV_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* CMF 1 ~ 10 */
    PART_CMF_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PART_CMF_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PART_CMF_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PART_CMF_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PART_CMF_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PART_CMF_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PART_CMF_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PART_CMF_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PART_CMF_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PART_CMF_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBOMSETMTL
ADD CONSTRAINT MBOMSETMTL_PK PRIMARY KEY
(
    FACTORY,
    BOM_SET_ID,
    BOM_SET_VERSION,
    SEQ_NUM
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MBOMCMPSTS : Component Status Table */
/* 현재 사용하지 않음 */
CREATE TABLE MBOMCMPSTS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CMP_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Component Type */
    CMP_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Material Qty */
    MAT_QTY                     NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Lot의 Operation 진행 단위 */
    MAT_UNIT                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /** Assy Info. **/
    /* Lot ID */
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Assemble Time */
    ASSY_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /** BOM Info. **/
    BOM_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    BOM_SET_VERSION             NUMBER(3)        DEFAULT(0)      NOT NULL,
    /* CMF 1 ~ 10 */
    CMP_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMP_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMP_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMP_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMP_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMP_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMP_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMP_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMP_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMP_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBOMCMPSTS
ADD CONSTRAINT MBOMCMPSTS_PK PRIMARY KEY
(
    FACTORY,
    CMP_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MBOMCMPSUB : Component Sub Assembly Status Table */
/* 현재 사용하지 않음 */
CREATE TABLE MBOMCMPSUB
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CMP_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /** BOM Info. **/
    BOM_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    BOM_SET_VERSION             NUMBER(3)        DEFAULT(0)      NOT NULL,
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Part Group */
    PART_GRP                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Material Qty */
    MAT_QTY                     NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Lot의 Operation 진행 단위 */
    MAT_UNIT                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Serial ID */
    SERIAL_ID                   VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Serial Type - L:Lot ID, M:Material, S:Sub Component */
    SERIAL_TYPE                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBOMCMPSUB
ADD CONSTRAINT MBOMCMPSUB_PK PRIMARY KEY
(
    FACTORY,
    CMP_ID,
    BOM_SET_ID,
    BOM_SET_VERSION,
    SEQ_NUM
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MBOMLOTASS : Lot Assembly Status Table */
CREATE TABLE MBOMLOTASS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /** BOM Info. **/
    BOM_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    BOM_SET_VERSION             NUMBER(3)        DEFAULT(0)      NOT NULL,
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Serial이 여러개인 경우 Base는 1 */
    SERIAL_SEQ_NUM              NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Part Group */
    PART_GRP                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Alternate Material Flag - _:Normal, 'Y':Alternate */
    ALT_MAT_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Material Qty */
    MAT_QTY                     NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Lot의 Operation 진행 단위 */
    MAT_UNIT                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Material Attach Qty */
    MAT_ATT_QTY                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Serial Input Flag */
    SERIAL_ID                   VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Serial Type - L:Lot ID, M:Material, S:Sub Component */
    SERIAL_TYPE                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Flow */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Operation */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MBOMLOTASS
ADD CONSTRAINT MBOMLOTASS_PK PRIMARY KEY
(
    FACTORY,
    LOT_ID,
    BOM_SET_ID,
    BOM_SET_VERSION,
    SEQ_NUM,
    SERIAL_SEQ_NUM
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MBOMLOTASH : Lot Assembly History(Assemble/Disassemble/Replace) Table */
CREATE TABLE MBOMLOTASH
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* BOM History Sequence */
    BOM_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    /** BOM Info. **/
    BOM_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    BOM_SET_VERSION             NUMBER(3)        DEFAULT(0)      NOT NULL,
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Serial이 여러개인 경우 Base는 1 */
    SERIAL_SEQ_NUM              NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* BOM History Type - 'A':Assemble, 'D':Disassemble, 'R':Replace */
    BOM_HIST_TYPE               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Part Group */
    PART_GRP                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Alternate Material Flag - _:Normal, 'Y':Alternate */
    ALT_MAT_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Material Qty */
    MAT_QTY                     NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Lot의 Operation 진행 단위 */
    MAT_UNIT                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Material Attach Qty */
    MAT_ATT_QTY                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Serial Input Flag */
    SERIAL_ID                   VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Serial Type - L:Lot ID, M:Material, S:Sub Component */
    SERIAL_TYPE                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Flow */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Operation */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Material Attach Qty */
    TO_MAT_ATT_QTY              NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Serial Input Flag */
    TO_SERIAL_ID                VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Delete Info. */
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    HIST_DEL_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MBOMLOTASH
ADD CONSTRAINT MBOMLOTASH_PK PRIMARY KEY
(
    FACTORY,
    LOT_ID,
    BOM_HIST_SEQ,
    BOM_SET_ID,
    BOM_SET_VERSION,
    SEQ_NUM,
    SERIAL_SEQ_NUM
) USING INDEX TABLESPACE HISTORY_IDX_TS;






























/*==== INV(Inventory Module) ====*/
/* MINVMATSTS : Material Inventory Status Table */
CREATE TABLE MINVMATSTS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Oper */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Quantity 1 ~ 3 */
    QTY_1                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Allocated Quantity */
    ALLOC_QTY                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /** Last Tran Info. **/
    /* History가 지워진 경우 마지막 Active History Seq Number 필요 */
    LAST_TRAN_CODE              VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    LAST_TRAN_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Last History Sequence Number(Only Increase) */
    LAST_HIST_SEQ               NUMBER(10)       DEFAULT(0)      NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MINVMATSTS
ADD CONSTRAINT MINVMATSTS_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    OPER
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MINVMATHIS : Material Inventory History Table */
CREATE TABLE MINVMATHIS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Oper */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* History Sequence */
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Transaction Time - Backdated 가능 */
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* System Time */
    SYS_TRAN_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Transaction Code */
    TRAN_CODE                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /* Quantity 1 ~ 3 */
    QTY_1                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Changed Quantity 1 ~ 3 */
    CHG_QTY_1                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CHG_QTY_2                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CHG_QTY_3                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* From To Flag - ' ':None, 'F':From, 'T':To */
    FROM_TO_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    FROM_TO_MAT_ID              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FROM_TO_MAT_VER             NUMBER(6)        DEFAULT(0)      NOT NULL,
    FROM_TO_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FROM_TO_QTY_1               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_QTY_2               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_QTY_3               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_HIST_SEQ            NUMBER(10)       DEFAULT(0)      NOT NULL,
    FROM_TO_LOT_ID              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Scrap Code - GCM Table 로 관리 */
    SCRAP_CODE                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Ship Info. */
    SHIP_CODE                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SHIP_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /** Old Inventory Info. **/
    /* Quantity 1 ~ 3 */
    OLD_QTY_1                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OLD_QTY_2                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OLD_QTY_3                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
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
    /* Transaction User ID/Comment */
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* Related Transaction and History Sequence */
    REL_TRAN_CODE               VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    REL_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Delete Info. */
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    HIST_DEL_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_COMMENT            VARCHAR2(400)    DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MINVMATHIS
ADD CONSTRAINT MINVMATHIS_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    OPER,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

/* MINVSRLSTS : Material Inventory Serial Status Table */
CREATE TABLE MINVSRLSTS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Oper */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* History Sequence */
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Serial Sequence */
    SERIAL_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Serial Number */
    SERIAL_ID                   VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Serial Type - L:Lot ID, M:Material, S:Sub Component */
    SERIAL_TYPE                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Material Qty */
    MAT_QTY                     NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Lot의 Operation 진행 단위 */
    MAT_UNIT                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Delete History Sequence */
    DEL_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MINVSRLSTS
ADD CONSTRAINT MINVSRLSTS_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    OPER,
    HIST_SEQ,
    SERIAL_SEQ
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

























/*==== POP(Point of Product Module) ====*/
/* MPOPLBLDEF : Label Definition Table */
CREATE TABLE MPOPLBLDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LABEL_ID                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LABEL_DESC                  VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Page Size */
    PAGE_WIDTH                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    PAGE_HEIGHT                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Label Size */
    LABEL_WIDTH                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    LABEL_HEIGHT                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Margin */
    MARGIN_LEFT                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    MARGIN_TOP                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Label Type */
    LABEL_TYPE                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Origin */
    ORIGIN_X                    NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    ORIGIN_Y                    NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    PRINTER_TYPE                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RESOLUTION                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    PRINT_SPEED                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    INVERT                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    REVERSE                     CHAR(1)          DEFAULT(' ')    NOT NULL,
    DARKNESS                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    PRINT_QTY                   NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* CMF 1~20 */
    LABEL_CMF_1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LABEL_CMF_2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LABEL_CMF_3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LABEL_CMF_4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LABEL_CMF_5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LABEL_CMF_6                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LABEL_CMF_7                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LABEL_CMF_8                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LABEL_CMF_9                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LABEL_CMF_10                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Zebra Command of Label Size */
    START_CMD                   VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    /* Zebra Command of last command */
    END_CMD                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MPOPLBLDEF
ADD CONSTRAINT MPOPLBLDEF_PK PRIMARY KEY
(
    FACTORY,
    LABEL_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MPOPLBLIMG : Label Image Definition Table */
CREATE TABLE MPOPLBLIMG
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    IMAGE_ID                    VARCHAR2(8)      DEFAULT(' ')    NOT NULL,
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    EXTENSION                   VARCHAR2(3)      DEFAULT(' ')    NOT NULL,
    IMAGE_DESC                  VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Image Size */
    TOTAL_BYTE                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    BYTE_PER_ROW                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    ROW_COUNT                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    IMAGE_DATA                  VARCHAR2(255)    DEFAULT(0.0)    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MPOPLBLIMG
ADD CONSTRAINT MPOPLBLIMG_PK PRIMARY KEY
(
    FACTORY,
    IMAGE_ID,
    SEQ_NUM
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MPOPLBLDGN : Label Degine Table */
CREATE TABLE MPOPLBLDGN
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LABEL_ID                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    TYPE                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Field Position Relative to Home Position */
    POSITION_X                  NUMBER(6)        DEFAULT(0)      NOT NULL,
    POSITION_Y                  NUMBER(6)        DEFAULT(0)      NOT NULL,
    ROTATE                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    FEED_FLAG                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    REVERSE_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    PRINT_FLAG                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    VARIABLE_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    DATA                        VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* Text or Barcode Font */
    FONT                        CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Text Width or Bar Width or Image Vertical Rate or Graphic Width */
    WIDTH                       NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Text Height or Bar Height or Image Hoizontal Rate or Graphic Height */
    HEIGHT                      NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Graphic thick */
    THICK                       NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Ratio between narrow bar and wide bar */
    BAR_RATE                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Barcode 위에 문자 인쇄 여부 */
    ABOVE_FLAG                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Barcode 아래에 문자 인쇄 여부 */
    BELOW_FLAG                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Check Digit 출력 여부 */
    CHECK_DIGIT                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Background Image Flag */
    BACKGROUND_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Error Control Code(ECC)  (2D) */
    ECC_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
     /* Column Count(2D) */
    COLUMN_COUNT                NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Row Count(2D) */
    ROW_COUNT                   NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Truncate Flag(PDF417) */
    TRUN_FLAG                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Model */
    MODEL                       CHAR(1)          DEFAULT(' ')    NOT NULL,
     /* Magnification Factor */
    MAGNI_FACTOR                NUMERIC(6)       DEFAULT(0)      NOT NULL,
     /* Zebra Command for current record */
    LABEL_CMD                   VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
     /* When data is variable, variable value is result of SQL */
    ARG_SQL                     VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MPOPLBLDGN
ADD CONSTRAINT MPOPLBLDGN_PK PRIMARY KEY
(
    FACTORY,
    LABEL_ID,
    SEQ_NUM
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MPOPMATLBL : Material-Label Relationship Table */
CREATE TABLE MPOPMATLBL
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    LABEL_ID                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MPOPMATLBL
ADD CONSTRAINT MPOPMATLBL_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    LABEL_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MPOPLOTPRH : Label Print History of Lot Table */
CREATE TABLE MPOPLOTPRH
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    WORK_YEAR                   NUMBER(4)        DEFAULT(0)      NOT NULL,
    WORK_DAYS                   NUMBER(4)        DEFAULT(0)      NOT NULL,
    WORK_DATE                   CHAR(8)          DEFAULT(0)      NOT NULL,
    QTY                         NUMBER(6)        DEFAULT(0)      NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    LABEL_ID                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    ORDER_ID                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MPOPLOTPRH
ADD CONSTRAINT MPOPLOTPRH_PK PRIMARY KEY
(
    FACTORY,
    LOT_ID,
    SEQ_NUM
) USING INDEX TABLESPACE HISTORY_IDX_TS;

/* Create Table : Label Design Extension Table */
CREATE TABLE MPOPLBLDEX
(
    FACTORY                             VARCHAR2(10)        DEFAULT(' ')        NOT NULL,
    LABEL_ID                            VARCHAR2(25)        DEFAULT(' ')        NOT NULL,
    SEQ_NUM                             NUMBER(6)           DEFAULT(0)          NOT NULL,
    DGN_CMF_1                           VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_2                           VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_3                           VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_4                           VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_5                           VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_6                           VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_7                           VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_8                           VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_9                           VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_10                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_11                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_12                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_13                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_14                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_15                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_16                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_17                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_18                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_19                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_20                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_21                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_22                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_23                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_24                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_25                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_26                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_27                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_28                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_29                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL,
    DGN_CMF_30                          VARCHAR2(50)        DEFAULT(' ')        NOT NULL
) TABLESPACE MESPLUS_DATA_TS

/* Create Primary Key of MPOPLBLDEX */
ALTER TABLE MPOPLBLDEX
ADD CONSTRAINT MPOPLBLDEX_PK PRIMARY KEY
(
    FACTORY,
    LABEL_ID,
    SEQ_NUM
) USING INDEX TABLESPACE MESPLUS_IDX_TS



























/*==== QCM(Quality Control Module) ====*/
/* MQCMSETDEF : Inspection Set Definition Table */
CREATE TABLE MQCMSETDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    INSP_SET_ID                 VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    INSP_SET_DESC               VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    ACTIVE_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    INSP_TYPE                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    INSP_METHOD                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SAMPLE_PROC                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_CHECK_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    MAX_QTY                     NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    SET_GRP_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SET_GRP_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SET_GRP_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SET_GRP_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SET_GRP_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SET_GRP_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SET_GRP_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SET_GRP_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SET_GRP_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SET_GRP_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SET_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SET_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SET_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SET_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SET_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SET_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SET_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SET_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SET_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SET_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    APPROVAL_REQUIRE_FLAG       CHAR(1)          DEFAULT(' ')    NOT NULL,
    APPROVAL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MQCMSETDEF
ADD CONSTRAINT MQCMSETDEF_PK PRIMARY KEY
(
    FACTORY,
    INSP_SET_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MQCMSETITM : Inspection Set - Inspection Item Attach Table */
CREATE TABLE MQCMSETITM
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    INSP_SET_ID                 VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    INSP_SET_VERSION            NUMBER(6)        DEFAULT(0)      NOT NULL,
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    INSP_ITEM                   VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    INSP_METHOD                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SAMPLE_PROC                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    ITEM_CMF_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_CMF_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_CMF_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_CMF_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_CMF_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_CMF_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_CMF_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_CMF_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_CMF_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_CMF_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MQCMSETITM
ADD CONSTRAINT MQCMSETITM_PK PRIMARY KEY
(
    FACTORY,
    INSP_SET_ID,
    INSP_SET_VERSION,
    SEQ_NUM
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MQCMITMDEF : Inspection Item Definition Table */
CREATE TABLE MQCMITMDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    INSP_ITEM                   VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    INSP_ITEM_DESC              VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    INSP_METHOD                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    ACTIVE_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    VALUE_FLAG                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    SAMPLE_PROC                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DEFECT_GROUP                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    ITEM_CMF_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_CMF_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_CMF_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_CMF_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_CMF_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_CMF_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_CMF_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_CMF_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_CMF_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_CMF_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MQCMITMDEF
ADD CONSTRAINT MQCMITMDEF_PK PRIMARY KEY
(
    FACTORY,
    INSP_ITEM
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MQCMSETVER : Inspection Item Definition Table */
CREATE TABLE MQCMSETVER
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    INSP_SET_ID                 VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    INSP_SET_VERSION            NUMBER(6)        DEFAULT(0)      NOT NULL,
    APPLY_START_TIME            VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    APPLY_END_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    APPROVAL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    APPROVAL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    APPROVAL_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    RELEASE_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    RELEASE_USER_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RELEASE_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MQCMSETVER
ADD CONSTRAINT MQCMSETVER_PK PRIMARY KEY
(
    FACTORY,
    INSP_SET_ID,
    INSP_SET_VERSION
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MQCMSMPDEF : Sampling Procedure Definition Table */
CREATE TABLE MQCMSMPDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SAMPLE_PROC                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SAMPLE_PROC_DESC            VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    SAMPLE_PROC_TYPE            VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SAMPLE_RATE                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    SAMPLE_QTY                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    SAMPLE_UNIT                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SAMPLE_SCHEME               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DETERMINE_VALUE             NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    DETERMINE_UNIT              VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHECK_DETERMINE_FLAG        VARCHAR2(2)      DEFAULT(' ')    NOT NULL,
    PROC_CMF_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PROC_CMF_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PROC_CMF_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PROC_CMF_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PROC_CMF_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PROC_CMF_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PROC_CMF_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PROC_CMF_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PROC_CMF_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PROC_CMF_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MQCMSMPDEF
ADD CONSTRAINT MQCMSMPDEF_PK PRIMARY KEY
(
    FACTORY,
    SAMPLE_PROC
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MQCMMATDEF : Inspection Material Definition Table */
CREATE TABLE MQCMMATDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    TOTAL_INSP                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    AUTO_FINAL                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    SKIP_RESULT_RECORD          CHAR(1)          DEFAULT(' ')    NOT NULL,
    ADD_SAMPLE                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    MAX_QTY                     NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    IQC_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    IQC_INSP_SET_ID             VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    PQC_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    PQC_INSP_SET_ID             VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    OQC_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    OQC_INSP_SET_ID             VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RMA_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    RMA_INSP_SET_ID             VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MQCMMATDEF
ADD CONSTRAINT MQCMMATDEF_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MQCMBATSTS : QC Batch Status Table */
CREATE TABLE MQCMBATSTS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BATCH_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BATCH_DEL_FLAG              CHAR(1)          DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    ORDER_ID                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    INSP_SET_ID                 VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    INSP_SET_VERSION            NUMBER(6)        DEFAULT(0)      NOT NULL,
    INSP_TYPE                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    INSP_METHOD                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TOT_INSP                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    SKIP_RESULT_RECORD          CHAR(1)          DEFAULT(' ')    NOT NULL,
    AUTO_FINAL                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    ITEM_COUNT                  NUMBER(10)       DEFAULT(0)      NOT NULL,
    TOT_QTY_1                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    TOT_QTY_2                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    TOT_QTY_3                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    INSP_STEP                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BATCH_STATUS                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    PO                          VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PO_ITEM                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    VENDOR                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CUSOTMER                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RET_DLV_ID                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FINAL_DECISION              VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BAT_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BAT_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BAT_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BAT_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BAT_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BAT_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BAT_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BAT_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BAT_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BAT_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LAST_HIST_SEQ               NUMBER(6)        DEFAULT(0)      NOT NULL,
    ITEM_RESULT_SEQ             NUMBER(6)        DEFAULT(0)      NOT NULL,
    INSP_SEQ                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    LAST_TRAN_CODE              VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LAST_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MQCMBATSTS
ADD CONSTRAINT MQCMBATSTS_PK PRIMARY KEY
(
    FACTORY,
    BATCH_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MQCMITMSTS : QC Batch Item Status Table */
CREATE TABLE MQCMITMSTS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BATCH_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_ID                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    INSP_METHOD                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    ORDER_ID                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    TOT_QTY_1                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    TOT_QTY_2                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    TOT_QTY_3                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    INSP_STEP                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    ITEM_STATUS                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    ITM_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITM_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITM_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITM_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITM_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITM_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITM_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITM_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITM_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITM_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LAST_HIST_SEQ               NUMBER(6)        DEFAULT(0)      NOT NULL,
    ITEM_RESULT_SEQ             NUMBER(6)        DEFAULT(0)      NOT NULL,
    INSP_SEQ                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    LAST_TRAN_CODE              VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LAST_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MQCMITMSTS
ADD CONSTRAINT MQCMITMSTS_PK PRIMARY KEY
(
    FACTORY,
    BATCH_ID,
    ITEM_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MQCMBATHIS : QC Batch History Table */
CREATE TABLE MQCMBATHIS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BATCH_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    INSP_METHOD                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    ORDER_ID                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    INSP_SET_ID                 VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    INSP_SET_VERSION            NUMBER(6)        DEFAULT(0)      NOT NULL,
    ITEM_COUNT                  NUMBER(10)       DEFAULT(0)      NOT NULL,
    TOT_QTY_1                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    TOT_QTY_2                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    TOT_QTY_3                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    INSP_STEP                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TRAN_CODE                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FINAL_DECISION              VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SPLIT_FROM_BATCH            VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MERGE_TO_BATCH              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ITEM_RESULT_SEQ             NUMBER(6)        DEFAULT(0)      NOT NULL,
    INSP_SEQ                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    BAT_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BAT_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BAT_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BAT_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BAT_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BAT_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BAT_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BAT_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BAT_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BAT_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HIS_COMMENT                 VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MQCMBATHIS
ADD CONSTRAINT MQCMBATHIS_PK PRIMARY KEY
(
    FACTORY,
    BATCH_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;



/* MQCMBATISP : QC Batch Inspection Result Table */
CREATE TABLE MQCMBATISP
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BATCH_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BATCH_HIST_SEQ              NUMBER(6)        DEFAULT(0)      NOT NULL,
    INSP_ITEM                   VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    INSP_SET_ID                 VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    INSP_SET_VERSION            NUMBER(6)        DEFAULT(0)      NOT NULL,
    INSP_SEQ                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    INSP_METHOD                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SAMPLE_QTY                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    TEST_QTY                    NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    DEFECT_QTY                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    RESULT_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    ISP_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ISP_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ISP_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ISP_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ISP_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ISP_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ISP_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ISP_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ISP_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ISP_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ISP_COMMENT                 VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MQCMBATISP
ADD CONSTRAINT MQCMBATISP_PK PRIMARY KEY
(
    FACTORY,
    BATCH_ID,
    BATCH_HIST_SEQ,
    INSP_ITEM
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MQCMITMISP : QC Batch Item Inspection Result Table */
CREATE TABLE MQCMITMISP
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BATCH_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BATCH_HIST_SEQ              NUMBER(6)        DEFAULT(0)      NOT NULL,
    ITEM_ID                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    INSP_ITEM                   VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
        HIST_DEL_FLAG                         CHAR(1)                    DEFAULT('N')    NOT NULL,
        DEL_RESULT_SEQ              NUMBER(6)        DEFAULT(0)      NOT NULL,
    INSP_SET_ID                 VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    INSP_SET_VERSION            NUMBER(6)        DEFAULT(0)      NOT NULL,
    INSP_SEQ                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    INSP_METHOD                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    SAMPLE_QTY                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    TEST_QTY                    NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    DEFECT_QTY                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    RESULT_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    ISP_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ISP_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ISP_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ISP_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ISP_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ISP_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ISP_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ISP_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ISP_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ISP_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ISP_COMMENT                 VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MQCMITMISP
ADD CONSTRAINT MQCMITMISP_PK PRIMARY KEY
(
    FACTORY,
    BATCH_ID,
    BATCH_HIST_SEQ,
    ITEM_ID,
        INSP_ITEM
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MQCMITMISP_IDX_1 ON MQCMITMISP
(
    FACTORY,
    BATCH_ID,
      HIST_DEL_FLAG,
    ITEM_ID,
    INSP_SET_ID,
    INSP_SET_VERSION,
    INSP_ITEM,
    INSP_SEQ
) TABLESPACE HISTORY_IDX_TS;


/* MQCMBATDFT : QC Batch Defect Table */
CREATE TABLE MQCMBATDFT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BATCH_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BATCH_HIST_SEQ              NUMBER(6)        DEFAULT(0)      NOT NULL,
    INSP_ITEM                   VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    DEFECT_CODE                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    INSP_SET_ID                 VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    INSP_SET_VERSION            NUMBER(6)        DEFAULT(0)      NOT NULL,
    INSP_METHOD                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    DEFECT_GROUP                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    QTY_1                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    INSP_SEQ                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MQCMBATDFT
ADD CONSTRAINT MQCMBATDFT_PK PRIMARY KEY
(
    FACTORY,
    BATCH_ID,
    BATCH_HIST_SEQ,
    INSP_ITEM,
    DEFECT_CODE
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MQCMITMDFT : QC Batch Item Defect Table */
CREATE TABLE MQCMITMDFT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BATCH_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BATCH_HIST_SEQ              NUMBER(6)        DEFAULT(0)      NOT NULL,
    ITEM_ID                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    INSP_ITEM                   VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    DEFECT_CODE                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_FLAG               CHAR(1)          DEFAULT('N')    NOT NULL,
    DEL_RESULT_SEQ              NUMBER(6)        DEFAULT(0)      NOT NULL,
    INSP_SET_ID                 VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    INSP_SET_VERSION            NUMBER(6)        DEFAULT(0)      NOT NULL,
    INSP_METHOD                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    DEFECT_GROUP                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    QTY_1                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    INSP_SEQ                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MQCMITMDFT
ADD CONSTRAINT MQCMITMDFT_PK PRIMARY KEY
(
    FACTORY,
    BATCH_ID,
    BATCH_HIST_SEQ,
    ITEM_ID,
    INSP_ITEM,
        DEFECT_CODE
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MQCMITMDFT_IDX_1 ON MQCMITMDFT
(
    FACTORY,
    BATCH_ID,
      HIST_DEL_FLAG,
    ITEM_ID,
    INSP_SET_ID,
    INSP_SET_VERSION,
    INSP_ITEM
) TABLESPACE HISTORY_IDX_TS;





























/*==== RAS(Resource Allocation and Status Module) ====*/
/* MRASRESDEF : Resource Definition Table */
CREATE TABLE MRASRESDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_DESC                    VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Resource Type */
    /* EQUIPMENT, TESTER, TOOL */
    RES_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Resource Group */
    RES_GRP_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_GRP_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_GRP_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_GRP_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_GRP_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_GRP_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_GRP_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_GRP_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_GRP_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_GRP_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Use Factory Level Status Prompt Use Flag */
    USE_FAC_PRT_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Resource Status Prompt */
    RES_STS_PRT_1               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_PRT_2               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_PRT_3               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_PRT_4               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_PRT_5               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_PRT_6               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_PRT_7               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_PRT_8               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_PRT_9               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_PRT_10              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* RES_CMF_1 ~ 10 */
    RES_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_CMF_11                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_CMF_12                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_CMF_13                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_CMF_14                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_CMF_15                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_CMF_16                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_CMF_17                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_CMF_18                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_CMF_19                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_CMF_20                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* 이공정이 속해있는 BAY 및 AREA */
    AREA_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUB_AREA_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Resource Location */
    RES_LOCATION                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Process Rule - _:Normal, S:Serial, B:Batch */
    /* Normal 장비 : Start-End-Start-End... */
    /* Serial 장비 : Start-Start-End-End... */
    /* Batch 장비 : Batch Start-Batch End... */
    PROC_RULE                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* 동시에 진행 가능한 최대 LOT 수, BATCH 장비는 BATCH 수 */
    MAX_PROC_COUNT              NUMBER(3)        DEFAULT(0)      NOT NULL,
    /* 허용 BATCH 갯수 : "X_X" : 1,3개 허용 */
    BATCH_COND_1                VARCHAR2(12)     DEFAULT('_')    NOT NULL,
    /* BATCH가 만들어 지는 조건 DEVICE MATCH,FLOW MATCH */
    BATCH_COND_2                VARCHAR2(12)     DEFAULT('_')    NOT NULL,
    /* NO WIP Event 발생 여부 */
    /* PM Schedule Enalbe Flag */
    PM_SCH_ENABLE_FLAG          CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Standard Time 측정 방법 : _:Lot, Y:Unit */
    UNIT_BASE_ST_FLAG           CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Security Check Flag - _:No, Y:Security Control */
    SEC_CHK_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* 자동 알람 수집 여부 */
    GATHER_ALARM_FLAG           CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Delete Info. */
    DELETE_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    DELETE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DELETE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /** Resource Status **/
    /* Resource Availibility - U:Up, D:Down */
    RES_UP_DOWN_FLAG            CHAR(1)          DEFAULT('U')    NOT NULL,
    /* Resource Primary Status - WAIT:Wait, PROC:Process, PM ... */
    RES_PRI_STS                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Resource Status 1 ~ 10 */
    RES_STS_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Lot ID, Carrier ID */
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* 장비 제어 모드 - OL: ON LINE, OR: ON LINE REAL, OF: OFF LINE */
    RES_CTRL_MODE               CHAR(2)          DEFAULT(' ')    NOT NULL,
    /* 장비 진행 모드 - M:MANUAL, S:SEMI AUTO, F: FULL AUTO */
    RES_PROC_MODE               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* 마지막 진행 RECIPE */
    LAST_RECIPE_ID              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* 진행 중인 LOT 수 */
    PROC_COUNT                  NUMBER(3)        DEFAULT(0)      NOT NULL,
    /* Last Start Time, Last End Time */
    LAST_START_TIME             VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LAST_END_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Last Down Time, Last Down Hist Seq */
    LAST_DOWN_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LAST_DOWN_HIST_SEQ          NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Last Event Info. */
    LAST_EVENT_ID               VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    LAST_EVENT_TIME             VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LAST_ACTIVE_HIST_SEQ        NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Last History Sequence Number(Only Increase) */
    LAST_HIST_SEQ               NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Short Description */
    RES_SHORT_DESC              VARCHAR2(50)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASRESDEF
ADD CONSTRAINT MRASRESDEF_PK PRIMARY KEY
(
    FACTORY,
    RES_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRASEVNDEF : Event Definition Table */
CREATE TABLE MRASEVNDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    EVENT_ID                    VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    EVENT_DESC                  VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Event Group */
    EVENT_GRP_1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    EVENT_GRP_2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    EVENT_GRP_3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    EVENT_GRP_4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    EVENT_GRP_5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    EVENT_GRP_6                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    EVENT_GRP_7                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    EVENT_GRP_8                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    EVENT_GRP_9                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    EVENT_GRP_10                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* SYSTEM에서 사용하는 이벤트 ,지울수 없음 */
    SYSTEM_FLAG                 CHAR(1)         DEFAULT(' ')     NOT NULL,
    /* CHECK 방법 '=': ALLOW '!':REJECT 'N'=NOT CHECK '>':크거나   '<' : 같거나 T : UPT Table Check */
    /* UP_DOWN_FLAG */
    CHK_UP_DOWN_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_UP_DOWN                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_UP_DOWN_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_UP_DOWN                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    OVR_UP_DOWN_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Primary Status */
    CHK_PRI_STS_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHK_PRI_STS                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_PRI_STS_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHG_PRI_STS                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OVR_PRI_STS_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    TBL_PRI_STS                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Check Old Status Flag */
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
    /* Check Old Status Value */
    CHK_STS_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_STS_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_STS_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_STS_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_STS_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_STS_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_STS_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_STS_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_STS_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHK_STS_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* 바꿀 방법 'Y' : 다음의 값으로 바꿈 '+' :다음의 값을 더함  */
    /* '-':다음의 값을 뺌 'N':바꾸지 안음  'O' : Override */
    /* Change Status Flag */
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
    /* Change to Status Value */
    CHG_STS_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_STS_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_STS_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_STS_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_STS_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_STS_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_STS_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_STS_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_STS_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_STS_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Validation Table for Status */
    TBL_1                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_2                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_3                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_4                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_5                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_6                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_7                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_8                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_9                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_10                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* EDC Collection Set */
    COL_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    CHART_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHART_FLAG                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Alarm Flag */
    ALARM_FLAG                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    ALARM_MSG_ID                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Security Check Flag */
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASEVNDEF
ADD CONSTRAINT MRASEVNDEF_PK PRIMARY KEY
(
    FACTORY,
    EVENT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRASRESEVN : Resource-Event Attach Table */
CREATE TABLE MRASRESEVN
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    EVENT_ID                    VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    RES_TYPE                    CHAR(1)          DEFAULT('M')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASRESEVN
ADD CONSTRAINT MRASRESEVN_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    EVENT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;



/* 2007.08.28. Aiden. */
/* MRASRSGDEF : Resource Group Definition */
CREATE TABLE MRASRSGDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RESG_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RESG_DESC                   VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASRSGDEF
ADD CONSTRAINT MRASRSGDEF_PK PRIMARY KEY
(
    FACTORY,
    RESG_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRASRSGRES : Resource Group & Resource Relation */
CREATE TABLE MRASRSGRES
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RESG_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASRSGRES
ADD CONSTRAINT MRASRSGRES_PK PRIMARY KEY
(
    FACTORY,
    RESG_ID,
    RES_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRASRESMFO : Resource & MFO Relation */
CREATE TABLE MRASRESMFO
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Resource Group. if relaton level is 'G' */
    RESG_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Relation Level - 'G' : Resource Group, 'R' : Resource */
    /* 'R' level is prior to 'G' */
    REL_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASRESMFO
ADD CONSTRAINT MRASRESMFO_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    OPER,
    RES_ID,
    RESG_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRASRESLAB : Resource-Laber(투입인력) History Table */
CREATE TABLE MRASRESLAB
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Work Position - 작업자 근무 위치 GCM Table로 관리 */
    WORK_POSITION               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Work Date - YYYYMMDD */
    WORK_DATE                   CHAR(8)          DEFAULT(' ')    NOT NULL,
    /* Work Shift - ' '/'1'/'2'/'3'/'4' */
    WORK_SHIFT                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    /** Labor Info. **/
    /* 직접 인원수, 간접 인원수 */
    DIRECT_LABOR_COUNT          NUMBER(3)        DEFAULT(0)      NOT NULL,
    INDIRECT_LABOR_COUNT        NUMBER(3)        DEFAULT(0)      NOT NULL,
    /* 총 투입 시간(단위 : 분) */
    DIRECT_LABOR_MIN            NUMBER(6)        DEFAULT(0)      NOT NULL,
    INDIRECT_LABOR_MIN          NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASRESLAB
ADD CONSTRAINT MRASRESLAB_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    WORK_POSITION,
    WORK_DATE,
    WORK_SHIFT
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRASRESHIS : Resource History Table */
CREATE TABLE MRASRESHIS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    EVENT_ID                    VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /* Transaction Time - Backdated 가능 */
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* System Time */
    SYS_TRAN_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Old Event */
    OLD_EVENT_ID                VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    OLD_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    OLD_TRAN_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OLD_SYS_TRAN_TIME           VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
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
    /* CUSTOMIZED FIELD FOR EVENT */
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
    TRAN_CMF_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
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
    HIST_DEL_COMMENT            VARCHAR2(400)    DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MRASRESHIS
ADD CONSTRAINT MRASRESHIS_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

/* MRASRESLTH : Resource-Lot History Table */
CREATE TABLE MRASRESLTH
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Resource Info. */
    RES_HIST_DEL_FLAG           CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_ID                    VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Lot Info. */
    LOT_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    LOT_HIST_DEL_FLAG           CHAR(1)          DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOT_TYPE                    CHAR(1)          DEFAULT('P')    NOT NULL,
    RWK_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    QTY_1                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    RES_SEQ                     NUMBER(10)       DEFAULT(1)      NOT NULL,
    /*** #987 Start / End 시에 Multi Resource 지원(2012.04.11 by JYPARK) ***/
    SUBRES_ID                   VARCHAR2(20)     DEFAULT (' ')   NOT NULL,
    PORT_ID                     VARCHAR2(10)     DEFAULT (' ')   NOT NULL,
    CRR_ID                      VARCHAR2(20)     DEFAULT (' ')   NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MRASRESLTH
ADD CONSTRAINT MRASRESLTH_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    RES_HIST_SEQ,
    LOT_ID
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MRASRESLTH_IDX_1 ON MRASRESLTH
(
    LOT_ID,
    LOT_HIST_SEQ,
    LOT_HIST_DEL_FLAG
) TABLESPACE HISTORY_IDX_TS;

/* MRASRESDWH : Resource Down History Table */
CREATE TABLE MRASRESDWH
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DOWN_HIST_SEQ               NUMBER(10)       DEFAULT(0)      NOT NULL,
    DOWN_EVENT_ID               VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /* Transaction Time - Backdated 가능 */
    DOWN_TRAN_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* System Time */
    DOWN_SYS_TRAN_TIME          VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Down Event Status */
    DOWN_PRI_STS                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DOWN_NEW_STS_1              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DOWN_NEW_STS_2              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DOWN_NEW_STS_3              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DOWN_NEW_STS_4              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DOWN_NEW_STS_5              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DOWN_NEW_STS_6              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DOWN_NEW_STS_7              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DOWN_NEW_STS_8              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DOWN_NEW_STS_9              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    DOWN_NEW_STS_10             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* 이벤트 COMMENT는 400 */
    DOWN_TRAN_USER_ID           VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DOWN_TRAN_COMMENT           VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* Down Interval (단위 : Second) */
    DOWN_INTERVAL               NUMBER(9)        DEFAULT(0)      NOT NULL,
    /** Up Event Info. **/
    UP_HIST_SEQ                 NUMBER(10)       DEFAULT(0)      NOT NULL,
    UP_EVENT_ID                 VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /* Transaction Time - Backdated 가능 */
    UP_TRAN_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* System Time */
    UP_SYS_TRAN_TIME            VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Up Event Status */
    UP_PRI_STS                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    UP_NEW_STS_1                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    UP_NEW_STS_2                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    UP_NEW_STS_3                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    UP_NEW_STS_4                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    UP_NEW_STS_5                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    UP_NEW_STS_6                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    UP_NEW_STS_7                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    UP_NEW_STS_8                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    UP_NEW_STS_9                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    UP_NEW_STS_10               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* 이벤트 COMMENT는 400 */
    UP_TRAN_USER_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UP_TRAN_COMMENT             VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* User CODE/ID/Time/Comment 1~3 */
    USER_ID_1                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_TIME_1                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    USER_COMMENT_1              VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    USER_ID_2                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_TIME_2                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    USER_COMMENT_2              VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    USER_ID_3                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_TIME_3                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    USER_COMMENT_3              VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* Delete Info. */
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    HIST_DEL_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_COMMENT            VARCHAR2(400)    DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MRASRESDWH
ADD CONSTRAINT MRASRESDWH_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    DOWN_HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MRASSRSDEF : Sub Resource Definition Table */
CREATE TABLE MRASSRSDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_DESC                 VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    PARENTS_SUBRES_ID           VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_TYPE                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USE_FAC_PRT_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    RES_STS_PRT_1               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_PRT_2               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_PRT_3               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_PRT_4               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_PRT_5               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_PRT_6               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_PRT_7               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_PRT_8               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_PRT_9               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_PRT_10              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_CMF_1                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_CMF_2                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_CMF_3                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_CMF_4                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_CMF_5                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_CMF_6                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_CMF_7                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_CMF_8                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_CMF_9                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_CMF_10               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_CMF_11               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_CMF_12               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_CMF_13               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_CMF_14               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_CMF_15               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_CMF_16               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_CMF_17               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_CMF_18               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_CMF_19               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_CMF_20               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHAMBER_TYPE_FLAG           CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHAMBER_GRP_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_LOCATION             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DELETE_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    DELETE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DELETE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    SUBRES_UP_DOWN_FLAG         CHAR(1)          DEFAULT('U')    NOT NULL,
    SUBRES_PRI_STS              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_STS_1                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_STS_2                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_STS_3                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_STS_4                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_STS_5                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_STS_6                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_STS_7                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_STS_8                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_STS_9                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBRES_STS_10               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LAST_EVENT_ID               VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    LAST_EVENT_TIME             VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LAST_ACTIVE_HIST_SEQ        NUMBER(10)       DEFAULT(0)      NOT NULL,
    LAST_HIST_SEQ               NUMBER(10)       DEFAULT(0)      NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASSRSDEF
ADD CONSTRAINT MRASSRSDEF_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    SUBRES_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRASSRSDEF : Sub Resource History Table */
CREATE TABLE MRASSRSHIS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    EVENT_ID                    VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    SYS_TRAN_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    PARENTS_SUBRES_ID           VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    MAIN_HIST_SEQ               NUMBER(10)       DEFAULT(0)      NOT NULL,
    OLD_EVENT_ID                VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    OLD_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    OLD_TRAN_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OLD_SYS_TRAN_TIME           VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
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
    LOT_EXIST_FLAG              CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* RAS-EDC 연결 */
    COL_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    COL_SET_VERSION             NUMBER(3)        DEFAULT(0)      NOT NULL,
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
    TRAN_CMF_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    LAST_DOWN_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LAST_DOWN_HIST_SEQ          NUMBER(10)       DEFAULT(0)      NOT NULL,
    HIST_START_SEQ              NUMBER(10)       DEFAULT(0)      NOT NULL,
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    HIST_DEL_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_COMMENT            VARCHAR2(200)    DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MRASSRSHIS
ADD CONSTRAINT MRASSRSHIS_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    SUBRES_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MRASSRSEVN : Sub Resource - Event Relation Table */
CREATE TABLE MRASSRSEVN
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    EVENT_ID                    VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASSRSEVN
ADD CONSTRAINT MRASSRSEVN_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    SUBRES_ID,
    EVENT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRASSRSLOT : Sub Resource - Lot Relation Table */
CREATE TABLE MRASSRSLOT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PARENTS_SUBRES_ID           VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    EVENT_ID                    VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASSRSLOT
ADD CONSTRAINT MRASSRSLOT_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    SUBRES_ID,
    LOT_ID,
    SUBLOT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRASSRSLTH : Sub Resource - Lot History Relation Table */
CREATE TABLE MRASSRSLTH
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PARENTS_SUBRES_ID           VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    EVENT_ID                    VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LOT_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    SUBLOT_HIST_SEQ             NUMBER(10)       DEFAULT(0)      NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOT_TYPE                    CHAR(1)          DEFAULT('P')    NOT NULL,
    RWK_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    QTY_1                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MRASSRSLTH
ADD CONSTRAINT MRASSRSLTH_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    SUBRES_ID,
    HIST_SEQ,
    LOT_ID,
    SUBLOT_ID
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MRASPMSSEC : Resource PM Security Table */
CREATE TABLE MRASPMSSEC
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* PM Schedule Enable Flag : 'Y' - Enable, ' ' - Disable */
    SCHEDULE_ENABLE_FLAG        CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* PM Event Enable Flag : 'Y'-Enable , ' ' - Disable */
    EVENT_ENABLE_FLAG           CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASPMSSEC
ADD CONSTRAINT MRASPMSSEC_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    USER_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRASPMSSTS : Resource PM Schedule & PM action Status Table */
CREATE TABLE MRASPMSSTS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* PM 계획 일자 (YYYYMMDD) */
    PM_PLAN_DATE                VARCHAR2(8)      DEFAULT(' ')    NOT NULL,
    /* PM 주기 (ex : 1D, 1W, 2W, 3W, 1M, 2M, 4M, 1Q, 2Q, 1Y .., 'US' - Unscheduled) */
    PM_PERIOD                   VARCHAR2(6)      DEFAULT(' ')    NOT NULL,
    /* PM 을 Schedule 한 User ID */
    PM_PLAN_USER_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* PM 을 Schedule 한 시간 */
    PM_PLAN_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* PM Event 발생시 Event ID */
    PM_EVENT_ID                 VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /* PM Action Flag : Y - Scheduled Action , U - Unscheduled Action, ' ' - PM 미실시 */
    PM_ACT_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* PM Event 발생한 장비 History Seq */
    PM_ACT_HIST_SEQ             NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* PM 실시자 (PM Event 를 발생시킨 User ID) */
    PM_ACT_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* PM Event 발생 시간 */
    PM_ACT_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* PM Scheduling시 입력한 Comment */
    PM_COMMENT                  VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASPMSSTS
ADD CONSTRAINT MRASPMSSTS_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    PM_PLAN_DATE
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRASTOLTYE : Tool Type Definition Table */
CREATE TABLE MRASTOLTYE
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TOOL_TYPE                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TOOL_TYPE_DESC              VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* SYSTEM에서 사용하는 TOOL TYPE ,지울수 없음. 'Y', ' ' */
    SYSTEM_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Prompt */
    PRT_1                       VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_2                       VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_3                       VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_4                       VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_5                       VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_6                       VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_7                       VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_8                       VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_9                       VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_10                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_11                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_12                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_13                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_14                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_15                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_16                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_17                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_18                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_19                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_20                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_21                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_22                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_23                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_24                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_25                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_26                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_27                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_28                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_29                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    PRT_30                      VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    /* Data Type - A:Ascii, N:Number, F:Float */
    FMT_1                       CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_2                       CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_3                       CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_4                       CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_5                       CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_6                       CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_7                       CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_8                       CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_9                       CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_10                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_11                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_12                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_13                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_14                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_15                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_16                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_17                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_18                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_19                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_20                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_21                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_22                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_23                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_24                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_25                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_26                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_27                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_28                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_29                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_30                      CHAR(1)          DEFAULT('A')    NOT NULL,
    /* Data Size - 0 ~ 30 */
    SIZE_1                      NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_2                      NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_3                      NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_4                      NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_5                      NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_6                      NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_7                      NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_8                      NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_9                      NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_10                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_11                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_12                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_13                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_14                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_15                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_16                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_17                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_18                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_19                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_20                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_21                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_22                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_23                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_24                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_25                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_26                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_27                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_28                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_29                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    SIZE_30                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    /* Code Validation Table Name */
    TBL_1                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_2                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_3                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_4                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_5                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_6                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_7                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_8                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_9                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_10                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_11                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_12                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_13                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_14                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_15                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_16                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_17                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_18                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_19                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_20                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_21                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_22                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_23                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_24                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_25                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_26                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_27                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_28                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_29                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_30                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Setup 에서 사용되는 Item 인지의 여부를 결정 */
    SETUP_FLAG_1                CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_2                CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_3                CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_4                CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_5                CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_6                CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_7                CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_8                CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_9                CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_10               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_11               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_12               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_13               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_14               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_15               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_16               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_17               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_18               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_19               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_20               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_21               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_22               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_23               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_24               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_25               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_26               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_27               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_28               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_29               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SETUP_FLAG_30               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Event 에서 사용되는 Item 인지의 여부를 결정 */
    EVENT_FLAG_1                CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_2                CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_3                CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_4                CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_5                CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_6                CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_7                CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_8                CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_9                CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_10               CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_11               CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_12               CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_13               CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_14               CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_15               CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_16               CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_17               CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_18               CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_19               CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_20               CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_21               CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_22               CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_23               CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_24               CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_25               CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_26               CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_27               CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_28               CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_29               CHAR(1)          DEFAULT(' ')    NOT NULL,
    EVENT_FLAG_30               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Setup 에서 사용되는 Item의 경우 Setup시 필수 입력사항인지를 결정 'Y', ' ' */
    OPT_1                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_2                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_3                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_4                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_5                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_6                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_7                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_8                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_9                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_10                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_11                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_12                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_13                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_14                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_15                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_16                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_17                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_18                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_19                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_20                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_21                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_22                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_23                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_24                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_25                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_26                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_27                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_28                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_29                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_30                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* create default value */
    CRT_VALUE_1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_6                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_7                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_8                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_9                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_10                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_11                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_12                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_13                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_14                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_15                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_16                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_17                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_18                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_19                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_20                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_21                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_22                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_23                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_24                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_25                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_26                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_27                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_28                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_29                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_VALUE_30                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Delete Info. */
    DELETE_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    DELETE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DELETE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASTOLTYE
ADD CONSTRAINT MRASTOLTYE_PK PRIMARY KEY
(
    FACTORY,
    TOOL_TYPE
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MRASTEVDEF : Tool Event Definition Table */
CREATE TABLE MRASTEVDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TOOL_TYPE                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TOOL_EVENT_ID               VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    TOOL_EVENT_DESC             VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* SYSTEM에서 사용하는 이벤트 ,지울수 없음. 'Y', ' ' */
    SYSTEM_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* DEFECT DATA를 COLLECT 하는 EVENT 여부 결정. 'Y', ' ' */
    COLLECT_DEFECT_FLAG         CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* DEFECT DATA를 CLEAN 하는 EVENT 여부 결정. 'Y', ' ' */
    CLEAN_DEFECT_FLAG           CHAR(1)          DEFAULT(' ')    NOT NULL,
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
    /* '-':다음의 값을 뺌, 'R' : 다음 값으로 무조건 변경, 'T' : Time */
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
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* CHANGE 할 FIELD */
    CHG_FIELD_1                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_2                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_3                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_4                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_5                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_6                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_7                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_8                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_9                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_10                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_11                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_12                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_13                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_14                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_15                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_16                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_17                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_18                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_19                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_20                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_21                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_22                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_23                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_24                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_25                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_26                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_27                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_28                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_29                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHG_FIELD_30                VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASTEVDEF
ADD CONSTRAINT MRASTEVDEF_PK PRIMARY KEY
(
    FACTORY,
    TOOL_TYPE,
    TOOL_EVENT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRASTOLDEF : Tool Definition Table */
CREATE TABLE MRASTOLDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TOOL_ID                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_DESC                   VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    TOOL_TYPE                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TOOL_GRP                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TOOL_SET_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TOOL_SET_LOCATION           VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TOOL_STATUS                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    AREA_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUB_AREA_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TOOL_LOCATION               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VENDOR_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VENDOR_TOOL_ID              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* TOOL 내 CELL의 수 */
    CELL_COUNT_X                NUMBER(10)       DEFAULT(0)      NOT NULL,
    CELL_COUNT_Y                NUMBER(10)       DEFAULT(0)      NOT NULL,
    CELL_COUNT_Z                NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* TOOL의 좌표별 SIZE */
    CELL_SIZE_X                 NUMBER(10)       DEFAULT(0)      NOT NULL,
    CELL_SIZE_Y                 NUMBER(10)       DEFAULT(0)      NOT NULL,
    CELL_SIZE_Z                 NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* TOOL 등급 */
    GRADE                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* TOOL의 상태값들 */
    TOOL_STS_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_21                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_22                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_23                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_24                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_25                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_26                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_27                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_28                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_29                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_30                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LAST_HIST_SEQ               NUMBER(10)       DEFAULT(0)      NOT NULL,
    LAST_ACTIVE_HIST_SEQ        NUMBER(10)       DEFAULT(0)      NOT NULL,
    LAST_TOOL_EVENT_ID          VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    LAST_TRAN_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* TOOL 패기, 반품 여부 'S' - 패기, 'R' - 반품, ' ' */
    DELETE_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    TOOL_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASTOLDEF
ADD CONSTRAINT MRASTOLDEF_PK PRIMARY KEY
(
    FACTORY,
    TOOL_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRASTOLEVN : Tool - Tool Event Relation Table */
CREATE TABLE MRASTOLEVN
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TOOL_ID                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_TYPE                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TOOL_EVENT_ID               VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASTOLEVN
ADD CONSTRAINT MRASTOLEVN_PK PRIMARY KEY
(
    FACTORY,
    TOOL_ID,
    TOOL_TYPE,
    TOOL_EVENT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRASTOLDFT : Tool - Tool Defect Data Table */
CREATE TABLE MRASTOLDFT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TOOL_ID                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_TYPE                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TOOL_EVENT_ID               VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    DEFECT_CODE                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    DEFECT_QTY                  NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    /* TOOL 내 CELL의 위치 정보 */
    CELL_X                      NUMBER(10)       DEFAULT(0)      NOT NULL,
    CELL_Y                      NUMBER(10)       DEFAULT(0)      NOT NULL,
    CELL_Z                      NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* DEFECT가 발생한 정확한 절대 위치 정보 */
    LOC_X                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    LOC_Y                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    LOC_Z                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CLEAN_FLAG                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CLEAN_HIST_SEQ              NUMBER(10)       DEFAULT(0)      NOT NULL,
    CLEAN_USER_ID               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CLEAN_TIME                  VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* 원인 Flow, 공정, 장비 */
    CAUSE_FLOW                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CAUSE_OPER                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CAUSE_RES_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CAUSE_SUBRES_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Defect Data 수집 요청자 */
    CHK_USER_ID1                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHK_USER_ID2                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    ATTACH_FILE_1               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    ATTACH_FILE_2               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    ATTACH_FILE_3               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    ATTACH_FILE_4               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    ATTACH_FILE_5               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    DEFECT_COMMENT              VARCHAR2(400)    DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MRASTOLDFT
ADD CONSTRAINT MRASTOLDFT_PK PRIMARY KEY
(
    FACTORY,
    TOOL_ID,
    HIST_SEQ,
    DEFECT_CODE,
    LOC_X,
    LOC_Y,
    LOC_Z
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MRASTOLHIS : Tool History Table */
CREATE TABLE MRASTOLHIS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TOOL_ID                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    TOOL_TYPE                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TOOL_EVENT_ID               VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    SYS_TRAN_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    TOOL_GRP                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TOOL_SET_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TOOL_SET_LOCATION           VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TOOL_STATUS                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    AREA_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUB_AREA_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TOOL_LOCATION               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VENDOR_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VENDOR_TOOL_ID              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* TOOL 내 CELL의 수 */
    CELL_COUNT_X                NUMBER(10)       DEFAULT(0)      NOT NULL,
    CELL_COUNT_Y                NUMBER(10)       DEFAULT(0)      NOT NULL,
    CELL_COUNT_Z                NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* TOOL의 좌표별 SIZE */
    CELL_SIZE_X                 NUMBER(10)       DEFAULT(0)      NOT NULL,
    CELL_SIZE_Y                 NUMBER(10)       DEFAULT(0)      NOT NULL,
    CELL_SIZE_Z                 NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* TOOL 등급 */
    GRADE                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* TOOL의 상태값들 */
    TOOL_STS_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_21                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_22                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_23                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_24                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_25                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_26                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_27                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_28                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_29                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_STS_30                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* TOOL 패기, 반품 여부 'S' - 패기, 'R' - 반품, ' ' */
    DELETE_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    TOOL_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    PREV_ACTIVE_HIST_SEQ        NUMBER(10)       DEFAULT(0)      NOT NULL,
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    HIST_DEL_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_COMMENT            VARCHAR2(400)    DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MRASTOLHIS
ADD CONSTRAINT MRASTOLHIS_PK PRIMARY KEY
(
    FACTORY,
    TOOL_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MRASPOTDEF : Port Definition Table */
CREATE TABLE MRASPOTDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Resource ID */
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Sub Resource id가 공백이면 메인에 붙어 있음 */
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PORT_ID                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* 화면에 보여주는 순서 */
    PORT_SEQ                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    PORT_DESC                   VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    TRS_STATE                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    ASC_STATE                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    ASC_OBJ_ID                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ACC_STATE                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    RSV_STATE                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    RSV_OBJ_ID                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    CRR_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* BARCODE STATUS U:UP    D:DOWN */
    BCR_STATUS_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* L : LOAD PORT U: UNLOAD PORT   B:BOTH */
    PORT_TYPE                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* BATCH LOAD PORT : 'Y' : BATCH LOADING 가능 */
    PORT_BATCH_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* RESERVED */
    ADD_PORT_TYPE               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* 사용 우선 순위 */
    PORT_LEVEL                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* PORT_CMF_1 ~ 10 이력에는 기록하지 않는다*/
    PORT_CMF_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PORT_CMF_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PORT_CMF_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PORT_CMF_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PORT_CMF_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PORT_CMF_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PORT_CMF_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PORT_CMF_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PORT_CMF_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PORT_CMF_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PORT_CMF_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PORT_CMF_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PORT_CMF_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PORT_CMF_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PORT_CMF_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PORT_CMF_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PORT_CMF_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PORT_CMF_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PORT_CMF_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PORT_CMF_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* 마지막 이력 */
    LAST_HIST_SEQ               NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASPOTDEF
ADD CONSTRAINT MRASPOTDEF_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    SUBRES_ID,
    PORT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRASPOTHIS : Port History Table */
CREATE TABLE MRASPOTHIS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Resource ID */
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Sub Resource id가 공백이면 메인에 붙어 있음 */
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PORT_ID                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Transaction Code */
    TRAN_CODE                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /* Transaction Time - Backdated 가능 */
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* System Time */
    SYS_TRAN_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    TRS_STATE                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    ASC_STATE                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    ASC_OBJ_ID                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ACC_STATE                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    RSV_STATE                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    RSV_OBJ_ID                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    CRR_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* BARCODE STATUS U:UP    D:DOWN */
    BCR_STATUS_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
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
    TRAN_CMF_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Transaction User ID/Comment */
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MRASPOTHIS
ADD CONSTRAINT MRASPOTHIS_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    SUBRES_ID,
    PORT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* 2007.11.22. Add by Aiden. */
/* Carrier Group Definition table */
CREATE TABLE MRASCRRGRP
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CRR_GROUP                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CRR_GRP_DESC                VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Default limitation */
    USAGE_LIMIT_COUNT           NUMBER(6)        DEFAULT(0)      NOT NULL,
    USAGE_LIMIT_TIME            NUMBER(6)        DEFAULT(0)      NOT NULL,
    CLEAN_LIMIT_COUNT           NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Default terminate time */
    PLAN_TERMINATE_TIME         VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    USAGE_LIMIT_ALARM           VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CLEAN_LIMIT_ALARM           VARCHAR2(20)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASCRRGRP
ADD CONSTRAINT MRASCRRGRP_PK PRIMARY KEY
(
    FACTORY,
    CRR_GROUP
) USING INDEX TABLESPACE MESPLUS_IDX_TS;



/* 2007.11.22. Modify by Aiden. */
/* 2009.08.02. Modify by Aiden. */
/* Carrier Definition table */
CREATE TABLE MRASCRRDEF
(
    CRR_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CRR_DESC                    VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CRR_GROUP                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Carrier Status */
    /* Initialize - INIT - I, Not Process - WAIT - W, Process - PROC - P, Need Clean - NEED_CLEAN - N, Clean - CLEAN - C, Holded - HOLD - H, Terminate - TERM - T */
    CRR_STATUS                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CRR_STATUS_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Carrier Type */
    CRR_TYPE1                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CRR_TYPE2                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CRR_TYPE3                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CRR_MATERIAL                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CRR_SIZE                    NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* 사용할 AREA,ABY,EQUIP */
    USE_AREA_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USE_SUB_AREA_ID             VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    USE_RES_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* 사용가능 횟수 */
    USAGE_LIMIT_COUNT           NUMBER(6)        DEFAULT(0)      NOT NULL,
    USAGE_LIMIT_TIME            NUMBER(6)        DEFAULT(0)      NOT NULL,
    USAGE_COUNT                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    CLEAN_LIMIT_COUNT           NUMBER(6)        DEFAULT(0)      NOT NULL,
    CLEAN_COUNT                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* 현재 리소스 */
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PORT_ID                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Current location. (Stocker, Vehicle ...) */
    LOCATION_1                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LOCATION_2                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LOCATION_3                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LOCATION_4                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LOCATION_5                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Previous Resource Information */
    OLD_RES_ID                  VARCHAR2(20)     DEFAULT(' ')     NOT NULL,
    OLD_SUBRES_ID               VARCHAR2(20)     DEFAULT(' ')     NOT NULL,
    OLD_PORT_ID                 VARCHAR2(10)     DEFAULT(' ')     NOT NULL,
    /* Previous location. (Stocker, Vehicle ...) */
    OLD_LOCATION_1              VARCHAR2(20)     DEFAULT(' ')     NOT NULL,
    OLD_LOCATION_2              VARCHAR2(20)     DEFAULT(' ')     NOT NULL,
    OLD_LOCATION_3              VARCHAR2(20)     DEFAULT(' ')     NOT NULL,
    OLD_LOCATION_4              VARCHAR2(20)     DEFAULT(' ')     NOT NULL,
    OLD_LOCATION_5              VARCHAR2(20)     DEFAULT(' ')     NOT NULL,
    /* 세정 완료등 */
    NEED_CLEAN_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
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
    /* 예정 폐기일 */
    PLAN_TERMINATE_TIME         VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* CARR_CMF_1 ~ 10 */
    CRR_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_CMF_11                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_CMF_12                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_CMF_13                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_CMF_14                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_CMF_15                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_CMF_16                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_CMF_17                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_CMF_18                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_CMF_19                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRR_CMF_20                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* 마지막 이력 */
    LAST_HIST_SEQ               NUMBER(10)       DEFAULT(0)      NOT NULL,
    LAST_TRAN_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LAST_TRAN_CODE              VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    USAGE_LIMIT_ALARM           VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CLEAN_LIMIT_ALARM           VARCHAR2(20)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASCRRDEF
ADD CONSTRAINT MRASCRRDEF_PK PRIMARY KEY
(
    CRR_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

CREATE INDEX MRASCRRDEF_IDX_1 ON MRASCRRDEF
(
    FACTORY,
    CRR_ID,
    CRR_GROUP,
    CRR_TYPE1
) TABLESPACE MESPLUS_IDX_TS;


/* 2007.11.22. Modify by Aiden. */
/* 2009.08.02. Modify by Aiden. */
/* Carrier History table */
CREATE TABLE MRASCRRHIS
(
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
    NEED_CLEAN_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
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
    TRAN_CMF_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Transaction User ID/Comment */
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;


ALTER TABLE MRASCRRHIS
ADD CONSTRAINT MRASCRRHIS_PK PRIMARY KEY
(
    CRR_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MRASCRRHIS_IDX_1 ON MRASCRRHIS
(
    TRAN_TIME,
    CRR_ID
) TABLESPACE HISTORY_IDX_TS;

/* 2009.09.29. Add by Aiden. */
/* Carrier Slot History table */
CREATE TABLE MRASCRRSHS
(
    CRR_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SLOT_NO                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Transaction Code */
    TRAN_CODE                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    CRR_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    CRR_SLOT_HIST_SEQ           NUMBER(10)       DEFAULT(0)      NOT NULL,
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SUBLOT_HIST_SEQ             NUMBER(10)       DEFAULT(0)      NOT NULL,
    OLD_CRR_HIST_SEQ            NUMBER(10)       DEFAULT(0)      NOT NULL,
    OLD_SUBLOT_ID               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_SUBLOT_HIST_SEQ         NUMBER(10)       DEFAULT(0)      NOT NULL,
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MRASCRRSHS
ADD CONSTRAINT MRASCRRSHS_PK PRIMARY KEY
(
    CRR_ID,
    SLOT_NO,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MRASCRRSHS_IDX_1 ON MRASCRRSHS
(
    CRR_ID,
    CRR_SLOT_HIST_SEQ
) TABLESPACE HISTORY_IDX_TS;

/* Lot Carrier relation table */
CREATE TABLE MWIPCRRLOT
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    CRR_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    QTY_1                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    USER_GRP_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    CRR_SEQ                     NUMBER(6)        DEFAULT(0)      NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPCRRLOT
ADD CONSTRAINT MWIPCRRLOT_PK PRIMARY KEY
(
    LOT_ID,
    CRR_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* Lot Carrier relation history table */
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
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPCRRLTH
ADD CONSTRAINT MWIPCRRLTH_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    CRR_ID
) USING INDEX TABLESPACE HISTORY_IDX_TS;

/* 2007.11.22. Add by Aiden. */
/* Carrier Group relation table */
CREATE TABLE MRASCGRREL
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Relation Level */
    /* 1 : MFO, 2 : FO, 3 : O, 4 : MO, R : Resource, P : Resource Port */
    REL_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PORT_ID                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CRR_GROUP                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRI_SEQ                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASCGRREL
ADD CONSTRAINT MRASCGRREL_PK PRIMARY KEY
(
    FACTORY,
    REL_LEVEL,
    MAT_ID,
    MAT_VER,
    FLOW,
    OPER,
    RES_ID,
    PORT_ID,
    CRR_GROUP
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* 2007.11.22. Add by Aiden. */
/* Carrier MFO option table */
CREATE TABLE MRASCRRMFO
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Relation Level */
    /* 1 : MFO, 2 : FO, 3 : O, 4 : MO */
    REL_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Change Point. A : Ad Hoc, S : Start, E : End */
    CHG_POINT                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    CUR_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TO_TYPE                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Change Mode. ST : Standard, SF : Standard Fill, XC : X-Cross, XF : X-Cross Fill */
    CHG_MODE                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASCRRMFO
ADD CONSTRAINT MRASCRRMFO_PK PRIMARY KEY
(
    FACTORY,
    REL_LEVEL,
    MAT_ID,
    MAT_VER,
    FLOW,
    OPER,
    CHG_POINT
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* Added by Hkyung - 2008.09.23 */
/* Carrier Event Definition Table */
CREATE TABLE MRASCEVDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CRR_EVENT_ID                VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    CRR_EVENT_DESC              VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
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
    /* '-':다음의 값을 뺌, 'R' : 다음 값으로 무조건 변경, 'T' : Time */
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


/* MRASTOLRSH : Resource and Tool History Relation Table */
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

/* MRASQRYDEF : Sheet Query Definition Table */
CREATE TABLE MRASQRYDEF
(
  FACTORY                       VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
  DATA_CODE                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  DATA_TYPE                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
  SHEET_DATA                    VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    /* Query Data */
  RESULT_TYPE                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* 'A': ASCII, 'N': Numeric Data */
  CHECK_VALUE                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* GCM Table Name For Validation */
  UPDATE_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
  UPDATE_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
  CREATE_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
  CREATE_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD1                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD2                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD3                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD4                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD5                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL
)TABLESPACE MESPLUS_DATA_TS;


ALTER TABLE MRASQRYDEF
ADD CONSTRAINT MRASQRYDEF_PK PRIMARY KEY
(
    FACTORY,
    DATA_CODE
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MRASSHTCAT : Sheet Type Definition Table */
CREATE TABLE MRASSHTCAT
(
  FACTORY                       VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
  SHEET_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
  TYPE_FLAG                     CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* 'S': SheetType, 'D': Transaction Type */
  CAT_SEQ                       NUMBER(10)       DEFAULT(0)      NOT NULL,
  CAT_CAPTION                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    /* Caption For Display */
  CAT_TABLE                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* GCM Table Name For Validation */
  UPDATE_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
  UPDATE_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
  CREATE_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
  CREATE_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD1                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD2                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD3                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD4                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD5                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL
)TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASSHTCAT
ADD CONSTRAINT MRASSHTCAT_PK PRIMARY KEY
(
    FACTORY,
    SHEET_TYPE,
    TYPE_FLAG,
    CAT_SEQ
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRASSHTDEF : Sheet Definition Table */
CREATE TABLE MRASSHTDEF
(
  FACTORY                       VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
  SHEET_NAME                    VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  SHEET_DESC                    VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
  SHEET_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
  SHEET_GRP_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  SHEET_GRP_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  SHEET_GRP_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  SHEET_GRP_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  SHEET_GRP_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  SHEET_GRP_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  SHEET_GRP_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  SHEET_GRP_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  SHEET_GRP_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  SHEET_GRP_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  UPDATE_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
  UPDATE_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
  CREATE_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
  CREATE_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD1                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD2                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD3                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD4                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD5                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASSHTDEF
ADD CONSTRAINT MRASSHTDEF_PK PRIMARY KEY
(
    FACTORY,
    SHEET_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;



/* MRASSHTDAT : Sheet and Query Relation Table */
CREATE TABLE MRASSHTDAT
(
  FACTORY                       VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
  SHEET_NAME                    VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  DATA_SEQ                      NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Display Sequence */
  DATA_CODE                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Query Code */
  SHEET_DATA                    VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
  RESULT_TYPE                   CHAR(1)          DEFAULT(' ')    NOT NULL,
  CHECK_VALUE                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
  UPDATE_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
  UPDATE_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
  CREATE_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
  CREATE_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD1                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD2                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD3                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD4                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD5                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASSHTDAT
ADD CONSTRAINT MRASSHTDAT_PK PRIMARY KEY
(
    FACTORY,
    SHEET_NAME,
    DATA_SEQ
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MRASSHTRST : Sheet Result Table */
CREATE TABLE MRASSHTRST
(
  FACTORY                       VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
  SHEET_NAME                    VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  SHEET_KEY_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  SHEET_KEY_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  SHEET_KEY_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  SHEET_KEY_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  SHEET_KEY_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  SHEET_KEY_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  SHEET_KEY_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  SHEET_KEY_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  SHEET_KEY_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  SHEET_KEY_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* User Define Code SHEET_KEY_1 ~ 10 */
  DATA_TYPE                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
  TRAN_TIME                     VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Sheet Result Category */
  DATA_SEQ                      NUMBER(10)       DEFAULT(0)      NOT NULL,
  DATA_CODE                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
  SHEET_DATA                    VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
  RESULT_TYPE                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* 'A': ASCII, 'N': Numeric Data */
  CHECK_VALUE                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* GCM Table For Validation */
  RESULT_VALUE                  VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
  UPDATE_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
  UPDATE_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
  CREATE_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
  CREATE_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
  SHEET_COMMENT                 VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
  RESV_FIELD1                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD2                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD3                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD4                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  RESV_FIELD5                   VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
  COMPLETE_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;


ALTER TABLE MRASSHTRST
ADD CONSTRAINT MRASSHTRST_PK PRIMARY KEY
(
    FACTORY,
    SHEET_NAME,
    SHEET_KEY_1,
    SHEET_KEY_2,
    SHEET_KEY_3,
    SHEET_KEY_4,
    SHEET_KEY_5,
    SHEET_KEY_6,
    SHEET_KEY_7,
    SHEET_KEY_8,
    SHEET_KEY_9,
    SHEET_KEY_10,
    DATA_TYPE,
    TRAN_TIME,
    DATA_SEQ
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* 2013.01.21. Add by Mihwa. */
/* ToolType relation table */
CREATE TABLE MRASTOLREL
(
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    REL_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RESG_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    EVENT_ID                    VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    TOOL_TYPE                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TOOL_ID                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TOOL_EVENT_ID               VARCHAR2(12)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MRASTOLREL
ADD CONSTRAINT MRASTOLREL_PK PRIMARY KEY
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
    EVENT_ID,
    TOOL_TYPE,
    TOOL_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


























/*==== WIP(Work In Process Module) ====*/
/* MWIPCALDEF : Calendar Definition Table */
CREATE TABLE MWIPCALDEF
(
    CALENDAR_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* System Year, Month, Day */
    SYS_YEAR                    NUMBER(4)        DEFAULT(0)      NOT NULL,
    SYS_MONTH                   NUMBER(2)        DEFAULT(0)      NOT NULL,
    SYS_DAY                     NUMBER(2)        DEFAULT(0)      NOT NULL,
    /* F:Factory Calendar, W:Work Calendar, F일 경우 CALENDAR_NAME은 FACTORY */
    CALENDAR_TYPE               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* SYS_DATE : 'YYYYMMDD' */
    SYS_DATE                    VARCHAR2(8)      DEFAULT(' ')    NOT NULL,
    /* Julian Day(1 ~ 365) */
    JULIAN_DAY                  NUMBER(4)        DEFAULT(0)      NOT NULL,
    /* 휴일 구분 */
    HOLIDAY_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    HOLIDAY_DESC                VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* 계획 년, 분기, 월, 주 */
    PLAN_YEAR                   NUMBER(4)        DEFAULT(0)      NOT NULL,
    PLAN_QUARTER                NUMBER(1)        DEFAULT(0)      NOT NULL,
    PLAN_MONTH                  NUMBER(2)        DEFAULT(0)      NOT NULL,
    PLAN_WEEK                   NUMBER(2)        DEFAULT(0)      NOT NULL,
    /* 시작시간, 시작시간이 어제인지, 작업 시간 */
    START_TIME                  NUMBER(14)       DEFAULT(0)      NOT NULL,
    PREV_DAY_FG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    WORK_HOURS                  NUMBER(4,2)      DEFAULT(0.0)    NOT NULL,
    /* Shift Change(근무하는 Shift Name 지정) */
    SHIFT_1                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SHIFT_2                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SHIFT_3                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SHIFT_4                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    CAL_GRP_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_GRP_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_GRP_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_GRP_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_GRP_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_GRP_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_GRP_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_GRP_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_GRP_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_GRP_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_CMF_11                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_CMF_12                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_CMF_13                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_CMF_14                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_CMF_15                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_CMF_16                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_CMF_17                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_CMF_18                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_CMF_19                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CAL_CMF_20                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPCALDEF
ADD CONSTRAINT MWIPCALDEF_PK PRIMARY KEY
(
    CALENDAR_ID,
    SYS_YEAR,
    SYS_MONTH,
    SYS_DAY
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPFACDEF : Factory Definition Table */
CREATE TABLE MWIPFACDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FAC_DESC                    VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* FACTORY TYPE FAB,ASSY,PROBE,TEST .... */
    FAC_TYPE                    VARCHAR2(2)      DEFAULT(' ')    NOT NULL,
    /* FACTORY GROUP */
    FAC_GRP_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FAC_GRP_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FAC_GRP_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FAC_GRP_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FAC_GRP_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* 주중 근무 일수, 일일 근무 시간 */
    DAYS_PER_WEEK               NUMBER(4,2)      DEFAULT(0.0)    NOT NULL,
    HOURS_PER_DAY               NUMBER(4,2)      DEFAULT(0.0)    NOT NULL,
    /* Variable Shift 구분, Shift 시작 시간, 전일(P)/금일( )/내일(N) 구분 */
    VARIABLE_SHIFT_FLAG         CHAR(1)          DEFAULT(' ')    NOT NULL,
    SHIFT_1_START               VARCHAR2(4)      DEFAULT(' ')    NOT NULL,
    SHIFT_1_DAY_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    SHIFT_2_START               VARCHAR2(4)      DEFAULT(' ')    NOT NULL,
    SHIFT_2_DAY_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    SHIFT_3_START               VARCHAR2(4)      DEFAULT(' ')    NOT NULL,
    SHIFT_3_DAY_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    SHIFT_4_START               VARCHAR2(4)      DEFAULT(' ')    NOT NULL,
    SHIFT_4_DAY_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Remote Factory 구분 */
    REMOTE_FAC_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Resource Status 1 ~ 10 */
    RES_STS_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RES_STS_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPFACDEF
ADD CONSTRAINT MWIPFACDEF_PK PRIMARY KEY
(
    FACTORY
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPFACSHP : Factory Shipping Definition Table */
CREATE TABLE MWIPFACSHP
(
    FACTORY_TO                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FACTORY_FROM                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    AUTO_TERM_FLAG              CHAR(1)          DEFAULT('Y')    NOT NULL,
    TRANSIT_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    REMOTE_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,  /* Add by J.S. 2009.03.05 */
    SHIP_CMF_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Mod For V42 cmf_1 -> ship_cmf_1*/
    SHIP_CMF_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SHIP_CMF_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SHIP_CMF_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SHIP_CMF_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SHIP_CMF_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SHIP_CMF_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SHIP_CMF_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SHIP_CMF_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SHIP_CMF_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SHIP_CMF_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SHIP_CMF_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SHIP_CMF_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SHIP_CMF_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SHIP_CMF_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SHIP_CMF_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SHIP_CMF_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SHIP_CMF_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SHIP_CMF_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SHIP_CMF_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPFACSHP
ADD CONSTRAINT MWIPFACSHP_PK PRIMARY KEY
(
    FACTORY_TO,
    FACTORY_FROM,
    TRANSIT_OPER
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPFACCMF : Factory GROUP & CMF(Customized Field) Definition Table */
CREATE TABLE MWIPFACCMF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    ITEM_NAME                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Prompt */
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
    /* Data Type - A:Ascii, N:Number, F:Float */
    FMT_1                       CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_2                       CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_3                       CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_4                       CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_5                       CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_6                       CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_7                       CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_8                       CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_9                       CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_10                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_11                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_12                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_13                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_14                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_15                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_16                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_17                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_18                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_19                      CHAR(1)          DEFAULT('A')    NOT NULL,
    FMT_20                      CHAR(1)          DEFAULT('A')    NOT NULL,
    /* Mandatory */
    OPT_1                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_2                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_3                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_4                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_5                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_6                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_7                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_8                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_9                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_10                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_11                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_12                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_13                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_14                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_15                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_16                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_17                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_18                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_19                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    OPT_20                      CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Code Validation Table Name */
    TBL_1                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_2                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_3                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_4                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_5                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_6                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_7                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_8                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_9                       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_10                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_11                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_12                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_13                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_14                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_15                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_16                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_17                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_18                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_19                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TBL_20                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPFACCMF
ADD CONSTRAINT MWIPFACCMF_PK PRIMARY KEY
(
    FACTORY,
    ITEM_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPMATDEF : Material Definition Table */
CREATE TABLE MWIPMATDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    MAT_DESC                    VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Material Type - FG:완제품, SG:반제품, CM:Component, RM:Raw Material */
    MAT_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* GRP 1 ~ 10 */
    MAT_GRP_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_GRP_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_GRP_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_GRP_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_GRP_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_GRP_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_GRP_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_GRP_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_GRP_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_GRP_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* CMF 1 ~ 20 */
    MAT_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_CMF_11                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_CMF_12                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_CMF_13                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_CMF_14                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_CMF_15                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_CMF_16                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_CMF_17                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_CMF_18                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_CMF_19                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_CMF_20                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* First Flow, Last Flow */
    FIRST_FLOW                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FIRST_FLOW_SEQ_NUM          NUMBER(6)        DEFAULT(0)      NOT NULL,
    LAST_FLOW                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LAST_FLOW_SEQ_NUM           NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* 생산 주체, 외주 생산 여부 */
    MFG_DEVISION                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBCONTRACT_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Base Material ID */
    BASE_MAT_ID                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* 자재 공급/생산 Vendor, Vendor Material ID */
    VENDOR_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    VENDOR_MAT_ID               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Customer ID, Customer Material ID */
    CUSTOMER_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CUSTOMER_MAT_ID             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Default Qty for Create(투입) Lot */
    DEF_QTY_1                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    DEF_QTY_2                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    DEF_QTY_3                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* 입출고 Unit of Measure */
    UNIT_1                      VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    UNIT_2                      VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    UNIT_3                      VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Weight(무게) */
    WEIGHT_NET                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    WEIGHT_GROSS                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    WEIGHT_UNIT                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Volume(부피) */
    VOLUME                      NUMBER(10,3)     DEFAULT(0.0) NOT NULL,
    VOLUME_UNIT                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Dimension(크기) - HR:HORIZONTAL, VT:VERTICAL, HT:HEIGHT */
    DIMENSION_HR                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    DIMENSION_HR_UNIT           VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    DIMENSION_VT                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    DIMENSION_VT_UNIT           VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    DIMENSION_HT                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    DIMENSION_HT_UNIT           VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* BOM Set ID */
    BOM_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Default Inventory Operation(자재 입고시 입고 공정) */
    DEF_INV_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* 포장 타입(_:N/A, L:Lot, Q:Qty) NOT NULL, 포장 수량(Lot Count, Qty) */
    PACK_TYPE                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    PACK_LOT_COUNT              NUMBER(10)       DEFAULT(0)      NOT NULL,
    PACK_QTY                    NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Stock Level 관리(Low Error/Low Warning/High Warning/High Error) */
    LE_STOCK_LEVEL              NUMBER(12,3)     DEFAULT(0.0)    NOT NULL,
    LW_STOCK_LEVEL              NUMBER(12,3)     DEFAULT(0.0)    NOT NULL,
    HW_STOCK_LEVEL              NUMBER(12,3)     DEFAULT(0.0)    NOT NULL,
    HE_STOCK_LEVEL              NUMBER(12,3)     DEFAULT(0.0)    NOT NULL,
    /* IQC(Ingoing QC) 수입 검사 여부, 샘플링 검사 여부 */
    IQC_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    IQC_SAMPLE_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    IQC_SAMPLE_RULE             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* OQC(Outgoing QC) 출하 검사 여부, 샘플링 검사 여부 */
    OQC_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    OQC_SAMPLE_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    OQC_SAMPLE_RULE             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* 목포 YIELD */
    TARGET_YIELD                NUMBER(20,10)     DEFAULT(0.0)    NOT NULL,
    /* 목표 DUE DAY */
    TARGET_DUE_DAY              NUMBER(4,2)      DEFAULT(0.0)    NOT NULL,
    /* TARGET QUANTITY */
    TARGET_QTY_1                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    TARGET_QTY_2                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    TARGET_QTY_3                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Approval, Release 필드 예약 */
    APPLY_START_TIME            VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    APPLY_END_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Approval Info. */
    APPROVAL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    APPROVAL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    APPROVAL_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Release Info.*/
    RELEASE_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    RELEASE_USER_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RELEASE_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* DeActive Info. */
    DEACTIVE_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    DEACTIVE_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DEACTIVE_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Delete Info. */
    DELETE_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    DELETE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DELETE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Short Description */
    MAT_SHORT_DESC              VARCHAR2(50)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPMATDEF
ADD CONSTRAINT MWIPMATDEF_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPOPRDEF : Operation Definition Table */
CREATE TABLE MWIPOPRDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    OPER_DESC                   VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* GRP 1 ~ 10 */
    OPER_GRP_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_GRP_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_GRP_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_GRP_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_GRP_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_GRP_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_GRP_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_GRP_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_GRP_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_GRP_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* CMF 1 ~ 20 */
    OPER_CMF_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_CMF_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_CMF_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_CMF_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_CMF_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_CMF_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_CMF_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_CMF_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_CMF_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_CMF_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_CMF_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_CMF_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_CMF_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_CMF_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_CMF_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_CMF_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_CMF_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_CMF_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_CMF_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OPER_CMF_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Lot의 Operation 진행 단위 */
    UNIT_1                      VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    UNIT_2                      VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    UNIT_3                      VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* TRANSIT OPERATION */
    TRANSIT_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* SHIPPING OPERATION */
    SHIP_FLAG                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Inventory OPERATION */
    INV_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* ERP INTERFACE OPERATION */
    ERP_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* START 필요 여부 */
    START_REQUIRE_FLAG          CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* 이공정 이후에는 더이상 진행 할 수 없음. */
    END_OPER_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* PUSH/PULL 구분 - _:PUSH, Y:PULL */
    PUSH_PULL_FLAG              CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* LOSS,BONUS,REWORK CODE TABLE */
    LOSS_TBL                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    BONUS_TBL                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    REWORK_TBL                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Operation을 진행할 수 있는 Security Group ' '일 경우 모든 USER사용 가능 */
    SEC_CHK_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* 이공정이 속해있는 BAY 및 AREA */
    AREA_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUB_AREA_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Short Description */
    OPER_SHORT_DESC             VARCHAR2(50)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPOPRDEF
ADD CONSTRAINT MWIPOPRDEF_PK PRIMARY KEY
(
    FACTORY,
    OPER
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPFLWDEF : Flow Definition Table */
CREATE TABLE MWIPFLWDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_DESC                   VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* REWORK FLOW 인지 여부 Y: REWORK FLOW  ' ':NORMAL FLOW */
    /* ALTER FLOW 인지 여부 Y: ALTER FLOW  ' ':NORMAL FLOW */
    /* FLOW_TYPE                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL, */
    /* GRP 1 ~ 10 */
    FLOW_GRP_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_GRP_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_GRP_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_GRP_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_GRP_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_GRP_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_GRP_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_GRP_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_GRP_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_GRP_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* CMF 1 ~ 10 */
    FLOW_CMF_1                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_CMF_2                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_CMF_3                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_CMF_4                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_CMF_5                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_CMF_6                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_CMF_7                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_CMF_8                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_CMF_9                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_CMF_10                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_CMF_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_CMF_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_CMF_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_CMF_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_CMF_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_CMF_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_CMF_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_CMF_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_CMF_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FLOW_CMF_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* First Oper, Last Oper */
    FIRST_OPER                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LAST_OPER                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* 이공정이 속해있는 BAY 및 AREA */
    /* AREA_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL, */
    /* SUB_AREA_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL, */
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Short Description */
    FLOW_SHORT_DESC             VARCHAR2(50)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPFLWDEF
ADD CONSTRAINT MWIPFLWDEF_PK PRIMARY KEY
(
    FACTORY,
    FLOW
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPFLWOPR : Flow-Oper Definition Table */
CREATE TABLE MWIPFLWOPR
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* V4 추가 공정간 Group, 연속된 공정만이 같은 group을 가질 수 있음*/
    OPT_OPER_GROUP              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPT_OPER_OPTION_FLAG        CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Sequence Number */
    SEQ_NUM                     NUMBER(6)        DEFAULT(0) NOT NULL,
    /* First Oper, Last Oper */
    PREV_OPER                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    NEXT_OPER                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPFLWOPR
ADD CONSTRAINT MWIPFLWOPR_PK PRIMARY KEY
(
    FACTORY,
    FLOW,
    OPER
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPMATFLW : Material-Flow Definition Table */
CREATE TABLE MWIPMATFLW
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* V4 추가 공정간 Group, 연속된 공정만이 같은 group을 가질 수 있음*/
    OPT_FLOW_GROUP              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPT_FLOW_OPTION_FLAG        CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Sequence Number */
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 SEQ_NUM -> FLOW_SEQ_NUM */
    /* First Oper, Last Oper */
    PREV_FLOW                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PREV_FLOW_SEQ_NUM           NUMBER(6)        DEFAULT(0)      NOT NULL,
    NEXT_FLOW                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    NEXT_FLOW_SEQ_NUM           NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPMATFLW
ADD CONSTRAINT MWIPMATFLW_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    FLOW_SEQ_NUM
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPRWKDEF : Rework Flow Definition Table */
CREATE TABLE MWIPRWKDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RWK_CODE                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Rework Flow/Oper */
    RWK_FLOW                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RWK_FLOW_SEQ_NUM            NUMBER(6)        DEFAULT(0)      NOT NULL,
    RWK_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RWK_STOP_OPER               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Option Level - '1':M-F-O, '2':F-O, '3':O */
    /* '3':Operation Level은 셋업하지 않는다. */
    OPT_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Rework Flow/Oper */
    RET_FLOW                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RET_FLOW_SEQ_NUM            NUMBER(6)        DEFAULT(0)      NOT NULL,
    RET_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Return Option Flag */
    /* ' ':Keep Rework, 'Y':Clear Rework */
    /* 'A':Clear Rework and Move to Next Operation */
    /* 'B':Keep Rework and Move to Next Operation */
    RET_CLEAR_FLAG              CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPRWKDEF
ADD CONSTRAINT MWIPRWKDEF_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    OPER,
    RWK_CODE,
    RWK_FLOW,
    RWK_FLOW_SEQ_NUM,
    RWK_OPER
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPCYTDEF : Standard Cycle Time Definition Table */
/* Queue/Proc Time의 단위는 Hour */
CREATE TABLE MWIPCYTDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Option Level - '1':M-F-O, '2':F-O, '3':O */
    OPT_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Queue Time, Process Time */
    QUEUE_TIME                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    PROC_TIME                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Hour Per Unit */
    HPU_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    HPU_PROC_TIME               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Unit Per Hour */
    UPH_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    UPH_PROC_TIME               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPCYTDEF
ADD CONSTRAINT MWIPCYTDEF_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    FLOW_SEQ_NUM,
    OPER
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPSLTDEF : Sub Lot Options Definition Table */
CREATE TABLE MWIPSLTDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Option Level - 1:P-R-O, 2:R-O, 3:O */
    OPT_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    SUBLOT_TRACKING_FLAG        CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPSLTDEF
ADD CONSTRAINT MWIPSLTDEF_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    OPER
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPYLDDEF : Standard Yield Definition Table */
CREATE TABLE MWIPYLDDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Option Level - '1':M-F-O, '2':F-O, '3':O */
    OPT_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Standard Yield */
    STD_YIELD                   NUMBER(20,10)     DEFAULT(0.0)    NOT NULL,
    /* Planning Yield */
    PLN_YIELD                   NUMBER(20,10)    DEFAULT(0.0)    NOT NULL,
    /* Unit Change Yield */
    UNIT_CHG_YIELD              NUMBER(20,10)    DEFAULT(0.0)    NOT NULL,
    CUSTOM_YIELD_1              NUMBER(20,10)    DEFAULT(0.0)    NOT NULL,
    CUSTOM_YIELD_2              NUMBER(20,10)    DEFAULT(0.0)    NOT NULL,
    CUSTOM_YIELD_3              NUMBER(20,10)    DEFAULT(0.0)    NOT NULL,
    CUSTOM_YIELD_4              NUMBER(20,10)    DEFAULT(0.0)    NOT NULL,
    CUSTOM_YIELD_5              NUMBER(20,10)    DEFAULT(0.0)    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_1                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_2                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_3                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_4                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_5                VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPYLDDEF
ADD CONSTRAINT MWIPYLDDEF_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    FLOW_SEQ_NUM,
    OPER
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPCOLDEF : WIP-Collection Set Attach Table */
CREATE TABLE MWIPCOLDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Option Level - '1':M-F-O, '2':F-O, '3':O */
    OPT_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Collection Set ID */
    COL_SET_ID                  VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Collection Mode */
    COLLECTION_MODE             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Default Flag */
    DEFAULT_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Disable Flag */
    DISABLE_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPCOLDEF
ADD CONSTRAINT MWIPCOLDEF_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    OPER,
    OPT_LEVEL,
    COL_SET_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* WIPALS : Alias Lot Number Table */
/* WIPATT : Attribute Definition Table */
/* WIPBAT : Batch(QA Lot) Information Table */
/* WIPBLA : Bill of Lading Information Table */
/* WIPBLT : Batch-Lot Information Table */
/* WIPCON : Container Information Table */
/* WIPOPR : Operation Definition Table */
/* WIPPLL : Pallet Information Table */
/* WIPPLT : Pallet-Lot Information Table */
/* WIPRWH : Replace(Rework) History Table */

/* WIPLBH : Lot Part Replace/Separate History Table */
/* WIPLBL : Lot-Bill of Lading(Container) Information Table */
/* WIPLHA : Lot Attribute History Table */
/* WIPLTA : Lot-Attribute Information Table */
/* WIPLTB : Lot-BOM Material Information Table */


/* MWIPORDSTS : Order Status Table */
CREATE TABLE MWIPORDSTS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /** Order Info. **/
    ORDER_ID                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Flow */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 SEQ_NUM -> FLOW_SEQ_NUM */
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
    /* Quantity 1 ~ 3 */
    QTY                         NUMBER(10,3)     DEFAULT(0.0) NOT NULL,
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
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    ORDER_DESC                  VARCHAR2(200)    DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPORDSTS
ADD CONSTRAINT MWIPORDSTS_PK PRIMARY KEY
(
    FACTORY,
    ORDER_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPPLNDEF : WIP Production Plan Table */
CREATE TABLE MWIPPLNDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Work Date - YYYYMMDD */
    WORK_DATE                   CHAR(8)          DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
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
    CREATE_LOT_COUNT            NUMBER(10)       DEFAULT(0)      NOT NULL,
    CREATE_QTY                  NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPPLNDEF
ADD CONSTRAINT MWIPPLNDEF_PK PRIMARY KEY
(
    FACTORY,
    WORK_DATE,
    MAT_ID,
    MAT_VER
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPPLNLOT : Planned Lot Table */
CREATE TABLE MWIPPLNLOT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Work Date - YYYYMMDD */
    WORK_DATE                   CHAR(8)          DEFAULT(' ')    NOT NULL,
    /** Create Info. **/
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOT_DESC                    VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Flow, Oper */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,  /* Add For V42 SEQ_NUM -> FLOW_SEQ_NUM */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Quantity 1 ~ 3 */
    QTY_1                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Lot Type - 'P':Production, 'T':Test, 'E':Engineer, 'D':Dummy, 'M':Monitoring */
    LOT_TYPE                    CHAR(1)          DEFAULT('P')    NOT NULL,
    /* Owner Code, Create Code */
    OWNER_CODE                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CREATE_CODE                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* LOT의 우선순위 - '0'-->'9' LOW-->HIGH, 기본값:'5' */
    LOT_PRIORITY                CHAR(1)          DEFAULT('5')    NOT NULL,
    /* Due Time(Original, Scheduled) */
    ORG_DUE_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Resource ID */
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /** Order Info. **/
    ORDER_ID                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /** Create Status **/
    LOT_CREATE_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOT_CREATE_TIME             VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPPLNLOT
ADD CONSTRAINT MWIPPLNLOT_PK PRIMARY KEY
(
    FACTORY,
    WORK_DATE,
    LOT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPWRKORD : Work Order Table */
CREATE TABLE MWIPWRKORD
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Resource or Oper Flag - 'R':Resource, 'O':Oper */
    RES_OR_OPR_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Resource ID */
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Operation */
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Work Date - YYYYMMDD */
    WORK_DATE                   CHAR(8)          DEFAULT(' ')    NOT NULL,
    /* Work Shift - ' '/'1'/'2'/'3'/'4' */
    WORK_SHIFT                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Sequence Number */
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /** Work Order Info. **/
    /* Work Comment */
    WORK_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* Order/Material/Lot Flag - 'O'/'M'/'L' */
    ORD_MAT_LOT_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Order */
    ORDER_ID                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Lot ID */
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Quantity - Order/Material 인 경우에는 입력 받는다. */
    QTY                         NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPWRKORD
ADD CONSTRAINT MWIPWRKORD_PK PRIMARY KEY
(
    FACTORY,
    RES_OR_OPR_FLAG,
    RES_ID,
    OPER,
    WORK_DATE,
    WORK_SHIFT,
    SEQ_NUM
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPLOTSTS : Lot Status Table */
CREATE TABLE MWIPLOTSTS
(
    /* Lot ID는 모든 Factory에서 Unique */
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOT_DESC                    VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Current Factory */
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Flow, Oper */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Quantity 1 ~ 3 */
    QTY_1                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* 캐리어 ID */
    CRR_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
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
    HOLD_PRV_GRP_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Oper In Quantity 1 ~ 3 */
    OPER_IN_QTY_1               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OPER_IN_QTY_2               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OPER_IN_QTY_3               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Create Qty 1~3 */
    CREATE_QTY_1                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CREATE_QTY_2                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CREATE_QTY_3                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Start Quantity 1 ~ 3 */
    START_QTY_1                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    START_QTY_2                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    START_QTY_3                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Inventory Operation에 들어 있음. MOVE 불가능 */
    INV_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* RECEIVING 대기 */
    TRANSIT_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Unit Exist Flag */
    UNIT_EXIST_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Inventory Unit */
    INV_UNIT                    VARCHAR2(10)     DEFAULT(0.0)    NOT NULL,
    /* Rework Info. */
    RWK_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    RWK_CODE                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* LOT의 Rework 누적 횟수 */
    RWK_COUNT                   NUMBER(6)        DEFAULT(0)      NOT NULL,
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
    RWK_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Non Standard Move Info. */
    NSTD_FLAG                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    NSTD_RET_FLOW               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    NSTD_RET_FLOW_SEQ_NUM       NUMBER(6)        DEFAULT(0)      NOT NULL,
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
    /* From To Info. */
    FROM_TO_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
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
    /* Last Tran Info. */
    /* Last Active History Seq(Requested by Fred) */
    /* History가 지워진 경우 마지막 Active History Seq Number 필요 */
    LAST_TRAN_CODE              VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    LAST_TRAN_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LAST_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    LAST_ACTIVE_HIST_SEQ        NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Last History Sequence Number(Only Increase) */
    LAST_HIST_SEQ               NUMBER(10)       DEFAULT(0)      NOT NULL,
    CRITICAL_RES_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* 크리티칼 레이어의 장비 그룹을 사용할 경우 경우를 대비 */
    CRITICAL_RES_GROUP_ID       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SAVE_RES_ID_1               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SAVE_RES_ID_2               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LOT_GROUP_ID_1              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOT_GROUP_ID_2              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOT_GROUP_ID_3              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Lot Yield Info. */
    YIELD_1                     NUMBER(20,10)    DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    YIELD_2                     NUMBER(20,10)    DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    YIELD_3                     NUMBER(20,10)    DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    GOOD_QTY                    NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    RESV_FIELD_1                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_2                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_3                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_4                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_5                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FLAG_1                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_2                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_3                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_4                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_5                 CHAR(1)          DEFAULT(' ')    NOT NULL 
) TABLESPACE MESPLUS_DATA_TS;


ALTER TABLE MWIPLOTSTS
ADD CONSTRAINT MWIPLOTSTS_PK PRIMARY KEY
(
    LOT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* Add by J.S. Resource에서 진행 중인 lot의 수량을 count하기 위함 */
CREATE INDEX MWIPLOTSTS_IDX_1 ON MWIPLOTSTS
(
    FACTORY,
    START_RES_ID,
    START_FLAG,
    LOT_DEL_FLAG
) TABLESPACE MESPLUS_IDX_TS;

CREATE INDEX MWIPLOTSTS_IDX_2 ON MWIPLOTSTS
(
    FACTORY,
    LOT_DEL_FLAG,
    OPER
) TABLESPACE MESPLUS_IDX_TS;

/* MWIPLOTSTS_SNP : Snapshot on MWIPLOTSTS Table */
/* Not Use
CREATE MATERIALIZED VIEW MWIPLOTSTS_SNP
NOCACHE
LOGGING
NOPARALLEL
BUILD IMMEDIATE
AS
SELECT MWIPLOTSTS.LOT_CMF_1 AS CM_KEY_1, MWIPLOTSTS.LOT_CMF_2 AS CM_KEY_2, MWIPLOTSTS.LOT_CMF_3 AS CM_KEY_3,
MWIPLOTSTS.LOT_CMF_4 AS CM_KEY_4, MWIPLOTSTS.LOT_CMF_5 AS CM_KEY_5, MWIPLOTSTS.* FROM MWIPLOTSTS;
*/


/* JJS */
/* MWIPLOTHIS : Lot History Table */
CREATE TABLE MWIPLOTHIS
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Transaction Time - Backdated 가능 */
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* System Time */
    SYS_TRAN_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Transaction Code */
    TRAN_CODE                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /******** Mod For V42 Status  *********/
    LOT_DESC                    VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Current Factory */
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Flow, Oper */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Quantity 1 ~ 3 */
    QTY_1                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* 캐리어 ID */
    CRR_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
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
    HOLD_PRV_GRP_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Oper In Quantity 1 ~ 3 */
    OPER_IN_QTY_1               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OPER_IN_QTY_2               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OPER_IN_QTY_3               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Create Qty 1~3 */
    CREATE_QTY_1                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CREATE_QTY_2                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CREATE_QTY_3                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Start Quantity 1 ~ 3 */
    START_QTY_1                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    START_QTY_2                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    START_QTY_3                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Inventory Operation에 들어 있음. MOVE 불가능 */
    INV_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* RECEIVING 대기 */
    TRANSIT_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Unit Exist Flag */
    UNIT_EXIST_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Inventory Unit */
    INV_UNIT                    VARCHAR2(10)     DEFAULT(0.0)    NOT NULL,
    /* Rework Info. */
    RWK_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    RWK_CODE                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* LOT의 Rework 누적 횟수 */
    RWK_COUNT                   NUMBER(6)        DEFAULT(0)      NOT NULL,
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
    RWK_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Non Standard Move Info. */
    NSTD_FLAG                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    NSTD_RET_FLOW               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    NSTD_RET_FLOW_SEQ_NUM       NUMBER(6)        DEFAULT(0)      NOT NULL,
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
    FROM_TO_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
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
    CRITICAL_RES_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* 크리티칼 레이어의 장비 그룹을 사용할 경우 경우를 대비 */
    CRITICAL_RES_GROUP_ID       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SAVE_RES_ID_1               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SAVE_RES_ID_2               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LOT_GROUP_ID_1              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOT_GROUP_ID_2              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOT_GROUP_ID_3              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Lot Yield Info. */
    YIELD_1                     NUMBER(20,10)    DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    YIELD_2                     NUMBER(20,10)    DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    YIELD_3                     NUMBER(20,10)    DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    GOOD_QTY                    NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    RESV_FIELD_1                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_2                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_3                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_4                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_5                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FLAG_1                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_2                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_3                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_4                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_5                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /******** Mod For V42 Status  *********/
    FROM_TO_MAT_ID              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FROM_TO_MAT_VER             NUMBER(6)        DEFAULT(0)      NOT NULL,
    FROM_TO_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FROM_TO_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,
    FROM_TO_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FROM_TO_QTY_1               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_QTY_2               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_QTY_3               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_HIST_SEQ            NUMBER(10)       DEFAULT(0)      NOT NULL,
    /** Old Lot Info. **/
    OLD_FACTORY                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    OLD_MAT_ID                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_MAT_VER                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Flow, Oper */
    OLD_FLOW                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OLD_FLOW_SEQ_NUM            NUMBER(6)        DEFAULT(0)      NOT NULL,
    OLD_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Quantity 1 ~ 3 */
    OLD_QTY_1                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OLD_QTY_2                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OLD_QTY_3                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Lot Type - 'P':Production, 'T':Test, 'E':Engineer, 'D':Dummy, 'M':Monitoring */
    OLD_LOT_TYPE                CHAR(1)          DEFAULT('P')    NOT NULL,
    /* Owner Code, Create Code */
    OLD_OWNER_CODE              VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    OLD_CREATE_CODE             VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    OLD_FAC_IN_TIME             VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OLD_FLOW_IN_TIME            VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OLD_OPER_IN_TIME            VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
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
    TRAN_CMF_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Transaction User ID/Comment */
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* Previous Active History Sequence */
    PREV_ACTIVE_HIST_SEQ        NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* History Block Number(Requested by Fred) */
    /* - Multi Transaction을 한번에 삭제할 경우 */
    MULTI_TR_KEY                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MULTI_TR_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* For additional extended table */
    EXT_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,  /* Add For V5 */
    /* Delete Info. */
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    HIST_DEL_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_COMMENT            VARCHAR2(400)    DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTHIS
ADD CONSTRAINT MWIPLOTHIS_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MWIPLOTHIS_IDX_1 ON MWIPLOTHIS
(
    LOT_ID,
    HIST_DEL_FLAG,
    TRAN_CODE
) TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MWIPLOTHIS_IDX_2 ON MWIPLOTHIS
(
    TRAN_TIME,
    LOT_ID,
    HIST_DEL_FLAG,
    TRAN_CODE
) TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MWIPLOTHIS_IDX_3 ON MWIPLOTHIS
(
    FACTORY,
    HIST_DEL_FLAG,
    MULTI_TR_KEY,
    TRAN_CODE,
    FROM_TO_FLAG,
    MULTI_TR_SEQ
) TABLESPACE HISTORY_IDX_TS;


/* MWIPLOTDEL : Deleted Lot History Table */
CREATE TABLE MWIPLOTDEL
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Transaction Time - Backdated 가능 */
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* System Time */
    SYS_TRAN_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Transaction Code */
    TRAN_CODE                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /******** Mod For V42 Status  *********/
    LOT_DESC                    VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Current Factory */
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Flow, Oper */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Quantity 1 ~ 3 */
    QTY_1                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* 캐리어 ID */
    CRR_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
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
    HOLD_PRV_GRP_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Oper In Quantity 1 ~ 3 */
    OPER_IN_QTY_1               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OPER_IN_QTY_2               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OPER_IN_QTY_3               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Create Qty 1~3 */
    CREATE_QTY_1                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CREATE_QTY_2                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CREATE_QTY_3                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Start Quantity 1 ~ 3 */
    START_QTY_1                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    START_QTY_2                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    START_QTY_3                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Inventory Operation에 들어 있음. MOVE 불가능 */
    INV_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* RECEIVING 대기 */
    TRANSIT_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Unit Exist Flag */
    UNIT_EXIST_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Inventory Unit */
    INV_UNIT                    VARCHAR2(10)     DEFAULT(0.0)    NOT NULL,
    /* Rework Info. */
    RWK_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    RWK_CODE                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* LOT의 Rework 누적 횟수 */
    RWK_COUNT                   NUMBER(6)        DEFAULT(0)      NOT NULL,
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
    RWK_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Non Standard Move Info. */
    NSTD_FLAG                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    NSTD_RET_FLOW               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    NSTD_RET_FLOW_SEQ_NUM       NUMBER(6)        DEFAULT(0)      NOT NULL,
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
    /* From To Info. */
    FROM_TO_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
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
    CRITICAL_RES_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* 크리티칼 레이어의 장비 그룹을 사용할 경우 경우를 대비 */
    CRITICAL_RES_GROUP_ID       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SAVE_RES_ID_1               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SAVE_RES_ID_2               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LOT_GROUP_ID_1              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOT_GROUP_ID_2              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOT_GROUP_ID_3              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Lot Yield Info. */
    YIELD_1                     NUMBER(20,10)    DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    YIELD_2                     NUMBER(20,10)    DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    YIELD_3                     NUMBER(20,10)    DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    GOOD_QTY                    NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    RESV_FIELD_1                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_2                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_3                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_4                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_5                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FLAG_1                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_2                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_3                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_4                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_5                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /******** Mod For V42 Status  *********/
    FROM_TO_MAT_ID              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FROM_TO_MAT_VER             NUMBER(6)        DEFAULT(0)      NOT NULL,
    FROM_TO_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FROM_TO_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,
    FROM_TO_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FROM_TO_QTY_1               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_QTY_2               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_QTY_3               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    FROM_TO_HIST_SEQ            NUMBER(10)       DEFAULT(0)      NOT NULL,
    /** Old Lot Info. **/
    OLD_FACTORY                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    OLD_MAT_ID                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    OLD_MAT_VER                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Flow, Oper */
    OLD_FLOW                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OLD_FLOW_SEQ_NUM            NUMBER(6)        DEFAULT(0)      NOT NULL,
    OLD_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Quantity 1 ~ 3 */
    OLD_QTY_1                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OLD_QTY_2                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OLD_QTY_3                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Lot Type - 'P':Production, 'T':Test, 'E':Engineer, 'D':Dummy, 'M':Monitoring */
    OLD_LOT_TYPE                CHAR(1)          DEFAULT('P')    NOT NULL,
    /* Owner Code, Create Code */
    OLD_OWNER_CODE              VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    OLD_CREATE_CODE             VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    OLD_FAC_IN_TIME             VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OLD_FLOW_IN_TIME            VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OLD_OPER_IN_TIME            VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Transaction CMF 1~10, Transaction User ID, Transaction Comment */
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
    TRAN_CMF_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Transaction User ID/Comment */
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* Previous Active History Sequence */
    PREV_ACTIVE_HIST_SEQ        NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* History Block Number(Requested by Fred) */
    /* - Multi Transaction을 한번에 삭제할 경우 */
    MULTI_TR_KEY                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MULTI_TR_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* For additional extended table */
    EXT_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,  /* Add For V5 */
    /* Delete Info. */
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    HIST_DEL_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_COMMENT            VARCHAR2(400)    DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTDEL
ADD CONSTRAINT MWIPLOTDEL_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    SYS_TRAN_TIME
) USING INDEX TABLESPACE HISTORY_IDX_TS;

/* MWIPLOTLOS : Lot Loss History Table */
CREATE TABLE MWIPLOTLOS
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
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
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
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTLOS
ADD CONSTRAINT MWIPLOTLOS_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    QTY_FLAG
) USING INDEX TABLESPACE HISTORY_IDX_TS;

/* MWIPLOTLSM : Lot Loss History(Multiple Record) Table */
CREATE TABLE MWIPLOTLSM
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
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Resource ID */
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Sequence Number */
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Loss Code/Qty */
    LOSS_CODE                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LOSS_QTY                    NUMBER(10,3)     DEFAULT(0.0)    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTLSM
ADD CONSTRAINT MWIPLOTLSM_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    QTY_FLAG,
    SEQ_NUM
) USING INDEX TABLESPACE HISTORY_IDX_TS;

/* MWIPLOTLNR : Not Loss History(Multiple Record) Table */
CREATE TABLE MWIPLOTLNR
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* QTY Flag - '1':Qty 1, '2':Qty 2, '3':Qty 3 */
    QTY_FLAG                    CHAR(1)          DEFAULT('1')    NOT NULL,
    /* Sequence Number */
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,
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

/* MWIPLOTBNS : Lot Bonus History Table */
CREATE TABLE MWIPLOTBNS
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
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
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
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTBNS
ADD CONSTRAINT MWIPLOTBNS_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    QTY_FLAG
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MWIPLOTBNM : Lot Bonus History(Multiple Record) Table */
CREATE TABLE MWIPLOTBNM
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
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Resource ID */
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Sequence Number */
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Bonus Code/Qty */
    BONUS_CODE                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BONUS_QTY                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTBNM
ADD CONSTRAINT MWIPLOTBNM_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    QTY_FLAG,
    SEQ_NUM
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MWIPLOTHLD : Lot Hold-Release History Table */
CREATE TABLE MWIPLOTHLD
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
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
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
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTHLD
ADD CONSTRAINT MWIPLOTHLD_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MWIPLOTSHP : Lot Shipping History Table */
CREATE TABLE MWIPLOTSHP
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
    CMF_11                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_12                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_13                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_14                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_15                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_16                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_17                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_18                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_19                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CMF_20                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL 
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTSHP
ADD CONSTRAINT MWIPLOTSHP_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MWIPLOTSPL : Lot Split History Table */
/* Mother와 Child의 이력을 모두 기록 */
CREATE TABLE MWIPLOTSPL
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
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTSPL
ADD CONSTRAINT MWIPLOTSPL_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MWIPLOTMRG : Lot Merge History Table */
/* Mother와 Child의 이력을 모두 기록 */
CREATE TABLE MWIPLOTMRG
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
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTMRG
ADD CONSTRAINT MWIPLOTMRG_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MWIPLOTCMB : Lot Combine History Table */
/* Mother와 Child의 이력을 모두 기록 */
CREATE TABLE MWIPLOTCMB
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
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTCMB
ADD CONSTRAINT MWIPLOTCMB_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MWIPLOTRWK : Lot Rework History Table */
CREATE TABLE MWIPLOTRWK
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
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTRWK
ADD CONSTRAINT MWIPLOTRWK_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MWIPREPDEF : Repair Operation Definition Table */
CREATE TABLE MWIPREPDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Repair Oper */
    REP_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Repair ReturnOper */
    RET_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPREPDEF
ADD CONSTRAINT MWIPREPDEF_PK PRIMARY KEY
(
    FACTORY,
    OPER,
    REP_OPER
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPLOTREP : Lot Repair History Table */
CREATE TABLE MWIPLOTREP
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Transaction Time - Backdate 가능 */
    REPAIR_TRAN_TIME            VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Repair End Time */
    REPAIR_END_TRAN_TIME        VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Delete Info. */
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Repair End History Sequence */
    REPAIR_END_HIST_SEQ         NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Factory */
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
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
    /* Repair Quantity 1 ~ 3 */
    IN_QTY_1                    NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    IN_QTY_2                    NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    IN_QTY_3                    NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Repair End Quantity 1 ~ 3 */
    OUT_QTY_1                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OUT_QTY_2                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OUT_QTY_3                   NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* CMF 1~20(Repair CMF) */
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
    /* CMF 1~20(Repair End CMF) */
    END_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    END_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    END_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    END_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    END_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    END_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    END_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    END_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    END_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    END_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    END_CMF_11                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    END_CMF_12                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    END_CMF_13                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    END_CMF_14                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    END_CMF_15                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    END_CMF_16                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    END_CMF_17                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    END_CMF_18                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    END_CMF_19                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    END_CMF_20                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Repair Info. */
    REPAIR_OPER                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    REPAIR_RES_ID               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    REPAIR_CODE_1               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    REPAIR_CODE_2               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    REPAIR_CODE_3               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* LOT의 Repair 누적 횟수 */
    REPAIR_COUNT                NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* REPAIR후 돌아올 공정 */
    REPAIR_RET_OPER             VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Repair Comment */
    REPAIR_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    REPAIR_COMMENT              VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* 결과 Code */
    RESULT_CODE_1               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RESULT_CODE_2               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RESULT_CODE_3               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* 조치 Code */
    ACTION_CODE_1               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    ACTION_CODE_2               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    ACTION_CODE_3               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Action User ID/Time/Comment  */
    ACTION_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    ACTION_USER_COMMENT         VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    USER_ID_1                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_TIME_1                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    USER_COMMENT_1              VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    USER_ID_2                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_TIME_2                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    USER_COMMENT_2              VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    USER_ID_3                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USER_TIME_3                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    USER_COMMENT_3              VARCHAR2(400)    DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTREP
ADD CONSTRAINT MWIPLOTREP_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;




/* Add by J.S. 2005.2.23 */
/* 2007.11.23. Modify by Aiden */
/* 2009.07.27. Modify by Aiden */
/* MWIPFATDEF : Future Action MFO and Point Definition */
CREATE TABLE MWIPFATDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Flow, Oper */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* I : Oper In, A : Oper At, O : Oper Out */
    OPER_POINT                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* B : Before, A : After */
    BA_POINT                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* 1 : MFO, 2 : FO, 3 : O, 4 : MO */
    OPT_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* YYYYMMDDHHMMSS+SEQ(3) */
    POINT_KEY                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPFATDEF
ADD CONSTRAINT MWIPFATDEF_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    OPER,
    OPER_POINT,
    BA_POINT
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

CREATE INDEX MWIPFATDEF_IDX_1 ON MWIPFATDEF
(
    POINT_KEY
) TABLESPACE MESPLUS_IDX_TS;

/* MWIPFATACT : Action Definition by Point Key */
CREATE TABLE MWIPFATACT
(
    POINT_KEY                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* POINT_KEY+SEQ(3) */
    ACTION_KEY                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_CODE                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* 1 : Just positive action, 2 : Action with True or False */
    /* 3 : To Flow/Oper with True or False, 4 : By Operation Count with True or False */
    ACTION_TYPE                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Y : Skip service, other : process service */
    SKIP_SERVICE                CHAR(1)          DEFAULT(' ')    NOT NULL,
    DATA_1                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_2                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_3                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_4                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_5                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_6                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_7                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_8                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_9                      VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_10                     VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_11                     VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_12                     VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_13                     VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_14                     VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_15                     VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_16                     VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_17                     VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_18                     VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_19                     VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    DATA_20                     VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
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
    TRAN_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Dependent action key */
    DEPENDENT_ACTION_KEY        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LONG_DATA_1                 VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    LONG_DATA_2                 VARCHAR2(1000)   DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPFATACT
ADD CONSTRAINT MWIPFATACT_PK PRIMARY KEY
(
    POINT_KEY,
    ACTION_KEY
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MWIPFATSVC : Apply Service by Action Key */
CREATE TABLE MWIPFATSVC
(
    ACTION_KEY                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SERVICE_NAME                VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPFATSVC
ADD CONSTRAINT MWIPFATSVC_PK PRIMARY KEY
(
    ACTION_KEY,
    SERVICE_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MWIPFATCND : Condition by Action Key */
CREATE TABLE MWIPFATCND
(
    ACTION_KEY                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
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

ALTER TABLE MWIPFATCND
ADD CONSTRAINT MWIPFATCND_PK PRIMARY KEY
(
    ACTION_KEY,
    SEQ_NO
) USING INDEX TABLESPACE MESPLUS_IDX_TS;




/* MWIPMHDSTS: MULTI HOLD 지원 */
CREATE TABLE MWIPMHDSTS
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HOLD_CODE                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    HOLD_PASSWORD               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Release 권한을 가지는 권한 그룹 */
    HOLD_PRV_GRP_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    LAST_TRAN_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPMHDSTS
ADD CONSTRAINT MWIPMHDSTS_PK PRIMARY KEY
(
    LOT_ID,
    HOLD_CODE
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPQTMDEF : Que time definition table */
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
    UPPER_WARN_QUE_TIME         NUMBER(10)       DEFAULT (0)     NOT NULL,
    LOWER_WARN_QUE_TIME         NUMBER(10)       DEFAULT (0)     NOT NULL,
    WARN_ALARM_ID               VARCHAR2(20)     DEFAULT (' ')   NOT NULL,
    /* MIN */
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
    /* Create/Update Info. */
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
    FLOW,
    FLOW_SEQ_NUM,
    OPER,
    FROM_FACTORY,
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


/* MWIPQTMHIS : Queue time history table */
CREATE TABLE MWIPQTMHIS
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* 진행될 공정 */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FROM_FACTORY                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FROM_FLOW                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FROM_FLOW_SEQ_NUM           NUMBER(6)        DEFAULT(0)      NOT NULL,
    FROM_OPER                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FROM_POINT_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHECK_POINT_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* W: Warning, E: Error */
    PROCESS_LEVEL               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* 현재 공정 */
    CUR_FLOW                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CUR_FLOW_SEQ_NUM            NUMBER(6)        DEFAULT(0)      NOT NULL,
    CUR_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    QUE_TIME                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    ALARM_ID                    VARCHAR2(20)     DEFAULT (' ')   NOT NULL,
    MSG                         VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    USER_GRP_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Over queue time */
    UPPER_QUE_TIME              NUMBER(10)       DEFAULT (0)     NOT NULL,
    LOWER_QUE_TIME              NUMBER(10)       DEFAULT (0)     NOT NULL,
    DIFF_QUE_TIME               NUMBER(10)       DEFAULT (0)     NOT NULL,
    /* Error시 발생한 TR */
    TRAN_CODE                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    /* Hold code,rework code .. */
    REASON_CODE                 VARCHAR2(10)     DEFAULT (' ')   NOT NULL,
    HOLD_PASSWORD               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Release 권한을 가지는 권한 그룹 */
    HOLD_PRV_GRP_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_TO_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_TO_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,
    TRAN_TO_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RET_FLOW                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RET_FLOW_SEQ_NUM            NUMBER(6)        DEFAULT(0)      NOT NULL,
    RET_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RWK_RET_CLEAR_FLAG          CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* lot transaction cmf */
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
    LOT_COMMENT                 VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
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


CREATE TABLE MWIPLOTMVH
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    TRAN_CODE                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Flow, Oper */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    START_TIME                  VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    END_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OPER_IN_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    QUEUE_TIME                  NUMBER(10)       DEFAULT(0)      NOT NULL,
    PROC_TIME                   NUMBER(10)       DEFAULT(0)      NOT NULL,
    TOTAL_TIME                  NUMBER(10)       DEFAULT(0)      NOT NULL
) TABLESPACE HISTORY_DATA_TS;
ALTER TABLE MWIPLOTMVH
ADD CONSTRAINT MWIPLOTMVH_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MWIPLOTMVH_IDX_1 ON MWIPLOTMVH
(
    LOT_ID,
    HIST_DEL_FLAG,
    OPER
) TABLESPACE HISTORY_IDX_TS;

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


CREATE TABLE MWIPSLTMVH
(
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    TRAN_CODE                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    START_TIME                  VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    END_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    OPER_IN_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    QUEUE_TIME                  NUMBER(10)       DEFAULT(0)      NOT NULL,
    PROC_TIME                   NUMBER(10)       DEFAULT(0)      NOT NULL,
    TOTAL_TIME                  NUMBER(10)       DEFAULT(0)      NOT NULL
) TABLESPACE HISTORY_DATA_TS;
ALTER TABLE MWIPSLTMVH
ADD CONSTRAINT MWIPSLTMVH_PK PRIMARY KEY
(
    SUBLOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MWIPSLTMVH_IDX_1 ON MWIPSLTMVH
(
    SUBLOT_ID,
    HIST_DEL_FLAG,
    OPER
) TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MWIPSLTMVH_IDX_2 ON MWIPSLTMVH
(
    LOT_ID,
    HIST_DEL_FLAG,
    OPER
) TABLESPACE HISTORY_IDX_TS;

/* MWIPLOTQTM : Lot Queue Time Information */
CREATE TABLE MWIPLOTQTM
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
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
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTQTM
ADD CONSTRAINT MWIPLOTQTM_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    FROM_FACTORY,
    FROM_FLOW,
    FROM_FLOW_SEQ_NUM,
    FROM_OPER
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MWIPLOTQTM_IDX_1 ON MWIPLOTQTM
(
    LOT_ID,
    FROM_FACTORY,
    FROM_FLOW,
    FROM_FLOW_SEQ_NUM,
    FROM_OPER,
    OPER
) TABLESPACE HISTORY_IDX_TS;

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


/* Add by J.S. */
/* MWIPBAKDEF : Batch Keep Define Table */
CREATE TABLE MWIPBAKDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Y: 일경우 공정 이동시 BATCH를 해체하지 않는다 */
    BATCH_KEEP_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* lot transaction cmf */
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

ALTER TABLE MWIPBAKDEF
ADD CONSTRAINT MWIPBAKDEF_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    OPER
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPRMASTS : RMA(Return Lot) Status Table */
CREATE TABLE MWIPRMASTS
(
    /* Factory */
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Work Date - YYYYMMDD */
    WORK_DATE                   CHAR(8)          DEFAULT(' ')    NOT NULL,
    /* Lot ID */
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Quantity */
    QTY                         NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Lot History Exist Flag - 'Y':Exit, 'N':Not Exist */
    HIST_EXIST_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* RMA Status - OPEN/CLOSE */
    RMA_STATUS                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* CMF 1~20 */
    RMA_CMF_1                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RMA_CMF_2                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RMA_CMF_3                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RMA_CMF_4                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RMA_CMF_5                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RMA_CMF_6                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RMA_CMF_7                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RMA_CMF_8                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RMA_CMF_9                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RMA_CMF_10                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RMA_CMF_11                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RMA_CMF_12                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RMA_CMF_13                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RMA_CMF_14                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RMA_CMF_15                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RMA_CMF_16                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RMA_CMF_17                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RMA_CMF_18                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RMA_CMF_19                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RMA_CMF_20                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* CMF 1~20 */
    RESULT_CMF_1                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESULT_CMF_2                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESULT_CMF_3                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESULT_CMF_4                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESULT_CMF_5                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESULT_CMF_6                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESULT_CMF_7                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESULT_CMF_8                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESULT_CMF_9                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESULT_CMF_10               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESULT_CMF_11               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESULT_CMF_12               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESULT_CMF_13               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESULT_CMF_14               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESULT_CMF_15               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESULT_CMF_16               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESULT_CMF_17               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESULT_CMF_18               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESULT_CMF_19               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESULT_CMF_20               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /** Create Info. **/
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    CREATE_CODE                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_COMMENT              VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /** Result Info. **/
    RESULT_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    RESULT_CODE                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RESULT_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RESULT_COMMENT              VARCHAR2(400)    DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPRMASTS
ADD CONSTRAINT MWIPRMASTS_PK PRIMARY KEY
(
    FACTORY,
    WORK_DATE,
    LOT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* JJS */
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
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Flow, Oper */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
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
    HOLD_PRV_GRP_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Oper In Quantity 2 ~ 3 */
    OPER_IN_QTY_2               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OPER_IN_QTY_3               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Create Qty 1~3 */
    CREATE_QTY_2                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CREATE_QTY_3                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Start Quantity 2 ~ 3 */
    START_QTY_2                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    START_QTY_3                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Inventory Operation에 들어 있음. MOVE 불가능 */
    INV_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* RECEIVING 대기 */
    TRANSIT_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Unit Exist Flag */
    UNIT_EXIST_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,  /* Add For V42 tracking flag 대치*/
    /* Inventory Unit */
    INV_UNIT                    VARCHAR2(10)     DEFAULT(0.0)    NOT NULL,
    /* Rework Info. */
    RWK_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    RWK_CODE                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* LOT의 Rework 누적 횟수 */
    RWK_COUNT                   NUMBER(6)        DEFAULT(0)      NOT NULL,
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
    RWK_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Non Standard Info. */
    NSTD_FLAG                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    NSTD_RET_FLOW               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    NSTD_RET_FLOW_SEQ_NUM       NUMBER(6)        DEFAULT(0)      NOT NULL,
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
    LAST_HIST_SEQ               NUMBER(10)       DEFAULT(0)      NOT NULL,
    SUBLOT_TYPE                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FIELD_1                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_2                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_3                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_4                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_5                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FLAG_1                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_2                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_3                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_4                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_5                 CHAR(1)          DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

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
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
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
    HOLD_PRV_GRP_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER_IN_QTY_2               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OPER_IN_QTY_3               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CREATE_QTY_2                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CREATE_QTY_3                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Start Quantity 1 ~ 3 */
    START_QTY_2                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    START_QTY_3                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    INV_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    TRANSIT_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Unit Exist Flag */
    UNIT_EXIST_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,  /* Add For V42 tracking flag 대치*/
    INV_UNIT                    VARCHAR2(10)     DEFAULT(0.0)    NOT NULL,
    RWK_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    RWK_CODE                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RWK_COUNT                   NUMBER(6)        DEFAULT(0)      NOT NULL,
    RWK_RET_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RWK_RET_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,
    RWK_RET_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RWK_END_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RWK_END_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,
    RWK_END_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RWK_RET_CLEAR_FLAG          CHAR(1)          DEFAULT(' ')    NOT NULL,
    RWK_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    NSTD_FLAG                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    NSTD_RET_FLOW               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    NSTD_RET_FLOW_SEQ_NUM       NUMBER(6)        DEFAULT(0)      NOT NULL,
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
    OLD_MAT_VER                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    OLD_FLOW                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OLD_FLOW_SEQ_NUM            NUMBER(6)        DEFAULT(0)      NOT NULL,
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
    TRAN_CMF_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    PREV_ACTIVE_HIST_SEQ        NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* - Multi Transaction을 한번에 삭제할 경우 */
    MULTI_TR_KEY                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 HIST_START_SEQ 대치*/
    MULTI_TR_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* For additional extended table */
    EXT_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,  /* Add For V5 */
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    HIST_DEL_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_COMMENT            VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    SUBLOT_TYPE                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FIELD_1                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_2                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_3                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_4                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_5                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FLAG_1                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_2                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_3                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_4                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_5                 CHAR(1)          DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

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

CREATE INDEX MWIPSLTHIS_IDX_3 ON MWIPSLTHIS
(
    LOT_ID,
    LOT_HIST_SEQ,
    HIST_DEL_FLAG,
    TRAN_CODE
) TABLESPACE HISTORY_IDX_TS;


/* MWIPLOTBAT : Lot Batch History Table */
CREATE TABLE MWIPLOTBAT
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    TRAN_CODE                   VARCHAR2(12)     DEFAULT(' ')    NOT NULL,
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
    /* Resource ID */
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    BATCH_ID                    VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    BATCH_SEQ                   NUMBER(3)        DEFAULT(0)      NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTBAT
ADD CONSTRAINT MWIPLOTBAT_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MWIPLOTBAT_IDX_1 ON MWIPLOTBAT
(
    FACTORY,
    TRAN_TIME,
    BATCH_ID
) TABLESPACE HISTORY_IDX_TS;


/* MWIPLOTDFT :Lot Defect Data Table */
CREATE TABLE MWIPLOTDFT
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Sequence Number */
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    DEFECT_CODE                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    DEFECT_QTY                  NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    /* LOT 내 CELL의 위치 정보 */
    CELL_X                      NUMBER(10)       DEFAULT(0)      NOT NULL,
    CELL_Y                      NUMBER(10)       DEFAULT(0)      NOT NULL,
    CELL_Z                      NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* DEFECT가 발생한 정확한 절대 위치 정보 */
    LOC_X                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    LOC_Y                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    LOC_Z                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    SYS_TRAN_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Clean 된경우 */
    CLEAN_FLAG                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    CLEAN_HIST_SEQ              NUMBER(10)       DEFAULT(0)      NOT NULL,
    CLEAN_USER_ID               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CLEAN_TIME                  VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Lot 정보 */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* 원인 Flow, 공정, 장비 */
    CAUSE_FLOW                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CAUSE_OPER                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CAUSE_RES_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CAUSE_SUBRES_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Defect Data 수집 요청자 */
    CHK_USER_ID_1               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHK_USER_ID_2               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Attach File Name */
    ATTACH_FILE_1               VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    ATTACH_FILE_2               VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    ATTACH_FILE_3               VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    ATTACH_FILE_4               VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    ATTACH_FILE_5               VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    DEFECT_COMMENT              VARCHAR2(400)    DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTDFT
ADD CONSTRAINT MWIPLOTDFT_PK PRIMARY KEY
(
    LOT_ID,
    SUBLOT_ID,
    HIST_SEQ,
    SEQ_NUM
) USING INDEX TABLESPACE HISTORY_IDX_TS;

/* MWIPGRDDEF : Grade Rule Table */
CREATE TABLE MWIPGRDDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT (' ')   NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT (' ')   NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT (' ')   NOT NULL,
    GRADE                       VARCHAR2(10)     DEFAULT (' ')   NOT NULL,
    RULE_TYPE                   CHAR(1)          DEFAULT (' ')   NOT NULL,
    SPEC_M                      NUMBER(6)        DEFAULT (0),
    CHECK_GRADE1                VARCHAR2(10)     DEFAULT (' ')   NOT NULL,
    COMP1                       VARCHAR2(2)      DEFAULT (' ')   NOT NULL,
    VALUE1                      NUMBER(6)        DEFAULT (0),
    AND_OR                      VARCHAR2(3)      DEFAULT (' ')   NOT NULL,
    CHECK_GRADE2                VARCHAR2(10)     DEFAULT (' ')   NOT NULL,
    COMP2                       VARCHAR2(2)      DEFAULT (' ')   NOT NULL,
    VALUE2                      NUMBER(6)        DEFAULT (0),
    CELL_COUNT_VT               NUMBER(6)        DEFAULT (0),
    CELL_COUNT_HR               NUMBER(6)        DEFAULT (0),
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPGRDDEF
ADD CONSTRAINT MWIPGRDDEF_PK PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    OPER,
    GRADE
) USING INDEX TABLESPACE MESPLUS_IDX_TS;



/* Add For V42 */
/* MWIPMFODEF : Material Flow Operation Option Definition Table */
CREATE TABLE MWIPMFODEF
(
  FACTORY                       VARCHAR2(10)     DEFAULT (' ')      NOT NULL,
  OPTION_NAME                   VARCHAR2(20)     DEFAULT (' ')      NOT NULL,
  OPTION_DESC                   VARCHAR2(200)    DEFAULT (' ')      NOT NULL,
  OPTION_SEQ                    NUMBER(6)        DEFAULT (0)        NOT NULL,
  REL_LEVEL                     CHAR(1)          DEFAULT (' ')      NOT NULL,
  MAT_ID                        VARCHAR2(30)     DEFAULT (' ')      NOT NULL,
  MAT_VER                       NUMBER(6)        DEFAULT (0)        NOT NULL,
  FLOW                          VARCHAR2(20)     DEFAULT (' ')      NOT NULL,
  OPER                          VARCHAR2(10)     DEFAULT (' ')      NOT NULL,
  RES_ID                        VARCHAR2(20)     DEFAULT (' ')      NOT NULL,
  RESG_ID                       VARCHAR2(20)     DEFAULT (' ')      NOT NULL,
  RES_TYPE                      VARCHAR2(20)     DEFAULT (' ')      NOT NULL,
  KEY_1                         VARCHAR2(30)     DEFAULT (' ')      NOT NULL,
  KEY_2                         VARCHAR2(30)     DEFAULT (' ')      NOT NULL,
  KEY_3                         VARCHAR2(30)     DEFAULT (' ')      NOT NULL,
  KEY_4                         VARCHAR2(30)     DEFAULT (' ')      NOT NULL,
  KEY_5                         VARCHAR2(30)     DEFAULT (' ')      NOT NULL,
  DATA_1                        VARCHAR2(50)     DEFAULT (' ')      NOT NULL,
  DATA_2                        VARCHAR2(50)     DEFAULT (' ')      NOT NULL,
  DATA_3                        VARCHAR2(50)     DEFAULT (' ')      NOT NULL,
  DATA_4                        VARCHAR2(50)     DEFAULT (' ')      NOT NULL,
  DATA_5                        VARCHAR2(50)     DEFAULT (' ')      NOT NULL,
  DATA_6                        VARCHAR2(50)     DEFAULT (' ')      NOT NULL,
  DATA_7                        VARCHAR2(50)     DEFAULT (' ')      NOT NULL,
  DATA_8                        VARCHAR2(50)     DEFAULT (' ')      NOT NULL,
  DATA_9                        VARCHAR2(50)     DEFAULT (' ')      NOT NULL,
  DATA_10                       VARCHAR2(50)     DEFAULT (' ')      NOT NULL,
  DATA_11                       VARCHAR2(50)     DEFAULT (' ')      NOT NULL,
  DATA_12                       VARCHAR2(50)     DEFAULT (' ')      NOT NULL,
  DATA_13                       VARCHAR2(50)     DEFAULT (' ')      NOT NULL,
  DATA_14                       VARCHAR2(50)     DEFAULT (' ')      NOT NULL,
  DATA_15                       VARCHAR2(50)     DEFAULT (' ')      NOT NULL,
  DATA_16                       VARCHAR2(50)     DEFAULT (' ')      NOT NULL,
  DATA_17                       VARCHAR2(50)     DEFAULT (' ')      NOT NULL,
  DATA_18                       VARCHAR2(50)     DEFAULT (' ')      NOT NULL,
  DATA_19                       VARCHAR2(50)     DEFAULT (' ')      NOT NULL,
  DATA_20                       VARCHAR2(50)     DEFAULT (' ')      NOT NULL,
  CREATE_USER_ID                VARCHAR2(20)     DEFAULT (' ')      NOT NULL,
  CREATE_TIME                   VARCHAR2(14)     DEFAULT (' ')      NOT NULL,
  UPDATE_USER_ID                VARCHAR2(20)     DEFAULT (' ')      NOT NULL,
  UPDATE_TIME                   VARCHAR2(14)     DEFAULT (' ')      NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPMFODEF
ADD CONSTRAINT MWIPMFODEF_PK PRIMARY KEY
(
    FACTORY,
    OPTION_NAME,
    OPTION_SEQ,
    REL_LEVEL,
    MAT_ID,
    MAT_VER,
    FLOW,
    OPER,
    RES_ID,
    RESG_ID,
    RES_TYPE
) USING INDEX TABLESPACE MESPLUS_IDX_TS;



/* Add For V42 */
/* MWIPMFOPMT : MFO Option Prompt Table */
CREATE TABLE MWIPMFOPMT
(
  FACTORY         VARCHAR2(10)             DEFAULT (' ')                 NOT NULL,
  OPTION_NAME     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  OPTION_DESC     VARCHAR2(200)            DEFAULT (' ')                 NOT NULL,
    /* System pre defined prompt Flag - Y:System prompt, _:User prompt */
  SYS_PMT_FLAG    CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  KEY_PMT_1       VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  KEY_PMT_2       VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  KEY_PMT_3       VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  KEY_PMT_4       VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  KEY_PMT_5       VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  KEY_OPT_1       CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  KEY_OPT_2       CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  KEY_OPT_3       CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  KEY_OPT_4       CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  KEY_OPT_5       CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  KEY_FMT_1       CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  KEY_FMT_2       CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  KEY_FMT_3       CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  KEY_FMT_4       CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  KEY_FMT_5       CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  KEY_TBL_1       VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  KEY_TBL_2       VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  KEY_TBL_3       VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  KEY_TBL_4       VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  KEY_TBL_5       VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_PMT_1      VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_PMT_2      VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_PMT_3      VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_PMT_4      VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_PMT_5      VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_PMT_6      VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_PMT_7      VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_PMT_8      VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_PMT_9      VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_PMT_10     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_PMT_11     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_PMT_12     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_PMT_13     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_PMT_14     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_PMT_15     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_PMT_16     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_PMT_17     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_PMT_18     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_PMT_19     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_PMT_20     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_OPT_1      CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_OPT_2      CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_OPT_3      CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_OPT_4      CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_OPT_5      CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_OPT_6      CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_OPT_7      CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_OPT_8      CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_OPT_9      CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_OPT_10     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_OPT_11     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_OPT_12     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_OPT_13     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_OPT_14     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_OPT_15     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_OPT_16     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_OPT_17     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_OPT_18     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_OPT_19     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_OPT_20     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_FMT_1      CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_FMT_2      CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_FMT_3      CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_FMT_4      CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_FMT_5      CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_FMT_6      CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_FMT_7      CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_FMT_8      CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_FMT_9      CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_FMT_10     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_FMT_11     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_FMT_12     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_FMT_13     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_FMT_14     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_FMT_15     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_FMT_16     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_FMT_17     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_FMT_18     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_FMT_19     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_FMT_20     CHAR(1)                  DEFAULT (' ')                 NOT NULL,
  DATA_TBL_1      VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_TBL_2      VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_TBL_3      VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_TBL_4      VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_TBL_5      VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_TBL_6      VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_TBL_7      VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_TBL_8      VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_TBL_9      VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_TBL_10     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_TBL_11     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_TBL_12     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_TBL_13     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_TBL_14     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_TBL_15     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_TBL_16     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_TBL_17     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_TBL_18     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_TBL_19     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  DATA_TBL_20     VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  CREATE_USER_ID  VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  CREATE_TIME     VARCHAR2(14)             DEFAULT (' ')                 NOT NULL,
  UPDATE_USER_ID  VARCHAR2(20)             DEFAULT (' ')                 NOT NULL,
  UPDATE_TIME     VARCHAR2(14)             DEFAULT (' ')                 NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPMFOPMT
ADD CONSTRAINT MWIPMFOPMT_PK PRIMARY KEY
(
    FACTORY,
    OPTION_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MWIPSLTLOS : History of Sub Lot multi Loss Definition Table */
CREATE TABLE MWIPSLTLOS
(
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    LOT_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    QTY_FLAG                    CHAR(1)          DEFAULT('1')    NOT NULL,
    GRADE                       CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOSS_CODE                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
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
    LOSS_QTY                    NUMBER(10,3)     DEFAULT(0.0)    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPSLTLOS
ADD CONSTRAINT MWIPSLTLOS_PK PRIMARY KEY
(
    SUBLOT_ID,
    LOT_ID,
    HIST_SEQ,
    QTY_FLAG,
    LOSS_CODE
) USING INDEX TABLESPACE HISTORY_IDX_TS;

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


/* MWIPLOTYLD : Lot Yield History Table */
CREATE TABLE MWIPLOTYLD
(
  LOT_ID                VARCHAR2(25)     DEFAULT (' ')   NOT NULL,
  HIST_SEQ              NUMBER(10)       DEFAULT (0)     NOT NULL,
  TRAN_TIME             VARCHAR2(14)     DEFAULT (' ')   NOT NULL,
  SYS_TRAN_TIME         VARCHAR2(14)     DEFAULT (' ')   NOT NULL,
  FACTORY               VARCHAR2(10)     DEFAULT (' ')   NOT NULL,
  MAT_ID                VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
  MAT_VER               NUMBER(6)        DEFAULT (0)     NOT NULL,
  FLOW                  VARCHAR2(20)     DEFAULT (' ')   NOT NULL,
  FLOW_SEQ_NUM          NUMBER(6)        DEFAULT (0)     NOT NULL,
  OPER                  VARCHAR2(10)     DEFAULT (' ')   NOT NULL,
  QTY_1                 NUMBER(10,3)     DEFAULT (0.0)   NOT NULL,
  QTY_2                 NUMBER(10,3)     DEFAULT (0.0)   NOT NULL,
  QTY_3                 NUMBER(10,3)     DEFAULT (0.0)   NOT NULL,
  SECTION_IN_QTY_1      NUMBER(10,3)     DEFAULT (0.0)   NOT NULL,
  SECTION_IN_QTY_2      NUMBER(10,3)     DEFAULT (0.0)   NOT NULL,
  SECTION_IN_QTY_3      NUMBER(10,3)     DEFAULT (0.0)   NOT NULL,
  WORKCELL_IN_QTY_1     NUMBER(10,3)     DEFAULT (0.0)   NOT NULL,
  WORKCELL_IN_QTY_2     NUMBER(10,3)     DEFAULT (0.0)   NOT NULL,
  WORKCELL_IN_QTY_3     NUMBER(10,3)     DEFAULT (0.0)   NOT NULL,
  LINE_IN_QTY_1         NUMBER(10,3)     DEFAULT (0.0)   NOT NULL,
  LINE_IN_QTY_2         NUMBER(10,3)     DEFAULT (0.0)   NOT NULL,
  LINE_IN_QTY_3         NUMBER(10,3)     DEFAULT (0.0)   NOT NULL,
  SECTION_ID            VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
  WORKCELL_ID           VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
  LINE_ID               VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
  RESV_FIELD_1          VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
  RESV_FIELD_2          VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
  RESV_FIELD_3          VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
  RESV_FIELD_4          VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
  RESV_FIELD_5          VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
  RESV_FLAG_1           CHAR(1)          DEFAULT (' ')   NOT NULL,
  RESV_FLAG_2           CHAR(1)          DEFAULT (' ')   NOT NULL,
  RESV_FLAG_3           CHAR(1)          DEFAULT (' ')   NOT NULL,
  RESV_FLAG_4           CHAR(1)          DEFAULT (' ')   NOT NULL,
  RESV_FLAG_5           CHAR(1)          DEFAULT (' ')   NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPLOTYLD
ADD CONSTRAINT MWIPLOTYLD_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* Add by J.S. 2009.03.05 for Remote Shipping */
/* MWIPRSHLOT : Remote Shipping Lot Table */
CREATE TABLE MWIPRSHLOT
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Transaction Time - Backdate 가능 */
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    FACTORY_TO                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FACTORY_FROM                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TRANSIT_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CRR_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPRSHLOT
ADD CONSTRAINT MWIPRSHLOT_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

/* MWIPLOTCVH : Lot Count Variance History Table */
CREATE TABLE MWIPLOTCVH
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
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
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
    /* New Quantity */
    NEW_QTY                     NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Old Quantity */
    OLD_QTY                     NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Total Loss Qty */
    TOTAL_CV_QTY                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Loss Comment */
    CV_COMMENT_1                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    CV_COMMENT_2                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    CV_COMMENT_3                VARCHAR2(400)    DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTCVH
ADD CONSTRAINT MWIPLOTCVH_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    QTY_FLAG
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MWIPLOTCVM : Lot Count Variance History(Multiple Record) Table */
CREATE TABLE MWIPLOTCVM
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
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Resource ID */
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Sequence Number */
    SEQ_NUM                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Loss Code/Qty */
    CV_CODE                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CV_QTY                      NUMBER(10,3)     DEFAULT(0.0)    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTCVM
ADD CONSTRAINT MWIPLOTCVM_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    QTY_FLAG,
    SEQ_NUM
) USING INDEX TABLESPACE HISTORY_IDX_TS;

/* MWIPLOTRDS : Lot Rework Depth Status Table */
CREATE TABLE MWIPLOTRDS
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Rework Complete Flag */
    /* C : Normal Complete, A : Abnormal Complete */
    COMPLETE_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    COMPLETE_HIST_SEQ           NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* REWORK 공정 */
    RWK_FLOW                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RWK_FLOW_SEQ_NUM            NUMBER(6)        DEFAULT(0)      NOT NULL,
    RWK_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RWK_STOP_OPER               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Rework Info. */
    RWK_DEPTH                   NUMBER(6)        DEFAULT(0)      NOT NULL,
    RWK_CODE                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RWK_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    RWK_START_HIST_SEQ          NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* REWORK을 보낸 공정 */
    FROM_FLOW                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FROM_FLOW_SEQ_NUM           NUMBER(6)        DEFAULT(0)      NOT NULL,
    FROM_OPER                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* REWORK후 돌아올 공정 */
    RET_FLOW                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RET_FLOW_SEQ_NUM            NUMBER(6)        DEFAULT(0)      NOT NULL,
    RET_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Return Option Flag */
    /* ' ':Keep Rework, 'Y':Clear Rework */
    /* 'A':Clear Rework and Move to Next Operation */
    /* 'B':Keep Rework and Move to Next Operation */
    RET_CLEAR_FLAG              CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOCAL_REWORK_FLAG           CHAR(1)          DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPLOTRDS
ADD CONSTRAINT MWIPLOTRDS_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* MWIPSLTRDS : SubLot Rework Depth Status Table */
CREATE TABLE MWIPSLTRDS
(
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Rework Complete Flag */
    /* C : Normal Complete, A : Abnormal Complete */
    COMPLETE_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    COMPLETE_HIST_SEQ           NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* REWORK 공정 */
    RWK_FLOW                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RWK_FLOW_SEQ_NUM            NUMBER(6)        DEFAULT(0)      NOT NULL,
    RWK_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RWK_STOP_OPER               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Rework Info. */
    RWK_DEPTH                   NUMBER(6)        DEFAULT(0)      NOT NULL,
    RWK_CODE                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RWK_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    RWK_START_HIST_SEQ          NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* REWORK을 보낸 공정 */
    FROM_FLOW                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FROM_FLOW_SEQ_NUM           NUMBER(6)        DEFAULT(0)      NOT NULL,
    FROM_OPER                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* REWORK후 돌아올 공정 */
    RET_FLOW                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RET_FLOW_SEQ_NUM            NUMBER(6)        DEFAULT(0)      NOT NULL,
    RET_OPER                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Return Option Flag */
    /* ' ':Keep Rework, 'Y':Clear Rework */
    /* 'A':Clear Rework and Move to Next Operation */
    /* 'B':Keep Rework and Move to Next Operation */
    RET_CLEAR_FLAG              CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOCAL_REWORK_FLAG           CHAR(1)          DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPSLTRDS
ADD CONSTRAINT MWIPSLTRDS_PK PRIMARY KEY
(
    SUBLOT_ID,
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


/* Add by Simon Kim 2010.01.10 */
/* MWIPSTPDEF : Step definition Table */
CREATE TABLE MWIPSTPDEF
(
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    STEP                     VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    STEP_DESC                VARCHAR2(200)   DEFAULT (' ')    NOT NULL,
    STEP_GRP_1               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_GRP_2               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_GRP_3               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_GRP_4               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_GRP_5               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_GRP_6               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_GRP_7               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_GRP_8               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_GRP_9               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_GRP_10              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_CMF_1               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_CMF_2               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_CMF_3               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_CMF_4               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_CMF_5               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_CMF_6               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_CMF_7               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_CMF_8               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_CMF_9               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_CMF_10              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_CMF_11              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_CMF_12              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_CMF_13              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_CMF_14              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_CMF_15              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_CMF_16              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_CMF_17              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_CMF_18              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_CMF_19              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    STEP_CMF_20              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    CREATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;


ALTER TABLE MWIPSTPDEF ADD (
  CONSTRAINT MWIPSTPDEF_PK
 PRIMARY KEY
 (FACTORY, STEP) USING INDEX TABLESPACE MESPLUS_IDX_TS);

/* Add by Simon Kim 2010.01.10 */
/* MWIPSTPMFO : Step MFO Relationship information Table */
CREATE TABLE MWIPSTPMFO
(
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    MAT_ID                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    MAT_VER                  NUMBER(6)       DEFAULT (0)      NOT NULL,
    FLOW                     VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    OPER                     VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    STEP                     VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    CREATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    REL_LEVEL                CHAR(1)         DEFAULT (' ')    NOT NULL,
    SEQ_NUM                  NUMBER(6)       DEFAULT (0)      NOT NULL,
    PREV_STEP                VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    NEXT_STEP                VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    AUTO_START_FLAG          CHAR(1)         DEFAULT (' ')    NOT NULL,
    AUTO_END_FLAG            CHAR(1)         DEFAULT (' ')    NOT NULL,
    START_REQ_FLAG           CHAR(1)         DEFAULT (' ')    NOT NULL,
    END_REQ_FLAG             CHAR(1)         DEFAULT (' ')    NOT NULL,
    SERIAL_PROC_FLAG         CHAR(1)         DEFAULT (' ')    NOT NULL,
    RESV_FIELD_1             VARCHAR2(50)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_2             VARCHAR2(50)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_3             VARCHAR2(50)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_4             VARCHAR2(50)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_5             VARCHAR2(50)    DEFAULT (' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPSTPMFO ADD (
  CONSTRAINT MWIPSTPMFO_PK
 PRIMARY KEY
 (FACTORY, MAT_ID, MAT_VER, FLOW, OPER, STEP) USING INDEX TABLESPACE MESPLUS_IDX_TS);


/* Add by Simon Kim 2010.01.10 */
/* MWIPSTPSTS : Step Status information Table */
CREATE TABLE MWIPSTPSTS
(
    LOT_ID                   VARCHAR2(25)    DEFAULT (' ')    NOT NULL,
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    MAT_ID                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    MAT_VER                  NUMBER(6)       DEFAULT (0)      NOT NULL,
    FLOW                     VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    FLOW_SEQ_NUM             NUMBER(6)       DEFAULT (0)      NOT NULL,
    OPER                     VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    STEP                     VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    START_FLAG               CHAR(1)         DEFAULT (' ')    NOT NULL,
    END_FLAG                 CHAR(1)         DEFAULT (' ')    NOT NULL,
    LAST_TRAN_CODE           VARCHAR2(12)    DEFAULT (' ')    NOT NULL,
    LAST_TRAN_TIME           VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    LAST_TRAN_COMMENT        VARCHAR2(400)   DEFAULT (' ')    NOT NULL,
    LAST_ACTIVE_HIST_SEQ     NUMBER(10)      DEFAULT (0)      NOT NULL,
    LAST_HIST_SEQ            NUMBER(10)      DEFAULT (0)      NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPSTPSTS ADD (
  CONSTRAINT MWIPSTPSTS_PK
 PRIMARY KEY
 (LOT_ID) USING INDEX TABLESPACE MESPLUS_IDX_TS);


/* Add by Simon Kim 2010.01.10 */
/* MWIPSTPHIS : Step History information Table */
CREATE TABLE MWIPSTPHIS
(
    LOT_ID                   VARCHAR2(25)    DEFAULT (' ')    NOT NULL,
    HIST_SEQ                 NUMBER(10)      DEFAULT (0)      NOT NULL,
    TRAN_CMF_1               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_CMF_2               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_CMF_3               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_CMF_4               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_CMF_5               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_CMF_6               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_CMF_7               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_CMF_8               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_CMF_9               VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_CMF_10              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_CMF_11              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_CMF_12              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_CMF_13              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_CMF_14              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_CMF_15              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_CMF_16              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_CMF_17              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_CMF_18              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_CMF_19              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_CMF_20              VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    TRAN_TIME                VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    SYS_TRAN_TIME            VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    TRAN_CODE                VARCHAR2(12)    DEFAULT (' ')    NOT NULL,
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    MAT_ID                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    MAT_VER                  NUMBER(6)       DEFAULT (0)      NOT NULL,
    FLOW                     VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    FLOW_SEQ_NUM             NUMBER(6)       DEFAULT (0)      NOT NULL,
    OPER                     VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    STEP                     VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    START_FLAG               CHAR(1)         DEFAULT (' ')    NOT NULL,
    END_FLAG                 CHAR(1)         DEFAULT (' ')    NOT NULL,
    LOT_HIST_SEQ             NUMBER(10)      DEFAULT (0)      NOT NULL,
    OPER_TRAN_FLAG           CHAR(1)         DEFAULT (' ')    NOT NULL,
    TRAN_USER_ID             VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    TRAN_COMMENT             VARCHAR2(400)   DEFAULT (' ')    NOT NULL,
    HIST_DEL_FLAG            CHAR(1)         DEFAULT (' ')    NOT NULL,
    HIST_DEL_TIME            VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    HIST_DEL_USER_ID         VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    HIST_DEL_COMMENT         VARCHAR2(400)   DEFAULT (' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPSTPHIS ADD (
  CONSTRAINT MWIPSTPHIS_PK
 PRIMARY KEY
 (LOT_ID, HIST_SEQ) USING INDEX TABLESPACE HISTORY_IDX_TS);


/* MWIPTOLLTH : Lot and Tool History Relation Table */
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


/* MWIPOPRIV : Input Operation Value List Table */
CREATE TABLE MWIPOPRINV
(
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    REL_LEVEL                CHAR(1)         DEFAULT (' ')    NOT NULL,
    MAT_ID                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    MAT_VER                  NUMBER(6)       DEFAULT (0)      NOT NULL,
    FLOW                     VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    OPER                     VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    POINT_TYPE               CHAR(1)         DEFAULT (' ')    NOT NULL,
    SEQ                      NUMBER(6)       DEFAULT (0)      NOT NULL,
    VALUE_TYPE               CHAR(1)         DEFAULT (' ')    NOT NULL,
    DATA_1                   VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_2                   VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_3                   VARCHAR2(100)   DEFAULT (' ')    NOT NULL,
    DATA_4                   VARCHAR2(4000)  DEFAULT (' ')    NOT NULL,
    DATA_5                   VARCHAR2(4000)  DEFAULT (' ')    NOT NULL,
    DISPLAY_TYPE             CHAR(1)         DEFAULT (' ')    NOT NULL,
    INPUT_TYPE               CHAR(1)         DEFAULT (' ')    NOT NULL,
    REQUIRE_FLAG             CHAR(1)         DEFAULT (' ')    NOT NULL,
    BACK_COLOR               NUMBER(10)      DEFAULT (0)      NOT NULL,
    INPUT_VALUE_TYPE         VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    CMF_1                    VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CMF_2                    VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CMF_3                    VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CMF_4                    VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CMF_5                    VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CMF_6                    VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CMF_7                    VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CMF_8                    VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CMF_9                    VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CMF_10                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CMF_11                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CMF_12                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CMF_13                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CMF_14                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CMF_15                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CMF_16                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CMF_17                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CMF_18                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CMF_19                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CMF_20                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    CREATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPOPRINV ADD (
  CONSTRAINT MWIPOPRINV_PK
 PRIMARY KEY
 (FACTORY, REL_LEVEL, MAT_ID, MAT_VER, FLOW, OPER, POINT_TYPE, SEQ) USING INDEX TABLESPACE MESPLUS_IDX_TS);


/* MWIPIDGDEF : Rule ID Definition Table */
CREATE TABLE MWIPIDGDEF
(
    RULE_ID                     VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RULE_DESC                   VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    GEN_TYPE                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    SAVE_POINT                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    FULFILL_SEQ                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Create/Update Info. */
    APPROVAL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    NOT_USED_ID_SEARCH_OPTION   CHAR(1)          DEFAULT(' ')    NOT NULL
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
    DATA_3                      VARCHAR2(2000)   DEFAULT(' ')    NOT NULL,
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
    SEQ_KEY_1                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
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

/* MWIPIDGSKV : Sequence Rule History Table */
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
    /* Create/Update Info. */
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

/* MWIPIDGHIS : Gen ID History Table */
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
    /* Create/Update Info. */
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

/* Add by J.S. 2011.11.14 */
CREATE INDEX MWIPIDGHIS_IDX_1 ON MWIPIDGHIS
(GEN_ID, CONFIRM_KEY) TABLESPACE HISTORY_IDX_TS;


/* MWIPIDGSCF : Confirm Gen ID of Sequence Rule */
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




/* Batch Management */
/* MWIPBATRUL - Creation Batch Rule */
CREATE TABLE MWIPBATRUL
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CRT_RULE_ID                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CRT_RULE_DESC               VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
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
    /* Add 2009.01.25 */
    CUSTOM_RULE                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CUSTOM_RULE_FOR_CHECK       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SEND_LOT_TO_CUSTOM_RULE_FLAG CHAR(1)         DEFAULT(' ')    NOT NULL,
    MAX_SEND_LOT_COUNT          NUMBER(6)        DEFAULT(0)      NOT NULL,
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

/* MWIPBATREL - Relation of Creation Batch Rule */
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

/* MWIPBATRSV - Reservation Batch */
CREATE TABLE MWIPBATRSV
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
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
    FLOW_SEQ_NUM,
    OPER,
    RES_TYPE,
    RESG_ID,
    RES_ID,
    RECIPE,
    RSV_BATCH_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

CREATE UNIQUE INDEX MWIPBATRSV_IDX_1 ON MWIPBATRSV
(
        FACTORY,
        RSV_BATCH_ID
) TABLESPACE MESPLUS_IDX_TS;

/* MWIPBATRIT - Reserved Batch Items */
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


/* MWIPBATHIS - Batch Definition History */

CREATE TABLE MWIPBATHIS
(
    FACTORY                  VARCHAR2(10)    DEFAULT(' ')    NOT NULL,
    BATCH_ID                 VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    TRAN_TIME                VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    TRAN_CODE                VARCHAR2(12)    DEFAULT(' ')    NOT NULL,
    ITEM_ID                  VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    SEQ_NUM                  NUMBER(6)       DEFAULT(0)      NOT NULL,
    ITEM_HIST_SEQ            NUMBER(10)      DEFAULT(0)      NOT NULL,
    ITEM_TYPE                CHAR(1)         DEFAULT(' ')    NOT NULL,
    OPER                     VARCHAR2(10)    DEFAULT(' ')    NOT NULL,
    REL_LEVEL                CHAR(1)         DEFAULT(' ')    NOT NULL,
    RES_ID                   VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    RESG_ID                  VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    RES_TYPE                 VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    CRT_RULE_ID              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    GEN_RULE_ID              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    CONFIRM_FLAG             CHAR(1)         DEFAULT(' ')    NOT NULL,
    BATCH_COMMENT            VARCHAR2(200)   DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPBATHIS
ADD CONSTRAINT MWIPBATHIS_PK PRIMARY KEY
(
    FACTORY,
    BATCH_ID,
    TRAN_TIME,
    TRAN_CODE,
    SEQ_NUM
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE TABLE MWIPBATDEF
(
    FACTORY                  VARCHAR2(10)    DEFAULT(' ')    NOT NULL,
    BATCH_ID                 VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    ITEM_ID                  VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    SEQ_NUM                  NUMBER(6)       DEFAULT(0)      NOT NULL,
    ITEM_TYPE                CHAR(1)         DEFAULT(' ')    NOT NULL,
    OPER                     VARCHAR2(10)    DEFAULT(' ')    NOT NULL,
    REL_LEVEL                CHAR(1)         DEFAULT(' ')    NOT NULL,
    RES_ID                   VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    RESG_ID                  VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    RES_TYPE                 VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    CRT_RULE_ID              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    GEN_RULE_ID              VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    CREATE_TIME              VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT(' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT(' ')    NOT NULL,
    CONFIRM_FLAG             CHAR(1)         DEFAULT(' ')    NOT NULL,
    BATCH_COMMENT            VARCHAR2(200)   DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPBATDEF
ADD CONSTRAINT MWIPBATDEF_PK PRIMARY KEY
(
    FACTORY,
    BATCH_ID,
    ITEM_ID,
    SEQ_NUM
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

CREATE UNIQUE INDEX MWIPBATDEF_IDX_1 ON MWIPBATDEF
(FACTORY, BATCH_ID, SEQ_NUM) TABLESPACE MESPLUS_IDX_TS;

CREATE INDEX MWIPBATDEF_IDX_2 ON MWIPBATDEF
(FACTORY, ITEM_TYPE, ITEM_ID) TABLESPACE MESPLUS_IDX_TS;



CREATE TABLE MWIPELTSTS
(
    LOT_ID                  VARCHAR2(25)    DEFAULT(' ')        NOT NULL,
    HIST_SEQ                NUMBER(10)      DEFAULT(0)          NOT NULL
)TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPELTSTS ADD (
CONSTRAINT MWIPELTSTS_PK
PRIMARY KEY
(
    LOT_ID
)USING INDEX TABLESPACE MESPLUS_IDX_TS);


CREATE TABLE MWIPELTHIS
(
    LOT_ID                  VARCHAR2(25)    DEFAULT(' ')        NOT NULL,
    HIST_SEQ                NUMBER(10)      DEFAULT(0)          NOT NULL
)TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPELTHIS ADD (
CONSTRAINT MWIPELTHIS_PK
PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ
)USING INDEX TABLESPACE HISTORY_IDX_TS);

/* MWIPTSTPGM : Test Program Definition */
CREATE TABLE MWIPTSTPGM
(
    CREATE_USER_ID           VARCHAR2(20)    DEFAULT(' ')     NOT NULL,
    CREATE_TIME              VARCHAR2(14)    DEFAULT(' ')     NOT NULL,
    UPDATE_USER_ID           VARCHAR2(20)    DEFAULT(' ')     NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT(' ')     NOT NULL,
    FACTORY                  VARCHAR2(10)    DEFAULT(' ')     NOT NULL,
    REL_LEVEL                CHAR(1)         DEFAULT(' ')     NOT NULL,
    MAT_ID                   VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    MAT_VER                  NUMBER(6)       DEFAULT(0)       NOT NULL,
    FLOW                     VARCHAR2(20)    DEFAULT(' ')     NOT NULL,
    FLOW_SEQ_NUM             NUMBER(6)       DEFAULT(0)       NOT NULL,
    OPER                     VARCHAR2(10)    DEFAULT(' ')     NOT NULL,
    RES_ID                   VARCHAR2(20)    DEFAULT(' ')     NOT NULL,
    RESG_ID                  VARCHAR2(20)    DEFAULT(' ')     NOT NULL,
    RES_TYPE                 VARCHAR2(20)    DEFAULT(' ')     NOT NULL,
    /* Lot Customized Field Definition */
    LOT_CMF_1                VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    LOT_CMF_2                VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    LOT_CMF_3                VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    LOT_CMF_4                VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    LOT_CMF_5                VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    LOT_CMF_6                VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    LOT_CMF_7                VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    LOT_CMF_8                VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    LOT_CMF_9                VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    LOT_CMF_10               VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    /* Resource Group */
    RES_GRP_1                VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    RES_GRP_2                VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    RES_GRP_3                VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    RES_GRP_4                VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    RES_GRP_5                VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    RES_GRP_6                VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    RES_GRP_7                VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    RES_GRP_8                VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    RES_GRP_9                VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    RES_GRP_10               VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    TEST_VERSION             NUMBER(6)       DEFAULT(0)       NOT NULL,
    TEST_PGM_NAME            VARCHAR2(60)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_VER             VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    DESCRIPTION              VARCHAR2(200)   DEFAULT(' ')     NOT NULL,
    TEST_TIME                VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    INDEX_TIME               VARCHAR2(10)    DEFAULT(' ')     NOT NULL,
    TEST_TEMP                VARCHAR2(10)    DEFAULT(' ')     NOT NULL,
    PROGRAM_DIR              VARCHAR2(200)   DEFAULT(' ')     NOT NULL,
    /* Apply Start/End Time */
    APPLY_START_TIME         VARCHAR2(14)    DEFAULT(' ')     NOT NULL,
    APPLY_END_TIME           VARCHAR2(14)    DEFAULT(' ')     NOT NULL,
    /* Approval Info. */
    APPROVAL_FLAG            CHAR(1)         DEFAULT(' ')     NOT NULL,
    APPROVAL_USER_ID         VARCHAR2(20)    DEFAULT(' ')     NOT NULL,
    APPROVAL_TIME            VARCHAR2(14)    DEFAULT(' ')     NOT NULL,
    /* Release Info.*/
    RELEASE_FLAG             CHAR(1)         DEFAULT(' ')     NOT NULL,
    RELEASE_USER_ID          VARCHAR2(20)    DEFAULT(' ')     NOT NULL,
    RELEASE_TIME             VARCHAR2(14)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_CMF_1           VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_CMF_2           VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_CMF_3           VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_CMF_4           VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_CMF_5           VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_CMF_6           VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_CMF_7           VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_CMF_8           VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_CMF_9           VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_CMF_10          VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_CMF_11          VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_CMF_12          VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_CMF_13          VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_CMF_14          VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_CMF_15          VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_CMF_16          VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_CMF_17          VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_CMF_18          VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_CMF_19          VARCHAR2(30)    DEFAULT(' ')     NOT NULL,
    TEST_PGM_CMF_20          VARCHAR2(30)    DEFAULT(' ')     NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPTSTPGM ADD
CONSTRAINT MWIPTSTPGM_PK PRIMARY KEY
(
    FACTORY     ,
    REL_LEVEL   ,
    MAT_ID      ,
    MAT_VER     ,
    FLOW        ,
    FLOW_SEQ_NUM,
    OPER        ,
    RES_ID      ,
    RESG_ID     ,
    RES_TYPE    ,
    LOT_CMF_1   ,
    LOT_CMF_2   ,
    LOT_CMF_3   ,
    LOT_CMF_4   ,
    LOT_CMF_5   ,
    LOT_CMF_6   ,
    LOT_CMF_7   ,
    LOT_CMF_8   ,
    LOT_CMF_9   ,
    LOT_CMF_10  ,
    RES_GRP_1   ,
    RES_GRP_2   ,
    RES_GRP_3   ,
    RES_GRP_4   ,
    RES_GRP_5   ,
    RES_GRP_6   ,
    RES_GRP_7   ,
    RES_GRP_8   ,
    RES_GRP_9   ,
    RES_GRP_10  ,
    TEST_VERSION
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

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
    MAT_VER                 NUMBER(6)           DEFAULT(0)      NOT NULL,
    FLOW                    VARCHAR2(20)        DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM            NUMBER(6)           DEFAULT(0)      NOT NULL,
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
    CV_TYPE           		VARCHAR2(10 )       DEFAULT(' ')    NOT NULL,
    UNIT                    VARCHAR2(10)        DEFAULT(' ')    NOT NULL,
    UNIT_TYPE               VARCHAR2(10)        DEFAULT(' ')    NOT NULL,
    AQL_TYPE                VARCHAR2(10)        DEFAULT(' ')    NOT NULL,
    YIELD_BASE              VARCHAR2(20)        DEFAULT(' ')    NOT NULL,
    BASE_OPER               VARCHAR2(10)        DEFAULT(' ')    NOT NULL,
    BASE_COLUMN       		VARCHAR2(30 )       DEFAULT(' ')    NOT NULL,
    CHECK_TYPE              VARCHAR2(10)        DEFAULT(' ')    NOT NULL,
    TOT_UPPER_YIELD         NUMBER(10,3)        DEFAULT(0)      NOT NULL,
    TOT_LOWER_YIELD         NUMBER(10,3)        DEFAULT(0)      NOT NULL,
    ALARM_ID                VARCHAR2(20)        DEFAULT(' ')    NOT NULL,
    PROTECT_END_FLAG        CHAR(1)             DEFAULT(' ')    NOT NULL,
    DESCRIPTION       		VARCHAR2(200 )      DEFAULT(' ')    NOT NULL,
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



/* MWIPBINDEF : BIN Definition Table */
CREATE TABLE MWIPBINDEF
(
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BIN_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_DESC                    VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    BIN_DEF_GRP_1               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_DEF_GRP_2               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_DEF_GRP_3               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_DEF_GRP_4               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_DEF_GRP_5               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_DEF_GRP_6               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_DEF_GRP_7               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_DEF_GRP_8               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_DEF_GRP_9               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_DEF_GRP_10              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_DEF_CMF_1               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_DEF_CMF_2               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_DEF_CMF_3               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_DEF_CMF_4               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_DEF_CMF_5               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_DEF_CMF_6               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_DEF_CMF_7               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_DEF_CMF_8               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_DEF_CMF_9               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_DEF_CMF_10              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    APPROVAL_REQUIRE_FLAG       CHAR(1)          DEFAULT(' ')    NOT NULL,
    APPROVAL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DELETE_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    DELETE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    DELETE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPBINDEF
ADD CONSTRAINT MWIPBINDEF_PK PRIMARY KEY
(
    FACTORY,
    BIN_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MWIPBINVER : BIN Version Definition Table */
CREATE TABLE MWIPBINVER
(
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BIN_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_VERSION                 NUMBER(5)        DEFAULT(0)      NOT NULL,
    APPLY_START_TIME            VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    APPLY_END_TIME              VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    APPROVAL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    APPROVAL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    APPROVAL_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    RELEASE_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    RELEASE_USER_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RELEASE_TIME                VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPBINVER
ADD CONSTRAINT MWIPBINVER_PK PRIMARY KEY
(
    FACTORY,
    BIN_ID,
    BIN_VERSION
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MWIPBINUNT : BIN Unit Definition Table */
CREATE TABLE MWIPBINUNT
(
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BIN_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_VERSION                 NUMBER(5)        DEFAULT(0)      NOT NULL,
    BIN_UNIT                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_DESC               VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    TOT_SPLIT_FLAG              CHAR(1)          DEFAULT(' ')    NOT NULL,
    YIELD_CALC_TYPE             CHAR(1)          DEFAULT(' ')    NOT NULL,
    YIELD_BASE                  VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    YIELD_BASE_OPER             VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    UPPER_LIMIT                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    LOWER_LIMIT                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    ALARM_ID                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    USE_SPEC_LIMIT_FLAG         CHAR(1)          DEFAULT(' ')    NOT NULL,
    USE_SPEC_CHAR_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_CMF_1              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_CMF_2              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_CMF_3              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_CMF_4              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_CMF_5              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_CMF_6              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_CMF_7              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_CMF_8              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_CMF_9              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_CMF_10             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_CMF_11             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_CMF_12             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_CMF_13             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_CMF_14             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_CMF_15             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_CMF_16             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_CMF_17             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_CMF_18             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_CMF_19             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT_CMF_20             VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPBINUNT
ADD CONSTRAINT MWIPBINUNT_PK PRIMARY KEY
(
    FACTORY,
    BIN_ID,
    BIN_VERSION,
    BIN_UNIT
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MWIPBINGRD : BIN Grade Definition Table */
CREATE TABLE MWIPBINGRD
(
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BIN_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_VERSION                 NUMBER(5)        DEFAULT(0)      NOT NULL,
    BIN_UNIT                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BIN_SEQ                     NUMBER(3)        DEFAULT(0)      NOT NULL,
    BIN_PROMPT                  VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_PROMPT_DESC             VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    BIN_TYPE                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOGICAL_BIN_FLAG            CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEEP_LOT_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    SPLIT_LOT_ID_RULE           VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    SPLIT_BY_BIN_SEQ            NUMBER(3)        DEFAULT(0)      NOT NULL,
    USE_BIN_PROMPT_FAIL_REASON  CHAR(1)          DEFAULT(' ')    NOT NULL,
    KEEP_LOT_QTY_FAIL           CHAR(1)          DEFAULT(' ')    NOT NULL,
    FAIL_REASON_CODE            VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    REASON_CODE_REF_OPER        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHANGE_MAT_ID               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CHANGE_MAT_VER              NUMBER(6)        DEFAULT(0)      NOT NULL,
    CHANGE_FLOW                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CHANGE_FLOW_SEQ_NUM         NUMBER(6)        DEFAULT(0)      NOT NULL,
    CHANGE_OPER                 VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHANGE_LOT_TYPE             CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHANGE_LOT_PRIORITY         CHAR(1)          DEFAULT(' ')    NOT NULL,
    CHANGE_CREATE_CODE          VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHANGE_OWNER_CODE           VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    CHANGE_CRR_GROUP            VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CODE                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_KEY_REF_OPER           VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TRAN_KEY_CODE_1             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_KEY_CODE_2             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_KEY_CODE_3             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_TO_MAT_ID              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_TO_MAT_VER             NUMBER(6)        DEFAULT(0)      NOT NULL,
    TRAN_TO_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_TO_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,
    TRAN_TO_OPER                VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TRAN_STOP_OPER              VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TRAN_RET_FLOW               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_RET_FLOW_SEQ_NUM       NUMBER(6)        DEFAULT(0)      NOT NULL,
    TRAN_RET_OPER               VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TRAN_RET_OPTION             VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    TG_TRAN_CODE                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TG_TRAN_KEY_REF_OPER        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TG_TRAN_KEY_CODE_1          VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TG_TRAN_KEY_CODE_2          VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TG_TRAN_KEY_CODE_3          VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TG_TRAN_TO_MAT_ID           VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TG_TRAN_TO_MAT_VER          NUMBER(6)        DEFAULT(0)      NOT NULL,
    TG_TRAN_TO_FLOW             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TG_TRAN_TO_FLOW_SEQ_NUM     NUMBER(6)        DEFAULT(0)      NOT NULL,
    TG_TRAN_TO_OPER             VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TG_TRAN_STOP_OPER           VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TG_TRAN_RET_FLOW            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TG_TRAN_RET_FLOW_SEQ_NUM    NUMBER(6)        DEFAULT(0)      NOT NULL,
    TG_TRAN_RET_OPER            VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TG_TRAN_RET_OPTION          VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TG_TRAN_COMMENT             VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    PY_PERIOD                   NUMBER(2)        DEFAULT(0)      NOT NULL,
    PY_UPPER_LIMIT              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PY_LOWER_LIMIT              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    PY_ALARM_ID                 VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PY_USE_SPEC_LIMIT_FLAG      CHAR(1)          DEFAULT(' ')    NOT NULL,
    PY_USE_SPEC_CHAR_ID         VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    BIN_GRADE_CMF_1             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_GRADE_CMF_2             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_GRADE_CMF_3             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_GRADE_CMF_4             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_GRADE_CMF_5             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_GRADE_CMF_6             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_GRADE_CMF_7             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_GRADE_CMF_8             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_GRADE_CMF_9             VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_GRADE_CMF_10            VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_GRADE_CMF_11            VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_GRADE_CMF_12            VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_GRADE_CMF_13            VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_GRADE_CMF_14            VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_GRADE_CMF_15            VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_GRADE_CMF_16            VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_GRADE_CMF_17            VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_GRADE_CMF_18            VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_GRADE_CMF_19            VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_GRADE_CMF_20            VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPBINGRD
ADD CONSTRAINT MWIPBINGRD_PK PRIMARY KEY
(
    FACTORY,
    BIN_ID,
    BIN_VERSION,
    BIN_UNIT,
    BIN_SEQ
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MWIPBINREL : BIN Definition Relation Table */
CREATE TABLE MWIPBINREL
(
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* '1': MFO, '2': FO, '3': O, '4': MO, 'T': Resource Type, 'G': Resource Group, 'R': Resource */
    REL_LEVEL                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RESG_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
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
    BIN_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_UNIT                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    COL_OTHER_UNIT_FLAG         CHAR(1)          DEFAULT(' ')    NOT NULL,
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
    RESV_FIELD_11               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_12               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_13               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_14               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_15               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_16               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_17               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_18               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_19               VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_20               VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPBINREL
ADD CONSTRAINT MWIPBINREL_PK PRIMARY KEY
(
    FACTORY,REL_LEVEL,MAT_ID,MAT_VER,FLOW,OPER,RES_TYPE,RESG_ID,RES_ID,
    LOT_CMF_1,LOT_CMF_2,LOT_CMF_3,LOT_CMF_4,LOT_CMF_5,LOT_CMF_6,LOT_CMF_7,LOT_CMF_8,LOT_CMF_9,LOT_CMF_10,
    LOT_CMF_11,LOT_CMF_12,LOT_CMF_13,LOT_CMF_14,LOT_CMF_15,LOT_CMF_16,LOT_CMF_17,LOT_CMF_18,LOT_CMF_19,LOT_CMF_20,
    BIN_ID,BIN_UNIT
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MWIPBINHIS : BIN Data Collection History Table */
CREATE TABLE MWIPBINHIS
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    BIN_COL_SEQ                 NUMBER(5)        DEFAULT(0)      NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BIN_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_VERSION                 NUMBER(5)        DEFAULT(0)      NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    SYS_TRAN_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RESG_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    QTY_1                       NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    BIN_UNIT                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    COL_BASE_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    TOT_INPUT_QTY               NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    TOT_PASS_QTY                NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    TOT_FAIL_QTY                NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    TOT_YIELD_BASE_QTY          NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    TOT_YIELD                   NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    YIELD_CALC_TYPE             CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOW_YIELD_FLAG              CHAR(1)          DEFAULT(' ')    NOT NULL,
    BASE_UYL                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BASE_LYL                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_ALARM_ID               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* BIN 에 대한 코멘트 */
    BIN_COMMENT_1               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    BIN_COMMENT_2               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    BIN_COMMENT_3               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* Collect BIN 에 대한 트렌젝션 코멘트 */
    TRAN_COMMENT_1              VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT_2              VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT_3              VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
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
    TRAN_CMF_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
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
    HIST_DEL_COMMENT            VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* BIN Grade 를 포함한 모든 Low Yield 에 대해 Pass 하였는지 남긴다. */
    /* BIN Grade 에서 Low Yield 라 하더라도 Low Yield Action 이 없다면 Pass 로 판단한다. */
    /* P - Pass, F - Fail */
    BIN_RESULT_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MWIPBINHIS
ADD CONSTRAINT MWIPBINHIS_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    BIN_COL_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

/* MWIPBINSHS : BIN Data Collection History by BIN Sequence */
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
    /* BIN 에 대한 코멘트 */
    BIN_COMMENT_1               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    BIN_COMMENT_2               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    BIN_COMMENT_3               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* Collect BIN 에 대한 트렌젝션 코멘트 */
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

/* MWIPBINHSS : BIN Data Collection History by Sublot */
CREATE TABLE MWIPBINHSS
(
    SUBLOT_ID                   VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    BIN_COL_SEQ                 NUMBER(5)        DEFAULT(0)      NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BIN_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_VERSION                 NUMBER(5)        DEFAULT(0)      NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    SYS_TRAN_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOT_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RESG_ID                     VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    BIN_UNIT                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TOT_INPUT_QTY               NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    TOT_PASS_QTY                NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    TOT_FAIL_QTY                NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    TOT_YIELD_BASE_QTY          NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    TOT_YIELD                   NUMBER(10,3)     DEFAULT(0)      NOT NULL,
    YIELD_CALC_TYPE             CHAR(1)          DEFAULT(' ')    NOT NULL,
    LOW_YIELD_FLAG              CHAR(1)          DEFAULT(' ')    NOT NULL,
    BASE_UYL                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BASE_LYL                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_ALARM_ID               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* BIN 에 대한 코멘트 */
    BIN_COMMENT_1               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    BIN_COMMENT_2               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    BIN_COMMENT_3               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* Collect BIN 에 대한 트렌젝션 코멘트 */
    TRAN_COMMENT_1              VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT_2              VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT_3              VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
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
    TRAN_CMF_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
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

ALTER TABLE MWIPBINHSS
ADD CONSTRAINT MWIPBINHSS_PK PRIMARY KEY
(
    SUBLOT_ID,
    HIST_SEQ,
    BIN_COL_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

CREATE INDEX MWIPBINHSS_IDX_1 ON MWIPBINHSS
(
    LOT_ID,
    LOT_HIST_SEQ,
    HIST_DEL_FLAG,
    BIN_COL_SEQ,
    SUBLOT_ID,
    HIST_SEQ
) TABLESPACE HISTORY_IDX_TS;


/* MWIPBINSSH : BIN Data Collection History by BIN Sequence by Sublot */
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
    /* BIN 에 대한 코멘트 */
    BIN_COMMENT_1               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    BIN_COMMENT_2               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    BIN_COMMENT_3               VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* Collect BIN 에 대한 트렌젝션 코멘트 */
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

/* MWIPBINFML : BIN Grade Formula Definition Table */
CREATE TABLE MWIPBINFML
(
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BIN_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    BIN_VERSION                 NUMBER(5)        DEFAULT(0)      NOT NULL,
    BIN_UNIT                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    BIN_SEQ                     NUMBER(3)        DEFAULT(0)      NOT NULL,
    /* Formula Type: 'G' - BIN Sequence Formula, 'T' - Sublot BIN Sequence Total Formula */
    FML_TYPE                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    SEQ_NO                      NUMBER(6)        DEFAULT(0)      NOT NULL,
    AND_OR                      VARCHAR2(3)      DEFAULT(' ')    NOT NULL,
    L_BRACKET                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    FORMULA                     VARCHAR2(4000)   DEFAULT(' ')    NOT NULL,
    OPERATOR                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    TARGET_VALUE                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    R_BRACKET                   VARCHAR2(10)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPBINFML
ADD CONSTRAINT MWIPBINFML_PK PRIMARY KEY
(
    FACTORY,
    BIN_ID,
    BIN_VERSION,
    BIN_UNIT,
    BIN_SEQ,
    FML_TYPE,
    SEQ_NO
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MWIPPRIDEF : Priority Control Table */
CREATE TABLE MWIPPRIDEF
(
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    PRI_TYPE                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    PRIORITY                    NUMBER(3)        DEFAULT(0)      NOT NULL,
    PRI_DESC                    VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    CHECK_ITEM                  VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    RESV_FIELD_1                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_2                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_3                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_4                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_5                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_6                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_7                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_8                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_9                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_10               VARCHAR2(30)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MWIPPRIDEF
ADD CONSTRAINT MWIPPRIDEF_PK PRIMARY KEY
(
    FACTORY,
    PRI_TYPE,
    PRIORITY
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

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
    LOT_DESC                    VARCHAR2(200)    DEFAULT(' ')    NOT NULL,
    /* Current Factory */
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Material ID */
    MAT_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MAT_VER                     NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Flow, Oper */
    FLOW                        VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FLOW_SEQ_NUM                NUMBER(6)        DEFAULT(0)      NOT NULL,
    OPER                        VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* Quantity 1 ~ 3 */
    QTY_1                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_2                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    QTY_3                       NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* 캐리어 ID */
    CRR_ID                      VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
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
    HOLD_PRV_GRP_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* Oper In Quantity 1 ~ 3 */
    OPER_IN_QTY_1               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OPER_IN_QTY_2               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    OPER_IN_QTY_3               NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Create Qty 1~3 */
    CREATE_QTY_1                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CREATE_QTY_2                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    CREATE_QTY_3                NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Start Quantity 1 ~ 3 */
    START_QTY_1                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    START_QTY_2                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    START_QTY_3                 NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,
    /* Inventory Operation에 들어 있음. MOVE 불가능 */
    INV_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* RECEIVING 대기 */
    TRANSIT_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Unit Exist Flag */
    UNIT_EXIST_FLAG             CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Inventory Unit */
    INV_UNIT                    VARCHAR2(10)     DEFAULT(0.0)    NOT NULL,
    /* Rework Info. */
    RWK_FLAG                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    RWK_CODE                    VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    /* LOT의 Rework 누적 횟수 */
    RWK_COUNT                   NUMBER(6)        DEFAULT(0)      NOT NULL,
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
    RWK_TIME                    VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    /* Non Standard Move Info. */
    NSTD_FLAG                   CHAR(1)          DEFAULT(' ')    NOT NULL,
    NSTD_RET_FLOW               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    NSTD_RET_FLOW_SEQ_NUM       NUMBER(6)        DEFAULT(0)      NOT NULL,
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
    FROM_TO_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL,
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
    CRITICAL_RES_ID             VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    /* 크리티칼 레이어의 장비 그룹을 사용할 경우 경우를 대비 */
    CRITICAL_RES_GROUP_ID       VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SAVE_RES_ID_1               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SAVE_RES_ID_2               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SUBRES_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LOT_GROUP_ID_1              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOT_GROUP_ID_2              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    LOT_GROUP_ID_3              VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    /* Lot Yield Info. */
    YIELD_1                     NUMBER(20,10)    DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    YIELD_2                     NUMBER(20,10)    DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    YIELD_3                     NUMBER(20,10)    DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    GOOD_QTY                    NUMBER(10,3)     DEFAULT(0.0)    NOT NULL,  /* Add For V5 */
    RESV_FIELD_1                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_2                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_3                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_4                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FIELD_5                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    RESV_FLAG_1                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_2                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_3                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_4                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    RESV_FLAG_5                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    /******** Mod For V42 Status  *********/
    FROM_TO_MAT_ID              VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FROM_TO_MAT_VER             NUMBER(6)        DEFAULT(0)      NOT NULL,
    FROM_TO_FLOW                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    FROM_TO_FLOW_SEQ_NUM        NUMBER(6)        DEFAULT(0)      NOT NULL,
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
    OLD_MAT_VER                 NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Flow, Oper */
    OLD_FLOW                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    OLD_FLOW_SEQ_NUM            NUMBER(6)        DEFAULT(0)      NOT NULL,
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
    OLD_CRR_ID                  VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
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
    TRAN_CMF_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Transaction User ID/Comment */
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    /* Previous Active History Sequence */
    PREV_ACTIVE_HIST_SEQ        NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* History Block Number(Requested by Fred) */
    /* - Multi Transaction을 한번에 삭제할 경우 */
    MULTI_TR_KEY                VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    MULTI_TR_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,
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
    /* CUSTOMIZED FIELD FOR EVENT */
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
    TRAN_CMF_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
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
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MTMPRESHIS
ADD CONSTRAINT MTMPRESHIS_PK PRIMARY KEY
(
    TABLE_UPDATE_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;


CREATE TABLE MTMPELTHIS
(
    TABLE_UPDATE_SEQ        NUMBER(12)      DEFAULT(0)          NOT NULL,
    CM_KEY_1                VARCHAR2(30)    DEFAULT(' ')        NOT NULL,
    CM_KEY_2                VARCHAR2(30)    DEFAULT(' ')        NOT NULL,
    CM_KEY_3                VARCHAR2(30)    DEFAULT(' ')        NOT NULL,
    CM_KEY_4                VARCHAR2(30)    DEFAULT(' ')        NOT NULL,
    CM_KEY_5                VARCHAR2(30)    DEFAULT(' ')        NOT NULL,
    LOT_ID                  VARCHAR2(25)    DEFAULT(' ')        NOT NULL,
    HIST_SEQ                NUMBER(10)      DEFAULT(0)          NOT NULL
)TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MTMPELTHIS ADD (
CONSTRAINT MTMPELTHIS_PK
PRIMARY KEY
(
    TABLE_UPDATE_SEQ
)USING INDEX TABLESPACE HISTORY_IDX_TS);

/*==== MES --> Report Attribute Interface Table ====*/
CREATE TABLE MTMPATRHIS
(
    TABLE_UPDATE_SEQ            NUMBER(12)      DEFAULT(0)      NOT NULL,
    CM_KEY_1                    VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CM_KEY_2                    VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CM_KEY_3                    VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CM_KEY_4                    VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    CM_KEY_5                    VARCHAR2(30)    DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)    DEFAULT (' ')   NOT NULL,
    ATTR_TYPE                   VARCHAR2(20)    DEFAULT (' ')   NOT NULL,
    ATTR_NAME                   VARCHAR2(100)   DEFAULT (' ')   NOT NULL,
    ATTR_KEY                    VARCHAR2(100)   DEFAULT (' ')   NOT NULL,
    HIST_SEQ                    NUMBER(10)      DEFAULT (0)     NOT NULL,
    ATTR_OLD_VALUE              VARCHAR2(1000)  DEFAULT (' ')   NOT NULL,
    ATTR_NEW_VALUE              VARCHAR2(1000)  DEFAULT (' ')   NOT NULL,
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
    PROCESS_FLAG                CHAR(1)         DEFAULT (' ')   NOT NULL,
	TRAN_USER_ID                VARCHAR2(20)    DEFAULT (' ')   NOT NULL
	
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MTMPATRHIS
ADD CONSTRAINT MTMPATRHIS_PK PRIMARY KEY
(
    TABLE_UPDATE_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

/*==== MES --> Report Cassette Interface Table ====*/
CREATE TABLE MTMPCRRHIS
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
    TRAN_CMF_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    TRAN_CMF_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* Transaction User ID/Comment */
    TRAN_USER_ID                VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    TRAN_COMMENT                VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    PROCESS_FLAG                CHAR(1)          DEFAULT (' ')   NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MTMPCRRHIS
ADD CONSTRAINT MTMPCRRHIS_PK PRIMARY KEY
(
    TABLE_UPDATE_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;





















/* MQCGACTDEF : Action Rule Definition */
CREATE TABLE MQCGACTDEF
(
    FACTORY                  VARCHAR2(25)    DEFAULT (' ')    NOT NULL,
    RULE_ID                  VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    RULE_DESC                VARCHAR2(50)    DEFAULT (' ')    NOT NULL,
    PASS_FLAG                VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    ALARM_CODE               VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    PROTECT_END              CHAR(1)         DEFAULT (' ')    NOT NULL,
    QA_RUL_CMF_1             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_RUL_CMF_2             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_RUL_CMF_3             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_RUL_CMF_4             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_RUL_CMF_5             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_RUL_CMF_6             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_RUL_CMF_7             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_RUL_CMF_8             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_RUL_CMF_9             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_RUL_CMF_10            VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_1             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_2             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_3             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_4             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_5             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_6             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_7             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_8             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_9             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_10            VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CREATE_USER              VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    CREATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    UPDATE_USER              VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MQCGACTDEF
ADD CONSTRAINT MQCGACTDEF_PK PRIMARY KEY
(
    FACTORY,
    RULE_ID
)USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MQCGLOTDEF : QA Lot Definition */
CREATE TABLE MQCGLOTDEF
(
    LOT_ID                   VARCHAR2(25)    DEFAULT (' ')    NOT NULL,
    HIST_SEQ                 NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    QA_HIST_SEQ              NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    TRAN_TIME                VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    MAT_ID                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    MAT_VER                  NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    FLOW                     VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    FLOW_SEQ_NUM             NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    OPER                     VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    QA_OPER                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    RES_ID                   VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    CRR_ID                   VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    QTY_1                    NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    QTY_2                    NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    QTY_3                    NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    DEF_SEQ                  NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    DEF_QTY_FLAG             CHAR(1)         DEFAULT (' ')    NOT NULL,
    DEF_CODE                 VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    DEF_QTY                  NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    YIELD                    NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    HIST_DEL_FLAG            CHAR(1)         DEFAULT (' ')    NOT NULL,
    HIST_DEL_TIME            VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    HIST_DEL_USER            VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    HIST_DEL_COMMENT         VARCHAR2(400)   DEFAULT (' ')    NOT NULL,
    RESV_FIELD_1             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_2             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_3             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_4             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_5             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_6             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_7             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_8             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_9             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_10            VARCHAR2(30)    DEFAULT (' ')    NOT NULL
)TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MQCGLOTDEF
ADD CONSTRAINT MQCGLOTDEF_PK PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    QA_HIST_SEQ,
    DEF_SEQ,
    QTY_1,
    QTY_2,
    DEF_CODE,
    DEF_QTY
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MQCGLOTHIS : QA Lot History */
CREATE TABLE MQCGLOTHIS
(
    LOT_ID                   VARCHAR2(25)    DEFAULT (' ')    NOT NULL,
    HIST_SEQ                 NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    QA_HIST_SEQ              NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    TRAN_TIME                VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    MAT_ID                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    MAT_VER                  NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    FLOW                     VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    FLOW_SEQ_NUM             NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    OPER                     VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    QA_OPER                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    RES_ID                   VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    CRR_ID                   VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    QTY_1                    NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    QTY_2                    NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    QTY_3                    NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    SMP_RULE_ID              VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    ACT_RULE_ID              VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    PASS_FLAG                VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    SMP_SIZE_1               NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    SMP_SIZE_2               NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    DEF_QTY_1                NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    DEF_QTY_2                NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    YIELD_1                  NUMBER(5,2)     DEFAULT (0)      NOT NULL,
    YIELD_2                  NUMBER(5,2)     DEFAULT (0)      NOT NULL,
    TEST_TYPE                VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    INSPECTOR                VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    SHIFT                    VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    IRRMRR                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_COMMENT               VARCHAR2(400)   DEFAULT (' ')    NOT NULL,
    ALARM_CODE               VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    HIST_DEL_FLAG            CHAR(1)         DEFAULT (' ')    NOT NULL,
    HIST_DEL_TIME            VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    HIST_DEL_USER            VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    HIST_DEL_COMMENT         VARCHAR2(400)   DEFAULT (' ')    NOT NULL,
    QA_CMF_1                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_CMF_2                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_CMF_3                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_CMF_4                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_CMF_5                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_CMF_6                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_CMF_7                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_CMF_8                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_CMF_9                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_CMF_10                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_1             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_2             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_3             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_4             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_5             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_6             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_7             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_8             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_9             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_10            VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    BACKSIDE_ISSUE_1         VARCHAR2(200)   DEFAULT (' ')    NOT NULL,
    BACKSIDE_ISSUE_2         VARCHAR2(200)   DEFAULT (' ')    NOT NULL,
    BACKSIDE_ISSUE_3         VARCHAR2(200)   DEFAULT (' ')    NOT NULL,
    BACKSIDE_ISSUE_4         VARCHAR2(200)   DEFAULT (' ')    NOT NULL,
    CP_QTY                   NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    GOOD_QTY                 NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    LOT_YIELD                NUMBER(5,2)     DEFAULT (100)    NOT NULL,
    UNION_LOT_YIELD          NUMBER(5,2)     DEFAULT (100)    NOT NULL
)TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MQCGLOTHIS ADD (
CONSTRAINT MQCGLOTHIS_PK
PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    QA_HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS);

/* MQCGMFOREL : QA MFO Relation */
CREATE TABLE MQCGMFOREL
(
    FACTORY                  VARCHAR2(25)    DEFAULT (' ')    NOT NULL,
    MAT_ID                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    MAT_VER                  NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    FLOW                     VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    FLOW_SEQ                 NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    OPER                     VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    RES_ID                   VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    SUB_RES_ID               VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    REL_TYPE                 VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    RULE_ID                  VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_1             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_2             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_3             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_4             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_5             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_6             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_7             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_8             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_9             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_10            VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_PASS_COUNT            NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    QA_SKIP_COUNT            NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    QA_FAIL_COUNT            NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    QA_TOTAL_COUNT           NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    QA_TEST_COUNT            NUMBER(6,0)     DEFAULT (0)      NOT NULL
)TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MQCGMFOREL ADD (
CONSTRAINT MQCGMFOREL_PK
PRIMARY KEY
(
    FACTORY,
    MAT_ID,
    MAT_VER,
    FLOW,
    FLOW_SEQ,
    OPER,
    RES_ID,
    SUB_RES_ID,
    REL_TYPE,
    RULE_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS);

/* MQCGSLTDEF : QA Sub Lot Definition */
CREATE TABLE MQCGSLTDEF
(
    LOT_ID                   VARCHAR2(25)    DEFAULT (' ')    NOT NULL,
    HIST_SEQ                 NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    SUBLOT_ID                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    SUB_LOT_HIST_SEQ         NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    SLOT_NO                  NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    QA_HIST_SEQ              NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    TRAN_TIME                VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    MAT_ID                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    MAT_VER                  NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    FLOW                     VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    FLOW_SEQ_NUM             NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    OPER                     VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    QA_OPER                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    RES_ID                   VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    CRR_ID                   VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    QTY_2                    NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    QTY_3                    NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    DEF_QTY_FLAG             CHAR(1)         DEFAULT (' ')    NOT NULL,
    DEF_CODE                 VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    DEF_QTY                  NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    YIELD                    NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    LOC_X                    NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    LOC_Y                    NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    LOC_Z                    NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    CELL_X                   NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    CELL_Y                   NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    CELL_Z                   NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    HIST_DEL_FLAG            CHAR(1)         DEFAULT (' ')    NOT NULL,
    HIST_DEL_TIME            VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    HIST_DEL_USER            VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    HIST_DEL_COMMENT         VARCHAR2(400)   DEFAULT (' ')    NOT NULL,
    RESV_FIELD_1             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_2             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_3             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_4             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_5             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_6             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_7             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_8             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_9             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_10            VARCHAR2(30)    DEFAULT (' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MQCGSLTDEF ADD (
CONSTRAINT MQCGSLTDEF_PK
PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    QA_HIST_SEQ,
    SUBLOT_ID,
    DEF_CODE,
    LOC_X,
    LOC_Y,
    LOC_Z,
    CELL_X,
    CELL_Y,
    CELL_Z
) USING INDEX TABLESPACE MESPLUS_IDX_TS);


/* MQCGSLTHIS : QA Sub Lot History */
CREATE TABLE MQCGSLTHIS
(
    LOT_ID                   VARCHAR2(25)    DEFAULT (' ')    NOT NULL,
    HIST_SEQ                 NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    QA_HIST_SEQ              NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    SUBLOT_ID                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    SLOT_NO                  NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    SUB_LOT_HIST_SEQ         NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    TRAN_TIME                VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    MAT_ID                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    MAT_VER                  NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    FLOW                     VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    FLOW_SEQ_NUM             NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    OPER                     VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    QA_OPER                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    RES_ID                   VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    CRR_ID                   VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    QTY_2                    NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    QTY_3                    NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    PASS_FLAG                VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    SMP_SIZE                 NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    DEF_QTY                  NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    YIELD                    NUMBER(5,2)     DEFAULT (0)      NOT NULL,
    TEST_TYPE                VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    INSPECTOR                VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    SHIFT                    VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    IRRMRR                   VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_COMMENT               VARCHAR2(400)   DEFAULT (' ')    NOT NULL,
    ALARM_CODE               VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    HIST_DEL_FLAG            CHAR(1)         DEFAULT (' ')    NOT NULL,
    HIST_DEL_TIME            VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    HIST_DEL_USER            VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    HIST_DEL_COMMENT         VARCHAR2(400)   DEFAULT (' ')    NOT NULL,
    QA_CMF_1                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_CMF_2                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_CMF_3                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_CMF_4                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_CMF_5                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_CMF_6                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_CMF_7                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_CMF_8                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_CMF_9                 VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_CMF_10                VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_1             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_2             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_3             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_4             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_5             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_6             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_7             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_8             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_9             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_10            VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CP_QTY                   NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    GOOD_QTY                 NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    IC_TOTAL_LIMIT           NUMBER(5,2)     DEFAULT (0)      NOT NULL,
    IC_OTHER_LIMIT           NUMBER(5,2)     DEFAULT (0)      NOT NULL,
    TOTAL_DEFECT_LIMIT       NUMBER(5,2)     DEFAULT (0)      NOT NULL,
    FIRST_DEFECT_LIMIT       NUMBER(5,2)     DEFAULT (0)      NOT NULL
)TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MQCGSLTHIS ADD (
CONSTRAINT MQCGSLTHIS_PK
PRIMARY KEY
(
    LOT_ID,
    HIST_SEQ,
    QA_HIST_SEQ,
    SUBLOT_ID
) USING INDEX TABLESPACE HISTORY_IDX_TS);

/* MQCGSMPDEF : QA Sample Rule Definition */
CREATE TABLE MQCGSMPDEF
(
    FACTORY                  VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    RULE_ID                  VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    RULE_DESC                VARCHAR2(50)    DEFAULT (' ')    NOT NULL,
    SMP_TYPE                 VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    UNIT1_SMP_FLAG           CHAR(1)         DEFAULT (' ')    NOT NULL,
    UNIT1_SMP_TYPE           VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    UNIT1_SMP_SIZE           NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    UNIT1_SMP_SEL_TYPE       VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    UNIT1_SMP_FORMULA        VARCHAR2(200)   DEFAULT (' ')    NOT NULL,
    UNIT1_SMP_SEL_LOC        VARCHAR2(200)   DEFAULT (' ')    NOT NULL,
    UNIT2_SMP_FLAG           CHAR(1)         DEFAULT (' ')    NOT NULL,
    UNIT2_SMP_TYPE           VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    UNIT2_SMP_SIZE           NUMBER(10,3)    DEFAULT (0)      NOT NULL,
    UNIT2_SMP_SEL_TYPE       VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    UNIT2_SMP_FORMULA        VARCHAR2(200)   DEFAULT (' ')    NOT NULL,
    UNIT2_SMP_SEL_LOC        VARCHAR2(200)   DEFAULT (' ')    NOT NULL,
    LOT_SMP_FLAG             CHAR(1)         DEFAULT (' ')    NOT NULL,
    SKIP_CNT_BY_PASS         NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    TST_CNT_BY_FAIL          NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    TEST_COUNT               NUMBER(6,0)     DEFAULT (0)      NOT NULL,
    TEST_TYPE_1              VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    TEST_TYPE_2              VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    TEST_TYPE_3              VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    TEST_TYPE_4              VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    TEST_TYPE_5              VARCHAR2(10)    DEFAULT (' ')    NOT NULL,
    QA_RUL_CMF_1             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_RUL_CMF_2             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_RUL_CMF_3             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_RUL_CMF_4             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_RUL_CMF_5             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_RUL_CMF_6             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_RUL_CMF_7             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_RUL_CMF_8             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_RUL_CMF_9             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    QA_RUL_CMF_10            VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    CREATE_USER              VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    CREATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    UPDATE_USER              VARCHAR2(20)    DEFAULT (' ')    NOT NULL,
    UPDATE_TIME              VARCHAR2(14)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_1             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_2             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_3             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_4             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_5             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_6             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_7             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_8             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_9             VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    RESV_FIELD_10            VARCHAR2(30)    DEFAULT (' ')    NOT NULL,
    PASS_COUNT_FOR_SKIP      NUMBER(6,0)     DEFAULT (0)      NOT NULL
)TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MQCGSMPDEF ADD (
CONSTRAINT MQCGSMPDEF_PK
PRIMARY KEY
(
    FACTORY,
    RULE_ID
)USING INDEX TABLESPACE MESPLUS_IDX_TS);

CREATE TABLE MSECCONUSR
(
    CON_INFO          VARCHAR2(37)    DEFAULT(' ')     NOT NULL,
    CON_TIME          VARCHAR2(14)    DEFAULT(' ')     NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MSECCONUSR ADD
CONSTRAINT MSECCONUSR_PK PRIMARY KEY
(
    CON_INFO
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


