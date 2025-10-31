package com.pda.mes.h101.request.sec;

import android.content.Context;

import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;

/**
 * Created on 2021. 01. 20..
 */
public class SecUpdateFavorites extends Request {
    public SecUpdateFavorites(Context context) {
        super(context);
        addParam("_SERVICE_NAME", "S", H101Const.SEC_UPDATE_FAVORITES);
        addParam("_MODULE_NAME", "S", H101Const.MODULE_NAME_SEC);
        addParam("PROGRAM_ID", "S", H101Const.PROGRAM_ID);
    }
}
