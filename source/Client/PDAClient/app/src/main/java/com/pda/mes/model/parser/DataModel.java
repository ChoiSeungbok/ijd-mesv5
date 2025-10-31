package com.pda.mes.model.parser;

import com.google.gson.annotations.SerializedName;

import java.util.List;

public class DataModel {

    @SerializedName("@N")
    private String N;

    private List<VariableModel> D;

    private List<DataModel> L;

    public void setL(List<DataModel> l) {
        L = l;
    }

    public void setD(List<VariableModel> d) {
        D = d;
    }

    public String getN() {
        return N;
    }

    public void setN(String n) {
        N = n;
    }

    public List<VariableModel> getData() {
        return D;
    }

    public List<DataModel> getList() {
        return L;
    }
}
