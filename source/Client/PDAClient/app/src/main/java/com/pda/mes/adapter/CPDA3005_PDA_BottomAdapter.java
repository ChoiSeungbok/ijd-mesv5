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
import com.pda.mes.utils.FormatUtil;
import com.pda.mes.utils.ViewUtil;

import java.util.ArrayList;
import java.util.List;

public class CPDA3005_PDA_BottomAdapter extends BaseAdapter {

    private Context mContext;

    private List<SHPModel> mModels = new ArrayList<>();

    private LayoutInflater mLayoutInflater;

    public CPDA3005_PDA_BottomAdapter(Context context) {
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
            convertView = mLayoutInflater.inflate(R.layout.cell_cpda3005_bottom, null);

            viewHolder.shipNo = convertView.findViewById(R.id.cellShipNo);
            viewHolder.seq = convertView.findViewById(R.id.cellSeq);
            viewHolder.ItemDesc = convertView.findViewById(R.id.cellItemDesc);
            viewHolder.packOrderId = convertView.findViewById(R.id.cellPackOrderId);
            viewHolder.packLineNo = convertView.findViewById(R.id.cellPackLineNo);
            viewHolder.qty = convertView.findViewById(R.id.cellQty);
            viewHolder.unit = convertView.findViewById(R.id.cellUnit);
            viewHolder.oper = convertView.findViewById(R.id.cellOper);

            viewHolder.rootLayout = convertView.findViewById(R.id.rootLayout);

            convertView.setTag(viewHolder);
        } else {
            viewHolder = (ViewHolder)convertView.getTag();
        }

        SHPModel model = (SHPModel)getItem(position);

        //viewHolder.rootLayout.setSelected(model.isSelected());
        ViewUtil.setSelectView(viewHolder.rootLayout, model.isSelected());
        viewHolder.shipNo.setText(model.getShipNo());
        viewHolder.seq.setText(FormatUtil.toNumFormat(model.getSeq()));
        viewHolder.ItemDesc.setText(model.getDesc());
        viewHolder.packOrderId.setText(model.getPackOrderId());
        viewHolder.packLineNo.setText(FormatUtil.toNumFormat(model.getPackLineNo()));
        viewHolder.qty.setText(FormatUtil.toNumFormat(model.getQty()));
        viewHolder.unit.setText(model.getUnit());
        viewHolder.oper.setText(model.getOper());

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
        public TextView shipNo;
        public TextView seq;
        public TextView ItemDesc;
        public TextView packOrderId;
        public TextView packLineNo;
        public TextView qty;
        public TextView unit;
        public TextView oper;

        public View rootLayout;
    }
}
