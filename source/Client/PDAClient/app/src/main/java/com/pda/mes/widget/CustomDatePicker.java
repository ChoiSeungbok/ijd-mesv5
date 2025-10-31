package com.pda.mes.widget;

import android.content.Context;
import android.util.AttributeSet;
import android.util.TypedValue;
import android.view.View;
import android.widget.EditText;

import com.pda.mes.R;

/**
 * Created by sjs on 2020. 9. 21
 */

public class CustomDatePicker extends android.widget.DatePicker {

    public CustomDatePicker(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    @Override
    public void addView(View child) {
        super.addView(child);
        updateView(child);
    }

    @Override
    public void addView(View child, int index, android.view.ViewGroup.LayoutParams params) {
        super.addView(child, index, params);
        updateView(child);
    }

    @Override
    public void addView(View child, android.view.ViewGroup.LayoutParams params) {
        super.addView(child, params);
        updateView(child);
    }

    private void updateView(View view) {
        if(view instanceof EditText) {
            ((EditText)view).setTextSize(TypedValue.COMPLEX_UNIT_DIP, 19);
            ((EditText)view).setTextColor(getContext().getResources().getColor(R.color.picker_selector));
        }
    }
}