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

namespace CUS_QCM
{
    public partial class frmViewPackingOrderListByShipReport : CUS_COM.frmViewForm01
    {
        public frmViewPackingOrderListByShipReport()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "
        private enum PACK_ITEM
        {
            CHK,                    // 1 : CHK
            ITEM,                   // 2 : 항목
            ITEM_DESC               // 3 : 항목명
        }

        private enum PACK_ORDER
        {
            PACK_ORDER_ID,         // 1 : 포장 지시 번호
            LINE_NO,               // 2 : 포장 라인 번호
            LOT_ID,                 // 3. LOT_ID (GRT의 경우 검사LOT_ID , 다른사업부는 포장LOT_ID)
            INCLUDE_INSPECTION,    // 4 : 검사 성적서 포함 여부
            REPORT_NO,                  // 5 : 성적서 번호
            PACK_ORD_STATUS,       // 6 : 주문지시 상태
            MAT_ID,                // 7 : 제품
            MAT_DESC,              // 8 : 제품명
            LABEL_NAME,            // 9 : 라벨품명
            CUSTOMER_NAME,         // 10 : 고객사명
            DELIVERY_NAME,         // 11 : 최종 납품처명
        }

        #endregion

        #region " Variable Definition "
        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnExcel.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //벨리데이션 체크
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        if (MPCF.Trim(cdvDept.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
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
        // 주문 지시 정보 조회
        private void ViewOrderList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[11];
                DataTable dt = null;
                string sSql = "";
                string sViewID = "";
                List<string> ItemList1 = new List<string>();
                List<string> ItemList2 = new List<string>();              

                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;
                
                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = cdvMatId.Text;

                dvcArgu[3].sCondition_ID = "CUSTOMER_ID";
                dvcArgu[3].sCondition_Value = cdvCustomerId.Text;

                dvcArgu[4].sCondition_ID = "PACK_ORDER_ID";
                dvcArgu[4].sCondition_Value = txtPackingOrderNo.Text;

                dvcArgu[5].sCondition_ID = "PACK_ORD_STATUS";
                dvcArgu[5].sCondition_Value = cdvOrderStatus.Text;

                dvcArgu[6].sCondition_ID = "FROM_DATE";
                dvcArgu[6].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", ""));

                dvcArgu[7].sCondition_ID = "TO_DATE";
                dvcArgu[7].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";

                dvcArgu[8].sCondition_ID = "MAT_DESC";
                dvcArgu[8].sCondition_Value = txtMatDesc.Text;

                dvcArgu[9].sCondition_ID = "LOT_ID";
                dvcArgu[9].sCondition_Value = txtLotID.Text;

                dvcArgu[10].sCondition_ID = "INCLUDE_INSPECTION";
                dvcArgu[10].sCondition_Value = cdvIncludeInspection.Text;


                sViewID = "CQCM3009-002";

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdOrderList);
                    return;
                }

                MPCF.ClearList(spdOrderList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdOrderList_Sheet1.RowCount++;


                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LINE_NO].Value = dt.Rows[i]["LINE_NO"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.INCLUDE_INSPECTION].Value = dt.Rows[i]["INCLUDE_INSPECTION"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.REPORT_NO].Value = dt.Rows[i]["REPORT_NO"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_ORD_STATUS].Value = dt.Rows[i]["PACK_ORD_STATUS"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CUSTOMER_NAME].Value = dt.Rows[i]["CUSTOMER_NAME"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DELIVERY_NAME].Value = dt.Rows[i]["DELIVERY_NAME"];

                }
                MPCF.FitColumnHeader(spdOrderList);

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
                    case "VIEW":

                        MPCF.ClearList(spdOrderList);                       
                        break;

                    case "ALL":

                        MPCF.ClearList(spdOrderList);
                        this.dtpToWorkDate.Value = DateTime.Now;
                        this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);

                        this.cdvDept.Text = "";
                        this.cdvMatId.Text = "";
                        this.cdvCustomerId.Text = "";
                        this.cdvOrderStatus.Text = "";
                        this.txtPackingOrderNo.Text = "";
                        this.txtMatDesc.Text = "";
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
        private void frmViewPackingOrderListByShipReport_Load(object sender, EventArgs e)
        {
            try
            {
                cdvOrderStatus.Text = CSGC.CP_PACK_STATUS_WAIT;
                cdvOrderStatus.DisplayText = CSGC.CP_PACK_STATUS_WAIT_DESC;
                dtpToWorkDate.Value = DateTime.Now;
                dtpFromWorkDate.Value = DateTime.Now;
                dtpFromWorkDate.Format = DateTimePickerFormat.Custom;
                dtpFromWorkDate.CustomFormat = " ";
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvIncludeInspection_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvIncludeInspection.Init();
                MPCF.InitListView(cdvIncludeInspection.GetListView);
                cdvIncludeInspection.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvIncludeInspection.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvIncludeInspection.SelectedSubItemIndex = 0;
                cdvIncludeInspection.DisplaySubItemIndex = 0;

                if (BASLIST.ViewGCMDataList(cdvIncludeInspection.GetListView, '1', "YESNO") == false)
                {
                    return;
                }

                cdvIncludeInspection.InsertEmptyRow(0, 1);
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
                cdvMatId.Text = "";

                MPCF.ClearList(spdOrderList);

               // ViewItemList(cdvDept.Text);
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

                ClearList("VIEW");
                ViewOrderList();
            }
            catch(Exception ex)
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

        private void cdvCustomerId_ButtonPress(object sender, EventArgs e)
        {
            //고객사 팝업으로 변경
            try
            {
                frmPopCustomerList popup = new frmPopCustomerList();
                popup.StartPosition = FormStartPosition.CenterParent;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvCustomerId.Text = popup.g_CustomerId;
                    this.cdvCustomerId.DisplayText = popup.g_CustomerDesc;
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

        private void spdOrderList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                {
                    if (spdOrderList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdOrderList, e.Row, e.Column, true, true, false);
                    }
                }
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdOrderList, e.Row);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }
        
        private void cdvOrderStatus_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvOrderStatus.Init();
                MPCF.InitListView(cdvOrderStatus.GetListView);
                cdvOrderStatus.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvOrderStatus.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOrderStatus.SelectedSubItemIndex = 0;
                cdvOrderStatus.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvOrderStatus.GetListView, '1', CSGC.CP_GCM_SHIP_STATUS) == false)
                {
                    return;
                }

                cdvOrderStatus.InsertEmptyRow(0, 1);
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
                EXTFUC.SaveExcel(spdOrderList, "PackOrderList");
                
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvMatId_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatId.DisplayText == "")
                cdvMatId.Text = "";
        }
        private void cdvCustomerId_TextBoxTextChanged(object sender, EventArgs e)
        {

            if (cdvCustomerId.DisplayText == "")
                cdvCustomerId.Text = "";
        }
        private void cdvOrderStatus_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvOrderStatus.DisplayText == "")
                cdvOrderStatus.Text = "";
        }   

        private void txtMatDesc_KeyPress(object sender, KeyPressEventArgs e)
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

        private void txtPackingOrderNo_KeyPress(object sender, KeyPressEventArgs e)
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

        #endregion


    }
}
