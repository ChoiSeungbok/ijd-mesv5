package com.pda.mes.manager;

import android.util.Log;

/**
 * Created by sjs on 2020. 09. 24
 */

public class AppLogManager {

    public static final String TAG = "APP_MESPDA";

    public static void printScreenNameLog(String message) {
        printScreenNameLog(TAG,  message);
    }


    public static void printScreenNameLog(String tag, String message) {
        //if(App.getInstance().isDebugMode()) {
            Log.e(tag,  " -                       Screen Name >>>>>> " +message);
        //}
    }

    public static void printLog(String message) {
        printLog(TAG,  message);
    }


    public static void printLog(String tag, String message) {
        //if(App.getInstance().isDebugMode()) {
            Log.v(tag,  message);
        //}
    }

    public static void printErrorLog(String message) {
        //if(App.getInstance().isDebugMode()) {
            Log.e(TAG, " -                       ERROR >>>>>> " + message);
        //}
    }

    public static void printRequestMessage(String message) {
        // if(App.getInstance().isDebugMode()) {
            System.out.println(TAG + " -              Message >>>>>> " + message);
        //}
    }
}
