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
import com.pda.mes.model.WIPModel;
import com.pda.mes.utils.FormatUtil;

import java.util.ArrayList;
import java.util.List;

public class DialogWipLotAdapter extends BaseAdapter {

    private Context mContext;

    private List<WIPModel> mModels = new ArrayList<>();

    private LayoutInflater mLayoutInflater;

    public DialogWipLotAdapter(Context context) {
        mContext = context;
        this.mLayoutInflater = LayoutInflater.from(context);
    }

    public void setModels(List<WIPModel> models) {
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
            convertView = mLayoutInflater.inflate(R.layout.cell_wip_lot_dialog_list, null);

            viewHolder.lotId = convertView.findViewById(R.id.cellLotId);
            viewHolder.lotItemCode = convertView.findViewById(R.id.cellLotItemCode);
            viewHolder.lotItemDesc = convertView.findViewById(R.id.cellLotItemDesc);
            viewHolder.lotQty = convertView.findViewById(R.id.cellLotQty);
            viewHolder.ordQty = convertView.findViewById(R.id.cellOrdQty);
            viewHolder.workOrderId = convertView.findViewById(R.id.cellOrderId);

            viewHolder.rootLayout = convertView.findViewById(R.id.rootLayout);

            convertView.setTag(viewHolder);
        } else {
            viewHolder = (ViewHolder)convertView.getTag();
        }

        WIPModel model = (WIPModel)getItem(position);

        viewHolder.rootLayout.setSelected(model.isSelected());
        //ViewUtil.setSelectView(viewHolder.rootLayout, model.isSelected());
        viewHolder.lotId.setText(model.getLotId());
        viewHolder.lotItemCode.setText(model.getMatId());
        viewHolder.lotItemDesc.setText(model.getDesc());
        viewHolder.lotQty.setText(FormatUtil.toNumFormat(model.getQty()));
        viewHolder.ordQty.setText(FormatUtil.toNumFormat(model.getOrdQty()));
        viewHolder.workOrderId.setText(model.getWorkOrderId());
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
        public TextView lotId;
        public TextView lotItemCode;
        public TextView lotItemDesc;
        public TextView lotQty;
        public TextView ordQty;
        public TextView workOrderId;

        public View rootLayout;
    }
}
