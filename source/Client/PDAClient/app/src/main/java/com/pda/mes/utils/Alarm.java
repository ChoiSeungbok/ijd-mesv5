package com.pda.mes.utils;

import android.content.Context;
import android.media.AudioManager;
import android.media.SoundPool;
import android.os.Vibrator;

import com.pda.mes.App;
import com.pda.mes.AppContext;
import com.pda.mes.R;
import com.pda.mes.manager.SessionManager;

import static android.content.Context.AUDIO_SERVICE;

public class Alarm {
    private static class SetupHolder { public static final Alarm INSTANCE = new Alarm(); }
    public static Alarm getInstance () { return Alarm.SetupHolder.INSTANCE; }
    Alarm() { };

    private SoundPool soundPool = null;
    private int soundID = 0;

    public void startAlarm() {
        if(soundPool == null)
            soundPool = new SoundPool(1, AudioManager.STREAM_MUSIC, 0);

        if(soundID == 0)
            soundPool.load(AppContext.getAppContext(), R.raw.beep, 1);

        // 진동을 일으킨다.
        final Vibrator vibrator = (Vibrator)AppContext.getAppContext().getSystemService(AppContext.getAppContext().VIBRATOR_SERVICE); // 시스템에서 진동 서비스를 받아와야 함
        long[] pattern = {0,500,300,500,300,500}; // 0초 대기하고 0.5초 진동 0.3초 대기하고 0.5초 진동 0.3초 대기 0.5초 진동 (홀수 인덱스 : 대기, 짝수 인덱스 진동)
        vibrator.vibrate(pattern, -1); // 진동 시작 repeat -1 이면 진동을 반복하지 않음

        AudioManager audioManager;
        audioManager = (AudioManager)AppContext.getAppContext().getSystemService(AUDIO_SERVICE);
        audioManager.playSoundEffect(AudioManager.FX_KEYPRESS_STANDARD);

        // 사운드 재생
        if(!SessionManager.getUserId(AppContext.getAppContext()).equals("MESTEST"))
            soundPool.play(soundID, 1, 1,0, 3, 1.0f);
    }
}
