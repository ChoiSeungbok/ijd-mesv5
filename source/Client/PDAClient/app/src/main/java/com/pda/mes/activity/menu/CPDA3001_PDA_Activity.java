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
import android.widget.TextView;

import com.pda.mes.R;
import com.pda.mes.activity.ToolbarActivity;
import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.prod.WipViewLotInfoRequest;
import com.pda.mes.h101.request.inv.InvCheckBarcodeTypeRequest;
import com.pda.mes.manager.AppLogManager;
import com.pda.mes.utils.FormatUtil;

import java.util.List;
import java.util.Map;

import device.common.ScanConst;

public class CPDA3001_PDA_Activity extends ToolbarActivity {
    public static final String TAG = CPDA3001_PDA_Activity.class.getSimpleName();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        AppLogManager.printScreenNameLog(TAG, getIntent().getStringExtra(EXTRA_NAME_TITLE));
        setContentView(R.layout.activity_cpda3001, TOOLBAR_TYPE_PUSH);

        EditText e = (EditText) findViewById(R.id.lotId);

        e.addTextChangedListener(new TextWatcher() {

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

                ((TextView)findViewById(R.id.area)).setText("");
                ((TextView)findViewById(R.id.subArea)).setText("");
                ((TextView)findViewById(R.id.workOrder)).setText("");
                ((TextView)findViewById(R.id.oper)).setText("");
                ((TextView)findViewById(R.id.machine)).setText("");
                ((TextView)findViewById(R.id.itemCode)).setText("");
                ((TextView)findViewById(R.id.itemDesc)).setText("");
                ((TextView)findViewById(R.id.lotQty)).setText("");
                ((TextView)findViewById(R.id.lotStatus)).setText("");

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
        this.registerReceiver(new CPDA3001_PDA_Activity.ScanResultReceiver(), filter);
    }

    //region Button Click Event
    public void onclickWindow(View view){
        resetLogoutTimer();
        InputMethodManager imm = (InputMethodManager) getSystemService(INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(((EditText)findViewById(R.id.lotId)).getWindowToken(), 0);
    }

    public void onClickSearch(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        final String sLotId = ((TextView)findViewById(R.id.lotId)).getText().toString();

        if(sLotId.isEmpty())
        {
            showDialog(getString(R.string.alert_message_no_lot_id));
            return;
        }

        requestLotList(sLotId);
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
                    case H101Const.LOT :
                        requestLotList(barcode);
                        break;
                    default:
                        startAlarm();
                        showDialog(getString(R.string.alert_message_error_no_registered_barcode));
                        ((TextView)findViewById(R.id.lotId)).setText("");
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
                //리스트 초기화
                clearView();
                break;
            default:
                break;
        }
    }

    private void clearView(){
        ((TextView)findViewById(R.id.lotId)).setText("");
        ((TextView)findViewById(R.id.area)).setText("");
        ((TextView)findViewById(R.id.subArea)).setText("");
        ((TextView)findViewById(R.id.workOrder)).setText("");
        ((TextView)findViewById(R.id.oper)).setText("");
        ((TextView)findViewById(R.id.machine)).setText("");
        ((TextView)findViewById(R.id.itemCode)).setText("");
        ((TextView)findViewById(R.id.itemDesc)).setText("");
        ((TextView)findViewById(R.id.lotQty)).setText("");
        ((TextView)findViewById(R.id.lotStatus)).setText("");

        ((TextView)findViewById(R.id.lotId)).requestFocus();
    }

    private void requestLotList(final String sBarcode){

        WipViewLotInfoRequest request = new WipViewLotInfoRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("LOT_ID", "S", sBarcode);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                Map<String, Object> resultMap = (Map<String, Object>)result;

                for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {
                    ((TextView)findViewById(R.id.lotId)).setText(row.get(H101Const.LOT_ID));
                    ((TextView)findViewById(R.id.area)).setText(row.get(H101Const.AREA_DESC));
                    ((TextView)findViewById(R.id.subArea)).setText(row.get(H101Const.SUB_AREA_DESC));
                    ((TextView)findViewById(R.id.workOrder)).setText(row.get(H101Const.ORDER_ID));
                    ((TextView)findViewById(R.id.oper)).setText(row.get(H101Const.OPER_DESC));
                    ((TextView)findViewById(R.id.machine)).setText(row.get(H101Const.RES_DESC));
                    ((TextView)findViewById(R.id.itemCode)).setText(row.get(H101Const.MAT_ID));
                    ((TextView)findViewById(R.id.itemDesc)).setText(row.get(H101Const.MAT_DESC));
                    ((TextView)findViewById(R.id.lotQty)).setText(FormatUtil.toNumFormat(Double.parseDouble(row.get(H101Const.QTY_1))));
                    ((TextView)findViewById(R.id.lotStatus)).setText(row.get(H101Const.LOT_STATUS));
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

    //endregion
}