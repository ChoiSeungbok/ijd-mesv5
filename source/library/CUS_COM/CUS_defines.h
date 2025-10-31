
#ifndef _CUS_DEFINES_H
#define _CUS_DEFINES_H 
 
/*
** Variable Definitions
*/

extern char gs_cus_cpt_dir[256];
extern char gs_sys_time[14];
extern char gs_cus_rpt_dir[256];

extern char gs_area_ctm[3];
extern char gs_area_pdc[3];
extern char gs_area_hm[3];
extern char gs_area_grt[3];
extern double pv_clw_in_temp;
extern double pv_clw_out_temp;
extern double pv_hdl_temp;

struct work_date_tag
{
    char s_sys_time[14];
    char s_work_month[6];
    char s_work_date[8];
    char s_day_night[10];
	char c_kind;
};

struct execute_seq_tag
{
    char s_execute_date[8];
    char s_total_seq[8];
};

/*
** Constant Definitions
*/
/***********************************************************************************************/
/* Factory                                                                                       */
/************************************************************123456789012345678901234567890*******/ 


/*************************************************************************************************/
/* MES Plus Cation Type                                                                          */
/************************************************************123456789012345678901234567890*******/
#define MP_CAPTION_TYPE_MENU                               ("Menu      ")                        //Menu
#define MP_CAPTION_TYPE_MESSAGE                            ("Message   ")                        //Message
#define MP_CAPTION_TYPE_OTHERS                             ("Others    ")                        //Others
#define MP_CAPTION_TYPE_BUTTON                             ("Button    ")                        //Button

/*************************************************************************************************/
/* MES Plus Cation File Name
/************************************************************123456789012345678901234567890*******/
#define MP_CAPTION_FILE_MESSAGE                             "MESMessage.xml"                     //Message
#define MP_CAPTION_FILE_CAPTION                             "MESCaption.xml"                     //Caption

//SYSTEM FACTORY
#define MP_SYS_FACTORY		("SYSTEM")

//DEFAULT SETUP
#define MP_DEFAULT_USER_ID		("MESSYSTEM")

//GCM 리스트

#define MP_GCM_SYSTEM		            ("C_SYSTEM_OPTION")         //CUSTOM SYSTEM OPTION
#define MP_GCM_GLOBAL_AREA		        ("GLOBAL_AREA")             //GLOBAL AREA code
#define MP_GCM_AREA				        ("AREA")
#define MP_GCM_SUB_AREA                 ("SUB_AREA")
#define MP_GCM_AREA_OPTION				("C_AREA_OPTION")
#define MP_GCM_OPER_OPTION              ("C_OPER_OPTION")
#define MP_GCM_OPER_DATA                ("C_OPER_DATA")
#define MP_GCM_OPER_LOSS                ("C_OPER_LOSS")
#define MP_GCM_LOSS_CODE                ("LOSS_CODE")
#define MP_GCM_CUSTOMER			        ("C_CUSTOMER")				// CUSTOMER
#define MP_GCM_GRIT_OPER                ("C_GRIT_OPER")
#define MP_GCM_GRIT_CLASS_TYPE          ("C_GRIT_CLASS_TYPE")
#define MP_GCM_GRIT_CLASS_JUDGE         ("C_GRIT_CLASS_JUDGE")
#define MP_GCM_GRIT_CLASS               ("C_GRIT_CLASS")
#define MP_GCM_VENDOR			        ("C_VENDOR")				//  VENDOR
#define MP_GCM_UNIT				        ("UNIT")					//  UNIT
#define MP_GCM_MATERIAL_TYPE	        ("MATERIAL_TYPE")			//  MATERIAL_TYPE
#define MP_GCM_INSP_GRIT_SIZE	        ("C_INSP_GRIT_SIZE")		//  GRIT ST BY SIZE
#define MP_GCM_SRC_CODE			        ("C_SRC_CODE")				//  SRC CODE
#define MP_GCM_INSP_STATUS	            ("C_INSP_STATUS")			//  INSPECTION STATUS
#define MP_GCM_ETC_IN_TYPE		        ("C_ETC_IN_TYPE")			//  ETC IN TYPE
#define MP_GCM_ETC_OUT_TYPE		        ("C_ETC_OUT_TYPE")			//  ETC OUT TYPE
#define MP_GCM_CAR		                ("C_CAR")			        //  CAR정보
#define MP_GCM_NOP_GRP_1		        ("C_NOP_GRP_1")			    //  비가동 그룹 1
#define MP_GCM_NOP_GRP_2		        ("C_NOP_GRP_2")			    //  비가동 그룹 2
#define MP_GCM_NOP_GRP_3	            ("C_NOP_GRP_3")		        //  비가동 그룹 3
#define MP_GCM_MATCH_STATUS	            ("C_MATCH_STATUS")		    //  일치여부(출하 LOT 체크)
#define MP_GCM_INSP_JUDGE_LIST	        ("C_INSP_JUDGE_LIST")		//  JUDGE 리스트
#define MP_GCM_INSP_JUDGE				("C_INSP_JUDGE")			//  OPER 별 JUDGE 
#define MP_GCM_TRANS_RES_INFO	        ("C_TRANS_RES_INFO")		//  컵, 임펙트 설비정보 전송
#define MP_GCM_PRESS_PROFILE_MAP	    ("C_PROFILE_MAP")		    //  사업부, 설비, 제품코드, 프로파일 매핑 
#define MP_GCM_PROFILE_DEF	            ("C_PROFILE_DEF")		    //  사업부별 프로파일 리스트
#define MP_GCM_PROFILE_DATA	            ("C_PROFILE_DATA")		    //  사업부별 프로파일 리스트
#define MP_GCM_PRESS_TIME_SET	        ("C_PRESS_TIME_SET")		//  PRESS TIME SET
#define MP_GCM_MOLD_OPER                ("C_MOLD_OPER ")		    //  금형 창고
#define MP_GCM_MAT_CLASS_1_MAP          ("C_MAT_CLASS_1_MAP")		//  Summary 용 제품분류
#define MP_GCM_DELIVERY			        ("C_DELIVERY")				//  DELIVERY
#define MP_GCM_LOAD_LEVEL		        ("C_LOAD_LEVEL")			//  LOAD LEVEL
#define MP_GCM_C_INSP_IQC_MES_FLAG		("C_INSP_IQC_MES_FLAG")			//  수입검사유무
#define MP_GCM_C_SHP_ALL_SHIP_CUS		("C_SHP_ALL_SHIP_CUS")			//  판정제약없이 나갈수있는 고객사명.

//CUSTOM SYSTEM OPTION 
#define MP_SYS_ORDER_OVER_QTY           ("ORDER_OVER_QTY")          // system option 작업지시 생성 수량 벨리데이션
#define MP_SYS_START_BOM_CHECK          ("START_BOM_CHECK")         // system option 자재 bom 단위 투입 벨리데이션
#define MP_SYS_CHECK_ERP_ERR            ("CHECK_ERP_ERR")           // system option ERP처리 에러시 LOT의 작업 진행여부 체크 벨리데이션
#define MP_SYS_CHECK_DELETE_DATE        ("CHECK_DELETE_DATE")       // system option 이력삭제시 해당 날짜 이전에는 이력삭제 못하게 하는 벨리데이션
#define MP_SYS_CHECK_ERP_OPER           ("CHECK_ERP_OPER")          // system option 작업지시의 flow의 공정이 작업지시상 erp공정이 존재하는지 체크
#define MP_SYS_CHECK_ERP_OPER_END       ("CHECK_ERP_OPER_END")      // system option END시 작업지시의 flow의 공정이 작업지시상 erp공정이 존재하는지 체크(임시)

//작업지시 상태 
#define MP_CWIP_ORDER_WAIT       ('W')
#define MP_CWIP_ORDER_START      ('O')
#define MP_CWIP_ORDER_CLOSE      ('C')
#define MP_CWIP_ORDER_FINISH     ('F')
#define MP_CWIP_ORDER_DELETE     ('D')

#define MP_LOT_TYPE_T               ('T')
#define MP_LOT_TYPE_P               ('P')
#define MP_OWNER_CODE_PROD			("PROD")
#define MP_OWNER_CODE_DEVE			("DEVE")
#define MP_CREATE_CODE_PROD			("PROD")
#define MP_CREATE_CODE_TEST			("TEST")
#define MP_CREATE_CODE_RND			("RND")
#define MP_CREATE_CODE_SAMPLE		("SAMPLE")

//자재 LOT 상태								
#define MP_CINV_LOT_STATUS_WAIT				("WAIT")
#define MP_CINV_LOT_STATUS_CONFIRM			("CONFIRM")
#define MP_CINV_LOT_STATUS_COMPLETED		("COMPLETED")


//상태										  0123456789
#define MP_STATUS_WAIT						("WAIT      ")
#define MP_STATUS_CONFIRM					("CONFIRM   ")
#define MP_STATUS_COMPLETED					("COMPLETED ")
#define MP_STATUS_OPEN						("OPEN      ")
#define MP_STATUS_CLOSE						("CLOSE     ")
#define MP_STATUS_SHIPPED					("SHIPPED   ")
#define MP_STATUS_RETURNED					("RETURNED  ")


//LOT 분류 - 자재 or 공정 
#define MP_LOT_TYPE_WIP			("WIP")
#define MP_LOT_TYPE_INV			("INV")

//자재 투입 방식 
#define MP_INPUT_TYPE_BOM		("BOM")
#define MP_INPUT_TYPE_ALL		("ALL")
#define MP_INPUT_TYPE_LOT		("LOT")

//자재 트랜잭션 코드                      012345678901234567890123456789
#define MP_CINV_TRAN_CODE_CREATE		("CREATE                        ")
#define MP_CINV_TRAN_CODE_TEMP_IN		("TEMP_IN                       ")
#define MP_CINV_TRAN_CODE_RET_OUT		("RET_OUT                       ")
#define MP_CINV_TRAN_CODE_IN			("IN                            ")
#define MP_CINV_TRAN_CODE_MOVE			("MOVE                          ")
#define MP_CINV_TRAN_CODE_OPER_IN		("OPER_IN                       ")
#define MP_CINV_TRAN_CODE_INV_IN		("INV_IN                        ")
#define MP_CINV_TRAN_CODE_HOLD			("HOLD                          ")
#define MP_CINV_TRAN_CODE_RELEASE		("RELEASE                       ")
#define MP_CINV_TRAN_CODE_SPLIT			("SPLIT                         ")
#define MP_CINV_TRAN_CODE_MERGE			("MERGE                         ")
#define MP_CINV_TRAN_CODE_TERMINATE		("TERMINATE                     ")
#define MP_CINV_TRAN_CODE_LOAD			("LOAD                          ")
#define MP_CINV_TRAN_CODE_UNLOAD		("UNLOAD                        ")
#define MP_CINV_TRAN_CODE_ISSUE			("ISSUE                         ")
#define MP_CINV_TRAN_CODE_CV			("CV                            ")
#define MP_CINV_TRAN_CODE_ETC_IN		("ETC_IN                        ")
#define MP_CINV_TRAN_CODE_ETC_OUT		("ETC_OUT                       ") 
#define MP_CINV_TRAN_CODE_KITTING		("KITTING                       ") 
#define MP_CINV_TRAN_CODE_UNKITTING		("UNKITTING                     ") 
#define MP_CINV_TRAN_CODE_REGENERATE	("REGENERATE                    ")
#define MP_CINV_TRAN_CODE_PROD_IN		("PROD_IN                       ")
#define MP_CINV_TRAN_CODE_PROD_OUT		("PROD_OUT                      ")
#define MP_CINV_TRAN_CODE_SHIP			("SHIP                          ")
#define MP_CINV_TRAN_CODE_OUTSRC_IN		("OUTSRC_IN                     ")
#define MP_CINV_TRAN_CODE_RET_IN        ("RET_IN                        ")
#define MP_CINV_TRAN_CODE_LOAD_LOT		("LOAD_LOT                      ")
#define MP_CINV_TRAN_CODE_LOAD_RES		("LOAD_RES                      ")
#define MP_CINV_TRAN_CODE_LOAD_WO		("LOAD_WO                       ")
#define MP_CINV_TRAN_CODE_LOAD_OPER		("LOAD_OPER                     ")
#define MP_CINV_TRAN_CODE_UNLOAD_LOT	("UNLOAD_LOT                    ")
#define MP_CINV_TRAN_CODE_UNLOAD_RES	("UNLOAD_RES                    ")
#define MP_CINV_TRAN_CODE_UNLOAD_WO		("UNLOAD_WO                     ")
#define MP_CINV_TRAN_CODE_UNLOAD_OPER	("UNLOAD_OPER                   ")


//창고 코드
#define MP_OPER_I_RAW					("I-RAW") 
#define MP_OPER_W_RMA					("W-RMA") 
#define MP_OPER_INSP					("INSP") 

//불출 요청 상태
#define MP_CINV_ISSUE_CREATE			("CREATE")
#define MP_CINV_ISSUE_REQUEST			("REQUEST")
#define MP_CINV_ISSUE_REGIST			("REGIST")
#define MP_CINV_ISSUE_ISSUE				("ISSUE")
#define MP_CINV_ISSUE_COMPLETED			("COMPLETED")

//ID 채번 룰 확정_
#define MP_ID_ROLE_WIP_COM_OPER		    ("WIP_OPER_LOT_ID")             //공통 공정LOT ID 
#define MP_ID_ROLE_CTM_MCUP_LOT		    ("WIP_CTM_MANUAL_CUP_LOT_ID")   //CTM 수동 컵LOT ID 
#define MP_ID_ROLE_CTM_ACUP_LOT		    ("WIP_CTM_AUTO_CUP_LOT_ID")     //CTM 자동 컵LOT ID 
#define MP_ID_ROLE_WIP_MOVE_ORDER		("WIP_MOVE_ORDER")              //이동지시번호
#define MP_ID_ROLE_WIP_PRESS_LOT_ID		("WIP_PRESS_LOT_ID")            //CTM PRESS ID 발번
#define MP_ID_ROLE_WIP_GROUP_ID		    ("WIP_GROUP_ID")                //그룹번호(D12,CELL)
#define MP_ID_ROLE_WIP_ISP_GROUP_ID		("WIP_ISP_GROUP_ID")            //황삭 준비 공정 그룹 ID
#define MP_ID_ROLE_WIP_CUP_GROUP_ID		("WIP_CUP_GROUP_ID")            //컵계량 SPLIT후 그룹ID
#define MP_ID_ROLE_WIP_PDC_SPT_LOT		("WIP_PDC_SPLIT_LOT")           //PDC SPLIT LOT
#define MP_ID_ROLE_WIP_HM_SINTER		("WIP_HM_SINTER_LOT_ID")        //HM소결 LOT
#define MP_ID_ROLE_SHIPPING_LOT_ID		("WIP_SHIPPING_LOT_ID")        // 출하 LOT ID 
#define MP_ID_ROLE_INV_LOT_ID			("INV_LOT_ID")					//자재 LOT ID
#define MP_ID_ROLE_DLV_LOT_ID			("DLV_LOT_ID")					//입하 LOT ID
#define MP_ID_ROLE_DLV_LOT_ID_1			("DLV_LOT_ID_1")				//입하 LOT ID_1
#define MP_ID_ROLE_ISSUE_REQUEST_NO		("ISSUE_REQUEST_NO")			//불출 요청 NO
#define MP_ID_ROLE_KITTING_ID			("KITTING_ID")					//KITTING ID
#define MP_ID_ROLE_SPLIT_INV_LOT_ID		("SPLIT_INV_LOT_ID")			//자재 분할 ID
#define	MP_ID_ROLE_DLV_NO				("DLV_NO")						//구매 입고 NO
#define MP_ID_ROLE_GRT_CLASS_LOT_ID		("WIP_GRT_CLASS_LOT_ID")	    //형상분류 LOTID
#define MP_ID_ROLE_RET_ORDER_NO			("RET_ORDER_NO")				//반품지시 NO
#define MP_ID_ROLE_CTM_SHIPPING_LOT_ID	("WIP_CTM_SHIPPING_LOT_ID")     // CTM 출하 LOT ID 
#define MP_ID_ROLE_SPLIT_INV_LOT_ID_NEW ("SPLIT_INV_LOT_ID_NEW")		// 신규 SPLIT LOT ID
#define MP_ID_ROLE_TEST_ORDER           ("WIP_TEST_ORDER")		        // 테스트 작업지시 번호
#define MP_ID_ROLE_GRT_PRESS_LOT_ID     ("WIP_GRT_PRESS_LOT_ID")		// 그릿 합성 ID 룰
#define MP_ID_ROLE_INSP_ID     ("INSP_ID")		// 검사요청번호
#define MP_ID_ROLE_CTV_CELL_NO	    ("WIP_CTV_CELL_NO")   //CTV 베트남 CELL NO

//ID 채번 룰
#define MP_ID_ROLE_SPLIT_SHP_LOT		("SPLIT_SHP_LOT_ID")	// SPLIT SHP LOT ID 채번
#define MP_ID_ROLE_SPLIT_GRT_LOT		("SPLIT_GRT_LOT_ID")	// GRT SPLIT LOT 채번
#define MP_ID_ROLE_GRIT_CLASS_ORDER		("GRIT_CLASS_ORDER")  //그릿 작업지시 

//재단기
#define MP_PRESS						("Press")

//설비 그룹 코드
#define MP_RESS_GRP_PRESS			    ("E002")
#define MP_RESS_GRP_BOLMIL			    ("E005")
#define MP_RESS_GRP_ROUND			    ("E026")

//EAP설비 그룹 채널 셋팅
#define MP_EAP_RES_GRP_BOLMIL	        ("BALLG01")
#define MP_EAP_RES_GRP_PRESS1	        ("PRESSG01")
#define MP_EAP_RES_GRP_PRESS2	        ("PRESSG02")

//CV코드 
#define MP_CV_CODE_INPUT_INV		    ("CV002") 

//LOSS 코드 
#define MP_LOSS_CODE_SIZE		        ("GBAE106")    //사이즈 분류 잔량 LOSS코드
#define MP_LOSS_CODE_MAGN		        ("GBAE105")    //자성 분류 잔량 LOSS코드
#define MP_LOSS_CODE_CUP		        ("GBAE107")    //형상 분류 잔량 LOSS코드
#define MP_LOSS_CODE_COM		        ("CBAD002")    //자성 분류 잔량 LOSS코드
#define MP_LOSS_CODE_NON_STOCK		    ("GBAN001")    //부외재고 이공 불량코드
#define MP_LOSS_CODE_P_STOCK		    ("CBAD410")    //P급창고  이공 불량코드

//MAPPING GROUP TYPE 
#define MP_MAPPING_GROUP_D12		    ("D12") 
#define MP_MAPPING_GROUP_CELL		    ("CELL") 
#define MP_MAPPING_GROUP_ISP		    ("ISP") 
#define MP_MAPPING_GROUP_CUP		    ("CUP") 

// 출하 상태
#define MP_CSHP_STATUS_WAIT				("WAIT")
#define MP_CSHP_STATUS_PACKED			("PACKED")
#define MP_CSHP_STATUS_SHIPPED			("SHIPPED")
#define MP_CSHP_STATUS_RETURNED			("RETURNED")

// 사업부
#define MP_AREA_GRIT					("GRT")
#define MP_AREA_HM						("HM")
#define MP_AREA_PDC						("PDC")
#define MP_AREA_CTM						("CTM")

// 금형 자재
#define MP_MAT_TYPE_STORED_GOODS        ("STORED_GOODS")

// 제품 타입
#define MP_MAT_TYPE_FINISHED_GOODS     ("FINISHED_GOODS") // 제품
#define MP_MAT_TYPE_SEMI_FINISHED     ("SEMI_FINISHED")   // 반제품
#define MP_MAT_TYPE_RAW_MATERIAL     ("RAW_MATERIAL")     // 원자재
#define MP_MAT_TYPE_PROTO_TYPE     ("PROTO_TYPE")     // 개발품

// 창고 TYPE
#define MP_OPER_GRP_TYPE_INV			("INV")
#define MP_OPER_GRP_TYPE_OPER			("OPER")
#define MP_OPER_GRP_TYPE_SHIP			("SHIP")
#define MP_OPER_GRP_TYPE_RET			("RET")
#define MP_OPER_GRP_TYPE_PROD			("PROD")
#define MP_OPER_GRP_TYPE_INSP			("INSP")
#define MP_OPER_GRP_TYPE_MOLD			("MOLD")
#define MP_OPER_GRP_TYPE_CONSIGNMENT	("CONSIGNMENT")
#define MP_OPER_GRP_TYPE_RET_R			("RET_R")
#define MP_OPER_GRP_TYPE_OSP			("OSP")
#define MP_OPER_GRP_TYPE_LOSS			("LOSS")

// 금형 폐기 요청 상태
#define MP_CRAS_DSP_REQ_STATUS_REQUEST		("REQUEST")
#define MP_CRAS_DSP_REQ_STATUS_CONFIRM	    ("CONFIRM")
#define MP_CRAS_DSP_REQ_STATUS_COMPLETED	("COMPLETED")

//검사 타입
#define MP_INSP_TYPE_IQC ("IQC")     //Incoming Quality Control
#define MP_INSP_TYPE_OQC ("OQC")  //Outgoing Quality Control
#define MP_INSP_TYPE_PQC ("PQC")   //Process Quality Control
#define MP_INSP_TYPE_RMA ("RMA")   //Return Merchandise Authorization
#define MP_INSP_TYPE_RQC ("RQC")   //Outside Quality Control

//  부서코드
#define MP_DEPT_CODE_RES                ("RES") //설비팀

// 바코드 TYPE
#define MP_BARCODE_TYPE_INV_LOT			("INV_LOT")
#define MP_BARCODE_TYPE_DLV_LOT			("DLV_LOT")
#define MP_BARCODE_TYPE_ISSUE_REQUEST	("ISSUE_REQUEST")
#define MP_BARCODE_TYPE_LOT				("LOT")
#define MP_BARCODE_TYPE_MOVE_REQUEST	("MOVE_REQUEST")
#define MP_BARCODE_TYPE_BOX				("BOX")
#define MP_BARCODE_TYPE_FINAL_BOX		("FINAL_BOX")
#define MP_BARCODE_TYPE_NOTHING			("NOTHING")
#define MP_BARCODE_TYPE_MACHINE			("MACHINE")
#define MP_BARCODE_TYPE_GROUP_LOT	    ("GROUP_LOT")


//검사 공정 타입 -> OPER_GRP_2
#define MP_INSP_OPER_TYPE_IQC ("IQC")       //검사공정 타입 IQC
#define MP_INSP_OPER_TYPE_OQC ("OQC")       //검사공정 타입 OQC
#define MP_INSP_OPER_TYPE_PQC ("PQC")       //검사공정 타입 PQC
#define MP_INSP_OPER_TYPE_NON ("NONE")      //검사공정 타입 없음

// 검사 상태
#define MP_CQMS_STATUS_CANCEL			('C')
#define MP_CQMS_STATUS_REQUEST			('Q')
#define MP_CQMS_STATUS_RECEIVE			('R')
#define MP_CQMS_STATUS_HOLD			    ('H')
#define MP_CQMS_STATUS_COMPLETE	    ('S')

//분류 기준 정보
#define MP_CLASS_TYPE_SIZE      ("SIZE")        //size 분류
#define MP_CLASS_TYPE_MAGN      ("MAGN")        //자성 분류
#define MP_CLASS_TYPE_CUP       ("CUP")         //형상 분류
#define MP_CLASS_TYPE_NONE      ("NONE")        //분류 X

//분류 mat type 정보
#define MP_GRIT_TYPE_IMDT      ("IMD-T")        //size 분류
#define MP_GRIT_TYPE_IMDK      ("IMD-KINIK")   //자성 분류
#define MP_GRIT_TYPE_ISD       ("ISD")         //형상 분류

//분류 mat type 정보
#define MP_MAT_ID_IMDT      ("TIMD0000-00001")   //size 분류
#define MP_MAT_ID_IMDK      ("KIMD0000-00001")   //자성 분류
#define MP_MAT_ID_ISD       ("ISD0000-00001")    //형상 분류


//검사 판정 그룹 
#define MP_CQMS_INSP_JUDGE_GROUP_LP        ("INSP_03")   //L/P검사
#define MP_CQMS_INSP_JUDGE_GROUP_ROUND     ("INSP_04")   //ROUND 검사

// 검사 판정 코드
#define MP_CQMS_INSP_JUDGE_FAIL				('F') //불합격
#define MP_CQMS_INSP_JUDGE_PASS				('P') //합격
#define MP_CQMS_INSP_JUDGE_REWORK			('R') //재가공
#define MP_CQMS_INSP_JUDGE_SPECIAL			('S') //특채
#define MP_CQMS_INSP_JUDGE_CHANGE_MATERIAL	('M') //품목변환용

#define MP_CQMS_INSP_JUDGE_A	            ('A') // 절단가능품
#define MP_CQMS_INSP_JUDGE_B	            ('B') // 절단소재용
#define MP_CQMS_INSP_JUDGE_C	            ('C') // SAMPLE
#define MP_CQMS_INSP_JUDGE_D	            ('D') // 부외재고
#define MP_CQMS_INSP_JUDGE_V				('V') // 이거 잘못만든거임 안쓰고있음
#define MP_CQMS_INSP_JUDGE_E				('E') // 품목전환(저함량 Solid)
#define MP_CQMS_INSP_JUDGE_RND_PASS			('U') // RND Pass
#define MP_CQMS_INSP_JUDGE_Z				('Z') // RND Cuttable product
#define MP_CQMS_INSP_JUDGE_W				('W') // special approve(E-cls)
#define MP_CQMS_INSP_JUDGE_I				('I') // R&D Disposal

// 판정 코드
#define MP_OK			("OK") //불합격
#define MP_NG			("NG") //합격

// 생성 이유
#define MP_CREATE_DESC_RETURN_LOT	("RETURN LOT")

// ADAPT 이유
#define MP_ADAPT_REASON_1_MOVE	("MOVE STORE")

// ADAPT 목적지
#define MP_ADAPT_REASON_2_MOVE_PROD		("PROD")
#define MP_ADAPT_REASON_2_MOVE_SHIP		("SHIP")
#define MP_ADAPT_REASON_2_MOVE_RET		("RET")

// 자재 LOT TYPE
#define MP_INV_LOT_TYPE_INV				("INV")
#define MP_INV_LOT_TYPE_SHIP			("SHIP")

// ERP TRAN TYPE ID
#define MP_ERP_TRAN_TYPE_ID_1			("1")	//기타 출고
#define MP_ERP_TRAN_TYPE_ID_2			("2")	//자재 불출
#define MP_ERP_TRAN_TYPE_ID_31			("31")	//출고
#define MP_ERP_TRAN_TYPE_ID_35			("35")	//자재소모, 수량 음수
#define MP_ERP_TRAN_TYPE_ID_40			("40")	//기타 입고
#define MP_ERP_TRAN_TYPE_ID_41			("41")	//위탁 입고
#define MP_ERP_TRAN_TYPE_ID_43			("43")	//자재소모 취소, 수량 양수
#define MP_ERP_TRAN_TYPE_ID_44			("44")	//생산입고(WIP Assembly Completion), P급, 자재변환 공통, 수량 양수
#define MP_ERP_TRAN_TYPE_ID_17			("17")	//생산반환(Wip Assembly Return), P급, 자재변환 공통, 수량 음수
#define MP_ERP_TRAN_TYPE_ID_180			("180")	//이론적인 최소 정상 LOSS

// ERP TRAN TYPE (고정 값)
#define	MP_ERP_TRAN_TYPE_35_COMPONENT_ISSUE		("Work Component Issue")
#define	MP_ERP_TRAN_TYPE_43_COMPONENT_RETURN	("Work Component Return")
#define	MP_ERP_TRAN_TYPE_44_WIP_COMPLETION		("WIP Completion")
#define MP_ERP_TRAN_TYPE_44_ORDLESS_COMPLETION	("Work Orderless Completion")
#define MP_ERP_TRAN_TYPE_17_ORDLESS_RETURN		("Work Orderless Return")

// ERP TRAN STEP ID
#define	MP_ERP_TRAN_STEP_Q				("Queue")					
#define	MP_ERP_TRAN_STEP_T				("To Move")					
#define	MP_ERP_TRAN_STEP_S				("Scrap")					

// ERP TRAN STEP ID
#define	MP_ERP_PO_TYPE_OSP				("OSP")					

// ERP ORDER ID
#define MP_ERP_ORDER_ID_2			    ("2")	//ERP ORDER ID 그릿 분류

//성적서 발번 규칙
#define	MP_SHIP_REPORT_CTM				("SHIP_REPORT_CTM")	
#define	MP_SHIP_REPORT_HM				("SHIP_REPORT_HM")	
#define	MP_SHIP_REPORT_GRIT				("SHIP_REPORT_GRIT")	
#define	MP_SHIP_REPORT_PDC				("SHIP_REPORT_PDC")	

//작업지시 상태 값

#define MP_ORD_STATUS_WAIT				('W')
#define MP_ORD_STATUS_CLOSE				('C')
#define MP_ORD_STATUS_FINISH			('F')
#define MP_ORD_STATUS_OPEN				('O')
#define MP_ORD_STATUS_DELETE_OR_CANCEL	('D')

//ERP외주공정
#define MP_ORD_OPER_OSP	                ("OS01")

//부외재고 창고
#define MP_ORD_OPER_NON_STOCK	        ("GW-GRT-OB")

//SPEC TYPE 값
#define MP_SPEC_TYPE_B                  ('B')   
#define MP_SPEC_TYPE_L                  ('L') 
#define MP_SPEC_TYPE_U                  ('U') 

//자재 LOAD LEVEL
#define MP_LOAD_LEVEL_LOT				("Lot")
#define MP_LOAD_LEVEL_RES				("Resource")
#define MP_LOAD_LEVEL_WO				("Work Order")
#define MP_LOAD_LEVEL_OPER				("Operation")

//이력삭제 tran Comment
#define MP_DEL_TRAN_COMMENT				("Delete Lot History")

//PDA tran Comment
#define MP_PDA_TRAN_COMMENT				("PDA_PROCESS_OUT")

//ETC TYPE
#define MP_ETC_LOT_TYPE_INV				("INV       ")
#define MP_ETC_LOT_TYPE_WIP				("WIP       ")
#define MP_ETC_TYPE_IN					("IN        ")
#define MP_ETC_TYPE_OUT					("OUT       ")


// ORDER JOB TYPE
#define MP_ORD_JOB_TYPE_STANDARD        (1)
#define MP_ORD_JOB_TYPE_NON_STANDARD    (3)


// TOOL 이벤트 
#define MP_TOOL_EVENT_COUNT			    ("TOOL_COUNT")      //TOOL 사용량 증가

// 법인간 출고 입고 LOT 종류
#define MP_SHIP_INPUT_PACK_LOT_ID		    ("PACK_LOT_ID")
#define MP_SHIP_INPUT_ORG_LOT_ID	        ("ORG_LOT_ID")

// MC서버주소
#define MP_SERVER_IP_MC		    ("197.200.16.28")

#endif /* _CUS_DEFINES_H */
