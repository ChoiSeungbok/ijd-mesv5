package com.pda.mes.dialog;

import android.app.DatePickerDialog;
import android.content.Context;
import android.icu.util.Calendar;
import android.text.TextUtils;
import android.view.View;
import android.view.Window;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.ListView;
import android.widget.TextView;

import com.pda.mes.R;
import com.pda.mes.adapter.DialogShipOrderAdapter;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.SQLQueryRequest;
import com.pda.mes.manager.AppLogManager;
import com.pda.mes.manager.AppSettingManager;
import com.pda.mes.manager.SessionManager;
import com.pda.mes.model.DropDownModel;
import com.pda.mes.model.SHPModel;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Locale;
import java.util.Map;

/**
 * 출하지시번호 선택 다이얼로그
 */
public class ComboBoxShipOrderDialog extends BaseDialog {

	private DialogShipOrderAdapter adapter;

	private ListView listView;

	private OnClickListener listener;

	private List<DropDownModel> listAreaModels = new ArrayList<>(); //AREA LIST(사업부)
	private List<DropDownModel> listCustomerModels = new ArrayList<>(); //고객사
	private List<SHPModel> listShipOrderModels = new ArrayList<>(); // 출하지시 리스트

	private MessageDialog messageDialog;

	private String userAreaId;

	public ComboBoxShipOrderDialog(Context context) throws InterruptedException {
        super(context);
		View view = View.inflate(context, R.layout.dialog_ship_order_combobox, null);
		setCanceledOnTouchOutside(true);
		setCancelable(true);
        requestWindowFeature(Window.FEATURE_NO_TITLE);

		setContentView(view);

		userAreaId = SessionManager.getUserAreaId(context);

		requestAreaList();
		Thread.sleep(500);
		requestCustomerList();
		setDateTime();


		init();
	}

	private void init() {
		listView = findViewById(R.id.dialogListView);
		adapter = new DialogShipOrderAdapter(this.getContext());
		adapter.setModels(listShipOrderModels);
		listView.setAdapter(adapter);

		listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
			@Override
			public void onItemClick(AdapterView<?> adapterView, View view, int position, long l) {

				for(int i = 0 ; i < adapter.getCount() ; i++) {
					SHPModel model = (SHPModel)adapter.getItem(i);

					if(i == position) {
						model.setSelected(true);
					}
					else
					{
						model.setSelected(false);
					}
				}

				adapter.notifyDataSetChanged();
			}
		});

		Button areaButton = (Button)findViewById(R.id.area);
		areaButton.setOnClickListener(new Button.OnClickListener() {
			@Override
			public void onClick(View view) {
				showAreaDialog();
			}
		});

		Button customerButton = (Button)findViewById(R.id.customer);
		customerButton.setOnClickListener(new Button.OnClickListener() {
			@Override
			public void onClick(View view) {
				showCustomerDialog();
			}
		});

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

		Button searchButton = findViewById(R.id.searchButton);
		searchButton.setOnClickListener(new Button.OnClickListener() {
			@Override
			public void onClick(View view) {
				requestShipOrder();
			}
		});

		Button selectButton = findViewById(R.id.selectButton);
		selectButton.setOnClickListener(new Button.OnClickListener() {
			@Override
			public void onClick(View view) {
				// TODO : click event
				if (listShipOrderModels.size() <= 0)
				{
					messageDialog = new MessageDialog(view.getContext());
					messageDialog.setDialog(view.getContext().getString(R.string.alert_message_no_object));
					messageDialog.show();
					return;
				}

				boolean bSelect = false;

				for(SHPModel model : listShipOrderModels)
				{
					if(model.isSelected())
					{
						bSelect = true;
						break;
					}
				}

				if(!bSelect)
				{
					messageDialog = new MessageDialog(view.getContext());
					messageDialog.setDialog(view.getContext().getString(R.string.alert_message_no_object));
					messageDialog.show();
					return;
				}

				listener.onClick(view);
				dismiss();
			}
		});

		Button closeButton = findViewById(R.id.closeButton);
		closeButton.setOnClickListener(new Button.OnClickListener() {
			@Override
			public void onClick(View view) {
				//선택된 항목 모두 초기화
				for(int i = 0 ; i < adapter.getCount() ; i++) {
					SHPModel model = (SHPModel)adapter.getItem(i);

					model.setSelected(false);
				}

				adapter.notifyDataSetChanged();

				dismiss();
			}
		});
	}

	public void setDialogTitle(String title) {
		((TextView)findViewById(R.id.dialogTitleLabel)).setText(title);
	}

	public void setData(List<SHPModel> models) {
	}

	public List<SHPModel> getData()
	{
		return listShipOrderModels;
	}

	public void showDialog() {
	    show();
    }

	public void setOnClickListener(OnClickListener listener) {
		this.listener = listener;
	}

	public interface OnClickListener {
		void onClick(View view);
	}

	//region Function Event
	private void showAreaDialog() {
		ComboBoxDialog dialog = new ComboBoxDialog(this.getContext());
		dialog.setDialogTitle(this.getContext().getString(R.string.common_word_area));
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

	private void showCustomerDialog() {
		ComboBoxSearchDialog dialog = new ComboBoxSearchDialog(this.getContext());
		dialog.setDialogTitle(this.getContext().getString(R.string.common_word_customer_id));
		dialog.setData(listCustomerModels);
		dialog.setOnSelectItemListener(new ComboBoxSearchDialog.OnSelectItemListener() {
			@Override
			public void onClickItem(DropDownModel model) {
				// factory 를 변경하지 않으면 아무것도 하지 않는다.
				String sCustomer = ((TextView)findViewById(R.id.customer)).getText().toString();

				if(sCustomer.equalsIgnoreCase(model.getName()))
					return;

				((TextView)findViewById(R.id.customer)).setText(model.getName());

				for (DropDownModel customerModel : listCustomerModels)
				{
					customerModel.setSelected(false);
				}

				model.setSelected(true);

				init(1);
			}
		});
		dialog.showDialog();
	}

	private void requestCustomerList() {
		String requestQuery
				= "SELECT KEY_1 CUSTOMER, DATA_1 CUSTOMER_DESC"
				+ " FROM MGCMTBLDAT"
				+ " WHERE 1 = 1"
				+ " AND FACTORY = '" + AppSettingManager.getLoginFactory(this.getContext()) + "'"
				+ " AND TABLE_NAME = \'C_CUSTOMER\'";

		SQLQueryRequest request = new SQLQueryRequest(this.getContext(), requestQuery);

		request.request(new Request.RequestHandler() {
			@Override
			public void onResult(Object result) {
				Map<String, Object> resultMap = (Map<String, Object>)result;

				if(resultMap.containsKey("ROWS")) {
					setCustomer((List<Map<String, String>>)resultMap.get("ROWS"));
				}
			}
		});
	}

	private void requestShipOrder() {
		String sArea = ((TextView)findViewById(R.id.area)).getText().toString();
		String sCustomer = ((TextView)findViewById(R.id.customer)).getText().toString();

		if(sArea == null || sArea == "")
		{
			messageDialog = new MessageDialog(this.getContext());
			messageDialog.setDialog(this.getContext().getString(R.string.common_word_check_area));
			messageDialog.show();
			return;
		}

		for (DropDownModel areaModel : listAreaModels) {
			if (areaModel.isSelected()) {
				sArea = areaModel.getId();
				break;
			}
		}

		for (DropDownModel customerModel : listCustomerModels) {
			if (customerModel.isSelected()) {
				sCustomer = customerModel.getId();
				break;
			}
		}

		String requestQuery
				= "SELECT SHIP_ORDER_ID, TO_CHAR(TO_DATE(SUBSTR(SHIP_ORD_DATE, 0, 8), 'yyyy-MM-dd'), 'yyyy-MM-dd') SHIP_ORD_DATE, CUSTOMER_NAME, DELIVERY_NAME"
				+ " FROM CSHPORDMST"
				+ " WHERE 1 = 1"
				+ " AND FACTORY = '" + AppSettingManager.getLoginFactory(this.getContext()) + "'";

				if(!sArea.isEmpty())
				{
					requestQuery += " AND AREA_ID = '" + sArea + "'";
				}

				if(!sCustomer.isEmpty())
				{
					requestQuery += " AND CUSTOMER_ID = '" + sCustomer + "'";
				}

				requestQuery += " AND SHIP_ORD_DATE BETWEEN '" + ((TextView)findViewById(R.id.shipFromDate)).getText().toString().replace("-", "") + "000000'"
				+ " AND '" + ((TextView)findViewById(R.id.shipToDate)).getText().toString().replace("-", "") + "235959'"
				+ " AND DELETE_FLAG = ' '"
				+ " ORDER BY SHIP_ORDER_ID";

		SQLQueryRequest request = new SQLQueryRequest(this.getContext(), requestQuery);

		request.request(new Request.RequestHandler() {
			@Override
			public void onResult(Object result) {
				listShipOrderModels.clear();

				Map<String, Object> resultMap = (Map<String, Object>)result;

				if(resultMap.containsKey("ROWS")) {
					try {
						for(Map<String, String> row : (List<Map<String, String>>)resultMap.get("ROWS")) {

							SHPModel model = new SHPModel();
							model.setShipNo((String)row.get("SHIP_ORDER_ID"));
							model.setShipOrdDate((String)row.get("SHIP_ORD_DATE"));
							model.setCustomerName((String)row.get("CUSTOMER_NAME"));
							model.setDeliveryName((String)row.get("DELIVERY_NAME"));

							listShipOrderModels.add(model);
						}
					}
					catch(RuntimeException re) {
						throw re;
					}
					catch(Exception e) {
						listShipOrderModels.clear();
					}
				}

				adapter.notifyDataSetChanged();
			}
		});
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

		DatePickerDialog dialog = new DatePickerDialog(this.getContext(), fromListener, iFromYear, iFromMonth - 1, iFromDay);
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

		DatePickerDialog dialog = new DatePickerDialog(this.getContext(), toListener, iToYear, iToMonth - 1, iToDay);
		dialog.show();
	}

	private void requestAreaList() {
		String requestQuery
				= "SELECT KEY_1 AREA, DATA_1 AREA_DESC"
				+ " FROM MGCMTBLDAT"
				+ " WHERE 1 = 1"
				+ " AND FACTORY = '" + AppSettingManager.getLoginFactory(this.getContext()) + "'"
				+ " AND TABLE_NAME = \'AREA\'";

		SQLQueryRequest request = new SQLQueryRequest(this.getContext(), requestQuery);

		request.request(new Request.RequestHandler() {
			@Override
			public void onResult(Object result) {
				Map<String, Object> resultMap = (Map<String, Object>)result;

				if(resultMap.containsKey("ROWS")) {
					setArea((List<Map<String, String>>)resultMap.get("ROWS"));
				}
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
				((Button) findViewById(R.id.area)).setText(userAreaId);
			}

		} catch(RuntimeException re) {
			throw re;
		} catch(Exception e) {
			AppLogManager.printErrorLog(e.getMessage());
		}
	}

	private void setCustomer(List<Map<String, String>> rows) {
		listCustomerModels.clear();

		try {
			for(Map<String, String> row : rows) {
				DropDownModel model = new DropDownModel();
				model.setId(row.get("CUSTOMER"));
				model.setName(row.get("CUSTOMER_DESC"));

				listCustomerModels.add(model);
			}
		} catch(RuntimeException re) {
			throw re;
		} catch(Exception e) {
			AppLogManager.printErrorLog(e.getMessage());
		}

		((TextView)findViewById(R.id.customer)).setText("");
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

	private void init(int iSeq)
	{
		int iMethod = iSeq;
		switch (iMethod)
		{
			case 1 :
				//리스트 초기화
				clearListView();
				break;
			default:
				break;
		}
	}

	private void clearListView(){
		listShipOrderModels.clear();
		adapter.notifyDataSetChanged();
	}
	//endregion
}
