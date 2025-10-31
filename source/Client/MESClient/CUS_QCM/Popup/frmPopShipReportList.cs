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

namespace CUS_QCM.Popup
{
    public partial class frmPopShipReportList : CUS_COM.frmTranForm01
    {
        public frmPopShipReportList()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        public string s_report_no = "";
        public string s_area_id = "";
        public bool b_mp_yn = false;

        private enum SHIP_REPORT
        {
            SHIP_REPORT_NO,
            PACK_ORDER_ID,         // 1 : 포장 지시 번호
            CREATE_DATE,
            GRADE,                  // GRADE
            TYPES,                   // TYPES
     
        }





        #endregion

        #region " Function Definition "
        private void InitControl()
        {
            try
            {
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

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

        private void ClearList(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "VIEW":

                        MPCF.ClearList(spdShipReportList);

                        break;

                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //Packing Order LIST 조회 함수
        private void ViewPackingOrderList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                string sViewID = "";



                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "FROM_DATE";
                dvcArgu[1].sCondition_Value = dtpFromWorkDate.Text.Replace("-", "");

                dvcArgu[2].sCondition_ID = "TO_DATE";
                dvcArgu[2].sCondition_Value = dtpToWorkDate.Text.Replace("-", "");

                dvcArgu[3].sCondition_ID = "REPORT_NO";
                dvcArgu[3].sCondition_Value = txtShipReportNo.Text;

                if (cdvDept.Text == CSGV.gs_area_ctm)
                {
                    sViewID = "CQCM2100-003_P10";
                }
                else if (cdvDept.Text == CSGV.gs_area_hm)
                {
                    sViewID = "CQCM2100-003_P20";
                }
                else if (cdvDept.Text == CSGV.gs_area_grit)
                {
                    if (b_mp_yn)
                    {
                        sViewID = "CQCM2100-003_P40";
                    }
                    else
                    {
                        sViewID = "CQCM2100-003_P30";
                    }
                    
                }

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdShipReportList);
                    return;
                }

                MPCF.ClearList(spdShipReportList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdShipReportList_Sheet1.RowCount++;

                    spdShipReportList_Sheet1.Cells[i, (int)SHIP_REPORT.SHIP_REPORT_NO].Value = dt.Rows[i]["SHIP_REPORT_NO"];
                    spdShipReportList_Sheet1.Cells[i, (int)SHIP_REPORT.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdShipReportList_Sheet1.Cells[i, (int)SHIP_REPORT.CREATE_DATE].Value = dt.Rows[i]["CREATE_DATE"];
                    spdShipReportList_Sheet1.Cells[i, (int)SHIP_REPORT.GRADE].Value = dt.Rows[i]["GRADE"];
                    spdShipReportList_Sheet1.Cells[i, (int)SHIP_REPORT.TYPES].Value = dt.Rows[i]["TYPES"];

                }
                MPCF.FitColumnHeader(spdShipReportList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        #endregion

        #region " Event Definition "
        private void cdvPackOper_ButtonPress(object sender, EventArgs e)
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

                cdvPackOper.Init();
                MPCF.InitListView(cdvPackOper.GetListView);
                cdvPackOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvPackOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvPackOper.SelectedSubItemIndex = 0;
                cdvPackOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvPackOper.GetListView, '6', cdvDept.Text, "", "", "", 'Y') == false)
                {
                    return;
                }

                cdvPackOper.InsertEmptyRow(0, 1);
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

        private void cdvCustomerID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvCustomerID.Init();
                MPCF.InitListView(cdvCustomerID.GetListView);
                cdvCustomerID.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvCustomerID.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvCustomerID.SelectedSubItemIndex = 0;
                cdvCustomerID.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvCustomerID.GetListView, '1', CSGC.CP_GCM_CUSTOMER) == false)
                {
                    return;
                }

                cdvCustomerID.InsertEmptyRow(0, 1);
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

                ViewPackingOrderList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnProcess_Click(object sender, EventArgs e)
        {
            if (spdShipReportList.ActiveSheet.ActiveRowIndex < 0)
                return;


            try
            {
                int iRow = spdShipReportList.ActiveSheet.ActiveRowIndex;

                s_report_no = spdShipReportList.ActiveSheet.Cells[iRow, (int)SHIP_REPORT.SHIP_REPORT_NO].Text;


                this.DialogResult = DialogResult.OK;

                this.Close();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmPopShipReportList_Load(object sender, EventArgs e)
        {
            this.dtpToWorkDate.Value = DateTime.Now;
            this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);

            cdvDept.Text = s_area_id;



            if(s_area_id =="CTM" && s_area_id == "CTV") {
                if (MPGV.gsFactory == "IJDK1")
                {
                    cdvDept.Text = "CTM";
                }
                else
                {
                    cdvDept.Text = "CTV";
                }

            }

            cdvDept.Enabled = true;

            ViewPackingOrderList();
        }

        private void cdvCustomerID_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvCustomerID.DisplayText == "")
                cdvCustomerID.Text = "";
        }

        private void txtShipReportNo_KeyPress(object sender, KeyPressEventArgs e)
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

        #endregion
    }
}
