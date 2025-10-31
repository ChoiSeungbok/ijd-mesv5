/*
**
**  File Name    : MESplusV5-Table-Migration.sql
**  Description  : MESplus V5 Release Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g / 11g
**
**  Period       : 2011.04.08 ~ 2011.04.08
**  Release Date : 2011.04.08
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
*/

REM INSERTING into MBASGLBPMT : MP_AllowMergeDiffProcessStatus
Insert into MBASGLBPMT
   (OPTION_NAME, OPTION_DESC, MESPLUS_FLAG, VALUE_PMT_1, VALUE_PMT_2, VALUE_PMT_3, VALUE_PMT_4, VALUE_PMT_5, VALUE_FMT_1, VALUE_FMT_2, VALUE_FMT_3, VALUE_FMT_4, VALUE_FMT_5, VALUE_TBL_1, VALUE_TBL_2, VALUE_TBL_3, VALUE_TBL_4, VALUE_TBL_5, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('MP_AllowMergeDiffProcessStatus', 'Whether to Allow Lot Merge between other different processing status', 'Y', 'Yes or No', ' ', ' ', ' ', ' ', 'A', ' ', ' ', ' ', ' ', 'YESNO', ' ', ' ', ' ', ' ', 'ADMIN', '20110407145804', ' ', ' ');


    
BEGIN
	FOR REC IN (
		SELECT DISTINCT FACTORY FROM MWIPFACDEF
		MINUS
		SELECT DISTINCT FACTORY FROM MBASGLBDEF
		WHERE OPTION_NAME = 'MP_AllowMergeDiffProcessStatus'
		) 
	LOOP
	
        Insert into MBASGLBDEF
           (FACTORY, OPTION_NAME, OPTION_DESC, VALUE_1, VALUE_2, VALUE_3, VALUE_4, VALUE_5, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
         Values
           (REC.FACTORY, 'MP_AllowMergeDiffProcessStatus', 'Whether to Allow Lot Merge between other different processing status', 'N', ' ', ' ', ' ', ' ', 'ADMIN', '20110407150137', 'ADMIN', '20110407150211');

	END LOOP;
END ;
/