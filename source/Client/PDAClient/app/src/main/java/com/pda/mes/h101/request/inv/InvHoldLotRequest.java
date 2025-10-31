package com.pda.mes.h101.request.inv;

import android.content.Context;

import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;

/**
 * Created by sjs on 2020. 09. 23
 */

public class InvHoldLotRequest extends Request {

    public InvHoldLotRequest(Context context) {
        super(context);
        addParam("_SERVICE_NAME", "S", H101Const.CUS_INV_HOLD_LOT);
        addParam("_MODULE_NAME", "S", H101Const.MODULE_NAME_CUS_INV);
        addParam("PROGRAM_ID", "S", H101Const.PROGRAM_ID);
    }
}