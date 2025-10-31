package com.pda.mes.model;

import java.io.Serializable;

public class SHPModel implements Serializable {

    // 바코드
    private String barcode;

    // 품번
    private String matId;

    // 설명
    private String desc;

    // LOT번호
    private String lotId;

    // 스타일
    private String style;

    // 출하지시번호
    private String shipNo;

    // 품명
    private String name;

    // 위치
    private String location;

    // 오퍼
    private String oper;

    // 창고
    private String stock;

    // PO_ID
    private String poid;

    // SEQ
    private int seq;
    // vsm
    private String vsm;

    // 품목버전
    private String matVer;

    // 포장지시번호
    private String packOrderId;

    // 포장라인번호
    private int packLineNo;

    // 공장
    private String factory;

    // status
    private String status;

    // 모델명
    private String modelNm;

    // 단위
    private String unit;

    // 수량
    private double quantityLeft;

    private double inQty;

    public double qty = 0;

    public double reqQty = 0;

    //등록수량
    public double regQty = 0;

    public double totalQty = 0;

    // 애니메이션 효과
    private boolean isAnimate;

    // 선택여부
    private boolean isSelected = false;

    private boolean isChecked;

    //대박스 ID
    private String finalBoxId;

    //중박스 ID
    private String boxId;

    //출하 LOT(보통 PACK LOT)
    private String shipLodId;

    //공정 LOT
    private String processLotId;

    //출하지시일자
    private String shipOrdDate;

    //고객사
    private String customerId;

    //납품사
    private String deliveryId;

    //사업부
    private String area;

    //고객사명
    private String customerName;

    //납품업체명
    private String deliveryName;

    //납품업체명
    private String labelName;

    public boolean isChecked() {
        return isChecked;
    }

    public void setChecked(boolean checked) {
        isChecked = checked;
    }

    public String getModelNm() {
        return modelNm;
    }

    public void setModelNm(String modelNm) {
        this.modelNm = modelNm;
    }

    public String getLotId() {
        return lotId;
    }

    public void setLotId(String lotId) {
        this.lotId = lotId;
    }

    public String getProcessLotId() {
        return processLotId;
    }

    public void setProcessLotId(String processLotId) {
        this.processLotId = processLotId;
    }

    public String getShipLotId() {
        return shipLodId;
    }

    public void setShipLotId(String shipLodId) {
        this.shipLodId = shipLodId;
    }

    public String getBoxId() {
        return boxId;
    }

    public void setBoxId(String boxId) {
        this.boxId = boxId;
    }

    public String getFinalBoxId() {
        return finalBoxId;
    }

    public void setFinalBoxId(String finalBoxId) {
        this.finalBoxId = finalBoxId;
    }

    public String getUnit() {
        return unit;
    }

    public void setUnit(String unit) {
        this.unit = unit;
    }

    public String getVsm() {
        return vsm;
    }

    public void setVsm(String vsm) {
        this.vsm = vsm;
    }

    public String getMatVer() {
        return matVer;
    }

    public void setMatVer(String matVer) {
        this.matVer = matVer;
    }

    public String getPackOrderId() {
        return packOrderId;
    }

    public void setPackOrderId(String packOrderId) {
        this.packOrderId = packOrderId;
    }

    public int getPackLineNo() {
        return packLineNo;
    }

    public void setPackLineNo(int packLineNo) {
        this.packLineNo = packLineNo;
    }

    public String getShipNo() {
        return shipNo;
    }

    public void setShipNo(String shipNo) {
        this.shipNo = shipNo;
    }

    public String getShipOrdDate() {
        return shipOrdDate;
    }

    public void setShipOrdDate(String shipOrdDate) {
        this.shipOrdDate = shipOrdDate;
    }

    public String getArea() {
        return area;
    }

    public void setArea(String area) {
        this.area = area;
    }

    public String getCustomerId() {
        return customerId;
    }

    public void setCustomerId(String customerId) {
        this.customerId = customerId;
    }

    public String getCustomerName() {
        return customerName;
    }

    public void setCustomerName(String customerName) {
        this.customerName = customerName;
    }

    public String getDeliveryName() {
        return deliveryName;
    }

    public void setDeliveryName(String deliveryName) {
        this.deliveryName = deliveryName;
    }

    public String getDeliveryId() {
        return deliveryId;
    }

    public void setDeliveryId(String deliveryId) {
        this.deliveryId = deliveryId;
    }

    public String getFactory() {
        return factory;
    }

    public void setFactory(String factory) {
        this.factory = factory;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public double getInQty() {
        return inQty;
    }

    public void setInQty(double inQty) {
        this.inQty = inQty;
    }

    public double getRegQty() {
        return regQty;
    }

    public void setRegQty(double regQty) {
        this.regQty = regQty;
    }

    public double getReqQty() {
        return reqQty;
    }

    public double getQty() {
        return qty;
    }

    public void setQty(double qty) {
        this.qty = qty;
    }

    public String getPoid() {
        return poid;
    }

    public void setPoid(String poid) {
        this.poid = poid;
    }

    public int getSeq() {
        return seq;
    }

    public void setSeq(int seq) {
        this.seq = seq;
    }

    public boolean isSelected() {
        return isSelected;
    }

    public void setSelected(boolean selected) {
        isSelected = selected;
    }

    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

    public String getOper() {
        return oper;
    }

    public void setOper(String oper) {
        this.oper = oper;
    }

    public String getStock() {
        return stock;
    }

    public void setStock(String stock) {
        this.stock = stock;
    }

    public boolean isAnimate() {
        return isAnimate;
    }

    public void setAnimate(boolean animate) {
        isAnimate = animate;
    }

    public String getMatId() {
        return matId;
    }

    public void setDesc(String desc) {
        this.desc = desc;
    }

    public String getDesc() {
        return desc;
    }

    public void setMatId(String matId) {
        this.matId = matId;
    }

    public String getStyle() {
        if(style == null)
            return "";
        else
            return style;
    }

    public void setStyle(String style) {
        this.style = style;
    }

    public String getBarcode() {
        return barcode;
    }

    public void setBarcode(String Pcard) {
        this.barcode = Pcard;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getQuantityLeft() {
        return quantityLeft;
    }

    public void setQuantityLeft(double quantityLeft) {
        this.quantityLeft = quantityLeft;
    }

    public String getLabelName() {
        return labelName;
    }

    public void setLabelName(String labelName) {
        this.labelName = labelName;
    }
}

