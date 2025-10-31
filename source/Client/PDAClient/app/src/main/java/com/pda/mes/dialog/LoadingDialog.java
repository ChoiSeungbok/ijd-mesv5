package com.pda.mes.dialog;

import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.view.Window;

import com.pda.mes.R;

/**
 * 화면 로딩 다이얼로그
 */
public class LoadingDialog extends BaseDialog {

	public LoadingDialog(Context context) {
        super(context);
		View view = View.inflate(context, R.layout.dialog_loading, null);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        setCanceledOnTouchOutside(false);
		setContentView(view);
	}
}
