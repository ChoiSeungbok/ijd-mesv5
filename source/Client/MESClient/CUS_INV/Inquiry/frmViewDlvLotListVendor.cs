using CUS_COM;
using FarPoint.Win.Spread;
using Miracom.CliFrx;
using Miracom.DNMCore;
using Miracom.MESCore;
using Miracom.TRSCore;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;

namespace CUS_INV
{
    public partial class frmViewDlvLotListVendor : CUS_COM.frmViewForm01
    {
        public frmViewDlvLotListVendor()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum ARRIVALLOT
        {
            DLV_LOT_ID,                // 1 : 입하 LOT ID
            DLV_TIME,                  // 2 : 입하일
            VENDOR_SITE_ID,            // 3 : 업체 SITE ID
            VENDOR_DESC,               // 4 : 업체명
            MAT_ID,                    // 5 : 제품
            MAT_VER,                   // 6 : 버전
            MAT_DESC,                  // 7 : 제품명
            QTY,                       // 8 : 수량
            UNIT,                      // 9 : 단위
            DLV_LOT_STATUS,            // 10 : 입하 LOT 상태
            VENDOR_LOT_ID,             // 11 : 업체 LOT ID
            INSP_ID,                   // 12 : 수입 검사 ID
            INSP_RESULT_FLAG,          // 13 : 수입검사 결과
            PO_NO,                     // 14 : PO 번호
            PO_SEQ,                    // 15 : PO SEQ
            VENDOR_ID,                 // 16 : 업체 ID
        }

        private enum LABEL
        {
            LABEL_ID,                // 1 : 라벨 ID
            SEQ,                     // 2 : 순번
            QTY,                     // 3 : 수량
            UNIT,                    // 4 : 단위
            MAT_ID,                  // 5 : 제품
            MAT_VER,                 // 6 : 버전
            MAT_DESC,                // 7 : 제품명
            DLV_TIME,                // 8 : 입하일
            DLV_LOT_ID               // 9 : 입하 LOT ID
        }

        #endregion

        #region " Variable Definition "
        string sArrivalLotID;
        string sVendorLotID;
        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //입하 자재 LOT LIST 조회 함수
        private void ViewArrivalLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[8];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "VENDOR_ID";
                dvcArgu[2].sCondition_Value = cdvVendorID.Text;

                dvcArgu[3].sCondition_ID = "MAT_ID";
                dvcArgu[3].sCondition_Value = cdvMatID.Text;

                dvcArgu[4].sCondition_ID = "DLV_LOT_STATUS";
                dvcArgu[4].sCondition_Value = cdvLotStatus.Text;

                dvcArgu[5].sCondition_ID = "FROM_DATE";
                dvcArgu[5].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", ""));

                dvcArgu[6].sCondition_ID = "TO_DATE";
                dvcArgu[6].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";

                dvcArgu[7].sCondition_ID = "PO_NO";
                dvcArgu[7].sCondition_Value = txtPONo.Text;

                if (TPDR.GetDataOne("", ref dt, "CINV3011-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdArrivalLotList);
                    return;
                }

                MPCF.ClearList(spdArrivalLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdArrivalLotList_Sheet1.RowCount++;

                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.DLV_LOT_ID].Value = dt.Rows[i]["DLV_LOT_ID"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.DLV_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["DLV_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.VENDOR_SITE_ID].Value = dt.Rows[i]["VENDOR_SITE_ID"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.VENDOR_DESC].Value = dt.Rows[i]["VENDOR_DESC"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.DLV_LOT_STATUS].Value = dt.Rows[i]["DLV_LOT_STATUS"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.INSP_ID].Value = dt.Rows[i]["INSP_ID"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.INSP_RESULT_FLAG].Value = dt.Rows[i]["INSP_RESULT_FLAG"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.PO_NO].Value = dt.Rows[i]["PO_NO"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.PO_SEQ].Value = dt.Rows[i]["PO_SEQ"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.VENDOR_ID].Value = dt.Rows[i]["VENDOR_ID"];
                }
                MPCF.FitColumnHeader(spdArrivalLotList);

                return;
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
                        cdvVendorID.Text = "";
                        cdvMatID.Text = "";
                        cdvLotStatus.Text = "";
                        txtPONo.Text = "";
                        this.dtpToWorkDate.Value = DateTime.Now;
                        this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);
                        dtpFromWorkDate.Format = DateTimePickerFormat.Custom;
                        dtpFromWorkDate.CustomFormat = " ";

                        MPCF.ClearList(spdArrivalLotList);
                        txtArrivalLotID.Text = "";
                        txtVendorLotID.Text = "";
                        txtChangeVendorLot.Text = "";
                        break;

                    case "VIEW":

                        MPCF.ClearList(spdArrivalLotList);
                        txtArrivalLotID.Text = "";
                        txtVendorLotID.Text = "";
                        txtChangeVendorLot.Text = "";
                        break;

                    case "CLICK_DEPT":

                        cdvVendorID.Text = "";
                        cdvMatID.Text = "";

                        MPCF.ClearList(spdArrivalLotList);
                        txtArrivalLotID.Text = "";
                        txtVendorLotID.Text = "";
                        txtChangeVendorLot.Text = "";
                        break;

                    case "ARRIVAL_LOT_CLICK_CELL":
                        txtArrivalLotID.Text = "";
                        txtVendorLotID.Text = "";
                        txtChangeVendorLot.Text = "";
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

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        
        //Vendor Lot ID 저장
        private bool SaveVendorLotID()
        {
            string ssql = "";
            string sDlvLotID = "";
            string sVendorLotID = "";
            
            try
            {
                sDlvLotID = txtArrivalLotID.Text.Trim();
                sVendorLotID = txtChangeVendorLot.Text.Trim();

                ssql = "UPDATE MINVDLVLOT SET VENDOR_LOT_ID = '" + sVendorLotID + "' WHERE FACTORY = '" + MPGV.gsFactory + "' AND DLV_LOT_ID = '" + sDlvLotID + "'";

                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                in_node.AddString("SQL", ssql);


                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
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
        #endregion

        #region " Event Definition "
        private void frmViewDlvLotList_Load(object sender, EventArgs e)
        {
            try
            {
                this.dtpToWorkDate.Value = DateTime.Now;
                this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);
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

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("VIEW") == false)
                    return;

                ClearList("VIEW");

                ViewArrivalLotList();
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

        private void cdvVendorID_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvVendorID.DisplayText == "")
                cdvVendorID.Text = "";
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                FpSpread excelSp = new FpSpread();
                spdArrivalLotList_Sheet1.SheetName = "Sheet1";
                excelSp.Sheets.Add(spdArrivalLotList_Sheet1);
                
                EXTFUC.SaveExcel(excelSp, "DlvLotList");

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

        private void dtpFromWorkDate_CloseUp(object sender, EventArgs e)
        {
            dtpFromWorkDate.CustomFormat = "yyyy-MM-dd";
        }

        private void cdvMatID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                // 제품 팝업으로 변경
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMatID.Text = popup.sMat_id;
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

        private void cdvMatID_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatID.DisplayText == "")
                cdvMatID.Text = "";
        }

        private void cdvLotStatus_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvLotStatus.Init();
                MPCF.InitListView(cdvLotStatus.GetListView);
                cdvLotStatus.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvLotStatus.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvLotStatus.SelectedSubItemIndex = 0;
                cdvLotStatus.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvLotStatus.GetListView, '1', CSGC.CP_GCM_DLV_LOT_STATUS) == false)
                {
                    return;
                }

                cdvLotStatus.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvLotStatus_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvLotStatus.DisplayText == "")
                cdvLotStatus.Text = "";
        }

        private void spdArrivalLotList_CellClick(object sender, CellClickEventArgs e)
        {
            ClearList("ARRIVAL_LOT_CLICK_CELL");

            try
            {
                SheetView svArrive = spdArrivalLotList.ActiveSheet;

                if (e.Row < 0)
                {
                    return;
                }

                if (e.ColumnHeader == true)
                {
                    return;
                }

                for (int i = 0; i < spdArrivalLotList.ActiveSheet.RowCount; i++)
                {
                    svArrive.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }
                
                svArrive.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                sArrivalLotID = svArrive.Cells[e.Row, (int)ARRIVALLOT.DLV_LOT_ID].Text;
                txtArrivalLotID.Text = sArrivalLotID;
                sVendorLotID = svArrive.Cells[e.Row, (int)ARRIVALLOT.VENDOR_LOT_ID].Text;                
                txtVendorLotID.Text = sVendorLotID;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                if (txtArrivalLotID.Text == "" || txtVendorLotID.Text == "")
                {
                    //CMN199 ERROR - 선택된 Lot이 없습니다. 먼저 Lot을 선택하여 주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(199) + " [" + lblChangeVendorLotID.Text + "]");
                    return;
                }

                if (txtChangeVendorLot.Text == "" )
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblChangeVendorLotID.Text + "]");
                    txtChangeVendorLot.Focus();
                    return;
                }

                if (SaveVendorLotID())
                {
                    btnView.PerformClick();
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
