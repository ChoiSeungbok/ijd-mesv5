package com.pda.mes.activity.menu;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.AdapterView;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;

import com.pda.mes.R;
import com.pda.mes.activity.ToolbarActivity;
import com.pda.mes.adapter.CPDA2002_PDA_Adapter;
import com.pda.mes.dialog.ComboBoxDialog;
import com.pda.mes.dialog.InputDialog;
import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.SQLQueryRequest;
import com.pda.mes.h101.request.prod.RasViewResourceListRequest;
import com.pda.mes.h101.request.prod.WipMultiProcessLotRequest;
import com.pda.mes.h101.request.prod.WipViewLotInfoRequest;
import com.pda.mes.h101.request.prod.WipViewOperListRequest;
import com.pda.mes.h101.request.prod.WipViewWorkerListRequest;
import com.pda.mes.h101.request.inv.InvCheckBarcodeTypeRequest;
import com.pda.mes.manager.AppLogManager;
import com.pda.mes.manager.AppSettingManager;
import com.pda.mes.manager.SessionManager;
import com.pda.mes.model.DropDownModel;
import com.pda.mes.model.WIPModel;
import com.pda.mes.model.parser.DataModel;
import com.pda.mes.model.parser.VariableModel;
import com.pda.mes.utils.FormatUtil;
import com.pda.mes.utils.ParseH101Xml;
import com.pda.mes.utils.StringUtil;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import device.common.ScanConst;

public class CPDA2002_PDA_Activity extends ToolbarActivity {
    public static final String TAG = CPDA2002_PDA_Activity.class.getSimpleName();

    private CPDA2002_PDA_Adapter adapter; // 아이템 리스트 어댑터
    private ListView listView; // 아이템 리스트 뷰
    private List<DropDownModel> listAreaModels = new ArrayList<>(); //AREA LIST(사업부)
    private List<DropDownModel> listSubAreaModels = new ArrayList<>(); //SUB AREA LIST(작업장)
    private List<DropDownModel> listOperModels = new ArrayList<>(); //OPER LIST(공정)
    private List<DropDownModel> listMachineModels = new ArrayList<>(); //MACHINE LIST(설비)
    private List<DropDownModel> listWorkShiftModels = new ArrayList<>(); //WORK SHIFT LIST(근무조)
    private List<DropDownModel> listWorkerModels = new ArrayList<>(); //WORKER LIST(작업자)
    private List<DropDownModel> listToOperModels = new ArrayList<>(); //TO OPER LIST
    private List<WIPModel> listLotModels = new ArrayList<>();
    private List<String> listLot = new ArrayList<>();//중복제거를 위한 LOT확인
    //USER SETUP 정보
    private String sSetupArea = "";
    private String sSetupSubArea = "";
    private String sSetupOper = "";
    private boolean isLoading = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        AppLogManager.printScreenNameLog(TAG, getIntent().getStringExtra(EXTRA_NAME_TITLE));
        setContentView(R.layout.activity_cpda2002, TOOLBAR_TYPE_PUSH);

        adapter = new CPDA2002_PDA_Adapter(this);
        listView = findViewById(R.id.listView);

        adapter.setModels(listLotModels);
        listView.setAdapter(adapter);

        findViewById(R.id.subAreaLayout).setEnabled(false);
        findViewById(R.id.operLayout).setEnabled(false);
        findViewById(R.id.machineLayout).setEnabled(false);
        findViewById(R.id.workShiftLayout).setEnabled(false);
        findViewById(R.id.workerLayout).setEnabled(false);
        findViewById(R.id.toOperLayout).setEnabled(false);

        //USER CMF 1,2,3(사업부, 작업장, 공정)에 해당하는 값이 들어있는 경우 해당 값을 가져온다.
        checkUserSetup();

        requestWorkShiftList();

        adapter.setOnClickCellListener(new CPDA2002_PDA_Adapter.OnClickCellListener() {

            @Override
            public void onClickInput(WIPModel model) {
                inputValue(model);
            }

        });

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int position, long l) {
                resetLogoutTimer(); // 로그아웃 체크 시간 초기화

                for(int i = 0 ; i < adapter.getCount() ; i++) {
                    WIPModel model = (WIPModel)adapter.getItem(i);

                    if(i == position) {
                        if(model.isSelected()) {
                            model.setSelected(false);
                        } else if(!model.isSelected()) {
                            model.setSelected(true);
                        }
                    }
                }

                adapter.notifyDataSetChanged();
            }
        });

        EditText e = (EditText) findViewById(R.id.lotId);

        e.addTextChangedListener(new TextWatcher() {

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

                if (before == 0 && count == 1 && s.charAt(start) == '\n') {
                    String sData = ((TextView)findViewById(R.id.lotId)).getText().toString().replaceAll ("\n", "");

                    if(sData.isEmpty())
                    {
                        ((TextView) findViewById(R.id.lotId)).setText("");
                        return;
                    }

                    requestBarcodeType(sData);
                }

            }
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {}
            @Override
            public void afterTextChanged(Editable s) {}
        });
    }

    @Override
    protected void onResume() {
        super.onResume();
        this.registerReceiver(new ScanResultReceiver(), filter);
    }

    //region Button Click Event
    public void onclickWindow(View view){
        resetLogoutTimer();
        InputMethodManager imm = (InputMethodManager) getSystemService(INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(((EditText)findViewById(R.id.lotId)).getWindowToken(), 0);
    }

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

    public void onClickMachine(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showMachineDialog();
    }

    public void onClickWorkShift(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showWorkShiftDialog();
    }

    public void onClickWorker(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showWorkerDialog();
    }

    public void onClickToOper(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showToOperDialog();
    }

    public void onClickDelete(View view){
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        int iSelected = 0;

        for (WIPModel model : listLotModels)
        {
            if(model.isSelected())
            {
                iSelected++;
                break;
            }
        }

        if(iSelected <= 0)
        {
            showDialog(getString(R.string.alert_message_no_object));
            return;
        }

        for (int i = listLotModels.size() - 1; i >= 0; i--)
        {
            if(listLotModels.get(i).isSelected())
                listLotModels.remove(i);
        }

        adapter.notifyDataSetChanged();

        setTotalCount();
    }

    public void onClickEnd(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화

        if(listLotModels.size() <= 0)
        {
            showDialog(getString(R.string.alert_message_no_object));
            return;
        }

        listLot.clear();

        //중복제거
        for(WIPModel model : listLotModels)
        {
            boolean bSame = false;
            //중복체크
            for(String sLot : listLot){
                if(model.getLotId().equalsIgnoreCase(sLot))
                {
                    bSame = true;
                    break;
                }
            }

            if(!bSame)
            {
                model.setSelected(false);
                listLot.add(model.getLotId());
            }
            else
                model.setSelected(true);
        }

        for (int i = listLotModels.size() - 1; i >= 0; i--)
        {
            if(listLotModels.get(i).isSelected())
                listLotModels.remove(i);
        }

        adapter.notifyDataSetChanged();

        setTotalCount();

        showConfirmDialog(getString(R.string.alert_message_end), new Runnable() {
            @Override
            public void run() {
                requestEnd();
            }
        });
    }

    public void onClickClear(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showConfirmDialog(getString(R.string.alert_message_clear), new Runnable() {
            @Override
            public void run() {
                init(1);
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

                        if(isLoading)
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
                    case H101Const.LOT :
                        ((TextView) findViewById(R.id.lotId)).setText(barcode);
                        requestLotValid(barcode);
                        break;
                    default:
                        startAlarm();
                        showDialog(getString(R.string.alert_message_error_no_registered_barcode));
                        ((TextView) findViewById(R.id.lotId)).setText("");
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

    public void requestLotValid(String sBarcode){
        if(isLoading)
            return;
        isLoading = true;

        String sArea = "";
        String sSubArea = "";
        String sOper = "";

        ((TextView) findViewById(R.id.lotId)).setText("");

        //입력된 LOT이 없을 경우 에러
        if(sBarcode == null || sBarcode == "")
        {
            showDialog((getString(R.string.alert_message_lot_empty)));
            isLoading = false;
            return;
        }

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

        WipViewLotInfoRequest request = new WipViewLotInfoRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("LOT_ID", "S", sBarcode);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                isLoading = false;
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                int iSelection = 0;
                String sFlowID = "";
                isLoading = false;
                Map<String, Object> resultMap = (Map<String, Object>)result;
                if(resultMap.containsKey("ROWS")) {
                    for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                        //해당 LOT의 사업부/작업장/공정 LOAD
                        sSetupArea = (String)row.get("AREA_ID");
                        sSetupSubArea = (String)row.get("SUB_AREA_ID");
                        sSetupOper = (String)row.get("OPER");

                        if(!validLot())
                        {
                            isLoading = false;
                            return;
                        }

                        for (WIPModel wipModel : listLotModels)
                        {
                            if(wipModel.getLotId().equalsIgnoreCase((String)row.get("LOT_ID")))
                            {
                                showDialog((getString(R.string.alert_message_error_scan_wrong_duplicate)));
                                isLoading = false;
                                return;
                            }
                        }

                        WIPModel model = new WIPModel();
                        model.setLotId((String)row.get("LOT_ID"));
                        model.setMatId((String)row.get("MAT_ID"));
                        model.setDesc((String)row.get("MAT_DESC"));
                        model.setMatVer((String)row.get("MAT_VER"));
                        model.setQty(FormatUtil.convertStringToDouble((String)row.get("QTY_1")));
                        model.setOrdQty(FormatUtil.convertStringToDouble((String)row.get("QTY_1")));
                        model.setWorkOrderId((String)row.get("ORDER_ID"));
                        //model.setSelected(true);

                        if(sFlowID == null || sFlowID == "")
                        {
                            sFlowID = (String)row.get("FLOW");
                        }

                        iSelection = listLotModels.size() + 1;

                        listLotModels.add(model);
                    }

                    adapter.notifyDataSetChanged(); // 리스트 갱신

                    listView.setSelection(iSelection);

                    setTotalCount();

                    findViewById(R.id.toOperLayout).setEnabled(true);
                    requestToOper(sFlowID);
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

    private void setTotalCount(){
        ((TextView) findViewById(R.id.totalCount)).setText(FormatUtil.toNumFormat(listLotModels.size()));
    }

    private boolean validLot(){
        String sArea = "";

        for (DropDownModel areaModel : listAreaModels) {
            if(areaModel.isSelected())
            {
                sArea = areaModel.getId();
                break;
            }
        }

        //LOT의 AREA와 비교
        if(!sArea.equalsIgnoreCase(sSetupArea))
        {
            showDialog(getString(R.string.alert_message_error_not_same_area));
            return false;
        }
        else
        {
            String sSubArea = "";

            for (DropDownModel subAreaModel : listSubAreaModels) {
                if(subAreaModel.isSelected())
                {
                    sSubArea = subAreaModel.getId();
                    break;
                }
            }

            // 선택된 SUB AREA가 존재할때
            if(sSubArea != null && sSubArea != "")
            {
                //LOT의 SUB AREA와 비교
                if(!sSubArea.equalsIgnoreCase(sSetupSubArea))
                {
                    showDialog(getString(R.string.alert_message_error_not_same_sub_area));
                    return false;
                }
                else
                {
                    String sOper = "";

                    for (DropDownModel operModel : listOperModels) {
                        if(operModel.isSelected())
                        {
                            sOper = operModel.getId();
                            break;
                        }
                    }

                    //LOT의 OPER와 비교
                    if(!sOper.equalsIgnoreCase(sSetupOper))
                    {
                        showDialog(getString(R.string.alert_message_error_not_same_oper));
                        return false;
                    }
                }
            }
        }

        return true;
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
                ((TextView)findViewById(R.id.toOper)).setText("");
                findViewById(R.id.toOperLayout).setEnabled(false);
                listToOperModels.clear();
                break;
            case 2 :
                //전부초기화
                clearAllView();
                break;
            default:
                break;
        }
    }

    private void clearListView() {
        ((TextView)findViewById(R.id.lotId)).setText("");

        listLotModels.clear();
        adapter.notifyDataSetChanged();

        setTotalCount();

        ((TextView)findViewById(R.id.lotId)).requestFocus();
    }

    private void clearAllView(){
        ((TextView)findViewById(R.id.area)).setText("");
        ((TextView)findViewById(R.id.subArea)).setText("");
        ((TextView)findViewById(R.id.oper)).setText("");
        ((TextView)findViewById(R.id.machine)).setText("");
        ((TextView)findViewById(R.id.workShift)).setText("");
        ((TextView)findViewById(R.id.worker)).setText("");
        ((TextView)findViewById(R.id.lotId)).setText("");
        ((TextView)findViewById(R.id.toOper)).setText("");

        listLotModels.clear();
        listAreaModels.clear();
        listSubAreaModels.clear();
        listOperModels.clear();
        listMachineModels.clear();
        listWorkShiftModels.clear();
        listWorkerModels.clear();
        listToOperModels.clear();

        adapter.notifyDataSetChanged();

        setTotalCount();

        findViewById(R.id.subAreaLayout).setEnabled(false);
        findViewById(R.id.operLayout).setEnabled(false);
        findViewById(R.id.machineLayout).setEnabled(false);
        findViewById(R.id.workShiftLayout).setEnabled(false);
        findViewById(R.id.workerLayout).setEnabled(false);
        findViewById(R.id.toOperLayout).setEnabled(false);

        requestAreaList();
        requestWorkShiftList();

        ((TextView)findViewById(R.id.lotId)).requestFocus();
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
                    findViewById(R.id.machineLayout).setEnabled(false);
                    //다음 작업장 호출
                    requestSubArea(areaModel.getId());
                }
                else
                {
                    areaModel.setSelected(false);
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
                    findViewById(R.id.machineLayout).setEnabled(false);
                    requestOper(sArea, subAreaModel.getId());
                }
                else
                {
                    subAreaModel.setSelected(false);
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
                    findViewById(R.id.machineLayout).setEnabled(true);
                    findViewById(R.id.workShiftLayout).setEnabled(true);
                    requestMachine(operModel.getId());
                }
                else
                {
                    operModel.setSelected(false);
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
                // factory 를 변경하지 않으면 아무것도 하지 않는다.
                String sArea = ((TextView)findViewById(R.id.area)).getText().toString();

                if(sArea.equalsIgnoreCase(model.getName()))
                    return;

                ((TextView)findViewById(R.id.area)).setText(model.getName());

                //사업부 제외 모든 하위 검색조건 초기화
                ((TextView)findViewById(R.id.subArea)).setText("");
                ((TextView)findViewById(R.id.oper)).setText("");
                ((TextView)findViewById(R.id.machine)).setText("");
                ((TextView)findViewById(R.id.workShift)).setText("");
                ((TextView)findViewById(R.id.worker)).setText("");
                listWorkerModels.clear();

                for (DropDownModel areaModel : listAreaModels)
                {
                    areaModel.setSelected(false);
                }

                model.setSelected(true);

                requestSubArea(model.getId());
                findViewById(R.id.subAreaLayout).setEnabled(true);
                findViewById(R.id.operLayout).setEnabled(false);
                findViewById(R.id.machineLayout).setEnabled(false);
                findViewById(R.id.workShiftLayout).setEnabled(false);
                findViewById(R.id.workerLayout).setEnabled(false);

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
                ((TextView)findViewById(R.id.machine)).setText("");
                ((TextView)findViewById(R.id.workShift)).setText("");
                ((TextView)findViewById(R.id.worker)).setText("");
                listWorkerModels.clear();
                findViewById(R.id.operLayout).setEnabled(true);
                findViewById(R.id.machineLayout).setEnabled(false);
                findViewById(R.id.workShiftLayout).setEnabled(false);
                findViewById(R.id.workerLayout).setEnabled(false);
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

                requestMachine(model.getId()); //공정코드로 설비 리스트 받아오기
                ((TextView)findViewById(R.id.machine)).setText("");
                ((TextView)findViewById(R.id.workShift)).setText("");
                ((TextView)findViewById(R.id.worker)).setText("");
                listWorkerModels.clear();
                findViewById(R.id.machineLayout).setEnabled(true);
                findViewById(R.id.workShiftLayout).setEnabled(true);
                findViewById(R.id.workerLayout).setEnabled(false);
                requestWorkShiftList();
                init(1);
            }
        });
        dialog.showDialog();
    }

    private void requestMachine(String sOper) {
        RasViewResourceListRequest request = new RasViewResourceListRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("OPER", "S", sOper);
        request.addParam("NEXT_RES_ID", "S", "");

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                listMachineModels.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            DropDownModel model = new DropDownModel();
                            model.setId(row.get("RES_ID"));
                            model.setName(row.get("RES_DESC"));

                            listMachineModels.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listMachineModels.clear();
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

    private void showMachineDialog() {
        ComboBoxDialog dialog = new ComboBoxDialog(this);
        dialog.setDialogTitle(getString(R.string.common_word_machine));
        dialog.setData(listMachineModels);
        dialog.setOnSelectItemListener(new ComboBoxDialog.OnSelectItemListener() {
            @Override
            public void onClickItem(DropDownModel model) {
                String sMachine = ((TextView)findViewById(R.id.machine)).getText().toString();
                String sOper = "";

                if(sMachine.equalsIgnoreCase(model.getName()))
                    return;

                for (DropDownModel machineModel : listMachineModels)
                {
                    machineModel.setSelected(false);
                }

                model.setSelected(true);

                for (DropDownModel operModel : listOperModels) {
                    if(operModel.isSelected())
                    {
                        sOper = operModel.getId();
                        break;
                    }
                }

                ((TextView)findViewById(R.id.machine)).setText(model.getName());

                requestLotList(sOper, model.getId()); //공정, 설비를 통해 시작된 LOT 리스트 조회
                //init(1);
            }
        });
        dialog.showDialog();
    }

    private void requestWorkShiftList() {
        String requestQuery
                = "SELECT KEY_1 WORK_SHIFT, DATA_1 WORK_SHIFT_DESC"
                + " FROM MGCMTBLDAT"
                + " WHERE 1 = 1"
                + " AND FACTORY = '" + AppSettingManager.getLoginFactory(this) + "'"
                + " AND TABLE_NAME = \'C_WORKER_GROUP\'";

        SQLQueryRequest request = new SQLQueryRequest(this, requestQuery);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                listWorkShiftModels.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            DropDownModel model = new DropDownModel();
                            model.setId(row.get("WORK_SHIFT"));
                            model.setName(row.get("WORK_SHIFT_DESC"));

                            listWorkShiftModels.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listWorkShiftModels.clear();
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
            }
        });
    }

    private void showWorkShiftDialog() {
        ComboBoxDialog dialog = new ComboBoxDialog(this);
        dialog.setDialogTitle(getString(R.string.common_word_work_shift));
        dialog.setData(listWorkShiftModels);
        dialog.setOnSelectItemListener(new ComboBoxDialog.OnSelectItemListener() {
            @Override
            public void onClickItem(DropDownModel model) {
                String sShift = ((TextView)findViewById(R.id.workShift)).getText().toString();
                String sArea = "";
                String sSubArea = "";
                String sOper = "";


                if(sShift.equalsIgnoreCase(model.getName()))
                    return;

                for (DropDownModel shiftModel : listWorkShiftModels)
                {
                    shiftModel.setSelected(false);
                }

                model.setSelected(true);

                ((TextView)findViewById(R.id.workShift)).setText(model.getName());

                //AREA
                for (DropDownModel areaModel : listAreaModels) {
                    if(areaModel.isSelected())
                    {
                        sArea = areaModel.getId();
                        break;
                    }
                }

                //SUB AREA
                for (DropDownModel subAreaModel : listSubAreaModels) {
                    if(subAreaModel.isSelected())
                    {
                        sSubArea = subAreaModel.getId();
                        break;
                    }
                }

                //OPER
                for (DropDownModel operModel : listOperModels) {
                    if(operModel.isSelected())
                    {
                        sOper = operModel.getId();
                        break;
                    }
                }

                requestWorker(sArea, sSubArea, sOper, model.getId()); //AREA, SUB_AREA, OPER, WORK_SHIFT로 작업자 조회
                ((TextView)findViewById(R.id.worker)).setText("");
                findViewById(R.id.workerLayout).setEnabled(true);
                //init(1);
            }
        });
        dialog.showDialog();
    }

    private void requestWorker(String sArea, String sSubArea, String sOper, String sWorkShift) {
        WipViewWorkerListRequest request = new WipViewWorkerListRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("AREA_ID", "S", sArea);
        request.addParam("SUB_AREA_ID", "S", sSubArea);
        request.addParam("OPER", "S", sOper);
        request.addParam("GROUP_ID", "S", sWorkShift);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                listWorkerModels.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            DropDownModel model = new DropDownModel();
                            model.setId(row.get("WORKER_ID"));
                            model.setName(row.get("WORKER_DESC"));

                            listWorkerModels.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listWorkerModels.clear();
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

    private void showWorkerDialog() {
        ComboBoxDialog dialog = new ComboBoxDialog(this);
        dialog.setDialogTitle(getString(R.string.common_word_worker));
        dialog.setData(listWorkerModels);
        dialog.setOnSelectItemListener(new ComboBoxDialog.OnSelectItemListener() {
            @Override
            public void onClickItem(DropDownModel model) {
                String sWorker = ((TextView)findViewById(R.id.worker)).getText().toString();

                if(sWorker.equalsIgnoreCase(model.getName()))
                    return;

                for (DropDownModel workerModel : listWorkerModels)
                {
                    workerModel.setSelected(false);
                }

                model.setSelected(true);

                ((TextView)findViewById(R.id.worker)).setText(model.getName());
            }
        });
        dialog.showDialog();
    }

    public void requestLotList(String sOper, String sMachine){

        WipViewLotInfoRequest request = new WipViewLotInfoRequest(this);

        request.addParam("PROCSTEP", "C", "4");
        request.addParam("OPER", "S", sOper);
        request.addParam("RES_ID", "S", sMachine);
        request.addParam("NEXT_LOT_ID", "S", "");

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                int iSelection = 0;

                Map<String, Object> resultMap = (Map<String, Object>)result;
                if(resultMap.containsKey("ROWS")) {
                    for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {
                        WIPModel model = new WIPModel();
                        model.setLotId((String)row.get("LOT_ID"));

                        boolean bSameCheck = false;

                        //중복 LOT체크
                        for (WIPModel checkModel : listLotModels)
                        {
                            //같으면 추가하지 않고 진행
                            if(row.get("LOT_ID").equalsIgnoreCase(checkModel.getLotId()))
                            {
                                bSameCheck = true;
                                break;
                            }
                        }

                        if(bSameCheck)
                            continue;

                        model.setMatId((String)row.get("MAT_ID"));
                        model.setDesc((String)row.get("MAT_DESC"));
                        model.setQty(FormatUtil.convertStringToDouble((String)row.get("QTY_1")));
                        model.setOrdQty(FormatUtil.convertStringToDouble((String)row.get("QTY_1")));
                        model.setWorkOrderId((String)row.get("ORDER_ID"));
                        //model.setSelected(true);

                        iSelection = listLotModels.size() + 1;

                        listLotModels.add(model);
                    }

                    adapter.notifyDataSetChanged(); // 리스트 갱신

                    listView.setSelection(iSelection);

                    setTotalCount();
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

    private void requestEnd() {
        if(isLoading)
            return;
        isLoading = true;
        String sOper = "";
        String sMachine = "";
        String sWorker = "";
        String sToOper = "";

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

        for (DropDownModel machineModel : listMachineModels) {
            if(machineModel.isSelected())
            {
                sMachine = machineModel.getId();
                break;
            }
        }

        for (DropDownModel workerModel : listWorkerModels) {
            if(workerModel.isSelected())
            {
                sWorker = workerModel.getId();
                break;
            }
        }

        if(sWorker == null || sWorker == "")
        {
            showDialog(getString(R.string.common_word_check_worker));
            isLoading = false;
            return;
        }

        for (DropDownModel toOperModel : listToOperModels) {
            if(toOperModel.isSelected())
            {
                sToOper = toOperModel.getId();
                break;
            }
        }

        WipMultiProcessLotRequest request = new WipMultiProcessLotRequest(this);

        request.addParam("PROCSTEP", "C", "2");
        request.addParam("OPER", "S", sOper);
        request.addParam("RES_ID", "S", sMachine);
        request.addParam("COMMENT", "S", "PDA_PROCESS_OUT");
        request.addParam("TO_OPER", "S", sToOper);

        for (WIPModel model : listLotModels) {
            DataModel data = new DataModel();
            List<VariableModel> columns = new ArrayList<>();

            columns.add(ParseH101Xml.createVariableModel("LOT_ID", "S", model.getLotId()));
            columns.add(ParseH101Xml.createVariableModel("ORDER_ID", "S", model.getWorkOrderId()));
            columns.add(ParseH101Xml.createVariableModel("GOOD_QTY_1", "F8", String.valueOf(model.getOrdQty())));
            columns.add(ParseH101Xml.createVariableModel("LOSS_QTY_1", "F8", "0"));

            data.setD(columns);
            data.setN("LOT_TBL");

            request.addListParam(data);
        }

        //작업자 파라미터 추가
        for (DropDownModel userModel : listWorkerModels) {
            if(userModel.isSelected())
            {
                DataModel data = new DataModel();
                List<VariableModel> columns = new ArrayList<>();

                columns.add(ParseH101Xml.createVariableModel("WORKER_ID", "S", userModel.getId()));

                data.setD(columns);
                data.setN("WORKER_TBL");

                request.addListParam(data);
                break;
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
                init(1);
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

    private void inputValue(final WIPModel model) {
        InputDialog dialog = new InputDialog(this);
        dialog.setDialog(getString(R.string.common_word_work_quantity), "0", FormatUtil.toNumFormat(model.getOrdQty()));
        dialog.setOnInputMessageListener(new InputDialog.OnInputMessageListener() {
            @Override
            public void onClickDone(String value) {

                if(StringUtil.isNullOrEmpty(value)) {
                    return;
                }

                double inputValue = FormatUtil.convertStringToDouble(value);

                if(model.getQty() < inputValue) {
                    showDialog(getString(R.string.alert_message_over_input_qty), new Runnable() {
                        @Override
                        public void run() {
                            inputValue(model);
                        }
                    });
                    return;
                }

                model.setOrdQty(FormatUtil.convertStringToDouble(value));

                adapter.notifyDataSetChanged();
            }
        });

        dialog.show();
    }

    private void requestToOper(String sFlowID) {
        String requestQuery
                = "SELECT FLW.OPER, OPR.OPER_DESC "
                + "    FROM MWIPFLWOPR FLW, MWIPOPRDEF OPR "
                + "   WHERE     FLW.FACTORY = OPR.FACTORY "
                + "         AND FLW.FACTORY = '" + AppSettingManager.getLoginFactory(this) + "'"
                + "         AND FLW.OPER = OPR.OPER "
                + "         AND FLW.FLOW = '" + sFlowID + "'" //FLOW 조건
                + " ORDER BY FLW.SEQ_NUM ";

        SQLQueryRequest request = new SQLQueryRequest(this, requestQuery);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                listToOperModels.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            DropDownModel model = new DropDownModel();
                            model.setId(row.get("OPER"));
                            model.setName(row.get("OPER_DESC"));
                            model.setSelected(false);
                            listToOperModels.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listToOperModels.clear();
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

    private void showToOperDialog() {
        ComboBoxDialog dialog = new ComboBoxDialog(this);
        dialog.setDialogTitle(getString(R.string.common_word_to_oper));
        dialog.setData(listToOperModels);
        dialog.setOnSelectItemListener(new ComboBoxDialog.OnSelectItemListener() {
            @Override
            public void onClickItem(DropDownModel model) {
                String sToOper = ((TextView)findViewById(R.id.toOper)).getText().toString();
                String sOper = "";

                if(sToOper.equalsIgnoreCase(model.getName()))
                    return;

                for (DropDownModel operModel : listOperModels)
                {
                    if(operModel.isSelected())
                    {
                        sOper = operModel.getId();
                        break;
                    }
                }

                if(sOper.equalsIgnoreCase(model.getId()))
                {
                    showDialog(getString(R.string.alert_message_error_duplicate_oper));
                    return;
                }

                for (DropDownModel toOperModel : listToOperModels)
                {
                    toOperModel.setSelected(false);
                }

                model.setSelected(true);

                ((TextView)findViewById(R.id.toOper)).setText(model.getName());
            }
        });
        dialog.showDialog();
    }

    //endregion
}
