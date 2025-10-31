/*
**
**  File Name    : MESplusV5-Table-Migration.sql
**  Description  : MESplus V5 Release Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g
**
**  Period       : 2009.03.04 ~ ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
**
**  Revision History
**  Seq   Date        Modifier      Description                        
**  ---------------------------------------------------------------------------
**  1     2009.03.04  Aiden         Make file
**  2     2009.03.06  JJS           Modify MWIPFACSHP, Add MWIPRSHLOT tables for remote shipping
**  3     2009.03.09  Aiden         Add Message Group
   
*/


RENAME MWIPFACSHP TO MWIPFACSHP_OLD;

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
    SHIP_CMF_11                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    SHIP_CMF_12                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    SHIP_CMF_13                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    SHIP_CMF_14                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    SHIP_CMF_15                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    SHIP_CMF_16                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    SHIP_CMF_17                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    SHIP_CMF_18                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    SHIP_CMF_19                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    SHIP_CMF_20                 VARCHAR2(30)     DEFAULT(' ')    NOT NULL,  /* Add For V42 */
    /* Create/Update Info. */
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;


INSERT INTO MWIPFACSHP VALUE (
SELECT 
    FACTORY_TO        ,
    FACTORY_FROM      ,
    AUTO_TERM_FLAG    ,
    TRANSIT_OPER      ,
    ' '       ,
    SHIP_CMF_1        ,
    SHIP_CMF_2        ,
    SHIP_CMF_3        ,
    SHIP_CMF_4        ,
    SHIP_CMF_5        ,
    SHIP_CMF_6        ,
    SHIP_CMF_7        ,
    SHIP_CMF_8        ,
    SHIP_CMF_9        ,
    SHIP_CMF_10       ,
    SHIP_CMF_11       ,
    SHIP_CMF_12       ,
    SHIP_CMF_13       ,
    SHIP_CMF_14       ,
    SHIP_CMF_15       ,
    SHIP_CMF_16       ,
    SHIP_CMF_17       ,
    SHIP_CMF_18       ,
    SHIP_CMF_19       ,
    SHIP_CMF_20       ,
    CREATE_USER_ID    ,
    CREATE_TIME       ,
    UPDATE_USER_ID    ,
    UPDATE_TIME       
 	FROM MWIPFACSHP_OLD
);

ALTER TABLE MWIPFACSHP_OLD DROP CONSTRAINT MWIPFACSHP_PK;

DROP INDEX MWIPFACSHP_PK;

ALTER TABLE MWIPFACSHP
ADD CONSTRAINT MWIPFACSHP_PK PRIMARY KEY
(
    FACTORY_TO,
    FACTORY_FROM,
    TRANSIT_OPER
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


/* Add by J.S. 2009.03.05 for Remote Shipping */
/* MWIPRSHLOT : Remote Shipping Lot Table */
CREATE TABLE MWIPRSHLOT
(
    LOT_ID                      VARCHAR2(25)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    /* Transaction Time - Backdate 가능 */
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
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

Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'MESSAGE_GROUP', 'BAS', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'BAS Message', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20080110161005', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'MESSAGE_GROUP', 'CMN', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'MESplus Common Message', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20080624114604', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'MESSAGE_GROUP', 'EIS', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'EIS Message', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20051228102627', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'MESSAGE_GROUP', 'PLN', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'PLN Message', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'MESSAGE_GROUP', 'RMS', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RMS Message', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20051226135241', 'ADMIN', '20051226135254');





Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'CMF_ITEM_NAME', 'CMF_PDS_LOT', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Pre-Dispatched cmf lot', 'BASE', '10', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20050628153906', 'ADMIN', '20070307215416');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'CMF_ITEM_NAME', 'CMF_PDS_RES', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Pre-Dispatched cmf resource', 'BASE', '10', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20050628153906', 'ADMIN', '20070307215416');


BEGIN
	 FOR REC IN (
				SELECT DISTINCT FACTORY FROM MWIPFACDEF
				MINUS
				SELECT DISTINCT FACTORY FROM MGCMTBLDAT 
				WHERE TABLE_NAME = 'CMF_ITEM_NAME'
					AND KEY_1 = 'CMF_PDS_LOT'
				) 
	  LOOP
		Insert into MGCMTBLDAT
		   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
		 Values
		   (REC.FACTORY, 'CMF_ITEM_NAME', 'CMF_PDS_LOT', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Pre-Dispatched cmf lot', 'BASE', '10', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20050628153906', 'ADMIN', '20070307215416');
		Insert into MGCMTBLDAT
		   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
		 Values
		   (REC.FACTORY, 'CMF_ITEM_NAME', 'CMF_PDS_RES', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Pre-Dispatched cmf resource', 'BASE', '10', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20050628153906', 'ADMIN', '20070307215416');

	  END LOOP;			
END ;
/



RENAME MRTDLOTPDS TO MRTDLOTPDS_OLD;

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

INSERT INTO MRTDLOTPDS VALUE (
SELECT 
    FACTORY                     ,
    RES_OPER_FLAG               ,   
    RES_OPER_ID                 ,
    LOT_ID                      ,
    SET_OPER                    ,
    SET_RESG_ID                 ,
    SET_RES_ID                  ,
    DSP_ID                      ,
    RULE_ID                     ,
    TEMP_BATCH_ID               ,
    TEMP_BATCH_SEQ              ,
    CUR_OPER                    ,
    REFERENCE_OPER              , 
    UNSELECTED_FLAG             ,
    LOT_RESV_FLAG               ,
    LOT_RESV_TIME               ,
    CAPABLE_FLAG                ,
    PRI_ADJUST_FLAG             ,
    PRIORITY_SCORE              ,
    PRIORITY_SUPPORT            ,
    HIST_SEQ                    ,
    PRI_ADJUST_REASON           ,
    TRIGGER_BY                  ,
    DSP_REASON                  ,
    UNSELECT_REASON             ,
    CAPABLE_REASON              ,
    ' '                   ,
    ' '                   ,
    ' '                   ,
    ' '                   ,
    ' '                   ,
    ' '                   ,
    ' '                   ,
    ' '                   ,
    ' '                   ,
    ' '                  ,
    CREATE_USER_ID              ,
    CREATE_TIME                 ,
    UPDATE_USER_ID              ,
    UPDATE_TIME                 
    FROM MRTDLOTPDS_OLD);


ALTER TABLE MRTDLOTPDS_OLD DROP CONSTRAINT MRTDLOTPDS_PK;

DROP INDEX MRTDLOTPDS_PK;

ALTER TABLE MRTDLOTPDS
ADD CONSTRAINT MRTDLOTPDS_PK PRIMARY KEY
(
    FACTORY,
    RES_OPER_FLAG,
    RES_OPER_ID,
    LOT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

DROP INDEX MRTDLOTPDS_IDX_1;

CREATE INDEX MRTDLOTPDS_IDX_1 ON MRTDLOTPDS
(
    LOT_ID
) TABLESPACE MESPLUS_IDX_TS;






RENAME MRTDLOTPDH TO MRTDLOTPDH_OLD;

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


INSERT INTO MRTDLOTPDH VALUE (
SELECT 
    TRAN_TIME                   ,
    FACTORY                     ,
    RES_OPER_FLAG               ,   
    RES_OPER_ID                 ,
    LOT_ID                      ,
    SET_OPER                    ,
    SET_RESG_ID                 ,
    SET_RES_ID                  ,
    DSP_ID                      ,
    RULE_ID                     ,
    TEMP_BATCH_ID               ,
    TEMP_BATCH_SEQ              ,
    CUR_OPER                    ,
    REFERENCE_OPER              , 
    UNSELECTED_FLAG             ,
    LOT_RESV_FLAG               ,
    LOT_RESV_TIME               ,
    CAPABLE_FLAG                ,
    PRI_ADJUST_FLAG             ,
    PRIORITY_SCORE              ,
    PRIORITY_SUPPORT            ,
    HIST_SEQ                    ,
    PRI_ADJUST_REASON           ,
    TRIGGER_BY                  ,
    DSP_REASON                  ,
    UNSELECT_REASON             ,
    CAPABLE_REASON              ,
    ' '                   ,
    ' '                   ,
    ' '                   ,
    ' '                   ,
    ' '                   ,
    ' '                   ,
    ' '                   ,
    ' '                   ,
    ' '                   ,
    ' '                  ,
    CREATE_USER_ID              ,
    CREATE_TIME                 ,
    UPDATE_USER_ID              ,
    UPDATE_TIME                 
    FROM MRTDLOTPDH_OLD);


ALTER TABLE MRTDLOTPDH_OLD DROP CONSTRAINT MRTDLOTPDH_PK;

DROP INDEX MRTDLOTPDH_PK;

ALTER TABLE MRTDLOTPDH
ADD CONSTRAINT MRTDLOTPDH_PK PRIMARY KEY
(
    FACTORY,
    TRAN_TIME,
    RES_OPER_FLAG,
    RES_OPER_ID,
    LOT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

DROP INDEX MRTDLOTPDH_IDX_1;

CREATE INDEX MRTDLOTPDH_IDX_1 ON MRTDLOTPDH
(
    FACTORY,
    TRAN_TIME
) TABLESPACE MESPLUS_IDX_TS;




RENAME MFMBRESLOC TO MFMBRESLOC_OLD;

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

INSERT INTO MFMBRESLOC (
   FACTORY, RES_ID, RES_TYPE, 
   LAYOUT_ID, SEQ, LOC_X, 
   LOC_Y, LOC_WIDTH, LOC_HEIGHT, 
   TEXT, TEXT_SIZE, TEXT_COLOR, 
   TEXT_STYLE, TAG_TYPE, BACK_COLOR, 
   CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, 
   UPDATE_TIME, NO_MOUSE_EVENT, SIGNAL_FLAG, 
   MOTHER_RES_ID) 
SELECT FACTORY, RES_ID, RES_TYPE, 
   LAYOUT_ID, SEQ, LOC_X, 
   LOC_Y, LOC_WIDTH, LOC_HEIGHT, 
   TEXT, TEXT_SIZE, TEXT_COLOR, 
   TEXT_STYLE, TAG_TYPE, BACK_COLOR, 
   CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, 
   UPDATE_TIME, NO_MOUSE_EVENT, SIGNAL_FLAG, 
   MOTHER_RES_ID FROM MFMBRESLOC_OLD;

ALTER TABLE MFMBRESLOC_OLD DROP CONSTRAINT MFMBRESLOC_PK;

DROP INDEX MFMBRESLOC_PK;

ALTER TABLE MFMBRESLOC
ADD CONSTRAINT MFMBRESLOC_PK PRIMARY KEY
(
    FACTORY,
    RES_ID,
    RES_TYPE,
    LAYOUT_ID,
    MOTHER_RES_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


RENAME MFMBUDRLOC TO MFMBUDRLOC_OLD;

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

INSERT INTO MFMBUDRLOC (
   FACTORY, GROUP_ID, RES_ID, 
   RES_TYPE, SEQ, LOC_X, 
   LOC_Y, LOC_WIDTH, LOC_HEIGHT, 
   TEXT, TEXT_SIZE, TEXT_COLOR, 
   TEXT_STYLE, TAG_TYPE, BACK_COLOR, 
   CREATE_TIME, UPDATE_TIME, NO_MOUSE_EVENT, 
   SIGNAL_FLAG, MOTHER_RES_ID) 
SELECT FACTORY, GROUP_ID, RES_ID, 
   RES_TYPE, SEQ, LOC_X, 
   LOC_Y, LOC_WIDTH, LOC_HEIGHT, 
   TEXT, TEXT_SIZE, TEXT_COLOR, 
   TEXT_STYLE, TAG_TYPE, BACK_COLOR, 
   CREATE_TIME, UPDATE_TIME, NO_MOUSE_EVENT, 
   SIGNAL_FLAG, MOTHER_RES_ID FROM MFMBUDRLOC_OLD;
   
ALTER TABLE MFMBUDRLOC_OLD DROP CONSTRAINT MFMBUDRLOC_PK;

DROP INDEX MFMBUDRLOC_PK;

ALTER TABLE MFMBUDRLOC
ADD CONSTRAINT MFMBUDRLOC_PK PRIMARY KEY
(
    FACTORY,
    GROUP_ID,
    RES_ID,
    RES_TYPE,
    MOTHER_RES_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


UPDATE MFMBRESLOC SET SIGNAL_FLAG = '2' WHERE SIGNAL_FLAG = 'Y';
UPDATE MFMBUDRLOC SET SIGNAL_FLAG = '2' WHERE SIGNAL_FLAG = 'Y';

RENAME MFMBEVTCLR TO MFMBEVTCLR_OLD;

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

INSERT INTO MFMBEVTCLR (
   FACTORY, RES_TYPE, EVENT_ID, 
   COLOR, CREATE_USER_ID, CREATE_TIME, 
   UPDATE_USER_ID, UPDATE_TIME) 
SELECT FACTORY, 'RES', EVENT_ID, 
   COLOR, CREATE_USER_ID, CREATE_TIME, 
   UPDATE_USER_ID, UPDATE_TIME FROM  MFMBEVTCLR_OLD;

ALTER TABLE MFMBEVTCLR_OLD DROP CONSTRAINT MFMBEVTCLR_PK;

DROP INDEX MFMBEVTCLR_PK;

ALTER TABLE MFMBEVTCLR
ADD CONSTRAINT MFMBEVTCLR_PK PRIMARY KEY
(
    FACTORY,
    RES_TYPE,
    EVENT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


RENAME MFMBENVDEF TO MFMBENVDEF_OLD;

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

INSERT INTO MFMBENVDEF (
   FACTORY, CREATE_USER_ID, CREATE_TIME, 
   UPDATE_USER_ID, UPDATE_TIME, FONT_FAMILY, 
   RES_WIDTH, RES_HEIGHT, SRS_WIDTH, 
   SRS_HEIGHT, POT_WIDTH, POT_HEIGHT, 
   TOL_WIDTH, TOL_HEIGHT, RTG_WIDTH, 
   RTG_HEIGHT, ELP_WIDTH, ELP_HEIGHT, 
   TRI_WIDTH, TRI_HEIGHT, VER_WIDTH, 
   VER_HEIGHT, HOR_WIDTH, HOR_HEIGHT, 
   PIE1_WIDTH, PIE1_HEIGHT, PIE2_WIDTH, 
   PIE2_HEIGHT, PIE3_WIDTH, PIE3_HEIGHT, 
   PIE4_WIDTH, PIE4_HEIGHT, LAYOUT_WIDTH, 
   LAYOUT_HEIGHT, UDR_WIDTH, UDR_HEIGHT, 
   EVENT_COLOR_FLAG, SIGNAL_FLAG, TEXT_SIZE, 
   TEXT_COLOR, BACK_COLOR) 
SELECT FACTORY, CREATE_USER_ID, CREATE_TIME, 
   UPDATE_USER_ID, UPDATE_TIME, FONT_FAMILY, 
   RES_WIDTH, RES_HEIGHT, SRS_WIDTH, 
   SRS_HEIGHT, POT_WIDTH, POT_HEIGHT, 
   TOL_WIDTH, TOL_HEIGHT, RTG_WIDTH, 
   RTG_HEIGHT, ELP_WIDTH, ELP_HEIGHT, 
   TRI_WIDTH, TRI_HEIGHT, VER_WIDTH, 
   VER_HEIGHT, HOR_WIDTH, HOR_HEIGHT, 
   PIE1_WIDTH, PIE1_HEIGHT, PIE2_WIDTH, 
   PIE2_HEIGHT, PIE3_WIDTH, PIE3_HEIGHT, 
   PIE4_WIDTH, PIE4_HEIGHT, LAYOUT_WIDTH, 
   LAYOUT_HEIGHT, UDR_WIDTH, UDR_HEIGHT, 
   EVENT_COLOR_FLAG, SIGNAL_FLAG, TEXT_SIZE, 
   TEXT_COLOR, BACK_COLOR FROM MFMBENVDEF_OLD;

ALTER TABLE MFMBENVDEF_OLD DROP CONSTRAINT MFMBENVDEF_PK;

DROP INDEX MFMBENVDEF_PK;

ALTER TABLE MFMBENVDEF
ADD CONSTRAINT MFMBENVDEF_PK PRIMARY KEY
(
    FACTORY
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

UPDATE MFMBENVDEF SET BACK_OPT = 'Event' WHERE EVENT_COLOR_FLAG = 'Y';

Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB1003', 'Resource Color Setup', 'F', 'SETUP', 'Miracom.FMBCore.dll', 'Miracom.FMBCore.frmFMBSetupResourceColor', ' ', 242, 'btnAdd', 'btnDel', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.18.html', 'ADMIN', '20090302161949', ' ', ' ');

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB-0014', 'FMB', 'FMB-0014 : The resource already has back color information.', '이 장비는 이미 배경색 정보를 가지고 있습니다.', 'FMB-0014 :', 'ADMIN', '20090302171342', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB-0015', 'FMB', 'FMB-0015 : The resource does not have back color information.', '이 장비의 배경색 정보가 존재하지 않습니다.', 'FMB-0015 :', 'ADMIN', '20090302171521', ' ', ' ');

Insert into MSECGRPFUN
   (FACTORY, PROGRAM_ID, SEC_GRP_ID, FUNC_NAME, DISP_LEVEL, SEPARATOR, SHORT_CUT, ADD_TOOL_BAR, CTL_EN_FLAG_1, CTL_EN_FLAG_2, CTL_EN_FLAG_3, CTL_EN_FLAG_4, CTL_EN_FLAG_5, CTL_EN_FLAG_6, CTL_EN_FLAG_7, CTL_EN_FLAG_8, CTL_EN_FLAG_9, CTL_EN_FLAG_10, TAB_DS_FLAG_1, TAB_DS_FLAG_2, TAB_DS_FLAG_3, TAB_DS_FLAG_4, TAB_DS_FLAG_5, TAB_DS_FLAG_6, TAB_DS_FLAG_7, TAB_DS_FLAG_8, TAB_DS_FLAG_9, TAB_DS_FLAG_10, OPT_VALUE_1, OPT_VALUE_2, OPT_VALUE_3, OPT_VALUE_4, OPT_VALUE_5, OPT_VALUE_6, OPT_VALUE_7, OPT_VALUE_8, OPT_VALUE_9, OPT_VALUE_10, FLD_EN_ALL_FLAG, FLD_EN_MASK, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'FMBClient', 'DEFAULT_ADMIN_FUNC', 'FMB1003', '!.#', ' ', ' ', 'N', 'Y', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20090312173558', ' ', ' ');

-- For Attribute Loader
 CREATE SEQUENCE MTMPATRHIS_SEQ
  START WITH 1
  MAXVALUE 999999999999
  MINVALUE 1
  CYCLE
  CACHE 20
  NOORDER;

-- For Cassette Loader
 CREATE SEQUENCE MTMPCRRHIS_SEQ
  START WITH 1
  MAXVALUE 999999999999
  MINVALUE 1
  CYCLE
  CACHE 20
  NOORDER;

/*==== MES --> Report Attribute Interface Table ====*/
CREATE TABLE MTMPATRHIS 
(
    TABLE_UPDATE_SEQ            NUMBER(12)       DEFAULT(0)      NOT NULL,
    CM_KEY_1                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_2                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_3                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_4                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    CM_KEY_5                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    ATTR_TYPE                   VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    ATTR_NAME                   VARCHAR2(100)    DEFAULT(' ')    NOT NULL,
    ATTR_KEY                    VARCHAR2(30)     DEFAULT(' ')    NOT NULL,
    HIST_SEQ                    NUMBER(10)       DEFAULT(0)      NOT NULL,
    ATTR_OLD_VALUE              VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    ATTR_NEW_VALUE              VARCHAR2(1000)   DEFAULT(' ')    NOT NULL,
    TRAN_TIME                   VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    SYS_TRAN_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    KEY_HIST_SEQ                NUMBER(10)       DEFAULT(0)      NOT NULL,                
    PREV_ACTIVE_HIST_SEQ        NUMBER(10)       DEFAULT(0)      NOT NULL,
    HIST_START_SEQ              NUMBER(10)       DEFAULT(0)      NOT NULL,
    HIST_DEL_FLAG               CHAR(1)          DEFAULT(' ')    NOT NULL,
    HIST_DEL_TIME               VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_USER_ID            VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    HIST_DEL_COMMENT            VARCHAR2(400)    DEFAULT(' ')    NOT NULL,
    PROCESS_FLAG                CHAR(1)          DEFAULT(' ')    NOT NULL
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
    PROCESS_FLAG                CHAR(1)          DEFAULT(' ')   NOT NULL
) TABLESPACE HISTORY_DATA_TS;

ALTER TABLE MTMPCRRHIS
ADD CONSTRAINT MTMPCRRHIS_PK PRIMARY KEY
(
    TABLE_UPDATE_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

Insert into MSVMSVCDEF
   (SERVICE_NAME, MODULE_NAME, SERVICE_MODE, SERVICE_CATEGORY, SERVICE_DESC_1, SERVICE_DESC_2, SERVICE_DESC_3, SEC_CHK_FLAG, SHARED_LIB_NAME, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP_Scribe_Lot_Ext', 'WIP', 'RR', 'T', 'Scribe transaction of the lot with sub lot', ' ', ' ', ' ', ' ', 'ADMIN', '20090303161040', ' ', ' ');

Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2055', 'Scribe Extension', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranScribeLotExt', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', 'ADMIN', '20090303003856', ' ', ' ');

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0383', 'WIP', 'WIP-0383 : The result of unit2 after scribe is not integer. Only integer is allowed in factories that manage cell grade. Please check scribe count.', 'WIP-0383 : Scribe후 unit2의 결과가 정수가 아닙니다. CELL GRADE를 관리하는 공장에서는 정수만 허용됩니다. SCRIBE COUNT를 확인 하세요.', 'WIP-0383', 'ADMIN', '20090305153612', ' ', ' ');

Delete from MMSGMSGDEF where MSG_ID = 'SEC-0050';
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SEC-0050', 'SEC', 'SEC-0050 : This user does not have privilege to use this service .', 'SEC-0050 : 이 사용자는 해당 서비스를 사용할 수 있는 권한이 없습니다.', 'SEC-0050 : This user does not have privilege to use this service.', 'ADMIN', '20060405160005', 'ADMIN', '20080312210149');
Delete from MMSGMSGDEF where MSG_ID = 'SEC-0051';
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SEC-0051', 'SEC', 'SEC-0051 : Other user have privilege for this service and This user does not have privilege to use this service .', 'SEC-0051 : 이 서비스는 이미 다른 사용자에 의해 권한 설정이 되었습니다. 이 서비스를 사용하기 위해 적절한 권한 설정이 필요합니다.', 'SEC-0051 : Other user have privilege for this service and This user does not have privilege to use this service .', 'ADMIN', '20060405160005', 'ADMIN', '20080312210149');
Delete from MMSGMSGDEF where MSG_ID = 'WIP-0280';
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0280', 'WIP', 'WIP-0280 : This operation requires "END" transaction. End Lot first.', 'WIP-0280 : 이 공정은 END가 필요한 공정 입니다. 먼저 END 후 사용 하세요.', 'WIP-0280 : Diese Operation verlangt eine End-Transaktion. Fuehren Sie zuerst ein End Lot durch.', 'ADMIN', '20050203162807', 'ADMIN', '20090318171254');
Delete from MMSGMSGDEF where MSG_ID = 'RAS-0074';
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS-0074', 'RAS', 'RAS-0074 : Lot or Carrier exists at the port. Remove the Lot or Carrier and retry.', 'RAS-0074 : 포트에 Lot 또는 카세트가 존재합니다. Lot 또는 카세트를 먼저 제거하고 다시 시도하십시요.', 'RAS-0074 : Los oder Trager haben einen Port. Entfernen Sie das Los oder Carrier und versuchen Sie es erneut.', 'ADMIN', '20081201010101', ' ', ' ');
Delete from MMSGMSGDEF where MSG_ID = 'WIP-0075';
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0075', 'WIP', 'WIP-0075 : This lot exists at another factory. Please check lot id.', 'WIP-0075 : 이 LOT은 다른 공장에 존재 합니다. LOT을  확인 하세요.', 'WIP-0075 : Dieses Lot existiert in einer anderen Factory. Bitte ueberpruefen Sie die Lot ID.', 'ADMIN', '20081201010101', ' ', ' ');
Delete from MMSGMSGDEF where MSG_ID = 'WIP-0115';
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0115', 'WIP', 'WIP-0115 : Invaild transaction code exists in history.', 'WIP-0115 : 알수 없는 TRANSACTION CODE가 HISTORY에 존재합니다.', 'WIP-0115 : Ungueltiger Transaction-Ccode existiert in Historie.', 'ADMIN', '20081201010101', ' ', ' ');



/* Add by J.S. for RTD */

Delete from MSVMSVCMBR where service_name = 'RTD_Adjust_Lot_Priority';
Delete from MSVMSVCMBR where service_name = 'RTD_Copy_Dispatch_Rule';
Delete from MSVMSVCMBR where service_name = 'RTD_External_Dispatch_Event';
Delete from MSVMSVCMBR where service_name = 'RTD_Get_Lot_Simulation_Result';
Delete from MSVMSVCMBR where service_name = 'RTD_Get_Resource_Simulation_Result';
Delete from MSVMSVCMBR where service_name = 'RTD_Interface';
Delete from MSVMSVCMBR where service_name = 'RTD_Re_Dispatch_Lot';
Delete from MSVMSVCMBR where service_name = 'RTD_Update_Dispatch_Relation';
Delete from MSVMSVCMBR where service_name = 'RTD_Update_Dispatcher';
Delete from MSVMSVCMBR where service_name = 'RTD_Update_Dispatcher_Event';
Delete from MSVMSVCMBR where service_name = 'RTD_Update_Dispatcher_Oper';
Delete from MSVMSVCMBR where service_name = 'RTD_Update_Dispatcher_Res';
Delete from MSVMSVCMBR where service_name = 'RTD_Update_Reference_Operation';
Delete from MSVMSVCMBR where service_name = 'RTD_Update_Rule';
Delete from MSVMSVCMBR where service_name = 'RTD_Update_Rule_Items';
Delete from MSVMSVCMBR where service_name = 'RTD_View_Dispatch_Relation';
Delete from MSVMSVCMBR where service_name = 'RTD_View_Dispatched_Lot_List';
Delete from MSVMSVCMBR where service_name = 'RTD_View_Dispatched_Resource_List';
Delete from MSVMSVCMBR where service_name = 'RTD_View_Dispatcher';
Delete from MSVMSVCMBR where service_name = 'RTD_View_Dispatcher_Event';
Delete from MSVMSVCMBR where service_name = 'RTD_View_Dispatcher_Event_History';
Delete from MSVMSVCMBR where service_name = 'RTD_View_Dispatcher_Event_List';
Delete from MSVMSVCMBR where service_name = 'RTD_View_Dispatcher_List';
Delete from MSVMSVCMBR where service_name = 'RTD_View_DspOper_List';
Delete from MSVMSVCMBR where service_name = 'RTD_View_DspRes_List';
Delete from MSVMSVCMBR where service_name = 'RTD_View_Pre_Dispatched_History';
Delete from MSVMSVCMBR where service_name = 'RTD_View_Pre_Dispatched_Status';
Delete from MSVMSVCMBR where service_name = 'RTD_View_Reference_Operation';
Delete from MSVMSVCMBR where service_name = 'RTD_View_Resource_PriSts';
Delete from MSVMSVCMBR where service_name = 'RTD_View_Rule';
Delete from MSVMSVCMBR where service_name = 'RTD_View_Rule_Item';
Delete from MSVMSVCMBR where service_name = 'RTD_View_Rule_Item_List';
Delete from MSVMSVCMBR where service_name = 'RTD_View_Rule_List';

Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Adjust_Lot_Priority', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Adjust_Lot_Priority', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Adjust_Lot_Priority', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Adjust_Lot_Priority', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Adjust_Lot_Priority', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Adjust_Lot_Priority', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': Priority Up, ''2'': Priority Down, ''3'': Toggle Unselectable Flag, ''4'': Cancel Adjustment of Lot Priority)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Adjust_Lot_Priority', 'I', 0, 'RES_OPER_FLAG', 6, ' ', ' ', ' ', ' ', 0, 'RES_OPER_FLAG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Adjust_Lot_Priority', 'I', 0, 'RES_OPER_ID', 7, ' ', ' ', ' ', ' ', 0, 'RES_OPER_ID', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Adjust_Lot_Priority', 'I', 0, 'LOT_ID', 8, 'Lot ID to change Dispatch Priority', ' ', ' ', 'String', 25, 'LOT_ID', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Adjust_Lot_Priority', 'I', 0, 'PRIORITY_SCORE', 9, ' ', ' ', ' ', ' ', 0, 'PRIORITY_SCORE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Adjust_Lot_Priority', 'I', 0, 'PRI_ADJUST_REASON', 10, ' ', ' ', ' ', ' ', 0, 'PRI_ADJUST_REASON', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Adjust_Lot_Priority', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Adjust_Lot_Priority', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Adjust_Lot_Priority', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Adjust_Lot_Priority', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Adjust_Lot_Priority', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Adjust_Lot_Priority', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Adjust_Lot_Priority', 'O', 0, 'CSTATUS', 6, ' ', ' ', ' ', ' ', 0, 'CSTATUS', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Copy_Dispatch_Rule', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Copy_Dispatch_Rule', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Copy_Dispatch_Rule', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Copy_Dispatch_Rule', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Copy_Dispatch_Rule', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Copy_Dispatch_Rule', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''C'': Copy)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Copy_Dispatch_Rule', 'I', 0, 'FROM_RULE_ID', 6, ' ', ' ', ' ', ' ', 0, 'FROM_RULE_ID', ' ', 'M', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Copy_Dispatch_Rule', 'I', 0, 'TO_RULE_ID', 7, ' ', ' ', ' ', ' ', 0, 'TO_RULE_ID', ' ', 'M', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Copy_Dispatch_Rule', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Copy_Dispatch_Rule', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Copy_Dispatch_Rule', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Copy_Dispatch_Rule', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Copy_Dispatch_Rule', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Copy_Dispatch_Rule', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Copy_Dispatch_Rule', 'O', 0, 'CSTATUS', 6, ' ', ' ', ' ', ' ', 0, 'CSTATUS', ' ', 'O', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USERID', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': Default)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'I', 0, 'SERVICE_NAME', 6, ' ', ' ', ' ', ' ', 0, 'SERVICE_NAME', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'I', 0, 'LOT_ID', 7, 'Lot ID. Mandatory when Action Category is Lot', ' ', ' ', 'String', 25, 'LOT_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'I', 0, 'RES_ID', 8, 'ResourceID (Equipment, Entity). Mandatory when Action Category is Resource.', ' ', ' ', 'String', 20, 'RES_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'I', 0, 'RESG_ID', 9, 'Resource Group ID. Mandatory when Action Category is Resource Group.', ' ', ' ', 'String', 20, 'RESG_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'I', 0, 'MAT_ID', 10, 'Material ID (Product). Mandatory when Action Category is Material, Material-Flow-Oper, or Material-Oper.', ' ', ' ', 'String', 30, 'MAT_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'I', 0, 'MAT_VER', 11, 'Material Version. Mandatory when Action Category is Material-Flow-Oper, or Material-Oper.', ' ', ' ', 'Int', 0, 'MAT_VER', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'I', 0, 'FLOW', 12, 'Flow. The group of unit operations. Mandatory when Action Category is  Material-Flow-Oper, or Flow-Oper.', ' ', ' ', 'String', 20, 'FLOW', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'I', 0, 'OPER', 13, 'Unit Operation. Mandatory when Action Category is Material-Flow-Oper, Flow-Oper, Oper, or Material-Oper.', ' ', ' ', 'String', 10, 'OPER', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'I', 0, 'BATCH_ID', 14, 'Batch ID. Mandatory when Action Category is Batch.', ' ', ' ', 'String', 30, 'BATCH_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_External_Dispatch_Event', 'O', 0, 'CSTATUS', 6, ' ', ' ', ' ', ' ', 0, 'CSTATUS', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': Lot List in Operations which configured to Dispatcher for Simulation, ''2'': Lot List in Operations which has relationship with the specific Resource)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'I', 0, 'DSP_ID', 6, 'Dispatcher ID. Mandatory when Process Step =''1'' for Simulation', ' ', ' ', 'String', 20, 'DSP_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'I', 0, 'RES_ID', 7, 'ResourceID (Equipment, Entity). Mandatory when Process Step =''2'' for Real-Time Dispatch', ' ', ' ', 'String', 20, 'RES_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'I', 0, 'NEXT_LOT_ID', 8, ' ', ' ', ' ', ' ', 0, 'NEXT_LOT_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'I', 0, 'NEXT_OPER', 9, ' ', ' ', ' ', ' ', 0, 'NEXT_OPER', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'I', 0, 'NEXT_COUNT', 10, ' ', ' ', ' ', ' ', 0, 'NEXT_COUNT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 0, 'COUNT', 6, ' ', ' ', ' ', ' ', 0, 'COUNT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 0, 'NEXT_LOT_ID', 7, ' ', ' ', ' ', ' ', 0, 'NEXT_LOT_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 0, 'NEXT_OPER', 8, ' ', ' ', ' ', ' ', 0, 'NEXT_OPER', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 0, 'NEXT_COUNT', 9, ' ', ' ', ' ', ' ', 0, 'NEXT_COUNT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 0, 'LOT_LIST', 10, 'Lot List', ' ', ' ', 'List', 0, ' ', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'LOT_ID', 0, ' ', ' ', ' ', ' ', 0, 'LOT_ID', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'LOT_DESC', 1, ' ', ' ', ' ', ' ', 0, 'LOT_DESC', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'MAT_ID', 3, ' ', ' ', ' ', ' ', 0, 'MAT_ID', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'MAT_VER', 4, ' ', ' ', ' ', ' ', 0, 'MAT_VER', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'FLOW', 5, ' ', ' ', ' ', ' ', 0, 'FLOW', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'FLOW_SEQ_NUM', 6, ' ', ' ', ' ', ' ', 0, 'FLOW_SEQ_NUM', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'OPER', 7, ' ', ' ', ' ', ' ', 0, 'OPER', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'QTY_1', 8, ' ', ' ', ' ', ' ', 0, 'QTY_1', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'QTY_2', 9, ' ', ' ', ' ', ' ', 0, 'QTY_2', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'QTY_3', 10, ' ', ' ', ' ', ' ', 0, 'QTY_3', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'LOT_TYPE', 11, ' ', ' ', ' ', ' ', 0, 'LOT_TYPE', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'OWNER_CODE', 12, ' ', ' ', ' ', ' ', 0, 'OWNER_CODE', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'CREATE_CODE', 13, ' ', ' ', ' ', ' ', 0, 'CREATE_CODE', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'LOT_PRIORITY', 14, ' ', ' ', ' ', ' ', 0, 'LOT_PRIORITY', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'LOT_STATUS', 15, ' ', ' ', ' ', ' ', 0, 'LOT_STATUS', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'HOLD_FLAG', 16, ' ', ' ', ' ', ' ', 0, 'HOLD_FLAG', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'RWK_FLAG', 17, ' ', ' ', ' ', ' ', 0, 'RWK_FLAG', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'NSTD_FLAG', 18, ' ', ' ', ' ', ' ', 0, 'NSTD_FLAG', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'START_FLAG', 19, ' ', ' ', ' ', ' ', 0, 'START_FLAG', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'REP_FLAG', 20, ' ', ' ', ' ', ' ', 0, 'REP_FLAG', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'ORG_DUE_TIME', 21, ' ', ' ', ' ', ' ', 0, 'ORG_DUE_TIME', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'SCH_DUE_TIME', 22, ' ', ' ', ' ', ' ', 0, 'SCH_DUE_TIME', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'OPER_IN_TIME', 23, ' ', ' ', ' ', ' ', 0, 'OPER_IN_TIME', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'LAST_TRAN_CODE', 24, ' ', ' ', ' ', ' ', 0, 'LAST_TRAN_CODE', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'PRIORITY_SCORE', 25, ' ', ' ', ' ', ' ', 0, 'PRIORITY_SCORE', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'UNSELECT_FLAG', 26, ' ', ' ', ' ', ' ', 0, 'UNSELECT_FLAG', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'CAPABLE_FLAG', 27, ' ', ' ', ' ', ' ', 0, 'RULE_ID', ' ', 'O', 'LOT_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090317155032', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'RULE_ID', 28, 'Dispatch Rule ID', ' ', ' ', 'String', 20, 'RULE_ID', ' ', 'O', 'LOT_LIST', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317155032');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'DSP_REASON', 29, ' ', ' ', ' ', ' ', 0, 'DSP_REASON', ' ', 'O', 'LOT_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317155032');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'UNSELECT_REASON', 30, 'Information of Dispatch calculation result. It shows unseleted reason.', ' ', ' ', 'String', 1000, 'UNSELECT_REASON', ' ', 'O', 'LOT_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155124', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'CAPABLE_REASON', 31, 'Information of Dispatch calculation result. It shows capable or uncapable reason.', ' ', ' ', 'String', 1000, 'CAPABLE_REASON', ' ', 'O', 'LOT_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155124', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'PDS_CMF_1', 32, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_1', ' ', 'O', 'LOT_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155233', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'PDS_CMF_2', 33, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_2', ' ', 'O', 'LOT_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155233', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'PDS_CMF_3', 34, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_3', ' ', 'O', 'LOT_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155233', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'PDS_CMF_4', 35, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_4', ' ', 'O', 'LOT_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155233', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'PDS_CMF_5', 36, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_5', ' ', 'O', 'LOT_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155233', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'PDS_CMF_6', 37, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_6', ' ', 'O', 'LOT_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155233', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'PDS_CMF_7', 38, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_7', ' ', 'O', 'LOT_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155233', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'PDS_CMF_8', 39, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_8', ' ', 'O', 'LOT_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155233', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'PDS_CMF_9', 40, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_9', ' ', 'O', 'LOT_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155233', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Lot_Simulation_Result', 'O', 1, 'PDS_CMF_10', 41, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_10', ' ', 'O', 'LOT_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155233', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': Resource List which configured to Dispatcher for Simulation, ''2'': Resource List which has relationship with Material, Flow, Operation)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'I', 0, 'NEXT_RES_ID', 6, ' ', ' ', ' ', ' ', 0, 'NEXT_RES_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'I', 0, 'NEXT_COUNT', 7, ' ', ' ', ' ', ' ', 0, 'NEXT_COUNT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'I', 0, 'DSP_ID', 8, 'Dispatcher ID. Mandatory when Process Step =''1''.', ' ', ' ', 'String', 20, 'DSP_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'I', 0, 'MAT_ID', 9, 'Material ID (Product). Mandatory when Process Step =''2''.', ' ', ' ', 'String', 30, 'MAT_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'I', 0, 'MAT_VER', 10, 'Material Version. Mandatory when Process Step =''2''.', ' ', ' ', 'Int', 0, 'MAT_VER', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'I', 0, 'FLOW', 11, 'Flow.  Mandatory when Process Step =''2''.', ' ', ' ', 'String', 20, 'FLOW', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'I', 0, 'OPER', 12, 'Unit Operation. Mandatory when Process Step =''2''.', ' ', ' ', 'String', 10, 'OPER', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 0, 'COUNT', 6, ' ', ' ', ' ', ' ', 0, 'COUNT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 0, 'NEXT_RES_ID', 7, ' ', ' ', ' ', ' ', 0, 'NEXT_RES_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 0, 'NEXT_COUNT', 8, ' ', ' ', ' ', ' ', 0, 'NEXT_COUNT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 0, 'RES_LIST', 9, ' ', ' ', ' ', 'List', 0, ' ', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'RES_ID', 0, ' ', ' ', ' ', ' ', 0, 'RES_ID', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'RES_DESC', 1, ' ', ' ', ' ', ' ', 0, 'RES_DESC', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'RES_TYPE', 2, ' ', ' ', ' ', ' ', 0, 'RES_TYPE', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'AREA_ID', 3, ' ', ' ', ' ', ' ', 0, 'AREA_ID', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'SUB_AREA_ID', 4, ' ', ' ', ' ', ' ', 0, 'SUB_AREA_ID', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'RES_UP_DOWN_FLAG', 5, ' ', ' ', ' ', ' ', 0, 'RES_UP_DOWN_FLAG', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'RES_PRI_STS', 6, ' ', ' ', ' ', ' ', 0, 'RES_PRI_STS', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'LAST_EVENT_ID', 7, ' ', ' ', ' ', ' ', 0, 'LAST_EVENT_ID', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'LAST_EVENT_TIME', 8, ' ', ' ', ' ', ' ', 0, 'LAST_EVENT_TIME', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'LAST_START_TIME', 9, ' ', ' ', ' ', ' ', 0, 'LAST_START_TIME', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'LAST_END_TIME', 10, ' ', ' ', ' ', ' ', 0, 'LAST_END_TIME', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'PRIORITY_SCORE', 11, ' ', ' ', ' ', ' ', 0, 'PRIORITY_SCORE', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'UNSELECT_FLAG', 12, ' ', ' ', ' ', ' ', 0, 'UNSELECT_FLAG', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'CAPABLE_FLAG', 13, ' ', ' ', ' ', ' ', 0, 'CAPABLE_FLAG', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090317155514', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'RULE_ID', 14, 'Dispatch Rule ID', ' ', ' ', 'String', 20, 'RULE_ID', ' ', 'O', 'RES_LIST', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317155514');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'DSP_REASON', 15, ' ', ' ', ' ', ' ', 0, 'DSP_REASON', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317155514');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'UNSELECT_REASON', 16, 'Information of Dispatch calculation result. It shows unseleted reason.', ' ', ' ', 'String', 1000, 'UNSELECT_REASON', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155514', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'CAPABLE_REASON', 17, 'Information of Dispatch calculation result. It shows capable or uncapable reason.', ' ', ' ', 'String', 1000, 'CAPABLE_REASON', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155514', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'PDS_CMF_1', 18, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_1', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155514', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'PDS_CMF_2', 19, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_2', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155514', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'PDS_CMF_3', 20, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_3', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155514', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'PDS_CMF_4', 21, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_4', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155514', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'PDS_CMF_5', 22, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_5', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155514', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'PDS_CMF_6', 23, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_6', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155514', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'PDS_CMF_7', 24, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_7', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155514', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'PDS_CMF_8', 25, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_8', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155514', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'PDS_CMF_9', 26, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_9', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155514', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Get_Resource_Simulation_Result', 'O', 1, 'PDS_CMF_10', 27, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_10', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317155514', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Interface', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090211231838', 'ADMIN', '20090211231922');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Interface', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090211231839', 'ADMIN', '20090211231922');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Interface', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090211231839', 'ADMIN', '20090211231922');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Interface', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USERID', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090211231839', 'ADMIN', '20090211231922');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Interface', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090211231839', 'ADMIN', '20090211231922');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Interface', 'I', 0, 'PROCSTEP', 5, ' ', ' ', ' ', ' ', 0, 'PROCSTEP', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090211231839', 'ADMIN', '20090211231922');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Interface', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUSVALUE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090211231839', 'ADMIN', '20090211231922');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Interface', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSGCODE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090211231839', 'ADMIN', '20090211231922');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Interface', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090211231839', 'ADMIN', '20090211231922');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Interface', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSGCATE', ' ', 'M', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090211231839', 'ADMIN', '20090211231922');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Interface', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELDMSG', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090211231839', 'ADMIN', '20090211231922');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Interface', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DBERRMSG', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090211231839', 'ADMIN', '20090211231922');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': Re-Dispatch)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'I', 0, 'CHANGE_MEMBER', 6, ' ', ' ', ' ', ' ', 0, 'CHANGE_MEMBER', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'I', 0, 'LOT_ID', 7, 'Lot ID. Mandatory when CHANGE_MEMBER is Lot (LOT_ID).', ' ', ' ', 'String', 25, 'LOT_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'I', 0, 'BATCH_ID', 8, 'Batch ID.Mandatory when CHANGE_MEMBER is Batch (BATCH_ID).', ' ', ' ', 'String', 30, 'BATCH_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'I', 0, 'DSP_ID', 9, 'Dispatcher ID. Mandatory when CHANGE_MEMBER is Dispatcher (DSP_ID).', ' ', ' ', 'String', 20, 'DSP_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'I', 0, 'RULE_ID', 10, 'Dispatch Rule ID. Mandatory when CHANGE_MEMBER is Dispatcher Rule (RULE_ID).', ' ', ' ', 'String', 20, 'RULE_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'I', 0, 'MAT_ID', 11, 'Material ID (Product). Mandatory when CHANGE_MEMBER is Material (MAT_ID), Material-Flow-Oper(MFO), or Material-Oper(MO).', ' ', ' ', 'String', 30, 'MAT_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'I', 0, 'MAT_VER', 12, 'Material Version. Mandatory when CHANGE_MEMBER is Material (MAT_ID), Material-Flow-Oper(MFO), or Material-Oper(MO).', ' ', ' ', 'Int', 0, 'MAT_VER', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'I', 0, 'FLOW', 13, 'Flow. The group of unit operations. Mandatory when CHANGE_MEMBER is Flow (FLOW), Material-Flow-Oper(MFO), or Flow-Oper(FO).', ' ', ' ', 'String', 20, 'FLOW', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'I', 0, 'OPER', 14, 'Unit Operation. Mandatory when CHANGE_MEMBER is Oper (OPER), Material-Flow-Oper(MFO), Flow-Oper(FO), Material-Oper(MO).', ' ', ' ', 'String', 10, 'OPER', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'I', 0, 'RESG_ID', 15, 'Resource Group ID. Mandatory when CHANGE_MEMBER is Resource Group (RESG_ID).', ' ', ' ', 'String', 20, 'RESG_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'I', 0, 'RES_ID', 16, 'ResourceID (Equipment, Entity). Mandatory when CHANGE_MEMBER is Resource (RES_ID).', ' ', ' ', 'String', 20, 'RES_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'I', 0, 'RES_TYPE', 17, ' ', ' ', ' ', ' ', 0, 'RES_TYPE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'I', 0, 'UNSELECT_CAPABLE_ONLY_FLAG', 18, 'If this flag is set, RTD calurate unselect, capable only.', ' ', ' ', 'Char', 0, 'UNSELECT_CAPABLE_ONLY_FLAG', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20090317142337', 'ADMIN', '20090317142503');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Re_Dispatch_Lot', 'O', 0, 'CSTATUS', 6, ' ', ' ', ' ', ' ', 0, 'CSTATUS', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''I'': Create, ''U'': Modify, ''D'': Delete)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'I', 0, 'RELATION_LEVEL', 6, ' ', ' ', ' ', ' ', 0, 'RELATION_LEVEL', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'I', 0, 'MAT_ID', 7, 'Material ID (Product). Reserved (Not in Use).', ' ', ' ', 'String', 30, 'MAT_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'I', 0, 'MAT_VER', 8, 'Material Version. Reserved (Not in Use).', ' ', ' ', 'Int', 0, 'MAT_VER', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'I', 0, 'FLOW', 9, 'Flow. The group of unit operations. Reserved (Not in Use).', ' ', ' ', 'String', 20, 'FLOW', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'I', 0, 'OPER', 10, 'Unit Operation. Mandatory when RELATION_LEVEL is''O''.', ' ', ' ', 'String', 10, 'OPER', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'I', 0, 'RESG_ID', 11, 'Resource Group ID. Mandatory when RELATION_LEVEL is''G''.', ' ', ' ', 'String', 20, 'RESG_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'I', 0, 'RES_ID', 12, 'ResourceID (Equipment, Entity). Mandatory when RELATION_LEVEL is''R''.', ' ', ' ', 'String', 20, 'RES_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'I', 0, 'DSP_ID', 13, ' ', ' ', ' ', ' ', 0, 'DSP_ID', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatch_Relation', 'O', 0, 'CSTATUS', 6, ' ', ' ', ' ', ' ', 0, 'CSTATUS', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''I'': Create, ''U'': Modify, ''D'': Delete)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'I', 0, 'SIMULATION_FLAG', 6, ' ', ' ', ' ', ' ', 0, 'SIMULATION_FLAG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'I', 0, 'DSP_ID', 7, ' ', ' ', ' ', ' ', 0, 'DSP_ID', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'I', 0, 'DSP_DESC', 8, ' ', ' ', ' ', ' ', 0, 'DSP_DESC', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'I', 0, 'RES_OR_OPER', 9, 'Indication of Resource or Operation (''R'': By Resource, ''O'': By Operation). Additional configuration for Simulation mode. Mandatory when Simulation Flag is ''Y''.', ' ', ' ', 'Char', 1, 'RES_OR_OPER', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'I', 0, 'PRV_GRP_ID', 10, 'Privilege Group ID. To allow to access/use the Dispatcher ID only this Privilege Group Users. Additional configuration for Simulation mode.', ' ', ' ', 'String', 20, 'PRV_GRP_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'I', 0, 'MAX_COUNT', 11, 'Maximum Count of Reply. If it is defined, the Service replies only the limited # of records by this count. Additional configuration for Simulation mode.', ' ', ' ', 'Int', 0, 'MAX_COUNT', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'I', 0, 'LOT_RULE', 12, 'Rule ID of Lot Dispatching (What''s Next Rule). Mandatory when Simulation Flag is '' ''.', ' ', ' ', 'String', 20, 'LOT_RULE', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'I', 0, 'RESOURCE_RULE', 13, 'Rule ID of Resource Dispatching (Where Next Rule). Mandatory when Simulation Flag is'' ''.', ' ', ' ', 'String', 20, 'RESOURCE_RULE', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher', 'O', 0, 'CSTATUS', 6, ' ', ' ', ' ', ' ', 0, 'CSTATUS', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''I'': Create, ''U'': Modify, ''D'': Delete)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'SERVICE_NAME', 6, ' ', ' ', ' ', ' ', 0, 'SERVICE_NAME', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'SERVICE_SEQ', 7, ' ', ' ', ' ', ' ', 0, 'SERVICE_SEQ', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'SERVICE_DESC', 8, ' ', ' ', ' ', ' ', 0, 'SERVICE_DESC', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'CHK_MEMBER', 9, ' ', ' ', ' ', ' ', 0, 'CHK_MEMBER', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'CHK_FLAG', 10, 'Indication of whether or how to validate Check Member with Check Status or Check Table. (''='': Equal, ''!'': Not Equal, ''N'': Not Check, ''>'': Greater than, ''<'': Less than, ''T'': Check GCM Table)', ' ', ' ', 'Char', 1, 'CHK_FLAG', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'CHK_STS', 11, ' ', ' ', ' ', ' ', 0, 'CHK_STS', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'CHK_TBL', 12, ' ', ' ', ' ', ' ', 0, 'CHK_TBL', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'CHK_SQL', 13, ' ', ' ', ' ', ' ', 0, 'CHK_SQL', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'DEPENDENT_SEQ', 14, ' ', ' ', ' ', ' ', 0, 'DEPENDENT_SEQ', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'DEPENDENT_COMBINATION', 15, ' ', ' ', ' ', ' ', 0, 'DEPENDENT_COMBINATION', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'ACTION_ARRAY_1', 16, ' ', ' ', ' ', ' ', 0, 'ACTION_ARRAY_1', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'ACTION_ARRAY_2', 17, ' ', ' ', ' ', ' ', 0, 'ACTION_ARRAY_2', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'ACTION_MEMBER_1', 18, ' ', ' ', ' ', ' ', 0, 'ACTION_MEMBER_1', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'ACTION_MEMBER_2', 19, ' ', ' ', ' ', ' ', 0, 'ACTION_MEMBER_2', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'ACTION_MEMBER_3', 20, ' ', ' ', ' ', ' ', 0, 'ACTION_MEMBER_3', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'ACTION_MEMBER_4', 21, ' ', ' ', ' ', ' ', 0, 'ACTION_MEMBER_4', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'ACTION_FLAG', 22, ' ', ' ', ' ', ' ', 0, 'ACTION_FLAG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'CUSTOM_ACTION_KEY', 23, ' ', ' ', ' ', ' ', 0, 'CUSTOM_ACTION_KEY', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'I', 0, 'UNSELECT_CAPABLE_ONLY_FLAG', 24, 'If this flag is set, RTD calurate unselect, capable only.', ' ', ' ', 'Char', 0, 'UNSELECT_CAPABLE_ONLY_FLAG', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20090317142616', 'ADMIN', '20090317142721');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Event', 'O', 0, 'CSTATUS', 6, ' ', ' ', ' ', ' ', 0, 'CSTATUS', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Oper', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Oper', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Oper', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Oper', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Oper', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Oper', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''I'': Create, ''U'': Modify, ''D'': Delete)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Oper', 'I', 0, 'DSP_ID', 6, ' ', ' ', ' ', ' ', 0, 'DSP_ID', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Oper', 'I', 0, 'OPER', 7, 'Unit Operation. Assigned/De-Assigned for Dispatch Simulation.', ' ', ' ', 'String', 10, 'OPER', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Oper', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Oper', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Oper', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Oper', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Oper', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Oper', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Oper', 'O', 0, 'CSTATUS', 6, ' ', ' ', ' ', ' ', 0, 'CSTATUS', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Res', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Res', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Res', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Res', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Res', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Res', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''I'': Create, ''U'': Modify, ''D'': Delete)', ' ', ' ', 'Char', 0, 'PROC_STEP', ' ', 'M', ' ', 'Y', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317164316');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Res', 'I', 0, 'DSP_ID', 6, ' ', ' ', ' ', ' ', 0, 'DSP_ID', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Res', 'I', 0, 'RES_ID', 7, 'ResourceID (Equipment, Entity). Assigned/De-Assigned for Dispatch Simulation.', ' ', ' ', 'String', 20, 'RES_ID', ' ', 'M', ' ', 'Y', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317164337');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Res', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Res', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Res', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Res', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Res', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Res', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Dispatcher_Res', 'O', 0, 'CSTATUS', 6, ' ', ' ', ' ', ' ', 0, 'CSTATUS', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Reference_Operation', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Reference_Operation', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Reference_Operation', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Reference_Operation', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Reference_Operation', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Reference_Operation', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''I'': Create, ''U'': Modify, ''D'': Delete)', ' ', ' ', 'Char', 0, 'PROC_STEP', ' ', 'M', ' ', 'Y', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317164405');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Reference_Operation', 'I', 0, 'RELATION_LEVEL', 6, 'Level of relationship to assign Reference Operation to Target Operation  (''1'': Material-Flow-Operation, ''2'': Flow-Operation, ''3'': Operation, ''4'': Material-Operation)', ' ', ' ', 'Char', 1, 'RELATION_LEVEL', ' ', 'M', ' ', 'Y', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317164457');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Reference_Operation', 'I', 0, 'MAT_ID', 7, 'Material ID (Product). Mandatory when Relation Level is''1'' (Material-Flow-Operation) or ''4'' (Material-Operation) case.', ' ', ' ', 'String', 30, 'MAT_ID', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317164457');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Reference_Operation', 'I', 0, 'MAT_VER', 8, 'Material Version. Mandatory when Relation Level is''1'' (Material-Flow-Operation) or ''4'' (Material-Operation) case.', ' ', ' ', 'Int', 0, 'MAT_VER', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317164457');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Reference_Operation', 'I', 0, 'FLOW', 9, 'Flow. The group of unit operations. Mandatory when Relation Level is''2'' (Flow-Operation) case.', ' ', ' ', 'String', 20, 'FLOW', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317164457');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Reference_Operation', 'I', 0, 'OPER', 10, ' ', ' ', ' ', ' ', 0, 'OPER', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Reference_Operation', 'I', 0, 'REFERENCE_OPER', 11, ' ', ' ', ' ', ' ', 0, 'REFERENCE_OPER', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Reference_Operation', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Reference_Operation', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Reference_Operation', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Reference_Operation', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Reference_Operation', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Reference_Operation', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Reference_Operation', 'O', 0, 'CSTATUS', 6, ' ', ' ', ' ', ' ', 0, 'CSTATUS', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''I'': Create, ''U'': Modify, ''D'': Delete)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule', 'I', 0, 'RULE_ID', 6, 'Dispatch Rule ID', ' ', ' ', 'String', 20, 'RULE_ID', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule', 'I', 0, 'RULE_DESC', 7, ' ', ' ', ' ', ' ', 0, 'RULE_DESC', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule', 'I', 0, 'RULE_TYPE', 8, 'Dispatch Rule Type (''L'': Lot Dispatch (What''s Next Rule), ''R'': Resource Dispatch (Where Next Rule))', ' ', ' ', 'Char', 1, 'RULE_TYPE', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule', 'O', 0, 'CSTATUS', 6, ' ', ' ', ' ', ' ', 0, 'CSTATUS', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''I'': Create, ''U'': Modify, ''D'': Delete)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'RULE_ID', 6, 'Dispatch Rule ID', ' ', ' ', 'String', 20, 'RULE_ID', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'RULE_TYPE', 7, 'Dispatch Rule Type (''L'': Lot Dispatch (What''s Next Rule), ''R'': Resource Dispatch (Where Next Rule))', ' ', ' ', 'Char', 1, 'RULE_TYPE', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'PRIO_LEVEL', 8, ' ', ' ', ' ', ' ', 0, 'PRIO_LEVEL', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'PRIO_KEY', 9, ' ', ' ', ' ', ' ', 0, 'PRIO_KEY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'SORTING_TYPE', 10, ' ', ' ', ' ', ' ', 0, 'SORTING_TYPE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'CLASS_TYPE', 11, ' ', ' ', ' ', ' ', 0, 'CLASS_TYPE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'KEY_VALUE_1', 12, ' ', ' ', ' ', ' ', 0, 'KEY_VALUE_1', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'KEY_VALUE_2', 13, ' ', ' ', ' ', ' ', 0, 'KEY_VALUE_2', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'KEY_POINT', 14, ' ', ' ', ' ', ' ', 0, 'KEY_POINT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'LOT_TYPE', 15, 'Detail Type of Dispatch Rule Item especially LOT_INFO, RES_INFO Dispatch Rule ID case. (''L'': Lot Status, ''A'': Attribute of Lot or Resource, ''R'': Resource Status) OR Real-Time Calculation option for Custom Dispatch Rule (''Y'': Real-Time Calculation required, ''N'': No Real-Time Calculation)', ' ', ' ', 'Char', 0, 'LOT_TYPE', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'UNSELECT_FLAG', 16, ' ', ' ', ' ', ' ', 0, 'UNSELECT_FLAG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'CAPABLE_FLAG', 17, ' ', ' ', ' ', ' ', 0, 'CAPABLE_FLAG', ' ', 'O', ' ', ' ', ' ', 0, 0, 'ADMIN', '20090317142105', 'ADMIN', '20090317162850');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'TO_PRIO_LEVEL', 18, ' ', ' ', ' ', ' ', 0, 'TO_PRIO_LEVEL', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317142105');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'TO_PRIO_KEY', 19, ' ', ' ', ' ', ' ', 0, 'TO_PRIO_KEY', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317142105');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'TO_KEY_VALUE_1', 20, ' ', ' ', ' ', ' ', 0, 'TO_KEY_VALUE_1', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317142105');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'I', 0, 'TO_KEY_VALUE_2', 21, ' ', ' ', ' ', ' ', 0, 'TO_KEY_VALUE_2', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317142105');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_Update_Rule_Items', 'O', 0, 'CSTATUS', 6, ' ', ' ', ' ', ' ', 0, 'CSTATUS', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatch_Relation', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatch_Relation', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatch_Relation', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatch_Relation', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatch_Relation', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatch_Relation', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': By Relation Level and (Oper, Resource Group, or Resource))', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatch_Relation', 'I', 0, 'RELATION_LEVEL', 6, ' ', ' ', ' ', ' ', 0, 'RELATION_LEVEL', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatch_Relation', 'I', 0, 'OPER', 7, 'Unit Operation. Mandatory when Relation Level is''O''.', ' ', ' ', 'String', 10, 'OPER', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatch_Relation', 'I', 0, 'RESG_ID', 8, 'Resource Group ID. Mandatory when Relation Level is''G''.', ' ', ' ', 'String', 20, 'RESG_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatch_Relation', 'I', 0, 'RES_ID', 9, 'ResourceID (Equipment, Entity). Mandatory when Relation Level is''R''.', ' ', ' ', 'String', 20, 'RES_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatch_Relation', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatch_Relation', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatch_Relation', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatch_Relation', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatch_Relation', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatch_Relation', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatch_Relation', 'O', 0, 'DSP_ID', 6, ' ', ' ', ' ', ' ', 0, 'DSP_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (Process Step. Option for expansion (''1''-Excluding Unselectable Lot, ''2''-Including Unselectable Lot))', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'I', 0, 'RES_OPER_FLAG', 6, 'Indication of Resource or Operation (''R''-Resource, ''O''-Operation)', ' ', ' ', 'Char', 0, 'RES_OPER_FLAG', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'I', 0, 'RES_OPER_ID', 7, 'Resource or Operation ID. When RES_OPER_FLAG is''R'', then Resource ID and  when RES_OPER_FLAG is ''O'', then Operation ID.', ' ', ' ', 'String', 20, 'RES_OPER_ID', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'I', 0, 'MAX_COUNT', 8, ' ', ' ', ' ', ' ', 0, 'MAX_COUNT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'I', 0, 'INCLUDE_UNSELECT', 9, 'Indication of whether including Unseletable Item in Dispatch Result or not (''Y''-Including Unseletable Item)', ' ', ' ', 'Char', 0, 'INCLUDE_UNSELECT', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20090317143144', 'ADMIN', '20090317143439');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'I', 0, 'INCLUDE_UNCAPABLE', 10, 'Indication of whether including Uncapable Item in Dispatch Result or not (''Y''-Including Uncapable Item)', ' ', ' ', 'Char', 0, 'INCLUDE_UNCAPABLE', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20090317143208', 'ADMIN', '20090317143403');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 0, 'LIST', 6, ' ', ' ', ' ', 'List', 0, ' ', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'LOT_ID', 0, ' ', ' ', ' ', ' ', 0, 'LOT_ID', ' ', 'O', 'LIST', ' ', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090312093234');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'SET_OPER', 1, ' ', ' ', ' ', ' ', 0, 'SET_OPER', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'SET_RESG_ID', 2, ' ', ' ', ' ', ' ', 0, 'SET_RESG_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'SET_RES_ID', 3, ' ', ' ', ' ', ' ', 0, 'SET_RES_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'DSP_ID', 4, ' ', ' ', ' ', ' ', 0, 'DSP_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'RULE_ID', 5, ' ', ' ', ' ', ' ', 0, 'RULE_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'TEMP_BATCH_ID', 6, ' ', ' ', ' ', ' ', 0, 'TEMP_BATCH_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'CUR_OPER', 7, ' ', ' ', ' ', ' ', 0, 'CUR_OPER', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'REFERENCE_OPER', 8, ' ', ' ', ' ', ' ', 0, 'REFERENCE_OPER', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'UNSELECTED_FLAG', 9, ' ', ' ', ' ', ' ', 0, 'UNSELECTED_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'LOT_RESV_FLAG', 10, ' ', ' ', ' ', ' ', 0, 'LOT_RESV_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'LOT_RESV_TIME', 11, ' ', ' ', ' ', ' ', 0, 'LOT_RESV_TIME', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'CAPABLE_FLAG', 12, ' ', ' ', ' ', ' ', 0, 'CAPABLE_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'PRI_ADJUST_FLAG', 13, ' ', ' ', ' ', ' ', 0, 'PRI_ADJUST_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'PRIORITY_SCORE', 14, ' ', ' ', ' ', ' ', 0, 'PRIORITY_SCORE', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'PRIORITY_SUPPORT', 15, ' ', ' ', ' ', ' ', 0, 'PRIORITY_SUPPORT', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'HIST_SEQ', 16, ' ', ' ', ' ', ' ', 0, 'HIST_SEQ', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'PRI_ADJUST_REASON', 17, ' ', ' ', ' ', ' ', 0, 'PRI_ADJUST_REASON', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'TRIGGER_BY', 18, ' ', ' ', ' ', ' ', 0, 'TRIGGER_BY', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'DSP_REASON', 19, ' ', ' ', ' ', ' ', 0, 'DSP_REASON', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'UNSELECT_REASON', 20, 'Information of Dispatch calculation result. It shows unseleted reason.', ' ', ' ', 'String', 1000, 'UNSELECT_REASON', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317143910', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'CAPABLE_REASON', 21, 'Information of Dispatch calculation result. It shows capable or uncapable reason.', ' ', ' ', 'String', 1000, 'CAPABLE_REASON', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317143943', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'PDS_CMF_1', 22, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_1', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150938', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'PDS_CMF_2', 23, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_2', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150938', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'PDS_CMF_3', 24, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_3', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150938', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'PDS_CMF_4', 25, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_4', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150938', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'PDS_CMF_5', 26, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_5', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150938', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'PDS_CMF_6', 27, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_6', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150938', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'PDS_CMF_7', 28, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_7', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150938', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'PDS_CMF_8', 29, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_8', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150938', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'PDS_CMF_9', 30, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_9', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150938', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'PDS_CMF_10', 31, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_10', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150938', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'CREATE_USER_ID', 32, ' ', ' ', ' ', ' ', 0, 'CREATE_USER_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150937');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'CREATE_TIME', 33, ' ', ' ', ' ', ' ', 0, 'CREATE_TIME', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150937');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'UPDATE_USER_ID', 34, ' ', ' ', ' ', ' ', 0, 'UPDATE_USER_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'UPDATE_TIME', 35, ' ', ' ', ' ', ' ', 0, 'UPDATE_TIME', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'MAT_ID', 36, ' ', ' ', ' ', ' ', 0, 'MAT_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'MAT_VER', 37, ' ', ' ', ' ', ' ', 0, 'MAT_VER', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'FLOW', 38, ' ', ' ', ' ', ' ', 0, 'FLOW', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'FLOW_SEQ_NUM', 39, ' ', ' ', ' ', ' ', 0, 'FLOW_SEQ_NUM', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'OPER', 40, ' ', ' ', ' ', ' ', 0, 'OPER', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'QTY_1', 41, ' ', ' ', ' ', ' ', 0, 'QTY_1', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'QTY_2', 42, ' ', ' ', ' ', ' ', 0, 'QTY_2', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'QTY_3', 43, ' ', ' ', ' ', ' ', 0, 'QTY_3', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'LOT_TYPE', 44, ' ', ' ', ' ', ' ', 0, 'LOT_TYPE', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'CREATE_CODE', 45, ' ', ' ', ' ', ' ', 0, 'CREATE_CODE', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'OWNER_CODE', 46, ' ', ' ', ' ', ' ', 0, 'OWNER_CODE', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'LOT_PRIORITY', 47, ' ', ' ', ' ', ' ', 0, 'LOT_PRIORITY', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'LOT_STATUS', 48, ' ', ' ', ' ', ' ', 0, 'LOT_STATUS', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'HOLD_FLAG', 49, ' ', ' ', ' ', ' ', 0, 'HOLD_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'RWK_FLAG', 50, ' ', ' ', ' ', ' ', 0, 'RWK_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'NSTD_FLAG', 51, ' ', ' ', ' ', ' ', 0, 'NSTD_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'START_FLAG', 52, ' ', ' ', ' ', ' ', 0, 'START_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'REP_FLAG', 53, ' ', ' ', ' ', ' ', 0, 'REP_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'ORG_DUE_TIME', 54, ' ', ' ', ' ', ' ', 0, 'ORG_DUE_TIME', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'SCH_DUE_TIME', 55, ' ', ' ', ' ', ' ', 0, 'SCH_DUE_TIME', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'OPER_IN_TIME', 56, ' ', ' ', ' ', ' ', 0, 'OPER_IN_TIME', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Lot_List', 'O', 1, 'LAST_TRAN_CODE', 57, ' ', ' ', ' ', ' ', 0, 'LAST_TRAN_CODE', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317150938');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': Resource Dispatch List)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'I', 0, 'LOT_ID', 6, 'Lot ID', ' ', ' ', 'String', 25, 'LOT_ID', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'I', 0, 'NEXT_COUNT', 7, ' ', ' ', ' ', ' ', 0, 'NEXT_COUNT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'I', 0, 'INCLUDE_UNSELECT', 8, ' ', ' ', ' ', ' ', 0, 'INCLUDE_UNSELECT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'I', 0, 'INCLUDE_UNCAPABLE', 9, 'Indication of whether including Uncapable Item in Dispatch Result or not (''Y''-Including Uncapable Item)', ' ', ' ', 'Char', 0, 'INCLUDE_UNCAPABLE', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20090317143350', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 0, 'COUNT', 6, ' ', ' ', ' ', ' ', 0, 'COUNT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 0, 'NEXT_RES_ID', 7, ' ', ' ', ' ', ' ', 0, 'NEXT_RES_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 0, 'NEXT_COUNT', 8, ' ', ' ', ' ', ' ', 0, 'NEXT_COUNT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 0, 'RES_LIST', 9, ' ', ' ', ' ', 'List', 0, ' ', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'PRIORITY_SCORE', 0, ' ', ' ', ' ', ' ', 0, 'PRIORITY_SCORE', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'UNSELECT_FLAG', 1, ' ', ' ', ' ', ' ', 0, 'UNSELECT_FLAG', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'CAPABLE_FLAG', 2, ' ', ' ', ' ', ' ', 0, 'CAPABLE_FLAG', ' ', 'O', 'RES_LIST', ' ', ' ', 0, 0, 'ADMIN', '20090317163139', 'ADMIN', '20090317163146');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'DSP_REASON', 3, ' ', ' ', ' ', ' ', 0, 'DSP_REASON', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'UNSELECT_REASON', 4, 'Information of Dispatch calculation result. It shows unseleted reason.', ' ', ' ', 'String', 1000, 'UNSELECT_REASON', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317144323', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'CAPABLE_REASON', 5, 'Information of Dispatch calculation result. It shows capable or uncapable reason.', ' ', ' ', 'String', 1000, 'CAPABLE_REASON', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317144420', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'RES_ID', 6, ' ', ' ', ' ', ' ', 0, 'RES_ID', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317144420');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'RES_DESC', 7, ' ', ' ', ' ', ' ', 0, 'RES_DESC', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317144420');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'RES_TYPE', 8, ' ', ' ', ' ', ' ', 0, 'RES_TYPE', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317144420');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'AREA_ID', 9, ' ', ' ', ' ', ' ', 0, 'AREA_ID', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317144420');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'SUB_AREA_ID', 10, ' ', ' ', ' ', ' ', 0, 'SUB_AREA_ID', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317144420');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'RES_UP_DOWN_FLAG', 11, ' ', ' ', ' ', ' ', 0, 'RES_UP_DOWN_FLAG', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317144420');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'RES_PRI_STS', 12, ' ', ' ', ' ', ' ', 0, 'RES_PRI_STS', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317144420');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'LAST_EVENT_ID', 13, ' ', ' ', ' ', ' ', 0, 'LAST_EVENT_ID', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317144420');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'LAST_EVENT_TIME', 14, ' ', ' ', ' ', ' ', 0, 'LAST_EVENT_TIME', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317144420');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'LAST_START_TIME', 15, ' ', ' ', ' ', ' ', 0, 'LAST_START_TIME', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317144420');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'LAST_END_TIME', 16, ' ', ' ', ' ', ' ', 0, 'LAST_END_TIME', ' ', 'O', 'RES_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317144420');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'PDS_CMF_1', 17, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_1', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317144725', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'PDS_CMF_2', 18, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_2', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317144725', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'PDS_CMF_3', 19, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_3', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317144725', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'PDS_CMF_4', 20, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_4', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317144725', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'PDS_CMF_5', 21, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_5', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317144725', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'PDS_CMF_6', 22, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_6', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317144725', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'PDS_CMF_7', 23, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_7', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317144725', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'PDS_CMF_8', 24, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_8', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317144725', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'PDS_CMF_9', 25, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_9', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317144725', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatched_Resource_List', 'O', 1, 'PDS_CMF_10', 26, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_10', ' ', 'O', 'RES_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317144725', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': By Dispatcher ID)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'I', 0, 'DSP_ID', 6, ' ', ' ', ' ', ' ', 0, 'DSP_ID', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'O', 0, 'DSP_ID', 6, ' ', ' ', ' ', ' ', 0, 'DSP_ID', ' ', 'O', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'O', 0, 'DSP_DESC', 7, ' ', ' ', ' ', ' ', 0, 'DSP_DESC', ' ', 'O', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'O', 0, 'RES_OR_OPER', 8, ' ', ' ', ' ', ' ', 0, 'RES_OR_OPER', ' ', 'O', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'O', 0, 'MAX_COUNT', 9, ' ', ' ', ' ', ' ', 0, 'MAX_COUNT', ' ', 'O', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'O', 0, 'PRV_GRP_ID', 10, ' ', ' ', ' ', ' ', 0, 'PRV_GRP_ID', ' ', 'O', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'O', 0, 'CREATE_USER_ID', 11, ' ', ' ', ' ', ' ', 0, 'CREATE_USER_ID', ' ', 'O', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'O', 0, 'CREATE_TIME', 12, ' ', ' ', ' ', ' ', 0, 'CREATE_TIME', ' ', 'O', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'O', 0, 'UPDATE_USER_ID', 13, ' ', ' ', ' ', ' ', 0, 'UPDATE_USER_ID', ' ', 'O', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'O', 0, 'UPDATE_TIME', 14, ' ', ' ', ' ', ' ', 0, 'UPDATE_TIME', ' ', 'O', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'O', 0, 'LOT_RULE', 15, ' ', ' ', ' ', ' ', 0, 'LOT_RULE', ' ', 'O', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher', 'O', 0, 'RESOURCE_RULE', 16, ' ', ' ', ' ', ' ', 0, 'RESOURCE_RULE', ' ', 'O', ' ', 'N', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': By Service Name and Service Sequence)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'I', 0, 'SERVICE_NAME', 6, ' ', ' ', ' ', ' ', 0, 'SERVICE_NAME', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'I', 0, 'SERVICE_SEQ', 7, ' ', ' ', ' ', ' ', 0, 'SERVICE_SEQ', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'FACTORY', 6, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'SERVICE_NAME', 7, ' ', ' ', ' ', ' ', 0, 'SERVICE_NAME', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'SERVICE_SEQ', 8, ' ', ' ', ' ', ' ', 0, 'SERVICE_SEQ', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'SERVICE_DESC', 9, ' ', ' ', ' ', ' ', 0, 'SERVICE_DESC', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'CHK_MEMBER', 10, ' ', ' ', ' ', ' ', 0, 'CHK_MEMBER', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'CHK_FLAG', 11, 'Indication of whether or how to validate Check Member with Check Status or Check Table. (''='': Equal, ''!'': Not Equal, ''N'': Not Check, ''>'': Greater than, ''<'': Less than, ''T'': Check GCM Table)', ' ', ' ', 'Char', 1, 'CHK_FLAG', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'CHK_STS', 12, ' ', ' ', ' ', ' ', 0, 'CHK_STS', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'CHK_TBL', 13, ' ', ' ', ' ', ' ', 0, 'CHK_TBL', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'CHK_SQL', 14, ' ', ' ', ' ', ' ', 0, 'CHK_SQL', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'DEPENDENT_SEQ', 15, ' ', ' ', ' ', ' ', 0, 'DEPENDENT_SEQ', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'DEPENDENT_COMBINATION', 16, ' ', ' ', ' ', ' ', 0, 'DEPENDENT_COMBINATION', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'ACTION_ARRAY_1', 17, ' ', ' ', ' ', ' ', 0, 'ACTION_ARRAY_1', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'ACTION_ARRAY_2', 18, ' ', ' ', ' ', ' ', 0, 'ACTION_ARRAY_2', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'ACTION_MEMBER_1', 19, ' ', ' ', ' ', ' ', 0, 'ACTION_MEMBER_1', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'ACTION_MEMBER_2', 20, ' ', ' ', ' ', ' ', 0, 'ACTION_MEMBER_2', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'ACTION_MEMBER_3', 21, ' ', ' ', ' ', ' ', 0, 'ACTION_MEMBER_3', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'ACTION_MEMBER_4', 22, ' ', ' ', ' ', ' ', 0, 'ACTION_MEMBER_4', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'ACTION_FLAG', 23, ' ', ' ', ' ', ' ', 0, 'ACTION_FLAG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'CUSTOM_ACTION_KEY', 24, ' ', ' ', ' ', ' ', 0, 'CUSTOM_ACTION_KEY', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'CREATE_USER_ID', 25, ' ', ' ', ' ', ' ', 0, 'CREATE_USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'CREATE_TIME', 26, ' ', ' ', ' ', ' ', 0, 'CREATE_TIME', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'UPDATE_USER_ID', 27, ' ', ' ', ' ', ' ', 0, 'UPDATE_USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'UPDATE_TIME', 28, ' ', ' ', ' ', ' ', 0, 'UPDATE_TIME', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event', 'O', 0, 'UNSELECT_CAPABLE_ONLY_FLAG', 29, 'sss', ' ', ' ', 'Char', 0, 'UNSELECT_CAPABLE_ONLY_FLAG', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20090317144827', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': By Time Period. Lot ID, Resource is optional.)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'I', 0, 'LOT_ID', 6, ' ', ' ', ' ', ' ', 0, 'LOT_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'I', 0, 'RES_ID', 7, ' ', ' ', ' ', ' ', 0, 'RES_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'I', 0, 'FROM_TRAN_TIME', 8, ' ', ' ', ' ', ' ', 0, 'FROM_TRAN_TIME', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'I', 0, 'TO_TRAN_TIME', 9, ' ', ' ', ' ', ' ', 0, 'TO_TRAN_TIME', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'I', 0, 'NEXT_EVENT_SEQ', 10, ' ', ' ', ' ', ' ', 0, 'NEXT_EVENT_SEQ', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 0, 'NEXT_EVENT_SEQ', 6, ' ', ' ', ' ', ' ', 0, 'NEXT_EVENT_SEQ', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 0, 'LIST', 7, ' ', ' ', ' ', 'List', 0, ' ', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 1, 'TRAN_CODE', 0, 'Transaction Code of Dispatch Event ("PROCESS"-Process normally, "DELETE"-Delete Dispatch Event because of duplication)', ' ', ' ', 'String', 12, 'TRAN_CODE', ' ', 'O', 'LIST', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 1, 'TRAN_TIME', 1, ' ', ' ', ' ', ' ', 0, 'TRAN_TIME', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 1, 'CHANGE_MEMBER', 2, ' ', ' ', ' ', ' ', 0, 'CHANGE_MEMBER', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 1, 'LOT_ID', 3, ' ', ' ', ' ', ' ', 0, 'LOT_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 1, 'BATCH_ID', 4, ' ', ' ', ' ', ' ', 0, 'BATCH_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 1, 'DSP_ID', 5, ' ', ' ', ' ', ' ', 0, 'DSP_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 1, 'RULE_ID', 6, 'Dispatch Rule ID', ' ', ' ', 'String', 20, 'RULE_ID', ' ', 'O', 'LIST', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 1, 'MAT_ID', 7, ' ', ' ', ' ', ' ', 0, 'MAT_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 1, 'MAT_VER', 8, ' ', ' ', ' ', ' ', 0, 'MAT_VER', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 1, 'FLOW', 9, ' ', ' ', ' ', ' ', 0, 'FLOW', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 1, 'OPER', 10, ' ', ' ', ' ', ' ', 0, 'OPER', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 1, 'RESG_ID', 11, ' ', ' ', ' ', ' ', 0, 'RESG_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 1, 'RES_ID', 12, ' ', ' ', ' ', ' ', 0, 'RES_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 1, 'RES_TYPE', 13, ' ', ' ', ' ', ' ', 0, 'RES_TYPE', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 1, 'ETC_TYPE', 14, ' ', ' ', ' ', ' ', 0, 'ETC_TYPE', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 1, 'ETC_ID', 15, ' ', ' ', ' ', ' ', 0, 'ETC_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 1, 'CUSTOM_ACTION_KEY', 16, ' ', ' ', ' ', ' ', 0, 'CUSTOM_ACTION_KEY', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 1, 'CREATE_USER_ID', 17, ' ', ' ', ' ', ' ', 0, 'CREATE_USER_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 1, 'CREATE_TIME', 18, ' ', ' ', ' ', ' ', 0, 'CREATE_TIME', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_History', 'O', 1, 'UNSELECT_CAPABLE_ONLY_FLAG', 19, 'If this flag is set, RTD calurate unselect, capable only.', ' ', ' ', 'Char', 0, 'UNSELECT_CAPABLE_ONLY_FLAG', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317145923', 'ADMIN', '20090317150030');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_List', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_List', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_List', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_List', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_List', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_List', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': By Factory, ''2'': By Factory and Service Name)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_List', 'I', 0, 'NEXT_SERVICE_NAME', 6, 'The next Dispatch Service Name to inquiry remaining data from the last inquiry result. There is a maximum limitation to get data at one time. Usually"Next Value" uses when it needs more than one service call to get a large amount of data exceeding the maximum limit. Set blank to get data from the beginning. Mandatory when Process Step is ''2''.', ' ', ' ', 'String', 100, 'NEXT_SERVICE_NAME', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_List', 'I', 0, 'NEXT_SERVICE_SEQ', 7, ' ', ' ', ' ', ' ', 0, 'NEXT_SERVICE_SEQ', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_List', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_List', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_List', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_List', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_List', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_List', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_List', 'O', 0, 'NEXT_SERVICE_NAME', 6, ' ', ' ', ' ', ' ', 0, 'NEXT_SERVICE_NAME', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_List', 'O', 0, 'NEXT_SERVICE_SEQ', 7, ' ', ' ', ' ', ' ', 0, 'NEXT_SERVICE_SEQ', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_List', 'O', 0, 'SERVICE_LIST', 8, 'Service List', ' ', ' ', 'List', 0, ' ', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_List', 'O', 1, 'SERVICE_NAME', 0, ' ', ' ', ' ', ' ', 0, 'SERVICE_NAME', ' ', 'O', 'SERVICE_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_List', 'O', 1, 'SERVICE_SEQ', 1, ' ', ' ', ' ', ' ', 0, 'SERVICE_SEQ', ' ', 'O', 'SERVICE_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_Event_List', 'O', 1, 'SERVICE_DESC', 2, ' ', ' ', ' ', ' ', 0, 'SERVICE_DESC', ' ', 'O', 'SERVICE_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': By Factory, ''2'': Simulation only. By Factory with checking Privilege Group)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'I', 0, 'NEXT_DSP_ID', 6, ' ', ' ', ' ', ' ', 0, 'NEXT_DSP_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'O', 0, 'NEXT_DSP_ID', 6, ' ', ' ', ' ', ' ', 0, 'NEXT_DSP_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'O', 0, 'DSP_LIST', 7, ' ', ' ', ' ', 'List', 0, ' ', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'O', 1, 'DSP_ID', 0, ' ', ' ', ' ', ' ', 0, 'DSP_ID', ' ', 'O', 'DSP_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'O', 1, 'DSP_DESC', 1, ' ', ' ', ' ', ' ', 0, 'DSP_DESC', ' ', 'O', 'DSP_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'O', 1, 'RES_OR_OPER', 2, ' ', ' ', ' ', ' ', 0, 'RES_OR_OPER', ' ', 'O', 'DSP_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'O', 1, 'MAX_COUNT', 3, ' ', ' ', ' ', ' ', 0, 'MAX_COUNT', ' ', 'O', 'DSP_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'O', 1, 'PRV_GRP_ID', 4, ' ', ' ', ' ', ' ', 0, 'PRV_GRP_ID', ' ', 'O', 'DSP_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'O', 1, 'LOT_RULE', 5, ' ', ' ', ' ', ' ', 0, 'LOT_RULE', ' ', 'O', 'DSP_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Dispatcher_List', 'O', 1, 'RESOURCE_RULE', 6, ' ', ' ', ' ', ' ', 0, 'RESOURCE_RULE', ' ', 'O', 'DSP_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspOper_List', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspOper_List', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspOper_List', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspOper_List', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspOper_List', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspOper_List', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': By Factory, Dispatcher ID)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspOper_List', 'I', 0, 'NEXT_DSP_ID', 6, 'Dispatcher ID', ' ', ' ', 'String', 20, 'NEXT_DSP_ID', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspOper_List', 'I', 0, 'NEXT_OPER', 7, ' ', ' ', ' ', ' ', 0, 'NEXT_OPER', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspOper_List', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspOper_List', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspOper_List', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspOper_List', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspOper_List', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspOper_List', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspOper_List', 'O', 0, 'NEXT_OPER', 6, ' ', ' ', ' ', ' ', 0, 'NEXT_OPER', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspOper_List', 'O', 0, 'DSP_LIST', 7, 'Dispatch Operation List', ' ', ' ', 'List', 0, ' ', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspOper_List', 'O', 1, 'OPER', 0, 'Operation which is assigned to the Dispatcher ID', ' ', ' ', 'String', 10, 'OPER', ' ', 'O', 'DSP_LIST', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspOper_List', 'O', 1, 'OPER_DESC', 1, ' ', ' ', ' ', ' ', 0, 'OPER_DESC', ' ', 'O', 'DSP_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspRes_List', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspRes_List', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspRes_List', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspRes_List', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspRes_List', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspRes_List', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': By Factory, Dispatcher ID)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspRes_List', 'I', 0, 'NEXT_DSP_ID', 6, 'Dispatcher ID', ' ', ' ', 'String', 20, 'NEXT_DSP_ID', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspRes_List', 'I', 0, 'NEXT_RES_ID', 7, ' ', ' ', ' ', ' ', 0, 'NEXT_RES_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspRes_List', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspRes_List', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspRes_List', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspRes_List', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspRes_List', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspRes_List', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspRes_List', 'O', 0, 'NEXT_RES_ID', 6, ' ', ' ', ' ', ' ', 0, 'NEXT_RES_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspRes_List', 'O', 0, 'DSP_LIST', 7, 'Dispatch Resource List', ' ', ' ', 'List', 0, ' ', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspRes_List', 'O', 1, 'RES_ID', 0, 'Resource ID which is assigned the Dispatcher ID', ' ', ' ', 'String', 20, 'RES_ID', ' ', 'O', 'DSP_LIST', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_DspRes_List', 'O', 1, 'RES_DESC', 1, ' ', ' ', ' ', ' ', 0, 'RES_DESC', ' ', 'O', 'DSP_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': By Time Period. Lot ID is optional)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'I', 0, 'LOT_ID', 6, ' ', ' ', ' ', ' ', 0, 'LOT_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'I', 0, 'FROM_TRAN_TIME', 7, ' ', ' ', ' ', ' ', 0, 'FROM_TRAN_TIME', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'I', 0, 'TO_TRAN_TIME', 8, ' ', ' ', ' ', ' ', 0, 'TO_TRAN_TIME', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'I', 0, 'NEXT_ROW_SEQ', 9, ' ', ' ', ' ', ' ', 0, 'NEXT_ROW_SEQ', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 0, 'NEXT_ROW_SEQ', 6, ' ', ' ', ' ', ' ', 0, 'NEXT_ROW_SEQ', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 0, 'LIST', 7, ' ', ' ', ' ', 'List', 0, ' ', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'TRAN_TIME', 0, ' ', ' ', ' ', ' ', 0, 'TRAN_TIME', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'FACTORY', 1, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'RES_OPER_FLAG', 2, ' ', ' ', ' ', ' ', 0, 'RES_OPER_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'RES_OPER_ID', 3, ' ', ' ', ' ', ' ', 0, 'RES_OPER_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'LOT_ID', 4, ' ', ' ', ' ', ' ', 0, 'LOT_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'SET_OPER', 5, ' ', ' ', ' ', ' ', 0, 'SET_OPER', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'SET_RESG_ID', 6, ' ', ' ', ' ', ' ', 0, 'SET_RESG_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'SET_RES_ID', 7, ' ', ' ', ' ', ' ', 0, 'SET_RES_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'DSP_ID', 8, ' ', ' ', ' ', ' ', 0, 'DSP_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'RULE_ID', 9, 'Dispatch Rule ID', ' ', ' ', 'String', 20, 'RULE_ID', ' ', 'O', 'LIST', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'TEMP_BATCH_ID', 10, ' ', ' ', ' ', ' ', 0, 'TEMP_BATCH_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'CUR_OPER', 11, ' ', ' ', ' ', ' ', 0, 'CUR_OPER', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'REFERENCE_OPER', 12, ' ', ' ', ' ', ' ', 0, 'REFERENCE_OPER', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'UNSELECTED_FLAG', 13, ' ', ' ', ' ', ' ', 0, 'UNSELECTED_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'LOT_RESV_FLAG', 14, ' ', ' ', ' ', ' ', 0, 'LOT_RESV_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'LOT_RESV_TIME', 15, ' ', ' ', ' ', ' ', 0, 'LOT_RESV_TIME', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'CAPABLE_FLAG', 16, ' ', ' ', ' ', ' ', 0, 'CAPABLE_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'PRI_ADJUST_FLAG', 17, ' ', ' ', ' ', ' ', 0, 'PRI_ADJUST_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'PRIORITY_SCORE', 18, ' ', ' ', ' ', ' ', 0, 'PRIORITY_SCORE', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'HIST_SEQ', 19, ' ', ' ', ' ', ' ', 0, 'HIST_SEQ', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'PRI_ADJUST_REASON', 20, ' ', ' ', ' ', ' ', 0, 'PRI_ADJUST_REASON', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'TRIGGER_BY', 21, ' ', ' ', ' ', ' ', 0, 'TRIGGER_BY', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'DSP_REASON', 22, ' ', ' ', ' ', ' ', 0, 'DSP_REASON', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'UNSELECT_REASON', 23, 'Information of Dispatch calculation result. It shows unseleted reason.', ' ', ' ', 'String', 1000, 'UNSELECT_REASON', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150608', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'CAPABLE_REASON', 24, 'Information of Dispatch calculation result. It shows capable or uncapable reason.', ' ', ' ', 'String', 1000, 'CAPABLE_REASON', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317151051', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'PDS_CMF_1', 25, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_1', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150757', 'ADMIN', '20090317151051');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'PDS_CMF_2', 26, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_2', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150757', 'ADMIN', '20090317151051');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'PDS_CMF_3', 27, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_3', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150757', 'ADMIN', '20090317151051');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'PDS_CMF_4', 28, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_4', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150757', 'ADMIN', '20090317151051');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'PDS_CMF_5', 29, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_5', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150757', 'ADMIN', '20090317151051');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'PDS_CMF_6', 30, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_6', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150757', 'ADMIN', '20090317151051');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'PDS_CMF_7', 31, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_7', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150757', 'ADMIN', '20090317151051');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'PDS_CMF_8', 32, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_8', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150757', 'ADMIN', '20090317151051');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'PDS_CMF_9', 33, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_9', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150757', 'ADMIN', '20090317151051');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'PDS_CMF_10', 34, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_10', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317150757', 'ADMIN', '20090317151051');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'CREATE_USER_ID', 35, ' ', ' ', ' ', ' ', 0, 'CREATE_USER_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151051');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_History', 'O', 1, 'CREATE_TIME', 36, ' ', ' ', ' ', ' ', 0, 'CREATE_TIME', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151051');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': By Factory, Res_Oper_Flag, Res_Oper_ID, Including Unselectable, Lot Status is WAIT excluding Lot in Reference Operation for Look-Ahead, Lot is not on Hold, and Qty 1 is not zero)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'I', 0, 'RES_OPER_FLAG', 6, ' ', ' ', ' ', ' ', 0, 'RES_OPER_FLAG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'I', 0, 'RES_OPER_ID', 7, ' ', ' ', ' ', ' ', 0, 'RES_OPER_ID', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'I', 0, 'NEXT_INDEX', 8, ' ', ' ', ' ', ' ', 0, 'NEXT_INDEX', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 0, 'NEXT_INDEX', 6, ' ', ' ', ' ', ' ', 0, 'NEXT_INDEX', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 0, 'LIST', 7, ' ', ' ', ' ', 'List', 0, ' ', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'LOT_ID', 0, ' ', ' ', ' ', ' ', 0, 'LOT_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'SET_OPER', 1, ' ', ' ', ' ', ' ', 0, 'SET_OPER', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'SET_RESG_ID', 2, ' ', ' ', ' ', ' ', 0, 'SET_RESG_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'SET_RES_ID', 3, ' ', ' ', ' ', ' ', 0, 'SET_RES_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'DSP_ID', 4, ' ', ' ', ' ', ' ', 0, 'DSP_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'RULE_ID', 5, 'Dispatch Rule ID', ' ', ' ', 'String', 20, 'RULE_ID', ' ', 'O', 'LIST', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'TEMP_BATCH_ID', 6, ' ', ' ', ' ', ' ', 0, 'TEMP_BATCH_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'CUR_OPER', 7, ' ', ' ', ' ', ' ', 0, 'CUR_OPER', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'REFERENCE_OPER', 8, ' ', ' ', ' ', ' ', 0, 'REFERENCE_OPER', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'UNSELECTED_FLAG', 9, ' ', ' ', ' ', ' ', 0, 'UNSELECTED_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'LOT_RESV_FLAG', 10, ' ', ' ', ' ', ' ', 0, 'LOT_RESV_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'LOT_RESV_TIME', 11, ' ', ' ', ' ', ' ', 0, 'LOT_RESV_TIME', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'CAPABLE_FLAG', 12, ' ', ' ', ' ', ' ', 0, 'CAPABLE_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'PRI_ADJUST_FLAG', 13, ' ', ' ', ' ', ' ', 0, 'PRI_ADJUST_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'PRIORITY_SCORE', 14, ' ', ' ', ' ', ' ', 0, 'PRIORITY_SCORE', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'HIST_SEQ', 15, ' ', ' ', ' ', ' ', 0, 'HIST_SEQ', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'PRI_ADJUST_REASON', 16, ' ', ' ', ' ', ' ', 0, 'PRI_ADJUST_REASON', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'TRIGGER_BY', 17, ' ', ' ', ' ', ' ', 0, 'TRIGGER_BY', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'DSP_REASON', 18, ' ', ' ', ' ', ' ', 0, 'DSP_REASON', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'UNSELECT_REASON', 19, 'Information of Dispatch calculation result. It shows unseleted reason.', ' ', ' ', 'String', 1000, 'UNSELECT_REASON', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317151216', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'CAPABLE_REASON', 20, 'Information of Dispatch calculation result. It shows capable or uncapable reason.', ' ', ' ', 'String', 1000, 'CAPABLE_REASON', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317151216', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'PDS_CMF_1', 21, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_1', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317151353', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'PDS_CMF_2', 22, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_2', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317151353', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'PDS_CMF_3', 23, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_3', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317151353', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'PDS_CMF_4', 24, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_4', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317151353', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'PDS_CMF_5', 25, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_5', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317151353', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'PDS_CMF_6', 26, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_6', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317151353', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'PDS_CMF_7', 27, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_7', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317151353', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'PDS_CMF_8', 28, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_8', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317151353', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'PDS_CMF_9', 29, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_9', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317151353', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'PDS_CMF_10', 30, 'Customized field', ' ', ' ', 'String', 30, 'PDS_CMF_10', ' ', 'O', 'LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317151353', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'CREATE_USER_ID', 31, ' ', ' ', ' ', ' ', 0, 'CREATE_USER_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'CREATE_TIME', 32, ' ', ' ', ' ', ' ', 0, 'CREATE_TIME', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'MAT_ID', 33, ' ', ' ', ' ', ' ', 0, 'MAT_ID', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'MAT_VER', 34, ' ', ' ', ' ', ' ', 0, 'MAT_VER', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'FLOW', 35, ' ', ' ', ' ', ' ', 0, 'FLOW', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'FLOW_SEQ_NUM', 36, ' ', ' ', ' ', ' ', 0, 'FLOW_SEQ_NUM', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'OPER', 37, ' ', ' ', ' ', ' ', 0, 'OPER', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'QTY_1', 38, ' ', ' ', ' ', ' ', 0, 'QTY_1', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'QTY_2', 39, ' ', ' ', ' ', ' ', 0, 'QTY_2', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'QTY_3', 40, ' ', ' ', ' ', ' ', 0, 'QTY_3', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'LOT_TYPE', 41, ' ', ' ', ' ', ' ', 0, 'LOT_TYPE', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'OWNER_CODE', 42, ' ', ' ', ' ', ' ', 0, 'OWNER_CODE', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'CREATE_CODE', 43, ' ', ' ', ' ', ' ', 0, 'CREATE_CODE', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'LOT_PRIORITY', 44, ' ', ' ', ' ', ' ', 0, 'LOT_PRIORITY', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'LOT_STATUS', 45, ' ', ' ', ' ', ' ', 0, 'LOT_STATUS', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'RWK_FLAG', 46, ' ', ' ', ' ', ' ', 0, 'RWK_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'NSTD_FLAG', 47, ' ', ' ', ' ', ' ', 0, 'NSTD_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'START_FLAG', 48, ' ', ' ', ' ', ' ', 0, 'START_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'REP_FLAG', 49, ' ', ' ', ' ', ' ', 0, 'REP_FLAG', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'ORG_DUE_TIME', 50, ' ', ' ', ' ', ' ', 0, 'ORG_DUE_TIME', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'SCH_DUE_TIME', 51, ' ', ' ', ' ', ' ', 0, 'SCH_DUE_TIME', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'OPER_IN_TIME', 52, ' ', ' ', ' ', ' ', 0, 'OPER_IN_TIME', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Pre_Dispatched_Status', 'O', 1, 'LAST_TRAN_CODE', 53, ' ', ' ', ' ', ' ', 0, 'LAST_TRAN_CODE', ' ', 'O', 'LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317151353');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': By Relation Level and Operation. Material, Material Version, Flow is optional)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'I', 0, 'RELATION_LEVEL', 6, ' ', ' ', ' ', ' ', 0, 'RELATION_LEVEL', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'I', 0, 'MAT_ID', 7, 'Material ID (Product). Mandatory when Relation Level is''1'' (Material-Flow-Operation), ''4'' (Material-Operation).', ' ', ' ', 'String', 30, 'MAT_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'I', 0, 'MAT_VER', 8, 'Material Version. Mandatory when Relation Level is''1'' (Material-Flow-Operation), ''4'' (Material-Operation).', ' ', ' ', 'Int', 0, 'MAT_VER', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'I', 0, 'FLOW', 9, 'Flow. The group of operations. Mandatory when Relation Level is''1'' (Material-Flow-Operation), ''2'' (Flow-Operation).', ' ', ' ', 'String', 20, 'FLOW', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'I', 0, 'OPER', 10, ' ', ' ', ' ', ' ', 0, 'OPER', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'O', 0, 'REFERENCE_OPER', 6, ' ', ' ', ' ', ' ', 0, 'REFERENCE_OPER', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'O', 0, 'CREATE_USER_ID', 7, ' ', ' ', ' ', ' ', 0, 'CREATE_USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'O', 0, 'CREATE_TIME', 8, ' ', ' ', ' ', ' ', 0, 'CREATE_TIME', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'O', 0, 'UPDATE_USER_ID', 9, ' ', ' ', ' ', ' ', 0, 'UPDATE_USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Reference_Operation', 'O', 0, 'UPDATE_TIME', 10, ' ', ' ', ' ', ' ', 0, 'UPDATE_TIME', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Resource_PriSts', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Resource_PriSts', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Resource_PriSts', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Resource_PriSts', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Resource_PriSts', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Resource_PriSts', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': Unique list of CHG_PRI_STS by Factory)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Resource_PriSts', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Resource_PriSts', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Resource_PriSts', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Resource_PriSts', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Resource_PriSts', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Resource_PriSts', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Resource_PriSts', 'O', 0, 'STS_LIST', 6, ' ', ' ', ' ', 'List', 0, ' ', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Resource_PriSts', 'O', 1, 'RES_PRI_STS', 0, ' ', ' ', ' ', ' ', 0, 'RES_PRI_STS', ' ', 'O', 'STS_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': By Factory, Rule ID)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule', 'I', 0, 'RULE_ID', 6, 'Dispatch Rule ID', ' ', ' ', 'String', 20, 'RULE_ID', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule', 'O', 0, 'RULE_ID', 6, 'Dispatch Rule ID', ' ', ' ', 'String', 20, 'RULE_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule', 'O', 0, 'RULE_DESC', 7, ' ', ' ', ' ', ' ', 0, 'RULE_DESC', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule', 'O', 0, 'RULE_TYPE', 8, 'Dispatch Rule Type (''L'': Lot Dispatch (What''s Next Rule), ''R'': Resource Dispatch (Where Next Rule))', ' ', ' ', 'Char', 1, 'RULE_TYPE', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule', 'O', 0, 'CREATE_USER_ID', 9, ' ', ' ', ' ', ' ', 0, 'CREATE_USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule', 'O', 0, 'CREATE_TIME', 10, ' ', ' ', ' ', ' ', 0, 'CREATE_TIME', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule', 'O', 0, 'UPDATE_USER_ID', 11, ' ', ' ', ' ', ' ', 0, 'UPDATE_USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule', 'O', 0, 'UPDATE_TIME', 12, ' ', ' ', ' ', ' ', 0, 'UPDATE_TIME', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': By Factory, Rule ID, Rule Type, Priority Level, Priority Key, Key Value1, Key Value 2)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'I', 0, 'RULE_ID', 6, 'Dispatch Rule ID', ' ', ' ', 'String', 20, 'RULE_ID', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'I', 0, 'RULE_TYPE', 7, 'Dispatch Rule Type (''L'': Lot Dispatch (What''s Next Rule), ''R'': Resource Dispatch (Where Next Rule))', ' ', ' ', 'Char', 1, 'RULE_TYPE', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'I', 0, 'PRIO_LEVEL', 8, ' ', ' ', ' ', ' ', 0, 'PRIO_LEVEL', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'I', 0, 'PRIO_KEY', 9, ' ', ' ', ' ', ' ', 0, 'PRIO_KEY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'I', 0, 'KEY_VALUE_1', 10, ' ', ' ', ' ', ' ', 0, 'KEY_VALUE_1', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'I', 0, 'KEY_VALUE_2', 11, ' ', ' ', ' ', ' ', 0, 'KEY_VALUE_2', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'RULE_ID', 6, 'Dispatch Rule ID', ' ', ' ', 'String', 20, 'RULE_ID', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'RULE_TYPE', 7, 'Dispatch Rule Type (''L'': Lot Dispatch (What''s Next Rule), ''R'': Resource Dispatch (Where Next Rule))', ' ', ' ', 'Char', 1, 'RULE_TYPE', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'PRIO_LEVEL', 8, ' ', ' ', ' ', ' ', 0, 'PRIO_LEVEL', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'PRIO_KEY', 9, ' ', ' ', ' ', ' ', 0, 'PRIO_KEY', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'SORTING_TYPE', 10, ' ', ' ', ' ', ' ', 0, 'SORTING_TYPE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'CLASS_TYPE', 11, ' ', ' ', ' ', ' ', 0, 'CLASS_TYPE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'KEY_VALUE_1', 12, ' ', ' ', ' ', ' ', 0, 'KEY_VALUE_1', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'KEY_VALUE_2', 13, ' ', ' ', ' ', ' ', 0, 'KEY_VALUE_2', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'KEY_POINT', 14, ' ', ' ', ' ', ' ', 0, 'KEY_POINT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'LOT_TYPE', 15, 'Detail Type of Dispatch Rule Item especially LOT_INFO, RES_INFO Dispatch Rule ID case. (''L'': Lot Status, ''A'': Attribute of Lot or Resource, ''R'': Resource Status) OR Real-Time Calculation option for Custom Dispatch Rule (''Y'': Real-Time Calculation required, ''N'': No Real-Time Calculation)', ' ', ' ', 'Char', 0, 'LOT_TYPE', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'UNSELECT_FLAG', 16, ' ', ' ', ' ', ' ', 0, 'UNSELECT_FLAG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'CAPABLE_FLAG', 17, 'Indication of the Lot is capable or not by Dispatch calculation result (''Y'': Capable   ''N'': Uncapable)', ' ', ' ', 'Char', 0, 'CAPABLE_FLAG', ' ', 'O', ' ', 'Y', ' ', 0, 0, 'ADMIN', '20090317152136', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'CREATE_USER_ID', 18, ' ', ' ', ' ', ' ', 0, 'CREATE_USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317152136');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'CREATE_TIME', 19, ' ', ' ', ' ', ' ', 0, 'CREATE_TIME', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317152136');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'UPDATE_USER_ID', 20, ' ', ' ', ' ', ' ', 0, 'UPDATE_USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317152136');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'UPDATE_TIME', 21, ' ', ' ', ' ', ' ', 0, 'UPDATE_TIME', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317152136');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item', 'O', 0, 'VALUE_COUNT', 22, 'Number of Required Value to configure Custom Batch Rule correctly (''0'': No Required Value, ''1'', Value 1 required to input, ''2'': Value 1 and Value 2 required to input)', ' ', ' ', 'Int', 0, 'VALUE_COUNT', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', 'ADMIN', '20090317152136');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': By Factory, Rule ID, Rule Type. Order by Priority Level Ascending and Key Point Descending)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'I', 0, 'RULE_ID', 6, 'Dispatch Rule ID', ' ', ' ', 'String', 20, 'RULE_ID', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'I', 0, 'RULE_TYPE', 7, 'Dispatch Rule Type (''L'': Lot Dispatch (What''s Next Rule), ''R'': Resource Dispatch (Where Next Rule))', ' ', ' ', 'Char', 1, 'RULE_TYPE', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'I', 0, 'NEXT_PRIO_LEVEL', 8, ' ', ' ', ' ', ' ', 0, 'NEXT_PRIO_LEVEL', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'I', 0, 'NEXT_KEY_POINT', 9, ' ', ' ', ' ', ' ', 0, 'NEXT_KEY_POINT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'O', 0, 'NEXT_PRIO_LEVEL', 6, ' ', ' ', ' ', ' ', 0, 'NEXT_PRIO_LEVEL', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'O', 0, 'NEXT_KEY_POINT', 7, ' ', ' ', ' ', ' ', 0, 'NEXT_KEY_POINT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'O', 0, 'DSP_LIST', 8, 'Dispatch Rule Item List', ' ', ' ', 'List', 0, ' ', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'O', 1, 'PRIO_LEVEL', 0, ' ', ' ', ' ', ' ', 0, 'PRIO_LEVEL', ' ', 'O', 'DSP_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'O', 1, 'PRIO_KEY', 1, ' ', ' ', ' ', ' ', 0, 'PRIO_KEY', ' ', 'O', 'DSP_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'O', 1, 'SORTING_TYPE', 2, ' ', ' ', ' ', ' ', 0, 'SORTING_TYPE', ' ', 'O', 'DSP_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'O', 1, 'CLASS_TYPE', 3, ' ', ' ', ' ', ' ', 0, 'CLASS_TYPE', ' ', 'O', 'DSP_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'O', 1, 'KEY_VALUE_1', 4, ' ', ' ', ' ', ' ', 0, 'KEY_VALUE_1', ' ', 'O', 'DSP_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'O', 1, 'KEY_VALUE_2', 5, ' ', ' ', ' ', ' ', 0, 'KEY_VALUE_2', ' ', 'O', 'DSP_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'O', 1, 'KEY_POINT', 6, ' ', ' ', ' ', ' ', 0, 'KEY_POINT', ' ', 'O', 'DSP_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'O', 1, 'LOT_TYPE', 7, 'Detail Type of Dispatch Rule Item especially LOT_INFO, RES_INFO Dispatch Rule ID case. (''L'': Lot Status, ''A'': Attribute of Lot or Resource, ''R'': Resource Status) OR Real-Time Calculation option for Custom Dispatch Rule (''Y'': Real-Time Calculation required, ''N'': No Real-Time Calculation)', ' ', ' ', 'Char', 0, 'LOT_TYPE', ' ', 'O', 'DSP_LIST', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'O', 1, 'UNSELECT_FLAG', 8, ' ', ' ', ' ', ' ', 0, 'UNSELECT_FLAG', ' ', 'O', 'DSP_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_Item_List', 'O', 1, 'CAPABLE_FLAG', 9, 'Indication of the Lot is capable or not by Dispatch calculation result (''Y'': Capable   ''N'': Uncapable)', ' ', ' ', 'Char', 1, 'CAPABLE_FLAG', ' ', 'O', 'DSP_LIST', 'Y', ' ', 0, 0, 'ADMIN', '20090317153149', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_List', 'I', 0, 'PASSPORT', 0, ' ', ' ', ' ', ' ', 0, 'PASSPORT', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_List', 'I', 0, 'LANGUAGE', 1, ' ', ' ', ' ', ' ', 0, 'LANGUAGE', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_List', 'I', 0, 'FACTORY', 2, ' ', ' ', ' ', ' ', 0, 'FACTORY', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_List', 'I', 0, 'USERID', 3, ' ', ' ', ' ', ' ', 0, 'USER_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_List', 'I', 0, 'PASSWORD', 4, ' ', ' ', ' ', ' ', 0, 'PASSWORD', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_List', 'I', 0, 'PROCSTEP', 5, 'Process Step. Option for expansion (''1'': By Factory. If Rule Type is specified, then By Factory and Rule Type)', ' ', ' ', 'Char', 1, 'PROC_STEP', ' ', 'M', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_List', 'I', 0, 'RULE_TYPE', 6, 'Dispatch Rule Type (''L'': Lot Dispatch (What''s Next Rule), ''R'': Resource Dispatch (Where Next Rule)).', ' ', ' ', 'Char', 0, 'RULE_TYPE', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_List', 'I', 0, 'NEXT_RULE_ID', 7, ' ', ' ', ' ', ' ', 0, 'NEXT_RULE_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_List', 'O', 0, 'STATUSVALUE', 0, ' ', ' ', ' ', ' ', 0, 'STATUS_VALUE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_List', 'O', 0, 'MSGCODE', 1, ' ', ' ', ' ', ' ', 0, 'MSG_CODE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_List', 'O', 0, 'MSG', 2, ' ', ' ', ' ', ' ', 0, 'MSG', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_List', 'O', 0, 'MSGCATE', 3, ' ', ' ', ' ', ' ', 0, 'MSG_CATE', ' ', 'M', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_List', 'O', 0, 'FIELDMSG', 4, ' ', ' ', ' ', ' ', 0, 'FIELD_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_List', 'O', 0, 'DBERRMSG', 5, ' ', ' ', ' ', ' ', 0, 'DB_ERR_MSG', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_List', 'O', 0, 'NEXT_RULE_ID', 6, ' ', ' ', ' ', ' ', 0, 'NEXT_RULE_ID', ' ', 'O', ' ', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_List', 'O', 0, 'RULE_LIST', 7, 'Dispatch Rule List', ' ', ' ', 'List', 0, ' ', ' ', 'O', ' ', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_List', 'O', 1, 'RULE_ID', 0, 'Dispatch Rule ID', ' ', ' ', 'String', 20, 'RULE_ID', ' ', 'O', 'RULE_LIST', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_List', 'O', 1, 'RULE_DESC', 1, ' ', ' ', ' ', ' ', 0, 'RULE_DESC', ' ', 'O', 'RULE_LIST', 'N', ' ', 0, 0, 'ADMIN', '200812010101', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_DEPTH, MEMBER_NAME, MEMBER_SEQ, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, PARENT_MEMBER_NAME, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD', 'RTD_View_Rule_List', 'O', 1, 'RULE_TYPE', 2, 'Dispatch Rule Type (''L'': Lot Dispatch (What''s Next Rule), ''R'': Resource Dispatch (Where Next Rule)).', ' ', ' ', 'Char', 0, 'RULE_TYPE', ' ', 'O', 'RULE_LIST', 'Y', 'N', 0, 0, 'ADMIN', '200812010101', ' ', ' ');


/* Function Name is duplicated */
DELETE FROM MSECFUNDEF WHERE FUNC_NAME = 'ADM1005'; 
DELETE FROM MSECGRPFUN WHERE FUNC_NAME = 'ADM1005';

Delete from MMSGMSGDEF where msg_id = 'SEC-0037';

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SEC-0037', 'SEC', 'SEC-0037 : The number of alphabat characters included in password is fewer than set.', 'SEC-0037 : 암호에 포함된 문자의 개수가 설정보다 적습니다.', 'SEC-0037 : ', 'ADMIN', '20060405160005', 'ADMIN', '20081218132231');

/* Modification of GCM Table definition for wrong data length */
Delete from MGCMTBLDEF where factory = 'SYSTEM' and table_name = 'CRR_TYPE1';
Delete from MGCMTBLDEF where factory = 'SYSTEM' and table_name = 'CRR_TYPE2';
Delete from MGCMTBLDEF where factory = 'SYSTEM' and table_name = 'CRR_TYPE3';
Insert into MGCMTBLDEF
   (FACTORY, TABLE_NAME, TABLE_DESC, SYS_TBL_FLAG, CENTRAL_FLAG, TABLE_TYPE, USE_SQL_FLAG, TABLE_GROUP, KEY_1_PRT, KEY_1_FMT, KEY_1_SIZE, KEY_2_PRT, KEY_2_FMT, KEY_2_SIZE, KEY_3_PRT, KEY_3_FMT, KEY_3_SIZE, KEY_4_PRT, KEY_4_FMT, KEY_4_SIZE, KEY_5_PRT, KEY_5_FMT, KEY_5_SIZE, KEY_6_PRT, KEY_6_FMT, KEY_6_SIZE, KEY_7_PRT, KEY_7_FMT, KEY_7_SIZE, KEY_8_PRT, KEY_8_FMT, KEY_8_SIZE, KEY_9_PRT, KEY_9_FMT, KEY_9_SIZE, KEY_10_PRT, KEY_10_FMT, KEY_10_SIZE, DATA_1_PRT, DATA_1_FMT, DATA_1_SIZE, DATA_2_PRT, DATA_2_FMT, DATA_2_SIZE, DATA_3_PRT, DATA_3_FMT, DATA_3_SIZE, DATA_4_PRT, DATA_4_FMT, DATA_4_SIZE, DATA_5_PRT, DATA_5_FMT, DATA_5_SIZE, DATA_6_PRT, DATA_6_FMT, DATA_6_SIZE, DATA_7_PRT, DATA_7_FMT, DATA_7_SIZE, DATA_8_PRT, DATA_8_FMT, DATA_8_SIZE, DATA_9_PRT, DATA_9_FMT, DATA_9_SIZE, DATA_10_PRT, DATA_10_FMT, DATA_10_SIZE, SQL_1, SQL_2, SQL_3, SQL_4, SQL_5, TABLE_PASSWORD, SEC_CHK_FLAG, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'CRR_TYPE1', 'Carrier Type1', 'Y', ' ', ' ', ' ', 'RAS', 'Type', 'A', 10, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, 'DESCRIPTION', 'A', 50, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20050701171948', 'ADMIN', '20070814094559');
Insert into MGCMTBLDEF
   (FACTORY, TABLE_NAME, TABLE_DESC, SYS_TBL_FLAG, CENTRAL_FLAG, TABLE_TYPE, USE_SQL_FLAG, TABLE_GROUP, KEY_1_PRT, KEY_1_FMT, KEY_1_SIZE, KEY_2_PRT, KEY_2_FMT, KEY_2_SIZE, KEY_3_PRT, KEY_3_FMT, KEY_3_SIZE, KEY_4_PRT, KEY_4_FMT, KEY_4_SIZE, KEY_5_PRT, KEY_5_FMT, KEY_5_SIZE, KEY_6_PRT, KEY_6_FMT, KEY_6_SIZE, KEY_7_PRT, KEY_7_FMT, KEY_7_SIZE, KEY_8_PRT, KEY_8_FMT, KEY_8_SIZE, KEY_9_PRT, KEY_9_FMT, KEY_9_SIZE, KEY_10_PRT, KEY_10_FMT, KEY_10_SIZE, DATA_1_PRT, DATA_1_FMT, DATA_1_SIZE, DATA_2_PRT, DATA_2_FMT, DATA_2_SIZE, DATA_3_PRT, DATA_3_FMT, DATA_3_SIZE, DATA_4_PRT, DATA_4_FMT, DATA_4_SIZE, DATA_5_PRT, DATA_5_FMT, DATA_5_SIZE, DATA_6_PRT, DATA_6_FMT, DATA_6_SIZE, DATA_7_PRT, DATA_7_FMT, DATA_7_SIZE, DATA_8_PRT, DATA_8_FMT, DATA_8_SIZE, DATA_9_PRT, DATA_9_FMT, DATA_9_SIZE, DATA_10_PRT, DATA_10_FMT, DATA_10_SIZE, SQL_1, SQL_2, SQL_3, SQL_4, SQL_5, TABLE_PASSWORD, SEC_CHK_FLAG, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'CRR_TYPE2', 'Carrier Type2', 'Y', ' ', ' ', ' ', 'RAS', 'Type', 'A', 10, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, 'DESCRIPTION', 'A', 50, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20050701171948', 'ADMIN', '20070814094605');
Insert into MGCMTBLDEF
   (FACTORY, TABLE_NAME, TABLE_DESC, SYS_TBL_FLAG, CENTRAL_FLAG, TABLE_TYPE, USE_SQL_FLAG, TABLE_GROUP, KEY_1_PRT, KEY_1_FMT, KEY_1_SIZE, KEY_2_PRT, KEY_2_FMT, KEY_2_SIZE, KEY_3_PRT, KEY_3_FMT, KEY_3_SIZE, KEY_4_PRT, KEY_4_FMT, KEY_4_SIZE, KEY_5_PRT, KEY_5_FMT, KEY_5_SIZE, KEY_6_PRT, KEY_6_FMT, KEY_6_SIZE, KEY_7_PRT, KEY_7_FMT, KEY_7_SIZE, KEY_8_PRT, KEY_8_FMT, KEY_8_SIZE, KEY_9_PRT, KEY_9_FMT, KEY_9_SIZE, KEY_10_PRT, KEY_10_FMT, KEY_10_SIZE, DATA_1_PRT, DATA_1_FMT, DATA_1_SIZE, DATA_2_PRT, DATA_2_FMT, DATA_2_SIZE, DATA_3_PRT, DATA_3_FMT, DATA_3_SIZE, DATA_4_PRT, DATA_4_FMT, DATA_4_SIZE, DATA_5_PRT, DATA_5_FMT, DATA_5_SIZE, DATA_6_PRT, DATA_6_FMT, DATA_6_SIZE, DATA_7_PRT, DATA_7_FMT, DATA_7_SIZE, DATA_8_PRT, DATA_8_FMT, DATA_8_SIZE, DATA_9_PRT, DATA_9_FMT, DATA_9_SIZE, DATA_10_PRT, DATA_10_FMT, DATA_10_SIZE, SQL_1, SQL_2, SQL_3, SQL_4, SQL_5, TABLE_PASSWORD, SEC_CHK_FLAG, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'CRR_TYPE3', 'Carrier Type3', 'Y', ' ', ' ', ' ', 'RAS', 'Type', 'A', 10, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, 'DESCRIPTION', 'A', 50, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20050701171948', 'ADMIN', '20070814094609');


Insert into MSECPRVGRP
   (FACTORY, PRV_GRP_ID, PRV_GRP_DESC, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'ADMIN_PRV_GROUP', 'Administrator Privilege Group', 'ADMIN', '20090317201929', ' ', ' ');

Insert into MSECPRVUSR
   (FACTORY, PRV_GRP_ID, USER_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'ADMIN_PRV_GROUP', 'ADMIN', 'ADMIN', '20090317201945', ' ', ' ');
Insert into MSECPRVUSR
   (FACTORY, PRV_GRP_ID, USER_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'ADMIN_PRV_GROUP', 'ADMINA', 'ADMIN', '20090317201946', ' ', ' ');

Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_Check_Version', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202936', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_Copy_Table', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202705', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_Delete_Calendar_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202936', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_SQL_Multi_Query', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202936', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_SQL_Query', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202936', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_Update_Attribute_Value', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202936', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_Update_Calendar_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202936', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_Update_Data_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202936', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_Update_Message', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202936', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_Update_Table', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202706', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_View_Attribute', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202936', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_View_Attribute_History', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202936', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_View_Attribute_History_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202936', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_View_Attribute_Name', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202937', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_View_Attribute_Name_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202937', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_View_Attribute_Value', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202937', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_View_Attribute_Value_Brief', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202937', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_View_Calendar', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202937', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_View_Calendar_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202937', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_View_Data', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202937', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_View_Data_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202937', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_View_Message', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202937', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_View_Message_Group_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202937', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_View_Message_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202937', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_View_Table', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202937', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'BAS_View_Table_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202937', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_Change_Password', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203128', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_Change_Password_Ext', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203128', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_Copy_Privilege_Group', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202740', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_Copy_SecGrp', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202740', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_Get_HelpURL', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203128', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_Login', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203128', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_Login_Ext', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203128', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_Update_Favorites', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203128', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_Update_Flexible_Header', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202740', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_Update_Function', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202740', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_Update_GrpFunc_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202740', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_Update_Privilege', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202740', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_Update_Privilege_Group', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202740', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_Update_Privilege_Group_User', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202740', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_Update_SecGrp', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202740', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_Update_User', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202740', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_Update_User_Ext', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202740', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_View_Favorites_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203128', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_View_Flexible_Header', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203128', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_View_Flexible_Header_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203128', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_View_Function', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203128', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_View_Function_Detail', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203129', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_View_Function_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203129', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_View_Group_By_Type_Privilege_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203129', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_View_GrpFunc_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203129', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_View_Privilege', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203129', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_View_Privilege_Group', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203129', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_View_Privilege_Group_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203129', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_View_Privilege_Group_User_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203129', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_View_Privilege_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203129', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_View_SecGrp', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203129', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_View_SecGrp_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203129', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_View_User', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203129', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_View_User_Ext', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203129', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SEC_View_User_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203129', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SVM_Update_Default_Function_Version', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202754', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SVM_Update_Member', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202754', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SVM_Update_Service', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202754', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SVM_Update_Service_Member', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202754', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SVM_Update_Service_Member_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202754', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SVM_Update_Service_User_Routine_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202754', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SVM_View_Default_Function_Version', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203129', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SVM_View_Member', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203129', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SVM_View_Member_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203129', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SVM_View_Module_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203130', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SVM_View_Service', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203130', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SVM_View_Service_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203130', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SVM_View_Service_Member', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203130', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SVM_View_Service_Member_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203130', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'SVM_View_Service_User_Routine_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203130', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_Batch_Relation', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203158', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_Batch_Rule', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203158', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_CycleTime', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203158', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_Factory', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202754', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_Factory_Cmf_Item', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317202754', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_Future_Action', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203158', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_ID_Rule', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203158', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_MFO_Batch_Keep_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203158', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_MFO_Grade_Rule_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203158', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_MFO_Option_Definition', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203158', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_MFO_Option_Prompt', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203158', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_MFO_Sublot', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203158', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_MFO_Sublot_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203159', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_Material', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203159', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_Optional_Flow', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203159', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_Optional_Oper', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203159', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_Queue_Time', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203159', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_Repair_Oper', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203159', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_Rework_Flow', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203159', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_Rule_Def', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203159', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_Rule_Relation', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203159', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_Ship_Factory', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203159', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_Sublot_Grade_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203159', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_Update_Yield', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203159', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Batch_History', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203159', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Batch_Lot_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203159', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Batch_Relation', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203159', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Batch_Relation_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203159', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Batch_Rule', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203159', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Batch_Rule_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203200', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_CMF_Change', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203200', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_CycleTime_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203200', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Data_List_By_Attribute', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203200', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Ext_Code_Table', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203200', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Factory', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203200', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Factory_Cmf_Item', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203200', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Factory_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203200', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Flow', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203200', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Flow_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203200', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Flow_List_By_Operation', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203200', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Flow_Sequence_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203200', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Future_Action', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203200', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Future_Action_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203200', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Hold_Lot_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203200', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_ID_Rule', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203200', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_ID_Rule_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203200', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Lot', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203201', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Lot_Bonus_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203201', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Lot_Defect_List_Detail', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203201', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Lot_History', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203201', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Lot_Hold_Code_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203201', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Lot_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203201', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Lot_List_By_Operation', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203201', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Lot_List_By_Resource', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203201', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Lot_List_Detail', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203201', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Lot_List_Detail_By_SQL_Query', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203201', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Lot_Loss_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203201', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Lot_Trace', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203201', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Lot_Trace_History', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203201', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Lot_Trace_Tree', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203201', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_MFO_Batch_Keep_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203201', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_MFO_Grade_Rule_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203201', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_MFO_Option_Definition', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203202', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_MFO_Option_Definition_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203202', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_MFO_Option_Prompt', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203202', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_MFO_Option_Prompt_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203202', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_MFO_Queue_Time_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203202', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_MFO_Sublot', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203202', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_MFO_Sublot_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203202', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Material', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203202', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Material_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203202', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Material_List_By_Flow', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203202', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Material_List_By_Group', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203203', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Material_Version_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203203', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Operation', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203203', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Operation_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203203', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_ProcTime', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203203', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Process_Operation_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203203', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Queue_Time', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203203', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Repair_Oper_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203203', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Reserve_Batch', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203203', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Reserve_Batch_Lot_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203203', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Reserve_Lot_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203203', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Reserve_Sublot_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203203', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_ReturnLot', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203203', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_ReturnLot_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203203', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Rework_Flow_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203203', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Rework_Lot_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203203', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Rework_Oper_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203204', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Rule_Def', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203204', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Rule_Def_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203204', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Rule_Relation', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203204', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Rule_Relation_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203204', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Ship_Factory', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203204', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Ship_Factory_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203204', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Shipped_Lot_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203204', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Sublot', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203204', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Sublot_History', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203204', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Sublot_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203204', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Sublot_List_Detail', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203204', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Sublot_Loss_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203204', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Trouble_Lot', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203204', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Trouble_Lot_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203204', ' ', ' ');
Insert into MSECPRVDEF
   (FACTORY, PRV_TYPE, PRV_ITEM1, PRV_ITEM2, PRV_ITEM3, PRV_GRP_ID, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'SERVICE', 'WIP_View_Yield_List', ' ', ' ', 'ADMIN_PRV_GROUP', 'ADMIN', '20090317203204', ' ', ' ');

