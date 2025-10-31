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
import com.pda.mes.adapter.CPDA2001_PDA_Adapter;
import com.pda.mes.dialog.ComboBoxDialog;
import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.SQLQueryRequest;
import com.pda.mes.h101.request.prod.RasViewResourceListRequest;
import com.pda.mes.h101.request.prod.WipMultiProcessLotRequest;
import com.pda.mes.h101.request.prod.WipViewLotInfoRequest;
import com.pda.mes.h101.request.prod.WipViewOperListRequest;
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

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import device.common.ScanConst;

public class CPDA2001_PDA_Activity extends ToolbarActivity {
    public static final String TAG = CPDA2001_PDA_Activity.class.getSimpleName();

    private CPDA2001_PDA_Adapter adapter; // 아이템 리스트 어댑터
    private ListView listView; // 아이템 리스트 뷰
    private List<DropDownModel> listAreaModels = new ArrayList<>(); //AREA LIST(사업부)
    private List<DropDownModel> listSubAreaModels = new ArrayList<>(); //SUB AREA LIST(작업장)
    private List<DropDownModel> listOperModels = new ArrayList<>(); //OPER LIST(공정)
    private List<DropDownModel> listMachineModels = new ArrayList<>(); //MACHINE LIST(설비)
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
        setContentView(R.layout.activity_cpda2001, TOOLBAR_TYPE_PUSH);

        adapter = new CPDA2001_PDA_Adapter(this);
        listView = findViewById(R.id.listView);

        adapter.setModels(listLotModels);
        listView.setAdapter(adapter);

        findViewById(R.id.subAreaLayout).setEnabled(false);
        findViewById(R.id.operLayout).setEnabled(false);
        findViewById(R.id.machineLayout).setEnabled(false);

        //USER CMF 1,2,3(사업부, 작업장, 공정)에 해당하는 값이 들어있는 경우 해당 값을 가져온다.
        checkUserSetup();

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

    public void onClickStart(View view) {
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

        showConfirmDialog(getString(R.string.alert_message_start), new Runnable() {
            @Override
            public void run() {
                requestStarting();
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
                isLoading = false;
                int iSelection = 0;
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

                        // GROUP으로 스캔했을 경우가 존재하여 중복 VALIDATION이 필요.
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

        listLotModels.clear();
        listAreaModels.clear();
        listSubAreaModels.clear();
        listOperModels.clear();
        listMachineModels.clear();

        adapter.notifyDataSetChanged();

        setTotalCount();

        findViewById(R.id.subAreaLayout).setEnabled(false);
        findViewById(R.id.operLayout).setEnabled(false);
        findViewById(R.id.machineLayout).setEnabled(false);

        requestAreaList();

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

        //((TextView)findViewById(R.id.area)).setText("");
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

                for (DropDownModel areaModel : listAreaModels)
                {
                    areaModel.setSelected(false);
                }

                model.setSelected(true);

                requestSubArea(model.getId());
                findViewById(R.id.subAreaLayout).setEnabled(true);
                findViewById(R.id.operLayout).setEnabled(false);
                findViewById(R.id.machineLayout).setEnabled(false);

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
                findViewById(R.id.operLayout).setEnabled(true);
                findViewById(R.id.machineLayout).setEnabled(false);
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
                findViewById(R.id.machineLayout).setEnabled(true);
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
                String sMachine = ((TextView)findViewById(R.id.oper)).getText().toString();

                if(sMachine.equalsIgnoreCase(model.getName()))
                    return;

                for (DropDownModel machineModel : listMachineModels)
                {
                    machineModel.setSelected(false);
                }

                model.setSelected(true);

                ((TextView)findViewById(R.id.machine)).setText(model.getName());
                //init(1);
            }
        });
        dialog.showDialog();
    }

    private void requestStarting() {
        if(isLoading)
            return;
        isLoading = true;
        String sOper = "";
        String sMachine = "";

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

        WipMultiProcessLotRequest request = new WipMultiProcessLotRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("OPER", "S", sOper);
        request.addParam("RES_ID", "S", sMachine);

        for (WIPModel model : listLotModels) {
            DataModel data = new DataModel();
            List<VariableModel> columns = new ArrayList<>();

            columns.add(ParseH101Xml.createVariableModel("LOT_ID", "S", model.getLotId()));
            columns.add(ParseH101Xml.createVariableModel("ORDER_ID", "S", model.getWorkOrderId()));

            data.setD(columns);
            data.setN("LOT_TBL");

            request.addListParam(data);
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
    //endregion
}
