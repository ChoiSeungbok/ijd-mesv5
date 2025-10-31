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
using FarPoint.Win.Spread;
using System.IO.Ports;
using FarPoint.Win.Spread.CellType;
using Miracom.UI;
using System.Threading;

namespace CUS_WIP
{
    public partial class frmTranPLotManagement : CUS_COM.frmTranForm01
    {

        public delegate void ReceivedHandler(string sText);
        ReceivedHandler rh_Sanner;
        public frmTranPLotManagement()
        {
            InitializeComponent();
            InitControl();
        }

        private void InitControl()
        {
            try
            {
                btnDelete.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                chkMatChange.Visible = true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewLotList()
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                string text = "";
                int num = 0;
                double num2 = 0.0;
                text = (string.Equals(cdvDept.Text, CSGV.gs_area_ctm) ? "CWIP2019-001" : ((!string.Equals(cdvDept.Text, "GRT")) ? "" : "CWIP2019-004"));
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "MAT_ID";
                array[1].sCondition_Value = cdvMatID.Text;
                array[2].sCondition_ID = "OPER";
                array[2].sCondition_Value = cdvFromOper.Text;
                array[3].sCondition_ID = "AREA_ID";
                array[3].sCondition_Value = cdvDept.Text;
                if (!TPDR.GetDataOne("", ref dt, text, array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdFromLotList);
                    return;
                }
                MPCF.ClearList(spdFromLotList);
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdFromLotList_Sheet1.RowCount++;
                    spdFromLotList_Sheet1.SetValue(num, 0, false);
                    spdFromLotList_Sheet1.Cells[num, 1].Value = dt.Rows[num]["LOT_ID"];
                    spdFromLotList_Sheet1.Cells[num, 2].Value = dt.Rows[num]["QTY"];
                    spdFromLotList_Sheet1.Cells[num, 3].Value = dt.Rows[num]["UNIT"];
                    spdFromLotList_Sheet1.Cells[num, 4].Value = dt.Rows[num]["OPER"];
                    spdFromLotList_Sheet1.Cells[num, 5].Value = dt.Rows[num]["OPER_DESC"];
                    spdFromLotList_Sheet1.Cells[num, 6].Value = dt.Rows[num]["MAT_ID"];
                    spdFromLotList_Sheet1.Cells[num, 7].Value = dt.Rows[num]["MAT_DESC"];
                }
                MPCF.FitColumnHeader(spdFromLotList);
                for (num = 0; num < spdFromLotList_Sheet1.RowCount; num++)
                {
                    num2 += MPCF.ToDbl(spdFromLotList.ActiveSheet.Cells[num, 2].Text);
                }
                spdFromLotList.ActiveSheet.ColumnFooter.Cells[0, 2].Value = num2;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void InputLot(string sLot_ID)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                string text = "";
                int num = 0;
                text = (string.Equals(cdvDept.Text, CSGV.gs_area_ctm) ? "CWIP2019-002" : ((!string.Equals(cdvDept.Text, "GRT")) ? "" : "CWIP2019-005"));
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "MAT_ID";
                array[1].sCondition_Value = "";
                array[2].sCondition_ID = "OPER";
                array[2].sCondition_Value = cdvFromOper.Text;
                array[3].sCondition_ID = "LOT_ID";
                array[3].sCondition_Value = sLot_ID;
                if (!TPDR.GetDataOne("", ref dt, text, array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    txtLotID.SelectAll();
                    return;
                }
                for (int i = 0; i < spdToLotList_Sheet1.RowCount; i++)
                {
                    if (object.Equals(spdToLotList_Sheet1.Cells[i, 1].Text, dt.Rows[0]["LOT_ID"]))
                    {
                        spdToLotList_Sheet1.RemoveRows(i, 1);
                        break;
                    }
                }
                for (int j = 0; j < spdFromLotList_Sheet1.RowCount; j++)
                {
                    if (object.Equals(spdFromLotList_Sheet1.Cells[j, 1].Text, dt.Rows[0]["LOT_ID"]))
                    {
                        spdFromLotList_Sheet1.RemoveRows(j, 1);
                        break;
                    }
                }
                num = spdToLotList_Sheet1.RowCount++;
                spdToLotList_Sheet1.SetValue(num, 0, true);
                spdToLotList_Sheet1.Cells[num, 1].Value = dt.Rows[0]["LOT_ID"];
                spdToLotList_Sheet1.Cells[num, 2].Value = dt.Rows[0]["QTY"];
                spdToLotList_Sheet1.Cells[num, 3].Value = dt.Rows[0]["UNIT"];
                spdToLotList_Sheet1.Cells[num, 4].Value = dt.Rows[0]["OPER"];
                spdToLotList_Sheet1.Cells[num, 5].Value = dt.Rows[0]["OPER_DESC"];
                spdToLotList_Sheet1.Cells[num, 6].Value = dt.Rows[0]["MAT_ID"];
                spdToLotList_Sheet1.Cells[num, 7].Value = dt.Rows[0]["MAT_DESC"];
                GradeMatChange(spdToLotList_Sheet1.Cells[num, 7].Text);
                MPCF.FitColumnHeader(spdToLotList);
                txtLotID.SelectAll();
                CheckCount();
                CheckCount2();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool MoveLot()
        {
            TRSNode tRSNode = new TRSNode("move_Lot_In");
            TRSNode out_node = new TRSNode("move_Lot_Out");
            bool flag = false;
            try
            {
                if (string.Equals(cdvDept.Text, CSGV.gs_area_ctm))
                {
                    MPCR.SetInMsg(tRSNode);
                    tRSNode.ProcStep = '1';
                    tRSNode.AddString("TO_OPER", cdvToOper.Text);
                    tRSNode.AddString("TRAN_COMMENT", txtComment.Text);
                    if (chkMatChange.Checked)
                    {
                        tRSNode.AddChar("MAT_CHANGE", MPCF.ToChar("Y"));
                    }
                    else
                    {
                        tRSNode.AddChar("MAT_CHANGE", MPCF.ToChar("N"));
                    }
                    tRSNode.AddString("TO_MAT_ID", cdvToMatID.Text);
                    if (chkMatChange.Checked && MPCF.Trim(cdvToMatID.Text) == "")
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToMatID.Text + "]");
                        cdvToMatID.Focus();
                        return false;
                    }
                    for (int i = 0; i < spdToLotList_Sheet1.RowCount; i++)
                    {
                        if (spdToLotList_Sheet1.Cells[i, 0].Text.ToString().ToUpper() == "TRUE")
                        {
                            TRSNode tRSNode2 = tRSNode.AddNode("LOT_LIST");
                            tRSNode2.AddString("LOT_ID", spdToLotList_Sheet1.Cells[i, 1].Text);
                            flag = true;
                        }
                    }
                    if (!flag)
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(109));
                        return false;
                    }
                    if (!MPCR.CallService("CUS_WIP", "CUS_WIP_Regenerate_P_Lot", tRSNode, ref out_node))
                    {
                        return false;
                    }
                    MPCR.ShowSuccessMsg(out_node);
                }
                else
                {
                    if (!string.Equals(cdvDept.Text, "GRT"))
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(508));
                        return false;
                    }
                    if (MPCF.Trim(cdvInType.Text) == "")
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblInType.Text + "]");
                        cdvInType.Focus();
                        return false;
                    }
                    if (MPCF.Trim(cdvToMatID.Text) == "")
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToMatID.Text + "]");
                        cdvToMatID.Focus();
                        return false;
                    }
                    MPCR.SetInMsg(tRSNode);
                    tRSNode.ProcStep = '2';
                    tRSNode.AddString("TO_OPER", cdvToOper.Text);
                    tRSNode.AddString("TRAN_COMMENT", txtComment.Text);
                    tRSNode.AddString("AREA_ID", cdvDept.Text);
                    tRSNode.AddString("IN_TYPE", cdvInType.Text);
                    tRSNode.AddString("TO_MAT_ID", cdvToMatID.Text);
                    tRSNode.AddString("TRAN_COMMENT", txtComment.Text);
                    tRSNode.AddChar("ERP_FLAG", 'Y');
                    for (int j = 0; j < spdToLotList_Sheet1.RowCount; j++)
                    {
                        if (spdToLotList_Sheet1.Cells[j, 0].Text.ToString().ToUpper() == "TRUE")
                        {
                            TRSNode tRSNode2 = tRSNode.AddNode("LOT_LIST");
                            tRSNode2.AddString("LOT_ID", spdToLotList_Sheet1.Cells[j, 1].Text);
                            flag = true;
                        }
                    }
                    if (!flag)
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(109));
                        return false;
                    }
                    if (!MPCR.CallService("CUS_WIP", "CUS_WIP_Regenerate_P_Lot", tRSNode, ref out_node))
                    {
                        return false;
                    }
                    MPCR.ShowSuccessMsg(out_node);
                }
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool DeletePLot()
        {
            TRSNode tRSNode = new TRSNode("Lot_In");
            TRSNode out_node = new TRSNode("Lot_Out");
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                for (int i = 0; i < spdToLotList_Sheet1.RowCount; i++)
                {
                    if (spdToLotList_Sheet1.Cells[i, 0].Text.ToString().ToUpper() == "TRUE")
                    {
                        TRSNode tRSNode2 = tRSNode.AddNode("LOT_LIST");
                        tRSNode2.AddString("LOT_ID", spdToLotList_Sheet1.Cells[i, 1].Text);
                    }
                }
                if (!MPCR.CallService("CUS_WIP", "CUS_WIP_Delete_P_Lot", tRSNode, ref out_node))
                {
                    return false;
                }
                return true;
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }

        private bool CheckCondition(string sType)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }
                if (MPCF.Trim(cdvFromOper.Text) == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblFromOper.Text + "]");
                    cdvFromOper.Focus();
                    return false;
                }
                if (!(sType == "MOVE"))
                {
                    if (sType == "INPUT" && MPCF.Trim(txtLotID.Text) == "")
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLotID.Text + "]");
                        txtLotID.Focus();
                        return false;
                    }
                }
                else
                {
                    if (spdToLotList_Sheet1.RowCount == 0)
                    {
                        return false;
                    }
                    if (MPCF.Trim(cdvToOper.Text) == "")
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToOper.Text + "]");
                        cdvToOper.Focus();
                        return false;
                    }
                    if (string.Equals(cdvFromOper.Text, cdvToOper.Text))
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(368) + " [" + lblToOper.Text + "]");
                        cdvToOper.Focus();
                        return false;
                    }
                }
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void CheckCount()
        {
            double num = 0.0;
            int num2 = 0;
            try
            {
                for (int i = 0; i < spdFromLotList_Sheet1.RowCount; i++)
                {
                    if (spdFromLotList_Sheet1.Cells[i, 0].Value.ToString().ToUpper() == "TRUE")
                    {
                        num2++;
                        num += MPCF.ToDbl(spdFromLotList_Sheet1.Cells[i, 2].Text);
                    }
                }
                spdFromLotList_Sheet1.ColumnFooter.Cells[0, 0].Value = num2;
                spdFromLotList_Sheet1.ColumnFooter.Cells[0, 2].Value = num;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool CheckCount2(string chkType = "")
        {
            double num = 0.0;
            int num2 = 0;
            try
            {
                for (int i = 0; i < spdToLotList_Sheet1.RowCount; i++)
                {
                    if (spdToLotList_Sheet1.Cells[i, 0].Value.ToString().ToUpper() == "TRUE")
                    {
                        num2++;
                        num += MPCF.ToDbl(spdToLotList_Sheet1.Cells[i, 2].Text);
                    }
                }
                spdToLotList_Sheet1.ColumnFooter.Cells[0, 0].Value = num2;
                spdToLotList_Sheet1.ColumnFooter.Cells[0, 2].Value = num;
                if (chkType == "DELETE" && num2 == 0)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(465));
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

        private void ClearList(string sType)
        {
            try
            {
                if (!(sType == "VIEW"))
                {
                    if (sType == "ALL")
                    {
                        MPCF.ClearList(spdFromLotList);
                        MPCF.ClearList(spdToLotList);
                        spdFromLotList.ActiveSheet.ColumnFooter.Cells[0, 0].Value = 0;
                        spdFromLotList.ActiveSheet.ColumnFooter.Cells[0, 2].Value = 0;
                        spdToLotList.ActiveSheet.ColumnFooter.Cells[0, 0].Value = 0;
                        spdToLotList.ActiveSheet.ColumnFooter.Cells[0, 2].Value = 0;
                        cdvFromOper.Text = "";
                        cdvToOper.Text = "";
                        cdvMatID.Text = "";
                        txtLotID.Text = "";
                        txtComment.Text = "";
                        cdvToMatID.Text = "";
                        cdvInType.Text = "";
                        lblToMatID.Enabled = false;
                        cdvToMatID.Enabled = false;
                        lblInType.Enabled = false;
                        cdvInType.Enabled = false;
                    }
                }
                else
                {
                    MPCF.ClearList(spdFromLotList);
                    MPCF.ClearList(spdToLotList);
                    spdFromLotList.ActiveSheet.ColumnFooter.Cells[0, 0].Value = 0;
                    spdFromLotList.ActiveSheet.ColumnFooter.Cells[0, 2].Value = 0;
                    spdToLotList.ActiveSheet.ColumnFooter.Cells[0, 0].Value = 0;
                    spdToLotList.ActiveSheet.ColumnFooter.Cells[0, 2].Value = 0;
                    cdvToOper.Text = "";
                    txtLotID.Text = "";
                    txtComment.Text = "";
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool P_WO_Check()
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                string text = "";
                text = "CWIP2019-006";
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "AREA_ID";
                array[1].sCondition_Value = cdvDept.Text;
                array[2].sCondition_ID = "MAT_ID";
                array[2].sCondition_Value = cdvToMatID.Text;
                if (!TPDR.GetDataOne("", ref dt, text, array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    txtLotID.SelectAll();
                    return false;
                }
                if (dt.Rows.Count == 0)
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

        private void frmTranPLotManagement_Load(object sender, EventArgs e)
        {
            bool flag = false;
            try
            {
                cdvToMatID.Text = "";
                cdvInType.Text = "";
                lblToMatID.Enabled = false;
                cdvToMatID.Enabled = false;
                lblInType.Enabled = false;
                cdvInType.Enabled = false;
                string[] portNames = SerialPort.GetPortNames();
                for (int i = 0; i < portNames.Length; i++)
                {
                    flag = false;
                    for (int j = 0; j < cboPort.Items.Count; j++)
                    {
                        if (cboPort.Items[j].ToString() == portNames[i])
                        {
                            flag = true;
                            break;
                        }
                    }
                    if (!flag)
                    {
                        cboPort.Items.Add(portNames[i]);
                    }
                }
                cboPort.Items.Add("");
                rh_Sanner = rhText;
                if (cboPort.Text != "")
                {
                    Open_Port(cboPort.Text, 'N');
                }
                if (MPGV.gsFactory == "IJDV1")
                {
                    cdvDept.Text = "CTV";
                    chkMatChange.Checked = true;
                    GradeMatChange(" ");
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                ClearList("ALL");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList frmPopMaterialList = new frmPopMaterialList();
                frmPopMaterialList.StartPosition = FormStartPosition.CenterParent;
                frmPopMaterialList.sArea_id = cdvDept.Text;
                frmPopMaterialList.sArea_desc = cdvDept.DisplayText;
                if (frmPopMaterialList.ShowDialog() == DialogResult.OK)
                {
                    cdvMatID.Text = frmPopMaterialList.sMat_id;
                    frmPopMaterialList = null;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("VIEW"))
                {
                    ClearList("VIEW");
                    ViewLotList();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            try
            {
                int num = 0;
                for (int num2 = spdFromLotList_Sheet1.RowCount - 1; num2 >= 0; num2--)
                {
                    if (spdFromLotList_Sheet1.Cells[num2, 0].Text.ToString().ToUpper() == "TRUE")
                    {
                        num = spdToLotList_Sheet1.RowCount++;
                        spdToLotList_Sheet1.SetValue(num, 0, true);
                        spdToLotList_Sheet1.Cells[num, 1].Value = spdFromLotList_Sheet1.Cells[num2, 1].Text;
                        spdToLotList_Sheet1.Cells[num, 2].Value = spdFromLotList_Sheet1.Cells[num2, 2].Text;
                        spdToLotList_Sheet1.Cells[num, 3].Value = spdFromLotList_Sheet1.Cells[num2, 3].Text;
                        spdToLotList_Sheet1.Cells[num, 4].Value = spdFromLotList_Sheet1.Cells[num2, 4].Text;
                        spdToLotList_Sheet1.Cells[num, 5].Value = spdFromLotList_Sheet1.Cells[num2, 5].Text;
                        spdToLotList_Sheet1.Cells[num, 6].Value = spdFromLotList_Sheet1.Cells[num2, 6].Text;
                        spdToLotList_Sheet1.Cells[num, 7].Value = spdFromLotList_Sheet1.Cells[num2, 7].Text;
                        if (MPGV.gsFactory == "IJDV1" && cdvDept.Text == "CTV")
                        {
                            GradeMatChange(spdFromLotList_Sheet1.Cells[num2, 7].Text);
                        }
                    }
                }
                MPCF.FitColumnHeader(spdFromLotList);
                CheckCount();
                CheckCount2();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void GradeMatChange(string sMatDesc)
        {
            if (!(cdvDept.Text == "CTV"))
            {
                return;
            }
            if (sMatDesc.Length > 4)
            {
                if (sMatDesc.Substring(0, 4).ToString() == "IPOL")
                {
                    cdvToMatID.Text = "BC1BC00-00170";
                    txtToMatdesc.Text = "IPOL.P.GRADE";
                    cdvToOper.Text = "CW-L/P-H";
                    cdvToOper.DisplayText = "Lap/Pol process warehouse";
                }
                else
                {
                    cdvToMatID.Text = "BC2BC00-00083";
                    txtToMatdesc.Text = "IBON.P.GRADE";
                    cdvToOper.Text = "CW-L/P-H";
                    cdvToOper.DisplayText = "Lap/Pol process warehouse";
                }
            }
            else
            {
                cdvToMatID.Text = "BC2BC00-00083";
                txtToMatdesc.Text = "IBON.P.GRADE";
                cdvToOper.Text = "CW-L/P-H";
                cdvToOper.DisplayText = "Lap/Pol process warehouse";
            }
        }

        private void btnDel_Click(object sender, EventArgs e)
        {
            try
            {
                int num = 0;
                for (int num2 = spdToLotList_Sheet1.RowCount - 1; num2 >= 0; num2--)
                {
                    if (spdToLotList_Sheet1.Cells[num2, 0].Text.ToString().ToUpper() == "TRUE")
                    {
                        num = spdFromLotList_Sheet1.RowCount++;
                        spdFromLotList_Sheet1.SetValue(num, 0, false);
                        spdFromLotList_Sheet1.Cells[num, 1].Value = spdToLotList_Sheet1.Cells[num2, 1].Text;
                        spdFromLotList_Sheet1.Cells[num, 2].Value = spdToLotList_Sheet1.Cells[num2, 2].Text;
                        spdFromLotList_Sheet1.Cells[num, 3].Value = spdToLotList_Sheet1.Cells[num2, 3].Text;
                        spdFromLotList_Sheet1.Cells[num, 4].Value = spdToLotList_Sheet1.Cells[num2, 4].Text;
                        spdFromLotList_Sheet1.Cells[num, 5].Value = spdToLotList_Sheet1.Cells[num2, 5].Text;
                        spdFromLotList_Sheet1.Cells[num, 6].Value = spdToLotList_Sheet1.Cells[num2, 6].Text;
                        spdFromLotList_Sheet1.Cells[num, 7].Value = spdToLotList_Sheet1.Cells[num2, 7].Text;
                        spdToLotList_Sheet1.RemoveRows(num2, 1);
                    }
                }
                MPCF.FitColumnHeader(spdToLotList);
                CheckCount();
                CheckCount2();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("MOVE") && MoveLot())
                {
                    ClearList("VIEW");
                    ViewLotList();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdFromLotList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                if (spdFromLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdFromLotList, e.Row, e.Column, b_checked: true, b_isColHeaderCheckBox: true);
                }
                CheckCount();
            }
        }

        private void spdToLotList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                if (spdToLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdToLotList, e.Row, e.Column, b_checked: true, b_isColHeaderCheckBox: true);
                }
                CheckCount2();
            }
        }

        private void txtLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == '\r' && CheckCondition("INPUT"))
                {
                    InputLot(txtLotID.Text);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvFromOper_ButtonPress(object sender, EventArgs e)
        {
            cdvFromOper.Init();
            MPCF.InitListView(cdvFromOper.GetListView);
            cdvFromOper.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
            cdvFromOper.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
            cdvFromOper.SelectedSubItemIndex = 0;
            cdvFromOper.DisplaySubItemIndex = 1;
            if (COM_LIST.ViewOperationList(cdvFromOper.GetListView, 'J', cdvDept.Text, "", "", "", 'Y'))
            {
                cdvFromOper.InsertEmptyRow(0, 1);
                ClearList("VIEW");
            }
        }

        private void cdvToOper_ButtonPress(object sender, EventArgs e)
        {
            cdvToOper.Init();
            MPCF.InitListView(cdvToOper.GetListView);
            cdvToOper.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
            cdvToOper.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
            cdvToOper.SelectedSubItemIndex = 0;
            cdvToOper.DisplaySubItemIndex = 1;
            if (COM_LIST.ViewOperationList(cdvToOper.GetListView, '4', cdvDept.Text, "", "", "", 'Y'))
            {
                cdvToOper.InsertEmptyRow(0, 1);
            }
        }

        private void cdvDept_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                ClearList("ALL");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdFromLotList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            try
            {
                CheckCount();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdFromLotList_Change(object sender, ChangeEventArgs e)
        {
            try
            {
                CheckCount();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdToLotList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            try
            {
                CheckCount2();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdToLotList_Change(object sender, ChangeEventArgs e)
        {
            try
            {
                CheckCount2();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDept_SelectedItemChanged(object sender, MCCodeViewSelChanged_EventArgs e)
        {
            if (string.Equals(cdvDept.Text, "GRT"))
            {
                cdvToMatID.Text = "";
                cdvInType.Text = "";
                lblToMatID.Enabled = true;
                cdvToMatID.Enabled = true;
                lblInType.Enabled = true;
                cdvInType.Enabled = true;
                chkMatChange.Visible = false;
                chkMatChange.Checked = false;
            }
            else
            {
                cdvToMatID.Text = "";
                cdvInType.Text = "";
                lblToMatID.Enabled = false;
                cdvToMatID.Enabled = false;
                lblInType.Enabled = false;
                cdvInType.Enabled = false;
                chkMatChange.Visible = true;
                chkMatChange.Checked = false;
            }
        }

        private void cdvInType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvInType.Init();
                MPCF.InitListView(cdvInType.GetListView);
                cdvInType.Columns.Add("DESC", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvInType.Columns.Add("ID", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvInType.SelectedSubItemIndex = 1;
                cdvInType.DisplaySubItemIndex = 0;
                if (COM_LIST.ViewEtcTypeList(cdvInType.GetListView, "CINV2012-002", cdvDept.Text, "RECEIPT"))
                {
                    cdvInType.InsertEmptyRow(0, 1);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvToMatID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (string.Equals(cdvDept.Text, "GRT"))
                {
                    cdvToMatID.Init();
                    MPCF.InitListView(cdvToMatID.GetListView);
                    cdvToMatID.Columns.Add("DESC", 50, System.Windows.Forms.HorizontalAlignment.Left);
                    cdvToMatID.Columns.Add("ID", 100, System.Windows.Forms.HorizontalAlignment.Left);
                    cdvToMatID.SelectedSubItemIndex = 1;
                    cdvToMatID.DisplaySubItemIndex = 0;
                    if (COM_LIST.ViewPMaterialList(cdvToMatID.GetListView, "CWIP2019-003", cdvDept.Text))
                    {
                        cdvToMatID.InsertEmptyRow(0, 1);
                    }
                    return;
                }
                frmPopMaterialList frmPopMaterialList = new frmPopMaterialList();
                frmPopMaterialList.StartPosition = FormStartPosition.CenterParent;
                frmPopMaterialList.sArea_id = CSGV.gs_area_ctm;
                frmPopMaterialList.sArea_desc = CSGV.gs_area_ctm;
                if (frmPopMaterialList.ShowDialog() == DialogResult.OK)
                {
                    cdvToMatID.Text = frmPopMaterialList.sMat_id;
                    txtToMatdesc.Text = frmPopMaterialList.sMat_Desc;
                    frmPopMaterialList = null;
                    if (!P_WO_Check())
                    {
                        MPCF.ShowMsgBox("해당품목은 P급작지가 없습니다. 관리자에게 문의하세요");
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            try
            {
                if (!CheckCount2("DELETE"))
                {
                    return;
                }
                DialogResult dialogResult = MessageBox.Show(MPCF.GetMessage(453), "Info", MessageBoxButtons.OKCancel, MessageBoxIcon.Asterisk);
                if (dialogResult != DialogResult.OK || !DeletePLot())
                {
                    return;
                }
                SheetView sheetView = spdToLotList_Sheet1;
                for (int num = sheetView.RowCount - 1; num >= 0; num--)
                {
                    if (Convert.ToBoolean((sheetView.Cells[num, 0] == null) ? ((object)false) : sheetView.Cells[num, 0].Value))
                    {
                        sheetView.RemoveRows(num, 1);
                    }
                }
                MPCF.ShowMsgBox(MPCF.GetMessage(52));
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvToMatID_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvToMatID.DisplayText == "")
            {
                cdvToMatID.Text = "";
            }
            txtToMatdesc.Text = "";
        }

        private void frmTranPLotManagement_FormClosed(object sender, FormClosedEventArgs e)
        {
            try
            {
                spScanner.Close();
                if (cboPort.SelectedIndex != -1)
                {
                    MPCF.SaveRegSetting(Application.ProductName, base.Name, cboPort.Name, cboPort.SelectedItem.ToString());
                }
                else
                {
                    MPCF.SaveRegSetting(Application.ProductName, base.Name, cboPort.Name, "");
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void chkMatChange_CheckedChanged(object sender, EventArgs e)
        {
            if (chkMatChange.Checked)
            {
                lblToMatID.Enabled = true;
                cdvToMatID.Enabled = true;
                txtToMatdesc.Enabled = true;
                if (MPGV.gsFactory == "IJDV1" && cdvDept.Text == "CTV")
                {
                    cdvToMatID.Text = "BC1BC00-00170";
                    txtToMatdesc.Text = "IPOL.P.GRADE";
                    cdvToOper.Text = "CW-L/P-H";
                    cdvToOper.DisplayText = "Lap/Pol process warehouse";
                }
                else
                {
                    cdvToMatID.Text = "";
                    txtToMatdesc.Text = "";
                    cdvToOper.Text = "";
                    cdvToOper.DisplayText = "";
                }
            }
            else
            {
                lblToMatID.Enabled = false;
                cdvToMatID.Enabled = false;
                txtToMatdesc.Enabled = true;
                cdvToMatID.Text = "";
                txtToMatdesc.Text = "";
                cdvToOper.Text = "";
                cdvToOper.DisplayText = "";
            }
        }

        private void btnPortOpen_Click(object sender, EventArgs e)
        {
            try
            {
                Open_Port(cboPort.Text, 'Y');
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmTranMultiProcessLot_FormClosed(object sender, FormClosedEventArgs e)
        {
            try
            {
                spScanner.Close();
                if (cboPort.SelectedIndex != -1)
                {
                    MPCF.SaveRegSetting(Application.ProductName, base.Name, cboPort.Name, cboPort.SelectedItem.ToString());
                }
                else
                {
                    MPCF.SaveRegSetting(Application.ProductName, base.Name, cboPort.Name, "");
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cboPort_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                if (cboPort.Text == "" && spScanner.IsOpen)
                {
                    spScanner.Close();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spScanner_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            string text = "";
            try
            {
                Thread.Sleep(100);
                text = spScanner.ReadExisting();
                if (!string.IsNullOrEmpty(text))
                {
                    string[] array = text.Split('\r');
                    IAsyncResult asyncResult = BeginInvoke(rh_Sanner, array[0]);
                    EndInvoke(asyncResult);
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void Open_Port(string s_port, char c_MsgYN)
        {
            try
            {
                if (spScanner.IsOpen)
                {
                    spScanner.Close();
                }
                spScanner.PortName = s_port;
                spScanner.BaudRate = 9600;
                spScanner.DataBits = 8;
                spScanner.Parity = Parity.None;
                spScanner.StopBits = StopBits.One;
                spScanner.Handshake = Handshake.None;
                spScanner.RtsEnable = false;
                spScanner.DtrEnable = false;
                spScanner.Open();
                if (spScanner.IsOpen && c_MsgYN == 'Y')
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(500));
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void rhText(string sText)
        {
            txtLotID.Text = sText;
            InputLot(sText);
        }

        private void cboPort_SelectedIndexChanged_1(object sender, EventArgs e)
        {
        }

        private void spdToLotList_KeyDown(object sender, KeyEventArgs e)
        {
            try
            {
                if (!CheckCondition(""))
                {
                    return;
                }
                SheetView activeSheet = spdToLotList.ActiveSheet;
                if (e.Control && e.KeyCode == Keys.V)
                {
                    int activeRowIndex = activeSheet.ActiveRowIndex;
                    string[] separator = new string[1] { "\r\n" };
                    string text = Clipboard.GetText();
                    string[] array = text.Split(separator, StringSplitOptions.None);
                    for (int i = 0; i < array.Length - 1; i++)
                    {
                        if (activeSheet.RowCount > 1000)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(510));
                            return;
                        }
                        string[] separator2 = new string[1] { "\t" };
                        string[] array2 = array[i].Split(separator2, StringSplitOptions.None);
                        InputLot(array2[0]);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
            e.Handled = true;
        }
    }
}
