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
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;

import com.pda.mes.R;
import com.pda.mes.activity.ToolbarActivity;
import com.pda.mes.adapter.CPDA2015_PDA_BottomAdapter;
import com.pda.mes.adapter.CPDA2015_PDA_TopAdapter;
import com.pda.mes.dialog.ComboBoxDialog;
import com.pda.mes.dialog.ComboBoxShipOrderDialog;
import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.SQLQueryRequest;
import com.pda.mes.h101.request.inv.InvCheckBarcodeTypeRequest;
import com.pda.mes.h101.request.shp.ShpShipLotRequest;
import com.pda.mes.h101.request.shp.ShpViewOrderListRequest;
import com.pda.mes.manager.AppLogManager;
import com.pda.mes.manager.AppSettingManager;
import com.pda.mes.model.DropDownModel;
import com.pda.mes.model.SHPModel;
import com.pda.mes.model.parser.DataModel;
import com.pda.mes.model.parser.VariableModel;
import com.pda.mes.utils.FormatUtil;
import com.pda.mes.utils.ParseH101Xml;

import java.sql.Timestamp;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;

import device.common.ScanConst;

public class CPDA2015_PDA_Activity extends ToolbarActivity {
    public static final String TAG = CPDA2015_PDA_Activity.class.getSimpleName();

    private CPDA2015_PDA_TopAdapter topAdapter; // 상단 리스트뷰 어댑터
    private CPDA2015_PDA_BottomAdapter bottomAdapter; //하단 리스트뷰 어댑터
    private ListView listTopView; // 뷰모델 상단 리스트뷰
    private ListView listBottomView; // 뷰모델 하단 리스트뷰
    private List<SHPModel> listInvShipModels = new ArrayList<>(); // 라벨 뷰모델 리스트
    private List<SHPModel> listLotModel = new ArrayList<>(); // 라벨 뷰모델 리스트
    private List<SHPModel> listShipOrderModels = new ArrayList<>(); // 출하지시 리스트
    private Map <String,Double> boxMap =  new HashMap<String,Double>();
    private Map <String,Double> finalBoxMap =  new HashMap<String,Double>();
    private boolean isLoading = false;
    private String sShipSeq = "";
    private String sAreaId = "";
    private SHPModel mSelectedTopModel = null;
    CheckBox mCheckAll;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        AppLogManager.printScreenNameLog(TAG, getIntent().getStringExtra(EXTRA_NAME_TITLE));
        setContentView(R.layout.activity_cpda2015, TOOLBAR_TYPE_PUSH);

        topAdapter = new CPDA2015_PDA_TopAdapter(this);
        listTopView = findViewById(R.id.listTopView);

        topAdapter.setModels(listInvShipModels);
        listTopView.setAdapter(topAdapter);
        listTopView.requestFocusFromTouch();

        bottomAdapter = new CPDA2015_PDA_BottomAdapter(this);
        listBottomView = findViewById(R.id.listBottomView);

        bottomAdapter.setModels(listLotModel);
        listBottomView.setAdapter(bottomAdapter);

        EditText f = (EditText) findViewById(R.id.lotAll);
        mCheckAll = (CheckBox) findViewById(R.id.select_all);


        f.addTextChangedListener(new TextWatcher() {

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

                if (before == 0 && count == 1 && s.charAt(start) == '\n') {
                    String sData = ((TextView)findViewById(R.id.lotAll)).getText().toString().replaceAll ("\n", "");

                    if(sData.isEmpty())
                    {
                        ((TextView) findViewById(R.id.lotAll)).setText("");
                        return;
                    }

                    requestBarcodeType(sData, "LOT_ALL");
                }

            }
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {}
            @Override
            public void afterTextChanged(Editable s) {}
        });

        listTopView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int position, long l) {
                resetLogoutTimer(); // 로그아웃 체크 시간 초기화

                if(isLoading)
                    return;

                isLoading = true;

                for(int i = 0 ; i < topAdapter.getCount() ; i++) {
                    ((SHPModel)topAdapter.getItem(i)).setSelected(i == position ? true : false);
                    if (i == position) {
                        mSelectedTopModel = (SHPModel)topAdapter.getItem(i);
                    }
                }

                topAdapter.notifyDataSetChanged();

                isLoading = false;

                if(!"HM".equals(sAreaId))
                {
                    for (SHPModel model : listInvShipModels) {
                        if (model.isSelected()) {

                            String sShipNo = model.getShipNo();
                            sShipSeq = String.valueOf(model.getSeq());

                            requsetShipLotList(sShipNo, sShipSeq);
                            break;
                        }
                    }
                }
            }
        });

        listBottomView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int position, long l) {
                resetLogoutTimer(); // 로그아웃 체크 시간 초기화

                for(int i = 0 ; i < bottomAdapter.getCount() ; i++) {
                    SHPModel model = (SHPModel)bottomAdapter.getItem(i);

                    if(i == position) {
                        if(model.isSelected()) {
                            model.setSelected(false);
                        } else if(!model.isSelected()) {
                            model.setSelected(true);
                        }
                    }
                }

                bottomAdapter.notifyDataSetChanged();

                setTotalCount();
            }
        });

        ((TextView) findViewById(R.id.shipNo)).requestFocus();
    }

    @Override
    protected void onResume() {
        super.onResume();
        this.registerReceiver(new CPDA2015_PDA_Activity.ScanResultReceiver(), filter);
    }

    //region Button Click Event
    public void onclickWindow(View view){
        resetLogoutTimer();
        InputMethodManager imm = (InputMethodManager) getSystemService(INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(((EditText)findViewById(R.id.lotAll)).getWindowToken(), 0);
    }

    public void onClickShipNo(View view) throws InterruptedException {
        resetLogoutTimer();
        showShipNoDialog();
    }

    public void onClickRegist(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        int iSelect = 0;

        for (SHPModel model : listLotModel)
        {
            if(model.isSelected())
            {
                if(model.getShipNo() != null && model.getShipNo() != "")
                {
                    model.setSelected(false);
                }
                else
                {
                    iSelect++;
                }
            }
        }

        bottomAdapter.notifyDataSetChanged();

        if(iSelect <= 0)
        {
            showDialog(getString(R.string.alert_message_no_object));
            return;
        }

        showConfirmDialog(getString(R.string.alert_message_regist), new Runnable() {
            @Override
            public void run() {
                requestRegist();
            }
        });
    }

    public void onClickCancel(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        int iSelect = 0;

        for (SHPModel model : listLotModel)
        {
            if(model.isSelected())
            {
                if(model.getShipNo() == null || model.getShipNo() == "")
                {
                    model.setSelected(false);
                }
                else
                {
                    iSelect++;
                }
            }
        }

        bottomAdapter.notifyDataSetChanged();

        if(iSelect <= 0)
        {
            showDialog(getString(R.string.alert_message_no_object));
            return;
        }

        showConfirmDialog(getString(R.string.alert_message_cancel), new Runnable() {
            @Override
            public void run() {
                requestCancel();
            }
        });
    }

    public void onClickClose(View view){
        this.finish();
    }

    public void onAllChkClicked(View view) {
        for(int i = 0 ; i < bottomAdapter.getCount() ; i++) {
            if (mCheckAll.isChecked()) {
                SHPModel model = (SHPModel)bottomAdapter.getItem(i);
                model.setSelected(true);
            } else {
                SHPModel model = (SHPModel)bottomAdapter.getItem(i);
                model.setSelected(false);
            }
        }
        bottomAdapter.notifyDataSetChanged();
        setTotalCount();
    }

//    public void onCntTotalClicked(View view) {
//        for(int i = 0; i < bottomAdapter.getCount(); i++)
//        {
//            SHPModel model = (SHPModel)bottomAdapter.getItem(i);
//
//            model.setSelected(false);
//
//            setTotalCount();
//        }
//
//        bottomAdapter.notifyDataSetChanged();
//    }


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
//                    case H101Const.ISSUE_REQUEST :
//
//                        break;
                    case H101Const.LOT :
                        ((TextView) findViewById(R.id.lotAll)).setText(barcode);
                        requestLotValid(barcode);
                        break;
                    case H101Const.BOX :
                        ((TextView) findViewById(R.id.lotAll)).setText(barcode);
                        requestBoxValid(barcode);
                        break;
                    case H101Const.FINAL_BOX :
                        ((TextView) findViewById(R.id.lotAll)).setText(barcode);
                        requestFinalBoxValid(barcode);
                        break;
                    default: //임시로 SHIP NO는 여기로 스캔 서버에 안만들어짐
                        requestShipList(barcode);
                        //startAlarm();
                        //showDialog(getString(R.string.alert_message_error_no_registered_barcode));
                        if(type.equalsIgnoreCase("SHIP_NO"))
                            ((TextView)findViewById(R.id.shipNo)).setText("");
                        else if(type.equalsIgnoreCase("LOT_ALL"))
                            ((TextView)findViewById(R.id.lotAll)).setText("");
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
                clearBottomListView();
                break;
            case 2 :
                clearAllListView();
                break;
            case 3 :
                clearTopListView();
                clearBottomListView();
            default:
                break;
        }
    }

    private void clearTopListView() {

        listInvShipModels.clear();
        topAdapter.notifyDataSetChanged();
        sAreaId = "";
    }

    private void clearBottomListView() {
        ((TextView)findViewById(R.id.lotAll)).setText("");

        listLotModel.clear();
        bottomAdapter.notifyDataSetChanged();

        ((TextView)findViewById(R.id.lotAll)).requestFocus();
    }

    private void clearAllListView(){
        ((TextView)findViewById(R.id.shipNo)).setText("");
        ((TextView)findViewById(R.id.lotAll)).setText("");

        listInvShipModels.clear();
        listLotModel.clear();

        topAdapter.notifyDataSetChanged();
        bottomAdapter.notifyDataSetChanged();

        sAreaId = "";
        sShipSeq = "";

        ((TextView)findViewById(R.id.shipNo)).requestFocus();
    }

    private void showShipNoDialog() throws InterruptedException {
        final ComboBoxShipOrderDialog dialog = new ComboBoxShipOrderDialog(this);
        dialog.setDialogTitle(getString(R.string.common_word_ship_order_id));
        dialog.setOnClickListener(new ComboBoxShipOrderDialog.OnClickListener() {
            @Override
            public void onClick(View view) {
                listShipOrderModels = dialog.getData();

                for(SHPModel model : listShipOrderModels)
                {
                    if(model.isSelected())
                    {
                        ((TextView) findViewById(R.id.shipNo)).setText(model.getShipNo());
                        requestShipList(model.getShipNo());
                        break;
                    }
                }
            }
        });
        dialog.showDialog();
    }

    private void requestShipList(final String sShipNo){

        ShpViewOrderListRequest request = new ShpViewOrderListRequest(this);

        request.addParam("PROCSTEP", "C", "3");
        request.addParam("SHIP_ORDER_ID", "S", sShipNo);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {

                Map<String, Object> resultMap = (Map<String, Object>)result;

                //SHIP ORDER번호 입력시 모두 초기화
                listInvShipModels.clear();
                listLotModel.clear();

                //출하 지시 범위
                if(resultMap.containsKey("ORDER_TBL_PDA")) {
                    try {

                        ((TextView) findViewById(R.id.shipNo)).setText(sShipNo);

                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ORDER_TBL_PDA")) {
                            SHPModel model = new SHPModel();

                            model.setShipNo(row.get("SHIP_ORDER_ID"));
                            model.setSeq(FormatUtil.convertStringToInteger(row.get("SEQ")));
                            model.setDesc(row.get("MAT_DESC"));
                            model.setPackOrderId(row.get("PACK_ORDER_ID"));
                            model.setPackLineNo(FormatUtil.convertStringToInteger(row.get("PACK_LINE_NO")));
                            model.setQty(FormatUtil.convertStringToDouble(row.get("QTY")));
                            model.setRegQty(FormatUtil.convertStringToDouble(row.get("REG_QTY")));
                            model.setUnit(row.get("UNIT"));
                            model.setStock(row.get("OPER_DESC"));

                            if(model.getSeq() == FormatUtil.convertStringToInteger(sShipSeq))
                            {
                                model.setSelected(true);
                            }
                            listInvShipModels.add(model);
                        }

                        sAreaId = resultMap.get("AREA_ID").toString();

                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listInvShipModels.clear();
                    }

                    topAdapter.notifyDataSetChanged(); // 리스트 갱신
                }
                else {
                    startAlarm();
                    showDialog(sShipNo + ":" + getString(R.string.alert_message_no_data));
                    init(2);
                    return;
                }

                if("HM".equals(sAreaId))
                {
                    if(resultMap.containsKey("SHIP_LOT_TBL_PDA"))
                    {
                        try {
                            ((TextView) findViewById(R.id.lotAllTitle)).setText(getString(R.string.common_word_lot_box_final_box));

                            for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("SHIP_LOT_TBL_PDA")) {

                                SHPModel model = new SHPModel();

                                model.setProcessLotId(row.get("ORG_LOT_ID"));
                                model.setShipLotId(row.get("PACK_LOT_ID"));
                                model.setDesc(row.get("DESC"));
                                model.setQty(FormatUtil.convertStringToDouble(row.get("QTY")));
                                model.setUnit(row.get("UNIT"));
                                model.setShipNo(row.get("SHIP_ORDER_ID"));
                                model.setBoxId(row.get("BOX_ID"));
                                model.setFinalBoxId(row.get("FINAL_BOX_ID"));
                                model.setSelected(true);

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
                    }
                    else
                    {
                        ((TextView) findViewById(R.id.lotAllTitle)).setText(getString(R.string.common_word_lot));
                    }
                }

                onSelectTopItem();
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

    private void requsetShipLotList(final String sShipNo, final String sSeq){
        ShpViewOrderListRequest request = new ShpViewOrderListRequest(this);

        request.addParam("PROCSTEP", "C", "4");
        request.addParam("SHIP_ORDER_ID", "S", sShipNo);
        request.addParam("SEQ", "I4", sSeq);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS"))
                {
                    try {
                        ((TextView) findViewById(R.id.lotAllTitle)).setText(getString(R.string.common_word_lot));

                        listLotModel.clear();

                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            SHPModel model = new SHPModel();

                            model.setProcessLotId(row.get("ORG_LOT_ID"));
                            model.setShipLotId(row.get("PACK_LOT_ID"));
                            model.setDesc(row.get("MAT_DESC"));
                            model.setLabelName(row.get("DESC"));
                            model.setQty(FormatUtil.convertStringToDouble(row.get("QTY")));
                            model.setUnit(row.get("UNIT"));
                            model.setShipNo(row.get("SHIP_ORDER_ID"));
                            model.setBoxId(row.get("BOX_ID"));
                            model.setFinalBoxId(row.get("FINAL_BOX_ID"));
//                            model.setSelected(true);

                            listLotModel.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listLotModel.clear();
                    }
//                    mCheckAll.setChecked(true);
                    bottomAdapter.notifyDataSetChanged(); // 리스트 갱신
                }
                else
                {
                    ((TextView) findViewById(R.id.lotAllTitle)).setText(getString(R.string.common_word_lot_box_final_box));
                }

                setTotalCount();
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

    private void setTotalCount(){
        int lotCount = 0;
        for (SHPModel lotModel : listLotModel) {
            // 동일한 LOT번호 있는지 체크
            if(lotModel.isSelected())
            {
                lotCount++;
            }
        }
        ((TextView) findViewById(R.id.totalCount)).setText(FormatUtil.toNumFormat(lotCount));
    }

    public void requestLotValid(final String sLotId){
        int iSameLot = 0;
        ((TextView) findViewById(R.id.lotAll)).setText("");

        //입력된 LOT이 없을 경우 에러
        if(sLotId.isEmpty())
        {
            showDialog((getString(R.string.alert_message_lot_empty)));
            return;
        }

        for (SHPModel lotModel : listLotModel) {
            // 동일한 LOT번호 있는지 체크
            if (lotModel.getShipLotId().equalsIgnoreCase(sLotId)) {
                if(lotModel.isSelected())
                    lotModel.setSelected(false);
                else
                    lotModel.setSelected(true);

                iSameLot ++;
                bottomAdapter.notifyDataSetChanged();
                break;
            }
        }

        if(iSameLot <= 0)
        {
            showDialog((getString(R.string.alert_message_error_not_same_lot)));
            return;
        }

        setTotalCount();
    }

    public void requestBoxValid(final String sBoxId){
        int iSameLot = 0;
        ((TextView) findViewById(R.id.lotAll)).setText("");

        //HM인 사업부가 아니면 RETURN
        if(!((TextView) findViewById(R.id.lotAllTitle)).getText().toString().equals(getString(R.string.common_word_lot_box_final_box)))
        {
            showDialog((getString(R.string.alert_message_no_hm)));
            return;
        }

        //입력된 LOT이 없을 경우 에러
        if(sBoxId.isEmpty())
        {
            showDialog((getString(R.string.alert_message_lot_empty)));
            return;
        }

        for (SHPModel lotModel : listLotModel) {
            // 동일한 LOT번호 있는지 체크
            if(lotModel.getBoxId() != null && lotModel.getBoxId() != "")
            {
                if (lotModel.getBoxId().equals(sBoxId)) {
                    if(lotModel.isSelected())
                        lotModel.setSelected(false);
                    else
                        lotModel.setSelected(true);

                    iSameLot ++;
                }
            }
        }

        bottomAdapter.notifyDataSetChanged();

        if(iSameLot <= 0)
        {
            showDialog((getString(R.string.alert_message_error_not_same_lot)));
            return;
        }

        setTotalCount();
    }

    public void requestFinalBoxValid(final String sFinalBoxId){
        int iSameLot = 0;
        ((TextView) findViewById(R.id.lotAll)).setText("");

        //HM인 사업부가 아니면 RETURN
        if(!((TextView) findViewById(R.id.lotAllTitle)).getText().toString().equals(getString(R.string.common_word_lot_box_final_box)))
        {
            showDialog((getString(R.string.alert_message_no_hm)));
            return;
        }

        //입력된 LOT이 없을 경우 에러
        if(sFinalBoxId.isEmpty())
        {
            showDialog((getString(R.string.alert_message_lot_empty)));
            return;
        }

        for (SHPModel lotModel : listLotModel) {
            // 동일한 LOT번호 있는지 체크
            if(lotModel.getFinalBoxId() != null && lotModel.getFinalBoxId() != "")
            {
                if (lotModel.getFinalBoxId().equals(sFinalBoxId)) {
                    if(lotModel.isSelected())
                        lotModel.setSelected(false);
                    else
                        lotModel.setSelected(true);

                    iSameLot ++;
                }
            }
        }

        bottomAdapter.notifyDataSetChanged();

        if(iSameLot <= 0)
        {
            showDialog((getString(R.string.alert_message_error_not_same_lot)));
            return;
        }

        setTotalCount();
    }

    private void requestRegist() {
        if(isLoading)
            return;
        isLoading = true;

        boxMap.clear();
        finalBoxMap.clear();

        ShpShipLotRequest request = new ShpShipLotRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("SHIP_ORDER_ID", "S", ((TextView)findViewById(R.id.shipNo)).getText().toString());

        for (SHPModel model : listLotModel) {
            if(model.isSelected())
            {
                //선택된 것 중에서 SHIP ORDER ID가 존재하지 않는 것만
                if(model.getShipNo() == null || model.getShipNo() == "")
                {
                    DataModel data = new DataModel();
                    List<VariableModel> columns = new ArrayList<>();

                    columns.add(ParseH101Xml.createVariableModel("ORG_LOT_ID", "S", model.getProcessLotId()));
                    columns.add(ParseH101Xml.createVariableModel("PACK_LOT_ID", "S", model.getShipLotId()));

                    //중박스ID가 비어있지 않은 경우
                    if(model.getBoxId() != null && model.getBoxId() != "")
                    {
                        int iSameBoxId = 0;

                        for (int i = 0; i<boxMap.size(); i++)
                        {
                            //기존 BOX ID가 Map에 존재하는 경우
                            if(boxMap.containsKey(model.getBoxId())) {
                                double dBoxQty = boxMap.get(model.getBoxId()) + 1;
                                iSameBoxId++;
                                boxMap.put(model.getBoxId(), dBoxQty);
                                break;
                            }
                        }

                        if(iSameBoxId <= 0)
                            boxMap.put(model.getBoxId(), 1.0);
                    }

                    //FINAL BOX가 비어있지 않은 경우
                    if(model.getFinalBoxId() != null && model.getFinalBoxId() != "")
                    {
                        int iSameFinalBoxId = 0;

                        for (int i = 0; i<finalBoxMap.size(); i++)
                        {
                            //기존 BOX ID가 Map에 존재하는 경우
                            if(finalBoxMap.containsKey(model.getFinalBoxId())) {
                                double dBoxQty = finalBoxMap.get(model.getFinalBoxId()) + 1;
                                iSameFinalBoxId++;
                                finalBoxMap.put(model.getFinalBoxId(), dBoxQty);
                                break;
                            }
                        }

                        if(iSameFinalBoxId <= 0)
                            finalBoxMap.put(model.getFinalBoxId(), 1.0);
                    }

                    data.setD(columns);
                    data.setN("PACK_LOT_LIST");

                    request.addListParam(data);
                }
            }
        }

        if(boxMap.size() > 0)
        {
            Set keys = boxMap.keySet();
            for (Iterator i = keys.iterator(); i.hasNext();)
            {
                String key = (String) i.next();
                double value = boxMap.get(key);

                DataModel data = new DataModel();
                List<VariableModel> columns = new ArrayList<>();

                columns.add(ParseH101Xml.createVariableModel("BOX_ID", "S", key));
                columns.add(ParseH101Xml.createVariableModel("QTY", "F8", String.valueOf(value)));

                data.setD(columns);
                data.setN("PACK_BOX_LIST");

                request.addListParam(data);
            }
        }

        if(finalBoxMap.size() > 0)
        {
            Set keys = finalBoxMap.keySet();
            for (Iterator i = keys.iterator(); i.hasNext();)
            {
                String key = (String) i.next();
                double value = finalBoxMap.get(key);

                DataModel data = new DataModel();
                List<VariableModel> columns = new ArrayList<>();

                columns.add(ParseH101Xml.createVariableModel("FINAL_BOX_ID", "S", key));
                columns.add(ParseH101Xml.createVariableModel("QTY", "F8", String.valueOf(value)));

                data.setD(columns);
                data.setN("PACK_FINAL_BOX_LIST");

                request.addListParam(data);
            }
        }

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result)  {
                isLoading = false;
                showToast(getString(R.string.processing_completed));
                init(3);
                requestShipList(((TextView)findViewById(R.id.shipNo)).getText().toString());
                mCheckAll.setChecked(false);

            }

            @Override
            public void onFailure(Exception exception) {
                isLoading = false;
                startAlarm();
                showDialog(exception.getMessage());
            }

            @Override
            public void onFinish() {
                if(!"HM".equals(sAreaId)){
                    requsetShipLotList(((TextView)findViewById(R.id.shipNo)).getText().toString(), sShipSeq);
                }
                isLoading = false;
                hideLoadingDialog();
            }
        });
    }

    private void requestCancel() {
        if(isLoading)
            return;
        isLoading = true;

        boxMap.clear();
        finalBoxMap.clear();

        ShpShipLotRequest request = new ShpShipLotRequest(this);

        request.addParam("PROCSTEP", "C", "2");
        request.addParam("SHIP_ORDER_ID", "S", ((TextView)findViewById(R.id.shipNo)).getText().toString());

        for (SHPModel model : listLotModel) {
            if(model.isSelected())
            {
                //선택된 것 중에서 SHIP ORDER ID가 존재하는것만 취소
                if(model.getShipNo() != null && model.getShipNo() != "")
                {
                    DataModel data = new DataModel();
                    List<VariableModel> columns = new ArrayList<>();

                    columns.add(ParseH101Xml.createVariableModel("ORG_LOT_ID", "S", model.getProcessLotId()));
                    columns.add(ParseH101Xml.createVariableModel("PACK_LOT_ID", "S", model.getShipLotId()));

                    //중박스ID가 비어있지 않은 경우
                    if(model.getBoxId() != null && model.getBoxId() != "")
                    {
                        int iSameBoxId = 0;

                        for (int i = 0; i<boxMap.size(); i++)
                        {
                            //기존 BOX ID가 Map에 존재하는 경우
                            if(boxMap.containsKey(model.getBoxId())) {
                                double dBoxQty = boxMap.get(model.getBoxId()) + 1;
                                iSameBoxId++;
                                boxMap.put(model.getBoxId(), dBoxQty);
                                break;
                            }
                        }

                        if(iSameBoxId <= 0)
                            boxMap.put(model.getBoxId(), 1.0);
                    }

                    //FINAL BOX가 비어있지 않은 경우
                    if(model.getFinalBoxId() != null && model.getFinalBoxId() != "")
                    {
                        int iSameFinalBoxId = 0;

                        for (int i = 0; i<finalBoxMap.size(); i++)
                        {
                            //기존 BOX ID가 Map에 존재하는 경우
                            if(finalBoxMap.containsKey(model.getFinalBoxId())) {
                                double dBoxQty = finalBoxMap.get(model.getFinalBoxId()) + 1;
                                iSameFinalBoxId++;
                                finalBoxMap.put(model.getFinalBoxId(), dBoxQty);
                                break;
                            }
                        }

                        if(iSameFinalBoxId <= 0)
                            finalBoxMap.put(model.getFinalBoxId(), 1.0);
                    }

                    data.setD(columns);
                    data.setN("PACK_LOT_LIST");

                    request.addListParam(data);
                }
            }
        }

        if(boxMap.size() > 0)
        {
            Set keys = boxMap.keySet();
            for (Iterator i = keys.iterator(); i.hasNext();)
            {
                String key = (String) i.next();
                double value = boxMap.get(key);

                DataModel data = new DataModel();
                List<VariableModel> columns = new ArrayList<>();

                columns.add(ParseH101Xml.createVariableModel("BOX_ID", "S", key));
                columns.add(ParseH101Xml.createVariableModel("QTY", "F8", String.valueOf(value)));

                data.setD(columns);
                data.setN("PACK_BOX_LIST");

                request.addListParam(data);
            }
        }

        if(finalBoxMap.size() > 0)
        {
            Set keys = finalBoxMap.keySet();
            for (Iterator i = keys.iterator(); i.hasNext();)
            {
                String key = (String) i.next();
                double value = finalBoxMap.get(key);

                DataModel data = new DataModel();
                List<VariableModel> columns = new ArrayList<>();

                columns.add(ParseH101Xml.createVariableModel("FINAL_BOX_ID", "S", key));
                columns.add(ParseH101Xml.createVariableModel("QTY", "F8", String.valueOf(value)));

                data.setD(columns);
                data.setN("PACK_FINAL_BOX_LIST");

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
                isLoading = false;
                showToast(getString(R.string.processing_completed));
                init(3);
                mCheckAll.setChecked(false);
                requestShipList(((TextView)findViewById(R.id.shipNo)).getText().toString());
            }

            @Override
            public void onFailure(Exception exception) {
                isLoading = false;
                startAlarm();
                showDialog(exception.getMessage());
            }

            @Override
            public void onFinish() {
                if(!"HM".equals(sAreaId)){
                    requsetShipLotList(((TextView)findViewById(R.id.shipNo)).getText().toString(), sShipSeq);
                }
                isLoading = false;
                hideLoadingDialog();
            }
        });
    }

    private void onSelectTopItem() {
        if (mSelectedTopModel != null && topAdapter != null && topAdapter.getCount() > 0) {
            for(int i = 0 ; i < topAdapter.getCount() ; i++) {
                if (Integer.parseInt(sShipSeq) == ((SHPModel) topAdapter.getItem(i)).getSeq()) {
                    ((SHPModel)topAdapter.getItem(i)).setSelected(true);
                    topAdapter.notifyDataSetChanged();
                    listTopView.setSelection(i);
                } else {
                    ((SHPModel)topAdapter.getItem(i)).setSelected(false);
                }
            }
        }
    }
    //endregion
}