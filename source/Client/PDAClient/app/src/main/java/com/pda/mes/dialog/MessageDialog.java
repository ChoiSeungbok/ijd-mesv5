package com.pda.mes.dialog;

import android.content.Context;
import android.view.View;
import android.view.Window;
import android.widget.TextView;

import com.pda.mes.R;

/**
 * 컨펌 다이얼로그
 */
public class MessageDialog extends BaseDialog implements View.OnClickListener {

	private Runnable mDoneRunnable;

	public MessageDialog(Context context) {
        super(context);
		View view = View.inflate(context, R.layout.dialog_message, null);
        requestWindowFeature(Window.FEATURE_NO_TITLE);

		setContentView(view);

		init();
	}

	private void init() {
		findViewById(R.id.doneButton).setOnClickListener(this);
	}

	public void setDialog(String message) {
		((TextView)findViewById(R.id.dialogMessageLabel)).setText(message);
	}

	public void setDialog(String message, Runnable runnable) {
		((TextView)findViewById(R.id.dialogMessageLabel)).setText(message);
		mDoneRunnable = runnable;
	}

	@Override
	public void onClick(View view) {

		if(view.getId() == R.id.doneButton) {
			if(null != mDoneRunnable) {
				mDoneRunnable.run();
			}
		}

		dismiss();
	}
}
