package com.pda.mes.dialog;

import android.content.Context;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.view.Window;
import android.view.inputmethod.InputMethodManager;
import android.widget.AdapterView;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;

import com.pda.mes.R;
import com.pda.mes.adapter.DropDownAdapter;
import com.pda.mes.model.DropDownModel;

import java.util.ArrayList;
import java.util.List;

/**
 * 리스트 아이템 선택 다이얼로그
 */
public class ComboBoxSearchDialog extends BaseDialog implements View.OnClickListener {

	private DropDownAdapter adapter;
	private DropDownAdapter allAdapter;

	private ListView listView;
	private ListView allListView;

	private OnSelectItemListener listener;

	public ComboBoxSearchDialog(Context context) {
        super(context);
		View view = View.inflate(context, R.layout.dialog_combobox_search, null);
		setCanceledOnTouchOutside(true);
		setCancelable(true);
        requestWindowFeature(Window.FEATURE_NO_TITLE);

		setContentView(view);

		init();
	}

	private void init() {
		findViewById(R.id.closeButton).setOnClickListener(this);
		listView = findViewById(R.id.dialogListView);
		adapter = new DropDownAdapter(getContext());

		listView.setAdapter(adapter);

		allListView = findViewById(R.id.copyListView);
		allAdapter = new DropDownAdapter(getContext());

		allListView.setAdapter(allAdapter);

		listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
			@Override
			public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
				listener.onClickItem((DropDownModel)adapter.getItem(i));
				dismiss();
			}
		});

		final EditText e = (EditText) findViewById(R.id.comboboxId);

		e.addTextChangedListener(new TextWatcher() {

			@Override
			public void onTextChanged(CharSequence s, int start, int before, int count) {

				List<DropDownModel> dModels = new ArrayList<>();

				for (int i=0; i<allAdapter.getCount(); i++)
				{
					DropDownModel model = (DropDownModel)allAdapter.getItem(i);

					if((model.getName().toUpperCase()).contains(e.getText().toString().toUpperCase()))
					{
						dModels.add(model);
					}
				}

				adapter.setModels(dModels);

				adapter.notifyDataSetChanged();
			}
			@Override
			public void beforeTextChanged(CharSequence s, int start, int count, int after) {}
			@Override
			public void afterTextChanged(Editable s) {}
		});
	}

	public void setDialogTitle(String title) {
		((TextView)findViewById(R.id.dialogTitleLabel)).setText(title);
	}

	public void setData(List<DropDownModel> models) {
		adapter.setModels(models);
		adapter.notifyDataSetChanged();

		allAdapter.setModels(models);

		int selectIndex = 0;

		for(int i = 0 ; i < models.size() ; i++) {
			if(models.get(i).isSelected()) {
				selectIndex = i;
				break;
			}
		}

		listView.setSelection(selectIndex);
	}

	public void showDialog() {

	    if(adapter.getCount() == 0) {
            listView.setVisibility(View.GONE);
            findViewById(R.id.emptyView).setVisibility(View.VISIBLE);
        }

	    show();
    }

	@Override
	public void onClick(View view) {
		if(view.getId() == R.id.closeButton) {
			dismiss();
			return;
		}
	}

	public void setOnSelectItemListener(OnSelectItemListener listener) {
		this.listener = listener;
	}

	public interface OnSelectItemListener {
		void onClickItem(DropDownModel model);
	}
}
