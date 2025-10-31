--##### INSERT SYSTEM ERROR MESSAGE ######
--select * from mmsgmsgdef where msg_grp like 'SPC%' order by msg_id

Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0000', 'SPC', 'SPC-0000 : This step does not supported. Please check the step number.', 'SPC-0000 : 지원되지 않는 STEP입니다. 다시 확인 하십시요.', 'SPC-0000 : Dieser Schritt wird nicht unterstuetzt. Bitte ueberpruefen Sie die Schritt Nummer.', 'ADMIN', '20050503091916', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0001', 'SPC', 'SPC-0001 : This is required field. Please enter valid value.', 'SPC-0001 : 이 항목은 필요한 필드 입니다. 입력 바랍니다.', 'SPC-0001 : Feld muss ausgefuellt sein. Bitte um Eingabe.', 'ADMIN', '20050503101705', 'ADMIN', '20050503101809');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0002', 'SPC', 'SPC-0002 : The chart is already exist.', 'SPC-0002 : 이 차트는 이미 존재합니다.', 'SPC-0002 : Dieser Chart existiert bereits.', 'ADMIN', '20050503101801', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0003', 'SPC', 'SPC-0003 : The chart is not exist.', 'SPC-0003 : 이 차트는 존재하지 않습니다.', 'SPC-0003 : Dieser Chart existiert nicht.', 'ADMIN', '20050503101903', 'ADMIN', '20050503153513');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0004', 'SPC', 'SPC-0004 : Fatal database error is occured. Please contact admin person.', 'SPC-0004 : Database 작업중 오류가 발생 하였습니다. 관리자에게 문의 바랍니다.', 'SPC-0004 : Fataler Datenbankfehler. Bitte kontaktieren Sie den Admin.', 'ADMIN', '20050503101933', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0005', 'SPC', 'SPC-0005 : The chart was deleted.', 'SPC-0005 : 이 차트는 삭제되었습니다.', 'SPC-0005 : Dieser Chart wurde geloescht.', 'ADMIN', '20050503102511', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0006', 'SPC', 'SPC-0006 : ''Lot_Res_Flag'' is allowed to set only when chart is created.', 'SPC-0006 : ''Lot_Res_Flag'' 필드는 차트를 생성할때만 지정할수 있습니다.', 'SPC-0006 : ''Lot_Res_Flag'' Feld ist nur erlaubt, wenn der Chart erstellt wird.', 'ADMIN', '20050503163413', 'ADMIN', '20050506100241');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0007', 'SPC', 'SPC-0007 : The version is already exist.', 'SPC-0007 : 이 버전은 이미 존재합니다.', 'SPC-0007 : Diese Version existiert bereits.', 'ADMIN', '20050504091803', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0008', 'SPC', 'SPC-0008 : The version is not exist.', 'SPC-0008 : 이 버전은 존재하지 않습니다.', 'SPC-0008 : Diese Version existiert nicht.', 'ADMIN', '20050504091829', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0009', 'SPC', 'SPC-0009 : Cannot update this version because the version was already released.', 'SPC-0009 : 이 버전은 이미 Release 되었기 때문에 수정할 수 없습니다.', 'SPC-0009 : Diese Version kann nicht aktualisiert werden, da es bereits freigegeben wurde.', 'ADMIN', '20050504094329', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0010', 'SPC', 'SPC-0010 : End time of applying is faster than start time. please correct end time that later start time', 'SPC-0010 : 버전의 적용 만료 날짜가 적용 시작 날짜 이전입니다. 만료 날짜를 시작날짜 이후로 수정해 주세요.', 'SPC-0010 : Tag des Anwendungsstarts hinter dem Anwendungsende. Setzen Sie den Tag fuer das Anwendungsstart vor dem Ende.', 'ADMIN', '20050504094938', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0011', 'SPC', 'SPC-0011 : Cannot create version which is smaller than existing version.', 'SPC-0011 : 현재 존재하는 버전보다 작은 버전은 생성할 수 없습니다.', 'SPC-0011 : Eine Version,die kleiner ist als die aktuelle, kann nicht erstellt werden.', 'ADMIN', '20050504170238', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0012', 'SPC', 'SPC-0012 : Graph Type is allowed to set only when chart is created.', 'SPC-0012 :  그래프 종류는 차트를 생성할때만 지정할수 있습니다.', 'SPC-0012 : Graph Typ kann nur zugeteilt werden, wenn ein Chart erstellt wird.', 'ADMIN', '20050506100232', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0013', 'SPC', 'SPC-0013 : ''Use_Unit_Flag'' is allowed to set only when chart is created.', 'SPC-0013 : ''Use_Unit_Flag''  필드는 차트를 생성할때만 지정할수 있습니다.', 'SPC-0013 : ''Use_Unit_Flag'' Feld kann nur zugeteilt werden, wenn Chart erstellt wird.', 'ADMIN', '20050506104907', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0014', 'SPC', 'SPC-0014 : No Spec Version is able to apply.', 'SPC-0014 : 적용 가능한 SPEC VERSION을 찾을 수 없습니다.', 'SPC-0014 : Anwendbare SPEC VERSION kann nicht gefunden werden.', 'ADMIN', '20050506170955', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0015', 'SPC', 'SPC-0015 : The spec information is not last version. Please check again.', 'SPC-0015 : Spec 정보가 최신 버전이 아닙니다. 다시 확인해주십시요.', 'SPC-0015 : Es handeln sich nicht um die neuesten Spec Informationen. Bitte um Ueberpruefung.', 'ADMIN', '20050513114236', 'ADMIN', '20050513133129');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0016', 'SPC', 'SPC-0016 : The chart information is not last one. Please check again.', 'SPC-0016 : 차트 정보가 최신이 아닙니다. 다시 확인해주십시요.', 'SPC-0016 : Es handeln sich nicht um die neuesten Chart Informationen. Bitte um Ueberpruefung.', 'ADMIN', '20050513133602', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0017', 'SPC', 'SPC-0017 : The chart is not allowed to collect lot data.', 'SPC-0017 : LOT DATA를 수집할수 있는 차트가 아닙니다.', 'SPC-0017 : Dieser Chart kann keine LOT Daten sammeln.', 'ADMIN', '20050513134519', 'ADMIN', '20050513135132');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0018', 'SPC', 'SPC-0018 : The chart is not allowed to collect resource data.', 'SPC-0018 : RESOURCE DATA를 수집할수 있는 차트가 아닙니다.', 'SPC-0018 : Dieser Chart kann keine RESOURCE Daten sammeln.', 'ADMIN', '20050513135152', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0019', 'SPC', 'SPC-0019 : The OOC history is not exist.', 'SPC-0019 : 이 OOC History는 존재하지 않습니다.', 'SPC-0019 : OOC History ist nicht vorhanden.', 'ADMIN', '20050527095044', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0020', 'SPC', 'SPC-0020 : The EDC history is not exist.', 'SPC-0020 : 이 EDC History는 존재하지 않습니다.', 'SPC-0020 : EDC History ist nicht vorhanden.', 'ADMIN', '20050601150246', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0021', 'SPC', 'SPC-0021 : The Calculation history is not exist.', 'SPC-0021 : 이 Calculation History는 존재하지 않습니다.', 'SPC-0021 : Calculation History existiert nicht.', 'ADMIN', '20050601155146', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0022', 'SPC', 'SPC-0022 : Unit Count is allowed to set only when chart is created.', 'SPC-0022 : Unit Count 필드는 차트를 생성할때만 지정할수 있습니다.', 'SPC-0022 : Unit Count Feld kann nur zugeteilt werden, wenn Chart erstellt wird.', 'ADMIN', '20050603160332', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0023', 'SPC', 'SPC-0023 : Sample Size is allowed to set only when chart is created.', 'SPC-0023 : Sample Size 필드는 차트를 생성할때만 지정할수 있습니다.', 'SPC-0023 : Sample Size Feld kann nur zugeteilt werden, wenn Chart erstellt wird.', 'ADMIN', '20050603160357', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0024', 'SPC', 'SPC-0024 : The user is not set for the chart.', 'SPC-0024 : 차트에 지정되지 않은 사용자 입니다.', 'SPC-0024 : Der Benutzer ist dem Chart nicht zugeordnet worden.', 'ADMIN', '20050608161246', 'ADMIN', '20050608161915');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0025', 'SPC', 'SPC-0025 : The user is already set for the chart.', 'SPC-0025 : 차트에 이미 지정된 사용자 입니다.', 'SPC-0025 : Der Benutzer ist dem Chart bereits zugeordnet worden.', 'ADMIN', '20050608161907', 'ADMIN', '20050622114141');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0026', 'SPC', ' SPC-0026 : The data is not exist.', 'SPC-0026 : 데이터가 존재하지 않습니다.', 'SPC-0026 : Daten sind nicht vorhanden.', 'ADMIN', '20050617100000', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0027', 'SPC', 'SPC-0027 : Cannot release version which is smaller than existing released version.', 'SPC-0027 : 현재 존재하는 릴리즈된 버전보다 작은 버전은 릴리즈할 수 없습니다.', 'SPC-0027 : Version kleiner als aktuelle Version kann nicht freigegeben werden.', 'ADMIN', '20050621110949', 'ADMIN', '20050621111813');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0028', 'SPC', 'SPC-0028 : The chart can''t  auto-calculated of spec .', 'SPC-0028 : SPEC을 자동 계산할 수 있는 차트가 아닙니다.', 'SPC-0028 : Automatische SPEC Kalkulation mit diesem Chart nicht moeglich.', 'ADMIN', '20050812111631', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0029', 'SPC', 'SPC-0029 : No Alarm history.', 'SPC-0029 : 해당 알람 이력이 없습니다.', 'SPC-0029 : Alarm History nicht vorhanden.', 'ADMIN', '20051018160640', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0030', 'SPC', 'SPC-0030 : The alarm is aleady cleared.', 'SPC-0030 : 이 알람은 이미 처리되었습니다.', 'SPC-0030 : Dieser Alarm wurde bereits erledigt.', 'ADMIN', '20051025133320', 'ADMIN', '20051025133350');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0031', 'SPC', 'SPC-0031 : The chart set is already exist.', 'SPC-0031 : 이 CHART SET은  이미 존재합니다.', 'SPC-0031 : Dieser CHART SET existiert bereits.', 'ADMIN', '20051108180007', 'ADMIN', '20051108180017');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0032', 'SPC', 'SPC-0032 : The chart set is not exist.', 'SPC-0032 : 이 CHART SET은 존재하지 않습니다.', 'SPC-0032 : CHART SET existiert nicht.', 'ADMIN', '20051108180233', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0033', 'SPC', 'SPC-0033 : The chart is not set for the chart set.', 'SPC-0033 : CHART SET에 지정되지 않은 차트입니다.', 'SPC-0033 : Dieser Chart wurde nicht dem CHART SET zugeordnet.', 'ADMIN', '20051108183753', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0034', 'SPC', 'SPC-0034 : The chart is already set for the chart set.', 'SPC-0034 : CHART SET에 이미 지정된 차트 입니다.', 'SPC-0034 : Dieser Chart wurde bereits dem CHART SET zugeordnet.', 'ADMIN', '20051108183858', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0035', 'SPC', 'SPC-0035 : The data is already included.', 'SPC-0035 : 이 데이터는 이미 포함되어 있습니다.', 'SPC-0035 : Daten sind bereits eingefuegt.', 'ADMIN', '20051125114312', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0036', 'SPC', 'SPC-0036 : The data is already excluded.', 'SPC-0036 : 이 데이터는 이미 제외되어 있습니다.', 'SPC-0036 : Daten sind bereits ausgegliedert.', 'ADMIN', '20051125114425', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0037', 'SPC', 'SPC-0037 : The chart set is not exist. Create the chart set first.', 'SPC-0037 : 이 CHART SET은 존재하지 않습니다. CHART SET을 먼저 생성하십시요.', 'SPC-0037 : Dieser CHART SET existiert nicht. Bitten stellen Sie zuerst einen CHART SET her.', 'ADMIN', '20051129115459', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0038', 'SPC', 'SPC-0038 : This material-flow-operation has no chart.', 'SPC-0038 : 이 MATERIAL-FLOW-OPERATION에는 CHART가 존재 하지 않습니다.', 'SPC-0038 : Diese MATERIAL-FLOW-OPERATION besitzt keinen Chart.', 'ADMIN', '20060119161059', 'ADMIN', '20060119161439');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0039', 'SPC', 'SPC-0039 : This material-flow-operation  already has chart.', 'SPC-0039 : 이 MATERIAL-FLOW-OPERATION 은 이미 차트를 가지고 있습니다.', 'SPC-0039 : Diese MATERIAL-FLOW-OPERATION besitzt bereits einen Chart.', 'ADMIN', '20060119161531', 'ADMIN', '20060119161601');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0040', 'SPC', 'SPC-0040 : The flow is not attached to the material', 'SPC-0040 :  이 FLOW는 MATERIAL에 속해 있지 않습니다.', 'SPC-0040 : Dieser FLOW ist nicht im MATERIAL inbegriffen.', 'ADMIN', '20060119163907', 'ADMIN', '20060119163939');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0041', 'SPC', 'SPC-0041 : The operation is not attached to the flow.', 'SPC-0041 :  이 OPERATION은 FLOW에 속해 있지 않습니다.', 'SPC-0041 : Diese OPERATION ist nicht im FLOW inbegriffen.', 'ADMIN', '20060119164047', 'ADMIN', '20060119164112');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0042', 'SPC', 'SPC-0042 : The chart must exist to set the override flag value to "Y"', 'SPC-0042 :  OVERRIDE FLAG를 "Y" 로 지정하기 위해서는 CHART가 반드시 존재해야 합니다.', 'SPC-0042 : Um OVERRIDE FLAG dem "Y" zuzuordnen, muss der CHART vorhanden sein.', 'ADMIN', '20060119172304', 'ADMIN', '20060119172342');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0043', 'SPC', 'SPC-0043 : Cannot update M-F-O information because the chart set is attached at material-flow-oper.', 'SPC-0043 : 이 CHART SET은 M-F-O에 연결되어 있기때문에 M-F-O 정보를 수정할 수 없습니다.', 'SPC-0043 : Da dieses CHART SET mit dem M-F-O verbunden ist, koennen M-F-O Informationen nicht modifiziert werden.', 'ADMIN', '20060208101101', 'ADMIN', '20060208115400');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0044', 'SPC', 'SPC-0044 : Cannot update M-F-O information because some chart is attached to the chart set.', 'SPC-0044 : 이 CHART SET은 차트가 등록되어 있기때문에 M-F-O 정보를 수정할 수 없습니다.', 'SPC-0044 : Da dieses CHART SET registriert ist, koennen M-F-O Informationen nicht modifiziert werden.', 'ADMIN', '20060208101744', 'ADMIN', '20060208115709');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0045', 'SPC', 'SPC-0045 : The chart cannot be set for the chart set because chart and chart set have different M-F-O information.', 'SPC-0045 : 이 차트는 CHART SET과 M-F-O 정보가 다르기 때문에 CHART SET에 등록할 수 없습니다.', 'SPC-0045 : Dieser Cahrt kann nicht im Chart Set registriert werden, da CHART SET und M-F-O Informationen unterschiedlich sind.', 'ADMIN', '20060208110158', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0046', 'SPC', 'SPC-0046 : Cannot update M-F-O information because the chart is attached at material-flow-oper.', 'SPC-0046 : 이 차트는 M-F-O에 연결되어 있기때문에 M-F-O 정보를 수정할 수 없습니다.', 'SPC-0046 : Da dieses CHART mit dem M-F-O verbunden ist, koennen M-F-O Informationen nicht modifiziert werden.', 'ADMIN', '20060208115441', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0047', 'SPC', 'SPC-0047 : Cannot update M-F-O information because the chart is attached to chart set.', 'SPC-0047 : 이 차트는 CHART SET에 등록되어 있기때문에 M-F-O 정보를 수정할 수 없습니다.', 'SPC-0047 : Da dieser Chart im CHART SET registriert ist, koennen M-F-O Informationen nicht modifiziert werden.', 'ADMIN', '20060208115655', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0048', 'SPC', 'SPC-0048 : The chart does not have prompt information.', 'SPC-0048 : 이 차트는 PROMPT 정보가 없습니다.', 'SPC-0048 : Dieser Chart enthaelt keine PROMPT Informationen.', 'ADMIN', '20060223110713', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0049', 'SPC', 'SPC-0049 : Unit is missed. Please Enter Unit.', 'SPC-0049 : Unit이 입력되지 않았습니다.UNIT을 입력해 주세요.', 'SPC-0049 : Unit wurde nicht eingegeben. Bitte geben sie Unit ein.', 'ADMIN', '20060515172130', 'ADMIN', '20060515172201');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0050', 'SPC', 'SPC-0050 : Unit ID is not valid . Please input valid Unit ID.', 'SPC-0050 : UNIT ID 가 올바르지 않습니다. 올바른 UNIT ID를 입력해 주세요.', 'SPC-0050 : Ungueltiger UNIT ID. Bitte geben Sie gueltigen ID ein.', 'ADMIN', '20060515172219', 'ADMIN', '20060515172326');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0051', 'SPC', 'SPC-0051 : Default unit ID does not exist according to the unit sequence.', 'SPC-0051 : UNIT SEQUENCE 에 대한 Default Unit ID 가 존재하지 않습니다.', 'SPC-0051 : Laut der UNIT SEQUENCE existiert die Default Unit ID nicht.', 'ADMIN', '20060515172350', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0052', 'SPC', 'SPC-0052 : This character cannot save blank because it is synchronize with SPC.', 'SPC-0052 : 이 캐릭터는 SPC와 연동되어 있기 때문에 공백을 저장할 수 없습니다.', 'SPC-0052 : Da dieser Character mit dem SPC verbunden ist, koennen Leerstellen nicht gespeichert werden.', 'ADMIN', '20060523133854', 'ADMIN', '20060523133948');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0053', 'SPC', 'SPC-0053 : The defect count cannot greater than sample size.', 'SPC-0053 : 결점수는 샘플 크기 보다 클 수 없습니다.', 'SPC-0053 : Die Defektanzahl darf nicht groesser sein als die Mustergroesse.', 'ADMIN', '20060707174733', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0054', 'SPC', 'SPC-0054 : The chart cannot be set for the chart set because chart and chart set have different resource information.', 'SPC-0054 : 이 차트는 CHART SET과 장비 정보가 다르기 때문에 CHART SET에 등록할 수 없습니다.', 'SPC-0054 : Da dieser Chart und CHART SET verschieden Equip. Informationen haben, ist eine Registration im Chart Set nicht moeglich.', 'ADMIN', '20060802094422', ' ', ' ');
Insert into MMSGMSGDEF
   (MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME)
 Values
   ('SPC-0055', 'SPC', 'SPC-0055 : ''Sync EDC Flag'' is allowed to set only when chart is created.', 'SPC-0055 : ''Sync EDC Flag'' 필드는 차트를 생성할때만 지정할수 있습니다.', 'SPC-0055 : ''Sync EDC Flag'' Feld kann nur zugeordnet werden, wenn ein Chart erstellt wird.', 'ADMIN', '20060802094422', ' ', ' ');
/* Added By YJJUNG 2012.05.23 */
INSERT INTO MMSGMSGDEF(MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME) 
VALUES('SPC-0056', 'SPC', 'SPC-0056 : The count of data is not enough for Minimum Count during the period.', 'SPC-0056 : 해당 기간의 데이터 수가 Minimum Count에 미치지 못합니다.', 'SPC-0056 :Die Anzahl der Daten ist nicht genug fur minimale Anzahl wahrend der Periode.', 'ADMIN', '20120523111327', ' ', ' ');

/* Added By YJJUNG 2016.03.03 */
INSERT INTO MMSGMSGDEF(MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME) 
VALUES('SPC-0057','SPC','SPC-0057 : Only numeric value is allowed. Please input again.','SPC-0057 : 숫자 값만 허용 합니다. 다시 입력하여 주세요.','SPC-0057 : Nur numerische Werte sind erlaubt. Bitte erneut eingeben.','ADMIN','20160303010101',' ',' ');                   

/* Added By YJJUNG 2016.03.03 */
INSERT INTO MMSGMSGDEF(MSG_ID, MSG_GRP, MSG_1, MSG_2, MSG_3, CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME) 
VALUES('SPC-0058','SPC','SPC-0058 : Valid value is between 0 and 100. Please input again.','SPC-0058 : 값은 0보다 크고 100보다 작아야 합니다.다시 입력하여 주세요','SPC-0058 : Ein gultiger Wert zwischen 0 und 100. Bitte erneut eingeben.','ADMIN','20160303010101',' ',' ');                   


