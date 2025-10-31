package com.pda.mes.activity;

import android.content.Intent;
import android.content.pm.PackageManager;
import android.content.res.Configuration;
import android.os.Bundle;
import android.os.Handler;
import android.support.v4.view.GravityCompat;
import android.support.v4.widget.DrawerLayout;
import android.view.View;
import android.widget.ListView;
import android.widget.TextView;

import com.pda.mes.App;
import com.pda.mes.R;
import com.pda.mes.activity.intro.LoginActivity;
import com.pda.mes.activity.setting.SettingsActivity;
import com.pda.mes.adapter.MainMenuGroupAdapter;
import com.pda.mes.event.LanguageChangeEvent;
import com.pda.mes.h101.Request;
import com.pda.mes.h101.request.SQLQueryRequest;
import com.pda.mes.manager.AppLogManager;
import com.pda.mes.manager.AppSettingManager;
import com.pda.mes.manager.SessionManager;
import com.pda.mes.model.MenuModel;
import com.pda.mes.utils.BackPressCloseHandler;

import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Map;

import de.greenrobot.event.EventBus;

import static com.pda.mes.manager.AppSettingManager.DEFAULT_FACTORY;

public class GroupMenuActivity extends ToolbarActivity {

    public static final String TAG = GroupMenuActivity.class.getSimpleName();
    private static final int REQUEST_CODE_SETTINGS = 0x99;

    private BackPressCloseHandler backPressCloseHandler;
    private MainMenuGroupAdapter mainMenuGroupAdapter;
    private List<MenuModel> arrayListMenuGroupModel = new ArrayList<>();
    private ArrayList<String> arrayListMenuList = new ArrayList<>();

    public void onEventMainThread(LanguageChangeEvent event) {

        ((DrawerLayout)findViewById(R.id.drawerLayout)).closeDrawer(GravityCompat.START);

        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                refreshSettingData();
            }
        }, 500);
    }

    public void onClickSettings(View view) {
        AppLogManager.printLog(TAG, "onClickSettings " + view.getId());
        Intent intent = new Intent(this, SettingsActivity.class);
        animActivityForResult(intent, REQUEST_CODE_SETTINGS, R.anim.modal_animation, R.anim.scale_down);
    }

    public void onClickLogout(View view) {
        AppLogManager.printLog(TAG, "onClickSettings " + view.getId());
        showConfirmDialog(getString(R.string.alert_message_type_logout_01), new Runnable() {
            @Override
            public void run() {

                showLoadingDialog();

                ((DrawerLayout)findViewById(R.id.drawerLayout)).addDrawerListener(new DrawerLayout.DrawerListener() {

                    @Override
                    public void onDrawerSlide(View drawerView, float slideOffset) {
                        AppLogManager.printLog(TAG, "Not used onDrawerSlide");
                    }

                    @Override
                    public void onDrawerOpened(View drawerView) {
                        AppLogManager.printLog(TAG, "Not used onDrawerOpened");
                    }

                    @Override
                    public void onDrawerClosed(View drawerView) {

                        requestLoginHistory(false);

                        hideLoadingDialog();

                        SessionManager.clearData(GroupMenuActivity.this);

                        Intent intent = new Intent(GroupMenuActivity.this, LoginActivity.class);
                        intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP | Intent.FLAG_ACTIVITY_SINGLE_TOP);
                        fadeActivity(intent);
                        fadeFinish();
                    }

                    @Override
                    public void onDrawerStateChanged(int newState) {
                        AppLogManager.printLog(TAG, "Not used onDrawerStateChanged");
                    }
                });

                if(((DrawerLayout)findViewById(R.id.drawerLayout)).isDrawerOpen(GravityCompat.START)) {
                    ((DrawerLayout)findViewById(R.id.drawerLayout)).closeDrawer(GravityCompat.START);
                }
            }
        });
    }

    public void onClickMenu(View view) {

        if(((DrawerLayout)findViewById(R.id.drawerLayout)).isDrawerOpen(GravityCompat.START)) {
            ((DrawerLayout)findViewById(R.id.drawerLayout)).closeDrawer(GravityCompat.START);
        } else {
            ((DrawerLayout)findViewById(R.id.drawerLayout)).openDrawer(GravityCompat.START);
        }
    }

    @Override
    public void onBackPressed() {
        if(((DrawerLayout)findViewById(R.id.drawerLayout)).isDrawerOpen(GravityCompat.START)) {
            ((DrawerLayout)findViewById(R.id.drawerLayout)).closeDrawer(GravityCompat.START);
            return;
        }
        backPressCloseHandler.onBackPressed();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        EventBus.getDefault().register(this);
        setContentView(R.layout.activity_main, ToolbarActivity.TOOLBAR_TYPE_MAIN, true);
        setSlideView();

        mainMenuGroupAdapter = new MainMenuGroupAdapter(this);
        mainMenuGroupAdapter.setModels(arrayListMenuGroupModel);
        ((ListView)findViewById(R.id.listView)).setAdapter(mainMenuGroupAdapter);

        backPressCloseHandler = new BackPressCloseHandler(this);

        mainMenuGroupAdapter.setOnClickCellListener(new MainMenuGroupAdapter.OnClickCell() {
            @Override
            public void onClickMenu(MenuModel model) {
                Intent intent = new Intent(GroupMenuActivity.this, MainActivity.class);
                intent.putExtra(EXTRA_NAME_UER_GROUP, true);
                intent.putExtra(EXTRA_NAME_TITLE, model.getTitle());
                intent.putExtra(EXTRA_NAME_MENU_LIST, filterMenu(model.getTitle()));
                pushActivity(intent);
            }
        });
        requestMenuList();
    }

    @Override
    protected void onResume() {
        super.onResume();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        EventBus.getDefault().unregister(this);
    }

    private void refreshSettingData() {

        int type = AppSettingManager.getLanguageType(this);

        String localeName;

        switch(type) {
            case AppSettingManager.TYPE_LANGUAGE_VI:
                localeName = "vi";
                break;
            case AppSettingManager.TYPE_LANGUAGE_KR:
                localeName = "ko";
                break;
            default:
            case AppSettingManager.TYPE_LANGUAGE_US:
                localeName = "en";
                break;
        }

        Locale locale = new Locale(localeName);
        Configuration conf = getBaseContext().getResources().getConfiguration();
        conf.setLocale(locale);
        createConfigurationContext(conf);
        Intent refresh = new Intent(this, MainActivity.class);
        startActivity(refresh);
        overridePendingTransition(0, 0);
        super.finish();
        overridePendingTransition(0, 0);
    }

    private void setSlideView() {

        ((TextView)findViewById(R.id.userName)).setText(SessionManager.getUserName(this));

        String langName;

        if(AppSettingManager.getLanguageType(this) == AppSettingManager.TYPE_LANGUAGE_VI) {
            langName = getString(R.string.languageName01);
        } else if(AppSettingManager.getLanguageType(this) == AppSettingManager.TYPE_LANGUAGE_KR) {
            langName = getString(R.string.languageName02);
        } else {
            langName = getString(R.string.languageName03);
        }

        ((TextView)findViewById(R.id.languageLabel)).setText(langName);

        int serverType = AppSettingManager.getServerType(this);

        String[] serverNames = getResources().getStringArray(R.array.server);

        String serverName;

        switch(serverType) {
            default:
            case AppSettingManager.TYPE_SERVER_IJ:
                serverName = serverNames[0];
                break;
            case AppSettingManager.TYPE_SERVER_IJ_TEST:
                serverName = serverNames[1];
                break;
            case AppSettingManager.TYPE_SERVER_TEST:
                serverName = serverNames[2];
                break;
        }

        ((TextView)findViewById(R.id.serverName)).setText(serverName);

        String appVersion;

        try {
            appVersion = getPackageManager().getPackageInfo(getPackageName(), 0).versionName;
        } catch(PackageManager.NameNotFoundException e) {
            AppLogManager.printErrorLog(e.getMessage());
            appVersion = "";
        }

        ((TextView)findViewById(R.id.versionName)).setText(appVersion);
    }

    private void requestMenuList() {
        if(SessionManager.getUserId(this).equalsIgnoreCase("MESTEST") || App.getInstance().isDebugMode()) {
            findViewById(R.id.debugLayout).setVisibility(View.VISIBLE);
            // createRmMenu();
            return;
        }

        String requestQuery
                = "SELECT A.FUNC_NAME          FUNC_NAME"
                + " FROM MSECGRPFUN A"
                + " INNER JOIN MSECUSRDEF B ON A.FACTORY = B.FACTORY AND B.SEC_GRP_ID = A.SEC_GRP_ID AND B.USER_ID = '" + SessionManager.getUserId(this) + "'"
                + " WHERE 1             = 1"
                + " AND   A.FACTORY = '" + DEFAULT_FACTORY + "'\n"
                + " ORDER BY DISP_LEVEL";

        SQLQueryRequest request = new SQLQueryRequest(this, requestQuery);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                arrayListMenuList.clear();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    List<Map<String, String>> rows = (List<Map<String, String>>)resultMap.get("ROWS");

                    try {
                        for (Map<String, String> row : rows) {
                            arrayListMenuList.add(row.get("FUNC_NAME"));
                        }
                        createMenuGroup();
                    }
                    catch(RuntimeException re) {
                        throw re;
                    }
                    catch(Exception e) {
                        AppLogManager.printErrorLog(e.getMessage());
                    }
                }
            }

            @Override
            public void onFailure(Exception exception) {
                showDialog(exception.getMessage());
            }

            @Override
            public void onFinish() {
                hideLoadingDialog();
            }
        });
    }

    private void createMenuGroup() {
        final String[] listMenuGroup = getResources().getStringArray(R.array.main_menu_group_array);

        if(checkInManagementMenu()) {
            MenuModel menuGroupModel = new MenuModel();
            menuGroupModel.setTitle(listMenuGroup[0]);
            arrayListMenuGroupModel.add(menuGroupModel);
        }

        if(checkMoveManagementMenu()) {
            MenuModel menuGroupModel = new MenuModel();
            menuGroupModel.setTitle(listMenuGroup[1]);
            arrayListMenuGroupModel.add(menuGroupModel);
        }

        if(checkOutManagementMenu()) {
            MenuModel menuGroupModel = new MenuModel();
            menuGroupModel.setTitle(listMenuGroup[2]);
            arrayListMenuGroupModel.add(menuGroupModel);
        }

        if(checkInventoryManagementMenu()) {
            MenuModel menuGroupModel = new MenuModel();
            menuGroupModel.setTitle(listMenuGroup[3]);
            arrayListMenuGroupModel.add(menuGroupModel);
        }

        if(checkInquireMenu()) {
            MenuModel menuGroupModel = new MenuModel();
            menuGroupModel.setTitle(listMenuGroup[4]);
            arrayListMenuGroupModel.add(menuGroupModel);
        }

        if(checkLaminationMenu()) {
            MenuModel menuGroupModel = new MenuModel();
            menuGroupModel.setTitle(listMenuGroup[5]);
            arrayListMenuGroupModel.add(menuGroupModel);
        }

        // 만약 그룹에 해당 되지 않은 메뉴들만 존재하는 경우 (생산, MMS 사용자가 로그인 하는 경우)
        if(arrayListMenuGroupModel.isEmpty() && !arrayListMenuList.isEmpty()) {
            Intent intent = new Intent(GroupMenuActivity.this, MainActivity.class);
            intent.putExtra(EXTRA_NAME_UER_GROUP, false);
            intent.putExtra(EXTRA_NAME_MENU_LIST, arrayListMenuList);
            pushActivity(intent);
        }

        mainMenuGroupAdapter.notifyDataSetChanged();
    }

    private boolean checkInManagementMenu() {
        String[] idListInManagement = getResources().getStringArray(R.array.main_menu_in_management_menu_id_array);

        // 받아온 메뉴 리스트를 순회하면서
        for(String menuId : arrayListMenuList) {
            // IN MANAGEMENT 메뉴 그룹에 속하는 메뉴가 있는지 확인한다.
            for (String menu : idListInManagement) {
                if (menu.equals(menuId))
                    return true;
            }
        }
        return false;
    }

    private boolean checkMoveManagementMenu() {
        String[] idListMoveManagement = getResources().getStringArray(R.array.main_menu_move_management_menu_id_array);

        // 받아온 메뉴 리스트를 순회하면서
        for(String menuId : arrayListMenuList) {
            // MOVE MANAGEMENT 메뉴 그룹에 속하는 메뉴가 있는지 확인한다.
            for (String menu : idListMoveManagement) {
                if (menu.equals(menuId))
                    return true;
            }
        }
        return false;
    }

    private boolean checkOutManagementMenu() {
        String[] idListOutManagement = getResources().getStringArray(R.array.main_menu_out_management_menu_id_array);

        // 받아온 메뉴 리스트를 순회하면서
        for(String menuId : arrayListMenuList) {
            // OUT MANAGEMENT 메뉴 그룹에 속하는 메뉴가 있는지 확인한다.
            for (String menu : idListOutManagement) {
                if (menu.equals(menuId))
                    return true;
            }
        }
        return false;
    }

    private boolean checkInventoryManagementMenu() {
        String[] idListInventoryManagement = getResources().getStringArray(R.array.main_menu_inventory_management_menu_id_array);

        // 받아온 메뉴 리스트를 순회하면서
        for(String menuId : arrayListMenuList) {
            // OUT MANAGEMENT 메뉴 그룹에 속하는 메뉴가 있는지 확인한다.
            for (String menu : idListInventoryManagement) {
                if (menu.equals(menuId))
                    return true;
            }
        }
        return false;
    }

    private boolean checkInquireMenu() {
        String[] idListInquire = getResources().getStringArray(R.array.main_menu_inquire_menu_id_array);

        // 받아온 메뉴 리스트를 순회하면서
        for(String menuId : arrayListMenuList) {
            // OUT MANAGEMENT 메뉴 그룹에 속하는 메뉴가 있는지 확인한다.
            for (String menu : idListInquire) {
                if (menu.equals(menuId))
                    return true;
            }
        }
        return false;
    }

    private boolean checkLaminationMenu() {
        String[] idListLamination = getResources().getStringArray(R.array.main_menu_lamination_menu_id_array);

        // 받아온 메뉴 리스트를 순회하면서
        for(String menuId : arrayListMenuList) {
            // OUT MANAGEMENT 메뉴 그룹에 속하는 메뉴가 있는지 확인한다.
            for (String menu : idListLamination) {
                if (menu.equals(menuId))
                    return true;
            }
        }
        return false;
    }

    private ArrayList<String> filterMenu(String selectedGroupName) {
        String[] listMenuGroup = getResources().getStringArray(R.array.main_menu_group_array);
        String[] selectedGroupMenu = new String[]{};
        ArrayList<String> menuListInGroup = new ArrayList<String>();

        if (selectedGroupName.equals(listMenuGroup[0]))
            selectedGroupMenu = getResources().getStringArray(R.array.main_menu_in_management_menu_id_array);
        else if (selectedGroupName.equals(listMenuGroup[1]))
            selectedGroupMenu = getResources().getStringArray(R.array.main_menu_move_management_menu_id_array);
        else if (selectedGroupName.equals(listMenuGroup[2]))
            selectedGroupMenu = getResources().getStringArray(R.array.main_menu_out_management_menu_id_array);
        else if (selectedGroupName.equals(listMenuGroup[3]))
            selectedGroupMenu = getResources().getStringArray(R.array.main_menu_inventory_management_menu_id_array);
        else if (selectedGroupName.equals(listMenuGroup[4]))
            selectedGroupMenu = getResources().getStringArray(R.array.main_menu_inquire_menu_id_array);
        else if (selectedGroupName.equals(listMenuGroup[5]))
            selectedGroupMenu = getResources().getStringArray(R.array.main_menu_lamination_menu_id_array);

        for (String menu : arrayListMenuList) {
            for (String groupMenu : selectedGroupMenu) {
                if (menu.equals(groupMenu)) {
                    menuListInGroup.add(menu);
                    break;
                }
            }
        }

        return menuListInGroup;
    }
}
