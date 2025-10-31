package com.pda.mes.activity.setting;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.content.res.Configuration;
import android.content.res.Resources;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import com.pda.mes.App;
import com.pda.mes.R;
import com.pda.mes.activity.ToolbarActivity;
import com.pda.mes.dialog.InputServerIpDialog;
import com.pda.mes.dialog.ListDialog;
import com.pda.mes.event.LanguageChangeEvent;
import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.SQLQueryRequest;
import com.pda.mes.manager.AppSettingManager;
import com.pda.mes.model.DropDownModel;
import com.pda.mes.utils.LogUtil;
import com.pda.mes.utils.VersionCheckUtil;

import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Map;

import de.greenrobot.event.EventBus;

public class SettingsActivity extends ToolbarActivity {
    public static final String TAG = SettingsActivity.class.getSimpleName();
    private List<DropDownModel> factoryModels = new ArrayList<>();
    private String currentFactoryId;
    private int currentServerType;
    private int currentLocaleType;
    private String currentLoginFactory;
    private String[] serverNames;
    private String[] loginFactoryArray;
    private String serverVersion;

    public void onClickUpdate(View view) {
        try {
            Intent intent = new Intent(this, VersionActivity.class);
            intent.putExtra("serverVersion", serverVersion);
            modalActivity(intent);
        }
        catch (Exception e) {
            LogUtil.writeLog(TAG, "onClickUpdate()", e.getMessage());
        }
    }

    @SuppressLint("StringFormatInvalid")
    public void onClickDone(View view) {

        String timeOut = ((EditText)findViewById(R.id.timeOutInputField)).getText().toString().trim();

        if(null == timeOut || timeOut.isEmpty()) {
            showDialog(String.format(getString(R.string.alert_message_input_timeout_02), AppSettingManager.MIN_TIMEOUT));
            return;
        }

        try {
            int sec = Integer.parseInt(timeOut);

            if(sec < AppSettingManager.MIN_TIMEOUT) {
                showDialog(String.format(getString(R.string.alert_message_input_timeout_02), AppSettingManager.MIN_TIMEOUT));
                return;
            }

            AppSettingManager.setTimeOut(this, sec);
        } catch(Exception e) {
            showDialog(getString(R.string.alert_message_input_timeout_01));
            return;
        }

        EventBus.getDefault().post(new LanguageChangeEvent());

        AppSettingManager.setServerType(this, currentServerType);
        AppSettingManager.setLanguageType(this, currentLocaleType);
        AppSettingManager.setFactoryId(this, currentFactoryId);
        AppSettingManager.setLoginFactory(this, currentLoginFactory);

        modalFinish();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_settings, ToolbarActivity.TOOLBAR_TYPE_MODAL, true);
        setTitleLabel(getString(R.string.screen_name_settings));

        try {
            ((EditText) findViewById(R.id.timeOutInputField)).setText(String.valueOf(AppSettingManager.getTimeOut(this)));
            serverNames = getResources().getStringArray(App.getInstance().isDebugMode() ? R.array.debug_server : R.array.server);
            loginFactoryArray = getResources().getStringArray(R.array.login_factory);
            findViewById(R.id.versionLayout).setVisibility(View.VISIBLE);
            findViewById(R.id.updateLine).setVisibility(View.VISIBLE);

            if (getIntent().hasExtra("type"))
                currentLocaleType = getIntent().getIntExtra("type", AppSettingManager.TYPE_LANGUAGE_KR);
            else
                currentLocaleType = AppSettingManager.getLanguageType(this);

            if (getIntent().hasExtra("server"))
                currentServerType = getIntent().getIntExtra("server", AppSettingManager.TYPE_SERVER_IJ_TEST);
            else
                currentServerType = AppSettingManager.getServerType(this);

            if (getIntent().hasExtra("loginFactory"))
                currentLoginFactory = getIntent().getStringExtra("loginFactory");
            else
                currentLoginFactory = AppSettingManager.getLoginFactory(this);

            setLanguageName(currentLocaleType);
            setServerName(currentServerType);

            findViewById(R.id.settingLanguageLayout).setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    showLanguageDialog();
                }
            });

            findViewById(R.id.settingServerLayout).setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    showServerDialog();
                }
            });

            requestVersionCheck();
        }
        catch (Exception e) {
            LogUtil.writeLog(TAG, "onCreate()", e.getMessage());
        }
    }

    private void showServerDialog() {
        try {
            int selectedIndex;

            if (currentServerType == AppSettingManager.TYPE_SERVER_IJ)
                selectedIndex = 0;
            else if (currentServerType == AppSettingManager.TYPE_SERVER_IJ_TEST)
                selectedIndex = 1;
            else if (currentServerType == AppSettingManager.TYPE_SERVER_TEST)
                selectedIndex = 2;
            else
                selectedIndex = 0;

            ListDialog dialog = new ListDialog(this);
            dialog.setData(serverNames, selectedIndex);
            dialog.setOnSelectItemListener(new ListDialog.OnSelectItemListener() {
                @Override
                public void onClickItem(DropDownModel model, int index) {

                    switch (index) {
                        case 0:
                            currentServerType = AppSettingManager.TYPE_SERVER_IJ;
                            break;
                        case 1:
                            currentServerType = AppSettingManager.TYPE_SERVER_IJ_TEST;
                            break;
                        case 2:
                            currentServerType = AppSettingManager.TYPE_SERVER_TEST;
                            break;
                        default:
                            final String defaultIP = "172.110.0.";

                            InputServerIpDialog inputServerIpDialog = new InputServerIpDialog(SettingsActivity.this);
                            inputServerIpDialog.setDialog("Server IP", "IP를 입력하세요", defaultIP);
                            inputServerIpDialog.setOnInputMessageListener(new InputServerIpDialog.OnInputMessageListener() {
                                @Override
                                public void onClickDone(String value) {
                                    if (null == value || value.length() <= defaultIP.length())
                                        return;

                                    AppSettingManager.setInputIP(SettingsActivity.this, value + ":10101");

                                    if (!AppSettingManager.getInputIP(SettingsActivity.this).contains(":10101"))
                                        return;

                                    currentServerType = AppSettingManager.TYPE_SERVER_IJ_TEST;
                                    setServerName(currentServerType);
                                }
                            });
                            inputServerIpDialog.show();
                            return;
                    }
                    AppSettingManager.setInputIP(SettingsActivity.this, "");
                    setServerName(currentServerType);
                }
            });
            dialog.show();
        }
        catch (Exception e) {
            LogUtil.writeLog(TAG, "showServerDialog()", e.getMessage());
        }
    }

    private void showLanguageDialog() {
        try {
            String[] language = new String[]{
                    getString(R.string.languageName02)
                    , getString(R.string.languageName03)
                    , getString(R.string.languageName01) // TODO : 추후에 베트남어 지원되면 이걸 풀면됨
            };

            int selectedIndex;

            if (currentLocaleType == AppSettingManager.TYPE_LANGUAGE_KR)
                selectedIndex = 0;
            else if (currentLocaleType == AppSettingManager.TYPE_LANGUAGE_US)
                selectedIndex = 1;
            else
                selectedIndex = 2;

            ListDialog dialog = new ListDialog(this);
            dialog.setData(language, selectedIndex);
            dialog.setOnSelectItemListener(new ListDialog.OnSelectItemListener() {
                @Override
                public void onClickItem(DropDownModel model, int index) {
                    switch (index) {
                        default:
                        case 0:
                            currentLocaleType = AppSettingManager.TYPE_LANGUAGE_KR;
                            break;
                        case 1:
                            currentLocaleType = AppSettingManager.TYPE_LANGUAGE_US;
                            break;
                        case 2:
                            currentLocaleType = AppSettingManager.TYPE_LANGUAGE_VI;
                            break;
                    }
                    setLanguageName(currentLocaleType);

                    String localeName;

                    switch (currentLocaleType) {
                        case AppSettingManager.TYPE_LANGUAGE_VI:
                            localeName = "vi";
                            break;
                        case AppSettingManager.TYPE_LANGUAGE_US:
                            localeName = "en";
                            break;
                        default:
                        case AppSettingManager.TYPE_LANGUAGE_KR:
                            localeName = "ko";
                            break;
                    }
                    setLocale(localeName, currentLocaleType, currentServerType, currentFactoryId, currentLoginFactory);
                }
            });
            dialog.show();
        }
        catch (Exception e) {
            LogUtil.writeLog(TAG, "showLanguageDialog()", e.getMessage());
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
    }

    private void setLocale(String lang, int langType, int serverType, String factoryId, String loginFactory) {
        try {
            Locale locale = new Locale(lang);
            Resources res = getResources();
            DisplayMetrics dm = res.getDisplayMetrics();
            Configuration conf = res.getConfiguration();
            conf.locale = locale;
            res.updateConfiguration(conf, dm);
            getIntent().setClass(this, SettingsActivity.class);
            getIntent().putExtra("type", langType);
            getIntent().putExtra("server", serverType);
            getIntent().putExtra("factoryId", factoryId);
            getIntent().putExtra("loginFactory", loginFactory);
            startActivity(getIntent());
            overridePendingTransition(0, 0);
            super.finish();
            overridePendingTransition(0, 0);
        }
        catch (Exception e) {
            LogUtil.writeLog(TAG, "setLocale()", e.getMessage());
        }
    }

    private void setServerName(int type) {
        try {
            String serverName;

            if (type == AppSettingManager.TYPE_SERVER_IJ)
                serverName = serverNames[0];
            else if (type == AppSettingManager.TYPE_SERVER_IJ_TEST)
                serverName = serverNames[1];
            else if (type == AppSettingManager.TYPE_SERVER_TEST)
                serverName = serverNames[2];
            else
                serverName = AppSettingManager.getInputIP(this);

            ((TextView) findViewById(R.id.settingServerLabel)).setText(serverName);
        }
        catch (Exception e) {
            LogUtil.writeLog(TAG, "setServerName()", e.getMessage());
        }
    }

    private void setLanguageName(int type) {
        try {
            String languageName;

            if (type == AppSettingManager.TYPE_LANGUAGE_VI)
                languageName = getString(R.string.languageName01);
            else if (type == AppSettingManager.TYPE_LANGUAGE_KR)
                languageName = getString(R.string.languageName02);
            else if (type == AppSettingManager.TYPE_LANGUAGE_US)
                languageName = getString(R.string.languageName03);
            else
                languageName = getString(R.string.languageName02);

            ((TextView) findViewById(R.id.settingLanguageLabel)).setText(languageName);
        }
        catch (Exception e) {
            LogUtil.writeLog(TAG, "setLanguageName()", e.getMessage());
        }
    }

    private void setFactoryName(String id) {
        try {
            int index = 0;

            for (int i = 0; i < factoryModels.size(); i++) {
                DropDownModel model = factoryModels.get(i);

                if (model.getId().equals(id)) {
                    index = i;
                    break;
                }
            }
        }
        catch (Exception e) {
            LogUtil.writeLog(TAG, "setFactoryName()", e.getMessage());
        }
    }

    private void setParseData(List<Map<String, String>> rows) {
        try {
            for (Map<String, String> row : rows) {
                DropDownModel model = new DropDownModel();

                model.setId(row.get("KEY_1"));
                model.setName(row.get("DATA_1"));

                factoryModels.add(model);
            }

            if (null == factoryModels || factoryModels.isEmpty())
                return;

            if (AppSettingManager.getFactoryId(this).isEmpty())
                AppSettingManager.setFactoryId(this, factoryModels.get(0).getId());

            if (getIntent().hasExtra("factoryId"))
                currentFactoryId = getIntent().getStringExtra("factoryId");
            else
                currentFactoryId = AppSettingManager.getFactoryId(this);

            setFactoryName(currentFactoryId);
        }
        catch (Exception e) {
            LogUtil.writeLog(TAG, "setParseData()", e.getMessage());
        }
    }

    protected void requestVersionCheck() {
        try {
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

                    Map<String, Object> resultMap = (Map<String, Object>) result;

                    List<Map<String, String>> rows = (List<Map<String, String>>) resultMap.get("ROWS");

                    serverVersion = VersionCheckUtil.splitServerVersion(rows.get(0).get("SERVER_VERSION"));

                    if (VersionCheckUtil.checkVersion(VersionCheckUtil.getAppVersion(SettingsActivity.this), serverVersion))
                        findViewById(R.id.newIcon).setVisibility(View.VISIBLE);
                    else
                        findViewById(R.id.newIcon).setVisibility(View.GONE);
                }

                @Override
                public void onFailure(Exception exception) {
                    showDialog(exception.getMessage());
                    LogUtil.writeLog(TAG, "requestVersionCheck() : onFailure()", exception.getMessage());
                }
            });
        }
        catch (Exception e) {
            LogUtil.writeLog(TAG, "requestVersionCheck()", e.getMessage());
        }
    }
}
