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

public class CPDA2015_PDA_BottomAdapter extends BaseAdapter {

    private Context mContext;

    private List<SHPModel> mModels = new ArrayList<>();

    private LayoutInflater mLayoutInflater;

    public CPDA2015_PDA_BottomAdapter(Context context) {
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
            convertView = mLayoutInflater.inflate(R.layout.cell_cpda2015_bottom, null);

            viewHolder.rowNo = convertView.findViewById(R.id.cellRowNo);
            viewHolder.processLotId = convertView.findViewById(R.id.cellProcessLotId);
            viewHolder.shipLotId = convertView.findViewById(R.id.cellShipLotId);
            viewHolder.ItemDesc = convertView.findViewById(R.id.cellItemDesc);
            viewHolder.labelName = convertView.findViewById(R.id.cellLabelName);
            viewHolder.qty = convertView.findViewById(R.id.cellQty);
            viewHolder.unit = convertView.findViewById(R.id.cellUnit);
            viewHolder.shipOrderId = convertView.findViewById(R.id.cellShipOrderId);
            viewHolder.middleBoxId = convertView.findViewById(R.id.cellMiddleBoxId);
            viewHolder.finalBoxId = convertView.findViewById(R.id.cellFinalBoxId);

            viewHolder.rootLayout = convertView.findViewById(R.id.rootLayout);

            convertView.setTag(viewHolder);
        } else {
            viewHolder = (ViewHolder)convertView.getTag();
        }

        SHPModel model = (SHPModel)getItem(position);

        //viewHolder.rootLayout.setSelected(model.isSelected());
        ViewUtil.setSelectView(viewHolder.rootLayout, model.isSelected());
        viewHolder.rowNo.setText(String.valueOf(position + 1));
        viewHolder.processLotId.setText(model.getProcessLotId());
        viewHolder.shipLotId.setText(model.getShipLotId());
        viewHolder.ItemDesc.setText(model.getDesc());
        viewHolder.labelName.setText(model.getLabelName());
        viewHolder.qty.setText(FormatUtil.toNumFormat(model.getQty()));
        viewHolder.unit.setText(model.getUnit());
        viewHolder.shipOrderId.setText(model.getShipNo());
        viewHolder.middleBoxId.setText(model.getBoxId());
        viewHolder.finalBoxId.setText(model.getFinalBoxId());

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
        public TextView rowNo;
        public TextView processLotId;
        public TextView shipLotId;
        public TextView ItemDesc;
        public TextView qty;
        public TextView unit;
        public TextView shipOrderId;
        public TextView middleBoxId;
        public TextView finalBoxId;
        public TextView labelName;
        public View rootLayout;
    }
}
