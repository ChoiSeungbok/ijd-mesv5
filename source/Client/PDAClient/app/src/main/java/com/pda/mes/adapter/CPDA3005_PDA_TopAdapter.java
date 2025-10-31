package com.pda.mes.adapter;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.BaseAdapter;
import android.widget.TextView;

import com.pda.mes.R;
import com.pda.mes.model.SHPModel;

import java.util.ArrayList;
import java.util.List;

public class CPDA3005_PDA_TopAdapter extends BaseAdapter {

    private Context mContext;

    private List<SHPModel> mModels = new ArrayList<>();

    private LayoutInflater mLayoutInflater;

    public CPDA3005_PDA_TopAdapter(Context context) {
        mContext = context;
        this.mLayoutInflater = LayoutInflater.from(context);
    }

    public void setModels(List<SHPModel> models) {
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
            convertView = mLayoutInflater.inflate(R.layout.cell_cpda3005_top, null);

            viewHolder.shipNo = convertView.findViewById(R.id.cellShipNo);
            viewHolder.customerId = convertView.findViewById(R.id.cellCustomerId);
            viewHolder.area = convertView.findViewById(R.id.cellArea);
            viewHolder.shipOrdDate = convertView.findViewById(R.id.cellShipOrdDate);
            viewHolder.deliveryId = convertView.findViewById(R.id.cellDeliveryId);
            viewHolder.shipStatus = convertView.findViewById(R.id.cellShipStatus);
            viewHolder.oper = convertView.findViewById(R.id.cellOper);

            viewHolder.rootLayout = convertView.findViewById(R.id.rootLayout);

            convertView.setTag(viewHolder);
        } else {
            viewHolder = (ViewHolder)convertView.getTag();
        }

        SHPModel model = (SHPModel)getItem(position);

        viewHolder.rootLayout.setSelected(model.isSelected());
        //ViewUtil.setSelectView(viewHolder.rootLayout, model.isSelected());
        viewHolder.shipNo.setText(model.getShipNo());
        viewHolder.customerId.setText(model.getCustomerId());
        viewHolder.area.setText(model.getArea());
        viewHolder.shipOrdDate.setText(model.getShipOrdDate());
        viewHolder.deliveryId.setText(model.getDeliveryId());
        viewHolder.shipStatus.setText(model.getStatus());
        viewHolder.oper.setText(model.getOper());

        //viewHolder.rootLayout.setSelected(false);

        if(!model.isAnimate()) {
            Animation animation = AnimationUtils.loadAnimation(mContext, R.anim.fade_in);
            animation.setDuration(200);
            convertView.startAnimation(animation);
            model.setAnimate(true);
        }

        return convertView;
    }

    public static class ViewHolder {
        public TextView shipNo;
        public TextView customerId;
        public TextView area;
        public TextView shipOrdDate;
        public TextView deliveryId;
        public TextView shipStatus;
        public TextView oper;

        public View rootLayout;
    }
}
