package com.pda.mes.activity.menu;

import android.app.DatePickerDialog;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.icu.text.UFormat;
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
import com.pda.mes.h101.request.inv.InvTerminateLotRequest;
import com.pda.mes.h101.request.inv.InvValidEtcOutLotRequest;
import com.pda.mes.manager.AppLogManager;
import com.pda.mes.manager.AppSettingManager;
import com.pda.mes.model.DropDownModel;
import com.pda.mes.model.parser.DataModel;
import com.pda.mes.model.parser.VariableModel;
import com.pda.mes.utils.FormatUtil;
import com.pda.mes.utils.ParseH101Xml;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Locale;
import java.util.Map;

import device.common.ScanConst;

public class CPDA2013_PDA_Activity extends ToolbarActivity {
    public static final String TAG = CPDA2013_PDA_Activity.class.getSimpleName();
    private List<DropDownModel> listOutTypeModels = new ArrayList<>(); //기타출고유형

    private boolean isLoading = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        AppLogManager.printScreenNameLog(TAG, getIntent().getStringExtra(EXTRA_NAME_TITLE));
        setContentView(R.layout.activity_cpda2013, TOOLBAR_TYPE_PUSH);

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
                ((TextView)findViewById(R.id.OutQty)).setText("");
                ((TextView)findViewById(R.id.invLotOutType)).setText("");
                ((TextView)findViewById(R.id.invLotOutDate)).setText("");
                ((TextView)findViewById(R.id.invLotRemark)).setText("");

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
        this.registerReceiver(new CPDA2013_PDA_Activity.ScanResultReceiver(), filter);
    }

    //region Button Click Event
    public void onclickWindow(View view){
        resetLogoutTimer();
        InputMethodManager imm = (InputMethodManager) getSystemService(INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(((EditText)findViewById(R.id.invLotId)).getWindowToken(), 0);
        imm.hideSoftInputFromWindow(((EditText)findViewById(R.id.invLotRemark)).getWindowToken(), 0);
    }

    public void onClickOutType(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showOutTypeDialog();
    }

    public void onClickOutDate(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showOutDateDialog();
    }

    public void onClickRun(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        final String sLotId = ((TextView)findViewById(R.id.invLotId)).getText().toString();
        String sOutType = "";
        String sOutDate = ((TextView)findViewById(R.id.invLotOutDate)).getText().toString();
        String sOutQty = ((TextView)findViewById(R.id.OutQty)).getText().toString();

        if(sLotId.isEmpty())
        {
            showDialog(getString(R.string.alert_message_no_inv_lot_id));
            return;
        }

        for (DropDownModel outTypeModel : listOutTypeModels)
        {
            if(outTypeModel.isSelected()) {
                sOutType = outTypeModel.getId();
                break;
            }
        }

        if(sOutQty.isEmpty())
        {
            showDialog(getString(R.string.alert_message_no_out_qty));
            return;
        }

        if(FormatUtil.convertStringToDouble(sOutQty) <= 0)
        {
            showDialog(getString(R.string.alert_message_no_out_qty));
            return;
        }

        if(sOutType.isEmpty())
        {
            showDialog(getString(R.string.alert_message_no_out_type));
            return;
        }

        if(sOutDate.isEmpty())
        {
            showDialog(getString(R.string.alert_message_no_out_date));
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

    private void requestOutTypeList(String sAreaId) {
        String requestQuery
                = "SELECT TRAN_TYPE_ID, TRAN_SRC_DESC "
                + "  FROM CBASTXNDEF "
                + " WHERE     FACTORY = '" + AppSettingManager.getLoginFactory(this) + "'"
                + "       AND TRAN_SRC_TYPE_NAME = 'Account' "
                + "       AND AREA_ID = '" + sAreaId + "'"
                + "       AND ISSUE_RECEIPT_FLAG = 'ISSUE' ";

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
                            model.setId(row.get("TRAN_TYPE_ID"));
                            model.setName(row.get("TRAN_SRC_DESC"));

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
        ((TextView)findViewById(R.id.OutQty)).setText("");
        ((TextView)findViewById(R.id.invLotOutType)).setText("");
        ((TextView)findViewById(R.id.invLotOutDate)).setText("");
        ((TextView)findViewById(R.id.invLotRemark)).setText("");

        ((TextView)findViewById(R.id.invLotId)).requestFocus();
    }

    private void requestInvLotList(final String sBarcode){
        if(isLoading)
            return;
        isLoading = true;

        InvValidEtcOutLotRequest request = new InvValidEtcOutLotRequest(this);

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

                ((TextView)findViewById(R.id.invLotId)).setText(resultMap.get(H101Const.INV_LOT_ID).toString());
                ((TextView)findViewById(R.id.invLotMatId)).setText(resultMap.get(H101Const.MAT_ID).toString());
                ((TextView)findViewById(R.id.invLotMatDesc)).setText(resultMap.get(H101Const.MAT_DESC).toString());
                ((TextView)findViewById(R.id.invLotUnit)).setText(resultMap.get(H101Const.UNIT).toString());
                ((TextView)findViewById(R.id.invLotQty)).setText(FormatUtil.toNumFormat(Double.parseDouble(resultMap.get(H101Const.QTY).toString())));
                ((TextView)findViewById(R.id.OutQty)).setText(FormatUtil.toNumFormat(Double.parseDouble(resultMap.get(H101Const.QTY).toString())));
                ((TextView)findViewById(R.id.invLotOper)).setText(resultMap.get(H101Const.OPER).toString());
                ((TextView)findViewById(R.id.invLotOperDesc)).setText(resultMap.get(H101Const.OPER_DESC).toString());
                ((TextView)findViewById(R.id.invLotRemark)).setText("");

                requestOutTypeList(resultMap.get(H101Const.AREA_ID).toString());
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

        String sOutType = "";
        String sOutDate = ((TextView)findViewById(R.id.invLotOutDate)).getText().toString().replace("-", "");
        String sOutQty = ((TextView)findViewById(R.id.OutQty)).getText().toString();

        InvTerminateLotRequest request = new InvTerminateLotRequest(this);

        request.addParam("PROCSTEP", "C", "2");

        for (DropDownModel outTypeModel : listOutTypeModels)
        {
            if(outTypeModel.isSelected()) {
                sOutType = outTypeModel.getId();
                break;
            }
        }

        request.addParam("ETC_OUT_TYPE", "S", sOutType);
        request.addParam("OUT_DATE", "S", sOutDate);
        request.addParam("ERP_FLAG", "C", "Y");

        DataModel data = new DataModel();
        List<VariableModel> columns = new ArrayList<>();

        columns.add(ParseH101Xml.createVariableModel("INV_LOT_ID", "S", ((TextView)findViewById(R.id.invLotId)).getText().toString()));
        columns.add(ParseH101Xml.createVariableModel("OUT_QTY", "F8", sOutQty));

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