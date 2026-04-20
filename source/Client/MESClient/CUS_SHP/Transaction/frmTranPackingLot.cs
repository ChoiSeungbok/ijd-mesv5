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
using FarPoint.Win.Spread.CellType;
using Infragistics.Win.Misc;
using Miracom.UI;

namespace CUS_SHP
{
    public partial class frmTranPackingLot : CUS_COM.frmTranForm01
    {
        public frmTranPackingLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum PACK_ORDER
        {
            PACK_ORDER_ID,
            LINE_NO,
            MAT_DESC,
            PACK_ORD_DATE,
            QTY,
            REG_QTY,
            PACKED_QTY,
            REMAIN_QTY,
            UNIT,
            INCLUDE_INSPECTION,
            PACKING_INSTRUCTIONS,
            PACK_ORD_STATUS,
            ERP_PACK_ORDER_ID,
            CUSTOMER_ID,
            CUSTOMER_SITE_ID,
            CUSTOMER_NAME,
            DELIVERY_ID,
            DELIVERY_NAME,
            MAT_ID,
            MAT_VER,
            OPER,
            OPER_DESC,
            DRAWING_FLAG,
            ORDER_TYPE,
            REQUEST_DATE,
            SCHEDULE_SHIP_DATE,
            PO_GUBUN,
            LABEL_TYPE,
            LABEL_MESH,
            LABEL_NAME
        }

        private enum PACK_LOT
        {
            CHK,
            ORG_LOT_ID,
            PACK_LOT_ID,
            MAT_DESC,
            QTY,
            UNIT,
            PACK_FLAG,
            PACK_ORDER_ID,
            PACK_LINE_NO,
            MAT_ID,
            MAT_VER,
            ERP_PACK_ORDER_ID,
            SHIP_FLAG,
            LAST_COMMENT
        }



        #endregion

        #region " Variable Definition "
        string packOrderId = "";
        string packLineNo = "";
        string file_name = "";
        double pack_remain_qty = 0;
        string matId = "";
        #endregion

        private void InitControl()
        {
            try
            {
                chkMeshDeleteFlag.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                lblLableSize.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                cdvLabelSize.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewPackingOrderList()
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[9];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "AREA_ID";
                array[1].sCondition_Value = cdvDept.Text;
                array[2].sCondition_ID = "OPER";
                array[2].sCondition_Value = cdvPackOper.Text;
                array[3].sCondition_ID = "MAT_ID";
                array[3].sCondition_Value = cdvMatID.DisplayText;
                array[4].sCondition_ID = "PACK_ORDER_ID";
                array[4].sCondition_Value = txtPackingOrderNo.Text;
                array[5].sCondition_ID = "CUSTOMER_ID";
                array[5].sCondition_Value = cdvCustomerID.Text;
                array[6].sCondition_ID = "FROM_DATE";
                array[6].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", ""));
                array[7].sCondition_ID = "TO_DATE";
                array[7].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";
                array[8].sCondition_ID = "ERP_PACK_ORDER_ID";
                array[8].sCondition_Value = txtERPPackingOrderNo.Text.Trim();
                if (!TPDR.GetDataOne("", ref dt, "CSHP2001-001", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdOrderList);
                    return;
                }
                MPCF.ClearList(spdOrderList);
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdOrderList_Sheet1.RowCount++;
                    spdOrderList_Sheet1.Cells[num, 0].Value = dt.Rows[num]["PACK_ORDER_ID"];
                    spdOrderList_Sheet1.Cells[num, 1].Value = dt.Rows[num]["LINE_NO"];
                    spdOrderList_Sheet1.Cells[num, 12].Value = dt.Rows[num]["CMF_1"];
                    spdOrderList_Sheet1.Cells[num, 18].Value = dt.Rows[num]["MAT_ID"];
                    spdOrderList_Sheet1.Cells[num, 19].Value = dt.Rows[num]["MAT_VER"];
                    spdOrderList_Sheet1.Cells[num, 2].Value = dt.Rows[num]["MAT_DESC"];
                    spdOrderList_Sheet1.Cells[num, 3].Value = MPCF.MakeDateFormat(dt.Rows[num]["PACK_ORD_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdOrderList_Sheet1.Cells[num, 4].Value = dt.Rows[num]["QTY"];
                    spdOrderList_Sheet1.Cells[num, 5].Value = dt.Rows[num]["REG_QTY"];
                    spdOrderList_Sheet1.Cells[num, 6].Value = dt.Rows[num]["PACKED_QTY"];
                    spdOrderList_Sheet1.Cells[num, 7].Value = Convert.ToDouble(dt.Rows[num]["QTY"]) - Convert.ToDouble(dt.Rows[num]["REG_QTY"]);
                    spdOrderList_Sheet1.Cells[num, 8].Value = dt.Rows[num]["UNIT"];
                    spdOrderList_Sheet1.Cells[num, 9].Value = dt.Rows[num]["INCLUDE_INSPECTION"];
                    spdOrderList_Sheet1.Cells[num, 11].Value = dt.Rows[num]["PACK_ORD_STATUS"];
                    spdOrderList_Sheet1.Cells[num, 13].Value = dt.Rows[num]["CUSTOMER_ID"];
                    spdOrderList_Sheet1.Cells[num, 14].Value = dt.Rows[num]["CUSTOMER_SITE_ID"];
                    spdOrderList_Sheet1.Cells[num, 15].Value = dt.Rows[num]["CUSTOMER_NAME"];
                    spdOrderList_Sheet1.Cells[num, 16].Value = dt.Rows[num]["DELIVERY_ID"];
                    spdOrderList_Sheet1.Cells[num, 17].Value = dt.Rows[num]["DELIVERY_NAME"];

                    spdOrderList_Sheet1.Cells[num, 10].Value = dt.Rows[num]["PACKING_INSTRUCTIONS"];
                    spdOrderList_Sheet1.Cells[num, 20].Value = dt.Rows[num]["OPER"];
                    spdOrderList_Sheet1.Cells[num, 21].Value = dt.Rows[num]["OPER_DESC"];
                    spdOrderList_Sheet1.Cells[num, 22].Value = dt.Rows[num]["DRAWING_FLAG"];
                    spdOrderList_Sheet1.Cells[num, 23].Value = dt.Rows[num]["ORDER_TYPE"];
                    spdOrderList_Sheet1.Cells[num, 24].Value = MPCF.MakeDateFormat(dt.Rows[num]["REQUEST_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdOrderList_Sheet1.Cells[num, 25].Value = MPCF.MakeDateFormat(dt.Rows[num]["SCHEDULE_SHIP_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdOrderList_Sheet1.Cells[num, 26].Value = dt.Rows[num]["PO_GUBUN"];
                    spdOrderList_Sheet1.Cells[num, 27].Value = dt.Rows[num]["LABEL_TYPE"];
                    spdOrderList_Sheet1.Cells[num, 28].Value = dt.Rows[num]["LABEL_MESH"];
                    spdOrderList_Sheet1.Cells[num, 29].Value = dt.Rows[num]["LABEL_NAME"];
                    if (packOrderId == spdOrderList_Sheet1.Cells[num, 0].Value.ToString().Trim() && packLineNo == spdOrderList_Sheet1.Cells[num, 1].Value.ToString().Trim())
                    {
                        EXTFUC.SetSelectSheet(spdOrderList, num);
                    }
                }
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
                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (spdPackingLotList_Sheet1.Cells[i, 0].Value.ToString().ToUpper() == "TRUE")
                    {
                        num2++;
                        num += MPCF.ToDbl(spdPackingLotList.ActiveSheet.Cells[i, 4].Text);
                    }
                }
                spdPackingLotList_Sheet1.ColumnFooter.Cells[0, 0].Value = num2;
                spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, 4].Value = num;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewPackingLotList(string packOrderId, string packLineNo)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                double num2 = 0.0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "PACK_ORDER_ID";
                array[1].sCondition_Value = packOrderId;
                array[2].sCondition_ID = "PACK_LINE_NO";
                array[2].sCondition_Value = packLineNo;
                if (!TPDR.GetDataOne("", ref dt, "CSHP2001-008", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdPackingLotList);
                    return;
                }
                MPCF.ClearList(spdPackingLotList);
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdPackingLotList_Sheet1.RowCount++;
                    spdPackingLotList_Sheet1.SetValue(num, 0, false);
                    spdPackingLotList_Sheet1.Cells[num, 1].Value = dt.Rows[num]["ORG_LOT_ID"];
                    spdPackingLotList_Sheet1.Cells[num, 2].Value = dt.Rows[num]["PACK_LOT_ID"];
                    spdPackingLotList_Sheet1.Cells[num, 9].Value = dt.Rows[num]["MAT_ID"];
                    spdPackingLotList_Sheet1.Cells[num, 10].Value = dt.Rows[num]["MAT_VER"];
                    spdPackingLotList_Sheet1.Cells[num, 3].Value = dt.Rows[num]["MAT_DESC"];
                    spdPackingLotList_Sheet1.Cells[num, 4].Value = dt.Rows[num]["QTY"];
                    spdPackingLotList_Sheet1.Cells[num, 5].Value = dt.Rows[num]["UNIT"];
                    spdPackingLotList_Sheet1.Cells[num, 6].Value = dt.Rows[num]["PACK_FLAG"];
                    spdPackingLotList_Sheet1.Cells[num, 7].Value = dt.Rows[num]["PACK_ORDER_ID"];
                    spdPackingLotList_Sheet1.Cells[num, 8].Value = dt.Rows[num]["PACK_LINE_NO"];
                    spdPackingLotList_Sheet1.Cells[num, 11].Value = dt.Rows[num]["CMF_5"];
                    spdPackingLotList_Sheet1.Cells[num, 12].Value = dt.Rows[num]["SHIP_FLAG"];
                    spdPackingLotList_Sheet1.Cells[num, 13].Value = dt.Rows[num]["LAST_COMMENT"];
                }
                MPCF.FitColumnHeader(spdPackingLotList);
                for (num = 0; num < spdPackingLotList_Sheet1.RowCount; num++)
                {
                    num2 += MPCF.ToDbl(spdPackingLotList.ActiveSheet.Cells[num, 4].Text);
                }
                spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, 4].Value = num2;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void InputPackLot()
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                bool flag = true;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "OPER";
                array[1].sCondition_Value = cdvPackOper.Text;
                array[2].sCondition_ID = "LOT_ID";
                array[2].sCondition_Value = txtLotID.Text;
                array[3].sCondition_ID = "PACK_ORDER_ID";
                array[3].sCondition_Value = packOrderId;
                array[4].sCondition_ID = "LINE_NO";
                array[4].sCondition_Value = packLineNo;
                if (!TPDR.GetDataOne("", ref dt, "CSHP2001-009", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ShowMsgBox(MPCF.GetMessage(481));
                    txtLotID.Text = "";
                    return;
                }
                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (object.Equals(spdPackingLotList_Sheet1.Cells[i, 1].Text, dt.Rows[0]["ORG_LOT_ID"]))
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    if (MPCF.Trim(dt.Rows[0]["PACK_ORDER_ID"].ToString()) != "")
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(493));
                        return;
                    }
                    if (pack_remain_qty - MPCF.ToDbl(dt.Rows[0]["QTY"]) < 0.0)
                    {
                        txtLotID.b_Stop_Flag = true;
                        MPCF.ShowMsgBox(MPCF.GetMessage(496));
                        return;
                    }
                    pack_remain_qty -= MPCF.ToDbl(dt.Rows[0]["QTY"]);
                    num = spdPackingLotList_Sheet1.RowCount++;
                    spdPackingLotList_Sheet1.SetValue(num, 0, true);
                    spdPackingLotList_Sheet1.Cells[num, 1].Value = dt.Rows[0]["ORG_LOT_ID"];
                    spdPackingLotList_Sheet1.Cells[num, 2].Value = dt.Rows[0]["PACK_LOT_ID"];
                    spdPackingLotList_Sheet1.Cells[num, 9].Value = dt.Rows[0]["MAT_ID"];
                    spdPackingLotList_Sheet1.Cells[num, 10].Value = dt.Rows[0]["MAT_VER"];
                    spdPackingLotList_Sheet1.Cells[num, 3].Value = dt.Rows[0]["MAT_DESC"];
                    spdPackingLotList_Sheet1.Cells[num, 4].Value = dt.Rows[0]["QTY"];
                    spdPackingLotList_Sheet1.Cells[num, 5].Value = dt.Rows[0]["UNIT"];
                    spdPackingLotList_Sheet1.Cells[num, 6].Value = dt.Rows[0]["PACK_FLAG"];
                    spdPackingLotList_Sheet1.Cells[num, 7].Value = dt.Rows[0]["PACK_ORDER_ID"];
                    spdPackingLotList_Sheet1.Cells[num, 8].Value = dt.Rows[0]["PACK_LINE_NO"];
                    spdPackingLotList_Sheet1.Cells[num, 12].Value = dt.Rows[0]["SHIP_FLAG"];
                    spdPackingLotList_Sheet1.Cells[num, 13].Value = dt.Rows[0]["LAST_COMMENT"];
                    MPCF.FitColumnHeader(spdPackingLotList);
                }
                txtLotID.Text = "";
                CheckCount();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool CreatePackingLot()
        {
            TRSNode tRSNode = new TRSNode("create_packing_Lot_In");
            TRSNode out_node = new TRSNode("create_packing_Lot_Out");
            TRSNode tRSNode2 = new TRSNode("print_label_In");
            bool flag = false;
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("PACK_ORDER_ID", spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, 0].Text);
                tRSNode.AddInt("LINE_NO", MPCF.ToInt(spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, 1].Text));
                tRSNode.AddString("AREA_ID", cdvDept.Text);
                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (spdPackingLotList_Sheet1.Cells[i, 0].Text.ToString().ToUpper() == "TRUE" && !(MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, 7].Text) != ""))
                    {
                        TRSNode tRSNode3 = tRSNode.AddNode("PACK_LOT_LIST");
                        tRSNode3.AddString("ORG_LOT_ID", spdPackingLotList_Sheet1.Cells[i, 1].Text);
                        tRSNode3.AddString("PACK_LOT_ID", spdPackingLotList_Sheet1.Cells[i, 2].Text);
                        tRSNode3.AddDouble("QTY", MPCF.ToDbl(spdPackingLotList_Sheet1.Cells[i, 4].Text));
                        flag = true;
                    }
                }
                if (!flag)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }
                if (!MPCR.CallService("CUS_SHP", "CUS_SHP_Create_Pack_Lot", tRSNode, ref out_node))
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);
                MPCR.SetInMsg(tRSNode2);
                tRSNode2.AddChar("MESH_DELETE_FLAG", chkMeshDeleteFlag.Checked ? 'Y' : 'N');
                for (int j = 0; j < out_node.GetList(0).Count; j++)
                {
                    TRSNode tRSNode4 = tRSNode2.AddNode("PACK_LOT_LIST");
                    tRSNode4.AddString("PACK_LOT_ID", out_node.GetList(0)[j].GetString("PACK_LOT_ID"));
                    tRSNode4.AddString("ORG_LOT_ID", out_node.GetList(0)[j].GetString("ORG_LOT_ID"));
                }
                file_name = cdvLabelSize.Text;
                ViewPrintLabel(file_name, tRSNode2);
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool CheckCondition(string sType)
        {
            try
            {
                if (MPCF.Trim(cdvPackOper.Text) == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblPackOper.Text + "]");
                    cdvPackOper.Focus();
                    return false;
                }
                switch (sType)
                {
                    case "REGIST":
                        if (spdOrderList.ActiveSheet.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }
                        if (spdPackingLotList.ActiveSheet.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }
                        if (MPCF.Trim(cdvLabelSize.Text) == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLableSize.Text + "]");
                            cdvLabelSize.Focus();
                            return false;
                        }
                        break;
                    case "DELETE":
                        if (spdOrderList.ActiveSheet.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }
                        if (spdPackingLotList.ActiveSheet.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }
                        break;
                    case "INPUT":
                        if (spdOrderList.ActiveSheet.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }
                        break;
                    case "OPEN":
                        if (spdOrderList.ActiveSheet.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }
                        if (string.IsNullOrEmpty(matId))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
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

        private void ClearList(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "VIEW":
                        MPCF.ClearList(spdOrderList);
                        MPCF.ClearList(spdPackingLotList);
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, 0].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, 4].Value = 0;
                        txtLotID.Text = "";
                        pack_remain_qty = 0.0;
                        matId = "";
                        txtLotID.b_Stop_Flag = false;
                        break;
                    case "ALL":
                        MPCF.ClearList(spdOrderList);
                        MPCF.ClearList(spdPackingLotList);
                        dtpToWorkDate.Value = DateTime.Now;
                        dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7.0);
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, 0].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, 4].Value = 0;
                        cdvPackOper.Text = "";
                        cdvMatID.Text = "";
                        cdvCustomerID.Text = "";
                        txtPackingOrderNo.Text = "";
                        txtLotID.Text = "";
                        pack_remain_qty = 0.0;
                        matId = "";
                        chkMeshDeleteFlag.Checked = false;
                        txtLotID.b_Stop_Flag = false;
                        break;
                    case "ORDER_CLICK_CELL":
                        MPCF.ClearList(spdPackingLotList);
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, 0].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, 4].Value = 0;
                        txtLotID.Text = "";
                        pack_remain_qty = 0.0;
                        txtLotID.b_Stop_Flag = false;
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        public bool ViewPrintLabel(string sFileName, TRSNode in_node)
        {
            try
            {
                CSCF.ViewLabelList(sFileName, in_node);
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void frmTranPackingLot_Load(object sender, EventArgs e)
        {
            try
            {
                chkMeshDeleteFlag.Checked = false;
                dtpToWorkDate.Value = DateTime.Now;
                dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7.0);
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

        private void cdvPackOper_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvPackOper.Init();
                MPCF.InitListView(cdvPackOper.GetListView);
                cdvPackOper.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvPackOper.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvPackOper.SelectedSubItemIndex = 0;
                cdvPackOper.DisplaySubItemIndex = 1;
                if (COM_LIST.ViewOperationList(cdvPackOper.GetListView, '6', cdvDept.Text, "", "", "", 'Y'))
                {
                    cdvPackOper.InsertEmptyRow(0, 1);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvCustomerID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopCustomerList frmPopCustomerList = new frmPopCustomerList();
                frmPopCustomerList.StartPosition = FormStartPosition.CenterParent;
                if (frmPopCustomerList.ShowDialog() == DialogResult.OK)
                {
                    cdvCustomerID.Text = frmPopCustomerList.g_CustomerId;
                    cdvCustomerID.DisplayText = frmPopCustomerList.g_CustomerDesc;
                    frmPopCustomerList = null;
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
                if (e.KeyChar == '\r' && CheckCondition("INPUT"))
                {
                    InputPackLot();
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
                    ViewPackingOrderList();
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
                if (CheckCondition("REGIST") && CreatePackingLot())
                {
                    ClearList("ORDER_CLICK_CELL");
                    ViewPackingOrderList();
                    ViewPackingLotList(packOrderId, packLineNo);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdOrderList_CellClick(object sender, CellClickEventArgs e)
        {
            ClearList("ORDER_CLICK_CELL");
            try
            {
                if (e.Row < 0 || e.ColumnHeader)
                {
                    return;
                }
                for (int i = 0; i < spdOrderList.ActiveSheet.RowCount; i++)
                {
                    spdOrderList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                    if (cdvDept.Text == CSGV.gs_area_ctm)
                    {
                        string text = spdOrderList.ActiveSheet.Cells[e.Row, 2].Text;
                        string text2 = spdOrderList.ActiveSheet.Cells[e.Row, 29].Text;　　// 라벨명
                        if (text.StartsWith("(IDV)."))
                        {
                            text = text.Substring(6);
                        }
                        if (text.StartsWith("SPL."))
                        {
                            text = text.Substring(4);
                        }
                        string text3 = (text.Contains(".") ? text.Substring(0, text.IndexOf('.')) : text);
                        string text4 = (text2.Contains(" ") ? text2.Substring(0, text2.IndexOf(' ')) : text2);
                        if (text3 != text4)
                        {
                            lblLabelNameError.Text = ((MPCF.GetMessage(618) == "No Error Message") ? "" : (MPCF.GetMessage(618) + "(" + text3 + "->" + text4 + ")"));
                        }
                        else
                        {
                            lblLabelNameError.Text = "";
                        }
                    }
                }
                spdOrderList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);
                packOrderId = spdOrderList.ActiveSheet.Cells[e.Row, 0].Text;
                packLineNo = spdOrderList.ActiveSheet.Cells[e.Row, 1].Text;
                pack_remain_qty = MPCF.ToDbl(spdOrderList.ActiveSheet.Cells[e.Row, 4].Text) - MPCF.ToDbl(spdOrderList.ActiveSheet.Cells[e.Row, 5].Text);
                matId = spdOrderList.ActiveSheet.Cells[e.Row, 18].Text; //제품코드
                ViewPackingLotList(packOrderId, packLineNo);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdPackingLotList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                if (spdPackingLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdPackingLotList, e.Row, e.Column, b_checked: true, b_isColHeaderCheckBox: true);
                }
                CheckCount();
            }
        }

        private void btnPrint_Click(object sender, EventArgs e)
        {
            try
            {
                bool flag = false;
                bool flag2 = false;
                TRSNode tRSNode = new TRSNode("print_label_In");
                MPCR.SetInMsg(tRSNode);
                tRSNode.AddChar("MESH_DELETE_FLAG", chkMeshDeleteFlag.Checked ? 'Y' : 'N');
                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (spdPackingLotList_Sheet1.Cells[i, 0].Value.ToString().ToUpper() == "TRUE")
                    {
                        flag2 = true;
                        if (!(MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, 7].Text) == ""))
                        {
                            TRSNode tRSNode2 = tRSNode.AddNode("PACK_LOT_LIST");
                            tRSNode2.AddString("PACK_LOT_ID", spdPackingLotList_Sheet1.Cells[i, 2].Text);
                            tRSNode2.AddString("ORG_LOT_ID", spdPackingLotList_Sheet1.Cells[i, 1].Text);
                            flag = true;
                        }
                    }
                }
                if (!flag2)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return;
                }
                if (!flag)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(506));
                    return;
                }
                file_name = cdvLabelSize.Text;
                if (!ViewPrintLabel(file_name, tRSNode))
                {
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvLabelSize_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvLabelSize.Init();
                MPCF.InitListView(cdvLabelSize.GetListView);
                cdvLabelSize.Columns.Add("Size", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvLabelSize.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvLabelSize.Columns.Add("Code", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvLabelSize.SelectedSubItemIndex = 2;
                cdvLabelSize.DisplaySubItemIndex = 1;
                if (COM_LIST.ViewLabelGCMList(cdvLabelSize.GetListView, cdvDept.Text, "SHIP"))
                {
                    cdvLabelSize.InsertEmptyRow(0, 1);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdPackingLotList_ButtonClicked(object sender, EditorNotifyEventArgs e)
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

        private void spdPackingLotList_Change(object sender, ChangeEventArgs e)
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

        private void cdvDept_SelectedItemChanged(object sender, MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
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

        private void cdvCustomerID_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvCustomerID.DisplayText == "")
            {
                cdvCustomerID.Text = "";
            }
        }

        private void txtPackingOrderNo_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == '\r')
                {
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void dtpFromWorkDate_ValueChanged(object sender, EventArgs e)
        {
            dtpFromWorkDate.CustomFormat = "yyyy-MM-dd";
        }

        private void dtpFromWorkDate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            Keys keyCode = e.KeyCode;
            Keys keys = keyCode;
            if (keys == Keys.Delete)
            {
                dtpFromWorkDate.CustomFormat = " ";
            }
        }

        private void dtpFromWorkDate_CloseUp(object sender, EventArgs e)
        {
            dtpFromWorkDate.CustomFormat = "yyyy-MM-dd";
        }

        private void txtLotID_ButtonClick(object sender, AlertButtonClickedEventArgs e)
        {
            if (CheckCondition("OPEN"))
            {
                txtLotID.sArea_id = cdvDept.Text;
                txtLotID.sArea_desc = cdvDept.DisplayText;
                txtLotID.sOper_id = cdvPackOper.Text;
                txtLotID.sOper_desc = cdvPackOper.DisplayText;
                txtLotID.sMat_id = matId;
            }
        }

        private void btnGCM_Click(object sender, EventArgs e)
        {
            try
            {
                frmPopGcmData frmPopGcmData = new frmPopGcmData();
                frmPopGcmData.StartPosition = FormStartPosition.CenterParent;
                frmPopGcmData.sTable_name = "C_SHP_ALL_SHIP_CUS";
                frmPopGcmData.sViewOnly = "Y";
                frmPopGcmData.sTable_name_desc = ((MPCF.GetMessage(620) == "No Error Message") ? "" : MPCF.GetMessage(620));
                frmPopGcmData.sComment = ((MPCF.GetMessage(619) == "No Error Message") ? "" : MPCF.GetMessage(619));
                if (frmPopGcmData.ShowDialog() == DialogResult.OK)
                {
                    frmPopGcmData = null;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

    }
}
