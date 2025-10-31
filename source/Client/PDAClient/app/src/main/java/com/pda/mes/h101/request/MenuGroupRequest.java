package com.pda.mes.h101.request;

import android.content.Context;

import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;

/**
 * Created by sjs on 2020. 09. 24
 */

public class MenuGroupRequest extends Request {

    public MenuGroupRequest(Context context) {
        super(context);
        addParam("_SERVICE_NAME", "S", H101Const.MENU_GROUP);
        addParam("_MODULE_NAME", "S", H101Const.MODULE_NAME_SEC);
        addParam("PROCSTEP", "C", "1");
        addParam("PROGRAM_ID", "S", H101Const.PROGRAM_ID);
        addParam("ENCRYPTED_PASSWORD_FLAG", "C");
    }
}
