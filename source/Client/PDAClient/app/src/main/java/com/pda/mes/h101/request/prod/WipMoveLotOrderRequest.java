package com.pda.mes.h101.request.prod;

import android.content.Context;

import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;

public class WipMoveLotOrderRequest extends Request {
    public WipMoveLotOrderRequest(Context context) {
        super(context);
        addParam("_SERVICE_NAME", "S", H101Const.CUS_WIP_MOVE_LOT_ORDER);
        addParam("_MODULE_NAME", "S", H101Const.MODULE_NAME_CUS_WIP);
        addParam("PROGRAM_ID", "S", H101Const.PROGRAM_ID);
    }
}
