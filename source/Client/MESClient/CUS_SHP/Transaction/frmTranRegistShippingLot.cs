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
using CUS_COM.Reports;
using System.Xml.Linq;
using FarPoint.Win.Spread.CellType;
using Miracom.UI;

namespace CUS_SHP
{
    public partial class frmTranRegistShippingLot : CUS_COM.frmTranForm01
    {
        public frmTranRegistShippingLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum SHIP_MST
        {
            SHIP_ORDER_ID,
            SHIP_ORD_DATE,
            CUSTOMER_ID,
            CUSTOMER_NUMBER,
            CUSTOMER_NAME,
            AREA_ID,
            OPER,
            OPER_DESC,
            DELIVERY,
            DELIVERY_ID,
            DELIVERY_NAME,
            DELIVERY_LOCATION,
            DELIVERY_PHONE_NO,
            DELIVERY_USER_ID,
            SHIP_ORD_STATUS
        }

        private enum SHIP_DTL
        {
            SHIP_ORDER_ID,
            SEQ,
            MAT_DESC,
            LABEL_NAME,
            SHIP_ORD_STATUS,
            PACK_ORDER_ID,
            PACK_LINE_NO,
            ERP_PACK_ORDER_ID,
            QTY,
            REG_QTY,
            UNIT,
            MAT_ID,
            MAT_VER
        }

        private enum PACK_LOT
        {
            CHK,
            ORG_LOT_ID,
            PACK_LOT_ID,
            QTY,
            UNIT,
            PACK_FLAG,
            PACK_ORDER_ID,
            PACK_LINE_NO,
            ERP_PACK_ORDER_ID,
            OPERATION_MAT_ID,
            OPERATION_MAT_DESC,
            SHIP_FLAG,
            SHIP_ORDER_ID,
            SHIP_ORDER_SEQ,
            BOX_ID,
            FINAL_BOX_ID,
            REPORT_NO,
            SPLITE_QTY,
            SPLITE_BTN
        }

        #endregion

        #region " Variable Definition "
        string shipOrderId = "";
        string seq = "";
        bool b_refresh_flag = false;
        #endregion

        private void InitControl()
        {
            try
            {
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnCancel.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewShippingOrderList()
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[6];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                b_refresh_flag = false;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "AREA_ID";
                array[1].sCondition_Value = cdvDept.Text;
                array[2].sCondition_ID = "SHIP_ORDER_ID";
                array[2].sCondition_Value = txtShippingOrderNo.Text;
                array[3].sCondition_ID = "OPER";
                array[3].sCondition_Value = cdvShipOper.Text;
                array[4].sCondition_ID = "FROM_DATE";
                array[4].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", ""));
                array[5].sCondition_ID = "TO_DATE";
                array[5].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";
                if (!TPDR.GetDataOne("", ref dt, "CSHP2003-005", array, bIcon: false, bBGColor: false, ref sSql))
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
                    spdOrderList_Sheet1.Cells[num, 0].Value = dt.Rows[num]["SHIP_ORDER_ID"];
                    spdOrderList_Sheet1.Cells[num, 1].Value = MPCF.MakeDateFormat(dt.Rows[num]["SHIP_ORD_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdOrderList_Sheet1.Cells[num, 2].Value = dt.Rows[num]["CUSTOMER_ID"];
                    spdOrderList_Sheet1.Cells[num, 3].Value = dt.Rows[num]["CUSTOMER_NUMBER"];
                    spdOrderList_Sheet1.Cells[num, 4].Value = dt.Rows[num]["CUSTOMER_NAME"];
                    spdOrderList_Sheet1.Cells[num, 5].Value = dt.Rows[num]["AREA_ID"];
                    spdOrderList_Sheet1.Cells[num, 6].Value = dt.Rows[num]["OPER"];
                    spdOrderList_Sheet1.Cells[num, 7].Value = dt.Rows[num]["OPER_DESC"];
                    spdOrderList_Sheet1.Cells[num, 8].Value = dt.Rows[num]["DELIVERY"];
                    spdOrderList_Sheet1.Cells[num, 9].Value = dt.Rows[num]["DELIVERY_ID"];
                    spdOrderList_Sheet1.Cells[num, 10].Value = dt.Rows[num]["DELIVERY_NAME"];
                    spdOrderList_Sheet1.Cells[num, 11].Value = dt.Rows[num]["DELIVERY_LOCATION"];
                    spdOrderList_Sheet1.Cells[num, 12].Value = dt.Rows[num]["DELIVERY_PHONE_NO"];
                    spdOrderList_Sheet1.Cells[num, 13].Value = dt.Rows[num]["DELIVERY_USER_ID"];
                    spdOrderList_Sheet1.Cells[num, 14].Value = dt.Rows[num]["SHIP_ORD_STATUS"];
                    if (shipOrderId == spdOrderList_Sheet1.Cells[num, 0].Value.ToString().Trim())
                    {
                        EXTFUC.SetSelectSheet(spdOrderList, num);
                        b_refresh_flag = true;
                    }
                }
                MPCF.FitColumnHeader(spdOrderList);
                if (!b_refresh_flag)
                {
                    shipOrderId = "";
                    seq = "";
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewShippingOrderDetailList(string shipOrderId)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                b_refresh_flag = false;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "SHIP_ORDER_ID";
                array[1].sCondition_Value = shipOrderId;
                if (!TPDR.GetDataOne("", ref dt, "CSHP2003-008", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdOrderDetailList);
                    return;
                }
                MPCF.ClearList(spdOrderDetailList);
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdOrderDetailList_Sheet1.RowCount++;
                    spdOrderDetailList_Sheet1.Cells[num, 0].Value = dt.Rows[num]["SHIP_ORDER_ID"];
                    spdOrderDetailList_Sheet1.Cells[num, 1].Value = dt.Rows[num]["SEQ"];
                    spdOrderDetailList_Sheet1.Cells[num, 11].Value = dt.Rows[num]["MAT_ID"];
                    spdOrderDetailList_Sheet1.Cells[num, 12].Value = dt.Rows[num]["MAT_VER"];
                    spdOrderDetailList_Sheet1.Cells[num, 2].Value = dt.Rows[num]["MAT_DESC"];
                    spdOrderDetailList_Sheet1.Cells[num, 4].Value = dt.Rows[num]["SHIP_ORD_STATUS"];
                    spdOrderDetailList_Sheet1.Cells[num, 5].Value = dt.Rows[num]["PACK_ORDER_ID"];
                    spdOrderDetailList_Sheet1.Cells[num, 6].Value = dt.Rows[num]["PACK_LINE_NO"];
                    spdOrderDetailList_Sheet1.Cells[num, 7].Value = dt.Rows[num]["CMF_1"];
                    spdOrderDetailList_Sheet1.Cells[num, 8].Value = dt.Rows[num]["QTY"];
                    spdOrderDetailList_Sheet1.Cells[num, 10].Value = dt.Rows[num]["UNIT"];
                    spdOrderDetailList_Sheet1.Cells[num, 9].Value = dt.Rows[num]["REG_QTY"];
                    spdOrderDetailList_Sheet1.Cells[num, 3].Value = dt.Rows[num]["LABEL_NAME"];
                    spdOrderDetailList_Sheet1.Cells[num, 13].Value = dt.Rows[num]["INCLUDE_INSPECTION"];
                    if (shipOrderId == spdOrderDetailList_Sheet1.Cells[num, 0].Value.ToString().Trim() && seq == spdOrderDetailList_Sheet1.Cells[num, 1].Value.ToString().Trim())
                    {
                        EXTFUC.SetSelectSheet(spdOrderDetailList, num);
                        b_refresh_flag = true;
                    }
                }
                MPCF.FitColumnHeader(spdOrderDetailList);
                if (!b_refresh_flag)
                {
                    shipOrderId = "";
                    seq = "";
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewPackingLotListForHM(string shipOrderId)
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
                array[1].sCondition_ID = "SHIP_ORDER_ID";
                array[1].sCondition_Value = shipOrderId;
                array[2].sCondition_ID = "REGIST_FLAG";
                array[2].sCondition_Value = "";
                if (!TPDR.GetDataOne("", ref dt, "CSHP2006-003", array, bIcon: false, bBGColor: false, ref sSql))
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
                    spdPackingLotList_Sheet1.Cells[num, 3].Value = dt.Rows[num]["QTY"];
                    spdPackingLotList_Sheet1.Cells[num, 4].Value = dt.Rows[num]["UNIT"];
                    spdPackingLotList_Sheet1.Cells[num, 9].Value = dt.Rows[num]["MAT_ID"];
                    spdPackingLotList_Sheet1.Cells[num, 10].Value = dt.Rows[num]["MAT_DESC"];
                    spdPackingLotList_Sheet1.Cells[num, 5].Value = dt.Rows[num]["PACK_FLAG"];
                    spdPackingLotList_Sheet1.Cells[num, 6].Value = dt.Rows[num]["PACK_ORDER_ID"];
                    spdPackingLotList_Sheet1.Cells[num, 7].Value = dt.Rows[num]["PACK_LINE_NO"];
                    spdPackingLotList_Sheet1.Cells[num, 8].Value = dt.Rows[num]["CMF_5"];
                    spdPackingLotList_Sheet1.Cells[num, 11].Value = dt.Rows[num]["SHIP_FLAG"];
                    spdPackingLotList_Sheet1.Cells[num, 12].Value = dt.Rows[num]["SHIP_ORDER_ID"];
                    spdPackingLotList_Sheet1.Cells[num, 13].Value = dt.Rows[num]["SHIP_ORDER_SEQ"];
                    spdPackingLotList_Sheet1.Cells[num, 14].Value = dt.Rows[num]["BOX_ID_1"];
                    spdPackingLotList_Sheet1.Cells[num, 15].Value = dt.Rows[num]["BOX_ID_2"];
                    spdPackingLotList_Sheet1.Cells[num, 16].Value = dt.Rows[num]["REPORT_NO"];
                    if (cdvDept.Text == "HM")
                    {
                        spdPackingLotList_Sheet1.Columns.Get(17).Visible = true;
                        spdPackingLotList_Sheet1.Columns.Get(18).Visible = true;
                    }
                    else
                    {
                        spdPackingLotList_Sheet1.Columns.Get(17).Visible = true;
                        spdPackingLotList_Sheet1.Columns.Get(18).Visible = true;
                    }
                    if (spdPackingLotList_Sheet1.Cells[num, 16].Text == "")
                    {
                        spdPackingLotList_Sheet1.Rows[num].BackColor = Color.OrangeRed;
                    }
                }
                MPCF.FitColumnHeader(spdPackingLotList);
                for (num = 0; num < spdPackingLotList_Sheet1.RowCount; num++)
                {
                    num2 += MPCF.ToDbl(spdPackingLotList.ActiveSheet.Cells[num, 3].Text);
                }
                spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, 3].Value = num2;
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
                        num += MPCF.ToDbl(spdPackingLotList.ActiveSheet.Cells[i, 3].Text);
                    }
                }
                spdPackingLotList_Sheet1.ColumnFooter.Cells[0, 0].Value = num2;
                spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, 3].Value = num;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewPackingLotList(string shipOrderId, string seq)
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
                array[1].sCondition_ID = "SHIP_ORDER_ID";
                array[1].sCondition_Value = shipOrderId;
                array[2].sCondition_ID = "SEQ";
                array[2].sCondition_Value = seq;
                array[3].sCondition_ID = "REGIST_FLAG";
                array[3].sCondition_Value = "";
                if (!TPDR.GetDataOne("", ref dt, "CSHP2006-004", array, bIcon: false, bBGColor: false, ref sSql))
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
                    spdPackingLotList_Sheet1.Cells[num, 3].Value = dt.Rows[num]["QTY"];
                    spdPackingLotList_Sheet1.Cells[num, 4].Value = dt.Rows[num]["UNIT"];
                    spdPackingLotList_Sheet1.Cells[num, 9].Value = dt.Rows[num]["OPERATION_MAT_ID"];
                    spdPackingLotList_Sheet1.Cells[num, 10].Value = dt.Rows[num]["OPERATION_MAT_DESC"];
                    spdPackingLotList_Sheet1.Cells[num, 5].Value = dt.Rows[num]["PACK_FLAG"];
                    spdPackingLotList_Sheet1.Cells[num, 6].Value = dt.Rows[num]["PACK_ORDER_ID"];
                    spdPackingLotList_Sheet1.Cells[num, 7].Value = dt.Rows[num]["PACK_LINE_NO"];
                    spdPackingLotList_Sheet1.Cells[num, 8].Value = dt.Rows[num]["CMF_5"];
                    spdPackingLotList_Sheet1.Cells[num, 11].Value = dt.Rows[num]["SHIP_FLAG"];
                    spdPackingLotList_Sheet1.Cells[num, 12].Value = dt.Rows[num]["SHIP_ORDER_ID"];
                    spdPackingLotList_Sheet1.Cells[num, 13].Value = dt.Rows[num]["SHIP_ORDER_SEQ"];
                    spdPackingLotList_Sheet1.Cells[num, 14].Value = dt.Rows[num]["BOX_ID_1"];
                    spdPackingLotList_Sheet1.Cells[num, 15].Value = dt.Rows[num]["BOX_ID_2"];
                }
                MPCF.FitColumnHeader(spdPackingLotList);
                for (num = 0; num < spdPackingLotList_Sheet1.RowCount; num++)
                {
                    num2 += MPCF.ToDbl(spdPackingLotList.ActiveSheet.Cells[num, 3].Text);
                }
                spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, 3].Value = num2;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ScanPackLot()
        {
            try
            {
                bool flag = false;
                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (string.Equals(spdPackingLotList_Sheet1.Cells[i, 2].Text, txtPackingLotID.Text))
                    {
                        spdPackingLotList_Sheet1.SetValue(i, 0, true);
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(481));
                }
                txtPackingLotID.SelectAll();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ScanPackBox()
        {
            try
            {
                bool flag = false;
                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (string.Equals(spdPackingLotList_Sheet1.Cells[i, 14].Text, txtBoxID.Text))
                    {
                        spdPackingLotList_Sheet1.SetValue(i, 0, true);
                        flag = true;
                    }
                }
                if (!flag)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(481));
                }
                txtBoxID.SelectAll();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ScanPackFinalBox()
        {
            try
            {
                bool flag = false;
                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (string.Equals(spdPackingLotList_Sheet1.Cells[i, 15].Text, txtFinalBoxID.Text))
                    {
                        spdPackingLotList_Sheet1.SetValue(i, 0, true);
                        flag = true;
                    }
                }
                if (!flag)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(481));
                }
                txtFinalBoxID.SelectAll();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool RegistShippingLot()
        {
            TRSNode tRSNode = new TRSNode("regist_shipping_Lot_In");
            TRSNode out_node = new TRSNode("regist_shipping_Lot_Out");
            Dictionary<string, double> dictionary = new Dictionary<string, double>();
            Dictionary<string, double> dictionary2 = new Dictionary<string, double>();
            bool flag = false;
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("SHIP_ORDER_ID", spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, 0].Text);
                tRSNode.AddInt("SHIP_SEQ", MPCF.ToInt(spdOrderDetailList.ActiveSheet.Cells[spdOrderDetailList.ActiveSheet.ActiveRowIndex, 1].Text));
                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (!(spdPackingLotList_Sheet1.Cells[i, 0].Text.ToString().ToUpper() == "TRUE") || string.Equals(spdPackingLotList_Sheet1.Cells[i, 11].Text, "Y") || MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, 12].Text) != "")
                    {
                        continue;
                    }
                    TRSNode tRSNode2 = tRSNode.AddNode("PACK_LOT_LIST");
                    tRSNode2.AddString("ORG_LOT_ID", spdPackingLotList_Sheet1.Cells[i, 1].Text);
                    tRSNode2.AddString("PACK_LOT_ID", spdPackingLotList_Sheet1.Cells[i, 2].Text);
                    flag = true;
                    if (MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, 14].Text) != "")
                    {
                        if (dictionary.ContainsKey(spdPackingLotList_Sheet1.Cells[i, 14].Text))
                        {
                            dictionary[spdPackingLotList_Sheet1.Cells[i, 14].Text] += 1.0;
                        }
                        else
                        {
                            dictionary.Add(spdPackingLotList_Sheet1.Cells[i, 14].Text, 1.0);
                        }
                    }
                    if (MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, 15].Text) != "")
                    {
                        if (dictionary2.ContainsKey(spdPackingLotList_Sheet1.Cells[i, 15].Text))
                        {
                            dictionary2[spdPackingLotList_Sheet1.Cells[i, 15].Text] += 1.0;
                        }
                        else
                        {
                            dictionary2.Add(spdPackingLotList_Sheet1.Cells[i, 15].Text, 1.0);
                        }
                    }
                }
                if (dictionary.Count > 0)
                {
                    foreach (KeyValuePair<string, double> item in dictionary)
                    {
                        TRSNode tRSNode3 = tRSNode.AddNode("PACK_BOX_LIST");
                        tRSNode3.AddString("BOX_ID", item.Key);
                        tRSNode3.AddDouble("QTY", item.Value);
                    }
                }
                if (dictionary2.Count > 0)
                {
                    foreach (KeyValuePair<string, double> item2 in dictionary2)
                    {
                        TRSNode tRSNode4 = tRSNode.AddNode("PACK_FINAL_BOX_LIST");
                        tRSNode4.AddString("FINAL_BOX_ID", item2.Key);
                        tRSNode4.AddDouble("QTY", item2.Value);
                    }
                }
                if (!flag)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }
                if (!MPCR.CallService("CUS_SHP", "CUS_SHP_Ship_Lot", tRSNode, ref out_node))
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool CancelRegistShippingLot()
        {
            TRSNode tRSNode = new TRSNode("cancel_shipping_Lot_In");
            TRSNode out_node = new TRSNode("cancel_shipping_Lot_Out");
            Dictionary<string, double> dictionary = new Dictionary<string, double>();
            Dictionary<string, double> dictionary2 = new Dictionary<string, double>();
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '2';
                tRSNode.AddString("SHIP_ORDER_ID", spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, 0].Text);
                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (!(spdPackingLotList_Sheet1.Cells[i, 0].Text.ToString().ToUpper() == "TRUE") || string.Equals(spdPackingLotList_Sheet1.Cells[i, 11].Text, "Y") || MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, 12].Text) == "")
                    {
                        continue;
                    }
                    TRSNode tRSNode2 = tRSNode.AddNode("PACK_LOT_LIST");
                    tRSNode2.AddString("ORG_LOT_ID", spdPackingLotList_Sheet1.Cells[i, 1].Text);
                    tRSNode2.AddString("PACK_LOT_ID", spdPackingLotList_Sheet1.Cells[i, 2].Text);
                    if (MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, 14].Text) != "")
                    {
                        if (dictionary.ContainsKey(spdPackingLotList_Sheet1.Cells[i, 14].Text))
                        {
                            dictionary[spdPackingLotList_Sheet1.Cells[i, 14].Text] += 1.0;
                        }
                        else
                        {
                            dictionary.Add(spdPackingLotList_Sheet1.Cells[i, 14].Text, 1.0);
                        }
                    }
                    if (MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, 15].Text) != "")
                    {
                        if (dictionary2.ContainsKey(spdPackingLotList_Sheet1.Cells[i, 15].Text))
                        {
                            dictionary2[spdPackingLotList_Sheet1.Cells[i, 15].Text] += 1.0;
                        }
                        else
                        {
                            dictionary2.Add(spdPackingLotList_Sheet1.Cells[i, 15].Text, 1.0);
                        }
                    }
                }
                if (dictionary.Count > 0)
                {
                    foreach (KeyValuePair<string, double> item in dictionary)
                    {
                        TRSNode tRSNode3 = tRSNode.AddNode("PACK_BOX_LIST");
                        tRSNode3.AddString("BOX_ID", item.Key);
                        tRSNode3.AddDouble("QTY", item.Value);
                    }
                }
                if (dictionary2.Count > 0)
                {
                    foreach (KeyValuePair<string, double> item2 in dictionary2)
                    {
                        TRSNode tRSNode4 = tRSNode.AddNode("PACK_FINAL_BOX_LIST");
                        tRSNode4.AddString("FINAL_BOX_ID", item2.Key);
                        tRSNode4.AddDouble("QTY", item2.Value);
                    }
                }
                if (!MPCR.CallService("CUS_SHP", "CUS_SHP_Ship_Lot", tRSNode, ref out_node))
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);
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
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }
                switch (sType)
                {
                    case "REGIST":
                        {
                            if (spdOrderList.ActiveSheet.RowCount == 0)
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(109));
                                return false;
                            }
                            if (spdPackingLotList_Sheet1.RowCount == 0)
                            {
                                return false;
                            }
                            if (!(cdvDept.Text == "HM"))
                            {
                                break;
                            }
                            for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                            {
                                if (spdPackingLotList_Sheet1.Cells[i, 16].Text == "")
                                {
                                    if (MPCF.ShowMsgBox(MPCF.GetMessage(551), MessageBoxButtons.YesNo, 2) == DialogResult.No)
                                    {
                                        return false;
                                    }
                                    return true;
                                }
                            }
                            break;
                        }
                    case "INPUT_LOT":
                        if (MPCF.Trim(txtPackingLotID.Text) == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblPackLotID.Text + "]");
                            txtPackingLotID.Focus();
                            return false;
                        }
                        break;
                    case "INPUT_BOX":
                        if (MPCF.Trim(txtBoxID.Text) == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblBoxID.Text + "]");
                            txtBoxID.Focus();
                            return false;
                        }
                        break;
                    case "INPUT_FINAL_BOX":
                        if (MPCF.Trim(txtFinalBoxID.Text) == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblFinalBoxID.Text + "]");
                            txtFinalBoxID.Focus();
                            return false;
                        }
                        break;
                    case "PRINT":
                        if (MPCF.Trim(cdvLabelSize.Text) == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLableSize.Text + "]");
                            cdvLabelSize.Focus();
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
                        MPCF.ClearList(spdOrderDetailList);
                        MPCF.ClearList(spdPackingLotList);
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, 0].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, 3].Value = 0;
                        txtPackingLotID.Text = "";
                        txtBoxID.Text = "";
                        txtFinalBoxID.Text = "";
                        break;
                    case "ALL":
                        MPCF.ClearList(spdOrderList);
                        MPCF.ClearList(spdOrderDetailList);
                        MPCF.ClearList(spdPackingLotList);
                        dtpToWorkDate.Value = DateTime.Now;
                        dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7.0);
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, 0].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, 3].Value = 0;
                        cdvDept.Text = "";
                        cdvShipOper.Text = "";
                        txtShippingOrderNo.Text = "";
                        txtPackingLotID.Text = "";
                        txtBoxID.Text = "";
                        txtFinalBoxID.Text = "";
                        cdvRegistFlag.Text = "";
                        break;
                    case "ORDER_CLICK_CELL":
                        MPCF.ClearList(spdOrderDetailList);
                        MPCF.ClearList(spdPackingLotList);
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, 0].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, 3].Value = 0;
                        txtPackingLotID.Text = "";
                        txtBoxID.Text = "";
                        txtFinalBoxID.Text = "";
                        break;
                    case "DTL_ORDER_CLICK_CELL":
                        MPCF.ClearList(spdPackingLotList);
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, 0].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, 3].Value = 0;
                        txtPackingLotID.Text = "";
                        txtBoxID.Text = "";
                        txtFinalBoxID.Text = "";
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        public bool ViewPrintLabel(string sFileName)
        {
            try
            {
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool ViewShipDetail(int iRow, int iCol, int iRowD)
        {
            try
            {
                if (iRow < 0)
                {
                    return false;
                }
                for (int i = 0; i < spdOrderList.ActiveSheet.RowCount; i++)
                {
                    spdOrderList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }
                spdOrderList.ActiveSheet.Rows[iRow].BackColor = Color.FromArgb(255, 192, 255);
                shipOrderId = spdOrderList.ActiveSheet.Cells[iRow, 0].Text;
                ViewShippingOrderDetailList(shipOrderId);
                if (string.Equals(cdvDept.Text, "HM"))
                {
                    ViewPackingLotListForHM(shipOrderId);
                }
                else
                {
                    ViewPackingLotList(shipOrderId, seq);
                }
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void frmTranRegistShippingLot_Load(object sender, EventArgs e)
        {
            try
            {
                lblBoxID.Visible = false;
                txtBoxID.Visible = false;
                lblFinalBoxID.Visible = false;
                txtFinalBoxID.Visible = false;
                dtpToWorkDate.Value = DateTime.Now;
                dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7.0);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtShippingOrderNo_KeyPress(object sender, KeyPressEventArgs e)
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

        private void cdvDept_SelectedItemChanged(object sender, MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (string.Equals(cdvDept.Text, "HM"))
                {
                    lblBoxID.Visible = true;
                    txtBoxID.Visible = true;
                    lblFinalBoxID.Visible = true;
                    txtFinalBoxID.Visible = true;
                }
                else
                {
                    lblBoxID.Visible = false;
                    txtBoxID.Visible = false;
                    lblFinalBoxID.Visible = false;
                    txtFinalBoxID.Visible = false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvShipOper_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }
                cdvShipOper.Init();
                MPCF.InitListView(cdvShipOper.GetListView);
                cdvShipOper.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvShipOper.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvShipOper.SelectedSubItemIndex = 0;
                cdvShipOper.DisplaySubItemIndex = 1;
                if (COM_LIST.ViewOperationList(cdvShipOper.GetListView, '5', cdvDept.Text, "", "", "", 'Y', "", ' ', 'Y'))
                {
                    cdvShipOper.InsertEmptyRow(0, 1);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtPackingLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == '\r' && CheckCondition("INPUT_LOT"))
                {
                    ScanPackLot();
                    CheckCount();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtBoxID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == '\r' && CheckCondition("INPUT_BOX"))
                {
                    ScanPackBox();
                    CheckCount();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtFinalBoxID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == '\r' && CheckCondition("INPUT_FINAL_BOX"))
                {
                    ScanPackFinalBox();
                    CheckCount();
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
                    ViewShippingOrderList();
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
                if (!CheckCondition("REGIST") || !RegistShippingLot())
                {
                    return;
                }
                btnView_Click(null, null);
                if (b_refresh_flag)
                {
                    ViewShippingOrderDetailList(shipOrderId);
                    if (string.Equals(cdvDept.Text, "HM"))
                    {
                        ViewPackingLotListForHM(shipOrderId);
                    }
                    else if (shipOrderId != "" && seq != "")
                    {
                        ViewPackingLotList(shipOrderId, seq);
                    }
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
                if (CheckCondition("REGIST") && CancelRegistShippingLot())
                {
                    btnView_Click(null, null);
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
                if (!e.ColumnHeader)
                {
                    for (int i = 0; i < spdOrderList.ActiveSheet.RowCount; i++)
                    {
                        spdOrderList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                    }
                    spdOrderList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);
                    shipOrderId = spdOrderList.ActiveSheet.Cells[e.Row, 0].Text;
                    ViewShippingOrderDetailList(shipOrderId);
                    if (string.Equals(cdvDept.Text, "HM"))
                    {
                        ViewPackingLotListForHM(shipOrderId);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdOrderDetailList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.Row >= 0 && !e.ColumnHeader)
                {
                    for (int i = 0; i < spdOrderDetailList.ActiveSheet.RowCount; i++)
                    {
                        spdOrderDetailList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                    }
                    spdOrderDetailList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);
                    if (!string.Equals(cdvDept.Text, "HM"))
                    {
                        ClearList("DTL_ORDER_CLICK_CELL");
                        seq = spdOrderDetailList.ActiveSheet.Cells[e.Row, 1].Text;
                        ViewPackingLotList(shipOrderId, seq);
                    }
                }
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
                fnPrintShipReportHM("CQCM2006-005", "pip520pa");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void fnPrintShipReportHM(string sViewID, string sFileName)
        {
            try
            {
                string text = "";
                if (spdOrderDetailList.ActiveSheet.RowCount == 0)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return;
                }
                if (spdPackingLotList.ActiveSheet.RowCount > 0)
                {
                    for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                    {
                        text = text + ",'" + spdPackingLotList_Sheet1.Cells[i, 2].Value.ToString() + "'";
                    }
                }
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "SHIP_ORDER_ID";
                array[1].sCondition_Value = spdOrderDetailList_Sheet1.Cells[spdOrderDetailList.ActiveSheet.ActiveRowIndex, 0].Value;
                array[2].sCondition_ID = "SHIP_ORDR_SEQ";
                array[2].sCondition_Value = spdOrderDetailList_Sheet1.Cells[spdOrderDetailList.ActiveSheet.ActiveRowIndex, 1].Value;
                array[3].sCondition_ID = "SQL_TEXT";
                array[3].sCondition_Type = "TEXT";
                if (text == "")
                {
                    array[3].sCondition_Value = "AND 1=1";
                }
                else
                {
                    array[3].sCondition_Value = "AND  A.PACK_LOT_ID IN ('Z'" + text + ")";
                }
                if (!TPDR.GetDataOne("", ref dt, sViewID, array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    return;
                }
                
                string sATTRIBUTE02 = dt.Rows[0]["ATTRIBUTE02"].ToString();

                dt.Columns.Add("IMAGE_A", typeof(byte[]));
                dt.Columns.Add("IMAGE_B", typeof(byte[]));
                num = dt.Rows.Count;
                for (int j = 0; j < num; j++)
                {
                    string sCondition_Value = dt.Rows[j]["REPORT_NO"].ToString();
                    string sCondition_Value2 = dt.Rows[j]["IMAGE_LOT_ID"].ToString();
                    TPDR.DirectViewCond[] array2 = new TPDR.DirectViewCond[3];
                    DataTable dt2 = null;
                    array2[0].sCondition_ID = "FACTORY";
                    array2[0].sCondition_Value = MPGV.gsFactory;
                    array2[1].sCondition_ID = "REPORT_NO";
                    array2[1].sCondition_Value = sCondition_Value;
                    array2[2].sCondition_ID = "LOT_ID";
                    array2[2].sCondition_Value = sCondition_Value2;
                    if (!TPDR.GetDataOne("", ref dt2, "CQCM2101-010", array2, bIcon: false, bBGColor: false, ref sSql))
                    {
                        dt2?.Dispose();
                        GC.Collect();
                        return;
                    }
                    dt.Rows[j]["IMAGE_A"] = dt2.Rows[0]["IMAGE_A"];
                    dt.Rows[j]["IMAGE_B"] = dt2.Rows[0]["IMAGE_B"];
                }

                if (sATTRIBUTE02 != null && sATTRIBUTE02 == "HM_03")
                {
                    DevReport.PreviewXtraReport(dt, "pip520pc"); // SPEC 성적서
                }
                else
                {
                    DevReport.PreviewXtraReport(dt, sFileName);  //일반성적서 pip510p
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
                cdvLabelSize.DisplaySubItemIndex = 0;
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
                if (e.Column == 18 && MPCF.ShowMsgBox(MPCF.GetMessage(577), MessageBoxButtons.YesNo, 2) == DialogResult.Yes && LotSpleteProcess())
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(562));
                }
                if (e.Column == 0)
                {
                    CheckCount();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool LotSpleteProcess()
        {
            try
            {
                TRSNode tRSNode = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("LOT_ID", spdPackingLotList_Sheet1.Cells[spdPackingLotList_Sheet1.ActiveRowIndex, 2].Text);
                TRSNode tRSNode2 = tRSNode.AddNode("LOT_TBL");
                tRSNode2.AddString("LOT_ID", "");
                tRSNode2.AddDouble("QTY_1", MPCF.ToDbl(spdPackingLotList_Sheet1.Cells[spdPackingLotList_Sheet1.ActiveRowIndex, 17].Text));
                tRSNode2.AddChar("SHIP_SPLITE_FLAG", "Y");
                if (!MPCR.CallService("CUS_WIP", "CUS_WIP_Split_Wip_Lot", tRSNode, ref out_node))
                {
                    return false;
                }
                ViewPackingLotList(spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, 0].Text, seq);
                MPCR.ShowSuccessMsg(out_node);
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
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

        private void cdvRegistFlag_ButtonPress(object sender, EventArgs e)
        {
            cdvRegistFlag.Init();
            MPCF.InitListView(cdvRegistFlag.GetListView);
            cdvRegistFlag.Columns.Add("Flag", 30, System.Windows.Forms.HorizontalAlignment.Left);
            ListViewItem listViewItem = new ListViewItem("Y", 14);
            listViewItem.SubItems.Add("Y");
            cdvRegistFlag.Items.Add(listViewItem);
            cdvRegistFlag.InsertEmptyRow(0, 1);
        }

    }
}
