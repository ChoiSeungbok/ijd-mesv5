package com.pda.mes.dialog;

import android.content.Context;
import android.view.View;
import android.view.Window;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.pda.mes.R;
import com.pda.mes.activity.BaseActivity;

/**
 * 입력 다이얼로그
 */
public class InputServerIpDialog extends BaseDialog implements View.OnClickListener {

    private OnInputMessageListener listener;

    public InputServerIpDialog(Context context) {
        super(context);
        View view = View.inflate(context, R.layout.dialog_input_server_ip, null);
        requestWindowFeature(Window.FEATURE_NO_TITLE);

        setContentView(view);

        init();
    }

    private void init() {
        findViewById(R.id.closeButton).setOnClickListener(this);
        findViewById(R.id.doneButton).setOnClickListener(this);
    }

    public void setDialog(String title, String hint, String text) {
        ((TextView)findViewById(R.id.dialogTitleLabel)).setText(title);
        ((EditText)findViewById(R.id.dialogInputLabel)).setHint(hint);
        ((EditText)findViewById(R.id.dialogInputLabel)).setText(text);
        ((EditText)findViewById(R.id.dialogInputLabel)).setSelection(((EditText)findViewById(R.id.dialogInputLabel)).getText().toString().trim().length());
    }

    private String getInputMessage() {

        findViewById(R.id.dialogInputLabel).clearFocus();

        String ip = ((EditText)findViewById(R.id.dialogInputLabel)).getText().toString().trim();

        return ip;
    }

    @Override
    public void onClick(View view) {

        if(view.getId() == R.id.doneButton) {

            String value = getInputMessage();

            if(null == value || value.isEmpty()) {
                Toast.makeText(getContext(), "값을 입력해주세요", Toast.LENGTH_LONG).show();
                return;
            }

            listener.onClickDone(value);
        }

        dismiss();
    }

    public void setOnInputMessageListener(OnInputMessageListener listener) {
        this.listener = listener;
    }

    public interface OnInputMessageListener {
        void onClickDone(String value);
    }
}
