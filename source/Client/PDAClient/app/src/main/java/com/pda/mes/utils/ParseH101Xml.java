package com.pda.mes.utils;

import com.pda.mes.h101.H101Const;
import com.pda.mes.model.parser.DataModel;
import com.pda.mes.model.parser.VariableModel;
import com.pda.mes.model.parser.MessageModel;
import com.stanfy.gsonxml.GsonXml;
import com.stanfy.gsonxml.GsonXmlBuilder;
import com.stanfy.gsonxml.XmlParserCreator;

import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserFactory;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by sjs on 2020. 09. 24
 */
public class ParseH101Xml {

    public static String getValue(MessageModel model, String key) {

        String reValue = null;

        if(null != model.getData() && null != model.getData().getData() && !model.getData().getData().isEmpty()) {
            for(VariableModel variableModel : model.getData().getData()) {
                if(variableModel.getName().equals(key)) {
                    reValue = variableModel.getDescription();
                    break;
                }
            }
        }

        return reValue;
    }

    /**
     * 파라미터를 데이터 모델로 변환
     * @param name
     * @param t
     * @param e
     * @param value
     * @return
     */
    public static VariableModel createVariableModel(String name, String t, String e, String value) {

        VariableModel model = new VariableModel();

        model.setN(name);
        model.setT(t);
        model.setE(e);
        model.setDescription(value);

        return model;
    }

    public static VariableModel createVariableModel(String name) {
        return createVariableModel(name, null, null, null);
    }

    public static VariableModel createVariableModel(String name, String value) {
        return createVariableModel(name, null, null, value);
    }

    public static VariableModel createVariableModel(String name, String type, String value) {
        return createVariableModel(name, type, null, value);
    }

    /**
     * 파라미터와를 메세지 모델로 변환하여 다시 Xml로 변환
     * @param data
     * @param list
     * @return
     */
    public static String createXml(List<VariableModel> data, List<DataModel> list) {

        MessageModel messageModel = new MessageModel();

        messageModel.setVersion("1.0");
        messageModel.setName("Request Message");

        DataModel dataModel = new DataModel();

        dataModel.setD(data);

        if(null != list && 0 < list.size()) {
            dataModel.setL(list);
        }

        messageModel.setB(dataModel);

        return objectToXml(messageModel);
    }

    /**
     * Xml을 메세지 모델로 변환
     * @param xmlStr
     * @return
     */
    public static MessageModel parseXml(String xmlStr) throws IllegalStateException {

        GsonXml gsonXml = new GsonXmlBuilder()
                .setXmlParserCreator(new XmlParserCreator() {
                    @Override
                    public XmlPullParser createParser() {
                        try {
                            return XmlPullParserFactory.newInstance().newPullParser();
                        } catch(Exception e) {
                            throw new RuntimeException(e);
                        }
                    }
                })
                .setSameNameLists(true)
                .create();

        MessageModel model = gsonXml.fromXml(xmlStr, MessageModel.class);

        return model;
    }

    /**
     * 메세지 모델을 Xml로 변환
     * @param messageModel
     * @return
     */
    public static String objectToXml(MessageModel messageModel) {

        StringBuffer buf = new StringBuffer();

        buf.append("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
        buf.append("<MESSAGE Version=\"" + messageModel.getVersion() + "\" Name=\"" + messageModel.getName() + "\">");

        if(null != messageModel.getData()) {
            buf.append("<B>");

            if(null != messageModel.getData().getData() && !messageModel.getData().getData().isEmpty()) {
                buf.append(getDataXml(messageModel.getData().getData()));
            }

            if(null != messageModel.getData().getList() && !messageModel.getData().getList().isEmpty()) {
                for(DataModel model : messageModel.getData().getList()) {
                    buf.append("<L N=\"" + model.getN() + "\">");
                    buf.append(getDataXml(model.getData()));
                    buf.append("</L>");
                }
            }
            buf.append("</B>");
        }

        buf.append("</MESSAGE>");

        return buf.toString();
    }

    private static String getDataXml(List<VariableModel> models) {

        StringBuffer buf = new StringBuffer();

        for(VariableModel model : models) {
            buf.append(getData(model));
        }

        return buf.toString();
    }

    /**
     * 데이터 모델을 <D></D> 태그로 변환
     * @param model
     * @return
     */
    private static String getData(VariableModel model) {

        StringBuffer buf = new StringBuffer();

        buf.append("<D N=\"" + model.getName()+ "\" ");

        if(null != model.getT() && !model.getT().isEmpty()) {
            buf.append("T=\"" + model.getT() + "\" ");
        }

        if(null != model.getE() && !model.getE().isEmpty()) {
            buf.append("E=\"" + model.getE() + "\" ");
        }

        buf.append(null != model.getDescription() && !model.getDescription().isEmpty() ? ">" + model.getDescription()+ "</D>" : "/>");

        return buf.toString();
    }

    /**
     * Xml전문을 Object로 변환하여 Map으로 반환
     *
     * @param responseText
     * @return
     * @throws Exception
     */
    public static Object convertResultToMap(String responseText) throws Exception {

        Map<String, Object> resultMap = new HashMap<>();

        MessageModel messageModel = parseXml(responseText);

        if(null != messageModel) {
            try {

                String statusValue = getValue(messageModel, H101Const.KEY_STATUSVALUE);

                if(null != messageModel.getData().getData() && !messageModel.getData().getData().isEmpty()) {
                    for(int i = 0 ; i < messageModel.getData().getData().size() ; i++) {
                        resultMap.put(messageModel.getData().getData().get(i).getName(), messageModel.getData().getData().get(i).getDescription());
                    }
                } else {
                    // 파싱 불가
                    throw new Exception("Unusual response data");
                }

                if(null != statusValue && Integer.parseInt(statusValue) > 0) {
                    // 실패
                    String msg = getValue(messageModel, H101Const.KEY_MESSAGE);
                    String code = getValue(messageModel, H101Const.KEY_RESULT_CODE);

                    if(code.equals(H101Const.RESULT_CODE_NEED_POSITIVE_NUMBER) || code.equals(H101Const.RESULT_CODE_NEED_NEGATIVE_NUMBER) || code.equals(H101Const.RESULT_CODE_NEED_NUMBER)) {
                    // if(code.equals(H101Const.RESULT_CODE_NEED_POSITIVE_NUMBER)) {

                        String errorBarcode = null;

                        if(null != messageModel.getData() && null != messageModel.getData().getList()) {

                            try {
                                for(DataModel dataModel : messageModel.getData().getList()) {

                                    if(dataModel.getN().equals("FIELDMSG") && !CollectionUtil.isNullorEmpty(dataModel.getData())) {

                                        for(int i = 0 ; i < dataModel.getData().size() ; i++) {

                                            switch(i) {
                                                case 0: // barcode
                                                    errorBarcode = dataModel.getData().get(i).getDescription();
                                                    break;
                                                default:
                                                    break;
                                            }
                                        }
                                        break;
                                    }
                                }
                            } catch(Exception e) {
                                throw e;
                            }
                        }

                        resultMap.put("ERROR_BARCODE", errorBarcode);
                    } else {
                        throw new Exception(msg);
                    }
                } else {
                    // 성공
                    if(null != messageModel.getData() && null != messageModel.getData().getList()) {

                        List<DataModel> models = messageModel.getData().getList();

                        List<Map<String, String>> rowList = new ArrayList<>();

                        //SHIP ORDER LIST
                        List<Map<String, String>> rowShipList = new ArrayList<>();

                        //SHIP LOT LIST
                        List<Map<String, String>> rowLotList = new ArrayList<>();

                        List<String> keyList = new ArrayList<>();

                        for(DataModel model : models) {

                            Map<String, String> rowMap = new HashMap<>();

                            if(model.getN().equals("COLUMNS") && !CollectionUtil.isNullorEmpty(model.getData())) {
                                keyList.add(model.getData().get(2).getDescription());
                            } else if(model.getN().equals("ROWS") && !CollectionUtil.isNullorEmpty(model.getList())) {

                                for(int i = 0 ; i < keyList.size() ; i++) {
                                    rowMap.put(keyList.get(i), model.getList().get(i).getData().get(0).getDescription());
                                }

                                rowList.add(rowMap);
                            } else if((model.getN().equals("LOT_TBL")
                                    || model.getN().equals("MAT_LIST") || model.getN().equals("INV_LOT_LIST")
                                    || model.getN().equals("SHIP_LOT_LIST") || model.getN().equals("ORDER_TBL")
                                    || model.getN().equals("WORKER_LIST") || model.getN().equals("WORKER_LIST")
                                    || model.getN().equals("DLV_LBL_LIST") || model.getN().equals("REQ_DTL_LIST")
                                    || model.getN().equals("REQ_LOT_LIST") || model.getN().equals("DATA_LIST")
                                    || model.getN().equals("OPER_LIST") || model.getN().equals("DLV_DTL_LIST")
                                    || model.getN().equals("DLV_MST_LIST") || model.getN().equals("RES_LIST")) && !CollectionUtil.isNullorEmpty(model.getData())) {

                                for(int i = 0 ; i < model.getData().size() ; i++) {
                                    rowMap.put(model.getData().get(i).getName(), model.getData().get(i).getDescription());
                                }

                                rowList.add(rowMap);
                            } else if(model.getN().equals("LIST") && !CollectionUtil.isNullorEmpty(model.getData())) {
                                rowMap.put(model.getData().get(0).getName(), model.getData().get(0).getDescription());
                                rowList.add(rowMap);
                            } else if(model.getN().equals("ORDER_TBL_PDA")) {
                                for(int i = 0 ; i < model.getData().size() ; i++) {
                                    rowMap.put(model.getData().get(i).getName(), model.getData().get(i).getDescription());
                                }

                                rowShipList.add(rowMap);
                                resultMap.put(model.getN(), rowShipList);
                            }
                            else if(model.getN().equals("SHIP_LOT_TBL_PDA")) {

                                for(int i = 0 ; i < model.getData().size() ; i++) {
                                    rowMap.put(model.getData().get(i).getName(), model.getData().get(i).getDescription());
                                }

                                rowLotList.add(rowMap);
                                resultMap.put(model.getN(), rowLotList);
                            }
                        }

                        resultMap.put("ROWS", rowList);
                    }
                }
            } catch(Exception e) {
                throw e;
            }
        }

        return resultMap;
    }
}
