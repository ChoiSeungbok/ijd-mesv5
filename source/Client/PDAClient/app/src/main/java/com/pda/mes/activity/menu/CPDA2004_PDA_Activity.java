package com.pda.mes.activity.menu;

import android.app.DatePickerDialog;
import android.app.TimePickerDialog;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.text.format.DateFormat;
import android.view.View;
import android.widget.AdapterView;
import android.widget.DatePicker;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.TimePicker;

import com.pda.mes.R;
import com.pda.mes.activity.ToolbarActivity;
import com.pda.mes.adapter.CPDA2004_PDA_Adapter;
import com.pda.mes.dialog.ComboBoxDialog;
import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.SQLQueryRequest;
import com.pda.mes.h101.request.inv.InvCheckBarcodeTypeRequest;
import com.pda.mes.h101.request.prod.WipNonOperationRequest;
import com.pda.mes.h101.request.prod.WipViewOperListRequest;
import com.pda.mes.manager.AppLogManager;
import com.pda.mes.manager.AppSettingManager;
import com.pda.mes.manager.SessionManager;
import com.pda.mes.model.DropDownModel;
import com.pda.mes.model.WIPModel;
import com.pda.mes.model.parser.DataModel;
import com.pda.mes.model.parser.VariableModel;
import com.pda.mes.utils.FormatUtil;
import com.pda.mes.utils.ParseH101Xml;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Locale;
import java.util.Map;

import device.common.ScanConst;

public class CPDA2004_PDA_Activity extends ToolbarActivity {
    public static final String TAG = CPDA2004_PDA_Activity.class.getSimpleName();

    private CPDA2004_PDA_Adapter adapter; // 아이템 리스트 어댑터
    private ListView listView; // 아이템 리스트 뷰
    private List<DropDownModel> listAreaModels = new ArrayList<>(); //AREA LIST(사업부)
    private List<DropDownModel> listSubAreaModels = new ArrayList<>(); //SUB AREA LIST(작업장)
    private List<DropDownModel> listOperModels = new ArrayList<>(); //OPER LIST(공정)
    private List<DropDownModel> listMostDownModels = new ArrayList<>(); //MOST DOWN(비가동 우선순위)
    private List<DropDownModel> listDownModels = new ArrayList<>(); //DOWN(비가동)
    private List<WIPModel> listResModels = new ArrayList<>();
    //USER SETUP 정보
    private String sSetupArea = "";
    private String sSetupSubArea = "";
    private String sSetupOper = "";
    private boolean isLoading = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        AppLogManager.printScreenNameLog(TAG, getIntent().getStringExtra(EXTRA_NAME_TITLE));
        setContentView(R.layout.activity_cpda2004, TOOLBAR_TYPE_PUSH);

        adapter = new CPDA2004_PDA_Adapter(this);
        listView = findViewById(R.id.listView);

        adapter.setModels(listResModels);
        listView.setAdapter(adapter);

        findViewById(R.id.subAreaLayout).setEnabled(false);
        findViewById(R.id.operLayout).setEnabled(false);

        //USER CMF 1,2,3(사업부, 작업장, 공정)에 해당하는 값이 들어있는 경우 해당 값을 가져온다.
        checkUserSetup();

        setDateTime();

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int position, long l) {
                resetLogoutTimer(); // 로그아웃 체크 시간 초기화
                int iSelect = 0;

                for(int i = 0 ; i < adapter.getCount() ; i++) {
                    WIPModel model = (WIPModel)adapter.getItem(i);

                    if(i == position) {
                        if(model.isSelected()) {
                            model.setSelected(false);

                        } else if(!model.isSelected()) {
                            model.setSelected(true);
                        }
                    }

                    if(model.isSelected())
                        iSelect++;
                }

                adapter.notifyDataSetChanged();

                setTotalCount();

                //과반수가 안되면
                if(listResModels.size() >= iSelect * 2)
                {
                    ((TextView)findViewById(R.id.allSelect)).setText(R.string.common_word_all);
                }
                else
                {
                    ((TextView)findViewById(R.id.allSelect)).setText(R.string.common_word_unall);
                }
            }
        });
    }

    @Override
    protected void onResume() {
        super.onResume();
        this.registerReceiver(new ScanResultReceiver(), filter);
    }

    //region Button Click Event
    public void onClickArea(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showAreaDialog();
    }

    public void onClickSubArea(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showSubAreaDialog();
    }

    public void onClickOper(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showOperDialog();
    }

    public void onClickAll(View view){
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        selectAllUnAll();
    }

    public void onClickMostDown(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showMostDownDialog();
    }

    public void onClickDown(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showDownDialog();
    }

    public void onClickDownStartDate(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showDownStartDateDialog();
    }

    public void onClickDownStartTime(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showDownStartTimeDialog();
    }

    public void onClickDownEndDate(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showDownEndDateDialog();
    }

    public void onClickDownEndTime(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showDownEndTimeDialog();
    }

    public void onClickDelete(View view){
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        int iSelected = 0;

        for (WIPModel model : listResModels)
        {
            if(model.isSelected())
            {
                iSelected++;
            }
        }

        if(iSelected <= 0)
        {
            showDialog(getString(R.string.alert_message_no_object));
            return;
        }

        showConfirmDialog(getString(R.string.alert_message_delete), new Runnable() {
            @Override
            public void run() {
                requestDelete();
            }
        });
    }

    public void onClickStart(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        int iSelect = 0;
        int iMostDown = 0;
        int iDown = 0;
        String sDownStartDate = ((TextView)findViewById(R.id.downStartDate)).getText().toString();
        String sDownStartTime = ((TextView)findViewById(R.id.downStartTime)).getText().toString();

        //설비선택되었는지 확인
        for (WIPModel model : listResModels)
        {
            if (model.isSelected())
            {
                iSelect ++;
            }
        }

        if(iSelect <= 0)
        {
            showDialog(getString(R.string.alert_message_no_object));
            return;
        }

        //비가동 유형 체크
        for (DropDownModel mostDownModel : listMostDownModels)
        {
            if (mostDownModel.isSelected())
            {
                iMostDown ++;
                break;
            }
        }

        for (DropDownModel downModel : listDownModels)
        {
            if (downModel.isSelected())
            {
                iDown ++;
                break;
            }
        }

        if(iDown + iMostDown != 1)
        {
            showDialog((getString(R.string.common_word_check_down_code)));
            return;
        }

        //시작시간 체크
        if(sDownStartDate.isEmpty() || sDownStartTime.isEmpty())
        {
            showDialog((getString(R.string.common_word_check_time)));
            return;
        }

        showConfirmDialog(getString(R.string.alert_message_start), new Runnable() {
            @Override
            public void run() {
                requestStarting();
            }
        });
    }

    public void onClickEnd(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        int iSelect = 0;
        int iMostDown = 0;
        int iDown = 0;
        String sDownEndDate = ((TextView)findViewById(R.id.downEndDate)).getText().toString();
        String sDownEndTime = ((TextView)findViewById(R.id.downEndTime)).getText().toString();

        //설비선택되었는지 확인
        for (WIPModel model : listResModels)
        {
            if (model.isSelected())
            {
                iSelect ++;
            }
        }

        if(iSelect <= 0)
        {
            showDialog(getString(R.string.alert_message_no_object));
            return;
        }

        //종료시간 체크
        if(sDownEndDate.isEmpty() || sDownEndTime.isEmpty())
        {
            showDialog((getString(R.string.common_word_check_time)));
            return;
        }

        showConfirmDialog(getString(R.string.alert_message_end), new Runnable() {
            @Override
            public void run() {
                requestEnd();
            }
        });
    }

    public void onClickClose(View view){
        this.finish();
    }
    //endregion

    //region Function Event
    public class ScanResultReceiver extends BroadcastReceiver {
        @Override
        public void onReceive(Context context, Intent intent) {
            if (mScanner != null) {
                try {
                    if (ScanConst.INTENT_USERMSG.equals(intent.getAction())) {
                        mScanner.aDecodeGetResult(mDecodeResult.recycle());

                        if((mDecodeResult.toString()).equalsIgnoreCase("READ_FAIL"))
                            return;

                        requestBarcodeType(mDecodeResult.toString());
                    }
                }
                catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }

    private  void requestBarcodeType(final String barcode) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화

        InvCheckBarcodeTypeRequest request = new InvCheckBarcodeTypeRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("BARCODE_ID", "S", barcode);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                Map<String, Object> resultMap = (Map<String, Object>)result;

                switch (resultMap.get("BARCODE_TYPE").toString()) {
                    case H101Const.MACHINE :
                        //설비 선택해준다.
                        setMachine(barcode);
                        break;
                    default:
                        startAlarm();
                        showDialog(getString(R.string.alert_message_error_no_registered_barcode));
                        break;
                }
            }

            @Override
            public void onFailure(Exception exception) {
                showDialog(exception.getMessage());
            }

            @Override
            public void onFinish() {
                hideLoadingDialog();
            }
        });
    }

    public void setMachine(String sBarcode)
    {
        boolean bSame = false;
        int iSelection = 0;

        //설비 데이터 존재하지 않으면 에러
        if(listResModels.size() <= 0)
        {
            showDialog(getString(R.string.common_word_no_machine));
            return;
        }

        for (int i = 0; i< listResModels.size(); i++)
        {
            WIPModel machineModel = listResModels.get(i);

            //같은 설비가 있으면
            if(machineModel.getResCode().equalsIgnoreCase(sBarcode))
            {
                bSame = true;
                if(machineModel.isSelected())
                    machineModel.setSelected(false);
                else
                    machineModel.setSelected(true);

                iSelection = i;
            }
            else
            {
                machineModel.setSelected(false);
            }
        }

        if(!bSame)
        {
            showDialog(getString(R.string.common_word_no_machine));
            return;
        }

        adapter.notifyDataSetChanged();

        setTotalCount();

        listView.setSelection(iSelection);
    }

    private void setTotalCount(){
        int iSelect = 0;

        for (WIPModel model : listResModels)
        {
            if(model.isSelected())
                iSelect++;
        }

        ((TextView) findViewById(R.id.totalCount)).setText(FormatUtil.toNumFormat(iSelect));
    }

    private void init(int iSeq)
    {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화

        int iMethod = iSeq;
        switch (iMethod)
        {
            case 1 :
                //아래 리스트 초기화
                clearListView();
                break;
            case 2 :
                //전부초기화
                clearAllView();
                break;
            case 3 :
                //상위 검색조건 제외 초기화
                clearBottomView();
                break;
            default:
                break;
        }
    }

    private void clearListView() {
        listResModels.clear();
        adapter.notifyDataSetChanged();

        setTotalCount();
    }

    private void clearAllView(){
        ((TextView)findViewById(R.id.area)).setText("");
        ((TextView)findViewById(R.id.subArea)).setText("");
        ((TextView)findViewById(R.id.oper)).setText("");
        ((TextView)findViewById(R.id.mostDownCode)).setText("");
        ((TextView)findViewById(R.id.downCode)).setText("");

        listResModels.clear();
        listAreaModels.clear();
        listSubAreaModels.clear();
        listOperModels.clear();
        listMostDownModels.clear();
        listDownModels.clear();

        adapter.notifyDataSetChanged();

        setTotalCount();

        findViewById(R.id.subAreaLayout).setEnabled(false);
        findViewById(R.id.operLayout).setEnabled(false);

        requestAreaList();
        requsetMostDownCode();
        requestDownCode();

        setDateTime();
    }

    private void clearBottomView(){
        ((TextView)findViewById(R.id.mostDownCode)).setText("");
        ((TextView)findViewById(R.id.downCode)).setText("");

        listResModels.clear();
        listMostDownModels.clear();
        listDownModels.clear();

        adapter.notifyDataSetChanged();

        setTotalCount();

        requsetMostDownCode();
        requestDownCode();

        setDateTime();
    }

    private void checkUserSetup() {
        String requestQuery
                = "SELECT USER_CMF_1 SETUP_AREA, USER_CMF_2 SETUP_SUB_AREA, USER_CMF_3 SETUP_OPER"
                + " FROM MSECUSRDEF"
                + " WHERE 1 = 1"
                + " AND FACTORY = '" + AppSettingManager.getLoginFactory(this) + "'"
                + " AND USER_ID = '" + SessionManager.getUserId(this) + "'";

        SQLQueryRequest request = new SQLQueryRequest(this, requestQuery);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    //세팅이 되어있는 경우에만
                    for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                        sSetupArea = row.get("SETUP_AREA");
                        sSetupSubArea = row.get("SETUP_SUB_AREA");
                        sSetupOper = row.get("SETUP_OPER");
                    }
                }
            }

            @Override
            public void onFailure(Exception exception) {
                showDialog(exception.getMessage());
            }

            @Override
            public void onFinish() {
                hideLoadingDialog();
                requestAreaList();
                requsetMostDownCode();
                requestDownCode();
            }
        });
    }

    private void setupArea(){
        //사업부 세팅 존재하는 경우
        if(sSetupArea != "" && sSetupArea != null)
        {
            for (DropDownModel areaModel : listAreaModels)
            {
                String sArea = areaModel.getId();

                if(sArea.equals(sSetupArea))
                {
                    areaModel.setSelected(true);
                    ((TextView)findViewById(R.id.area)).setText(areaModel.getName());
                    findViewById(R.id.subAreaLayout).setEnabled(true);
                    findViewById(R.id.operLayout).setEnabled(false);
                    //다음 작업장 호출
                    requestSubArea(areaModel.getId());
                    break;
                }
            }
        }
        else
        {
            return;
        }
    }

    private void setupSubArea(){
        //작업장 세팅 존재하는 경우
        if(sSetupSubArea != "" && sSetupSubArea != null)
        {
            String sArea = "";

            for (DropDownModel areaModel : listAreaModels)
            {
                if (areaModel.isSelected())
                {
                    sArea = areaModel.getId();
                    break;
                }
            }

            for (DropDownModel subAreaModel : listSubAreaModels)
            {
                String sSubArea = subAreaModel.getId();

                if(sSubArea.equals(sSetupSubArea))
                {
                    subAreaModel.setSelected(true);
                    ((TextView)findViewById(R.id.subArea)).setText(subAreaModel.getName());
                    findViewById(R.id.operLayout).setEnabled(true);
                    requestOper(sArea, subAreaModel.getId());
                    break;
                }
            }
        }
        else
        {
            return;
        }
    }

    private void setupOper(){
        //작업장 세팅 존재하는 경우
        if(sSetupOper != "" && sSetupOper != null)
        {
            for (DropDownModel operModel : listOperModels)
            {
                String sOper = operModel.getId();

                if(sOper.equals(sSetupOper))
                {
                    operModel.setSelected(true);
                    ((TextView)findViewById(R.id.oper)).setText(operModel.getName());

                    init(1);

                    requestMachine(operModel.getId()); //공정코드로 설비 리스트 받아오기
                    break;
                }
            }
        }
        else
        {
            return;
        }
    }

    private void requestAreaList() {
        String requestQuery
                = "SELECT KEY_1 AREA, DATA_1 AREA_DESC"
                + " FROM MGCMTBLDAT"
                + " WHERE 1 = 1"
                + " AND FACTORY = '" + AppSettingManager.getLoginFactory(this) + "'"
                + " AND TABLE_NAME = \'AREA\'";

        SQLQueryRequest request = new SQLQueryRequest(this, requestQuery);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    setArea((List<Map<String, String>>)resultMap.get("ROWS"));
                }
            }

            @Override
            public void onFailure(Exception exception) {
                showDialog(exception.getMessage());
            }

            @Override
            public void onFinish() {
                hideLoadingDialog();
                setupArea();
            }
        });
    }

    private void setArea(List<Map<String, String>> rows) {
        listAreaModels.clear();

        try {
            for(Map<String, String> row : rows) {
                DropDownModel model = new DropDownModel();
                model.setId(row.get("AREA"));
                model.setName(row.get("AREA_DESC"));

                listAreaModels.add(model);
            }
        } catch(RuntimeException re) {
            throw re;
        } catch(Exception e) {
            AppLogManager.printErrorLog(e.getMessage());
        }
    }

    private void showAreaDialog() {
        ComboBoxDialog dialog = new ComboBoxDialog(this);
        dialog.setDialogTitle(getString(R.string.common_word_area));
        dialog.setData(listAreaModels);
        dialog.setOnSelectItemListener(new ComboBoxDialog.OnSelectItemListener() {
            @Override
            public void onClickItem(DropDownModel model) {
                // area 를 변경하지 않으면 아무것도 하지 않는다.
                String sArea = ((TextView)findViewById(R.id.area)).getText().toString();

                if(sArea.equalsIgnoreCase(model.getName()))
                    return;

                ((TextView)findViewById(R.id.area)).setText(model.getName());

                //사업부 제외 모든 하위 검색조건 초기화
                ((TextView)findViewById(R.id.subArea)).setText("");
                ((TextView)findViewById(R.id.oper)).setText("");

                for (DropDownModel areaModel : listAreaModels)
                {
                    areaModel.setSelected(false);
                }

                model.setSelected(true);

                requestSubArea(model.getId());
                findViewById(R.id.subAreaLayout).setEnabled(true);
                findViewById(R.id.operLayout).setEnabled(false);

                init(1);
            }
        });
        dialog.showDialog();
    }

    private void requestSubArea(String sArea) {
        String requestQuery
                = "SELECT KEY_1 SUB_AREA, DATA_1 SUB_AREA_DESC"
                + " FROM MGCMTBLDAT"
                + " WHERE 1 = 1"
                + " AND FACTORY = '" + AppSettingManager.getLoginFactory(this) + "'"
                + " AND TABLE_NAME = \'SUB_AREA\'"
                + " AND DATA_2 = '" + sArea + "'"; //사업부 조건

        SQLQueryRequest request = new SQLQueryRequest(this, requestQuery);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                listSubAreaModels.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            DropDownModel model = new DropDownModel();
                            model.setId(row.get("SUB_AREA"));
                            model.setName(row.get("SUB_AREA_DESC"));

                            listSubAreaModels.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listSubAreaModels.clear();
                    }
                }
            }

            @Override
            public void onFailure(Exception exception) {
                showDialog(exception.getMessage());
            }

            @Override
            public void onFinish() {
                hideLoadingDialog();
                setupSubArea();
            }
        });
    }

    private void showSubAreaDialog() {
        ComboBoxDialog dialog = new ComboBoxDialog(this);
        dialog.setDialogTitle(getString(R.string.common_word_sub_area));
        dialog.setData(listSubAreaModels);
        dialog.setOnSelectItemListener(new ComboBoxDialog.OnSelectItemListener() {
            @Override
            public void onClickItem(DropDownModel model) {
                String sSubArea = ((TextView)findViewById(R.id.subArea)).getText().toString();
                String sArea = "";

                if(sSubArea.equalsIgnoreCase(model.getName()))
                    return;

                ((TextView)findViewById(R.id.subArea)).setText(model.getName());

                for (DropDownModel subAreaModel : listSubAreaModels)
                {
                    subAreaModel.setSelected(false);
                }

                model.setSelected(true);

                for (DropDownModel areaModel : listAreaModels) {
                    if(areaModel.isSelected())
                    {
                        sArea = areaModel.getId();
                        break;
                    }
                }

                requestOper(sArea, model.getId()); //사업부, 작업장 파라미터로 공정리스트 가져오기
                ((TextView)findViewById(R.id.oper)).setText("");
                findViewById(R.id.operLayout).setEnabled(true);
                init(1);
            }
        });
        dialog.showDialog();
    }

    private void requestOper(String sArea, String sSubArea) {
        WipViewOperListRequest request = new WipViewOperListRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("AREA_ID", "S", sArea);
        request.addParam("SUB_AREA_ID", "S", sSubArea);
        request.addParam("INV_FLAG", "C", " ");
        request.addParam("NEXT_OPER", "S", "");

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                listOperModels.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            DropDownModel model = new DropDownModel();
                            model.setId(row.get("OPER"));
                            model.setName(row.get("OPER_DESC"));

                            listOperModels.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listOperModels.clear();
                    }
                }
            }

            @Override
            public void onFailure(Exception exception) {
                startAlarm();
                showDialog(exception.getMessage());
            }

            @Override
            public void onFinish() {
                hideLoadingDialog();
                setupOper();
            }
        });
    }

    private void showOperDialog() {
        ComboBoxDialog dialog = new ComboBoxDialog(this);
        dialog.setDialogTitle(getString(R.string.common_word_oper_d));
        dialog.setData(listOperModels);
        dialog.setOnSelectItemListener(new ComboBoxDialog.OnSelectItemListener() {
            @Override
            public void onClickItem(DropDownModel model) {
                String sOper = ((TextView)findViewById(R.id.oper)).getText().toString();

                if(sOper.equalsIgnoreCase(model.getName()))
                    return;

                for (DropDownModel OperModel : listOperModels)
                {
                    OperModel.setSelected(false);
                }

                model.setSelected(true);

                ((TextView)findViewById(R.id.oper)).setText(model.getName());

                init(1);

                requestMachine(model.getId()); //공정코드로 설비 리스트 받아오기
            }
        });
        dialog.showDialog();
    }

    private void requsetMostDownCode() {

        String requestQuery
                = "SELECT KEY_1 GRP_1, KEY_2 GRP_2, KEY_3 GRP_3, DATA_1 NOP_DESC"
                + " FROM MGCMTBLDAT"
                + " WHERE 1 = 1"
                + " AND FACTORY = '" + AppSettingManager.getLoginFactory(this) + "'"
                + " AND TABLE_NAME = \'C_NOP_GRP_3\'"
                + " AND DATA_2 = \'Y\'";

        SQLQueryRequest request = new SQLQueryRequest(this, requestQuery);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                listMostDownModels.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            DropDownModel model = new DropDownModel();
                            model.setGrp1(row.get("GRP_1"));
                            model.setGrp2(row.get("GRP_2"));
                            model.setGrp3(row.get("GRP_3"));
                            model.setName(row.get("NOP_DESC"));

                            listMostDownModels.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listMostDownModels.clear();
                    }
                }
            }

            @Override
            public void onFailure(Exception exception) {
                startAlarm();
                showDialog(exception.getMessage());
            }

            @Override
            public void onFinish() {
                hideLoadingDialog();
            }
        });
    }

    private void showMostDownDialog() {
        ComboBoxDialog dialog = new ComboBoxDialog(this);
        dialog.setDialogTitle(getString(R.string.common_word_most_down));
        dialog.setData(listMostDownModels);
        dialog.setOnSelectItemListener(new ComboBoxDialog.OnSelectItemListener() {
            @Override
            public void onClickItem(DropDownModel model) {
                String sNoRun = ((TextView)findViewById(R.id.mostDownCode)).getText().toString();

                if(sNoRun.equalsIgnoreCase(model.getName()))
                    return;

                for (DropDownModel mostDownModel : listMostDownModels)
                {
                    mostDownModel.setSelected(false);
                }

                model.setSelected(true);

                for (DropDownModel downModel : listDownModels)
                {
                    downModel.setSelected(false);
                }

                ((TextView)findViewById(R.id.mostDownCode)).setText(model.getName());
                ((TextView)findViewById(R.id.downCode)).setText("");
            }
        });
        dialog.showDialog();
    }

    private void requestDownCode() {

        String requestQuery
                = "SELECT KEY_1 GRP_1, KEY_2 GRP_2, KEY_3 GRP_3, DATA_1 NOP_DESC"
                + " FROM MGCMTBLDAT"
                + " WHERE 1 = 1"
                + " AND FACTORY = '" + AppSettingManager.getLoginFactory(this) + "'"
                + " AND TABLE_NAME = \'C_NOP_GRP_3\'"
                + " AND DATA_2 = \' \'";

        SQLQueryRequest request = new SQLQueryRequest(this, requestQuery);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                listDownModels.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            DropDownModel model = new DropDownModel();
                            model.setGrp1(row.get("GRP_1"));
                            model.setGrp2(row.get("GRP_2"));
                            model.setGrp3(row.get("GRP_3"));
                            model.setName(row.get("NOP_DESC"));

                            listDownModels.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listDownModels.clear();
                    }
                }
            }

            @Override
            public void onFailure(Exception exception) {
                startAlarm();
                showDialog(exception.getMessage());
            }

            @Override
            public void onFinish() {
                hideLoadingDialog();
            }
        });
    }

    private void showDownDialog() {
        ComboBoxDialog dialog = new ComboBoxDialog(this);
        dialog.setDialogTitle(getString(R.string.common_word_down));
        dialog.setData(listDownModels);
        dialog.setOnSelectItemListener(new ComboBoxDialog.OnSelectItemListener() {
            @Override
            public void onClickItem(DropDownModel model) {
                String sNoRun = ((TextView)findViewById(R.id.downCode)).getText().toString();

                if(sNoRun.equalsIgnoreCase(model.getName()))
                    return;

                for (DropDownModel downModel : listDownModels)
                {
                    downModel.setSelected(false);
                }

                model.setSelected(true);

                for (DropDownModel mostDownModel : listMostDownModels)
                {
                    mostDownModel.setSelected(false);
                }

                ((TextView)findViewById(R.id.downCode)).setText(model.getName());
                ((TextView)findViewById(R.id.mostDownCode)).setText("");
            }
        });
        dialog.showDialog();
    }

    private void requestMachine(String sOper) {

        String requestQuery
                = "SELECT A.RES_ID, A.RES_DESC, NVL(D.DATA_1,'') AS NOP_STATUS"
                + " , C.DOWN_START_TIME, C.DOWN_END_TIME, NVL(C.SEQ , 0) AS SEQ"
                + " FROM MRASRESDEF A"
                + " INNER JOIN MRASRESMFO B ON A.FACTORY = B.FACTORY AND A.RES_ID = B.RES_ID"
                + " LEFT JOIN CWIPDWNSTS C ON A.FACTORY = C.FACTORY AND A.RES_ID = C.RES_ID AND C.DOWN_STATUS = \'S\'"
                + " LEFT JOIN MGCMTBLDAT D ON C.DOWN_CODE = D.KEY_3 AND D.TABLE_NAME =\'C_NOP_GRP_3\'"
                + " WHERE 1 = 1"
                + " AND A.FACTORY = '" + AppSettingManager.getLoginFactory(this) + "'"
                + " AND B.OPER = '" + sOper + "'"
                + " ORDER BY A.RES_ID";

        SQLQueryRequest request = new SQLQueryRequest(this, requestQuery);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                ((TextView)findViewById(R.id.allSelect)).setText(R.string.common_word_all);
                listResModels.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            WIPModel model = new WIPModel();

                            model.setResCode(row.get("RES_ID"));
                            model.setResName(row.get("RES_DESC"));
                            model.setStatus(row.get("NOP_STATUS"));
                            model.setDownStartTime(row.get("DOWN_START_TIME"));
                            model.setDownEndTime(row.get("DOWN_END_TIME"));
                            model.setSeq(Integer.parseInt(row.get("SEQ")));

                            listResModels.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listResModels.clear();
                    }
                }

                adapter.notifyDataSetChanged();

                setTotalCount();
            }

            @Override
            public void onFailure(Exception exception) {
                startAlarm();
                showDialog(exception.getMessage());
            }

            @Override
            public void onFinish() {
                hideLoadingDialog();
            }
        });
    }

    private void showDownStartDateDialog() {
        SimpleDateFormat yearFormat = new SimpleDateFormat("yyyy", Locale.getDefault());
        SimpleDateFormat monthFormat = new SimpleDateFormat("MM", Locale.getDefault());
        SimpleDateFormat dayFormat = new SimpleDateFormat("dd", Locale.getDefault());

        Date date = new Date();

        int iTodayYear = Integer.parseInt(yearFormat.format(date));
        int iTodayMonth = Integer.parseInt(monthFormat.format(date));
        int iTodayDay = Integer.parseInt(dayFormat.format(date));

        DatePickerDialog dialog = new DatePickerDialog(this, downStartDateListener, iTodayYear, iTodayMonth - 1, iTodayDay);
        dialog.show();
    }

    private void selectAllUnAll(){
        //전체 선택_해제 기능

        //리스트가 없으면 동작 안함
        if(listResModels.size() <= 0)
            return;

        String sSeletMode = ((TextView)findViewById(R.id.allSelect)).getText().toString();
        boolean bSelect = false;

        //선택버튼일때 전체 선택
        if(sSeletMode.equalsIgnoreCase(getString(R.string.common_word_all)))
        {
            bSelect = true;
            ((TextView)findViewById(R.id.allSelect)).setText(R.string.common_word_unall);
        }
        else if(sSeletMode.equalsIgnoreCase(getString(R.string.common_word_unall)))
        {
            ((TextView)findViewById(R.id.allSelect)).setText(R.string.common_word_all);
        }

        for (WIPModel model : listResModels)
        {
            model.setSelected(bSelect);
        }

        adapter.notifyDataSetChanged();

        setTotalCount();
    }

    private DatePickerDialog.OnDateSetListener downStartDateListener = new DatePickerDialog.OnDateSetListener() {
        @Override
        public void onDateSet(DatePicker view, int year, int monthOfYear, int dayOfMonth) {
            String sDate = year + "-" + String.format("%02d", monthOfYear + 1) + "-" + String.format("%02d",dayOfMonth); //FORMAT 2020-09-24

            ((TextView)findViewById(R.id.downStartDate)).setText(sDate);
        }
    };

    private void showDownStartTimeDialog(){
        SimpleDateFormat hourFormat = new SimpleDateFormat("HH", Locale.getDefault());
        SimpleDateFormat minuteFormat = new SimpleDateFormat("mm", Locale.getDefault());

        Date date = new Date();

        int iTodayHour = Integer.parseInt(hourFormat.format(date));
        int iTodayMinute = Integer.parseInt(minuteFormat.format(date));

        TimePickerDialog dialog = new TimePickerDialog(this, android.R.style.Theme_Holo_Light_Dialog_NoActionBar,
                                                        downStartTimeListener, iTodayHour, iTodayMinute, DateFormat.is24HourFormat(getBaseContext()));

        dialog.show();
    }

    private TimePickerDialog.OnTimeSetListener downStartTimeListener = new TimePickerDialog.OnTimeSetListener() {
        @Override
        public void onTimeSet(TimePicker view, int hourOfDay, int minute) {
            String sTime = hourOfDay + ":" + String.format("%02d",minute);

            ((TextView)findViewById(R.id.downStartTime)).setText(sTime);
        }
    };

    private void showDownEndDateDialog() {
        SimpleDateFormat yearFormat = new SimpleDateFormat("yyyy", Locale.getDefault());
        SimpleDateFormat monthFormat = new SimpleDateFormat("MM", Locale.getDefault());
        SimpleDateFormat dayFormat = new SimpleDateFormat("dd", Locale.getDefault());

        Date date = new Date();

        int iTodayYear = Integer.parseInt(yearFormat.format(date));
        int iTodayMonth = Integer.parseInt(monthFormat.format(date));
        int iTodayDay = Integer.parseInt(dayFormat.format(date));

        DatePickerDialog dialog = new DatePickerDialog(this, downEndDateListener, iTodayYear, iTodayMonth - 1, iTodayDay);
        dialog.show();
    }

    private DatePickerDialog.OnDateSetListener downEndDateListener = new DatePickerDialog.OnDateSetListener() {
        @Override
        public void onDateSet(DatePicker view, int year, int monthOfYear, int dayOfMonth) {
            String sDate = year + "-" + String.format("%02d", monthOfYear + 1) + "-" + String.format("%02d",dayOfMonth); //FORMAT 2020-09-24

            ((TextView)findViewById(R.id.downEndDate)).setText(sDate);
        }
    };

    private void showDownEndTimeDialog(){
        SimpleDateFormat hourFormat = new SimpleDateFormat("HH", Locale.getDefault());
        SimpleDateFormat minuteFormat = new SimpleDateFormat("mm", Locale.getDefault());

        Date date = new Date();

        int iTodayHour = Integer.parseInt(hourFormat.format(date));
        int iTodayMinute = Integer.parseInt(minuteFormat.format(date));

        TimePickerDialog dialog = new TimePickerDialog(this, android.R.style.Theme_Holo_Light_Dialog_NoActionBar
                                                        , downEndTimeListener, iTodayHour, iTodayMinute, DateFormat.is24HourFormat(getBaseContext()));
        dialog.show();
    }

    private TimePickerDialog.OnTimeSetListener downEndTimeListener = new TimePickerDialog.OnTimeSetListener() {
        @Override
        public void onTimeSet(TimePicker view, int hourOfDay, int minute) {
            String sTime = hourOfDay + ":" + String.format("%02d",minute);

            ((TextView)findViewById(R.id.downEndTime)).setText(sTime);
        }
    };

    private void setDateTime()
    {
        SimpleDateFormat yyyyMMddFormat = new SimpleDateFormat("yyyy-MM-dd", Locale.getDefault());
        SimpleDateFormat HHmmFormat = new SimpleDateFormat("HH:mm", Locale.getDefault());

        Date date = new Date();

        String sDate = yyyyMMddFormat.format(date);
        String sTime = HHmmFormat.format(date);

        ((TextView)findViewById(R.id.downStartDate)).setText(sDate);
        ((TextView)findViewById(R.id.downStartTime)).setText(sTime);
        ((TextView)findViewById(R.id.downEndDate)).setText(sDate);
        ((TextView)findViewById(R.id.downEndTime)).setText(sTime);
    }

    private void requestStarting() {
        if(isLoading)
            return;
        isLoading = true;

        SimpleDateFormat secondFormat = new SimpleDateFormat("ss", Locale.getDefault());

        Date date = new Date();

        String sStartDateTime = ((TextView)findViewById(R.id.downStartDate)).getText().toString().replace("-", "")
                                + ((TextView)findViewById(R.id.downStartTime)).getText().toString().replace(":", "")
                                + secondFormat.format(date);

        String sArea = "";
        String sSubArea = "";
        String sOper = "";
        String sMostDownCode = ((TextView)findViewById(R.id.mostDownCode)).getText().toString();
        DropDownModel pickDownModel = new DropDownModel();

        for (DropDownModel areaModel : listAreaModels) {
            if(areaModel.isSelected())
            {
                sArea = areaModel.getId();
                break;
            }
        }

        if(sArea == null || sArea == "")
        {
            showDialog(getString(R.string.common_word_check_area));
            isLoading = false;
            return;
        }

        for (DropDownModel subAreaModel : listSubAreaModels) {
            if(subAreaModel.isSelected())
            {
                sSubArea = subAreaModel.getId();
                break;
            }
        }

        if(sSubArea == null || sSubArea == "")
        {
            showDialog(getString(R.string.common_word_check_sub_area));
            isLoading = false;
            return;
        }

        for (DropDownModel operModel : listOperModels) {
            if(operModel.isSelected())
            {
                sOper = operModel.getId();
                break;
            }
        }

        if(sOper == null || sOper == "")
        {
            showDialog(getString(R.string.common_word_check_oper));
            isLoading = false;
            return;
        }

        //우선순위 비가동이 비었으면 일반 비가동선택으로 간주
        //선택항목 dropdown model로 copy
        if(sMostDownCode.isEmpty())
        {
            for (DropDownModel downModel : listDownModels) {
                if(downModel.isSelected())
                {
                    pickDownModel = downModel;
                    break;
                }
            }
        }
        else
        {
            for (DropDownModel mostDownModel : listMostDownModels) {
                if(mostDownModel.isSelected())
                {
                    pickDownModel = mostDownModel;
                    break;
                }
            }
        }

        WipNonOperationRequest request = new WipNonOperationRequest(this);

        request.addParam("PROCSTEP", "C", "I");
        request.addParam("AREA_ID", "S", sArea);
        request.addParam("SUB_AREA_ID", "S", sSubArea);
        request.addParam("OPER", "S", sOper);
        request.addParam("DOWN_CODE", "S", pickDownModel.getGrp3());
        request.addParam("DOWN_TYPE_1", "S", pickDownModel.getGrp1());
        request.addParam("DOWN_TYPE_2", "S", pickDownModel.getGrp2());
        request.addParam("DOWN_TYPE_3", "S", pickDownModel.getGrp3());
        request.addParam("DOWN_STATUS", "C", "S");
        request.addParam("DOWN_START_TIME", "S", sStartDateTime);

        for (WIPModel model : listResModels) {
            DataModel data = new DataModel();
            List<VariableModel> columns = new ArrayList<>();

            if(model.isSelected())
            {
                if(model.getStatus() != null && model.getStatus() != "")
                {
                    showDialog(model.getResCode() + " : " + getString(R.string.common_word_check_down_status));
                    isLoading = false;
                    return;
                }

                columns.add(ParseH101Xml.createVariableModel("RES_ID", "S", model.getResCode()));

                data.setD(columns);
                data.setN("RES_TBL");

                request.addListParam(data);
            }
        }

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                isLoading = false;
                showToast(getString(R.string.processing_completed));
                init(3); //아래 초기화 후 설비 재조회

                for(DropDownModel opModel : listOperModels)
                {
                    if(opModel.isSelected())
                    {
                        requestMachine(opModel.getId());
                        break;
                    }
                }
            }

            @Override
            public void onFailure(Exception exception) {
                isLoading = false;
                startAlarm();
                showDialog(exception.getMessage());
            }

            @Override
            public void onFinish() {
                isLoading = false;
                hideLoadingDialog();
            }
        });
    }

    private void requestEnd() {
        if(isLoading)
            return;
        isLoading = true;

        SimpleDateFormat secondFormat = new SimpleDateFormat("ss", Locale.getDefault());

        Date date = new Date();

        String sEndDateTime = ((TextView)findViewById(R.id.downEndDate)).getText().toString().replace("-", "")
                + ((TextView)findViewById(R.id.downEndTime)).getText().toString().replace(":", "")
                + secondFormat.format(date);

        String sArea = "";
        String sSubArea = "";
        String sOper = "";
        String sMostDownCode = ((TextView)findViewById(R.id.mostDownCode)).getText().toString();
        DropDownModel pickDownModel = new DropDownModel();

        for (DropDownModel areaModel : listAreaModels) {
            if(areaModel.isSelected())
            {
                sArea = areaModel.getId();
                break;
            }
        }

        if(sArea == null || sArea == "")
        {
            showDialog(getString(R.string.common_word_check_area));
            isLoading = false;
            return;
        }

        for (DropDownModel subAreaModel : listSubAreaModels) {
            if(subAreaModel.isSelected())
            {
                sSubArea = subAreaModel.getId();
                break;
            }
        }

        if(sSubArea == null || sSubArea == "")
        {
            showDialog(getString(R.string.common_word_check_sub_area));
            isLoading = false;
            return;
        }

        for (DropDownModel operModel : listOperModels) {
            if(operModel.isSelected())
            {
                sOper = operModel.getId();
                break;
            }
        }

        if(sOper == null || sOper == "")
        {
            isLoading = false;
            showDialog(getString(R.string.common_word_check_oper));
            return;
        }

        //우선순위 비가동이 비었으면 일반 비가동선택으로 간주
        //선택항목 dropdown model로 copy
        if(sMostDownCode.isEmpty())
        {
            for (DropDownModel downModel : listDownModels) {
                if(downModel.isSelected())
                {
                    pickDownModel = downModel;
                    break;
                }
            }
        }
        else
        {
            for (DropDownModel mostDownModel : listMostDownModels) {
                if(mostDownModel.isSelected())
                {
                    pickDownModel = mostDownModel;
                    break;
                }
            }
        }

        WipNonOperationRequest request = new WipNonOperationRequest(this);

        request.addParam("PROCSTEP", "C", "U");
        request.addParam("AREA_ID", "S", sArea);
        request.addParam("SUB_AREA_ID", "S", sSubArea);
        request.addParam("OPER", "S", sOper);
        request.addParam("DOWN_STATUS", "C", "E");
        request.addParam("DOWN_END_TIME", "S", sEndDateTime);

        for (WIPModel model : listResModels) {
            DataModel data = new DataModel();
            List<VariableModel> columns = new ArrayList<>();

            if(model.isSelected())
            {
                if(model.getStatus() == null || model.getStatus() == "")
                {
                    showDialog(model.getResCode() + " : " + getString(R.string.common_word_check_down_status));
                    isLoading = false;
                    return;
                }

                //시작시간이 종료시간보다 앞설때 에러
                if(Double.parseDouble(model.getDownStartTime()) > Double.parseDouble(sEndDateTime))
                {
                    showDialog(model.getResCode() + " : " + getString(R.string.common_word_check_down_end_time));
                    isLoading = false;
                    return;
                }

                columns.add(ParseH101Xml.createVariableModel("RES_ID", "S", model.getResCode()));
                columns.add(ParseH101Xml.createVariableModel("SEQ", "I4", String.valueOf(model.getSeq())));

                data.setD(columns);
                data.setN("RES_TBL");

                request.addListParam(data);
            }
        }

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                isLoading = false;
                showToast(getString(R.string.processing_completed));
                init(3);

                for(DropDownModel opModel : listOperModels)
                {
                    if(opModel.isSelected())
                    {
                        requestMachine(opModel.getId());
                        break;
                    }
                }
            }

            @Override
            public void onFailure(Exception exception) {
                isLoading = false;
                startAlarm();
                showDialog(exception.getMessage());
            }

            @Override
            public void onFinish() {
                isLoading = false;
                hideLoadingDialog();
            }
        });
    }

    private void requestDelete(){
        if(isLoading)
            return;
        isLoading = true;

        WipNonOperationRequest request = new WipNonOperationRequest(this);

        request.addParam("PROCSTEP", "C", "D");

        for (WIPModel model : listResModels) {
            DataModel data = new DataModel();
            List<VariableModel> columns = new ArrayList<>();

            if(model.isSelected())
            {
                if(model.getStatus() == null || model.getStatus() == "")
                {
                    showDialog(model.getResCode() + " : " + getString(R.string.common_word_check_down_status));
                    isLoading = false;
                    return;
                }

                columns.add(ParseH101Xml.createVariableModel("RES_ID", "S", model.getResCode()));
                columns.add(ParseH101Xml.createVariableModel("SEQ", "I4", String.valueOf(model.getSeq())));

                data.setD(columns);
                data.setN("RES_TBL");

                request.addListParam(data);
            }
        }

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                isLoading = false;
                showToast(getString(R.string.processing_completed));
                init(3);

                for(DropDownModel opModel : listOperModels)
                {
                    if(opModel.isSelected())
                    {
                        requestMachine(opModel.getId());
                        break;
                    }
                }
            }

            @Override
            public void onFailure(Exception exception) {
                isLoading = false;
                startAlarm();
                showDialog(exception.getMessage());
            }

            @Override
            public void onFinish() {
                isLoading = false;
                hideLoadingDialog();
            }
        });
    }
    //endregion
}
