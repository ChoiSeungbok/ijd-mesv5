using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.OleDb;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using Miracom.MsgHandler;
using Miracom.MESCore;
using Miracom.CliFrx;
using Miracom.TRSCore;

namespace Admin.RPTCore
{
    public partial class frmDBReplicationTest : BaseForm01
    {
#region "Variables"
        private TRSNode in_node;
        private TRSNode out_node;
        private string sMessage;
        private bool m_load_flag = false;

#endregion

        public frmDBReplicationTest()
        {
            InitializeComponent();
        }

#region "Form Event"

        private void frmDBReplicationTest_Load(object sender, EventArgs e)
        {
        }

        private void frmDBReplicationTest_Activated(object sender, EventArgs e)
        {
            if(m_load_flag == false)
            {
                return;
            }
            m_load_flag = true;
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Dispose();
        }

        private void btnExecute_Click(object sender, EventArgs e)
        {
            int i;
            int iTemp;
            int iLotCnt, iSeqLen;
            string sSeq;
            string sLot;

            if (lisTable.SelectedIndices.Count <= 0)
                return;

            rtxProgress.Clear();
            rtxProgress.Visible = true;
            btnView.Text = "Close View";
            btnRun.Enabled = false;

            sSeq = lisTable.SelectedItems[0].SubItems[2].Text;
            iSeqLen = sSeq.Length;

            this.Cursor = Cursors.WaitCursor;

            for (iLotCnt = 0; iLotCnt < int.Parse(lisTable.SelectedItems[0].SubItems[3].Text); iLotCnt++)
            {
                sLot = lisTable.SelectedItems[0].SubItems[1].Text + sSeq;
                rtxProgress.AppendText("Process Lot Id: " + sLot.Trim() + "\n");
                for (i = 1; i < lisColList.Items.Count; i = i + 2)
                {
                    sMessage = "";
                    rtxProgress.AppendText("      => " + lisColList.Items[i].Text.ToUpper().Trim() + "\n");
                    if (lisColList.Items[i].Text.ToUpper().Trim() == "CREATE")
                    {
                        if (exeCreate(sLot, i) == true)
                            rtxProgress.AppendText("          => Success.\n");
                        else
                            rtxProgress.AppendText("          => " + sMessage + "\n");
                    }
                    if (lisColList.Items[i].Text.ToUpper().Trim() == "START")
                    {
                        if (exeStart(sLot, i) == true)
                            rtxProgress.AppendText("          => Success.\n");
                        else
                            rtxProgress.AppendText("          => " + sMessage + "\n");
                    }
                    if (lisColList.Items[i].Text.ToUpper().Trim() == "END")
                    {
                        if (exeEnd(sLot, i) == true)
                            rtxProgress.AppendText("          => Success.\n");
                        else
                            rtxProgress.AppendText("          => " + sMessage + "\n");
                    }
                    if (lisColList.Items[i].Text.ToUpper().Trim() == "HOLD")
                    {
                        if (exeHold(sLot, i) == true)
                            rtxProgress.AppendText("          => Success.\n");
                        else
                            rtxProgress.AppendText("          => " + sMessage + "\n");
                    }
                    if (lisColList.Items[i].Text.ToUpper().Trim() == "RELEASE")
                    {
                        if (exeRelease(sLot, i) == true)
                            rtxProgress.AppendText("          => Success.\n");
                        else
                            rtxProgress.AppendText("          => " + sMessage + "\n");
                    }
                    if (lisColList.Items[i].Text.ToUpper().Trim() == "SPLIT(LOT)")
                    {
                        if (exeSplit(sLot, i) == true)
                            rtxProgress.AppendText("          => Success.\n");
                        else
                            rtxProgress.AppendText("          => " + sMessage + "\n");
                    }
                    if (lisColList.Items[i].Text.ToUpper().Trim() == "MERGE")
                    {
                        if (exeMerge(sLot, i) == true)
                            rtxProgress.AppendText("          => Success.\n");
                        else
                            rtxProgress.AppendText("          => " + sMessage + "\n");
                    }
                    if (lisColList.Items[i].Text.ToUpper().Trim() == "ADAPT")
                    {
                        if (exeAdapt(sLot, i) == true)
                            rtxProgress.AppendText("          => Success.\n");
                        else
                            rtxProgress.AppendText("          => " + sMessage + "\n");
                    }
                    if (lisColList.Items[i].Text.ToUpper().Trim() == "STORE")
                    {
                        if (exeStore(sLot, i) == true)
                            rtxProgress.AppendText("          => Success.\n");
                        else
                            rtxProgress.AppendText("          => " + sMessage + "\n");
                    }
                    if (lisColList.Items[i].Text.ToUpper().Trim() == "UNSTORE")
                    {
                        if (exeUnStore(sLot, i) == true)
                            rtxProgress.AppendText("          => Success.\n");
                        else
                            rtxProgress.AppendText("          => " + sMessage + "\n");
                    }
                    if (lisColList.Items[i].Text.ToUpper().Trim() == "REWORK")
                    {
                        if (exeRework(sLot, i) == true)
                            rtxProgress.AppendText("          => Success.\n");
                        else
                            rtxProgress.AppendText("          => " + sMessage + "\n");
                    }
                    if (lisColList.Items[i].Text.ToUpper().Trim() == "LOSS(LOT)")
                    {
                        if (exeLoss(sLot, i) == true)
                            rtxProgress.AppendText("          => Success.\n");
                        else
                            rtxProgress.AppendText("          => " + sMessage + "\n");
                    }
                    rtxProgress.ScrollToCaret();
                    System.Threading.Thread.Sleep(3000);
                }
                iTemp = int.Parse(sSeq) + 1;
                sSeq = iTemp.ToString().PadLeft(10,'0');
                sSeq = sSeq.Substring(sSeq.Length - iSeqLen);
            }
            this.Cursor = Cursors.Default;

            MPCF.ShowMsgBox("Test Lot Generated and Executed.", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
        }

        private void lisTable_Click(object sender, EventArgs e)
        {
            OleDbConnection cn;
            OleDbDataAdapter cmd;
            DataSet ds;
            int i, j;
            string sFileName;
            lisColList.Items.Clear();
            if ( rtxProgress.Visible == true)
            {
                rtxProgress.Visible = false;
                btnView.Text = "View Log";
                btnRun.Enabled = true;
            }

            try
            {
                System.Windows.Forms.Cursor.Current = Cursors.WaitCursor;
                sFileName = lisTable.SelectedItems[0].Text.ToString();
                cn = new OleDbConnection("provider=Microsoft.Jet.OLEDB.4.0;" +
                        "data source=" + sFileName + ";Extended Properties=\"Excel 8.0;IMEX=1\"");
                cmd = new OleDbDataAdapter("select * from [Data$] where transaction <> NULL ", cn);
                ds = new DataSet();
                cn.Open();
                cmd.Fill(ds);
                cn.Close();

                for (i = 0; i < ds.Tables[0].Rows.Count; i++)
                {
                    ListViewItem item1 = new ListViewItem("");
                    for (j = 1; j < ds.Tables[0].Columns.Count; j++)
                    {
                        if (ds.Tables[0].Rows[i][j].ToString().Trim() != "")
                        {
                            item1.SubItems.Add(ds.Tables[0].Columns[j].ToString().Trim());
                        }
                    }
                    item1.BackColor = Color.Gray;
                    item1.ForeColor = Color.White;
                    lisColList.Items.Add(item1);

                    ListViewItem item2 = new ListViewItem(ds.Tables[0].Rows[i][0].ToString().Trim());
                    for (j = 1; j < ds.Tables[0].Columns.Count; j++)
                    {
                        if (ds.Tables[0].Rows[i][j].ToString().Trim() != "")
                        {
                            item2.SubItems.Add(ds.Tables[0].Rows[i][j].ToString().Trim());
                        }
                    }
                    if (((int)i / 2) * 2 == i)
                    {
                        item2.BackColor = Color.Yellow;
                    }
                    else
                    {
                        item2.BackColor = Color.Yellow;
                    }
                    lisColList.Items.Add(item2);
                }
                for (j = 0; j < lisColList.Columns.Count; j++)
                {
                    lisColList.Columns[j].Width = -1;
                }
            }
            catch(Exception ex)
            {
                System.Windows.Forms.Cursor.Current = Cursors.Default;
                MPCF.ShowMsgBox(ex.Message, "Open File", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                return;
            }

            System.Windows.Forms.Cursor.Current = Cursors.Default;
            return;
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void btnFileDialog_Click(object sender, EventArgs e)
        {
            Stream myStream = null;
            OpenFileDialog openFileDialog1 = new OpenFileDialog();

            openFileDialog1.InitialDirectory = "c:\\";
            openFileDialog1.Filter = "Microsoft Office Excel Workbook (*.xls)|*.xls";
            openFileDialog1.FilterIndex = 2;
            openFileDialog1.RestoreDirectory = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    if ((myStream = openFileDialog1.OpenFile()) != null)
                    {
                        using (myStream)
                        {
                            txtFileName.Text = openFileDialog1.FileName.ToString();
                        }
                    }
                }
                catch (Exception ex)
                {
                    MPCF.ShowMsgBox("Could not read file from disk. Original error: " + ex.Message, "Open File", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                }
            }

        }

        private void btnLoad_Click(object sender, EventArgs e)
        {

            if (txtFileName.Text.ToString() == "")
            {
                MPCF.ShowMsgBox("File Name Cannot be Blank. ", "Load", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                return;
            }
            if (txtLotId.Text.ToString() == "")
            {
                MPCF.ShowMsgBox("Lot Id Cannot be Blank. ", "Load", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                return;
            }
            if (txtCount.Text.ToString() == "")
            {
                MPCF.ShowMsgBox("Count Cannot be Blank. ", "Load", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                return;
            }
            else
            {
                if (int.Parse(txtCount.Text.ToString().Trim()) == 0)
                {
                    MPCF.ShowMsgBox("Count Cannot be zero. ", "Load", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                    return;
                }
            }


            if (txtSeq.Text.ToString().Trim() == "")
            {
                txtSeq.Text = "001";
            }
            else
            {
                if (int.Parse(txtSeq.Text.ToString().Trim()) == 0)
                {
                    MPCF.ShowMsgBox("Sequence Cannot be zero. ", "Load", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                    return;
                }
            }

            ListViewItem item1 = new ListViewItem(txtFileName.Text.ToString().Trim());
            item1.SubItems.Add(txtLotId.Text.ToString().Trim());
            item1.SubItems.Add(txtSeq.Text.ToString().Trim());
            item1.SubItems.Add(txtCount.Text.ToString().Trim());
            lisTable.Items.Add(item1);
        }

        private void txtSeq_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsNumber(e.KeyChar) && e.KeyChar != '\b')
                e.Handled = true;
        }

        private void txtCount_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsNumber(e.KeyChar) && e.KeyChar != '\b')
                e.Handled = true;
        }

        private void btnView_Click(object sender, EventArgs e)
        {
            if (rtxProgress.Visible == false)
            {
                rtxProgress.Visible = true;
                btnView.Text = "Close View";
                btnRun.Enabled = false;
            }
            else
            {
                rtxProgress.Visible = false;
                btnView.Text = "View Log";
                btnRun.Enabled = true;
            }

        }

#endregion

#region "Procedure and Function"

        private bool exeViewLot(string sLot)
        {
            TRSNode in_ViewNode = new TRSNode("VIEW_LOT_IN");
            out_node = new TRSNode("VIEW_LOT_OUT");

            MPCR.SetInMsg(in_ViewNode);
            in_ViewNode.ProcStep = '1';
            in_ViewNode.AddString("LOT_ID", sLot.ToUpper());

            if (MPCR.CallService("WIP", "WIP_View_Lot", in_ViewNode, ref out_node, txtChannel.Text.ToString(), 0, DeliveryMode.RReply, true) == false)
            {
                sMessage = out_node.Msg.ToString();
                return false;
            }
            return true;
        }

        private bool exeCreate(string sLot, int i)
        {
            int j;
            in_node = new TRSNode("CREATE_LOT_IN");
            out_node = new TRSNode("CMN_OUT");
            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';
            in_node.AddString("LOT_ID", sLot.Trim());
            in_node.AddString("LOT_DESC", MPCF.Trim("Replication Test Lot Auto Created"));

            try
            {
                for (j = 1; j < lisColList.Items[i - 1].SubItems.Count; j++)
                {
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "MAT_ID")
                        in_node.AddString("MAT_ID", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "MAT_VER")
                        in_node.AddInt("MAT_VER", int.Parse(lisColList.Items[i].SubItems[j].Text.ToUpper().Trim()));
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "FLOW")
                        in_node.AddString("FLOW", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "FLOW_SEQ_NUM")
                        in_node.AddInt("FLOW_SEQ_NUM", int.Parse(lisColList.Items[i].SubItems[j].Text.ToUpper().Trim()));
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "OPER")
                        in_node.AddString("OPER", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "LOT_TYPE")
                        in_node.AddChar("LOT_TYPE", char.Parse(lisColList.Items[i].SubItems[j].Text.ToUpper().Trim().Substring(0, 1)));
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "QTY_1")
                        in_node.AddDouble("QTY_1", double.Parse(lisColList.Items[i].SubItems[j].Text.ToUpper().Trim()));
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "QTY_2")
                        in_node.AddDouble("QTY_2", double.Parse(lisColList.Items[i].SubItems[j].Text.ToUpper().Trim()));
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "QTY_3")
                        in_node.AddDouble("QTY_3", double.Parse(lisColList.Items[i].SubItems[j].Text.ToUpper().Trim()));
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "CREATE_CODE")
                        in_node.AddString("CREATE_CODE", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "OWNER_CODE")
                        in_node.AddString("OWNER_CODE", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "LOT_PRIORITY")
                        in_node.AddChar("LOT_PRIORITY", char.Parse(lisColList.Items[i].SubItems[j].Text.ToUpper().Trim().Substring(0, 1)));
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "DUE_TIME")
                        in_node.AddString("DUE_TIME", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "OPER")
                        in_node.AddString("TO_OPER", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                }
                if (MPCR.CallService("WIP", "WIP_Create_Lot", in_node, ref out_node, txtChannel.Text.ToString(),0, DeliveryMode.RReply, true ) == false)
                {
                    return false;
                }
                if (out_node.StatusValue.ToString() == "0")
                    return true;
                else
                {
                    sMessage = out_node.Msg.ToString();
                    return false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool exeStart(string sLot, int i)
        {
            int j;

            if (exeViewLot(sLot.ToUpper()) == false)
                return false;

            in_node.ProcStep = '1';
            in_node.AddString("LOT_ID", sLot.ToUpper());
            in_node = new TRSNode("START_LOT_IN");
            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';
            in_node.AddString("LOT_ID", sLot.Trim());
            in_node.AddString("MAT_ID", out_node.GetString("MAT_ID"));
            in_node.AddInt("MAT_VER", out_node.GetInt("MAT_VER"));
            in_node.AddString("FLOW", out_node.GetString("FLOW"));
            in_node.AddInt("FLOW_SEQ_NUM", out_node.GetInt("FLOW_SEQ_NUM"));
            in_node.AddString("OPER", out_node.GetString("OPER"));
            in_node.AddInt("LAST_ACTIVE_HIST_SEQ", out_node.GetInt("LAST_HIST_SEQ"));

            out_node = new TRSNode("CMN_OUT");

            try
            {
                for (j = 1; j < lisColList.Items[i - 1].SubItems.Count; j++)
                {
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "RES_ID")
                        in_node.AddString("RES_ID", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                }
                if (MPCR.CallService("WIP", "WIP_Start_Lot", in_node, ref out_node, txtChannel.Text.ToString(), 0, DeliveryMode.RReply, true) == false)
                {
                    return false;
                }
                if (out_node.StatusValue.ToString() == "0")
                    return true;
                else
                {
                    sMessage = out_node.Msg.ToString();
                    return false;
                }
                //                MPCR.ShowSuccessMsg(out_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool exeEnd(string sLot, int i)
        {
            int j;

            if (exeViewLot(sLot.ToUpper()) == false)
                return false;

            in_node = new TRSNode("END_LOT_IN");
            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';
            in_node.AddString("LOT_ID", sLot.Trim());
            in_node.AddString("MAT_ID", out_node.GetString("MAT_ID"));
            in_node.AddInt("MAT_VER", out_node.GetInt("MAT_VER"));
            in_node.AddString("FLOW", out_node.GetString("FLOW"));
            in_node.AddInt("FLOW_SEQ_NUM", out_node.GetInt("FLOW_SEQ_NUM"));
            in_node.AddString("OPER", out_node.GetString("OPER"));
            in_node.AddInt("LAST_ACTIVE_HIST_SEQ", out_node.GetInt("LAST_HIST_SEQ"));
            in_node.AddString("RES_ID", out_node.GetString("START_RES_ID"));

            out_node = new TRSNode("CMN_OUT");

            try
            {
                for (j = 1; j < lisColList.Items[i - 1].SubItems.Count; j++)
                {
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "TO_FLOW")
                        in_node.AddString("TO_FLOW", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "TO_FLOW_SEQ_NUM")
                        in_node.AddString("TO_FLOW_SEQ_NUM", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "TO_OPER")
                        in_node.AddString("TO_OPER", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                }
                if (MPCR.CallService("WIP", "WIP_End_Lot", in_node, ref out_node, txtChannel.Text.ToString(), 0, DeliveryMode.RReply, true) == false)
                {
                    return false;
                }
                if (out_node.StatusValue.ToString() == "0")
                    return true;
                else
                {
                    sMessage = out_node.Msg.ToString();
                    return false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool exeHold(string sLot, int i)
        {
            int j;


            if (exeViewLot(sLot.ToUpper()) == false)
                return false;

            in_node = new TRSNode("HOLD_LOT_IN");
            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';
            in_node.AddInt("LAST_ACTIVE_HIST_SEQ", out_node.GetInt("LAST_HIST_SEQ"));
            in_node.AddString("LOT_ID", sLot.Trim());
            in_node.AddString("MAT_ID", out_node.GetString("MAT_ID"));
            in_node.AddInt("MAT_VER", out_node.GetInt("MAT_VER"));
            in_node.AddString("FLOW", out_node.GetString("FLOW"));
            in_node.AddInt("FLOW_SEQ_NUM", out_node.GetInt("FLOW_SEQ_NUM"));
            in_node.AddString("OPER", out_node.GetString("OPER"));

            out_node = new TRSNode("CMN_OUT");

            try
            {
                for (j = 1; j < lisColList.Items[i - 1].SubItems.Count; j++)
                {
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "HOLD_CODE")
                        in_node.AddString("HOLD_CODE", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "HOLD_PASSWORD")
                        in_node.AddString("HOLD_PASSWORD", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                }
                if (MPCR.CallService("WIP", "WIP_Hold_Lot", in_node, ref out_node, txtChannel.Text.ToString(), 0, DeliveryMode.RReply, true) == false)
                {
                    return false;
                }
                if (out_node.StatusValue.ToString() == "0")
                    return true;
                else
                {
                    sMessage = out_node.Msg.ToString();
                    return false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool exeRelease(string sLot, int i)
        {
            int j;


            if (exeViewLot(sLot.ToUpper()) == false)
                return false;

            in_node = new TRSNode("RELEASE_LOT_IN");
            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';
            in_node.AddInt("LAST_ACTIVE_HIST_SEQ", out_node.GetInt("LAST_HIST_SEQ"));
            in_node.AddString("LOT_ID", sLot.Trim());
            in_node.AddString("MAT_ID", out_node.GetString("MAT_ID"));
            in_node.AddInt("MAT_VER", out_node.GetInt("MAT_VER"));
            in_node.AddString("FLOW", out_node.GetString("FLOW"));
            in_node.AddInt("FLOW_SEQ_NUM", out_node.GetInt("FLOW_SEQ_NUM"));
            in_node.AddString("OPER", out_node.GetString("OPER"));

            out_node = new TRSNode("CMN_OUT");

            try
            {
                for (j = 1; j < lisColList.Items[i - 1].SubItems.Count; j++)
                {
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "HOLD_CODE")
                        in_node.AddString("HOLD_CODE", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "HOLD_PASSWORD")
                        in_node.AddString("HOLD_PASSWORD", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "RELEASE_CODE")
                        in_node.AddString("RELEASE_CODE", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                }
                if (MPCR.CallService("WIP", "WIP_Release_Lot", in_node, ref out_node, txtChannel.Text.ToString(), 0, DeliveryMode.RReply, true) == false)
                {
                    return false;
                }
                if (out_node.StatusValue.ToString() == "0")
                    return true;
                else
                {
                    sMessage = out_node.Msg.ToString();
                    return false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool exeSplit(string sLot, int i)
        {
            int j;
            string[] oneChildLot;
            string[] oneMoveQty1;
            string[] oneMoveQty2;
            string[] oneMoveQty3;

            if (exeViewLot(sLot.ToUpper()) == false)
                return false;

            in_node = new TRSNode("SPLIT_LOT_IN");
            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';
            in_node.AddInt("LAST_ACTIVE_HIST_SEQ", out_node.GetInt("LAST_HIST_SEQ"));
            in_node.AddString("LOT_ID", sLot.Trim());
            in_node.AddString("MAT_ID", out_node.GetString("MAT_ID"));
            in_node.AddInt("MAT_VER", out_node.GetInt("MAT_VER"));
            in_node.AddString("FLOW", out_node.GetString("FLOW"));
            in_node.AddInt("FLOW_SEQ_NUM", out_node.GetInt("FLOW_SEQ_NUM"));
            in_node.AddString("OPER", out_node.GetString("OPER"));

            in_node.AddString("CHILD_LOT_DESC", out_node.GetString("LOT_DESC"));
            in_node.AddString("CHILD_MAT_ID", out_node.GetString("MAT_ID"));
            in_node.AddInt("CHILD_MAT_VER", out_node.GetInt("MAT_VER"));
            in_node.AddString("CHILD_FLOW", out_node.GetString("FLOW"));
            in_node.AddInt("CHILD_FLOW_SEQ_NUM", out_node.GetInt("FLOW_SEQ_NUM"));
            in_node.AddString("CHILD_OPER", out_node.GetString("OPER"));

            in_node.AddString("CHILD_CREATE_CODE", out_node.GetString("CREATE_CODE"));
            in_node.AddString("CHILD_OWNER_CODE", out_node.GetString("OWNER_CODE"));
            in_node.AddString("CHILD_PRIORITY", out_node.GetString("PRIORITY"));

            in_node.AddDouble("MOVE_QTY_1", 0);
            in_node.AddDouble("MOVE_QTY_2", 0);
            in_node.AddDouble("MOVE_QTY_3", 0);

            out_node = new TRSNode("CMN_OUT");
            oneChildLot = new String[] { "" };
            oneMoveQty1 = new String[] { "" };
            oneMoveQty2 = new String[] { "" };
            oneMoveQty3 = new String[] { "" };

            try
            {
                for (j = 1; j < lisColList.Items[i - 1].SubItems.Count; j++)
                {
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "CHILD_CRR_ID" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.AddString("CHILD_CRR_ID", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "CHILD_LOT_ID" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        oneChildLot = lisColList.Items[i].SubItems[j].Text.ToUpper().Trim().Split(new Char[] { ' ', ',', ';' });
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "CHILD_MAT_ID" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.AddString("CHILD_MAT_ID", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "CHILD_MAT_VER" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.AddString("CHILD_MAT_VER", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "CHILD_FLOW" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.AddString("CHILD_FLOW", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "CHILD_FLOW_SEQ_NUM" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.AddString("CHILD_FLOW_SEQ_NUM", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "CHILD_OPER" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.AddString("CHILD_OPER", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "CHILD_CREATE_CODE" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.AddString("CHILD_CREATE_CODE", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "CHILD_OWNER_CODE" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.AddString("CHILD_OWNER_CODE", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "CHILD_PRIORITY" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.AddString("CHILD_PRIORITY", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "MOVE_QTY_1" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        oneMoveQty1 = lisColList.Items[i].SubItems[j].Text.ToUpper().Trim().Split(new Char[] { ' ', ',', ';' });
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "MOVE_QTY_2" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        oneMoveQty2 = lisColList.Items[i].SubItems[j].Text.ToUpper().Trim().Split(new Char[] { ' ', ',', ';' });
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "MOVE_QTY_3" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        oneMoveQty3 = lisColList.Items[i].SubItems[j].Text.ToUpper().Trim().Split(new Char[] { ' ', ',', ';' });
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "CHILD_DUE_TIME" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.AddString("CHILD_DUE_TIME", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                }

                if (oneChildLot.GetLength(0) != oneMoveQty1.GetLength(0))
                {
                    sMessage = "Child Lot Count and Move Qty Count different";
                    return false;
                }

                for (j = 0; j < oneChildLot.GetLength(0); j++)
                {
                    if (exeViewLot(sLot.ToUpper()) == false)
                        return false;
                    in_node.SetInt("LAST_ACTIVE_HIST_SEQ", out_node.GetInt("LAST_HIST_SEQ"));
                    out_node = new TRSNode("CMN_OUT");
                    in_node.SetString("CHILD_LOT_ID", sLot.ToString() + "." + oneChildLot[j].ToString().Trim());
                    in_node.SetDouble("MOVE_QTY_1", double.Parse(oneMoveQty1[j].ToString()));
                    if (oneMoveQty2.GetLength(0) > j && oneMoveQty2[j].ToString() != "")
                        in_node.SetDouble("MOVE_QTY_2", double.Parse(oneMoveQty2[j].ToString()));
                    else
                        in_node.SetDouble("MOVE_QTY_2", 0);
                    if (oneMoveQty3.GetLength(0) > j && oneMoveQty2[j].ToString() != "")
                        in_node.SetDouble("MOVE_QTY_3", double.Parse(oneMoveQty3[j].ToString()));
                    else
                        in_node.SetDouble("MOVE_QTY_3", 0);
                    rtxProgress.AppendText("          => "+sLot.ToString() + "."+oneChildLot[j].ToString());
                    if (MPCR.CallService("WIP", "WIP_Split_Lot", in_node, ref out_node, txtChannel.Text.ToString(), 0, DeliveryMode.RReply, true) == false)
                    {
                        return false;
                    }
                    if (out_node.StatusValue.ToString() == "0")
                        rtxProgress.AppendText(" --> Done\n");
                    else
                        rtxProgress.AppendText(" --> Fail --> " + out_node.Msg.ToString() + "\n");
                    rtxProgress.ScrollToCaret();
                    System.Threading.Thread.Sleep(1000);
                }
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool exeMerge(string sLot, int i)
        {
            int j;
            string[] oneChildLot;
            string[] oneMoveQty1;
            string[] oneMoveQty2;
            string[] oneMoveQty3;

            if (exeViewLot(sLot.ToUpper()) == false)
                return false;

            in_node = new TRSNode("MERGE_LOT_IN");
            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';
            in_node.AddInt("LAST_ACTIVE_HIST_SEQ", out_node.GetInt("LAST_HIST_SEQ"));
            in_node.AddString("INTO_LOT_ID", sLot.Trim());
            in_node.AddString("MAT_ID", out_node.GetString("MAT_ID"));
            in_node.AddInt("MAT_VER", out_node.GetInt("MAT_VER"));
            in_node.AddString("FLOW", out_node.GetString("FLOW"));
            in_node.AddInt("FLOW_SEQ_NUM", out_node.GetInt("FLOW_SEQ_NUM"));
            in_node.AddString("OPER", out_node.GetString("OPER"));
            in_node.AddDouble("MOVE_QTY_1", 0);
            in_node.AddDouble("MOVE_QTY_2", 0);
            in_node.AddDouble("MOVE_QTY_3", 0);
            in_node.AddChar("NO_AUTOMATIC_TERMINATE_LOT", 'Y');

            out_node = new TRSNode("CMN_OUT");
            oneChildLot = new String[] { "" };
            oneMoveQty1 = new String[] { "" };
            oneMoveQty2 = new String[] { "" };
            oneMoveQty3 = new String[] { "" };

            try
            {
                for (j = 1; j < lisColList.Items[i - 1].SubItems.Count; j++)
                {
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "CHILD_CRR_ID" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.AddString("CHILD_CRR_ID", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "CHILD_LOT_ID" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        oneChildLot = lisColList.Items[i].SubItems[j].Text.ToUpper().Trim().Split(new Char[] { ' ', ',', ';' });
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "MOVE_QTY_1" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        oneMoveQty1 = lisColList.Items[i].SubItems[j].Text.ToUpper().Trim().Split(new Char[] { ' ', ',', ';' });
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "MOVE_QTY_2" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        oneMoveQty2 = lisColList.Items[i].SubItems[j].Text.ToUpper().Trim().Split(new Char[] { ' ', ',', ';' });
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "MOVE_QTY_3" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        oneMoveQty3 = lisColList.Items[i].SubItems[j].Text.ToUpper().Trim().Split(new Char[] { ' ', ',', ';' });
                }

                if (oneChildLot.GetLength(0) != oneMoveQty1.GetLength(0))
                {
                    sMessage = "Child Lot Count and Move Qty Count different";
                    return false;
                }

                for (j = 0; j < oneChildLot.GetLength(0); j++)
                {
                    if (exeViewLot(sLot.ToString() + "." + oneChildLot[j].ToString().Trim()) == false)
                        return false;
                    in_node.SetInt("LAST_ACTIVE_HIST_SEQ", out_node.GetInt("LAST_HIST_SEQ"));
                    in_node.SetString("LOT_ID", sLot.ToString() + "." + oneChildLot[j].ToString().Trim());
                    in_node.SetString("MAT_ID", out_node.GetString("MAT_ID"));
                    in_node.SetInt("MAT_VER", out_node.GetInt("MAT_VER"));
                    in_node.SetString("FLOW", out_node.GetString("FLOW"));
                    in_node.SetInt("FLOW_SEQ_NUM", out_node.GetInt("FLOW_SEQ_NUM"));
                    in_node.SetString("OPER", out_node.GetString("OPER"));
                    out_node = new TRSNode("CMN_OUT");

                    in_node.SetDouble("MOVE_QTY_1", double.Parse(oneMoveQty1[j].ToString()));
                    if (oneMoveQty2.GetLength(0) > j && oneMoveQty2[j].ToString() != "")
                        in_node.SetDouble("MOVE_QTY_2", double.Parse(oneMoveQty2[j].ToString()));
                    else
                        in_node.SetDouble("MOVE_QTY_2", 0);
                    if (oneMoveQty3.GetLength(0) > j && oneMoveQty2[j].ToString() != "")
                        in_node.SetDouble("MOVE_QTY_3", double.Parse(oneMoveQty3[j].ToString()));
                    else
                        in_node.SetDouble("MOVE_QTY_3", 0);
                    rtxProgress.AppendText("          => " + sLot.ToString() + "." + oneChildLot[j].ToString());
                    if (MPCR.CallService("WIP", "WIP_Merge_Lot", in_node, ref out_node, txtChannel.Text.ToString(), 0, DeliveryMode.RReply, true) == false)
                    {
                        return false;
                    }
                    if (out_node.StatusValue.ToString() == "0")
                        rtxProgress.AppendText(" --> Done\n");
                    else
                        rtxProgress.AppendText(" --> Fail --> " + out_node.Msg.ToString() + "\n");
                    rtxProgress.ScrollToCaret();
                    System.Threading.Thread.Sleep(1000);
                }
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool exeAdapt(string sLot, int i)
        {
            int j;

            if (exeViewLot(sLot.ToUpper()) == false)
                return false;

            in_node = new TRSNode("ADAPT_LOT_IN");
            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';
            in_node.AddInt("LAST_ACTIVE_HIST_SEQ", out_node.GetInt("LAST_HIST_SEQ"));
            in_node.AddString("LOT_ID", sLot.Trim());
            in_node.AddString("MAT_ID", out_node.GetString("MAT_ID"));
            in_node.AddInt("MAT_VER", out_node.GetInt("MAT_VER"));
            in_node.AddString("FLOW", out_node.GetString("FLOW"));
            in_node.AddInt("FLOW_SEQ_NUM", out_node.GetInt("FLOW_SEQ_NUM"));
            in_node.AddString("OPER", out_node.GetString("OPER"));

            in_node.AddString("TO_MAT_ID", out_node.GetString("MAT_ID"));
            in_node.AddInt("TO_MAT_VER", out_node.GetInt("MAT_VER"));
            in_node.AddString("TO_FLOW", out_node.GetString("FLOW"));
            in_node.AddInt("TO_FLOW_SEQ_NUM", out_node.GetInt("FLOW_SEQ_NUM"));

            out_node = new TRSNode("CMN_OUT");

            try
            {
                for (j = 1; j < lisColList.Items[i - 1].SubItems.Count; j++)
                {
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "TO_OPER")
                        in_node.AddString("TO_OPER", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                }
                if (MPCR.CallService("WIP", "WIP_Adapt_Lot", in_node, ref out_node, txtChannel.Text.ToString(), 0, DeliveryMode.RReply, true) == false)
                {
                    return false;
                }
                if (out_node.StatusValue.ToString() == "0")
                    return true;
                else
                {
                    sMessage = out_node.Msg.ToString();
                    return false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool exeStore(string sLot, int i)
        {
            int j;

            if (exeViewLot(sLot.ToUpper()) == false)
                return false;

            in_node = new TRSNode("STORE_LOT_IN");
            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';
            in_node.AddInt("LAST_ACTIVE_HIST_SEQ", out_node.GetInt("LAST_HIST_SEQ"));
            in_node.AddString("LOT_ID", sLot.Trim());
            in_node.AddString("MAT_ID", out_node.GetString("MAT_ID"));
            in_node.AddInt("MAT_VER", out_node.GetInt("MAT_VER"));
            in_node.AddString("FLOW", out_node.GetString("FLOW"));
            in_node.AddInt("FLOW_SEQ_NUM", out_node.GetInt("FLOW_SEQ_NUM"));
            in_node.AddString("OPER", out_node.GetString("OPER"));

            out_node = new TRSNode("CMN_OUT");

            try
            {
                for (j = 1; j < lisColList.Items[i - 1].SubItems.Count; j++)
                {
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "TO_OPER")
                        in_node.AddString("TO_OPER", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                }
                if (MPCR.CallService("WIP", "WIP_Store_Lot", in_node, ref out_node, txtChannel.Text.ToString(), 0, DeliveryMode.RReply, true) == false)
                {
                    return false;
                }
                if (out_node.StatusValue.ToString() == "0")
                    return true;
                else
                {
                    sMessage = out_node.Msg.ToString();
                    return false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool exeUnStore(string sLot, int i)
        {
            int j;

            if (exeViewLot(sLot.ToUpper()) == false)
                return false;

            in_node = new TRSNode("Unstore_LOT");
            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';
            in_node.AddInt("LAST_ACTIVE_HIST_SEQ", out_node.GetInt("LAST_HIST_SEQ"));
            in_node.AddString("LOT_ID", sLot.Trim());
            in_node.AddString("MAT_ID", out_node.GetString("MAT_ID"));
            in_node.AddInt("MAT_VER", out_node.GetInt("MAT_VER"));
            in_node.AddString("FLOW", out_node.GetString("FLOW"));
            in_node.AddInt("FLOW_SEQ_NUM", out_node.GetInt("FLOW_SEQ_NUM"));
            in_node.AddString("OPER", out_node.GetString("OPER"));

            in_node.AddString("TO_FLOW", out_node.GetString("FLOW"));
            in_node.AddInt("TO_FLOW_SEQ_NUM", out_node.GetInt("FLOW_SEQ_NUM"));

            out_node = new TRSNode("CMN_OUT");

            try
            {
                for (j = 1; j < lisColList.Items[i - 1].SubItems.Count; j++)
                {
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "TO_FLOW" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.SetString("TO_FLOW", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "TO_FLOW_SEQ_NUM" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.SetInt("TO_FLOW_SEQ_NUM", int.Parse(lisColList.Items[i].SubItems[j].Text.ToUpper().Trim()));
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "TO_OPER")
                        in_node.AddString("TO_OPER", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                }
                if (MPCR.CallService("WIP", "WIP_Unstore_Lot", in_node, ref out_node, txtChannel.Text.ToString(), 0, DeliveryMode.RReply, true) == false)
                {
                    return false;
                }
                if (out_node.StatusValue.ToString() == "0")
                    return true;
                else
                {
                    sMessage = out_node.Msg.ToString();
                    return false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }
        
        public bool exeRework(string sLot, int i)
        {
            int j;

            if (exeViewLot(sLot.ToUpper()) == false)
                return false;

            TRSNode in_node1 = new TRSNode("VIEW_REWORK_FLOW_LIST_IN");
            TRSNode out_node1 = new TRSNode("VIEW_REWORK_FLOW_LIST_OUT");
            MPCR.SetInMsg(in_node1);
            in_node1.ProcStep = '4';
            in_node1.AddString("MAT_ID", out_node.GetString("MAT_ID"));
            in_node1.AddInt("MAT_VER", out_node.GetInt("MAT_VER"));
            in_node1.AddString("FLOW", out_node.GetString("FLOW"));
            in_node1.AddString("OPER", out_node.GetString("OPER"));

            try
            {
                for (j = 1; j < lisColList.Items[i - 1].SubItems.Count; j++)
                {
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "RWK_CODE")
                        in_node1.AddString("RWK_CODE", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                }
                if (MPCR.CallService("WIP", "WIP_View_Rework_Flow_List", in_node1, ref out_node1, txtChannel.Text.ToString(), 0, DeliveryMode.RReply, true) == false)
                {
                    sMessage = out_node1.Msg.ToString();
                    return false;
                }
                if (out_node1.StatusValue.ToString() != "0")
                {
                    sMessage = out_node1.Msg.ToString();
                    return false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            in_node = new TRSNode("REWORK_LOT_IN");
            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';
            in_node.AddInt("LAST_ACTIVE_HIST_SEQ", out_node.GetInt("LAST_HIST_SEQ"));
            in_node.AddString("LOT_ID", sLot.Trim());
            in_node.AddString("MAT_ID", out_node.GetString("MAT_ID"));
            in_node.AddInt("MAT_VER", out_node.GetInt("MAT_VER"));
            in_node.AddString("FLOW", out_node.GetString("FLOW"));
            in_node.AddInt("FLOW_SEQ_NUM", out_node.GetInt("FLOW_SEQ_NUM"));
            in_node.AddString("OPER", out_node.GetString("OPER"));
            in_node.AddDouble("QTY_1", -1);
            in_node.AddDouble("QTY_2", -1);
            in_node.AddDouble("QTY_3", -1);
            in_node.AddString("TO_FLOW", " ");
            in_node.AddInt("TO_FLOW_SEQ_NUM", 0);
            in_node.AddString("TO_OPER", " ");
            in_node.AddString("RET_FLOW", " ");
            in_node.AddInt("RET_FLOW_SEQ_NUM", 0);
            in_node.AddString("RET_OPER", " ");

            if (out_node1.GetList(0).Count > 0)
            {
                in_node.SetString("TO_FLOW", MPCF.Trim(out_node1.GetList(0)[0].GetString("RWK_FLOW")));

                if (out_node1.GetList(0)[0].GetInt("RWK_FLOW_SEQ_NUM") < 1)
                {
                    if (in_node.GetString("TO_FLOW") == in_node.GetString("FLOW"))
                    {
                        in_node.SetInt("TO_FLOW_SEQ_NUM", in_node.GetInt("FLOW_SEQ_NUM"));
                    }
                }
                else
                {
                    in_node.SetInt("TO_FLOW_SEQ_NUM", out_node1.GetList(0)[0].GetInt("RWK_FLOW_SEQ_NUM"));
                }

                in_node.SetString("TO_OPER", MPCF.Trim(out_node1.GetList(0)[0].GetString("RWK_OPER")));

                if (MPCF.Trim(out_node1.GetList(0)[0].GetString("RET_FLOW")) != "")
                {
                    in_node.SetString("RET_FLOW", MPCF.Trim(out_node1.GetList(0)[0].GetString("RET_FLOW")));

                    if (out_node1.GetList(0)[0].GetInt("RET_FLOW_SEQ_NUM") < 1)
                    {
                        if (in_node.GetString("RET_FLOW") == in_node.GetString("FLOW"))
                        {
                            in_node.SetInt("RET_FLOW_SEQ_NUM", in_node.GetInt("FLOW_SEQ_NUM"));
                        }
                    }
                    else
                    {
                        in_node.SetInt("RET_FLOW_SEQ_NUM", out_node1.GetList(0)[0].GetInt("RET_FLOW_SEQ_NUM"));
                    }
                }
                if (MPCF.Trim(out_node1.GetList(0)[0].GetString("RET_OPER")) != "")
                {
                    in_node.SetString("RET_OPER", MPCF.Trim(out_node1.GetList(0)[0].GetString("RET_OPER")));
                }
            }
            out_node = new TRSNode("CMN_OUT");

            try
            {
                for (j = 1; j < lisColList.Items[i - 1].SubItems.Count; j++)
                {
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "RWK_CODE")
                        in_node.AddString("RWK_CODE", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "QTY_1" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.SetDouble("QTY_1", double.Parse(lisColList.Items[i].SubItems[j].Text.ToUpper().Trim()));
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "QTY_2" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.SetDouble("QTY_2", double.Parse(lisColList.Items[i].SubItems[j].Text.ToUpper().Trim()));
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "QTY_3" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.SetDouble("QTY_3", double.Parse(lisColList.Items[i].SubItems[j].Text.ToUpper().Trim()));
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "TO_FLOW" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.SetString("TO_FLOW", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "TO_FLOW_SEQ_NUM" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.SetInt("TO_FLOW_SEQ_NUM", int.Parse(lisColList.Items[i].SubItems[j].Text.ToUpper().Trim()));
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "TO_OPER" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.SetString("TO_OPER", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "RET_FLOW" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.SetString("RET_FLOW", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "RET_FLOW_SEQ_NUM" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.SetInt("RET_FLOW_SEQ_NUM", int.Parse(lisColList.Items[i].SubItems[j].Text.ToUpper().Trim()));
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "RET_OPER" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.SetString("RET_OPER", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "CAUSE_FLOW" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.AddString("CAUSE_FLOW", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "CAUSE_OPER" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.AddString("CAUSE_OPER", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "CAUSE_RES_ID" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.AddString("CAUSE_RES_ID", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "RWK_RET_CLEAR_FLAG" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                    {
                        if (lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() == "Y" || lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() == "T")
                            in_node.AddChar("RWK_RET_CLEAR_FLAG", 'Y');
                        else
                            in_node.AddChar("RWK_RET_CLEAR_FLAG", ' ');
                    }
                }
                if (MPCR.CallService("WIP", "WIP_Rework_Lot", in_node, ref out_node, txtChannel.Text.ToString(), 0, DeliveryMode.RReply, true) == false)
                {
                    return false;
                }
                if (out_node.StatusValue.ToString() == "0")
                    return true;
                else
                {
                    sMessage = out_node.Msg.ToString();
                    return false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

        }

        private bool exeLoss(string sLot, int i)
        {
            int j;

            if (exeViewLot(sLot.ToUpper()) == false)
                return false;

            in_node = new TRSNode("LOSS_LOT_IN");
            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';
            in_node.AddInt("LAST_ACTIVE_HIST_SEQ", out_node.GetInt("LAST_HIST_SEQ"));
            in_node.AddString("LOT_ID", sLot.Trim());
            in_node.AddString("MAT_ID", out_node.GetString("MAT_ID"));
            in_node.AddInt("MAT_VER", out_node.GetInt("MAT_VER"));
            in_node.AddString("FLOW", out_node.GetString("FLOW"));
            in_node.AddInt("FLOW_SEQ_NUM", out_node.GetInt("FLOW_SEQ_NUM"));
            in_node.AddString("OPER", out_node.GetString("OPER"));
            in_node.AddDouble("OUT_QTY_1", out_node.GetDouble("QTY_1"));
            in_node.AddDouble("OUT_QTY_2", out_node.GetDouble("QTY_2"));
            in_node.AddDouble("OUT_QTY_3", out_node.GetDouble("QTY_3"));

            out_node = new TRSNode("CMN_OUT");

            try
            {
                for (j = 1; j < lisColList.Items[i - 1].SubItems.Count; j++)
                {
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "UNIT2_CODE_1" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                        in_node.AddString("UNIT1_CODE_1", lisColList.Items[i].SubItems[j].Text.ToUpper().Trim());
                    if (lisColList.Items[i - 1].SubItems[j].Text.ToUpper().Trim() == "UNIT2_QTY_1" && lisColList.Items[i].SubItems[j].Text.ToUpper().Trim() != "")
                    {
                        in_node.AddDouble("UNIT1_QTY_1", double.Parse(lisColList.Items[i].SubItems[j].Text.ToUpper().Trim()));
                        in_node.SetDouble("OUT_QTY_1", in_node.GetDouble("OUT_QTY_1") - in_node.GetDouble("UNIT1_QTY_1"));
                    }
                }
                if (MPCR.CallService("WIP", "WIP_Loss_Lot", in_node, ref out_node, txtChannel.Text.ToString(), 0, DeliveryMode.RReply, true) == false)
                {
                    return false;
                }
                if (out_node.StatusValue.ToString() == "0")
                    return true;
                else
                {
                    sMessage = out_node.Msg.ToString();
                    return false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }
       
#endregion

    }
}