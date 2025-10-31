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

import java.util.ArrayList;
import java.util.List;

public class CPDA2011_PDA_TopAdapter extends BaseAdapter {

    private Context mContext;

    private List<INVModel> mModels = new ArrayList<>();

    private LayoutInflater mLayoutInflater;

    public CPDA2011_PDA_TopAdapter(Context context) {
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
            convertView = mLayoutInflater.inflate(R.layout.cell_cpda2011_top, null);

            viewHolder.requestNo = convertView.findViewById(R.id.cellReqNo);
            viewHolder.itemCode = convertView.findViewById(R.id.cellItemCode);
            viewHolder.itemDesc = convertView.findViewById(R.id.cellItemDesc);
            viewHolder.matVer = convertView.findViewById(R.id.cellMatVer);
            viewHolder.requestQty = convertView.findViewById(R.id.cellReqQty);
            viewHolder.regQty = convertView.findViewById(R.id.cellRegQty);
            viewHolder.unit = convertView.findViewById(R.id.cellUnit);
            viewHolder.stock = convertView.findViewById(R.id.cellStock);
            viewHolder.reqStatus = convertView.findViewById(R.id.cellReqStatus);
            viewHolder.rootLayout = convertView.findViewById(R.id.rootLayout);

            convertView.setTag(viewHolder);
        } else {
            viewHolder = (ViewHolder)convertView.getTag();
        }

        INVModel model = (INVModel)getItem(position);

        viewHolder.rootLayout.setSelected(model.isSelected());
        //ViewUtil.setSelectView(viewHolder.rootLayout, model.isSelected());
        viewHolder.requestNo.setText(model.getInvReqNo());
        viewHolder.itemCode.setText(model.getMatId());
        viewHolder.itemDesc.setText(model.getDesc());
        viewHolder.matVer.setText(model.getMatVer());
        viewHolder.requestQty.setText(FormatUtil.toNumFormat(model.getReqQty()));
        viewHolder.regQty.setText(FormatUtil.toNumFormat(model.getRegQty()));
        viewHolder.unit.setText(model.getUnit());
        viewHolder.stock.setText(model.getStock());
        viewHolder.reqStatus.setText(model.getReqDtlStatus());
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
        public TextView requestNo;
        public TextView itemCode;
        public TextView itemDesc;
        public TextView matVer;
        public TextView requestQty;
        public TextView regQty;
        public TextView unit;
        public TextView stock;
        public TextView reqStatus;

        public View rootLayout;
    }
}
