namespace CUS_COM
{
    public sealed class CSGC
    {        
        public const int MAX_HIST_SEQ = 99999;

        public enum CHECK
        {
            NONE        = 0,
            VIEW        = 1,              
            SAVE        = 2,
            CONFIRM     = 3,
            CANCEL      = 4,
            ALL         = 5,
            ADD         = 6,
            DELETE      = 7,
            START       = 8,
            END         = 9,
            PRINT       = 10            
        };

        public enum SUB_AREA
        {
            DESC,
            AREA,
            FMB,
            ERP_SUB_AREA,
            BLENDING_YN
        };

        // 원자재 유형
        public const string CP_RAW_MATERIAL = "RAW_MATERIAL";                           //RAW_MATERIAL 원자재

        //설비 종류 PRESS
        public const string CP_RESOURCE_GROUP_PRESS = "E002";                           // 설비 종류 : PRESS

        //사업부 코드 시작
        public const string CP_AREA_GRT = "GRT";                                        //Grit 사업부
        public const string CP_AREA_CTM = "CTM";                                        //CTM 사업부
        public const string CP_AREA_PDC = "PDC";                                        //PDC 사업부
        public const string CP_AREA_HM = "HM";                                          //HM 사업부
        //사업부 코드 종료

        //grit 분류 타입
        public const string CP_CLASS_SIZE = "SIZE";                                     //그릿 분류 타입 SIZE
        public const string CP_CLASS_MAGN = "MAGN";                                     //그릿 분류 타입 자성
        public const string CP_CLASS_CUP = "CUP";                                       //그릿 분류 타입 형상
        public const string CP_CLASS_NONE = "NONE";                                     //그릿 분류 타입 없음
        //grit 분류 타입 종료

        public const string CP_MAPPING_GROUP_D12 = "D12";                               //MAPPING 그룹 D12
        public const string CP_MAPPING_GROUP_CELL = "CELL";                             //MAPPING 그룹 CELL
        public const string CP_WORK_TYPE_PROC = "PROC";                                 //작업구분 완료
        public const string CP_WORK_TYPE_WAIT = "WAIT";                                 //작업구분 시작
        public const string CP_TOOL_EVENT_RES_INPUT = "RES_INPUT";                      //툴 이벤트 장착
        public const string CP_TOOL_EVENT_RES_OUTPUT = "RES_OUTPUT";                    //툴 이벤트 해제
        public const string CP_MAT_TYPE_STORED_GOODS = "STORED_GOODS";                  //금형 자재
        public const string CP_REQ_STATUS_REQUEST = "REQUEST";                          //요청상태 요청

        //창고 유형
        public const string CP_OPER_GRP_INV = "INV";                                    //자재
        public const string CP_OPER_GRP_OPER = "OPER";                                  //생산
        public const string CP_OPER_GRP_PROD = "PROD";                                  //완제품
        public const string CP_OPER_GRP_SHIP = "SHIP";                                  //출하대기
        public const string CP_OPER_GRP_RET = "RET";                                    //고객반품
        public const string CP_OPER_GRP_RET_R = "RET_R";                                //자재과 반품
        public const string CP_OPER_GRP_CONSIGNMENT = "CONSIGNMENT";                    //위탁
        public const string CP_OPER_GRP_LOSS = "LOSS";                                  //부의재고
        public const string CP_OPER_GRP_INSP = "INSP";                                  //검사
        public const string CP_OPER_GRP_OSP = "OSP";                                    //외주
        public const string CP_OPER_GRP_MOLD = "MOLD";                                  //금형

        //라벨 유형
        public const string CP_LABEL_TYPE_SHIP = "SHIP";                                //출하
        public const string CP_LABEL_TYPE_INV = "INV";                                  //자재
        public const string CP_LABEL_TYPE_OPER = "OPER";                                //생산
        
        //자재 투입 유형
        public const string CP_MAT_INPUT_TYPE_ALL = "ALL";                              //전체 투입
        public const string CP_MAT_INPUT_TYPE_BOM = "BOM";                              //BOM단위 투입
        public const string CP_MAT_INPUT_TYPE_LOT = "LOT";                              //LOT단위 투입

        //성적서 타입
        public const string CP_SHIP_REPORT_CMT_01 = "CTM_01";                              //CTM 타입 A
        public const string CP_SHIP_REPORT_CMT_02 = "CTM_02";                              //CTM 타입 B
        public const string CP_SHIP_REPORT_CMT_03 = "CTM_03";                              //CTM MAPAL 성적서
        public const string CP_SHIP_REPORT_CMT_04 = "CTM_04";                              //CTM 상해이화성적서

        //포장 상태
        public const string CP_PACK_STATUS_WAIT = "WAIT";                              //WAIT
        public const string CP_PACK_STATUS_WAIT_DESC = "대기";                         //대기

        //lot type
        public const char CP_LOT_TYPE_P = 'P';                                          //생산품
        public const char CP_LOT_TYPE_T = 'T';                                          //테스트품

        //CREATE CODE
        public const string CP_CREATE_CODE_PROD = "PROD";                               //Product Lot
        public const string CP_CREATE_CODE_RND = "RND";                                 //R&D Lot
        public const string CP_CREATE_CODE_SAMPLE = "SAMPLE";                           //Sample Lot
        public const string CP_CREATE_CODE_TEST = "TEST";                               //Test Lot

        #region "GCM Table Name"

        //Custom GCM Table
        public const string CP_GCM_WORKER_GROUP= "C_WORKER_GROUP";                      //작업조
        public const string CP_GCM_SPARE_LOCATION_1 = "C_SPARE_LOCATION_1";             //스페어파트 적재위치
        public const string CP_GCM_SPARE_LOCATION_2 = "C_SPARE_LOCATION_2";             //스페어파트 행/열 순서
        public const string CP_GCM_REPAIR_TYPE = "C_REPAIR_TYPE";                       //수리 유형
        public const string CP_GCM_REPAIR_STATUS = "C_REPAIR_STATUS";                   //수리진행상태
        public const string CP_GCM_BREAK_CLASS = "C_BREAK_CLASS";                       //고장 분류
        public const string CP_GCM_BREAK_PART = "C_BREAK_PART";                         //고장 부위
        public const string CP_GCM_BREAK_TYPE = "C_BREAK_TYPE";                         //고장 유형
        public const string CP_GCM_GRADE = "C_GRADE";                                   //등급
        public const string CP_GCM_WEEKEND_FLAG = "C_WEEKEND_FLAG";                     //주말 여부
        public const string CP_GCM_DEPT_CODE = "C_DEPT_CODE";                           //부서정보
        public const string CP_GCM_OPER_LOSS = "C_OPER_LOSS";                           //공정 불량
        public const string CP_FILE_TYPE = "C_FILE_TYPE";                               //파일 타입
        public const string CP_GCM_VENDOR = "C_VENDOR";                                 //협력사 ID
        public const string CP_GCM_INV_HOLD_CODE = "C_INV_HOLD_CODE";                   //잠금코드
        public const string CP_GCM_INV_RELEASE_CODE = "C_INV_RELEASE_CODE";             //잠금해제코드
        public const string CP_GCM_SPARE_MAT_ID = "C_SPARE_MAT_ID";                     //스페어 품명
        public const string CP_GCM_SPARE_SPEC_ID = "C_SPARE_SPEC_ID";                   //스페어 사용규격
        public const string CP_GCM_SPARE_TYPE = "C_SPARE_TYPE";                         //스페어 종류
        public const string CP_GCM_MANUFACTURE_CODE = "C_MANUFACTURE_CODE";             //제조사
        public const string CP_GCM_AREA_OPTION = "C_AREA_OPTION";                       //사업부별 옵션
        public const string CP_GCM_CAR = "C_CAR";                                       //카
        public const string CP_GCM_INV_INPUT_TYPE = "C_INV_INPUT_TYPE";                 //자재 투입 방식
        public const string CP_GCM_MOLD_TYPE = "C_MOLD_TYPE";                           //금형 타입
        public const string CP_GCM_MAPPING_GROUP_TYPE = "C_MAPPING_GROUP_TYPE";         //맵핑그룹 타입
        public const string CP_GCM_WORK_TYPE = "C_WORK_TYPE";                           //작업구분
        public const string CP_GCM_CTM_MAT_GROUP = "C_CTM_MAT_GROUP";                   //CTM품목군
        public const string CP_GCM_OPER_OPTION = "C_OPER_OPTION";                       //공정옵션
        public const string CP_GCM_PAN = "C_PAN";                                       //상판/하판
        public const string CP_GCM_DSP_REQ_STATUS = "C_DSP_REQ_STATUS";                 //금형 폐기 요청 상태
        public const string CP_GCM_OPER_DATA = "C_OPER_DATA";                           //공정별 데이터
        public const string CP_GCM_ETC_IN_TYPE = "C_ETC_IN_TYPE";                       //기타 입고 유형
        public const string CP_GCM_ETC_OUT_TYPE = "C_ETC_OUT_TYPE";                     //기타 출고 유형
        public const string CP_GCM_INSP_JUDGE_FLAG = "C_INSP_JUDGE_FLAG";               // 검사판정 FLAG
        public const string CP_GCM_INSP_JUDGE_TYPE = "C_INSP_JUDGE_TYPE";               // 검사판정 TYPE
        public const string CP_GCM_INSP_STATUS = "C_INSP_STATUS";                       // 검사 상태
        public const string CP_GCM_INSP_TYPE = "C_INSP_TYPE";                           // 검사 TYPE
        public const string CP_GCM_INSP_TYPE_NOT_IQC = "C_INSP_TYPE_NOT_IQC";           // 검사 TYPE(Exceipt IQC)
        public const string CP_GCM_GRIT_CLASS = "C_GRIT_CLASS";                         // GRIT 분류정보
        public const string CP_GCM_GRIT_CLASS_JUDGE = "C_GRIT_CLASS_JUDGE";             // GRIT 분류정보
        public const string CP_GCM_INSP_COUNT = "C_INSP_COUNT";                         //검사 차수 설정
        public const string CP_GCM_CUSTOMER = "C_CUSTOMER";                             //고객사
        public const string CP_GCM_CUPCELL_OPER = "C_CUPCELL_OPER";                     //컵셀공정
        public const string CP_GCM_RECIPE_INFO = "C_RECIPE_INFO";                       //설비 레시피 항목
        public const string CP_GCM_TRANS_RES_INFO = "C_TRANS_RES_INFO";                 //설비 레시피 전송 정보
        public const string CP_GCM_INSP_SHIP_REPORT = "C_INSP_SHIP_REPORT";                 //출하성적서 타입
        public const string CP_GCM_INSP_ANALYZER = "C_INSP_ANALYZER";                 //MP ANALYZER
        public const string CP_GCM_SHIP_STATUS = "C_SHIP_STATUS";                       //물류 오더 상태
        public const string CP_GCM_DELIVERY = "C_DELIVERY";                             //납품처 정보(Delivery Info by Packing Order)
        public const string CP_GCM_MAT_GRADE = "C_MAT_GRADE";                           //Material Grade
        public const string CP_GCM_LOAD_LEVEL = "C_LOAD_LEVEL";                         //Material Load Level
        public const string CP_GCM_PROD_REG_TYPE = "C_PROD_REG_TYPE";                   //목표생산성 등록 타입 P:생산성, Y:수율
        public const string CP_GCM_PROD_CLASS_TYPE = "C_PROD_CLASS_TYPE";                   //목표생산성 월/주차 구분
        public const string CP_GCM_SIZE_LIST = "C_SIZE_LIST";                           //사이즈 리스트
        public const string CP_GCM_ADD_LOT_CHAR = "C_ADD_LOT_CHAR";                     //LOT ID 추가 글자
        public const string CP_GCM_ETC_TYPE = "C_ETC_TYPE";                             // 기타 입출고 타입
        public const string CP_GCM_SHIP_ORDER_STATUS = "C_SHIP_ORDER_STATUS";           //출하지시 상태
        public const string CP_GCM_DLV_LOT_STATUS = "C_DLV_LOT_STATUS";                 //입하 LOT 상태
        public const string CP_GCM_MOVE_OPTION = "C_MOVE_OPTION";                       //이동 출고 옵션

        #endregion



        #region "label name"

        public const string CP_LABEL_MOVE   = "prd702q";                     //창고 이동 출고증
        public const string CP_LABEL_MOVE_1 = "move_order";                  //창고 이동 출고증
        public const string CP_LABEL_MOVE_2 = "move_order_multi";            //창고 이동 출고증(CTM press)
        public const string CP_LABEL_TCARD  = "t_card";                      //tcard
        public const string CP_LABEL_T_BLANDING = "t_card_b";                //블랜딩 tcard
        public const string CP_LABEL_INV     = "mtl100p";                     //자재 라벨 (외주 입고에서도 사용)

        #endregion

    }
}
