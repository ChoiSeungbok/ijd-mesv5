package com.pda.mes.utils;

import android.app.Activity;
import android.widget.Toast;

import com.pda.mes.R;

public class BackPressCloseHandler {

    private long backKeyPressedTime = 0;
    private Toast toast;

    private Activity activity;

    public BackPressCloseHandler(Activity context) {
        this.activity = context;
    }

    public void onBackPressed() {
        if(System.currentTimeMillis() > backKeyPressedTime + 2000) {
            backKeyPressedTime = System.currentTimeMillis();
            showGuide();
            return;
        }
        if(System.currentTimeMillis() <= backKeyPressedTime + 2000) {
            // activity.finish();
            //activity.overridePendingTransition(R.anim.fade_in_activity, R.anim.fade_out_activity);

            activity.finishAffinity();
            toast.cancel();
        }
    }

    public void showGuide() {
        toast = Toast.makeText(activity, activity.getString(R.string.exit_message), Toast.LENGTH_SHORT);
        toast.show();
    }
}