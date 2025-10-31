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
    public partial class frmViewInvLotListByOper : CUS_COM.frmViewForm01
    {
        public frmViewInvLotListByOper()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT
        {
            CHK,                // 1 : CHK
            INV_LOT_ID,         // 2 : 자재 LOT ID
            INV_LOT_TYPE,       // 3 : 자재 LOT 타입
            MAT_ID,             // 4 : 제품
            MAT_VER,            // 5 : 버전
            MAT_DESC,           // 6 : 제품명
            QTY,                // 7 : 수량
            UNIT,               // 8 : 단위
            RECV_DATE,          // 9 : 입고일자
            VENDOR_ID,          // 10 : 업체
            VENDOR_DESC,        // 11 : 업체명
            VENDOR_SITE_ID,     // 12 : 업체 SITE ID
            VENDOR_LOT_ID,      // 13 : 업체 LOT ID
            AREA_ID,            // 14 : 사업부
            SUB_AREA_ID,        // 15 : 작업장
            OPER,               // 16 : 창고
            OPER_DESC,          // 17 : 창고명
            LOAD_FLAG,          // 18 : 투입 여부
            LOT_ID,             // 19 : LOT ID
            RES_ID,             // 20 : 설비 ID
            ORDER_ID,           // 21 : 작업 지시 번호
            LOAD_SUB_AREA_ID,   // 22 : 투입 작업장
            LOAD_OPER,          // 23 : 투입 공정
            LOAD_OPER_DESC,     // 24 : 투입 공정명
            HOLD_FLAG,          // 25 : 잠금여부
            INV_CMF_1,          // 26 : 금형 모델
            INV_CMF_2,          // 27 : 금형 구분
            INV_CMF_4           // 28 : KITTING ID
        }

        #endregion

        #region " Variable Definition "

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
                dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");
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
                        cdvOper.Text = "";
                        cdvMatId.Text = "";
                        txtMatDesc.Text = "";

                        MPCF.ClearList(spdInvLotList);
                        break;

                    case "VIEW":

                        MPCF.ClearList(spdInvLotList);
                        break;

                    case "CLICK_DEPT":
                        
                        cdvOper.Text = "";
                        cdvMatId.Text = "";

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

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
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
                    }
                }

                CSCF.ViewLabelList(file_name, in_node, 'I');

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        // 창고 별 자재 LOT 리스트 조회
        public bool ViewInvLotList()
        {
            try
            {


                if (chkNowOnly.Checked == true)
                {
                    dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");
                    dtpDate.Enabled = false;
                }
                else
                {
                    dtpDate.Enabled = true;
                }


                if (dtpDate.Text == DateTime.Now.ToString("yyyy-MM-dd"))
                {

                }
                else
                {

                    if (dtpDate.Text == DateTime.Now.AddDays(-1).ToString("yyyy-MM-dd") && int.Parse(DateTime.Now.Hour.ToString()) < 8)
                    {
                        MPCF.ShowMsgBox("전일 과거시점조회는 8시이후부터 조회가능 합니다. \n (You can inquire the previous day after 8 o'clock)");
                        dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");
                    }
                    else
                    {
                        MPCF.ShowMsgBox(dtpDate.Text + " 일 과거시점 재고조회 \n (" + dtpDate.Text + " Past Date Search)");
                    }

                }





                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[7];
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

                dvcArgu[4].sCondition_ID = "MAT_DESC";
                dvcArgu[4].sCondition_Value = txtMatDesc.Text;

                dvcArgu[5].sCondition_ID = "EOH_DATE";
                dvcArgu[5].sCondition_Value = dtpDate.Text.Replace("-", "");


                if (rdo08.Checked == true)
                {
                    dvcArgu[6].sCondition_ID = "EOH_ST";
                    dvcArgu[6].sCondition_Value = "08";
                }
                {
                    dvcArgu[6].sCondition_ID = "EOH_ST";
                    dvcArgu[6].sCondition_Value = "00";
                }



                if (TPDR.GetDataOne("", ref dt, "CINV3002-001", dvcArgu, false, false, ref sSql) == false)
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
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.RECV_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["RECV_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.VENDOR_ID].Value = dt.Rows[i]["VENDOR_ID"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.VENDOR_DESC].Value = dt.Rows[i]["VENDOR_DESC"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.VENDOR_SITE_ID].Value = dt.Rows[i]["VENDOR_SITE_ID"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.SUB_AREA_ID].Value = dt.Rows[i]["SUB_AREA_ID"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.OPER].Value = dt.Rows[i]["OPER"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.LOAD_FLAG].Value = dt.Rows[i]["LOAD_FLAG"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.RES_ID].Value = dt.Rows[i]["RES_ID"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.LOAD_SUB_AREA_ID].Value = dt.Rows[i]["INV_CMF_8"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.LOAD_OPER].Value = dt.Rows[i]["INV_CMF_9"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.LOAD_OPER_DESC].Value = dt.Rows[i]["LOAD_OPER_DESC"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.HOLD_FLAG].Value = dt.Rows[i]["HOLD_FLAG"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.INV_CMF_1].Value = dt.Rows[i]["INV_CMF_1"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.INV_CMF_2].Value = dt.Rows[i]["INV_CMF_2"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.INV_CMF_4].Value = dt.Rows[i]["INV_CMF_4"];
                }
                MPCF.FitColumnHeader(spdInvLotList);
                
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
        private void frmViewInvLotListByOper_Load(object sender, EventArgs e)
        {
            try
            {
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

                if (COM_LIST.ViewOperationList(cdvOper.GetListView, '7', cdvDept.Text, "", "", "", 'Y') == false)
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
                if (CheckCondition("VIEW") == false)
                    return;

                ClearList("VIEW");

                ViewInvLotList();
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

        private void cdvMatId_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatId.DisplayText == "")
                cdvMatId.Text = "";
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdInvLotList, "InvLotIssueList");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
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

        #endregion

        private void chkNowOnly_CheckedChanged(object sender, EventArgs e)
        {
            if (chkNowOnly.Checked == true)
            {
                dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");
                dtpDate.Enabled = false;

                pnlOldDate.Visible = false;

            }
            else
            {
                dtpDate.Enabled = true;

                pnlOldDate.Visible = true;
            }
        }
    }
}
