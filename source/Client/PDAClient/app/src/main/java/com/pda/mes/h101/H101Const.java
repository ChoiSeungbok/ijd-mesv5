package com.pda.mes.h101;

import com.pda.mes.manager.AppSettingManager;

public class H101Const {
    /**
     * Server Address
     */
    public static final String SERVER_IJ = "197.200.11.43:10101";

    public static final String SERVER_IJ_TEST = "197.200.1.92:10101";

    public static final String SERVER_TEST = "197.200.51.45:10101";

    public static final String DOWNLOAD_SERVER_IP_IJ = "197.200.11.43:81";

    public static final String DOWNLOAD_SERVER_IP_IJ_TEST = "197.200.1.92";

    public static final String DOWNLOAD_SERVER_IP_TEST = "197.200.1.92";

    public static final String APK_DOWNLOAD_URL = "http://%s/MESPDAClient_v%s.apk";

    public static final String PROGRAM_ID = "MESPDAClient";

    /**
     * Service name
     */

    public static final String SQL_QUERY_REQUEST = "BAS_SQL_Query";

    public static final String MENU_GROUP = "SEC_View_GrpFunc_List";

    /**
     * Service CUS_INV
     */
    public static final String CUS_INV_CHECK_BARCODE_TYPE = "CUS_INV_Check_Barcode_Type";
    public static final String CUS_INV_VIEW_ISSUE_REQUEST = "CUS_INV_View_Issue_Request";
    public static final String CUS_INV_VIEW_ISSUE_REQUEST_LOT = "CUS_INV_View_Issue_Request_Lot";
    public static final String CUS_INV_VALIDATION_ISSUE_REQUEST_LOT = "CUS_INV_Validation_Issue_Request_Lot";
    public static final String CUS_INV_CREATE_ISSUE_REQUEST_LOT = "CUS_INV_Create_Issue_Request_Lot";
    public static final String CUS_INV_DELETE_ISSUE_REQUEST_LOT = "CUS_INV_Delete_Issue_Request_Lot";
    public static final String CUS_INV_CONFIRM_ISSUE_REQUEST = "CUS_INV_Confirm_Issue_Request";
    public static final String CUS_INV_RECEIVE_ISSUE_REQUEST_LOT = "CUS_INV_Receive_Issue_Request_Lot";
    public static final String CUS_INV_VALIDATION_DLV_LOT = "CUS_INV_Validation_Dlv_Lot";
    public static final String CUS_INV_CREATE_LOT = "CUS_INV_Create_Lot";
    public static final String CUS_INV_VALIDATION_MOVE_LOT = "CUS_INV_Validation_Move_Lot";
    public static final String CUS_INV_MOVE_LOT = "CUS_INV_Move_Lot";
    public static final String CUS_INV_VIEW_LOT_INFO = "CUS_INV_View_Lot_Info";
    public static final String CUS_INV_MERGE_LOT = "CUS_INV_Merge_Lot";
    public static final String CUS_INV_HOLD_LOT = "CUS_INV_Hold_Lot";
    public static final String CUS_INV_RELEASE_LOT = "CUS_INV_Release_Lot";
    public static final String CUS_INV_VALIDATION_ETC_OUT_LOT = "CUS_INV_Validation_Etc_Out_Lot";
    public static final String CUS_INV_TERMINATE_LOT = "CUS_INV_Terminate_Lot";
    public static final String CUS_INV_VIEW_LOT_LIST_BY_OPER = "CUS_INV_View_Lot_List_By_Oper";
    public static final String CUS_INV_VIEW_PO_LIST = "CUS_INV_View_PO_List";
    public static final String CUS_INV_VIEW_MOVE_LOT = "CUS_INV_View_Move_Lot";
    public static final String CUS_INV_MOVE_LOT_ORDER = "CUS_INV_Move_Lot_Order";

    /**
     * Service CUS_WIP
     */
    public static final String CUS_WIP_VIEW_OPER_LIST = "CUS_WIP_View_Oper_List";
    public static final String CUS_WIP_VIEW_LOT_INFO = "CUS_WIP_View_Lot_Info";
    public static final String CUS_WIP_MULTI_PROCESS_LOT = "CUS_WIP_Multi_Process_Lot";
    public static final String CUS_WIP_VIEW_WORKER_LIST = "CUS_WIP_View_Worker_List";
    public static final String CUS_WIP_VIEW_OPER_LOSS = "CUS_WIP_View_Oper_Loss";
    public static final String CUS_WIP_UPDATE_LOT_LOSS = "CUS_WIP_Update_Lot_Loss";
    public static final String CUS_WIP_VIEW_MATERIAL_LIST = "CUS_WIP_View_Material_List";
    public static final String CUS_WIP_MOVE_LOT_ORDER = "CUS_WIP_Move_Lot_Order";
    public static final String CUS_WIP_NON_OPERATION = "CUS_WIP_non_operation";
    public static final String CUS_WIP_VALIDATION_ETC_OUT_LOT = "CUS_WIP_Validation_Etc_Out_Lot";
    public static final String CUS_WIP_ETC_OUT_LOT = "CUS_WIP_Etc_Out_Lot";

    /**
     * Service CUS_SHP
     */
    public static final String CUS_SHP_VIEW_ORDER_LIST = "CUS_SHP_View_Order_List";
    public static final String CUS_SHP_VALIDATION_SHIP_LOT = "CUS_SHP_Validation_Ship_Lot";
    public static final String CUS_SHP_SHIP_LOT = "CUS_SHP_Ship_Lot";
    public static final String CUS_SHP_CHECK_SHIP_LOT = "CUS_SHP_Check_Ship_Lot";

    /**
     * Service CUS_RAS
     */
    public static final String CUS_RAS_VIEW_RESOURCE_LIST = "CUS_RAS_View_Resource_List";

    /**
     * Service CUS_WIP
     * 2021-01-20 BookMark
     */
    public static final String SEC_UPDATE_FAVORITES = "SEC_Update_Favorites";


    /**
     * Module name
     */

    public static final String MODULE_NAME_CUS_INV = "CUS_INV";

    public static final String MODULE_NAME_CUS_WIP = "CUS_WIP";

    public static final String MODULE_NAME_CUS_RAS = "CUS_RAS";

    public static final String MODULE_NAME_CUS_SHP = "CUS_SHP";

    public static final String MODULE_NAME_BAS = "BAS";

    public static final String MODULE_NAME_SEC = "SEC";

    /**
     * Prod Barcode Type
     * INV_LOT 자재 LOT
     * DLV_LOT 입하 LOT
     * ISSUE_REQUEST 출하요청 지시번호
     * LOT MWIPLOSTS LOT
     * MOVE_REQUEST 이동지시번호
     * BOX BOX
     * FINAL_BOX FINAL_BOX
     */
    public static final String INV_LOT = "INV_LOT";
    public static final String DLV_LOT = "DLV_LOT";
    public static final String ISSUE_REQUEST = "ISSUE_REQUEST";
    public static final String LOT = "LOT";
    public static final String MOVE_REQUEST = "MOVE_REQUEST";
    public static final String BOX = "BOX";
    public static final String FINAL_BOX = "FINAL_BOX";
    public static final String MACHINE = "MACHINE";

    /**
     * Key name
     */

    public static final String KEY_STATUSVALUE = "STATUSVALUE";

    public static final String KEY_MESSAGE = "MSG";

    public static final String KEY_RESULT_CODE = "MSGCODE";

    public static final String KEY_USER_DESC = "USER_DESC";

    public static final String KEY_USER_AREA_ID = "USER_CMF_1";

    public static final String INV_LOT_ID = "INV_LOT_ID";

    public static final String MAT_ID = "MAT_ID";

    public static final String MAT_DESC = "MAT_DESC";

    public static final String UNIT = "UNIT";

    public static final String QTY = "QTY";

    public static final String QTY_1 = "QTY_1";

    public static final String OPER = "OPER";

    public static final String OPER_DESC = "OPER_DESC";

    public static final String RES_ID = "RES_ID";

    public static final String RES_DESC = "RES_DESC";

    public static final String INSP_ID = "INSP_ID";

    public static final String ORDER_ID = "ORDER_ID";

    public static final String LOT_ID = "LOT_ID";

    public static final String AREA_ID = "AREA_ID";

    public static final String AREA_DESC = "AREA_DESC";

    public static final String SUB_AREA_DESC = "SUB_AREA_DESC";

    public static final String FROM_SUB_AREA_DESC = "FROM_SUB_AREA_DESC";

    public static final String FROM_OPER_DESC = "FROM_OPER_DESC";

    public static final String TO_SUB_AREA_DESC = "TO_SUB_AREA_DESC";

    public static final String TO_OPER_DESC = "TO_OPER_DESC";

    public static final String MOVE_STATUS = "MOVE_STATUSDESC";

    public static final String INSP_RESULT_FLAG = "INSP_RESULT_FLAG";

    public static final String INSP_REQ_TIME = "INSP_REQ_TIME";

    public static final String INSP_USER_ID = "INSP_USER_ID";

    public static final String KEY_USER_GROUP_ID = "SEC_GRP_ID";

    public static final String LOT_STATUS = "LOT_STATUS";

    public static final String KEY_SERVER_APP_VERSION = "SERVER_VERSION";

    /**
     * Error Code
     */
    public static final String RESULT_CODE_NEED_POSITIVE_NUMBER = "WIP-0041";

    public static final String RESULT_CODE_NEED_NEGATIVE_NUMBER = "COM-0217";

    public static final String RESULT_CODE_NEED_NUMBER = "COM-0221";

    /**
     * H101 통신을 위한 서버별 ip 설정
     *
     * @param currentServerType
     * @return
     */
    public static String getBaseUrl(int currentServerType) {

        String baseUrl;

        switch(currentServerType) {
            default:
            case AppSettingManager.TYPE_SERVER_IJ:
                baseUrl = H101Const.SERVER_IJ;
                break;
            case AppSettingManager.TYPE_SERVER_IJ_TEST:
                baseUrl = H101Const.SERVER_IJ_TEST;
                break;
            case AppSettingManager.TYPE_SERVER_TEST:
                baseUrl = H101Const.SERVER_TEST;
                break;
        }

        return baseUrl;
    }

    /**
     * 다운로드 서버별 ip 설정
     *
     * @param currentServerType
     * @return
     */
    public static String getDownloadUrl(int currentServerType, String newVersionName) {

        String serverIp;

        switch(currentServerType) {
            default:
            case AppSettingManager.TYPE_SERVER_IJ:
                serverIp = H101Const.DOWNLOAD_SERVER_IP_IJ;
                break;
            case AppSettingManager.TYPE_SERVER_IJ_TEST:
                serverIp = H101Const.DOWNLOAD_SERVER_IP_IJ_TEST;
                break;
            case AppSettingManager.TYPE_SERVER_TEST:
                serverIp = H101Const.DOWNLOAD_SERVER_IP_TEST;
                break;
        }

        return String.format(APK_DOWNLOAD_URL, serverIp, newVersionName);
    }
}
