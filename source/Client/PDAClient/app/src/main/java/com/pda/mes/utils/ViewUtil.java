package com.pda.mes.utils;

import android.graphics.Color;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

public class ViewUtil {
    public static void setSelectView(View view, boolean check) {
        // 일단 배경은 뷰그룹이던 뷰이던 모두 변경한다.
        if(check)
            view.setBackgroundColor(Color.parseColor("#FC778A"));
        else
            view.setBackgroundColor(Color.WHITE);

        ViewGroup viewGroup;

        // 뷰를 뷰그룹으로 전환
        try {
            viewGroup = (ViewGroup) view;
        }
        catch (Exception e) {
            return; // 해당 뷰가 뷰그룹으로 전환이 안된다면 그건 레이아웃 뷰가 아니므로 return 한다.
        }

        // 뷰그룹들을 순회하면서
        for(int i = 0 ; i < viewGroup.getChildCount() ; i++) {
            try {
                // ChildView 를 ViewGroup 로 전환해본다.
                ViewGroup childViewGroup = (ViewGroup) viewGroup.getChildAt(i);
                // 만약 ViewGroup 로 전환되면 해당 함수를 다시 호출한다. // 찾으려고 하는건 View 이지 ViewGroup 가 아니다
                setSelectView(childViewGroup, check);
            }
            catch (Exception e) {
                // 만약 전환이 안되면 그건 일반 View 이다.
                try {
                    // TextView 로 변환해서 변환 되는 것들 만 글자색상을 변경해준다.
                    TextView textView = (TextView) viewGroup.getChildAt(i);
                    if(check)
                        textView.setTextColor(Color.WHITE);
                    else
                        textView.setTextColor(Color.BLACK);
                }
                catch (Exception ex) {
                    continue;
                }
            }
        }
    }

    public static void setProcessView(View view, boolean check) {
        // 일단 배경은 뷰그룹이던 뷰이던 모두 변경한다.
        if(check)
            view.setBackgroundColor(Color.LTGRAY);
        else
            view.setBackgroundColor(Color.WHITE);

        ViewGroup viewGroup;

        // 뷰를 뷰그룹으로 전환
        try {
            viewGroup = (ViewGroup) view;
        }
        catch (Exception e) {
            return; // 해당 뷰가 뷰그룹으로 전환이 안된다면 그건 레이아웃 뷰가 아니므로 return 한다.
        }

        // 뷰그룹들을 순회하면서
        for(int i = 0 ; i < viewGroup.getChildCount() ; i++) {
            try {
                // ChildView 를 ViewGroup 로 전환해본다.
                ViewGroup childViewGroup = (ViewGroup) viewGroup.getChildAt(i);
                // 만약 ViewGroup 로 전환되면 해당 함수를 다시 호출한다. // 찾으려고 하는건 View 이지 ViewGroup 가 아니다
                setProcessView(childViewGroup, check);
            }
            catch (Exception e) {
                // 만약 전환이 안되면 그건 일반 View 이다.
                try {
                    // TextView 로 변환해서 변환 되는 것들 만 글자색상을 변경해준다.
                    TextView textView = (TextView) viewGroup.getChildAt(i);
                    if(check)
                        textView.setTextColor(Color.WHITE);
                    else
                        textView.setTextColor(Color.BLACK);
                }
                catch (Exception ex) {
                    continue;
                }
            }
        }
    }

    public static void setCompleteView(View view, boolean check) {
        // 일단 배경은 뷰그룹이던 뷰이던 모두 변경한다.
        if(check)
            view.setBackgroundColor(Color.GRAY);
        else
            view.setBackgroundColor(Color.WHITE);

        ViewGroup viewGroup;

        // 뷰를 뷰그룹으로 전환
        try {
            viewGroup = (ViewGroup) view;
        }
        catch (Exception e) {
            return; // 해당 뷰가 뷰그룹으로 전환이 안된다면 그건 레이아웃 뷰가 아니므로 return 한다.
        }

        // 뷰그룹들을 순회하면서
        for(int i = 0 ; i < viewGroup.getChildCount() ; i++) {
            try {
                // ChildView 를 ViewGroup 로 전환해본다.
                ViewGroup childViewGroup = (ViewGroup) viewGroup.getChildAt(i);
                // 만약 ViewGroup 로 전환되면 해당 함수를 다시 호출한다. // 찾으려고 하는건 View 이지 ViewGroup 가 아니다
                setProcessView(childViewGroup, check);
            }
            catch (Exception e) {
                // 만약 전환이 안되면 그건 일반 View 이다.
                try {
                    // TextView 로 변환해서 변환 되는 것들 만 글자색상을 변경해준다.
                    TextView textView = (TextView) viewGroup.getChildAt(i);
                    if(check)
                        textView.setTextColor(Color.WHITE);
                    else
                        textView.setTextColor(Color.BLACK);
                }
                catch (Exception ex) {
                    continue;
                }
            }
        }
    }
}
