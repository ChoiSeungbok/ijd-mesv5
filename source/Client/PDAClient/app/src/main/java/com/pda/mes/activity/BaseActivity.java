package com.pda.mes.activity;

import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.Toast;

import com.pda.mes.R;
import com.pda.mes.dialog.ConfirmDialog;
import com.pda.mes.dialog.LoadingDialog;
import com.pda.mes.dialog.MessageDialog;
import com.pda.mes.dialog.PickerYearMonthDialog;
import com.pda.mes.h101.Request;
import com.pda.mes.manager.AppLogManager;
import com.pda.mes.manager.SessionManager;

import java.util.Map;

/**
 * Created by sjs on 2020. 09. 24
 */
public class BaseActivity extends AppCompatActivity {

    private LoadingDialog loadingDialog;

    private ConfirmDialog confirmDialog;

    private MessageDialog messageDialog;

    /**
     * Activity 화면 전환
     *
     * @param intent
     */
    public void modalActivity(Intent intent) {
        startActivity(intent);
        overridePendingTransition(R.anim.modal_animation, R.anim.scale_down);
    }

    /**
     * Activity 화면 전환
     *
     * @param intent
     */
    public void pushActivity(Intent intent) {
        startActivity(intent);
        overridePendingTransition(R.anim.slide_from_right, R.anim.scale_down);
    }

    /**
     * Activity 화면 전환
     *
     * @param intent
     */
    public void fadeActivity(Intent intent) {
        startActivity(intent);
        overridePendingTransition(R.anim.fade_in_activity, R.anim.fade_out_activity);
    }


    /**
     * Activity finish
     */
    public void modalFinish() {
        super.finish();
        overridePendingTransition(R.anim.scale_up, R.anim.modal_exit_animation);
    }

    /**
     * Activity finish
     */
    public void pushFinish() {
        super.finish();
        overridePendingTransition(R.anim.scale_up, R.anim.slide_out_to_right);
    }

    /**
     * Activity finish
     */
    public void fadeFinish() {
        super.finish();
        overridePendingTransition(R.anim.fade_in_activity, R.anim.fade_out_activity);
    }

    /**
     * Activity finish isAnimate
     */
    public void finish(boolean isAnimate) {
        super.finish();
        if(isAnimate) {
            overridePendingTransition(R.anim.scale_up, R.anim.slide_out_to_right);
        }
    }

    /**
     * Activity 화면 전환
     *
     * @param intent
     */
    public void pushActivityForResult(Intent intent, int requestCode) {
        startActivityForResult(intent, requestCode);
        overridePendingTransition(R.anim.slide_from_right, R.anim.scale_down);
    }

    /**
     * Activity 화면 전환
     *
     * @param intent
     */
    public void animActivityForResult(Intent intent, int requestCode, int enterAnim, int exitAnim) {
        startActivityForResult(intent, requestCode);
        overridePendingTransition(enterAnim, exitAnim);
    }

    /**
     * 로딩 인디케이터 on / off <br>
     */
    public void showLoadingDialog() {

        if(null == loadingDialog || BaseActivity.this.isFinishing()) {
            return;
        }

        if(!loadingDialog.isShowing()) {
            loadingDialog.show();
        }
    }

    public void hideLoadingDialog() {
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                try {
                    if(null != loadingDialog && loadingDialog.isShowing()) {
                        loadingDialog.dismiss();
                    }
                } catch (IllegalArgumentException e) {
                    e.printStackTrace();
                }
            }
        }, 100);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        loadingDialog = new LoadingDialog(this);
        loadingDialog.setCancelable(false);
    }

    public void showToast(String message) {
        Toast.makeText(this, message, Toast.LENGTH_SHORT).show();
    }

    public void showDialog(String message) {
        showDialog(message, null);
    }

    public void showDialog(String message, Runnable runnable) {

        if(null != messageDialog && messageDialog.isShowing()) {
            messageDialog.dismiss();
        }

        if(message == null) {
            message = "Unknown error. Please contact your administrator";
            return;
        }

        messageDialog = new MessageDialog(this);
        messageDialog.setDialog(message, runnable);
        messageDialog.show();
    }

    public void showConfirmDialog(String message, Runnable runnable) {

        if(null != confirmDialog && confirmDialog.isShowing()) {
            confirmDialog.dismiss();
        }

        confirmDialog = new ConfirmDialog(this);
        confirmDialog.setDialog(message, runnable);
        confirmDialog.show();
    }

    public void showYearMonthPicker(String title, int minYear, int maxYear, int left, int right, PickerYearMonthDialog.OnClickDone listener) {
        PickerYearMonthDialog dialog = new PickerYearMonthDialog(this, title, minYear, maxYear, left, right);
        dialog.setOnClickDoneListener(listener);
        dialog.show();
    }

    /**
     * 소프트 키보드를 보여준다.
     *
     * @param view 소프트 키보드를 보여주고 포커스를 가질 뷰
     */
    public void showKeyboard(final View view) {

        view.post(new Runnable() {
            @Override
            public void run() {
                // 포커스 요청
                view.requestFocus();
                InputMethodManager imm = (InputMethodManager)getSystemService(Context.INPUT_METHOD_SERVICE);
                imm.showSoftInput(view, 0);
            }
        });
    }

    /**
     * 소프트 키보드를 사라지게 한다.
     *
     * @param view 소프트 키보드를 사라지게 할 뷰
     */
    public void hideKeyboard(View view) {

        InputMethodManager imm = (InputMethodManager)getSystemService(Context.INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(view.getWindowToken(), 0);
    }

    protected String getAppVersion() {

        String appVersion;

        try {
            appVersion = getPackageManager().getPackageInfo(getPackageName(), 0).versionName;
        } catch(PackageManager.NameNotFoundException e) {
            AppLogManager.printErrorLog(e.getMessage());
            appVersion = "";
        }

        return appVersion;
    }

    protected void requestLoginHistory(final boolean isLogin) {

        AppLogManager.printErrorLog(isLogin ? "History Login" : "History Logout");

       /* LoginHistoryRequest request = new LoginHistoryRequest(this, isLogin);
        request.request(new Request.RequestHandler() {
            @Override
            public void onResult(Object result) {
                if(isLogin) {
                    Map<String, Object> resultMap = (Map<String, Object>)result;
                    SessionManager.setLogDate(BaseActivity.this, (String)resultMap.get("LOG_DATE"));
                    SessionManager.setProgranLoginTime(BaseActivity.this, (String)resultMap.get("PROGRAM_LOGIN_TIME"));
                    SessionManager.setTranTime(BaseActivity.this, (String)resultMap.get("TRAN_TIME"));
                }
            }
        });*/
    }

    protected void requestActivityHistory(String formId, String formName, final boolean isOpen) {

        AppLogManager.printErrorLog((isOpen ? "* * * * * * * Start Activity = " : "* * * * * * * Finish Activity = ") + formId + " / " + formName);

        /*LoginHistoryRequest request = new LoginHistoryRequest(this, formId, formName, isOpen);
        request.request(new Request.RequestHandler() {
            @Override
            public void onResult(Object result) {
                if(isOpen) {
                    Map<String, Object> resultMap = (Map<String, Object>)result;
                    SessionManager.setActivityLogDate(BaseActivity.this, (String)resultMap.get("LOG_DATE"));
                    SessionManager.setActivityTranTime(BaseActivity.this, (String)resultMap.get("TRAN_TIME"));
                }
            }
        });*/
    }
}
