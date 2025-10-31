package com.pda.mes.dialog;

import android.content.Context;
import android.view.View;
import android.view.ViewGroup;
import android.view.Window;
import android.widget.AdapterView;
import android.widget.LinearLayout;
import android.widget.ListView;

import com.pda.mes.R;
import com.pda.mes.adapter.DialogListAdapter;
import com.pda.mes.model.DropDownModel;

import java.util.ArrayList;
import java.util.List;

/**
 * 리스트 선택 다이얼로그
 */
public class ListDialog extends BaseDialog implements View.OnClickListener {

    public static final int RESIZE_ITEM_COUNT = 8;

    private DialogListAdapter adapter;

    private ListView listView;

    private OnSelectItemListener listener;

    public ListDialog(Context context) {
        super(context);
        View view = View.inflate(context, R.layout.dialog_list, null);
        setCanceledOnTouchOutside(true);
        setCancelable(true);
        requestWindowFeature(Window.FEATURE_NO_TITLE);

        setContentView(view);

        init();
    }

    private void init() {
        findViewById(R.id.closeButton).setOnClickListener(this);
        listView = findViewById(R.id.dialogListView);
        adapter = new DialogListAdapter(getContext());
        listView.setAdapter(adapter);
        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                listener.onClickItem((DropDownModel)adapter.getItem(i), i);
                dismiss();
            }
        });
    }


    public void setData(List<DropDownModel> models, int selectedIndex) {

        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(getContext().getResources().getDimensionPixelOffset(R.dimen.list_dialog_width_large), ViewGroup.LayoutParams.WRAP_CONTENT);
        findViewById(R.id.rootLayout).setLayoutParams(params);

        for(int i = 0 ; i < models.size() ; i++) {
            DropDownModel model = models.get(i);
            model.setSelected(i == selectedIndex);
        }

        adapter.setModels(models);
        adapter.notifyDataSetChanged();

        if(adapter.getCount() > RESIZE_ITEM_COUNT) {
            resizeListView();
        }

        listView.setSelection(selectedIndex);
    }

    public void setData(String[] array, int selectedIndex) {

        List<DropDownModel> models = new ArrayList<>();

        for(int i = 0 ; i < array.length ; i++) {
            DropDownModel model = new DropDownModel();
            model.setName(array[i]);
            model.setSelected(i == selectedIndex);
            models.add(model);
        }

        adapter.setModels(models);
        adapter.notifyDataSetChanged();

        if(adapter.getCount() > RESIZE_ITEM_COUNT) {
            resizeListView();
        }

        listView.setSelection(selectedIndex);
    }

    private void resizeListView() {

        listView.post(new Runnable() {
            @Override
            public void run() {
                View item = adapter.getView(0, null, listView);
                item.measure(0, 0);
                LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, (int)(adapter.getCount() * item.getMeasuredHeight()) + getContext().getResources().getDimensionPixelOffset(R.dimen.content_padding));
                listView.setLayoutParams(params);
            }
        });
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
        void onClickItem(DropDownModel model, int index);
    }
}
