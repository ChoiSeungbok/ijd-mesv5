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

public class CPDA3002_PDA_TopAdapter extends BaseAdapter {

    private Context mContext;

    private List<INVModel> mModels = new ArrayList<>();

    private LayoutInflater mLayoutInflater;

    public CPDA3002_PDA_TopAdapter(Context context) {
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
            convertView = mLayoutInflater.inflate(R.layout.cell_cpda3002_top, null);

            viewHolder.dlvNo = convertView.findViewById(R.id.cellDlvNo);
            viewHolder.poNo = convertView.findViewById(R.id.cellPoNo);
            viewHolder.blNo = convertView.findViewById(R.id.cellBlNo);
            viewHolder.expDate = convertView.findViewById(R.id.cellExpDate);
            viewHolder.vendor = convertView.findViewById(R.id.cellVendor);
            viewHolder.area = convertView.findViewById(R.id.cellArea);
            viewHolder.orderId = convertView.findViewById(R.id.cellOrderId);

            viewHolder.rootLayout = convertView.findViewById(R.id.rootLayout);

            convertView.setTag(viewHolder);
        } else {
            viewHolder = (ViewHolder)convertView.getTag();
        }

        INVModel model = (INVModel)getItem(position);

        viewHolder.rootLayout.setSelected(model.isSelected());
        //ViewUtil.setSelectView(viewHolder.rootLayout, model.isSelected());
        viewHolder.dlvNo.setText(model.getDlvNo());
        viewHolder.poNo.setText(model.getPoNo());
        viewHolder.blNo.setText(model.getBlNo());
        viewHolder.expDate.setText(model.getExpDate());
        viewHolder.vendor.setText(model.getVendorId());
        viewHolder.area.setText(model.getAreaID());
        viewHolder.orderId.setText(model.getOrderID());
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
        public TextView dlvNo;
        public TextView poNo;
        public TextView blNo;
        public TextView expDate;
        public TextView vendor;
        public TextView area;
        public TextView orderId;

        public View rootLayout;
    }
}
