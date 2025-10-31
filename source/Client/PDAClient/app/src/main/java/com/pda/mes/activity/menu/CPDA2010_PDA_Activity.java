package com.pda.mes.activity.menu;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.AdapterView;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;

import com.pda.mes.R;
import com.pda.mes.activity.ToolbarActivity;
import com.pda.mes.adapter.CPDA2010_PDA_BottomAdapter;
import com.pda.mes.adapter.CPDA2010_PDA_TopAdapter;
import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.inv.InvCheckBarcodeTypeRequest;
import com.pda.mes.h101.request.inv.InvConfirmIssueRequest;
import com.pda.mes.h101.request.inv.InvDeleteIssueLotRequest;
import com.pda.mes.h101.request.inv.InvViewIssueRequest;
import com.pda.mes.h101.request.inv.InvIssueLotRequest;
import com.pda.mes.h101.request.inv.InvCreateIssueLotRequest;
import com.pda.mes.h101.request.inv.InvValidIssueLotRequest;
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

public class CPDA2010_PDA_Activity extends ToolbarActivity {
    public static final String TAG = CPDA2010_PDA_Activity.class.getSimpleName();

    private CPDA2010_PDA_TopAdapter topAdapter; // 상단 리스트뷰 어댑터
    private CPDA2010_PDA_BottomAdapter bottomAdapter; //하단 리스트뷰 어댑터
    private ListView listTopView; // 뷰모델 상단 리스트뷰
    private ListView listBottomView; // 뷰모델 하단 리스트뷰
    private List<INVModel> listInvRequestModel = new ArrayList<>(); // 라벨 뷰모델 리스트
    private List<INVModel> listLotModel = new ArrayList<>(); // 라벨 뷰모델 리스트
    private List<String> listLot = new ArrayList<>();//중복제거를 위한 LOT확인
    private boolean isLoading = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        AppLogManager.printScreenNameLog(TAG, getIntent().getStringExtra(EXTRA_NAME_TITLE));
        setContentView(R.layout.activity_cpda2010, TOOLBAR_TYPE_PUSH);

        topAdapter = new CPDA2010_PDA_TopAdapter(this);
        listTopView = findViewById(R.id.listTopView);

        topAdapter.setModels(listInvRequestModel);
        listTopView.setAdapter(topAdapter);

        bottomAdapter = new CPDA2010_PDA_BottomAdapter(this);
        listBottomView = findViewById(R.id.listBottomView);

        bottomAdapter.setModels(listLotModel);
        listBottomView.setAdapter(bottomAdapter);

        listBottomView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int position, long l) {
                resetLogoutTimer(); // 로그아웃 체크 시간 초기화

                for(int i = 0 ; i < bottomAdapter.getCount() ; i++) {
                    INVModel model = (INVModel)bottomAdapter.getItem(i);

                    if(i == position) {
                        if(model.isSelected()) {
                            model.setSelected(false);

                        } else if(!model.isSelected()) {
                            model.setSelected(true);
                        }
                    }
                }

                bottomAdapter.notifyDataSetChanged();
            }
        });

        EditText e = (EditText) findViewById(R.id.issueReqNo);

        e.addTextChangedListener(new TextWatcher() {

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

                ((TextView)findViewById(R.id.invLotId)).setText("");

                listInvRequestModel.clear();
                listLotModel.clear();

                topAdapter.notifyDataSetChanged();
                bottomAdapter.notifyDataSetChanged();

                setTotalCount();

                if (before == 0 && count == 1 && s.charAt(start) == '\n') {
                    String sData = ((TextView)findViewById(R.id.issueReqNo)).getText().toString().replaceAll ("\n", "");

                    if(sData.isEmpty())
                    {
                        ((TextView) findViewById(R.id.issueReqNo)).setText("");
                        return;
                    }

                    requestBarcodeType(sData, "INV_REQ_NO");
                }

            }
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {}
            @Override
            public void afterTextChanged(Editable s) {}
        });

        EditText f = (EditText) findViewById(R.id.invLotId);

        f.addTextChangedListener(new TextWatcher() {

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

                if (before == 0 && count == 1 && s.charAt(start) == '\n') {
                    String sData = ((TextView)findViewById(R.id.invLotId)).getText().toString().replaceAll ("\n", "");

                    if(sData.isEmpty())
                    {
                        ((TextView) findViewById(R.id.invLotId)).setText("");
                        return;
                    }

                    requestBarcodeType(sData, "INV_LOT_ID");
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
        this.registerReceiver(new CPDA2010_PDA_Activity.ScanResultReceiver(), filter);
    }

    //region Button Click Event
    public void onclickWindow(View view){
        resetLogoutTimer();
        InputMethodManager imm = (InputMethodManager) getSystemService(INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(((EditText)findViewById(R.id.issueReqNo)).getWindowToken(), 0);
        imm.hideSoftInputFromWindow(((EditText)findViewById(R.id.invLotId)).getWindowToken(), 0);
    }

    private void clearBottomListView() {
        ((TextView)findViewById(R.id.invLotId)).setText("");

        listLotModel.clear();
        bottomAdapter.notifyDataSetChanged();

        setTotalCount();

        ((TextView)findViewById(R.id.invLotId)).requestFocus();
    }

    private void clearAllListView(){
        ((TextView)findViewById(R.id.issueReqNo)).setText("");
        ((TextView)findViewById(R.id.invLotId)).setText("");

        listInvRequestModel.clear();
        listLotModel.clear();

        topAdapter.notifyDataSetChanged();
        bottomAdapter.notifyDataSetChanged();

        setTotalCount();

        ((TextView)findViewById(R.id.issueReqNo)).requestFocus();
    }

    private void requestInvReqList(final String sInvReqNo){
        if(isLoading)
            return;
        isLoading = true;

        InvViewIssueRequest request = new InvViewIssueRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("REQ_NO", "S", sInvReqNo);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                isLoading = false;
                listLotModel.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    try {
                        ((TextView) findViewById(R.id.issueReqNo)).setText(sInvReqNo);

                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            INVModel model = new INVModel();

                            model.setInvReqNo(row.get("REQ_NO"));
                            model.setMatId(row.get("REQ_MAT_ID"));
                            model.setDesc(row.get("MAT_DESC"));
                            model.setMatVer(row.get("REQ_MAT_VER"));
                            model.setReqQty(FormatUtil.convertStringToDouble(row.get("REQ_QTY")));
                            model.setRegQty(FormatUtil.convertStringToDouble(row.get("REG_QTY")));
                            model.setUnit(row.get("UNIT"));
                            model.setStock(row.get("OPER_DESC"));

                            listInvRequestModel.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listLotModel.clear();
                    }

                    topAdapter.notifyDataSetChanged(); // 리스트 갱신
                    //하위 리스트 초기화
                    init(1);

                    requestLotItemList(sInvReqNo);
                }
                // 요청번호에 해당하는 데이터가 없는경우
                else {
                    startAlarm();
                    showDialog(getString(R.string.alert_message_not_found_inv_req_no));
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

    private void init(int iSeq)
    {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화

        int iMethod = iSeq;
        switch (iMethod)
        {
            case 1 :
                //아래 리스트 초기화
                clearBottomListView();
                break;
            case 2 :
                clearAllListView();
                break;
            default:
                break;
        }
    }

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
                    case H101Const.ISSUE_REQUEST :
                        requestInvReqList(barcode);
                        break;
                    case H101Const.INV_LOT :
                        ((TextView) findViewById(R.id.invLotId)).setText(barcode);
                        requestInvLotValid(barcode);
                        break;
                    default:
                        startAlarm();
                        showDialog(getString(R.string.alert_message_error_no_registered_barcode));
                        if(type.equalsIgnoreCase("INV_REQ_NO"))
                            ((TextView)findViewById(R.id.issueReqNo)).setText("");
                        else if(type.equalsIgnoreCase("INV_LOT_ID"))
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

    private void requestLotItemList(final String sInvReqNo)
    {
        if(isLoading)
            return;
        isLoading = true;

        InvIssueLotRequest request = new InvIssueLotRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("REQ_NO", "S", sInvReqNo);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                isLoading = false;

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    listLotModel.clear();

                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            INVModel model = new INVModel();

                            model.setLotId(row.get("REQ_LOT_ID"));
                            model.setMatId(row.get("REQ_MAT_ID"));
                            model.setDesc(row.get("MAT_DESC"));
                            model.setMatVer(row.get("REQ_MAT_VER"));
                            model.setQty(FormatUtil.convertStringToDouble(row.get("REQ_QTY")));
                            model.setUnit(row.get("UNIT"));
                            model.setStatus(row.get("REQ_STATUS"));

                            listLotModel.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listLotModel.clear();
                    }

                    bottomAdapter.notifyDataSetChanged(); // 리스트 갱신
                    //animateListTopLayout(true); // 리스트 보여주기

                    setTotalCount();
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

    public void requestInvLotValid(final String sLotId){
        ((TextView) findViewById(R.id.invLotId)).setText("");
        String sReqNo = ((TextView) findViewById(R.id.issueReqNo)).getText().toString();

        if(sReqNo.isEmpty())
        {
            showDialog((getString(R.string.alert_message_not_found_inv_req_no)));
            return;
        }

        InvValidIssueLotRequest request = new InvValidIssueLotRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("REQ_NO", "S", ((TextView) findViewById(R.id.issueReqNo)).getText().toString());

        //입력된 LOT이 없을 경우 에러
        if(sLotId.isEmpty())
        {
            showDialog((getString(R.string.alert_message_lot_empty)));
            return;
        }

        for (INVModel lotModel : listLotModel) {
            // 동일한 LOT번호 있는지 체크
            if (lotModel.getLotId().equalsIgnoreCase(sLotId)) {
                showDialog((getString(R.string.alert_message_error_scan_wrong_duplicate)));
                return;
            }
        }

        request.addParam("REQ_LOT_ID", "S", sLotId);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                int iSelection = 0;

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {
                            INVModel model = new INVModel();

                            model.setLotId(row.get("REQ_LOT_ID"));
                            model.setMatId(row.get("REQ_MAT_ID"));
                            model.setDesc(row.get("MAT_DESC"));
                            model.setMatVer(row.get("REQ_MAT_VER"));
                            model.setQty(FormatUtil.convertStringToDouble(row.get("REQ_QTY")));
                            model.setUnit(row.get("UNIT"));
                            model.setStatus(row.get("REQ_STATUS"));
                            model.setSelected(true);

                            iSelection = listLotModel.size() + 1;

                            listLotModel.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listLotModel.clear();
                    }

                    bottomAdapter.notifyDataSetChanged(); // 리스트 갱신

                    listBottomView.setSelection(iSelection);

                    setTotalCount();
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

    private void setTotalCount(){
        ((TextView) findViewById(R.id.totalCount)).setText(FormatUtil.toNumFormat(listLotModel.size()));
    }

    //저장버튼 클릭시
    public void onClickSave(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화

        int iSelectLot = 0;

        for (INVModel model : listLotModel)
        {
            if(model.isSelected())
            {
                if(model.getStatus() != null && model.getStatus() != "")
                {
                    showDialog(model.getLotId() + " : " + getString(R.string.alert_message_no_process_lot));
                    return;
                }

                iSelectLot++;
            }
        }

        if(iSelectLot <= 0) {
            showDialog(getString(R.string.alert_message_no_object));
            return;
        }

        showConfirmDialog(getString(R.string.alert_message_save), new Runnable() {
            @Override
            public void run() {
                requestSave();
            }
        });
    }

    public void onClickConfirm(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화

        if(null == listInvRequestModel || listInvRequestModel.isEmpty()) {
            showDialog(getString(R.string.alert_message_no_object));
            return;
        }

        showConfirmDialog(getString(R.string.alert_message_confirm), new Runnable() {
            @Override
            public void run() {
                requestConfirm();
            }
        });
    }

    public void onClickDelete(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        int iSelectLot = 0;

        for (INVModel model : listLotModel)
        {
            if(model.isSelected())
            {
                String sStatus = model.getStatus() == null ? "" : model.getStatus();

                if(!sStatus.equalsIgnoreCase("REGIST"))
                {
                    showDialog(model.getLotId() + " : " + getString(R.string.alert_message_no_process_lot));
                    return;
                }

                iSelectLot++;
            }
        }

        if(iSelectLot <= 0) {
            showDialog(getString(R.string.alert_message_no_object));
            return;
        }

        showConfirmDialog(getString(R.string.alert_message_delete), new Runnable() {
            @Override
            public void run() {
                requestDelete();
            }
        });
    }

    public void onClickClear(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showConfirmDialog(getString(R.string.alert_message_clear), new Runnable() {
            @Override
            public void run() {
                init(2);
            }
        });
    }

    public void onClickClose(View view){
        this.finish();
    }

    private void requestSave() {

        InvCreateIssueLotRequest request = new InvCreateIssueLotRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("REQ_NO", "S", ((TextView)findViewById(R.id.issueReqNo)).getText().toString());

        for (INVModel model : listLotModel) {
            if(model.isSelected())
            {
                DataModel data = new DataModel();
                List<VariableModel> columns = new ArrayList<>();

                columns.add(ParseH101Xml.createVariableModel("REQ_LOT_ID", "S", model.getLotId()));

                data.setD(columns);
                data.setN("REQ_LOT_LIST");

                request.addListParam(data);
            }
        }

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                showToast(getString(R.string.processing_completed));

                requestInvReqList(((TextView) findViewById(R.id.issueReqNo)).getText().toString());
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

    private void requestDelete()
    {
        InvDeleteIssueLotRequest request = new InvDeleteIssueLotRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("REQ_NO", "S", ((TextView)findViewById(R.id.issueReqNo)).getText().toString());

        for (INVModel model : listLotModel) {
            if(model.isSelected())
            {
                DataModel data = new DataModel();
                List<VariableModel> columns = new ArrayList<>();

                columns.add(ParseH101Xml.createVariableModel("REQ_LOT_ID", "S", model.getLotId()));

                data.setD(columns);
                data.setN("REQ_LOT_LIST");

                request.addListParam(data);
            }
        }

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                showToast(getString(R.string.processing_completed));

                requestInvReqList(((TextView) findViewById(R.id.issueReqNo)).getText().toString());
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

    private void requestConfirm() {

        InvConfirmIssueRequest request = new InvConfirmIssueRequest(this);
        request.addParam("PROCSTEP", "C", "3");
        request.addParam("REQ_NO", "S", ((TextView)findViewById(R.id.issueReqNo)).getText().toString());

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                showToast(getString(R.string.processing_completed));
                init(2);
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
}
