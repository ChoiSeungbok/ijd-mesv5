package com.pda.mes.utils;

import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.support.v7.app.AlertDialog;

import com.pda.mes.activity.intro.LoginActivity;
import com.pda.mes.dialog.MessageDialog;
import com.pda.mes.manager.AppLogManager;

public class LogoutTimeCheckUtil {
    private static class SetupHolder { public static final LogoutTimeCheckUtil INSTANCE = new LogoutTimeCheckUtil(); }
    public static LogoutTimeCheckUtil getInstance () { return SetupHolder.INSTANCE; }
    LogoutTimeCheckUtil() { };

    public final int LOGOUT_CHECK_TIME = 120*60*1000; // 60분간 아무 동작이 없으면 로그 아웃을 실행함

    private Thread logoutCheckTimerThread = null;

    public void resetLogoutCheckTime(final Context context) {
        if(logoutCheckTimerThread != null) {
            logoutCheckTimerThread.interrupt();
            logoutCheckTimerThread = null;
        }

        logoutCheckTimerThread = new Thread() {
            public void run() {
                try {
                    Thread.sleep(LOGOUT_CHECK_TIME);

                    Intent intent = new Intent(context, LoginActivity.class);
                    intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_SINGLE_TOP);
                    intent.putExtra("LOG_OUT", true);
                    context.startActivity(intent);
                }
                catch (Exception e) {
                    AppLogManager.printErrorLog(e.getMessage());
                }
            }
        };
        logoutCheckTimerThread.start();
    }
}
