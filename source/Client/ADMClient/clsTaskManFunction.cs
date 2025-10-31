using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

using Miracom.CliFrx;
using Miracom.MsgHandler;
using Miracom.TRSCore;
using Miracom.MESCore;
using Admin.ADMCore;

namespace ADMINClient
{
    public class clsTaskMan : intTaskManFunction
    {
        public static void InitialTaskManFunction()
        {
            clsTaskMan tm = new clsTaskMan();
            ADCGV.TaskMan = (Admin.ADMCore.intTaskManFunction)tm;
        }

        // PublishMsgTune()
        //       - Publish Message Tune
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //       -
        //
        public bool PublishADMMsgTune()
        {

            try
            {
                string sPublishChannel;

                //Modify by J.S. 2008/02/13 모든 Site ID에서 받는다.
                sPublishChannel = "/" + "*";
                sPublishChannel += "/ADM";
                //sPublishChannel += "/" + MPGV.gsFactory;
                //sPublishChannel += "/" + MPGV.gsUserGroup;
                //sPublishChannel += "/" + MPGV.gsUserID;

                MPMH.registerDispatcher("ADM", new ADMTunerImpl());
                if (true != MPMH.tune(sPublishChannel, true, false))
                {
                    MPCF.ShowMsgBox("Middleware Connection " + MPMH.StatusMessage, "Middleware Connection", MessageBoxButtons.OK, 1);
                    return false;
                }
            }
            catch (Exception)
            {
                MPCF.ShowMsgBox("PublishMsgTune() Failed.");
                return false;
            }

            return true;

        }

        public bool PublishADMMsgUnTune()
        {

            try
            {
                string sPublishChannel;

                sPublishChannel = "/" + "*";
                sPublishChannel += "/ADM";
                //sPublishChannel += "/" + MPGV.gsFactory;
                //sPublishChannel += "/" + MPGV.gsUserGroup;
                //sPublishChannel += "/" + MPGV.gsUserID;

                MPMH.untune(sPublishChannel, true, false);
                MPMH.unregisterDispatcher("ADM");
            }
            catch (Exception)
            {
                MPCF.ShowMsgBox("PublishMsgTune() Failed.");
                return false;
            }

            return true;
        }


        //Add by J.S. 2016.04.05
        // PublishSYSMsgTune()
        //       - Publish Message Tune
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //       -
        //
        public bool PublishSYSMsgTune()
        {

            try
            {
                string sPublishChannel;

                sPublishChannel = "/system/management";

                MPMH.registerDispatcher("SYSSVC", new SYSTunerImpl());
                if (true != MPMH.tune(sPublishChannel, true, false))
                {
                    MPCF.ShowMsgBox("Middleware Connection " + MPMH.StatusMessage, "Middleware Connection", MessageBoxButtons.OK, 1);
                    return false;
                }
            }
            catch (Exception)
            {
                MPCF.ShowMsgBox("PublishMsgTune() Failed.");
                return false;
            }

            return true;

        }

        public bool PublishSYSMsgUnTune()
        {

            try
            {
                string sPublishChannel;

                sPublishChannel = "/system/management";

                MPMH.untune(sPublishChannel, true, false);
                MPMH.unregisterDispatcher("SYSSVC");
            }
            catch (Exception)
            {
                MPCF.ShowMsgBox("PublishMsgTune() Failed.");
                return false;
            }

            return true;
        }


        //
        // CheckProcess()
        //       - Publish Check Process
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //
        //
        public bool CheckProcess()
        {


            try
            {
                TRSNode in_node = new TRSNode("CHECK_PROCESS_IN");

                int iSeq = 0;
                int i = 0;

                if (MPGV.gtServerInfoList == null)
                {
                    return false;
                }

                iSeq = ((MPGV.giRequestCnt + 1) % 2 == 0) ? 2 : 1;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddInt("CHECK_SEQ", iSeq);

                string sPublishChannel;

                if (MPIF.gInit.getMiddleware == "TIBRV")
                {
                    sPublishChannel = "/ADMIN/*/*";
                }
                else
                {
                    //Modify by J.S. 2009.02.12 H101, TIB 같은 형식으로 사용
                    sPublishChannel = "/ADMIN/*/*";
                    //sPublishChannel = "/*/*";
                }

                if (MPCR.CallService("ADM", "ADM_Check_Process", in_node, sPublishChannel, 0, DeliveryMode.Multicast, false) == false)
                {
                    return false;
                }

                if (MPGV.gtProcessinfoList != null)
                {
                    for (i = 0; i < MPGV.gtProcessinfoList.Length; i++)
                    {
                        if (iSeq == 1)
                        {
                            MPGV.gtProcessinfoList[i].reply_status_1 = MPGC.ADM_REQUEST_STATUS;
                        }
                        else if (iSeq == 2)
                        {
                            MPGV.gtProcessinfoList[i].reply_status_2 = MPGC.ADM_REQUEST_STATUS;
                        }
                    }
                }

                if (MPGV.giRequestCnt >= MPGC.ADM_MAX_REQUEST_CNT)
                {
                    MPGV.giRequestCnt = 1;
                }
                else
                {
                    MPGV.giRequestCnt++;
                }
                MPGV.giRequestSeq = iSeq;

                Cursor.Current = Cursors.Default;

                return true;

            }
            catch (Exception ex)
            {
                Cursor.Current = Cursors.Default;
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //
        // InitSharedPool()
        //       - Initial Shared Pool
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //
        //
        public bool InitSharedPool(string s_server_name, string s_channel)
        {
            try
            {
                int i;
                string sPublishChannel;
                TRSNode in_node = new TRSNode("INIT_SHARED_POOL_IN");

                if (MPGV.gtServerInfoList == null) return false;
                if (MPGV.gtProcessinfoList == null) return false;

                for (i = 0; i < MPGV.gtProcessinfoList.Length; i++)
                {
                    if (MPGV.gtProcessinfoList[i].server_name == s_server_name)
                    {
                        MPGV.gtProcessinfoList[i].shared_pool_status = MPGC.ADM_REQUEST_STATUS;
                    }
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("SERVER_NAME", s_server_name);

                if (MPIF.gInit.getMiddleware == "TIBRV")
                {
                    sPublishChannel = "/ADMIN/" + s_channel;
                }
                else
                {
                    sPublishChannel = s_channel;
                }

                if (MPCR.CallService("ADM", "ADM_Init_Shared_Pool", in_node, sPublishChannel, 0, DeliveryMode.Multicast, false) == false)
                {
                    return false;
                }

                Cursor.Current = Cursors.Default;

                return true;

            }
            catch (Exception ex)
            {
                Cursor.Current = Cursors.Default;
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }



    }
}
