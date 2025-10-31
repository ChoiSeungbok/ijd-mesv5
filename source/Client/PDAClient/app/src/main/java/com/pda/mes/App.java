package com.pda.mes;

/**
 * Created by sjs on 2020. 09. 24
 */

public class App extends android.app.Application {

    /**
     * 프리퍼런스 네임
     */
    public static final String PREFERENCE_NAME = "com.pda.mes";

    private static App sInstance;

    static {
        sInstance = new App();
    }

    public static App getInstance() {
        return sInstance;
    }

    public boolean isDebugMode() {
        //return BuildConfig.DEBUG;
        return false;
    }

    @Override
    public void onCreate() {
        super.onCreate();
    }
}