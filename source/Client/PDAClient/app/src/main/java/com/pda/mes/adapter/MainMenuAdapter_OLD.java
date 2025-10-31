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

public class MainMenuAdapter_OLD extends BaseAdapter {

    private List<MenuModel> mModels = new ArrayList<>();

    private OnClickCell mListener;

    private LayoutInflater mLayoutInflater;

    private Context context;

    public MainMenuAdapter_OLD(Context context) {
        this.context = context;
        this.mLayoutInflater = LayoutInflater.from(context);
    }

    public void setModels(List<MenuModel> models) {
        mModels = models;
    }

    @Override
    public int getCount() {
        return ((mModels.size() / 2) + (mModels.size() % 2 > 0 ? 1 : 0));
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
            convertView = mLayoutInflater.inflate(R.layout.cell_grid_menu, null);

            viewHolder.mLeftView = convertView.findViewById(R.id.menuLeft);
            viewHolder.mRightView = convertView.findViewById(R.id.menuRight);
            viewHolder.mTitleLeft = convertView.findViewById(R.id.menuLeftLabel);
            viewHolder.mTitleRight = convertView.findViewById(R.id.menuRightLabel);

            convertView.setTag(viewHolder);
        } else {
            viewHolder = (ViewHolder)convertView.getTag();
        }

        // Left Item
        final MenuModel leftModel = (MenuModel)getItem(2 * position);

        viewHolder.mLeftView.setEnabled(null != leftModel.getIntentClass());
        viewHolder.mTitleLeft.setText(leftModel.getTitle());
        viewHolder.mLeftView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                mListener.onClickMenu(leftModel);
            }
        });
        // Right Item
        try {
            final MenuModel rightModel = (MenuModel)getItem((2 * position) + 1);

            viewHolder.mRightView.setEnabled(null != rightModel.getIntentClass());
            viewHolder.mTitleRight.setText(rightModel.getTitle());
            viewHolder.mRightView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    mListener.onClickMenu(rightModel);
                }
            });

            viewHolder.mRightView.setVisibility(View.VISIBLE);
        } catch (Exception e) {
            // Right Empty
            viewHolder.mRightView.setVisibility(View.INVISIBLE);
            viewHolder.mRightView.setOnClickListener(null);
        }

        if(!leftModel.isAnimate()) {
            Animation animation = AnimationUtils.loadAnimation(this.context, R.anim.fade_in);
            animation.setStartOffset(convertPositionOffset(position));
            animation.setDuration(300);
            convertView.startAnimation(animation);
            leftModel.setAnimate(true);
        }

        return convertView;
    }

    private int convertPositionOffset(int position) {
        return position * 80;
    }

    public static class ViewHolder {
        public TextView mTitleLeft;
        public TextView mTitleRight;
        public View mLeftView;
        public View mRightView;
    }

    public void setOnClickCellListener(OnClickCell listener) {
        mListener = listener;
    }

    public interface OnClickCell {
        void onClickMenu(MenuModel model);
    }
}
