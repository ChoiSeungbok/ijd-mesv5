using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;
using FarPoint.Win.Spread;
using FarPoint.Excel.EntityClassLibrary.DrawingEx;
using System.Diagnostics;
using DevExpress.Data;
using FarPoint.Win;
using FarPoint.Excel.EntityClassLibrary.DrawingVML;

namespace CUS_QCM
{
    public partial class frmViewInspectionDataRound : CUS_COM.frmViewForm01
    {
        public frmViewInspectionDataRound()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "
        private enum LOT_INFO
        {
            INSP_REQ_TIME,
            JUDGE_DATE,
            OPER_DATE,
            JUDGE_TIME,
            LOT_ID,
            JUDGE,
            INSP_JUDGE_NAME_LP,
            INSP_JUDGE_NAME_ROUND,
            INSP_JUDGE_NAME_WD,
            ITEM_CHANGE_COUNT,
            INSP_MONTH_COUNT_LP,
            INSP_MONTH_COUNT_ROUND,
            INSP_MONTH_COUNT_WD,
            MAT_ID,
            MAT_DESC,
            GRADE,
            SPEC_MAX_D_VALUE,
            MIN_MAX_D_VALUE,
            MAX_MAX_D_VALUE,
            MIN_REAL_D_VALUE,
            MAX_REAL_D_VALUE,
            SPEC_ALL_T_VALUE,
            MIN_ALL_T_VALUE,
            MAX_ALL_T_VALUE,
            ALL_T_VALUE_1,
            ALL_T_VALUE_2,
            ALL_T_VALUE_3,
            ALL_T_VALUE_4,
            ALL_T_VALUE_5,
            ALL_T_VALUE_6,
            ALL_T_VALUE_7,
            ALL_T_VALUE_8,
            ALL_T_VALUE_9,
            ALL_T_VALUE_10,
            ALL_T_VALUE_11,
            ALL_T_VALUE_12,
            ALL_T_VALUE_13,
            SPEC_UT_VALUE,
            MIN_UT_VALUE,
            MAX_UT_VALUE,
            SPEC_FLAT_VALUE,
            MIN_FLAT_VALUE,
            MAX_FLAT_VALUE,
            FLAT_VALUE_1,
            FLAT_VALUE_2,
            FLAT_VALUE_3,
            FLAT_VALUE_4,
            FLAT_VALUE_5,
            FLAT_VALUE_6,
            FLAT_VALUE_7,
            FLAT_VALUE_8,
            FLAT_VALUE_9,
            FLAT_VALUE_10,
            FLAT_VALUE_11,
            FLAT_VALUE_12,
            FLAT_VALUE_13,
            MAIN_LOSS,
            SUB_LOSS,
            LOSS_CBAD003,
            LOSS_CBAD004,
            LOSS_CBAD005,
            LOSS_CBAD006,
            LOSS_CBAD401,
            LOSS_CBAD402,
            LOSS_CBAD007,
            LOSS_CBAD008,
            LOSS_CBAD009,
            LOSS_CBAD011,
            LOSS_CBAD018,
            LOSS_CBAD019,
            LOSS_CBAD020,
            LOSS_CBAD021,
            LOSS_CBAD022,
            LOSS_CBAD024,
            LOSS_CBAD027,
            LOSS_CBAD036,
            LOSS_CBAD037,
            LOSS_CBAD056,
            LOSS_CBAD52,
            LOSS_CBAD53,
            LOSS_CBAD54,
            LOSS_IBAD038,
            LOSS_CBAD999,
            LOSS_CBAD075,
            LOSS_CBAD415,
            LOSS_CBAD074,
            LOSS_CBAD406,
            LOSS_CBAD409,
            LOSS_CBAD412,
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
                btnExcel.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                btnFileManager.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewInspectionDataCountCheck(int iOutPutType)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[15];
                DataTable dt = null;
                string sSql = "";
                string sDbLink = "";
                int index = 0;
                string text = "";
                string text2 = "";
                string sCondition_Value = "";
                string sCondition_Value2 = "";
                string sCondition_Value3 = "";
                string sCondition_Value4 = "";
                string sCondition_Value5 = "";
                string sCondition_Value6 = "";
                string viewID = "";
                DateTime now = DateTime.Now;
                text2 = (rdoSubLossC.Checked ? "C" : (rdoSubLossNum.Checked ? "1" : ((!rdoSubLossNull.Checked) ? "V" : "")));
                text = (rdRound.Checked ? "OC05060" : ((!rdoWd.Checked) ? "ALL" : "OC05070"));
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
                if (rdIJDK1.Checked)
                {
                    array[0].sCondition_ID = "FACTORY";
                    array[0].sCondition_Value = "IJDK1";
                    viewID = ((!(MPGV.gsFactory == "IJDK1")) ? "CQCM3002-006" : "CQCM3002-005");
                }
                else if (rdIJDV1.Checked)
                {
                    array[0].sCondition_ID = "FACTORY";
                    array[0].sCondition_Value = "IJDV1";
                    viewID = ((!(MPGV.gsFactory == "IJDV1")) ? "CQCM3002-006" : "CQCM3002-005");
                }
                array[1].sCondition_ID = "FROM_JUDGE_DATE";
                array[1].sCondition_Value = sCondition_Value;
                array[2].sCondition_ID = "TO_JUDGE_DATE";
                array[2].sCondition_Value = sCondition_Value2;
                array[3].sCondition_ID = "FROM_INSP_REQ_DATE";
                array[3].sCondition_Value = sCondition_Value3;
                array[4].sCondition_ID = "TO_INSP_REQ_DATE";
                array[4].sCondition_Value = sCondition_Value4;
                array[5].sCondition_ID = "INSP_OPER";
                array[5].sCondition_Value = text;
                array[6].sCondition_ID = "MAT_DESC";
                array[6].sCondition_Value = txtMatDesc.Text + "%";
                array[7].sCondition_ID = "LOT_ID";
                array[7].sCondition_Value = txtLotID.Text + "%";
                array[8].sCondition_ID = "INSP_STATUS";
                array[8].sCondition_Value = cdvStatus.Text + "%";
                array[9].sCondition_ID = "SUBLOSS_YN";
                array[9].sCondition_Value = text2;
                array[10].sCondition_ID = "CREATE_CODE";
                array[10].sCondition_Value = cdvOrderType.Text + "%";
                array[11].sCondition_ID = "FROM_OPER_DATE";
                array[11].sCondition_Value = sCondition_Value5;
                array[12].sCondition_ID = "TO_OPER_DATE";
                array[12].sCondition_Value = sCondition_Value6;
                viewDbLink(ref sDbLink);
                array[13].sCondition_ID = "DB_LINK";
                array[13].sCondition_Value = sDbLink;
                array[13].sCondition_Type = "TEXT";
                array[14].sCondition_ID = "LOCAL_FAC";
                array[14].sCondition_Value = MPGV.gsFactory;
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

        private bool viewInspStatusList(ListView listView)
        {
            TRSNode tRSNode = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            MPCF.InitListView(listView);
            MPCR.SetInMsg(tRSNode);
            tRSNode.ProcStep = '1';
            tRSNode.AddString("SQL", "SELECT KEY_1 AS CODE,    DATA_1 AS VALUE  FROM MGCMTBLDAT  WHERE FACTORY = '" + MPGV.gsFactory + "'   AND TABLE_NAME = 'C_INSP_STATUS'   AND KEY_1 != 'C'  ORDER BY DATA_3");
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
                string sDbLink = "";
                int num = 0;
                string text = "";
                string text2 = "";
                string sCondition_Value = "";
                string sCondition_Value2 = "";
                string sCondition_Value3 = "";
                string sCondition_Value4 = "";
                string sCondition_Value5 = "";
                string sCondition_Value6 = "";
                string viewID = "";
                text2 = (rdoSubLossC.Checked ? "C" : (rdoSubLossNum.Checked ? "1" : ((!rdoSubLossNull.Checked) ? "V" : "")));
                text = (rdRound.Checked ? "OC05060" : ((!rdoWd.Checked) ? "ALL" : "OC05070"));
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
                if (rdIJDK1.Checked)
                {
                    array[0].sCondition_ID = "FACTORY";
                    array[0].sCondition_Value = "IJDK1";
                    viewID = ((!(MPGV.gsFactory == "IJDK1")) ? "CQCM3002-004" : "CQCM3002-003");
                }
                else if (rdIJDV1.Checked)
                {
                    array[0].sCondition_ID = "FACTORY";
                    array[0].sCondition_Value = "IJDV1";
                    viewID = ((!(MPGV.gsFactory == "IJDV1")) ? "CQCM3002-004" : "CQCM3002-003");
                }
                array[1].sCondition_ID = "FROM_JUDGE_DATE";
                array[1].sCondition_Value = sCondition_Value;
                array[2].sCondition_ID = "TO_JUDGE_DATE";
                array[2].sCondition_Value = sCondition_Value2;
                array[3].sCondition_ID = "FROM_INSP_REQ_DATE";
                array[3].sCondition_Value = sCondition_Value3;
                array[4].sCondition_ID = "TO_INSP_REQ_DATE";
                array[4].sCondition_Value = sCondition_Value4;
                array[5].sCondition_ID = "INSP_OPER";
                array[5].sCondition_Value = text;
                array[6].sCondition_ID = "MAT_DESC";
                array[6].sCondition_Value = txtMatDesc.Text + "%";
                array[7].sCondition_ID = "LOT_ID";
                array[7].sCondition_Value = txtLotID.Text + "%";
                array[8].sCondition_ID = "INSP_STATUS";
                array[8].sCondition_Value = cdvStatus.Text + "%";
                array[9].sCondition_ID = "SUBLOSS_YN";
                array[9].sCondition_Value = text2;
                array[10].sCondition_ID = "CREATE_CODE";
                array[10].sCondition_Value = cdvOrderType.Text + "%";
                array[11].sCondition_ID = "FROM_OPER_DATE";
                array[11].sCondition_Value = sCondition_Value5;
                array[12].sCondition_ID = "TO_OPER_DATE";
                array[12].sCondition_Value = sCondition_Value6;
                viewDbLink(ref sDbLink);
                array[13].sCondition_ID = "DB_LINK";
                array[13].sCondition_Value = sDbLink;
                array[13].sCondition_Type = "TEXT";
                array[14].sCondition_ID = "LOCAL_FAC";
                array[14].sCondition_Value = MPGV.gsFactory;
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
                    string filePath = Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + "\\RoundInpection_" + dSearchTime.ToString("yyyy-MM-dd_HHmmss") + "\\RoundInpection_" + dateTime.ToString("yyyy-MM-dd_HHmmss") + "~" + dateTime2.ToString("yyyy-MM-dd_HHmmss") + ".csv";
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
                    spdInspectionData.ActiveSheet.Cells[num, 0].Value = dt.Rows[num]["INSP_REQ_TIME"];
                    spdInspectionData.ActiveSheet.Cells[num, 1].Value = dt.Rows[num]["INSP_JUDGE_DATE"];
                    spdInspectionData.ActiveSheet.Cells[num, 2].Value = dt.Rows[num]["INSP_OPER_DATE"];
                    spdInspectionData.ActiveSheet.Cells[num, 3].Value = dt.Rows[num]["INSP_JUDGE_TIME"];
                    spdInspectionData.ActiveSheet.Cells[num, 4].Value = dt.Rows[num]["LOT_ID"];
                    spdInspectionData.ActiveSheet.Cells[num, 5].Value = dt.Rows[num]["INSP_JUDGE_DESC"];
                    spdInspectionData.ActiveSheet.Cells[num, 6].Value = dt.Rows[num]["INSP_JUDGE_NAME_LP"];
                    spdInspectionData.ActiveSheet.Cells[num, 7].Value = dt.Rows[num]["INSP_JUDGE_NAME_ROUND"];
                    spdInspectionData.ActiveSheet.Cells[num, 8].Value = dt.Rows[num]["INSP_JUDGE_NAME_WD"];
                    spdInspectionData.ActiveSheet.Cells[num, 9].Value = dt.Rows[num]["ITEM_CHANGE_COUNT"];
                    spdInspectionData.ActiveSheet.Cells[num, 10].Value = dt.Rows[num]["INSP_MONTH_COUNT_LP"];
                    spdInspectionData.ActiveSheet.Cells[num, 11].Value = dt.Rows[num]["INSP_MONTH_COUNT_ROUND"];
                    spdInspectionData.ActiveSheet.Cells[num, 12].Value = dt.Rows[num]["INSP_MONTH_COUNT_WD"];
                    spdInspectionData.ActiveSheet.Cells[num, 13].Value = dt.Rows[num]["MAT_ID"];
                    spdInspectionData.ActiveSheet.Cells[num, 14].Value = dt.Rows[num]["MAT_DESC"];
                    spdInspectionData.ActiveSheet.Cells[num, 15].Value = dt.Rows[num]["GRADE"];
                    spdInspectionData.ActiveSheet.Cells[num, 16].Value = dt.Rows[num]["SPEC_MAX_D_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[num, 17].Value = dt.Rows[num]["MIN_MAX_D_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[num, 18].Value = dt.Rows[num]["MAX_MAX_D_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[num, 19].Value = dt.Rows[num]["MIN_REAL_D_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[num, 20].Value = dt.Rows[num]["MAX_REAL_D_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[num, 21].Value = dt.Rows[num]["SPEC_ALL_T_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[num, 22].Value = dt.Rows[num]["MIN_ALL_T_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[num, 23].Value = dt.Rows[num]["MAX_ALL_T_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[num, 24].Value = dt.Rows[num]["ALL_T_VALUE_1"];
                    spdInspectionData.ActiveSheet.Cells[num, 25].Value = dt.Rows[num]["ALL_T_VALUE_2"];
                    spdInspectionData.ActiveSheet.Cells[num, 26].Value = dt.Rows[num]["ALL_T_VALUE_3"];
                    spdInspectionData.ActiveSheet.Cells[num, 27].Value = dt.Rows[num]["ALL_T_VALUE_4"];
                    spdInspectionData.ActiveSheet.Cells[num, 28].Value = dt.Rows[num]["ALL_T_VALUE_5"];
                    spdInspectionData.ActiveSheet.Cells[num, 29].Value = dt.Rows[num]["ALL_T_VALUE_6"];
                    spdInspectionData.ActiveSheet.Cells[num, 30].Value = dt.Rows[num]["ALL_T_VALUE_7"];
                    spdInspectionData.ActiveSheet.Cells[num, 31].Value = dt.Rows[num]["ALL_T_VALUE_8"];
                    spdInspectionData.ActiveSheet.Cells[num, 32].Value = dt.Rows[num]["ALL_T_VALUE_9"];
                    spdInspectionData.ActiveSheet.Cells[num, 33].Value = dt.Rows[num]["ALL_T_VALUE_10"];
                    spdInspectionData.ActiveSheet.Cells[num, 34].Value = dt.Rows[num]["ALL_T_VALUE_11"];
                    spdInspectionData.ActiveSheet.Cells[num, 35].Value = dt.Rows[num]["ALL_T_VALUE_12"];
                    spdInspectionData.ActiveSheet.Cells[num, 36].Value = dt.Rows[num]["ALL_T_VALUE_13"];
                    spdInspectionData.ActiveSheet.Cells[num, 37].Value = dt.Rows[num]["SPEC_UT_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[num, 38].Value = dt.Rows[num]["MIN_UT_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[num, 39].Value = dt.Rows[num]["MAX_UT_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[num, 40].Value = dt.Rows[num]["SPEC_FLAT_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[num, 41].Value = dt.Rows[num]["MIN_FLAT_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[num, 42].Value = dt.Rows[num]["MAX_FLAT_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[num, 43].Value = dt.Rows[num]["FLAT_VALUE_1"];
                    spdInspectionData.ActiveSheet.Cells[num, 44].Value = dt.Rows[num]["FLAT_VALUE_2"];
                    spdInspectionData.ActiveSheet.Cells[num, 45].Value = dt.Rows[num]["FLAT_VALUE_3"];
                    spdInspectionData.ActiveSheet.Cells[num, 46].Value = dt.Rows[num]["FLAT_VALUE_4"];
                    spdInspectionData.ActiveSheet.Cells[num, 47].Value = dt.Rows[num]["FLAT_VALUE_5"];
                    spdInspectionData.ActiveSheet.Cells[num, 48].Value = dt.Rows[num]["FLAT_VALUE_6"];
                    spdInspectionData.ActiveSheet.Cells[num, 49].Value = dt.Rows[num]["FLAT_VALUE_7"];
                    spdInspectionData.ActiveSheet.Cells[num, 50].Value = dt.Rows[num]["FLAT_VALUE_8"];
                    spdInspectionData.ActiveSheet.Cells[num, 51].Value = dt.Rows[num]["FLAT_VALUE_9"];
                    spdInspectionData.ActiveSheet.Cells[num, 52].Value = dt.Rows[num]["FLAT_VALUE_10"];
                    spdInspectionData.ActiveSheet.Cells[num, 53].Value = dt.Rows[num]["FLAT_VALUE_11"];
                    spdInspectionData.ActiveSheet.Cells[num, 54].Value = dt.Rows[num]["FLAT_VALUE_12"];
                    spdInspectionData.ActiveSheet.Cells[num, 55].Value = dt.Rows[num]["FLAT_VALUE_13"];
                    spdInspectionData.ActiveSheet.Cells[num, 56].Value = dt.Rows[num]["MAIN_LOSS"];
                    spdInspectionData.ActiveSheet.Cells[num, 57].Value = dt.Rows[num]["SUB_LOSS"];
                    spdInspectionData.ActiveSheet.Cells[num, 58].Value = dt.Rows[num]["LOSS_CBAD003"];
                    spdInspectionData.ActiveSheet.Cells[num, 59].Value = dt.Rows[num]["LOSS_CBAD004"];
                    spdInspectionData.ActiveSheet.Cells[num, 60].Value = dt.Rows[num]["LOSS_CBAD005"];
                    spdInspectionData.ActiveSheet.Cells[num, 61].Value = dt.Rows[num]["LOSS_CBAD006"];
                    spdInspectionData.ActiveSheet.Cells[num, 62].Value = dt.Rows[num]["LOSS_CBAD401"];
                    spdInspectionData.ActiveSheet.Cells[num, 63].Value = dt.Rows[num]["LOSS_CBAD402"];
                    spdInspectionData.ActiveSheet.Cells[num, 64].Value = dt.Rows[num]["LOSS_CBAD007"];
                    spdInspectionData.ActiveSheet.Cells[num, 65].Value = dt.Rows[num]["LOSS_CBAD008"];
                    spdInspectionData.ActiveSheet.Cells[num, 66].Value = dt.Rows[num]["LOSS_CBAD009"];
                    spdInspectionData.ActiveSheet.Cells[num, 67].Value = dt.Rows[num]["LOSS_CBAD011"];
                    spdInspectionData.ActiveSheet.Cells[num, 68].Value = dt.Rows[num]["LOSS_CBAD018"];
                    spdInspectionData.ActiveSheet.Cells[num, 69].Value = dt.Rows[num]["LOSS_CBAD019"];
                    spdInspectionData.ActiveSheet.Cells[num, 70].Value = dt.Rows[num]["LOSS_CBAD020"];
                    spdInspectionData.ActiveSheet.Cells[num, 71].Value = dt.Rows[num]["LOSS_CBAD021"];
                    spdInspectionData.ActiveSheet.Cells[num, 72].Value = dt.Rows[num]["LOSS_CBAD022"];
                    spdInspectionData.ActiveSheet.Cells[num, 73].Value = dt.Rows[num]["LOSS_CBAD024"];
                    spdInspectionData.ActiveSheet.Cells[num, 74].Value = dt.Rows[num]["LOSS_CBAD027"];
                    spdInspectionData.ActiveSheet.Cells[num, 75].Value = dt.Rows[num]["LOSS_CBAD036"];
                    spdInspectionData.ActiveSheet.Cells[num, 76].Value = dt.Rows[num]["LOSS_CBAD037"];
                    spdInspectionData.ActiveSheet.Cells[num, 77].Value = dt.Rows[num]["LOSS_CBAD056"];
                    spdInspectionData.ActiveSheet.Cells[num, 78].Value = dt.Rows[num]["LOSS_CBAD52"];
                    spdInspectionData.ActiveSheet.Cells[num, 79].Value = dt.Rows[num]["LOSS_CBAD53"];
                    spdInspectionData.ActiveSheet.Cells[num, 80].Value = dt.Rows[num]["LOSS_CBAD54"];
                    spdInspectionData.ActiveSheet.Cells[num, 81].Value = dt.Rows[num]["LOSS_IBAD038"];
                    spdInspectionData.ActiveSheet.Cells[num, 82].Value = dt.Rows[num]["LOSS_CBAD999"];
                    spdInspectionData.ActiveSheet.Cells[num, 83].Value = dt.Rows[num]["LOSS_CBAD075"];
                    spdInspectionData.ActiveSheet.Cells[num, 84].Value = dt.Rows[num]["LOSS_CBAD415"];
                    spdInspectionData.ActiveSheet.Cells[num, 85].Value = dt.Rows[num]["LOSS_CBAD074"];
                    spdInspectionData.ActiveSheet.Cells[num, 86].Value = dt.Rows[num]["LOSS_CBAD406"];
                    spdInspectionData.ActiveSheet.Cells[num, 87].Value = dt.Rows[num]["LOSS_CBAD409"];
                    spdInspectionData.ActiveSheet.Cells[num, 88].Value = dt.Rows[num]["LOSS_CBAD412"];
                    spdInspectionData.ActiveSheet.Cells[num, 89].Value = dt.Rows[num]["INSP_COMMENT"];
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmViewInspectionDataRound_Load(object sender, EventArgs e)
        {
            try
            {
                rdoJudge.Checked = true;
                rdRound.Checked = true;
                dtpToJudgeDate.Value = DateTime.Now;
                dtpFromJudgeDate.Value = dtpToJudgeDate.Value.AddDays(-1.0);
                cdvOrderType.Text = "PROD";
                cdvOrderType.DisplayText = "Product Lot";
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
                EXTFUC.SaveExcel(spdInspectionData, "InspectionData(Round)");
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvMat_ButtonPress(object sender, EventArgs e)
        {
        }

        private void cdvMat_TextBoxTextChanged(object sender, EventArgs e)
        {
        }

        private void cdvStatus_ButtonPress(object sender, EventArgs e)
        {
            viewInspStatusList(cdvStatus.GetListView);
            cdvStatus.InsertEmptyRow(0, 1);
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
                frmPopFtpUpDown.g_LotId = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, 4].Text;
                frmPopFtpUpDown.g_Mat_id = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, 13].Text;
                frmPopFtpUpDown.g_Mat_Desc = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, 14].Text;
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
