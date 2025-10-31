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
    public partial class frmViewInvLotMoveHistory : CUS_COM.frmViewForm01
    {
        public frmViewInvLotMoveHistory()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum MVH_INFO : int
        {
            INV_LOT_ID,         // 1 . 자재 LOT ID
            HIST_SEQ,           // 2 . 이력 순번
            TRAN_CODE,          // 3 . 처리 코드      
            MAT_ID,             // 4 . 제품
            MAT_DESC,           // 5 . 제품 명
            TRAN_QTY,           // 6 . 처리 수량
            UNIT,               // 7 . 단위
            AREA_DESC,          // 8 . 사업부
            SUB_AREA_DESC,      // 9 . 작업장
            OPER,               // 10. 공정
            OPER_DESC,          // 11. 공정 명
            TO_AREA_DESC,       // 12. To 사업부
            TO_SUB_AREA_DESC,   // 13. To 작업장
            TO_OPER,            // 14. To 공정
            TO_OPER_DESC,       // 15. To 공정명     
            TRAN_TIME,          // 16. 처리 시간
            TRAN_USER_ID        // 17. 처리자
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
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 초기화
        private void ClearData(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "VIEW":
                        break;
                }
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

        // 자재 이동 현황 조회
        public bool ViewInvMoveHistory()
        {
            TRSNode in_node = new TRSNode("VIEW_INV_MOVE_HISTORY_IN ");
            TRSNode out_node = new TRSNode("VIEW_INV_MOVE_HISTORY_OUT");

            int iRow = 0;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("OPER", cdvFromOper.Text);
                in_node.AddString("TO_OPER", cdvToOper.Text);
                in_node.AddString("MAT_ID", cdvMatId.Text);
                in_node.AddString("INV_LOT_ID", MPCF.Trim(txtInvLotID.Text));
                in_node.AddString("FROM_DATE", string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", "")));
                in_node.AddString("TO_DATE", dtpToWorkDate.Text.Replace("-", "") + "235959");

                MPCF.ClearList(spdInvLotMvhList);

                do
                {
                    if (MPCR.CallService("CUS_INV", "CUS_INV_View_Move_History_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    for (int i = 0; i < out_node.GetList("MVH_TBL").Count; i++)
                    {
                        iRow = spdInvLotMvhList_Sheet1.RowCount;

                        spdInvLotMvhList_Sheet1.RowCount++;

                        spdInvLotMvhList_Sheet1.Cells[iRow, (int)MVH_INFO.INV_LOT_ID].Value = out_node.GetList("MVH_TBL")[i].GetString("INV_LOT_ID");
                        spdInvLotMvhList_Sheet1.Cells[iRow, (int)MVH_INFO.HIST_SEQ].Value = out_node.GetList("MVH_TBL")[i].GetInt("HIST_SEQ");
                        spdInvLotMvhList_Sheet1.Cells[iRow, (int)MVH_INFO.TRAN_CODE].Value = out_node.GetList("MVH_TBL")[i].GetString("TRAN_CODE");
                        spdInvLotMvhList_Sheet1.Cells[iRow, (int)MVH_INFO.MAT_ID].Value = out_node.GetList("MVH_TBL")[i].GetString("MAT_ID");
                        spdInvLotMvhList_Sheet1.Cells[iRow, (int)MVH_INFO.MAT_DESC].Value = out_node.GetList("MVH_TBL")[i].GetString("MAT_DESC");
                        spdInvLotMvhList_Sheet1.Cells[iRow, (int)MVH_INFO.TRAN_QTY].Value = out_node.GetList("MVH_TBL")[i].GetDouble("TRAN_QTY");
                        spdInvLotMvhList_Sheet1.Cells[iRow, (int)MVH_INFO.UNIT].Value = out_node.GetList("MVH_TBL")[i].GetString("UNIT");
                        spdInvLotMvhList_Sheet1.Cells[iRow, (int)MVH_INFO.AREA_DESC].Value = out_node.GetList("MVH_TBL")[i].GetString("AREA_DESC");
                        spdInvLotMvhList_Sheet1.Cells[iRow, (int)MVH_INFO.SUB_AREA_DESC].Value = out_node.GetList("MVH_TBL")[i].GetString("SUB_AREA_DESC");
                        spdInvLotMvhList_Sheet1.Cells[iRow, (int)MVH_INFO.OPER].Value = out_node.GetList("MVH_TBL")[i].GetString("OPER");
                        spdInvLotMvhList_Sheet1.Cells[iRow, (int)MVH_INFO.OPER_DESC].Value = out_node.GetList("MVH_TBL")[i].GetString("OPER_DESC");
                        spdInvLotMvhList_Sheet1.Cells[iRow, (int)MVH_INFO.TO_AREA_DESC].Value = out_node.GetList("MVH_TBL")[i].GetString("TO_AREA_DESC");
                        spdInvLotMvhList_Sheet1.Cells[iRow, (int)MVH_INFO.TO_SUB_AREA_DESC].Value = out_node.GetList("MVH_TBL")[i].GetString("TO_SUB_AREA_DESC");
                        spdInvLotMvhList_Sheet1.Cells[iRow, (int)MVH_INFO.TO_OPER].Value = out_node.GetList("MVH_TBL")[i].GetString("TO_OPER");
                        spdInvLotMvhList_Sheet1.Cells[iRow, (int)MVH_INFO.TO_OPER_DESC].Value = out_node.GetList("MVH_TBL")[i].GetString("TO_OPER_DESC");
                        spdInvLotMvhList_Sheet1.Cells[iRow, (int)MVH_INFO.TRAN_TIME].Value = MPCF.MakeDateFormat(out_node.GetList("MVH_TBL")[i].GetString("TRAN_TIME"), DATE_TIME_FORMAT.DATETIME);
                        spdInvLotMvhList_Sheet1.Cells[iRow, (int)MVH_INFO.TRAN_USER_ID].Value = out_node.GetList("MVH_TBL")[i].GetString("TRAN_USER_ID");
                    }
                    in_node.SetInt("NEXT_HIST_SEQ", out_node.GetInt("NEXT_HIST_SEQ"));

                } while (in_node.GetInt("NEXT_HIST_SEQ") > 0);

                MPCF.FitColumnHeader(spdInvLotMvhList);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        #endregion

        private void frmViewInvLotMoveHistory_Load(object sender, EventArgs e)
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
                cdvFromOper.Text = "";
                cdvToOper.Text = "";
                cdvMatId.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvFromOper_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvFromOper.Init();
                MPCF.InitListView(cdvFromOper.GetListView);
                cdvFromOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvFromOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvFromOper.SelectedSubItemIndex = 0;
                cdvFromOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvFromOper.GetListView, 'F', cdvDept.Text, "", "", "", 'Y') == false)
                {
                    return;
                }

                cdvFromOper.InsertEmptyRow(0, 1);
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
                cdvToOper.Init();
                MPCF.InitListView(cdvToOper.GetListView);
                cdvToOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvToOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToOper.SelectedSubItemIndex = 0;
                cdvToOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvToOper.GetListView, 'F', cdvDept.Text, "", "", "", 'Y') == false)
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
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewInvMoveHistory();
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

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdInvLotMvhList, "InvLotMoveHistory");

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

        private void spdInvLotMvhList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdInvLotMvhList, e.Row);
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

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

        private void dtpFromWorkDate_CloseUp(object sender, EventArgs e)
        {
            dtpFromWorkDate.CustomFormat = "yyyy-MM-dd";
        }
    }
}
