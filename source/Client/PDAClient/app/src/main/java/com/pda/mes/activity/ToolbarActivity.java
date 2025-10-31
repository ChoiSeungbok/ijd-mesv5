package com.pda.mes.activity;

import android.content.Intent;
import android.content.IntentFilter;
import android.media.AudioManager;
import android.media.SoundPool;
import android.os.Vibrator;
import android.support.v7.widget.SwitchCompat;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CompoundButton;
import android.widget.FrameLayout;
import android.widget.TextView;

import com.kyleduo.switchbutton.SwitchButton;
import com.pda.mes.App;
import com.pda.mes.R;
import com.pda.mes.activity.setting.VersionActivity;
import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.SQLQueryRequest;
import com.pda.mes.h101.request.sec.SecUpdateFavorites;
import com.pda.mes.manager.SessionManager;
import com.pda.mes.utils.LogUtil;
import com.pda.mes.utils.LogoutTimeCheckUtil;
import com.pda.mes.utils.VersionCheckUtil;

import java.util.List;
import java.util.Map;

import device.common.DecodeResult;
import device.common.ScanConst;
import device.sdk.ScanManager;

/**
 * Created by sjs on 2020. 09. 24
 */
public class ToolbarActivity extends BaseActivity {

    public static final String EXTRA_NAME_EN_TITLE = "EN_TITLE";

    public static final String EXTRA_NAME_TITLE = "TITLE";

    public static final String EXTRA_NAME_SCREEN_ID = "SCREEN_ID";

    public static final String EXTRA_NAME_MENU_LIST = "MENU_LIST";

    public static final String EXTRA_NAME_UER_GROUP = "USE_GROUP";

    public static final String EXTRA_NAME_BOOK_MARK_FLAG = "BOOK_MARK_FLAG";

    public static final int TOOLBAR_TYPE_MAIN = 0;

    public static final int TOOLBAR_TYPE_PUSH = 1;

    public static final int TOOLBAR_TYPE_MODAL = 2;

    public static final int TOOLBAR_TYPE_TITLE = 3;

    public int currentType;

    private SoundPool soundPool;

    private int soundID;

    public static ScanManager mScanner;
    public static DecodeResult mDecodeResult;
    public static IntentFilter filter;
    // private static ScanResultReceiver mScanResultReceiver = null;

    //for BookMark
    private static SwitchButton mBookMark;
    private String userId;
    private String menuId;
    private String menuName;
    private String bookMarkFlag;

    @Override
    public void onBackPressed() {
        LogUtil.writeLog("ToolbarActivity()", "onBackPressed()", "BackPressed");

        if(getIntent().hasExtra(EXTRA_NAME_SCREEN_ID)) {
            requestActivityHistory(getIntent().getStringExtra(EXTRA_NAME_SCREEN_ID), getIntent().getStringExtra(EXTRA_NAME_EN_TITLE), false);
        }

        switch(currentType) {
            case TOOLBAR_TYPE_MAIN:
                fadeFinish();
                break;
            case TOOLBAR_TYPE_MODAL:
                modalFinish();
                break;
            default:
            case TOOLBAR_TYPE_TITLE:
            case TOOLBAR_TYPE_PUSH:
                pushFinish();
                break;
        }
    }

    public void onClickBack(View view) {
        LogUtil.writeLog("ToolbarActivity()", "onClickBack()", "onClickBack");

        if(currentType == TOOLBAR_TYPE_PUSH)
            pushFinish();
        else
            onBackPressed();
    }

    public void setContentView(int layoutResID, int toolbarType) {
        setContentView(layoutResID, toolbarType, false);
    }

    public void setContentView(int layoutResID, int toolbarType, boolean nonCheckVersion) {

        currentType = toolbarType;

        switch(toolbarType) {
            case TOOLBAR_TYPE_MAIN:
                super.setContentView(R.layout.view_toolbar_main);
                break;
            case TOOLBAR_TYPE_MODAL:
                super.setContentView(R.layout.view_toolbar_modal);
                break;
            default:
            case TOOLBAR_TYPE_TITLE:
            case TOOLBAR_TYPE_PUSH:
                menuId = getIntent().getStringExtra(EXTRA_NAME_SCREEN_ID);
                menuName = getIntent().getStringExtra(EXTRA_NAME_TITLE);
                userId = SessionManager.getUserId(this);
                bookMarkFlag = getIntent().getStringExtra(EXTRA_NAME_BOOK_MARK_FLAG);
                super.setContentView(R.layout.view_toolbar_push);
                break;
        }

        FrameLayout mLayoutContent = findViewById(R.id.container);
        getLayoutInflater().inflate(layoutResID, mLayoutContent);

        if(toolbarType == TOOLBAR_TYPE_MAIN) {
            View menuView = View.inflate(this, R.layout.view_slide_menu, null);
            ((ViewGroup)findViewById(R.id.drawer)).addView(menuView);
        }

        if(getIntent().hasExtra(EXTRA_NAME_TITLE)) {
            setTitleLabel(getIntent().getStringExtra(EXTRA_NAME_TITLE));
            setBookMark();
        }

        if(!nonCheckVersion && !App.getInstance().isDebugMode()) {
            requestVersionCheck();
        }

        if(getIntent().hasExtra(EXTRA_NAME_SCREEN_ID)) {
            requestActivityHistory(getIntent().getStringExtra(EXTRA_NAME_SCREEN_ID), getIntent().getStringExtra(EXTRA_NAME_EN_TITLE), true);
        }
    }

    public void setTitleLabel(String title) {
        ((TextView)findViewById(R.id.titleLabel)).setText(title);
    }

    protected void requestVersionCheck() {
        String requestQuery
                = "SELECT DATA_2 SERVER_VERSION"
                + " FROM MGCMTBLDAT"
                + " WHERE 1 = 1"
                + " AND FACTORY  = 'SYSTEM'\n"
                + " AND TABLE_NAME  = 'UPGRADE_OPTION'\n"
                + " AND KEY_1 = \'" + H101Const.PROGRAM_ID + "\'";

        SQLQueryRequest request = new SQLQueryRequest(this, requestQuery);

        request.request(new Request.RequestHandler() {

            @Override
            public void onResult(Object result) {

                Map<String, Object> resultMap = (Map<String, Object>)result;

                List<Map<String, String>> rows = (List<Map<String, String>>) resultMap.get("ROWS");

                final String serverVersion = VersionCheckUtil.splitServerVersion(rows.get(0).get("SERVER_VERSION"));

                if(VersionCheckUtil.checkVersion(getAppVersion(), serverVersion)){
                    // 업데이트 필요
                    showDialog(getString(R.string.alert_message_update), new Runnable() {
                        @Override
                        public void run() {
                            Intent intent = new Intent(ToolbarActivity.this, VersionActivity.class);
                            intent.putExtra("serverVersion", serverVersion);
                            intent.putExtra("forceUpdate", "");
                            modalActivity(intent);
                            findViewById(R.id.titleLabel).postDelayed(new Runnable() {
                                @Override
                                public void run() {
                                    pushFinish();
                                }
                            }, 500);
                        }
                    });
                }
            }

            @Override
            public void onFailure(Exception exception) {
            }
        });
    }

    @Override
    protected void onResume() {
        super.onResume();
        resetLogoutTimer(); // 화면을 켜면 자동으로 로그아웃 체크 타이머가 동작

        mScanner = new ScanManager();
        mDecodeResult = new DecodeResult();
        // mScanResultReceiver = new ScanResultReceiver();
        mScanner.aDecodeSetResultType(ScanConst.ResultType.DCD_RESULT_USERMSG);

        // IntentFilter filter = new IntentFilter();
        filter = new IntentFilter();
        filter.addAction(ScanConst.INTENT_USERMSG);
        filter.addAction(ScanConst.INTENT_EVENT);
        // this.registerReceiver(mScanResultReceiver, filter);

        // 각각의 재생하고자하는 음악을 미리 준비한다. 음악 파일 개수, 스트림 타입 , 음질
        soundPool = new SoundPool(1, AudioManager.STREAM_MUSIC, 0);
        soundID = soundPool.load(this, R.raw.beep, 1);
    }

    @Override
    protected void onPause() {
        super.onPause();
        unregistBarcode();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        unregistBarcode();
    }

    /**
     * 화면 정지 또는 종료시 바코트 컨트롤러 등록 삭제
     * 화면 재개시 onResume() 에서 등록 처리
     */
    private void unregistBarcode() {

    }

    public void resetLogoutTimer() {
        LogoutTimeCheckUtil.getInstance().resetLogoutCheckTime(this);
    }

    public void startAlarm() {
        // 진동을 일으킨다.
        final Vibrator vibrator = (Vibrator)getSystemService(this.VIBRATOR_SERVICE); // 시스템에서 진동 서비스를 받아와야 함
        long[] pattern = {0,500,300,500,300,500}; // 0초 대기하고 0.5초 진동 0.3초 대기하고 0.5초 진동 0.3초 대기 0.5초 진동 (홀수 인덱스 : 대기, 짝수 인덱스 진동)
        vibrator.vibrate(pattern, -1); // 진동 시작 repeat -1 이면 진동을 반복하지 않음

        AudioManager audioManager;
        audioManager = (AudioManager)getSystemService(AUDIO_SERVICE);
        audioManager.playSoundEffect(AudioManager.FX_KEYPRESS_STANDARD);

        // 사운드 재생
        if(!SessionManager.getUserName(this).equals("Choi kangho"))
            soundPool.play(soundID, 1, 1,0, 3, 1.0f);
    }

//    public static class ScanResultReceiver extends BroadcastReceiver {
//        @Override
//        public void onReceive(Context context, Intent intent) {
//            if (mScanner != null) {
//                try {
//                    if (ScanConst.INTENT_USERMSG.equals(intent.getAction())) {
//                        mScanner.aDecodeGetResult(mDecodeResult.recycle());
//                        String barcode = mDecodeResult.toString();
//                    }
//                }
//                catch (Exception e) {
//                    e.printStackTrace();
//                }
//            }
//        }
//    }

    private void setBookMark() {
        mBookMark = (SwitchButton)findViewById(R.id.bookMarkBtn);
        if (bookMarkFlag.equals("1")) {
            mBookMark.setChecked(true);
        } else {
            mBookMark.setChecked(false);
        }
        mBookMark.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                SecUpdateFavorites request = new SecUpdateFavorites(ToolbarActivity.this);
                request.addParam("FUNC_NAME", "S", menuId);
                request.addParam("USER_ID", "S", userId);
                request.addParam("USER_FUNC_DESC", "S", menuName);
                request.addParam("SEQ_NUM", "I4", "1");
                String workCode = "";
                if (isChecked) {
                    workCode = "I";

                } else {
                    workCode = "D";
                }
                request.addParam("PROCSTEP", "C", workCode);
                final String finalWorkCode = workCode;
                request.request(new Request.RequestHandler() {
                    @Override
                    public void onStart() {
                        super.onStart();
                    }

                    @Override
                    public void onResult(Object result) throws InterruptedException {
                        if (finalWorkCode.equals("I")) {
                            showToast(getString(R.string.book_mark_add));
                            Log.e("즐겨찾기", "즐겨찾기 등록. 메뉴 : " + menuId + ", 유저 : " + userId);
                        } else {
                            showToast(getString(R.string.book_mark_delete));
                            Log.e("즐겨찾기", "즐겨찾기 삭제. 메뉴 : " + menuId + ", 유저 : " + userId);
                        }
                    }

                    @Override
                    public void onFailure(Exception exception) {
                        super.onFailure(exception);
                    }
                });
            }
        });
    }

}
