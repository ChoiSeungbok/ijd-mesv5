package com.pda.mes.manager;

import android.content.Context;
import android.content.SharedPreferences;

import com.pda.mes.App;

public class SessionManager {

    private final static String KEY_USER_ID = "KEY_USER_ID";

    private final static String KEY_USER_PASSWORD = "KEY_USER_PASSWORD";

    private final static String KEY_USER_NAME = "KEY_USER_NAME";

    private final static String KEY_SEC_GRP_ID = "KEY_SEC_GRP_ID";

    private final static String KEY_LOG_DATE = "KEY_LOG_DATE";

    private final static String KEY_PROGRAM_LOGIN_TIME = "KEY_PROGRAM_LOGIN_TIME";

    private final static String KEY_TRAN_TIME = "KEY_TRAN_TIME";

    private final static String KEY_ACTIVITY_LOG_DATE = "KEY_ACTIVITY_LOG_DATE";

    private final static String KEY_ACTIVITY_TRAN_TIME = "KEY_ACTIVITY_TRAN_TIME";

    private final static String KEY_IS_CREATED_SHORTCUT = "KEY_IS_CREATED_SHORTCUT";

    private final static String KEY_USER_AREA_ID = "KEY_USER_AREA_ID";

    public static void clearData(Context context) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();
        editor.remove(KEY_USER_ID);
        editor.remove(KEY_USER_NAME);
        editor.remove(KEY_SEC_GRP_ID);
        editor.remove(KEY_LOG_DATE);
        editor.remove(KEY_PROGRAM_LOGIN_TIME);
        editor.remove(KEY_TRAN_TIME);
        editor.remove(KEY_ACTIVITY_LOG_DATE);
        editor.remove(KEY_ACTIVITY_TRAN_TIME);
        editor.remove(KEY_USER_AREA_ID);

        editor.commit();
    }

    public static String getUserId(Context context) {
        return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getString(KEY_USER_ID, "");
    }

    public static void setUserId(Context context, String value) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();
        editor.putString(KEY_USER_ID, value);
        editor.commit();
    }

    public static String getUserName(Context context) {
        return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getString(KEY_USER_NAME, "");
    }

    public static void setUserName(Context context, String value) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();
        editor.putString(KEY_USER_NAME, value);
        editor.commit();
    }

    public static String getUserGroup(Context context) {
        return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getString(KEY_SEC_GRP_ID, "");
    }

    public static void setUserGroup(Context context, String value) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();
        editor.putString(KEY_SEC_GRP_ID, value);
        editor.commit();
    }

    public static String getLogDate(Context context) {
        return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getString(KEY_LOG_DATE, "");
    }

    public static void setLogDate(Context context, String value) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();
        editor.putString(KEY_LOG_DATE, value);
        editor.commit();
    }

    public static String getProgranLoginTime(Context context) {
        return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getString(KEY_PROGRAM_LOGIN_TIME, "");
    }

    public static void setProgranLoginTime(Context context, String value) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();
        editor.putString(KEY_PROGRAM_LOGIN_TIME, value);
        editor.commit();
    }

    public static String getTranTime(Context context) {
        return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getString(KEY_TRAN_TIME, "");
    }

    public static void setTranTime(Context context, String value) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();
        editor.putString(KEY_TRAN_TIME, value);
        editor.commit();
    }

    public static String getActivityLogDate(Context context) {
        return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getString(KEY_ACTIVITY_LOG_DATE, "");
    }

    public static void setActivityLogDate(Context context, String value) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();
        editor.putString(KEY_ACTIVITY_LOG_DATE, value);
        editor.commit();
    }

    public static String getActivityTranTime(Context context) {
        return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getString(KEY_ACTIVITY_TRAN_TIME, "");
    }

    public static void setActivityTranTime(Context context, String value) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();
        editor.putString(KEY_ACTIVITY_TRAN_TIME, value);
        editor.commit();
    }

    public static boolean getIsCreatedShortcut(Context context) {
        return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getBoolean(KEY_IS_CREATED_SHORTCUT, false);
    }

    public static void setIsCreatedShortcut(Context context, boolean isCreated) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();
        editor.putBoolean(KEY_IS_CREATED_SHORTCUT, isCreated);
        editor.commit();
    }

    public static String getUserPassword(Context context) {
        return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getString(KEY_USER_PASSWORD, "1");
    }

    public static void setUserPassword(Context context, String userPassword) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();
        editor.putString(KEY_USER_PASSWORD, userPassword);
        editor.commit();
    }

    //2021-01-12 출하등록시 사업부에 디폴드 값으로 유저의 사업부가 세팅되도록 요청받음. by 미라콤 김우경 프로님.
    public static String getUserAreaId(Context context) {
        return context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).getString(KEY_USER_AREA_ID, "");
    }

    public static void setUserAreaId(Context context, String value) {
        SharedPreferences.Editor editor = context.getSharedPreferences(App.PREFERENCE_NAME, Context.MODE_PRIVATE).edit();
        editor.putString(KEY_USER_AREA_ID, value);
        editor.commit();
    }
}
