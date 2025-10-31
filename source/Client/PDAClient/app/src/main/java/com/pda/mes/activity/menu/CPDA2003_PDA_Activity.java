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
import com.pda.mes.adapter.CPDA2003_PDA_Adapter;
import com.pda.mes.dialog.ComboBoxDialog;
import com.pda.mes.dialog.InputDialog;
import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.prod.WipUpdateLotLossRequest;
import com.pda.mes.h101.request.prod.WipViewLotInfoRequest;
import com.pda.mes.h101.request.prod.WipViewOperListRequest;
import com.pda.mes.h101.request.prod.WipViewOperLossRequest;
import com.pda.mes.h101.request.inv.InvCheckBarcodeTypeRequest;
import com.pda.mes.manager.AppLogManager;
import com.pda.mes.model.DropDownModel;
import com.pda.mes.model.WIPModel;
import com.pda.mes.model.parser.DataModel;
import com.pda.mes.model.parser.VariableModel;
import com.pda.mes.utils.FormatUtil;
import com.pda.mes.utils.ParseH101Xml;
import com.pda.mes.utils.StringUtil;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import device.common.ScanConst;

public class CPDA2003_PDA_Activity extends ToolbarActivity {
    public static final String TAG = CPDA2003_PDA_Activity.class.getSimpleName();

    private CPDA2003_PDA_Adapter adapter; // 리스트뷰 어댑터
    private ListView listView; // 뷰모델 리스트뷰
    private List<WIPModel> listLossModel = new ArrayList<>(); // 불량 리스트 모델
    private List<DropDownModel> listCauseOperModels = new ArrayList<>(); //CAUSE OPER LIST
    private boolean isLoading = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        AppLogManager.printScreenNameLog(TAG, getIntent().getStringExtra(EXTRA_NAME_TITLE));
        setContentView(R.layout.activity_cpda2003, TOOLBAR_TYPE_PUSH);

        adapter = new CPDA2003_PDA_Adapter(this);
        listView = findViewById(R.id.listView);

        adapter.setModels(listLossModel);
        listView.setAdapter(adapter);

        //수량 셀 클릭시 INPUT팝업 활성화
        adapter.setOnClickCellListener(new CPDA2003_PDA_Adapter.OnClickCellListener() {

            @Override
            public void onClickInput(WIPModel model) {
                inputValue(model);
            }

        });

        EditText e = (EditText) findViewById(R.id.lotId);

        e.addTextChangedListener(new TextWatcher() {

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

                ((TextView)findViewById(R.id.area)).setText("");
                ((TextView)findViewById(R.id.subArea)).setText("");
                ((TextView)findViewById(R.id.oper)).setText("");
                ((TextView)findViewById(R.id.oper)).setTag("");
                ((TextView)findViewById(R.id.itemCode)).setText("");
                ((TextView)findViewById(R.id.itemDesc)).setText("");
                ((TextView)findViewById(R.id.workQty)).setText("");
                ((TextView)findViewById(R.id.goodLossQty)).setText("");

                listLossModel.clear();
                adapter.notifyDataSetChanged();

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
        this.registerReceiver(new CPDA2003_PDA_Activity.ScanResultReceiver(), filter);
    }

    //region Button Click Event
    public void onclickWindow(View view){
        resetLogoutTimer();
        InputMethodManager imm = (InputMethodManager) getSystemService(INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(((EditText)findViewById(R.id.lotId)).getWindowToken(), 0);
    }

    public void onClickSave(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화

        double dTotalLossQty = 0;

        if(listLossModel.size() <= 0)
        {
            showDialog(getString(R.string.alert_message_no_object));
            return;
        }

        for (WIPModel model : listLossModel)
        {
            dTotalLossQty += model.getLossQty();
        }

        if(dTotalLossQty <= 0)
        {
            showDialog(getString(R.string.alert_message_no_loss_object));
            return;
        }

        showConfirmDialog(getString(R.string.alert_message_processing), new Runnable() {
            @Override
            public void run() {
                requestSave();
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
                    case H101Const.LOT :
                        requestLotList(barcode);
                        break;
                    default:
                        startAlarm();
                        showDialog(getString(R.string.alert_message_error_no_registered_barcode));
                        ((TextView) findViewById(R.id.lotId)).setText("");
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
                clearBottomView();
                break;
            default:
                break;
        }
    }

    private void clearBottomView() {
        listLossModel.clear();
        adapter.notifyDataSetChanged();
    }

    private void requestLotList(final String sLotId){
        if(isLoading)
            return;
        isLoading = true;

        WipViewLotInfoRequest request = new WipViewLotInfoRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("LOT_ID", "S", sLotId);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                isLoading = false;

                Map<String, Object> resultMap = (Map<String, Object>)result;

                for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                    ((TextView)findViewById(R.id.lotId)).setText(sLotId);
                    ((TextView)findViewById(R.id.area)).setText(row.get(H101Const.AREA_DESC));
                    ((TextView)findViewById(R.id.area)).setTag(row.get(H101Const.AREA_ID));
                    ((TextView)findViewById(R.id.subArea)).setText(row.get(H101Const.SUB_AREA_DESC));
                    ((TextView)findViewById(R.id.oper)).setText(row.get(H101Const.OPER_DESC));
                    ((TextView)findViewById(R.id.oper)).setTag(row.get(H101Const.OPER)); //공정별 불량을 가져오기 위해 필요
                    ((TextView)findViewById(R.id.itemCode)).setText(row.get(H101Const.MAT_ID));
                    ((TextView)findViewById(R.id.itemDesc)).setText(row.get(H101Const.MAT_DESC));
                    ((TextView)findViewById(R.id.workQty)).setText(FormatUtil.toNumFormat(Double.parseDouble(row.get(H101Const.QTY_1))));
                    ((TextView)findViewById(R.id.goodLossQty)).setText("0 / 0");
                    ((TextView)findViewById(R.id.causeOper)).setText(row.get(H101Const.OPER_DESC));
                    ((TextView)findViewById(R.id.causeOper)).setTag(row.get(H101Const.OPER)); //공정별 불량을 가져오기 위해 필요

                    break;
                }

                String sOper =  ((TextView)findViewById(R.id.oper)).getTag().toString();

                requestLossList(sOper);
            }

            @Override
            public void onFailure(Exception exception) {
                isLoading = false;
                showDialog(exception.getMessage());
            }

            @Override
            public void onFinish() {
                requestCauseOper(((TextView)findViewById(R.id.area)).getTag().toString());
                isLoading = false;
                hideLoadingDialog();
            }
        });
    }

    private void requestLossList(String sOper){
        WipViewOperLossRequest request = new WipViewOperLossRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("OPER", "S", sOper);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                isLoading = false;

                listLossModel.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS"))
                {
                    try{
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            WIPModel model = new WIPModel();
                            model.setLossCode(row.get("LOSS_CODE"));
                            model.setLossDesc(row.get("LOSS_DESC"));
                            model.setLossQty(0);

                            listLossModel.add(model);
                        }
                    } catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listLossModel.clear();
                    }

                    adapter.notifyDataSetChanged();
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

    private void requestSave() {
        if(isLoading)
            return;
        isLoading = true;

        double dTotalLossQty = 0;

        WipUpdateLotLossRequest request = new WipUpdateLotLossRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("LOT_ID", "S", ((TextView)findViewById(R.id.lotId)).getText().toString());
        request.addParam("OPER", "S", ((TextView)findViewById(R.id.oper)).getTag().toString());
        request.addParam("CUASE_OPER", "S", ((TextView)findViewById(R.id.causeOper)).getTag().toString());
        request.addParam("CAUSE_FLOW", "S", ""); //필수 X
        request.addParam("RES_ID", "S", "");
        request.addParam("COMMENT", "S", ""); //비고

        for (WIPModel model : listLossModel) {
            if(model.getLossQty() > 0)
            {
                DataModel data = new DataModel();
                List<VariableModel> columns = new ArrayList<>();

                columns.add(ParseH101Xml.createVariableModel("CODE", "S", model.getLossCode()));
                columns.add(ParseH101Xml.createVariableModel("VALUE", "F8", String.valueOf(model.getLossQty())));

                dTotalLossQty += model.getLossQty();

                data.setD(columns);
                data.setN("LOSS_TBL");

                request.addListParam(data);
            }
        }

        request.addParam("OUT_QTY_1", "F8", String.valueOf(dTotalLossQty)); //총 LOSS 수량

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

                requestLotList(((TextView)findViewById(R.id.lotId)).getText().toString());
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

    private void inputValue(final WIPModel model) {
        InputDialog dialog = new InputDialog(this);
        dialog.setDialog(getString(R.string.common_word_loss_qty), "0", FormatUtil.toNumFormat(model.getLossQty()));
        dialog.setOnInputMessageListener(new InputDialog.OnInputMessageListener() {
            @Override
            public void onClickDone(String value) {

                if(StringUtil.isNullOrEmpty(value)) {
                    return;
                }

                double inputValue = FormatUtil.convertStringToDouble(value);

                String sGoodLossQty = "";
                double dTotalLossQty = 0;
                double dWorkQty = Double.parseDouble(((TextView)findViewById(R.id.workQty)).getText().toString());

                for (WIPModel wipModel : listLossModel)
                {
                    if(!model.getLossCode().equalsIgnoreCase(wipModel.getLossCode()))
                        dTotalLossQty += wipModel.getLossQty();
                }

                dTotalLossQty += inputValue;

                sGoodLossQty += Double.toString(dWorkQty - dTotalLossQty);
                sGoodLossQty += " / ";
                sGoodLossQty += Double.toString(dTotalLossQty);

                if(dWorkQty < dTotalLossQty) {
                    showDialog(getString(R.string.alert_message_loss_over_work_qty), new Runnable() {
                        @Override
                        public void run() {
                            inputValue(model);
                        }
                    });
                    return;
                }

                model.setLossQty(FormatUtil.convertStringToDouble(value));

                ((TextView)findViewById(R.id.goodLossQty)).setText(sGoodLossQty);

                adapter.notifyDataSetChanged();
            }
        });

        dialog.show();
    }

    public void onClickCauseOper(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showCauseOperDialog();
    }

    private void showCauseOperDialog() {
        ComboBoxDialog dialog = new ComboBoxDialog(this);
        dialog.setDialogTitle(getString(R.string.common_word_cause_oper));
        dialog.setData(listCauseOperModels);
        dialog.setOnSelectItemListener(new ComboBoxDialog.OnSelectItemListener() {
            @Override
            public void onClickItem(DropDownModel model) {
                String sCauseOper = ((TextView)findViewById(R.id.causeOper)).getText().toString();

                if(sCauseOper.equalsIgnoreCase(model.getName()))
                    return;

                for (DropDownModel causeOperModel : listCauseOperModels)
                {
                    causeOperModel.setSelected(false);
                }

                model.setSelected(true);

                ((TextView)findViewById(R.id.causeOper)).setText(model.getName());
                ((TextView)findViewById(R.id.causeOper)).setTag(model.getId());
            }
        });
        dialog.showDialog();
    }

    private void requestCauseOper(String sArea) {
        WipViewOperListRequest request = new WipViewOperListRequest(this);

        request.addParam("PROCSTEP", "C", "2");
        request.addParam("AREA_ID", "S", sArea);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                listCauseOperModels.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            DropDownModel model = new DropDownModel();
                            model.setId(row.get("OPER"));
                            model.setName(row.get("OPER_DESC"));
                            model.setSelected(false);
                            listCauseOperModels.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listCauseOperModels.clear();
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

    //endregion
}