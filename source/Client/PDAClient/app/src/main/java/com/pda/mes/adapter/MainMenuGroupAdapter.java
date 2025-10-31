package com.pda.mes.adapter;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import com.pda.mes.R;
import com.pda.mes.model.MenuModel;

import java.util.ArrayList;
import java.util.List;

public class MainMenuGroupAdapter extends BaseAdapter {
    private List<MenuModel> mModels = new ArrayList<>();

     private MainMenuGroupAdapter.OnClickCell mListener;

    private LayoutInflater mLayoutInflater;

    private Context context;

    public MainMenuGroupAdapter(Context context) {
        this.context = context;
        this.mLayoutInflater = LayoutInflater.from(context);
    }

    public void setModels(List<MenuModel> models) {
        mModels = models;
    }

    @Override
    public int getCount() {
        return mModels.size();
    }

    @Override
    public Object getItem(int position) {
        return mModels.get(position);
    }

    @Override
    public long getItemId(int i) {
        return 0;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup viewGroup) {

        MainMenuGroupAdapter.ViewHolder viewHolder = new MainMenuGroupAdapter.ViewHolder();

        if(null == convertView) {
            convertView = mLayoutInflater.inflate(R.layout.cell_main_menu, null);

            viewHolder.titleLabel = convertView.findViewById(R.id.menuLabel);
            viewHolder.rootLayout = convertView.findViewById(R.id.rootLayout);

            convertView.setTag(viewHolder);
        }
        else {
            viewHolder = (MainMenuGroupAdapter.ViewHolder)convertView.getTag();
        }

        final MenuModel model = (MenuModel)getItem(position);

        //viewHolder.rootLayout.setEnabled(null != model.getIntentClass());
        viewHolder.titleLabel.setText(model.getTitle());
        viewHolder.rootLayout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                mListener.onClickMenu(model);
            }
        });

        return convertView;
    }

    private int convertPositionOffset(int position) {
        return position * 30;
    }

    public static class ViewHolder {
        public TextView titleLabel;
        public View rootLayout;
    }

    public void setOnClickCellListener(MainMenuGroupAdapter.OnClickCell listener) {
        mListener = listener;
    }

    public interface OnClickCell {
        void onClickMenu(MenuModel model);
    }
}
