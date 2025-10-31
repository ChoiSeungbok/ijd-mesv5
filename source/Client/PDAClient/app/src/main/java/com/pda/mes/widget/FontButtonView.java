package com.pda.mes.widget;

import android.content.Context;
import android.content.res.TypedArray;
import android.graphics.Paint;
import android.graphics.Typeface;
import android.util.AttributeSet;
import android.widget.Button;

import com.pda.mes.R;
import com.pda.mes.manager.TypefaceManager;

/**
 * Created by sjs on 2020. 09. 24
 */
public class FontButtonView extends Button {

    public FontButtonView(Context context, AttributeSet attrs) {
		super(context, attrs);
        init(context, attrs);
	}

	public FontButtonView(Context context, AttributeSet attrs, int defStyle) {
		super(context, attrs, defStyle);
        init(context, attrs);
	}

    private void init(Context context, AttributeSet attrs) {

        setTransformationMethod(null);

        TypedArray typedArray = getContext().obtainStyledAttributes(attrs, R.styleable.FontView);
        for (int i = 0; i < typedArray.getIndexCount(); ++i) {

            int attr = typedArray.getIndex(i);

            if (attr == R.styleable.FontView_custom_font) {
                TypefaceManager typefaceManager = TypefaceManager.getInstance();
                Typeface typeface = typefaceManager.getTypeface(context, typedArray.getString(attr));
                setTypeface(typeface);
                setPaintFlags(getPaintFlags() | Paint.SUBPIXEL_TEXT_FLAG);
            }
        }
        typedArray.recycle();
    }
}
