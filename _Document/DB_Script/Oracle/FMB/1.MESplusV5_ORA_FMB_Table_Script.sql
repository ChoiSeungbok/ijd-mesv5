/*
**
**  File Name    : MESplusV5_ORA_FMB_Table_Script.sql
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

/*==== FMB(Factory Monitoring Board) ====*/
/* MFMBRESLOC : Resource/Tag Location Table */
CREATE TABLE MFMBRESLOC
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* R : Resource, T : Tag */
    RES_TYPE                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* Location */
    LAYOUT_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    SEQ                         NUMBER(6)        DEFAULT(0)      NOT NULL,                
    LOC_X                       NUMBER(6)        DEFAULT(0)      NOT NULL,
    LOC_Y                       NUMBER(6)        DEFAULT(0)      NOT NULL,
    LOC_WIDTH                   NUMBER(6)        DEFAULT(0)      NOT NULL,
    LOC_HEIGHT                  NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Style */
    TEXT                        VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    TEXT_SIZE                   NUMBER(2)        DEFAULT(0)      NOT NULL,
    TEXT_COLOR                  NUMBER(8)        DEFAULT(0)      NOT NULL,
    /* N : Normal, B : Bold, I : Italic */
    TEXT_STYLE                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* R : Rectangle, E : Ellipse, T : Triangle, N : RoundRectangle, L : Line */    
    TAG_TYPE                    NUMBER(2)        DEFAULT(0)      NOT NULL,
    BACK_COLOR                  NUMBER(8)        DEFAULT(0)      NOT NULL,
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    NO_MOUSE_EVENT              CHAR(1)          DEFAULT(' ')    NOT NULL,
    SIGNAL_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    MOTHER_RES_ID               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    ANGLE                       NUMBER(10,3)     DEFAULT(0)      NOT NULL,
		RES_SHAPE                   CHAR(1)          DEFAULT(' ')    NOT NULL   
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MFMBRESLOC
ADD CONSTRAINT MFMBRESLOC_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    RES_TYPE,
    LAYOUT_ID,
    MOTHER_RES_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MFMBUDRDEF : User Definition Group Table */
CREATE TABLE MFMBUDRDEF
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    GROUP_ID                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    GROUP_DESC                  VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    WIDTH                       NUMBER(5)        DEFAULT(0)      NOT NULL,            
    HEIGHT                      NUMBER(5)        DEFAULT(0)      NOT NULL,            
    /* Create/Update Info. */
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MFMBUDRDEF
ADD CONSTRAINT MFMBUDRDEF_PK PRIMARY KEY
(
    FACTORY,
    GROUP_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MFMBUDRLOC : User Definition Location Table */
CREATE TABLE MFMBUDRLOC
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    GROUP_ID                    VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    /* R : Resource, T : Tag */
    RES_TYPE                    CHAR(1)          DEFAULT(' ')    NOT NULL,
    SEQ                         NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Location */
    LOC_X                       NUMBER(6)        DEFAULT(0)      NOT NULL,
    LOC_Y                       NUMBER(6)        DEFAULT(0)      NOT NULL,
    LOC_WIDTH                   NUMBER(6)        DEFAULT(0)      NOT NULL,
    LOC_HEIGHT                  NUMBER(6)        DEFAULT(0)      NOT NULL,
    /* Style */
    TEXT                        VARCHAR2(40)     DEFAULT(' ')    NOT NULL,
    TEXT_SIZE                   NUMBER(2)        DEFAULT(0)      NOT NULL,
    TEXT_COLOR                  NUMBER(8)        DEFAULT(0)      NOT NULL,
    /* N : Normal, B : Bold, I : Italic */
    TEXT_STYLE                  CHAR(1)          DEFAULT(' ')    NOT NULL,
    /* R : Rectangle, E : Ellipse, T : Triangle, N : RoundRectangle, L : Line */    
    TAG_TYPE                    NUMBER(2)        DEFAULT(0)      NOT NULL,
    BACK_COLOR                  NUMBER(8)        DEFAULT(0)      NOT NULL,
    /* Create/Update Info. */
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    NO_MOUSE_EVENT              CHAR(1)          DEFAULT(' ')    NOT NULL,
    SIGNAL_FLAG                 CHAR(1)          DEFAULT(' ')    NOT NULL,
    MOTHER_RES_ID               VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    ANGLE                       NUMBER(10,3)     DEFAULT(0)      NOT NULL,
		RES_SHAPE                   CHAR(1)          DEFAULT(' ')    NOT NULL   
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MFMBUDRLOC
ADD CONSTRAINT MFMBUDRLOC_PK PRIMARY KEY
(
    FACTORY,
    GROUP_ID,
    RES_ID,
    RES_TYPE,
    MOTHER_RES_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MFMBGRPUSR : Group and User Relation */
CREATE TABLE MFMBGRPUSR
(
    FACTORY                     VARCHAR2(10)    DEFAULT (' ')   NOT NULL,
    GROUP_ID                    VARCHAR2(20)    DEFAULT (' ')   NOT NULL,
    USER_ID                     VARCHAR2(20)    DEFAULT (' ')   NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MFMBGRPUSR
ADD CONSTRAINT MFMBGRPUSR_PK PRIMARY KEY
(
    FACTORY,
    GROUP_ID,
    USER_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/* MFMBFACLYT : Factory LayOut Table */
CREATE TABLE MFMBFACLYT
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    LAYOUT_ID                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    LAYOUT_DESC                 VARCHAR2(50)     DEFAULT(' ')    NOT NULL,
    WIDTH                       NUMBER(5)        DEFAULT(0)      NOT NULL,            
    HEIGHT                      NUMBER(5)        DEFAULT(0)      NOT NULL,            
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MFMBFACLYT
ADD CONSTRAINT MFMBFACLYT_PK PRIMARY KEY
(
    FACTORY,
    LAYOUT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MFMBENVDEF : User Environment Table */
CREATE TABLE MFMBENVDEF
(
  FACTORY           VARCHAR2(10)           DEFAULT (' ')                 NOT NULL,
  CREATE_USER_ID    VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  CREATE_TIME       VARCHAR2(14)           DEFAULT (' ')                 NOT NULL,
  UPDATE_USER_ID    VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  UPDATE_TIME       VARCHAR2(14)           DEFAULT (' ')                 NOT NULL,
  FONT_FAMILY       VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  RES_WIDTH         NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  RES_HEIGHT        NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  SRS_WIDTH         NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  SRS_HEIGHT        NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  POT_WIDTH         NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  POT_HEIGHT        NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  TOL_WIDTH         NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  TOL_HEIGHT        NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  RTG_WIDTH         NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  RTG_HEIGHT        NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  ELP_WIDTH         NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  ELP_HEIGHT        NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  TRI_WIDTH         NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  TRI_HEIGHT        NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  VER_WIDTH         NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  VER_HEIGHT        NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  HOR_WIDTH         NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  HOR_HEIGHT        NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  PIE1_WIDTH        NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  PIE1_HEIGHT       NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  PIE2_WIDTH        NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  PIE2_HEIGHT       NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  PIE3_WIDTH        NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  PIE3_HEIGHT       NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  PIE4_WIDTH        NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  PIE4_HEIGHT       NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  LAYOUT_WIDTH      NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  LAYOUT_HEIGHT     NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  UDR_WIDTH         NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  UDR_HEIGHT        NUMBER(6)                   DEFAULT (0)                   NOT NULL,
  EVENT_COLOR_FLAG  CHAR(1)                DEFAULT (' ')                 NOT NULL,
  SIGNAL_FLAG       CHAR(1)                DEFAULT (' ')                 NOT NULL,
  TEXT_SIZE         NUMBER(2)                   DEFAULT (0)                   NOT NULL,
  TEXT_COLOR        NUMBER(8)                   DEFAULT (0)                   NOT NULL,
  BACK_COLOR        NUMBER(8)                   DEFAULT (0)                   NOT NULL,
  BACK_OPT          VARCHAR2(10)                DEFAULT (' ')                 NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MFMBENVDEF
ADD CONSTRAINT MFMBENVDEF_PK PRIMARY KEY
(
    FACTORY
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MFMBEVTCLR : Back Color of the Control by Event Table */
CREATE TABLE MFMBEVTCLR
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_TYPE                    VARCHAR2(10)     DEFAULT (' ')   NOT NULL,
    EVENT_ID                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    COLOR                       NUMBER(8)        DEFAULT(0)      NOT NULL,            
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MFMBEVTCLR
ADD CONSTRAINT MFMBEVTCLR_PK PRIMARY KEY
(
    FACTORY,
    RES_TYPE,
    EVENT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* MFMBRESIMG : Resource Image Table */
CREATE TABLE MFMBRESIMG
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
	  RES_TYPE                    VARCHAR2(10)     DEFAULT (' ')   NOT NULL,
	  SUBRES_ID                   VARCHAR2(20)     DEFAULT (' ')   NOT NULL,
    IMAGE_IDX                   NUMBER(3)        DEFAULT(0)      NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MFMBRESIMG
ADD CONSTRAINT MFMBRESIMG_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    RES_TYPE, 
    SUBRES_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;