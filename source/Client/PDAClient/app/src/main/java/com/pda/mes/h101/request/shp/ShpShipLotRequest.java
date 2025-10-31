package com.pda.mes.h101.request.shp;

import android.content.Context;

import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;

/**
 * Created by sjs on 2020. 9. 23
 */

public class ShpShipLotRequest extends Request {

    public ShpShipLotRequest(Context context) {
        super(context);
        addParam("_SERVICE_NAME", "S", H101Const.CUS_SHP_SHIP_LOT);
        addParam("_MODULE_NAME", "S", H101Const.MODULE_NAME_CUS_SHP);
        addParam("PROGRAM_ID", "S", H101Const.PROGRAM_ID);
    }
}