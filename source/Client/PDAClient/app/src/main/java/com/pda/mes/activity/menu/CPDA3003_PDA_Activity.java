package com.pda.mes.activity.menu;

import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.ListView;
import android.widget.TextView;

import com.pda.mes.R;
import com.pda.mes.activity.ToolbarActivity;
import com.pda.mes.adapter.CPDA3003_PDA_Adapter;
import com.pda.mes.dialog.ComboBoxDialog;
import com.pda.mes.dialog.ComboBoxSearchDialog;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.SQLQueryRequest;
import com.pda.mes.h101.request.inv.InvViewLotListByOperRequest;
import com.pda.mes.h101.request.prod.WipViewMaterialListRequest;
import com.pda.mes.h101.request.prod.WipViewOperListRequest;
import com.pda.mes.manager.AppLogManager;
import com.pda.mes.manager.AppSettingManager;
import com.pda.mes.manager.SessionManager;
import com.pda.mes.model.DropDownModel;
import com.pda.mes.model.INVModel;
import com.pda.mes.utils.FormatUtil;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class CPDA3003_PDA_Activity extends ToolbarActivity {
    public static final String TAG = CPDA3003_PDA_Activity.class.getSimpleName();

    private CPDA3003_PDA_Adapter adapter; // 리스트뷰 어댑터
    private ListView listView; // 뷰모델 리스트뷰
    private List<DropDownModel> listAreaModels = new ArrayList<>(); //AREA LIST(사업부)
    private List<DropDownModel> listOperModels = new ArrayList<>(); //OPER LIST(창고)
    private List<DropDownModel> listItemModels = new ArrayList<>(); //ITEM LIST(제품)
    private List<INVModel> listLotModels = new ArrayList<>(); // 라벨 뷰모델 리스트
    private String userAreaId = "";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        AppLogManager.printScreenNameLog(TAG, getIntent().getStringExtra(EXTRA_NAME_TITLE));
        setContentView(R.layout.activity_cpda3003, TOOLBAR_TYPE_PUSH);

        adapter = new CPDA3003_PDA_Adapter(this);
        listView = findViewById(R.id.listView);

        adapter.setModels(listLotModels);
        listView.setAdapter(adapter);

        userAreaId = SessionManager.getUserAreaId(this);

        findViewById(R.id.operLayout).setEnabled(false);

        requestAreaList();
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
        requestSearch();
    }


    public void onClickClose(View view){
        this.finish();
    }

    //endregion
    
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

            requestOper(userAreaId); //사업부로 공정리스트 가져오기
            ((TextView)findViewById(R.id.oper)).setText("");
            findViewById(R.id.operLayout).setEnabled(true);
            init(1);
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

                requestOper(model.getId()); //사업부로 공정리스트 가져오기
                ((TextView)findViewById(R.id.oper)).setText("");
                findViewById(R.id.operLayout).setEnabled(true);
                init(1);
            }
        });
        dialog.showDialog();
    }

    private void requestOper(String sArea) {
        WipViewOperListRequest request = new WipViewOperListRequest(this);

        request.addParam("PROCSTEP", "C", "7");
        request.addParam("AREA_ID", "S", sArea);
        request.addParam("INV_FLAG", "C", "Y");

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
                String sArea = "";

                if(sOper.equalsIgnoreCase(model.getName()))
                    return;

                for (DropDownModel OperModel : listOperModels)
                {
                    OperModel.setSelected(false);
                }

                model.setSelected(true);

                for (DropDownModel areaModel : listAreaModels) {
                    if(areaModel.isSelected())
                    {
                        sArea = areaModel.getId();
                        break;
                    }
                }

                ((TextView)findViewById(R.id.oper)).setText(model.getName());
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
            default:
                break;
        }
    }

    private void clearListView() {
        listLotModels.clear();
        adapter.notifyDataSetChanged();
    }

    private void requestSearch() {
        String sArea = "";
        String sOper = "";

        InvViewLotListByOperRequest request = new InvViewLotListByOperRequest(this);

        request.addParam("PROCSTEP", "C", "1");

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

        for (DropDownModel operModel : listOperModels) {
            if(operModel.isSelected())
            {
                sOper = operModel.getId();
                break;
            }
        }

        if(sOper == null || sOper == "")
        {
            showDialog(getString(R.string.common_word_check_stock));
            return;
        }

        request.addParam("AREA_ID", "S", sArea);
        request.addParam("OPER", "S", sOper);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                listLotModels.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;
                if(resultMap.containsKey("ROWS")) {
                    for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {
                        INVModel model = new INVModel();
                        model.setLotId((String)row.get("INV_LOT_ID"));
                        model.setMatId((String)row.get("MAT_ID"));
                        model.setDesc((String)row.get("MAT_DESC"));
                        model.setMatVer((String)row.get("MAT_VER"));
                        model.setQty(FormatUtil.convertStringToDouble((String)row.get("QTY")));
                        model.setUnit((String)row.get("UNIT"));
                        model.setOper((String)row.get("OPER_DESC"));

                        //model.setSelected(true);

                        listLotModels.add(model);
                    }

                    adapter.notifyDataSetChanged(); // 리스트 갱신
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

    //endregion
}