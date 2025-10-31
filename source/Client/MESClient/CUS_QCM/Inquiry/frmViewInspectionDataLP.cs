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
using FarPoint.Excel.EntityClassLibrary.DrawingVML;

namespace CUS_QCM
{
    public partial class frmViewInspectionDataLP : CUS_COM.frmViewForm01
    {
        public frmViewInspectionDataLP()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "
        private enum LOT_INFO
        {
            JUDGE_DATE,
            JUDGE_TIME,
            LOT_ID,
            INSP_JUDGE_NAME_LP,
            INSP_JUDGE_DESC,
            INSP_COUNT_LP,
            MAT_ID,
            MAT_DESC,
            GRADE,
            SPEC_UT_TARGET_VALUE,
            SPEC_UT_MIN_VALUE,
            SPEC_UT_MAX_VALUE,
            MIN_UT_VALUE,
            MAX_UT_VALUE,
            UT_DEV_VALUE,
            MAIN_LOSS,
            SUB_LOSS,
            LOSS_CBAD004,
            LOSS_CBAD005,
            LOSS_CBAD006,
            LOSS_CBAD401,
            LOSS_CBAD402,
            LOSS_CBAD007,
            LOSS_CBAD008,
            LOSS_CBAD011,
            LOSS_CBAD012,
            LOSS_CBAD013,
            LOSS_CBAD018,
            LOSS_CBAD019,
            LOSS_CBAD020,
            LOSS_CBAD022,
            LOSS_CBAD024,
            LOSS_CBAD047,
            LOSS_CBAD075,
            LOSS_CBAD074,
            LOSS_CBAD405,
            LOSS_CBAD406,
            LOSS_CBAD409,
            LOSS_IBAD038,
            LOSS_CBAD415,
            LOSS_CBAD003,
            LOSS_CBAD412,
            LOSS_CBAD999,
            INSP_COMMENT
        }


        #endregion

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnCsvDirect.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnFileManager.Anchor = AnchorStyles.Top | AnchorStyles.Right;
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
                if (CHECK != CSGC.CHECK.VIEW)
                {
                }
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void ViewInspectionDataCountCheck(int iOutPutType)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[15];
                DataTable dt = null;
                string sSql = "";
                int index = 0;
                string sDbLink = "";
                string viewID = "";
                string sCondition_Value = "";
                string sCondition_Value2 = "";
                string sCondition_Value3 = "";
                string sCondition_Value4 = "";
                string sCondition_Value5 = "";
                string sCondition_Value6 = "";
                DateTime now = DateTime.Now;
                string sCondition_Value7 = (rdoSubLossC.Checked ? "C" : (rdoSubLossNum.Checked ? "1" : ((!rdoSubLossNull.Checked) ? "V" : "")));
                if (rdIJDK1.Checked)
                {
                    array[0].sCondition_ID = "FACTORY";
                    array[0].sCondition_Value = "IJDK1";
                    viewID = ((!(MPGV.gsFactory == "IJDK1")) ? "CQCM3006-005" : "CQCM3006-004");
                }
                else if (rdIJDV1.Checked)
                {
                    array[0].sCondition_ID = "FACTORY";
                    array[0].sCondition_Value = "IJDV1";
                    viewID = ((!(MPGV.gsFactory == "IJDV1")) ? "CQCM3006-005" : "CQCM3006-004");
                }
                if (rdoJudge.Checked)
                {
                    sCondition_Value = (string.IsNullOrEmpty(dtpFromJudgeDate.Text.Trim()) ? "19000101" : dtpFromJudgeDate.Text.Replace("-", ""));
                    sCondition_Value2 = dtpToJudgeDate.Text.Replace("-", "");
                    sCondition_Value3 = "";
                    sCondition_Value4 = "";
                    sCondition_Value5 = "";
                    sCondition_Value6 = "";
                }
                else if (rdoInspReq.Checked)
                {
                    sCondition_Value = "";
                    sCondition_Value2 = "";
                    sCondition_Value3 = (string.IsNullOrEmpty(dtpFromJudgeDate.Text.Trim()) ? "19000101" : dtpFromJudgeDate.Text.Replace("-", ""));
                    sCondition_Value4 = dtpToJudgeDate.Text.Replace("-", "");
                    sCondition_Value5 = "";
                    sCondition_Value6 = "";
                }
                else if (rdoOper.Checked)
                {
                    sCondition_Value = "";
                    sCondition_Value2 = "";
                    sCondition_Value3 = "";
                    sCondition_Value4 = "";
                    sCondition_Value5 = (string.IsNullOrEmpty(dtpFromJudgeDate.Text.Trim()) ? "19000101" : dtpFromJudgeDate.Text.Replace("-", ""));
                    sCondition_Value6 = dtpToJudgeDate.Text.Replace("-", "");
                }
                array[1].sCondition_ID = "FROM_JUDGE_DATE";
                array[1].sCondition_Value = sCondition_Value;
                array[2].sCondition_ID = "TO_JUDGE_DATE";
                array[2].sCondition_Value = sCondition_Value2;
                array[3].sCondition_ID = "MAT_ID";
                array[3].sCondition_Value = cdvMat.Text + "%";
                array[4].sCondition_ID = "LOT_ID";
                array[4].sCondition_Value = txtLotID.Text + "%";
                array[5].sCondition_ID = "SUBLOSS_YN";
                array[5].sCondition_Value = sCondition_Value7;
                array[6].sCondition_ID = "CREATE_CODE";
                array[6].sCondition_Value = cdvOrderType.Text + "%";
                array[7].sCondition_ID = "GRADE";
                array[7].sCondition_Value = "%" + txtGrade.Text + "%";
                viewDbLink(ref sDbLink);
                array[8].sCondition_ID = "DB_LINK";
                array[8].sCondition_Value = sDbLink;
                array[8].sCondition_Type = "TEXT";
                array[9].sCondition_ID = "FROM_INSP_REQ_DATE";
                array[9].sCondition_Value = sCondition_Value3;
                array[10].sCondition_ID = "TO_INSP_REQ_DATE";
                array[10].sCondition_Value = sCondition_Value4;
                array[11].sCondition_ID = "FROM_OPER_DATE";
                array[11].sCondition_Value = sCondition_Value5;
                array[12].sCondition_ID = "TO_OPER_DATE";
                array[12].sCondition_Value = sCondition_Value6;
                array[13].sCondition_ID = "LOCAL_FAC";
                array[13].sCondition_Value = MPGV.gsFactory;
                array[14].sCondition_ID = "MAT_DESC";
                array[14].sCondition_Value = "%" + txtMatDesc.Text + "%";
                if (!TPDR.GetDataOne("", ref dt, viewID, array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdInspectionData);
                    return;
                }
                MPCF.ClearList(spdInspectionData);
                if (dt.Rows.Count > 1)
                {
                    if (MPCF.ShowMsgBox(MPCF.GetMessage(600), MessageBoxButtons.YesNo, 2) == DialogResult.Yes)
                    {
                        for (index = 0; index < dt.Rows.Count; index++)
                        {
                            ViewInspectionDataList(2, dt.Rows[index]["JUDGE_TIME_BEFORE"].ToString(), dt.Rows[index]["JUDGE_TIME_AFTER"].ToString(), now);
                        }
                    }
                }
                else if (iOutPutType == 2)
                {
                    ViewInspectionDataList(2, dt.Rows[index]["JUDGE_TIME_BEFORE"].ToString(), dt.Rows[0]["JUDGE_TIME_AFTER"].ToString(), now);
                }
                else
                {
                    ViewInspectionDataList(1, dt.Rows[index]["JUDGE_TIME_BEFORE"].ToString(), dt.Rows[0]["JUDGE_TIME_AFTER"].ToString(), now);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void viewDbLink(ref string sDbLink)
        {
            TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[3];
            DataTable dt = null;
            string sSql = "";
            array[0].sCondition_ID = "FACTORY";
            array[0].sCondition_Value = MPGV.gsFactory;
            array[1].sCondition_ID = "TABLE_NAME";
            array[1].sCondition_Value = "C_DB_LINK";
            array[2].sCondition_ID = "KEY_1";
            array[2].sCondition_Value = MPGV.gsFactory;
            if (!TPDR.GetDataOne("", ref dt, "BAS-02", array, bIcon: false, bBGColor: false, ref sSql))
            {
                dt?.Dispose();
                GC.Collect();
            }
            else
            {
                sDbLink = dt.Rows[0]["DATA_1"].ToString();
            }
        }

        private void ViewInspectionDataList(int iOutPutType, string FromDt, string ToDt, DateTime dSearchTime)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[16];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                string sDbLink = "";
                string viewID = "";
                string sCondition_Value = "";
                string sCondition_Value2 = "";
                string sCondition_Value3 = "";
                string sCondition_Value4 = "";
                string sCondition_Value5 = "";
                string sCondition_Value6 = "";
                string sCondition_Value7 = (rdoSubLossC.Checked ? "C" : (rdoSubLossNum.Checked ? "1" : ((!rdoSubLossNull.Checked) ? "V" : "")));
                if (rdIJDK1.Checked)
                {
                    array[0].sCondition_ID = "FACTORY";
                    array[0].sCondition_Value = "IJDK1";
                    viewID = ((!(MPGV.gsFactory == "IJDK1")) ? "CQCM3006-003" : "CQCM3006-002");
                }
                else if (rdIJDV1.Checked)
                {
                    array[0].sCondition_ID = "FACTORY";
                    array[0].sCondition_Value = "IJDV1";
                    viewID = ((!(MPGV.gsFactory == "IJDV1")) ? "CQCM3006-003" : "CQCM3006-002");
                }
                if (rdoJudge.Checked)
                {
                    sCondition_Value = FromDt;
                    sCondition_Value2 = ToDt;
                    sCondition_Value3 = "";
                    sCondition_Value4 = "";
                    sCondition_Value5 = "";
                    sCondition_Value6 = "";
                }
                else if (rdoInspReq.Checked)
                {
                    sCondition_Value = "";
                    sCondition_Value2 = "";
                    sCondition_Value3 = FromDt;
                    sCondition_Value4 = ToDt;
                    sCondition_Value5 = "";
                    sCondition_Value6 = "";
                }
                else if (rdoOper.Checked)
                {
                    sCondition_Value = "";
                    sCondition_Value2 = "";
                    sCondition_Value3 = "";
                    sCondition_Value4 = "";
                    sCondition_Value5 = FromDt;
                    sCondition_Value6 = ToDt;
                }
                array[1].sCondition_ID = "FROM_JUDGE_DATE";
                array[1].sCondition_Value = sCondition_Value;
                array[2].sCondition_ID = "TO_JUDGE_DATE";
                array[2].sCondition_Value = sCondition_Value2;
                array[3].sCondition_ID = "MAT_ID";
                array[3].sCondition_Value = cdvMat.Text + "%";
                array[4].sCondition_ID = "LOT_ID";
                array[4].sCondition_Value = txtLotID.Text + "%";
                array[5].sCondition_ID = "SUBLOSS_YN";
                array[5].sCondition_Value = sCondition_Value7;
                array[6].sCondition_ID = "CREATE_CODE";
                array[6].sCondition_Value = cdvOrderType.Text + "%";
                array[7].sCondition_ID = "GRADE";
                array[7].sCondition_Value = "%" + txtGrade.Text + "%";
                viewDbLink(ref sDbLink);
                array[8].sCondition_ID = "DB_LINK";
                array[8].sCondition_Value = sDbLink;
                array[8].sCondition_Type = "TEXT";
                array[9].sCondition_ID = "FROM_INSP_REQ_DATE";
                array[9].sCondition_Value = sCondition_Value3;
                array[10].sCondition_ID = "TO_INSP_REQ_DATE";
                array[10].sCondition_Value = sCondition_Value4;
                array[11].sCondition_ID = "FROM_OPER_DATE";
                array[11].sCondition_Value = sCondition_Value5;
                array[12].sCondition_ID = "TO_OPER_DATE";
                array[12].sCondition_Value = sCondition_Value6;
                array[13].sCondition_ID = "LOCAL_FAC";
                array[13].sCondition_Value = MPGV.gsFactory;
                array[14].sCondition_ID = "MAT_DESC";
                array[14].sCondition_Value = "%" + txtMatDesc.Text + "%";
                if (cdvLanguage.Text.Trim() == "" || cdvLanguage.Text.Trim() == MPGV.gsFactory)
                {
                    array[15].sCondition_ID = "JUDGE_LANG";
                    array[15].sCondition_Value = "N";
                }
                else
                {
                    array[15].sCondition_ID = "JUDGE_LANG";
                    array[15].sCondition_Value = "Y";
                }
                if (!TPDR.GetDataOne("", ref dt, viewID, array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdInspectionData);
                    return;
                }
                MPCF.ClearList(spdInspectionData);
                if (iOutPutType == 2)
                {
                    DateTime dateTime = DateTime.ParseExact(FromDt, "yyyyMMddHHmmss", null);
                    DateTime dateTime2 = DateTime.ParseExact(ToDt, "yyyyMMddHHmmss", null);
                    string filePath = Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + "\\LPInpection_" + dSearchTime.ToString("yyyy-MM-dd_HHmmss") + "\\LPInpection_" + dateTime.ToString("yyyy-MM-dd_HHmmss") + "~" + dateTime2.ToString("yyyy-MM-dd_HHmmss") + ".csv";
                    SheetView activeSheet = spdInspectionData.ActiveSheet;
                    clsCusExportFile clsCusExportFile = new clsCusExportFile();
                    if (clsCusExportFile.SaveDataTableToCsv(dt, filePath, activeSheet, null))
                    {
                        clsCusExportFile.OpenCsvInExcel(filePath);
                    }
                    return;
                }
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdInspectionData.ActiveSheet.RowCount++;
                    spdInspectionData.ActiveSheet.Cells[num, 0].Value = dt.Rows[num]["INSP_JUDGE_DATE"];
                    spdInspectionData.ActiveSheet.Cells[num, 1].Value = dt.Rows[num]["INSP_JUDGE_TIME"];
                    spdInspectionData.ActiveSheet.Cells[num, 2].Value = dt.Rows[num]["LOT_ID"];
                    spdInspectionData.ActiveSheet.Cells[num, 4].Value = dt.Rows[num]["INSP_JUDGE_DESC"];
                    spdInspectionData.ActiveSheet.Cells[num, 3].Value = dt.Rows[num]["INSP_JUDGE_NAME_LP"];
                    spdInspectionData.ActiveSheet.Cells[num, 5].Value = dt.Rows[num]["INSP_COUNT_LP"];
                    spdInspectionData.ActiveSheet.Cells[num, 6].Value = dt.Rows[num]["MAT_ID"];
                    spdInspectionData.ActiveSheet.Cells[num, 7].Value = dt.Rows[num]["MAT_DESC"];
                    spdInspectionData.ActiveSheet.Cells[num, 8].Value = dt.Rows[num]["GRADE"];
                    spdInspectionData.ActiveSheet.Cells[num, 9].Value = dt.Rows[num]["SPEC_UT_TARGET_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[num, 10].Value = dt.Rows[num]["SPEC_UT_MIN_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[num, 11].Value = dt.Rows[num]["SPEC_UT_MAX_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[num, 12].Value = dt.Rows[num]["MIN_UT_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[num, 13].Value = dt.Rows[num]["MAX_UT_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[num, 14].Value = dt.Rows[num]["UT_DEV_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[num, 15].Value = dt.Rows[num]["MAIN_LOSS"];
                    spdInspectionData.ActiveSheet.Cells[num, 16].Value = dt.Rows[num]["SUB_LOSS"];
                    spdInspectionData.ActiveSheet.Cells[num, 17].Value = dt.Rows[num]["LOSS_CBAD004"];
                    spdInspectionData.ActiveSheet.Cells[num, 18].Value = dt.Rows[num]["LOSS_CBAD005"];
                    spdInspectionData.ActiveSheet.Cells[num, 19].Value = dt.Rows[num]["LOSS_CBAD006"];
                    spdInspectionData.ActiveSheet.Cells[num, 20].Value = dt.Rows[num]["LOSS_CBAD401"];
                    spdInspectionData.ActiveSheet.Cells[num, 21].Value = dt.Rows[num]["LOSS_CBAD402"];
                    spdInspectionData.ActiveSheet.Cells[num, 22].Value = dt.Rows[num]["LOSS_CBAD007"];
                    spdInspectionData.ActiveSheet.Cells[num, 23].Value = dt.Rows[num]["LOSS_CBAD008"];
                    spdInspectionData.ActiveSheet.Cells[num, 24].Value = dt.Rows[num]["LOSS_CBAD011"];
                    spdInspectionData.ActiveSheet.Cells[num, 25].Value = dt.Rows[num]["LOSS_CBAD012"];
                    spdInspectionData.ActiveSheet.Cells[num, 26].Value = dt.Rows[num]["LOSS_CBAD013"];
                    spdInspectionData.ActiveSheet.Cells[num, 27].Value = dt.Rows[num]["LOSS_CBAD018"];
                    spdInspectionData.ActiveSheet.Cells[num, 28].Value = dt.Rows[num]["LOSS_CBAD019"];
                    spdInspectionData.ActiveSheet.Cells[num, 29].Value = dt.Rows[num]["LOSS_CBAD020"];
                    spdInspectionData.ActiveSheet.Cells[num, 30].Value = dt.Rows[num]["LOSS_CBAD022"];
                    spdInspectionData.ActiveSheet.Cells[num, 31].Value = dt.Rows[num]["LOSS_CBAD024"];
                    spdInspectionData.ActiveSheet.Cells[num, 32].Value = dt.Rows[num]["LOSS_CBAD047"];
                    spdInspectionData.ActiveSheet.Cells[num, 33].Value = dt.Rows[num]["LOSS_CBAD075"];
                    spdInspectionData.ActiveSheet.Cells[num, 34].Value = dt.Rows[num]["LOSS_CBAD074"];
                    spdInspectionData.ActiveSheet.Cells[num, 35].Value = dt.Rows[num]["LOSS_CBAD405"];
                    spdInspectionData.ActiveSheet.Cells[num, 36].Value = dt.Rows[num]["LOSS_CBAD406"];
                    spdInspectionData.ActiveSheet.Cells[num, 37].Value = dt.Rows[num]["LOSS_CBAD409"];
                    spdInspectionData.ActiveSheet.Cells[num, 38].Value = dt.Rows[num]["LOSS_IBAD038"];
                    spdInspectionData.ActiveSheet.Cells[num, 39].Value = dt.Rows[num]["LOSS_CBAD415"];
                    spdInspectionData.ActiveSheet.Cells[num, 40].Value = dt.Rows[num]["LOSS_CBAD003"];
                    spdInspectionData.ActiveSheet.Cells[num, 41].Value = dt.Rows[num]["LOSS_CBAD412"];
                    spdInspectionData.ActiveSheet.Cells[num, 42].Value = dt.Rows[num]["LOSS_CBAD999"];
                    spdInspectionData.ActiveSheet.Cells[num, 43].Value = dt.Rows[num]["INSP_COMMENT"];
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmViewInspectionDataLP_Load(object sender, EventArgs e)
        {
            try
            {
                dtpToJudgeDate.Value = DateTime.Now;
                dtpFromJudgeDate.Value = dtpToJudgeDate.Value.AddDays(-1.0);
                cdvOrderType.Text = "PROD";
                cdvOrderType.DisplayText = "Product Lot";
                rdoJudge.Checked = true;
                if (MPGV.gsFactory == "IJDK1")
                {
                    rdIJDK1.Checked = true;
                }
                else if (MPGV.gsFactory == "IJDV1")
                {
                    rdIJDV1.Checked = true;
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
                if (CheckCondition(CSGC.CHECK.VIEW))
                {
                    ViewInspectionDataCountCheck(1);
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
                EXTFUC.SaveExcel(spdInspectionData, "InspectionData(LP)");
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvMat_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList frmPopMaterialList = new frmPopMaterialList();
                frmPopMaterialList.StartPosition = FormStartPosition.CenterParent;
                frmPopMaterialList.cdvMatType.Text = "SEMI_FINISHED";
                if (frmPopMaterialList.ShowDialog() == DialogResult.OK)
                {
                    cdvMat.Text = frmPopMaterialList.sMat_id;
                    cdvMat.DisplayText = frmPopMaterialList.sMat_id;
                    txtMatDesc.Text = frmPopMaterialList.sMat_Desc;
                    frmPopMaterialList = null;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOrderType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvOrderType.Init();
                MPCF.InitListView(cdvOrderType.GetListView);
                cdvOrderType.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvOrderType.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvOrderType.SelectedSubItemIndex = 0;
                cdvOrderType.DisplaySubItemIndex = 1;
                if (BASLIST.ViewGCMDataList(cdvOrderType.GetListView, '1', "CREATE_CODE"))
                {
                    cdvOrderType.InsertEmptyRow(0, 1);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMat_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMat.DisplayText == "")
            {
                cdvMat.Text = "";
            }
        }

        private void pnlStsCond_Paint(object sender, PaintEventArgs e)
        {
        }

        private void btnCsvDirect_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW))
                {
                    ViewInspectionDataCountCheck(2);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnFileManager_Click(object sender, EventArgs e)
        {
            if (spdInspectionData.ActiveSheet.RowCount != 0)
            {
                frmPopFtpUpDown frmPopFtpUpDown = new frmPopFtpUpDown();
                frmPopFtpUpDown.StartPosition = FormStartPosition.CenterParent;
                frmPopFtpUpDown.g_PopYn = "Y";
                frmPopFtpUpDown.g_LotId = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, 2].Text;
                frmPopFtpUpDown.g_Mat_id = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, 6].Text;
                frmPopFtpUpDown.g_Mat_Desc = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, 7].Text;
                frmPopFtpUpDown.g_SearchType = "B";
                if (rdIJDK1.Checked)
                {
                    frmPopFtpUpDown.g_Area_Id = "CTM";
                }
                else
                {
                    frmPopFtpUpDown.g_Area_Id = "CTV";
                }
                if (frmPopFtpUpDown.ShowDialog() == DialogResult.OK)
                {
                    frmPopFtpUpDown = null;
                }
            }
        }

        private void cdvLanguage_ButtonPress(object sender, EventArgs e)
        {
            viewLanguageList(cdvLanguage.GetListView);
            cdvLanguage.InsertEmptyRow(0, 1);
        }

        private bool viewLanguageList(ListView listView)
        {
            TRSNode tRSNode = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            MPCF.InitListView(listView);
            MPCR.SetInMsg(tRSNode);
            tRSNode.ProcStep = '1';
            tRSNode.AddString("SQL", "select 'IJDK1' AS CODE, 'korean' AS VALUE FROM DUAL UNION ALL  select 'IJDV1' AS CODE, 'vietnam' AS VALUE FROM DUAL");
            do
            {
                if (!MPCR.CallService("BAS", "BAS_SQL_Query", tRSNode, ref out_node))
                {
                    return false;
                }
                MPCR.FillDataView(listView, out_node);
                tRSNode.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            }
            while (out_node.GetInt("NEXT_ROW") > 0);
            return true;
        }
    }
}
