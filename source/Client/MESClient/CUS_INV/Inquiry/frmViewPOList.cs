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

namespace CUS_INV
{
    public partial class frmViewPOList : CUS_COM.frmViewForm01
    {
        public frmViewPOList()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum PO_MST
        {
            DLV_NO,              // 1 : 입고 번호
            PO_NO,               // 2 : 구매 발주 번호
            BL_NO,               // 3 : 통관 번호
            DLV_EXP_DATE,        // 4 : 납품 예정 일자
            VENDOR_ID,           // 5 : 업체 코드
            VENDOR_SITE_ID,      // 6 : 업체 SITE ID
            VENDOR_DESC,         // 7 : 업체명
            AREA_ID,             // 8 : 사업부
            CMF_1                // 9 : 작업 지시 번호
        }

        private enum PO_DTL
        {
            DLV_NO,              // 1 : 입고 번호
            DLV_SEQ,             // 2 : 입고 순번
            PO_NO,               // 3 : 구매 발주 번호
            PO_SEQ,              // 4 : 구매 발주 순번
            BL_NO,               // 5 : 통관 번호
            BL_SEQ,              // 6 : 통관 순번
            DLV_QTY,             // 7 : 수량
            DLV_IN_QTY,          // 8 : 입하 확정 수량
            CONFIRM_QTY,         // 9 : 입고 수량
            LOSS_QTY,            // 10 : 불량 수량
            UNIT,                // 11 : 단위
            MAT_ID,              // 12 : 제품
            MAT_VER,             // 13 : 버전
            MAT_DESC,            // 14 : 제품명
            ERP_OPEN_YN          // 15 : ERP OPEN 상태
        }

        #endregion

        #region " Variable Definition "
        string s_dlv_no = "";
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

        //구매 입고 지시 조회
        private bool ViewPOList()
        {
            TRSNode in_node = new TRSNode("view_po_list_In");
            TRSNode out_node = new TRSNode("view_po_list_Out");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("VENDOR_ID", cdvVendorID.Text);
                in_node.AddString("FROM_DATE", string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", "")));
                in_node.AddString("TO_DATE", dtpToWorkDate.Text.Replace("-", "") + "235959");

                if (MPCR.CallService("CUS_INV", "CUS_INV_View_PO_List", in_node, ref out_node) == false)
                    return false;
                
                MPCF.ClearList(spdPOMasterList);
                
                for (int i = 0; i < out_node.GetList(0).Count; i++)
                {
                    spdPOMasterList_Sheet1.RowCount++;

                    spdPOMasterList_Sheet1.Cells[i, (int)PO_MST.DLV_NO].Value = out_node.GetList(0)[i].GetString("DLV_NO");
                    spdPOMasterList_Sheet1.Cells[i, (int)PO_MST.PO_NO].Value = out_node.GetList(0)[i].GetString("PO_NO");
                    spdPOMasterList_Sheet1.Cells[i, (int)PO_MST.BL_NO].Value = out_node.GetList(0)[i].GetString("BL_NO");
                    spdPOMasterList_Sheet1.Cells[i, (int)PO_MST.DLV_EXP_DATE].Value = MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("DLV_EXP_DATE"), DATE_TIME_FORMAT.DATE);
                    spdPOMasterList_Sheet1.Cells[i, (int)PO_MST.VENDOR_ID].Value = out_node.GetList(0)[i].GetString("VENDOR_ID");
                    spdPOMasterList_Sheet1.Cells[i, (int)PO_MST.VENDOR_SITE_ID].Value = out_node.GetList(0)[i].GetInt("VENDOR_SITE_ID");
                    spdPOMasterList_Sheet1.Cells[i, (int)PO_MST.VENDOR_DESC].Value = out_node.GetList(0)[i].GetString("VENDOR_DESC");
                    spdPOMasterList_Sheet1.Cells[i, (int)PO_MST.AREA_ID].Value = out_node.GetList(0)[i].GetString("AREA_ID");
                    spdPOMasterList_Sheet1.Cells[i, (int)PO_MST.CMF_1].Value = out_node.GetList(0)[i].GetString("CMF_1");   // CMF_1(작업지시번호)
                }

                MPCF.FitColumnHeader(spdPOMasterList);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //구매 입고 상세 지시 조회
        private bool ViewPODetailList(string s_dlv_no)
        {
            TRSNode in_node = new TRSNode("view_po_detail_list_In");
            TRSNode out_node = new TRSNode("view_po_detail_list_Out");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
                in_node.AddString("DLV_NO", s_dlv_no);

                if (MPCR.CallService("CUS_INV", "CUS_INV_View_PO_List", in_node, ref out_node) == false)
                    return false;

                MPCF.ClearList(spdPODetailList);

                for (int i = 0; i < out_node.GetList(0).Count; i++)
                {
                    spdPODetailList_Sheet1.RowCount++;

                    spdPODetailList_Sheet1.Cells[i, (int)PO_DTL.DLV_NO].Value = out_node.GetList(0)[i].GetString("DLV_NO");
                    spdPODetailList_Sheet1.Cells[i, (int)PO_DTL.DLV_SEQ].Value = out_node.GetList(0)[i].GetInt("DLV_SEQ");
                    spdPODetailList_Sheet1.Cells[i, (int)PO_DTL.PO_NO].Value = out_node.GetList(0)[i].GetString("PO_NO");
                    spdPODetailList_Sheet1.Cells[i, (int)PO_DTL.PO_SEQ].Value = out_node.GetList(0)[i].GetInt("PO_SEQ");
                    spdPODetailList_Sheet1.Cells[i, (int)PO_DTL.BL_NO].Value = out_node.GetList(0)[i].GetString("BL_NO");
                    spdPODetailList_Sheet1.Cells[i, (int)PO_DTL.BL_SEQ].Value = out_node.GetList(0)[i].GetInt("BL_SEQ");
                    spdPODetailList_Sheet1.Cells[i, (int)PO_DTL.DLV_QTY].Value = out_node.GetList(0)[i].GetDouble("DLV_QTY");
                    spdPODetailList_Sheet1.Cells[i, (int)PO_DTL.DLV_IN_QTY].Value = out_node.GetList(0)[i].GetDouble("DLV_IN_QTY");
                    spdPODetailList_Sheet1.Cells[i, (int)PO_DTL.CONFIRM_QTY].Value = out_node.GetList(0)[i].GetDouble("CONFIRM_QTY");
                    spdPODetailList_Sheet1.Cells[i, (int)PO_DTL.LOSS_QTY].Value = out_node.GetList(0)[i].GetDouble("LOSS_QTY");
                    spdPODetailList_Sheet1.Cells[i, (int)PO_DTL.UNIT].Value = out_node.GetList(0)[i].GetString("UNIT");
                    spdPODetailList_Sheet1.Cells[i, (int)PO_DTL.MAT_ID].Value = out_node.GetList(0)[i].GetString("MAT_ID");
                    spdPODetailList_Sheet1.Cells[i, (int)PO_DTL.MAT_VER].Value = out_node.GetList(0)[i].GetInt("MAT_VER");
                    spdPODetailList_Sheet1.Cells[i, (int)PO_DTL.MAT_DESC].Value = out_node.GetList(0)[i].GetString("MAT_DESC");
                    spdPODetailList_Sheet1.Cells[i, (int)PO_DTL.ERP_OPEN_YN].Value = out_node.GetList(0)[i].GetChar("ERP_OPEN_YN");
                }

                MPCF.FitColumnHeader(spdPODetailList);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
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
                        this.dtpToWorkDate.Value = DateTime.Now;
                        this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);
                        dtpFromWorkDate.Format = DateTimePickerFormat.Custom;
                        dtpFromWorkDate.CustomFormat = " ";

                        MPCF.ClearList(spdPOMasterList);
                        MPCF.ClearList(spdPODetailList);
                        break;

                    case "VIEW":

                        MPCF.ClearList(spdPOMasterList);
                        MPCF.ClearList(spdPODetailList);
                        break;

                    case "CLICK_DEPT":

                        cdvVendorID.Text = "";

                        MPCF.ClearList(spdPOMasterList);
                        MPCF.ClearList(spdPODetailList);
                        break;

                    case "PO_CLICK_CELL":
                        
                        MPCF.ClearList(spdPODetailList);
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
        #endregion

        #region " Event Definition "
        private void frmViewPOList_Load(object sender, EventArgs e)
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

                if (ViewPOList())
                {
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

        private void spdPOMasterList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            ClearList("PO_CLICK_CELL");

            try
            {
                if (e.Row < 0)
                {
                    return;
                }

                if (e.ColumnHeader == true)
                {
                    return;
                }
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdPOMasterList, e.Row);

                }
                //for (int i = 0; i < spdPOMasterList.ActiveSheet.RowCount; i++)
                //{
                //    spdPOMasterList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                //}

                //spdPOMasterList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                s_dlv_no = spdPOMasterList.ActiveSheet.Cells[e.Row, (int)PO_MST.DLV_NO].Text;

                // 구매 입고 상세 정보 조회
                ViewPODetailList(s_dlv_no);
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

        #endregion

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                FpSpread excelSp = new FpSpread();
                spdPOMasterList_Sheet1.SheetName = "Sheet1";
                excelSp.Sheets.Add(spdPOMasterList_Sheet1);
                spdPODetailList_Sheet1.SheetName = "Sheet2";
                excelSp.Sheets.Add(spdPODetailList_Sheet1);

                EXTFUC.SaveExcel(excelSp, "POList");

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

        private void spdPODetailList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdPODetailList, e.Row);
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
    }
}
