package com.pda.mes.model;

public class WIPModel {

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

    // 품명
    private String name;

    // 위치
    private String location;

    // 불량코드
    private String lossCode;

    // 불량명
    private String lossDesc;

    // 오퍼
    private String oper;

    // 창고
    private String stock;

    // 작지
    private String workOrderId;

    // 품목 버전
    private String matVer;

    // 요청번호
    private String invReqNo;

    // 공장
    private String factory;

    // SHOP CODE
    private String shopCode;

    // 요청일자
    private String reqDate;

    // 입고일자
    private String recvDate;

    // status
    private String status;

    // vendorId
    private String vendorId;

    // vendorDesc
    private String vendorDesc;

    // 수입검사번호
    private String insNo;

    // 모델명
    private String modelNm;

    // 단위
    private String unit;

    // 요청 상세 상태
    private String reqDtlStatus;

    // 요청 상세 상태
    private String operCode;

    // 요청 상세 상태
    private String operDesc;

    // 수량
    private double quantityLeft;

    // 조정수량
    private double changeQuantityLeft;

    // 출고수량
    private double outQuantity;

    // 필요수량
    private double requiredQuantity;

    // 작업수량
    private double workingQuantity;

    private double invWhQty;

    private double moveQty;

    private double lossQty;

    public boolean isComplete = false;

    public boolean isProcess = false;

    public boolean kittingCheck = true;

    private double inQty;

    private double okQty;

    private double ngQty;

    public double qty = 0;

    public double ordQty = 0;

    public double reqQty = 0;

    public double regQty = 0;

    public double issueQty = 0;

    public double needQty = 0;

    public double scanQty = 0;

    public double overIssQty = 0;

    public double convQty = 0;

    public double poQty = 0;

    public double styleQty = 0;

    public double totalQty = 0;

    private String operKind;

    private String operGroup;

    private String invMethod = null;

    // dlv 시퀀스
    private int dlvSeq;

    private int seq;

    // 요청시퀀스
    private int reqSeq;

    // 요청타입
    private String reqType;

    // 박스갯수
    private int boxCount;

    // 애니메이션 효과
    private boolean isAnimate;

    // 선택여부
    private boolean isSelected = false;

    private boolean isChecked;

    private String checkPoID;

    private String checkStyle;

    private String userCode;

    private String resCode;

    private String resName;

    //비가동 시작시간
    private String downStartTime;

    //비가동 종료시간
    private String downEndTime;

    public boolean isChecked() {
        return isChecked;
    }

    public void setChecked(boolean checked) {
        isChecked = checked;
    }

    public double getOkQty() {
        return okQty;
    }

    public void setOkQty(double okQty) {
        this.okQty = okQty;
    }

    public double getNgQty() {
        return ngQty;
    }

    public void setNgQty(double ngQty) {
        this.ngQty = ngQty;
    }

    public int getDlvSeq() {
        return dlvSeq;
    }

    public void setDlvSeq(int dlvSeq) {
        this.dlvSeq = dlvSeq;
    }

    public int getSeq() {
        return seq;
    }

    public void setSeq(int seq) {
        this.seq = seq;
    }

    public String getInsNo() {
        return insNo;
    }

    public void setInsNo(String insNo) {
        this.insNo = insNo;
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

    public String getUnit() {
        return unit;
    }

    public void setUnit(String unit) {
        this.unit = unit;
    }

    public String getMatVer() {
        return matVer;
    }

    public void setMatVer(String matVer) {
        this.matVer = matVer;
    }

    public String getResCode() {
        return resCode;
    }

    public void setResCode(String resCode) {
        this.resCode = resCode;
    }

    public String getResName() {
        return resName;
    }

    public void setResName(String resName) {
        this.resName = resName;
    }

    public String getDownStartTime() {
        return downStartTime;
    }

    public void setDownStartTime(String downStartTime) {
        this.downStartTime = downStartTime;
    }

    public String getDownEndTime() {
        return downEndTime;
    }

    public void setDownEndTime(String downEndTime) {
        this.downEndTime = downEndTime;
    }

    public double getRequiredQuantity() {
        return requiredQuantity;
    }

    public void setRequiredQuantity(double requiredQuantity) { this.requiredQuantity = requiredQuantity; }

    public double getWorkingQuantity() {
        return workingQuantity;
    }

    public void setWorkingQuantity(double workingQuantity) { this.workingQuantity = workingQuantity; }

    public int getReqSeq() {
        return reqSeq;
    }

    public void setReqSeq(int reqSeq) {
        this.reqSeq = reqSeq;
    }

    public String getReqType() {
        return reqType;
    }

    public void setReqType(String reqType) {
        this.reqType = reqType;
    }

    public String getInvReqNo() {
        return invReqNo;
    }

    public void setInvReqNo(String invReqNo) {
        this.invReqNo = invReqNo;
    }

    public String getFactory() {
        return factory;
    }

    public void setFactory(String factory) {
        this.factory = factory;
    }

    public String getShopCode() {
        return shopCode;
    }

    public void setShopCode(String shopCode) {
        this.shopCode = shopCode;
    }

    public String getReqDate() {
        return reqDate;
    }

    public void setReqDate(String reqDate) {
        this.reqDate = reqDate;
    }

    public String getRecvDate() {
        return recvDate;
    }

    public void setRecvDate(String recvDate) {
        this.recvDate = recvDate;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public String getVendorId() {
        return vendorId;
    }

    public void setVendorId(String vendorId) {
        this.vendorId = vendorId;
    }

    public String getVendorDesc() {
        return vendorDesc;
    }

    public void setVendorDesc(String vendorDesc) {
        this.vendorDesc = vendorDesc;
    }

    public int getBoxCount() {
        return boxCount;
    }

    public void setBoxCount(int boxCount) {
        this.boxCount = boxCount;
    }

    public double getInvWhQty() {
        return invWhQty;
    }

    public void setInvWhQty(double invWhQty) {
        this.invWhQty = invWhQty;
    }

    public double getLossQty() {
        return lossQty;
    }

    public void setLossQty(double lossQty) {
        this.lossQty = lossQty;
    }

    public double getMoveQty() {
        return moveQty;
    }

    public void setMoveQty(double moveQty) {
        this.moveQty = moveQty;
    }

    public double getInQty() {
        return inQty;
    }

    public void setInQty(double inQty) {
        this.inQty = inQty;
    }

    public double getReqQty() {
        return reqQty;
    }

    public void setReqQty(double reqQty) {
        this.reqQty = reqQty;
    }

    public double getRegQty() {
        return regQty;
    }

    public void setRegQty(double regQty) {
        this.regQty = regQty;
    }

    public double getIssueQty() {
        return issueQty;
    }

    public void setIssueQty(double issueQty) {
        this.issueQty = issueQty;
    }

    public double getConvQty() {
        return convQty;
    }

    public void setConvQty(double convQty) {
        this.convQty = convQty;
    }

    public double getOutQuantity() {
        return outQuantity;
    }

    public void setOutQuantity(double outQuantity) {
        this.outQuantity = outQuantity;
    }

    public double getQty() {
        return qty;
    }

    public void setQty(double qty) {
        this.qty = qty;
    }

    public double getOrdQty() {
        return ordQty;
    }

    public void setOrdQty(double ordQty) {
        this.ordQty = ordQty;
    }

    public double getChangeQuantityLeft() {
        return changeQuantityLeft;
    }

    public void setChangeQuantityLeft(double changeQuantityLeft) { this.changeQuantityLeft = changeQuantityLeft; }

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

    public String getLossCode() {
        return lossCode;
    }

    public void setLossCode(String lossCode) {
        this.lossCode = lossCode;
    }

    public String getLossDesc() {
        return lossDesc;
    }

    public void setLossDesc(String lossDesc) {
        this.lossDesc = lossDesc;
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

    public String getWorkOrderId() {
        return workOrderId;
    }

    public void setWorkOrderId(String workOrderId) {
        this.workOrderId = workOrderId;
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

    public String getOperKind() {
        return operKind;
    }

    public void setOperKind(String operKind) {
        this.operKind = operKind;
    }

    public String getOperGroup() {
        return operGroup;
    }

    public void setOperGroup(String operGroup) { this.operGroup = operGroup; }

    public String getCheckPoID() { return checkPoID; }

    public void setCheckPoID(String checkPoID) { this.checkPoID = checkPoID; }

    public String getCheckStyle() { return checkStyle; }

    public void setCheckStyle(String checkStyle) { this.checkStyle = checkStyle; }

    public String getUserCode() { return userCode; }

    public void setUserCode(String userCode) { this.userCode = userCode; }

    public String getInvMethod() { return invMethod; }

    public void setInvMethod(String invMethod) { this.invMethod = invMethod; }

    public String getReqDtlStatus() {return reqDtlStatus; }

    public void setReqDtlStatus(String reqDtlStatus) { this.reqDtlStatus = reqDtlStatus; }

    public String getOperCode() {
        return operCode;
    }

    public void setOperCode(String operCode) {
        this.operCode = operCode;
    }

    public String getOperDesc() {
        return operDesc;
    }

    public void setOperDesc(String operDesc) {
        this.operDesc = operDesc;
    }
}
