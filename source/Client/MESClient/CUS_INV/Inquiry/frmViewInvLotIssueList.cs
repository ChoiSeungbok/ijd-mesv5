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
    public partial class frmViewInvLotIssueList : CUS_COM.frmViewForm01
    {
        public frmViewInvLotIssueList()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum ISSUE
        {
            INV_LOT_ID,              // 1 : 자재 LOT ID
            REQ_NO,                  // 2 : 불출 요청 번호
            REQ_MAT_ID,              // 3 : 불출 요청 제품
            REQ_MAT_VER,             // 4 : 불출 요청 제품 버전
            REQ_MAT_DESC,            // 5 : 불출 요청 제품명
            ISSUE_TIME,              // 6 : 불출 시간
            ISSUE_QTY,               // 7 : 불출 수량
            UNIT,                    // 8 : 단위
            AREA_ID,                 // 9 : 사업부
            SUB_AREA_ID,             // 10 : 작업장
            OPER,                    // 11 : 창고
            OPER_DESC,               // 12 : 창고명
            TO_AREA_ID,              // 13 : 불출 사업부
            TO_SUB_AREA_ID,          // 14 : 불출 작업장
            TO_OPER,                 // 15 : 불출 창고
            TO_OPER_DESC             // 16 : 불출 창고명
        }

        #endregion

        #region " Variable Definition "

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

        //자재 불출 현황 조회
        private bool ViewIssueList()
        {
            TRSNode in_node = new TRSNode("view_issue_list_In");
            TRSNode out_node = new TRSNode("view_issue_list_Out");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("TO_OPER", cdvToOper.Text);
                in_node.AddString("REQ_MAT_ID", cdvMatId.Text);
                in_node.AddString("INV_LOT_ID", txtInvLotID.Text);
                in_node.AddString("FROM_DATE", string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", "")));
                in_node.AddString("TO_DATE", dtpToWorkDate.Text.Replace("-", "") + "235959");

                if (MPCR.CallService("CUS_INV", "CUS_INV_View_Lot_Issue_List", in_node, ref out_node) == false)
                    return false;
                
                MPCF.ClearList(spdIssueList);
                
                for (int i = 0; i < out_node.GetList(0).Count; i++)
                {
                    spdIssueList_Sheet1.RowCount++;

                    spdIssueList_Sheet1.Cells[i, (int)ISSUE.INV_LOT_ID].Value = out_node.GetList(0)[i].GetString("INV_LOT_ID");
                    spdIssueList_Sheet1.Cells[i, (int)ISSUE.REQ_NO].Value = out_node.GetList(0)[i].GetString("REQ_NO");
                    spdIssueList_Sheet1.Cells[i, (int)ISSUE.REQ_MAT_ID].Value = out_node.GetList(0)[i].GetString("REQ_MAT_ID");
                    spdIssueList_Sheet1.Cells[i, (int)ISSUE.REQ_MAT_VER].Value = out_node.GetList(0)[i].GetInt("REQ_MAT_VER");
                    spdIssueList_Sheet1.Cells[i, (int)ISSUE.REQ_MAT_DESC].Value = out_node.GetList(0)[i].GetString("REQ_MAT_DESC");
                    spdIssueList_Sheet1.Cells[i, (int)ISSUE.ISSUE_TIME].Value = MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("ISSUE_TIME"), DATE_TIME_FORMAT.DATETIME);
                    spdIssueList_Sheet1.Cells[i, (int)ISSUE.ISSUE_QTY].Value = out_node.GetList(0)[i].GetDouble("ISSUE_QTY");
                    spdIssueList_Sheet1.Cells[i, (int)ISSUE.UNIT].Value = out_node.GetList(0)[i].GetString("UNIT");
                    spdIssueList_Sheet1.Cells[i, (int)ISSUE.AREA_ID].Value = out_node.GetList(0)[i].GetString("AREA_ID");
                    spdIssueList_Sheet1.Cells[i, (int)ISSUE.SUB_AREA_ID].Value = out_node.GetList(0)[i].GetString("SUB_AREA_ID");
                    spdIssueList_Sheet1.Cells[i, (int)ISSUE.OPER].Value = out_node.GetList(0)[i].GetString("OPER");
                    spdIssueList_Sheet1.Cells[i, (int)ISSUE.OPER_DESC].Value = out_node.GetList(0)[i].GetString("OPER_DESC");
                    spdIssueList_Sheet1.Cells[i, (int)ISSUE.TO_AREA_ID].Value = out_node.GetList(0)[i].GetString("TO_AREA_ID");
                    spdIssueList_Sheet1.Cells[i, (int)ISSUE.TO_SUB_AREA_ID].Value = out_node.GetList(0)[i].GetString("TO_SUB_AREA_ID");
                    spdIssueList_Sheet1.Cells[i, (int)ISSUE.TO_OPER].Value = out_node.GetList(0)[i].GetString("TO_OPER");
                    spdIssueList_Sheet1.Cells[i, (int)ISSUE.TO_OPER_DESC].Value = out_node.GetList(0)[i].GetString("TO_OPER_DESC");
                }

                MPCF.FitColumnHeader(spdIssueList);

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
                        cdvToOper.Text = "";
                        cdvMatId.Text = "";
                        txtInvLotID.Text = "";
                        this.dtpToWorkDate.Value = DateTime.Now;
                        this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);
                        //dtpFromWorkDate.Format = DateTimePickerFormat.Custom;
                        //dtpFromWorkDate.CustomFormat = " ";
                        MPCF.ClearList(spdIssueList);
                        break;

                    case "VIEW":

                        MPCF.ClearList(spdIssueList);
                        break;

                    case "CLICK_DEPT":
                        
                        cdvToOper.Text = "";
                        cdvMatId.Text = "";
                        txtInvLotID.Text = "";

                        MPCF.ClearList(spdIssueList);
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
        private void frmViewInvLotIssueList_Load(object sender, EventArgs e)
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

                if (COM_LIST.ViewOperationList(cdvToOper.GetListView, '4', cdvDept.Text, "", "", "", 'Y') == false)
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

        private void cdvMatId_ButtonPress(object sender, EventArgs e)
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

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("VIEW") == false)
                    return;

                ClearList("VIEW");

                if (ViewIssueList())
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

        private void cdvMatId_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatId.DisplayText == "")
                cdvMatId.Text = "";
        }
        #endregion

        private void txtInvLotID_KeyPress(object sender, KeyPressEventArgs e)
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

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdIssueList, "InvLotIssueList");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void spdIssueList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {

            try
            {
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdIssueList, e.Row);
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void dtpFromWorkDate_CloseUp(object sender, EventArgs e)
        {
            dtpFromWorkDate.CustomFormat = "yyyy-MM-dd";
        }
    }
}
