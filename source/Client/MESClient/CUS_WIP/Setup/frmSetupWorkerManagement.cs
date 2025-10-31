using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MExcel = Microsoft.Office.Interop.Excel;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;

namespace CUS_WIP
{
    public partial class frmSetupWorkerManagement : CUS_COM.frmTranForm05
    {
        public frmSetupWorkerManagement()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        // 작업자 정보
        private enum WORKER_INFO : int
        {
            CHECK,                  // 1 : 선택
            WORKER_ID,              // 2 : 사번
            WORKER_DESC,            // 3 : 작업자 명
            AREA_ID,                // 4 : 사업부 코드
            AREA_DESC,              // 5 : 사업부명
            AREA_SELECT,            // 6 : 사업부 버튼
            DEPT_CODE,              // 10: 부서정보코드  
            DEPT_DESC,              // 11: 부서정보명      
            DEPT_SELECT,            // 12: 부서정보 버튼        
        }

        //Excel 작업자 정보
        private enum WORKER_EXCEL : int
        {
            WORKER_ID,              // 1 : 사번
            WORKER_DESC,            // 2 : 작업자 명
            AREA_DESC,              // 3 : 사업부명
            DEPT_CODE,              // 6 : 부서정보코드  
            DEPT_DESC               // 7 : 부서정보명            
        }

        #endregion

        #region " Variable Definition "

        int worker_row = 0;
   
        int check_cnt = 0; 

        #endregion

        #region " Function Defintion "

        private void InitControl()
        {
            try
            {
                btnExcel.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                btnUploadExcel.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnDelete.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //초기화
        private void ClearList(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "EXCEL_DOWNLOAD":
                        break;

                    case "EXCEL_UPLOAD":
                        MPCF.ClearList(spdWorker);

                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewWorkerList()
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CWIP1001-001";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "DEPT_CODE";
                dvcArgu[2].sCondition_Value = cdvDeptCode.Text;

                MPCF.ClearList(spdWorker);

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdWorker_Sheet1.RowCount++;

                    spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_ID].Value = dt.Rows[i]["WORKER_ID"];
                    spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_DESC].Value = dt.Rows[i]["WORKER_DESC"];
                    spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                    spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.DEPT_CODE].Value = dt.Rows[i]["DEPT_CODE"];
                    spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.DEPT_DESC].Value = dt.Rows[i]["DEPT_DESC"];
                }
                MPCF.FitColumnHeader(spdWorker);
                worker_row = spdWorker_Sheet1.RowCount;

                return;
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

                    case CSGC.CHECK.SAVE:
                        break;

                    case CSGC.CHECK.DELETE:
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

        private bool CheckRow(int row)
        {
            try
            { 
                if (spdWorker_Sheet1.Cells[row, (int)WORKER_INFO.WORKER_ID].Text.Trim() == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                    spdWorker.ActiveSheet.SetActiveCell(row, (int)WORKER_INFO.WORKER_ID);
                    return false;
                }
                if (spdWorker_Sheet1.Cells[row, (int)WORKER_INFO.WORKER_DESC].Text.Trim() == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                    spdWorker.ActiveSheet.SetActiveCell(row, (int)WORKER_INFO.WORKER_DESC);
                    return false;
                }   
                if (spdWorker_Sheet1.Cells[row, (int)WORKER_INFO.AREA_DESC].Text.Trim() == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                    spdWorker.ActiveSheet.SetActiveCell(row, (int)WORKER_INFO.AREA_DESC);
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

        // 작업자 목록 정보로 저장
        private bool SaveWorkerInfo()
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode worker_list;

                MPCR.SetInMsg(in_node);
               
                in_node.ProcStep = '1';

                check_cnt = 0;

                for (int i = 0; i < spdWorker_Sheet1.RowCount; i++)
                {
                    if (spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.CHECK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (CheckRow(i))
                        {
                            worker_list = in_node.AddNode("WORKER_LIST");

                            worker_list.AddString("AREA_ID", spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.AREA_ID].Text.Trim());
                            worker_list.AddString("WORKER_ID", spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_ID].Text.Trim());
                            worker_list.AddString("WORKER_DESC", spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_DESC].Text.Trim());
                            worker_list.AddString("DEPT_CODE", spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.DEPT_CODE].Text);

                            check_cnt++;
                        }
                        else
                        {
                            return false;
                        }
                    }  
                }

                if (check_cnt > 0)
                {
                    if (MPCR.CallService("CUS_WIP", "CUS_WIP_Worker_Management", in_node, ref out_node) == false)
                    {
                        return false;
                    }
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
        private bool DeleteWorkerList()
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode worker_list;

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '2';

                check_cnt = 0; 

                for (int i = 0; i < spdWorker_Sheet1.RowCount; i++)
                {
                    if (spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.CHECK].Text.ToString().ToUpper() == "TRUE")
                    {
                        worker_list = in_node.AddNode("WORKER_LIST");

                        worker_list.AddString("WORKER_ID", spdWorker.ActiveSheet.Cells[i, (int)WORKER_INFO.WORKER_ID].Text.Trim());
                        check_cnt++;
                    }
                }

                if(check_cnt > 0)
                {
                    if (MPCR.CallService("CUS_WIP", "CUS_WIP_Worker_Management", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //엑셀 다운로드
        private void DownloadExcel()
        {
            int i=0, j = 0, k=0;
            try
            {          
                for(i =0;i<spdWorker_Sheet1.ColumnCount;i++)
                {
                    if(i==(int)WORKER_INFO.CHECK||i==(int)WORKER_INFO.AREA_ID|| 
                        i==(int)WORKER_INFO.AREA_SELECT||i==(int)WORKER_INFO.DEPT_SELECT)
                    {
                        continue;
                    }
                    
                    spdTemplate.ActiveSheet.ColumnHeader.Cells[j, k].Value = spdWorker_Sheet1.GetColumnLabel(j, i);
                    spdTemplate.ActiveSheet.ColumnHeader.Cells[j, k].BackColor = Color.Yellow;
                    k++;
                }

                for(i = 0;i<spdWorker.ActiveSheet.RowCount;i++)
                {
                    j = i;
                    spdTemplate_Sheet1.Cells[j, (int)WORKER_EXCEL.WORKER_ID].Value = spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_ID].Value;
                    spdTemplate_Sheet1.Cells[j, (int)WORKER_EXCEL.WORKER_DESC].Value = spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_DESC].Value;
                    spdTemplate_Sheet1.Cells[j, (int)WORKER_EXCEL.AREA_DESC].Value = spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.AREA_DESC].Value;
                    spdTemplate_Sheet1.Cells[j, (int)WORKER_EXCEL.DEPT_CODE].Value = spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.DEPT_CODE].Value;
                    spdTemplate_Sheet1.Cells[j, (int)WORKER_EXCEL.DEPT_DESC].Value = spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.DEPT_DESC].Value;
                }

                if (sfdFile.ShowDialog() == DialogResult.OK)
                {
                    spdTemplate.SaveExcelAndShow(sfdFile.FileName);
                }

            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //엑셀 업로드
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
                spdWorker_Sheet1.RowCount = row_count - 1;

                for (int i = 2; i <= row_count; i++)
                {
                    spdWorker_Sheet1.Cells[i - 2, (int)WORKER_INFO.CHECK].Value = true;
                    spdWorker_Sheet1.Cells[i - 2, (int)WORKER_INFO.WORKER_ID].Value = data[i, (int)WORKER_EXCEL.WORKER_ID+1];
                    spdWorker_Sheet1.Cells[i - 2, (int)WORKER_INFO.WORKER_DESC].Value = data[i, (int)WORKER_EXCEL.WORKER_DESC+1];
                    spdWorker_Sheet1.Cells[i - 2, (int)WORKER_INFO.AREA_DESC].Value = data[i, (int)WORKER_EXCEL.AREA_DESC+1];
                    spdWorker_Sheet1.Cells[i - 2, (int)WORKER_INFO.DEPT_CODE].Value = data[i, (int)WORKER_EXCEL.DEPT_CODE+1];
                    spdWorker_Sheet1.Cells[i - 2, (int)WORKER_INFO.DEPT_DESC].Value = data[i, (int)WORKER_EXCEL.DEPT_DESC+1];
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

        #endregion

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                {
                    return;
                }

                ViewWorkerList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnRowAdd_Click(object sender, EventArgs e)
        {
            int iRow = spdWorker_Sheet1.RowCount;
            FarPoint.Win.Spread.CellType.TextCellType cellType = new FarPoint.Win.Spread.CellType.TextCellType();

            try
            {
                cellType.ReadOnly = false;
                spdWorker_Sheet1.RowCount++;
                spdWorker_Sheet1.SetValue(iRow, (int)WORKER_INFO.CHECK, true);           
                spdWorker_Sheet1.Cells[iRow, (int)WORKER_INFO.WORKER_ID].CellType = cellType;
                spdWorker_Sheet1.Cells[iRow, (int)WORKER_INFO.AREA_ID].Value = cdvDept.Text;
                spdWorker_Sheet1.Cells[iRow, (int)WORKER_INFO.AREA_DESC].Value = cdvDept.DisplayText;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnRowDel_Click(object sender, EventArgs e)
        {
            try
            {
                for (int i = spdWorker.ActiveSheet.RowCount - 1; i >= worker_row; i--)
                {
                    if (spdWorker.ActiveSheet.Cells[i, (int)WORKER_INFO.CHECK].Text.ToString().ToUpper() == "TRUE")
                    {
                        spdWorker.ActiveSheet.RemoveRows(i, 1);
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
                if(SaveWorkerInfo())
                {
                    ViewWorkerList();

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
                    if (DeleteWorkerList())
                    {
                        ViewWorkerList();

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

        private void spdWorker_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                if (e.Column == (int)WORKER_INFO.AREA_SELECT ||e.Column == (int)WORKER_INFO.DEPT_SELECT)
                {
                    cdvGridButton.Init();
                    MPCF.InitListView(cdvGridButton.GetListView);
                    cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);
                    cdvGridButton.Columns.Add("Desc", 100, HorizontalAlignment.Left);

                    if (e.Column == (int)WORKER_INFO.AREA_SELECT)
                    {
                        //사업부 조회
                        if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                            return;
                    }                    
                    else if (e.Column == (int)WORKER_INFO.DEPT_SELECT)
                    {
                        //부서정보 조회
                        if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', CSGC.CP_GCM_DEPT_CODE) == false)
                        {
                            return;
                        }

                    }

                    cdvGridButton.ShowPopupList(e.Row, e.Column);
                    cdvGridButton.InsertEmptyRow(0, 1);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvGridButton_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (spdWorker.ActiveSheet.ActiveColumnIndex == (int)WORKER_INFO.AREA_SELECT)
                {
                    spdWorker_Sheet1.SetValue(e.Row, (int)WORKER_INFO.AREA_ID, e.SelectedItem.SubItems[0].Text);
                    spdWorker_Sheet1.SetValue(e.Row, (int)WORKER_INFO.AREA_DESC, e.SelectedItem.SubItems[1].Text);
                }                
                else if (spdWorker.ActiveSheet.ActiveColumnIndex == (int)WORKER_INFO.DEPT_SELECT)
                {
                    spdWorker_Sheet1.SetValue(e.Row, (int)WORKER_INFO.DEPT_CODE, e.SelectedItem.SubItems[0].Text);
                    spdWorker_Sheet1.SetValue(e.Row, (int)WORKER_INFO.DEPT_DESC, e.SelectedItem.SubItems[1].Text);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDeptCode_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvDeptCode.Init();
                MPCF.InitListView(cdvDeptCode.GetListView);
                cdvDeptCode.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvDeptCode.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvDeptCode.SelectedSubItemIndex = 0;
                cdvDeptCode.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvDeptCode.GetListView, '1', CSGC.CP_GCM_DEPT_CODE) == false)
                {
                    return;
                }

                cdvDeptCode.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdWorker_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            int iRow = -1;
            int iColumn = -1;

            try
            {
                if (!e.ColumnHeader)
                    return;

                iRow = e.Row;
                iColumn = e.Column;

                if (spdWorker.ActiveSheet.ColumnHeader.Cells[iRow, iColumn].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdWorker, iRow, iColumn, true, true, false);
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
                ClearList("EXCEL_DOWNLOAD");

                DownloadExcel();
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnUploadExcel_Click(object sender, EventArgs e)
        {
            try
            {
                ClearList("EXCEL_UPLOAD");
                UploadExcel();
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
    }
}
