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
import com.pda.mes.utils.ViewUtil;

import java.util.ArrayList;
import java.util.List;

public class CPDA2003_PDA_Adapter extends BaseAdapter {

    private Context mContext;

    private CPDA2003_PDA_Adapter.OnClickCellListener listener;

    private List<WIPModel> mModels = new ArrayList<>();

    private LayoutInflater mLayoutInflater;

    public CPDA2003_PDA_Adapter(Context context) {
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
            convertView = mLayoutInflater.inflate(R.layout.cell_cpda2003, null);

            viewHolder.lossCode = convertView.findViewById(R.id.cellLossCode);
            viewHolder.lossDesc = convertView.findViewById(R.id.cellLossDesc);
            viewHolder.lossQty = convertView.findViewById(R.id.cellLossQty);

            viewHolder.rootLayout = convertView.findViewById(R.id.rootLayout);

            convertView.setTag(viewHolder);
        } else {
            viewHolder = (ViewHolder)convertView.getTag();
        }

        final WIPModel model = (WIPModel)getItem(position);

        //viewHolder.rootLayout.setSelected(model.isSelected());
        ViewUtil.setSelectView(viewHolder.rootLayout, model.isSelected());
        viewHolder.lossCode.setText(model.getLossCode());
        viewHolder.lossDesc.setText(model.getLossDesc());
        viewHolder.lossQty.setText(FormatUtil.toNumFormat(model.getLossQty()));

//        x
        //viewHolder.rootLayout.setSelected(false);

        if(!model.isAnimate()) {
            Animation animation = AnimationUtils.loadAnimation(mContext, R.anim.fade_in);
            animation.setDuration(200);
            convertView.startAnimation(animation);
            model.setAnimate(true);
        }

        viewHolder.lossQty.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if(null != listener) {
                    listener.onClickInput(model);
                }
            }
        });

        return convertView;
    }

    public void setOnClickCellListener(CPDA2003_PDA_Adapter.OnClickCellListener $listener) {
        listener = $listener;
    }

    public interface OnClickCellListener {
        void onClickInput(WIPModel model);
    }

    public static class ViewHolder {
        public TextView lossCode;
        public TextView lossDesc;
        public TextView lossQty;

        public View rootLayout;
    }
}
