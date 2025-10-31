/*
**
**  File Name    : MESplusV5-Table-Migration-20081231.sql
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
**  2     2008.11.10  HK.Kim        Add Global Option - IsStoreDspEventHistory, IsStoreDspResultHistory
**  3     2008.11.18  Aiden         Add Server Error Message, Service User Routine Setup Function
**  4     2008.11.28  HK.Kim        Add Function Script with Icon Index
**  5     2008.12.05  HK.Kim        FMB Table Migration
**  6     2008.12.08  Aiden         SVM Table Migration
**  7     2008.12.08  Daniel.Jeong  Add Table Migration for MSECPRVDEF
**  8     2008.12.10  HK.Kim        Add RTD CMF, RTD_RULE_TYPE GCM Table
**  9     2008.12.10  Aiden         Add Error Message
**    
*/

/*
** New GCM Tables & Values
*/
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FABBLW', 'GLOBAL_OPTION', 'IsStoreDspEventHistory', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20081110135519', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FABBLW', 'GLOBAL_OPTION', 'IsStoreDspResultHistory', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20081110135519', 'ADMIN', '20081110144034');

Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'GLOBAL_OPTION', 'IsStoreDspEventHistory', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20081110135519', ' ', ' ');
Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'GLOBAL_OPTION', 'IsStoreDspResultHistory', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20081110135519', 'ADMIN', '20081110144034');

/*
** New Messages
*/
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('CMN-0006', 'CMN', 'CMN-0006 : No item was selected. Please select item.', ' ', 'CMN-0006 : Es wurde kein Element ausgewaehlt. Bitte waehlen Sie ein Element aus.', 'ADMIN', '20081118184551', ' ', ' ');


/*
** New Functions
*/
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM1004', 'Service User Routine Setup', 'F', 'SETUP', 'Miracom.SVMCore.dll', 'Miracom.SVMCore.frmSVMSetupServiceUserRoutine', ' ', -1, 'btnCreate', 'btnDelete', 'btnUpdate', 'btnClose', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20081118175336', 'ADMIN', '20081118180323');

/*
** 아이콘 적용 스크립트
*/

DELETE FROM MSECFUNDEF;

Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ADM1000', 'Admin', 'M', 'TOP', ' ', ' ', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'General', 'Lot List', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20081023164005', 'ADMIN', '20081023164005');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ADM1001', '[ADM] Archive option Setup', 'F', 'ADMIN', 'Admin.ARCCore.dll', 'Admin.ARCCore.frmARCSetupOption', ' ', -1, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '20080211072531', 'ADMIN', '20080211072531');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ADM1002', '[ADM] Archive Table key Setup', 'F', 'ADMIN', 'Admin.ARCCore.dll', 'Admin.ARCCore.frmARCSetupTableKey', ' ', -1, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '20080208194041', 'ADMIN', '20080208194041');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ADM1003', '[ADM] Run Archive and view Archive option list', 'F', 'ADMIN', 'Admin.ARCCore.dll', 'Admin.ARCCore.frmARCViewOptionList', ' ', -1, 'btnRun', 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '20080208195106', 'ADMIN', '20080208195106');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ADM1004', '[ADM] Task Manager', 'F', 'ADMIN', 'Admin.ADMCore.dll', 'Admin.ADMCore.frmADMTaskManager', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '20080208194233', 'ADMIN', '20080208194233');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ADM1005', '[ADM] Archive Setup Option', 'F', 'ADMIN', 'Admin.ARCCore.dll', 'Admin.ARCCore.frmARCSetupOption', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '20080212171722', 'ADMIN', '20080212171722');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ADM1006', '[ADM] Dearchive', 'F', 'ADMIN', 'Admin.ARCCore.dll', 'Admin.ARCCore.frmARCDeArchive', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '20080212171732', 'ADMIN', '20080212171732');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ADM3001', '[ADM] View Log History', 'F', 'ADMIN', 'Admin.ADMCore.dll', 'Admin.ADMCore.frmADMViewLogHistory', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '20080208194328', 'ADMIN', '20080208194328');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ALM1000', '[ALM] Alarm', 'M', 'SETUP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080116224446', 'ADMIN', '20080116224446');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ALM1001', 'Alarm Setup', 'F', 'SETUP', 'Miracom.ALMCore.dll', 'Miracom.ALMCore.frmALMSetupAlarm', ' ', 146, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', 'tbpEvent', 'tbpMessage', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071213185004', 'ADMIN', '20081127161324');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ALM1002', 'Attach Alarm to MFO/Resource', 'F', 'SETUP', 'Miracom.ALMCore.dll', 'Miracom.ALMCore.frmALMSetupAlarmMFO', ' ', 147, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071213185158', 'ADMIN', '20081127161335');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ALM2000', '[ALM] Alarm', 'M', 'TRAN', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080116224456', 'ADMIN', '20080116224456');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ALM2001', 'Raise Alarm', 'F', 'TRAN', 'Miracom.ALMCore.dll', 'Miracom.ALMCore.frmALMTranRaiseAlarm', ' ', 178, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071220011424', 'ADMIN', '20081127161825');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ALM2003', 'Clear Alarm', 'F', 'TRAN', 'Miracom.ALMCore.dll', 'Miracom.ALMCore.frmALMTranClearAlarm', ' ', 179, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080312104035', 'ADMIN', '20081127161830');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ALM3000', '[ALM] Alarm', 'M', 'INQUIRY', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080116224504', 'ADMIN', '20080116224504');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ALM3001', 'View Alarm History', 'F', 'INQUIRY', 'Miracom.ALMCore.dll', 'Miracom.ALMCore.frmALMViewAlarmHistory', ' ', 211, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071220011531', 'ADMIN', '20081127164138');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('BAS1000', '[BAS] Basic', 'M', 'SETUP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080116224846', 'ADMIN', '20080116224846');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('BAS1001', 'Attribute Setup', 'F', 'SETUP', 'Miracom.BASCore.dll', 'Miracom.BASCore.frmBASSetupAttribute', ' ', 149, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071219220600', 'ADMIN', '20081127161359');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('BAS2000', '[BAS] Basic', 'M', 'TRAN', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080116224854', 'ADMIN', '20080116224854');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('BAS2001', 'Input Attribute Value', 'F', 'TRAN', 'Miracom.BASCore.dll', 'Miracom.BASCore.frmBASTranAttribute', ' ', 183, 'btnView', 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080110185328', 'ADMIN', '20081127161926');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2044', 'Change CMF Value', 'F', 'TRAN', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranChangeCMF', ' ', 184, 'btnView', 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071216230813', 'ADMIN', '20081127161933');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('BAS3000', '[BAS] Basic', 'F', 'INQUIRY', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.26.html', ' ', '20080116224901', 'ADMIN', '20080116224901');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('BAS3001', 'View Attribute Status', 'F', 'INQUIRY', 'Miracom.BASCore.dll', 'Miracom.BASCore.frmBASViewAttributeStatus', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071215070530', 'ADMIN', '20071215070530');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('BAS3002', 'View Attribute History', 'F', 'INQUIRY', 'Miracom.BASCore.dll', 'Miracom.BASCore.frmBASViewAttributeHistory', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20071215070511', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('BOM1000', '[BOM] Bill Of Material', 'M', 'SETUP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-3.html', ' ', '20080116224924', 'ADMIN', '20080116224924');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('BOM1001', 'BOM Set Setup', 'F', 'SETUP', 'Miracom.BOMCore.dll', 'Miracom.BOMCore.frmBOMSetupBOMSet', ' ', 128, 'btnCopy', 'btnVerCreate', 'btnVerDelete', 'btnVerUpdate', 'btnUndelete', 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', 'tbpBOMCMF', 'tbpBOMGeneral', 'tbpBOMGroup', 'tbpBOMVersion', 'tbpCMF', 'tbpGeneral', 'tbpCopy', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-3.html', ' ', '20070920174807', 'ADMIN', '20081127160740');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('BOM1002', 'Attach Material Setup', 'F', 'SETUP', 'Miracom.BOMCore.dll', 'Miracom.BOMCore.frmBOMSetupAttachMaterial', ' ', 129, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-3.html', ' ', '20070920174818', 'ADMIN', '20081127160749');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('BOM1003', 'Approval and Release Setup', 'F', 'SETUP', 'Miracom.BOMCore.dll', 'Miracom.BOMCore.frmBOMSetupApprovalRelease', ' ', 130, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-3.html', ' ', '20070920175223', 'ADMIN', '20081127160759');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('BOM2000', '[BOM] Bill Of Material', 'M', 'TRAN', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-3.html', ' ', '20080116224938', 'ADMIN', '20080116224938');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('BOM2001', 'Assembly Lot', 'F', 'TRAN', 'Miracom.BOMCore.dll', 'Miracom.BOMCore.frmBOMTranAssembly', ' ', 162, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-3.html', ' ', '20070920184657', 'ADMIN', '20081127161602');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('BOM2002', 'Disassemble Lot', 'F', 'TRAN', 'Miracom.BOMCore.dll', 'Miracom.BOMCore.frmBOMTranDisassembly', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-3.html', ' ', '20070920184703', 'ADMIN', '20070920184703');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('BOM2003', 'Replace Lot', 'P', 'TRAN', 'Miracom.BOMCore.dll', 'Miracom.BOMCore.frmBOMTranReplace', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-3.html', ' ', '20070920184712', 'ADMIN', '20070920184712');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('BOM2004', 'Delete BOM History', 'F', 'TRAN', 'Miracom.BOMCore.dll', 'Miracom.BOMCore.frmBOMTranDeleteBOMHistory', ' ', 163, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-3.html', ' ', '20070920184733', 'ADMIN', '20081127161619');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('BOM3000', '[BOM] Bill Of Material', 'M', 'INQUIRY', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-3a2.html', ' ', '20080116224954', 'ADMIN', '20080116224954');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('BOM3001', 'View Lot Status For Assembly', 'F', 'INQUIRY', 'Miracom.BOMCore.dll', 'Miracom.BOMCore.frmBOMViewLotStatusForAssembly', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-3a2.html', ' ', '20070912170200', 'ADMIN', '20070912170200');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('BOM3002', 'View Lot History For Assembly', 'F', 'INQUIRY', 'Miracom.BOMCore.dll', 'Miracom.BOMCore.frmBOMViewLotHistoryForAssembly', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-3a2.html', ' ', '20070912170148', 'ADMIN', '20070912170148');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('BOM3003', 'View Material List By BOM Set ID', 'F', 'INQUIRY', 'Miracom.BOMCore.dll', 'Miracom.BOMCore.frmBOMViewMaterialByBOMSet', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-3a2.html', ' ', '20070912170222', 'ADMIN', '20070912170222');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC1000', '[EDC] Engineering Data Collection', 'M', 'SETUP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-7.html', ' ', '20080116225020', 'ADMIN', '20080116225020');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC1001', 'Character Setup', 'F', 'SETUP', 'Miracom.EDCCore.dll', 'Miracom.EDCCore.frmEDCSetupCharacter', ' ', 131, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tabCMF', 'tabGeneral', 'tabGroup', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-7.html', ' ', '20080109014104', 'ADMIN', '20081127160815');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC1002', 'Collection Set Setup', 'F', 'SETUP', 'Miracom.EDCCore.dll', 'Miracom.EDCCore.frmEDCSetupCollectionSet', ' ', 132, 'btnCopy', 'btnVerCreate', 'btnVerDelete', 'btnVerUpdate', 'btnUndelete', 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', 'tbpCopy', 'tbpGeneral', 'tbpAppNRel', 'tbpEDCCMF', 'tbpEDCGeneral', 'tbpEDCGroup', 'tbpEDCVersion', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-7.html', ' ', '20080109014111', 'ADMIN', '20081127160820');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC1003', 'Attach Character', 'F', 'SETUP', 'Miracom.EDCCore.dll', 'Miracom.EDCCore.frmEDCSetupAttachCharacter', ' ', 133, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-7.html', ' ', '20080109014134', 'ADMIN', '20081127160832');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC1004', 'Attach Collection Set To MFO', 'F', 'SETUP', 'Miracom.EDCCore.dll', 'Miracom.EDCCore.frmEDCSetupAttachCollectionSetToMFO', ' ', 134, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpOper', 'tbpFO', 'tbpMFO', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-7.html', ' ', '20080109014145', 'ADMIN', '20081127160839');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC1005', 'Approval Release Setup', 'F', 'SETUP', 'Miracom.EDCCore.dll', 'Miracom.EDCCore.frmEDCSetupApprovalRelease', ' ', 135, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-7.html', ' ', '20070920175251', 'ADMIN', '20081127160845');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC2000', '[EDC] Engineering Data Collection', 'M', 'TRAN', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-5.html', ' ', '20080116225029', 'ADMIN', '20080116225029');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC2001', 'Collect Lot Data', 'F', 'TRAN', 'Miracom.EDCCore.dll', 'Miracom.EDCCore.frmEDCCollectLotData', ' ', 164, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-5.html', ' ', '20081021100206', 'ADMIN', '20081127161635');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC2002', 'Change Lot Data', 'F', 'TRAN', 'Miracom.EDCCore.dll', 'Miracom.EDCCore.frmEDCChangeLotData', ' ', 165, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-5.html', ' ', '20081021102259', 'ADMIN', '20081127161642');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC2003', 'Change Resource Data', 'F', 'TRAN', 'Miracom.EDCCore.dll', 'Miracom.EDCCore.frmEDCChangeResData', ' ', 166, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-5.html', ' ', '20081021102310', 'ADMIN', '20081127161649');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC2004', 'Delete EDC Data History', 'F', 'TRAN', 'Miracom.EDCCore.dll', 'Miracom.EDCCore.frmEDCDeleteLotDataHistory', ' ', 167, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-5.html', ' ', '20081021102326', 'ADMIN', '20081127161657');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC2005', 'Delete Resource Data History', 'F', 'TRAN', 'Miracom.EDCCore.dll', 'Miracom.EDCCore.frmEDCDeleteResourceDataHistory', ' ', 168, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-5.html', ' ', '20070912200801', 'ADMIN', '20081127161709');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC3000', '[EDC] Engineering Data Collection', 'M', 'INQUIRY', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-5.html', ' ', '20080116225037', 'ADMIN', '20080116225037');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC3001', 'View Lot Data', 'F', 'INQUIRY', 'Miracom.EDCCore.dll', 'Miracom.EDCCore.frmEDCViewLotDatabyLot', ' ', 210, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-5.html', 'ADMIN', '20040715145726', 'ADMIN', '20081127164122');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC3002', 'View Lot Data By Collection Set', 'F', 'INQUIRY', 'Miracom.EDCCore.dll', 'Miracom.EDCCore.frmEDCViewLotDatabyCollectionSet', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-5.html', 'ADMIN', '20040715145907', 'MESPLUS', '20040908164944');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC3003', 'View Resource Data', 'F', 'INQUIRY', 'Miracom.EDCCore.dll', 'Miracom.EDCCore.frmEDCViewResourceData', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-5.html', 'ADMIN', '20040715145742', 'MESPLUS', '20040908164948');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC3004', 'View Resource Data By Collection Set', 'F', 'INQUIRY', 'Miracom.EDCCore.dll', 'Miracom.EDCCore.frmEDCViewResourceDataByCollectionSet', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-5.html', 'MESPLUS', '20040823104358', 'MESPLUS', '20040908164951');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC3005', 'View Character By Collection Set', 'F', 'INQUIRY', 'Miracom.EDCCore.dll', 'Miracom.EDCCore.frmEDCViewCharacterbyCollectionSet', ' ', -1, 'btnUnit', 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-5.html', 'ADMIN', '20040715145817', 'MESPLUS', '20040908164955');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC3006', 'View Collection Set By MFO', 'F', 'INQUIRY', 'Miracom.EDCCore.dll', 'Miracom.EDCCore.frmEDCViewCollectionSetbyMFO', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-5.html', 'ADMIN', '20040715145841', 'MESPLUS', '20040908164959');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC3007', 'View Character by Group', 'F', 'INQUIRY', 'Miracom.EDCCore.dll', 'Miracom.EDCCore.frmEDCViewCharacterByGroup', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-5.html', 'MESPLUS', '20040811154554', 'MESPLUS', '20040908165003');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('EDC3008', 'View Collection Set by Group', 'F', 'INQUIRY', 'Miracom.EDCCore.dll', 'Miracom.EDCCore.frmEDCViewCollectionSetByGroup', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-5.html', 'MESPLUS', '20040811154609', 'MESPLUS', '20040908165006');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FAV1001', 'Favorites Setup', 'F', 'SETUP', 'Miracom.MESCore.dll', 'Miracom.MESCore.frmSetupFavorites', ' ', -1, 'btnAttach', 'btnDetach', 'btnAlias', 'btnUp', 'btnDown', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual5a3.html', ' ', '20070920175258', 'ADMIN', '20070920175258');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB0001', 'Setup', 'M', 'FMB', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080506100938', 'ADMIN', '20080506100938');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB0002', 'Transaction', 'M', 'FMB', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080506100942', 'ADMIN', '20080506100942');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB0003', 'Inquiry', 'M', 'FMB', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080506100948', 'ADMIN', '20080506100948');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB0004', 'Design', 'M', 'FMB', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080506100953', 'ADMIN', '20080506100953');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB0005', 'Format', 'M', 'FMB', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080506100956', 'ADMIN', '20080506100956');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB0006', 'Utilities', 'M', 'FMB', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080506141811', 'ADMIN', '20080506141811');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB0007', 'View', 'M', 'FMB', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20080506141818', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB1001', 'Global Option Setup', 'F', 'SETUP', 'Miracom.FMBClientCore.dll', 'Miracom.FMBClientCore.frmFMBSetupGlobalOption', ' ', 241, 'btnView', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.17.html', ' ', '20080506100121', 'ADMIN', '20081127181657');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB1002', 'Resource Image Setup', 'F', 'SETUP', 'Miracom.FMBClientCore.dll', 'Miracom.FMBClientCore.frmFMBSetupResourceImage', ' ', 242, 'btnAdd', 'btnDel', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.18.html', ' ', '20080506100136', 'ADMIN', '20081127181709');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB2001', 'Event', 'F', 'TRAN', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASTranEvent', ' ', -1, 'btnOK', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.20.html', ' ', '20080506105022', 'ADMIN', '20080506105022');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB3001', 'View Resource Status', 'F', 'INQUIRY', 'Miracom.FMBClientCore.dll', 'Miracom.FMBClientCore.frmFMBViewResourceStatus', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.22.html', ' ', '20080506100823', 'ADMIN', '20080506100823');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB3002', 'View Resource History', 'F', 'INQUIRY', 'Miracom.FMBClientCore.dll', 'Miracom.FMBClientCore.frmFMBViewResourceHistory', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.23.html', ' ', '20080506100826', 'ADMIN', '20080506100826');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB3003', 'View Resource List Detail', 'F', 'INQUIRY', 'Miracom.FMBClientCore.dll', 'Miracom.FMBClientCore.frmFMBViewResourceListDetail', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.24.html', ' ', '20080506100829', 'ADMIN', '20080506100829');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB3004', 'View Lot List Detail', 'F', 'INQUIRY', 'Miracom.FMBClientCore.dll', 'Miracom.FMBClientCore.frmFMBViewLotListDetail', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.25.html', ' ', '20080506100833', 'ADMIN', '20080506100833');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB3005', 'View Lot List by Resource', 'F', 'INQUIRY', 'Miracom.FMBClientCore.dll', 'Miracom.FMBClientCore.frmFMBViewLotListByResource', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.26.html', ' ', '20080506100837', 'ADMIN', '20080506100837');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB4001', 'New LayOut', 'F', 'FMB', 'Miracom.FMBClientCore.dll', 'Miracom.FMBClientCore.frmFMBCreateLayOut', ' ', 243, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.28.html', ' ', '20080506100814', 'ADMIN', '20081127181726');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB4002', 'New User Design', 'F', 'FMB', 'Miracom.FMBClientCore.dll', 'Miracom.FMBClientCore.frmFMBCreateUDRGroup', ' ', 244, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.29.html', ' ', '20080506100817', 'ADMIN', '20081127181736');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB4003', 'Design Update Function', 'F', 'FMB', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.30.html', ' ', '20051102115455', 'ADMIN', '20051102115455');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB5001', 'Format', 'F', 'FMB', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.36.html', ' ', '20051102115509', 'ADMIN', '20051102115509');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB6001', 'Utilities Send Message', 'F', 'FMB', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.42.html', ' ', '20051102115522', 'ADMIN', '20051102115522');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('GCM1000', '[GCM] General Code Management', 'M', 'SETUP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-4a3.html', ' ', '20080116225129', 'ADMIN', '20080116225129');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('GCM1001', 'General Code Table Setup', 'F', 'SETUP', 'Miracom.BASCore.dll', 'Miracom.BASCore.frmBASSetupGeneralCodeTable', ' ', 46, 'btnCopy', 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpGeneral', 'tbpCopy', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-4a3.html', ' ', '20081029144025', 'ADMIN', '20081029144025');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('GCM1002', 'General Code Data Setup', 'F', 'SETUP', 'Miracom.BASCore.dll', 'Miracom.BASCore.frmBASSetupGeneralCodeData', ' ', 37, 'btnSelect', 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-4a3.html', ' ', '20081029144032', 'ADMIN', '20081029144032');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('INV2000', '[INV] Inventory', 'M', 'TRAN', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-2.html', ' ', '20080116225150', 'ADMIN', '20080116225150');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('INV2001', 'Tran In Store', 'F', 'TRAN', 'Miracom.INVCore.dll', 'Miracom.INVCore.frmINVTranInInventory', ' ', 154, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-2.html', ' ', '20051207091650', 'ADMIN', '20081127161500');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('INV2002', 'Tran Out Store', 'F', 'TRAN', 'Miracom.INVCore.dll', 'Miracom.INVCore.frmINVTranOutInventory', ' ', 155, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-2.html', ' ', '20070912200957', 'ADMIN', '20081127161505');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('INV2003', 'Tran Transfer Store', 'F', 'TRAN', 'Miracom.INVCore.dll', 'Miracom.INVCore.frmINVTranTransferInventory', ' ', 156, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-2.html', ' ', '20051207091714', 'ADMIN', '20081127161510');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('INV2004', 'Tran Convert Inventory Type To Lot', 'F', 'TRAN', 'Miracom.INVCore.dll', 'Miracom.INVCore.frmINVTranConvToLot', ' ', 157, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', 'tbpCreateCMF', 'tbpCreateTmCMF', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-2.html', ' ', '20051207091857', 'ADMIN', '20081127161524');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('INV2005', 'Tran Convert Lot To Inventory Type', 'F', 'TRAN', 'Miracom.INVCore.dll', 'Miracom.INVCore.frmINVTranConvToInv', ' ', 158, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-2.html', ' ', '20070912201053', 'ADMIN', '20081127161528');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('INV2006', 'Tran Consume', 'F', 'TRAN', 'Miracom.INVCore.dll', 'Miracom.INVCore.frmINVTranConsume', ' ', 159, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-2.html', ' ', '20051207092147', 'ADMIN', '20081127161539');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('INV2007', 'Tran Scrap', 'F', 'TRAN', 'Miracom.INVCore.dll', 'Miracom.INVCore.frmINVTranScrap', ' ', 160, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-2.html', ' ', '20051207092204', 'ADMIN', '20081127161545');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('INV2008', 'Tran Delete Inventory History', 'F', 'TRAN', 'Miracom.INVCore.dll', 'Miracom.INVCore.frmINVTranDeleteInvHistory', ' ', 161, 'btnView', 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-2.html', 'MESPLUS', '20040811195814', 'ADMIN', '20081127161551');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('INV3000', '[INV] Inventory', 'M', 'INQUIRY', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-3.html', ' ', '20080116225202', 'ADMIN', '20080116225202');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('INV3001', 'View Inventory History', 'F', 'INQUIRY', 'Miracom.INVCore.dll', 'Miracom.INVCore.frmINVViewInventoryHistory', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-3.html', 'MESPLUS', '20040816102630', 'MESPLUS', '20040908165348');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('MSG1000', '[MSG] Message', 'M', 'SETUP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-4.html', ' ', '20080116225211', 'ADMIN', '20080116225211');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('MSG1001', 'Message Setup', 'F', 'SETUP', 'Miracom.BASCore.dll', 'Miracom.BASCore.frmBASSetupMessage', ' ', 38, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-4.html', ' ', '20081029144055', 'ADMIN', '20081029144055');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ORD1001', 'Production Order Setup', 'F', 'SETUP', 'Miracom.ORDCore.dll', 'Miracom.ORDCore.frmORDSetupProductionOrder', ' ', 213, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', 'tbpCreate', 'tbpStatus', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-1-4.html', ' ', '20070920175338', 'ADMIN', '20081127164207');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ORD1002', 'Production Plan Setup', 'F', 'SETUP', 'Miracom.ORDCore.dll', 'Miracom.ORDCore.frmORDSetupProductionPlan', ' ', 214, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-1-4.html', ' ', '20070920175347', 'ADMIN', '20081127164211');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ORD1003', 'Planned Lot Setup', 'F', 'SETUP', 'Miracom.ORDCore.dll', 'Miracom.ORDCore.frmORDSetupPlannedLot', ' ', 215, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-1-4.html', ' ', '20070920175355', 'ADMIN', '20081127164222');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ORD1004', 'Work Order Setup', 'F', 'SETUP', 'Miracom.ORDCore.dll', 'Miracom.ORDCore.frmORDSetupWorkOrder', ' ', 216, 'btnDown', 'btnUp', 'btnCreate', 'btnDelete', 'btnUpdate', 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-1-4.html', ' ', '20070920175401', 'ADMIN', '20081127164231');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ORD2001', 'Tran Create Lot Based On Order', 'F', 'TRAN', 'Miracom.ORDCore.dll', 'Miracom.ORDCore.frmORDTranCreateLotOrder', ' ', 221, 'btnViewOrderList', 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', 'tbpCreateCMF', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-5.html', ' ', '20051207093217', 'ADMIN', '20081127173143');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ORD2002', 'Tran Create Lot Based On Plan', 'F', 'TRAN', 'Miracom.ORDCore.dll', 'Miracom.ORDCore.frmORDTranCreateLotPlan', ' ', 222, 'btnViewPlanList', 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', 'tbpCreateCMF', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-5.html', ' ', '20051207093237', 'ADMIN', '20081127173150');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ORD2003', 'Tran Create Planned Lot', 'F', 'TRAN', 'Miracom.ORDCore.dll', 'Miracom.ORDCore.frmORDTranCreatePlannedLot', ' ', 223, 'btnViewLotList', 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', 'tbpCreateCMF', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-5.html', ' ', '20051207093543', 'ADMIN', '20081127173202');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ORD2004', 'Tran Attach Lot To Order', 'F', 'TRAN', 'Miracom.ORDCore.dll', 'Miracom.ORDCore.frmORDTranAttachLotToOrder', ' ', 224, 'btnAttach', 'btnDetach', 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpLot', 'tbpOrder', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-5.html', ' ', '20051207093114', 'ADMIN', '20081127173212');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ORD3001', 'View Production Order', 'F', 'INQUIRY', 'Miracom.ORDCore.dll', 'Miracom.ORDCore.frmORDViewProductionOrder', ' ', 217, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-1-2.html', 'ADMIN', '20040715143320', 'ADMIN', '20081127164242');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ORD3002', 'View Production Plan', 'F', 'INQUIRY', 'Miracom.ORDCore.dll', 'Miracom.ORDCore.frmORDViewProductionPlan', ' ', 218, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-1-2.html', 'ADMIN', '20040715143330', 'ADMIN', '20081127164251');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ORD3003', 'View Planned Lot', 'F', 'INQUIRY', 'Miracom.ORDCore.dll', 'Miracom.ORDCore.frmORDViewPlannedLot', ' ', 219, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-1-2.html', 'ADMIN', '20040715143343', 'ADMIN', '20081127164255');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ORD3004', 'View Work Order', 'F', 'INQUIRY', 'Miracom.ORDCore.dll', 'Miracom.ORDCore.frmORDViewWorkOrder', ' ', 220, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-1-2.html', 'MESPLUS', '20040811154429', 'ADMIN', '20081127173130');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('POP1000', '[POP] Label', 'M', 'SETUP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080116225224', 'ADMIN', '20080116225224');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('POP1001', 'Label Setup', 'F', 'SETUP', 'Miracom.POPCore.dll', 'Miracom.POPCore.frmPOPSetupLabel', ' ', -1, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-1-2.html', ' ', '20070920175412', 'ADMIN', '20070920175412');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('POP1002', 'Label Design Setup', 'F', 'SETUP', 'Miracom.POPCore.dll', 'Miracom.POPCore.frmPOPSetupLabelDesign', ' ', -1, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-1-2.html', ' ', '20070920175420', 'ADMIN', '20070920175420');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('POP1003', 'Material Label Setup', 'F', 'SETUP', 'Miracom.POPCore.dll', 'Miracom.POPCore.frmPOPSetupMaterialLabel', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-1-2.html', ' ', '20070920175431', 'ADMIN', '20070920175431');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('POP1004', 'Image Setup', 'F', 'SETUP', 'Miracom.POPCore.dll', 'Miracom.POPCore.frmPOPSetupImage', ' ', -1, 'btnCreate', 'btnDelete', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-1-2.html', ' ', '20070920175438', 'ADMIN', '20070920175438');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('POP2000', '[POP] Label', 'M', 'TRAN', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080116225235', 'ADMIN', '20080116225235');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('POP2001', 'Tran Lot Label Print', 'F', 'TRAN', 'Miracom.POPCore.dll', 'Miracom.POPCore.frmPOPTranLotLabelPrint', ' ', 182, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-5.html', ' ', '20070912201148', 'ADMIN', '20081127161914');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('QCM1000', '[QCM] Quality Control Management', 'M', 'SETUP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080116225306', 'ADMIN', '20080116225306');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('QCM1001', 'Sampling Procedure Setup', 'F', 'SETUP', 'Miracom.QCMCore.dll', 'Miracom.QCMCore.frmQCMSetupSamplingProcedure', ' ', -1, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20070920175447', 'ADMIN', '20070920175447');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('QCM1002', 'Inspection Item Setup', 'F', 'SETUP', 'Miracom.QCMCore.dll', 'Miracom.QCMCore.frmQCMSetupInspectionItem', ' ', -1, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20070920175456', 'ADMIN', '20070920175456');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('QCM1003', 'Inspection Set Setup', 'F', 'SETUP', 'Miracom.QCMCore.dll', 'Miracom.QCMCore.frmQCMSetupInspectionSet', ' ', -1, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20070920175504', 'ADMIN', '20070920175504');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('QCM1004', 'Attach Inspection Item To Version Setup', 'F', 'SETUP', 'Miracom.QCMCore.dll', 'Miracom.QCMCore.frmQCMSetupAttachInspectionItem', ' ', -1, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20070920175511', 'ADMIN', '20070920175511');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('QCM1005', 'Approval and Release Inspection Set Version Setup', 'F', 'SETUP', 'Miracom.QCMCore.dll', 'Miracom.QCMCore.frmQCMSetupApprovalRelease', ' ', -1, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20070920183642', 'ADMIN', '20070920183642');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('QCM1006', 'Inspection Material Setup', 'F', 'SETUP', 'Miracom.QCMCore.dll', 'Miracom.QCMCore.frmQCMSetupMaterial', ' ', -1, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20051226150326', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('QCM2000', '[QCM] Quality Control Management', 'M', 'TRAN', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080116225314', 'ADMIN', '20080116225314');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('QCM2001', 'Tran Create QCM Batch', 'F', 'TRAN', 'Miracom.QCMCore.dll', 'Miracom.QCMCore.frmQCMTranCreateBatch', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20051228143344', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('QCM2002', 'Tran Result Recording', 'F', 'TRAN', 'Miracom.QCMCore.dll', 'Miracom.QCMCore.frmQCMTranResultRecording', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20060131102551', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('QCM2003', 'Tran Final Decision', 'F', 'TRAN', 'Miracom.QCMCore.dll', 'Miracom.QCMCore.frmQCMTranFinalDecision', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20060131102606', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('QCM2006', 'Tran Request Reinspection', 'F', 'TRAN', 'Miracom.QCMCore.dll', 'Miracom.QCMCore.frmQCMTranRequestReinspection', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20080219180040', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('QCM3000', '[QCM] Quality Control', 'F', 'INQUIRY', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080221115406', 'ADMIN', '20080221115406');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('QCM3001', 'View QC Batch Status', 'F', 'INQUIRY', 'Miracom.QCMCore.dll', 'Miracom.QCMCore.frmQCMViewQCBatchStatus', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080221120116', 'ADMIN', '20080221120116');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('QCM3002', 'View QC Batch History', 'F', 'INQUIRY', 'Miracom.QCMCore.dll', 'Miracom.QCMCore.frmQCMViewQCBatchHistory', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20080221162409', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('QCM3003', 'View Inspection History', 'F', 'INQUIRY', 'Miracom.QCMCore.dll', 'Miracom.QCMCore.frmQCMViewInspectionHistory', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20080222151655', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('QCM3004', 'View QC Batch List', 'F', 'INQUIRY', 'Miracom.QCMCore.dll', 'Miracom.QCMCore.frmQCMViewQCBatchList', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20080225133735', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1000', '[RAS] Resource Allocation and Status', 'M', 'RAS', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-2-1.html', ' ', '20080116225339', 'ADMIN', '20080116225339');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1001', 'Resource Setup', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupResource', ' ', 28, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', 'tbpGroup', 'tbpResStatus', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-2-1.html', ' ', '20080109013504', 'ADMIN', '20080109013504');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1002', 'Event Setup', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupEvent', ' ', 29, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpEvent', 'tbpOption', 'tbpGroup', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-2-2.html', ' ', '20080109013701', 'ADMIN', '20080109013701');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1003', 'Resource Group Setup', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupResourceGroup', ' ', 51, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpEvent', 'tbpOption', 'tbpGroup', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-2-2.html', ' ', '20081029134602', 'ADMIN', '20081029134602');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1004', 'Resource - Event Relation Setup', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupAttachEvent', ' ', 53, 'btnDel', 'btnAdd', 'btnDetach', 'btnAttach', 'btnProcess', ' ', ' ', ' ', ' ', ' ', 'tbpResource', 'tbpSubResource', 'tbpEvent', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-2-2.html', ' ', '20081029134636', 'ADMIN', '20081029134636');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1005', 'Resource Labor Setup', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupResourceLabor', ' ', 54, 'btnView', 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-2-2.html', ' ', '20081029134657', 'ADMIN', '20081029134657');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1006', 'PM Security Setup', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupPMSecurity', ' ', 56, 'btnDel', 'btnAdd', 'btnDetach', 'btnAttach', 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029134709', 'ADMIN', '20081029134709');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1007', 'PM Schedule Setup', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupPMSchedule', ' ', 57, 'btnDel', 'btnView', 'btnCreate', 'btnDelete', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029134719', 'ADMIN', '20081029134719');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1008', 'Carrier Setup', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupCarrier', ' ', 61, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029134752', 'ADMIN', '20081029134752');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1009', 'Tool Type Setup', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupToolType', ' ', 64, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029140504', 'ADMIN', '20081029140504');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1010', 'Tool Event Setup', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupToolEvent', ' ', 65, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029140550', 'ADMIN', '20081029140550');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1011', 'Sub Resource Setup', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupSubResource', ' ', 55, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-2-1.html', ' ', '20081029140620', 'ADMIN', '20081029140620');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1012', 'Tool Setup', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupTool', ' ', 66, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029140630', 'ADMIN', '20081029140630');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1013', 'Tool - Event Relation Setup', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupToolEventRelation', ' ', 67, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpTool', 'tbpToolEvent', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029140640', 'ADMIN', '20081029140640');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1014', 'Port Setup', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupPort', ' ', 47, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029140845', 'ADMIN', '20081029140845');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1015', 'Resource - Resource Group Relation Setup', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupResourceGroupRelation', ' ', 52, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpEvent', 'tbpOption', 'tbpGroup', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-2-2.html', ' ', '20081029140902', 'ADMIN', '20081029140902');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1016', 'Resource MFO Relation Setup', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupResourceMFORelation', ' ', 108, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpEvent', 'tbpOption', 'tbpGroup', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-2-2.html', ' ', '20081031093609', 'ADMIN', '20081031093609');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1017', 'Carrier Group Setup', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupCarrierGroup', ' ', 62, 'btnCreate', 'btnUpdate', 'btnDelete', 'btnClose', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029140958', 'ADMIN', '20081029140958');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1018', 'Carrier Group Relation Setup', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupCarrierGroupRelation', ' ', 109, 'btnCreate', 'btnUpdate', 'btnDelete', 'btnClose', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081031093243', 'ADMIN', '20081031093243');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1019', 'Check Query Setup', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupCheckQuery', ' ', 58, 'btnDel', 'btnView', 'btnCreate', 'btnDelete', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20081029141156', 'ADMIN', '20081029141156');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1020', 'Attach Query To Check List', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupAttachQueryToCheck', ' ', 59, 'btnDel', 'btnView', 'btnCreate', 'btnDelete', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20081029141205', 'ADMIN', '20081029141205');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1021', 'Check Type Definition', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupCheckTypeDef', ' ', 60, 'btnDel', 'btnView', 'btnCreate', 'btnDelete', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20081029141220', 'ADMIN', '20081029141220');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS1022', 'Carrier Event Setup', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASSetupCarrierEvent', ' ', 63, 'btnDel', 'btnView', 'btnCreate', 'btnDelete', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20081029141308', 'ADMIN', '20081029141308');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS2000', '[RAS] Resource Allocation and Status', 'M', 'RAS', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-4.html', ' ', '20080116225348', 'ADMIN', '20080116225348');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS2001', 'Tran Event', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASTranEvent', ' ', 30, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpGeneral', 'tbpResData', 'tbpResStatus', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-4.html', ' ', '20080116230731', 'ADMIN1', '20080116230731');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS2002', 'Tran Delete Resource History', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASTranDeleteResourceHistory', ' ', 90, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-4.html', ' ', '20081029141423', 'ADMIN', '20081029141423');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS2003', 'Tran Clean Carrier', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASTranCleanCarrier', ' ', 92, 'btnDelete', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-4.html', ' ', '20081029141438', 'ADMIN', '20081029141438');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS2004', 'Tran Attach Lot To Carrier', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASTranAttachLotToCarrier', ' ', 93, 'btnUpdate', 'btnDelete', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-4.html', ' ', '20081029141510', 'ADMIN', '20081029141510');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS2005', 'Tran Tool Event', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASTranToolEvent', ' ', 98, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-4.html', ' ', '20081029141525', 'ADMIN', '20081029141525');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS2006', 'Tran Delete Tool History', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASTranDeleteToolHistory', ' ', 68, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-4.html', ' ', '20081029141549', 'ADMIN', '20081029141549');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS2007', 'Tran Change Port State', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASTranChangePortStatus', ' ', 110, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-4.html', ' ', '20081031093304', 'ADMIN', '20081031093304');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS2008', 'Tran Attach Carrier To Lot', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASTranAttachCarrierToLot', ' ', 94, 'btnUpdate', 'btnDelete', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-4.html', ' ', '20081029141633', 'ADMIN', '20081029141633');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS2009', 'Tran Assign SublotTo Carrier', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASTranAssignSublotToCarrier', ' ', 95, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-4.html', ' ', '20081029141656', 'ADMIN', '20081029141656');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS2010', 'Delete Sub Resource History', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASTranDeleteSubResourceHistory', ' ', 91, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029141704', 'ADMIN', '20081029141704');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS2011', 'Tran Sub Resource Event', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASTranSubEvent', ' ', 89, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpGeneral', 'tbpResData', 'tbpResStatus', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-4.html', ' ', '20081029141916', 'ADMIN', '20081029141916');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS2012', 'Tran Carrier Change/Exchange', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASTranCarrierChange', ' ', 96, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029141932', 'ADMIN', '20081029141932');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS2013', 'Make Check Result', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASTranMakeCheckResult', ' ', 115, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20081031093324', 'ADMIN', '20081031093324');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS2014', 'Tran Change Transfer State', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASTranChangeTransferState', ' ', 111, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-4.html', ' ', '20081031093334', 'ADMIN', '20081031093334');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS2015', 'Tran Change Association State', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASTranChangeAssociationState', ' ', 112, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-4.html', ' ', '20081031093406', 'ADMIN', '20081031093406');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS2016', 'Tran Change Access Mode State', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASTranChangeAccessModeState', ' ', 113, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-4.html', ' ', '20081031093413', 'ADMIN', '20081031093413');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS2017', 'Tran Change Reservation State', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASTranChangeReservationState', ' ', 114, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-4.html', ' ', '20081031093421', 'ADMIN', '20081031093421');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS2018', 'Tran Carrier Event', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASTranCarrierEvent', ' ', 97, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-4.html', ' ', '20081029142007', 'ADMIN', '20081029142007');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3000', '[RAS] Resource Allocation and Status', 'M', 'RAS', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', ' ', '20080116225357', 'ADMIN', '20080116225357');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3001', 'View Resource Status', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewResourceStatus', ' ', 188, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', 'ADMIN', '20040715145505', 'ADMIN', '20081127162020');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3002', 'View Resource History', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewResourceHistory', ' ', 189, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', 'ADMIN', '20040715145517', 'ADMIN', '20081127162024');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3004', 'View Resource By Group', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewResourceByGroup', ' ', 192, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', 'ADMIN', '20040715145540', 'ADMIN', '20081127162107');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3005', 'View Resource By MFO', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewResourceByMFO', ' ', 193, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', 'ADMIN', '20040715145554', 'ADMIN', '20081127162117');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3006', 'View Lot By Resource', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewLotbyResource', ' ', 194, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', 'ADMIN', '20040715145613', 'ADMIN', '20081127162127');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3007', 'View Event By Group', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewEventByGroup', ' ', 195, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', 'ADMIN', '20040715145634', 'ADMIN', '20081127162140');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3008', 'View Lot List by Resource Group', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewLotByResourceGroup', ' ', 196, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', 'MESPLUS', '20040810183803', 'ADMIN', '20081127162149');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3009', 'View Resource Down History', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewResourceDownHistory', ' ', 197, 'btnUpdate', 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', 'MESPLUS', '20040812134329', 'ADMIN', '20081127162158');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3010', 'View Resource Labor', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewResourceLabor', ' ', 198, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', 'MESPLUS', '20040813175932', 'ADMIN', '20081127162208');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3011', 'View PM Schedule - In view of Planner', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewPMSchedule_Planner', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', ' ', '20050509150046', 'ADMIN', '20050509150046');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3012', 'View PM Schedule - In view of Actor', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewPMSchedule_Actor', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', 'ADMIN', '20050509150057', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3013', 'View Tool', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewTool', ' ', 203, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', ' ', '20050727104424', 'ADMIN', '20081127162247');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3014', 'View Tool List by Operation', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewToolListbyOper', ' ', 205, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', ' ', '20050729113750', 'ADMIN', '20081127163302');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3015', 'View Tool History', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewToolHistory', ' ', 207, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', ' ', '20050727104408', 'ADMIN', '20081127164031');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3016', 'View Tool Defect Data', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewToolDefectList', ' ', 208, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', 'ADMIN', '20050727104356', 'ADMIN', '20081127164041');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3017', 'View Tool List by Resource', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewToolListbyRes', ' ', 206, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', 'ADMIN', '20050729113953', 'ADMIN', '20081127164022');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3018', 'View Tool List', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewToolList', ' ', 204, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', ' ', '20050809092058', 'ADMIN', '20081127163250');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3019', 'View Port History', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewPortHistory', ' ', 190, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', 'ADMIN', '20051122140337', 'ADMIN', '20081127162039');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3020', 'View Sub Resource History', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewSubResourceHistory', ' ', 191, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', 'ADMIN', '20060120120450', 'ADMIN', '20081127162048');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3021', 'View Carrier Status', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewCarrierStatus', ' ', 199, 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', 'ADMIN', '20060419172047', 'ADMIN', '20081127162217');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3022', 'View Carrier History', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewCarrierHistory', ' ', 200, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', 'ADMIN', '20060419172125', 'ADMIN', '20081127162224');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3023', 'View Carrier History By Lot', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewCarrierHistoryByLot', ' ', 201, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', 'ADMIN', '20060420182116', 'ADMIN', '20081127162232');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3024', 'View Carrier Lot List', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewCarrierLotList', ' ', 202, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-2-1.html', 'ADMIN', '20071204063002', 'ADMIN', '20081127162239');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RAS3025', 'View Check Result', 'F', 'RAS', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASViewCheckResult', ' ', 209, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080804100025', 'ADMIN', '20081127164059');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RCP1000', '[RCP] Recipe', 'M', 'SETUP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080116225414', 'ADMIN', '20080116225414');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RCP1001', 'Recipe Setup', 'F', 'SETUP', 'Miracom.RCPCore.dll', 'Miracom.RCPCore.frmRCPSetupRecipe', ' ', 136, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20070920175519', 'ADMIN', '20081127160859');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RCP1002', 'Recipe Version Setup', 'F', 'SETUP', 'Miracom.RCPCore.dll', 'Miracom.RCPCore.frmRCPSetupRecipeVersion', ' ', 137, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20070920175526', 'ADMIN', '20081127160909');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RCP1003', 'Approval and Release Setup', 'F', 'SETUP', 'Miracom.RCPCore.dll', 'Miracom.RCPCore.frmRCPSetupApprovalRelease', ' ', 138, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20070920175535', 'ADMIN', '20081127160918');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RCP1004', 'Attach Recipe To MFO Setup', 'F', 'SETUP', 'Miracom.RCPCore.dll', 'Miracom.RCPCore.frmRCPSetupAttachRecipeToMFO', ' ', 139, 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20070920175541', 'ADMIN', '20081127160927');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RCP2000', '[RCP] Recipe', 'M', 'TRAN', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080116225424', 'ADMIN', '20080116225424');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RCP2001', 'Tran Modify Lot Recipe', 'F', 'TRAN', 'Miracom.RCPCore.dll', 'Miracom.RCPCore.frmRCPTranModifyLotRecipe', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20050630181045', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RCP2002', 'Tran Modify Sublot Recipe', 'F', 'TRAN', 'Miracom.RCPCore.dll', 'Miracom.RCPCore.frmRCPTranModifySublotRecipe', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20050630181058', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RCP3000', '[RCP] Recipe', 'M', 'INQUIRY', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080116225434', 'ADMIN', '20080116225434');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RCP3001', 'View Lot Recipe History', 'F', 'INQUIRY', 'Miracom.RCPCore.dll', 'Miracom.RCPCore.frmRCPViewLotRecipeHistory', ' ', 212, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20050630181123', 'ADMIN', '20081127164151');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RCP3002', 'View Sublot Recipe History', 'F', 'INQUIRY', 'Miracom.RCPCore.dll', 'Miracom.RCPCore.frmRCPViewSublotRecipeHistory', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20050630181134', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD1000', '[RTD]Real Time Dispatcher', 'M', 'SETUP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080827104027', 'ADMIN', '20080827104027');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD1001', 'Dispatcher Setup', 'F', 'SETUP', 'Miracom.RTDCore.dll', 'Miracom.RTDCore.frmRTDSetupDispatcher', ' ', 142, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20070920175552', 'ADMIN', '20081127161106');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD1002', 'Dispatcher Rule Setup', 'F', 'SETUP', 'Miracom.RTDCore.dll', 'Miracom.RTDCore.frmRTDSetupRule', ' ', 141, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080618173519', 'ADMIN', '20081127161005');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD1003', 'Dispatcher Relation Setup', 'F', 'SETUP', 'Miracom.RTDCore.dll', 'Miracom.RTDCore.frmRTDSetupDispatcherRelation', ' ', 144, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080617174925', 'ADMIN', '20081127161036');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD1004', 'Dispatcher Simulation Setup', 'F', 'SETUP', 'Miracom.RTDCore.dll', 'Miracom.RTDCore.frmRTDSetupDispatcherSimulation', ' ', 143, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20080617174942', 'ADMIN', '20081127161044');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD1005', 'Dispatcher Rule Item Setup', 'F', 'SETUP', 'Miracom.RTDCore.dll', 'Miracom.RTDCore.frmRTDSetupRuleItem', ' ', 141, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20080618173559', 'ADMIN', '20081127161238');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD1006', 'Reference Operation Setup', 'F', 'SETUP', 'Miracom.RTDCore.dll', 'Miracom.RTDCore.frmRTDSetupReferenceOperation', ' ', 145, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080827104205', 'ADMIN', '20081127161253');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD1007', 'Dispatch Event Configuration Setup', 'F', 'SETUP', 'Miracom.RTDCore.dll', 'Miracom.RTDCore.frmRTDSetupDispatcherEvent', ' ', 250, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080925180420', 'ADMIN', '20081128091129');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD2000', '[RTD] Real Time Dispatcher', 'M', 'TRAN', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080917174250', 'ADMIN', '20080917174250');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD2001', 'Adjust Lot Priority', 'M', 'INQUIRY', 'Miracom.RTDCore.dll', 'Miracom.RTDCore.frmRTDTranAdjustPriority', ' ', 180, 'btnView', 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20080828154234', 'ADMIN', '20081127161847');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD2002', 'Re-Dispatch Lot', 'M', 'INQUIRY', 'Miracom.RTDCore.dll', 'Miracom.RTDCore.frmRTDTranReDispatchLot', ' ', 181, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080910144012', 'ADMIN', '20081127161859');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD3000', '[RTD]Real Time Dispatcher', 'M', 'SETUP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080827105829', 'ADMIN', '20080827105829');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD3001', 'View Dispatch Event Interface History', 'M', 'INQUIRY', 'Miracom.RTDCore.dll', 'Miracom.RTDCore.frmRTDViewDispatcherEventHistory', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080925180428', 'ADMIN', '20080925180428');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD3002', 'View Pre-Dispatched History', 'M', 'INQUIRY', 'Miracom.RTDCore.dll', 'Miracom.RTDCore.frmRTDViewPreDispatchedHistory', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20080827175106', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD3003', 'View Dispatched Lot List', 'M', 'INQUIRY', 'Miracom.RTDCore.dll', 'Miracom.RTDCore.frmRTDViewDispatchedLotList', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20080902113035', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('RTD3004', 'View Dispatched Resource List', 'M', 'INQUIRY', 'Miracom.RTDCore.dll', 'Miracom.RTDCore.frmRTDViewDispatchedResourceList', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20080902113049', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SEC1000', '[SEC] Security', 'M', 'SETUP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-4a2.html', ' ', '20080116225513', 'ADMIN', '20080116225513');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SEC1001', 'User Setup', 'F', 'SETUP', 'Miracom.SECCore.dll', 'Miracom.SECCore.frmSECSetupUser', ' ', 39, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-4a2.html', ' ', '20081029142047', 'ADMIN', '20081029142047');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SEC1002', 'Security Group Setup', 'F', 'SETUP', 'Miracom.SECCore.dll', 'Miracom.SECCore.frmSECSetupSecurityGroup', ' ', 40, 'btnCopy', 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-4a2.html', ' ', '20081029142101', 'ADMIN', '20081029142101');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SEC1003', 'Function Setup', 'F', 'SETUP', 'Miracom.SECCore.dll', 'Miracom.SECCore.frmSECSetupFunction', ' ', 42, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-4a2.html', ' ', '20081029142118', 'ADMIN', '20081029142118');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SEC1004', 'Assign Function to Security Group', 'F', 'SETUP', 'Miracom.SECCore.dll', 'Miracom.SECCore.frmSECSetupGroupFunction', ' ', 41, 'btnDel', 'btnAdd', 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-4a2.html', ' ', '20081029142135', 'ADMIN', '20081029142135');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SEC1005', 'Privilege Group Setup', 'F', 'SETUP', 'Miracom.SECCore.dll', 'Miracom.SECCore.frmSECSetupPrivilegeGroup', ' ', 43, 'btnCopy', 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029142149', 'ADMIN', '20081029142149');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SEC1006', 'Privilege Group - User Relation Setup', 'F', 'SETUP', 'Miracom.SECCore.dll', 'Miracom.SECCore.frmSECSetupPrvUser', ' ', 45, 'btnDel', 'btnAdd', 'btnDetach', 'btnAttach', 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029142200', 'ADMIN', '20081029142200');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SEC1007', 'Privilege Definition Setup', 'F', 'SETUP', 'Miracom.SECCore.dll', 'Miracom.SECCore.frmSECSetupPrivilege', ' ', 44, 'btnCopy', 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029142210', 'ADMIN', '20081029142210');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SEC1010', 'Flexible Header Setup', 'F', 'SETUP', 'Miracom.SECCore.dll', 'Miracom.SECCore.frmSECSetupFlexibleHeader', ' ', 118, 'btnCreate', 'btnUpdate', 'btnDelete', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20080825094212', 'ADMIN', '20081127155508');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC0001', 'Setup', 'M', 'SPC', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071106214256', 'ADMIN', '20071106214256');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC0002', 'Transaction', 'M', 'SPC', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071106214304', 'ADMIN', '20071106214304');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC0003', 'Analysis', 'M', 'SPC', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071106214309', 'ADMIN', '20071106214309');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC0004', 'Inquiry', 'M', 'SPC', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071106214314', 'ADMIN', '20071106214314');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC0005', 'Maintenance', 'M', 'SPC', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071106214320', 'ADMIN', '20071106214320');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC0006', 'Utilities', 'M', 'SPC', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071106214347', 'ADMIN', '20071106214347');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC0007', 'Favorites', 'M', 'SPC', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20071107211235', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC1001', 'Character Setup', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCSetupCharacter', ' ', 33, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'SPC_UserManual.1.21.html', ' ', '20080109014208', 'ADMIN', '20080109014208');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC1002', 'Chart Setup', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCSetupChart', ' ', 225, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'SPC_UserManual.1.22.html', ' ', '20070920175715', 'ADMIN', '20081127173227');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC1003', 'Spec Management Setup', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCSpecManagement', ' ', 226, 'btnCreate', 'btnDelete', 'btnUpdate', 'btnRelease', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'SPC_UserManual.1.23.html', ' ', '20070920175726', 'ADMIN', '20081127173238');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC1004', 'Attach User to Chart Setup', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCAttachUserToChart', ' ', 227, 'btnAdd', 'btnDel', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'SPC_UserManual.1.24.html', ' ', '20070920175733', 'ADMIN', '20081127173243');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC1005', 'Chart Set Setup', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCSetupChartSet', ' ', 228, 'btnCreate', 'btnUpdate', 'btnDelete', 'btnAdd', 'btnDel', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071107181715', 'ADMIN', '20081127173252');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC1006', 'Trouble and Action Code Setup', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCSetupGCMData', ' ', 229, 'btnCreate', 'btnUpdate', 'btnDelete', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080226091259', 'ADMIN', '20081127173301');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC1007', 'Attach Chart to MFO', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCAttachChartToMFO', ' ', -1, 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20060123164957', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC1008', 'EDC Prompt Setup', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCSetupPrompt', ' ', -1, 'btnUpdate', 'btnDelete', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20060223175411', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC2001', 'Tran Collect Lot Data', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCTranCollectLotData', ' ', -1, 'btnOK', 'btnReset', 'btnGraph', 'btnRawData', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20051028132544', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC2002', 'Tran Collect Resource Data', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCTranCollectResourceData', ' ', -1, 'btnOK', 'btnReset', 'btnGraph', 'btnRawData', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'SPC_UserManual.1.29.html', ' ', '20051028134043', 'ADMIN', '20051028134043');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC2003', 'Tran Clear Alarm', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCTranClearAlarm', ' ', -1, 'btnView', 'btnClear', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20051028132658', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC2004', 'Tran Collect EDC Data by Chart Set', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCTranCollectLotDatabyCharacter', ' ', -1, 'btnOK', 'btnHistogram', 'btnGraph', 'btnRawData', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071107191336', 'ADMIN', '20071107191336');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC2005', 'Tran Collect Resource Data by Chart Set (Type1)', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCTranCollectResDatabyCharacter', ' ', -1, 'btnOK', 'btnHistogram', 'btnGraph', 'btnRawData', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071107191415', 'ADMIN', '20071107191415');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC2006', 'Tran Collect Lot Data by Chart Set (Type2)', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCTranCollectLotDatabyChartSet', ' ', -1, 'btnOK', 'btnHistogram', 'btnGraph', 'btnRawData', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071107191442', 'ADMIN', '20071107191442');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC2007', 'Tran Collect Resource Data by Chart Set (Type2)', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCTranCollectResDatabyChartSet', ' ', -1, 'btnOK', 'btnHistogram', 'btnGraph', 'btnRawData', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071107191503', 'ADMIN', '20071107191503');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC2008', 'Tran Collect Lot Data by Chart Set (Type3)', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCTranCollectLotDataType3', ' ', -1, 'btnOK', 'btnHistogram', 'btnGraph', 'btnRawData', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071107191525', 'ADMIN', '20071107191525');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC2009', 'Tran Collect Resource Data by Chart Set (Type3)', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCTranCollectResDataType3', ' ', -1, 'btnOK', 'btnHistogram', 'btnGraph', 'btnRawData', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071107191550', 'ADMIN', '20071107191550');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC3001', 'Analysis Realtime Monitoring Control Chart', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCTranOnLineChart', ' ', -1, 'btnMonitoring', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'SPC_UserManual.1.31.html', ' ', '20071107191642', 'ADMIN', '20071107191642');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC3002', 'Analysis Multi Realtime Monitoring Control Chart', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCTranDynamicMultiChart', ' ', -1, 'btnMonitoring', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20071107191729', 'ADMIN', '20071107191729');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC3003', 'Analysis Control Chart', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCTranControlChart', ' ', -1, 'btnView', 'btnHistogram', 'btnViewRawData', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'SPC_UserManual.1.32.html', ' ', '20071107191758', 'ADMIN', '20071107191758');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC3004', 'Analysis Capability Analysis', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCTranCapability', ' ', 232, 'btnView', 'btnGraph', 'btnViewRawData', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'SPC_UserManual.1.33.html', ' ', '20071107191819', 'ADMIN', '20081127173405');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC4001', 'Inquiry View EDC Data', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCViewEDCData', ' ', 234, 'btnView', 'btnGraph', 'btnHistogram', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'SPC_UserManual.1.35.html', ' ', '20051028134145', 'ADMIN', '20081127173430');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC4002', 'View Spec History', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCViewSpecHistory', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'SPC_UserManual.1.36.html', ' ', '20070920200910', 'ADMIN', '20070920200910');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC4003', 'Inquiry View OOC History', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCViewOOCHistory', ' ', 235, 'btnView', 'btnTrouble', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'SPC_UserManual.1.37.html', ' ', '20051028134203', 'ADMIN', '20081127173438');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC4004', 'Inquiry View Process Capability', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCViewProcessCapability', ' ', 236, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'SPC_UserManual.1.39.html', ' ', '20080805210008', 'ADMIN', '20081127173450');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC4005', 'Inquiry View Alarm History', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCViewAlarmHistory', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20051028133721', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC4006', 'Inquiry View Lot List by Operation', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCViewLotListbyOperation', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'SPC_UserManual.1.40.html', ' ', '20051028134226', 'ADMIN', '20051028134226');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC4007', 'Inquiry View Resource List Detail', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCViewResourceList', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'SPC_UserManual.1.41.html', ' ', '20051028134236', 'ADMIN', '20051028134236');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC4008', 'Inquiry View Excluded EDC History', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCViewExcludedEDCHistory', ' ', 237, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20051125110854', 'ADMIN', '20081127173501');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC4009', 'Inquiry View Chart List', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCViewChartList', ' ', 238, 'btnView', 'btnSelect', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20060621165559', 'ADMIN', '20081127173512');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC5001', 'Maintenance Lot Data', 'F', 'SPC', 'Miracom.SPCCore.dll', 'Miracom.SPCCore.frmSPCTranChangeEDCData', ' ', -1, 'btnView', 'btnChange', 'btnDelete', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080226091455', 'ADMIN', '20080226091455');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC6001', 'Utilities Send Message', 'F', 'SPC', 'Miracom.UTLCore.dll', 'Miracom.UTLCore.frmUTLSendMessage', ' ', -1, 'btnSend', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'SPC_UserManual.1.45.html', ' ', '20071107192151', 'ADMIN', '20071107192151');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM1000', '[SVM] Service Manager', 'M', 'SETUP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081028092414', 'ADMIN', '20081028092414');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM1001', 'Service Member Setup', 'F', 'SETUP', 'Miracom.SVMCore.dll', 'Miracom.SVMCore.frmSVMSetupServiceMember', ' ', 150, 'btnCreate', 'btnDelete', 'btnUpdate', 'btnClose', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20080924171446', 'ADMIN', '20081127161413');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM1002', 'Member Setup', 'F', 'SETUP', 'Miracom.SVMCore.dll', 'Miracom.SVMCore.frmSVMSetupMember', ' ', 151, 'btnCreate', 'btnDelete', 'btnUpdate', 'btnClose', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20080924215623', 'ADMIN', '20081127161421');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM1003', 'Default Service Version Setup', 'F', 'SETUP', 'Miracom.SVMCore.dll', 'Miracom.SVMCore.frmSVMSetupSharedFunctionVersion', ' ', -1, 'btnCreate', 'btnUpdate', 'btnDelete', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20080926211031', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM1004', 'Service User Routine Setup', 'F', 'SETUP', 'Miracom.SVMCore.dll', 'Miracom.SVMCore.frmSVMSetupServiceUserRoutine', ' ', -1, 'btnCreate', 'btnDelete', 'btnUpdate', 'btnClose', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20081118175336', 'ADMIN', '20081118180323');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM3000', '[SVM] Service Manager', 'M', 'INQUIRY', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081028092427', 'ADMIN', '20081028092427');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SVM3001', 'View Service Member', 'F', 'INQUIRY', 'Miracom.SVMCore.dll', 'Miracom.SVMCore.frmSVMViewServiceMember', ' ', -1, 'btnView', 'btnClose', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-3.html', 'ADMIN', '20080924171703', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('TOP0001', 'Setup', 'M', 'TOP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-0.html', ' ', '20070904214015', 'ADMIN', '20070904214015');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('TOP0002', 'Transaction', 'M', 'TOP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-0.html', ' ', '20070904214020', 'ADMIN', '20070904214020');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('TOP0003', 'Inquiry', 'M', 'TOP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-0.html', ' ', '20070904214025', 'ADMIN', '20070904214025');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('TOP0004', 'Order', 'M', 'TOP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20070904214030', 'ADMIN', '20070904214030');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('TOP0005', 'Favorites', 'M', 'TOP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual5a3.html', ' ', '20070904214037', 'ADMIN', '20070904214037');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('TOP0006', 'Utilities', 'M', 'TOP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual9.html', ' ', '20070904214043', 'ADMIN', '20070904214043');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('TOP0009', 'SPC', 'M', 'TOP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20070904214100', 'ADMIN', '20070904214100');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('UTL2001', 'Send Message', 'F', 'TRAN', 'Miracom.UTLCore.dll', 'Miracom.UTLCore.frmUTLSendMessage', ' ', 105, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual92.html', ' ', '20081031093659', 'ADMIN', '20081031093659');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('UTL2002', 'Material Loader', 'M', 'ADMIN', 'Siltronic.Pilot.dll', 'Siltronic.Pilot.frmSILTranLoader', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20080123170622', 'ADMIN', '20080123170622');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WFM0001', '[WFM] Work Flow Modeler', 'M', ' ', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20070709142801', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WFM1000', 'Work Flow Modeler WIP', 'F', 'SETUP', 'Miracom.WFMCore.dll', 'Miracom.WFMCore.frmWFMWIPMain', ' ', 152, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081024113034', 'ADMIN', '20081127161439');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WFM2000', 'Work Flow Modeler RAS', 'F', 'SETUP', 'Miracom.WFMCore.dll', 'Miracom.WFMCore.frmWFMRASMain', ' ', 153, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20081024113024', 'ADMIN', '20081127161444');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1000', '[WIP] Work In Process', 'M', 'WIP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-1-1.html', ' ', '20080116225621', 'ADMIN', '20080116225621');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1001', 'Factory Setup', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPSetupFactory', ' ', 0, 'btnDetach', 'btnAttach', 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', 'tbpCmf', 'tbpGeneral', 'tbpGroup', 'tbpResource', 'tbpShipFac', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-1-1.html', ' ', '20071008160445', 'MES19', '20071008160445');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1002', 'Material Setup', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPSetupMaterial', ' ', 1, 'btnAttach', 'btnDetach', 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', 'tbpGeneral', 'tbpFlow', 'tbpCMF', 'tbpGroup', 'tbpProperty', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-1-2.html', ' ', '20070920175831', 'ADMIN', '20070920175831');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1003', 'Flow Setup', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPSetupFlow', ' ', 2, 'btnToRight', 'btnToLeft', 'btnCopy', 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', 'tbpAttachOper', 'tbpCopyFlow', 'tbpCMF', 'tbpGroup', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-1-2.html', ' ', '20070920175841', 'ADMIN', '20070920175841');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1004', 'Operation Setup', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPSetupOperation', ' ', 3, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpGeneral', 'tbpCMF', 'tbpGroup', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-1-2.html', ' ', '20080116225953', 'ADMIN', '20080116225953');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1005', 'Rework Flow Setup', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPSetupReworkFlow', ' ', 4, 'btnAdd', 'btnProcess', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpFO', 'tbpMFO', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-1-3.html', ' ', '20070920175854', 'ADMIN', '20070920175854');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1006', 'Cycle Time Setup', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPSetupCycleTime', ' ', 5, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpOper', 'tbpFlowOper', 'tbpMatFlowOper', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-1-3.html', ' ', '20070920175901', 'ADMIN', '20070920175901');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1007', 'Calendar Setup', 'F', 'WIP', 'Miracom.BASCore.dll', 'Miracom.BASCore.frmBASSetupCalendar', ' ', 119, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-1-4.html', ' ', '20080109014309', 'ADMIN', '20081127155743');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1008', 'Calendar Setup (Detail)', 'F', 'WIP', 'Miracom.BASCore.dll', 'Miracom.BASCore.frmBASSetupCalendarDetail', ' ', 7, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-1-4.html', ' ', '20080109014316', 'ADMIN', '20080109014316');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1009', 'Repair Operation Setup', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPSetupRepairOper', ' ', 48, 'btnAdd', 'btnProcess', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual6-1-3.html', ' ', '20081029142248', 'ADMIN', '20081029142248');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1010', 'Future Action Setup', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPSetupFutureAction', ' ', 122, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpOper', 'tbpFO', 'tbpMFO', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080109014335', 'ADMIN', '20081127160645');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1011', 'Queue Time Setup', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPSetupQueueTime', ' ', 123, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080109014352', 'ADMIN', '20081127160654');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1012', 'Batch Keep Flag Setup', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPSetupBatchKeepMFO', ' ', 106, 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpOper', 'tbpFO', 'tbpMFO', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081031093631', 'ADMIN', '20081031093631');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1013', 'Sublot Option Setup', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPSetupSubLotOptionToMFO', ' ', 49, 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20081029142317', 'ADMIN', '20081029142317');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1014', 'Grade Rule Setup', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPSetupGradeRule', ' ', -1, 'btnCreate', 'btnUpdate', 'btnDelete', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20080818110349', 'ADMIN', '20080818110349');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1016', 'MFO Option Setup', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPSetupMFOOption', ' ', 50, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '20081029142324', 'ADMIN', '20081029142324');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1017', 'Yield Setup', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPSetupYield', ' ', 107, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '20081031093543', 'ADMIN', '20081031093543');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1018', 'ID Generator Setup', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPSetupIDGenerator', ' ', 124, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '20080612102742', 'ADMIN', '20081127160705');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1019', 'ID Generator Relation Setup', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPSetupIDGeneratorRelation', ' ', 125, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '20080612102745', 'ADMIN', '20081127160714');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1020', 'Batch Creation Rule Setup', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPSetupBatchCreationRule', ' ', 126, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '20080616104954', 'ADMIN', '20081127160723');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP1021', 'Batch Creation Rule Relation Setup', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPSetupBatchCreationRuleRelation', ' ', 127, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '20080616104949', 'ADMIN', '20081127160727');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2000', '[WIP] Work In Process', 'M', 'WIP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20080116225630', 'ADMIN', '20080116225630');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2001', 'Create Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranCreateLot', ' ', 8, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpGeneral', 'tbpCMF', 'tbpCreateCmf', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'txtLotID', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20080109014413', 'ADMIN', '20080109014413');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2002', 'Start Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranStartLot', ' ', 9, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20080109014420', 'ADMIN', '20080109014420');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2003', 'Multi Start Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranMultiStartLotNew', ' ', 10, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20080220015122', 'ADMIN', '20080220015122');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2004', 'End Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranEndLot', ' ', 11, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20080109014434', 'ADMIN', '20080109014434');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2005', 'Multi End Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranMultiEndLotNew', ' ', 12, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20080220015128', 'ADMIN', '20080220015128');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2006', 'Move Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranMoveLot', ' ', 13, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20080109014502', 'ADMIN', '20080109014502');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2007', 'Rework Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranReworkLot', ' ', 14, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20080109014511', 'ADMIN', '20080109014511');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2008', 'Split Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranSplitLot', ' ', 15, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpCreateCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-2.html', ' ', '20080109014521', 'ADMIN', '20080109014521');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2009', 'Merge Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranMergeLot', ' ', 16, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-2.html', ' ', '20080109014528', 'ADMIN', '20080109014528');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2010', 'Combine Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranCombineLot', ' ', 18, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-2.html', ' ', '20080109014535', 'ADMIN', '20080109014535');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2012', 'Hold Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranHoldLot', ' ', 19, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-2.html', ' ', '20080109014549', 'ADMIN', '20080109014549');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2013', 'Release Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranReleaseLot', ' ', 20, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-2.html', ' ', '20080109014556', 'ADMIN', '20080109014556');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2014', 'Ship Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranShipLot', ' ', 21, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-3.html', ' ', '20080109014629', 'ADMIN', '20080109014629');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2015', 'Receive Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranReceiveLot', ' ', 22, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-3.html', ' ', '20080109014635', 'ADMIN', '20080109014635');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2016', 'Adapt Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranAdaptLot', ' ', 23, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', 'tbpCrtCmf', 'tbpRework', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-4.html', ' ', '20080109014645', 'ADMIN', '20080109014645');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2017', 'Loss Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranLossLot', ' ', 24, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', 'tbpInfo', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-4.html', ' ', '20080109014652', 'ADMIN', '20080109014652');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2018', 'Bonus Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranBonusLot', ' ', 25, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', 'tbpInfo', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-4.html', ' ', '20080109014658', 'ADMIN', '20080109014658');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2019', 'Delete Lot History', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranDeleteLotHistory', ' ', 27, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-5.html', ' ', '20080109014704', 'ADMIN', '20080109014704');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2020', 'Open Return Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranOpenReturnLot', ' ', 74, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-5.html', ' ', '20081029142416', 'ADMIN', '20081029142416');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2021', 'Close Return Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranCloseReturnLot', ' ', 75, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-5.html', ' ', '20081029142422', 'ADMIN', '20081029142422');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2022', 'Skip Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranSkipLot', ' ', 13, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-5.html', ' ', '20080109014717', 'ADMIN', '20080109014717');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2023', 'Repair Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranRepairLot', ' ', 69, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-5.html', ' ', '20081029142553', 'ADMIN', '20081029142553');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2024', 'Repair End Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranRepairEndLot', ' ', 70, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-5.html', ' ', '20081029142600', 'ADMIN', '20081029142600');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2025', 'Local Repair Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranLocalRepairLot', ' ', 71, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-5.html', ' ', '20081029155933', 'ADMIN', '20081029155933');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2026', 'Store Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranStoreLot', ' ', 72, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029142612', 'ADMIN', '20081029142612');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2027', 'Unstore Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranUnstoreLot', ' ', 73, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029142620', 'ADMIN', '20081029142620');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2028', 'Make Batch', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranMakeBatch', ' ', 76, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029142635', 'ADMIN', '20081029142635');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2029', 'Release Batch', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranReleaseBatch', ' ', 77, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029142641', 'ADMIN', '20081029142641');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2030', 'Start Batch', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranStartBatch', ' ', 78, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029142648', 'ADMIN', '20081029142648');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2031', 'End Batch', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranEndBatch', ' ', 79, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029142654', 'ADMIN', '20081029142654');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2032', 'Collect Lot Defect', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranCollectLotDefect', ' ', 80, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', 'tbpDefect', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029142708', 'ADMIN', '20081029142708');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2033', 'Clean Lot Defect', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranCleanLotDefect', ' ', 81, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029142717', 'ADMIN', '20081029142717');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2034', '[WIPX] Work In Process Extension', 'M', 'WIP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20080116225653', 'ADMIN', '20080116225653');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2035', 'Start Sublot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranStartSublot', ' ', 169, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20051201164858', 'ADMIN', '20081127161727');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2036', 'End Sublot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranEndSublot', ' ', 170, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20051201164858', 'ADMIN', '20081127161731');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2037', 'Rework Sublot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranReworkSublot', ' ', 171, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20051201164858', 'ADMIN', '20081127161737');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2038', 'Delete Sublot History', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranDeleteSublotHistory', ' ', 172, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20051201164858', 'ADMIN', '20081127161742');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2039', 'Split Extension', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranSplitLotExt', ' ', 173, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20051201164858', 'ADMIN', '20081127161746');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2040', 'Merge Extension', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranMergeLotExt', ' ', 174, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20051201164858', 'ADMIN', '20081127161751');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2041', 'Combine Extension', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranCombineLotExt', ' ', 175, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20051201164858', 'ADMIN', '20081127161756');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2042', 'Loss Extension', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranLossLotExt', ' ', 176, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20051201164858', 'ADMIN', '20081127161811');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2043', 'Sort Extension', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranSortLotExt', ' ', 177, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20051201164858', 'ADMIN', '20081127161815');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2047', 'Terminate Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranTerminateLot', ' ', 82, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20081029142734', 'ADMIN', '20081029142734');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2049', 'Multi Terminate Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranMultiTerminateLotNew', ' ', 83, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20081029142740', 'ADMIN', '20081029142740');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2050', 'Make SubLot Batch', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranMakeSubLotBatch', ' ', 86, 'btnMake', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029143948', 'ADMIN', '20081029143948');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2051', 'Reserve Lot Batch', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranReserveLotBatch', ' ', 87, 'btnMake', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029142841', 'ADMIN', '20081029142841');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2052', 'Reserve Sub Lot Batch', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranReserveSubLotBatch', ' ', 88, 'btnMake', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029142846', 'ADMIN', '20081029142846');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2053', 'Reserve Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranReserveLot', ' ', 84, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029142852', 'ADMIN', '20081029142852');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP2054', 'Unreserve Lot', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPTranUnReserveLot', ' ', 85, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20081029142859', 'ADMIN', '20081029142859');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3000', '[WIP] Work In Process', 'M', 'WIP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-1-1.html', ' ', '20080116225703', 'ADMIN', '20080116225703');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3001', 'View Lot Status', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewLotStatus', ' ', 185, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-1-1.html', ' ', '20080109014819', 'ADMIN', '20081127161950');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3002', 'View Lot History', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewLotHistory', ' ', 186, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-1-1.html', ' ', '20080109014825', 'ADMIN', '20081127161959');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3004', 'View Lot Trace', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewLotTrace', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-1-1.html', ' ', '20080109014832', 'ADMIN', '20080109014832');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3005', 'View Material By Group', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewMaterialByGroup', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-1-1.html', 'ADMIN', '20040715144927', 'MESPLUS', '20040908170920');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3006', 'View Material By Flow', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewMaterialByFlow', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-1-1.html', 'ADMIN', '20040715145026', 'MESPLUS', '20040908170926');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3007', 'View Flow By Operation', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewFlowByOperation', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-1-1.html', 'ADMIN', '20040715145050', 'MESPLUS', '20040908170929');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3008', 'View Lot List By Operation', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewLotListByOperation', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-1-1.html', 'ADMIN', '20040715145004', 'MESPLUS', '20040908170932');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3009', 'View Shipped Lot List', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewShippedLotList', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-1-2.html', 'ADMIN', '20040715145119', 'MESPLUS', '20040908170948');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3010', 'View Hold Lot List', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewHoldLotList', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-1-2.html', 'ADMIN', '20040715145136', 'MESPLUS', '20040908170951');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3011', 'View Trouble Lot List', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewTroubleLotList', ' ', -1, 'btnProcess', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-1-2.html', 'ADMIN', '20040715145158', 'MESPLUS', '20040908170954');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3012', 'View Rework Lot List', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewReworkLotList', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'tbpCMF', 'tbpGeneral', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-1-2.html', 'MESPLUS', '20040819152248', 'MESPLUS', '20040908170958');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3013', 'View Return Lot List', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewReturnLotList', ' ', -1, 'btnOpen', 'btnProcess', 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-1-2.html', ' ', '20051215092925', 'ADMIN', '20051215092925');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3014', 'View Lot Defect List', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewLotDefectList', ' ', -1, 'btnProcess', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual8-1-2.html', 'ADMIN', '20051215092841', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3015', '[WIPX] Work In Process Extension', 'M', 'WIP', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20080116225717', 'ADMIN', '20080116225717');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3016', 'View Sublot Status', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewSublotStatus', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20051201164858', 'ADMIN', '20051201164858');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3017', 'View Sublot List', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewSubLotList', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20070912201410', 'AA', '20070912201410');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3018', 'View Sublot History', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewSubLotHistory', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20070912201417', 'AA', '20070912201417');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3020', 'View Lot Bonus List', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewLotBonusList', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20071204063518', 'ADMIN', '20071204063518');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3021', 'View Lot Loss List', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewLotLossList', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', ' ', '20071204063504', 'ADMIN', '20071204063504');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3024', 'View Data List By Attribute', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewDataListByAttribute', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', 'ADMIN', '20080130024058', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3025', 'View Sublot Loss List', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewSublotLossList', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'MES_UserManual7-1-1.html', 'ADMIN', '20080225005935', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3026', 'View Batch Status', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewBatchStatus', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20080618154626', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP3027', 'View Batch History', 'F', 'WIP', 'Miracom.WIPCore.dll', 'Miracom.WIPCore.frmWIPViewBatchHistory', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20080619174356', ' ', ' ');




RENAME MWIPSLTSTS TO  MWIPSLTSTS_OLD;

CREATE TABLE MWIPSLTSTS
(
  SUBLOT_ID              VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  LOT_ID                 VARCHAR2(25)      DEFAULT (' ')                 NOT NULL,
  FACTORY                VARCHAR2(10)      DEFAULT (' ')                 NOT NULL,
  MAT_ID                 VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  MAT_VER                NUMBER(6)         DEFAULT (0)                   NOT NULL,
  FLOW                   VARCHAR2(20)      DEFAULT (' ')                 NOT NULL,
  FLOW_SEQ_NUM           NUMBER(6)         DEFAULT (0)                   NOT NULL,
  OPER                   VARCHAR2(10)      DEFAULT (' ')                 NOT NULL,
  SLOT_NO                NUMBER(6)         DEFAULT (0)                   NOT NULL,
  QTY_2                  NUMBER(10,3)      DEFAULT (0.0)                 NOT NULL,
  QTY_3                  NUMBER(10,3)      DEFAULT (0.0)                 NOT NULL,
  CRR_ID                 VARCHAR2(20)      DEFAULT (' ')                 NOT NULL,
  OWNER_CODE             VARCHAR2(10)      DEFAULT (' ')                 NOT NULL,
  CREATE_CODE            VARCHAR2(10)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_STATUS          VARCHAR2(10)      DEFAULT (' ')                 NOT NULL,
  HOLD_FLAG              CHAR(1)           DEFAULT (' ')                 NOT NULL,
  HOLD_CODE              VARCHAR2(10)      DEFAULT (' ')                 NOT NULL,
  HOLD_PASSWORD          VARCHAR2(20)      DEFAULT (' ')                 NOT NULL,
  HOLD_PRV_GRP_ID        VARCHAR2(20)      DEFAULT (' ')                 NOT NULL,
  OPER_IN_QTY_2          NUMBER(10,3)      DEFAULT (0.0)                 NOT NULL,
  OPER_IN_QTY_3          NUMBER(10,3)      DEFAULT (0.0)                 NOT NULL,
  CREATE_QTY_2           NUMBER(10,3)      DEFAULT (0.0)                 NOT NULL,
  CREATE_QTY_3           NUMBER(10,3)      DEFAULT (0.0)                 NOT NULL,
  START_QTY_2            NUMBER(10,3)      DEFAULT (0.0)                 NOT NULL,
  START_QTY_3            NUMBER(10,3)      DEFAULT (0.0)                 NOT NULL,
  INV_FLAG               CHAR(1)           DEFAULT (' ')                 NOT NULL,
  TRANSIT_FLAG           CHAR(1)           DEFAULT (' ')                 NOT NULL,
  UNIT_EXIST_FLAG        CHAR(1)           DEFAULT (' ')                 NOT NULL,
  INV_UNIT               VARCHAR2(10)      DEFAULT (0.0)                 NOT NULL,
  RWK_FLAG               CHAR(1)           DEFAULT (' ')                 NOT NULL,
  RWK_CODE               VARCHAR2(10)      DEFAULT (' ')                 NOT NULL,
  RWK_COUNT              NUMBER(6)         DEFAULT (0)                   NOT NULL,
  RWK_RET_FLOW           VARCHAR2(20)      DEFAULT (' ')                 NOT NULL,
  RWK_RET_FLOW_SEQ_NUM   NUMBER(6)         DEFAULT (0)                   NOT NULL,
  RWK_RET_OPER           VARCHAR2(10)      DEFAULT (' ')                 NOT NULL,
  RWK_END_FLOW           VARCHAR2(20)      DEFAULT (' ')                 NOT NULL,
  RWK_END_FLOW_SEQ_NUM   NUMBER(6)         DEFAULT (0)                   NOT NULL,
  RWK_END_OPER           VARCHAR2(10)      DEFAULT (' ')                 NOT NULL,
  RWK_RET_CLEAR_FLAG     CHAR(1)           DEFAULT (' ')                 NOT NULL,
  RWK_TIME               VARCHAR2(14)      DEFAULT (' ')                 NOT NULL,
  NSTD_FLAG              CHAR(1)           DEFAULT (' ')                 NOT NULL,
  NSTD_RET_FLOW          VARCHAR2(20)      DEFAULT (' ')                 NOT NULL,
  NSTD_RET_FLOW_SEQ_NUM  NUMBER(6)         DEFAULT (0)                   NOT NULL,
  NSTD_RET_OPER          VARCHAR2(10)      DEFAULT (' ')                 NOT NULL,
  NSTD_TIME              VARCHAR2(14)      DEFAULT (' ')                 NOT NULL,
  REP_FLAG               CHAR(1)           DEFAULT (' ')                 NOT NULL,
  REP_RET_OPER           VARCHAR2(10)      DEFAULT (' ')                 NOT NULL,
  STR_RET_FLOW           VARCHAR2(20)      DEFAULT (' ')                 NOT NULL,
  STR_RET_FLOW_SEQ_NUM   NUMBER(6)         DEFAULT (0)                   NOT NULL,
  STR_RET_OPER           VARCHAR2(10)      DEFAULT (' ')                 NOT NULL,
  CREATE_TIME            VARCHAR2(14)      DEFAULT (' ')                 NOT NULL,
  FAC_IN_TIME            VARCHAR2(14)      DEFAULT (' ')                 NOT NULL,
  FLOW_IN_TIME           VARCHAR2(14)      DEFAULT (' ')                 NOT NULL,
  OPER_IN_TIME           VARCHAR2(14)      DEFAULT (' ')                 NOT NULL,
  START_FLAG             CHAR(1)           DEFAULT (' ')                 NOT NULL,
  START_TIME             VARCHAR2(14)      DEFAULT (' ')                 NOT NULL,
  START_RES_ID           VARCHAR2(20)      DEFAULT (' ')                 NOT NULL,
  END_FLAG               CHAR(1)           DEFAULT (' ')                 NOT NULL,
  END_TIME               VARCHAR2(14)      DEFAULT (' ')                 NOT NULL,
  END_RES_ID             VARCHAR2(20)      DEFAULT (' ')                 NOT NULL,
  SAMPLE_FLAG            CHAR(1)           DEFAULT (' ')                 NOT NULL,
  SAMPLE_WAIT_FLAG       CHAR(1)           DEFAULT (' ')                 NOT NULL,
  SAMPLE_RESULT          CHAR(1)           DEFAULT (' ')                 NOT NULL,
  RESERVE_RES_ID         VARCHAR2(20)      DEFAULT (' ')                 NOT NULL,
  PORT_ID                VARCHAR2(20)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_LOCATION_1      VARCHAR2(20)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_LOCATION_2      VARCHAR2(20)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_LOCATION_3      VARCHAR2(20)      DEFAULT (' ')                 NOT NULL,
  SUBRES_ID              VARCHAR2(20)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_1           VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_2           VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_3           VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_4           VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_5           VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_6           VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_7           VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_8           VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_9           VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_10          VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_11          VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_12          VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_13          VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_14          VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_15          VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_16          VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_17          VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_18          VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_19          VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_20          VARCHAR2(30)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_DEL_FLAG        CHAR(1)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_DEL_CODE        VARCHAR2(10)      DEFAULT (' ')                 NOT NULL,
  SUBLOT_DEL_TIME        VARCHAR2(14)      DEFAULT (' ')                 NOT NULL,
  GRADE                  CHAR(1)           DEFAULT (' ')                 NOT NULL,
  GRADE_CODE             VARCHAR2(10)      DEFAULT (' ')                 NOT NULL,
  CELL_GRADE             VARCHAR2(200)     DEFAULT (' ')                 NOT NULL,
  LOT_BASE               CHAR(1)           DEFAULT (' ')                 NOT NULL,
  LOT_HIST_SEQ           NUMBER(10)        DEFAULT (0)                   NOT NULL,
  LAST_TRAN_CODE         VARCHAR2(12)      DEFAULT (' ')                 NOT NULL,
  LAST_TRAN_TIME         VARCHAR2(14)      DEFAULT (' ')                 NOT NULL,
  LAST_COMMENT           VARCHAR2(400)     DEFAULT (' ')                 NOT NULL,
  LAST_ACTIVE_HIST_SEQ   NUMBER(10)        DEFAULT (0)                   NOT NULL,
  LAST_HIST_SEQ          NUMBER(10)        DEFAULT (0)                   NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

INSERT INTO MWIPSLTSTS VALUE
(SELECT 
  SUBLOT_ID              ,
  LOT_ID                 ,
  FACTORY                ,
  MAT_ID                 ,
  MAT_VER                ,
  FLOW                   ,
  FLOW_SEQ_NUM           ,
  OPER                   ,
  SLOT_NO                ,
  QTY_2                  ,
  QTY_3                  ,
  CRR_ID                 ,
  OWNER_CODE             ,
  CREATE_CODE            ,
  SUBLOT_STATUS          ,
  HOLD_FLAG              ,
  HOLD_CODE              ,
  HOLD_PASSWORD          ,
  HOLD_PRV_GRP_ID        ,
  OPER_IN_QTY_2          ,
  OPER_IN_QTY_3          ,
  CREATE_QTY_2           ,
  CREATE_QTY_3           ,
  START_QTY_2            ,
  START_QTY_3            ,
  INV_FLAG               ,
  TRANSIT_FLAG           ,
  UNIT_EXIST_FLAG        ,
  INV_UNIT               ,
  RWK_FLAG               ,
  RWK_CODE               ,
  RWK_COUNT              ,
  RWK_RET_FLOW           ,
  RWK_RET_FLOW_SEQ_NUM   ,
  RWK_RET_OPER           ,
  RWK_END_FLOW           ,
  RWK_END_FLOW_SEQ_NUM   ,
  RWK_END_OPER           ,
  RWK_RET_CLEAR_FLAG     ,
  RWK_TIME               ,
  NSTD_FLAG              ,
  NSTD_RET_FLOW          ,
  NSTD_RET_FLOW_SEQ_NUM  ,
  NSTD_RET_OPER          ,
  NSTD_TIME              ,
  REP_FLAG               ,
  REP_RET_OPER           ,
  STR_RET_FLOW           ,
  STR_RET_FLOW_SEQ_NUM   ,
  STR_RET_OPER           ,
  ' '            ,
  ' '            ,
  ' '           ,
  ' '           ,
  START_FLAG             ,
  START_TIME             ,
  START_RES_ID           ,
  END_FLAG               ,
  END_TIME               ,
  END_RES_ID             ,
  SAMPLE_FLAG            ,
  SAMPLE_WAIT_FLAG       ,
  SAMPLE_RESULT          ,
  RESERVE_RES_ID         ,
  PORT_ID                ,
  SUBLOT_LOCATION_1      ,
  SUBLOT_LOCATION_2      ,
  SUBLOT_LOCATION_3      ,
  SUBRES_ID              ,
  SUBLOT_CMF_1           ,
  SUBLOT_CMF_2           ,
  SUBLOT_CMF_3           ,
  SUBLOT_CMF_4           ,
  SUBLOT_CMF_5           ,
  SUBLOT_CMF_6           ,
  SUBLOT_CMF_7           ,
  SUBLOT_CMF_8           ,
  SUBLOT_CMF_9           ,
  SUBLOT_CMF_10          ,
  SUBLOT_CMF_11          ,
  SUBLOT_CMF_12          ,
  SUBLOT_CMF_13          ,
  SUBLOT_CMF_14          ,
  SUBLOT_CMF_15          ,
  SUBLOT_CMF_16          ,
  SUBLOT_CMF_17          ,
  SUBLOT_CMF_18          ,
  SUBLOT_CMF_19          ,
  SUBLOT_CMF_20          ,
  SUBLOT_DEL_FLAG        ,
  SUBLOT_DEL_CODE        ,
  SUBLOT_DEL_TIME        ,
  GRADE                  ,
  GRADE_CODE             ,
  CELL_GRADE             ,
  LOT_BASE               ,
  LOT_HIST_SEQ           ,
  LAST_TRAN_CODE         ,
  LAST_TRAN_TIME         ,
  LAST_COMMENT           ,
  LAST_ACTIVE_HIST_SEQ   ,
  LAST_HIST_SEQ          
FROM MWIPSLTSTS_OLD);

DROP TABLE MWIPSLTSTS_OLD CASCADE CONSTRAINT PURGE;

ALTER TABLE MWIPSLTSTS
ADD CONSTRAINT MWIPSLTSTS_PK PRIMARY KEY
(
    SUBLOT_ID
) USING INDEX TABLESPACE MESPLUS_IDX_TS;


RENAME MWIPSLTHIS TO MWIPSLTHIS_OLD;

CREATE TABLE MWIPSLTHIS
(
  SUBLOT_ID              VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  HIST_SEQ               NUMBER(10)             DEFAULT (0)                   NOT NULL,
  TRAN_TIME              VARCHAR2(14)           DEFAULT (' ')                 NOT NULL,
  SYS_TRAN_TIME          VARCHAR2(14)           DEFAULT (' ')                 NOT NULL,
  TRAN_CODE              VARCHAR2(12)           DEFAULT (' ')                 NOT NULL,
  LOT_ID                 VARCHAR2(25)           DEFAULT (' ')                 NOT NULL,
  FACTORY                VARCHAR2(10)           DEFAULT (' ')                 NOT NULL,
  MAT_ID                 VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  MAT_VER                NUMBER(6)              DEFAULT (0)                   NOT NULL,
  FLOW                   VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  FLOW_SEQ_NUM           NUMBER(6)              DEFAULT (0)                   NOT NULL,
  OPER                   VARCHAR2(10)           DEFAULT (' ')                 NOT NULL,
  SLOT_NO                NUMBER(6)              DEFAULT (0)                   NOT NULL,
  QTY_2                  NUMBER(10,3)           DEFAULT (0.0)                 NOT NULL,
  QTY_3                  NUMBER(10,3)           DEFAULT (0.0)                 NOT NULL,
  CRR_ID                 VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  OWNER_CODE             VARCHAR2(10)           DEFAULT (' ')                 NOT NULL,
  CREATE_CODE            VARCHAR2(10)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_STATUS          VARCHAR2(10)           DEFAULT (' ')                 NOT NULL,
  HOLD_FLAG              CHAR(1)                DEFAULT (' ')                 NOT NULL,
  HOLD_CODE              VARCHAR2(10)           DEFAULT (' ')                 NOT NULL,
  HOLD_PASSWORD          VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  HOLD_PRV_GRP_ID        VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  OPER_IN_QTY_2          NUMBER(10,3)           DEFAULT (0.0)                 NOT NULL,
  OPER_IN_QTY_3          NUMBER(10,3)           DEFAULT (0.0)                 NOT NULL,
  CREATE_QTY_2           NUMBER(10,3)           DEFAULT (0.0)                 NOT NULL,
  CREATE_QTY_3           NUMBER(10,3)           DEFAULT (0.0)                 NOT NULL,
  START_QTY_2            NUMBER(10,3)           DEFAULT (0.0)                 NOT NULL,
  START_QTY_3            NUMBER(10,3)           DEFAULT (0.0)                 NOT NULL,
  INV_FLAG               CHAR(1)                DEFAULT (' ')                 NOT NULL,
  TRANSIT_FLAG           CHAR(1)                DEFAULT (' ')                 NOT NULL,
  UNIT_EXIST_FLAG        CHAR(1)                DEFAULT (' ')                 NOT NULL,
  INV_UNIT               VARCHAR2(10)           DEFAULT (0.0)                 NOT NULL,
  RWK_FLAG               CHAR(1)                DEFAULT (' ')                 NOT NULL,
  RWK_CODE               VARCHAR2(10)           DEFAULT (' ')                 NOT NULL,
  RWK_COUNT              NUMBER(6)              DEFAULT (0)                   NOT NULL,
  RWK_RET_FLOW           VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  RWK_RET_FLOW_SEQ_NUM   NUMBER(6)              DEFAULT (0)                   NOT NULL,
  RWK_RET_OPER           VARCHAR2(10)           DEFAULT (' ')                 NOT NULL,
  RWK_END_FLOW           VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  RWK_END_FLOW_SEQ_NUM   NUMBER(6)              DEFAULT (0)                   NOT NULL,
  RWK_END_OPER           VARCHAR2(10)           DEFAULT (' ')                 NOT NULL,
  RWK_RET_CLEAR_FLAG     CHAR(1)                DEFAULT (' ')                 NOT NULL,
  RWK_TIME               VARCHAR2(14)           DEFAULT (' ')                 NOT NULL,
  NSTD_FLAG              CHAR(1)                DEFAULT (' ')                 NOT NULL,
  NSTD_RET_FLOW          VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  NSTD_RET_FLOW_SEQ_NUM  NUMBER(6)              DEFAULT (0)                   NOT NULL,
  NSTD_RET_OPER          VARCHAR2(10)           DEFAULT (' ')                 NOT NULL,
  NSTD_TIME              VARCHAR2(14)           DEFAULT (' ')                 NOT NULL,
  REP_FLAG               CHAR(1)                DEFAULT (' ')                 NOT NULL,
  REP_RET_OPER           VARCHAR2(10)           DEFAULT (' ')                 NOT NULL,
  STR_RET_FLOW           VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  STR_RET_FLOW_SEQ_NUM   NUMBER(6)              DEFAULT (0)                   NOT NULL,
  STR_RET_OPER           VARCHAR2(10)           DEFAULT (' ')                 NOT NULL,
  CREATE_TIME            VARCHAR2(14)           DEFAULT (' ')                 NOT NULL,
  FAC_IN_TIME            VARCHAR2(14)           DEFAULT (' ')                 NOT NULL,
  FLOW_IN_TIME           VARCHAR2(14)           DEFAULT (' ')                 NOT NULL,
  OPER_IN_TIME           VARCHAR2(14)           DEFAULT (' ')                 NOT NULL,
  START_FLAG             CHAR(1)                DEFAULT (' ')                 NOT NULL,
  START_TIME             VARCHAR2(14)           DEFAULT (' ')                 NOT NULL,
  START_RES_ID           VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  END_FLAG               CHAR(1)                DEFAULT (' ')                 NOT NULL,
  END_TIME               VARCHAR2(14)           DEFAULT (' ')                 NOT NULL,
  END_RES_ID             VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  SAMPLE_FLAG            CHAR(1)                DEFAULT (' ')                 NOT NULL,
  SAMPLE_WAIT_FLAG       CHAR(1)                DEFAULT (' ')                 NOT NULL,
  SAMPLE_RESULT          CHAR(1)                DEFAULT (' ')                 NOT NULL,
  RESERVE_RES_ID         VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  PORT_ID                VARCHAR2(10)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_LOCATION_1      VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_LOCATION_2      VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_LOCATION_3      VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  SUBRES_ID              VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_1           VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_2           VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_3           VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_4           VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_5           VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_6           VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_7           VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_8           VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_9           VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_10          VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_11          VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_12          VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_13          VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_14          VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_15          VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_16          VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_17          VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_18          VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_19          VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_CMF_20          VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_DEL_FLAG        CHAR(1)                DEFAULT (' ')                 NOT NULL,
  SUBLOT_DEL_CODE        VARCHAR2(10)           DEFAULT (' ')                 NOT NULL,
  SUBLOT_DEL_TIME        VARCHAR2(14)           DEFAULT (' ')                 NOT NULL,
  GRADE                  CHAR(1)                DEFAULT (' ')                 NOT NULL,
  GRADE_CODE             VARCHAR2(10)           DEFAULT (' ')                 NOT NULL,
  CELL_GRADE             VARCHAR2(200)          DEFAULT (' ')                 NOT NULL,
  LOT_BASE               CHAR(1)                DEFAULT (' ')                 NOT NULL,
  LOT_HIST_SEQ           NUMBER(10)             DEFAULT (0)                   NOT NULL,
  OLD_FACTORY            VARCHAR2(10)           DEFAULT (' ')                 NOT NULL,
  OLD_MAT_ID             VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  OLD_MAT_VER            NUMBER(6)              DEFAULT (0)                   NOT NULL,
  OLD_FLOW               VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  OLD_FLOW_SEQ_NUM       NUMBER(6)              DEFAULT (0)                   NOT NULL,
  OLD_OPER               VARCHAR2(10)           DEFAULT (' ')                 NOT NULL,
  OLD_QTY_2              NUMBER(10,3)           DEFAULT (0.0)                 NOT NULL,
  OLD_QTY_3              NUMBER(10,3)           DEFAULT (0.0)                 NOT NULL,
  OLD_CRR_ID             VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  OLD_OWNER_CODE         VARCHAR2(10)           DEFAULT (' ')                 NOT NULL,
  OLD_CREATE_CODE        VARCHAR2(10)           DEFAULT (' ')                 NOT NULL,
  OLD_FAC_IN_TIME        VARCHAR2(14)           DEFAULT (' ')                 NOT NULL,
  OLD_FLOW_IN_TIME       VARCHAR2(14)           DEFAULT (' ')                 NOT NULL,
  OLD_OPER_IN_TIME       VARCHAR2(14)           DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_1             VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_2             VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_3             VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_4             VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_5             VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_6             VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_7             VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_8             VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_9             VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_10            VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_11            VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_12            VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_13            VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_14            VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_15            VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_16            VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_17            VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_18            VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_19            VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  TRAN_CMF_20            VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  TRAN_USER_ID           VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  TRAN_COMMENT           VARCHAR2(400)          DEFAULT (' ')                 NOT NULL,
  PREV_ACTIVE_HIST_SEQ   NUMBER(10)             DEFAULT (0)                   NOT NULL,
  MULTI_TR_KEY           VARCHAR2(30)           DEFAULT (' ')                 NOT NULL,
  MULTI_TR_SEQ           NUMBER(10)             DEFAULT (0)                   NOT NULL,
  EXT_HIST_SEQ           NUMBER(10)             DEFAULT (0)                   NOT NULL,
  HIST_DEL_FLAG          CHAR(1)                DEFAULT (' ')                 NOT NULL,
  HIST_DEL_TIME          VARCHAR2(14)           DEFAULT (' ')                 NOT NULL,
  HIST_DEL_USER_ID       VARCHAR2(20)           DEFAULT (' ')                 NOT NULL,
  HIST_DEL_COMMENT       VARCHAR2(400)          DEFAULT (' ')                 NOT NULL
) TABLESPACE HISTORY_DATA_TS;

 INSERT INTO MWIPSLTHIS VALUE
 (SELECT 
  SUBLOT_ID              ,
  HIST_SEQ               ,
  TRAN_TIME              ,
  SYS_TRAN_TIME          ,
  TRAN_CODE              ,
  LOT_ID                 ,
  FACTORY                ,
  MAT_ID                 ,
  MAT_VER                ,
  FLOW                   ,
  FLOW_SEQ_NUM           ,
  OPER                   ,
  SLOT_NO                ,
  QTY_2                  ,
  QTY_3                  ,
  CRR_ID                 ,
  OWNER_CODE             ,
  CREATE_CODE            ,
  SUBLOT_STATUS          ,
  HOLD_FLAG              ,
  HOLD_CODE              ,
  HOLD_PASSWORD          ,
  HOLD_PRV_GRP_ID        ,
  OPER_IN_QTY_2          ,
  OPER_IN_QTY_3          ,
  CREATE_QTY_2           ,
  CREATE_QTY_3           ,
  START_QTY_2            ,
  START_QTY_3            ,
  INV_FLAG               ,
  TRANSIT_FLAG           ,
  UNIT_EXIST_FLAG        ,
  INV_UNIT               ,
  RWK_FLAG               ,
  RWK_CODE               ,
  RWK_COUNT              ,
  RWK_RET_FLOW           ,
  RWK_RET_FLOW_SEQ_NUM   ,
  RWK_RET_OPER           ,
  RWK_END_FLOW           ,
  RWK_END_FLOW_SEQ_NUM   ,
  RWK_END_OPER           ,
  RWK_RET_CLEAR_FLAG     ,
  RWK_TIME               ,
  NSTD_FLAG              ,
  NSTD_RET_FLOW          ,
  NSTD_RET_FLOW_SEQ_NUM  ,
  NSTD_RET_OPER          ,
  NSTD_TIME              ,
  REP_FLAG               ,
  REP_RET_OPER           ,
  STR_RET_FLOW           ,
  STR_RET_FLOW_SEQ_NUM   ,
  STR_RET_OPER           ,
  ' '            ,
  ' '            ,
  ' '           ,
  ' '           ,
  START_FLAG             ,
  START_TIME             ,
  START_RES_ID           ,
  END_FLAG               ,
  END_TIME               ,
  END_RES_ID             ,
  SAMPLE_FLAG            ,
  SAMPLE_WAIT_FLAG       ,
  SAMPLE_RESULT          ,
  RESERVE_RES_ID         ,
  PORT_ID                ,
  SUBLOT_LOCATION_1      ,
  SUBLOT_LOCATION_2      ,
  SUBLOT_LOCATION_3      ,
  SUBRES_ID              ,
  SUBLOT_CMF_1           ,
  SUBLOT_CMF_2           ,
  SUBLOT_CMF_3           ,
  SUBLOT_CMF_4           ,
  SUBLOT_CMF_5           ,
  SUBLOT_CMF_6           ,
  SUBLOT_CMF_7           ,
  SUBLOT_CMF_8           ,
  SUBLOT_CMF_9           ,
  SUBLOT_CMF_10          ,
  SUBLOT_CMF_11          ,
  SUBLOT_CMF_12          ,
  SUBLOT_CMF_13          ,
  SUBLOT_CMF_14          ,
  SUBLOT_CMF_15          ,
  SUBLOT_CMF_16          ,
  SUBLOT_CMF_17          ,
  SUBLOT_CMF_18          ,
  SUBLOT_CMF_19          ,
  SUBLOT_CMF_20          ,
  SUBLOT_DEL_FLAG        ,
  SUBLOT_DEL_CODE        ,
  SUBLOT_DEL_TIME        ,
  GRADE                  ,
  GRADE_CODE             ,
  CELL_GRADE             ,
  LOT_BASE               ,
  LOT_HIST_SEQ           ,
  OLD_FACTORY            ,
  OLD_MAT_ID             ,
  OLD_MAT_VER            ,
  OLD_FLOW               ,
  OLD_FLOW_SEQ_NUM       ,
  OLD_OPER               ,
  OLD_QTY_2              ,
  OLD_QTY_3              ,
  OLD_CRR_ID             ,
  OLD_OWNER_CODE         ,
  OLD_CREATE_CODE        ,
  ' '            ,
  ' '           ,
  ' '           ,
  TRAN_CMF_1             ,
  TRAN_CMF_2             ,
  TRAN_CMF_3             ,
  TRAN_CMF_4             ,
  TRAN_CMF_5             ,
  TRAN_CMF_6             ,
  TRAN_CMF_7             ,
  TRAN_CMF_8             ,
  TRAN_CMF_9             ,
  TRAN_CMF_10            ,
  TRAN_CMF_11            ,
  TRAN_CMF_12            ,
  TRAN_CMF_13            ,
  TRAN_CMF_14            ,
  TRAN_CMF_15            ,
  TRAN_CMF_16            ,
  TRAN_CMF_17            ,
  TRAN_CMF_18            ,
  TRAN_CMF_19            ,
  TRAN_CMF_20            ,
  TRAN_USER_ID           ,
  TRAN_COMMENT           ,
  PREV_ACTIVE_HIST_SEQ   ,
  MULTI_TR_KEY           ,
  MULTI_TR_SEQ           ,
  EXT_HIST_SEQ           ,
  HIST_DEL_FLAG          ,
  HIST_DEL_TIME          ,
  HIST_DEL_USER_ID       ,
  HIST_DEL_COMMENT       
FROM MWIPSLTHIS_OLD);

DROP TABLE MWIPSLTHIS_OLD  CASCADE CONSTRAINT PURGE;

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
    LOT_BASE
) TABLESPACE HISTORY_IDX_TS;

ALTER TABLE MWIPSLTHIS
ADD CONSTRAINT MWIPSLTHIS_PK PRIMARY KEY
(
    SUBLOT_ID, 
    HIST_SEQ
) USING INDEX TABLESPACE HISTORY_IDX_TS;

RENAME MSVMSVCDEF TO MSVMSVCDEF_OLD;

CREATE TABLE MSVMSVCDEF
(
  MODULE_NAME       VARCHAR2(30 BYTE)           DEFAULT (' ')                 NOT NULL,
  SERVICE_NAME      VARCHAR2(100 BYTE)          DEFAULT (' ')                 NOT NULL,
  SERVICE_MODE      VARCHAR2(2 BYTE)            DEFAULT (' ')                 NOT NULL,
  SERVICE_CATEGORY  CHAR(1 BYTE)                DEFAULT (' ')                 NOT NULL,
  SERVICE_DESC_1    VARCHAR2(1000 BYTE)         DEFAULT (' ')                 NOT NULL,
  SERVICE_DESC_2    VARCHAR2(1000 BYTE)         DEFAULT (' ')                 NOT NULL,
  SERVICE_DESC_3    VARCHAR2(1000 BYTE)         DEFAULT (' ')                 NOT NULL,
  SEC_CHK_FLAG      CHAR(1 BYTE)                DEFAULT (' ')                 NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

 INSERT INTO MSVMSVCDEF VALUE
 (SELECT 
  MODULE_NAME       ,
  SERVICE_NAME      ,
  SERVICE_MODE      ,
  SERVICE_CATEGORY  ,
  SERVICE_DESC_1    ,
  SERVICE_DESC_2    ,
  SERVICE_DESC_3    ,
  ' '      
FROM MSVMSVCDEF_OLD);

DROP TABLE MSVMSVCDEF_OLD  CASCADE CONSTRAINT PURGE;

CREATE UNIQUE INDEX MSVMSVCDEF_PK ON MSVMSVCDEF
(MODULE_NAME, 
 SERVICE_NAME)
TABLESPACE MESPLUS_IDX_TS;


ALTER TABLE MSVMSVCDEF ADD CONSTRAINT MSVMSVCDEF_PK
 PRIMARY KEY
 (
  MODULE_NAME, 
  SERVICE_NAME
  )
    USING INDEX 
    TABLESPACE MESPLUS_IDX_TS;


/*FMB Table Migration*/
CREATE TABLE MFMBRESLOC_OLD
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
    MOTHER_RES_ID               VARCHAR2(20)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

INSERT INTO MFMBRESLOC_OLD (
   FACTORY, RES_ID, RES_TYPE, 
   LAYOUT_ID, SEQ, LOC_X, 
   LOC_Y, LOC_WIDTH, LOC_HEIGHT, 
   TEXT, TEXT_SIZE, TEXT_COLOR, 
   TEXT_STYLE, TAG_TYPE, BACK_COLOR, 
   CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, 
   UPDATE_TIME, NO_MOUSE_EVENT, SIGNAL_FLAG) 
SELECT FACTORY, RES_ID, RES_TYPE, 
   LAYOUT_ID, SEQ, LOC_X, 
   LOC_Y, LOC_WIDTH, LOC_HEIGHT, 
   TEXT, TEXT_SIZE, TEXT_COLOR, 
   TEXT_STYLE, TAG_TYPE, BACK_COLOR, 
   CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, 
   UPDATE_TIME, NO_MOUSE_EVENT, SIGNAL_FLAG
   FROM MFMBRESLOC;
   
   DROP TABLE MFMBRESLOC PURGE;
   
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
    MOTHER_RES_ID               VARCHAR2(20)     DEFAULT(' ')    NOT NULL
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

INSERT INTO MFMBRESLOC (
   FACTORY, RES_ID, RES_TYPE, 
   LAYOUT_ID, SEQ, LOC_X, 
   LOC_Y, LOC_WIDTH, LOC_HEIGHT, 
   TEXT, TEXT_SIZE, TEXT_COLOR, 
   TEXT_STYLE, TAG_TYPE, BACK_COLOR, 
   CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, 
   UPDATE_TIME, NO_MOUSE_EVENT, SIGNAL_FLAG) 
SELECT FACTORY, RES_ID, RES_TYPE, 
   LAYOUT_ID, SEQ, LOC_X, 
   LOC_Y, LOC_WIDTH, LOC_HEIGHT, 
   TEXT, TEXT_SIZE, TEXT_COLOR, 
   TEXT_STYLE, TAG_TYPE, BACK_COLOR, 
   CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, 
   UPDATE_TIME, NO_MOUSE_EVENT, SIGNAL_FLAG
   FROM MFMBRESLOC_OLD;

DROP TABLE MFMBRESLOC_OLD PURGE;


CREATE TABLE MFMBUDRLOC_OLD
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
    MOTHER_RES_ID               VARCHAR2(20)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

INSERT INTO MFMBUDRLOC_OLD (
   FACTORY, GROUP_ID, RES_ID, 
   RES_TYPE, SEQ, LOC_X, 
   LOC_Y, LOC_WIDTH, LOC_HEIGHT, 
   TEXT, TEXT_SIZE, TEXT_COLOR, 
   TEXT_STYLE, TAG_TYPE, BACK_COLOR, 
   CREATE_TIME, UPDATE_TIME, NO_MOUSE_EVENT, 
   SIGNAL_FLAG) 
SELECT FACTORY, GROUP_ID, RES_ID, 
   RES_TYPE, SEQ, LOC_X, 
   LOC_Y, LOC_WIDTH, LOC_HEIGHT, 
   TEXT, TEXT_SIZE, TEXT_COLOR, 
   TEXT_STYLE, TAG_TYPE, BACK_COLOR, 
   CREATE_TIME, UPDATE_TIME, NO_MOUSE_EVENT, 
   SIGNAL_FLAG FROM MFMBUDRLOC;
   
DROP TABLE MFMBUDRLOC PURGE;

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
    MOTHER_RES_ID               VARCHAR2(20)     DEFAULT(' ')    NOT NULL
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


INSERT INTO MFMBUDRLOC (
   FACTORY, GROUP_ID, RES_ID, 
   RES_TYPE, SEQ, LOC_X, 
   LOC_Y, LOC_WIDTH, LOC_HEIGHT, 
   TEXT, TEXT_SIZE, TEXT_COLOR, 
   TEXT_STYLE, TAG_TYPE, BACK_COLOR, 
   CREATE_TIME, UPDATE_TIME, NO_MOUSE_EVENT, 
   SIGNAL_FLAG) 
SELECT FACTORY, GROUP_ID, RES_ID, 
   RES_TYPE, SEQ, LOC_X, 
   LOC_Y, LOC_WIDTH, LOC_HEIGHT, 
   TEXT, TEXT_SIZE, TEXT_COLOR, 
   TEXT_STYLE, TAG_TYPE, BACK_COLOR, 
   CREATE_TIME, UPDATE_TIME, NO_MOUSE_EVENT, 
   SIGNAL_FLAG FROM MFMBUDRLOC_OLD;
   
DROP TABLE MFMBUDRLOC_OLD PURGE;


CREATE TABLE MFMBENVDEF_OLD
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
  BACK_COLOR        NUMBER(8)                   DEFAULT (0)                   NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

INSERT INTO MFMBENVDEF_OLD (
   FACTORY, CREATE_USER_ID, CREATE_TIME, 
   UPDATE_USER_ID, UPDATE_TIME, FONT_FAMILY, 
   RES_WIDTH, RES_HEIGHT, RTG_WIDTH, 
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
   RES_WIDTH, RES_HEIGHT, RTG_WIDTH, 
   RTG_HEIGHT, ELP_WIDTH, ELP_HEIGHT, 
   TRI_WIDTH, TRI_HEIGHT, VER_WIDTH, 
   VER_HEIGHT, HOR_WIDTH, HOR_HEIGHT, 
   PIE1_WIDTH, PIE1_HEIGHT, PIE2_WIDTH, 
   PIE2_HEIGHT, PIE3_WIDTH, PIE3_HEIGHT, 
   PIE4_WIDTH, PIE4_HEIGHT, LAYOUT_WIDTH, 
   LAYOUT_HEIGHT, UDR_WIDTH, UDR_HEIGHT, 
   EVENT_COLOR_FLAG, SIGNAL_FLAG, TEXT_SIZE, 
   TEXT_COLOR, BACK_COLOR FROM MFMBENVDEF;
   
DROP TABLE MFMBENVDEF PURGE;

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
  BACK_COLOR        NUMBER(8)                   DEFAULT (0)                   NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

ALTER TABLE MFMBENVDEF
ADD CONSTRAINT MFMBENVDEF_PK PRIMARY KEY
(
    FACTORY
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

INSERT INTO MFMBENVDEF (
   FACTORY, CREATE_USER_ID, CREATE_TIME, 
   UPDATE_USER_ID, UPDATE_TIME, FONT_FAMILY, 
   RES_WIDTH, RES_HEIGHT, RTG_WIDTH, 
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
   RES_WIDTH, RES_HEIGHT, RTG_WIDTH, 
   RTG_HEIGHT, ELP_WIDTH, ELP_HEIGHT, 
   TRI_WIDTH, TRI_HEIGHT, VER_WIDTH, 
   VER_HEIGHT, HOR_WIDTH, HOR_HEIGHT, 
   PIE1_WIDTH, PIE1_HEIGHT, PIE2_WIDTH, 
   PIE2_HEIGHT, PIE3_WIDTH, PIE3_HEIGHT, 
   PIE4_WIDTH, PIE4_HEIGHT, LAYOUT_WIDTH, 
   LAYOUT_HEIGHT, UDR_WIDTH, UDR_HEIGHT, 
   EVENT_COLOR_FLAG, SIGNAL_FLAG, TEXT_SIZE, 
   TEXT_COLOR, BACK_COLOR FROM MFMBENVDEF_OLD;
   
DROP TABLE MFMBENVDEF_OLD PURGE;

CREATE TABLE MFMBRESIMG_OLD
(
    FACTORY                     VARCHAR2(10)     DEFAULT(' ')    NOT NULL,
    RES_ID                      VARCHAR2(30)     DEFAULT (' ')   NOT NULL,
	  RES_TYPE                    VARCHAR2(10)     DEFAULT (' ')   NOT NULL,
	  SUBRES_ID                   VARCHAR2(20)     DEFAULT (' ')   NOT NULL,
    IMAGE_IDX                   NUMBER(3)        DEFAULT(0)      NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

INSERT INTO MFMBRESIMG_OLD (
   FACTORY, RES_ID, IMAGE_IDX) 
SELECT FACTORY, RES_ID, IMAGE_IDX 
FROM MFMBRESIMG;

DROP TABLE MFMBRESIMG PURGE;

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

INSERT INTO MFMBRESIMG (
   FACTORY, RES_ID, RES_TYPE,  IMAGE_IDX) 
SELECT FACTORY, RES_ID, 'RES', IMAGE_IDX 
FROM MFMBRESIMG_OLD;

DROP TABLE MFMBRESIMG_OLD PURGE;    

/*Change FMB Library Name FMBClientCore->FMBCore */
DELETE from MSECFUNDEF where FUNC_NAME like 'FMB%';

Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB0001', 'Setup', 'M', 'FMB', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080506100938', 'ADMIN', '20080506100938');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB0002', 'Transaction', 'M', 'FMB', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080506100942', 'ADMIN', '20080506100942');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB0003', 'Inquiry', 'M', 'FMB', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080506100948', 'ADMIN', '20080506100948');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB0004', 'Design', 'M', 'FMB', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080506100953', 'ADMIN', '20080506100953');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB0005', 'Format', 'M', 'FMB', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080506100956', 'ADMIN', '20080506100956');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB0006', 'Utilities', 'M', 'FMB', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', ' ', '20080506141811', 'ADMIN', '20080506141811');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB0007', 'View', 'M', 'FMB', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', ' ', 'ADMIN', '20080506141818', ' ', ' ');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB1001', 'Global Option Setup', 'F', 'SETUP', 'Miracom.FMBCore.dll', 'Miracom.FMBCore.frmFMBSetupGlobalOption', ' ', 241, 'btnView', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.17.html', ' ', '20080506100121', 'ADMIN', '20081204150155');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB1002', 'Resource Image Setup', 'F', 'SETUP', 'Miracom.FMBCore.dll', 'Miracom.FMBCore.frmFMBSetupSubResourceImage', ' ', 242, 'btnAdd', 'btnDel', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.18.html', ' ', '20080506100136', 'ADMIN', '20081204175405');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB2001', 'Event', 'F', 'TRAN', 'Miracom.RASCore.dll', 'Miracom.RASCore.frmRASTranEvent', ' ', -1, 'btnOK', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.20.html', ' ', '20080506105022', 'ADMIN', '20080506105022');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB3001', 'View Resource Status', 'F', 'INQUIRY', 'Miracom.FMBCore.dll', 'Miracom.FMBCore.frmFMBViewResourceStatus', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.22.html', ' ', '20080506100823', 'ADMIN', '20081204150225');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB3002', 'View Resource History', 'F', 'INQUIRY', 'Miracom.FMBCore.dll', 'Miracom.FMBCore.frmFMBViewResourceHistory', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.23.html', ' ', '20080506100826', 'ADMIN', '20081204150232');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB3003', 'View Resource List Detail', 'F', 'INQUIRY', 'Miracom.FMBCore.dll', 'Miracom.FMBCore.frmFMBViewResourceListDetail', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.24.html', ' ', '20080506100829', 'ADMIN', '20081204150244');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB3004', 'View Lot List Detail', 'F', 'INQUIRY', 'Miracom.FMBCore.dll', 'Miracom.FMBCore.frmFMBViewLotListDetail', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.25.html', ' ', '20080506100833', 'ADMIN', '20081204150252');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB3005', 'View Lot List by Resource', 'F', 'INQUIRY', 'Miracom.FMBCore.dll', 'Miracom.FMBCore.frmFMBViewLotListByResource', ' ', -1, 'btnView', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.26.html', ' ', '20080506100837', 'ADMIN', '20081204150301');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB4001', 'New LayOut', 'F', 'FMB', 'Miracom.FMBCore.dll', 'Miracom.FMBCore.frmFMBCreateLayOut', ' ', 243, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.28.html', ' ', '20080506100814', 'ADMIN', '20081204150309');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB4002', 'New User Design', 'F', 'FMB', 'Miracom.FMBCore.dll', 'Miracom.FMBCore.frmFMBCreateUDRGroup', ' ', 244, 'btnCreate', 'btnDelete', 'btnUpdate', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.29.html', ' ', '20080506100817', 'ADMIN', '20081204150316');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB4003', 'Design Update Function', 'F', 'FMB', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.30.html', ' ', '20051102115455', 'ADMIN', '20051102115455');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB5001', 'Format', 'F', 'FMB', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.36.html', ' ', '20051102115509', 'ADMIN', '20051102115509');
Insert into MSECFUNDEF
   (FUNC_NAME, FUNC_DESC, FUNC_TYPE_FLAG, FUNC_GROUP, ASSEMBLY_FILE, ASSEMBLY_NAME, SHORT_CUT, ICON_INDEX, CTL_NAME_1, CTL_NAME_2, CTL_NAME_3, CTL_NAME_4, CTL_NAME_5, CTL_NAME_6, CTL_NAME_7, CTL_NAME_8, CTL_NAME_9, CTL_NAME_10, TAB_NAME_1, TAB_NAME_2, TAB_NAME_3, TAB_NAME_4, TAB_NAME_5, TAB_NAME_6, TAB_NAME_7, TAB_NAME_8, TAB_NAME_9, TAB_NAME_10, OPT_NAME_1, OPT_NAME_2, OPT_NAME_3, OPT_NAME_4, OPT_NAME_5, OPT_NAME_6, OPT_NAME_7, OPT_NAME_8, OPT_NAME_9, OPT_NAME_10, FLD_EN_MASK_USE_FLAG, HELP_URL, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB6001', 'Utilities Send Message', 'F', 'FMB', ' ', ' ', ' ', -1, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'FMB_UserManual.1.42.html', ' ', '20051102115522', 'ADMIN', '20051102115522');


RENAME MSVMMBRDEF TO MSVMMBRDEF_OLD;

CREATE TABLE MSVMMBRDEF
(
  MEMBER_NAME                   VARCHAR2(50)     DEFAULT (' ')    NOT NULL,
  MEMBER_DESC_1                 VARCHAR2(1000)   DEFAULT (' ')    NOT NULL,
  MEMBER_DESC_2                 VARCHAR2(1000)   DEFAULT (' ')    NOT NULL,
  MEMBER_DESC_3                 VARCHAR2(1000)   DEFAULT (' ')    NOT NULL,
  MEMBER_TYPE                   VARCHAR2(10)     DEFAULT (' ')    NOT NULL,
  MEMBER_SIZE                   NUMBER(6)        DEFAULT (0)      NOT NULL,
  USE_RANGE_FLAG                CHAR(1)          DEFAULT (' ')    NOT NULL,
  RANGE_MIN                     NUMBER(22,4)     DEFAULT (0)      NOT NULL,
  RANGE_MAX                     NUMBER(22,4)     DEFAULT (0)      NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

INSERT INTO MSVMMBRDEF VALUE (
SELECT 
	MEMBER_NAME    ,
	MEMBER_DESC_1  ,
	MEMBER_DESC_2  ,
	MEMBER_DESC_3  ,
	MEMBER_TYPE    ,
	MEMBER_SIZE    ,
	USE_RANGE_FLAG ,
	RANGE_MIN      ,
	RANGE_MAX      ,
	'ADMIN',
	'20081201010101',
	' ',
	' '
FROM MSVMMBRDEF_OLD
);

DROP TABLE MSVMMBRDEF_OLD CASCADE CONSTRAINT PURGE;

ALTER TABLE MSVMMBRDEF 
ADD CONSTRAINT MSVMMBRDEF_PK PRIMARY KEY
(
  MEMBER_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;



RENAME MSVMSVCDEF TO MSVMSVCDEF_OLD;

CREATE TABLE MSVMSVCDEF
(
  MODULE_NAME                  VARCHAR2(30)      DEFAULT (' ')    NOT NULL,
  SERVICE_NAME                 VARCHAR2(100)     DEFAULT (' ')    NOT NULL,
  SERVICE_MODE                 VARCHAR2(2)       DEFAULT (' ')    NOT NULL,
  SERVICE_CATEGORY             CHAR(1)           DEFAULT (' ')    NOT NULL,
  SERVICE_DESC_1               VARCHAR2(1000)    DEFAULT (' ')    NOT NULL,
  SERVICE_DESC_2               VARCHAR2(1000)    DEFAULT (' ')    NOT NULL,
  SERVICE_DESC_3               VARCHAR2(1000)    DEFAULT (' ')    NOT NULL,
  SEC_CHK_FLAG                 CHAR(1)           DEFAULT (' ')    NOT NULL,
    CREATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    CREATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL,
    UPDATE_USER_ID              VARCHAR2(20)     DEFAULT(' ')    NOT NULL,
    UPDATE_TIME                 VARCHAR2(14)     DEFAULT(' ')    NOT NULL
) TABLESPACE MESPLUS_DATA_TS;

INSERT INTO MSVMSVCDEF VALUE (
SELECT 
	MODULE_NAME        ,
	SERVICE_NAME       ,
	SERVICE_MODE       ,
	SERVICE_CATEGORY   ,
	SERVICE_DESC_1     ,
	SERVICE_DESC_2     ,
	SERVICE_DESC_3     ,
	SEC_CHK_FLAG       ,
	'ADMIN',
	'20081201010101',
	' ',
	' '
FROM MSVMSVCDEF_OLD
);

DROP TABLE MSVMSVCDEF_OLD CASCADE CONSTRAINT PURGE;

ALTER TABLE MSVMSVCDEF 
ADD CONSTRAINT MSVMSVCDEF_PK PRIMARY KEY
(
  MODULE_NAME, 
  SERVICE_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;




RENAME MSVMSVCMBR TO MSVMSVCMBR_OLD;

CREATE TABLE MSVMSVCMBR
(
  MODULE_NAME                  VARCHAR2(30)      DEFAULT (' ')    NOT NULL,
  SERVICE_NAME                 VARCHAR2(100)     DEFAULT (' ')    NOT NULL,
  DIRECTION                    CHAR(1)           DEFAULT (' ')    NOT NULL,
  MEMBER_DEPTH                 NUMBER(6)         DEFAULT (0)      NOT NULL,
  MEMBER_NAME                  VARCHAR2(50)      DEFAULT (' ')    NOT NULL,
  MEMBER_SEQ                   NUMBER(6)         DEFAULT (0)      NOT NULL,
  MEMBER_DESC_1                VARCHAR2(1000)    DEFAULT (' ')    NOT NULL,
  MEMBER_DESC_2                VARCHAR2(1000)    DEFAULT (' ')    NOT NULL,
  MEMBER_DESC_3                VARCHAR2(1000)    DEFAULT (' ')    NOT NULL,
  MEMBER_TYPE                  VARCHAR2(10)      DEFAULT (' ')    NOT NULL,
  MEMBER_SIZE                  NUMBER(6)         DEFAULT (0)      NOT NULL,
  MEMBER_PRT                   VARCHAR2(50)      DEFAULT (' ')    NOT NULL,
  REQ_MEMBER_FLAG              CHAR(1)           DEFAULT (' ')    NOT NULL,
  PARENT_MEMBER_NAME           VARCHAR2(50)      DEFAULT (' ')    NOT NULL,
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

INSERT INTO MSVMSVCMBR VALUE (
SELECT 
	MODULE_NAME           ,
	SERVICE_NAME          ,
	DIRECTION             ,
	MEMBER_DEPTH          ,
	MEMBER_NAME           ,
	MEMBER_SEQ            ,
	MEMBER_DESC_1         ,
	MEMBER_DESC_2         ,
	MEMBER_DESC_3         ,
	MEMBER_TYPE           ,
	MEMBER_SIZE           ,
	MEMBER_PRT            ,
	REQ_MEMBER_FLAG       ,
	PARENT_MEMBER_NAME    ,
	OVERRIDE_FLAG         ,
	USE_RANGE_FLAG        ,
	RANGE_MIN             ,
	RANGE_MAX             ,
	'ADMIN',
	'20081201010101',
	' ',
	' '
FROM MSVMSVCMBR_OLD
);

DROP TABLE MSVMSVCMBR_OLD CASCADE CONSTRAINT PURGE;

ALTER TABLE MSVMSVCMBR 
ADD CONSTRAINT MSVMSVCMBR_PK PRIMARY KEY
(
  MODULE_NAME, 
  SERVICE_NAME, 
  DIRECTION, 
  MEMBER_DEPTH, 
  MEMBER_NAME,
  PARENT_MEMBER_NAME
) USING INDEX TABLESPACE MESPLUS_IDX_TS;

/*PRV Item will be assigned multiple PRV Group
CREATE TABLE MSECPRVDEF_OLD
(
  FACTORY         VARCHAR2(10 BYTE)             DEFAULT (' ')                 NOT NULL,
  PRV_TYPE        VARCHAR2(20 BYTE)             DEFAULT (' ')                 NOT NULL,
  PRV_ITEM1       VARCHAR2(50 BYTE)             DEFAULT (' ')                 NOT NULL,
  PRV_ITEM2       VARCHAR2(50 BYTE)             DEFAULT (' ')                 NOT NULL,
  PRV_ITEM3       VARCHAR2(50 BYTE)             DEFAULT (' ')                 NOT NULL,
  PRV_GRP_ID      VARCHAR2(20 BYTE)             DEFAULT (' ')                 NOT NULL,
  CREATE_USER_ID  VARCHAR2(20 BYTE)             DEFAULT (' ')                 NOT NULL,
  CREATE_TIME     VARCHAR2(14 BYTE)             DEFAULT (' ')                 NOT NULL,
  UPDATE_USER_ID  VARCHAR2(20 BYTE)             DEFAULT (' ')                 NOT NULL,
  UPDATE_TIME     VARCHAR2(14 BYTE)             DEFAULT (' ')  
) TABLESPACE MESPLUS_DATA_TS;

INSERT INTO MSECPRVDEF_OLD (
   FACTORY,
  PRV_TYPE,
  PRV_ITEM1,
  PRV_ITEM2,
  PRV_ITEM3,
  PRV_GRP_ID,
  CREATE_USER_ID,
  CREATE_TIME,
  UPDATE_USER_ID,
  UPDATE_TIME)
SELECT  FACTORY,
        PRV_TYPE,
        PRV_ITEM1,
        PRV_ITEM2,
        PRV_ITEM3,
        PRV_GRP_ID,
        CREATE_USER_ID,
        CREATE_TIME,
        UPDATE_USER_ID,
        UPDATE_TIME
FROM MSECPRVDEF;

DROP TABLE MSECPRVDEF PURGE;

CREATE TABLE MSECPRVDEF
(
  FACTORY         VARCHAR2(10 BYTE)             DEFAULT (' ')                 NOT NULL,
  PRV_TYPE        VARCHAR2(20 BYTE)             DEFAULT (' ')                 NOT NULL,
  PRV_ITEM1       VARCHAR2(50 BYTE)             DEFAULT (' ')                 NOT NULL,
  PRV_ITEM2       VARCHAR2(50 BYTE)             DEFAULT (' ')                 NOT NULL,
  PRV_ITEM3       VARCHAR2(50 BYTE)             DEFAULT (' ')                 NOT NULL,
  PRV_GRP_ID      VARCHAR2(20 BYTE)             DEFAULT (' ')                 NOT NULL,
  CREATE_USER_ID  VARCHAR2(20 BYTE)             DEFAULT (' ')                 NOT NULL,
  CREATE_TIME     VARCHAR2(14 BYTE)             DEFAULT (' ')                 NOT NULL,
  UPDATE_USER_ID  VARCHAR2(20 BYTE)             DEFAULT (' ')                 NOT NULL,
  UPDATE_TIME     VARCHAR2(14 BYTE)             DEFAULT (' ')  
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

INSERT INTO MSECPRVDEF (
        FACTORY,
        PRV_TYPE,
        PRV_ITEM1,
        PRV_ITEM2,
        PRV_ITEM3,
        PRV_GRP_ID,
        CREATE_USER_ID,
        CREATE_TIME,
        UPDATE_USER_ID,
        UPDATE_TIME) 
SELECT  FACTORY,
        PRV_TYPE,
        PRV_ITEM1,
        PRV_ITEM2,
        PRV_ITEM3,
        PRV_GRP_ID,
        CREATE_USER_ID,
        CREATE_TIME,
        UPDATE_USER_ID,
        UPDATE_TIME 
FROM MSECPRVDEF_OLD;

DROP TABLE MSECPRVDEF_OLD PURGE;    

/*RTD - Default Service version setup CMF*/
Insert into MWIPFACCMF
   (FACTORY, ITEM_NAME, PRT_1, PRT_2, PRT_3, PRT_4, PRT_5, PRT_6, PRT_7, PRT_8, PRT_9, PRT_10, PRT_11, PRT_12, PRT_13, PRT_14, PRT_15, PRT_16, PRT_17, PRT_18, PRT_19, PRT_20, FMT_1, FMT_2, FMT_3, FMT_4, FMT_5, FMT_6, FMT_7, FMT_8, FMT_9, FMT_10, FMT_11, FMT_12, FMT_13, FMT_14, FMT_15, FMT_16, FMT_17, FMT_18, FMT_19, FMT_20, OPT_1, OPT_2, OPT_3, OPT_4, OPT_5, OPT_6, OPT_7, OPT_8, OPT_9, OPT_10, OPT_11, OPT_12, OPT_13, OPT_14, OPT_15, OPT_16, OPT_17, OPT_18, OPT_19, OPT_20, TBL_1, TBL_2, TBL_3, TBL_4, TBL_5, TBL_6, TBL_7, TBL_8, TBL_9, TBL_10, TBL_11, TBL_12, TBL_13, TBL_14, TBL_15, TBL_16, TBL_17, TBL_18, TBL_19, TBL_20, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'FKT-RTD', 'Return Type', 'Rule Type', 'Value Count', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'A', 'A', 'N', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'Y', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RTD_RULE_TYPE', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20080806165037', 'ADMIN', '20081107174526');

Insert into MGCMTBLDEF
   (FACTORY, TABLE_NAME, TABLE_DESC, SYS_TBL_FLAG, CENTRAL_FLAG, TABLE_TYPE, USE_SQL_FLAG, TABLE_GROUP, KEY_1_PRT, KEY_1_FMT, KEY_1_SIZE, KEY_2_PRT, KEY_2_FMT, KEY_2_SIZE, KEY_3_PRT, KEY_3_FMT, KEY_3_SIZE, KEY_4_PRT, KEY_4_FMT, KEY_4_SIZE, KEY_5_PRT, KEY_5_FMT, KEY_5_SIZE, KEY_6_PRT, KEY_6_FMT, KEY_6_SIZE, KEY_7_PRT, KEY_7_FMT, KEY_7_SIZE, KEY_8_PRT, KEY_8_FMT, KEY_8_SIZE, KEY_9_PRT, KEY_9_FMT, KEY_9_SIZE, KEY_10_PRT, KEY_10_FMT, KEY_10_SIZE, DATA_1_PRT, DATA_1_FMT, DATA_1_SIZE, DATA_2_PRT, DATA_2_FMT, DATA_2_SIZE, DATA_3_PRT, DATA_3_FMT, DATA_3_SIZE, DATA_4_PRT, DATA_4_FMT, DATA_4_SIZE, DATA_5_PRT, DATA_5_FMT, DATA_5_SIZE, DATA_6_PRT, DATA_6_FMT, DATA_6_SIZE, DATA_7_PRT, DATA_7_FMT, DATA_7_SIZE, DATA_8_PRT, DATA_8_FMT, DATA_8_SIZE, DATA_9_PRT, DATA_9_FMT, DATA_9_SIZE, DATA_10_PRT, DATA_10_FMT, DATA_10_SIZE, SQL_1, SQL_2, SQL_3, SQL_4, SQL_5, TABLE_PASSWORD, SEC_CHK_FLAG, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'RTD_RULE_TYPE', 'RTD Rule Type', ' ', ' ', ' ', ' ', 'SYSTEM', 'RULE_TYPE', 'A', 1, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, 'DESCRIPTION', 'A', 50, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20080619085133', ' ', ' ');

Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'RTD_RULE_TYPE', 'L', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Lot Type', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20080619085206', ' ', ' ');

Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SYSTEM', 'RTD_RULE_TYPE', 'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Resource Type', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20080619085206', ' ', ' ');

delete from MWIPFACCMF where factory = 'FABBLW' and item_name = 'FKT-RTD';
Insert into MWIPFACCMF
   (FACTORY, ITEM_NAME, PRT_1, PRT_2, PRT_3, PRT_4, PRT_5, PRT_6, PRT_7, PRT_8, PRT_9, PRT_10, PRT_11, PRT_12, PRT_13, PRT_14, PRT_15, PRT_16, PRT_17, PRT_18, PRT_19, PRT_20, FMT_1, FMT_2, FMT_3, FMT_4, FMT_5, FMT_6, FMT_7, FMT_8, FMT_9, FMT_10, FMT_11, FMT_12, FMT_13, FMT_14, FMT_15, FMT_16, FMT_17, FMT_18, FMT_19, FMT_20, OPT_1, OPT_2, OPT_3, OPT_4, OPT_5, OPT_6, OPT_7, OPT_8, OPT_9, OPT_10, OPT_11, OPT_12, OPT_13, OPT_14, OPT_15, OPT_16, OPT_17, OPT_18, OPT_19, OPT_20, TBL_1, TBL_2, TBL_3, TBL_4, TBL_5, TBL_6, TBL_7, TBL_8, TBL_9, TBL_10, TBL_11, TBL_12, TBL_13, TBL_14, TBL_15, TBL_16, TBL_17, TBL_18, TBL_19, TBL_20, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FABBLW', 'FKT-RTD', 'Return Type', 'Rule Type', 'Value Count', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'A', 'A', 'N', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Y', 'Y', 'Y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'RTD_RULE_TYPE', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20080806165037', 'ADMIN', '20081107174526');

Insert into MGCMTBLDEF
   (FACTORY, TABLE_NAME, TABLE_DESC, SYS_TBL_FLAG, CENTRAL_FLAG, TABLE_TYPE, USE_SQL_FLAG, TABLE_GROUP, KEY_1_PRT, KEY_1_FMT, KEY_1_SIZE, KEY_2_PRT, KEY_2_FMT, KEY_2_SIZE, KEY_3_PRT, KEY_3_FMT, KEY_3_SIZE, KEY_4_PRT, KEY_4_FMT, KEY_4_SIZE, KEY_5_PRT, KEY_5_FMT, KEY_5_SIZE, KEY_6_PRT, KEY_6_FMT, KEY_6_SIZE, KEY_7_PRT, KEY_7_FMT, KEY_7_SIZE, KEY_8_PRT, KEY_8_FMT, KEY_8_SIZE, KEY_9_PRT, KEY_9_FMT, KEY_9_SIZE, KEY_10_PRT, KEY_10_FMT, KEY_10_SIZE, DATA_1_PRT, DATA_1_FMT, DATA_1_SIZE, DATA_2_PRT, DATA_2_FMT, DATA_2_SIZE, DATA_3_PRT, DATA_3_FMT, DATA_3_SIZE, DATA_4_PRT, DATA_4_FMT, DATA_4_SIZE, DATA_5_PRT, DATA_5_FMT, DATA_5_SIZE, DATA_6_PRT, DATA_6_FMT, DATA_6_SIZE, DATA_7_PRT, DATA_7_FMT, DATA_7_SIZE, DATA_8_PRT, DATA_8_FMT, DATA_8_SIZE, DATA_9_PRT, DATA_9_FMT, DATA_9_SIZE, DATA_10_PRT, DATA_10_FMT, DATA_10_SIZE, SQL_1, SQL_2, SQL_3, SQL_4, SQL_5, TABLE_PASSWORD, SEC_CHK_FLAG, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FABBLW', 'RTD_RULE_TYPE', 'RTD Rule Type', ' ', ' ', ' ', ' ', 'SYSTEM', 'RULE_TYPE', 'A', 1, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, 'DESCRIPTION', 'A', 50, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', 0, ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20080619085133', ' ', ' ');

Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FABBLW', 'RTD_RULE_TYPE', 'L', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Lot Type', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20080619085206', ' ', ' ');

Insert into MGCMTBLDAT
   (FACTORY, TABLE_NAME, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_10, DATA_1, DATA_2, DATA_3, DATA_4, DATA_5, DATA_6, DATA_7, DATA_8, DATA_9, DATA_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FABBLW', 'RTD_RULE_TYPE', 'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Resource Type', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'ADMIN', '20080619085206', ' ', ' ');


/* MMSGMSGDEF 추가 */
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0380', 'WIP', 'WIP-0380 : Invaild argument index in Where statement. Check Where statement in [ID Generator Setup] and argument value in this service.', 'WIP-0380 : Where 절에 설정된 인수 Index 값이 존재하지 않습니다. [ID Generator Setup]의 Where 절과 인수를 정확히 입력했는지 확인하십시오.', 'WIP-0380', 'ADMIN', '20081211010549', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('GCM-0022', 'GCM', 'GCM-0022 : This GCM table needs argument of sql query. Please check sql query again.', 'GCM-0022 : 이 GCM 테이블은 SQL 쿼리 인수가 필요합니다. GCM 테이블의 SQL 쿼리를 확인하십시오', 'GCM-0022', 'ADMIN', '20081211014701', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('GCM-0023', 'GCM', 'GCM-0023 : Invaild argument index in Where statement. Check Where statement in [GCM Table Setup] and argument value in this service.', 'GCM-0023 : Where 절에 설정된 인수 Index 값이 존재하지 않습니다. [GCM Table Setup]의 Where 절과 인수를 정확히 입력했는지 확인하십시오.', 'GCM-0023', 'ADMIN', '20081211015053', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('GCM-0024', 'GCM', 'GCM-0024 : Invaild sql statement argument for this GCM table. This GCM table only able''$FACTORY'' argument for sql. Check Where statement in [GCM Table Setup].', 'GCM-0024 : 이 GCM Table의 SQL 쿼리 인수로는 $FACTORY 값만이 유효합니다. [GCM Table Setup]의 Where 절을 확인하십시오.', 'GCM-0024', 'ADMIN', '20081211020029', ' ', ' ');

