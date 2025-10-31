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

//CWIP2034
namespace CUS_WIP
{
    public partial class frmTranOutsourcingReturn : CUS_COM.frmTranForm05
    {
        public frmTranOutsourcingReturn()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT_INFO
        {
            CHK,                    // 1 : 공정명
            LOT_ID,                 // 2 : LOT ID
            MAT_ID,                 // 3 : 자재코드
            MAT_DESC,               // 4 : 자재명
            QTY,                    // 5 : 총소요량            
            ORDER_ID, 
            PO_NO,
            OPER,
            LOT_TYPE,
            COMMENT
        }

        private enum MOVE_INFO
        {
            CHK,                    // 1 : 공정명
            LOT_ID,                 // 2 : LOT ID
            MAT_ID,                 // 3 : 자재코드
            MAT_DESC,               // 4 : 자재명
            QTY,                    // 5 : 총소요량
            ORDER_ID, 
            PO_NO, 
            OPER,
            LOT_TYPE,
            COMMENT
        }

        #endregion

        #region " Variable Definition "

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //lot 정보 조회 함수
        private void ViewLotInfo(string sLot_ID)
        {
            string sLotId = "";
            string sOper = "";
            int iRow = 0;

            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '2';
                in_node.AddString("LOT_ID", sLot_ID);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_View_Lot_Info", in_node, ref out_node) == false)
                {
                    return;
                }
                for (int i = 0; i < out_node.GetList("LOT_TBL").Count; i++)
                {
                    //lot 정보가 이미 있는경우 넘어간다.
                    sLotId = out_node.GetList("LOT_TBL")[i].GetString("LOT_ID");
                    for (int k = 0; k < spdMoveLotList.ActiveSheet.RowCount; k++)
                    {
                        if (sLotId == spdMoveLotList.ActiveSheet.Cells[k, (int)LOT_INFO.LOT_ID].Text)
                        {
                            continue;
                        }
                    }

                    sOper = out_node.GetList("LOT_TBL")[i].GetString("OPER");

                    if (cdvWarehouse.Text != sOper)
                    {
                        //CMN457 ERROR - 이 LOT은 해당 공정에 존재하지 않습니다.
                        MPCF.ShowMsgBox(MPCF.GetMessage(457) + " [ " + sOper + " ]");
                        return;
                    }

                    if (MPCF.Trim(out_node.GetList("LOT_TBL")[i].GetString("LOT_CMF_14")) != "")
                    {
                        continue;
                    }

                    iRow = spdMoveLotList.ActiveSheet.RowCount;

                    spdMoveLotList.ActiveSheet.RowCount++;
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.CHK, true);
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.LOT_ID, out_node.GetList("LOT_TBL")[i].GetString("LOT_ID"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.MAT_ID, out_node.GetList("LOT_TBL")[i].GetString("MAT_ID"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.MAT_DESC, out_node.GetList("LOT_TBL")[i].GetString("MAT_DESC"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.ORDER_ID, out_node.GetList("LOT_TBL")[i].GetString("OSP_ORDER_ID"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.PO_NO, out_node.GetList("LOT_TBL")[i].GetString("PO_NO"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.OPER, out_node.GetList("LOT_TBL")[i].GetString("OPER"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.LOT_TYPE, out_node.GetList("LOT_TBL")[i].GetString("LOT_TYPE"));
                    spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.COMMENT, out_node.GetList("LOT_TBL")[i].GetString("LAST_COMMENT"));

                    //lot list에 스캔한 lot이 존재한 경우 리스트에서 없애준다.
                    for (int k = 0; k < spdLotList.ActiveSheet.RowCount; k++)
                    {
                        if (spdLotList.ActiveSheet.Cells[k, (int)LOT_INFO.LOT_ID].Text == sLotId)
                        {
                            spdLotList.ActiveSheet.RemoveRows(k, 1);
                        }
                    }
                }

                MPCF.FitColumnHeader(spdMoveLotList);

                txtLotID.Text = "";

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void ViewLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                string sViewID = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;
                
                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvWarehouse.Text;

                dvcArgu[2].sCondition_ID = "ORDER_ID";
                dvcArgu[2].sCondition_Value = cdvOrder.Text;

                dvcArgu[3].sCondition_ID = "VENDOR_ID";
                dvcArgu[3].sCondition_Value = cdvVendor.Text;

                dvcArgu[4].sCondition_ID = "PO_NO";
                dvcArgu[4].sCondition_Value = txtPo.Text;

                sViewID = "CWIP2034-001";

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLotList);
                    return;
                }

                MPCF.ClearList(spdLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList_Sheet1.RowCount++;

                    spdLotList_Sheet1.SetValue(i, (int)LOT_INFO.CHK, false);
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.QTY].Value = dt.Rows[i]["QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.PO_NO].Value = dt.Rows[i]["PO_NO"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.COMMENT].Value = dt.Rows[i]["LAST_COMMENT"];
                }

                MPCF.FitColumnHeader(spdLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool MoveLot()
        {
            TRSNode in_node = new TRSNode("MoveLot_In");
            TRSNode out_node = new TRSNode("MoveLot_Out");
            TRSNode input_list;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '7';

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("OPER", cdvWarehouse.Text);
                in_node.AddString("TO_OPER", cdvToOper.Text);
                in_node.AddString("COMMENT", txtComment.Text);

                for (int i = 0; i < spdMoveLotList.ActiveSheet.RowCount; i++)
                {
                    input_list = in_node.AddNode("LOT_TBL");
                    input_list.AddString("LOT_ID", spdMoveLotList.ActiveSheet.Cells[i, (int)MOVE_INFO.LOT_ID].Text);
                    input_list.AddString("MAT_ID", spdMoveLotList.ActiveSheet.Cells[i, (int)MOVE_INFO.MAT_ID].Text);
                    input_list.AddDouble("QTY", MPCF.ToDbl(spdMoveLotList.ActiveSheet.Cells[i, (int)MOVE_INFO.QTY].Text));
                    input_list.AddString("OUT_OPER", spdMoveLotList.ActiveSheet.Cells[i, (int)MOVE_INFO.OPER].Text);
                    input_list.AddString("LOT_TYPE", spdMoveLotList.ActiveSheet.Cells[i, (int)MOVE_INFO.LOT_TYPE].Text);
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Outsourcing_Process", in_node, ref out_node) == false)
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
                if (MPCF.Trim(cdvWarehouse.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWarehouse.Text + "]");
                    cdvWarehouse.Focus();
                    return false;
                }

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

                        if (MPCF.Trim(cdvWarehouse.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWarehouse.Text + "]");
                            cdvWarehouse.Focus();
                            return false;
                        }

                        break;

                    case CSGC.CHECK.SAVE:

                        if (MPCF.Trim(cdvToWorkPlace.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToWorkPlace.Text + "]");
                            cdvToWorkPlace.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvToOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToOper.Text + "]");
                            cdvToOper.Focus();
                            return false;
                        }

                        if (spdMoveLotList.ActiveSheet.RowCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
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

                        break;

                    case "OPER":

                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdMoveLotList);

                        break;

                    case "SAVE":

                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdMoveLotList);

                        txtLotID.Text = "";
                        cdvToWorkPlace.Text = "";
                        cdvToOper.Text = "";

                        break;

                    case "ALL":

                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdMoveLotList);

                        cdvOrder.Text = "";
                        cdvVendor.Text = "";
                        txtPo.Text = "";
                        cdvWarehouse.Text = "";
                        cdvToWorkPlace.Text = "";
                        cdvToOper.Text = "";
                        txtLotID.Text = "";
                        txtComment.Text = "";

                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmTranOutsourcingReturn_Load(object sender, EventArgs e)
        {
            try
            {


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                ClearData("ALL");
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
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }

                CUS_COM.Popup.frmPopWorkOrderList popup = new CUS_COM.Popup.frmPopWorkOrderList();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.g_AreaCode = cdvDept.Text;
                popup.g_AreaDesc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvOrder.Text = popup.g_WorkOrder;
                    popup = null;
                }
                else
                    return;
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
                cdvWarehouse.Init();
                MPCF.InitListView(cdvWarehouse.GetListView);
                cdvWarehouse.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWarehouse.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWarehouse.SelectedSubItemIndex = 0;
                cdvWarehouse.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvWarehouse.GetListView, 'S', cdvDept.Text) == false)
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

        private void cdvWarehouse_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                ClearData("OPER");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvToWorkPlace_ButtonPress(object sender, EventArgs e)
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

                cdvToWorkPlace.Init();
                MPCF.InitListView(cdvToWorkPlace.GetListView);
                cdvToWorkPlace.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvToWorkPlace.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToWorkPlace.SelectedSubItemIndex = 0;
                cdvToWorkPlace.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList_AREA(cdvToWorkPlace.GetListView, '1', MPGC.MP_RAS_SUBAREA_CODE, -1, null, "", true, -1, -1, null, cdvDept.Text) == false)
                {
                    return;
                }

                cdvToWorkPlace.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvToWorkPlace_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
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
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }

                cdvToOper.Init();
                MPCF.InitListView(cdvToOper.GetListView);
                cdvToOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvToOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToOper.SelectedSubItemIndex = 0;
                cdvToOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvToOper.GetListView, '3', cdvDept.Text, cdvToWorkPlace.Text, "", "", 'Y') == false)
                {
                    return;
                }

                cdvToOper.InsertEmptyRow(0, 1);
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
                    if (MPCF.Trim(txtLotID.Text) == "")
                        return;

                    ViewLotInfo(txtLotID.Text);
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

            try
            {
                for (int i = spdLotList.ActiveSheet.RowCount; i > 0; i--)
                {
                    if (spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        sTmp = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.LOT_ID].Text;

                        for (int k = 0; k < spdMoveLotList.ActiveSheet.RowCount; k++)
                        {
                            if (spdMoveLotList.ActiveSheet.Cells[k, (int)MOVE_INFO.LOT_ID].Text == sTmp)
                                continue;
                        }

                        iRow = spdMoveLotList.ActiveSheet.RowCount;
                        spdMoveLotList.ActiveSheet.RowCount++;

                        spdMoveLotList.ActiveSheet.SetValue(iRow, (int)MOVE_INFO.CHK, true);
                        spdMoveLotList.ActiveSheet.Cells[iRow, (int)MOVE_INFO.LOT_ID].Value = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.LOT_ID].Text;
                        spdMoveLotList.ActiveSheet.Cells[iRow, (int)MOVE_INFO.MAT_ID].Value = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.MAT_ID].Text;
                        spdMoveLotList.ActiveSheet.Cells[iRow, (int)MOVE_INFO.MAT_DESC].Value = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.MAT_DESC].Text;
                        spdMoveLotList.ActiveSheet.Cells[iRow, (int)MOVE_INFO.QTY].Value = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.QTY].Value;
                        spdMoveLotList.ActiveSheet.Cells[iRow, (int)MOVE_INFO.ORDER_ID].Value = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.ORDER_ID].Text;
                        spdMoveLotList.ActiveSheet.Cells[iRow, (int)MOVE_INFO.PO_NO].Value = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.PO_NO].Text;
                        spdMoveLotList.ActiveSheet.Cells[iRow, (int)MOVE_INFO.OPER].Value = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.OPER].Text;
                        spdMoveLotList.ActiveSheet.Cells[iRow, (int)MOVE_INFO.LOT_TYPE].Value = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.LOT_TYPE].Text;
                        spdMoveLotList.ActiveSheet.Cells[iRow, (int)MOVE_INFO.COMMENT].Value = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.COMMENT].Text;

                        spdLotList.ActiveSheet.RemoveRows(i - 1, 1);
                    }
                }

                spdMoveLotList.ActiveSheet.SortRows((int)MOVE_INFO.LOT_ID, true, false);
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

            try
            {
                if (MPCF.Trim(cdvWarehouse.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWarehouse.Text + "]");
                    cdvWarehouse.Focus();
                    return;
                }

                for (int i = spdMoveLotList.ActiveSheet.RowCount; i > 0; i--)
                {
                    if (spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        sTmp = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.LOT_ID].Text;

                        for (int k = 0; k < spdLotList.ActiveSheet.RowCount; k++)
                        {
                            if (spdLotList.ActiveSheet.Cells[k, (int)LOT_INFO.LOT_ID].Text == sTmp)
                                continue;
                        }

                        iRow = spdLotList.ActiveSheet.RowCount;
                        spdLotList.ActiveSheet.RowCount++;

                        spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.CHK, false);
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.LOT_ID].Value = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.LOT_ID].Text;
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.MAT_ID].Value = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.MAT_ID].Text;
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.MAT_DESC].Value = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.MAT_DESC].Text;
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.QTY].Value = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.QTY].Value;
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.ORDER_ID].Value = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.ORDER_ID].Text;
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.PO_NO].Value = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.PO_NO].Text;
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.OPER].Value = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.OPER].Text;
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.LOT_TYPE].Value = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.LOT_TYPE].Text;
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.COMMENT].Value = spdMoveLotList.ActiveSheet.Cells[i - 1, (int)MOVE_INFO.COMMENT].Text;

                        spdMoveLotList.ActiveSheet.RemoveRows(i - 1, 1);
                    }
                }

                spdLotList.ActiveSheet.SortRows((int)LOT_INFO.LOT_ID, true, false);
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
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewLotList();
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
                ClearData("ALL");
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
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewLotList();
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

                if (MoveLot())
                {
                    ClearData("SAVE");

                    ViewLotList();
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
