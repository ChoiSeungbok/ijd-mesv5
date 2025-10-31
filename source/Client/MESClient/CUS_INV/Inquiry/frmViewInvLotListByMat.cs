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
    public partial class frmViewInvLotListByMat : CUS_COM.frmViewForm01
    {
        public frmViewInvLotListByMat()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum MAT : int
        {
            MAT_ID,               // 1 : 품목
            MAT_VER,              // 2 : 버전
            MAT_DESC,             // 3 : 품명 
            MAT_TYPE,             // 4 : 제품 종류
            QTY,                  // 5 : 수량
            UNIT,                 // 6 : 단위
            AREA_ID               // 7 : 사업부  
        }

        private enum LOT
        {
            CHK,                    // 1 : CHK
            INV_LOT_ID,             // 2 : 자재 LOT ID
            INV_LOT_TYPE,           // 3 : 자재 LOT 타입
            MAT_ID,                 // 4 : 제품
            MAT_DESC,               // 5 : 제품명
            QTY,                    // 6 : 수량
            UNIT,                   // 7 : 단위
            RECV_DATE,              // 8 : 입고일자
            VENDOR_ID,              // 9 : 공급사
            VENDOR_DESC,            // 10 : 공급사명
            VENDOR_SITE_ID,         // 11 : 공급사 SITE ID       
            VENDOR_LOT_ID,          // 12 : 공급사 LOT ID
            OPER,                   // 13 : 창고
            OPER_DESC,              // 14 : 창고명
            LOAD_FLAG,              // 15 : 투입 여부 
            LOT_ID,                 // 16 : 작업 지시 번호
            RES_ID,                 // 17 : 작업 지시 번호
            ORDER_ID,               // 18 : 작업 지시 번호
            LOAD_WORKPLACE_DESC,    // 19 : 투입 작업장
            LOAD_OPER,              // 20 : 투입 공정
            LOAD_OPER_DESC,         // 21 : 투입 공정명
            HOLD_FLAG               // 22 : 보류 여부
        }

        #endregion

        #region " Variable Definition "

        string s_area_id = "";
        string s_mat_id = "";
        string s_mat_ver = "";

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
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
                        MPCF.ClearList(spdMatList);
                        MPCF.ClearList(spdLotList);
                        break;

                    case "MAT_CLICK":
                        MPCF.ClearList(spdLotList);
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

                        if (MPCF.Trim(cdvMatType.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMatType.Text + "]");
                            cdvMatType.Focus();
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

        //품목별 자재 현황 조회
        private bool ViewMaterialList()
        {
            TRSNode in_node = new TRSNode("view_inv_lot_list_By_Mat_In");
            TRSNode out_node = new TRSNode("view_inv_lot_list_By_Mat_Out");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("MAT_ID", cdvMatId.Text);
                in_node.AddString("MAT_TYPE", cdvMatType.Text);

                if (MPCR.CallService("CUS_INV", "CUS_INV_View_Lot_List_By_Mat", in_node, ref out_node) == false)
                    return false;

                for (int i = 0; i < out_node.GetList(0).Count; i++)
                {
                    spdMatList_Sheet1.RowCount++;

                    spdMatList_Sheet1.Cells[i, (int)MAT.MAT_ID].Value = out_node.GetList(0)[i].GetString("MAT_ID");
                    spdMatList_Sheet1.Cells[i, (int)MAT.MAT_VER].Value = out_node.GetList(0)[i].GetInt("MAT_VER");
                    spdMatList_Sheet1.Cells[i, (int)MAT.MAT_DESC].Value = out_node.GetList(0)[i].GetString("MAT_DESC");
                    spdMatList_Sheet1.Cells[i, (int)MAT.MAT_TYPE].Value = out_node.GetList(0)[i].GetString("MAT_TYPE");
                    spdMatList_Sheet1.Cells[i, (int)MAT.QTY].Value = out_node.GetList(0)[i].GetDouble("QTY");
                    spdMatList_Sheet1.Cells[i, (int)MAT.UNIT].Value = out_node.GetList(0)[i].GetString("UNIT");
                    spdMatList_Sheet1.Cells[i, (int)MAT.AREA_ID].Value = out_node.GetList(0)[i].GetString("AREA_ID");
                }
                MPCF.FitColumnHeader(spdMatList);

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

                for (int i = 0; i < spdLotList_Sheet1.RowCount; i++)
                {
                    if (spdLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        label_list = in_node.AddNode("INV_LOT_LIST");
                        label_list.AddString("INV_LOT_ID", spdLotList_Sheet1.Cells[i, (int)LOT.INV_LOT_ID].Text);
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

        //자재 LOT 조회
        private bool ViewInvLotList(string sAreaId, string sMatId, string sMatVer)
        {
            TRSNode in_node = new TRSNode("view_inv_lot_list_By_Mat_In");
            TRSNode out_node = new TRSNode("view_inv_lot_list_By_Mat_Out");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
                in_node.AddString("AREA_ID", sAreaId);
                in_node.AddString("MAT_ID", sMatId);
                in_node.AddInt("MAT_VER", sMatVer);

                if (MPCR.CallService("CUS_INV", "CUS_INV_View_Lot_List_By_Mat", in_node, ref out_node) == false)
                    return false;

                for (int i = 0; i < out_node.GetList(0).Count; i++)
                {
                    spdLotList_Sheet1.RowCount++;

                    spdLotList_Sheet1.SetValue(i, (int)LOT.CHK, false);
                    spdLotList_Sheet1.Cells[i, (int)LOT.INV_LOT_ID].Value = out_node.GetList(0)[i].GetString("INV_LOT_ID");
                    spdLotList_Sheet1.Cells[i, (int)LOT.INV_LOT_TYPE].Value = out_node.GetList(0)[i].GetString("INV_LOT_TYPE");
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Value = out_node.GetList(0)[i].GetString("MAT_ID");
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Value = out_node.GetList(0)[i].GetString("MAT_DESC");
                    spdLotList_Sheet1.Cells[i, (int)LOT.QTY].Value = out_node.GetList(0)[i].GetDouble("QTY");
                    spdLotList_Sheet1.Cells[i, (int)LOT.UNIT].Value = out_node.GetList(0)[i].GetString("UNIT");
                    spdLotList_Sheet1.Cells[i, (int)LOT.RECV_DATE].Value = MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("RECV_DATE"), DATE_TIME_FORMAT.DATE);
                    spdLotList_Sheet1.Cells[i, (int)LOT.VENDOR_ID].Value = out_node.GetList(0)[i].GetString("VENDOR_ID");
                    spdLotList_Sheet1.Cells[i, (int)LOT.VENDOR_DESC].Value = out_node.GetList(0)[i].GetString("VENDOR_DESC");
                    spdLotList_Sheet1.Cells[i, (int)LOT.VENDOR_SITE_ID].Value = out_node.GetList(0)[i].GetInt("VENDOR_SITE_ID");
                    spdLotList_Sheet1.Cells[i, (int)LOT.VENDOR_LOT_ID].Value = out_node.GetList(0)[i].GetString("VENDOR_LOT_ID"); 
                    spdLotList_Sheet1.Cells[i, (int)LOT.OPER].Value = out_node.GetList(0)[i].GetString("OPER"); 
                    spdLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Value = out_node.GetList(0)[i].GetString("OPER_DESC");
                    spdLotList_Sheet1.Cells[i, (int)LOT.LOAD_FLAG].Value = out_node.GetList(0)[i].GetChar("LOAD_FLAG");
                    spdLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Value = out_node.GetList(0)[i].GetString("LOT_ID");
                    spdLotList_Sheet1.Cells[i, (int)LOT.RES_ID].Value = out_node.GetList(0)[i].GetString("RES_ID");
                    spdLotList_Sheet1.Cells[i, (int)LOT.ORDER_ID].Value = out_node.GetList(0)[i].GetString("ORDER_ID");
                    spdLotList_Sheet1.Cells[i, (int)LOT.LOAD_WORKPLACE_DESC].Value = out_node.GetList(0)[i].GetString("LOAD_WORKPLACE_DESC");
                    spdLotList_Sheet1.Cells[i, (int)LOT.LOAD_OPER].Value = out_node.GetList(0)[i].GetString("LOAD_OPER");
                    spdLotList_Sheet1.Cells[i, (int)LOT.LOAD_OPER_DESC].Value = out_node.GetList(0)[i].GetString("LOAD_OPER_DESC");
                    spdLotList_Sheet1.Cells[i, (int)LOT.HOLD_FLAG].Value = out_node.GetList(0)[i].GetChar("HOLD_FLAG");
                }

                MPCF.FitColumnHeader(spdLotList);
                
                return true;
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        #endregion

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
                cdvMatType.Text = "";
                cdvMatId.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvMatType.Init();
                MPCF.InitListView(cdvMatType.GetListView);
                cdvMatType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvMatType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvMatType.SelectedSubItemIndex = 0;
                cdvMatType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvMatType.GetListView, '1', MPGC.MP_WIP_MATERIAL_TYPE) == false)
                {
                    return;
                }

                cdvMatType.InsertEmptyRow(0, 1);
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
                popup.sType_id = cdvMatType.Text;
                popup.sType_desc = cdvMatType.DisplayText;

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

        private void cdvMatType_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvMatId.Text = "";
            }
            catch(Exception ex)
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

                ViewMaterialList();
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdMatList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                //for (int i = 0; i < spdMatList.ActiveSheet.RowCount; i++)
                //{
                //    spdMatList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                //}

                ClearList("MAT_CLICK");

                if (e.ColumnHeader || e.Row < 0)
                {
                    return;
                }
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdMatList, e.Row);

                }
                // spdMatList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                s_area_id = spdMatList_Sheet1.Cells[e.Row, (int)MAT.AREA_ID].Text;
                s_mat_id = spdMatList_Sheet1.Cells[e.Row, (int)MAT.MAT_ID].Text;
                s_mat_ver = spdMatList_Sheet1.Cells[e.Row, (int)MAT.MAT_VER].Text;

                ViewInvLotList(s_area_id, s_mat_id, s_mat_ver);
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
                FpSpread excelSp = new FpSpread();
                spdMatList_Sheet1.SheetName = "Sheet1";
                excelSp.Sheets.Add(spdMatList_Sheet1);
                spdLotList_Sheet1.SheetName = "Sheet2";
                excelSp.Sheets.Add(spdLotList_Sheet1);

                EXTFUC.SaveExcel(excelSp, "InvLotByMat");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void spdLotList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                {
                    if (spdLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdLotList, e.Row, e.Column, true, true, false);
                    }
                }

                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdLotList, e.Row);
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
                if (ViewPrintLabel())
                {
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
    }
}
