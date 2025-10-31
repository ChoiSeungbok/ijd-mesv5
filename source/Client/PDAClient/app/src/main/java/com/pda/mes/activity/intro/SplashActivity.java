package com.pda.mes.activity.intro;

import android.content.Intent;
import android.content.res.Configuration;
import android.content.res.Resources;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;

import com.pda.mes.App;
import com.pda.mes.R;
import com.pda.mes.activity.BaseActivity;
import com.pda.mes.activity.MainActivity;
import com.pda.mes.manager.AppSettingManager;
import com.pda.mes.manager.SessionManager;

import java.util.Locale;

/**
 * Created by sjs on 2020. 09. 24
 */

public class SplashActivity extends BaseActivity {

    public static final String TAG = SplashActivity.class.getSimpleName();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_splash);

        int type = AppSettingManager.getLanguageType(this);

        String localeName;

        switch(type) {
            default:
            case AppSettingManager.TYPE_LANGUAGE_VI:
                localeName = "vi";
                break;
            case AppSettingManager.TYPE_LANGUAGE_KR:
                localeName = "ko";
                break;
            case AppSettingManager.TYPE_LANGUAGE_US:
                localeName = "en";
                break;
        }

        Locale locale = new Locale(localeName);
        Resources res = getResources();
        DisplayMetrics dm = res.getDisplayMetrics();
        Configuration conf = res.getConfiguration();
        conf.locale = locale;
        res.updateConfiguration(conf, dm);

        Animation animation = AnimationUtils.loadAnimation(this, R.anim.fade_in);

        animation.setStartOffset(200);
        animation.setDuration(1500);
        animation.setAnimationListener(new Animation.AnimationListener() {
            @Override
            public void onAnimationStart(Animation animation) {}

            @Override
            public void onAnimationEnd(Animation animation) {

                findViewById(R.id.logoView).postDelayed(new Runnable() {
                    @Override
                    public void run() {

                        Intent intent = new Intent();

                        // 디버깅 모드일경우 자동로그인
                        if(!App.getInstance().isDebugMode()) {
                            SessionManager.clearData(SplashActivity.this);
                            intent.setClass(SplashActivity.this, LoginActivity.class);
                        }
                        else {
                            SessionManager.setUserId(SplashActivity.this, "MESTEST");

                            if(checkLogin()) {
                                intent.setClass(SplashActivity.this, MainActivity.class);
                            } else {
                                intent.setClass(SplashActivity.this, LoginActivity.class);
                            }
                        }

                        fadeActivity(intent);
                        fadeFinish();
                    }
                }, 1000);
            }

            @Override
            public void onAnimationRepeat(Animation animation) {}
        });

        findViewById(R.id.logoView).startAnimation(animation);
        findViewById(R.id.logoView).setVisibility(View.VISIBLE);

        createShortcut();
    }

    private boolean checkLogin() {

        boolean reValue = false;

        if(null != SessionManager.getUserId(this) && !SessionManager.getUserId(this).isEmpty()) {
            reValue = true;
        }

        return reValue;
    }

    private void createShortcut() {
        if(SessionManager.getIsCreatedShortcut(this))
            return;

        Intent shortcutIntent = new Intent(Intent.ACTION_MAIN);
        shortcutIntent.addCategory(Intent.CATEGORY_LAUNCHER);
        shortcutIntent.setClassName(this, getClass().getName());
        shortcutIntent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_RESET_TASK_IF_NEEDED);


        Intent intent = new Intent();
        intent.putExtra(Intent.EXTRA_SHORTCUT_INTENT, shortcutIntent);
        intent.putExtra(Intent.EXTRA_SHORTCUT_NAME, getResources().getString(R.string.app_name));
        intent.putExtra(Intent.EXTRA_SHORTCUT_ICON_RESOURCE, Intent.ShortcutIconResource.fromContext(this, R.mipmap.ic_launcher));

        intent.putExtra("duplicate", false);
        intent.setAction("com.android.launcher.action.INSTALL_SHORTCUT");

        sendBroadcast(intent);

        SessionManager.setIsCreatedShortcut(this, true);
    }
}
