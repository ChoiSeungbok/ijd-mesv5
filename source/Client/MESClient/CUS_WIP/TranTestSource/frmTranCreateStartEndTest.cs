using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;

namespace CUS_WIP
{
    public partial class frmTranCreateStartEndTest : Miracom.MESCore.TranForm02
    {
        public frmTranCreateStartEndTest()
        {
            InitializeComponent();
        }

        private bool fnTran(char cStep)
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode lot_list;

                MPCR.SetInMsg(in_node);

                //cStep 1 : create, cStep 2 : start , cStep 3 : end
                in_node.ProcStep = cStep;
                in_node.AddString("OPER", cdvOperation.Text);
                in_node.AddString("MAT_ID", txtMatid.Text);
                in_node.AddString("FLOW", "F001");

                if (cStep == '1')
                {
                    in_node.AddInt("CREATE_COUNT", MPCF.ToInt(txtCount.Text));
                }
                else
                {
                    for (int i = 0; i < spdLotInfo.ActiveSheet.RowCount; i++)
                    {
                        lot_list = in_node.AddNode("LOT_LIST");
                        lot_list.AddString("LOT_ID", spdLotInfo.ActiveSheet.Cells[i, 1].Text);
                    }
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Test_Process", in_node, ref out_node) == false)
                {
                    return false;
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }



        private void frmTranCreateStartEndTest_Load(object sender, EventArgs e)
        {

        }

        private void btnView_Click(object sender, EventArgs e)
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];                
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "TEST_001";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOperation.Text;

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLotInfo);
                    return;
                }

                MPCF.ClearList(spdLotInfo);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotInfo_Sheet1.RowCount++;

                    spdLotInfo_Sheet1.Cells[i, 0].Value = (i + 1).ToString();
                    spdLotInfo_Sheet1.Cells[i, 1].Value = dt.Rows[i]["LOT_ID"].ToString();
                    spdLotInfo_Sheet1.Cells[i, 2].Value = dt.Rows[i]["LOT_STATUS"].ToString();
                }

                MPCF.FitColumnHeader(spdLotInfo);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnCreate_Click(object sender, EventArgs e)
        {
            try
            {
                if (fnTran('1') == true)
                {
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            try
            {
                if (fnTran('2') == true)
                {
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnEnd_Click(object sender, EventArgs e)
        {
            try
            {
                if (fnTran('3') == true)
                {
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOperation_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvOperation.Init();
                MPCF.InitListView(cdvOperation.GetListView);
                cdvOperation.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOperation.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOperation.SelectedSubItemIndex = 0;

                if (WIPLIST.ViewOperationList(cdvOperation.GetListView, '2', "", 0, "F001", "", null, "") == false)
                {
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void cdvOperation_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            btnView.PerformClick();
        }


    }
}
