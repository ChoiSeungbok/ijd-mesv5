package com.pda.mes.utils;

import android.os.Environment;
import android.util.Log;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.text.SimpleDateFormat;
import java.util.Calendar;

public class LogUtil {
    private final static String LOG_FILE_DATE_FORMAT = "%02d%02d%02d_";
    private final static String TIME_FORMAT = "[%02d-%02d %02d:%02d:%02d] ";
    private final static String ENDDING_WORD = "\r\n";
    private final static String LOG_FILE_NAME = "Log.txt";
    private final static int LOG_FILE_DATA_SIZE = 1024*1024;
    private final static String LOG_DIRECTORY_PATH = "Log";
    private final static String LOG_TAG = "Logger";
    public final static String ACTIVITY_START = "Activity Start ================================";

    /**
     * 내부함수 : 저장할 로그파일의 전체 경로를 구한다.
     * @return 로그파일의 전체경로
     */
    private static String getLogFileAbsolutePath(String date) {
        // Log 를 저장할 디렉토리의 경로부터 구한다.
        try {
            // String logDirectoryPath = context.getFilesDir().getAbsolutePath();
            // 다운로드 폴더 아래에 LOG 폴더에 저장한다.
            String logDirectoryPath = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS).getAbsolutePath();
            String logFilePath = "";

            if (logDirectoryPath.endsWith(File.separator))
                logDirectoryPath += LOG_DIRECTORY_PATH;
            else
                logDirectoryPath += (File.separator + LOG_DIRECTORY_PATH);

            // 해당 디렉토리가 없는 경우 디렉토리를 생성한다.
            File file = new File(logDirectoryPath);
            if (!file.exists())
                file.mkdirs();

            // 날짜를 넣은 로그파일의 전체 경로를 구한다.
            if (!logDirectoryPath.endsWith(File.separator))
                logFilePath = logDirectoryPath + File.separator + date + LOG_FILE_NAME;
            else
                logFilePath = logDirectoryPath + date + LOG_FILE_NAME;

            return logFilePath;
        }
        catch (Exception e) {
            Log.e(LOG_TAG, "[getLogFileAbsolutePath()] Exception : " + e.getMessage());
            return null;
        }
    }

    /**
     * 현재 시간을 구하는 함수
     * @return 현재 시간을 TIME_FORMAT 에 맞춰 반환한다.
     */
    private static String getNowTime() {
        Calendar calendar = Calendar.getInstance();
        String time = String.format(TIME_FORMAT, calendar.get(Calendar.MONTH) + 1,
                calendar.get(Calendar.DAY_OF_MONTH), calendar.get(Calendar.HOUR_OF_DAY),
                calendar.get(Calendar.MINUTE), calendar.get(Calendar.SECOND));
        return time;
    }

    /**
     * log_Tag 와 내용을 넣으면 해당 내용을 디버거에 출력하고, 파일에 쓰는 함수
     * @param log_Tag
     * @param msg
     */
    public static void writeLog(String log_Tag, String functionName, String msg) {
        try {
            // 일단 안드로이드 스튜디오에 로그를 찍고
            Log.e(log_Tag, msg);

            // 오늘 날짜를 구한다.
            Calendar calendar = Calendar.getInstance();
            String date = String.format(LOG_FILE_DATE_FORMAT, calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH) + 1, calendar.get(Calendar.DAY_OF_MONTH));

            // 파일로 해당 로그를 남긴다.
            FileOutputStream fileOutputStream = new FileOutputStream(getLogFileAbsolutePath(date), true);
            msg = getNowTime() + log_Tag + " | " + "[" + functionName + "] " + msg + ENDDING_WORD;
            fileOutputStream.write(msg.getBytes());
            fileOutputStream.close();
        }
        catch (Exception e) {
            Log.e(LOG_TAG, "[writeLog()] Exception : " + e.getMessage());
        }
    }

    public String readLog(String date) {
        try {
            Calendar calendar = Calendar.getInstance();
            SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd");
            calendar.setTime(simpleDateFormat.parse(date));
            date = String.format(LOG_FILE_DATE_FORMAT, calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH) + 1, calendar.get(Calendar.DAY_OF_MONTH));

            File readFile = new File(getLogFileAbsolutePath(date));

            int length = (int) readFile.length();
            byte[] bytes = new byte[length];
            FileInputStream fileInputStream = new FileInputStream(readFile);
            try {
                fileInputStream.read(bytes);
            }
            finally {
                fileInputStream.close();
            }
            return new String(bytes);
        }
        catch (Exception e) {
            Log.e(LOG_TAG, "[readLog()] Exception : " + e.getMessage());
            return "";
        }
    }
}
