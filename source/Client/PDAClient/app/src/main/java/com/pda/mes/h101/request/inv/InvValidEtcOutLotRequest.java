package com.pda.mes.h101.request.inv;

import android.content.Context;

import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;

/**
 * Created by sjs on 2020. 09. 24
 */

public class InvValidEtcOutLotRequest extends Request {

    public InvValidEtcOutLotRequest(Context context) {
        super(context);
        addParam("_SERVICE_NAME", "S", H101Const.CUS_INV_VALIDATION_ETC_OUT_LOT);
        addParam("_MODULE_NAME", "S", H101Const.MODULE_NAME_CUS_INV);
        addParam("PROGRAM_ID", "S", H101Const.PROGRAM_ID);
    }
}