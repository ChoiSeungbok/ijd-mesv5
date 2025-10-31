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

namespace CUS_INV
{
    public partial class frmViewStoreInvLotList : CUS_COM.frmViewForm01
    {
        public frmViewStoreInvLotList()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT
        {
            CHK,                // 1 : CHK
            ERROR_MEG,
            INV_LOT_ID,         // 2 : 자재 LOT ID
            INV_LOT_TYPE,       // 3 : 자재 LOT 타입
            MAT_ID,             // 4 : 제품
            MAT_VER,            // 5 : 버전
            MAT_DESC,           // 6 : 제품명
            QTY,                // 7 : 수량
            UNIT,               // 8 : 단위
            ORDER_ID,           // 9 : 작업 지시 번호
            VENDOR_ID,          // 10 : 업체
            VENDOR_SITE_ID,     // 11 : 업체 SITE ID
            VENDOR_DESC,        // 12 : 업체명
            VENDOR_LOT_ID,      // 13 : 업체 LOT ID
            AREA_ID,            // 14 : 사업부
            SUB_AREA_ID,        // 15 : 작업장
            OPER,               // 16 : 창고
            OPER_DESC,          // 17 : 창고명
            HOLD_FLAG,          // 18 : 잠금여부
            INV_CMF_1,          // 19 : 금형 모델
            INV_CMF_2,          // 20 : 금형 구분
            INV_CMF_4,          // 21 : KITTING ID
            DLV_LOT_ID,         // 22 : 입하 LOT ID
            DLV_NO,             // 23 : 입고 번호
            DLV_SEQ,            // 24 : 입고 순번
            PO_NO,              // 25 : 구매 발주 번호
            PO_SEQ,             // 26 : 구매 발주 순번
            BL_NO,              // 27 : 통관 번호
            BL_SEQ,             // 28 : 통관 순번
            RECV_DATE           // 29 : 입고 일자
        }

        #endregion

        #region " Variable Definition "
        string consignmentYN = "";
        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnReturn.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //초기화 함수
        private void ClearList(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "ALL":

                        cdvDept.Text = "";
                        cdvMatId.Text = "";
                        cdvVendorID.Text = "";
                        txtVendorLotNo.Text = "";
                        cdvOper.Text = "";
                        txtDlvNo.Text = "";
                        this.dtpToWorkDate.Value = DateTime.Now;
                        this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);
                        //dtpFromWorkDate.Format = DateTimePickerFormat.Custom;
                        //dtpFromWorkDate.CustomFormat = " ";
                        txtInvLotID.Text = "";
                        MPCF.ClearList(spdInvLotList);
                        consignmentYN = "";
                        txtPONo.Text = "";
                        break;

                    case "VIEW":

                        MPCF.ClearList(spdInvLotList);
                        break;

                    case "CLICK_DEPT":

                        cdvMatId.Text = "";
                        cdvVendorID.Text = "";
                        cdvOper.Text = "";
                        txtVendorLotNo.Text = "";
                        txtDlvNo.Text = "";

                        MPCF.ClearList(spdInvLotList);
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //벨리데이션 체크
        private bool CheckCondition(string sType)
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

                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return false;
                }

                switch (sType)
                {
                    case "PRINT":

                        if (spdInvLotList_Sheet1.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (spdInvLotList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
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

        // 입고 자재 현황 조회
        public bool ViewInvLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[12];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text;

                dvcArgu[3].sCondition_ID = "MAT_ID";
                dvcArgu[3].sCondition_Value = cdvMatId.Text;

                dvcArgu[4].sCondition_ID = "VENDOR_ID";
                dvcArgu[4].sCondition_Value = cdvVendorID.Text;

                dvcArgu[5].sCondition_ID = "VENDOR_LOT_ID";
                dvcArgu[5].sCondition_Value = txtVendorLotNo.Text;

                dvcArgu[6].sCondition_ID = "DLV_NO";
                dvcArgu[6].sCondition_Value = txtVendorLotNo.Text;

                dvcArgu[7].sCondition_ID = "FROM_DATE";
                dvcArgu[7].sCondition_Value = string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", "");

                dvcArgu[8].sCondition_ID = "TO_DATE";
                dvcArgu[8].sCondition_Value = dtpToWorkDate.Text.Replace("-", "");

                dvcArgu[9].sCondition_ID = "INV_LOT_ID";
                dvcArgu[9].sCondition_Value = txtInvLotID.Text;

                dvcArgu[10].sCondition_ID = "CONSIGNMENT_FLAG";
                dvcArgu[10].sCondition_Value = consignmentYN;

                dvcArgu[11].sCondition_ID = "PO_NO";
                dvcArgu[11].sCondition_Value = txtPONo.Text;

                if (TPDR.GetDataOne("", ref dt, "CINV3005-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdInvLotList);
                    return false;
                }

                MPCF.ClearList(spdInvLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdInvLotList_Sheet1.RowCount++;

                    spdInvLotList_Sheet1.SetValue(i, (int)LOT.CHK, false);
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.INV_LOT_ID].Value = dt.Rows[i]["INV_LOT_ID"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.INV_LOT_TYPE].Value = dt.Rows[i]["INV_LOT_TYPE"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.VENDOR_ID].Value = dt.Rows[i]["VENDOR_ID"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.VENDOR_SITE_ID].Value = dt.Rows[i]["VENDOR_SITE_ID"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.VENDOR_DESC].Value = dt.Rows[i]["VENDOR_DESC"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.SUB_AREA_ID].Value = dt.Rows[i]["SUB_AREA_ID"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.OPER].Value = dt.Rows[i]["OPER"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.HOLD_FLAG].Value = dt.Rows[i]["HOLD_FLAG"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.INV_CMF_1].Value = dt.Rows[i]["INV_CMF_1"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.INV_CMF_2].Value = dt.Rows[i]["INV_CMF_2"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.INV_CMF_4].Value = dt.Rows[i]["INV_CMF_4"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.DLV_LOT_ID].Value = dt.Rows[i]["DLV_LOT_ID"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.DLV_NO].Value = dt.Rows[i]["DLV_NO"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.DLV_SEQ].Value = dt.Rows[i]["DLV_SEQ"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.PO_NO].Value = dt.Rows[i]["PO_NO"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.PO_SEQ].Value = dt.Rows[i]["PO_SEQ"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.BL_NO].Value = dt.Rows[i]["BL_NO"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.BL_SEQ].Value = dt.Rows[i]["BL_SEQ"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.RECV_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["RECV_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                }
                MPCF.FitColumnHeader(spdInvLotList);

                spdInvLotList_Sheet1.Columns[(int)LOT.ERROR_MEG].Visible = false;




                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void CheckOper()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2010-006", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                if (string.Equals(dt.Rows[0]["OPER_GRP_1"].ToString(), "CONSIGNMENT"))
                {
                    consignmentYN = "Y";
                }
                else
                {
                    consignmentYN = "N";
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 라벨 프린트
        public bool ViewPrintLabel()
        {
            try
            {
                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                string file_name = "mtl100p";

                MPCR.SetInMsg(in_node);

                for (int i = 0; i < spdInvLotList_Sheet1.RowCount; i++)
                {
                    if (spdInvLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        label_list = in_node.AddNode("INV_LOT_LIST");
                        label_list.AddString("INV_LOT_ID", spdInvLotList_Sheet1.Cells[i, (int)LOT.INV_LOT_ID].Text);
                        label_list.AddString("DLV_LOT_ID", spdInvLotList_Sheet1.Cells[i, (int)LOT.DLV_LOT_ID].Text);
                    }
                }

                CSCF.ViewLabelList(file_name, in_node);

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
        private void frmViewStoreInvLotList_Load(object sender, EventArgs e)
        {
            try
            {
                this.dtpToWorkDate.Value = DateTime.Now;
                this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);
                //dtpFromWorkDate.Format = DateTimePickerFormat.Custom;
                //dtpFromWorkDate.CustomFormat = " ";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void cdvDept_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Init();
                MPCF.InitListView(cdvDept.GetListView);
                cdvDept.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvDept.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvDept.SelectedSubItemIndex = 0;
                cdvDept.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvDept.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                {
                    return;
                }
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
                ClearList("CLICK_DEPT");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMatId.Text = popup.sMat_id;
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

        private void cdvVendorID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopVendorList popup = new frmPopVendorList();
                popup.StartPosition = FormStartPosition.CenterParent;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvVendorID.Text = popup.g_VendorId;
                    this.cdvVendorID.DisplayText = popup.g_VendorDesc;
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

        private void cdvOper_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;
                cdvOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvOper.GetListView, 'G', cdvDept.Text, "", "", "", 'Y') == false)
                {
                    return;
                }

                cdvOper.InsertEmptyRow(0, 1);
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
                if (CheckCondition("VIEW") == false)
                    return;

                ClearList("VIEW");

                ViewInvLotList();
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

        private void spdInvLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                {
                    if (spdInvLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdInvLotList, e.Row, e.Column, true, true, false);
                    }
                }

                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdInvLotList, e.Row);
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
                if (CheckCondition("PRINT") == false)
                    return;

                if (ViewPrintLabel())
                {
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvMatId_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatId.DisplayText == "")
                cdvMatId.Text = "";
        }

        #endregion

        private void txtDlvNo_KeyPress(object sender, KeyPressEventArgs e)
        {

            try
            {
                if (e.KeyChar == (char)13)
                {
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdInvLotList, "StoreInvLotList");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void dtpFromWorkDate_ValueChanged(object sender, EventArgs e)
        {
            dtpFromWorkDate.CustomFormat = "yyyy-MM-dd";
        }

        private void dtpFromWorkDate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Delete:
                    dtpFromWorkDate.CustomFormat = " ";
                    break;
            }
        }

        private void txtVendorLotNo_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void dtpFromWorkDate_CloseUp(object sender, EventArgs e)
        {
            dtpFromWorkDate.CustomFormat = "yyyy-MM-dd";
        }

        private void cdvOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                CheckOper();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnReturn_Click(object sender, EventArgs e)
        {
            string sErrMsg = "";
            int ErrorCount = 0;
            int SuccessCount = 0;

            if (MPCF.ShowMsgBox("It is turning around Po & Lot Qty?", MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
            {
                return;
            }
            else
            {
                for (int i = 0; i < spdInvLotList_Sheet1.RowCount; i++)
                {

                    if (spdInvLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        SaveReturnQty(spdInvLotList_Sheet1.Cells[i, (int)LOT.INV_LOT_ID].Text, ref sErrMsg);

                        if (sErrMsg != "Return Completd")
                        {
                            spdInvLotList_Sheet1.Columns[(int)LOT.ERROR_MEG].Visible = true;
                            spdInvLotList_Sheet1.Cells[i, (int)LOT.ERROR_MEG].Text = sErrMsg;
                            spdInvLotList_Sheet1.SetValue(i, (int)LOT.CHK, false);
                            ErrorCount = ErrorCount + 1;
                        }
                        else
                        {
                            spdInvLotList_Sheet1.Rows[i].Visible = false;
                            spdInvLotList_Sheet1.Cells[i, (int)LOT.ERROR_MEG].Text = sErrMsg;
                            SuccessCount = SuccessCount + 1;
                        }
                    }

                }

                if(ErrorCount != 0 || SuccessCount != 0)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(584) + "[SUCESS: " + SuccessCount.ToString() + "] [ERROR: " + ErrorCount.ToString() + "]");

       
                }




            }
        }




        private void SaveReturnQty(string sLotId, ref string sErrMsg)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";



                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "LOT_ID";
                dvcArgu[1].sCondition_Value = sLotId;




                if (TPDR.GetDataOne("", ref dt, "CINV3005-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;

                }
                else
                {
                    sErrMsg = dt.Rows[0][0].ToString();
                    return;
                }

            }
            catch (Exception ex)
            {
                sErrMsg = ex.Message;
                return;
                //  MPCF.ShowMsgBox(ex.Message);
            }
        }

    }
}
