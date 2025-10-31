
using System.Diagnostics;
using System;
using System.Windows.Forms;
using System.Collections;
using System.Drawing;

using Miracom.MsgHandler;
using System.Data;
using Miracom.MESCore;
using Miracom.CliFrx;
using Miracom.TRSCore;
using CUS_COM;

namespace MESClient
{
    public class clsFormEventFunctionImp : intFormEventFunction
    {
        private bool initSpread(Control baseControl)
        {
            foreach (Control ctrl in baseControl.Controls)
            {
                if (ctrl is FarPoint.Win.Spread.FpSpread)
                {
                    (ctrl as FarPoint.Win.Spread.FpSpread).HorizontalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
                    (ctrl as FarPoint.Win.Spread.FpSpread).VerticalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
                    (ctrl as FarPoint.Win.Spread.FpSpread).ScrollBarTrackPolicy = FarPoint.Win.Spread.ScrollBarTrackPolicy.Both;
                    (ctrl as FarPoint.Win.Spread.FpSpread).ScrollTipPolicy = FarPoint.Win.Spread.ScrollTipPolicy.Both;
                }

                if (ctrl.Controls.Count > 0)
                    initSpread(ctrl);
            }

            return true;
        }

        private void Update_Program_Usage(System.Windows.Forms.Form frm)
        {
            TRSNode in_node = new TRSNode("Update_used_data_in");
            TRSNode out_node = new TRSNode("Update_used_data_out");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("PROGRAM_ID", frm.Name);
                in_node.AddString("PROGRAM_DESC", frm.Text);
                in_node.AddString("ASSEMBLY_NAME", frm.GetType().Namespace + "." + frm.GetType().Name);
                in_node.AddString("FUNC_NAME", MPCF.Trim(frm.Tag));
                in_node.AddString("PG_KIND", "MES");

                if (Miracom.MsgHandler.MessageCaster.CallService("CUS_BAS", "CUS_BAS_Update_Used_Data", in_node, DeliveryMode.Unicast) == false)
                    return;
            }
            catch
            {
            }
        }

        public void Form_Load(System.Windows.Forms.Form frm, System.EventArgs e)
        {
            try
            {
				/* Middleware 를 통한 통신이 가능한지 확인 */
                if (MPIF.gInit.IsAvailableSendMessage == true)
                {
                    if (MPGO.DisplayColHeadCodeView() == true)
                    {
                        MPCR.SetCodeViewVisibleColumnHeader(frm, true, null, null, null, null, null, null, null, null, null, null);
                    }
                }

                MPCF.ToClientLanguage(frm);

                Update_Program_Usage(frm);

                if (MPGV.gsUserGroup == "ADMIN_GROUP")
                {
                    if (frm.Tag != null)
                    {
                        frm.Text = "[" + MPCF.Trim(frm.Tag) + "] " + frm.Text + "-" + frm.Name;
                    }
                    else
                    {
                        frm.Text = frm.Text + "-" + frm.Name;
                    }
                }
                else
                {
                    if (frm.Tag != null)
                    {
                        frm.Text = "[" + MPCF.Trim(frm.Tag) + "] " + frm.Text;
                    }
                }

                initSpread(frm);

                //레지스트리에 저장한 값을 폼 오픈시 값을 가져 오도록 한다. _20200722_lwg
                CSCF.GetCondition(frm);

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        
        public void Form_Activated(System.Windows.Forms.Form frm, System.EventArgs e)
        {
            
        }

        public void Form_Closed(System.Windows.Forms.Form frm, FormClosedEventArgs e)
        {
            //폼 클로우즈 시 레지스트리에 콘트롤의 값을 저장 하도록 한다. _20200722_lwg
            Miracom.CliFrx.BaseForm01 Saveform = new BaseForm01();
            Saveform = (Miracom.CliFrx.BaseForm01)frm;

            if (Saveform.SaveRegistry != null && Saveform.SaveRegistry.Count > 0)
            {
                CSCF.SaveCondition(Saveform, Saveform.SaveRegistry);
            }            
        }
        
    }
    
}
