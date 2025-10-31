package com.pda.mes.model;

public class DropDownModel {

    private String id;
    private String name;
    private String desc;
    private String grp1;
    private String grp2;
    private String grp3;
    private boolean isSelected;
    public int index;

    public DropDownModel() {
    }

    public String getDesc() {
        return desc;
    }

    public void setDesc(String desc) {
        this.desc = desc;
    }

    public boolean isSelected() {
        return isSelected;
    }

    public void setSelected(boolean selected) {
        isSelected = selected;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getGrp1() {
        return grp1;
    }

    public void setGrp1(String grp1) {
        this.grp1 = grp1;
    }

    public String getGrp2() {
        return grp2;
    }

    public void setGrp2(String grp2) {
        this.grp2 = grp2;
    }

    public String getGrp3() {
        return grp3;
    }

    public void setGrp3(String grp3) {
        this.grp3 = grp3;
    }
}
