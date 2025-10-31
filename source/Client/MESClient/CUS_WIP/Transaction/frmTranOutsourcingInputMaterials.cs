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
    public partial class frmTranOutsourcingInputMaterials : CUS_COM.frmTranForm01
    {
        public frmTranOutsourcingInputMaterials()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum WORKORDER
        {
            ORDER_ID,               // 1 : 작업지시번호
            PO_NO,                  // 2 : po 번호
            START_DATE,             // 3 : 시작일
            END_DATE,               // 4 : 완료일
            MAT_ID,                 // 5 : 제품코드
            MAT_DESC,               // 6 : 제품명
            UNIT,                   // 7 : 단위
            ORDER_QTY,              // 8 : 지시수량
            PROD_QTY,               // 9 : 생산수량
            STOCK,                  //10 : 창고
            STOCK_DESC              //11 : 창고명
        }

        private enum BOM
        {
            MAT_ID,                 // 1 : 자재코드
            MAT_DESC,               // 2 : 자재명
            UNIT_QTY,               // 3 : 단위소요량
            TOTAL_QTY,              // 4 : 총소요량
            UNIT,                   // 5 : 단위
            TO_STOCK                // 6 : 출고창고
        }

        private enum STOCK
        {
            CHK,                    // 1 : 공정명
            LOT_ID,                 // 2 : LOT ID
            MAT_ID,                 // 3 : 자재코드
            MAT_DESC,               // 4 : 자재명
            QTY,                    // 5 : 총소요량
            UNIT,                   // 6 : 단위
            LOT_TYPE                // 7 : LOT 타입
        }

        private enum INPUT
        {
            CHK,                    // 1 : 공정명
            LOT_ID,                 // 2 : LOT ID
            MAT_ID,                 // 3 : 자재코드
            MAT_DESC,               // 4 : 자재명
            QTY,                    // 5 : 총소요량
            UNIT,                   // 6 : 단위
            LOT_TYPE,               // 7 : LOT 타입
            OUT_OPER,               // 8 : 출고 공정
            INPUT_QTY,              // 7 : 투입 수량
            UNIT_QTY               // 8 : 단위 수량
        }

        #endregion

        #region " Variable Definition "

        public string sArea_id = "";
        public string sArea_desc = "";
        public string sSub_area_id = "";
        public string sSub_area_desc = "";
        public string sOper_id = "";
        public string sOper_desc = "";
        public string sOrder_id = "";
        public string sVendor_id = "";
        public string sVendor_desc = "";
        public string sPo_id = "";

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewOrder()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "ORDER_ID";
                dvcArgu[1].sCondition_Value = cdvOrder.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2008-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdWorkOrder_Sheet1.RowCount++;

                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.PO_NO].Value = dt.Rows[i]["PO_NO"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.START_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["START_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.END_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["END_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.UNIT].Value = dt.Rows[i]["UNIT_1"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.ORDER_QTY].Value = dt.Rows[i]["ORDER_QTY"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.PROD_QTY].Value = dt.Rows[i]["PROD_QTY"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.STOCK].Value = dt.Rows[i]["STOCK"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.STOCK_DESC].Value = dt.Rows[i]["STOCK_DESC"];
                }

                MPCF.FitColumnHeader(spdWorkOrder);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewBom(string sOrder_id)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "ORDER_ID";
                dvcArgu[1].sCondition_Value = sOrder_id;

                if (TPDR.GetDataOne("", ref dt, "CWIP2008-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdBom);
                    return;
                }

                MPCF.ClearList(spdBom);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdBom_Sheet1.RowCount++;

                    spdBom_Sheet1.Cells[i, (int)BOM.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdBom_Sheet1.Cells[i, (int)BOM.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdBom_Sheet1.Cells[i, (int)BOM.UNIT_QTY].Value = dt.Rows[i]["UNIT_QTY"];
                    spdBom_Sheet1.Cells[i, (int)BOM.TOTAL_QTY].Value = dt.Rows[i]["TOTAL_QTY"];
                    spdBom_Sheet1.Cells[i, (int)BOM.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdBom_Sheet1.Cells[i, (int)BOM.TO_STOCK].Value = dt.Rows[i]["OUT_OPER_DESC"];
                }
                MPCF.FitColumnHeader(spdBom);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewMatList()
        {
            string sSql = "";
            int i = 0;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvWarehouse.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2008-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdMatList);
                    return;
                }

                MPCF.ClearList(spdMatList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdMatList_Sheet1.RowCount++;

                    spdMatList_Sheet1.SetValue(i, (int)STOCK.CHK, false);
                    spdMatList_Sheet1.Cells[i, (int)STOCK.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.QTY].Value = dt.Rows[i]["QTY"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];
                }

                MPCF.FitColumnHeader(spdMatList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewInputList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                dvcArgu[2].sCondition_ID = "ORDER_ID";
                dvcArgu[2].sCondition_Value = cdvOrder.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2008-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdInputList);
                    return;
                }

                MPCF.ClearList(spdInputList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdInputList_Sheet1.RowCount++;

                    spdInputList_Sheet1.SetValue(i, (int)INPUT.CHK, false);
                    spdInputList_Sheet1.Cells[i, (int)INPUT.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.QTY].Value = dt.Rows[i]["QTY"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.OUT_OPER].Value = dt.Rows[i]["OUT_OPER"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.INPUT_QTY].Value = dt.Rows[i]["INPUT_QTY"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.UNIT_QTY].Value = dt.Rows[i]["UNIT_QTY"];
                }

                MPCF.FitColumnHeader(spdInputList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewLotInfo()
        {
            int iRow = 0;
            string sLotId = "";
            double dUnitQty = 0;
            string sMatTmp = "";

            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '2';
                in_node.AddString("LOT_ID", txtLotID.Text);
                in_node.AddString("OPER", cdvWarehouse.Text);
                //in_node.AddString("OPER", "OG01900");

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_View_Lot_Info", in_node, ref out_node) == false)
                {
                    return;
                }
                for (int i = 0; i < out_node.GetList("LOT_TBL").Count; i++)
                {
                    //lot 정보가 이미 있는경우 넘어간다.
                    sLotId = out_node.GetList("LOT_TBL")[i].GetString("LOT_ID");
                    sMatTmp = out_node.GetList("LOT_TBL")[i].GetString("MAT_ID");

                    for (int k = 0; k < spdInputList.ActiveSheet.RowCount; k++)
                    {
                        if (sLotId == spdInputList.ActiveSheet.Cells[k, (int)INPUT.LOT_ID].Text)
                        {
                            continue;
                        }
                    }

                    for (int j = spdMatList.ActiveSheet.RowCount; j > 0; j--)
                    {
                        if (spdMatList.ActiveSheet.Cells[j - 1, (int)STOCK.LOT_ID].Text == sLotId)
                        {
                            spdMatList.ActiveSheet.RemoveRows(j - 1, 1);
                        }
                    }

                    for (int j = 0; j < spdBom.ActiveSheet.RowCount; j++)
                    {
                        if (spdBom.ActiveSheet.Cells[j, (int)BOM.MAT_ID].Text == sMatTmp)
                        {
                            dUnitQty = MPCF.ToDbl(spdBom.ActiveSheet.Cells[j, (int)BOM.UNIT_QTY].Text);
                        }
                    }

                    iRow = spdInputList.ActiveSheet.RowCount;

                    spdInputList.ActiveSheet.RowCount++;
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.CHK, true);
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.LOT_ID, out_node.GetList("LOT_TBL")[i].GetString("LOT_ID"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.MAT_ID, out_node.GetList("LOT_TBL")[i].GetString("MAT_ID"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.MAT_DESC, out_node.GetList("LOT_TBL")[i].GetString("MAT_DESC"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.UNIT, out_node.GetList("LOT_TBL")[i].GetString("UNIT_1"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.LOT_TYPE, out_node.GetList("LOT_TBL")[i].GetString("LOT_TYPE"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.OUT_OPER, out_node.GetList("LOT_TBL")[i].GetString("OPER"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.INPUT_QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.UNIT_QTY, dUnitQty);
                }

                txtLotID.Text = "";

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private bool InputMat()
        {
            TRSNode in_node = new TRSNode("input_In");
            TRSNode out_node = new TRSNode("input_Out");
            TRSNode input_list;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
                in_node.AddString("OPER", cdvOper.Text);
                //in_node.AddString("OUT_OPER", cdvWarehouse.Text);
                in_node.AddString("ORDER_ID", cdvOrder.Text);
                in_node.AddChar("REL_LEVEL", '2');

                for (int i = 0; i < spdInputList.ActiveSheet.RowCount; i++)
                {
                    input_list = in_node.AddNode("LIST_TBL");
                    input_list.AddString("LOT_ID", spdInputList.ActiveSheet.Cells[i, (int)INPUT.LOT_ID].Text);
                    input_list.AddString("MAT_ID", spdInputList.ActiveSheet.Cells[i, (int)INPUT.MAT_ID].Text);
                    //input_list.AddDouble("QTY", spdInputList.ActiveSheet.Cells[i, (int)INPUT.QTY].Text);
                    input_list.AddString("LOT_TYPE", spdInputList.ActiveSheet.Cells[i, (int)INPUT.LOT_TYPE].Text);
                    input_list.AddString("INPUT_TYPE", CSGC.CP_MAT_INPUT_TYPE_BOM);
                    input_list.AddString("OUT_OPER", spdInputList.ActiveSheet.Cells[i, (int)INPUT.OUT_OPER].Text);
                    input_list.AddDouble("QTY", MPCF.ToDbl(spdInputList.ActiveSheet.Cells[i, (int)INPUT.INPUT_QTY].Text));
                    input_list.AddDouble("BOM_QTY", MPCF.ToDbl(spdInputList.ActiveSheet.Cells[i, (int)INPUT.UNIT_QTY].Text));
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Input_Material_Lot", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvOrder.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOrder.Text + "]");
                    cdvOrder.Focus();
                    return false;
                }

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

                        break;

                    case CSGC.CHECK.SAVE:


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

        #endregion

        #region " Event Definition "

        private void frmTranOutsourcingInputMaterials_Load(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Text = sArea_id;
                cdvDept.DisplayText = sArea_desc;
                cdvWorkPlace.Text = sSub_area_id;
                cdvWorkPlace.DisplayText = sSub_area_desc;
                cdvOper.Text = sOper_id;
                cdvOper.DisplayText = sOper_desc;
                cdvOrder.Text = sOrder_id;
                cdvVendor.Text = sVendor_id;
                cdvVendor.DisplayText = sVendor_desc;
                txtPo.Text = sPo_id;

                if (MPCF.Trim(cdvOrder.Text) != "")
                {
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOrder_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return;
                }

                cdvOrder.Init();
                MPCF.InitListView(cdvOrder.GetListView);
                cdvOrder.Columns.Add("Order", 50, HorizontalAlignment.Left);
                cdvOrder.Columns.Add("Start_date", 50, HorizontalAlignment.Left);
                cdvOrder.Columns.Add("End_date", 50, HorizontalAlignment.Left);
                cdvOrder.SelectedSubItemIndex = 0;

                if (COM_LIST.ViewOrderList(cdvOrder.GetListView, '1', cdvDept.Text, cdvWorkPlace.Text, cdvOper.Text) == false)
                {
                    return;
                }

                cdvOrder.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvVendor_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopVendorList popup = new frmPopVendorList();
                popup.StartPosition = FormStartPosition.CenterParent;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvVendor.Text = popup.g_VendorId;
                    this.cdvVendor.DisplayText = popup.g_VendorDesc;
                    popup = null;
                }
                else
                {
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWarehouse_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }

                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return;
                }

                cdvWarehouse.Init();
                MPCF.InitListView(cdvWarehouse.GetListView);
                cdvWarehouse.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWarehouse.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWarehouse.SelectedSubItemIndex = 0;
                cdvWarehouse.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvWarehouse.GetListView, '9', cdvDept.Text, "", "", "", 'Y') == false)
                {
                    return;
                }

                cdvWarehouse.InsertEmptyRow(0, 1);
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
                if (e.KeyChar == (char)13)
                {
                    ViewLotInfo();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void spdMatList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)STOCK.CHK)
                    {
                        CSCF.CheckSpreadCell(spdMatList, 0, 0, true, true);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdInputList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)INPUT.CHK)
                    {
                        CSCF.CheckSpreadCell(spdInputList, 0, 0, true, true);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            string sTmp = "";
            int iRow = 0;
            double dUnitQty = 0;
            string sMatTmp = "";

            try
            {
                for (int i = spdMatList.ActiveSheet.RowCount; i > 0; i--)
                {
                    if (spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        sTmp = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.LOT_ID].Text;
                        sMatTmp = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.MAT_ID].Text;

                        for (int k = 0; k < spdInputList.ActiveSheet.RowCount; k++)
                        {
                            if (spdInputList.ActiveSheet.Cells[k, (int)INPUT.LOT_ID].Text == sTmp)
                                continue;
                        }

                        for (int j = 0; j < spdBom.ActiveSheet.RowCount; j++)
                        {
                            if (spdBom.ActiveSheet.Cells[j, (int)BOM.MAT_ID].Text == sMatTmp)
                            {
                                dUnitQty = MPCF.ToDbl(spdBom.ActiveSheet.Cells[j, (int)BOM.UNIT_QTY].Text);
                            }
                        }

                        iRow = spdInputList.ActiveSheet.RowCount;
                        spdInputList.ActiveSheet.RowCount++;

                        spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.CHK, true);
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.LOT_ID].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.LOT_ID].Text;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.MAT_ID].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.MAT_ID].Text;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.MAT_DESC].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.MAT_DESC].Text;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.QTY].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.QTY].Value;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.UNIT].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.UNIT].Text;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.LOT_TYPE].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.LOT_TYPE].Text;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.OUT_OPER].Value = MPCF.Trim(cdvWarehouse.Text);
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.INPUT_QTY].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.QTY].Value;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.UNIT_QTY].Value = dUnitQty;

                        spdMatList.ActiveSheet.RemoveRows(i - 1, 1);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnDel_Click(object sender, EventArgs e)
        {
            string sTmp = "";
            int iRow = 0;
            bool bCheck = false;

            try
            {
                if (MPCF.Trim(cdvWarehouse.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWarehouse.Text + "]");
                    cdvWarehouse.Focus();
                    return;
                }

                for (int i = spdInputList.ActiveSheet.RowCount; i > 0; i--)
                {
                    if (spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        sTmp = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.LOT_ID].Text;

                        for (int k = 0; k < spdMatList.ActiveSheet.RowCount; k++)
                        {
                            if (spdMatList.ActiveSheet.Cells[k, (int)STOCK.LOT_ID].Text == sTmp)
                                continue;
                        }

                        for (int j = 0; j < spdMatList.ActiveSheet.RowCount; j++)
                        {
                            if (spdMatList.ActiveSheet.Cells[j, (int)STOCK.LOT_ID].Text == sTmp)
                            {
                                bCheck = true;
                                break;
                            }
                        }

                        if (bCheck == true)
                        {
                            spdInputList.ActiveSheet.RemoveRows(i - 1, 1);
                            continue;
                        }

                        iRow = spdMatList.ActiveSheet.RowCount;
                        spdMatList.ActiveSheet.RowCount++;

                        spdMatList.ActiveSheet.SetValue(iRow, (int)STOCK.CHK, false);
                        spdMatList.ActiveSheet.Cells[iRow, (int)STOCK.LOT_ID].Value = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.LOT_ID].Text;
                        spdMatList.ActiveSheet.Cells[iRow, (int)STOCK.MAT_ID].Value = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.MAT_ID].Text;
                        spdMatList.ActiveSheet.Cells[iRow, (int)STOCK.MAT_DESC].Value = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.MAT_DESC].Text;
                        spdMatList.ActiveSheet.Cells[iRow, (int)STOCK.QTY].Value = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.QTY].Value;
                        spdMatList.ActiveSheet.Cells[iRow, (int)STOCK.UNIT].Value = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.UNIT].Text;
                        spdMatList.ActiveSheet.Cells[iRow, (int)STOCK.LOT_TYPE].Value = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.LOT_TYPE].Text;

                        spdInputList.ActiveSheet.RemoveRows(i - 1, 1);
                    }
                }

                spdMatList.ActiveSheet.SortRows((int)STOCK.LOT_ID, true, false);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnMatView_Click(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvWarehouse.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWarehouse.Text + "]");
                    cdvWarehouse.Focus();
                    return;
                }

                ViewMatList();
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
                if (CheckCondition(CSGC.CHECK.NONE) == false)
                    return;

                ViewOrder();
                ViewBom(cdvOrder.Text);

                if (MPCF.Trim(cdvWarehouse.Text) != "")
                {
                    ViewMatList();
                }
                else
                {
                    MPCF.ClearList(spdMatList);
                }

                ViewInputList();
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
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (InputMat())
                {
                    btnMatView.PerformClick();
                    ViewInputList();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        #endregion


    }
}
