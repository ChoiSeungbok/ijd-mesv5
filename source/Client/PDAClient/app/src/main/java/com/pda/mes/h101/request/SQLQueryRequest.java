package com.pda.mes.h101.request;

import android.content.Context;

import com.pda.mes.h101.H101Const;
import com.pda.mes.h101.Request;

/**
 * Created by sjs on 2020. 09. 24
 */

public class SQLQueryRequest extends Request {
    public SQLQueryRequest(Context context, String requestQuery) {
        super(context);
        addParam("_SERVICE_NAME", "S", H101Const.SQL_QUERY_REQUEST);
        addParam("_MODULE_NAME", "S", H101Const.MODULE_NAME_BAS);
        addParam("PROCSTEP", "C", "1");
        addParam("NEXT_ROW", "I4", "0");
        addParam("SQL", "S", requestQuery);
    }
}