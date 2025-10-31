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
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;

import com.pda.mes.R;
import com.pda.mes.activity.ToolbarActivity;
import com.pda.mes.adapter.CPDA2006_PDA_Adapter;
import com.pda.mes.dialog.ComboBoxDialog;
import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.SQLQueryRequest;
import com.pda.mes.h101.request.inv.InvCheckBarcodeTypeRequest;
import com.pda.mes.h101.request.inv.InvMoveLotRequest;
import com.pda.mes.h101.request.inv.InvValidMoveLotRequest;
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

public class CPDA2006_PDA_Activity extends ToolbarActivity {
    public static final String TAG = CPDA2006_PDA_Activity.class.getSimpleName();

    private CPDA2006_PDA_Adapter adapter; // 아이템 리스트 어댑터
    private ListView listView; // 아이템 리스트 뷰
    private List<DropDownModel> listAreaModels = new ArrayList<>(); //AREA LIST
    private List<DropDownModel> listOutOperModels = new ArrayList<>(); //OUT OPER LIST
    private List<DropDownModel> listMoveOperModels = new ArrayList<>(); //MOVE OPER LIST
    private List<INVModel> listLotModels = new ArrayList<>();
    private List<String> listLot = new ArrayList<>();//중복제거를 위한 LOT확인
    private boolean isLoading = false;
    private String userAreaId = "";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        AppLogManager.printScreenNameLog(TAG, getIntent().getStringExtra(EXTRA_NAME_TITLE));
        setContentView(R.layout.activity_cpda2006, TOOLBAR_TYPE_PUSH);

        adapter = new CPDA2006_PDA_Adapter(this);
        listView = findViewById(R.id.listView);

        adapter.setModels(listLotModels);
        listView.setAdapter(adapter);

        userAreaId = SessionManager.getUserAreaId(this);

        findViewById(R.id.outOperLayout).setEnabled(false);
        findViewById(R.id.moveOperLayout).setEnabled(false);

        requestAreaList();

        EditText e = (EditText) findViewById(R.id.invLotId);

        e.addTextChangedListener(new TextWatcher() {

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

                if (before == 0 && count == 1 && s.charAt(start) == '\n') {
                    String sData = ((TextView)findViewById(R.id.invLotId)).getText().toString().replaceAll ("\n", "");

                    if(sData.isEmpty())
                    {
                        ((TextView) findViewById(R.id.invLotId)).setText("");
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
        imm.hideSoftInputFromWindow(((EditText)findViewById(R.id.invLotId)).getWindowToken(), 0);
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

    public void onClickProcessing(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        String sMoveOper = ((TextView) findViewById(R.id.moveOper)).getText().toString();

        //이동창고가 없을경우
        if(sMoveOper.isEmpty())
        {
            showDialog((getString(R.string.alert_message_move_oper_empty)));
            return;
        }

        if(listLotModels.size() <= 0)
        {
            showDialog(getString(R.string.alert_message_no_object));
            return;
        }

        listLot.clear();

        //중복제거
        for(INVModel model : listLotModels)
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

        showConfirmDialog(getString(R.string.alert_message_processing), new Runnable() {
            @Override
            public void run() {
                requestProcessing();
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
                    case H101Const.INV_LOT :
                        ((TextView) findViewById(R.id.invLotId)).setText(barcode);
                        requestInvLotValid(barcode);
                        break;
                    default:
                        startAlarm();
                        showDialog(getString(R.string.alert_message_error_no_registered_barcode));
                        ((TextView) findViewById(R.id.invLotId)).setText("");
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

    public void requestInvLotValid(String sBarcode){
        ((TextView) findViewById(R.id.invLotId)).setText("");
        String sOutOper = ((TextView) findViewById(R.id.outOper)).getText().toString();

        //출고창고가 없을경우
        if(sOutOper.isEmpty())
        {
            showDialog((getString(R.string.alert_message_out_oper_empty)));
            return;
        }

        //입력된 LOT이 없을 경우 에러
        if(sBarcode == null || sBarcode == "")
        {
            showDialog((getString(R.string.alert_message_lot_empty)));
            return;
        }

        for (INVModel invModel : listLotModels)
        {
            if(invModel.getLotId().equalsIgnoreCase(sBarcode))
            {
                showDialog((getString(R.string.alert_message_error_scan_wrong_duplicate)));
                return;
            }
        }

        for (DropDownModel model : listOutOperModels)
        {
            if(model.isSelected())
            {
                sOutOper = model.getId();
                break;
            }
        }

        InvValidMoveLotRequest request = new InvValidMoveLotRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("INV_LOT_ID", "S", sBarcode);
        request.addParam("FROM_OPER", "S", sOutOper);

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
                model.setMatId((String)resultMap.get("INV_LOT_ID"));
                model.setDesc((String)resultMap.get("MAT_DESC"));
                model.setMatVer((String)resultMap.get("MAT_VER"));
                model.setQty(FormatUtil.convertStringToDouble((String)resultMap.get("QTY")));
                model.setUnit((String)resultMap.get("UNIT"));
                model.setOper((String)resultMap.get("OPER_DESC"));
                //model.setSelected(true);

                iSelection = listLotModels.size() + 1;

                listLotModels.add(model);

                adapter.notifyDataSetChanged(); // 리스트 갱신

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
        ((TextView) findViewById(R.id.totalCount)).setText(FormatUtil.toNumFormat(listLotModels.size()));
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
        ((TextView)findViewById(R.id.invLotId)).setText("");

        listLotModels.clear();
        adapter.notifyDataSetChanged();

        setTotalCount();

        ((TextView)findViewById(R.id.invLotId)).requestFocus();
    }

    private void clearAllView(){
        ((TextView)findViewById(R.id.area)).setText("");
        ((TextView)findViewById(R.id.outOper)).setText("");
        ((TextView)findViewById(R.id.moveOper)).setText("");
        ((TextView)findViewById(R.id.invLotId)).setText("");

        listLotModels.clear();
        listAreaModels.clear();
        listOutOperModels.clear();
        listMoveOperModels.clear();

        adapter.notifyDataSetChanged();

        setTotalCount();

        findViewById(R.id.outOperLayout).setEnabled(false);
        findViewById(R.id.moveOperLayout).setEnabled(false);

        requestAreaList();

        ((TextView)findViewById(R.id.invLotId)).requestFocus();
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

                listAreaModels.add(model);
            }

            if (!TextUtils.isEmpty(userAreaId) && userAreaId != null) {
                for (DropDownModel item : listAreaModels) {
                    if (item.getId().equalsIgnoreCase(userAreaId)) {
                        item.setSelected(true);
                    }
                }
            }
            ((TextView)findViewById(R.id.area)).setText(userAreaId);

            requestOutOper(userAreaId);
            findViewById(R.id.outOperLayout).setEnabled(true);
            findViewById(R.id.moveOperLayout).setEnabled(false);
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

    private void requestProcessing() {
        if(isLoading)
            return;
        isLoading = true;
        String sMoveOper = "";

        for (DropDownModel moveOperModel : listMoveOperModels) {
            if(moveOperModel.isSelected())
            {
                sMoveOper = moveOperModel.getId();
                break;
            }
        }

        InvMoveLotRequest request = new InvMoveLotRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("TO_OPER", "S", sMoveOper);

        for (INVModel model : listLotModels) {
            DataModel data = new DataModel();
            List<VariableModel> columns = new ArrayList<>();

            columns.add(ParseH101Xml.createVariableModel("INV_LOT_ID", "S", model.getLotId()));

            data.setD(columns);
            data.setN("INV_LOT_LIST");

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
