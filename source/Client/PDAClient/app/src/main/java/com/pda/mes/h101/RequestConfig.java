package com.pda.mes.h101;

public class RequestConfig {
    private static class SetupHolder { public static final RequestConfig INSTANCE = new RequestConfig(); }
    public static RequestConfig getInstance () { return RequestConfig.SetupHolder.INSTANCE; }
    RequestConfig() { }

    public boolean isRequest = false;
    public boolean isTran = false;

    public void releaseRequest() {
        this.isRequest = false;
        this.isTran = false;
    }
}
