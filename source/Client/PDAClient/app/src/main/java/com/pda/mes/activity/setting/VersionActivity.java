package com.pda.mes.activity.setting;

import android.Manifest;
import android.app.DownloadManager;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.content.res.ColorStateList;
import android.database.Cursor;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.support.annotation.NonNull;
import android.support.v4.content.FileProvider;
import android.view.View;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

import com.pda.mes.BuildConfig;
import com.pda.mes.R;
import com.pda.mes.activity.ToolbarActivity;
import com.pda.mes.h101.H101Const;
import com.pda.mes.manager.AppSettingManager;
import com.pda.mes.utils.LogUtil;
import com.pda.mes.utils.VersionCheckUtil;

import java.io.File;
import java.text.DecimalFormat;

public class VersionActivity extends ToolbarActivity {
    public static final String TAG = VersionActivity.class.getSimpleName();
    private final int MY_PERMISSION_REQUEST_READ_CONTACTS = 0x02;
    private final String FILE_PATH = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS) + File.separator + "MESPDA";
    private final String FILE_NAME = "MESPDAClient_v%s.apk";
    private String appVersion;
    private String serverVersion;
    private String downloadUrl;
    private long refId;
    private DownloadManager downloadManager;
    private ProgressBar progressBar;
    private File downloadFile;
    private boolean isDownloadComplete;
    private boolean forceUpdate;

    public void onClickDownload(View view) {
        if(isDownloadComplete)
            installPackage(); // 설치하기
        else
            checkPermission(); // 업데이트하기
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        try {
            switch (requestCode) {
                case MY_PERMISSION_REQUEST_READ_CONTACTS:
                    if (grantResults[0] == PackageManager.PERMISSION_GRANTED)
                        enqueueDownload();
                    else
                        showDialog(getString(R.string.alert_message_write_file_permission));
                    break;
            }
        }
        catch (Exception e) {
            LogUtil.writeLog(TAG, "onRequestPermissionsResult()", e.getMessage());
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_version, TOOLBAR_TYPE_MODAL, true);
        setTitleLabel(getString(R.string.version_info));

        try {
            if (getIntent().hasExtra("forceUpdate"))
                forceUpdate = true;

            downloadManager = (DownloadManager) getSystemService(Context.DOWNLOAD_SERVICE);
            registerReceiver(onComplete, new IntentFilter(DownloadManager.ACTION_DOWNLOAD_COMPLETE));
            appVersion = VersionCheckUtil.getAppVersion(this);

            serverVersion = getIntent().getStringExtra("serverVersion");

            downloadUrl = H101Const.getDownloadUrl(AppSettingManager.getServerType(this), serverVersion);
            progressBar = findViewById(R.id.progressBar);
            progressBar.setVisibility(View.GONE);
            progressBar.setProgressTintList(ColorStateList.valueOf(getColor(R.color.colorPrimary)));

            if (!new File(FILE_PATH).exists())
                new File(FILE_PATH).mkdirs();

            downloadFile = new File(FILE_PATH + File.separator + String.format(FILE_NAME, serverVersion));

            ((TextView) findViewById(R.id.appVersion)).setText(getString(R.string.current_version) + " : v" + appVersion);
            ((TextView) findViewById(R.id.newVersion)).setText(getString(R.string.new_version) + " : v" + serverVersion);

            File[] files = new File(FILE_PATH).listFiles();

            if (null != files && files.length > 0) {
                for (File file : files) {
                    if (!file.equals(downloadFile))
                        file.delete();     // 최신 업데이트 apk 파일이 아니면 삭제
                }
            }
        }
        catch (Exception e) {
            LogUtil.writeLog(TAG, "onCreate()", e.getMessage());
        }
    }

    @Override
    protected void onResume() {
        super.onResume();

        try {
            if (VersionCheckUtil.checkVersion(appVersion, serverVersion))
                setUpdateView(); // 업데이트 필요
            else {
                // 최신버전
                findViewById(R.id.executeButton).setEnabled(false);
                findViewById(R.id.newVersion).setVisibility(View.GONE);
                progressBar.setVisibility(View.GONE);
                findViewById(R.id.descLabel).setVisibility(View.GONE);
                ((TextView) findViewById(R.id.executeButton)).setText(getString(R.string.latest_version));
            }
        }
        catch (Exception e) {
            LogUtil.writeLog(TAG, "onCreate()", e.getMessage());
        }
    }

    private void installPackage() {
        try {
            Uri uri = FileProvider.getUriForFile(this, BuildConfig.APPLICATION_ID + ".provider", new File(FILE_PATH + File.separator + String.format(FILE_NAME, serverVersion)));

            Intent intent = new Intent(Intent.ACTION_INSTALL_PACKAGE);
            intent.setData(uri);
            intent.setFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION);
            startActivity(intent);
        }
        catch (Exception e) {
            LogUtil.writeLog(TAG, "onCreate()", e.getMessage());
        }
    }

    private void setUpdateView() {
        try {
            if (downloadFile.exists())
                isDownloadComplete = true; // 다운로드된 최신 apk 파일 있음
            else
                isDownloadComplete = false; // 없음

            if (isDownloadComplete) {
                // 설치하기
                findViewById(R.id.executeButton).setEnabled(true);
                setDesc(getString(R.string.view_message_download_complete));
                progressBar.setVisibility(View.GONE);
                ((TextView) findViewById(R.id.executeButton)).setText(getString(R.string.install));

                if (forceUpdate) {
                    new Handler().postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            installPackage();
                            forceUpdate = false;
                        }
                    }, 1000);
                }
            }
            else {
                // 업데이트하기
                ((TextView) findViewById(R.id.executeButton)).setText(getString(R.string.update));
                setDesc(getString(R.string.view_message_click_update));

                if (forceUpdate) {
                    new Handler().postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            checkPermission();
                            forceUpdate = false;
                        }
                    }, 1000);
                }
            }
        }
        catch (Exception e) {
            LogUtil.writeLog(TAG, "setUpdateView()", e.getMessage());
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        try {
            unregisterReceiver(onComplete);
        }
        catch (Exception e) {
            LogUtil.writeLog(TAG, "onDestroy()", e.getMessage());
        }
    }

    private void setDesc(String desc) {
        ((TextView)findViewById(R.id.descLabel)).setText(desc);
    }

    private String readableFileSize(long size) {
        try {
            if (size <= 0) return "0";
            final String[] units = new String[]{"B", "kB", "MB", "GB", "TB"};
            int digitGroups = (int) (Math.log10(size) / Math.log10(1024));
            return new DecimalFormat("#,##0.#").format(size / Math.pow(1024, digitGroups)) + " " + units[digitGroups];
        }
        catch (Exception e) {
            LogUtil.writeLog(TAG, "readableFileSize()", e.getMessage());
            return "0";
        }
    }

    private void enqueueDownload() {
        try {
            findViewById(R.id.executeButton).setEnabled(false);

            DownloadManager.Request request = new DownloadManager.Request(Uri.parse(downloadUrl));
            request.setAllowedNetworkTypes(DownloadManager.Request.NETWORK_WIFI | DownloadManager.Request.NETWORK_MOBILE);
            request.setAllowedOverRoaming(false);
            request.setTitle("MESPDA Update");
            request.setDescription("Download apk");
            request.setVisibleInDownloadsUi(true);
            request.allowScanningByMediaScanner();
            request.setNotificationVisibility(DownloadManager.Request.VISIBILITY_VISIBLE);
            request.setDestinationInExternalPublicDir(Environment.DIRECTORY_DOWNLOADS, File.separator + "MESPDA" + File.separator + String.format(FILE_NAME, serverVersion));

            progressBar.setVisibility(View.VISIBLE);
            refId = downloadManager.enqueue(request);

            new Thread(new Runnable() {
                @Override
                public void run() {
                    boolean downloading = true;

                    while (downloading) {
                        DownloadManager.Query q = new DownloadManager.Query();
                        q.setFilterById(refId);

                        Cursor cursor = downloadManager.query(q);
                        cursor.moveToFirst();
                        int bytes_downloaded = cursor.getInt(cursor.getColumnIndex(DownloadManager.COLUMN_BYTES_DOWNLOADED_SO_FAR));
                        int bytes_total = cursor.getInt(cursor.getColumnIndex(DownloadManager.COLUMN_TOTAL_SIZE_BYTES));

                        if (cursor.getInt(cursor.getColumnIndex(DownloadManager.COLUMN_STATUS)) == DownloadManager.STATUS_SUCCESSFUL)
                            downloading = false;

                        final int dl_progress = (int) ((double) bytes_downloaded / (double) bytes_total * 100f);
                        final long final_bytes_downloaded = bytes_downloaded;
                        final long final_bytes_total = bytes_total;

                        runOnUiThread(new Runnable() {

                            @Override
                            public void run() {
                                if (final_bytes_downloaded == final_bytes_total) {
                                    ((TextView) findViewById(R.id.executeButton)).setText(getString(R.string.install));
                                    setDesc(getString(R.string.view_message_download_complete));
                                    installPackage();
                                }
                                else
                                    setDesc(readableFileSize(final_bytes_downloaded) + " / " + readableFileSize(final_bytes_total));

                                ((TextView) findViewById(R.id.executeButton)).setText(getString(R.string.common_word_download));
                                progressBar.setProgress(dl_progress);
                            }
                        });
                        cursor.close();
                    }
                }
            }).start();
        }
        catch (Exception e) {
            LogUtil.writeLog(TAG, "enqueueDownload()", e.getMessage());
        }
    }

    private void checkPermission() {
        try {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
                if (checkSelfPermission(Manifest.permission.READ_CONTACTS) != PackageManager.PERMISSION_GRANTED) {
                    if (shouldShowRequestPermissionRationale(Manifest.permission.WRITE_EXTERNAL_STORAGE))
                        Toast.makeText(this, getString(R.string.alert_message_write_file_permission), Toast.LENGTH_LONG).show();

                    requestPermissions(new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE}, MY_PERMISSION_REQUEST_READ_CONTACTS);
                }
                else
                    enqueueDownload();
            }
            else
                enqueueDownload();
        }
        catch (Exception e) {
            LogUtil.writeLog(TAG, "checkPermission()", e.getMessage());
        }
    }

    private BroadcastReceiver onComplete = new BroadcastReceiver() {
        public void onReceive(Context ctxt, Intent intent) {
            try {
                long referenceId = intent.getLongExtra(DownloadManager.EXTRA_DOWNLOAD_ID, -1);
                if (refId == referenceId)
                    setUpdateView();
            }
            catch (Exception e) {
                LogUtil.writeLog(TAG, "BroadcastReceiver : onReceive()", e.getMessage());
            }
        }
    };
}
