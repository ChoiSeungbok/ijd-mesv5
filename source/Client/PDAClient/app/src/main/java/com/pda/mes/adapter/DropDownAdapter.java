package com.pda.mes.adapter;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import com.pda.mes.R;
import com.pda.mes.model.DropDownModel;

import java.util.ArrayList;
import java.util.List;

public class DropDownAdapter extends BaseAdapter {

    private List<DropDownModel> mModels = new ArrayList<>();

    private LayoutInflater mLayoutInflater;

    public DropDownAdapter(Context context) {
        this.mLayoutInflater = LayoutInflater.from(context);
    }

    public void setModels(List<DropDownModel> models) {
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

        ViewHolder viewHolder = new ViewHolder();

        if(null == convertView) {
            convertView = mLayoutInflater.inflate(R.layout.cell_dialog_list, null);

            viewHolder.nameLabel = convertView.findViewById(R.id.nameLabel);
            viewHolder.nameLabelLayout = convertView.findViewById(R.id.nameLabelLayout);

            convertView.setTag(viewHolder);
        } else {
            viewHolder = (ViewHolder)convertView.getTag();
        }

        DropDownModel model = (DropDownModel)getItem(position);

        viewHolder.nameLabelLayout.setSelected(model.isSelected());
        viewHolder.nameLabel.setText(model.getName());

        return convertView;
    }

    public static class ViewHolder {
        public TextView nameLabel;
        public View nameLabelLayout;
    }
}
