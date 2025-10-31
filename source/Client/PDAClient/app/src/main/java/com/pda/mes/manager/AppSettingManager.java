package com.pda.mes.manager;

import android.content.Context;
import android.content.SharedPreferences;

import com.pda.mes.App;

public class AppSettingManager {

    public static final int TYPE_LANGUAGE_VI = 0x01;
    public static final int TYPE_LANGUAGE_KR = 0x02;
    public static final int TYPE_LANGUAGE_US = 0x03;

    public static final int TYPE_SERVER_IJ = 0x21;
    public static final int TYPE_SERVER_IJ_TEST = 0x22;
    public static final int TYPE_SERVER_TEST = 0x23;

    public static final int DEFAULT_TIMEOUT = 30;
    public static final int MIN_TIMEOUT = 30;

    public static final String DEFAULT_FACTORY = "IJDK1";

    private final static String KEY_LANGUAGE = "KEY_LANGUAGE";

    private final static String KEY_SERVER = "KEY_SERVER";

    private final static String KEY_TIMEOUT = "KEY_TIMEOUT";

    private final static String KEY_INPUT_IP = "KEY_INPUT_IP";

    private final static String KEY_FACTORY_ID = "KEY_FACTORY_ID";

    private final static String KEY_LOGIN_FACTORY_ID = "KEY_LOGIN_FACTORY_ID";

    private final static String KEY_WORK_SHIFT = "KEY_WORK_SHIFT";

    private final static String KEY_WORKER = "KEY_WORKER";

    public static void clearData(Context context) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();

        editor.commit();
    }

    public static int getServerType(Context context) {
        return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getInt(KEY_SERVER, TYPE_SERVER_IJ_TEST);
    }

    public static void setServerType(Context context, int value) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();
        editor.putInt(KEY_SERVER, value);
        editor.commit();
    }

    public static int getLanguageType(Context context) {
        return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getInt(KEY_LANGUAGE, TYPE_LANGUAGE_KR);
    }

    public static void setLanguageType(Context context, int value) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();
        editor.putInt(KEY_LANGUAGE, value);
        editor.commit();
    }

    public static int getTimeOut(Context context) {
        return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getInt(KEY_TIMEOUT, DEFAULT_TIMEOUT);
    }

    public static void setTimeOut(Context context, int value) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();
        editor.putInt(KEY_TIMEOUT, value);
        editor.commit();
    }

    public static String getInputIP(Context context) {
        return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getString(KEY_INPUT_IP, "");
    }

    public static void setInputIP(Context context, String value) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();
        editor.putString(KEY_INPUT_IP, value);
        editor.commit();
    }

    // VMW
    public static String getFactoryId(Context context) {
        return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getString(KEY_FACTORY_ID, "");
        //if(VM_FACTORY == getLoginFactory(context))
        //    return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getString(KEY_FACTORY_ID, "VMW");
        //else
        //    return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getString(KEY_FACTORY_ID, "");
    }

    public static void setFactoryId(Context context, String value) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();
        editor.putString(KEY_FACTORY_ID, value);
        editor.commit();
    }

    // VM
    public static String getLoginFactory(Context context) {
        return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getString(KEY_LOGIN_FACTORY_ID, DEFAULT_FACTORY);
    }

    public static void setLoginFactory(Context context, String value) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();
        editor.putString(KEY_LOGIN_FACTORY_ID, value);
        editor.commit();
    }

    public static String getWorkShift(Context context) {
        return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getString(KEY_WORK_SHIFT, "");
    }

    public static void setWorkShift(Context context, String value) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();
        editor.putString(KEY_WORK_SHIFT, value);
        editor.commit();
    }

    public static String getWorker(Context context) {
        return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getString(KEY_WORKER, "");
    }

    public static void setWorker(Context context, String value) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();
        editor.putString(KEY_WORKER, value);
        editor.commit();
    }
}
