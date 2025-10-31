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
import com.pda.mes.adapter.CPDA3002_PDA_BottomAdapter;
import com.pda.mes.adapter.CPDA3002_PDA_TopAdapter;
import com.pda.mes.dialog.ComboBoxDialog;
import com.pda.mes.dialog.ComboBoxSearchDialog;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.SQLQueryRequest;
import com.pda.mes.h101.request.inv.InvViewPOListRequest;
import com.pda.mes.manager.AppLogManager;
import com.pda.mes.manager.AppSettingManager;
import com.pda.mes.manager.SessionManager;
import com.pda.mes.model.DropDownModel;
import com.pda.mes.model.INVModel;
import com.pda.mes.utils.FormatUtil;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Locale;
import java.util.Map;

public class CPDA3002_PDA_Activity extends ToolbarActivity {
    public static final String TAG = CPDA3002_PDA_Activity.class.getSimpleName();

    private CPDA3002_PDA_TopAdapter topAdapter; // 상단 리스트뷰 어댑터
    private CPDA3002_PDA_BottomAdapter bottomAdapter; //하단 리스트뷰 어댑터
    private ListView listTopView; // 뷰모델 상단 리스트뷰
    private ListView listBottomView; // 뷰모델 하단 리스트뷰
    private List<DropDownModel> listAreaModels = new ArrayList<>(); //AREA LIST(사업부)
    private List<DropDownModel> listVendorModels = new ArrayList<>(); //VENDOR LIST(협력사)
    private List<INVModel> listDlvMstModel = new ArrayList<>(); // 라벨 뷰모델 리스트
    private List<INVModel> listDlvDtlModel = new ArrayList<>(); // 라벨 뷰모델 리스트
    private boolean isLoading = false;
    private String userAreaId = "";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        AppLogManager.printScreenNameLog(TAG, getIntent().getStringExtra(EXTRA_NAME_TITLE));
        setContentView(R.layout.activity_cpda3002, TOOLBAR_TYPE_PUSH);

        Button fromDateButton = (Button)findViewById(R.id.FromDate);
        fromDateButton.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View view) {
                showFromDateDialog();
            }
        });

        Button ToDateButton = (Button)findViewById(R.id.ToDate);
        ToDateButton.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View view) {
                showToDateDialog();
            }
        });
        topAdapter = new CPDA3002_PDA_TopAdapter(this);
        listTopView = findViewById(R.id.listTopView);

        topAdapter.setModels(listDlvMstModel);
        listTopView.setAdapter(topAdapter);

        bottomAdapter = new CPDA3002_PDA_BottomAdapter(this);
        listBottomView = findViewById(R.id.listBottomView);

        bottomAdapter.setModels(listDlvDtlModel);
        listBottomView.setAdapter(bottomAdapter);

        userAreaId = SessionManager.getUserAreaId(this);

        requestVendorList();
        requestAreaList();
        setDateTime();

        listTopView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int position, long l) {
                resetLogoutTimer(); // 로그아웃 체크 시간 초기화

                for(int i = 0 ; i < topAdapter.getCount() ; i++) {
                    ((INVModel)topAdapter.getItem(i)).setSelected(i == position ? true : false);
                }

                topAdapter.notifyDataSetChanged();

                for (INVModel model : listDlvMstModel) {
                    // 선택된 항목들만 리스트에 넣는다. 선택된 항목이 없어도 로드를 진행해야 한다. 그럼 선택된 아이템의 항목들이 모두 미싱처리 된다.
                    if (model.isSelected()) {

                        String sDlvNo = model.getDlvNo();

                        init(2);

                        requestDlvDetailList(sDlvNo);
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

    public void onClickVendor(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화
        showVendorDialog();
    }

    public void onClickSearch(View view) {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화

        init(1);

        requestSearch();
    }

    public void onClickClose(View view){
        this.finish();
    }

    //region Function Event
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

                for (DropDownModel areaModel : listAreaModels)
                {
                    areaModel.setSelected(false);
                }

                model.setSelected(true);

                init(1);
            }
        });
        dialog.showDialog();
    }

    private void requestVendorList() {
        String requestQuery
                = "SELECT KEY_1 VENDOR, DATA_1 VENDOR_DESC"
                + " FROM MGCMLAGDAT"
                + " WHERE 1 = 1"
                + " AND FACTORY = '" + AppSettingManager.getLoginFactory(this) + "'"
                + " AND TABLE_NAME = \'C_VENDOR\'";

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
                    setVendor((List<Map<String, String>>)resultMap.get("ROWS"));
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

    private void setVendor(List<Map<String, String>> rows) {
        listVendorModels.clear();

        try {
            for(Map<String, String> row : rows) {
                DropDownModel model = new DropDownModel();
                model.setId(row.get("VENDOR"));
                model.setName(row.get("VENDOR_DESC"));

                listVendorModels.add(model);
            }
        } catch(RuntimeException re) {
            throw re;
        } catch(Exception e) {
            AppLogManager.printErrorLog(e.getMessage());
        }

        ((TextView)findViewById(R.id.vendor)).setText("");
    }

    private void showVendorDialog() {
        ComboBoxSearchDialog dialog = new ComboBoxSearchDialog(this);
        dialog.setDialogTitle(getString(R.string.common_word_vendor));
        dialog.setData(listVendorModels);
        dialog.setOnSelectItemListener(new ComboBoxSearchDialog.OnSelectItemListener() {
            @Override
            public void onClickItem(DropDownModel model) {
                // factory 를 변경하지 않으면 아무것도 하지 않는다.
                String sVendor = ((TextView)findViewById(R.id.vendor)).getText().toString();

                if(sVendor.equalsIgnoreCase(model.getName()))
                    return;

                ((TextView)findViewById(R.id.vendor)).setText(model.getName());

                for (DropDownModel vendorModel : listVendorModels)
                {
                    vendorModel.setSelected(false);
                }

                model.setSelected(true);

                init(1);
            }
        });
        dialog.showDialog();
    }

    private void init(int iSeq)
    {
        resetLogoutTimer(); // 로그아웃 체크 시간 초기화

        int iMethod = iSeq;
        switch (iMethod)
        {
            case 1 :
                //아래 리스트 초기화
                clearListView();
                break;

            case 2 :
                //BOTTOM 리스트 초기화
                clearBottomListView();

            default:
                break;
        }
    }

    private void clearListView() {
        listDlvMstModel.clear();
        listDlvDtlModel.clear();
        topAdapter.notifyDataSetChanged();
        bottomAdapter.notifyDataSetChanged();
    }

    private void clearBottomListView() {
        listDlvDtlModel.clear();
        bottomAdapter.notifyDataSetChanged();
    }

    private void requestSearch() {

        String sArea = "";
        String sVendorCode = "";

        InvViewPOListRequest request = new InvViewPOListRequest(this);

        request.addParam("PROCSTEP", "C", "1");
        request.addParam("FROM_DATE", "S", ((TextView)findViewById(R.id.FromDate)).getText().toString().replace("-", "") + "000000'");
        request.addParam("TO_DATE", "S", ((TextView)findViewById(R.id.ToDate)).getText().toString().replace("-", "") + "235959'");

        for (DropDownModel areaModel : listAreaModels) {
            if(areaModel.isSelected())
            {
                sArea = areaModel.getId();
                break;
            }
        }

        if(sArea == null || sArea == "")
        {
            showDialog(getString(R.string.common_word_check_area));
            return;
        }

        for (DropDownModel vendorModel : listVendorModels) {
            if(vendorModel.isSelected())
            {
                sVendorCode = vendorModel.getId();
                break;
            }
        }

        if(sVendorCode == null || sVendorCode == "")
        {
            showDialog(getString(R.string.common_word_check_vendor));
            return;
        }

        request.addParam("AREA_ID", "S", sArea);
        request.addParam("VENDOR_ID", "S", sVendorCode);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                listDlvMstModel.clear();
                listDlvDtlModel.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;
                if(resultMap.containsKey("ROWS")) {
                    for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {
                        INVModel model = new INVModel();

                        model.setDlvNo((String)row.get("DLV_NO"));
                        model.setPoNo((String)row.get("PO_NO"));
                        model.setBlNo((String)row.get("BL_NO"));
                        model.setExpDate((String)row.get("DLV_EXP_DATE"));
                        model.setVendorId((String)row.get("VENDOR_ID"));
                        model.setAreaID((String)row.get("AREA_ID"));
                        model.setOrderID((String)row.get("CMF_1")); //작업지시(CMF_1)
                        //model.setSelected(true);

                        listDlvMstModel.add(model);
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
                startAlarm();
                showDialog(exception.getMessage());
            }

            @Override
            public void onFinish() {
                hideLoadingDialog();
            }
        });
    }


    private void requestDlvDetailList(final String sDlvNo)
    {
        InvViewPOListRequest request = new InvViewPOListRequest(this);

        request.addParam("PROCSTEP", "C", "2");
        request.addParam("DLV_NO", "S", sDlvNo);

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
                    listDlvDtlModel.clear();

                    try {
                        for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

                            INVModel model = new INVModel();

                            model.setDlvSeq(FormatUtil.convertStringToInteger(row.get("DLV_SEQ")));
                            model.setMatId(row.get("MAT_ID"));
                            model.setMatVer(row.get("MAT_VER"));
                            model.setDesc(row.get("MAT_DESC"));
                            model.setQty(FormatUtil.convertStringToDouble(row.get("DLV_QTY")));
                            model.setConfirmQty(FormatUtil.convertStringToDouble(row.get("CONFIRM_QTY")));
                            model.setUnit(row.get("UNIT"));

                            listDlvDtlModel.add(model);
                        }
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        listDlvDtlModel.clear();
                    }

                    bottomAdapter.notifyDataSetChanged(); // 리스트 갱신
                    //animateListTopLayout(true); // 리스트 보여주기
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

    private DatePickerDialog.OnDateSetListener fromListener = new DatePickerDialog.OnDateSetListener() {
        @Override
        public void onDateSet(DatePicker view, int year, int monthOfYear, int dayOfMonth) {
            String sDate = year + "-" + String.format("%02d", monthOfYear + 1) + "-" + String.format("%02d",dayOfMonth); //FORMAT 2020-09-24

            ((TextView)findViewById(R.id.FromDate)).setText(sDate);

            init(1);
        }
    };

    private void showFromDateDialog() {
        String[] sFromSplit = ((TextView)findViewById(R.id.FromDate)).getText().toString().split("-");

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

            ((TextView)findViewById(R.id.ToDate)).setText(sDate);

            init(1);
        }
    };

    private void showToDateDialog() {
        String[] sToSplit = ((TextView)findViewById(R.id.ToDate)).getText().toString().split("-");

        int iToYear = Integer.parseInt(sToSplit[0]);
        int iToMonth = Integer.parseInt(sToSplit[1]);
        int iToDay = Integer.parseInt(sToSplit[2]);

        DatePickerDialog dialog = new DatePickerDialog(this, toListener, iToYear, iToMonth - 1, iToDay);
        dialog.show();
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

        ((TextView)findViewById(R.id.FromDate)).setText(sWeekAgoDate);
        ((TextView)findViewById(R.id.ToDate)).setText(sDate);
    }
}
