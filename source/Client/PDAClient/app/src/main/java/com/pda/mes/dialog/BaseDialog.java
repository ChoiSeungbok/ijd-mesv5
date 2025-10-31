package com.pda.mes.dialog;

import android.app.Dialog;
import android.content.Context;

import com.pda.mes.R;

/**
 * 스타일 커스텀을 위한 커스텀 베이스 다이얼로그
 */
public abstract class BaseDialog extends Dialog {
	
	public BaseDialog(Context context) {
		super(context, R.style.DimDialog);
		setCanceledOnTouchOutside(false);
		setCancelable(false);
	}
}
