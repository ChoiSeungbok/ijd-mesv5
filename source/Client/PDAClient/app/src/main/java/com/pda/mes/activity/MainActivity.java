package com.pda.mes.activity;

import android.content.Intent;
import android.content.pm.PackageManager;
import android.content.res.Configuration;
import android.os.Bundle;
import android.os.Handler;
import android.support.v4.view.GravityCompat;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.widget.SwitchCompat;
import android.view.View;
import android.widget.ListView;
import android.widget.TextView;

import com.pda.mes.App;
import com.pda.mes.R;
import com.pda.mes.activity.intro.LoginActivity;
import com.pda.mes.activity.menu.CPDA2001_PDA_Activity;
import com.pda.mes.activity.menu.CPDA2002_PDA_Activity;
import com.pda.mes.activity.menu.CPDA2003_PDA_Activity;
import com.pda.mes.activity.menu.CPDA2004_PDA_Activity;
import com.pda.mes.activity.menu.CPDA2005_PDA_Activity;
import com.pda.mes.activity.menu.CPDA2006_PDA_Activity;
import com.pda.mes.activity.menu.CPDA2007_PDA_Activity;
import com.pda.mes.activity.menu.CPDA2008_PDA_Activity;
import com.pda.mes.activity.menu.CPDA2009_PDA_Activity;
import com.pda.mes.activity.menu.CPDA2010_PDA_Activity;
import com.pda.mes.activity.menu.CPDA2011_PDA_Activity;
import com.pda.mes.activity.menu.CPDA2012_PDA_Activity;
import com.pda.mes.activity.menu.CPDA2013_PDA_Activity;
import com.pda.mes.activity.menu.CPDA2014_PDA_Activity;
import com.pda.mes.activity.menu.CPDA2015_PDA_Activity;
import com.pda.mes.activity.menu.CPDA2016_PDA_Activity;
import com.pda.mes.activity.menu.CPDA2017_PDA_Activity;
import com.pda.mes.activity.menu.CPDA2018_PDA_Activity;
import com.pda.mes.activity.menu.CPDA2019_PDA_Activity;
import com.pda.mes.activity.menu.CPDA2020_PDA_Activity;
import com.pda.mes.activity.menu.CPDA3001_PDA_Activity;
import com.pda.mes.activity.menu.CPDA3002_PDA_Activity;
import com.pda.mes.activity.menu.CPDA3003_PDA_Activity;
import com.pda.mes.activity.menu.CPDA3004_PDA_Activity;
import com.pda.mes.activity.menu.CPDA3005_PDA_Activity;
import com.pda.mes.activity.menu.CPDA3006_PDA_Activity;
import com.pda.mes.activity.setting.SettingsActivity;
import com.pda.mes.adapter.MainMenuAdapter;
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

public class MainActivity extends ToolbarActivity {

    public static final String TAG = MainActivity.class.getSimpleName();

    private static final int REQUEST_CODE_SETTINGS = 0x99;

    private BackPressCloseHandler backPressCloseHandler;
    private MainMenuAdapter mainMenuAdapter;
    private ListView listView;

    private List<MenuModel> menuModels = new ArrayList<>();
    private List<MenuModel> bookMarkMenuModels = new ArrayList<>();

    private List<String> menuIdList = new ArrayList<>();

    private String[] menuArray;
    private String[] menuIdArray;
    private String[] menuEnNameArray;

    private boolean nowViewBookMark = true;

    public void onEventMainThread(LanguageChangeEvent event) {

        ((DrawerLayout)findViewById(R.id.drawerLayout)).closeDrawer(GravityCompat.START);

        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                refreshSettingData();
            }
        }, 500);
    }

    /**
     * 자재메뉴 보기 핸들러
     *
     * @param view
     */
    public void onClickINV(View view) {
        createINVMenu();

        if(((DrawerLayout)findViewById(R.id.drawerLayout)).isDrawerOpen(GravityCompat.START)) {
            ((DrawerLayout)findViewById(R.id.drawerLayout)).closeDrawer(GravityCompat.START);
            return;
        }
    }

    /**
     * 생산메뉴 보기 핸들러
     *
     * @param view
     */
    public void onClickWIP(View view) {
        createWIPMenu();

        if(((DrawerLayout)findViewById(R.id.drawerLayout)).isDrawerOpen(GravityCompat.START)) {
            ((DrawerLayout)findViewById(R.id.drawerLayout)).closeDrawer(GravityCompat.START);
            return;
        }
    }

    /**
     * SHP 보기 핸들러
     *
     * @param view
     */
    public void onClickSHP(View view) {
        createSHPMenu();

        if(((DrawerLayout)findViewById(R.id.drawerLayout)).isDrawerOpen(GravityCompat.START)) {
            ((DrawerLayout)findViewById(R.id.drawerLayout)).closeDrawer(GravityCompat.START);
            return;
        }
    }


    public void onClickBookMark(View view) {
        createBookMarkMenu();

        if(((DrawerLayout)findViewById(R.id.drawerLayout)).isDrawerOpen(GravityCompat.START)) {
            ((DrawerLayout)findViewById(R.id.drawerLayout)).closeDrawer(GravityCompat.START);
            return;
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

                        SessionManager.clearData(MainActivity.this);

                        Intent intent = new Intent(MainActivity.this, LoginActivity.class);
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
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        EventBus.getDefault().register(this);

        setContentView(R.layout.activity_main, ToolbarActivity.TOOLBAR_TYPE_MAIN, true);
        setSlideView();
        backPressCloseHandler = new BackPressCloseHandler(this);

        menuEnNameArray = getResources().getStringArray(R.array.main_menu_array_en);
        menuArray = getResources().getStringArray(R.array.main_menu_array);
        menuIdArray = getResources().getStringArray(R.array.main_menu_id_array);

        mainMenuAdapter = new MainMenuAdapter(this);
        listView = findViewById(R.id.listView);
        mainMenuAdapter.setModels(menuModels);
        listView.setAdapter(mainMenuAdapter);

        mainMenuAdapter.setOnClickCellListener(new MainMenuAdapter.OnClickCell() {
            @Override
            public void onClickMenu(MenuModel model) {
                String bookMarkFlag = "0";
                Intent intent = new Intent();
                intent.putExtra(EXTRA_NAME_TITLE, model.getTitle());
                intent.putExtra(EXTRA_NAME_SCREEN_ID, model.getId());
                intent.putExtra(EXTRA_NAME_EN_TITLE, model.getEnTitle());
                intent.setClass(MainActivity.this, model.getIntentClass());
                if (bookMarkMenuModels.size() > 0) {
                    for (MenuModel item : bookMarkMenuModels) {
                        if (item.getId().equals(model.getId())) {
                            bookMarkFlag = "1";
                            break;
                        }
                    }
                }
                intent.putExtra(EXTRA_NAME_BOOK_MARK_FLAG, bookMarkFlag);
                pushActivity(intent);
            }
        });

        //requestMenuList(); // todo : 나중에 없애기
        requestBookMark();
        if(App.getInstance().isDebugMode()) {
            findViewById(R.id.debugLayout).setVisibility(View.VISIBLE);
        }
    }

    @Override
    protected void onResume() {
        new Thread() {
            @Override
            public void run() {
                requestBookMark();
            }
        }.start();
        super.onResume();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        EventBus.getDefault().unregister(this);
    }

    private void createBookMarkMenu() {
        nowViewBookMark = true;
        int menuIndex;
        boolean addFlag = false;
        MenuModel menuModel;
        menuModels.clear();
        if (bookMarkMenuModels.size() <= 0) {
            mainMenuAdapter.notifyDataSetChanged();
            return;
        }


        menuModel = null;
        // 받아온 메뉴의 메뉴 ID 를 기준으로 리소스에 저장된 메뉴 ID 배열의 index 를 찾는다.
        for(menuIndex = 0; menuIndex < menuIdArray.length; menuIndex++) {
            for(MenuModel item : bookMarkMenuModels) {
                if(item.getId().equalsIgnoreCase(menuIdArray[menuIndex])) {
                    // 찾아온 index 에 해당 하는 menuIdArray, menuArray, menuEnNameArray 를 매핑한다.
                    menuModel = new MenuModel();
                    menuModel.setId(menuIdArray[menuIndex]);
                    menuModel.setTitle(menuArray[menuIndex]);
                    menuModel.setEnTitle(menuEnNameArray[menuIndex]);
                    addFlag = true;
                    break;
                }
            }

            // menuModel 이 null 이면 받아온 id 에 대한 메뉴가 없기 때문에 넘어간다.
            if(menuModel == null)
                continue;
            if(!addFlag) {
                continue;
            }
            Class intentClass;

            switch(menuIndex) {
                default:
                    intentClass = null;
                    break;
                case 0:
                    //공정실적등록(착공)
                    intentClass = CPDA2001_PDA_Activity.class;
                    break;
                case 1:
                    //공정실적등록(완공)
                    intentClass = CPDA2002_PDA_Activity.class;
                    break;
                case 2:
                    //불량 등록
                    intentClass = CPDA2003_PDA_Activity.class;
                    break;
                case 3:
                    //비가동 등록
                    intentClass = CPDA2004_PDA_Activity.class;
                    break;
                case 4:
                    //이동지시확정
                    intentClass = CPDA2005_PDA_Activity.class;
                    break;
                case 5:
                    //창고간자재이동
                    intentClass = CPDA2006_PDA_Activity.class;
                    break;
                case 6:
                    //자재병합
                    intentClass = CPDA2007_PDA_Activity.class;
                    break;
                case 7:
                    //자재잠금
                    intentClass = CPDA2008_PDA_Activity.class;
                    break;
                case 8:
                    //자재잠금해제
                    intentClass = CPDA2009_PDA_Activity.class;
                    break;
                /*case 9:
                    //자재불출등록
                    intentClass = CPDA2010_PDA_Activity.class;
                    break;
                case 10:
                    //자재인수
                    intentClass = CPDA2011_PDA_Activity.class;
                    break;*/
                case 11:
                    //자재입고관리
                    intentClass = CPDA2012_PDA_Activity.class;
                    break;
                case 12:
                    //기타출고
                    intentClass = CPDA2013_PDA_Activity.class;
                    break;
                /*case 13:
                    //출하확정
                    intentClass = CPDA2014_PDA_Activity.class;
                    break;*/
                case 14:
                    //LOT 정보 조회
                    intentClass = CPDA3001_PDA_Activity.class;
                    break;
                case 15:
                    //구매 지시 조회
                    intentClass = CPDA3002_PDA_Activity.class;
                    break;
                case 16:
                    //창고 별 자재 현황
                    intentClass = CPDA3003_PDA_Activity.class;
                    break;
                case 17:
                    //자재 LOT 조회
                    intentClass = CPDA3004_PDA_Activity.class;
                    break;
                case 18:
                    //출하 지시 조회
                    intentClass = CPDA3005_PDA_Activity.class;
                    break;
                case 19:
                    //출하등록
                    intentClass = CPDA2015_PDA_Activity.class;
                    break;
                case 20:
                    //공정실적등록(착공)-CTM(가공)
                    intentClass = CPDA2016_PDA_Activity.class;
                    break;
                case 21:
                    //공정실적등록(완공)-CTM(가공)
                    intentClass = CPDA2017_PDA_Activity.class;
                    break;
                case 22:
                    //공정-출하 LOT별 관게체크
                    intentClass = CPDA3006_PDA_Activity.class;
                    break;
                case 23:
                    //기타출고 (WIP)
                    intentClass = CPDA2018_PDA_Activity.class;
                    break;
                case 24:
                    //자재 이동 등록
                    intentClass = CPDA2019_PDA_Activity.class;
                    break;
                case 25:
                    //자재 이동 확정
                    intentClass = CPDA2020_PDA_Activity.class;
                    break;
            }

            menuModel.setIntentClass(intentClass);
            addFlag = false;
            if(null != intentClass)
                menuModels.add(menuModel);
        }
        mainMenuAdapter.notifyDataSetChanged();
        setTitleLabel(getString(R.string.book_mark_menu));
    }

    private void createSHPMenu() {
        nowViewBookMark = false;
        menuModels.clear();

        for(int i = 0 ; i < menuArray.length ; i++) {

            boolean isEquals = true;

            for(String id : menuIdList) {
                if(id.equals(menuIdArray[i])) {
                    isEquals = true;
                    break;
                }
            }

            if(isEquals) {
                MenuModel model = new MenuModel();
                model.setId(menuIdArray[i]);
                model.setTitle(menuArray[i]);
                model.setEnTitle(menuEnNameArray[i]);

                Class intentClass;

                switch(i) {
                    default:
                        intentClass = null;
                        break;
                    /*case 13:
                        //출하확정
                        intentClass = CPDA2014_PDA_Activity.class;
                        break;*/
                    case 18:
                        //출하 지시 조회
                        intentClass = CPDA3005_PDA_Activity.class;
                        break;
                    case 19:
                        //출하등록
                        intentClass = CPDA2015_PDA_Activity.class;
                        break;
                    case 22:
                        //공정-출하 LOT별 관게체크
                        intentClass = CPDA3006_PDA_Activity.class;
                        break;
                }
                model.setIntentClass(intentClass);

                if(null != intentClass) {
                    menuModels.add(model);
                }
            }
        }

        mainMenuAdapter.notifyDataSetChanged();
        setTitleLabel(getString(R.string.shp_menu));
    }

    private void createWIPMenu() {
        nowViewBookMark = false;
        menuModels.clear();

        for(int i = 0 ; i < menuArray.length ; i++) {

            boolean isEquals = true;

            for(String id : menuIdList) {
                if(id.equals(menuIdArray[i])) {
                    isEquals = true;
                    break;
                }
            }

            if(isEquals) {
                MenuModel model = new MenuModel();
                model.setId(menuIdArray[i]);
                model.setTitle(menuArray[i]);
                model.setEnTitle(menuEnNameArray[i]);

                Class intentClass;

                switch(i) {
                    default:
                        intentClass = null;
                        break;
                    case 0:
                        //공정실적등록(착공)
                        intentClass = CPDA2001_PDA_Activity.class;
                        break;
                    case 1:
                        //공정실적등록(완공)
                        intentClass = CPDA2002_PDA_Activity.class;
                        break;
                    case 2:
                        //불량 등록
                        intentClass = CPDA2003_PDA_Activity.class;
                        break;
                    case 3:
                        //비가동 등록
                        intentClass = CPDA2004_PDA_Activity.class;
                        break;
                    case 4:
                        //이동지시확정
                        intentClass = CPDA2005_PDA_Activity.class;
                        break;
                    case 14:
                        //LOT 정보 조회
                        intentClass = CPDA3001_PDA_Activity.class;
                        break;
                    case 20:
                        //공정실적등록(착공)-CTM(가공)
                        intentClass = CPDA2016_PDA_Activity.class;
                        break;
                    case 21:
                        //공정실적등록(완공)-CTM(가공)
                        intentClass = CPDA2017_PDA_Activity.class;
                        break;
                    case 23:
                        //기타출고 (WIP)
                        intentClass = CPDA2018_PDA_Activity.class;
                        break;
                }

                model.setIntentClass(intentClass);

                if(null != intentClass) {
                    menuModels.add(model);
                }
            }
        }

        mainMenuAdapter.notifyDataSetChanged();
        setTitleLabel(getString(R.string.production_menu));
    }

    private void createINVMenu() {
        nowViewBookMark = false;
        menuModels.clear();

        for(int i = 0 ; i < menuArray.length ; i++) {

            boolean isEquals = true;

            for(String id : menuIdList) {
                if(id.equals(menuIdArray[i])) {
                    isEquals = true;
                    break;
                }
            }

            if(isEquals) {
                MenuModel model = new MenuModel();
                model.setId(menuIdArray[i]);
                model.setTitle(menuArray[i]);
                model.setEnTitle(menuEnNameArray[i]);

                Class intentClass;

                switch(i) {
                    default:
                        intentClass = null;
                        break;
                    case 5:
                        //창고간자재이동
                        intentClass = CPDA2006_PDA_Activity.class;
                        break;
                    case 6:
                        //자재병합
                        intentClass = CPDA2007_PDA_Activity.class;
                        break;
                    case 7:
                        //자재잠금
                        intentClass = CPDA2008_PDA_Activity.class;
                        break;
                    case 8:
                        //자재잠금해제
                        intentClass = CPDA2009_PDA_Activity.class;
                        break;
                    /*case 9:
                        //자재불출등록
                        intentClass = CPDA2010_PDA_Activity.class;
                        break;
                    case 10:
                        //자재인수
                        intentClass = CPDA2011_PDA_Activity.class;
                        break;*/
                    case 11:
                        //자재입고관리
                        intentClass = CPDA2012_PDA_Activity.class;
                        break;
                    case 12:
                        //기타출고(INV)
                        intentClass = CPDA2013_PDA_Activity.class;
                        break;
                    case 15:
                        //구매 지시 조회
                        intentClass = CPDA3002_PDA_Activity.class;
                        break;
                    case 16:
                        //창고 별 자재 현황
                        intentClass = CPDA3003_PDA_Activity.class;
                        break;
                    case 17:
                        //자재 LOT 조회
                        intentClass = CPDA3004_PDA_Activity.class;
                        break;
                    case 24:
                        //자재 이동 등록
                        intentClass = CPDA2019_PDA_Activity.class;
                        break;
                    case 25:
                        //자재 이동 확정
                        intentClass = CPDA2020_PDA_Activity.class;
                        break;
                }

                model.setIntentClass(intentClass);

                if(null != intentClass) {
                    menuModels.add(model);
                }
            }
        }

        mainMenuAdapter.notifyDataSetChanged();
        setTitleLabel(getString(R.string.inv_menu));
    }

    private void createMenu(ArrayList<String> arrayListMenuList) {
        nowViewBookMark = false;
        int menuIndex;
        MenuModel menuModel;
        menuModels.clear(); //createMenu 메뉴 쌓기전에 항상 초기화 작업 추가

        for(String menuId : arrayListMenuList) {
            menuModel = null;
            // 받아온 메뉴의 메뉴 ID 를 기준으로 리소스에 저장된 메뉴 ID 배열의 index 를 찾는다.
            for(menuIndex = 0; menuIndex < menuIdArray.length; menuIndex++) {
                if(menuId.equalsIgnoreCase(menuIdArray[menuIndex])) {
                    // 찾아온 index 에 해당 하는 menuIdArray, menuArray, menuEnNameArray 를 매핑한다.
                    menuModel = new MenuModel();
                    menuModel.setId(menuIdArray[menuIndex]);
                    menuModel.setTitle(menuArray[menuIndex]);
                    menuModel.setEnTitle(menuEnNameArray[menuIndex]);
                    break;
                }
            }

            // menuModel 이 null 이면 받아온 id 에 대한 메뉴가 없기 때문에 넘어간다.
            if(menuModel == null)
                continue;

            Class intentClass;

            switch(menuIndex) {
                default:
                    intentClass = null;
                    break;
                case 0:
                    //공정실적등록(착공)
                    intentClass = CPDA2001_PDA_Activity.class;
                    break;
                case 1:
                    //공정실적등록(완공)
                    intentClass = CPDA2002_PDA_Activity.class;
                    break;
                case 2:
                    //불량 등록
                    intentClass = CPDA2003_PDA_Activity.class;
                    break;
                case 3:
                    //비가동 등록
                    intentClass = CPDA2004_PDA_Activity.class;
                    break;
                case 4:
                    //이동지시확정
                    intentClass = CPDA2005_PDA_Activity.class;
                    break;
                case 5:
                    //창고간자재이동
                    intentClass = CPDA2006_PDA_Activity.class;
                    break;
                case 6:
                    //자재병합
                    intentClass = CPDA2007_PDA_Activity.class;
                    break;
                case 7:
                    //자재잠금
                    intentClass = CPDA2008_PDA_Activity.class;
                    break;
                case 8:
                    //자재잠금해제
                    intentClass = CPDA2009_PDA_Activity.class;
                    break;
                /*case 9:
                    //자재불출등록
                    intentClass = CPDA2010_PDA_Activity.class;
                    break;
                case 10:
                    //자재인수
                    intentClass = CPDA2011_PDA_Activity.class;
                    break;*/
                case 11:
                    //자재입고관리
                    intentClass = CPDA2012_PDA_Activity.class;
                    break;
                case 12:
                    //기타출고
                    intentClass = CPDA2013_PDA_Activity.class;
                    break;
                /*case 13:
                    //출하확정
                    intentClass = CPDA2014_PDA_Activity.class;
                    break;*/
                case 14:
                    //LOT 정보 조회
                    intentClass = CPDA3001_PDA_Activity.class;
                    break;
                case 15:
                    //구매 지시 조회
                    intentClass = CPDA3002_PDA_Activity.class;
                    break;
                case 16:
                    //창고 별 자재 현황
                    intentClass = CPDA3003_PDA_Activity.class;
                    break;
                case 17:
                    //자재 LOT 조회
                    intentClass = CPDA3004_PDA_Activity.class;
                    break;
                case 18:
                    //출하 지시 조회
                    intentClass = CPDA3005_PDA_Activity.class;
                    break;
                case 19:
                    //출하등록
                    intentClass = CPDA2015_PDA_Activity.class;
                    break;
                case 20:
                    //공정실적등록(착공)-CTM(가공)
                    intentClass = CPDA2016_PDA_Activity.class;
                    break;
                case 21:
                    //공정실적등록(완공)-CTM(가공)
                    intentClass = CPDA2017_PDA_Activity.class;
                    break;
                case 22:
                    //공정-출하 LOT별 관게체크
                    intentClass = CPDA3006_PDA_Activity.class;
                    break;
                case 23:
                    //기타출고 (WIP)
                    intentClass = CPDA2018_PDA_Activity.class;
                    break;
                case 24:
                    //자재 이동 등록
                    intentClass = CPDA2019_PDA_Activity.class;
                    break;
                case 25:
                    //자재 이동 확정
                    intentClass = CPDA2020_PDA_Activity.class;
                    break;
            }

            menuModel.setIntentClass(intentClass);

            if(null != intentClass)
                menuModels.add(menuModel);
        }
        mainMenuAdapter.notifyDataSetChanged();
        setTitleLabel(getString(R.string.menu));
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
            case AppSettingManager.TYPE_SERVER_IJ:
                serverName = serverNames[0];
                break;
            case AppSettingManager.TYPE_SERVER_IJ_TEST:
                serverName = serverNames[1];
                break;
            case AppSettingManager.TYPE_SERVER_TEST:
                serverName = serverNames[2];
                break;
            default:
                serverName = serverNames[0];
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
        //2021-01-19
        //해당 그룹에 속해있으면 메인화면에 처음으로 들어왔을 시 메뉴들이 안보임.
        //이 부분 주석처리. by 김민수 프로님.
        /*
        if(SessionManager.getUserGroup(this).equalsIgnoreCase("ADMIN_GROUP") || SessionManager.getUserGroup(this).equalsIgnoreCase("TEST_GROUP") || App.getInstance().isDebugMode()) {
            findViewById(R.id.debugLayout).setVisibility(View.VISIBLE);
            ArrayList<String> arrayListMenuList = new ArrayList<>();
            createMenu(arrayListMenuList);
            return;
        }
        */


        String requestQuery
                = "SELECT A.FUNC_NAME          FUNC_NAME"
                + " FROM MSECGRPFUN A"
                + " INNER JOIN MSECUSRDEF B ON A.FACTORY = B.FACTORY AND B.SEC_GRP_ID = A.SEC_GRP_ID AND B.USER_ID = '" + SessionManager.getUserId(this) + "'"
                + " WHERE 1             = 1"
                + " AND   A.FACTORY     = '"+ AppSettingManager.getLoginFactory(this) +"'"
                + " AND   A.PROGRAM_ID  = 'MESPDAClient'"
                + " ORDER BY DISP_LEVEL";

        SQLQueryRequest request = new SQLQueryRequest(this, requestQuery);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                showLoadingDialog();
            }

            @Override
            public void onResult(Object result) {
                ArrayList<String> arrayListMenuList = new ArrayList<>();

                Map<String, Object> resultMap = (Map<String, Object>)result;

                if(resultMap.containsKey("ROWS")) {
                    List<Map<String, String>> rows = (List<Map<String, String>>)resultMap.get("ROWS");

                    try {
                        for (Map<String, String> row : rows) {
                            arrayListMenuList.add(row.get("FUNC_NAME"));
                        }
                        createMenu(arrayListMenuList);
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

    private void requestBookMark() {
        String requestQuery
                = "SELECT A.USER_ID USER_ID,"
                + " A.SEQ_NUM SEQ_NUM,"
                + " A.FUNC_NAME FUNC_NAME,"
                + " A.USER_FUNC_DESC USER_FUNC_DESC"
                + " FROM MSECUSRFUN A"
                + " WHERE 1             = 1"
                + " AND   A.FACTORY     = '"+ AppSettingManager.getLoginFactory(this) +"'"
                + " AND   A.USER_ID     = '"+ SessionManager.getUserId(this) +"'"
                + " AND   A.PROGRAM_ID  = 'MESPDAClient'"
                + " ORDER BY SEQ_NUM";

        SQLQueryRequest request = new SQLQueryRequest(this, requestQuery);

        request.request(new Request.RequestHandler() {
            @Override
            public void onStart() {
                super.onStart();
            }

            @Override
            public void onResult(Object result) throws InterruptedException {
                Map<String, Object> resultMap = (Map<String, Object>)result;
                bookMarkMenuModels = new ArrayList<>();
                if (resultMap.containsKey("ROWS")) {
                    List<Map<String, String>> rows = (List<Map<String, String>>)resultMap.get("ROWS");
                    for (Map<String, String> item : rows) {
                        MenuModel menu = new MenuModel();
                        menu.setId(item.get("FUNC_NAME"));
                        menu.setTitle(item.get("USER_FUNC_DESC"));
                        bookMarkMenuModels.add(menu);
                    }
                } else {
                    requestMenuList();
                    return;
                }

                if (nowViewBookMark) {
                    createBookMarkMenu();
                }
            }

            @Override
            public void onFailure(Exception exception) {
                super.onFailure(exception);
            }
        });
    }
}
