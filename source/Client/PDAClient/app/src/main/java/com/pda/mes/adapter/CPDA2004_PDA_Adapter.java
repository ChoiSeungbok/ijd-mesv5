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

public class CPDA2004_PDA_Adapter extends BaseAdapter {

    private Context mContext;

    private List<WIPModel> mModels = new ArrayList<>();

    private LayoutInflater mLayoutInflater;

    public CPDA2004_PDA_Adapter(Context context) {
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
            convertView = mLayoutInflater.inflate(R.layout.cell_cpda2004, null);

            viewHolder.resCode = convertView.findViewById(R.id.cellResCode);
            viewHolder.resName = convertView.findViewById(R.id.cellResName);
            viewHolder.downStatus = convertView.findViewById(R.id.cellStatus);
            viewHolder.downStartTime = convertView.findViewById(R.id.cellDownStartTime);
            viewHolder.downEndTime = convertView.findViewById(R.id.cellDownEndTime);
            viewHolder.histSeq = convertView.findViewById(R.id.cellSeq);
            viewHolder.rootLayout = convertView.findViewById(R.id.rootLayout);

            convertView.setTag(viewHolder);
        } else {
            viewHolder = (ViewHolder)convertView.getTag();
        }

        WIPModel model = (WIPModel)getItem(position);

        viewHolder.rootLayout.setSelected(model.isSelected());
        //ViewUtil.setSelectView(viewHolder.rootLayout, model.isSelected());
        viewHolder.resCode.setText(model.getResCode());
        viewHolder.resName.setText(model.getResName());
        viewHolder.downStatus.setText(model.getStatus());
        viewHolder.downStartTime.setText(model.getDownStartTime());
        viewHolder.downEndTime.setText(model.getDownEndTime());
        viewHolder.histSeq.setText(String.valueOf(model.getSeq()));
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
        public TextView resCode;
        public TextView resName;
        public TextView downStatus;
        public TextView downStartTime;
        public TextView downEndTime;
        public TextView histSeq;

        public View rootLayout;
    }
}
