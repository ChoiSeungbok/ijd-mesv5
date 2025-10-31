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
import com.pda.mes.model.MenuModel;

import java.util.ArrayList;
import java.util.List;

public class MainMenuAdapter extends BaseAdapter {

    private List<MenuModel> mModels = new ArrayList<>();

    private OnClickCell mListener;

    private LayoutInflater mLayoutInflater;

    private Context context;

    public MainMenuAdapter(Context context) {
        this.context = context;
        this.mLayoutInflater = LayoutInflater.from(context);
    }

    public void setModels(List<MenuModel> models) {
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
            convertView = mLayoutInflater.inflate(R.layout.cell_main_menu, null);

            viewHolder.titleLabel = convertView.findViewById(R.id.menuLabel);
            viewHolder.rootLayout = convertView.findViewById(R.id.rootLayout);

            convertView.setTag(viewHolder);
        } else {
            viewHolder = (ViewHolder)convertView.getTag();
        }

        final MenuModel model = (MenuModel)getItem(position);

        viewHolder.rootLayout.setEnabled(null != model.getIntentClass());
        viewHolder.titleLabel.setText(model.getTitle());
        viewHolder.rootLayout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                mListener.onClickMenu(model);
            }
        });

//        if(!model.isAnimate()) {
//            Animation animation = AnimationUtils.loadAnimation(this.context, R.anim.fade_in);
////            animation.setStartOffset(convertPositionOffset(position));
//            animation.setDuration(200);
//            convertView.startAnimation(animation);
//            model.setAnimate(true);
//        }

        return convertView;
    }

    private int convertPositionOffset(int position) {
        return position * 30;
    }

    public static class ViewHolder {
        public TextView titleLabel;
        public View rootLayout;
    }

    public void setOnClickCellListener(OnClickCell listener) {
        mListener = listener;
    }

    public interface OnClickCell {
        void onClickMenu(MenuModel model);
    }
}
