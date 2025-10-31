package com.pda.mes.activity.menu;

import android.app.DatePickerDialog;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.TextView;

import com.pda.mes.R;
import com.pda.mes.activity.ToolbarActivity;
import com.pda.mes.dialog.ComboBoxDialog;
import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.SQLQueryRequest;
import com.pda.mes.h101.request.inv.InvCheckBarcodeTypeRequest;
import com.pda.mes.h101.request.inv.InvViewLotInfoRequest;
import com.pda.mes.manager.AppLogManager;
import com.pda.mes.manager.AppSettingManager;
import com.pda.mes.model.DropDownModel;
import com.pda.mes.utils.FormatUtil;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Locale;
import java.util.Map;

import device.common.ScanConst;

public class CPDA3004_PDA_Activity extends ToolbarActivity {
    public static final String TAG = CPDA3004_PDA_Activity.class.getSimpleName();
    private List<DropDownModel> listOutTypeModels = new ArrayList<>(); //기타출고유형

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        AppLogManager.printScreenNameLog(TAG, getIntent().getStringExtra(EXTRA_NAME_TITLE));
        setContentView(R.layout.activity_cpda3004, TOOLBAR_TYPE_PUSH);

        requestOutTypeList();

        EditText e = (EditText) findViewById(R.id.invLotId);

        e.addTextChangedListener(new TextWatcher() {

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

                ((TextView)findViewById(R.id.invLotMatId)).setText("");
                ((TextView)findViewById(R.id.invLotMatDesc)).setText("");
                ((TextView)findViewById(R.id.invLotQty)).setText("");
                ((TextView)findViewById(R.id.invLotUnit)).setText("");
                ((TextView)findViewById(R.id.invLotOper)).setText("");
                ((TextView)findViewById(R.id.invLotOperDesc)).setText("");

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
        this.registerReceiver(new CPDA3004_PDA_Activity.ScanResultReceiver(), filter);
    }

    //region Button Click Event
    public void onclickWindow(View view){
        resetLogoutTimer();
        InputMethodManager imm = (InputMethodManager) getSystemService(INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(((EditText)findViewById(R.id.invLotId)).getWindowToken(), 0);
    }

    public void onClickOutType(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showOutTypeDialog();
    }

    public void onClickOutDate(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showOutDateDialog();
    }

    public void onClickSearch(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        final String sLotId = ((TextView)findViewById(R.id.invLotId)).getText().toString();

        if(sLotId.isEmpty())
        {
            showDialog(getString(R.string.alert_message_no_inv_lot_id));
            return;
        }

        requestInvLotList(sLotId);
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

    private void requestOutTypeList() {
        String requestQuery
                = "SELECT KEY_1 OUT_TYPE_CODE, DATA_1 OUT_TYPE_DESC"
                + " FROM MGCMTBLDAT"
                + " WHERE 1 = 1"
                + " AND FACTORY = '" + AppSettingManager.getLoginFactory(this) + "'"
                + " AND TABLE_NAME = \'C_ETC_OUT_TYPE\'";

        SQLQueryRequest request = new SQLQueryRequest(this, requestQuery);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                listOutTypeModels.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            DropDownModel model = new DropDownModel();
                            model.setId(row.get("OUT_TYPE_CODE"));
                            model.setName(row.get("OUT_TYPE_DESC"));

                            listOutTypeModels.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listOutTypeModels.clear();
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

    private void showOutTypeDialog() {
        ComboBoxDialog dialog = new ComboBoxDialog(this);
        dialog.setDialogTitle(getString(R.string.common_word_out_type));
        dialog.setData(listOutTypeModels);
        dialog.setOnSelectItemListener(new ComboBoxDialog.OnSelectItemListener() {
            @Override
            public void onClickItem(DropDownModel model) {
                String sOutType = ((TextView)findViewById(R.id.invLotOutType)).getText().toString();

                if(sOutType.equalsIgnoreCase(model.getName()))
                    return;

                for (DropDownModel outModel : listOutTypeModels)
                {
                    outModel.setSelected(false);
                }

                model.setSelected(true);

                ((TextView)findViewById(R.id.invLotOutType)).setText(model.getName());
            }
        });
        dialog.showDialog();
    }

    private void showOutDateDialog() {
        SimpleDateFormat yearFormat = new SimpleDateFormat("yyyy", Locale.getDefault());
        SimpleDateFormat monthFormat = new SimpleDateFormat("MM", Locale.getDefault());
        SimpleDateFormat dayFormat = new SimpleDateFormat("dd", Locale.getDefault());

        Date date = new Date();

        int iTodayYear = Integer.parseInt(yearFormat.format(date));
        int iTodayMonth = Integer.parseInt(monthFormat.format(date));
        int iTodayDay = Integer.parseInt(dayFormat.format(date));

        DatePickerDialog dialog = new DatePickerDialog(this, listener, iTodayYear, iTodayMonth - 1, iTodayDay);
        dialog.show();
    }

    private DatePickerDialog.OnDateSetListener listener = new DatePickerDialog.OnDateSetListener() {
        @Override
        public void onDateSet(DatePicker view, int year, int monthOfYear, int dayOfMonth) {
            String sDate = year + "-" + String.format("%02d", monthOfYear + 1) + "-" + String.format("%02d",dayOfMonth); //FORMAT 2020-09-24

            ((TextView)findViewById(R.id.invLotOutDate)).setText(sDate);
        }
    };

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
        ((TextView)findViewById(R.id.invLotId)).setText("");
        ((TextView)findViewById(R.id.invLotMatId)).setText("");
        ((TextView)findViewById(R.id.invLotMatDesc)).setText("");
        ((TextView)findViewById(R.id.invLotQty)).setText("");
        ((TextView)findViewById(R.id.invLotUnit)).setText("");
        ((TextView)findViewById(R.id.invLotOper)).setText("");
        ((TextView)findViewById(R.id.invLotOperDesc)).setText("");

        ((TextView)findViewById(R.id.invLotId)).requestFocus();
    }

    private void requestInvLotList(final String sBarcode){
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

                Map<String, Object> resultMap = (Map<String, Object>)result;

                ((TextView)findViewById(R.id.invLotId)).setText(resultMap.get(H101Const.INV_LOT_ID).toString());
                ((TextView)findViewById(R.id.invLotMatId)).setText(resultMap.get(H101Const.MAT_ID).toString());
                ((TextView)findViewById(R.id.invLotMatDesc)).setText(resultMap.get(H101Const.MAT_DESC).toString());
                ((TextView)findViewById(R.id.invLotUnit)).setText(resultMap.get(H101Const.UNIT).toString());
                ((TextView)findViewById(R.id.invLotQty)).setText(FormatUtil.toNumFormat(Double.parseDouble(resultMap.get(H101Const.QTY).toString())));
                ((TextView)findViewById(R.id.invLotOper)).setText(resultMap.get(H101Const.OPER).toString());
                ((TextView)findViewById(R.id.invLotOperDesc)).setText(resultMap.get(H101Const.OPER_DESC).toString());
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