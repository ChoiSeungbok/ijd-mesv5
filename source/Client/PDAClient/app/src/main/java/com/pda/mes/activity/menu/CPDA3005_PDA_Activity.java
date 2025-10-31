package com.pda.mes.activity.menu;

import android.app.DatePickerDialog;
import android.icu.util.Calendar;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.ListView;
import android.widget.TextView;

import com.pda.mes.R;
import com.pda.mes.activity.ToolbarActivity;
import com.pda.mes.adapter.CPDA3005_PDA_BottomAdapter;
import com.pda.mes.adapter.CPDA3005_PDA_TopAdapter;
import com.pda.mes.adapter.DialogShipOrderAdapter;
import com.pda.mes.dialog.ComboBoxDialog;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.SQLQueryRequest;
import com.pda.mes.h101.request.prod.WipViewOperListRequest;
import com.pda.mes.h101.request.shp.ShpViewOrderListRequest;
import com.pda.mes.manager.AppLogManager;
import com.pda.mes.manager.AppSettingManager;
import com.pda.mes.manager.SessionManager;
import com.pda.mes.model.DropDownModel;
import com.pda.mes.model.SHPModel;
import com.pda.mes.utils.FormatUtil;
import com.pda.mes.widget.FontTextView;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Locale;
import java.util.Map;

public class CPDA3005_PDA_Activity extends ToolbarActivity {
    public static final String TAG = CPDA3005_PDA_Activity.class.getSimpleName();

    private CPDA3005_PDA_TopAdapter topAdapter; // 상단 리스트뷰 어댑터
    private CPDA3005_PDA_BottomAdapter bottomAdapter; //하단 리스트뷰 어댑터
    private ListView listTopView; // 뷰모델 상단 리스트뷰
    private ListView listBottomView; // 뷰모델 하단 리스트뷰
    private List<DropDownModel> listAreaModels = new ArrayList<>(); //AREA LIST(사업부)
    private List<DropDownModel> listOperModels = new ArrayList<>(); //OPER LIST(창고)
    private List<SHPModel> listShipModels = new ArrayList<>(); // 라벨 뷰모델 리스트
    private List<SHPModel> listShipDetailModels = new ArrayList<>(); // 라벨 뷰모델 리스트
    private boolean isLoading = false;
    private String userAreaId = "";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        AppLogManager.printScreenNameLog(TAG, getIntent().getStringExtra(EXTRA_NAME_TITLE));
        setContentView(R.layout.activity_cpda3005, TOOLBAR_TYPE_PUSH);

        Button fromDateButton = (Button)findViewById(R.id.shipFromDate);
        fromDateButton.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View view) {
                showShipFromDateDialog();
            }
        });

        Button ToDateButton = (Button)findViewById(R.id.shipToDate);
        ToDateButton.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View view) {
                showShipToDateDialog();
            }
        });

        userAreaId = SessionManager.getUserAreaId(this);

        topAdapter = new CPDA3005_PDA_TopAdapter(this);
        listTopView = findViewById(R.id.listTopView);

        topAdapter.setModels(listShipModels);
        listTopView.setAdapter(topAdapter);

        bottomAdapter = new CPDA3005_PDA_BottomAdapter(this);
        listBottomView = findViewById(R.id.listBottomView);

        bottomAdapter.setModels(listShipDetailModels);
        listBottomView.setAdapter(bottomAdapter);

        setDateTime();
        requestAreaList();
        findViewById(R.id.oper).setEnabled(false);

        listTopView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int position, long l) {
                resetLogoutTimer(); // 로그아웃 체크 시간 초기화

                if(isLoading)
                    return;

                isLoading = true;

                for(int i = 0 ; i < topAdapter.getCount() ; i++) {
                    ((SHPModel)topAdapter.getItem(i)).setSelected(i == position ? true : false);
                }

                topAdapter.notifyDataSetChanged();

                isLoading = false;

                for (SHPModel model : listShipModels) {
                    // 선택된 항목들만 리스트에 넣는다. 선택된 항목이 없어도 로드를 진행해야 한다. 그럼 선택된 아이템의 항목들이 모두 미싱처리 된다.
                    if (model.isSelected()) {

                        String sShipNo = model.getShipNo();

                        init(3);

                        requestShipDetailList(sShipNo);
                        break;
                    }
                }
            }
        });
    }

    //region Button Click Event
    public void onClickArea(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showAreaDialog();
    }

    public void onClickOper(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showOperDialog();
    }

    public void onClickSearch(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화

        //int iSelectRows = 0;

        String sArea = "";
        String sOper = "";

        for (DropDownModel areaModel : listAreaModels) {
            if (areaModel.isSelected()) {
                sArea = areaModel.getId();
                break;
            }
        }

        if(sArea == null || sArea == "")
        {
            showDialog(getString(R.string.common_word_check_area));
            return;
        }

        for (DropDownModel operModel : listOperModels) {
            if (operModel.isSelected()) {
                sOper = operModel.getId();
                break;
            }
        }

        if(sOper == null || sOper == "")
        {
            showDialog(getString(R.string.common_word_check_stock));
            return;
        }

        requestSearch(sArea, sOper);

        //하단 초기화
        listShipDetailModels.clear();
        bottomAdapter.notifyDataSetChanged();
    }

    public void onClickClose(View view){
        this.finish();
    }

    //endregion

    //region Function Event
    private void clearTopListView() {
        listShipModels.clear();
        topAdapter.notifyDataSetChanged();
    }

    private void clearBottomListView() {
        listShipDetailModels.clear();
        bottomAdapter.notifyDataSetChanged();
    }

    private void clearListView(){
        listShipModels.clear();
        listShipDetailModels.clear();

        topAdapter.notifyDataSetChanged();
        bottomAdapter.notifyDataSetChanged();
    }

    private void clearAllListView(){
        ((TextView)findViewById(R.id.area)).setText("");
        ((TextView)findViewById(R.id.oper)).setText("");

        requestAreaList();
        findViewById(R.id.oper).setEnabled(false);

        listShipModels.clear();
        listShipDetailModels.clear();

        topAdapter.notifyDataSetChanged();
        bottomAdapter.notifyDataSetChanged();
    }

    private void init(int iSeq)
    {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화

        int iMethod = iSeq;
        switch (iMethod)
        {
            case 1 :
                //리스트만 초기화
                clearListView();
                break;
            case 2 :
                //TOP 리스트 초기화
                clearTopListView();
                break;
            case 3 :
                //BOTTOM 리스트 초기화
                clearBottomListView();
                break;
            case 4 :
                //모두 초기화
                clearAllListView();
                break;
            default:
                break;
        }
    }

    private void requestAreaList() {
        String requestQuery
                = "SELECT KEY_1 AREA, DATA_1 AREA_DESC"
                + " FROM MGCMTBLDAT"
                + " WHERE 1 = 1"
                + " AND FACTORY = '" + AppSettingManager.getLoginFactory(this) + "'"
                + " AND TABLE_NAME = \'AREA\'";

        SQLQueryRequest request = new SQLQueryRequest(this, requestQuery);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    setArea((List<Map<String, String>>)resultMap.get("ROWS"));
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

    private void setArea(List<Map<String, String>> rows) {
        listAreaModels.clear();

        try {
            for(Map<String, String> row : rows) {
                DropDownModel model = new DropDownModel();
                model.setId(row.get("AREA"));
                model.setName(row.get("AREA_DESC"));

                listAreaModels.add(model);
            }

            if (!TextUtils.isEmpty(userAreaId) && userAreaId != null) {
                for (DropDownModel item : listAreaModels) {
                    if (item.getId().equalsIgnoreCase(userAreaId)) {
                        item.setSelected(true);
                    }
                }
            }
            ((TextView)findViewById(R.id.area)).setText(userAreaId);
            requestOper(userAreaId);
        } catch(RuntimeException re) {
            throw re;
        } catch(Exception e) {
            AppLogManager.printErrorLog(e.getMessage());
        }
    }

    private void showAreaDialog() {
        ComboBoxDialog dialog = new ComboBoxDialog(this);
        dialog.setDialogTitle(getString(R.string.common_word_area));
        dialog.setData(listAreaModels);
        dialog.setOnSelectItemListener(new ComboBoxDialog.OnSelectItemListener() {
            @Override
            public void onClickItem(DropDownModel model) {
                // factory 를 변경하지 않으면 아무것도 하지 않는다.
                String sArea = ((TextView)findViewById(R.id.area)).getText().toString();

                if(sArea.equalsIgnoreCase(model.getName()))
                    return;

                ((TextView)findViewById(R.id.area)).setText(model.getName());

                //사업부 제외 모든 하위 검색조건 초기화
                ((TextView)findViewById(R.id.oper)).setText("");

                for (DropDownModel areaModel : listAreaModels)
                {
                    areaModel.setSelected(false);
                }

                model.setSelected(true);

                requestOper(model.getId());
                findViewById(R.id.operLayout).setEnabled(true);

                init(1);
            }
        });
        dialog.showDialog();
    }

    private void requestOper(String sArea) {
        WipViewOperListRequest request = new WipViewOperListRequest(this);

        request.addParam("PROCSTEP", "C", "5");
        request.addParam("AREA_ID", "S", sArea);
        request.addParam("INV_FLAG", "C", "Y");
        request.addParam("SHIP_FLAG", "C", "Y");

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                listOperModels.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            DropDownModel model = new DropDownModel();
                            model.setId(row.get("OPER"));
                            model.setName(row.get("OPER_DESC"));

                            listOperModels.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listOperModels.clear();
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

    private void showOperDialog() {
        ComboBoxDialog dialog = new ComboBoxDialog(this);
        dialog.setDialogTitle(getString(R.string.common_word_oper));
        dialog.setData(listOperModels);
        dialog.setOnSelectItemListener(new ComboBoxDialog.OnSelectItemListener() {
            @Override
            public void onClickItem(DropDownModel model) {
                String sOper = ((TextView)findViewById(R.id.oper)).getText().toString();

                if(sOper.equalsIgnoreCase(model.getName()))
                    return;

                for (DropDownModel OperModel : listOperModels)
                {
                    OperModel.setSelected(false);
                }

                model.setSelected(true);

                ((TextView)findViewById(R.id.oper)).setText(model.getName());
                init(1);
            }
        });
        dialog.showDialog();
    }

    private void requestSearch(String sArea, String sOper) {
        if(isLoading)
            return;
        isLoading = true;

        ShpViewOrderListRequest request = new ShpViewOrderListRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("AREA_ID", "S", sArea);
        request.addParam("OPER", "S", sOper);
        request.addParam("SHIP_ORDER_ID", "S", "");
        request.addParam("FROM_DATE", "S", ((TextView)findViewById(R.id.shipFromDate)).getText().toString().replace("-", "") + "000000'");
        request.addParam("TO_DATE", "S", ((TextView)findViewById(R.id.shipToDate)).getText().toString().replace("-", "") + "235959'");

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                isLoading = false;

                listShipModels.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            SHPModel model = new SHPModel();

                            model.setShipNo(row.get("SHIP_ORDER_ID"));
                            model.setCustomerId(row.get("CUSTOMER_ID"));
                            model.setArea(row.get("AREA_DESC"));
                            model.setShipOrdDate(row.get("SHIP_ORD_DATE"));
                            model.setDeliveryId(row.get("DELIVERY_ID"));
                            model.setStatus(row.get("SHIP_ORD_STATUS"));
                            model.setOper(row.get("OPER_DESC"));

                            listShipModels.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listShipModels.clear();
                    }

                    topAdapter.notifyDataSetChanged(); // 리스트 갱신
                }
                else
                {
                    showDialog(getString(R.string.alert_message_no_data));
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

    private void requestShipDetailList(final String sShipNo)
    {
        if(isLoading)
            return;
        isLoading = true;

        ShpViewOrderListRequest request = new ShpViewOrderListRequest(this);

        request.addParam("PROCSTEP", "C", "2");
        request.addParam("SHIP_ORDER_ID", "S", sShipNo);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                isLoading = false;

                listShipDetailModels.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            SHPModel model = new SHPModel();

                            model.setShipNo(row.get("SHIP_ORDER_ID"));
                            model.setSeq(FormatUtil.convertStringToInteger(row.get("SEQ")));
                            model.setDesc(row.get("MAT_DESC"));
                            model.setPackOrderId(row.get("PACK_ORDER_ID"));
                            model.setPackLineNo(FormatUtil.convertStringToInteger(row.get("PACK_LINE_NO")));
                            model.setQty(FormatUtil.convertStringToDouble(row.get("QTY")));
                            model.setUnit(row.get("UNIT"));
                            model.setOper(row.get("OPER_DESC"));

                            listShipDetailModels.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listShipDetailModels.clear();
                    }

                    bottomAdapter.notifyDataSetChanged(); // 리스트 갱신
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

    private void setDateTime(){
        SimpleDateFormat yyyyMMddFormat = new SimpleDateFormat("yyyy-MM-dd", Locale.getDefault());

        //현재날짜
        Date date = new Date();

        //7일전날짜
        Calendar cal = Calendar.getInstance();
        cal.setTime(date);
        cal.add(Calendar.DATE, -7);
        Date weekAgo = cal.getTime();

        String sDate = yyyyMMddFormat.format(date);
        String sWeekAgoDate = yyyyMMddFormat.format(weekAgo);

        ((TextView)findViewById(R.id.shipFromDate)).setText(sWeekAgoDate);
        ((TextView)findViewById(R.id.shipToDate)).setText(sDate);
    }

    private DatePickerDialog.OnDateSetListener fromListener = new DatePickerDialog.OnDateSetListener() {
        @Override
        public void onDateSet(DatePicker view, int year, int monthOfYear, int dayOfMonth) {
            String sDate = year + "-" + String.format("%02d", monthOfYear + 1) + "-" + String.format("%02d",dayOfMonth); //FORMAT 2020-09-24

            ((TextView)findViewById(R.id.shipFromDate)).setText(sDate);

            init(1);
        }
    };

    private void showShipFromDateDialog() {
        String[] sFromSplit = ((TextView)findViewById(R.id.shipFromDate)).getText().toString().split("-");

        int iFromYear = Integer.parseInt(sFromSplit[0]);
        int iFromMonth = Integer.parseInt(sFromSplit[1]);
        int iFromDay = Integer.parseInt(sFromSplit[2]);

        DatePickerDialog dialog = new DatePickerDialog(this, fromListener, iFromYear, iFromMonth - 1, iFromDay);
        dialog.show();
    }

    private DatePickerDialog.OnDateSetListener toListener = new DatePickerDialog.OnDateSetListener() {
        @Override
        public void onDateSet(DatePicker view, int year, int monthOfYear, int dayOfMonth) {
            String sDate = year + "-" + String.format("%02d", monthOfYear + 1) + "-" + String.format("%02d",dayOfMonth); //FORMAT 2020-09-24

            ((TextView)findViewById(R.id.shipToDate)).setText(sDate);

            init(1);
        }
    };

    private void showShipToDateDialog() {
        String[] sToSplit = ((TextView)findViewById(R.id.shipToDate)).getText().toString().split("-");

        int iToYear = Integer.parseInt(sToSplit[0]);
        int iToMonth = Integer.parseInt(sToSplit[1]);
        int iToDay = Integer.parseInt(sToSplit[2]);

        DatePickerDialog dialog = new DatePickerDialog(this, toListener, iToYear, iToMonth - 1, iToDay);
        dialog.show();
    }

    //endregion
}
