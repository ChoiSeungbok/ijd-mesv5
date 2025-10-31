using System;
using Miracom.CliFrx;
using Miracom.DNMCore;
using System.Data;
using Miracom.TRSCore;
using Miracom.MESCore;
using Miracom.MsgHandler;
using System.Windows.Forms;

namespace CUS_COM
{
    public  class clsServerConection
    {
        // fun_name_sSearch();


        private const string IDK1_FACTORY = "IJDK1";
        private const string IDK1_SITE_ID = "IDK1";
        private const string IDK1_ADDRESS = "197.200.11.43";
        private const string IDV1_FACTORY = "IJDV1";
        private const string IDV1_SITE_ID = "IDV1";
        private const string IDV1_ADDRESS = "10.201.81.31";


        public void fun_site_factory_change()
        {

            MPGV.gsSiteID = "";
            MPGV.gsRemoteAddress = "";
            MPGV.gsFactory = "";
            MPGV.gsUserID = "";
            MPGV.gsPassword = "";
            MPGV.gsRvService = "";
            MPGV.gsRvNetwork = "";
            MPGV.gsStationMode = "";





        }

        public void fun_site_factory_change(string sFactory)
        {
            if (sFactory == "IJDV1")
            {
                MPCF.SaveRegSetting(Application.ProductName, "Option", "BackGroundLogin", "Y");
                MPCF.SaveRegSetting(Application.ProductName, "Option", "SiteID", IDK1_SITE_ID);
                MPCF.SaveRegSetting(Application.ProductName, "Option", "RemoteAddress", IDK1_ADDRESS);
                MPCF.SaveRegSetting(Application.ProductName, "Settings", "Factory", IDK1_FACTORY);
                MPCF.SaveRegSetting(Application.ProductName, "Option", "StationMode" + "0", MPGV.gsStationMode);
                MPCF.SaveRegSetting(Application.ProductName, "Settings", "Password", MPGV.gsPassword);
                MPGV.gsSiteID = IDK1_SITE_ID;
                MPGV.gsRemoteAddress = IDK1_ADDRESS;

                /*
                if (RunProcess(Application.ExecutablePath) == false)
                {
                    return;
                }
                */

                /*
                MPCF.SaveRegSetting(Application.ProductName, "Option", "BackGroundLogin", "Y");
                MPCF.SaveRegSetting(Application.ProductName, "Option", "SiteID", IDV1_SITE_ID);
                MPCF.SaveRegSetting(Application.ProductName, "Option", "RemoteAddress", IDV1_ADDRESS);
                MPCF.SaveRegSetting(Application.ProductName, "Settings", "Factory", IDV1_FACTORY);
                MPCF.SaveRegSetting(Application.ProductName, "Option", "StationMode" + "0", MPGV.gsStationMode);
                MPCF.SaveRegSetting(Application.ProductName, "Settings", "Password", MPGV.gsPassword);
                MPGV.gsSiteID = IDV1_SITE_ID;
                MPGV.gsRemoteAddress = IDV1_ADDRESS;
                */
            }
        }


            public void fun_name_sSearch()
        {

            try
            {

                TRSNode in_node = new TRSNode("SQL_IN");
                TRSNode out_node = new TRSNode("SQL_OUT");


                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';


                in_node.AddString("SQL", "SELECT MAX(FUNC_NAME) KEEP(dense_rank first order by UPDATE_TIME DESC) AS FUNC_NAME FROM CSECUSEDAT WHERE USER_ID ='" + MPGV.gsUserID + "'");


                do
                {
                    if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                    {
                        return;
                    }

                    url_open(out_node.GetList("ROWS")[0].GetList("COLS")[0].GetString("DATA"));

                } while (out_node.GetInt("NEXT_ROW") > 0);




                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }

        public void url_open(string skey_1)
        {
            try
            {

                string sUrl;
      

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                string sViewID = "BAS-02";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;


                dvcArgu[1].sCondition_ID = "TABLE_NAME";
                dvcArgu[1].sCondition_Value = "C_ETC_WEB";

                dvcArgu[2].sCondition_ID = "KEY_1";
                dvcArgu[2].sCondition_Value = skey_1;





                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                //특정그룹만 접속가능한경우
                if (MPCF.Trim(dt.Rows[i]["DATA_7"].ToString()) != "Y")
                {
                    if (MPGV.gsUserGroup != dt.Rows[i]["DATA_3"].ToString())
                    {
                        //CMN106 ERROR - Function을 사용할 권한이 없습니다.
                        MPCF.ShowMsgBox(MPCF.GetMessage(106));
                        return;
                    }

                }



                sUrl = MPCF.Trim(dt.Rows[i]["DATA_4"].ToString()) + MPCF.Trim(dt.Rows[i]["DATA_5"].ToString()) + MPCF.Trim(dt.Rows[i]["DATA_6"].ToString());

                //브라우저 종류별로 실생될때까지 실행.
                if (process_open(dt.Rows[i]["DATA_1"].ToString(), sUrl) == false)
                {
                    if (process_open(dt.Rows[i]["DATA_2"].ToString(), sUrl) == false)
                    {

                        if (process_open(dt.Rows[i]["DATA_3"].ToString(), sUrl) == false)
                        {
                            //CMN554 INFO - 실행가능 웹브라우저가 없습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(554));
                            return;
                        }
                    }
                }



                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        public bool process_open(string sfileName, string sArguments)
        {


                System.Diagnostics.Process.Start(sfileName, sArguments);

               //일단은 브라우저 실행까지만..하고
         



            return true;


        }

    }


   

}
