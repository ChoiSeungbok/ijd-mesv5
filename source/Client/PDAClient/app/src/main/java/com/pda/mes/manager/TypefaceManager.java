package com.pda.mes.manager;

import android.content.Context;
import android.graphics.Typeface;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by sjs on 2020. 09. 24
 */
public class TypefaceManager {

    private final static TypefaceManager sInstance = new TypefaceManager();

    private final Map<String, Typeface> mTypefaceMap;

    private TypefaceManager() {
        mTypefaceMap = new HashMap<>();
    }

    public static TypefaceManager getInstance() {
        return sInstance;
    }

    public Typeface getTypeface(Context context, String typefaceName) {

        Typeface typeface = mTypefaceMap.get(typefaceName);

        if(typeface == null) {
            context = context.getApplicationContext();
            try {
                typeface = Typeface.createFromAsset(context.getAssets(), typefaceName);
                mTypefaceMap.put(typefaceName, typeface);
            } catch(Exception e) {
                typeface = Typeface.DEFAULT;
            }
        }

        return typeface;
    }
}
