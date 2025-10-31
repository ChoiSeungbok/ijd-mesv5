package com.pda.mes.dialog;

import android.app.Dialog;
import android.content.Context;
import android.content.res.Resources;
import android.view.View;
import android.view.Window;
import android.widget.NumberPicker;
import android.widget.TextView;
import android.widget.Toast;

import com.pda.mes.R;
import com.pda.mes.widget.CustomNumberPicker;

public class PickerYearMonthDialog extends Dialog implements View.OnClickListener {

    private TextView titleLabel;
    private TextView doneButton;

    private CustomNumberPicker leftPicker;
    private CustomNumberPicker rightPicker;

    private String[] valueArrayLeft;
    private String[] valueArrayRight;
    private String title;

    private int leftIndex = 0;
    private int rightIndex = 0;

    private OnClickDone mListener;

    private int minYear;
    private int maxYear;

    public PickerYearMonthDialog(Context context, String title, int minYear, int maxYear, int left, int right) {
        super(context);
        this.minYear = minYear;
        this.maxYear = maxYear;
        this.title = title;
        this.leftIndex = left;
        this.rightIndex = right;
        init();
    }

    private void init() {
        View view = View.inflate(getContext(), R.layout.dialog_picker_twice, null);
        requestWindowFeature(Window.FEATURE_NO_TITLE);

        titleLabel = view.findViewById(R.id.titleLabel);

        doneButton = view.findViewById(R.id.doneButton);

        leftPicker = view.findViewById(R.id.leftPicker);
        rightPicker = view.findViewById(R.id.rightPicker);

        doneButton.setOnClickListener(this);

        leftPicker.setWrapSelectorWheel(false);
        rightPicker.setWrapSelectorWheel(false);

        leftPicker.setDescendantFocusability(NumberPicker.FOCUS_BLOCK_DESCENDANTS);
        rightPicker.setDescendantFocusability(NumberPicker.FOCUS_BLOCK_DESCENDANTS);

        titleLabel.setText(title);

        valueArrayLeft = new String[(maxYear - minYear) + 1];
        valueArrayRight = new String[12];

        for(int i = 0 ; i < (maxYear - minYear) + 1 ; i++) {
            valueArrayLeft[i] = String.valueOf(minYear + i);
        }

        for(int i = 0 ; i < 12 ; i++) {
            valueArrayRight[i] = String.valueOf(i + 1);
        }

        leftPicker.setMaxValue(valueArrayLeft.length - 1);
        leftPicker.setMinValue(0);
        leftPicker.setValue(leftIndex == -1 ? 0 : leftIndex);
        rightPicker.setMaxValue(valueArrayRight.length - 1);
        rightPicker.setMinValue(0);
        rightPicker.setValue(rightIndex == -1 ? 0 : rightIndex);
        leftPicker.setDisplayedValues(valueArrayLeft);
        rightPicker.setDisplayedValues(valueArrayRight);

        java.lang.reflect.Field[] pickerFields = NumberPicker.class.getDeclaredFields();
        for(java.lang.reflect.Field pf : pickerFields) {
            if(pf.getName().equals("mSelectionDivider")) {
                pf.setAccessible(true);
                try {
                    pf.set(leftPicker, getContext().getResources().getDrawable(android.R.color.transparent));
                    pf.set(rightPicker, getContext().getResources().getDrawable(android.R.color.transparent));
                } catch(IllegalArgumentException e) {
                    e.printStackTrace();
                } catch(Resources.NotFoundException e) {
                    e.printStackTrace();
                } catch(IllegalAccessException e) {
                    e.printStackTrace();
                }
                break;
            }
        }

        leftPicker.setOnValueChangedListener(new NumberPicker.OnValueChangeListener() {
            @Override
            public void onValueChange(NumberPicker numberPicker, int prevIndex, int index) {
                leftIndex = index;
            }
        });

        rightPicker.setOnValueChangedListener(new NumberPicker.OnValueChangeListener() {
            @Override
            public void onValueChange(NumberPicker numberPicker, int prevIndex, int index) {
                rightIndex = index;
            }
        });

        setContentView(view);
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.doneButton:
                leftIndex = leftIndex == -1 ? 0 : leftIndex;
                rightIndex = rightIndex == -1 ? 0 : rightIndex;

                mListener.onClickDone(Integer.parseInt(valueArrayLeft[leftIndex]), Integer.parseInt(valueArrayRight[rightIndex]));
                dismiss();
                break;
        }
    }

    public void setOnClickDoneListener(OnClickDone listener) {
        mListener = listener;
    }

    public interface OnClickDone {
        void onClickDone(int left, int right);
    }
}
