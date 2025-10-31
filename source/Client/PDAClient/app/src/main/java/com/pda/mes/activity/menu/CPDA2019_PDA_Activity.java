package com.pda.mes.activity.menu;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextUtils;
import android.text.TextWatcher;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.AdapterView;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;

import com.pda.mes.R;
import com.pda.mes.activity.ToolbarActivity;
import com.pda.mes.adapter.CPDA2019_PDA_Adapter;
import com.pda.mes.dialog.ComboBoxDialog;
import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.SQLQueryRequest;
import com.pda.mes.h101.request.inv.InvCheckBarcodeTypeRequest;
import com.pda.mes.h101.request.inv.InvRegistMoveLotRequest;
import com.pda.mes.h101.request.inv.InvValidMoveLotRequest;
import com.pda.mes.h101.request.inv.InvViewMoveLotRequest;
import com.pda.mes.h101.request.prod.WipViewOperListRequest;
import com.pda.mes.manager.AppLogManager;
import com.pda.mes.manager.AppSettingManager;
import com.pda.mes.manager.SessionManager;
import com.pda.mes.model.DropDownModel;
import com.pda.mes.model.INVModel;
import com.pda.mes.model.parser.DataModel;
import com.pda.mes.model.parser.VariableModel;
import com.pda.mes.utils.FormatUtil;
import com.pda.mes.utils.ParseH101Xml;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import device.common.ScanConst;

public class CPDA2019_PDA_Activity extends ToolbarActivity {
    public static final String TAG = CPDA2019_PDA_Activity.class.getSimpleName();

    private CPDA2019_PDA_Adapter Adapter; //하단 리스트뷰 어댑터
    private ListView listView; // 뷰모델 리스트뷰
    private List<INVModel> listLotModel = new ArrayList<>(); // 라벨 뷰모델 리스트
    private List<String> listLot = new ArrayList<>();//중복제거를 위한 LOT확인
    private List<DropDownModel> listAreaModels = new ArrayList<>(); //AREA LIST
    private List<DropDownModel> listOutOperModels = new ArrayList<>(); //OUT OPER LIST
    private List<DropDownModel> listMoveOperModels = new ArrayList<>(); //MOVE OPER LIST
    private boolean isLoading = false;
    private String userAreaId = "";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        AppLogManager.printScreenNameLog(TAG, getIntent().getStringExtra(EXTRA_NAME_TITLE));
        setContentView(R.layout.activity_cpda2019, TOOLBAR_TYPE_PUSH);

        Adapter = new CPDA2019_PDA_Adapter(this);
        listView = findViewById(R.id.listView);

        Adapter.setModels(listLotModel);
        listView.setAdapter(Adapter);

        userAreaId = SessionManager.getUserAreaId(this);

        findViewById(R.id.outOperLayout).setEnabled(false);
        findViewById(R.id.moveOperLayout).setEnabled(false);

        requestAreaList();

        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int position, long l) {
                resetLogoutTimer(); // 로그아웃 체크 시간 초기화

                for(int i = 0 ; i < Adapter.getCount() ; i++) {
                    INVModel model = (INVModel)Adapter.getItem(i);

                    if(i == position) {
                        if(model.isSelected()) {
                            model.setSelected(false);

                        } else if(!model.isSelected()) {
                            model.setSelected(true);
                        }
                    }
                }

                Adapter.notifyDataSetChanged();
            }
        });

        EditText e = (EditText) findViewById(R.id.moveId);

        e.addTextChangedListener(new TextWatcher() {

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

                ((TextView)findViewById(R.id.invLotId)).setText("");

                listLotModel.clear();

                Adapter.notifyDataSetChanged();

                setTotalCount();

                if (before == 0 && count == 1 && s.charAt(start) == '\n') {
                    String sData = ((TextView)findViewById(R.id.moveId)).getText().toString().replaceAll ("\n", "");

                    if(sData.isEmpty())
                    {
                        ((TextView) findViewById(R.id.moveId)).setText("");
                        return;
                    }

                    requestBarcodeType(sData, "MOVE_REQUEST");
                }

            }
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {}
            @Override
            public void afterTextChanged(Editable s) {}
        });

        EditText f = (EditText) findViewById(R.id.invLotId);

        f.addTextChangedListener(new TextWatcher() {

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

                if (before == 0 && count == 1 && s.charAt(start) == '\n') {
                    String sData = ((TextView)findViewById(R.id.invLotId)).getText().toString().replaceAll ("\n", "");

                    if(sData.isEmpty())
                    {
                        ((TextView) findViewById(R.id.invLotId)).setText("");
                        return;
                    }

                    requestBarcodeType(sData, "INV_LOT_ID");
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
        this.registerReceiver(new CPDA2019_PDA_Activity.ScanResultReceiver(), filter);
    }

    //region Button Click Event
    public void onclickWindow(View view){
        resetLogoutTimer();
        InputMethodManager imm = (InputMethodManager) getSystemService(INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(((EditText)findViewById(R.id.moveId)).getWindowToken(), 0);
        imm.hideSoftInputFromWindow(((EditText)findViewById(R.id.invLotId)).getWindowToken(), 0);
    }

    private void clearListView() {
        ((TextView)findViewById(R.id.invLotId)).setText("");

        listLotModel.clear();
        Adapter.notifyDataSetChanged();

        setTotalCount();

        ((TextView)findViewById(R.id.invLotId)).requestFocus();
    }

    private void clearAllListView(){
        ((TextView)findViewById(R.id.moveId)).setText("");
        ((TextView)findViewById(R.id.area)).setText("");
        ((TextView)findViewById(R.id.outOper)).setText("");
        ((TextView)findViewById(R.id.moveOper)).setText("");
        ((TextView)findViewById(R.id.invLotId)).setText("");

        listLotModel.clear();

        Adapter.notifyDataSetChanged();

        setTotalCount();

        ((TextView)findViewById(R.id.moveId)).requestFocus();
    }

    private void requestInvLotList(final String sMoveID){
        if(isLoading)
            return;
        isLoading = true;

        InvViewMoveLotRequest request = new InvViewMoveLotRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("MOVE_ID", "S", sMoveID);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                isLoading = false;
                listLotModel.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    try {
                        ((TextView) findViewById(R.id.moveId)).setText(sMoveID);

                        findViewById(R.id.outOperLayout).setEnabled(true);
                        findViewById(R.id.moveOperLayout).setEnabled(true);

                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            INVModel model = new INVModel();

                            model.setLotId(row.get("INV_LOT_ID"));
                            model.setMatId(row.get("MAT_ID"));
                            model.setDesc(row.get("MAT_DESC"));
                            model.setMatVer(row.get("MAT_VER"));
                            model.setQty(FormatUtil.convertStringToDouble(row.get("QTY")));
                            model.setUnit(row.get("UNIT"));
                            model.setSelected(true);

                            listLotModel.add(model);
                        }

                        ((TextView)findViewById(R.id.area)).setText(resultMap.get("AREA_ID").toString());

                        requestOutOper(resultMap.get("AREA_ID").toString());
                        ((TextView)findViewById(R.id.outOper)).setText(resultMap.get("FROM_OPER_DESC").toString());

                        Thread.sleep(500);

                        requestMoveOper(resultMap.get("AREA_ID").toString());
                        ((TextView)findViewById(R.id.moveOper)).setText(resultMap.get("TO_OPER_DESC").toString());
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listLotModel.clear();
                    }

                    Adapter.notifyDataSetChanged(); // 리스트 갱신

                    setTotalCount();



                }
                // 이동번호에 해당하는 데이터가 없는경우
                else {
                    startAlarm();
                    showDialog(getString(R.string.alert_message_not_found_move_id));
                }
            }

            @Override
            public void onFailure(Exception exception) {
                isLoading = false;
                showDialog(exception.getMessage());
            }

            @Override
            public void onFinish() {
                isLoading = false;
                hideLoadingDialog();
            }
        });
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
                clearAllListView();
                break;
            default:
                break;
        }
    }

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

                        requestBarcodeType(mDecodeResult.toString(), "");
                    }
                }
                catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }

    private  void requestBarcodeType(final String barcode, final String type) {
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
                    case H101Const.MOVE_REQUEST :
                        requestInvLotList(barcode);
                        break;
                    case H101Const.INV_LOT :
                        ((TextView) findViewById(R.id.invLotId)).setText(barcode);
                        requestInvLotValid(barcode);
                        break;
                    default:
                        startAlarm();
                        showDialog(getString(R.string.alert_message_error_no_registered_barcode));
                        if(type.equalsIgnoreCase("MOVE_REQUEST"))
                            ((TextView)findViewById(R.id.moveId)).setText("");
                        else if(type.equalsIgnoreCase("INV_LOT_ID"))
                            ((TextView)findViewById(R.id.invLotId)).setText("");
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

    public void requestInvLotValid(final String sLotId){
        ((TextView) findViewById(R.id.invLotId)).setText("");
        String sFromOper = ((TextView) findViewById(R.id.outOper)).getText().toString();
        String sMoveId = ((TextView) findViewById(R.id.moveId)).getText().toString();

        //입력된 LOT이 없을 경우 에러
        if(sLotId.isEmpty())
        {
            showDialog((getString(R.string.alert_message_lot_empty)));
            return;
        }

        //입력된 OUT OPER가 없을 경우 에러
        if(sFromOper.isEmpty())
        {
            showDialog((getString(R.string.alert_message_out_oper_empty)));
            return;
        }

        for (INVModel lotModel : listLotModel) {
            // 동일한 LOT번호 있는지 체크
            if (lotModel.getLotId().equalsIgnoreCase(sLotId)) {
                showDialog((getString(R.string.alert_message_error_scan_wrong_duplicate)));
                return;
            }
        }

        for (DropDownModel model : listOutOperModels)
        {
            if(model.isSelected())
            {
                sFromOper = model.getId();
                break;
            }
        }

        InvValidMoveLotRequest request = new InvValidMoveLotRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("FROM_OPER", "S", sFromOper);
        request.addParam("INV_LOT_ID", "S", sLotId);
        request.addParam("MOVE_ID", "S", sMoveId);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                int iSelection = 0;

                Map<String, Object> resultMap = (Map<String, Object>)result;

                INVModel model = new INVModel();

                model.setLotId((String)resultMap.get("INV_LOT_ID"));
                model.setMatId((String)resultMap.get("MAT_ID"));
                model.setDesc((String)resultMap.get("MAT_DESC"));
                model.setMatVer((String)resultMap.get("MAT_VER"));
                model.setQty(FormatUtil.convertStringToDouble((String)resultMap.get("QTY")));
                model.setUnit((String)resultMap.get("UNIT"));
                model.setSelected(true);

                iSelection = listLotModel.size() + 1;

                listLotModel.add(model);

                Adapter.notifyDataSetChanged(); // 리스트 갱신

                listView.setSelection(iSelection);

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

    private void setTotalCount(){
        ((TextView) findViewById(R.id.totalCount)).setText(FormatUtil.toNumFormat(listLotModel.size()));
    }

    public void onClickArea(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showAreaDialog();
    }

    public void onClickOutOper(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showOutOperDialog();
    }

    public void onClickMoveOper(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showMoveOperDialog();
    }

    //저장버튼 클릭시
    public void onClickSave(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화

        int iSelectLot = 0;

        for (INVModel model : listLotModel)
        {
            if(model.isSelected())
            {
                iSelectLot++;
            }
        }

        if(iSelectLot <= 0) {
            showDialog(getString(R.string.alert_message_no_object));
            return;
        }

        showConfirmDialog(getString(R.string.alert_message_save), new Runnable() {
            @Override
            public void run() {
                requestSave();
            }
        });
    }

    public void onClickDelete(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화

        String sData = ((TextView)findViewById(R.id.moveId)).getText().toString().replaceAll ("\n", "");

        if(sData.isEmpty())
        {
            ((TextView) findViewById(R.id.moveId)).setText("");
            showDialog(getString(R.string.alert_message_not_found_move_id));
            return;
        }

        showConfirmDialog(getString(R.string.alert_message_delete), new Runnable() {
            @Override
            public void run() {
                requestDelete();
            }
        });
    }

    public void onClickClear(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showConfirmDialog(getString(R.string.alert_message_clear), new Runnable() {
            @Override
            public void run() {
                init(2);
            }
        });
    }

    public void onClickClose(View view){
        this.finish();
    }

    private void requestSave() {

        String sMoveId = ((TextView) findViewById(R.id.moveId)).getText().toString();
        String sArea = ((TextView) findViewById(R.id.area)).getText().toString();
        String sMoveOper = ((TextView) findViewById(R.id.moveOper)).getText().toString();
        String sOutOper = ((TextView) findViewById(R.id.outOper)).getText().toString();

        for (DropDownModel model : listAreaModels)
        {
            if(model.isSelected())
            {
                sArea = model.getId();
                break;
            }
            else if(model.getName().equals(sArea))
            {
                sArea = model.getId();
                model.setSelected(true);
                break;
            }
        }

        //입력된 OUT OPER가 없을 경우 에러
        if(sOutOper.isEmpty())
        {
            showDialog((getString(R.string.alert_message_out_oper_empty)));
            return;
        }

        for (DropDownModel model : listOutOperModels)
        {
            if(model.isSelected())
            {
                sOutOper = model.getId();
                break;
            }
            else if(model.getName().equals(sOutOper))
            {
                sOutOper = model.getId();
                model.setSelected(true);
                break;
            }
        }

        //입력된 OUT OPER가 없을 경우 에러
        if(sMoveOper.isEmpty())
        {
            showDialog((getString(R.string.alert_message_move_oper_empty)));
            return;
        }

        for (DropDownModel model : listMoveOperModels)
        {
            if(model.isSelected())
            {
                sMoveOper = model.getId();
                break;
            }
            else if(model.getName().equals(sMoveOper))
            {
                sMoveOper = model.getId();
                model.setSelected(true);
                break;
            }
        }

        InvRegistMoveLotRequest request = new InvRegistMoveLotRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("MOVE_ID", "S", sMoveId);
        request.addParam("OPER", "S", sOutOper);
        request.addParam("TO_OPER", "S", sMoveOper);
        request.addParam("AREA_ID", "S", sArea);

        for (INVModel model : listLotModel) {
            if(model.isSelected()){
                DataModel data = new DataModel();
                List<VariableModel> columns = new ArrayList<>();

                columns.add(ParseH101Xml.createVariableModel("INV_LOT_ID", "S", model.getLotId()));
                columns.add(ParseH101Xml.createVariableModel("QTY", "F8", FormatUtil.toNumFormat(model.getQty())));

                data.setD(columns);
                data.setN("INV_LOT_LIST");

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
                Map<String, Object> resultMap = (Map<String, Object>)result;

                showToast(getString(R.string.processing_completed));

                ((TextView)findViewById(R.id.moveId)).setText(resultMap.get("MOVE_ID").toString());

                requestInvLotList(((TextView) findViewById(R.id.moveId)).getText().toString());
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

    private void requestDelete()
    {
        InvRegistMoveLotRequest request = new InvRegistMoveLotRequest(this);

        request.addParam("PROCSTEP", "C", "2");
        request.addParam("MOVE_ID", "S", ((TextView)findViewById(R.id.moveId)).getText().toString());

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                showToast(getString(R.string.processing_completed));

                init(2);
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
                model.setSelected(false);

                listAreaModels.add(model);
            }

            if (!TextUtils.isEmpty(userAreaId) && userAreaId != null) {
                for (DropDownModel item : listAreaModels) {
                    if (item.getId().equalsIgnoreCase(userAreaId)) {
                        item.setSelected(true);
                    }
                }
            }

            requestOutOper(userAreaId);
            findViewById(R.id.outOperLayout).setEnabled(true);
            findViewById(R.id.moveOperLayout).setEnabled(false);
            init(1);

            ((TextView)findViewById(R.id.area)).setText(userAreaId);
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
                ((TextView)findViewById(R.id.outOper)).setText("");
                ((TextView)findViewById(R.id.moveOper)).setText("");

                for (DropDownModel areaModel : listAreaModels)
                {
                    areaModel.setSelected(false);
                }

                model.setSelected(true);

                requestOutOper(model.getId());
                findViewById(R.id.outOperLayout).setEnabled(true);
                findViewById(R.id.moveOperLayout).setEnabled(false);
                init(1);
            }
        });
        dialog.showDialog();
    }

    private void requestOutOper(String sArea) {
        WipViewOperListRequest request = new WipViewOperListRequest(this);

        request.addParam("PROCSTEP", "C", "3");
        request.addParam("AREA_ID", "S", sArea);
        request.addParam("SUB_AREA_ID", "S", "");
        request.addParam("INV_FLAG", "C", "Y");

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                listOutOperModels.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            DropDownModel model = new DropDownModel();
                            model.setId(row.get("OPER"));
                            model.setName(row.get("OPER_DESC"));
                            model.setSelected(false);
                            listOutOperModels.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listOutOperModels.clear();
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

    private void showOutOperDialog() {

        ComboBoxDialog dialog = new ComboBoxDialog(this);
        dialog.setDialogTitle(getString(R.string.common_word_out_oper));
        dialog.setData(listOutOperModels);
        dialog.setOnSelectItemListener(new ComboBoxDialog.OnSelectItemListener() {
            @Override
            public void onClickItem(DropDownModel model) {
                String sOutOper = ((TextView)findViewById(R.id.outOper)).getText().toString();
                String sArea = "";

                if(sOutOper.equalsIgnoreCase(model.getName()))
                    return;

                ((TextView)findViewById(R.id.outOper)).setText(model.getName());

                for (DropDownModel outOperModel : listOutOperModels)
                {
                    outOperModel.setSelected(false);
                }

                model.setSelected(true);

                for (DropDownModel areaModel : listAreaModels) {
                    if(areaModel.isSelected())
                    {
                        sArea = areaModel.getId();
                        break;
                    }
                }

                requestMoveOper(sArea);
                ((TextView)findViewById(R.id.moveOper)).setText("");
                findViewById(R.id.moveOperLayout).setEnabled(true);
                init(1);
            }
        });
        dialog.showDialog();
    }

    private void requestMoveOper(String sArea) {
        WipViewOperListRequest request = new WipViewOperListRequest(this);

        request.addParam("PROCSTEP", "C", "H");
        request.addParam("AREA_ID", "S", sArea);
        request.addParam("SUB_AREA_ID", "S", "");
        request.addParam("INV_FLAG", "C", "Y");

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                listMoveOperModels.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            DropDownModel model = new DropDownModel();
                            model.setId(row.get("OPER"));
                            model.setName(row.get("OPER_DESC"));
                            model.setSelected(false);
                            listMoveOperModels.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listMoveOperModels.clear();
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

    private void showMoveOperDialog() {
        ComboBoxDialog dialog = new ComboBoxDialog(this);
        dialog.setDialogTitle(getString(R.string.common_word_move_oper));
        dialog.setData(listMoveOperModels);
        dialog.setOnSelectItemListener(new ComboBoxDialog.OnSelectItemListener() {
            @Override
            public void onClickItem(DropDownModel model) {
                String sMoveOper = ((TextView)findViewById(R.id.moveOper)).getText().toString();
                String sOutoper = "";

                if(sMoveOper.equalsIgnoreCase(model.getName()))
                    return;

                for (DropDownModel outOperModel : listOutOperModels)
                {
                    if(outOperModel.isSelected())
                    {
                        sOutoper = outOperModel.getId();
                        break;
                    }
                }

                if(sOutoper.equalsIgnoreCase(model.getId()))
                {
                    showDialog(getString(R.string.alert_message_error_duplicate_oper));
                    return;
                }

                for (DropDownModel moveOperModel : listMoveOperModels)
                {
                    moveOperModel.setSelected(false);
                }

                model.setSelected(true);

                ((TextView)findViewById(R.id.moveOper)).setText(model.getName());
            }
        });
        dialog.showDialog();
    }
}
