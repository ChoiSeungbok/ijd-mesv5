using System;
using System.Data;
using System.Drawing;
using System.Windows.Forms;

using Miracom.CliFrx;
using Miracom.MsgHandler;
using Miracom.MESCore;
using Miracom.TRSCore;


//-----------------------------------------------------------------------------
//
//   System      : ADMINClient
//   File Name   :
//   Description : Common Function Definition Module
//
//   ADM Version : 5.0.0
//
//   Function List
//
//   Detail Description
//       -
//
//   History
//       - 2008-11-19 : Created by James Kwon
//
//   Copyright(C) 1998-2004 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------

namespace Admin.ADMCore
{
    public interface intTaskManFunction
    {
        bool PublishADMMsgTune();
        bool PublishADMMsgUnTune();
        bool CheckProcess();
        bool InitSharedPool(string s_server_name, string s_channel);

        //Add by J.S. 2016.04.05
        bool PublishSYSMsgTune();
        bool PublishSYSMsgUnTune();
    }

    public sealed class ADCGV
    {
        public static intTaskManFunction TaskMan;

        //Add by J.S. 2016.04.05
        public static string SysMessage;
    }

    public abstract class ADMTuner : ServiceDispatcher
    {
        #region "Call Service Member"

        public bool dispatch(string s_service_name, Miracom.TRSCore.TRSNode in_node, Miracom.TRSCore.TRSNode out_node)
        {
            if (s_service_name.Equals("Publish_Process_Status"))
                Publish_Process_Status(in_node);
            else if (s_service_name.Equals("Publish_Shared_Pool_Status"))
                Publish_Shared_Pool_Status(in_node);
            else
                return false;

            return true;
        }

        public abstract void Publish_Process_Status(TRSNode node);
        public abstract void Publish_Shared_Pool_Status(TRSNode node);

        #endregion
    }

    public class ADMTunerImpl : ADMTuner
    {
        // Publish_Process_Status()
        //       - Process Status Publish Message Process
        // Return Value
        //       - Integer : MP_SUCCESS or MP_FAIL
        // Arguments
        //       - ByRef Publish_Process_Status_In As Publish_Process_Status_In_Tag
        //
        public override void Publish_Process_Status(Miracom.TRSCore.TRSNode node)
        {
            int iSeq = 0;

            try
            {
                if (MPGV.gtProcessinfoList == null) return;

                for (int i = 0; i < MPGV.gtProcessinfoList.Length; i++)
                {
                    if (MPGV.gtProcessinfoList[i].server_name == MPCF.Trim(node.GetString("SERVER_NAME")) &&
                        (MPGV.gtProcessinfoList[i].sub_no == "" ||
                         MPGV.gtProcessinfoList[i].sub_no == MPCF.Trim(node.GetString("SUB_NO"))))
                    {
                        if (node.GetInt("CHECK_SEQ") == 1)
                        {
                            if (MPGV.gtProcessinfoList[i].reply_status_1 != MPGC.ADM_REPLY_STATUS)
                                iSeq = 1;
                            else
                                iSeq = 2;
                        }
                        else if (node.GetInt("CHECK_SEQ") == 2)
                        {
                            if (MPGV.gtProcessinfoList[i].reply_status_2 != MPGC.ADM_REPLY_STATUS)
                                iSeq = 2;
                            else
                                iSeq = 1;
                        }

                        MPGV.gtProcessinfoList[i].process_name = MPCF.Trim(node.GetString("PROCESS_NAME"));
                        MPGV.gtProcessinfoList[i].channel = MPCF.Trim(node.GetString("CHANNEL"));
                        MPGV.gtProcessinfoList[i].sub_no = MPCF.Trim(node.GetString("SUB_NO"));

                        if (MPGV.gtProcessinfoList[i].reply_count > MPGV.giRequestCnt)
                            MPGV.gtProcessinfoList[i].reply_count = MPGV.giRequestCnt;
                        else
                            MPGV.gtProcessinfoList[i].reply_count += 1;

                        if (iSeq == 1)
                        {
                            MPGV.gtProcessinfoList[i].reply_status_1 = MPGC.ADM_REPLY_STATUS;
                        }
                        else
                        {
                            MPGV.gtProcessinfoList[i].reply_status_2 = MPGC.ADM_REPLY_STATUS;
                        }

                        break;
                    }
                }

                Sort_Process_Status();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Publish_Process_Status()" + "\r\n" + ex.Message);
            }
        }

        private void Sort_Process_Status()
        {
            int i1, i2, i3;

            try
            {
                if (MPGV.gtServerInfoList == null) return;
                if (MPGV.gtProcessinfoList == null) return;

                for (i1 = 0; i1 < MPGV.gtServerInfoList.Length; i1++)
                {
                    for (i2 = 0, i3 = 0; i2 < MPGV.gtProcessinfoList.Length; i2++, i3++)
                    {
                        if (MPGV.gtServerInfoList[i1].server_name == MPGV.gtProcessinfoList[i2].server_name)
                        {
                            Sort_Process_Status_Sub(i2, MPGV.gtServerInfoList[i1].tot_count);
                        }
                        i2 += MPGV.gtServerInfoList[i3].tot_count - 1;
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Sort_Process_Status()" + "\r\n" + ex.Message);
            }
        }

        private void Sort_Process_Status_Sub(int a, int b)
        {
            int i1, i2;

            try
            {
                if (MPGV.gtProcessinfoList == null) return;

                for (i1 = a; i1 < b + a - 1; i1++)
                {
                    if (MPGV.gtProcessinfoList[i1].sub_no != "")
                    {
                        for (i2 = i1 + 1; i2 < b + a; i2++)
                        {
                            if (MPGV.gtProcessinfoList[i2].sub_no != "")
                            {
                                if (MPGV.gtProcessinfoList[i1].sub_no.CompareTo(MPGV.gtProcessinfoList[i2].sub_no) > 0)
                                {
                                    Swap_Process_Status(i1, i2);
                                }
                            }
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Sort_Process_Status()" + "\r\n" + ex.Message);
            }
        }

        private void Swap_Process_Status(int i_from, int i_to)
        {
            gtProcessInfoTag tmp;

            if (MPGV.gtProcessinfoList == null) return;

            tmp.server_name = MPGV.gtProcessinfoList[i_to].server_name;
            tmp.process_name = MPGV.gtProcessinfoList[i_to].process_name;
            tmp.channel = MPGV.gtProcessinfoList[i_to].channel;
            tmp.sub_no = MPGV.gtProcessinfoList[i_to].sub_no;
            tmp.check_seq = MPGV.gtProcessinfoList[i_to].check_seq;
            tmp.reply_count = MPGV.gtProcessinfoList[i_to].reply_count;
            tmp.reply_status_1 = MPGV.gtProcessinfoList[i_to].reply_status_1;
            tmp.reply_status_2 = MPGV.gtProcessinfoList[i_to].reply_status_2;
            tmp.shared_pool_status = MPGV.gtProcessinfoList[i_to].shared_pool_status;

            MPGV.gtProcessinfoList[i_to].server_name = MPGV.gtProcessinfoList[i_from].server_name;
            MPGV.gtProcessinfoList[i_to].process_name = MPGV.gtProcessinfoList[i_from].process_name;
            MPGV.gtProcessinfoList[i_to].channel = MPGV.gtProcessinfoList[i_from].channel;
            MPGV.gtProcessinfoList[i_to].sub_no = MPGV.gtProcessinfoList[i_from].sub_no;
            MPGV.gtProcessinfoList[i_to].check_seq = MPGV.gtProcessinfoList[i_from].check_seq;
            MPGV.gtProcessinfoList[i_to].reply_count = MPGV.gtProcessinfoList[i_from].reply_count;
            MPGV.gtProcessinfoList[i_to].reply_status_1 = MPGV.gtProcessinfoList[i_from].reply_status_1;
            MPGV.gtProcessinfoList[i_to].reply_status_2 = MPGV.gtProcessinfoList[i_from].reply_status_2;
            MPGV.gtProcessinfoList[i_to].shared_pool_status = MPGV.gtProcessinfoList[i_from].shared_pool_status;

            MPGV.gtProcessinfoList[i_from].server_name = tmp.server_name;
            MPGV.gtProcessinfoList[i_from].process_name = tmp.process_name;
            MPGV.gtProcessinfoList[i_from].channel = tmp.channel;
            MPGV.gtProcessinfoList[i_from].sub_no = tmp.sub_no;
            MPGV.gtProcessinfoList[i_from].check_seq = tmp.check_seq;
            MPGV.gtProcessinfoList[i_from].reply_count = tmp.reply_count;
            MPGV.gtProcessinfoList[i_from].reply_status_1 = tmp.reply_status_1;
            MPGV.gtProcessinfoList[i_from].reply_status_2 = tmp.reply_status_2;
            MPGV.gtProcessinfoList[i_from].shared_pool_status = tmp.shared_pool_status;
        }

        // Publish_Shared_Pool_Status()
        //       - Process Status Publish Message Process
        // Return Value
        //       - Integer : MP_SUCCESS or MP_FAIL
        // Arguments
        //       - ByRef Publish_Process_Status_In As Publish_Process_Status_In_Tag
        //
        public override void Publish_Shared_Pool_Status(Miracom.TRSCore.TRSNode node)
        {
            try
            {
                if (MPGV.gtProcessinfoList == null) return;

                for (int i = 0; i < MPGV.gtProcessinfoList.Length; i++)
                {
                    if (MPGV.gtProcessinfoList[i].server_name == MPCF.Trim(node.GetString("SERVER_NAME")) &&
                        MPGV.gtProcessinfoList[i].sub_no == MPCF.Trim(node.GetString("SUB_NO")))
                    {
                        if (node.GetInt("POOL_CLEAR") == 1)
                        {
                            MPGV.gtProcessinfoList[i].shared_pool_status = MPGC.ADM_REPLY_STATUS;
                        }

                        break;
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Publish_Shared_Pool_Status()" + "\r\n" + ex.Message);
            }
        }
    }




    //Add by J.S. 2016.04.05
    public abstract class SYSTuner : ServiceDispatcher
    {
        #region "Call Service Member"

        public bool dispatch(string s_service_name, Miracom.TRSCore.TRSNode in_node, Miracom.TRSCore.TRSNode out_node)
        {
            if (s_service_name.Equals("SYS_Publish_Message"))
                SYS_Publish_Message(in_node);
            else
                return false;

            return true;
        }


        public abstract void SYS_Publish_Message(TRSNode node);

        #endregion
    }

    public class SYSTunerImpl : SYSTuner
    {
        // Publish_Process_Status()
        //       - Process Status Publish Message Process
        // Return Value
        //       - Integer : MP_SUCCESS or MP_FAIL
        // Arguments
        //       - ByRef Publish_Process_Status_In As Publish_Process_Status_In_Tag
        //
        public override void SYS_Publish_Message(Miracom.TRSCore.TRSNode node)
        {
            try
            {
                ADCGV.SysMessage = node.GetString("MESSAGE");
  
            }
            catch (Exception ex)
            {
                MessageBox.Show("SYS_Publish_Message()" + "\r\n" + ex.Message);
            }
        }
 
    }

}
