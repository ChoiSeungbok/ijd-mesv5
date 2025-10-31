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
import com.pda.mes.h101.request.inv.InvCheckBarcodeTypeRequest;
import com.pda.mes.h101.request.inv.InvMergeLotRequest;
import com.pda.mes.h101.request.inv.InvViewLotInfoRequest;
import com.pda.mes.manager.AppLogManager;
import com.pda.mes.utils.FormatUtil;

import java.util.Map;

import device.common.ScanConst;

public class CPDA2007_PDA_Activity extends ToolbarActivity {
    public static final String TAG = CPDA2007_PDA_Activity.class.getSimpleName();

    private boolean isLoading = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        AppLogManager.printScreenNameLog(TAG, getIntent().getStringExtra(EXTRA_NAME_TITLE));
        setContentView(R.layout.activity_cpda2007, TOOLBAR_TYPE_PUSH);

        EditText t = (EditText) findViewById(R.id.toInvLotId);

        t.addTextChangedListener(new TextWatcher() {

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

                ((TextView)findViewById(R.id.toInvLotMatId)).setText("");
                ((TextView)findViewById(R.id.toInvLotMatDesc)).setText("");
                ((TextView)findViewById(R.id.toInvLotQty)).setText("");
                ((TextView)findViewById(R.id.toInvLotOper)).setText("");

                if (before == 0 && count == 1 && s.charAt(start) == '\n') {
                    String sData = ((TextView)findViewById(R.id.toInvLotId)).getText().toString().replaceAll ("\n", "");

                    if(sData.isEmpty())
                    {
                        ((TextView) findViewById(R.id.toInvLotId)).setText("");
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

        EditText f = (EditText) findViewById(R.id.fromInvLotId);

        f.addTextChangedListener(new TextWatcher() {

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

                ((TextView)findViewById(R.id.fromInvLotMatId)).setText("");
                ((TextView)findViewById(R.id.fromInvLotMatDesc)).setText("");
                ((TextView)findViewById(R.id.fromInvLotQty)).setText("");
                ((TextView)findViewById(R.id.fromInvLotOper)).setText("");

                if (before == 0 && count == 1 && s.charAt(start) == '\n') {
                    String sData = ((TextView)findViewById(R.id.fromInvLotId)).getText().toString().replaceAll ("\n", "");

                    if(sData.isEmpty())
                    {
                        ((TextView) findViewById(R.id.fromInvLotId)).setText("");
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
        this.registerReceiver(new CPDA2007_PDA_Activity.ScanResultReceiver(), filter);
    }

    //region Button Click Event
    public void onclickWindow(View view){
        resetLogoutTimer();
        InputMethodManager imm = (InputMethodManager) getSystemService(INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(((EditText)findViewById(R.id.toInvLotId)).getWindowToken(), 0);
        imm.hideSoftInputFromWindow(((EditText)findViewById(R.id.fromInvLotId)).getWindowToken(), 0);
    }

    public void onClickProcessing(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        String sToInvLotId = ((TextView)findViewById(R.id.toInvLotId)).getText().toString();
        String sFromInvLotId = ((TextView)findViewById(R.id.fromInvLotId)).getText().toString();

        if(sToInvLotId.isEmpty())
        {
            showDialog(getString(R.string.alert_message_no_to_inv_lot_id));
            return;
        }

        if(sFromInvLotId.isEmpty())
        {
            showDialog(getString(R.string.alert_message_no_from_inv_lot_id));
            return;
        }

        showConfirmDialog(getString(R.string.alert_message_processing), new Runnable() {
            @Override
            public void run() {
                requestProcessing();
            }
        });
    }

    public void onClickClear(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showConfirmDialog(getString(R.string.alert_message_clear), new Runnable() {
            @Override
            public void run() {
                init(3);
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
                    case H101Const.INV_LOT :
                        String sToInvLotId = ((TextView)findViewById(R.id.toInvLotId)).getText().toString();
                        String sFromInvLotId = ((TextView)findViewById(R.id.fromInvLotId)).getText().toString();

                        if(type.isEmpty())
                        {
                            if(sToInvLotId.equalsIgnoreCase(barcode) || sFromInvLotId.equalsIgnoreCase(barcode))
                            {
                                showDialog(getString(R.string.alert_message_error_scan_wrong_duplicate));
                                return;
                            }

                            //병합LOT이 비어있는 경우 FROM LOT으로 인식
                            if(sToInvLotId.isEmpty())
                                requestToInvLotList(barcode);
                            else
                                requestFromInvLotList(barcode);
                        }
                        else
                        {
                            if(type.equalsIgnoreCase("T"))
                                requestToInvLotList(barcode);
                            else if(type.equalsIgnoreCase("F"))
                                requestFromInvLotList(barcode);
                        }

                        break;
                    default:
                        startAlarm();
                        showDialog(getString(R.string.alert_message_error_no_registered_barcode));
                        if(type.equalsIgnoreCase("T"))
                            ((TextView)findViewById(R.id.toInvLotId)).setText("");
                        else if(type.equalsIgnoreCase("F"))
                            ((TextView)findViewById(R.id.fromInvLotId)).setText("");
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
                //상위 리스트 초기화
                clearTopListView();
                break;
            case 2 :
                //하위 리스트 초기화
                clearBottomListView();
                break;
            case 3 :
                //전체 초기화
                clearAllView();
                break;
            default:
                break;
        }
    }

    private void clearTopListView() {
        ((TextView)findViewById(R.id.toInvLotId)).setText("");
        ((TextView)findViewById(R.id.toInvLotMatId)).setText("");
        ((TextView)findViewById(R.id.toInvLotMatDesc)).setText("");
        ((TextView)findViewById(R.id.toInvLotQty)).setText("");
        ((TextView)findViewById(R.id.toInvLotOper)).setText("");

        ((TextView)findViewById(R.id.toInvLotId)).requestFocus();
    }

    private void clearBottomListView() {
        ((TextView)findViewById(R.id.fromInvLotId)).setText("");
        ((TextView)findViewById(R.id.fromInvLotMatId)).setText("");
        ((TextView)findViewById(R.id.fromInvLotMatDesc)).setText("");
        ((TextView)findViewById(R.id.fromInvLotQty)).setText("");
        ((TextView)findViewById(R.id.fromInvLotOper)).setText("");

        ((TextView)findViewById(R.id.fromInvLotId)).requestFocus();
    }

    private void clearAllView(){
        ((TextView)findViewById(R.id.toInvLotId)).setText("");
        ((TextView)findViewById(R.id.toInvLotMatId)).setText("");
        ((TextView)findViewById(R.id.toInvLotMatDesc)).setText("");
        ((TextView)findViewById(R.id.toInvLotQty)).setText("");
        ((TextView)findViewById(R.id.toInvLotOper)).setText("");
        ((TextView)findViewById(R.id.fromInvLotId)).setText("");
        ((TextView)findViewById(R.id.fromInvLotMatId)).setText("");
        ((TextView)findViewById(R.id.fromInvLotMatDesc)).setText("");
        ((TextView)findViewById(R.id.fromInvLotQty)).setText("");
        ((TextView)findViewById(R.id.fromInvLotOper)).setText("");

        ((TextView)findViewById(R.id.toInvLotId)).requestFocus();
    }

    private void requestToInvLotList(final String sBarcode){
        if(isLoading)
            return;
        isLoading = true;

        InvViewLotInfoRequest request = new InvViewLotInfoRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("INV_LOT_ID", "S", sBarcode);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                isLoading = false;

                Map<String, Object> resultMap = (Map<String, Object>)result;

                ((TextView) findViewById(R.id.toInvLotId)).setText(sBarcode);
                ((TextView)findViewById(R.id.toInvLotMatId)).setText(resultMap.get(H101Const.MAT_ID).toString());
                ((TextView)findViewById(R.id.toInvLotMatDesc)).setText(resultMap.get(H101Const.MAT_DESC).toString());
                ((TextView)findViewById(R.id.toInvLotQty)).setText(FormatUtil.toNumFormat(Double.parseDouble(resultMap.get(H101Const.QTY).toString())));
                ((TextView)findViewById(R.id.toInvLotOper)).setText(resultMap.get(H101Const.OPER_DESC).toString());
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

    private void requestFromInvLotList(final String sBarcode){
        if(isLoading)
            return;
        isLoading = true;

        InvViewLotInfoRequest request = new InvViewLotInfoRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("INV_LOT_ID", "S", sBarcode);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                isLoading = false;

                Map<String, Object> resultMap = (Map<String, Object>)result;

                ((TextView) findViewById(R.id.fromInvLotId)).setText(sBarcode);
                ((TextView)findViewById(R.id.fromInvLotMatId)).setText(resultMap.get(H101Const.MAT_ID).toString());
                ((TextView)findViewById(R.id.fromInvLotMatDesc)).setText(resultMap.get(H101Const.MAT_DESC).toString());
                ((TextView)findViewById(R.id.fromInvLotQty)).setText(FormatUtil.toNumFormat(Double.parseDouble(resultMap.get(H101Const.QTY).toString())));
                ((TextView)findViewById(R.id.fromInvLotOper)).setText(resultMap.get(H101Const.OPER_DESC).toString());
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

        InvMergeLotRequest request = new InvMergeLotRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("FROM_INV_LOT_ID", "S", ((TextView)findViewById(R.id.fromInvLotId)).getText().toString());
        request.addParam("TO_INV_LOT_ID", "S", ((TextView)findViewById(R.id.toInvLotId)).getText().toString());

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