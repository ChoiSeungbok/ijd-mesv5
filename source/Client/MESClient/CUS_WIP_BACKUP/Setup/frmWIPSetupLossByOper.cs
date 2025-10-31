using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Miracom.CliFrx;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.DNMCore;

using CUS_COM;

namespace CUS_WIP
{
    public partial class frmWIPSetupLossByOper : Miracom.MESCore.SetupForm02
    {
        public frmWIPSetupLossByOper()
        {
            InitializeComponent();
        }

        private bool b_is_work = false;

        /// <summary>
        /// 공정별 불량 조회
        /// </summary>
        /// <returns></returns>
        private bool View_Loss_By_Oper(string sOper)
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
            DataTable dt = null;
            ListViewItem itmx;
            string sSql = "";
            int i = 0;

            try
            {
                lisAttachLoss.BeginUpdate();
                MPCF.InitListView(lisAttachLoss);

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = sOper;

                if (TPDR.GetDataOne("", ref dt, "CWIP1002-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }

                for(i = 0; i < dt.Rows.Count; i++)
                {
                    itmx = new ListViewItem(dt.Rows[i]["LOSS_CODE"].ToString(), (int)SMALLICON_INDEX.IDX_POLICY);
                    itmx.SubItems.Add(dt.Rows[i]["LOSS_DESC"].ToString());

                    lisAttachLoss.Items.Add(itmx);
                }

                //MPCF.FitColumnHeader(lisAttachLoss);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox($"View_Loss_By_Oper(){ex.Message}");
                return false;
            }
            finally
            {
                lisAttachLoss.EndUpdate();
            }
        }

        private bool Update_Loss_By_oper()
        {
            TRSNode in_node = new TRSNode("Update_Loss_By_Oper_In");
            TRSNode out_node = new TRSNode("Update_Loss_By_Oper_Out");

            TRSNode data_list;

            int i = 0;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.AddString("OPER", lisOperList.SelectedItems[0].Text);

                for(i = 0; i < lisAttachLoss.Items.Count; i++)
                {
                    if (lisAttachLoss.Items[i].SubItems[0].Text != "Attach ...")
                    {
                        data_list = in_node.AddNode("DATA_LIST");
                        data_list.AddString("LOSS_CODE", lisAttachLoss.Items[i].SubItems[0].Text);
                        data_list.AddString("SEQ", i.ToString());
                    }
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Update_Loss_By_Oper", in_node, ref out_node) == false)
                    return false;

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox($"Update_Loss_By_oper() : {ex.Message}");
                return false;
            }
        }

        private void Swap_List_Item(int iAOperSeq, int iBOperSeq)
        {
            string sAOper, sADesc;
            string sBOper, sBDesc;

            //2014.04.03 Optional Group, Option 칼럼의 위치를 Description 다음으로 이동
            sAOper = lisAttachLoss.Items[iAOperSeq].SubItems[0].Text;
            sADesc = lisAttachLoss.Items[iAOperSeq].SubItems[1].Text;

            sBOper = lisAttachLoss.Items[iBOperSeq].SubItems[0].Text;
            sBDesc = lisAttachLoss.Items[iBOperSeq].SubItems[1].Text;

            lisAttachLoss.Items[iAOperSeq].SubItems[0].Text = sBOper;
            lisAttachLoss.Items[iAOperSeq].SubItems[1].Text = sBDesc;

            lisAttachLoss.Items[iBOperSeq].SubItems[0].Text = sAOper;
            lisAttachLoss.Items[iBOperSeq].SubItems[1].Text = sADesc;
        }

        private void pnlAttachOperFill_Resize(object sender, EventArgs e)
        {
            MPCF.FieldAdjust(pnlAttachLossFill, pnlAttachLoss, pnlLossList, pnlAttachLossMid, 40);
        }

        private void frmWIPSetupLossByOper_Load(object sender, EventArgs e)
        {
            MPCF.InitListView(lisOperList);
            MPCF.InitListView(lisAttachLoss);
            MPCF.InitListView(lisLossList);

            if (WIPLIST.ViewOperationList(lisOperList, '1', "", 0, "", "", null, "") == false)
            {
                return;
            }

            lblDataCount.Text = lisOperList.Items.Count.ToString();

            BASLIST.ViewGCMDataList(lisLossList, '1', MPGC.s_loss_table);

            if (lisOperList.Items.Count > 0)
                lisOperList.Items[0].Selected = true;

            MPCF.FitColumnHeader(lisOperList);
            MPCF.FitColumnHeader(lisLossList);
        }

        private void lisOperList_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (lisOperList.SelectedItems.Count > 0)
            {
                View_Loss_By_Oper(lisOperList.SelectedItems[0].Text);

                ListViewItem itmX;

                itmX = lisAttachLoss.Items.Insert(lisAttachLoss.Items.Count, "Attach ...", (int)SMALLICON_INDEX.IDX_OPER);
                itmX.SubItems.Add("");

                lisAttachLoss.Items[0].Selected = true;
                lisAttachLoss.Items[0].EnsureVisible();                
            }
        }

        private void btnToLeft_Click(object sender, EventArgs e)
        {
            try
            {
                string sALoss;
                string sBLoss;
                ListViewItem itmX;
                int idx;
                int i;

                if (lisLossList.SelectedItems.Count <= 0 || lisAttachLoss.SelectedItems.Count <= 0)
                {
                    return;
                }

                for (i = 0; i <= lisLossList.SelectedItems.Count - 1; i++)
                {
                    sALoss = lisLossList.SelectedItems[i].Text;
                    sBLoss = lisAttachLoss.SelectedItems[0].Text;

                    if (sBLoss == "Attach ...")
                    {
                        sBLoss = "";
                    }

                    if (MPCF.FindListItem(lisAttachLoss, sALoss, false) == false)
                    {
                        itmX = lisAttachLoss.Items.Insert(lisAttachLoss.SelectedItems[0].Index, sALoss, (int)SMALLICON_INDEX.IDX_OPER);
                        itmX.SubItems.Add(lisLossList.SelectedItems[i].SubItems[1].Text);
                    }
                }
                if (lisLossList.SelectedItems.Count == 1)
                {
                    idx = lisLossList.SelectedItems[0].Index;
                    if (idx + 1 < lisLossList.Items.Count)
                    {
                        lisLossList.Items[idx].Selected = false;
                        lisLossList.Items[idx + 1].Selected = true;
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnToRight_Click(object sender, EventArgs e)
        {
            int iIdx = 0;
            int i;

            if (lisAttachLoss.SelectedItems.Count <= 0)
            {
                return;
            }
            if (lisAttachLoss.SelectedItems[0].Index >= lisAttachLoss.Items.Count - 1)
            {
                return;
            }

            for (i = lisAttachLoss.SelectedItems.Count - 1; i >= 0; i--)
            {
                if (lisAttachLoss.SelectedItems[i].Text != "Attach ...")
                {
                    iIdx = lisAttachLoss.SelectedItems[i].Index;
                    lisAttachLoss.Items.RemoveAt(iIdx);
                }
            }
            if (lisAttachLoss.Items.Count - 1 == iIdx && iIdx > 0)
            {
                iIdx--;
            }
            lisAttachLoss.Items[iIdx].Selected = true;
        }

        private void btnUp_Click(object sender, EventArgs e)
        {
            string sAOper, sBOper;
            int iAOperSeq, iBOperSeq;
            ListView.SelectedListViewItemCollection lisItems = lisAttachLoss.SelectedItems;

            // 리스트에 아이템이 Attach를 제외하고 한개만 존재할때는 동작하지 않도록 함
            if (lisAttachLoss.Items.Count < 3)
                return;

            // 선택된 아이템이 없는 경우 동작하지 않도록 함
            if (lisItems.Count == 0)
                return;

            // 선택된 아이템이 전체를 천택한 경우 동작하지 않도록 함
            if (lisItems.Count > lisAttachLoss.Items.Count - 2)
                return;

            if (b_is_work == false)
            {
                b_is_work = true;
                for (int i = 0; i < lisItems.Count; i++)
                {
                    if (lisItems[i].Index == 0)
                        continue;

                    if (lisItems[i].Index > lisAttachLoss.Items.Count - 2)
                        continue;

                    iAOperSeq = lisItems[i].Index;
                    iBOperSeq = iAOperSeq - 1;

                    if (lisAttachLoss.Items[iBOperSeq].Selected == true)
                        continue;

                    sAOper = lisAttachLoss.Items[iAOperSeq].Text;
                    sBOper = lisAttachLoss.Items[iBOperSeq].Text;

                    Swap_List_Item(iAOperSeq, iBOperSeq);
                    lisAttachLoss.Items[iAOperSeq].Selected = false;
                    lisAttachLoss.Items[iBOperSeq].Selected = true;

                }
                b_is_work = false;
            }
        }

        private void btnDown_Click(object sender, EventArgs e)
        {
            string sAOper, sBOper;
            int iAOperSeq, iBOperSeq;
            ListView.SelectedListViewItemCollection lisItems = lisAttachLoss.SelectedItems;

            // 리스트에 아이템이 Attach를 제외하고 한개만 존재할때는 동작하지 않도록 함
            if (lisAttachLoss.Items.Count < 3)
                return;

            // 선택된 아이템이 없는 경우 동작하지 않도록 함
            if (lisItems.Count == 0)
                return;

            // 선택된 아이템이 전체를 선택한 경우 동작하지 않도록 함
            if (lisItems.Count > lisAttachLoss.Items.Count - 2)
                return;

            if (b_is_work == false)
            {
                b_is_work = true;
                for (int i = lisItems.Count - 1; i >= 0; i--)
                {
                    if (lisItems[i].Index > lisAttachLoss.Items.Count - 3)
                        continue;

                    iAOperSeq = lisItems[i].Index;
                    iBOperSeq = iAOperSeq + 1;

                    if (lisAttachLoss.Items[iBOperSeq].Selected == true)
                        continue;

                    sAOper = lisAttachLoss.Items[iAOperSeq].Text;
                    sBOper = lisAttachLoss.Items[iBOperSeq].Text;

                    Swap_List_Item(iAOperSeq, iBOperSeq);
                    lisAttachLoss.Items[iAOperSeq].Selected = false;
                    lisAttachLoss.Items[iBOperSeq].Selected = true;
                }
                b_is_work = false;
            }
        }

        private void txtFind_TextChanged(object sender, EventArgs e)
        {
            MPCF.FindListItemPartial(lisOperList, txtFind.Text, 0, true, false);
        }

        private void btnNext_Click(object sender, EventArgs e)
        {
            MPCF.FindListItemNextPartial(lisOperList, txtFind.Text, true, false);
        }

        private void btnRefresh_Click(object sender, EventArgs e)
        {
            try
            {
                lblDataCount.Text = "";
                if (WIPLIST.ViewOperationList(lisOperList, '1', "", 0, "", "", null, "") == false)
                {
                    return;
                }

                try
                {
                    lisLossList.BeginUpdate();
                    BASLIST.ViewGCMDataList(lisLossList, '1', MPGC.s_loss_table);
                }
                finally
                {
                    lisLossList.EndUpdate();
                }

                lblDataCount.Text = lisOperList.Items.Count.ToString();

                if (lisOperList.Items.Count > 0)
                {
                    MPCF.FindListItem(lisOperList, lisOperList.Items[0].Text, false);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            MPCF.ExportToExcel(lisOperList, this.Text, "");
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            if (lisAttachLoss.SelectedItems.Count > 1)
                return;

            if (Update_Loss_By_oper() == false)
                return;
        }
    }
}
