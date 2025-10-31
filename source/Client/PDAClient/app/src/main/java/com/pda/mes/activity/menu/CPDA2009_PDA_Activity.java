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
import com.pda.mes.dialog.ComboBoxDialog;
import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.SQLQueryRequest;
import com.pda.mes.h101.request.inv.InvCheckBarcodeTypeRequest;
import com.pda.mes.h101.request.inv.InvReleaseLotRequest;
import com.pda.mes.h101.request.inv.InvViewLotInfoRequest;
import com.pda.mes.manager.AppLogManager;
import com.pda.mes.manager.AppSettingManager;
import com.pda.mes.model.DropDownModel;
import com.pda.mes.model.parser.DataModel;
import com.pda.mes.model.parser.VariableModel;
import com.pda.mes.utils.FormatUtil;
import com.pda.mes.utils.ParseH101Xml;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import device.common.ScanConst;

public class CPDA2009_PDA_Activity extends ToolbarActivity {
    public static final String TAG = CPDA2009_PDA_Activity.class.getSimpleName();
    private List<DropDownModel> listReleaseModels = new ArrayList<>(); //잠금해제코드
    private boolean isLoading = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        AppLogManager.printScreenNameLog(TAG, getIntent().getStringExtra(EXTRA_NAME_TITLE));
        setContentView(R.layout.activity_cpda2009, TOOLBAR_TYPE_PUSH);

        requestReleaseCodeList();

        EditText e = (EditText) findViewById(R.id.invLotId);

        e.addTextChangedListener(new TextWatcher() {

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

                ((TextView)findViewById(R.id.invLotMatDesc)).setText("");
                ((TextView)findViewById(R.id.invLotQty)).setText("");
                ((TextView)findViewById(R.id.invLotOper)).setText("");
                ((TextView)findViewById(R.id.releaseCode)).setText("");

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
        this.registerReceiver(new CPDA2009_PDA_Activity.ScanResultReceiver(), filter);
    }

    //region Button Click Event
    public void onclickWindow(View view){
        resetLogoutTimer();
        InputMethodManager imm = (InputMethodManager) getSystemService(INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(((EditText)findViewById(R.id.invLotId)).getWindowToken(), 0);
    }

    public void onClickReleaseCode(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showReleaseCodeDialog();
    }

    public void onClickRun(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        String sInvLotId = ((TextView)findViewById(R.id.invLotId)).getText().toString();
        String sHoldCode = ((TextView)findViewById(R.id.releaseCode)).getText().toString();

        if(sInvLotId.isEmpty())
        {
            showDialog(getString(R.string.alert_message_no_inv_lot_id));
            return;
        }

        if(sHoldCode.isEmpty())
        {
            showDialog(getString(R.string.alert_message_no_release_code));
            return;
        }

        showConfirmDialog(getString(R.string.alert_message_run), new Runnable() {
            @Override
            public void run() {
                requestRun();
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
                        requestInvLotList(barcode);
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

    private void init(int iSeq)
    {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화

        int iMethod = iSeq;
        switch (iMethod)
        {
            case 1 :
                //상위 리스트 초기화
                clearListView();
                break;
            default:
                break;
        }
    }

    private void clearListView(){
        ((TextView)findViewById(R.id.invLotId)).setText("");
        ((TextView)findViewById(R.id.invLotMatId)).setText("");
        ((TextView)findViewById(R.id.invLotMatDesc)).setText("");
        ((TextView)findViewById(R.id.invLotQty)).setText("");
        ((TextView)findViewById(R.id.invLotOper)).setText("");
        ((TextView)findViewById(R.id.releaseCode)).setText("");

        ((TextView)findViewById(R.id.invLotId)).requestFocus();
    }

    private void requestReleaseCodeList() {
        String requestQuery
                = "SELECT KEY_1 RELEASE_CODE, DATA_1 RELEASE_DESC"
                + " FROM MGCMTBLDAT"
                + " WHERE 1 = 1"
                + " AND FACTORY = '" + AppSettingManager.getLoginFactory(this) + "'"
                + " AND TABLE_NAME = \'C_INV_RELEASE_CODE\'";

        SQLQueryRequest request = new SQLQueryRequest(this, requestQuery);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                listReleaseModels.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            DropDownModel model = new DropDownModel();
                            model.setId(row.get("RELEASE_CODE"));
                            model.setName(row.get("RELEASE_DESC"));

                            listReleaseModels.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listReleaseModels.clear();
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

    private void showReleaseCodeDialog() {
        ComboBoxDialog dialog = new ComboBoxDialog(this);
        dialog.setDialogTitle(getString(R.string.common_word_release_code));
        dialog.setData(listReleaseModels);
        dialog.setOnSelectItemListener(new ComboBoxDialog.OnSelectItemListener() {
            @Override
            public void onClickItem(DropDownModel model) {
                String sReleaseCode = ((TextView)findViewById(R.id.releaseCode)).getText().toString();

                if(sReleaseCode.equalsIgnoreCase(model.getName()))
                    return;

                for (DropDownModel releaseModel : listReleaseModels)
                {
                    releaseModel.setSelected(false);
                }

                model.setSelected(true);

                ((TextView)findViewById(R.id.releaseCode)).setText(model.getName());
            }
        });
        dialog.showDialog();
    }

    private void requestInvLotList(final String sBarcode){
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

                ((TextView) findViewById(R.id.invLotId)).setText(sBarcode);
                ((TextView)findViewById(R.id.invLotMatId)).setText(resultMap.get(H101Const.MAT_ID).toString());
                ((TextView)findViewById(R.id.invLotMatDesc)).setText(resultMap.get(H101Const.MAT_DESC).toString());
                ((TextView)findViewById(R.id.invLotQty)).setText(FormatUtil.toNumFormat(Double.parseDouble(resultMap.get(H101Const.QTY).toString())));
                ((TextView)findViewById(R.id.invLotOper)).setText(resultMap.get(H101Const.OPER_DESC).toString());
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

    private void requestRun() {
        if(isLoading)
            return;
        isLoading = true;

        String sReleaseCode = "";
        InvReleaseLotRequest request = new InvReleaseLotRequest(this);

        request.addParam("PROCSTEP", "C", "1");

        for (DropDownModel releaseModel : listReleaseModels)
        {
            if(releaseModel.isSelected()) {
                sReleaseCode = releaseModel.getId();
                break;
            }
        }

        request.addParam("RELEASE_CODE", "S", sReleaseCode);

        DataModel data = new DataModel();
        List<VariableModel> columns = new ArrayList<>();

        columns.add(ParseH101Xml.createVariableModel("INV_LOT_ID", "S", ((TextView)findViewById(R.id.invLotId)).getText().toString()));

        data.setD(columns);
        data.setN("INV_LOT_LIST");

        request.addListParam(data);

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