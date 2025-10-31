package com.pda.mes.dialog;

import android.content.Context;
import android.view.View;
import android.view.Window;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;

import com.pda.mes.R;
import com.pda.mes.adapter.DialogWipLotAdapter;
import com.pda.mes.model.DropDownModel;
import com.pda.mes.model.WIPModel;

import java.util.List;

/**
 * 리스트 아이템 선택 다이얼로그
 */
public class ComboBoxWipLotDialog extends BaseDialog {

	private DialogWipLotAdapter adapter;

	private ListView listView;

	private OnClickListener listener;

	public ComboBoxWipLotDialog(Context context) {
        super(context);
		View view = View.inflate(context, R.layout.dialog_wip_lot_combobox, null);
		setCanceledOnTouchOutside(true);
		setCancelable(true);
        requestWindowFeature(Window.FEATURE_NO_TITLE);

		setContentView(view);

		init();
	}

	private void init() {
		listView = findViewById(R.id.dialogListView);
		adapter = new DialogWipLotAdapter(getContext());
		listView.setAdapter(adapter);

		listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
			@Override
			public void onItemClick(AdapterView<?> adapterView, View view, int position, long l) {

				for(int i = 0 ; i < adapter.getCount() ; i++) {
					WIPModel model = (WIPModel)adapter.getItem(i);

					if(i == position) {
						if(model.isSelected()) {
							model.setSelected(false);
						} else if(!model.isSelected()) {
							model.setSelected(true);
						}
					}
				}

				adapter.notifyDataSetChanged();
			}
		});

		Button selectButton = findViewById(R.id.selectButton);
		selectButton.setOnClickListener(new Button.OnClickListener() {
			@Override
			public void onClick(View view) {
				// TODO : click event
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
					WIPModel model = (WIPModel)adapter.getItem(i);

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

	public void setData(List<WIPModel> models) {
		adapter.setModels(models);
		adapter.notifyDataSetChanged();

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

	public void setOnClickListener(OnClickListener listener) {
		this.listener = listener;
	}

	public interface OnClickListener {
		void onClick(View view);
	}
}
