using System;
using System.Data;
using System.Collections.Generic;
using System.Windows.Forms;
using MExcel = Microsoft.Office.Interop.Excel;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;
using FarPoint.Win.Spread;
using System.Drawing;

//202100719 화면 전반적으로 수정(기존 기능 visible false나 hidden 등으로 숨겨놓기만 함 일단 추후 다시 써야할지몰라서
namespace CUS_ORD
{
    public partial class frmTranProdPlanRegistration : frmTranForm07
    {
        public frmTranProdPlanRegistration()
        {
            InitializeComponent();

            InitControl();
        }

        private void frmTranProdPlanRegistration_Load(object sender, EventArgs e)
        {
            dtpFrDate.Text = DateTime.Now.ToShortDateString();
            dtpToDate.Text = DateTime.Now.ToShortDateString();

            cdvDept.Text = string.Empty;
            cdvDept.DisplayText = string.Empty;
            cdvWorkPlace.Text = string.Empty;
            cdvWorkPlace.DisplayText = string.Empty;
            cdvOper.Text = string.Empty;
            cdvOper.DisplayText = string.Empty;
        }

        #region " Constant Definition "

        // 작업자 정보
        private enum PROD_PLAN_INFO : int
        {
            CHECK,             // 1 : 선택
            PLAN_WW,           // 2: 주차
            PLAN_DY,           // 3: 요일 
            PLAN_D,            // 4: 휴일여부
            PLAN_DATE,         // 4: 계획 날짜 
            AREA_CODE,         // 5 : 사업부 코드
            AREA_BUTTON,       // 6 : 사업부 버튼
            AREA_DESC,         // 7 : 사업부명
            SUB_AREA_CODE,     // 8 : 작업장 코드
            SUB_AREA_BUTTON,   // 9 : 작업장 버튼
            SUB_AREA_DESC,     // 10 : 작업장명
            OPER_CODE,         // 11: 공정 코드
            OPER_BUTTON,       // 12 : 공정 버튼    
            OPER_DESC,         // 13: 공정명      
            MAT_CODE,          // 14: 품목 코드     
            MAT_BUTTON,        // 15: 품목 버튼
            MAT_DESC,          // 16: 품목명
            QTY,               // 17: 수량
            UNIT,              // 18: 단위
        }

        #endregion

        #region " Variable Definition "
        #endregion


        #region " Grid Definition "
        private void spdProdPlan_CellClick(object sender, CellClickEventArgs e)
        {
            int i = 0;
            SheetView sv = spdProdPlan.ActiveSheet;

            if(sv.Rows.Count == 0)
            {
                return;
            }

            if (e.Row >= 0 && Convert.ToBoolean(sv.Cells[e.Row, (int)PROD_PLAN_INFO.CHECK] == null ? false : sv.Cells[e.Row, (int)PROD_PLAN_INFO.CHECK].Value))
                sv.Cells[e.Row, (int)PROD_PLAN_INFO.CHECK].Value = true;


            if (e.ColumnHeader == false)
            {
                return;
            }

            if (e.Column != 0)
            {
                return;
            }
            bool allChecked = false;
            if (sv.ColumnHeader.Cells[0, 0].Value == null || Convert.ToBoolean(sv.ColumnHeader.Cells[0, 0].Value == null ? false : sv.ColumnHeader.Cells[0, 0].Value) == false)
            {
                allChecked = false;
            }
            else
            {
                allChecked = true;
            }

            if (allChecked == true)
            {
                for (i = 0; i < sv.RowCount; i++)
                {
                    sv.Cells[i, 0].Value = false;
                }

                sv.ColumnHeader.Cells[0, 0].Value = false;
            }
            else
            {
                for (i = 0; i < sv.RowCount; i++)
                {
                    sv.Cells[i, 0].Value = true;
                }
                sv.ColumnHeader.Cells[0, 0].Value = true;
            }

        }

        private void spdProdPlan_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                SheetView sv = spdProdPlan.ActiveSheet;

                if (e.Column == (int)PROD_PLAN_INFO.AREA_BUTTON || e.Column == (int)PROD_PLAN_INFO.SUB_AREA_BUTTON
                    || e.Column == (int)PROD_PLAN_INFO.OPER_BUTTON)
                {
                    cdvGridButton.Init();
                    MPCF.InitListView(cdvGridButton.GetListView);
                    cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);
                    cdvGridButton.Columns.Add("Desc", 100, HorizontalAlignment.Left);

                    if (e.Column == (int)PROD_PLAN_INFO.AREA_BUTTON)
                    {
                        //사업부 조회
                        if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                            return;

                        sv.Cells[e.Row, (int)PROD_PLAN_INFO.SUB_AREA_CODE].Value = string.Empty;
                        sv.Cells[e.Row, (int)PROD_PLAN_INFO.SUB_AREA_DESC].Value = string.Empty;
                        sv.Cells[e.Row, (int)PROD_PLAN_INFO.OPER_CODE].Value = string.Empty;
                        sv.Cells[e.Row, (int)PROD_PLAN_INFO.OPER_DESC].Value = string.Empty;
                    }
                    else if (e.Column == (int)PROD_PLAN_INFO.SUB_AREA_BUTTON)
                    {
                        //작업장 조회
                        if (BASLIST.ViewGCMDataList_AREA(cdvGridButton.GetListView, '1', MPGC.MP_RAS_SUBAREA_CODE, -1, null, "", true, -1, -1, null, MPCF.Trim(sv.Cells[e.Row, (int)PROD_PLAN_INFO.AREA_CODE].Value)) == false)
                            return;

                        spdProdPlan_Sheet1.Cells[e.Row, (int)PROD_PLAN_INFO.OPER_CODE].Value = string.Empty;
                        spdProdPlan_Sheet1.Cells[e.Row, (int)PROD_PLAN_INFO.OPER_DESC].Value = string.Empty;
                    }
                    else if (e.Column == (int)PROD_PLAN_INFO.OPER_BUTTON)
                    {
                        //공정 조회
                        if (COM_LIST.ViewOperationList(cdvGridButton.GetListView, '1', MPCF.Trim(sv.Cells[e.Row, (int)PROD_PLAN_INFO.AREA_CODE].Value), MPCF.Trim(sv.Cells[e.Row, (int)PROD_PLAN_INFO.SUB_AREA_CODE].Value)) == false)
                        {
                            return;
                        }
                    }

                    cdvGridButton.ShowPopupList(e.Row, e.Column);
                    cdvGridButton.InsertEmptyRow(0, 1);
                }
                else if (e.Column == (int)PROD_PLAN_INFO.MAT_BUTTON)
                {
                    frmPopMaterialList popup = new frmPopMaterialList();
                    popup.StartPosition = FormStartPosition.CenterParent;
                    popup.Width = 900;
                    popup.Height = 500;
                    popup.sArea_id = sv.Cells[e.Row, (int)PROD_PLAN_INFO.AREA_CODE].Value == null ? string.Empty : sv.Cells[e.Row, (int)PROD_PLAN_INFO.AREA_CODE].Value.ToString();
                    popup.sArea_desc = sv.Cells[e.Row, (int)PROD_PLAN_INFO.AREA_DESC].Value == null ? string.Empty : sv.Cells[e.Row, (int)PROD_PLAN_INFO.AREA_DESC].Value.ToString();

                    if (popup.ShowDialog() == DialogResult.OK)
                    {
                        sv.Cells[e.Row, (int)PROD_PLAN_INFO.MAT_CODE].Value = popup.sMat_id;
                        sv.Cells[e.Row, (int)PROD_PLAN_INFO.MAT_DESC].Value = popup.sMat_Desc;
                        popup = null;
                    }
                    else
                    {
                        return;
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvGridButton_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            SheetView sv = spdProdPlan.ActiveSheet;
            try
            {
                if (sv.ActiveColumnIndex == (int)PROD_PLAN_INFO.AREA_BUTTON)
                {
                    spdProdPlan_Sheet1.SetValue(e.Row, (int)PROD_PLAN_INFO.AREA_CODE, e.SelectedItem.SubItems[0].Text);
                    spdProdPlan_Sheet1.SetValue(e.Row, (int)PROD_PLAN_INFO.AREA_DESC, e.SelectedItem.SubItems[1].Text);
                }
                else if (sv.ActiveColumnIndex == (int)PROD_PLAN_INFO.SUB_AREA_BUTTON)
                {
                    spdProdPlan_Sheet1.SetValue(e.Row, (int)PROD_PLAN_INFO.SUB_AREA_CODE, e.SelectedItem.SubItems[0].Text);
                    spdProdPlan_Sheet1.SetValue(e.Row, (int)PROD_PLAN_INFO.SUB_AREA_DESC, e.SelectedItem.SubItems[1].Text);
                }
                else if (sv.ActiveColumnIndex == (int)PROD_PLAN_INFO.OPER_BUTTON)
                {
                    spdProdPlan_Sheet1.SetValue(e.Row, (int)PROD_PLAN_INFO.OPER_CODE, e.SelectedItem.SubItems[0].Text);
                    spdProdPlan_Sheet1.SetValue(e.Row, (int)PROD_PLAN_INFO.OPER_DESC, e.SelectedItem.SubItems[1].Text);
                }
            }

            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        //조건에서 MAT ID 팝업 클릭
        private void cdvMatid_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.Width = 900;
                popup.Height = 500;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvMatid.Text = popup.sMat_id;
                    cdvMatid.DisplayText = popup.sMat_Desc;
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
        #endregion

        #region " Function Defintion "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                pnlGCM.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                chkFavorite2.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                lblExcComment.Anchor = AnchorStyles.Top | AnchorStyles.Left;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewProdPlanList()
        {
            string sViewId = "CORD2001-001";
            string sSql = "";
            SheetView sv = spdProdPlan.ActiveSheet;


            try
            {
                MPCF.ClearList(spdProdPlan);

                TPDR.DirectViewCond[] dvcProdPlan = new TPDR.DirectViewCond[6];
                DataTable dt = new DataTable();

                dvcProdPlan[0].sCondition_ID = "P_FACTORY";
                dvcProdPlan[0].sCondition_Value = MPGV.gsFactory;

                dvcProdPlan[1].sCondition_ID = "P_AREA_ID";
                dvcProdPlan[1].sCondition_Value = cdvDept.Text;

                dvcProdPlan[2].sCondition_ID = "P_OPER";
                dvcProdPlan[2].sCondition_Value = cdvPlanOper.Text;

                dvcProdPlan[3].sCondition_ID = "P_PLAN_FR_DATE";
                dvcProdPlan[3].sCondition_Value = dtpFrDate.Text.Replace("-", "");

                dvcProdPlan[4].sCondition_ID = "P_PLAN_TO_DATE";
                dvcProdPlan[4].sCondition_Value = dtpToDate.Text.Replace("-", "");

                dvcProdPlan[5].sCondition_ID = "P_MAT_ID";
                dvcProdPlan[5].sCondition_Value = cdvMatid.Text;

                if (TPDR.GetDataOne("", ref dt, sViewId, dvcProdPlan, false, false, ref sSql) == false)
                {
                    if (dt == null || dt.Rows.Count == 0)
                    {
                        //추후 메시지 필요하면 추가하는 것으로 현재 다른화면도 없음
                    }
                    else
                    {
                        dt.Dispose();
                    }
                    return;
                }

                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    sv.RowCount++;
                    sv.Cells[i, (int)PROD_PLAN_INFO.CHECK].Value = false;
                    sv.Cells[i, (int)PROD_PLAN_INFO.PLAN_WW].Value = dt.Rows[i]["PLAN_WW"];
                    sv.Cells[i, (int)PROD_PLAN_INFO.PLAN_DY].Value = dt.Rows[i]["PLAN_DY"];
                    sv.Cells[i, (int)PROD_PLAN_INFO.PLAN_D].Value = dt.Rows[i]["PLAN_D"];
                    sv.Cells[i, (int)PROD_PLAN_INFO.PLAN_DATE].Value = dt.Rows[i]["PLAN_DATE"];
                    sv.Cells[i, (int)PROD_PLAN_INFO.AREA_CODE].Value = dt.Rows[i]["AREA_ID"];
                    sv.Cells[i, (int)PROD_PLAN_INFO.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                    sv.Cells[i, (int)PROD_PLAN_INFO.SUB_AREA_CODE].Value = dt.Rows[i]["SUB_AREA_ID"];
                    sv.Cells[i, (int)PROD_PLAN_INFO.SUB_AREA_DESC].Value = dt.Rows[i]["SUB_AREA_DESC"];
                    sv.Cells[i, (int)PROD_PLAN_INFO.OPER_CODE].Value = dt.Rows[i]["OPER"];
                    sv.Cells[i, (int)PROD_PLAN_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    sv.Cells[i, (int)PROD_PLAN_INFO.MAT_CODE].Value = dt.Rows[i]["MAT_ID"];
                    sv.Cells[i, (int)PROD_PLAN_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    sv.Cells[i, (int)PROD_PLAN_INFO.QTY].Value = dt.Rows[i]["QTY"];
                    sv.Cells[i, (int)PROD_PLAN_INFO.UNIT].Value = dt.Rows[i]["UNIT"];

                    if(i != 0)
                    {
                        if (sv.Cells[i, (int)PROD_PLAN_INFO.PLAN_DATE].Text == sv.Cells[i-1, (int)PROD_PLAN_INFO.PLAN_DATE].Text)
                        {
                            spdProdPlan.ActiveSheet.Cells[i, (int)PROD_PLAN_INFO.PLAN_DY, i, spdProdPlan.ActiveSheet.ColumnCount-1].BackColor = spdProdPlan.ActiveSheet.Cells[i-1, (int)PROD_PLAN_INFO.PLAN_DY, i-1, spdProdPlan.ActiveSheet.ColumnCount-1].BackColor;
                        }
                        else
                        {
                            if (spdProdPlan.ActiveSheet.Cells[i-1, (int)PROD_PLAN_INFO.PLAN_DY].BackColor == Color.WhiteSmoke)
                            {
                                spdProdPlan.ActiveSheet.Cells[i, (int)PROD_PLAN_INFO.PLAN_DY, i, spdProdPlan.ActiveSheet.ColumnCount-1].BackColor = Color.White;
                            }
                            else
                            {
                                spdProdPlan.ActiveSheet.Cells[i, (int)PROD_PLAN_INFO.PLAN_DY, i, spdProdPlan.ActiveSheet.ColumnCount-1].BackColor = Color.WhiteSmoke;
                            }
                        }
                    }


                    
                    if (dt.Rows[i]["HOLIDAY_YN"].ToString() == "Y")
                    {

                        spdProdPlan.ActiveSheet.Cells[i, (int)PROD_PLAN_INFO.PLAN_DY, i, (int)PROD_PLAN_INFO.PLAN_D].ForeColor = Color.Red;

                    }
                    else
                    {

                    }
                    


                }

               // MPCF.FitColumnHeader(spdProdPlan);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                int iCheckCount = 0;
                SheetView sv = spdProdPlan.ActiveSheet;

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        if (string.IsNullOrEmpty(MPCF.Trim(cdvDept.Text)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
                            return false;
                        }

                        /* if (string.IsNullOrEmpty(MPCF.Trim(cdvOper.Text)))
                         {
                             MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                             cdvOper.Focus();
                             return false;
                         }*/

                        if (string.IsNullOrEmpty(MPCF.Trim(dtpFrDate.Text)))
                         {
                             MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDate.Text + "]");
                             dtpFrDate.Focus();
                             return false;
                         }


                        if (string.IsNullOrEmpty(MPCF.Trim(dtpToDate.Text)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDate.Text + "]");
                            dtpToDate.Focus();
                            return false;
                        }



                        /*if (string.IsNullOrEmpty(MPCF.Trim(cdvMatid.Text)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMatId.Text + "]");
                            cdvMatid.Focus();
                            return false;
                        }*/
                        break;

                    case CSGC.CHECK.SAVE:
                        if (sv.RowCount <= 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(465));
                            return false;
                        }
                        else
                        {
                            for (int i = 0; i < sv.RowCount; i++)
                            {
                                if (Convert.ToBoolean(sv.Cells[i, (int)PROD_PLAN_INFO.CHECK] == null ? false : sv.Cells[i, (int)PROD_PLAN_INFO.CHECK].Value))
                                {
                                    //사업부 검사
                                    if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.AREA_CODE].Value)))
                                    {
                                        MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                        sv.SetActiveCell(i, (int)PROD_PLAN_INFO.AREA_CODE);
                                        return false;
                                    }
                                    //작업장 검사
                                    if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.SUB_AREA_CODE].Value)))
                                    {
                                        MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                        sv.SetActiveCell(i, (int)PROD_PLAN_INFO.SUB_AREA_CODE);
                                        return false;
                                    }

                                    //공정 검사
                                    if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.OPER_CODE].Value)))
                                    {
                                        MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                        sv.SetActiveCell(i, (int)PROD_PLAN_INFO.OPER_CODE);
                                        return false;
                                    }



                                    //20210716 품목입력 제거 *로 대처
                                    /*
                                    if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.PLAN_DATE].Value)))
                                    {
                                        MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                        sv.SetActiveCell(i, (int)PROD_PLAN_INFO.PLAN_DATE);
                                        return false;
                                    }

                                    if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.MAT_CODE].Value)))
                                    {
                                        MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                        sv.SetActiveCell(i, (int)PROD_PLAN_INFO.MAT_CODE);
                                        return false;
                                    }
                                    */

                                    iCheckCount++;
                                }
                            }

                          

                            if (iCheckCount <= 0)
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(466));
                                return false;
                            }
                        }
                        break;

                    case CSGC.CHECK.DELETE:
                        if (sv.RowCount <= 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(465));
                            return false;
                        }
                        else
                        {
                            for (int i = 0; i < sv.RowCount; i++)
                            {
                                //체크항목만 확인
                                if (Convert.ToBoolean(sv.Cells[i, (int)PROD_PLAN_INFO.CHECK] == null ? false : sv.Cells[i, (int)PROD_PLAN_INFO.CHECK].Value))
                                {
                                    iCheckCount++;
                                }
                            }

                            if (iCheckCount <= 0)
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(466));
                                return false;
                            }
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
        private void UploadExcel()
        {

            MExcel.Application XApp = null;
            MExcel.Workbooks XBooks = null;
            MExcel.Workbook XBook = null;
            MExcel.Worksheet XSheet = null;
            MExcel.Sheets XSheets = null;

            OpenFileDialog ofdFile = new OpenFileDialog();

            try
            {
                ofdFile.Filter = "Excel Files(*.xls;*.xlsx)|*.xls;*.xlsx";
                ofdFile.DefaultExt = "xls,xlsx";

                if (ofdFile.ShowDialog() != DialogResult.OK)
                    return;

                XApp = new MExcel.Application();
                XApp.Interactive = false;
                XBooks = XApp.Workbooks;
                XBook = XBooks.Open(ofdFile.FileName);

                ((Excel.Worksheet)XBook.Sheets[1]).Select();

                XSheets = XBook.Worksheets;
                XSheet = XSheets.get_Item(1) as MExcel.Worksheet;

                //시트에서 사용된 셀범위
                MExcel.Range range = XSheet.UsedRange;

                //2차원 배열에 담기
                Object[,] data = range.Value;
                int row_count = range.Rows.Count;

                for (int i = 2; i <= row_count; i++)
                {
                    /*
                    spdProdPlan.ActiveSheet.RowCount++;
                    spdProdPlan.ActiveSheet.SetValue(i - 2, (int)PROD_PLAN_INFO.CHECK, true);
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.AREA_CODE].Value = data[i, (int)PROD_PLAN_INFO.AREA_CODE + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.AREA_DESC].Value = data[i, (int)PROD_PLAN_INFO.AREA_DESC + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.SUB_AREA_CODE].Value = data[i, (int)PROD_PLAN_INFO.SUB_AREA_CODE + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.SUB_AREA_DESC].Value = data[i, (int)PROD_PLAN_INFO.SUB_AREA_DESC + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.OPER_CODE].Value = data[i, (int)PROD_PLAN_INFO.OPER_CODE + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.OPER_DESC].Value = data[i, (int)PROD_PLAN_INFO.OPER_DESC + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.PLAN_DATE].Value = data[i, (int)PROD_PLAN_INFO.PLAN_DATE + 1].ToString().Substring(0, 4) + "-" + data[i, (int)PROD_PLAN_INFO.PLAN_DATE + 1].ToString().Replace("-", "").Substring(4, 2) + "-" + data[i, (int)PROD_PLAN_INFO.PLAN_DATE + 1].ToString().Replace("-", "").Substring(6, 2);
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.MAT_CODE].Value = data[i, (int)PROD_PLAN_INFO.MAT_CODE + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.MAT_DESC].Value = data[i, (int)PROD_PLAN_INFO.MAT_DESC + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.QTY].Value = data[i, (int)PROD_PLAN_INFO.QTY + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.UNIT].Value = data[i, (int)PROD_PLAN_INFO.UNIT + 1];
                    */



                    spdProdPlan.ActiveSheet.RowCount++;

                    if(data[i, (int)PROD_PLAN_INFO.QTY + 1] != null )
                    {
                        if (data[i, (int)PROD_PLAN_INFO.QTY + 1].ToString() == "0" || data[i, (int)PROD_PLAN_INFO.QTY + 1].ToString() == " " || data[i, (int)PROD_PLAN_INFO.QTY + 1].ToString().Length == 0 || data[i, (int)PROD_PLAN_INFO.QTY + 1].ToString() == "\n" || data[i, (int)PROD_PLAN_INFO.QTY + 1].ToString() == "")
                        {
                            spdProdPlan.ActiveSheet.SetValue(i - 2, (int)PROD_PLAN_INFO.CHECK, false);
                        }
                        else
                        {
                            spdProdPlan.ActiveSheet.SetValue(i - 2, (int)PROD_PLAN_INFO.CHECK, true);
                        }
                    }
                    else
                    {
                        spdProdPlan.ActiveSheet.SetValue(i - 2, (int)PROD_PLAN_INFO.CHECK, false);
                    }
                  
              

                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.PLAN_WW].Value = data[i, (int)PROD_PLAN_INFO.PLAN_WW + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.PLAN_DY].Value = data[i, (int)PROD_PLAN_INFO.PLAN_DY + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.PLAN_D].Value = data[i, (int)PROD_PLAN_INFO.PLAN_D + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.PLAN_DATE].Value = data[i, (int)PROD_PLAN_INFO.PLAN_DATE + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.AREA_CODE].Value = data[i, (int)PROD_PLAN_INFO.AREA_CODE + 1];
                    //   spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.AREA_BUTTON].Value = data[i, (int)PROD_PLAN_INFO.AREA_BUTTON + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.AREA_DESC].Value = data[i, (int)PROD_PLAN_INFO.AREA_DESC + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.SUB_AREA_CODE].Value = data[i, (int)PROD_PLAN_INFO.SUB_AREA_CODE + 1];
                    //   spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.SUB_AREA_BUTTON].Value = data[i, (int)PROD_PLAN_INFO.SUB_AREA_BUTTON + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.SUB_AREA_DESC].Value = data[i, (int)PROD_PLAN_INFO.SUB_AREA_DESC + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.OPER_CODE].Value = data[i, (int)PROD_PLAN_INFO.OPER_CODE + 1];
                    //   spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.OPER_BUTTON].Value = data[i, (int)PROD_PLAN_INFO.OPER_BUTTON + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.OPER_DESC].Value = data[i, (int)PROD_PLAN_INFO.OPER_DESC + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.MAT_CODE].Value = "*";
                    //    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.MAT_BUTTON].Value = data[i, (int)PROD_PLAN_INFO.MAT_BUTTON + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.MAT_DESC].Value = "*";
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.QTY].Value = data[i, (int)PROD_PLAN_INFO.QTY + 1];
                    spdProdPlan.ActiveSheet.Cells[i - 2, (int)PROD_PLAN_INFO.UNIT].Value = data[i, (int)PROD_PLAN_INFO.UNIT + 1];


                }

                XBook.Close(true);
                XApp.Quit();

                MPCF.ShowMsgBox(MPCF.GetMessage(52));
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
            finally
            {
                ReleasExcelObject(XSheet);
                ReleasExcelObject(XBook);
                ReleasExcelObject(XApp);
            }
        }
        private void ReleasExcelObject(object obj)
        {
            try
            {
                if (obj != null)
                {
                    System.Runtime.InteropServices.Marshal.ReleaseComObject(obj);
                    obj = null;
                }
            }
            catch (Exception ex)
            {
                obj = null;
                throw ex;
            }
            finally
            {
                GC.Collect();
            }
        }

        // 작업자 목록 정보로 저장
        private bool SaveProdPlanInfo()
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode prod_plan_list;
                int iCheckCount = 0;
                SheetView sv = spdProdPlan.ActiveSheet;

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';

                iCheckCount = 0;

                for (int i = 0; i < sv.RowCount; i++)
                {
                    if (Convert.ToBoolean(sv.Cells[i, (int)PROD_PLAN_INFO.CHECK] == null ? false : sv.Cells[i, (int)PROD_PLAN_INFO.CHECK].Value))
                    {
                        //사업부 검사
                        if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.AREA_CODE].Value)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            spdProdPlan.ActiveSheet.SetActiveCell(i, (int)PROD_PLAN_INFO.AREA_CODE);
                            return false;
                        }

                        //공정 검사
                        if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.OPER_CODE].Value)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            spdProdPlan.ActiveSheet.SetActiveCell(i, (int)PROD_PLAN_INFO.OPER_CODE);
                            return false;
                        }

                        //날짜 검사
                        if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.PLAN_DATE].Value)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            spdProdPlan.ActiveSheet.SetActiveCell(i, (int)PROD_PLAN_INFO.PLAN_DATE);
                            return false;
                        }

                        /*
                        //품목검사
                        if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.MAT_CODE].Value)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            spdProdPlan.ActiveSheet.SetActiveCell(i, (int)PROD_PLAN_INFO.MAT_CODE);
                            return false;
                        }
                        */

                        /*
                        //수량검사
                        if (MPCF.ToDbl(sv.Cells[i, (int)PROD_PLAN_INFO.QTY].Value) <= 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            sv.SetActiveCell(i, (int)PROD_PLAN_INFO.QTY);
                            return false;
                        }
                        */

                        prod_plan_list = in_node.AddNode("DATA_LIST");

                        prod_plan_list.AddString("AREA_ID", MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.AREA_CODE].Value));
                        prod_plan_list.AddString("OPER", MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.OPER_CODE].Value));
                        prod_plan_list.AddString("MAT_ID", MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.MAT_CODE].Value));

                        //20210716 품목입력 사실상 의미가 없어서 제거 나중에 쓸줄 모르니...히든만 시키고 품목컬럼에 *넣어줌
                        if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.MAT_CODE].Value)))
                        {
                            prod_plan_list.AddString("MAT_ID", "*");
                        }
                        else
                        {
                            prod_plan_list.AddString("MAT_ID", MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.MAT_CODE].Value));
                        }

                        prod_plan_list.AddString("PLAN_DATE", MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.PLAN_DATE].Text).Replace("-", ""));


                        //20210716 DELETE 버튼를 없에고 수량수정하는것으로 UPDATE되는것으로 변경.
                        if (MPCF.ToDbl(sv.Cells[i, (int)PROD_PLAN_INFO.QTY].Value) <= 0)
                        {
                            prod_plan_list.AddDouble("QTY", 0);
                        }
                        else
                        {
                            prod_plan_list.AddDouble("QTY", MPCF.ToDbl(sv.Cells[i, (int)PROD_PLAN_INFO.QTY].Value));
                        }


                        iCheckCount++;
                    }
                }

                if (iCheckCount > 0)
                {
                    if (MPCR.CallService("CUS_ORD", "CUS_ORD_Prod_Plan_Registration", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                }
                else
                {
                    //체크항목이 존재하지 않습니다. 확인해주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(465));
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        // 선택된 작업자 삭제
        private bool DeleteProdPlanInfo()
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode prod_plan_list;
                SheetView sv = spdProdPlan.ActiveSheet;
                int iCheckCount = 0;

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '2';

                iCheckCount = 0;

                for (int i = 0; i < sv.RowCount; i++)
                {
                    //사업부 검사
                    if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.AREA_CODE].Value)))
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(108));
                        spdProdPlan.ActiveSheet.SetActiveCell(i, (int)PROD_PLAN_INFO.AREA_CODE);
                        return false;
                    }

                    //공정 검사
                    if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.OPER_CODE].Value)))
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(108));
                        spdProdPlan.ActiveSheet.SetActiveCell(i, (int)PROD_PLAN_INFO.OPER_CODE);
                        return false;
                    }

                    //날짜 검사
                    if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.PLAN_DATE].Value)))
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(108));
                        spdProdPlan.ActiveSheet.SetActiveCell(i, (int)PROD_PLAN_INFO.PLAN_DATE);
                        return false;
                    }

                    /*
                    //품목검사
                    if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.MAT_CODE].Value)))
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(108));
                        spdProdPlan.ActiveSheet.SetActiveCell(i, (int)PROD_PLAN_INFO.MAT_CODE);
                        return false;
                    }
                    */

                    /*
                    //수량검사
                    if (MPCF.ToDbl(sv.Cells[i, (int)PROD_PLAN_INFO.QTY].Value) <= 0)
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(108));
                        spdProdPlan.ActiveSheet.SetActiveCell(i, (int)PROD_PLAN_INFO.QTY);
                        return false;
                    }
                    */

                    if (Convert.ToBoolean(sv.Cells[i, (int)PROD_PLAN_INFO.CHECK] == null ? false : sv.Cells[i, (int)PROD_PLAN_INFO.CHECK].Value))
                    {
                        prod_plan_list = in_node.AddNode("DATA_LIST");

                        prod_plan_list.AddString("AREA_ID", MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.AREA_CODE].Value));
                        prod_plan_list.AddString("OPER", MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.OPER_CODE].Value));
                        prod_plan_list.AddString("MAT_ID", MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.MAT_CODE].Value));
                        prod_plan_list.AddString("PLAN_DATE", MPCF.Trim(sv.Cells[i, (int)PROD_PLAN_INFO.PLAN_DATE].Text).Replace("-", ""));

                        iCheckCount++;
                    }
                }

                if (iCheckCount > 0)
                {
                    if (MPCR.CallService("CUS_ORD", "CUS_ORD_Prod_Plan_Registration", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                }
                else
                {
                    //체크항목이 존재하지 않습니다. 확인해주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(465));
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

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewProdPlanList();


                totalplan();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnRowAdd_Click(object sender, EventArgs e)
        {
            SheetView sv = spdProdPlan.ActiveSheet;
            int iRow = sv.RowCount;

            try
            {
                sv.RowCount++;
                sv.Cells[iRow, (int)PROD_PLAN_INFO.CHECK].Value = true;
                sv.Cells[iRow, (int)PROD_PLAN_INFO.AREA_CODE].Value = cdvDept.Text;
                sv.Cells[iRow, (int)PROD_PLAN_INFO.AREA_DESC].Value = cdvDept.DisplayText;
                sv.Cells[iRow, (int)PROD_PLAN_INFO.SUB_AREA_CODE].Value = cdvWorkPlace.Text;
                sv.Cells[iRow, (int)PROD_PLAN_INFO.SUB_AREA_DESC].Value = cdvWorkPlace.DisplayText;
                sv.Cells[iRow, (int)PROD_PLAN_INFO.OPER_CODE].Value = cdvOper.Text;
                sv.Cells[iRow, (int)PROD_PLAN_INFO.OPER_DESC].Value = cdvOper.DisplayText;
                sv.Cells[iRow, (int)PROD_PLAN_INFO.PLAN_DATE].Value = DateTime.Now.ToShortDateString();//dtpFrDate.Text;
                sv.Cells[iRow, (int)PROD_PLAN_INFO.MAT_CODE].Value = cdvMatid.Text;
                sv.Cells[iRow, (int)PROD_PLAN_INFO.MAT_DESC].Value = cdvMatid.DisplayText;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnRowDel_Click(object sender, EventArgs e)
        {
            SheetView sv = spdProdPlan.ActiveSheet;

            try
            {
                for (int i = sv.RowCount - 1; i >= 0; i--)
                {
                    if (Convert.ToBoolean(sv.Cells[i, (int)PROD_PLAN_INFO.CHECK] == null ? false : sv.Cells[i, (int)PROD_PLAN_INFO.CHECK].Value))
                    {
                        sv.RemoveRows(i, 1);
                    }
                }
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
                {
                    return;
                }

                // 작업자 목록 정보로 저장
                if (SaveProdPlanInfo())
                {
                    ViewProdPlanList();

                    MPCF.ShowMsgBox(MPCF.GetMessage(52));
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.DELETE) == false)
                {
                    return;
                }

                DialogResult dr = MessageBox.Show(MPCF.GetMessage(453), "Info", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);

                if (dr == DialogResult.OK)
                {
                    if (DeleteProdPlanInfo())
                    {
                        ViewProdPlanList();

                        MPCF.ShowMsgBox(MPCF.GetMessage(52));
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                {
                    return;
                }

                // 작업자 목록 정보로 저장
                if (SaveProdPlanInfo())
                {
                    ViewProdPlanList();

                    MPCF.ShowMsgBox(MPCF.GetMessage(52));
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void spdProdPlan_KeyDown(object sender, KeyEventArgs e)
        {
            try
            {
                if (e.Control && e.KeyCode == Keys.V)
                {
                    SheetView sv = spdProdPlan.ActiveSheet;
                    int iActiveRow = sv.ActiveRowIndex;

                    if (iActiveRow < 0)
                        return;

                    //줄바꿈을 자르고 마지막은 빈값이므로 포함안시킴ㄴ
                    string[] rowSeparators = new string[] { "\r\n" };
                    string sClipboard = Clipboard.GetText();
                    string[] sList = sClipboard.Split(rowSeparators, StringSplitOptions.None);

                    for (int i = 0; i < sList.Length - 1; i++)
                    {
                        //이제 열로 구분된 값을 다시 잘라서 각 ROW에 넣어준다.
                        string[] columnSeparators = new string[] { "\t" };

                        string[] sColumnList = sList[i].Split(columnSeparators, StringSplitOptions.None);

                        //체크박스 선택
                        sv.Cells[iActiveRow, 0].Value = true;

                        int c = 1;

                        for (int j = 0; j < sColumnList.Length; j++)
                        {
                            if (j == 1 || j == 3 || j == 5 || j == 8)
                            {
                                c++;
                            }
                            sv.Cells[iActiveRow, c + j].Value = sColumnList[j];

                        }

                        iActiveRow++;
                        sv.RowCount++;
                    }

                    sv = spdProdPlan.ActiveSheet;

                    sv.RemoveRows(iActiveRow, (sv.RowCount - iActiveRow - 1) == 0 ? 1 : (sv.RowCount - iActiveRow - 1));

                    if (sv.RowCount - iActiveRow - 1 != 0)
                    {
                        sv.RowCount++;
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

            e.Handled = true;
        }

        private void cdvMatid_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatid.DisplayText == "")
                cdvMatid.Text = "";
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                /*
                spdProdPlan.ActiveSheet.Columns.Get((int)PROD_PLAN_INFO.CHECK).Visible = false;
                spdProdPlan.ActiveSheet.Columns.Get((int)PROD_PLAN_INFO.AREA_BUTTON).Visible = false;
                spdProdPlan.ActiveSheet.Columns.Get((int)PROD_PLAN_INFO.SUB_AREA_BUTTON).Visible = false;
                spdProdPlan.ActiveSheet.Columns.Get((int)PROD_PLAN_INFO.OPER_BUTTON).Visible = false;
                spdProdPlan.ActiveSheet.Columns.Get((int)PROD_PLAN_INFO.MAT_BUTTON).Visible = false;
                */
                EXTFUC.SaveExcel(spdProdPlan, "OrderPlan");
                /*
                spdProdPlan.ActiveSheet.Columns.Get((int)PROD_PLAN_INFO.CHECK).Visible = true;
                spdProdPlan.ActiveSheet.Columns.Get((int)PROD_PLAN_INFO.AREA_BUTTON).Visible = true;
                spdProdPlan.ActiveSheet.Columns.Get((int)PROD_PLAN_INFO.SUB_AREA_BUTTON).Visible = true;
                spdProdPlan.ActiveSheet.Columns.Get((int)PROD_PLAN_INFO.OPER_BUTTON).Visible = true;
                spdProdPlan.ActiveSheet.Columns.Get((int)PROD_PLAN_INFO.MAT_BUTTON).Visible = true;
                */

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void btnUploadExcel_Click(object sender, EventArgs e)
        {

            try
            {
                MPCF.ClearList(spdProdPlan);
                UploadExcel();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void pnlBottom_Paint(object sender, PaintEventArgs e)
        {

        }

        private void spdProdPlan_EditModeStarting(object sender, EditModeStartingEventArgs e)
        {
            if (spdProdPlan_Sheet1.ActiveColumnIndex != 0)
                spdProdPlan_Sheet1.Cells[spdProdPlan_Sheet1.ActiveRowIndex, (int)PROD_PLAN_INFO.CHECK].Value = true;
        }

        private void cdvPlanOper_ButtonPress(object sender, EventArgs e)
        {
            viewOperList(cdvPlanOper.GetListView);
            cdvPlanOper.InsertEmptyRow(0, 1);
        }
        
        private bool viewOperList(ListView listView)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';


            in_node.AddString("SQL", "SELECT KEY_2 AS CODE, DATA_1 AS VALUE "
                                                + "   FROM MGCMTBLDAT   WHERE TABLE_NAME ='C_PLAN_OPER' AND KEY_1 ='" + cdvDept.Text +  "' ORDER BY DATA_2 ");


            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return false;
                }

                MPCR.FillDataView(listView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));

            } while (out_node.GetInt("NEXT_ROW") > 0);


            return true;
        }

        private void chkMerge_CheckedChanged(object sender, EventArgs e)
        {

            if(chkMerge.Checked == true)
            {
                sheetMergePolicy("Y");
            }
            else
            {
                sheetMergePolicy("N");
            }

        }

        private void sheetMergePolicy(string sYn)
        {
            if (sYn == "Y")
            {
                spdProdPlan.ActiveSheet.Columns.Get((int)PROD_PLAN_INFO.PLAN_WW).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdProdPlan.ActiveSheet.Columns.Get((int)PROD_PLAN_INFO.PLAN_DY).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdProdPlan.ActiveSheet.Columns.Get((int)PROD_PLAN_INFO.PLAN_D).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Restricted;
                spdProdPlan.ActiveSheet.Columns.Get((int)PROD_PLAN_INFO.PLAN_DATE).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;

            }
            else
            {
                spdProdPlan.ActiveSheet.Columns.Get((int)PROD_PLAN_INFO.PLAN_WW).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.None;
                spdProdPlan.ActiveSheet.Columns.Get((int)PROD_PLAN_INFO.PLAN_DY).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.None;
                spdProdPlan.ActiveSheet.Columns.Get((int)PROD_PLAN_INFO.PLAN_D).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.None;
                spdProdPlan.ActiveSheet.Columns.Get((int)PROD_PLAN_INFO.PLAN_DATE).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.None;
            }
        }




        #region " Favorite add "
        //20210712 즐겨찾기 추가
        private void chkFavorite2_CheckedChanged(object sender, EventArgs e)
        {
            if (chkFavorite2.Checked == true)
            {
                Update_Favorites(MPGC.MP_STEP_CREATE);
            }
            else
            {
                Update_Favorites(MPGC.MP_STEP_DELETE);
            }

            //Add by J.S. 2009.02.13
            //favorites수정시 LotListMain, ResourceListMain시 submenu를 refresh하기위한 변수 
            MPGV.gbFavoriteChangeForLotListMain = true;
            MPGV.gbFavoriteChangeForResourceListMain = true;

            MPGV.gIMdiForm.FavoritesRefresh();
        }



        private void FuncNameSearch(ref DataTable dt, char cStep_Flag)
        {
            try
            {


                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "FUNC_NAME";
                dvcArgu[1].sCondition_Value = this.Name.ToString();



                dvcArgu[2].sCondition_ID = "PROGRAM_ID";
                dvcArgu[2].sCondition_Value = MPGV.gsProgramID;

                dvcArgu[3].sCondition_ID = "USER_ID";
                dvcArgu[3].sCondition_Value = MPGV.gsUserID;


                if (TPDR.GetDataOne("", ref dt, "BAS-03", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    if (cStep_Flag != MPGC.MP_STEP_CREATE && cStep_Flag != MPGC.MP_STEP_DELETE)
                    {
                        chkFavorite2.Checked = false;
                    }
                    return;
                }

                if (cStep_Flag != MPGC.MP_STEP_CREATE && cStep_Flag != MPGC.MP_STEP_DELETE)
                {
                    if (MPCF.ToInt(dt.Rows[0]["INSERT_YN"]) > 0)
                    {
                        chkFavorite2.Checked = true;
                    }
                    else
                    {
                        chkFavorite2.Checked = false;
                    }
                }


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void Update_Favorites(char cStep_Flag)
        {
            try
            {

                string sPgmID = MPGV.gsProgramID;
                DataTable dt = null;

                TRSNode in_node = new TRSNode("UPDATE_FAVORITES_IN");
                TRSNode out_node = new TRSNode("CMN_OUT");

                //System.Windows.Forms.ColumnHeader;



                FuncNameSearch(ref dt, cStep_Flag);

                //MPGC.MP_STEP_DELETE
                //MPGC.MP_STEP_CREATE;

                if (cStep_Flag == MPGC.MP_STEP_CREATE && MPCF.ToInt(dt.Rows[0]["INSERT_YN"]) > 0)
                {
                    //이미 즐겨찾기 되어있음 리턴.
                    return;
                }

                if (cStep_Flag == MPGC.MP_STEP_DELETE && MPCF.ToInt(dt.Rows[0]["INSERT_YN"]) == 0)
                {
                    //이미 즐겨찾기 없음 리턴.
                    return;
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = cStep_Flag;
                in_node.AddString("PROGRAM_ID", sPgmID);
                in_node.AddInt("SEQ_NUM", MPCF.ToInt(dt.Rows[0]["SEQ_NUM"]));
                in_node.AddString("FUNC_NAME", dt.Rows[0]["FUNC_NAME"]);
                in_node.AddString("USER_FUNC_DESC", dt.Rows[0]["USER_FUNC_DESC"]);



                if (MPCR.CallService("SEC", "SEC_Update_Favorites", in_node, ref out_node) == false)
                {
                    return;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }
        #endregion

        private void btnGCM_Click(object sender, EventArgs e)
        {
            try
            {

                frmPopGcmData popup = new frmPopGcmData();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sTable_name = "C_PLAN_OPER";

                if (MPGV.gcLanguage == '2')
                {
                    popup.sTable_name_desc = "생산계획공정 등록";
                    popup.sComment = "";

                }
                else
                {
                    popup.sTable_name_desc = "OPERATION PLAN INSERT";
                    popup.sComment = "";

                }


                if (popup.ShowDialog() == DialogResult.OK)
                {

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

        private void cdvPlanOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            MPCF.ClearList(spdProdPlan);
        }

        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            MPCF.ClearList(spdProdPlan);
            cdvPlanOper.Text = "";
        }


        private void totalplan()
        {

                SheetView sv = spdProdPlan.ActiveSheet;

                TRSNode in_node = new TRSNode("SQL_IN");
                TRSNode out_node = new TRSNode("SQL_OUT");

                txtOperCount.Text = "(" + dtpFrDate.Text + " ~ " + dtpToDate.Text + ") ";

                //   MPCF.InitListView(listView);

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';


                in_node.AddString("SQL", "SELECT DATA_1 AS CODE, DATA_1 AS VALUE "
                                                    + "   FROM MGCMTBLDAT   WHERE TABLE_NAME ='C_PLAN_OPER' AND KEY_1 ='" + cdvDept.Text + "' ORDER BY DATA_2 ");


                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                        return;
                }
       
                 //   data_list = out_node.GetList("DATA_LIST");

                string[,] iOplist = new string[out_node.GetList("ROWS").Count, 2];

                for (int iOp = 0; iOp < out_node.GetList("ROWS").Count; iOp++)
                {
                //  iOplist[iOp,0] = out_node.GetList("ROWS")[iOp].GetString("NEXT_ROW");

                iOplist[iOp, 0] = out_node.GetList("ROWS")[iOp].GetList("COLS")[0].GetString("DATA");
                iOplist[iOp, 1] = "0";

                for (int i = 0; i < sv.RowCount; i++)
                    {
                        if(sv.Cells[i, (int)PROD_PLAN_INFO.OPER_DESC].Text == iOplist[iOp, 0].ToString())
                        {
                            //Convert.ToInt32(sv.Cells[i, (int)PROD_PLAN_INFO.QTY].Value
                            if(MPCF.ToDbl(sv.Cells[i, (int)PROD_PLAN_INFO.QTY].Value) > 0) 
                            {
                                iOplist[iOp, 1] = Convert.ToString(Convert.ToDouble(iOplist[iOp, 1].ToString()) + Convert.ToDouble(sv.Cells[i, (int)PROD_PLAN_INFO.QTY].Value));

                            }

                        }

                    }

                    txtOperCount.Text = txtOperCount.Text + " //  " + iOplist[iOp, 0] + ": " + iOplist[iOp, 1];
                }







            }
    }
}
