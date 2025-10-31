/*
**
**  File Name    : MESplusV5-Table-Migration.sql
**  Description  : MESplus V5 Release Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g / 11g
**
**  Period       : 2011.10.08 ~ 2011.12.23
**  Release Date : 2011.12.23
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
*/

 /* Add by J.S. 2011.11.07 */
 Insert into MBASGLBPMT
   (OPTION_NAME, OPTION_DESC, MESPLUS_FLAG, VALUE_PMT_1, VALUE_PMT_2, 
    VALUE_PMT_3, VALUE_PMT_4, VALUE_PMT_5, VALUE_FMT_1, VALUE_FMT_2, 
    VALUE_FMT_3, VALUE_FMT_4, VALUE_FMT_5, VALUE_TBL_1, VALUE_TBL_2, 
    VALUE_TBL_3, VALUE_TBL_4, VALUE_TBL_5, CREATE_USER_ID, CREATE_TIME, 
    UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('MP_KeepOperInTimeFlowChgAdapt', 'Whether to keep operation-in-time when material,flow changes at ADAPT', 'Y', 'Yes or No', ' ', 
    ' ', ' ', ' ', 'A', ' ', 
    ' ', ' ', ' ', 'YESNO', ' ', 
    ' ', ' ', ' ', 'ADMIN', '20111107173722', 
    ' ', ' ');

 BEGIN
    FOR REC IN (
        SELECT DISTINCT FACTORY FROM MWIPFACDEF
        MINUS
        SELECT DISTINCT FACTORY FROM MBASGLBDEF 
        WHERE OPTION_NAME = 'MP_KeepOperInTimeFlowChgAdapt'
        ) 
    LOOP
    
        Insert into MBASGLBDEF
           (FACTORY, OPTION_NAME, OPTION_DESC, VALUE_1, VALUE_2, 
            VALUE_3, VALUE_4, VALUE_5, CREATE_USER_ID, CREATE_TIME, 
            UPDATE_USER_ID, UPDATE_TIME)
         Values
           (REC.FACTORY, 'MP_KeepOperInTimeFlowChgAdapt', 'Whether to keep operation-in-time when material,flow changes at ADAPT', 'N', ' ', 
            ' ', ' ', ' ', 'ADMIN', '20111107173807', 
            ' ', ' ');
    END LOOP;
END ;
/
/* End Add */	


/* Add by J.S. 2011.11.14 for ID GEN */
ALTER TABLE MWIPIDGHIS ADD(SEQ_POSITION  VARCHAR2(50)  DEFAULT (' ')  NOT NULL);

CREATE INDEX MWIPIDGHIS_IDX_1 ON MWIPIDGHIS
(GEN_ID) TABLESPACE MESPLUS_IDX_TS;
/* End Add */