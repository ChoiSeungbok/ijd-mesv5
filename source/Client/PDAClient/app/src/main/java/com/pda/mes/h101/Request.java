package com.pda.mes.h101;

import android.content.Context;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import android.widget.Toast;

import com.miracom.oneoone.transceiverx.ErrorCode;
import com.miracom.oneoone.transceiverx.Message;
import com.miracom.oneoone.transceiverx.Session;
import com.miracom.oneoone.transceiverx.StreamTransformer;
import com.miracom.oneoone.transceiverx.Transceiver;
import com.miracom.oneoone.transceiverx.TrxException;
import com.miracom.oneoone.transceiverx.parser.DeliveryType;
import com.miracom.oneoone.transceiverx.parser.StreamTransformerImpl;
import com.pda.mes.manager.AppSettingManager;
import com.pda.mes.manager.SessionManager;
import com.pda.mes.model.parser.DataModel;
import com.pda.mes.model.parser.VariableModel;
import com.pda.mes.manager.AppLogManager;
import com.pda.mes.utils.LogUtil;
import com.pda.mes.utils.ParseH101Xml;

import java.util.ArrayList;
import java.util.List;

import static com.pda.mes.manager.AppSettingManager.DEFAULT_FACTORY;

public abstract class Request {
    private final static String TAG = Request.class.getSimpleName();
    private final static String SESSION_NAME = "CasterRequestReply";
    private Handler mHandler;
    private List<DataModel> listparams;
    private List<VariableModel> params;
    private Context context;

    public Request(Context context) {
        this.context = context;
        params = new ArrayList<>();
        listparams = new ArrayList<>();
    }

    public void addParam(String key, String t) {
        addParam(key, t, null, null);
    }

    public void addParam(String key, String t, String value) {
        addParam(key, t, null, value);
    }

    public void addParam(String key, String t, String e, String value) {
        VariableModel model = new VariableModel();
        model.setN(key);
        model.setT(t);
        model.setE(e);
        model.setDescription(value);

        this.params.add(model);

        if(key.equals("_SERVICE_NAME")) {
            if (!(value.equals("BAS_SQL_Query") || value.equals("TKCOM_Login_Ext") || value.equals("TKCOM_Update_Login_History") || value.equals("BAS_Check_Version") || value.equals("TKINV_Valid_Label") || value.equals("TKORD_Scan_Barcode")))
                RequestConfig.getInstance().isTran = true;
        }
    }

    public void addListParam(DataModel model) {
        this.listparams.add(model);
    }

    public void request(final RequestHandler handler) {
        if(RequestConfig.getInstance().isRequest && RequestConfig.getInstance().isTran)
            return;
        RequestConfig.getInstance().isRequest = true;

        if(null != mHandler)
            mHandler.removeCallbacksAndMessages(0);

        mHandler = new Handler(Looper.getMainLooper());

        setRequiredParam();

        new Thread() {
            @Override
            public void run() {
                Session ioiSession = null;
                try {
                    //세션 생성(Inter-Station, PULL Mode) 세션 생성시 pull모드로 진행
                    ioiSession = Transceiver.createSession(SESSION_NAME, Session.SESSION_INTER_STATION_MODE | Session.SESSION_PULL_DELIVERY_MODE);

                    //세션 복원 기능 옵션은 false로 설정
                    ioiSession.setAutoRecovery(false);
                    ioiSession.setDefaultTTL(AppSettingManager.getTimeOut(context) * 1000);

                    String serviceIP = H101Const.getBaseUrl(AppSettingManager.getServerType(context));

                    //세션 연결
                    ioiSession.connect(serviceIP);

                    mHandler.post(new Runnable() {
                        @Override
                        public void run() {
                            handler.onStart();
                        }
                    });

                    //메시지 생성 및 송신 Channel, TTL, DeliveryMode, Data 설정
                    Message msg = ioiSession.createMessage();

                    String msgData = ParseH101Xml.createXml(params, listparams);

                    AppLogManager.printErrorLog("service IP = " + serviceIP);
                    AppLogManager.printErrorLog("request = " + msgData);

                    try {
                        StreamTransformer former = new StreamTransformerImpl();
                        former.writeMsgString(msgData);
                        for(int i = 0 ; i < 10 ; i++)
                            former.writeMsgByteArray(null);
                        byte[] reqBytes = former.getBytes();
                        msg.setData(reqBytes);

                    }
                    catch(Exception e) {
                        if(e.getMessage().contains("TRX")) {
                            LogUtil.writeLog(TAG, "request()", "#1 Exception : Failed connection. Please try again after connecting to the network. : " + e.getMessage());
                            handler.onFailure(new Exception("Failed connection. Please try again after connecting to the network."));
                        }
                        else {
                            LogUtil.writeLog(TAG, "request()", "#2 StreamTransformer Exception : " + e.getMessage());
                            handler.onFailure(e);
                        }
                    }

                    msg.setChannel("/IDK1/MESServer");
                    msg.setDeliveryMode(DeliveryType.REQUEST);
                    msg.setTTL(AppSettingManager.getTimeOut(context) * 1000);
                    msg.setProperty("VERSION", "4.0");
                    msg.setProperty("MODULE", "MESPLUS");
                    msg.setProperty("INTERFACE", "MESPLUS");
                    msg.setProperty("OPERATION", "CallService");

                    //메시지 전송
                    Message rep = ioiSession.sendRequest(msg);

                    //응답 메시지 처리
                    if(rep == null) throw new TrxException(ErrorCode.INVALID_MESSAGE);

                    long resultCode = Long.parseLong((String)rep.getProperty("RESULT_CODE"));
                    if(resultCode < 0) {
                        final String strRep = (String)rep.getProperty("RESULT_MSG");
                        System.out.println("strRep = " + strRep);
                        mHandler.post(new Runnable() {
                            @Override
                            public void run() {
                                RequestConfig.getInstance().releaseRequest();
                                LogUtil.writeLog(TAG, "request()", "#3 Result code size under 0 Exception : " + strRep);
                                handler.onFailure(new Exception(strRep));
                            }
                        });
                        return;
                    }

                    // Response Message
                    String respStr = null; // 받을 메세지 값
                    try {
                        Object data = rep.getData();

                        if(data instanceof byte[])
                            respStr = new String((byte[])data, "UTF-8");
                        else
                            respStr = data.toString();

                        respStr = respStr.substring(respStr.indexOf("<?"));
                        respStr = respStr.substring(0, respStr.lastIndexOf("</MESSAGE>") + 10);
                    }
                    catch(Exception e) {
                        LogUtil.writeLog(TAG, "request()", "#4 Response Message Exception : " + e.getMessage());
                        e.printStackTrace();
                    }

                    final String resultMsg = respStr;

                    if(null != resultMsg) {
                        AppLogManager.printErrorLog("result = " + resultMsg);
                        mHandler.post(new Runnable() {
                            @Override
                            public void run() {
                                try {
                                    RequestConfig.getInstance().releaseRequest();
                                    handler.onResult(ParseH101Xml.convertResultToMap(resultMsg));
                                }
                                catch(Exception e) {
                                    RequestConfig.getInstance().releaseRequest();
                                    LogUtil.writeLog(TAG, "request()", "#5 Result Parse Exception : " + e.getMessage());
                                    e.printStackTrace();
                                    handler.onFailure(e);
                                }
                            }
                        });
                    }
                    else {
                        mHandler.post(new Runnable() {
                            @Override
                            public void run() {
                                LogUtil.writeLog(TAG, "request()", "#6 Exception : Null Response");
                                handler.onFailure(new Exception("Null Response"));
                            }
                        });
                    }
                }
                catch(final TrxException e) {
                    e.printStackTrace();
                    mHandler.post(new Runnable() {
                        @Override
                        public void run() {
                            RequestConfig.getInstance().releaseRequest();
                            LogUtil.writeLog(TAG, "request()", "#7 Exception : Failed connection. Please try again after connecting to the network. : " + e.getMessage());
                            handler.onFailure(new Exception("Failed connection. Please try again after connecting to the network."));
                        }
                    });
                }
                catch(final Exception e1) {
                    e1.printStackTrace();
                    mHandler.post(new Runnable() {
                        @Override
                        public void run() {
                            RequestConfig.getInstance().releaseRequest();
                            LogUtil.writeLog(TAG, "request()", "#8 Exception : " + e1.getMessage());
                            handler.onFailure(e1);
                        }
                    });
                }
                finally {
                    try {
                        // 세션 연결 종료 및 삭제, 메시지 송수신후 세션 종료
                        ioiSession.disconnect();
                        ioiSession.destroy();

                        mHandler.post(new Runnable() {
                            @Override
                            public void run() {
                                RequestConfig.getInstance().releaseRequest();
                                handler.onFinish();
                            }
                        });

                    }
                    catch(final Exception e) {
                        e.printStackTrace();
                        mHandler.post(new Runnable() {
                            @Override
                            public void run() {
                                RequestConfig.getInstance().releaseRequest();
                                LogUtil.writeLog(TAG, "request()", "#9 Exception : " + e.getMessage());
                                handler.onFailure(e);
                            }
                        });
                    }

                    if(null != mHandler) {
                        mHandler.removeCallbacksAndMessages(0);
                    }
                    RequestConfig.getInstance().releaseRequest();
                }
            }
        }.start();
    }

    // 서버간 통신을 할때 사용하는 Request (VT 처럼 서버가 VT, CT, MT 같이 분리된 경우에만 사용)
    public void request(final int serverType, final RequestHandler handler) {
        if(RequestConfig.getInstance().isRequest && RequestConfig.getInstance().isTran)
            return;
        RequestConfig.getInstance().isRequest = true;

        if(null != mHandler) {
            mHandler.removeCallbacksAndMessages(0);
        }

        mHandler = new Handler(Looper.getMainLooper());
        setRequiredParam();

        new Thread() {
            @Override
            public void run() {
                Session ioiSession = null;
                try {
                    //세션 생성(Inter-Station, PULL Mode) 세션 생성시 pull모드로 진행
                    ioiSession = Transceiver.createSession(SESSION_NAME, Session.SESSION_INTER_STATION_MODE | Session.SESSION_PULL_DELIVERY_MODE);

                    //세션 복원 기능 옵션은 false로 설정
                    ioiSession.setAutoRecovery(false);
                    ioiSession.setDefaultTTL(AppSettingManager.getTimeOut(context) * 1000);

                    String serviceIP;

                    if(AppSettingManager.getServerType(context) == AppSettingManager.TYPE_SERVER_IJ) {
                        serviceIP = AppSettingManager.getInputIP(context);
                    }
                    else {
                        // serviceIP = H101Const.getBaseUrl(AppSettingManager.getServerType(context));
                        serviceIP = H101Const.getBaseUrl(serverType);
                    }

                    //세션 연결
                    ioiSession.connect(serviceIP);

                    mHandler.post(new Runnable() {
                        @Override
                        public void run() {
                            handler.onStart();
                        }
                    });

                    //메시지 생성 및 송신 Channel, TTL, DeliveryMode, Data 설정
                    Message msg = ioiSession.createMessage();

                    String msgData = ParseH101Xml.createXml(params, listparams);

                    AppLogManager.printErrorLog("service IP = " + serviceIP);
                    AppLogManager.printErrorLog("request = " + msgData);

                    try {
                        StreamTransformer former = new StreamTransformerImpl();
                        former.writeMsgString(msgData);
                        for(int i = 0 ; i < 10 ; i++)
                            former.writeMsgByteArray(null);
                        byte[] reqBytes = former.getBytes();
                        msg.setData(reqBytes);

                    }
                    catch(Exception e) {
                        e.printStackTrace();
                    }

                    msg.setChannel("//MESServer");
                    msg.setDeliveryMode(DeliveryType.REQUEST);
                    msg.setTTL(AppSettingManager.getTimeOut(context) * 1000);
                    msg.setProperty("VERSION", "4.0");
                    msg.setProperty("MODULE", "MESPLUS");
                    msg.setProperty("INTERFACE", "MESPLUS");
                    msg.setProperty("OPERATION", "CallService");

                    //메시지 전송
                    Message rep = ioiSession.sendRequest(msg);

                    //응답 메시지 처리
                    if(rep == null) throw new TrxException(ErrorCode.INVALID_MESSAGE);

                    long resultCode = Long.parseLong((String)rep.getProperty("RESULT_CODE"));
                    if(resultCode < 0) {
                        final String strRep = (String)rep.getProperty("RESULT_MSG");
                        System.out.println("strRep = " + strRep);
                        mHandler.post(new Runnable() {
                            @Override
                            public void run() {
                                RequestConfig.getInstance().releaseRequest();
                                handler.onFailure(new Exception(strRep));
                            }
                        });
                        return;
                    }

                    // Response Message
                    String respStr = null; // 받을 메세지 값
                    try {
                        Object data = rep.getData();

                        if(data instanceof byte[]) respStr = new String((byte[])data, "UTF-8");
                        else respStr = data.toString();

                        respStr = respStr.substring(respStr.indexOf("<?"));
                        respStr = respStr.substring(0, respStr.lastIndexOf("</MESSAGE>") + 10);
                    }
                    catch(Exception e) {
                        e.printStackTrace();
                    }

                    final String resultMsg = respStr;

                    if(null != resultMsg) {
                        AppLogManager.printErrorLog("result = " + resultMsg);

                        mHandler.post(new Runnable() {
                            @Override
                            public void run() {
                                try {
                                    RequestConfig.getInstance().releaseRequest();
                                    handler.onResult(ParseH101Xml.convertResultToMap(resultMsg));
                                }
                                catch(Exception e) {
                                    RequestConfig.getInstance().releaseRequest();
                                    e.printStackTrace();
                                    handler.onFailure(e);
                                }
                            }
                        });
                    }
                    else {
                        mHandler.post(new Runnable() {
                            @Override
                            public void run() {
                                RequestConfig.getInstance().releaseRequest();
                                handler.onFailure(new Exception("Null Response"));
                            }
                        });
                    }
                }
                catch(final TrxException e) {
                    e.printStackTrace();
                    mHandler.post(new Runnable() {
                        @Override
                        public void run() {
                            RequestConfig.getInstance().releaseRequest();
                            handler.onFailure(new Exception("Failed connection. Please try again after connecting to the network."));
                        }
                    });
                }
                catch(final Exception e1) {
                    e1.printStackTrace();
                    mHandler.post(new Runnable() {
                        @Override
                        public void run() {
                            RequestConfig.getInstance().releaseRequest();
                            handler.onFailure(e1);
                        }
                    });
                }
                finally {
                    try {
                        // 세션 연결 종료 및 삭제 메시지 송수신후 세션 종료
                        ioiSession.disconnect();
                        ioiSession.destroy();

                        mHandler.post(new Runnable() {
                            @Override
                            public void run() {
                                RequestConfig.getInstance().releaseRequest();
                                handler.onFinish();
                            }
                        });
                    }
                    catch(final Exception e) {
                        e.printStackTrace();
                        mHandler.post(new Runnable() {
                            @Override
                            public void run() {
                                RequestConfig.getInstance().releaseRequest();
                                handler.onFailure(e);
                            }
                        });
                    }

                    if(null != mHandler) {
                        mHandler.removeCallbacksAndMessages(0);
                    }
                    RequestConfig.getInstance().releaseRequest();
                }
            }
        }.start();
    }

    private void setRequiredParam() {
        addParam("PASSPORT", "S");
        addParam("LANGUAGE", "C");
        addParam("LOGLEVEL", "C");
        addParam("FACTORY", "S", "IJDK1");

        boolean isDuplicated = false;

        for(VariableModel model : params) {
            if(model.getName().equals("USERID")) {
                isDuplicated = true;
                break;
            }
        }

        if(!SessionManager.getUserId(context).isEmpty() && !isDuplicated) {
            addParam("USERID", "S", "Y", SessionManager.getUserId(context));
            addParam("PASSWORD", "S", "Y", SessionManager.getUserPassword(context));
        }
    }

    public static class RequestHandler {
        public void onStart() {
        }

        public void onResult(Object result) throws InterruptedException {
        }

        public void onFailure(Exception exception) {
        }

        public void onFinish() {
        }
    }
}
