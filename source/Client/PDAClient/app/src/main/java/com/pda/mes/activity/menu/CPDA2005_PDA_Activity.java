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
import com.pda.mes.adapter.CPDA2005_PDA_Adapter;
import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.inv.InvCheckBarcodeTypeRequest;
import com.pda.mes.h101.request.prod.WipMoveLotOrderRequest;
import com.pda.mes.h101.request.prod.WipViewLotInfoRequest;
import com.pda.mes.manager.AppLogManager;
import com.pda.mes.model.WIPModel;
import com.pda.mes.utils.FormatUtil;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import device.common.ScanConst;

public class CPDA2005_PDA_Activity extends ToolbarActivity {
    public static final String TAG = CPDA2005_PDA_Activity.class.getSimpleName();

    private CPDA2005_PDA_Adapter Adapter; // 리스트뷰 어댑터
    private ListView listView; // 뷰모델 리스트뷰
    private List<WIPModel> listMoveLotModel = new ArrayList<>(); // 라벨 뷰모델 리스트
    private boolean isLoading = false;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        AppLogManager.printScreenNameLog(TAG, getIntent().getStringExtra(EXTRA_NAME_TITLE));
        setContentView(R.layout.activity_cpda2005, TOOLBAR_TYPE_PUSH);

        Adapter = new CPDA2005_PDA_Adapter(this);
        listView = findViewById(R.id.listView);

        Adapter.setModels(listMoveLotModel);
        listView.setAdapter(Adapter);

        EditText e = (EditText) findViewById(R.id.moveId);

        e.addTextChangedListener(new TextWatcher() {

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

                init(1);

                if (before == 0 && count == 1 && s.charAt(start) == '\n') {
                    String sData = ((TextView)findViewById(R.id.moveId)).getText().toString().replaceAll ("\n", "");

                    if(sData.isEmpty())
                    {
                        ((TextView) findViewById(R.id.moveId)).setText("");
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
        this.registerReceiver(new CPDA2005_PDA_Activity.ScanResultReceiver(), filter);
    }

    //region Button Click Event
    public void onclickWindow(View view){
        resetLogoutTimer();
        InputMethodManager imm = (InputMethodManager) getSystemService(INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(((EditText)findViewById(R.id.moveId)).getWindowToken(), 0);
    }

    public void onClickConfirm(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화

        if(listMoveLotModel.size() <= 0)
        {
            showDialog(getString(R.string.alert_message_no_object));
            return;
        }

        showConfirmDialog(getString(R.string.alert_message_processing), new Runnable() {
            @Override
            public void run() {
                requestConfirm();
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
                    case H101Const.MOVE_REQUEST :
                        requestMoveLotList(barcode);
                        break;
                    default:
                        startAlarm();
                        showDialog(getString(R.string.alert_message_error_no_registered_barcode));
                        ((TextView)findViewById(R.id.moveId)).setText("");
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
        ((TextView)findViewById(R.id.cpda2005TextViewFromSubArea)).setText("");
        ((TextView)findViewById(R.id.cpda2005TextViewFromOper)).setText("");
        ((TextView)findViewById(R.id.cpda2005TextViewToSubArea)).setText("");
        ((TextView)findViewById(R.id.cpda2005TextViewToOper)).setText("");
        ((TextView)findViewById(R.id.cpda2005TextViewMoveStatus)).setText("");

        listMoveLotModel.clear();
        Adapter.notifyDataSetChanged();
    }

    private void requestMoveLotList(final String sMoveId){
        if(isLoading)
            return;
        isLoading = true;

        WipViewLotInfoRequest request = new  WipViewLotInfoRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("LOT_ID", "S", sMoveId);
        request.addParam("SKIP_YN", "C","Y");

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                isLoading = false;

                Map<String, Object> resultMap = (Map<String, Object>)result;

                ((TextView) findViewById(R.id.moveId)).setText(sMoveId);

                ((TextView)findViewById(R.id.cpda2005TextViewFromSubArea)).setText(resultMap.get(H101Const.FROM_SUB_AREA_DESC).toString());
                ((TextView)findViewById(R.id.cpda2005TextViewFromOper)).setText(resultMap.get(H101Const.FROM_OPER_DESC).toString());
                ((TextView)findViewById(R.id.cpda2005TextViewToSubArea)).setText(resultMap.get(H101Const.TO_SUB_AREA_DESC).toString());
                ((TextView)findViewById(R.id.cpda2005TextViewToOper)).setText(resultMap.get(H101Const.TO_OPER_DESC).toString());
                ((TextView)findViewById(R.id.cpda2005TextViewMoveStatus)).setText(resultMap.get(H101Const.MOVE_STATUS).toString());

                if(resultMap.containsKey("ROWS")) {
                    listMoveLotModel.clear();

                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            WIPModel model = new WIPModel();

                            model.setLotId(row.get("LOT_ID"));
                            model.setMatId(row.get("MAT_ID"));
                            model.setDesc(row.get("MAT_DESC"));
                            model.setQty(FormatUtil.convertStringToDouble(row.get("QTY_1")));
                            model.setUnit(row.get("UNIT_1"));

                            listMoveLotModel.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listMoveLotModel.clear();
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

    private void  requestConfirm() {
        if(isLoading)
            return;
        isLoading = true;

        WipMoveLotOrderRequest request = new WipMoveLotOrderRequest(this);

        request.addParam("PROCSTEP", "C", "3");
        request.addParam("MOVE_ID", "S", ((TextView)findViewById(R.id.moveId)).getText().toString());

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
