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
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.shp.ShpCheckShipLotRequest;
import com.pda.mes.manager.AppLogManager;

import java.util.Map;

import device.common.ScanConst;

public class CPDA3006_PDA_Activity extends ToolbarActivity {
    public static final String TAG = CPDA3006_PDA_Activity.class.getSimpleName();

    private boolean isLoading = false;
    private boolean b_lotSeq = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        AppLogManager.printScreenNameLog(TAG, getIntent().getStringExtra(EXTRA_NAME_TITLE));
        setContentView(R.layout.activity_cpda3006, TOOLBAR_TYPE_PUSH);

        EditText t = (EditText) findViewById(R.id.lot1);

        t.addTextChangedListener(new TextWatcher() {

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

                ((TextView)findViewById(R.id.result)).setText("");

                if (before == 0 && count == 1 && s.charAt(start) == '\n') {
                    String sData = ((TextView)findViewById(R.id.lot1)).getText().toString().replaceAll ("\n", "");

                    if(sData.isEmpty())
                    {
                        ((TextView) findViewById(R.id.lot1)).setText("");
                        return;
                    }

                    requestBarcodeType(sData, "T");
                }

            }
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {}
            @Override
            public void afterTextChanged(Editable s) {}
        });

        EditText f = (EditText) findViewById(R.id.lot2);

        f.addTextChangedListener(new TextWatcher() {

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

                ((TextView)findViewById(R.id.result)).setText("");

                if (before == 0 && count == 1 && s.charAt(start) == '\n') {
                    String sData = ((TextView)findViewById(R.id.lot2)).getText().toString().replaceAll ("\n", "");

                    if(sData.isEmpty())
                    {
                        ((TextView) findViewById(R.id.lot2)).setText("");
                        return;
                    }

                    requestBarcodeType(sData, "F");
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
        this.registerReceiver(new CPDA3006_PDA_Activity.ScanResultReceiver(), filter);
    }

    //region Button Click Event
    public void onclickWindow(View view){
        resetLogoutTimer();
        InputMethodManager imm = (InputMethodManager) getSystemService(INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(((EditText)findViewById(R.id.lot1)).getWindowToken(), 0);
        imm.hideSoftInputFromWindow(((EditText)findViewById(R.id.lot2)).getWindowToken(), 0);
    }

    public void onClickClear(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        init(1);
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
        ((TextView) findViewById(R.id.result)).setText("");

        //사용하지 않고, 해당하는 lot1에 없으면 lot1에 lot2에 없으면 lot2에 넣어준다.
        String sLot1 = ((TextView) findViewById(R.id.lot1)).getText().toString();
        String sLot2 = ((TextView) findViewById(R.id.lot2)).getText().toString();

        if(type.equalsIgnoreCase("T"))
        {
            sLot1 = barcode;
            ((TextView)findViewById(R.id.lot1)).setText(barcode);

            EditText f = (EditText) findViewById(R.id.lot2);
            f.requestFocus();
        }
        else if(type.equalsIgnoreCase("F"))
        {
            sLot2 = barcode;
            ((TextView)findViewById(R.id.lot2)).setText(barcode);
        }
        else
        {
            if(sLot1.isEmpty())
            {
                sLot1 = barcode;
                ((TextView)findViewById(R.id.lot1)).setText(barcode);

                EditText f = (EditText) findViewById(R.id.lot2);
                f.requestFocus();
            }
            else
            {
                sLot2 = barcode;
                ((TextView)findViewById(R.id.lot2)).setText(barcode);
            }

        }

        if(sLot1.isEmpty() || sLot2.isEmpty())
        {
            return;
        }

        //같으면 에러
        if(sLot1.equalsIgnoreCase(sLot2))
        {
            showDialog(getString(R.string.alert_message_error_scan_wrong_duplicate));
            return;
        }

        requestMatching();
    }

    private void init(int iSeq)
    {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화

        int iMethod = iSeq;
        switch (iMethod)
        {
            case 1 :
                clearAllView();
                break;
            default:
                break;
        }
    }

    private void clearAllView(){
        ((TextView)findViewById(R.id.lot1)).setText("");
        ((TextView)findViewById(R.id.lot2)).setText("");
        ((TextView)findViewById(R.id.result)).setText("");

        ((TextView)findViewById(R.id.lot1)).requestFocus();
    }

    private void requestMatching() {
        ShpCheckShipLotRequest request = new ShpCheckShipLotRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("LOT_ID_1", "S", ((TextView)findViewById(R.id.lot1)).getText().toString());
        request.addParam("LOT_ID_2", "S", ((TextView)findViewById(R.id.lot2)).getText().toString());

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                Map<String, Object> resultMap = (Map<String, Object>)result;

                //결과값을 넣어줌
                ((TextView)findViewById(R.id.result)).setText(resultMap.get("MATCH").toString());
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

    //endregion
}