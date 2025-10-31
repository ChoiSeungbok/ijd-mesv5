using System;
using System.Data;
using System.Windows.Forms;
using MExcel = Microsoft.Office.Interop.Excel;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;
using FarPoint.Win.Spread;

namespace CUS_WIP
{
    public partial class frmTranProductivityGoalRegistration : frmTranForm07
    {
        public frmTranProductivityGoalRegistration()
        {
            InitializeComponent();
            InitControl();
        }

        #region " Constant Definition "
        private enum PROD_GOAL_INFO : int
        {
            CHECK,              // 1 : 선택
            AREA_ID,            // 2 : 사업부 코드
            AREA_BUTTON,        // 3 : 사업부 버튼
            AREA_DESC,          // 4 : 사업부명
            SHOP,               // 5 : 작업장 코드
            SHOP_BUTTON,        // 6 : 작업장 버튼
            SHOP_DESC,          // 7 : 작업장명
            OPER_GRP,           // 8 : 공정 코드
            OPER_GRP_BUTTON,    // 9 : 공정 버튼    
            OPER_GRP_DESC,      // 10: 공정명  
            WORK_MONTH,         // 11: 목표 년월
            WEEK_OF_MONTH,      // 12: 월주차
            GOAL_PRODUCTVITY,   // 13: 목표 생산성(%)
            GOAL_YIELD,         // 14: 목표 수율(%)
        }
        

        #endregion

        #region " Variable Definition "

        #endregion

        #region " Function Defintion "

        private void InitControl()
        {
            try
            {
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSave.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnDelete.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void ClearList(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "SAVE":                       
                            break;
                    case "DELETE":
                        break;

                }
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
                sv = spdProdGoal.ActiveSheet;

                switch (CHECK)
                {
                    case CSGC.CHECK.SAVE:

                        if (MPCF.Trim(cdvGubun.Text) == "P")
                        {
                            for (int i = 0; i < sv.RowCount; i++)
                            {
                                if (Convert.ToBoolean(sv.Cells[i, (int)PROD_GOAL_INFO.CHECK] == null ? false : sv.Cells[i, (int)PROD_GOAL_INFO.CHECK].Value))
                                {
                                    //사업부 검사
                                    if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)PROD_GOAL_INFO.AREA_ID].Value)))
                                    {
                                        MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                        sv.SetActiveCell(i, (int)PROD_GOAL_INFO.AREA_ID);
                                        return false;
                                    }
                                    //작업장 검사
                                    if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)PROD_GOAL_INFO.SHOP].Value)))
                                    {
                                        MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                        sv.SetActiveCell(i, (int)PROD_GOAL_INFO.SHOP);
                                        return false;
                                    }

                                    //공정 검사
                                    if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)PROD_GOAL_INFO.OPER_GRP].Value)))
                                    {
                                        MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                        sv.SetActiveCell(i, (int)PROD_GOAL_INFO.OPER_GRP);
                                        return false;
                                    }

                                    //생산성
                                    //if (MPCF.ToDbl(sv.Cells[i, (int)PROD_GOAL_INFO.GOAL_PRODUCTVITY].Value) <= 0.0
                                    //        || MPCF.ToDbl(sv.Cells[i, (int)PROD_GOAL_INFO.GOAL_PRODUCTVITY].Value) > 100)
                                    //{
                                    //    MPCF.ShowMsgBox(MPCF.GetMessage(364));
                                    //    sv.SetActiveCell(i, (int)PROD_GOAL_INFO.GOAL_PRODUCTVITY);
                                    //    return false;
                                    //}

                                    iCheckCount++;
                                }
                            }
                        }
                        else if (MPCF.Trim(cdvGubun.Text) == "Y")
                        {
                            for (int i = 0; i < sv.RowCount; i++)
                            {
                                if (Convert.ToBoolean(sv.Cells[i, (int)PROD_GOAL_INFO.CHECK] == null ? false : sv.Cells[i, (int)PROD_GOAL_INFO.CHECK].Value))
                                {
                                    //사업부 검사
                                    if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)PROD_GOAL_INFO.AREA_ID].Value)))
                                    {
                                        MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                        sv.SetActiveCell(i, (int)PROD_GOAL_INFO.AREA_ID);
                                        return false;
                                    }

                                    //수율 
                                    //if (MPCF.ToDbl(sv.Cells[i, (int)PROD_GOAL_INFO.GOAL_YIELD].Value) <= 0.0 
                                    //    || MPCF.ToDbl(sv.Cells[i, (int)PROD_GOAL_INFO.GOAL_YIELD].Value) > 100)
                                    //{
                                    //    MPCF.ShowMsgBox(MPCF.GetMessage(364));
                                    //    sv.SetActiveCell(i, (int)PROD_GOAL_INFO.GOAL_YIELD);
                                    //    return false;
                                    //}

                                    iCheckCount++;
                                }
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
                            if (Convert.ToBoolean(sv.Cells[i, (int)PROD_GOAL_INFO.CHECK] == null ? false : sv.Cells[i, (int)PROD_GOAL_INFO.CHECK].Value))
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

        public bool ViewWorkPlaceList(Control control, string sArea)
        {
            try
            {
                ListViewItem itmX;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sArea;

                if (TPDR.GetDataOne("", ref dt, "CWIP2027-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                }

                if (dt == null)
                    return false;

                foreach (DataRow row in dt.Rows)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(row["KEY_2"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["DATA_3"].ToString());
                        }
                        ((ListView)control).Items.Add(itmX);
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

        public bool ViewOperList(Control control, string sArea, string sShop)
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

                dvcArgu[2].sCondition_ID = "SHOP";
                dvcArgu[2].sCondition_Value = sShop;


                if (TPDR.GetDataOne("", ref dt, "CWIP2027-004",  dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                }

                if (dt == null)
                    return false;

                foreach (DataRow row in dt.Rows)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(row["KEY_3"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["DATA_4"].ToString());
                        }
                        ((ListView)control).Items.Add(itmX);
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

        private void ViewProdGoalList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[7];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "KIND";
                dvcArgu[1].sCondition_Value = cdvGubun.Text; 

                dvcArgu[2].sCondition_ID = "AREA_ID";
                dvcArgu[2].sCondition_Value = cdvDept.Text;

                dvcArgu[3].sCondition_ID = "SHOP";
                dvcArgu[3].sCondition_Value = cdvWorkPlaceNew.Text;

                dvcArgu[4].sCondition_ID = "OPER_GRP";
                dvcArgu[4].sCondition_Value = cdvOperNew.Text;

                dvcArgu[5].sCondition_ID = "CLASS";
                dvcArgu[5].sCondition_Value = cdvClass.Text;

                dvcArgu[6].sCondition_ID = "WORK_MONTH";
                dvcArgu[6].sCondition_Value = string.Format("{0}%", string.IsNullOrEmpty(dtpWorkMonth.Text.Trim()) ? "" : dtpWorkMonth.Text.Replace("-", ""));

                if (TPDR.GetDataOne("", ref dt, "CWIP2027-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdProdGoal);
                    return;
                }

                MPCF.ClearList(spdProdGoal);
                
                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdProdGoal_Sheet1.RowCount++;

                    spdProdGoal_Sheet1.Cells[i, (int)PROD_GOAL_INFO.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdProdGoal_Sheet1.Cells[i, (int)PROD_GOAL_INFO.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                    spdProdGoal_Sheet1.Cells[i, (int)PROD_GOAL_INFO.SHOP].Value = dt.Rows[i]["SHOP"];
                    spdProdGoal_Sheet1.Cells[i, (int)PROD_GOAL_INFO.SHOP_DESC].Value = dt.Rows[i]["SHOP_DESC"];
                    spdProdGoal_Sheet1.Cells[i, (int)PROD_GOAL_INFO.OPER_GRP].Value = dt.Rows[i]["OPER_GRP"];
                    spdProdGoal_Sheet1.Cells[i, (int)PROD_GOAL_INFO.OPER_GRP_DESC].Value = dt.Rows[i]["OPER_GRP_DESC"];
                    spdProdGoal_Sheet1.Cells[i, (int)PROD_GOAL_INFO.WORK_MONTH].Value = dt.Rows[i]["WORK_MONTH"].ToString().Substring(0,4) + "-" + dt.Rows[i]["WORK_MONTH"].ToString().Substring(4, 2);
                    spdProdGoal_Sheet1.Cells[i, (int)PROD_GOAL_INFO.WEEK_OF_MONTH].Value = dt.Rows[i]["WEEK_OF_MONTH"].ToString();
                    spdProdGoal_Sheet1.Cells[i, (int)PROD_GOAL_INFO.GOAL_PRODUCTVITY].Value = dt.Rows[i]["GOAL_PRODUCTVITY"];
                    spdProdGoal_Sheet1.Cells[i, (int)PROD_GOAL_INFO.GOAL_YIELD].Value = dt.Rows[i]["GOAL_YIELD"];
                }
               // MPCF.FitColumnHeader(spdProdGoal);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewProdYieldList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "KIND";
                dvcArgu[1].sCondition_Value = "Y";  //수율

                dvcArgu[2].sCondition_ID = "AREA_ID";
                dvcArgu[2].sCondition_Value = cdvDept.Text;

                dvcArgu[3].sCondition_ID = "WORK_MONTH";
                dvcArgu[3].sCondition_Value = dtpWorkMonth.Text.Replace("-", "");

                if (TPDR.GetDataOne("", ref dt, "CWIP2027-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdProdGoal);
                    return;
                }

                MPCF.ClearList(spdProdGoal);                

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdProdGoal_Sheet1.RowCount++;

                    spdProdGoal_Sheet1.Cells[i, (int)PROD_GOAL_INFO.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdProdGoal_Sheet1.Cells[i, (int)PROD_GOAL_INFO.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];                  ;
                    spdProdGoal_Sheet1.Cells[i, (int)PROD_GOAL_INFO.WORK_MONTH].Value = dt.Rows[i]["WORK_MONTH"];
                    spdProdGoal_Sheet1.Cells[i, (int)PROD_GOAL_INFO.GOAL_YIELD].Value = dt.Rows[i]["GOAL_YIELD"];
                }
                MPCF.FitColumnHeader(spdProdGoal);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool SavepProductivity(char sProcStep)
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode prod_list;
                SheetView sv = spdProdGoal_Sheet1;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sProcStep;

                for (int i = 0; i < sv.RowCount; i++)
                {
                    if (Convert.ToBoolean(sv.Cells[i, (int)PROD_GOAL_INFO.CHECK] == null ? false : sv.Cells[i, (int)PROD_GOAL_INFO.CHECK].Value))
                    {
                        prod_list = in_node.AddNode("TBL_LIST");
                        prod_list.AddChar("KIND", cdvGubun.Text);
                        prod_list.AddString("CLASS", cdvClass.Text);
                        prod_list.AddString("AREA_ID", sv.Cells[i, (int)PROD_GOAL_INFO.AREA_ID].Text.Trim());
                        prod_list.AddString("WORK_MONTH", sv.Cells[i, (int)PROD_GOAL_INFO.WORK_MONTH].Text.Replace("-", "").Trim());

                        if (cdvGubun.Text == "P")
                        {
                            prod_list.AddString("SHOP", sv.Cells[i, (int)PROD_GOAL_INFO.SHOP].Text.Trim());
                            prod_list.AddString("OPER_GRP", sv.Cells[i, (int)PROD_GOAL_INFO.OPER_GRP].Text.Trim());                           
                            prod_list.AddDouble("GOAL_PRODUCTVITY", sv.Cells[i, (int)PROD_GOAL_INFO.GOAL_PRODUCTVITY].Text.Trim().Replace("%",""));
                            prod_list.AddDouble("GOAL_YIELD", 0);
                        }
                        else if (cdvGubun.Text == "Y")
                        {
                            prod_list.AddString("SHOP", " ");
                            prod_list.AddString("OPER_GRP", " ");                           
                            prod_list.AddDouble("GOAL_PRODUCTVITY", 0);
                            prod_list.AddDouble("GOAL_YIELD", sv.Cells[i, (int)PROD_GOAL_INFO.GOAL_YIELD].Text.Trim().Replace("%", ""));
                        }

                        if (cdvClass.Text == "MONTH")
                        {
                            prod_list.AddString("WEEK_OF_MONTH", "1");
                        }
                        else
                        {
                            prod_list.AddString("WEEK_OF_MONTH", sv.Cells[i, (int)PROD_GOAL_INFO.WEEK_OF_MONTH].Text.Trim());
                        }
                    }
                }                

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Update_Productivity_Goal", in_node, ref out_node) == false)
                {
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
        
        private void SettingSheetView(string sGubun, string sClass)
        {
            SheetView sv = spdProdGoal_Sheet1;

            try
            {
                MPCF.ClearList(spdProdGoal);

                if (sGubun == "P") ///구분에 따라서 칼럼 사용
                {
                    sv.Columns.Get((int)PROD_GOAL_INFO.SHOP).Visible = true;
                    sv.Columns.Get((int)PROD_GOAL_INFO.SHOP_BUTTON).Visible = true;
                    sv.Columns.Get((int)PROD_GOAL_INFO.SHOP_DESC).Visible = true;
                    sv.Columns.Get((int)PROD_GOAL_INFO.OPER_GRP).Visible = true;
                    sv.Columns.Get((int)PROD_GOAL_INFO.OPER_GRP_BUTTON).Visible = true;
                    sv.Columns.Get((int)PROD_GOAL_INFO.OPER_GRP_DESC).Visible = true;                    
                    sv.Columns.Get((int)PROD_GOAL_INFO.GOAL_PRODUCTVITY).Visible = true;
                    sv.Columns.Get((int)PROD_GOAL_INFO.GOAL_YIELD).Visible = false;

                }
                else if (sGubun == "Y")
                {
                    sv.Columns.Get((int)PROD_GOAL_INFO.SHOP).Visible = false;
                    sv.Columns.Get((int)PROD_GOAL_INFO.SHOP_BUTTON).Visible = false;
                    sv.Columns.Get((int)PROD_GOAL_INFO.SHOP_DESC).Visible = false;
                    sv.Columns.Get((int)PROD_GOAL_INFO.OPER_GRP).Visible = false;
                    sv.Columns.Get((int)PROD_GOAL_INFO.OPER_GRP_BUTTON).Visible = false;
                    sv.Columns.Get((int)PROD_GOAL_INFO.OPER_GRP_DESC).Visible = false;
                    sv.Columns.Get((int)PROD_GOAL_INFO.GOAL_PRODUCTVITY).Visible = false;
                    sv.Columns.Get((int)PROD_GOAL_INFO.GOAL_YIELD).Visible = true;
                }

                if(sClass=="MONTH")
                    sv.Columns.Get((int)PROD_GOAL_INFO.WEEK_OF_MONTH).Visible = false;
                else
                    sv.Columns.Get((int)PROD_GOAL_INFO.WEEK_OF_MONTH).Visible = true;
            }
            catch (Exception ex)
            {
                throw ex;
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

                for (int i = 2; i <= row_count; i++)
                {                   

                    spdProdGoal_Sheet1.RowCount++;
                    spdProdGoal_Sheet1.SetValue(i - 2, (int)PROD_GOAL_INFO.CHECK, true);
                    spdProdGoal_Sheet1.Cells[i - 2, (int)PROD_GOAL_INFO.AREA_ID].Value = data[i, (int)PROD_GOAL_INFO.AREA_ID + 1];
                    spdProdGoal_Sheet1.Cells[i - 2, (int)PROD_GOAL_INFO.AREA_DESC].Value = data[i, (int)PROD_GOAL_INFO.AREA_DESC + 1];
                    spdProdGoal_Sheet1.Cells[i - 2, (int)PROD_GOAL_INFO.SHOP].Value = data[i, (int)PROD_GOAL_INFO.SHOP + 1];
                    spdProdGoal_Sheet1.Cells[i - 2, (int)PROD_GOAL_INFO.SHOP_DESC].Value = data[i, (int)PROD_GOAL_INFO.SHOP_DESC + 1];
                    spdProdGoal_Sheet1.Cells[i - 2, (int)PROD_GOAL_INFO.OPER_GRP].Value = data[i, (int)PROD_GOAL_INFO.OPER_GRP + 1];
                    spdProdGoal_Sheet1.Cells[i - 2, (int)PROD_GOAL_INFO.OPER_GRP_DESC].Value = data[i, (int)PROD_GOAL_INFO.OPER_GRP_DESC + 1];
                    spdProdGoal_Sheet1.Cells[i - 2, (int)PROD_GOAL_INFO.WORK_MONTH].Value = data[i, (int)PROD_GOAL_INFO.WORK_MONTH + 1].ToString().Substring(0, 4) + "-" + data[i, (int)PROD_GOAL_INFO.WORK_MONTH + 1].ToString().Replace("-","").Substring(4, 2);
                    spdProdGoal_Sheet1.Cells[i - 2, (int)PROD_GOAL_INFO.WEEK_OF_MONTH].Value = data[i, (int)PROD_GOAL_INFO.WEEK_OF_MONTH + 1];
                    spdProdGoal_Sheet1.Cells[i - 2, (int)PROD_GOAL_INFO.GOAL_PRODUCTVITY].Value = data[i, (int)PROD_GOAL_INFO.GOAL_PRODUCTVITY + 1];
                    spdProdGoal_Sheet1.Cells[i - 2, (int)PROD_GOAL_INFO.GOAL_YIELD].Value = data[i, (int)PROD_GOAL_INFO.GOAL_YIELD + 1];
                    
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

        #region " Event Defintion 
        private void frmTranProductivityGoalRegistration_Load(object sender, EventArgs e)
        {
            cdvGubun.Text = "P";
            cdvGubun.DisplayText = "생산성";
            cdvClass.Text = "MONTH";
            cdvClass.DisplayText = "Month";            

            cdvDept.Text = string.Empty;
            cdvDept.DisplayText = string.Empty;
            cdvWorkPlaceNew.Text = string.Empty;
            cdvWorkPlaceNew.DisplayText = string.Empty;
            cdvOperNew.Text = string.Empty;
            cdvOperNew.DisplayText = string.Empty;

            dtpWorkMonth.Format = DateTimePickerFormat.Custom;
            //dtpWorkMonth.CustomFormat = " ";
            dtpWorkMonth.Value = DateTime.Now;
            dtpWorkMonth.Text = ""; //DateTime.Now.ToString("yyyy");

            MPCF.ClearList(this.spdProdGoal);
            SettingSheetView(cdvGubun.Text, cdvClass.Text);

        }     

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                MPCF.ClearList(this.spdProdGoal);

                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewProdGoalList();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (SavepProductivity('1'))
                {
                    ViewProdGoalList();

                    MPCF.ShowMsgBox(MPCF.GetMessage(52));
                }
                
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

                DialogResult dr = MessageBox.Show(MPCF.GetMessage(453), "Info", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);

                if (dr == DialogResult.OK)
                {
                    if (SavepProductivity('2'))
                    {                     
                        ViewProdGoalList();                       

                        MPCF.ShowMsgBox(MPCF.GetMessage(52));
                    }
                    
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvGubun_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvGubun.Init();
                MPCF.InitListView(cdvGubun.GetListView);
                cdvGubun.Columns.Add("Type", 50, HorizontalAlignment.Left);
                cdvGubun.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvGubun.SelectedSubItemIndex = 0;
                cdvGubun.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvGubun.GetListView, '1', CSGC.CP_GCM_PROD_REG_TYPE) == false)
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
                MPCF.InitListView(cdvGubun.GetListView);
                cdvDept.Columns.Add("Type", 50, HorizontalAlignment.Left);
                cdvDept.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvDept.SelectedSubItemIndex = 0;
                cdvDept.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvDept.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                {
                    return;
                }
                cdvDept.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorkPlaceNew_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvWorkPlace.Focus();
                    return;
                }

                cdvWorkPlaceNew.Init();
                MPCF.InitListView(cdvWorkPlaceNew.GetListView);
                cdvWorkPlaceNew.Columns.Add("WorkPlace", 50, HorizontalAlignment.Left);
                cdvWorkPlaceNew.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWorkPlaceNew.SelectedSubItemIndex = 0;
                cdvWorkPlaceNew.DisplaySubItemIndex = 1;

                if (ViewWorkPlaceList(cdvWorkPlaceNew.GetListView, cdvDept.Text) == false)
                {
                    return;
                }

                cdvWorkPlaceNew.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
   
        private void cdvOperNew_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvWorkPlaceNew.Text) == "")
                {                    
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlaceNew.Focus();
                    return;
                }

                cdvOperNew.Init();
                MPCF.InitListView(cdvOperNew.GetListView);
                cdvOperNew.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOperNew.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOperNew.SelectedSubItemIndex = 0;
                cdvOperNew.DisplaySubItemIndex = 1;

                if (ViewOperList(cdvOperNew.GetListView, cdvDept.Text, cdvWorkPlaceNew.Text) == false)
                {
                    return;
                }
                cdvOperNew.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
               
        private void btnRowAdd_Click(object sender, EventArgs e)
        {
            SheetView sv = spdProdGoal.ActiveSheet;
            int iRow = sv.RowCount;

            try
            {
                sv.RowCount++;
                sv.Cells[iRow, (int)PROD_GOAL_INFO.CHECK].Value = true;
                sv.Cells[iRow, (int)PROD_GOAL_INFO.AREA_ID].Value = cdvDept.Text;
                sv.Cells[iRow, (int)PROD_GOAL_INFO.AREA_DESC].Value = cdvDept.DisplayText;
              // sv.Cells[iRow, (int)PROD_GOAL_INFO.WORK_MONTH].Value = dtpWorkMonth.Text;
                sv.Cells[iRow, (int)PROD_GOAL_INFO.WEEK_OF_MONTH].Value = "1";

                if (cdvGubun.Text == "P")
                {                                      
                    sv.Cells[iRow, (int)PROD_GOAL_INFO.SHOP].Value = cdvWorkPlaceNew.Text;
                    sv.Cells[iRow, (int)PROD_GOAL_INFO.SHOP_DESC].Value = cdvWorkPlaceNew.DisplayText;
                    sv.Cells[iRow, (int)PROD_GOAL_INFO.OPER_GRP].Value = cdvOperNew.Text;
                    sv.Cells[iRow, (int)PROD_GOAL_INFO.OPER_GRP_DESC].Value = cdvOperNew.DisplayText;                   
                    sv.Cells[iRow, (int)PROD_GOAL_INFO.GOAL_PRODUCTVITY].Value = 0;
                    sv.Cells[iRow, (int)PROD_GOAL_INFO.GOAL_YIELD].Value = 0;
                }
                else if (cdvGubun.Text == "Y")
                {
                    sv.Cells[iRow, (int)PROD_GOAL_INFO.SHOP].Value = "";
                    sv.Cells[iRow, (int)PROD_GOAL_INFO.SHOP_DESC].Value = "";
                    sv.Cells[iRow, (int)PROD_GOAL_INFO.OPER_GRP].Value = "";
                    sv.Cells[iRow, (int)PROD_GOAL_INFO.OPER_GRP_DESC].Value = "";
                    sv.Cells[iRow, (int)PROD_GOAL_INFO.GOAL_PRODUCTVITY].Value = 0;
                    sv.Cells[iRow, (int)PROD_GOAL_INFO.GOAL_YIELD].Value = 0;

                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnRowDel_Click(object sender, EventArgs e)
        {
            SheetView sv= spdProdGoal.ActiveSheet;          

            try
            {
                for (int i = sv.RowCount - 1; i >= 0; i--)
                {
                    if (Convert.ToBoolean(sv.Cells[i, (int)PROD_GOAL_INFO.CHECK] == null ? false : sv.Cells[i, (int)PROD_GOAL_INFO.CHECK].Value))
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

        private void cdvGubun_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                MPCF.ClearList(spdProdGoal);

                SettingSheetView(cdvGubun.Text, cdvClass.Text);
      
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

            
        }

        private void cdvClass_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                MPCF.ClearList(spdProdGoal);

                SettingSheetView(cdvGubun.Text, cdvClass.Text);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }

        private void spdProdGoal_CellClick(object sender, CellClickEventArgs e)
        {
            int i = 0;
            SheetView sv = spdProdGoal.ActiveSheet;

            if (e.Row > 0 && Convert.ToBoolean(sv.Cells[e.Row, (int)PROD_GOAL_INFO.CHECK] == null ? false : sv.Cells[e.Row, (int)PROD_GOAL_INFO.CHECK].Value))
                sv.Cells[e.Row, (int)PROD_GOAL_INFO.CHECK].Value = true;


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

        private void spdProdGoal_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            try
            {
                SheetView sv = spdProdGoal.ActiveSheet;

                if (e.Column == (int)PROD_GOAL_INFO.AREA_BUTTON || e.Column == (int)PROD_GOAL_INFO.SHOP_BUTTON
                    || e.Column == (int)PROD_GOAL_INFO.OPER_GRP_BUTTON)
                {
                    cdvGridButton.Init();
                    MPCF.InitListView(cdvGridButton.GetListView);
                    cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);
                    cdvGridButton.Columns.Add("Desc", 100, HorizontalAlignment.Left);

                    if (e.Column == (int)PROD_GOAL_INFO.AREA_BUTTON)
                    {
                        //사업부 조회
                        if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                            return;

                        sv.Cells[e.Row, (int)PROD_GOAL_INFO.SHOP].Value = string.Empty;
                        sv.Cells[e.Row, (int)PROD_GOAL_INFO.SHOP_DESC].Value = string.Empty;
                        sv.Cells[e.Row, (int)PROD_GOAL_INFO.OPER_GRP].Value = string.Empty;
                        sv.Cells[e.Row, (int)PROD_GOAL_INFO.OPER_GRP_DESC].Value = string.Empty;
                    }
                    else if (e.Column == (int)PROD_GOAL_INFO.SHOP_BUTTON)
                    {
                        //작업장 조회
                        if (ViewWorkPlaceList(cdvGridButton.GetListView, MPCF.Trim(sv.Cells[e.Row, (int)PROD_GOAL_INFO.AREA_ID].Value)) == false)
                            return;

                        sv.Cells[e.Row, (int)PROD_GOAL_INFO.OPER_GRP].Value = string.Empty;
                        sv.Cells[e.Row, (int)PROD_GOAL_INFO.OPER_GRP_DESC].Value = string.Empty;
                    }
                    else if (e.Column == (int)PROD_GOAL_INFO.OPER_GRP_BUTTON)
                    {
                        //공정 조회
                        if (ViewOperList(cdvGridButton.GetListView, MPCF.Trim(sv.Cells[e.Row, (int)PROD_GOAL_INFO.AREA_ID].Value), MPCF.Trim(sv.Cells[e.Row, (int)PROD_GOAL_INFO.SHOP].Value)) == false)
                        {
                            return;
                        }
                    }

                    cdvGridButton.ShowPopupList(e.Row, e.Column);
                    //cdvGridButton.InsertEmptyRow(0, 1);
                }
               
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }       

        private void spdProdGoal_KeyDown(object sender, KeyEventArgs e)
        {
            try
            {
                /*
                if (e.Control && e.KeyCode == Keys.V)
                {
                    SheetView sv = spdProdGoal.ActiveSheet;
                    int iActiveRow = sv.ActiveRowIndex;

                    if (iActiveRow < 0)
                        return;

                    //줄바꿈을 자르고 마지막은 빈값이므로 포함안시킴
                    string[] rowSeparators = new string[] { "\r\n" };
                    string sClipboard = Clipboard.GetText();
                    string[] sList = sClipboard.Split(rowSeparators, StringSplitOptions.None);

                    for (int i = 0; i < sList.Length - 1; i++)
                    {
                        //이제 열로 구분된 값을 다시 잘라서 각 ROW에 넣어준다.
                        string[] columnSeparators = new string[] { "\t" };
                        string[] sColumnList = sList[i].Split(columnSeparators, StringSplitOptions.None);

                        sv.Cells[iActiveRow, 0].Value = true;
                        if (sColumnList.Length == 1)
                        {
                            sv.Cells[iActiveRow, sv.ActiveColumnIndex].Value = sColumnList[0];
                        }
                        else
                        {

                            if (cdvGubun.Text == "P")
                            {
                                sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.AREA_ID].Value = sColumnList[0];
                                sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.AREA_DESC].Value = sColumnList[2];
                                sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.SHOP].Value = sColumnList[3];
                                sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.SHOP_DESC].Value = sColumnList[5];
                                sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.OPER_GRP].Value = sColumnList[6];
                                sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.OPER_GRP_DESC].Value = sColumnList[8];
                                sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.WORK_MONTH].Value = sColumnList[9];
                                if (cdvClass.Text == "MONTH")
                                {
                                    sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.WEEK_OF_MONTH].Value = "1";
                                    sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.GOAL_PRODUCTVITY].Value = sColumnList[10];
                                }
                                else
                                {
                                    sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.WEEK_OF_MONTH].Value = sColumnList[10];
                                    sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.GOAL_PRODUCTVITY].Value = sColumnList[11];
                                }

                                sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.GOAL_YIELD].Value = "0";
                            }
                            else if (cdvGubun.Text == "Y")
                            {
                                sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.AREA_ID].Value = sColumnList[0];
                                sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.AREA_DESC].Value = sColumnList[2];
                                sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.SHOP].Value = "";
                                sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.SHOP_DESC].Value = "";
                                sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.OPER_GRP].Value = "";
                                sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.OPER_GRP_DESC].Value = "";
                                sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.WORK_MONTH].Value = sColumnList[3];
                                sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.GOAL_PRODUCTVITY].Value = "0";

                                if (cdvClass.Text == "MONTH")
                                {
                                    sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.WEEK_OF_MONTH].Value = "1";
                                    sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.GOAL_YIELD].Value = sColumnList[4];
                                }
                                else
                                {
                                    sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.WEEK_OF_MONTH].Value = sColumnList[4];
                                    sv.Cells[iActiveRow, (int)PROD_GOAL_INFO.GOAL_YIELD].Value = sColumnList[5];
                                }
                            }
                        }

                        iActiveRow++;
                        if ((sv.RowCount - 1) < iActiveRow)
                            sv.RowCount++;
                    }                 

                    //sv.RemoveRows(iActiveRow, (sv.RowCount - iActiveRow - 1) == 0 ? 1 : (sv.RowCount - iActiveRow - 1));

                    //if (sv.RowCount - iActiveRow - 1 != 0)
                    //{
                   //     sv.RowCount++;
                    //}
                }*/
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

            e.Handled = true;
        }
              
        private void cdvGridButton_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            SheetView sv = spdProdGoal.ActiveSheet;
            try
            {
                if (sv.ActiveColumnIndex == (int)PROD_GOAL_INFO.AREA_BUTTON)
                {
                    sv.SetValue(e.Row, (int)PROD_GOAL_INFO.AREA_ID, e.SelectedItem.SubItems[0].Text);
                    sv.SetValue(e.Row, (int)PROD_GOAL_INFO.AREA_DESC, e.SelectedItem.SubItems[1].Text);
                }
                else if (sv.ActiveColumnIndex == (int)PROD_GOAL_INFO.SHOP_BUTTON)
                {
                    sv.SetValue(e.Row, (int)PROD_GOAL_INFO.SHOP, e.SelectedItem.SubItems[0].Text);
                    sv.SetValue(e.Row, (int)PROD_GOAL_INFO.SHOP_DESC, e.SelectedItem.SubItems[1].Text);
                }
                else if (sv.ActiveColumnIndex == (int)PROD_GOAL_INFO.OPER_GRP_BUTTON)
                {
                    sv.SetValue(e.Row, (int)PROD_GOAL_INFO.OPER_GRP, e.SelectedItem.SubItems[0].Text);
                    sv.SetValue(e.Row, (int)PROD_GOAL_INFO.OPER_GRP_DESC, e.SelectedItem.SubItems[1].Text);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        
        private void spdProdGoal_EditModeStarting(object sender, EditModeStartingEventArgs e)
        {
            if (spdProdGoal_Sheet1.ActiveColumnIndex != 0)
                spdProdGoal_Sheet1.Cells[spdProdGoal_Sheet1.ActiveRowIndex, (int)PROD_GOAL_INFO.CHECK].Value = true;
        }

        private void cdvClass_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvClass.Init();
                MPCF.InitListView(cdvClass.GetListView);
                cdvClass.Columns.Add("Type", 50, HorizontalAlignment.Left);
                cdvClass.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvClass.SelectedSubItemIndex = 0;
                cdvClass.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvClass.GetListView, '1', CSGC.CP_GCM_PROD_CLASS_TYPE) == false)
                {
                    return;
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
                MPCF.ClearList(spdProdGoal);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                spdProdGoal_Sheet1.Columns.Get((int)PROD_GOAL_INFO.CHECK).Visible = false;
                spdProdGoal_Sheet1.Columns.Get((int)PROD_GOAL_INFO.AREA_BUTTON).Visible = false;
                if (cdvGubun.Text == "P")
                {
                    spdProdGoal_Sheet1.Columns.Get((int)PROD_GOAL_INFO.SHOP_BUTTON).Visible = false;
                    spdProdGoal_Sheet1.Columns.Get((int)PROD_GOAL_INFO.OPER_GRP_BUTTON).Visible = false;
                }
                EXTFUC.SaveExcel(spdProdGoal, string.Format("Productivity_{0}", string.IsNullOrEmpty(cdvDept.Text) ? "ALL" : cdvDept.Text));
                                
                spdProdGoal_Sheet1.Columns.Get((int)PROD_GOAL_INFO.CHECK).Visible = true;
                spdProdGoal_Sheet1.Columns.Get((int)PROD_GOAL_INFO.AREA_BUTTON).Visible = true;
                if (cdvGubun.Text == "P")
                {
                    spdProdGoal_Sheet1.Columns.Get((int)PROD_GOAL_INFO.SHOP_BUTTON).Visible = true;
                    spdProdGoal_Sheet1.Columns.Get((int)PROD_GOAL_INFO.OPER_GRP_BUTTON).Visible = true;
                }

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
                MPCF.ClearList(spdProdGoal);
                UploadExcel();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

    }
}
