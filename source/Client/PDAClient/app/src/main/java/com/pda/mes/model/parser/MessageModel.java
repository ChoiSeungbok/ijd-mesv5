package com.pda.mes.model.parser;

import com.google.gson.annotations.SerializedName;

public class MessageModel {

    @SerializedName("@Version")
    private String version;

    @SerializedName("@Name")
    private String name;

    private DataModel B;

    public void setVersion(String version) {
        this.version = version;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setB(DataModel b) {
        B = b;
    }

    public String getVersion() {
        return version;
    }

    public String getName() {
        return name;
    }

    public DataModel getData() {
        return B;
    }
}
