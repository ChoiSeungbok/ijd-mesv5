--##### INSERT SYSTEM ERROR MESSAGE ######
--select * from mmsgmsgdef where msg_grp = 'ADM' or msg_grp = 'ARC' order by msg_id

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ADM-0000', 'ADM', 'ADM-0000 : This step does not supported. Please check the step number.', 'ADM-0000 : 지원되지 않는 STEP입니다. 다시 확인 하십시요.', 'ADM-0000 : Dieser Step wird nicht unterstuetzt. Bitte ueberpruefen Sie die Step Nummer.', ' ', ' ', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ADM-0001', 'ADM', 'ADM-0001 : This is required field. Please enter valid value', 'ADM-0001 : 이 항목은 필요한 필드 입니다. 입력 바랍니다.', 'ADM-0001 : Dies ist ein Pflichtfeld. Bitte geben Sie den gueltigen Wert ein.', ' ', ' ', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ADM-0004', 'ADM', 'ADM-0004 : Fatal database error is occured. Please contact admin person.', 'ADM-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.', 'ADM-0004 : Fataler Datenbankfehler. Bitte kontaktieren Sie den Admin.', ' ', ' ', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ADM-0005', 'ADM', 'ADM-0005 : Some problems are occured in reading Disk Filesystem Information.', 'ADM-0005 : 디스크 정보를 얻어오는 과정에서 문제가 발생했습니다. 관리자에게 문의하세요', 'ADM-0005 : Probleme sind im Disk Filesystem aufgetreten. Bitte wenden Sie sich an den Admin.', ' ', ' ', ' ', ' ');

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ARC-0000', 'ARC', 'ARC-0000 : This  process step number is not supported. Please check the process step number.', 'ARC-0000 : 지원되지 않는 STEP입니다. 다시 확인 하십시요.', 'ARC-0000 : Diese Prozess Ablaufnummer wird nicht unterstuetzt. Bitte ueberpruefen sie die Prozess-Ablaufnummer.', 'ADMIN', '20050808151608', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ARC-0001', 'ARC', 'ARC-0001 : A required field is empty. Please enter a valid value.', 'ARC-0001 : 이 항목은 필요한 필드 입니다. 입력 바랍니다.', 'ARC-0001 : Ein erforderliches Eingabefeld ist leer. Bitte geben Sie gueltige Daten ein.', 'ADMIN', '20050808151639', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ARC-0002', 'ARC', 'ARC-0002 : This archive option already exists.', 'ARC-0002 : 이 Archive Option이 이미 존재합니다.', 'ARC-0002 : Diese Archivoption existiert bereits.', 'ADMIN', '20050808151728', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ARC-0003', 'ARC', 'ARC-0003 : This archive option does not exist.', 'ARC-0003 : 이 Archive Option이 존재하지 않습니다.', 'ARC-0003 : Diese Archiveoption existiert nicht.', 'ADMIN', '20050808151751', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ARC-0004', 'ARC', 'ARC-0004 : A fatal database error occurred. Please contact an administrator.', 'ARC-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.', 'ARC-0004 : Ein schwerer Datenbankfehler ist aufgetreten. Bitte kontaktieren Sie einen Administrator.', 'ADMIN', '20050808151852', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ARC-0041', 'ARC', 'ARC-0041 : A fatal database error occurred. Please contact an administrator.', 'ARC-0041 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.', 'ARC-0041 : Ein schwerer Datenbankfehler ist aufgetreten. Bitte kontaktieren Sie einen Administrator.', 'ADMIN', '20050823162340', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ARC-0042', 'ARC', 'ARC-0042 : A fatal database error occurred. Please contact an administrator.', 'ARC-0042 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.', 'ARC-0042 : Ein schwerer Datenbankfehler ist aufgetreten. Bitte kontaktieren Sie einen Administrator.', 'ADMIN', '20050823162346', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ARC-0005', 'ARC', 'ARC-0005 : This archive table already exist.', 'ARC-0005 : 이 Archive Table이 이미 존재합니다.', 'ARC-0005 : Diese Archivtabelle existiert bereits.', 'ADMIN', '20050808151912', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ARC-0006', 'ARC', 'ARC-0006 : This archive table does not exist.', 'ARC-0006 : 이 Archive Table이 존재하지 않습니다.', 'ARC-0006 : Diese Archivetabelle existiert nicht.', 'ADMIN', '20050808152453', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ARC-0007', 'ARC', 'ARC-0007 : The master table of this module already exist.', 'ARC-0007 : 이 모듈의 Master Table이 이미 존재합니다.', 'ARC-0007 : Die Mastertabelle fur dieses Modul existiert bereits.', 'ADMIN', '20050808152517', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ARC-0008', 'ARC', 'ARC-0008 : Archive program could not run.', 'ARC-0008 : Archive Program이 동작되지 않았습니다.', 'ARC-0008 : Das Archivirungsprogramm konnte nicht laufen.', 'ADMIN', '20050808152543', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ARC-0010', 'ARC', 'ARC-0010 : DB is not connected. Please check DB Link Name.', 'ARC-0010 : DB가 연결되지 않았습니다. DB Link 이름을 확인하세요.', 'ARC-0010 : Die Datenbank ist nicht erreichbar. Bitte uberprufen Sie die Einstellungen.', 'ADMIN', '20050823162340', 'ADMIN', '20081217170412');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('ARC-0011', 'ARC', 'ARC-0011 : Archived data does not exist.', 'ARC-0011 : Archive 데이터가 존재하지 않습니다.', 'ARC-0011 : Es sind keine archivierten Daten vorhanden.', 'ADMIN', '20050823162340', 'ADMIN', '20081217170625');
Insert into MMSGMSGDEF 
   (MSG_ID,MSG_GRP,MSG_1,MSG_2,MSG_3,CREATE_USER_ID,CREATE_TIME,UPDATE_USER_ID,UPDATE_TIME)
 Values 
   ('ARC-0012','ARC','ARC-0012 : Archive option setup for the specific module does not exist.','ARC-0012 : 해당 Module에 대한 Archive option setup 정보가 없습니다.','ARC-0012 : Archiv Option Setup fuer das spezielle Modul existiert nicht.','ADMIN','20100502173007',' ',' ');
   

