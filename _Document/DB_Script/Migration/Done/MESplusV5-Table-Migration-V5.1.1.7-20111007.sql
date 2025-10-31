/*
**
**  File Name    : MESplusV5-Table-Migration.sql
**  Description  : MESplus V5 Release Script
**
**  DB Type      : Oracle
**  DB Version   : Oracle 10g / 11g
**
**  Period       : 2011.08.13 ~ 2011.10.07
**  Release Date : 2011.10.07
**
**  Copyright(C) MIRACOM,INC. All rights reserved.
**
*/

/* Missing error message at previous version. Please ignore unique constraint error */
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0470', 'WIP', 'WIP-0470 : This step does not exist.', 'WIP-0470 : 이 Step은 존재하지 않습니다.', 'WIP-0470 : Dieser Schritt existiert nicht.', 'ADMIN', '20101224150556', 'ADMIN', '20101224160226');

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0471', 'WIP', 'WIP-0471 : This step already exists.', 'WIP-0471 : 이 Step은 이미 존재하고 있습니다.', 'WIP-0471 : Dieser Schritt existiert bereits.', 'ADMIN', '20101224150626', 'ADMIN', '20101224155323');

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0472', 'WIP', 'WIP-0472 : This step is not attached to operation.', 'WIP-0472 : 이 step은 operation 에 속해 있지 않습니다.', 'WIP-0472 : Dieser Schritt gehoert nicht zur Operation.', 'ADMIN', '20101224150828', 'ADMIN', '20101224150929');

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0473', 'WIP', 'WIP-0473 : This step is already attached to operation.', 'WIP-0473 : 이 step은 이미 operation에 속해 있습니다.', 'WIP-0473 : Dieser Schritt ist bereits Teil der Operation.', 'ADMIN', '20101224150919', ' ', ' ');

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0474', 'WIP', 'WIP-0474 : This before step is not attached at operation.', 'WIP-0474 : 이 이전 FLOW는 제품에 속해 있지 않습니다.', 'WIP-0474 : Der vorherige FLOW gehoert nicht zur Operation.', 'ADMIN', '20101224154618', 'ADMIN', '20101224155812');

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0475', 'WIP', 'WIP-0475 : Some operation is using this step. Please detach this step from operation.', 'WIP-0475 : 이 STEP은 OPERATION 에서 사용 중입니다. 먼저 OPERATION 에서 분리 후 지우세요.', 'WIP-0475 : Einige Prozesse benutzen diesen Schritt bereits. Bitte von OPERATION trennen.', 'ADMIN', '20101224160043', ' ', ' ');

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0476', 'WIP', 'WIP-0476 : Before processing this operation to end,  you should execute [End lot for step] for this step. Check Step MFO Relation and the option of this step. [End Required]', 'WIP-0476 :  이 STEP을 END 처리 후 진행할 수 있습니다. 이 STEP의 END_REQ_FLAG 를 확인하시기 바랍니다.', 'WIP-0476 : Bevor dieser Schritt ausgefuehrt wird, muss dieser Step beendet werden [End lot for step]. Bitte ueberpruefen Sie END_REQ_FLAG.', 'ADMIN', '20101229102236', 'ADMIN', '20110105154135');

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0477', 'WIP', 'WIP-0477 : Before processing this operation to end,  you should execute [Start lot for step] for this step. Check Step MFO relation and the option of this step. [Start Required].', 'WIP-0477 :  이 STEP을 START 처리 후 진행할 수 있습니다. 이 STEP의 START_REQ_FLAG 를 확인하시기 바랍니다.', 'WIP-0477 : Bevor dieser Schritt ausgefuehrt wird, muss dieser Step beendet werden [Start lot for step]. Bitte ueberpruefen Sie START_REQ_FLAG.', 'ADMIN', '20101229102628', 'ADMIN', '20110105192219');

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0478', 'WIP', 'WIP-0478 : This step is already processing.', 'WIP-0478 :  이 STEP은 이미 Start 진행 중입니다.', 'WIP-0478 : Dieser Schritt ist bereits im Gange.', 'ADMIN', '20101229112653', 'ADMIN', '20101229113615');

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0479', 'WIP', 'WIP-0479 : This step is already processing to end.', 'WIP-0479 :  이 STEP은 이미 End 처리가 되었습니다.', 'WIP-0479 : Dieser Schritt ist bereits fast beendet.', 'ADMIN', '20101229114533', ' ', ' ');

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0480', 'WIP', 'WIP-0480 : This Step doesn''t have MFO relationship. Please check the definition of MFO - Step relationship.', 'WIP-0480 : 이 Step은 MFO 관계가 정립되어 있지 않습니다. MFO - Step 관계를 확인하시기 바랍니다.', 'WIP-0480 : Bei diesem Step liegt keine Verbindung zum MFO vor. Bitte ueberpruefen Sie die MFO-Step Verbindung.', 'ADMIN', '20110104093438', 'ADMIN', '20110104095537');

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0481', 'WIP', 'WIP-0481 : Before processing this step, you should execute [Start lot for step] for a previous step. Check the option of a previous step. [Serial Proc Flag].', 'WIP-0481 : 이전 Step은 Start 처리 후 진행할 수 있습니다. 이전 Step의 Serial oprtion 을 확인하시기 바랍니다.', 'WIP-0481 : Bevor dieser Schritt ausgefuehrt wird, muss der vorherige Step gestartet werden [Start lot for step]. Bitte ueberpruefen Sie die Serial option des vorherigen Step [Serial Proc Flag].', 'ADMIN', '20110104105551', 'ADMIN', '20110105192250');

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0482', 'WIP', 'WIP-0482 : Before processing this step, you should execute [End lot for step] for a previous step. Check the option of a previous step. [Serial Proc Flag].', 'WIP-0482 : 이전 Step은 End 처리 후 진행할 수 있습니다. 이전 Step의 Serial oprtion 을 확인하시기 바랍니다.', 'WIP-0482 : Bevor dieser Schritt ausgefuehrt wird, muss der vorherige Step beendet werden [End lot for step]. Bitte ueberpruefen Sie die Serial option des vorherigen Step [Serial Proc Flag].', 'ADMIN', '20110104112902', 'ADMIN', '20110105192203');

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP-0483', 'WIP', 'WIP-0483 : Can''t delete step history by lot transaction.', 'WIP-0483 : Lot 트랜잭션으로 생긴 step history는 삭제할 수 없습니다.', 'WIP-0483 : Step History kann nicht durch eine Lot Transaktion geloescht werden.', 'ADMIN', '20110105192100', 'ADMIN', '20110110112837');
 
Insert into MMSGMSGDEF (MSG_ID,MSG_GRP,MSG_1,MSG_2,MSG_3,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME) 
 values 
   ('WIP-0484','WIP','WIP-0484 : No allow change flow on STORE status.','WIP-0484 : STORE 상태에서는 FLOW의 변경이 허용되지 않습니다.','WIP-0484 : Flow Change ist im STORE Zustand nicht erlaubt. ','ADMIN','20110113151912',' ',' ');

Insert into MMSGMSGDEF (MSG_ID,MSG_GRP,MSG_1,MSG_2,MSG_3,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME) 
 values 
   ('WIP-0485','WIP','WIP-0485 : No allow change operation on STORE and REPAIR status.','WIP-0485 : STORE, REPAIR 상태에서는 공정의 변경이 허용되지 않습니다.','WIP-0485 : Operation Change ist im STORE, REPAIR Zustand nicht erlaubt.','ADMIN','20110113152027',' ',' ');

Insert into MMSGMSGDEF (MSG_ID,MSG_GRP,MSG_1,MSG_2,MSG_3,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME)
 values 
   ('WIP-0486','WIP','WIP-0486 : It different execution Point with current action and dependent action. Dependent action must same execution Point with current action.', 'WIP-0486 : 현재 Action 과 Dependent Action 의 실행 Point 가 다릅니다. Depenent Action 과 현재 Action 은 반드시 동일한 실행 Point 에 있어야 합니다.','WIP-0486 : Der Execution Point der aktuelllen Action und des Dependent Action ist nicht gleich, was unbedingt notwendig ist.','ADMIN','20110209230558',' ',' ');

Insert into MMSGMSGDEF (MSG_ID,MSG_GRP,MSG_1,MSG_2,MSG_3,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME)
 values 
   ('WIP-0487','WIP','WIP-0487 : This action does not exist.', 'WIP-0487 : 이 Action 은 존재하지 않습니다.','WIP-0487 : Diese Aktion existiert nicht.','ADMIN','20110209231011',' ',' ');

Insert into MMSGMSGDEF (MSG_ID,MSG_GRP,MSG_1,MSG_2,MSG_3,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME)
 values 
   ('WIP-0488','WIP','WIP-0488 : No allow set same Action with current action and dependent action.', 'WIP-0488 : 현재 Action 과 설정한 Depenent Action 은 같을 수 없습니다.','WIP-0488 : Aktuelle und auszuwaehlende Depenent Action duerfen nicht gleich sein.','ADMIN','20110209231305',' ',' ');

Insert into MMSGMSGDEF (MSG_ID,MSG_GRP,MSG_1,MSG_2,MSG_3,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME)
 values 
   ('WIP-0489','WIP','WIP-0489 : It just allow "Just Positive Condition" for Action Type, Because selected Point already have another Actions.', 'WIP-0489 : 선택된 Point 에 이미 다른 Action 이 설정되어 있어 ActionType 은 JustPositiveCondition 만 가능합니다.','WIP-0489 : Nur Action type "Just Positive Condition" moeglich, da der ausgesuchte Point bereits eine andere Action besitzt.','ADMIN','20110209232636',' ',' ');

Insert into MMSGMSGDEF (MSG_ID,MSG_GRP,MSG_1,MSG_2,MSG_3,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME) 
 values 
   ('WIP-0490','WIP','WIP-0490 : It just allow "Just Positive Condition" for Action Type, When each actions set in same Point.', 'WIP-0490 : 동일한 Point 에 여러 Action 이 설정된 경우, Action Type 은 Just Positive Condition 만 허용됩니다.','WIP-0490 : Nur Action type "Just Positive Condition" moeglich, wenn der selbe Point mehrere Action besitzt.','ADMIN','20110209232828','ADMIN','20110209233121');

Insert into MMSGMSGDEF (MSG_ID,MSG_GRP,MSG_1,MSG_2,MSG_3,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME)
 values 
   ('WIP-0491','WIP','WIP-0491 : Inputted operation input data of condition does not exist.','WIP-0491 : 입력된 조건의 공정 입력 데이터가 존재하지 않습니다.','WIP-0491 : Prozessdaten der eingegebenen Bedingungen existieren nicht.','ADMIN','20110215152326',' ',' ');

Insert into MMSGMSGDEF (MSG_ID,MSG_GRP,MSG_1,MSG_2,MSG_3,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME) 
 values 
   ('WIP-0492','WIP','WIP-0492 : Inputted operation input data of condition already exists.','WIP-0492 : 입력된 조건의 공정 데이터가 이미 존재합니다.','WIP-0492 : Prozessdaten der eingegebenen Bedingungen sind bereits verfuegbar.','ADMIN','20110215152349','ADMIN','20110215152402');
/* End */

/* Add by J.S. 2011.10.07 */
Insert into MSVMSVCDEF
   (SERVICE_NAME, MODULE_NAME, SERVICE_MODE, SERVICE_CATEGORY, SERVICE_TYPE, SERVICE_DESC_1, SERVICE_DESC_2, SERVICE_DESC_3, SEC_CHK_FLAG, LOG_LEVEL, SHARED_LIB_NAME, SERVICE_CMF_1, SERVICE_CMF_2, SERVICE_CMF_3, SERVICE_CMF_4, SERVICE_CMF_5, SERVICE_CMF_6, SERVICE_CMF_7, SERVICE_CMF_8, SERVICE_CMF_9, SERVICE_CMF_10, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP_View_Factory_Cmf_List_Detail', 'WIP', 'RR', 'I', 'G', 
    'Views detail list of the customer  field of factory', ' ', ' ', ' ', ' ', 
    ' ', ' ', ' ', ' ', ' ', 
    ' ', ' ', ' ', ' ', ' ', 
    ' ', 'ADMIN', '20110930144427', 'ADMIN', '20111007093900');

Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_PATH, MEMBER_DEPTH, MEMBER_SEQ, PARENT_MEMBER_PATH, MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_View_Factory_Cmf_List_Detail', 'I', 'PASSPORT', 0, 
    0, ' ', 'PASSPORT', 'Client authentication, always empty', ' ', 
    ' ', 'String', 100, 'PASSPORT', ' ', 
    'O', ' ', ' ', 0, 0, 
    'ADMIN', '20110930144427', 'ADMIN', '20110930160850');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_PATH, MEMBER_DEPTH, MEMBER_SEQ, PARENT_MEMBER_PATH, MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_View_Factory_Cmf_List_Detail', 'I', 'LANGUAGE', 0, 
    1, ' ', 'LANGUAGE', 'The language set to be used (''1'': English, ''2'': 2nd Language, ''3'': 3rd Language). If not specified, ''1'' will be used as default', ' ', 
    ' ', 'Char', 1, 'LANGUAGE', ' ', 
    'O', ' ', ' ', 0, 0, 
    'ADMIN', '20110930144427', 'ADMIN', '20110930160851');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_PATH, MEMBER_DEPTH, MEMBER_SEQ, PARENT_MEMBER_PATH, MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_View_Factory_Cmf_List_Detail', 'I', 'LOGLEVEL', 0, 
    2, ' ', 'LOGLEVEL', 'Level of the log saved in the log file (0 = Save all the logs of Error, Warning, Information, Debug, 1 = Save all the logs of Error, Warning, Information, 2 = Save only the log at Error, Warning, 3 = Save only the log at Error)', ' ', 
    ' ', 'Char', 0, 'LOGLEVEL', ' ', 
    'O', ' ', ' ', 0, 0, 
    'ADMIN', '20110930144427', 'ADMIN', '20110930160851');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_PATH, MEMBER_DEPTH, MEMBER_SEQ, PARENT_MEMBER_PATH, MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_View_Factory_Cmf_List_Detail', 'I', 'FACTORY', 0, 
    3, ' ', 'FACTORY', 'Factory', ' ', 
    ' ', 'String', 10, 'FACTORY', ' ', 
    'M', ' ', ' ', 0, 0, 
    'ADMIN', '20110930144427', 'ADMIN', '20110930160851');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_PATH, MEMBER_DEPTH, MEMBER_SEQ, PARENT_MEMBER_PATH, MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_View_Factory_Cmf_List_Detail', 'I', 'USERID', 0, 
    4, ' ', 'USERID', 'User ID', ' ', 
    ' ', 'String', 20, 'USER_ID', ' ', 
    'O', ' ', ' ', 0, 0, 
    'ADMIN', '20110930144427', 'ADMIN', '20110930160851');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_PATH, MEMBER_DEPTH, MEMBER_SEQ, PARENT_MEMBER_PATH, MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_View_Factory_Cmf_List_Detail', 'I', 'PASSWORD', 0, 
    5, ' ', 'PASSWORD', 'Password', ' ', 
    ' ', 'String', 20, 'PASSWORD', ' ', 
    'O', ' ', ' ', 0, 0, 
    'ADMIN', '20110930144427', 'ADMIN', '20110930160851');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_PATH, MEMBER_DEPTH, MEMBER_SEQ, PARENT_MEMBER_PATH, MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_View_Factory_Cmf_List_Detail', 'I', 'PROCSTEP', 0, 
    6, ' ', 'PROCSTEP', 'Process Step. Option for expansion (''1'': Create, ''2'': Modify)', ' ', 
    ' ', 'Char', 1, 'PROC_STEP', ' ', 
    'M', 'Y', ' ', 0, 0, 
    'ADMIN', '20110930144427', 'ADMIN', '20110930160851');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_PATH, MEMBER_DEPTH, MEMBER_SEQ, PARENT_MEMBER_PATH, MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_View_Factory_Cmf_List_Detail', 'O', 'STATUSVALUE', 0, 
    0, ' ', 'STATUSVALUE', 'Status for the Service request (''0'': Success, ''1'': Fail)', 'Status for the Service request (''0'': Success, ''1'': Fail)', 
    'Status for the Service request (''0'': Success, ''1'': Fail)', 'Char', 0, 'STATUS_VALUE', ' ', 
    'M', ' ', ' ', 0, 0, 
    'ADMIN', '20110930144427', 'ADMIN', '20110930160851');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_PATH, MEMBER_DEPTH, MEMBER_SEQ, PARENT_MEMBER_PATH, MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_View_Factory_Cmf_List_Detail', 'O', 'MSGCODE', 0, 
    1, ' ', 'MSGCODE', 'Message code', 'Message code', 
    'Message code', 'String', 10, 'MSG_CODE', ' ', 
    'M', ' ', ' ', 0, 0, 
    'ADMIN', '20110930144427', 'ADMIN', '20110930160851');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_PATH, MEMBER_DEPTH, MEMBER_SEQ, PARENT_MEMBER_PATH, MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_View_Factory_Cmf_List_Detail', 'O', 'MSG', 0, 
    2, ' ', 'MSG', 'Message for the Message code', ' ', 
    ' ', 'String', 200, 'MSG', ' ', 
    'M', ' ', ' ', 0, 0, 
    'ADMIN', '20110930144427', 'ADMIN', '20110930160851');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_PATH, MEMBER_DEPTH, MEMBER_SEQ, PARENT_MEMBER_PATH, MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_View_Factory_Cmf_List_Detail', 'O', 'MSGCATE', 0, 
    3, ' ', 'MSGCATE', 'Message Category (''S''- Success, ''W'' - Warning, ''E'' - Error)', 'Message Category (''S''- Success, ''W'' - Warning, ''E'' - Error)', 
    'Message Category (''S''- Success, ''W'' - Warning, ''E'' - Error)', 'Char', 0, 'MSG_CATE', ' ', 
    'M', ' ', ' ', 0, 0, 
    'ADMIN', '20110930144427', 'ADMIN', '20110930160851');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_PATH, MEMBER_DEPTH, MEMBER_SEQ, PARENT_MEMBER_PATH, MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_View_Factory_Cmf_List_Detail', 'O', 'FIELDMSG', 0, 
    4, ' ', 'FIELDMSG', 'Detail data for the reason of Message code occurs', 'Detail data for the reason of Message code occurs', 
    'Detail data for the reason of Message code occurs', 'List', 0, 'FIELD_MSG', ' ', 
    'O', ' ', ' ', 0, 0, 
    'ADMIN', '20110930144427', 'ADMIN', '20110930160851');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_PATH, MEMBER_DEPTH, MEMBER_SEQ, PARENT_MEMBER_PATH, MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_View_Factory_Cmf_List_Detail', 'O', 'DBERRMSG', 0, 
    5, ' ', 'DBERRMSG', 'Database error message', 'Database error message', 
    'Database error message', 'String', 200, 'DB_ERR_MSG', ' ', 
    'O', ' ', ' ', 0, 0, 
    'ADMIN', '20110930144427', 'ADMIN', '20110930160851');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_PATH, MEMBER_DEPTH, MEMBER_SEQ, PARENT_MEMBER_PATH, MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_View_Factory_Cmf_List_Detail', 'O', 'ITEM_LIST', 0, 
    6, ' ', 'ITEM_LIST', 'List of CMF Item', ' ', 
    ' ', 'List', 0, ' ', ' ', 
    'O', 'Y', ' ', 0, 0, 
    'ADMIN', '20110930161102', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_PATH, MEMBER_DEPTH, MEMBER_SEQ, PARENT_MEMBER_PATH, MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_View_Factory_Cmf_List_Detail', 'O', 'ITEM_LIST/ITEM_NAME', 1, 
    0, 'ITEM_LIST', 'ITEM_NAME', 'Item Name', ' ', 
    ' ', 'String', 20, ' ', ' ', 
    'O', ' ', ' ', 0, 0, 
    'ADMIN', '20110930161102', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_PATH, MEMBER_DEPTH, MEMBER_SEQ, PARENT_MEMBER_PATH, MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_View_Factory_Cmf_List_Detail', 'O', 'ITEM_LIST/DATA_LIST', 1, 
    1, 'ITEM_LIST', 'DATA_LIST', 'List of CMF DATA', ' ', 
    ' ', 'List', 0, ' ', ' ', 
    'O', 'Y', ' ', 0, 0, 
    'ADMIN', '20110930161102', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_PATH, MEMBER_DEPTH, MEMBER_SEQ, PARENT_MEMBER_PATH, MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_View_Factory_Cmf_List_Detail', 'O', 'ITEM_LIST/DATA_LIST/PROMPT', 2, 
    0, 'ITEM_LIST/DATA_LIST', 'PROMPT', 'The prompt of the item', ' ', 
    ' ', 'String', 20, ' ', ' ', 
    'O', ' ', ' ', 0, 0, 
    'ADMIN', '20110930161154', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_PATH, MEMBER_DEPTH, MEMBER_SEQ, PARENT_MEMBER_PATH, MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_View_Factory_Cmf_List_Detail', 'O', 'ITEM_LIST/DATA_LIST/FORMAT', 2, 
    1, 'ITEM_LIST/DATA_LIST', 'FORMAT', 'The data format of the item (''A'': Ascii, ''N'': Numeric, ''F'': Float)', ' ', 
    ' ', 'Char', 0, ' ', ' ', 
    'O', ' ', ' ', 0, 0, 
    'ADMIN', '20110930161154', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_PATH, MEMBER_DEPTH, MEMBER_SEQ, PARENT_MEMBER_PATH, MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_View_Factory_Cmf_List_Detail', 'O', 'ITEM_LIST/DATA_LIST/OPT', 2, 
    2, 'ITEM_LIST/DATA_LIST', 'OPT', 'Option (''Y'': Valid only in case of setup_flag is ''Y'')', ' ', 
    ' ', 'Char', 1, ' ', ' ', 
    'O', ' ', ' ', 0, 0, 
    'ADMIN', '20110930161154', ' ', ' ');
Insert into MSVMSVCMBR
   (MODULE_NAME, SERVICE_NAME, DIRECTION, MEMBER_PATH, MEMBER_DEPTH, MEMBER_SEQ, PARENT_MEMBER_PATH, MEMBER_NAME, MEMBER_DESC_1, MEMBER_DESC_2, MEMBER_DESC_3, MEMBER_TYPE, MEMBER_SIZE, MEMBER_PRT, ARRAY_TYPE, REQ_MEMBER_FLAG, OVERRIDE_FLAG, USE_RANGE_FLAG, RANGE_MIN, RANGE_MAX, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('WIP', 'WIP_View_Factory_Cmf_List_Detail', 'O', 'ITEM_LIST/DATA_LIST/TABLE_NAME', 2, 
    3, 'ITEM_LIST/DATA_LIST', 'TABLE_NAME', 'GCM Table Name', ' ', 
    ' ', 'String', 20, ' ', ' ', 
    'O', ' ', ' ', 0, 0, 
    'ADMIN', '20110930161154', ' ', ' ');	
/* End */
