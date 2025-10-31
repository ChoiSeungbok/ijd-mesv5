package com.pda.mes.activity.intro;

import android.content.Intent;
import android.content.res.Configuration;
import android.content.res.Resources;
import android.os.Bundle;
import android.os.Handler;
import android.text.InputFilter;
import android.text.Spanned;
import android.util.DisplayMetrics;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.EditText;
import android.widget.TextView;

import com.pda.mes.R;
import com.pda.mes.activity.BaseActivity;
import com.pda.mes.activity.MainActivity;
import com.pda.mes.activity.setting.SettingsActivity;
import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.SQLQueryRequest;
import com.pda.mes.manager.AppSettingManager;
import com.pda.mes.manager.SessionManager;
import com.pda.mes.utils.BackPressCloseHandler;

import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.regex.Pattern;

import static com.pda.mes.manager.AppSettingManager.DEFAULT_FACTORY;

/**
 * Created by sjs on 2020. 09. 24
 */

public class LoginActivity extends BaseActivity {

    private static final int REQUEST_CODE_SETTINGS = 0x99;

    private boolean isApiRequesting = false;

    private BackPressCloseHandler backPressCloseHandler;

    protected InputFilter filterAlpha = new InputFilter() {
        public CharSequence filter(CharSequence source, int start, int end,
                                   Spanned dest, int dstart, int dend) {

            Pattern ps = Pattern.compile("^[a-zA-Z0-9]+$");
            if(!ps.matcher(source).matches()) {
                return "";
            }
            return null;
        }
    };

    @Override
    public void onBackPressed() {
//        if(((DrawerLayout)findViewById(R.id.drawerLayout)).isDrawerOpen(GravityCompat.START)) {
//            ((DrawerLayout)findViewById(R.id.drawerLayout)).closeDrawer(GravityCompat.START);
//            return;
//        }
        backPressCloseHandler.onBackPressed();
    }


    @Override
    public void finish() {
        fadeFinish();
    }

    public void onClickUpdateCancel(View view) {
        animateUpdateLayout(false);
    }

    public void onClickUpdate(View view) {
    }

    public void onClickLogin(View view) {

        if(isApiRequesting) {
            return;
        }

        isApiRequesting = true;
        String inputIdText = ((EditText)findViewById(R.id.inputIdField)).getText().toString().trim();
        
        String inputPasswordText = ((EditText)findViewById(R.id.inputPasswordField)).getText().toString().trim();

        if(null == inputIdText || 0 == inputIdText.length()) {
            showToast(getString(R.string.alert_message_type_login_01));
            isApiRequesting = false;
            return;
        }

        hideKeyboard(findViewById(R.id.inputIdField));
        requestLogin(inputIdText, inputPasswordText);
    }

    public void onClickSettings(View view) {
        Intent intent = new Intent(LoginActivity.this, SettingsActivity.class);
        intent.putExtra("enterLogin", "");
        animActivityForResult(intent, REQUEST_CODE_SETTINGS, R.anim.modal_animation, R.anim.scale_down);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {

        if(requestCode == REQUEST_CODE_SETTINGS) {
            new Handler().postDelayed(new Runnable() {
                @Override
                public void run() {
                    refreshSettingData();
                }
            }, 500);
        }
        super.onActivityResult(requestCode, resultCode, data);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        setSettingData();

        ((TextView)findViewById(R.id.versionLabel)).setText(getAppVersion());
        ((EditText)findViewById(R.id.inputIdField)).setPrivateImeOptions("defaultInputmode=english;");
        ((EditText)findViewById(R.id.inputIdField)).setFilters(new InputFilter[] {filterAlpha});

        backPressCloseHandler = new BackPressCloseHandler(this);

        if(getIntent().getBooleanExtra("LOG_OUT", false))
            showDialog(getString(R.string.alert_message_auto_logout));
    }

    private void animateUpdateLayout(boolean isShowun) {

        if(isShowun && findViewById(R.id.versionLayout).getVisibility() == View.VISIBLE) {
            return;
        }

        if(!isShowun && findViewById(R.id.versionLayout).getVisibility() == View.GONE) {
            return;
        }

        Animation animation = AnimationUtils.loadAnimation(this, isShowun ? R.anim.slide_from_top : R.anim.slide_out_top);

        findViewById(R.id.versionLayout).startAnimation(animation);
        findViewById(R.id.versionLayout).setVisibility(isShowun ? View.VISIBLE : View.GONE);
    }

    private void refreshSettingData() {

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
        Intent refresh = new Intent(this, LoginActivity.class);
        startActivity(refresh);
        overridePendingTransition(0, 0);
        super.finish();
        overridePendingTransition(0, 0);
    }

    private void setSettingData() {

        String langName;

        if(AppSettingManager.getLanguageType(this) == AppSettingManager.TYPE_LANGUAGE_VI)
            langName = getString(R.string.languageName01);
        else if(AppSettingManager.getLanguageType(this) == AppSettingManager.TYPE_LANGUAGE_KR)
            langName = getString(R.string.languageName02);
        else if(AppSettingManager.getLanguageType(this) == AppSettingManager.TYPE_LANGUAGE_US)
            langName = getString(R.string.languageName03);
        else
            langName = getString(R.string.languageName02);


        ((TextView)findViewById(R.id.langLabel)).setText(langName);

        String[] serverNames = getResources().getStringArray(R.array.server);
        int serverType = AppSettingManager.getServerType(this);

        AppSettingManager.setLoginFactory(this, DEFAULT_FACTORY);

        String serverName;

        if(serverType == AppSettingManager.TYPE_SERVER_IJ) {
            serverName = serverNames[0];
        }
        else if(serverType == AppSettingManager.TYPE_SERVER_IJ_TEST) {
            serverName = serverNames[1];
        }
        else if(serverType == AppSettingManager.TYPE_SERVER_TEST) {
            serverName = serverNames[2];
        }
        else {
            serverName = serverNames[0];
        }

        ((TextView)findViewById(R.id.serverLabel)).setText(serverName);
    }

    private void requestLogin(final String userId, final  String userPassword) {

        String requestQuery
                = "SELECT USER_ID, USER_DESC, SEC_GRP_ID, USER_CMF_1"
                + " FROM MSECUSRDEF"
                + " WHERE 1 = 1"
                + " AND FACTORY = \'" + AppSettingManager.getLoginFactory(this) + "\'"
                + " AND USER_ID = \'" + userId + "\'";

        SQLQueryRequest request = new SQLQueryRequest(this, requestQuery);

        request.request(new Request.RequestHandler() {

            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    //2021-01-12.
                    //resultMap.get(필드명)은 빈값을 갖고옴.
                    //resultMap.get("ROWS").get(0).get(필드명)으로 수정함.

                    List<Map<String, String>> rows = (List<Map<String, String>>)resultMap.get("ROWS");
//                    SessionManager.setUserName(LoginActivity.this, (String)resultMap.get(H101Const.KEY_USER_DESC));
//                    SessionManager.setUserGroup(LoginActivity.this, (String)resultMap.get(H101Const.KEY_USER_GROUP_ID));
                    SessionManager.setUserName(LoginActivity.this, (String)rows.get(0).get(H101Const.KEY_USER_DESC));
                    SessionManager.setUserId(LoginActivity.this, userId);
                    SessionManager.setUserGroup(LoginActivity.this, (String)rows.get(0).get(H101Const.KEY_USER_GROUP_ID));
                    SessionManager.setUserPassword(LoginActivity.this, userPassword);
                    SessionManager.setUserAreaId(LoginActivity.this, (String)rows.get(0).get(H101Const.KEY_USER_AREA_ID));
                    String userAreaId = SessionManager.getUserAreaId(LoginActivity.this);
                    String userName = SessionManager.getUserName(LoginActivity.this);
                    String userGroup = SessionManager.getUserGroup(LoginActivity.this);
                    requestLoginHistory(true);

                    fadeActivity(new Intent(LoginActivity.this, MainActivity.class));
                    fadeFinish();
                }
                else
                {
                    showDialog(getString(R.string.alert_message_no_user));
                }
            }

            @Override
            public void onFailure(Exception exception) {
                showDialog(exception.getMessage());
            }

            @Override
            public void onFinish() {
                hideLoadingDialog();
                isApiRequesting = false;
            }
        });
    }
}