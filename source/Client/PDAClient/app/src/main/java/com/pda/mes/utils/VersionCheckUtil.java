package com.pda.mes.utils;

import android.content.Context;
import android.content.pm.PackageManager;

import com.pda.mes.manager.AppLogManager;

public class VersionCheckUtil {

    public static boolean checkVersion(String curVersion, String newVersion) {

        boolean needUpdate = false;

        if(curVersion.contains("-DEBUG")) {
            curVersion = curVersion.replace("-DEBUG", "");
        }

        if(null == newVersion || newVersion.isEmpty()) {
            return needUpdate;
        }

        String[] currVersion = curVersion.split("\\.");
        String[] serverVersion = newVersion.split("\\.");

        int currPatchVersion = Integer.parseInt(currVersion[2]);
        int serverPatchVersion = Integer.parseInt(serverVersion[2]);

        int currMinorVersion = Integer.parseInt(currVersion[1]);
        int serverMinorVersion = Integer.parseInt(serverVersion[1]);

        int currMajorVersion = Integer.parseInt(currVersion[0]);
        int serverMajorVersion = Integer.parseInt(serverVersion[0]);

        if(currMajorVersion < serverMajorVersion) {
            needUpdate = true;
        } else if(currMajorVersion == serverMajorVersion && currMinorVersion < serverMinorVersion) {
            needUpdate = true;
        } else if(currMajorVersion == serverMajorVersion && currMinorVersion == serverMinorVersion && currPatchVersion < serverPatchVersion) {
            needUpdate = true;
        }

        return needUpdate;
    }

    public static String splitServerVersion(String version) {
        return version.replace("MESPDA_V", "");
    }

    public static String getAppVersion(Context context) {

        String appVersion;

        try {
            appVersion = context.getPackageManager().getPackageInfo(context.getPackageName(), 0).versionName;
        } catch(PackageManager.NameNotFoundException e) {
            AppLogManager.printErrorLog(e.getMessage());
            appVersion = "";
        }

        return appVersion;
    }

}
