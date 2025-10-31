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

public class DialogShipOrderAdapter extends BaseAdapter {

    private Context mContext;

    private List<SHPModel> mModels = new ArrayList<>();

    private LayoutInflater mLayoutInflater;

    public DialogShipOrderAdapter(Context context) {
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
            convertView = mLayoutInflater.inflate(R.layout.cell_ship_order_dialog_list, null);

            viewHolder.shipOrderId = convertView.findViewById(R.id.cellShipOrderId);
            viewHolder.shipOrdDate = convertView.findViewById(R.id.cellShipOrdDate);
            viewHolder.customerName = convertView.findViewById(R.id.cellCustomerName);
            viewHolder.deliveryName = convertView.findViewById(R.id.cellDeliveryName);

            viewHolder.rootLayout = convertView.findViewById(R.id.rootLayout);

            convertView.setTag(viewHolder);
        } else {
            viewHolder = (ViewHolder)convertView.getTag();
        }

        SHPModel model = (SHPModel)getItem(position);

        viewHolder.rootLayout.setSelected(model.isSelected());
        //ViewUtil.setSelectView(viewHolder.rootLayout, model.isSelected());
        viewHolder.shipOrderId.setText(model.getShipNo());
        viewHolder.shipOrdDate.setText(model.getShipOrdDate());
        viewHolder.customerName.setText(model.getCustomerName());
        viewHolder.deliveryName.setText(model.getDeliveryName());
//        x
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
        public TextView shipOrderId;
        public TextView shipOrdDate;
        public TextView customerName;
        public TextView deliveryName;

        public View rootLayout;
    }
}
