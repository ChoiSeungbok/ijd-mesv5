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
import com.pda.mes.model.INVModel;
import com.pda.mes.utils.FormatUtil;
import com.pda.mes.utils.ViewUtil;

import java.util.ArrayList;
import java.util.List;

public class CPDA3002_PDA_BottomAdapter extends BaseAdapter {

    private Context mContext;

    private List<INVModel> mModels = new ArrayList<>();

    private LayoutInflater mLayoutInflater;

    public CPDA3002_PDA_BottomAdapter(Context context) {
        mContext = context;
        this.mLayoutInflater = LayoutInflater.from(context);
    }

    public void setModels(List<INVModel> models) {
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
            convertView = mLayoutInflater.inflate(R.layout.cell_cpda3002_bottom, null);

            viewHolder.dlvSeq = convertView.findViewById(R.id.cellDlvSeq);
            viewHolder.matId = convertView.findViewById(R.id.cellItemCode);
            viewHolder.matVer = convertView.findViewById(R.id.cellMatVer);
            viewHolder.desc = convertView.findViewById(R.id.cellItemDesc);
            viewHolder.qty = convertView.findViewById(R.id.cellQty);
            viewHolder.confirmQty = convertView.findViewById(R.id.cellConfirmQty);
            viewHolder.unit = convertView.findViewById(R.id.cellUnit);

            viewHolder.rootLayout = convertView.findViewById(R.id.rootLayout);

            convertView.setTag(viewHolder);
        } else {
            viewHolder = (ViewHolder)convertView.getTag();
        }

        INVModel model = (INVModel)getItem(position);

        //viewHolder.rootLayout.setSelected(model.isSelected());
        ViewUtil.setSelectView(viewHolder.rootLayout, model.isSelected());

        viewHolder.dlvSeq.setText(FormatUtil.toNumFormat(model.getDlvSeq()));
        viewHolder.matId.setText(model.getMatId());
        viewHolder.matVer.setText(model.getMatVer());
        viewHolder.desc.setText(model.getDesc());
        viewHolder.qty.setText(FormatUtil.toNumFormat(model.getQty()));
        viewHolder.confirmQty.setText(FormatUtil.toNumFormat(model.getConfirmQty()));
        viewHolder.unit.setText(model.getUnit());

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
        public TextView dlvSeq;
        public TextView matId;
        public TextView matVer;
        public TextView desc;
        public TextView qty;
        public TextView confirmQty;
        public TextView unit;

        public View rootLayout;
    }
}
