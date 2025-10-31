package com.pda.mes.h101.request.prod;

import android.content.Context;

import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;

/**
 * Created by sjs on 2020. 09. 24
 */

public class WipViewMaterialListRequest extends Request {

    public WipViewMaterialListRequest(Context context) {
        super(context);
        addParam("_SERVICE_NAME", "S", H101Const.CUS_WIP_VIEW_MATERIAL_LIST);
        addParam("_MODULE_NAME", "S", H101Const.MODULE_NAME_CUS_WIP);
        addParam("PROGRAM_ID", "S", H101Const.PROGRAM_ID);
    }
}