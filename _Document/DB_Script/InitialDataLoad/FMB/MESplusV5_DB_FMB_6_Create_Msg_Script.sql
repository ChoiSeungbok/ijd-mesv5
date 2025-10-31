--##### INSERT SYSTEM ERROR MESSAGE ######
--select * from mmsgmsgdef where msg_grp = 'FMB' order by msg_id

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB-0000', 'FMB', 'FMB-0000 : This step does not supported. Please check the step number.', 'FMB-0000 : 지원되지 않는 STEP입니다. 다시 확인 하십시요.', 'FMB-0000 : Dieser Schritt wird nicht unterstuetzt. Bitte ueberpruefen Sie die Schritt Nummer.', 'ADMIN', '20050131134550', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB-0001', 'FMB', 'FMB-0001 : This is required field. Please enter valid value.', 'FMB-0001 : 이 항목은 필요한 필드 입니다. 입력 바랍니다.', 'FMB-0001 : Dies ist ein Pflichtfeld. Bitte geben Sie den gueltigen Wert ein.', 'ADMIN', '20050131134837', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB-0002', 'FMB', 'FMB-0002 : The user define resource group is already exist.', 'FMB-0002 : 이 사용자 정의 장비 그룹은 이미 존재 합니다.', 'FMB-0002 : Die benutzerdefinierte Resource Gruppe existiert bereits.', 'ADMIN', '20050131172021', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB-0003', 'FMB', 'FMB-0003 : The user define resource group is not exist.', 'FMB-0003 : 이 사용자 정의 장비 그룹은 존재하지 않습니다.', 'FMB-0003 : Die benutzerdefinierte Resource Gruppe existiert nicht.', 'ADMIN', '20050131172133', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB-0004', 'FMB', 'FMB-0004 : Fatal database error is occured. Please contact admin person.', 'FMB-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.', 'FMB-0004 : Fataler Datenbankfehler ist aufgetreten. Bitte kontaktieren Sie den Admin.', 'ADMIN', '20050131134907', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB-0005', 'FMB', 'FMB-0005 : The resource/tag already has location information.', 'FMB-0005 : 이 장비/태그는 이미 위치 정보를 가지고 있습니다.', 'FMB-0005 : Dieses Equipment/Tag hat bereits Informationen ueber seine Position.', 'ADMIN', '20050201170416', 'ADMIN', '20050429103500');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB-0006', 'FMB', 'FMB-0006 : The resource/tag does not have location information.', 'FMB-0006 : 이 장비/태그는 위치 정보가 없습니다.', 'FMB-0006 : Dieses Equipment/Tag hat keine Informationen ueber seine Position.', 'ADMIN', '20050201170502', 'ADMIN', '20050429103522');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB-0007', 'FMB', 'FMB-0007 : The user define resource/tag already has location information.', 'FMB-0007 : 이 사용자 정의 장비/태그는 이미 위치 정보를 가지고 있습니다.', 'FMB-0007 : Dieses benutzerdefinierte Resource/Tag hat bereits Informationen ueber seine Position.', 'ADMIN', '20050201170614', 'ADMIN', '20050429103535');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB-0008', 'FMB', 'FMB-0008 : The user define resource/tag group does not have location information.', 'FMB-0008 : 이 사용자 정의 장비/태그는 위치 정보가 없습니다.', 'FMB-0008 : Dieses benutzerdefinierte Resource/Tag hat keine Informationen ueber seine Position.', 'ADMIN', '20050201170644', 'ADMIN', '20050429103617');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB-0009', 'FMB', 'FMB-0009 : The layout id is already exist.', 'FMB-0009 : 이 LayOut ID는 이미 존재 합니다.', 'FMB-0009 : LayOut ID existiert bereits.', 'ADMIN', '20050204102744', 'ADMIN', '20050204102834');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB-0010', 'FMB', 'FMB-0010 : The layout id  is not exist.', 'FMB-0010 : 이 LayOut ID는 존재하지 않습니다.', 'FMB-0010 : LayOut ID ist nicht vorhanden.', 'ADMIN', '20050204102826', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB-0011', 'FMB', 'FMB-0011 :  Cannot use the same name with factory name.', 'FMB-0011 : Factory 이름과 동일한 이름을 사용할 수 없습니다. ', 'FMB-0011 : Der gleiche Name wie der Factory Name kann nicht verwendet werden.', ' ', ' ', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB-0012', 'FMB', 'FMB-0012 :  The factory does not have environment information.', 'FMB-0012 : 이 공장은 환경 설정에 관한 정보가 존재하지 않습니다.', 'FMB-0012 : Die Factory besitzt keine Umweltinformationen.', 'ADMIN', '20050324102559', 'ADMIN', '20050324102654');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB-0013', 'FMB', 'FMB-0013 :  The resource does not have image.', 'FMB-0013 : 이 장비는 이미지가 없습니다.', 'FMB-0013 : Diese Resource hat kein Image.', 'ADMIN', '20050324173644', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB-0014', 'FMB', 'FMB-0014 : The resource already has back color information.', '이 장비는 이미 배경색 정보를 가지고 있습니다.', 'FMB-0014 : Das Resource hat bereits Informationen ueber die Hintergrundfarbe.', 'ADMIN', '20090302171342', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('FMB-0015', 'FMB', 'FMB-0015 : The resource does not have back color information.', '이 장비의 배경색 정보가 존재하지 않습니다.', 'FMB-0015 : Das Resource hat keine Informationen ueber die Hintergrundfarbe.', 'ADMIN', '20090302171521', ' ', ' ');



