/*
**
**  File Name    : MESplusV5-Table-Migration_Data.sql
**  Description  : MESplus V5 Release for Data Migration
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g / 11g
**
**  Period       : 2015.10.30 ~ ****
**  Release Date : ****
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
**  1. 2015.10.30   Aiden   Create
*/


/* Added By YJJung 151204 GCM-0032 */
INSERT INTO MMSGMSGDEF(MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME) VALUES('GCM-0032', 'GCM', 'GCM-0032 : The valid count is between 1 and 20.', 'GCM-0032 : SIZE는 1보다 크고 20 보다 작거나 같아야 합니다.', 'GCM-0032 : Der gueltige Zahlwert liegt zwischen 1 und 20.', 'ADMIN', '20081201010101', 'ADMIN', '20120203164813');

/* Added By YJJUNG 2016.03.03 */
INSERT INTO MMSGMSGDEF(MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME) 
VALUES('SPC-0057','SPC','SPC-0057 : Only numeric value is allowed. Please input again.','SPC-0057 : 숫자 값만 허용 합니다. 다시 입력하여 주세요.','SPC-0057 : Nur numerische Werte sind erlaubt. Bitte erneut eingeben.','ADMIN','20160303010101',' ',' ');

/* Added By YJJUNG 2016.03.03 */
INSERT INTO MMSGMSGDEF(MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME) 
VALUES('SPC-0058','SPC','SPC-0058 : Valid value is between 0 and 100. Please input again.','SPC-0058 : 값은 0보다 크고 100보다 작아야 합니다.다시 입력하여 주세요','SPC-0058 : Ein gultiger Wert zwischen 0 und 100. Bitte erneut eingeben.','ADMIN','20160303010101',' ',' ');


