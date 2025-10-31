package com.pda.mes.activity.menu;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;

import com.pda.mes.R;
import com.pda.mes.activity.ToolbarActivity;
import com.pda.mes.adapter.CPDA2012_PDA_Adapter;
import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.inv.InvCheckBarcodeTypeRequest;
import com.pda.mes.h101.request.inv.InvCreateLotRequest;
import com.pda.mes.h101.request.inv.InvValidDlvLotRequest;
import com.pda.mes.manager.AppLogManager;
import com.pda.mes.model.INVModel;
import com.pda.mes.model.parser.DataModel;
import com.pda.mes.model.parser.VariableModel;
import com.pda.mes.utils.FormatUtil;
import com.pda.mes.utils.ParseH101Xml;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import device.common.ScanConst;

public class CPDA2012_PDA_Activity extends ToolbarActivity {
    public static final String TAG = CPDA2012_PDA_Activity.class.getSimpleName();

    private CPDA2012_PDA_Adapter Adapter; // 리스트뷰 어댑터
    private ListView listView; // 뷰모델 리스트뷰
    private List<INVModel> listInvLotModel = new ArrayList<>(); // 라벨 뷰모델 리스트
    private boolean isLoading = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        AppLogManager.printScreenNameLog(TAG, getIntent().getStringExtra(EXTRA_NAME_TITLE));
        setContentView(R.layout.activity_cpda2012, TOOLBAR_TYPE_PUSH);

        Adapter = new CPDA2012_PDA_Adapter(this);
        listView = findViewById(R.id.listView);

        Adapter.setModels(listInvLotModel);
        listView.setAdapter(Adapter);

        EditText e = (EditText) findViewById(R.id.dlvLotId);

        e.addTextChangedListener(new TextWatcher() {

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

                init(1);

                if (before == 0 && count == 1 && s.charAt(start) == '\n') {
                    String sData = ((TextView)findViewById(R.id.dlvLotId)).getText().toString().replaceAll ("\n", "");

                    if(sData.isEmpty())
                    {
                        ((TextView) findViewById(R.id.dlvLotId)).setText("");
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
        this.registerReceiver(new CPDA2012_PDA_Activity.ScanResultReceiver(), filter);
    }

    //region Button Click Event
    public void onclickWindow(View view){
        resetLogoutTimer();
        InputMethodManager imm = (InputMethodManager) getSystemService(INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(((EditText)findViewById(R.id.dlvLotId)).getWindowToken(), 0);
    }

    public void onClickProcessing(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화

        if(listInvLotModel.size() <= 0)
        {
            showDialog(getString(R.string.alert_message_no_object));
            return;
        }

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
                    case H101Const.DLV_LOT :
                        requestInvLotList(barcode);
                        break;
                    default:
                        startAlarm();
                        showDialog(getString(R.string.alert_message_error_no_registered_barcode));
                        ((TextView)findViewById(R.id.dlvLotId)).setText("");
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
            default:
                break;
        }
    }

    private void clearListView() {
        ((TextView)findViewById(R.id.cpda2012TextViewIqcId)).setText("");
        ((TextView)findViewById(R.id.cpda2012TextViewIqcResult)).setText("");
        ((TextView)findViewById(R.id.cpda2012TextViewIqcTime)).setText("");
        ((TextView)findViewById(R.id.cpda2012TextViewIqcWorker)).setText("");

        listInvLotModel.clear();
        Adapter.notifyDataSetChanged();
    }

    private void requestInvLotList(final String sDlvLotId){
        if(isLoading)
            return;
        isLoading = true;

        InvValidDlvLotRequest request = new InvValidDlvLotRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("DLV_LOT_ID", "S", sDlvLotId);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                isLoading = false;

                Map<String, Object> resultMap = (Map<String, Object>)result;

                ((TextView) findViewById(R.id.dlvLotId)).setText(sDlvLotId);
                ((TextView)findViewById(R.id.cpda2012TextViewIqcId)).setText(resultMap.get(H101Const.INSP_ID).toString());
                ((TextView)findViewById(R.id.cpda2012TextViewIqcResult)).setText(resultMap.get(H101Const.INSP_RESULT_FLAG).toString());
                ((TextView)findViewById(R.id.cpda2012TextViewIqcTime)).setText(resultMap.get(H101Const.INSP_REQ_TIME).toString());
                ((TextView)findViewById(R.id.cpda2012TextViewIqcWorker)).setText(resultMap.get(H101Const.INSP_USER_ID).toString());

                if(resultMap.containsKey("ROWS")) {
                    listInvLotModel.clear();

                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            INVModel model = new INVModel();

                            model.setLotId(row.get("LABEL_ID"));
                            model.setMatId(row.get("MAT_ID"));
                            model.setDesc(row.get("MAT_DESC"));
                            model.setMatVer(row.get("MAT_VER"));
                            model.setQty(FormatUtil.convertStringToDouble(row.get("QTY")));
                            model.setUnit(row.get("UNIT"));

                            listInvLotModel.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listInvLotModel.clear();
                    }

                    Adapter.notifyDataSetChanged(); // 리스트 갱신
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

    private void requestProcessing() {
        if(isLoading)
            return;
        isLoading = true;

        InvCreateLotRequest request = new InvCreateLotRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("DLV_LOT_ID", "S", ((TextView)findViewById(R.id.dlvLotId)).getText().toString());

        for (INVModel model : listInvLotModel) {
            DataModel data = new DataModel();
            List<VariableModel> columns = new ArrayList<>();

            columns.add(ParseH101Xml.createVariableModel("INV_LOT_ID", "S", model.getLotId()));
            columns.add(ParseH101Xml.createVariableModel("QTY", "F8", String.valueOf(model.getQty())));
            columns.add(ParseH101Xml.createVariableModel("QTY_2", "F8", "0"));
            columns.add(ParseH101Xml.createVariableModel("QTY_3", "F8", "0"));

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