using System;
using System.Data;
using System.Linq;
using System.Windows.Forms;
using Excel = Microsoft.Office.Interop.Excel;
using FarPoint.Win.Spread;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;

namespace CUS_RAS
{
    public partial class frmSetupResEfficiency : frmTranForm01
    {
        public frmSetupResEfficiency()
        {
            InitializeComponent();
            InitControl();
        }

        #region " Constant Definition "


        #endregion

        #region " Variable Definition "

        private enum RASBASDAT
        {
            CHECK,
            RES_ID,                      // 1 : 설비ID
            RES_BUTTON,               
            RES_DESC,                    // 2 : 설비명
            PROC_YN,                     // 3 : 대상유무
            NOWORK_TYPE,                 // 4 : 고정 비 근무 적용
            RUN_TYPE,                    // 5 : 고정 비 부하 적용
            CMF_1,
            CMF_2,
            CMF_3,
            CMF_4,
            CMF_5
        }


        #endregion

        #region " Function Defintion "

        private void InitControl()
        {
            try
            {
                btnExcel.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                btnUploadExcel.Anchor = AnchorStyles.Top | AnchorStyles.Left;

                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnDelete.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            SheetView sv = null;
            int iCheckCount = 0;

            try
            {
                sv = spdList.ActiveSheet;

                switch (CHECK)
                {
                    case CSGC.CHECK.SAVE:
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (Convert.ToBoolean(sv.Cells[i, (int)RASBASDAT.CHECK] == null ? false : sv.Cells[i, (int)RASBASDAT.CHECK].Value))
                            {
                                //사업부 검사
                                if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)RASBASDAT.RES_ID].Value)))
                                {
                                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                    sv.SetActiveCell(i, (int)RASBASDAT.RES_ID);
                                    return false;
                                }                               

                                iCheckCount++;
                            }
                        }
                        if (iCheckCount == 0)
                        {
                            //체크항목이 존재하지 않습니다. 확인해주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(465));
                            return false;
                        }
                        break;
                    case CSGC.CHECK.DELETE:

                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (Convert.ToBoolean(sv.Cells[i, (int)RASBASDAT.CHECK] == null ? false : sv.Cells[i, (int)RASBASDAT.CHECK].Value))
                            {
                                iCheckCount++;
                            }
                        }

                        if (iCheckCount == 0)
                        {
                            //체크항목이 존재하지 않습니다. 확인해주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(465));
                            return false;
                        }
                        break;
                    case CSGC.CHECK.VIEW:
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

        private void ViewList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = cdvWorkPlace.Text;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = cdvOper.Text;

                dvcArgu[4].sCondition_ID = "RES_ID";
                dvcArgu[4].sCondition_Value = cdvResId.Text;

                if (TPDR.GetDataOne("", ref dt, "CRAS1002-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdList);
                    return;
                }

                MPCF.ClearList(spdList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdList.ActiveSheet.RowCount++;

                    spdList.ActiveSheet.SetValue(i, (int)RASBASDAT.CHECK, false);
                    spdList.ActiveSheet.Cells[i, (int)RASBASDAT.RES_ID].Value = dt.Rows[i]["RES_ID"];
                    spdList.ActiveSheet.Cells[i, (int)RASBASDAT.RES_DESC].Value = dt.Rows[i]["RES_DESC"];
                    spdList.ActiveSheet.Cells[i, (int)RASBASDAT.PROC_YN].Value = dt.Rows[i]["PROC_YN"];
                    spdList.ActiveSheet.Cells[i, (int)RASBASDAT.NOWORK_TYPE].Value = dt.Rows[i]["NOWORK_TYPE"];
                    spdList.ActiveSheet.Cells[i, (int)RASBASDAT.RUN_TYPE].Value = dt.Rows[i]["RUN_TYPE"];
                    spdList.ActiveSheet.Cells[i, (int)RASBASDAT.CMF_1].Value = dt.Rows[i]["CMF_1"];
                    spdList.ActiveSheet.Cells[i, (int)RASBASDAT.CMF_2].Value = dt.Rows[i]["CMF_2"];
                    spdList.ActiveSheet.Cells[i, (int)RASBASDAT.CMF_3].Value = dt.Rows[i]["CMF_3"];
                    spdList.ActiveSheet.Cells[i, (int)RASBASDAT.CMF_4].Value = dt.Rows[i]["CMF_4"];
                    spdList.ActiveSheet.Cells[i, (int)RASBASDAT.CMF_5].Value = dt.Rows[i]["CMF_5"];
                }

                return;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
      

        private bool ViewOperList(Control control, string sArea, string sSubAreaId)
        {
            try
            {
                ListViewItem itmX;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sArea;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = sSubAreaId;

                if (TPDR.GetDataOne("", ref dt, "CRAS1001-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }

                foreach (DataRow row in dt.Rows)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(row["OPER_CODE"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["OPER_DESC"].ToString());
                        }
                       ((ListView)control).Items.Add(itmX);
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                throw ex;
            }
        }

        private bool ViewResList(Control control, string sArea, string sSubAreaId, string sOper)
        {
            try
            {
                ListViewItem itmX;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sArea;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = sSubAreaId;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = sOper;

                if (TPDR.GetDataOne("", ref dt, "CRAS1001-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }

                foreach (DataRow row in dt.Rows)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(row["RES_ID"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {                            
                            itmX.SubItems.Add(row["RES_DESC"].ToString());
                        }
                       ((ListView)control).Items.Add(itmX);
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                throw ex;
            }
        }

        private bool SaveList(char sProcStep)
        {
            try
            {

                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode list;
                SheetView sv = spdList_Sheet1;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sProcStep;

                for (int i = 0; i < sv.RowCount; i++)
                {
                    if (Convert.ToBoolean(sv.Cells[i, (int)RASBASDAT.CHECK] == null ? false : sv.Cells[i, (int)RASBASDAT.CHECK].Value))
                    {
                        list = in_node.AddNode("TBL_LIST");
                        list.AddString("RES_ID", sv.Cells[i, (int)RASBASDAT.RES_ID].Text.Trim());
                        list.AddChar("PROC_YN", sv.Cells[i, (int)RASBASDAT.PROC_YN].Text.Trim());
                        list.AddChar("NOWORK_TYPE", sv.Cells[i, (int)RASBASDAT.NOWORK_TYPE].Text.Trim());
                        list.AddChar("RUN_TYPE", sv.Cells[i, (int)RASBASDAT.RUN_TYPE].Text.Trim());

                        list.AddString("CMF_1", sv.Cells[i, (int)RASBASDAT.CMF_1].Text.Trim());
                        list.AddString("CMF_2", sv.Cells[i, (int)RASBASDAT.CMF_2].Text.Trim());
                        list.AddString("CMF_3", sv.Cells[i, (int)RASBASDAT.CMF_3].Text.Trim());
                        list.AddString("CMF_4", sv.Cells[i, (int)RASBASDAT.CMF_4].Text.Trim());
                        list.AddString("CMF_5", sv.Cells[i, (int)RASBASDAT.CMF_5].Text.Trim());                        
                    }
                }

                if (MPCR.CallService("CUS_RAS", "CUS_RAS_Update_Resource_Efficiency_Info", in_node, ref out_node) == false)
                {
                  
                    return false;
                }              

                MPCR.ShowSuccessMsg(out_node);

                return true;

            }
            catch (Exception ex)
            {
                throw ex;
            }
        }

        private void UploadExcel()
        {

            Excel.Application XApp = null;
            Excel.Workbooks XBooks = null;
            Excel.Workbook XBook = null;
            Excel.Worksheet XSheet = null;
            Excel.Sheets XSheets = null;

            OpenFileDialog ofdFile = new OpenFileDialog();

            try
            {
                ofdFile.Filter = "Excel Files(*.xls;*.xlsx)|*.xls;*.xlsx";
                ofdFile.DefaultExt = "xls,xlsx";

                if (ofdFile.ShowDialog() != DialogResult.OK)
                    return;

                XApp = new Excel.Application();
                XApp.Interactive = false;
                XBooks = XApp.Workbooks;
                XBook = XBooks.Open(ofdFile.FileName);

                ((Excel.Worksheet)XBook.Sheets[1]).Select();

                XSheets = XBook.Worksheets;
                XSheet = XSheets.get_Item(1) as Excel.Worksheet;

                //시트에서 사용된 셀범위
                Excel.Range range = XSheet.UsedRange;

                //2차원 배열에 담기
                Object[,] data = range.Value;
                int row_count = range.Rows.Count;

                for (int i = 2; i <= row_count; i++)
                {
                    spdList.ActiveSheet.RowCount++;
                    spdList.ActiveSheet.SetValue(i - 2, (int)RASBASDAT.CHECK, true);
                    spdList.ActiveSheet.Cells[i - 2, (int)RASBASDAT.RES_ID].Value = data[i, (int)RASBASDAT.RES_ID + 1];
                    spdList.ActiveSheet.Cells[i - 2, (int)RASBASDAT.RES_DESC].Value = data[i, (int)RASBASDAT.RES_DESC + 1];
                    spdList.ActiveSheet.Cells[i - 2, (int)RASBASDAT.PROC_YN].Value = data[i, (int)RASBASDAT.PROC_YN + 1];
                    spdList.ActiveSheet.Cells[i - 2, (int)RASBASDAT.NOWORK_TYPE].Value = data[i, (int)RASBASDAT.NOWORK_TYPE + 1];
                    spdList.ActiveSheet.Cells[i - 2, (int)RASBASDAT.RUN_TYPE].Value = data[i, (int)RASBASDAT.RUN_TYPE + 1];
                    spdList.ActiveSheet.Cells[i - 2, (int)RASBASDAT.CMF_1].Value = data[i, (int)RASBASDAT.CMF_1 + 1];
                    spdList.ActiveSheet.Cells[i - 2, (int)RASBASDAT.CMF_2].Value = data[i, (int)RASBASDAT.CMF_2 + 1];
                    spdList.ActiveSheet.Cells[i - 2, (int)RASBASDAT.CMF_3].Value = data[i, (int)RASBASDAT.CMF_3 + 1];
                    spdList.ActiveSheet.Cells[i - 2, (int)RASBASDAT.CMF_4].Value = data[i, (int)RASBASDAT.CMF_4 + 1];
                    spdList.ActiveSheet.Cells[i - 2, (int)RASBASDAT.CMF_5].Value = data[i, (int)RASBASDAT.CMF_5 + 1];

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

        #region " Event Defintion "

        private void frmSetupResEfficiency_Load(object sender, EventArgs e)
        {
            try
            {
                MPCF.FieldClear(pnlStsCond);

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
                cdvOper.Columns.Add("OPER_CODE", 50, HorizontalAlignment.Left);
                cdvOper.Columns.Add("OPER_DESC", 100, HorizontalAlignment.Left);
                cdvOper.DisplaySubItemIndex = 1;
                cdvOper.SelectedSubItemIndex = 0;

                if (ViewOperList(cdvOper.GetListView, cdvDept.Text, cdvWorkPlace.Text) == false)
                {
                    return;
                }
                cdvOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void cdvResId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvResId.Init();
                MPCF.InitListView(cdvResId.GetListView);
                cdvResId.Columns.Add("RES_ID", 50, HorizontalAlignment.Left);
                cdvResId.Columns.Add("RED_DESC", 100, HorizontalAlignment.Left);
                cdvResId.DisplaySubItemIndex = 1;
                cdvResId.SelectedSubItemIndex = 0;

                if (ViewResList(cdvResId.GetListView, cdvDept.Text, cdvWorkPlace.Text, cdvOper.Text) == false)
                {
                    return;
                }
                cdvResId.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }
        
        private void btnRowAdd_Click(object sender, EventArgs e)
        {
            SheetView sv = spdList.ActiveSheet;
            int iRow = sv.RowCount;

            try
            {
                sv.RowCount++;
                sv.SetValue(iRow, (int)RASBASDAT.CHECK, true);
                sv.Cells[iRow, (int)RASBASDAT.RES_ID].Value = "";
                sv.Cells[iRow, (int)RASBASDAT.RES_DESC].Value = "";
                sv.Cells[iRow, (int)RASBASDAT.PROC_YN].Value = "";
                sv.Cells[iRow, (int)RASBASDAT.NOWORK_TYPE].Value = "";
                sv.Cells[iRow, (int)RASBASDAT.RUN_TYPE].Value = "";
                sv.Cells[iRow, (int)RASBASDAT.CMF_1].Value = "";
                sv.Cells[iRow, (int)RASBASDAT.CMF_2].Value = "";
                sv.Cells[iRow, (int)RASBASDAT.CMF_3].Value = "";
                sv.Cells[iRow, (int)RASBASDAT.CMF_4].Value = "";
                sv.Cells[iRow, (int)RASBASDAT.CMF_5].Value = "";

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnRowDel_Click(object sender, EventArgs e)
        {
            SheetView sv = spdList.ActiveSheet;

            try
            {
                for (int i = sv.RowCount - 1; i >= 0; i--)
                {
                    if (Convert.ToBoolean(sv.Cells[i, (int)RASBASDAT.CHECK] == null ? false : sv.Cells[i, (int)RASBASDAT.CHECK].Value))
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

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewList();

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
                    return;

                if (SaveList('1'))
                    ViewList();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }       
        private void btnDelete_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.DELETE) == false)
                    return;

                if (SaveList('2'))
                    ViewList();

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
                spdList.ActiveSheet.Columns.Get((int)RASBASDAT.CHECK).Visible = false;
                spdList.ActiveSheet.Columns.Get((int)RASBASDAT.RES_BUTTON).Visible = false;

                EXTFUC.SaveExcel(spdList, "OEE_BaseInfo");

                spdList.ActiveSheet.Columns.Get((int)RASBASDAT.CHECK).Visible = true;
                spdList.ActiveSheet.Columns.Get((int)RASBASDAT.RES_BUTTON).Visible = true;

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
                MPCF.ClearList(spdList);
                UploadExcel();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)RASBASDAT.CHECK)
                    {
                        CSCF.CheckSpreadCell(spdList, 0, 0, true, true);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }       

        private void spdList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            try
            {
                SheetView sv = spdList_Sheet1;

                if (e.Column == (int)RASBASDAT.RES_BUTTON)
                {

                    cdvGridButton.Init();
                    MPCF.InitListView(cdvGridButton.GetListView);
                    cdvGridButton.Columns.Add("RES_ID", 50, HorizontalAlignment.Left);
                    cdvGridButton.Columns.Add("RES_DESC", 100, HorizontalAlignment.Left);

                    if (e.Column == (int)RASBASDAT.RES_BUTTON)
                    {
                        if (ViewResList(cdvGridButton.GetListView, cdvDept.Text, cdvWorkPlace.Text, cdvOper.Text) == false)                      
                            return;
                    }
                                      
                    cdvGridButton.ShowPopupList(e.Row, e.Column);

                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }        

        private void cdvGridButton_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            SheetView sv = spdList.ActiveSheet;
            try
            {
                if (sv.ActiveColumnIndex == (int)RASBASDAT.RES_BUTTON)
                {
                    sv.SetValue(e.Row, (int)RASBASDAT.RES_ID, e.SelectedItem.SubItems[0].Text);
                    sv.SetValue(e.Row, (int)RASBASDAT.RES_DESC, e.SelectedItem.SubItems[1].Text);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }       

        private void spdList_EditModeStarting(object sender, EditModeStartingEventArgs e)
        {
            if (spdList_Sheet1.ActiveColumnIndex != 0)
                spdList_Sheet1.Cells[spdList_Sheet1.ActiveRowIndex, (int)RASBASDAT.CHECK].Value = true;
        }

        #endregion
    }
}
