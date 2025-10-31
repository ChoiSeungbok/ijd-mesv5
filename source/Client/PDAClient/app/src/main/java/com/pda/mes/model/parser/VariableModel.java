package com.pda.mes.model.parser;

import com.google.gson.annotations.SerializedName;

public class VariableModel {

    @SerializedName("@N")
    private String n;

    @SerializedName("@T")
    private String t;

    @SerializedName("@E")
    private String e;

    @SerializedName("$")
    private String description;

    public String getName() {
        return n;
    }

    public String getT() {
        return t;
    }

    public String getE() {
        return e;
    }

    public String getDescription() {
        return description;
    }

    public void setN(String n) {
        this.n = n;
    }

    public void setT(String t) {
        this.t = t;
    }

    public void setE(String e) {
        this.e = e;
    }

    public void setDescription(String description) {
        this.description = description;
    }
}
