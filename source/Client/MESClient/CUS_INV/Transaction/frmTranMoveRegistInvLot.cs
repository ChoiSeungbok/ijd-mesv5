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
using Miracom.UI;

namespace CUS_INV
{
    public partial class frmTranMoveRegistInvLot : CUS_COM.frmTranForm01
    {
        public frmTranMoveRegistInvLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "
        private enum MOVE_LIST
        {
            MOVE_ORDER_ID,
            FROM_AREA_ID,
            FROM_SUB_AREA_ID,
            FROM_SUB_AREA_DESC,
            FROM_OPER,
            FROM_OPER_DESC,
            TO_AREA_ID,
            TO_AREA_DESC,
            TO_SUB_AREA_ID,
            TO_SUB_AREA_DESC,
            TO_OPER,
            TO_OPER_DESC,
            MOVE_STATUS
        }

        private enum LOT_INFO
        {
            CHK,
            INV_LOT_ID,
            MAT_ID,
            MAT_DESC,
            QTY,
            VENDOR_LOT_ID,
            PO_NO,
            PO_SEQ
        }

        private enum MOVE_INFO
        {
            CHK,
            INV_LOT_ID,
            MAT_ID,
            MAT_DESC,
            QTY,
            VENDOR_LOT_ID
        }


        #endregion

        #region " Variable Definition "

        string sMove_id = "";

        #endregion

        private void InitControl()
        {
            try
            {
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnCancel.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnNew.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewMoveList()
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "AREA_ID";
                array[1].sCondition_Value = cdvDept.Text;
                array[2].sCondition_ID = "OPER";
                array[2].sCondition_Value = cdvFromOper.Text;
                array[3].sCondition_ID = "MOVE_ID";
                array[3].sCondition_Value = txtMoveOrder.Text;
                if (!TPDR.GetDataOne("", ref dt, "CINV2015-002", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdMoveList);
                    return;
                }
                MPCF.ClearList(spdMoveList);
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdMoveList_Sheet1.RowCount++;
                    spdMoveList_Sheet1.Cells[num, 0].Value = dt.Rows[num]["MOVE_ID"];
                    spdMoveList_Sheet1.Cells[num, 1].Value = dt.Rows[num]["FROM_AREA_ID"];
                    spdMoveList_Sheet1.Cells[num, 2].Value = dt.Rows[num]["FROM_SUB_AREA_ID"];
                    spdMoveList_Sheet1.Cells[num, 3].Value = dt.Rows[num]["FROM_SUB_AREA_DESC"];
                    spdMoveList_Sheet1.Cells[num, 4].Value = dt.Rows[num]["FROM_OPER"];
                    spdMoveList_Sheet1.Cells[num, 5].Value = dt.Rows[num]["FROM_OPER_DESC"];
                    spdMoveList_Sheet1.Cells[num, 6].Value = dt.Rows[num]["TO_AREA_ID"];
                    spdMoveList_Sheet1.Cells[num, 7].Value = dt.Rows[num]["TO_AREA_DESC"];
                    spdMoveList_Sheet1.Cells[num, 8].Value = dt.Rows[num]["TO_SUB_AREA_ID"];
                    spdMoveList_Sheet1.Cells[num, 9].Value = dt.Rows[num]["TO_SUB_AREA_DESC"];
                    spdMoveList_Sheet1.Cells[num, 10].Value = dt.Rows[num]["TO_OPER"];
                    spdMoveList_Sheet1.Cells[num, 11].Value = dt.Rows[num]["TO_OPER_DESC"];
                    spdMoveList_Sheet1.Cells[num, 12].Value = dt.Rows[num]["MOVE_STATUS"];
                }
                MPCF.FitColumnHeader(spdMoveList);
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
                int num = 0;
                double num2 = 0.0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "MAT_ID";
                array[1].sCondition_Value = cdvMatID.Text;
                array[2].sCondition_ID = "OPER";
                array[2].sCondition_Value = cdvFromOper.Text;
                array[3].sCondition_ID = "AREA_ID";
                array[3].sCondition_Value = cdvDept.Text;
                if (!TPDR.GetDataOne("", ref dt, "CINV2003-001", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdLotList);
                    return;
                }
                MPCF.ClearList(spdLotList);
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdLotList_Sheet1.RowCount++;
                    spdLotList_Sheet1.SetValue(num, 0, false);
                    spdLotList_Sheet1.Cells[num, 1].Value = dt.Rows[num]["INV_LOT_ID"];
                    spdLotList_Sheet1.Cells[num, 2].Value = dt.Rows[num]["MAT_ID"];
                    spdLotList_Sheet1.Cells[num, 3].Value = dt.Rows[num]["MAT_DESC"];
                    spdLotList_Sheet1.Cells[num, 4].Value = dt.Rows[num]["QTY"];
                    spdLotList_Sheet1.Cells[num, 5].Value = dt.Rows[num]["VENDOR_LOT_ID"];
                    spdLotList_Sheet1.Cells[num, 6].Value = dt.Rows[num]["PO_NO"];
                    spdLotList_Sheet1.Cells[num, 7].Value = dt.Rows[num]["PO_SEQ"];
                }
                MPCF.FitColumnHeader(spdLotList);
                for (num = 0; num < spdLotList_Sheet1.RowCount; num++)
                {
                    num2 += MPCF.ToDbl(spdLotList.ActiveSheet.Cells[num, 4].Text);
                }
                spdLotList.ActiveSheet.ColumnFooter.Cells[0, 4].Value = num2;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void CheckCount()
        {
            double num = 0.0;
            int num2 = 0;
            try
            {
                for (int i = 0; i < spdLotList_Sheet1.RowCount; i++)
                {
                    if (spdLotList_Sheet1.Cells[i, 0].Value.ToString().ToUpper() == "TRUE")
                    {
                        num2++;
                        num += MPCF.ToDbl(spdLotList_Sheet1.Cells[i, 4].Text);
                    }
                }
                spdLotList_Sheet1.ColumnFooter.Cells[0, 0].Value = num2;
                spdLotList_Sheet1.ColumnFooter.Cells[0, 4].Value = num;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void CheckCount2()
        {
            double num = 0.0;
            int num2 = 0;
            try
            {
                for (int i = 0; i < spdMoveLotList_Sheet1.RowCount; i++)
                {
                    if (spdMoveLotList_Sheet1.Cells[i, 0].Value.ToString().ToUpper() == "TRUE")
                    {
                        num2++;
                        num += MPCF.ToDbl(spdMoveLotList_Sheet1.Cells[i, 4].Text);
                    }
                }
                spdMoveLotList_Sheet1.ColumnFooter.Cells[0, 0].Value = num2;
                spdMoveLotList_Sheet1.ColumnFooter.Cells[0, 4].Value = num;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewMoveLotList(string sMove_id)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                double num2 = 0.0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "MOVE_ID";
                array[1].sCondition_Value = sMove_id;
                if (!TPDR.GetDataOne("", ref dt, "CINV2015-001", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdMoveLotList);
                    return;
                }
                MPCF.ClearList(spdMoveLotList);
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdMoveLotList_Sheet1.RowCount++;
                    spdMoveLotList_Sheet1.SetValue(num, 0, false);
                    spdMoveLotList_Sheet1.Cells[num, 1].Value = dt.Rows[num]["INV_LOT_ID"];
                    spdMoveLotList_Sheet1.Cells[num, 2].Value = dt.Rows[num]["MAT_ID"];
                    spdMoveLotList_Sheet1.Cells[num, 3].Value = dt.Rows[num]["MAT_DESC"];
                    spdMoveLotList_Sheet1.Cells[num, 4].Value = dt.Rows[num]["QTY"];
                    spdMoveLotList_Sheet1.Cells[num, 5].Value = dt.Rows[num]["VENDOR_LOT_ID"];
                }
                MPCF.FitColumnHeader(spdMoveLotList);
                for (num = 0; num < spdMoveLotList_Sheet1.RowCount; num++)
                {
                    num2 += MPCF.ToDbl(spdMoveLotList.ActiveSheet.Cells[num, 4].Text);
                }
                spdMoveLotList.ActiveSheet.ColumnFooter.Cells[0, 4].Value = num2;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewLotInfo(string sLot_ID)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "MAT_ID";
                array[1].sCondition_Value = "";
                array[2].sCondition_ID = "OPER";
                array[2].sCondition_Value = cdvFromOper.Text;
                array[3].sCondition_ID = "INV_LOT_ID";
                array[3].sCondition_Value = txtInvLotID.Text;
                if (!TPDR.GetDataOne("", ref dt, "CINV2003-002", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    txtInvLotID.SelectAll();
                    return;
                }
                for (int i = 0; i < spdMoveLotList_Sheet1.RowCount; i++)
                {
                    if (object.Equals(spdMoveLotList_Sheet1.Cells[i, 1].Text, dt.Rows[0]["INV_LOT_ID"]))
                    {
                        spdMoveLotList_Sheet1.RemoveRows(i, 1);
                        break;
                    }
                }
                for (int j = 0; j < spdLotList_Sheet1.RowCount; j++)
                {
                    if (object.Equals(spdLotList_Sheet1.Cells[j, 1].Text, dt.Rows[0]["INV_LOT_ID"]))
                    {
                        spdLotList_Sheet1.RemoveRows(j, 1);
                        break;
                    }
                }
                num = spdMoveLotList_Sheet1.RowCount++;
                spdMoveLotList_Sheet1.SetValue(num, 0, true);
                spdMoveLotList_Sheet1.Cells[num, 1].Value = dt.Rows[0]["INV_LOT_ID"];
                spdMoveLotList_Sheet1.Cells[num, 2].Value = dt.Rows[0]["MAT_ID"];
                spdMoveLotList_Sheet1.Cells[num, 3].Value = dt.Rows[0]["MAT_DESC"];
                spdMoveLotList_Sheet1.Cells[num, 4].Value = dt.Rows[0]["QTY"];
                spdMoveLotList_Sheet1.Cells[num, 5].Value = dt.Rows[0]["VENDOR_LOT_ID"];
                MPCF.FitColumnHeader(spdMoveLotList);
                txtInvLotID.SelectAll();
                CheckCount();
                CheckCount2();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool MoveLot(char sStep, string sMove_id)
        {
            TRSNode tRSNode = new TRSNode("MoveLot_In");
            TRSNode out_node = new TRSNode("MoveLot_Out");
            bool flag = false;
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = sStep;
                tRSNode.AddString("AREA_ID", cdvDept.Text);
                tRSNode.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
                tRSNode.AddString("FROM_OPER", cdvFromOper.Text);
                tRSNode.AddString("TO_OPER", cdvToOper.Text);
                tRSNode.AddString("MOVE_ID", sMove_id);
                for (int i = 0; i < spdMoveLotList.ActiveSheet.RowCount; i++)
                {
                    TRSNode tRSNode2 = tRSNode.AddNode("INV_LOT_LIST");
                    tRSNode2.AddString("INV_LOT_ID", spdMoveLotList.ActiveSheet.Cells[i, 1].Text);
                    tRSNode2.AddDouble("QTY", MPCF.ToDbl(spdMoveLotList.ActiveSheet.Cells[i, 4].Text));
                    flag = true;
                }
                if (!flag)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }
                if (!MPCR.CallService("CUS_INV", "CUS_INV_Move_Lot_Order", tRSNode, ref out_node))
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);
                sMove_id = "";
                if (sStep == '1')
                {
                    PrintLable("move_order", out_node.GetString("MOVE_ID"));
                }
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void PrintLable(string sPrintLabel, string sMoveID)
        {
            try
            {
                TRSNode tRSNode = new TRSNode("Print_In");
                MPCR.SetInMsg(tRSNode);
                tRSNode.AddString("MOVE_ID", sMoveID);
                CSCF.ViewLabelList(sPrintLabel, tRSNode, 'I');
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool CheckCondition(CSGC.CHECK CHECK)
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
                switch (CHECK)
                {
                    case CSGC.CHECK.SAVE:
                        if (MPCF.Trim(cdvToOper.Text) == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToOper.Text + "]");
                            cdvToOper.Focus();
                            return false;
                        }
                        if (MPCF.Trim(cdvToOper.Text).Substring(1, 4) == "C-00")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(586) + " [" + lblToOper.Text + "]");
                            cdvToOper.Focus();
                            return false;
                        }
                        if (spdMoveLotList.ActiveSheet.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(305) + " [" + grpMoveLotInfo.Text + "]");
                            return false;
                        }
                        if (string.Equals(cdvFromOper.Text, cdvToOper.Text))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(368) + " [" + lblToOper.Text + "]");
                            cdvToOper.Focus();
                            return false;
                        }
                        break;
                    case CSGC.CHECK.CANCEL:
                        if (spdMoveLotList.ActiveSheet.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(305) + " [" + grpMoveLotInfo.Text + "]");
                            return false;
                        }
                        if (spdMoveList.ActiveSheet.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(305) + " [" + grpMoveLotInfo.Text + "]");
                            return false;
                        }
                        break;
                }
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void ClearData(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "VIEW":
                        MPCF.ClearList(spdMoveLotList);
                        spdMoveLotList.ActiveSheet.ColumnFooter.Cells[0, 0].Value = 0;
                        spdMoveLotList.ActiveSheet.ColumnFooter.Cells[0, 4].Value = 0;
                        sMove_id = "";
                        break;
                    case "SAVE":
                        MPCF.ClearList(spdMoveList);
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdMoveLotList);
                        spdMoveLotList.ActiveSheet.ColumnFooter.Cells[0, 0].Value = 0;
                        spdMoveLotList.ActiveSheet.ColumnFooter.Cells[0, 4].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, 0].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, 4].Value = 0;
                        sMove_id = "";
                        txtInvLotID.Text = "";
                        txtMoveOrder.Text = "";
                        cdvToOper.Text = "";
                        break;
                    case "NEW":
                        MPCF.ClearList(spdMoveList);
                        MPCF.ClearList(spdMoveLotList);
                        spdMoveLotList.ActiveSheet.ColumnFooter.Cells[0, 0].Value = 0;
                        spdMoveLotList.ActiveSheet.ColumnFooter.Cells[0, 4].Value = 0;
                        sMove_id = "";
                        cdvToOper.Text = "";
                        cdvMatID.Text = "";
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmTranMoveRegistInvLot_Load(object sender, EventArgs e)
        {
            try
            {
                switch (cdvDept.Text)
                {
                    case "CTM":
                        cdvFromOper.Text = "CI-RAW";
                        break;
                    case "HM":
                        cdvFromOper.Text = "HI-RAW";
                        break;
                    case "GRT":
                        cdvFromOper.Text = "GI-RAW";
                        break;
                    case "PDC":
                        cdvFromOper.Text = "PI-RAW";
                        break;
                }
                if (MPGV.gsFactory == "IJDK1")
                {
                    cdvFromOper.DisplayText = "원자재 창고-자재과";
                }
                else
                {
                    cdvFromOper.DisplayText = "Raw Material warehouse";
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDept_SelectedItemChanged(object sender, MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvFromOper.Text = "";
                txtMoveOrder.Text = "";
                txtInvLotID.Text = "";
                cdvToOper.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvToOper_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvToOper.Init();
                MPCF.InitListView(cdvToOper.GetListView);
                cdvToOper.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvToOper.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvToOper.SelectedSubItemIndex = 0;
                cdvToOper.DisplaySubItemIndex = 1;
                if (COM_LIST.ViewOperationList(cdvToOper.GetListView, '7', cdvDept.Text, "", "", "", 'Y'))
                {
                    cdvToOper.InsertEmptyRow(0, 1);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnPrint_Click(object sender, EventArgs e)
        {
            try
            {
                if (spdMoveLotList.ActiveSheet.RowCount == 0)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(305) + " [" + grpMoveLotInfo.Text + "]");
                }
                else if (spdMoveList.ActiveSheet.RowCount == 0)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(305) + " [" + grpMoveLotInfo.Text + "]");
                }
                else
                {
                    PrintLable("move_order", spdMoveList.ActiveSheet.Cells[spdMoveList.ActiveSheet.ActiveRowIndex, 0].Text);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            string text = "";
            int num = 0;
            try
            {
                for (int num2 = spdLotList.ActiveSheet.RowCount; num2 > 0; num2--)
                {
                    if (spdLotList.ActiveSheet.Cells[num2 - 1, 0].Value.ToString().ToUpper() == "TRUE")
                    {
                        text = spdLotList.ActiveSheet.Cells[num2 - 1, 1].Text;
                        for (int i = 0; i < spdMoveLotList.ActiveSheet.RowCount; i++)
                        {
                            if (spdMoveLotList.ActiveSheet.Cells[i, 1].Text == text)
                            {
                            }
                        }
                        num = spdMoveLotList.ActiveSheet.RowCount;
                        spdMoveLotList.ActiveSheet.RowCount++;
                        spdMoveLotList.ActiveSheet.SetValue(num, 0, true);
                        spdMoveLotList.ActiveSheet.Cells[num, 1].Value = spdLotList.ActiveSheet.Cells[num2 - 1, 1].Text;
                        spdMoveLotList.ActiveSheet.Cells[num, 2].Value = spdLotList.ActiveSheet.Cells[num2 - 1, 2].Text;
                        spdMoveLotList.ActiveSheet.Cells[num, 3].Value = spdLotList.ActiveSheet.Cells[num2 - 1, 3].Text;
                        spdMoveLotList.ActiveSheet.Cells[num, 4].Value = spdLotList.ActiveSheet.Cells[num2 - 1, 4].Value;
                        spdMoveLotList.ActiveSheet.Cells[num, 5].Value = spdLotList.ActiveSheet.Cells[num2 - 1, 5].Value;
                        spdLotList.ActiveSheet.RemoveRows(num2 - 1, 1);
                    }
                }
                spdMoveLotList.ActiveSheet.SortRows(1, ascending: true, showIndicator: false);
                MPCF.FitColumnHeader(spdMoveLotList);
                CheckCount();
                CheckCount2();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnDel_Click(object sender, EventArgs e)
        {
            string text = "";
            int num = 0;
            try
            {
                for (int num2 = spdMoveLotList.ActiveSheet.RowCount; num2 > 0; num2--)
                {
                    if (spdMoveLotList.ActiveSheet.Cells[num2 - 1, 0].Value.ToString().ToUpper() == "TRUE")
                    {
                        text = spdMoveLotList.ActiveSheet.Cells[num2 - 1, 1].Text;
                        for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                        {
                            if (spdLotList.ActiveSheet.Cells[i, 1].Text == text)
                            {
                            }
                        }
                        num = spdLotList.ActiveSheet.RowCount;
                        spdLotList.ActiveSheet.RowCount++;
                        spdLotList.ActiveSheet.SetValue(num, 0, false);
                        spdLotList.ActiveSheet.Cells[num, 1].Value = spdMoveLotList.ActiveSheet.Cells[num2 - 1, 1].Text;
                        spdLotList.ActiveSheet.Cells[num, 2].Value = spdMoveLotList.ActiveSheet.Cells[num2 - 1, 2].Text;
                        spdLotList.ActiveSheet.Cells[num, 3].Value = spdMoveLotList.ActiveSheet.Cells[num2 - 1, 3].Text;
                        spdLotList.ActiveSheet.Cells[num, 4].Value = spdMoveLotList.ActiveSheet.Cells[num2 - 1, 4].Value;
                        spdLotList.ActiveSheet.Cells[num, 5].Value = spdMoveLotList.ActiveSheet.Cells[num2 - 1, 5].Value;
                        spdMoveLotList.ActiveSheet.RemoveRows(num2 - 1, 1);
                    }
                }
                spdLotList.ActiveSheet.SortRows(1, ascending: true, showIndicator: false);
                MPCF.FitColumnHeader(spdLotList);
                CheckCount();
                CheckCount2();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdMoveList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (!e.ColumnHeader)
                {
                    for (int i = 0; i < spdMoveList.ActiveSheet.RowCount; i++)
                    {
                        spdMoveList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                    }
                    spdMoveList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);
                    sMove_id = spdMoveList.ActiveSheet.Cells[e.Row, 0].Text;
                    cdvToOper.Text = spdMoveList.ActiveSheet.Cells[e.Row, 10].Text;
                    cdvToOper.DisplayText = spdMoveList.ActiveSheet.Cells[e.Row, 11].Text;
                    if (MPCF.Trim(sMove_id) != "")
                    {
                        ViewMoveLotList(sMove_id);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == 0)
                    {
                        CSCF.CheckSpreadCell(spdLotList, 0, 0, b_checked: true, b_isColHeaderCheckBox: true);
                    }
                    CheckCount();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdMoveLotList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == 0)
                    {
                        CSCF.CheckSpreadCell(spdMoveLotList, 0, 0, b_checked: true, b_isColHeaderCheckBox: true);
                    }
                    CheckCount2();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == '\r' && !(MPCF.Trim(txtInvLotID.Text) == ""))
                {
                    ViewLotInfo(txtInvLotID.Text);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnNew_Click(object sender, EventArgs e)
        {
            try
            {
                ClearData("NEW");
                ViewLotList();
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
                if (CheckCondition(CSGC.CHECK.VIEW))
                {
                    ClearData("VIEW");
                    ViewMoveList();
                    ViewLotList();
                }
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
                if (CheckCondition(CSGC.CHECK.SAVE) && MoveLot('1', sMove_id))
                {
                    ClearData("SAVE");
                    ViewMoveList();
                    ViewLotList();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.CANCEL))
                {
                    sMove_id = spdMoveList.ActiveSheet.Cells[spdMoveList.ActiveSheet.ActiveRowIndex, 0].Text;
                    if (MoveLot('2', sMove_id))
                    {
                        ClearData("SAVE");
                        ViewMoveList();
                        ViewLotList();
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvFromOper_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }
                cdvFromOper.Init();
                MPCF.InitListView(cdvFromOper.GetListView);
                cdvFromOper.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvFromOper.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvFromOper.SelectedSubItemIndex = 0;
                cdvFromOper.DisplaySubItemIndex = 1;
                if (COM_LIST.ViewOperationList(cdvFromOper.GetListView, '7', cdvDept.Text, "", "", "", 'Y'))
                {
                    cdvFromOper.InsertEmptyRow(0, 1);
                }
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
                frmPopMaterialList.sType_id = "RAW_MATERIAL";
                frmPopMaterialList.sType_desc = "원재료";
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

        private void spdLotList_ButtonClicked(object sender, EditorNotifyEventArgs e)
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

        private void spdLotList_Change(object sender, ChangeEventArgs e)
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

        private void spdMoveLotList_ButtonClicked(object sender, EditorNotifyEventArgs e)
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

        private void spdMoveLotList_Change(object sender, ChangeEventArgs e)
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

        private void cdvMatID_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatID.DisplayText == "")
            {
                cdvMatID.Text = "";
            }
        }

    }
}
