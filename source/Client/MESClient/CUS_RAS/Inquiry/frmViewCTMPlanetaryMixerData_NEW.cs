using CUS_COM;
using FarPoint.Win.Spread;
using Miracom.CliFrx;
using Miracom.DNMCore;
using System;
using System.Data;
using System.Windows.Forms;

namespace CUS_RAS
{
    public partial class frmViewCTMPlanetaryMixerData_NEW : CUS_COM.frmViewForm03
    {
        //성충헌 과장 요청..차트랑 같이 데이터 보여달라고,차트 출력도 화면과 똑같이 엑셀차트로나오게 요청해서 화면 기존거에서 따로뺌... syw
        public frmViewCTMPlanetaryMixerData_NEW()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum RAS_INFO : int
        {
            RES_ID,
            RES_DESC,
            WORK_DATE,
            WORK_TIME,
            SV_TEMP,
            PV_TEMP,
            LOT_ID,
            MAT_ID,
            MAT_DESC,
            RES_STATUS
        }

        #endregion

        #region " Variable Definition "


        public string g_Dept = string.Empty;
        public string g_DeptDisplay = string.Empty;
        public string g_Oper = string.Empty;
        public string g_OperDisplay = string.Empty;
        public string g_ResId = string.Empty;
        public string g_ResDisplay = string.Empty;
        public string g_searchType = string.Empty;
        public string g_LotId = string.Empty;
        public string g_SearchYn = string.Empty;
        public string g_PopYn = "N";
        public string s_CopyString = string.Empty;

        public string g_Popup_yn = "N";

        #endregion

        #region " Function Definition "
        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnExcel.Anchor = AnchorStyles.Top | AnchorStyles.Right;

                chkAutoRefresh.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                numRefreshSec.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                lblSec.Anchor = AnchorStyles.Top | AnchorStyles.Left;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        public static bool ViewOper(Control control, string sArea_ID)
        {
            try
            {
                ListViewItem itmX;

                System.Data.DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sArea_ID;

                if (TPDR.GetDataOne("", ref dt, "CRAS3014-000", dvcArgu, false, false, ref sSql) == false)
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
                        itmX = new ListViewItem(row["OPER"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

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
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }
        public static bool ViewResID(Control control, string sOperID)
        {
            try
            {
                ListViewItem itmX;

                System.Data.DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = sOperID;

                if (TPDR.GetDataOne("", ref dt, "CRAS3014-003", dvcArgu, false, false, ref sSql) == false)
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
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }
        private void ViewPlanetaryMixerData()
        {
            int i = 0;
            string sSql = "";
            string sViewID = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
                System.Data.DataTable dt = null;

                if (rdoDate.Checked)
                    sViewID = "CRAS3019-001";
                else
                    sViewID = "CRAS3019-002";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text + "%";

                dvcArgu[2].sCondition_ID = "RES_ID";
                dvcArgu[2].sCondition_Value = cdvResId.Text + "%";

                dvcArgu[3].sCondition_ID = "LOT_ID";
                dvcArgu[3].sCondition_Value = txtLotID.Text;

                dvcArgu[4].sCondition_ID = "FROM_DATE";
                dvcArgu[4].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromDate.Text.Trim()) ? "19000101" : dtpFromDate.Text.Replace("-", ""));

                dvcArgu[5].sCondition_ID = "TO_DATE";
                dvcArgu[5].sCondition_Value = dtpToDate.Text.Replace("-", "") + "235959";

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    spdPlanetaryMixer_Sheet2.RowCount = 0;
                    spdPlanetaryMixer_Sheet3.RowCount = 0;
                    spdPlanetaryMixer_Sheet4.RowCount = 0;
                    spdPlanetaryMixer_Sheet5.RowCount = 0;
                    spdPlanetaryMixerData_Sheet1.RowCount = 0;


                    return;
                }


                spdPlanetaryMixer_Sheet2.RowCount = 0;
                spdPlanetaryMixer_Sheet3.RowCount = 0;
                spdPlanetaryMixer_Sheet4.RowCount = 0;
                spdPlanetaryMixer_Sheet5.RowCount = 0;
                spdPlanetaryMixerData_Sheet1.RowCount = 0;


                for (i = 0; i < dt.Rows.Count; i++)
                {

                    switch (dt.Rows[i]["RES_ID"].ToString())
                    {

                        case "E1000034":
                            spdPlanetaryMixer_Sheet2.RowCount++;
                            spdPlanetaryMixer_Sheet2.Cells[spdPlanetaryMixer_Sheet2.RowCount - 1, (int)RAS_INFO.RES_ID].Value = dt.Rows[i]["RES_ID"];
                            spdPlanetaryMixer_Sheet2.Cells[spdPlanetaryMixer_Sheet2.RowCount - 1, (int)RAS_INFO.RES_DESC].Value = dt.Rows[i]["RES_DESC"];
                            spdPlanetaryMixer_Sheet2.Cells[spdPlanetaryMixer_Sheet2.RowCount - 1, (int)RAS_INFO.WORK_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["WORK_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            spdPlanetaryMixer_Sheet2.Cells[spdPlanetaryMixer_Sheet2.RowCount - 1, (int)RAS_INFO.WORK_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["WORK_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                            spdPlanetaryMixer_Sheet2.Cells[spdPlanetaryMixer_Sheet2.RowCount - 1, (int)RAS_INFO.SV_TEMP].Value = dt.Rows[i]["SV_TEMP"];
                            spdPlanetaryMixer_Sheet2.Cells[spdPlanetaryMixer_Sheet2.RowCount - 1, (int)RAS_INFO.PV_TEMP].Value = dt.Rows[i]["PV_TEMP"];
                            spdPlanetaryMixer_Sheet2.Cells[spdPlanetaryMixer_Sheet2.RowCount - 1, (int)RAS_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            spdPlanetaryMixer_Sheet2.Cells[spdPlanetaryMixer_Sheet2.RowCount - 1, (int)RAS_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                            spdPlanetaryMixer_Sheet2.Cells[spdPlanetaryMixer_Sheet2.RowCount - 1, (int)RAS_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                            spdPlanetaryMixer_Sheet2.Cells[spdPlanetaryMixer_Sheet2.RowCount - 1, (int)RAS_INFO.RES_STATUS].Value = dt.Rows[i]["RES_STATUS"];
                            break;
                        case "E1000035":
                            spdPlanetaryMixer_Sheet3.RowCount++;
                            spdPlanetaryMixer_Sheet3.Cells[spdPlanetaryMixer_Sheet3.RowCount - 1, (int)RAS_INFO.RES_ID].Value = dt.Rows[i]["RES_ID"];
                            spdPlanetaryMixer_Sheet3.Cells[spdPlanetaryMixer_Sheet3.RowCount - 1, (int)RAS_INFO.RES_DESC].Value = dt.Rows[i]["RES_DESC"];
                            spdPlanetaryMixer_Sheet3.Cells[spdPlanetaryMixer_Sheet3.RowCount - 1, (int)RAS_INFO.WORK_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["WORK_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            spdPlanetaryMixer_Sheet3.Cells[spdPlanetaryMixer_Sheet3.RowCount - 1, (int)RAS_INFO.WORK_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["WORK_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                            spdPlanetaryMixer_Sheet3.Cells[spdPlanetaryMixer_Sheet3.RowCount - 1, (int)RAS_INFO.SV_TEMP].Value = dt.Rows[i]["SV_TEMP"];
                            spdPlanetaryMixer_Sheet3.Cells[spdPlanetaryMixer_Sheet3.RowCount - 1, (int)RAS_INFO.PV_TEMP].Value = dt.Rows[i]["PV_TEMP"];
                            spdPlanetaryMixer_Sheet3.Cells[spdPlanetaryMixer_Sheet3.RowCount - 1, (int)RAS_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            spdPlanetaryMixer_Sheet3.Cells[spdPlanetaryMixer_Sheet3.RowCount - 1, (int)RAS_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                            spdPlanetaryMixer_Sheet3.Cells[spdPlanetaryMixer_Sheet3.RowCount - 1, (int)RAS_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                            spdPlanetaryMixer_Sheet3.Cells[spdPlanetaryMixer_Sheet3.RowCount - 1, (int)RAS_INFO.RES_STATUS].Value = dt.Rows[i]["RES_STATUS"];
                            break;
                        case "E1000036":
                            spdPlanetaryMixer_Sheet4.RowCount++;
                            spdPlanetaryMixer_Sheet4.Cells[spdPlanetaryMixer_Sheet4.RowCount - 1, (int)RAS_INFO.RES_ID].Value = dt.Rows[i]["RES_ID"];
                            spdPlanetaryMixer_Sheet4.Cells[spdPlanetaryMixer_Sheet4.RowCount - 1, (int)RAS_INFO.RES_DESC].Value = dt.Rows[i]["RES_DESC"];
                            spdPlanetaryMixer_Sheet4.Cells[spdPlanetaryMixer_Sheet4.RowCount - 1, (int)RAS_INFO.WORK_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["WORK_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            spdPlanetaryMixer_Sheet4.Cells[spdPlanetaryMixer_Sheet4.RowCount - 1, (int)RAS_INFO.WORK_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["WORK_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                            spdPlanetaryMixer_Sheet4.Cells[spdPlanetaryMixer_Sheet4.RowCount - 1, (int)RAS_INFO.SV_TEMP].Value = dt.Rows[i]["SV_TEMP"];
                            spdPlanetaryMixer_Sheet4.Cells[spdPlanetaryMixer_Sheet4.RowCount - 1, (int)RAS_INFO.PV_TEMP].Value = dt.Rows[i]["PV_TEMP"];
                            spdPlanetaryMixer_Sheet4.Cells[spdPlanetaryMixer_Sheet4.RowCount - 1, (int)RAS_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            spdPlanetaryMixer_Sheet4.Cells[spdPlanetaryMixer_Sheet4.RowCount - 1, (int)RAS_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                            spdPlanetaryMixer_Sheet4.Cells[spdPlanetaryMixer_Sheet4.RowCount - 1, (int)RAS_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                            spdPlanetaryMixer_Sheet4.Cells[spdPlanetaryMixer_Sheet4.RowCount - 1, (int)RAS_INFO.RES_STATUS].Value = dt.Rows[i]["RES_STATUS"];
                            break;
                        case "E1000037":
                            spdPlanetaryMixer_Sheet5.RowCount++;
                            spdPlanetaryMixer_Sheet5.Cells[spdPlanetaryMixer_Sheet5.RowCount - 1, (int)RAS_INFO.RES_ID].Value = dt.Rows[i]["RES_ID"];
                            spdPlanetaryMixer_Sheet5.Cells[spdPlanetaryMixer_Sheet5.RowCount - 1, (int)RAS_INFO.RES_DESC].Value = dt.Rows[i]["RES_DESC"];
                            spdPlanetaryMixer_Sheet5.Cells[spdPlanetaryMixer_Sheet5.RowCount - 1, (int)RAS_INFO.WORK_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["WORK_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            spdPlanetaryMixer_Sheet5.Cells[spdPlanetaryMixer_Sheet5.RowCount - 1, (int)RAS_INFO.WORK_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["WORK_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                            spdPlanetaryMixer_Sheet5.Cells[spdPlanetaryMixer_Sheet5.RowCount - 1, (int)RAS_INFO.SV_TEMP].Value = dt.Rows[i]["SV_TEMP"];
                            spdPlanetaryMixer_Sheet5.Cells[spdPlanetaryMixer_Sheet5.RowCount - 1, (int)RAS_INFO.PV_TEMP].Value = dt.Rows[i]["PV_TEMP"];
                            spdPlanetaryMixer_Sheet5.Cells[spdPlanetaryMixer_Sheet5.RowCount - 1, (int)RAS_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            spdPlanetaryMixer_Sheet5.Cells[spdPlanetaryMixer_Sheet5.RowCount - 1, (int)RAS_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                            spdPlanetaryMixer_Sheet5.Cells[spdPlanetaryMixer_Sheet5.RowCount - 1, (int)RAS_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                            spdPlanetaryMixer_Sheet5.Cells[spdPlanetaryMixer_Sheet5.RowCount - 1, (int)RAS_INFO.RES_STATUS].Value = dt.Rows[i]["RES_STATUS"];
                            break;

                    }





                }

                //  chertDataSetup();

                chartDatagrid("", -1);

                switch (cdvResId.Text.Trim())
                {
                    case "E1000034":
                        chartDatagrid("E1000034", -1);
                        SheetDataCopy(spdPlanetaryMixer_Sheet2);
                        break;

                    case "E1000035":
                        chartDatagrid("E1000035", -1);
                        SheetDataCopy(spdPlanetaryMixer_Sheet3);
                        break;

                    case "E1000036":
                        chartDatagrid("E1000036", -1);
                        SheetDataCopy(spdPlanetaryMixer_Sheet4);
                        break;

                    case "E1000037":
                        chartDatagrid("E1000037", -1);
                        SheetDataCopy(spdPlanetaryMixer_Sheet5);
                        break;
                    default:
                        chartDatagrid("E1000034", -1);
                        SheetDataCopy(spdPlanetaryMixer_Sheet2);
                        break;
                }

                ChartMachineSelect(cdvResId.Text.Trim());



                //     MPCF.FitColumnHeader(spdPlanetaryMixer);

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
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

                        if (MPCF.Trim(cdvOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvOper.Focus();
                            return false;
                        }

                        /*
                        if (MPCF.Trim(cdvResId.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblRes.Text + "]");
                            cdvResId.Focus();
                            return false;
                        }
                        */
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
        private void ClearData()
        {
            try
            {
                // MPCF.ClearList(spdPlanetaryMixer);
                spdPlanetaryMixer_Sheet2.RowCount = 0;
                spdPlanetaryMixer_Sheet3.RowCount = 0;
                spdPlanetaryMixer_Sheet4.RowCount = 0;
                spdPlanetaryMixer_Sheet5.RowCount = 0;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void SheetDataCopy(SheetView oSheet)
        {
            try
            {
                if (oSheet.RowCount == 0)
                {
                    spdPlanetaryMixerData_Sheet1.RowCount = 0;
                    return;
                }



                spdPlanetaryMixerData_Sheet1.RowCount = 0;
                spdPlanetaryMixerData_Sheet1.RowCount = oSheet.RowCount;
                /*     spdPlanetaryMixerData_Sheet1.Cells[0, 0, oSheet.RowCount - 1, oSheet.ColumnCount - 1].Value = oSheet.Cells[0, 0, oSheet.RowCount - 1, oSheet.ColumnCount - 1].Value;*/

                for (int iRow = 0; iRow < oSheet.RowCount; iRow++)
                {
                    for (int iCol = 0; iCol < oSheet.ColumnCount; iCol++)
                    {
                        spdPlanetaryMixerData_Sheet1.Cells[iRow, iCol].Value = oSheet.Cells[iRow, iCol].Value;
                    }
                }
                /*
                                FarPoint.Win.Spread.Model.CellRange range =
                                                           new FarPoint.Win.Spread.Model.CellRange(0, 0, oSheet.RowCount, oSheet.ColumnCount);



                                oSheet.ClipboardCopy(range, FarPoint.Win.Spread.ClipboardCopyOptions.All);
                                spdPlanetaryMixerData_Sheet1.AddSelection(0, 0, spdPlanetaryMixerData_Sheet1.RowCount, spdPlanetaryMixerData_Sheet1.ColumnCount);
                                spdPlanetaryMixerData_Sheet1.ClipboardPaste();
                      */



            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void chartDatagrid(string sMachine, int iRow)
        {



            FarPoint.Win.Chart.LineSeries lineSeries1 = new FarPoint.Win.Chart.LineSeries();
            FarPoint.Win.Chart.LabelArea labelArea1 = new FarPoint.Win.Chart.LabelArea();
            FarPoint.Win.Chart.LabelArea labelArea2 = new FarPoint.Win.Chart.LabelArea();
            FarPoint.Win.Chart.LabelArea labelArea3 = new FarPoint.Win.Chart.LabelArea();
            FarPoint.Win.Chart.LegendArea legendArea1 = new FarPoint.Win.Chart.LegendArea();
            FarPoint.Win.Chart.YPlotArea yPlotArea1 = new FarPoint.Win.Chart.YPlotArea();
            FarPoint.Win.Chart.Wall wall1 = new FarPoint.Win.Chart.Wall();
            FarPoint.Win.Chart.Wall wall2 = new FarPoint.Win.Chart.Wall();
            FarPoint.Win.Chart.DirectionalLight directionalLight1 = new FarPoint.Win.Chart.DirectionalLight();
            FarPoint.Win.Chart.LineSeries lineSeries2 = new FarPoint.Win.Chart.LineSeries();
            FarPoint.Win.Chart.LineSeries lineSeries3 = new FarPoint.Win.Chart.LineSeries();
            FarPoint.Win.Chart.Wall wall3 = new FarPoint.Win.Chart.Wall();
            FarPoint.Win.Chart.IndexAxis indexAxis1 = new FarPoint.Win.Chart.IndexAxis();
            FarPoint.Win.Chart.ValueAxis valueAxis1 = new FarPoint.Win.Chart.ValueAxis();
            FarPoint.Win.Chart.IndexAxis indexAxis2 = new FarPoint.Win.Chart.IndexAxis();
            FarPoint.Win.Chart.LineSeries lineSeries4 = new FarPoint.Win.Chart.LineSeries();
            FarPoint.Win.Chart.LabelArea labelArea4 = new FarPoint.Win.Chart.LabelArea();
            FarPoint.Win.Chart.LabelArea labelArea5 = new FarPoint.Win.Chart.LabelArea();
            FarPoint.Win.Chart.LabelArea labelArea6 = new FarPoint.Win.Chart.LabelArea();
            FarPoint.Win.Chart.LegendArea legendArea2 = new FarPoint.Win.Chart.LegendArea();
            FarPoint.Win.Chart.YPlotArea yPlotArea2 = new FarPoint.Win.Chart.YPlotArea();
            FarPoint.Win.Chart.Wall wall4 = new FarPoint.Win.Chart.Wall();
            FarPoint.Win.Chart.Wall wall5 = new FarPoint.Win.Chart.Wall();
            FarPoint.Win.Chart.DirectionalLight directionalLight2 = new FarPoint.Win.Chart.DirectionalLight();
            FarPoint.Win.Chart.LineSeries lineSeries5 = new FarPoint.Win.Chart.LineSeries();
            FarPoint.Win.Chart.LineSeries lineSeries6 = new FarPoint.Win.Chart.LineSeries();
            FarPoint.Win.Chart.Wall wall6 = new FarPoint.Win.Chart.Wall();
            FarPoint.Win.Chart.IndexAxis indexAxis3 = new FarPoint.Win.Chart.IndexAxis();
            FarPoint.Win.Chart.ValueAxis valueAxis2 = new FarPoint.Win.Chart.ValueAxis();
            FarPoint.Win.Chart.IndexAxis indexAxis4 = new FarPoint.Win.Chart.IndexAxis();
            FarPoint.Win.Chart.LineSeries lineSeries7 = new FarPoint.Win.Chart.LineSeries();
            FarPoint.Win.Chart.LabelArea labelArea7 = new FarPoint.Win.Chart.LabelArea();
            FarPoint.Win.Chart.LabelArea labelArea8 = new FarPoint.Win.Chart.LabelArea();
            FarPoint.Win.Chart.LabelArea labelArea9 = new FarPoint.Win.Chart.LabelArea();
            FarPoint.Win.Chart.LegendArea legendArea3 = new FarPoint.Win.Chart.LegendArea();
            FarPoint.Win.Chart.YPlotArea yPlotArea3 = new FarPoint.Win.Chart.YPlotArea();
            FarPoint.Win.Chart.Wall wall7 = new FarPoint.Win.Chart.Wall();
            FarPoint.Win.Chart.Wall wall8 = new FarPoint.Win.Chart.Wall();
            FarPoint.Win.Chart.DirectionalLight directionalLight3 = new FarPoint.Win.Chart.DirectionalLight();
            FarPoint.Win.Chart.LineSeries lineSeries8 = new FarPoint.Win.Chart.LineSeries();
            FarPoint.Win.Chart.LineSeries lineSeries9 = new FarPoint.Win.Chart.LineSeries();
            FarPoint.Win.Chart.Wall wall9 = new FarPoint.Win.Chart.Wall();
            FarPoint.Win.Chart.IndexAxis indexAxis5 = new FarPoint.Win.Chart.IndexAxis();
            FarPoint.Win.Chart.ValueAxis valueAxis3 = new FarPoint.Win.Chart.ValueAxis();
            FarPoint.Win.Chart.IndexAxis indexAxis6 = new FarPoint.Win.Chart.IndexAxis();
            FarPoint.Win.Chart.LineSeries lineSeries10 = new FarPoint.Win.Chart.LineSeries();
            FarPoint.Win.Chart.LabelArea labelArea10 = new FarPoint.Win.Chart.LabelArea();
            FarPoint.Win.Chart.LabelArea labelArea11 = new FarPoint.Win.Chart.LabelArea();
            FarPoint.Win.Chart.LabelArea labelArea12 = new FarPoint.Win.Chart.LabelArea();
            FarPoint.Win.Chart.LegendArea legendArea4 = new FarPoint.Win.Chart.LegendArea();
            FarPoint.Win.Chart.YPlotArea yPlotArea4 = new FarPoint.Win.Chart.YPlotArea();
            FarPoint.Win.Chart.Wall wall10 = new FarPoint.Win.Chart.Wall();
            FarPoint.Win.Chart.Wall wall11 = new FarPoint.Win.Chart.Wall();
            FarPoint.Win.Chart.DirectionalLight directionalLight4 = new FarPoint.Win.Chart.DirectionalLight();
            FarPoint.Win.Chart.LineSeries lineSeries11 = new FarPoint.Win.Chart.LineSeries();
            FarPoint.Win.Chart.LineSeries lineSeries12 = new FarPoint.Win.Chart.LineSeries();
            FarPoint.Win.Chart.Wall wall12 = new FarPoint.Win.Chart.Wall();
            FarPoint.Win.Chart.IndexAxis indexAxis7 = new FarPoint.Win.Chart.IndexAxis();
            FarPoint.Win.Chart.ValueAxis valueAxis4 = new FarPoint.Win.Chart.ValueAxis();
            FarPoint.Win.Chart.IndexAxis indexAxis8 = new FarPoint.Win.Chart.IndexAxis();


            // spdPlanetaryMixer_Sheet1_SpreadChart1
            // 
            this.spdPlanetaryMixer_Sheet1_SpreadChart1.ChartName = "SpreadChart1";
            this.spdPlanetaryMixer_Sheet1_SpreadChart1.ContextMenuStrip = this.spreadChartContextMenuStrip1;
            this.spdPlanetaryMixer_Sheet1_SpreadChart1.IgnoreUpdateShapeLocation = false;
            this.spdPlanetaryMixer_Sheet1_SpreadChart1.IsGrayscale = false;

            labelArea1.AlignmentX = 0.5F;
            labelArea1.Location = new System.Drawing.PointF(0.5F, 0.02F);
            labelArea1.ManualLayout = false;
            labelArea1.Padding = new FarPoint.Win.Chart.PaddingF(1.5F, 1.5F, 1.5F, 1.5F);
            labelArea1.Text = "CTM_Planetary Mixer #1";
            labelArea2.AlignmentX = 0.5F;
            labelArea2.Location = new System.Drawing.PointF(0.03106335F, 0.2838837F);
            labelArea2.ManualLayout = true;
            labelArea2.Padding = new FarPoint.Win.Chart.PaddingF(1.5F, 1.5F, 1.5F, 1.5F);
            labelArea2.Text = "온도 (℃)";
            labelArea2.TextDirection = FarPoint.Win.Chart.TextDirection.Rotate270Degree;
            labelArea3.AlignmentX = 0.5F;
            labelArea3.Location = new System.Drawing.PointF(0.4F, 0.90F);
            labelArea3.ManualLayout = true;
            labelArea3.Padding = new FarPoint.Win.Chart.PaddingF(1.5F, 1.5F, 1.5F, 1.5F);
            labelArea3.Text = "가동시간";
            this.spdPlanetaryMixer_Sheet1_SpreadChart4.Model.LabelAreas.Clear();
            this.spdPlanetaryMixer_Sheet1_SpreadChart4.Model.LabelAreas.AddRange(new FarPoint.Win.Chart.LabelArea[] {
            labelArea1,
            labelArea2,
            labelArea3});


            //   legendArea1.Padding = new FarPoint.Win.Chart.PaddingF(3F, 3F, 3F, 3F);
            //   this.spdPlanetaryMixer_Sheet1_SpreadChart1.Model.LegendAreas.AddRange(new FarPoint.Win.Chart.LegendArea[] {
            //    legendArea1});
            ((System.ComponentModel.ISupportInitialize)(yPlotArea1)).BeginInit();

            wall1.Visible = true;
            yPlotArea1.BackWall = wall1;
            wall2.Visible = true;
            yPlotArea1.BottomWall = wall2;
            yPlotArea1.Elevation = 15F;
            yPlotArea1.GlobalAmbientLight = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(50)))), ((int)(((byte)(50)))));
            directionalLight1.AmbientColor = System.Drawing.Color.Gray;
            directionalLight1.DiffuseColor = System.Drawing.Color.Gray;
            directionalLight1.DirectionX = 10F;
            directionalLight1.DirectionY = 20F;
            directionalLight1.DirectionZ = 30F;
            directionalLight1.SpecularColor = System.Drawing.Color.Black;
            yPlotArea1.Lights.Clear();
            yPlotArea1.Lights.AddRange(new FarPoint.Win.Chart.Light[] {
            directionalLight1});
            yPlotArea1.Location = new System.Drawing.PointF(0.09271692F, 0.07545309F);
            yPlotArea1.Projection = new FarPoint.Win.Chart.OrthogonalProjection();
            yPlotArea1.Size = new System.Drawing.SizeF(0.8714088F, 0.4976179F);
            yPlotArea1.Projection = new FarPoint.Win.Chart.OrthogonalProjection();
            yPlotArea1.Rotation = -21F;
            lineSeries2.CategoryNames.DataField = "";
            lineSeries2.CategoryNames.DataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldCategoryName", "\'1\'!$D$1:$D$" + spdPlanetaryMixer_Sheet2.RowCount.ToString(), FarPoint.Win.Spread.Chart.SegmentDataType.Text, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Vertical);
            lineSeries2.PointMarker = new FarPoint.Win.Chart.NoMarker();
            lineSeries2.SeriesName = "설정온도";
            lineSeries2.SeriesNameDataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldSeriesName", "\"설정온도\"", FarPoint.Win.Spread.Chart.SegmentDataType.Text, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Vertical);
            lineSeries2.Values.DataField = "";
            lineSeries2.Values.DataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldValue", "\'1\'!$E$1:$E$" + spdPlanetaryMixer_Sheet2.RowCount.ToString(), FarPoint.Win.Spread.Chart.SegmentDataType.Number, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Vertical);
            lineSeries3.CategoryNames.DataField = "";
            lineSeries3.CategoryNames.DataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldCategoryName", "\'1\'!$D$1:$D$" + spdPlanetaryMixer_Sheet2.RowCount.ToString(), FarPoint.Win.Spread.Chart.SegmentDataType.Text, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Vertical);
            lineSeries3.PointMarker = new FarPoint.Win.Chart.NoMarker();
            if (iRow >= 0 && sMachine == "E1000034")
            {
                lineSeries3.PointFills.SetFill(iRow, new FarPoint.Win.Chart.SolidFill(System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))))));
                lineSeries3.PointMarkers.SetMarker(iRow, new FarPoint.Win.Chart.BuiltinMarker(FarPoint.Win.Chart.MarkerShape.Square, 10F));
            }


            lineSeries3.SeriesName = "실제온도";
            lineSeries3.SeriesNameDataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldSeriesName", "\"실제온도\"", FarPoint.Win.Spread.Chart.SegmentDataType.Text, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Vertical);
            lineSeries3.Values.DataField = "";
            lineSeries3.Values.DataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldValue", "\'1\'!$F$1:$F$" + spdPlanetaryMixer_Sheet2.RowCount.ToString(), FarPoint.Win.Spread.Chart.SegmentDataType.Number, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Vertical);







            yPlotArea1.Series.AddRange(new FarPoint.Win.Chart.Series[] {
            lineSeries2,
            lineSeries3});
            wall3.Visible = true;
            yPlotArea1.SideWall = wall3;
            indexAxis1.LabelTextDirection = FarPoint.Win.Chart.TextDirection.Rotate90Degree;

            if (splitContainer1.Panel1.Width > (spdPlanetaryMixer_Sheet2.RowCount * 15))
            {
                indexAxis1.AutoLabelUnit = true;
                indexAxis1.LabelUnit = 1;
            }
            else
            {
                indexAxis1.AutoLabelUnit = false;
                indexAxis1.LabelUnit = Math.Round(MPCF.ToDbl(spdPlanetaryMixer_Sheet2.RowCount / 20), 1);

            }
            if (txtAxisValue.Text.Trim() == "")
            {
                valueAxis1.AutoMaximum = true;
                valueAxis1.Maximum = 1;
            }
            else
            {
                valueAxis1.AutoMaximum = false;
                valueAxis1.Maximum = MPCF.ToDbl(txtAxisValue.Text);
            }



            /*
                if (spdPlanetaryMixer_Sheet2.RowCount <= 20)
            {
                indexAxis1.AutoLabelUnit = true;
                indexAxis1.LabelUnit = 1;
            }
            else
            {
                indexAxis1.AutoLabelUnit = false;
                indexAxis1.LabelUnit = Math.Round(MPCF.ToDbl(spdPlanetaryMixer_Sheet2.RowCount / 20), 1);
            }
         */




            yPlotArea1.XAxis = indexAxis1;
            yPlotArea1.YAxes.Clear();
            yPlotArea1.YAxes.AddRange(new FarPoint.Win.Chart.ValueAxis[] {
            valueAxis1});
            yPlotArea1.ZAxis = indexAxis2;
            ((System.ComponentModel.ISupportInitialize)(yPlotArea1)).EndInit();
            this.spdPlanetaryMixer_Sheet1_SpreadChart1.Model.PlotAreas.Clear();
            this.spdPlanetaryMixer_Sheet1_SpreadChart1.Model.PlotAreas.AddRange(new FarPoint.Win.Chart.PlotArea[] {
            yPlotArea1});
            this.spdPlanetaryMixer_Sheet1_SpreadChart1.Rectangle = new System.Drawing.Rectangle(5, 1, 707, 341);
            this.spdPlanetaryMixer_Sheet1_SpreadChart1.SheetName = "spdPlanetaryMixer_Sheet1";
            this.spdPlanetaryMixer_Sheet1_SpreadChart1.SizeProportional = true;
            // 
            // spdPlanetaryMixer_Sheet1_SpreadChart2
            // 
            this.spdPlanetaryMixer_Sheet1_SpreadChart2.ChartName = "SpreadChart2";
            this.spdPlanetaryMixer_Sheet1_SpreadChart2.ContextMenuStrip = this.spreadChartContextMenuStrip2;
            this.spdPlanetaryMixer_Sheet1_SpreadChart2.IgnoreUpdateShapeLocation = false;
            this.spdPlanetaryMixer_Sheet1_SpreadChart2.IsGrayscale = false;


            labelArea4.AlignmentX = 0.5F;
            labelArea4.Location = new System.Drawing.PointF(0.5F, 0.02F);
            labelArea4.ManualLayout = false;
            labelArea4.Padding = new FarPoint.Win.Chart.PaddingF(1.5F, 1.5F, 1.5F, 1.5F);
            labelArea4.Text = "CTM_Planetary Mixer #2";
            labelArea5.AlignmentX = 0.5F;
            labelArea5.Location = new System.Drawing.PointF(0.03106335F, 0.2838837F);
            labelArea5.ManualLayout = true;
            labelArea5.Padding = new FarPoint.Win.Chart.PaddingF(1.5F, 1.5F, 1.5F, 1.5F);
            labelArea5.Text = "온도 (℃)";
            labelArea5.TextDirection = FarPoint.Win.Chart.TextDirection.Rotate270Degree;
            labelArea6.AlignmentX = 0.5F;
            labelArea6.Location = new System.Drawing.PointF(0.4F, 0.90F);
            labelArea6.ManualLayout = true;
            labelArea6.Padding = new FarPoint.Win.Chart.PaddingF(1.5F, 1.5F, 1.5F, 1.5F);
            labelArea6.Text = "가동시간";
            this.spdPlanetaryMixer_Sheet1_SpreadChart2.Model.LabelAreas.Clear();
            this.spdPlanetaryMixer_Sheet1_SpreadChart2.Model.LabelAreas.AddRange(new FarPoint.Win.Chart.LabelArea[] {
          labelArea4,
          labelArea5,
          labelArea6});


            //   legendArea2.Padding = new FarPoint.Win.Chart.PaddingF(3F, 3F, 3F, 3F);
            //   this.spdPlanetaryMixer_Sheet1_SpreadChart2.Model.LegendAreas.AddRange(new FarPoint.Win.Chart.LegendArea[] {
            //    legendArea2});
            ((System.ComponentModel.ISupportInitialize)(yPlotArea2)).BeginInit();
            wall4.Visible = true;
            yPlotArea2.BackWall = wall4;
            wall5.Visible = true;
            yPlotArea2.BottomWall = wall5;
            yPlotArea2.Elevation = 15F;
            yPlotArea2.GlobalAmbientLight = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(50)))), ((int)(((byte)(50)))));
            directionalLight2.AmbientColor = System.Drawing.Color.Gray;
            directionalLight2.DiffuseColor = System.Drawing.Color.Gray;
            directionalLight2.DirectionX = 10F;
            directionalLight2.DirectionY = 20F;
            directionalLight2.DirectionZ = 30F;
            directionalLight2.SpecularColor = System.Drawing.Color.Black;
            yPlotArea2.Lights.Clear();
            yPlotArea2.Lights.AddRange(new FarPoint.Win.Chart.Light[] {
          directionalLight2});
            yPlotArea2.Location = new System.Drawing.PointF(0.09271692F, 0.07545309F);
            yPlotArea2.Projection = new FarPoint.Win.Chart.OrthogonalProjection();
            yPlotArea2.Size = new System.Drawing.SizeF(0.8714088F, 0.4976179F);
            yPlotArea2.Projection = new FarPoint.Win.Chart.OrthogonalProjection();
            yPlotArea2.Rotation = -21F;
            lineSeries5.CategoryNames.DataField = "";
            lineSeries5.CategoryNames.DataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldCategoryName", "\'2\'!$D$1:$D$" + spdPlanetaryMixer_Sheet3.RowCount.ToString(), FarPoint.Win.Spread.Chart.SegmentDataType.Text, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Vertical);
            lineSeries5.PointMarker = new FarPoint.Win.Chart.NoMarker();
            lineSeries5.SeriesName = "설정온도";
            lineSeries5.SeriesNameDataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldSeriesName", "\"설정온도\"", FarPoint.Win.Spread.Chart.SegmentDataType.Text, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Horizontal);
            lineSeries5.Values.DataField = "";
            lineSeries5.Values.DataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldValue", "\'2\'!$E$1:$E$" + spdPlanetaryMixer_Sheet3.RowCount.ToString(), FarPoint.Win.Spread.Chart.SegmentDataType.Number, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Vertical);
            lineSeries6.CategoryNames.DataField = "";
            lineSeries6.CategoryNames.DataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldCategoryName", "\'2\'!$D$1:$D$" + spdPlanetaryMixer_Sheet3.RowCount.ToString(), FarPoint.Win.Spread.Chart.SegmentDataType.Text, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Vertical);
            lineSeries6.PointMarker = new FarPoint.Win.Chart.NoMarker();

            if (iRow >= 0 && sMachine == "E1000035")
            {
                lineSeries6.PointFills.SetFill(iRow, new FarPoint.Win.Chart.SolidFill(System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))))));
                lineSeries6.PointMarkers.SetMarker(iRow, new FarPoint.Win.Chart.BuiltinMarker(FarPoint.Win.Chart.MarkerShape.Square, 10F));
            }

            lineSeries6.SeriesName = "실제온도";
            lineSeries6.SeriesNameDataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldSeriesName", "\"실제온도\"", FarPoint.Win.Spread.Chart.SegmentDataType.Text, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Horizontal);
            lineSeries6.Values.DataField = "";
            lineSeries6.Values.DataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldValue", "\'2\'!$F$1:$F$" + spdPlanetaryMixer_Sheet3.RowCount.ToString(), FarPoint.Win.Spread.Chart.SegmentDataType.Number, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Vertical);
            yPlotArea2.Series.AddRange(new FarPoint.Win.Chart.Series[] {
          lineSeries5,
          lineSeries6});
            wall6.Visible = true;
            yPlotArea2.SideWall = wall6;
            indexAxis3.LabelTextDirection = FarPoint.Win.Chart.TextDirection.Rotate90Degree;

            if (splitContainer1.Panel1.Width > (spdPlanetaryMixer_Sheet3.RowCount * 15))
            {
                indexAxis3.AutoLabelUnit = true;
                indexAxis3.LabelUnit = 1;
            }
            else
            {
                indexAxis3.AutoLabelUnit = false;
                indexAxis3.LabelUnit = Math.Round(MPCF.ToDbl(spdPlanetaryMixer_Sheet3.RowCount / 20), 1);

            }

            if (txtAxisValue.Text.Trim() == "")
            {
                valueAxis2.AutoMaximum = true;
                valueAxis2.Maximum = 1;
            }
            else
            {
                valueAxis2.AutoMaximum = false;
                valueAxis2.Maximum = MPCF.ToDbl(txtAxisValue.Text);
            }

            /*
            if (spdPlanetaryMixer_Sheet3.RowCount <= 20)
            {
                indexAxis7.AutoLabelUnit = true;
                indexAxis3.LabelUnit = 1;
            }
            else
            {
                indexAxis7.AutoLabelUnit = false;
                indexAxis3.LabelUnit = Math.Round(MPCF.ToDbl(spdPlanetaryMixer_Sheet3.RowCount / 20), 1);
            }
            */

            yPlotArea2.XAxis = indexAxis3;
            yPlotArea2.YAxes.Clear();
            yPlotArea2.YAxes.AddRange(new FarPoint.Win.Chart.ValueAxis[] {
          valueAxis2});
            yPlotArea2.ZAxis = indexAxis4;
            ((System.ComponentModel.ISupportInitialize)(yPlotArea2)).EndInit();
            this.spdPlanetaryMixer_Sheet1_SpreadChart2.Model.PlotAreas.Clear();
            this.spdPlanetaryMixer_Sheet1_SpreadChart2.Model.PlotAreas.AddRange(new FarPoint.Win.Chart.PlotArea[] {
          yPlotArea2});
            this.spdPlanetaryMixer_Sheet1_SpreadChart2.Rectangle = new System.Drawing.Rectangle(0, 400, 707, 341);
            this.spdPlanetaryMixer_Sheet1_SpreadChart2.SheetName = "spdPlanetaryMixer_Sheet1";
            this.spdPlanetaryMixer_Sheet1_SpreadChart2.SizeProportional = true;
            // 
            // spdPlanetaryMixer_Sheet1_SpreadChart3
            // 
            this.spdPlanetaryMixer_Sheet1_SpreadChart3.ChartName = "SpreadChart3";
            this.spdPlanetaryMixer_Sheet1_SpreadChart3.ContextMenuStrip = this.spreadChartContextMenuStrip3;
            this.spdPlanetaryMixer_Sheet1_SpreadChart3.IgnoreUpdateShapeLocation = false;
            this.spdPlanetaryMixer_Sheet1_SpreadChart3.IsGrayscale = false;

            labelArea7.AlignmentX = 0.5F;
            labelArea7.Location = new System.Drawing.PointF(0.5F, 0.02F);
            labelArea7.ManualLayout = false;
            labelArea7.Padding = new FarPoint.Win.Chart.PaddingF(1.5F, 1.5F, 1.5F, 1.5F);
            labelArea7.Text = "CTM_Planetary Mixer #3";
            labelArea8.AlignmentX = 0.5F;
            labelArea8.Location = new System.Drawing.PointF(0.03106335F, 0.2838837F);
            labelArea8.ManualLayout = true;
            labelArea8.Padding = new FarPoint.Win.Chart.PaddingF(1.5F, 1.5F, 1.5F, 1.5F);
            labelArea8.Text = "온도 (℃)";
            labelArea8.TextDirection = FarPoint.Win.Chart.TextDirection.Rotate270Degree;
            labelArea9.AlignmentX = 0.5F;
            labelArea9.Location = new System.Drawing.PointF(0.4F, 0.90F);
            labelArea9.ManualLayout = true;
            labelArea9.Padding = new FarPoint.Win.Chart.PaddingF(1.5F, 1.5F, 1.5F, 1.5F);
            labelArea9.Text = "가동시간";
            this.spdPlanetaryMixer_Sheet1_SpreadChart3.Model.LabelAreas.Clear();
            this.spdPlanetaryMixer_Sheet1_SpreadChart3.Model.LabelAreas.AddRange(new FarPoint.Win.Chart.LabelArea[] {
        labelArea7,
        labelArea8,
        labelArea9});



            //     legendArea3.Padding = new FarPoint.Win.Chart.PaddingF(3F, 3F, 3F, 3F);
            //     this.spdPlanetaryMixer_Sheet1_SpreadChart3.Model.LegendAreas.AddRange(new FarPoint.Win.Chart.LegendArea[] {
            //      legendArea3});
            ((System.ComponentModel.ISupportInitialize)(yPlotArea3)).BeginInit();
            wall7.Visible = true;
            yPlotArea3.BackWall = wall7;
            wall8.Visible = true;
            yPlotArea3.BottomWall = wall8;
            yPlotArea3.Elevation = 15F;
            yPlotArea3.GlobalAmbientLight = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(50)))), ((int)(((byte)(50)))));
            directionalLight3.AmbientColor = System.Drawing.Color.Gray;
            directionalLight3.DiffuseColor = System.Drawing.Color.Gray;
            directionalLight3.DirectionX = 10F;
            directionalLight3.DirectionY = 20F;
            directionalLight3.DirectionZ = 30F;
            directionalLight3.SpecularColor = System.Drawing.Color.Black;
            yPlotArea3.Lights.Clear();
            yPlotArea3.Lights.AddRange(new FarPoint.Win.Chart.Light[] {
        directionalLight3});
            yPlotArea3.Location = new System.Drawing.PointF(0.09271692F, 0.07545309F);
            yPlotArea3.Projection = new FarPoint.Win.Chart.OrthogonalProjection();
            yPlotArea3.Size = new System.Drawing.SizeF(0.8714088F, 0.4976179F);
            yPlotArea3.Projection = new FarPoint.Win.Chart.OrthogonalProjection();
            yPlotArea3.Rotation = -21F;
            lineSeries8.CategoryNames.DataField = "";
            lineSeries8.CategoryNames.DataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldCategoryName", "\'3\'!$D$1:$D$" + spdPlanetaryMixer_Sheet4.RowCount.ToString(), FarPoint.Win.Spread.Chart.SegmentDataType.Text, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Vertical);
            lineSeries8.PointMarker = new FarPoint.Win.Chart.NoMarker();
            lineSeries8.SeriesName = "설정온도";
            lineSeries8.SeriesNameDataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldSeriesName", "\"설정온도\"", FarPoint.Win.Spread.Chart.SegmentDataType.Text, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Horizontal);
            lineSeries8.Values.DataField = "";
            lineSeries8.Values.DataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldValue", "\'3\'!$E$1:$E$" + spdPlanetaryMixer_Sheet4.RowCount.ToString(), FarPoint.Win.Spread.Chart.SegmentDataType.Number, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Vertical);
            lineSeries9.CategoryNames.DataField = "";
            lineSeries9.CategoryNames.DataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldCategoryName", "\'3\'!$D$1:$D$" + spdPlanetaryMixer_Sheet4.RowCount.ToString(), FarPoint.Win.Spread.Chart.SegmentDataType.Text, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Vertical);
            lineSeries9.PointMarker = new FarPoint.Win.Chart.NoMarker();

            if (iRow >= 0 && sMachine == "E1000036")
            {
                lineSeries9.PointFills.SetFill(iRow, new FarPoint.Win.Chart.SolidFill(System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))))));
                lineSeries9.PointMarkers.SetMarker(iRow, new FarPoint.Win.Chart.BuiltinMarker(FarPoint.Win.Chart.MarkerShape.Square, 10F));
            }

            lineSeries9.SeriesName = "실제온도";
            lineSeries9.SeriesNameDataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldSeriesName", "\"실제온도\"", FarPoint.Win.Spread.Chart.SegmentDataType.Text, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Horizontal);
            lineSeries9.Values.DataField = "";
            lineSeries9.Values.DataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldValue", "\'3\'!$F$1:$F$" + spdPlanetaryMixer_Sheet4.RowCount.ToString(), FarPoint.Win.Spread.Chart.SegmentDataType.Number, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Vertical);
            yPlotArea3.Series.AddRange(new FarPoint.Win.Chart.Series[] {
        lineSeries8,
        lineSeries9});
            wall9.Visible = true;
            yPlotArea3.SideWall = wall9;
            indexAxis5.LabelTextDirection = FarPoint.Win.Chart.TextDirection.Rotate90Degree;



            if (splitContainer1.Panel1.Width > (spdPlanetaryMixer_Sheet4.RowCount * 15))
            {
                indexAxis5.AutoLabelUnit = true;
                indexAxis5.LabelUnit = 1;
            }
            else
            {
                indexAxis5.AutoLabelUnit = false;
                indexAxis5.LabelUnit = Math.Round(MPCF.ToDbl(spdPlanetaryMixer_Sheet4.RowCount / 20), 1);

            }

            if (txtAxisValue.Text.Trim() == "")
            {
                valueAxis3.AutoMaximum = true;
                valueAxis3.Maximum = 1;
            }
            else
            {
                valueAxis3.AutoMaximum = false;
                valueAxis3.Maximum = MPCF.ToDbl(txtAxisValue.Text);
            }

            /*
            if (spdPlanetaryMixer_Sheet4.RowCount <= 20)
            {
                indexAxis7.AutoLabelUnit = true;
                indexAxis7.LabelUnit = 1;
            }
            else
            {
                indexAxis7.AutoLabelUnit = false;
                indexAxis7.LabelUnit = Math.Round(MPCF.ToDbl(spdPlanetaryMixer_Sheet4.RowCount / 20), 1);
            }
            */
            yPlotArea3.XAxis = indexAxis5;
            yPlotArea3.YAxes.Clear();
            yPlotArea3.YAxes.AddRange(new FarPoint.Win.Chart.ValueAxis[] {
        valueAxis3});
            yPlotArea3.ZAxis = indexAxis6;
            ((System.ComponentModel.ISupportInitialize)(yPlotArea3)).EndInit();
            this.spdPlanetaryMixer_Sheet1_SpreadChart3.Model.PlotAreas.Clear();
            this.spdPlanetaryMixer_Sheet1_SpreadChart3.Model.PlotAreas.AddRange(new FarPoint.Win.Chart.PlotArea[] {
        yPlotArea3});
            this.spdPlanetaryMixer_Sheet1_SpreadChart3.Rectangle = new System.Drawing.Rectangle(0, 800, 707, 341);
            this.spdPlanetaryMixer_Sheet1_SpreadChart3.SheetName = "spdPlanetaryMixer_Sheet1";
            this.spdPlanetaryMixer_Sheet1_SpreadChart3.SizeProportional = true;
            // 
            // spdPlanetaryMixer_Sheet1_SpreadChart4
            // 
            this.spdPlanetaryMixer_Sheet1_SpreadChart4.ChartName = "SpreadChart4";
            this.spdPlanetaryMixer_Sheet1_SpreadChart4.ContextMenuStrip = this.spreadChartContextMenuStrip4;
            this.spdPlanetaryMixer_Sheet1_SpreadChart4.IgnoreUpdateShapeLocation = false;
            this.spdPlanetaryMixer_Sheet1_SpreadChart4.IsGrayscale = false;


            labelArea10.AlignmentX = 0.5F;
            labelArea10.Location = new System.Drawing.PointF(0.5F, 0.02F);
            labelArea10.ManualLayout = false;
            labelArea10.Padding = new FarPoint.Win.Chart.PaddingF(1.5F, 1.5F, 1.5F, 1.5F);
            labelArea10.Text = "CTM_Planetary Mixer #4";
            labelArea11.AlignmentX = 0.5F;
            labelArea11.Location = new System.Drawing.PointF(0.03106335F, 0.2838837F);
            labelArea11.ManualLayout = true;
            labelArea11.Padding = new FarPoint.Win.Chart.PaddingF(1.5F, 1.5F, 1.5F, 1.5F);
            labelArea11.Text = "온도 (℃)";
            labelArea11.TextDirection = FarPoint.Win.Chart.TextDirection.Rotate270Degree;
            labelArea12.AlignmentX = 0.5F;
            labelArea12.Location = new System.Drawing.PointF(0.4F, 0.90F);
            labelArea12.ManualLayout = true;
            labelArea12.Padding = new FarPoint.Win.Chart.PaddingF(1.5F, 1.5F, 1.5F, 1.5F);
            labelArea12.Text = "가동시간";
            this.spdPlanetaryMixer_Sheet1_SpreadChart4.Model.LabelAreas.Clear();

            this.spdPlanetaryMixer_Sheet1_SpreadChart4.Model.LabelAreas.AddRange(new FarPoint.Win.Chart.LabelArea[] {
      labelArea10,
      labelArea11,
      labelArea12});


            //      legendArea4.Padding = new FarPoint.Win.Chart.PaddingF(3F, 3F, 3F, 3F);
            //      this.spdPlanetaryMixer_Sheet1_SpreadChart4.Model.LegendAreas.AddRange(new FarPoint.Win.Chart.LegendArea[] {
            //     legendArea4});
            ((System.ComponentModel.ISupportInitialize)(yPlotArea4)).BeginInit();
            wall10.Visible = true;
            yPlotArea4.BackWall = wall10;
            wall11.Visible = true;
            yPlotArea4.BottomWall = wall11;
            yPlotArea4.Elevation = 15F;
            yPlotArea4.GlobalAmbientLight = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(50)))), ((int)(((byte)(50)))));
            directionalLight4.AmbientColor = System.Drawing.Color.Gray;
            directionalLight4.DiffuseColor = System.Drawing.Color.Gray;
            directionalLight4.DirectionX = 10F;
            directionalLight4.DirectionY = 20F;
            directionalLight4.DirectionZ = 30F;
            directionalLight4.SpecularColor = System.Drawing.Color.Black;
            yPlotArea4.Lights.Clear();
            yPlotArea4.Lights.AddRange(new FarPoint.Win.Chart.Light[] {
      directionalLight4});
            yPlotArea4.Location = new System.Drawing.PointF(0.09271692F, 0.07545309F);
            yPlotArea4.Projection = new FarPoint.Win.Chart.OrthogonalProjection();
            yPlotArea4.Size = new System.Drawing.SizeF(0.8714088F, 0.4976179F);

            yPlotArea4.Projection = new FarPoint.Win.Chart.OrthogonalProjection();
            yPlotArea4.Rotation = -21F;
            lineSeries11.CategoryNames.DataField = "";
            lineSeries11.CategoryNames.DataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldCategoryName", "\'4\'!$D$1:$D$" + spdPlanetaryMixer_Sheet5.RowCount.ToString(), FarPoint.Win.Spread.Chart.SegmentDataType.Text, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Vertical);
            lineSeries11.PointMarker = new FarPoint.Win.Chart.NoMarker();
            lineSeries11.SeriesName = "설정온도";
            lineSeries11.SeriesNameDataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldSeriesName", "\"설정온도\"", FarPoint.Win.Spread.Chart.SegmentDataType.Text, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Horizontal);
            lineSeries11.Values.DataField = "";
            lineSeries11.Values.DataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldValue", "\'4\'!$E$1:$E$" + spdPlanetaryMixer_Sheet5.RowCount.ToString(), FarPoint.Win.Spread.Chart.SegmentDataType.Number, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Vertical);
            lineSeries12.CategoryNames.DataField = "";
            lineSeries12.CategoryNames.DataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldCategoryName", "\'4\'!$D$1:$D$" + spdPlanetaryMixer_Sheet5.RowCount.ToString(), FarPoint.Win.Spread.Chart.SegmentDataType.Text, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Vertical);
            lineSeries12.PointMarker = new FarPoint.Win.Chart.NoMarker();

            if (iRow >= 0 && sMachine == "E1000037")
            {
                lineSeries12.PointFills.SetFill(iRow, new FarPoint.Win.Chart.SolidFill(System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))))));
                lineSeries12.PointMarkers.SetMarker(iRow, new FarPoint.Win.Chart.BuiltinMarker(FarPoint.Win.Chart.MarkerShape.Square, 10F));
            }

            lineSeries12.SeriesName = "실제온도";
            lineSeries12.SeriesNameDataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldSeriesName", "\"실제온도\"", FarPoint.Win.Spread.Chart.SegmentDataType.Text, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Horizontal);
            lineSeries12.Values.DataField = "";
            lineSeries12.Values.DataSource = new FarPoint.Win.Spread.Chart.SeriesDataField(this.spdPlanetaryMixer, "DataFieldValue", "\'4\'!$F$1:$F$" + spdPlanetaryMixer_Sheet5.RowCount.ToString(), FarPoint.Win.Spread.Chart.SegmentDataType.Number, new FarPoint.Win.Spread.Chart.ChartDataSetting(FarPoint.Win.Spread.Chart.EmptyValueStyle.Zero, false, false), FarPoint.Win.Spread.Chart.DataOrientation.Vertical);
            yPlotArea4.Series.AddRange(new FarPoint.Win.Chart.Series[] {
      lineSeries11,
      lineSeries12});
            wall12.Visible = true;
            yPlotArea4.SideWall = wall12;
            indexAxis7.LabelTextDirection = FarPoint.Win.Chart.TextDirection.Rotate90Degree;


            if (splitContainer1.Panel1.Width > (spdPlanetaryMixer_Sheet5.RowCount * 15))
            {
                indexAxis7.AutoLabelUnit = true;
                indexAxis7.LabelUnit = 1;
            }
            else
            {
                indexAxis7.AutoLabelUnit = false;
                indexAxis7.LabelUnit = Math.Round(MPCF.ToDbl(spdPlanetaryMixer_Sheet5.RowCount / 20), 1);

            }

            if (txtAxisValue.Text.Trim() == "")
            {
                valueAxis4.AutoMaximum = true;
                valueAxis4.Maximum = 1;
            }
            else
            {
                valueAxis4.AutoMaximum = false;
                valueAxis4.Maximum = MPCF.ToDbl(txtAxisValue.Text);
            }

            /*
            if (spdPlanetaryMixer_Sheet5.RowCount <= 20)
            {
                indexAxis7.AutoLabelUnit = true;
                indexAxis7.LabelUnit = 1;
            }
            else
            {
                indexAxis7.AutoLabelUnit = false;
                indexAxis7.LabelUnit = Math.Round(MPCF.ToDbl(spdPlanetaryMixer_Sheet5.RowCount / 20), 1);
            }
            */
            yPlotArea4.XAxis = indexAxis7;
            yPlotArea4.YAxes.Clear();
            yPlotArea4.YAxes.AddRange(new FarPoint.Win.Chart.ValueAxis[] {
      valueAxis4});
            yPlotArea4.ZAxis = indexAxis8;
            ((System.ComponentModel.ISupportInitialize)(yPlotArea4)).EndInit();
            this.spdPlanetaryMixer_Sheet1_SpreadChart4.Model.PlotAreas.Clear();
            this.spdPlanetaryMixer_Sheet1_SpreadChart4.Model.PlotAreas.AddRange(new FarPoint.Win.Chart.PlotArea[] {
      yPlotArea4});
            this.spdPlanetaryMixer_Sheet1_SpreadChart4.Rectangle = new System.Drawing.Rectangle(0, 1200, 707, 341);
            this.spdPlanetaryMixer_Sheet1_SpreadChart4.SheetName = "spdPlanetaryMixer_Sheet1";
            this.spdPlanetaryMixer_Sheet1_SpreadChart4.SizeProportional = true;
            // 
            // spreadChartContextMenuStrip1
            // 
            this.spreadChartContextMenuStrip1.Name = "spreadChartContextMenuStrip1";
            this.spreadChartContextMenuStrip1.Size = new System.Drawing.Size(205, 330);
            // 
            // spreadChartContextMenuStrip2
            // 
            this.spreadChartContextMenuStrip2.Name = "spreadChartContextMenuStrip2";
            this.spreadChartContextMenuStrip2.Size = new System.Drawing.Size(205, 308);
            // 
            // spreadChartContextMenuStrip3
            // 
            this.spreadChartContextMenuStrip3.Name = "spreadChartContextMenuStrip3";
            this.spreadChartContextMenuStrip3.Size = new System.Drawing.Size(205, 308);
            // 
            // spreadChartContextMenuStrip4
            // 
            this.spreadChartContextMenuStrip4.Name = "spreadChartContextMenuStrip4";
            this.spreadChartContextMenuStrip4.Size = new System.Drawing.Size(205, 308);



            spdPlanetaryMixer_Sheet1.Cells[0, 0].Row.Height = splitContainer1.Panel1.Height;
            spdPlanetaryMixer_Sheet1.Cells[0, 0].Column.Width = splitContainer1.Panel1.Width;

            spdPlanetaryMixer_Sheet1.Cells[1, 0].Row.Height = splitContainer1.Panel1.Height;
            spdPlanetaryMixer_Sheet1.Cells[1, 0].Column.Width = splitContainer1.Panel1.Width;

            spdPlanetaryMixer_Sheet1.Cells[2, 0].Row.Height = splitContainer1.Panel1.Height;
            spdPlanetaryMixer_Sheet1.Cells[2, 0].Column.Width = splitContainer1.Panel1.Width;

            spdPlanetaryMixer_Sheet1.Cells[3, 0].Row.Height = splitContainer1.Panel1.Height;
            spdPlanetaryMixer_Sheet1.Cells[3, 0].Column.Width = splitContainer1.Panel1.Width;


            this.spdPlanetaryMixer_Sheet1_SpreadChart1.Rectangle = new System.Drawing.Rectangle(0, 0, splitContainer1.Panel1.Width, splitContainer1.Height);
            this.spdPlanetaryMixer_Sheet1_SpreadChart2.Rectangle = new System.Drawing.Rectangle(0, splitContainer1.Height, splitContainer1.Panel1.Width, splitContainer1.Height);
            this.spdPlanetaryMixer_Sheet1_SpreadChart3.Rectangle = new System.Drawing.Rectangle(0, splitContainer1.Height * 2, splitContainer1.Panel1.Width, splitContainer1.Height);
            this.spdPlanetaryMixer_Sheet1_SpreadChart4.Rectangle = new System.Drawing.Rectangle(0, splitContainer1.Height * 3, splitContainer1.Panel1.Width, splitContainer1.Height);

        }
        private void ChartMachineSelect(string sMachine)
        {
            switch (sMachine)
            {
                case "":
                    spdPlanetaryMixer.SetViewportTopRow(0, 0);
                    break;
                case "E1000034":
                    spdPlanetaryMixer.SetViewportTopRow(0, 0);
                    break;

                case "E1000035":
                    spdPlanetaryMixer.SetViewportTopRow(0, 1);
                    break;

                case "E1000036":
                    spdPlanetaryMixer.SetViewportTopRow(0, 2);
                    break;

                case "E1000037":
                    spdPlanetaryMixer.SetViewportTopRow(0, 3);
                    break;
            }

        }
        #endregion

        #region " Event Definition "

        private void frmViewCTMPlanetaryMixerData_NEW_Load(object sender, EventArgs e)
        {
            try
            {


                if (g_Popup_yn == "Y")
                {

                    btnPopup.Visible = false;

                }
                else
                {
                    btnPopup.Visible = true;
                }


                FarPoint.Win.Spread.SheetView oSheet = spdPlanetaryMixer_Sheet1;

                if (g_PopYn == "Y")
                {
                    cdvDept.Text = g_Dept;
                    cdvDept.DisplayText = g_DeptDisplay;
                    cdvOper.Text = g_Oper;
                    cdvOper.DisplayText = g_OperDisplay;
                    cdvResId.Text = g_ResId;
                    cdvResId.DisplayText = g_ResDisplay;
                    txtLotID.Text = g_LotId;




                    if (g_searchType == "LOT")
                    {
                        rdoLot.Checked = true;
                        txtLotID.Enabled = true;
                        btnChngeLotTime.Enabled = true;
                        dtpFromDate.Enabled = false;
                        dtpToDate.Enabled = false;




                        spdPlanetaryMixer_Sheet2.Columns[(int)RAS_INFO.LOT_ID].Visible = true;
                        spdPlanetaryMixer_Sheet2.Columns[(int)RAS_INFO.MAT_ID].Visible = true;
                        spdPlanetaryMixer_Sheet2.Columns[(int)RAS_INFO.MAT_DESC].Visible = true;

                        spdPlanetaryMixer_Sheet3.Columns[(int)RAS_INFO.LOT_ID].Visible = true;
                        spdPlanetaryMixer_Sheet3.Columns[(int)RAS_INFO.MAT_ID].Visible = true;
                        spdPlanetaryMixer_Sheet3.Columns[(int)RAS_INFO.MAT_DESC].Visible = true;

                        spdPlanetaryMixer_Sheet4.Columns[(int)RAS_INFO.LOT_ID].Visible = true;
                        spdPlanetaryMixer_Sheet4.Columns[(int)RAS_INFO.MAT_ID].Visible = true;
                        spdPlanetaryMixer_Sheet4.Columns[(int)RAS_INFO.MAT_DESC].Visible = true;

                        spdPlanetaryMixer_Sheet5.Columns[(int)RAS_INFO.LOT_ID].Visible = true;
                        spdPlanetaryMixer_Sheet5.Columns[(int)RAS_INFO.MAT_ID].Visible = true;
                        spdPlanetaryMixer_Sheet5.Columns[(int)RAS_INFO.MAT_DESC].Visible = true;

                        spdPlanetaryMixerData_Sheet1.Columns[(int)RAS_INFO.LOT_ID].Visible = true;
                        spdPlanetaryMixerData_Sheet1.Columns[(int)RAS_INFO.MAT_ID].Visible = true;
                        spdPlanetaryMixerData_Sheet1.Columns[(int)RAS_INFO.MAT_DESC].Visible = true;

                    }
                    else
                    {

                        rdoLot.Checked = false;
                        txtLotID.Text = "";
                        txtLotID.Enabled = false;
                        btnChngeLotTime.Enabled = false;
                        dtpFromDate.Enabled = true;
                        dtpToDate.Enabled = true;



                        spdPlanetaryMixer_Sheet2.Columns[(int)RAS_INFO.LOT_ID].Visible = false;
                        spdPlanetaryMixer_Sheet2.Columns[(int)RAS_INFO.MAT_ID].Visible = false;
                        spdPlanetaryMixer_Sheet2.Columns[(int)RAS_INFO.MAT_DESC].Visible = false;

                        spdPlanetaryMixer_Sheet3.Columns[(int)RAS_INFO.LOT_ID].Visible = false;
                        spdPlanetaryMixer_Sheet3.Columns[(int)RAS_INFO.MAT_ID].Visible = false;
                        spdPlanetaryMixer_Sheet3.Columns[(int)RAS_INFO.MAT_DESC].Visible = false;

                        spdPlanetaryMixer_Sheet4.Columns[(int)RAS_INFO.LOT_ID].Visible = false;
                        spdPlanetaryMixer_Sheet4.Columns[(int)RAS_INFO.MAT_ID].Visible = false;
                        spdPlanetaryMixer_Sheet4.Columns[(int)RAS_INFO.MAT_DESC].Visible = false;

                        spdPlanetaryMixer_Sheet5.Columns[(int)RAS_INFO.LOT_ID].Visible = false;
                        spdPlanetaryMixer_Sheet5.Columns[(int)RAS_INFO.MAT_ID].Visible = false;
                        spdPlanetaryMixer_Sheet5.Columns[(int)RAS_INFO.MAT_DESC].Visible = false;

                        spdPlanetaryMixerData_Sheet1.Columns[(int)RAS_INFO.LOT_ID].Visible = false;
                        spdPlanetaryMixerData_Sheet1.Columns[(int)RAS_INFO.MAT_ID].Visible = false;
                        spdPlanetaryMixerData_Sheet1.Columns[(int)RAS_INFO.MAT_DESC].Visible = false;



                    }


                    if (g_SearchYn == "Y")
                    {
                        ViewPlanetaryMixerData();
                    }
                }
                else
                {
                    cdvDept.Text = CSGV.gs_area_ctm;
                    cdvDept.DisplayText = CSGV.gs_area_ctm;


                    cdvOper.Text = "OC02080";
                    cdvOper.DisplayText = "교반건조";


                    txtLotID.Enabled = false;
                    btnChngeLotTime.Enabled = false;

                    if (MPGV.gsUserGroup.Contains("ADMIN"))
                    {

                        spdPlanetaryMixer_Sheet2.Columns[(int)RAS_INFO.RES_STATUS].Visible = true;
                        spdPlanetaryMixer_Sheet3.Columns[(int)RAS_INFO.RES_STATUS].Visible = true;
                        spdPlanetaryMixer_Sheet4.Columns[(int)RAS_INFO.RES_STATUS].Visible = true;
                        spdPlanetaryMixer_Sheet5.Columns[(int)RAS_INFO.RES_STATUS].Visible = true;
                        spdPlanetaryMixerData_Sheet1.Columns[(int)RAS_INFO.RES_STATUS].Visible = true;
                    }
                    else
                    {
                        spdPlanetaryMixer_Sheet2.Columns[(int)RAS_INFO.RES_STATUS].Visible = false;
                        spdPlanetaryMixer_Sheet3.Columns[(int)RAS_INFO.RES_STATUS].Visible = false;
                        spdPlanetaryMixer_Sheet4.Columns[(int)RAS_INFO.RES_STATUS].Visible = false;
                        spdPlanetaryMixer_Sheet5.Columns[(int)RAS_INFO.RES_STATUS].Visible = false;
                        spdPlanetaryMixerData_Sheet1.Columns[(int)RAS_INFO.RES_STATUS].Visible = false;
                    }


                }






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
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }

                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;
                cdvOper.DisplaySubItemIndex = 1;

                if (ViewOper(cdvOper.GetListView, cdvDept.Text) == false)
                {
                    return;
                }

                cdvOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }
        private void cdvOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                //  MPCF.ClearList(spdPlanetaryMixer);
                ClearData();
                cdvResId.Text = "";
                txtLotID.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvResId_ButtonPress(object sender, EventArgs e)
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

                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return;
                }

                cdvResId.Init();
                MPCF.InitListView(cdvResId.GetListView);
                cdvResId.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvResId.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvResId.SelectedSubItemIndex = 0;
                cdvResId.DisplaySubItemIndex = 1;


                if (ViewResID(cdvResId.GetListView, cdvOper.Text) == false)
                {
                    return;
                }

                cdvResId.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvResId_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                // MPCF.ClearList(spdPlanetaryMixer);
                //     ClearData();
                ChartMachineSelect(cdvResId.Text.Trim());


                txtLotID.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void rdoDate_CheckedChanged(object sender, EventArgs e)
        {
            try
            {
                if (rdoDate.Checked == true)
                {
                    rdoLot.Checked = false;
                    txtLotID.Text = "";
                    txtLotID.Enabled = false;
                    btnChngeLotTime.Enabled = false;
                    dtpFromDate.Enabled = true;
                    dtpToDate.Enabled = true;




                    spdPlanetaryMixer_Sheet2.Columns[(int)RAS_INFO.LOT_ID].Visible = false;
                    spdPlanetaryMixer_Sheet2.Columns[(int)RAS_INFO.MAT_ID].Visible = false;
                    spdPlanetaryMixer_Sheet2.Columns[(int)RAS_INFO.MAT_DESC].Visible = false;

                    spdPlanetaryMixer_Sheet3.Columns[(int)RAS_INFO.LOT_ID].Visible = false;
                    spdPlanetaryMixer_Sheet3.Columns[(int)RAS_INFO.MAT_ID].Visible = false;
                    spdPlanetaryMixer_Sheet3.Columns[(int)RAS_INFO.MAT_DESC].Visible = false;

                    spdPlanetaryMixer_Sheet4.Columns[(int)RAS_INFO.LOT_ID].Visible = false;
                    spdPlanetaryMixer_Sheet4.Columns[(int)RAS_INFO.MAT_ID].Visible = false;
                    spdPlanetaryMixer_Sheet4.Columns[(int)RAS_INFO.MAT_DESC].Visible = false;

                    spdPlanetaryMixer_Sheet5.Columns[(int)RAS_INFO.LOT_ID].Visible = false;
                    spdPlanetaryMixer_Sheet5.Columns[(int)RAS_INFO.MAT_ID].Visible = false;
                    spdPlanetaryMixer_Sheet5.Columns[(int)RAS_INFO.MAT_DESC].Visible = false;

                    spdPlanetaryMixerData_Sheet1.Columns[(int)RAS_INFO.LOT_ID].Visible = false;
                    spdPlanetaryMixerData_Sheet1.Columns[(int)RAS_INFO.MAT_ID].Visible = false;
                    spdPlanetaryMixerData_Sheet1.Columns[(int)RAS_INFO.MAT_DESC].Visible = false;


                }
                else
                {
                    rdoLot.Checked = true;
                    txtLotID.Enabled = true;
                    btnChngeLotTime.Enabled = true;
                    dtpFromDate.Enabled = false;
                    dtpToDate.Enabled = false;


                    spdPlanetaryMixer_Sheet2.Columns[(int)RAS_INFO.LOT_ID].Visible = true;
                    spdPlanetaryMixer_Sheet2.Columns[(int)RAS_INFO.MAT_ID].Visible = true;
                    spdPlanetaryMixer_Sheet2.Columns[(int)RAS_INFO.MAT_DESC].Visible = true;

                    spdPlanetaryMixer_Sheet3.Columns[(int)RAS_INFO.LOT_ID].Visible = true;
                    spdPlanetaryMixer_Sheet3.Columns[(int)RAS_INFO.MAT_ID].Visible = true;
                    spdPlanetaryMixer_Sheet3.Columns[(int)RAS_INFO.MAT_DESC].Visible = true;

                    spdPlanetaryMixer_Sheet4.Columns[(int)RAS_INFO.LOT_ID].Visible = true;
                    spdPlanetaryMixer_Sheet4.Columns[(int)RAS_INFO.MAT_ID].Visible = true;
                    spdPlanetaryMixer_Sheet4.Columns[(int)RAS_INFO.MAT_DESC].Visible = true;

                    spdPlanetaryMixer_Sheet5.Columns[(int)RAS_INFO.LOT_ID].Visible = true;
                    spdPlanetaryMixer_Sheet5.Columns[(int)RAS_INFO.MAT_ID].Visible = true;
                    spdPlanetaryMixer_Sheet5.Columns[(int)RAS_INFO.MAT_DESC].Visible = true;

                    spdPlanetaryMixerData_Sheet1.Columns[(int)RAS_INFO.LOT_ID].Visible = true;
                    spdPlanetaryMixerData_Sheet1.Columns[(int)RAS_INFO.MAT_ID].Visible = true;
                    spdPlanetaryMixerData_Sheet1.Columns[(int)RAS_INFO.MAT_DESC].Visible = true;



                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void txtLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (rdoLot.Checked == true)
                    {
                        btnView.PerformClick();
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnChngeLotTime_Click(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(txtLotID.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLotID.Text + "]");
                    txtLotID.Focus();
                    return;
                }

                frmPopUpdateResourceWorkTime popup = new frmPopUpdateResourceWorkTime();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sLot_ID = txtLotID.Text;
                popup.sOper = cdvOper.Text;
                popup.sOper_desc = cdvOper.DisplayText;
                popup.sRes_ID = cdvResId.Text;
                popup.sRes_desc = cdvResId.DisplayText;

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
        private void btnExcel_Click(object sender, EventArgs e)
        {
            string sFileName = "";

            try
            {


                ViewPlanetaryMixerData();

                sFileName = cdvResId.Text + "CTM_Planetary Mixer";

                spdPlanetaryMixer_Sheet2.Visible = true;
                spdPlanetaryMixer_Sheet3.Visible = true;
                spdPlanetaryMixer_Sheet4.Visible = true;
                spdPlanetaryMixer_Sheet5.Visible = true;

                EXTFUC.SaveExcel(spdPlanetaryMixer, sFileName);
                spdPlanetaryMixer_Sheet2.Visible = false;
                spdPlanetaryMixer_Sheet3.Visible = false;
                spdPlanetaryMixer_Sheet4.Visible = false;
                spdPlanetaryMixer_Sheet5.Visible = false;


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
                ClearData();
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

                ViewPlanetaryMixerData();
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdPlanetaryMixer_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {

        }
        private void splitContainer1_Resize(object sender, EventArgs e)
        {
            /*
            spdPlanetaryMixer_Sheet1.SetRowHeight(0, splitContainer1.Height);
            spdPlanetaryMixer_Sheet1.SetColumnWidth(0, splitContainer1.Width);

            spdPlanetaryMixer_Sheet1.SetRowHeight(1, splitContainer1.Height);
            spdPlanetaryMixer_Sheet1.SetColumnWidth(1, splitContainer1.Width);

            spdPlanetaryMixer_Sheet1.SetRowHeight(2, splitContainer1.Height);
            spdPlanetaryMixer_Sheet1.SetColumnWidth(2, splitContainer1.Width);

            spdPlanetaryMixer_Sheet1.SetRowHeight(3, splitContainer1.Height);
            spdPlanetaryMixer_Sheet1.SetColumnWidth(3, splitContainer1.Width);
            */

        }
        private void splitContainer1_Panel1_SizeChanged(object sender, EventArgs e)
        {
            /*
            spdPlanetaryMixer_Sheet1.SetRowHeight(0, splitContainer1.Height);
            spdPlanetaryMixer_Sheet1.SetColumnWidth(0, splitContainer1.Width);

            spdPlanetaryMixer_Sheet1.SetRowHeight(1, splitContainer1.Height);
            spdPlanetaryMixer_Sheet1.SetColumnWidth(1, splitContainer1.Width);

            spdPlanetaryMixer_Sheet1.SetRowHeight(2, splitContainer1.Height);
            spdPlanetaryMixer_Sheet1.SetColumnWidth(2, splitContainer1.Width);

            spdPlanetaryMixer_Sheet1.SetRowHeight(3, splitContainer1.Height);
            spdPlanetaryMixer_Sheet1.SetColumnWidth(3, splitContainer1.Width);
            */

            spdPlanetaryMixer_Sheet1.Cells[0, 0].Row.Height = splitContainer1.Panel1.Height;
            spdPlanetaryMixer_Sheet1.Cells[0, 0].Column.Width = splitContainer1.Panel1.Width;

            spdPlanetaryMixer_Sheet1.Cells[1, 0].Row.Height = splitContainer1.Panel1.Height;
            spdPlanetaryMixer_Sheet1.Cells[1, 0].Column.Width = splitContainer1.Panel1.Width;

            spdPlanetaryMixer_Sheet1.Cells[2, 0].Row.Height = splitContainer1.Panel1.Height;
            spdPlanetaryMixer_Sheet1.Cells[2, 0].Column.Width = splitContainer1.Panel1.Width;

            spdPlanetaryMixer_Sheet1.Cells[3, 0].Row.Height = splitContainer1.Panel1.Height;
            spdPlanetaryMixer_Sheet1.Cells[3, 0].Column.Width = splitContainer1.Panel1.Width;


            spdPlanetaryMixer_Sheet1_SpreadChart1.Rectangle = new System.Drawing.Rectangle(0, 0, splitContainer1.Panel1.Width, splitContainer1.Height);
            spdPlanetaryMixer_Sheet1_SpreadChart2.Rectangle = new System.Drawing.Rectangle(0, splitContainer1.Height, splitContainer1.Panel1.Width, splitContainer1.Height);
            spdPlanetaryMixer_Sheet1_SpreadChart3.Rectangle = new System.Drawing.Rectangle(0, splitContainer1.Height * 2, splitContainer1.Panel1.Width, splitContainer1.Height);
            spdPlanetaryMixer_Sheet1_SpreadChart4.Rectangle = new System.Drawing.Rectangle(0, splitContainer1.Height * 3, splitContainer1.Panel1.Width, splitContainer1.Height);


            int iRow = spdPlanetaryMixer.GetViewportTopRow(0);
            int iRow2 = -1;

            if (spdPlanetaryMixerData_Sheet1.ActiveRowIndex <= 0)
            {
                iRow2 = spdPlanetaryMixerData_Sheet1.ActiveRowIndex;
            }

            switch (iRow)
            {
                case 0:
                    chartDatagrid("E1000034", iRow2);
                    break;

                case 1:
                    chartDatagrid("E1000035", iRow2);
                    break;

                case 2:
                    chartDatagrid("E1000036", iRow2);
                    break;

                case 3:
                    chartDatagrid("E1000037", iRow2);
                    break;
            }



            //IndexAxis

        }
        private void spdPlanetaryMixerData_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.Row < 0)
                {
                    return;
                }

                if (e.ColumnHeader == true)
                {
                    return;
                }

                chartDatagrid(spdPlanetaryMixerData_Sheet1.Cells[e.Row, (int)RAS_INFO.RES_ID].Text, e.Row);


                spdPlanetaryMixerData_Sheet1.Cells[0, 0, spdPlanetaryMixerData_Sheet1.RowCount - 1, spdPlanetaryMixerData_Sheet1.ColumnCount - 1].BackColor = System.Drawing.Color.White;

                spdPlanetaryMixerData_Sheet1.Cells[e.Row, 0, e.Row, spdPlanetaryMixerData_Sheet1.ColumnCount - 1].BackColor = System.Drawing.Color.OrangeRed;




            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdPlanetaryMixer_TopChange(object sender, TopChangeEventArgs e)
        {
            int iRow = spdPlanetaryMixer.GetViewportTopRow(0);

            switch (iRow)
            {
                case 0:
                    SheetDataCopy(spdPlanetaryMixer_Sheet2);
                    break;

                case 1:
                    SheetDataCopy(spdPlanetaryMixer_Sheet3);
                    break;

                case 2:
                    SheetDataCopy(spdPlanetaryMixer_Sheet4);
                    break;

                case 3:
                    SheetDataCopy(spdPlanetaryMixer_Sheet5);
                    break;
            }


        }
        private void tmrTimer_Tick(object sender, EventArgs e)
        {
            ViewPlanetaryMixerData();
        }
        private void numRefreshSec_VisibleChanged(object sender, EventArgs e)
        {
            if (chkAutoRefresh.Checked == true)
            {
                tmrTimer.Interval = ((int)(numRefreshSec.Value)) * 1000;
                tmrTimer.Start();
            }
        }
        private void chkAutoRefresh_CheckedChanged(object sender, EventArgs e)
        {
            if (chkAutoRefresh.Checked == true)
            {
                tmrTimer.Interval = ((int)(numRefreshSec.Value)) * 1000;
                tmrTimer.Start();
            }
            else
            {
                tmrTimer.Stop();

            }
        }
        private void btnPopup_Click(object sender, EventArgs e)
        {
            frmViewCTMPlanetaryMixerData_NEW popup = new frmViewCTMPlanetaryMixerData_NEW();
            popup.StartPosition = FormStartPosition.CenterParent;
            popup.WindowState = FormWindowState.Maximized;
            popup.g_Popup_yn = "Y";

            chkAutoRefresh.Checked = false;


            if (popup.ShowDialog() == DialogResult.OK)
            {

                popup = null;
                //   ViewToolStatus();
                ViewPlanetaryMixerData();
                chkAutoRefresh.Checked = true;
            }
            else
            {
                popup = null;
                //  ViewToolStatus();

                chkAutoRefresh.Checked = true;
            }
        }
        private void spdPlanetaryMixerData_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            try
            {
                if (spdPlanetaryMixerData_Sheet1.RowCount < 0)
                {
                    return;
                }



                chartDatagrid(spdPlanetaryMixerData_Sheet1.Cells[spdPlanetaryMixerData_Sheet1.ActiveRowIndex, (int)RAS_INFO.RES_ID].Text, spdPlanetaryMixerData_Sheet1.ActiveRowIndex);


                spdPlanetaryMixerData_Sheet1.Cells[0, 0, spdPlanetaryMixerData_Sheet1.RowCount - 1, spdPlanetaryMixerData_Sheet1.ColumnCount - 1].BackColor = System.Drawing.Color.White;

                spdPlanetaryMixerData_Sheet1.Cells[spdPlanetaryMixerData_Sheet1.ActiveRowIndex, 0, spdPlanetaryMixerData_Sheet1.ActiveRowIndex, spdPlanetaryMixerData_Sheet1.ColumnCount - 1].BackColor = System.Drawing.Color.OrangeRed;




            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void txtAxisValue_TextChanged(object sender, EventArgs e)
        {
            double QtyChk = 0;

            if (txtAxisValue.Text.Trim() == "")
            {
                return;
            }

            bool isNum = double.TryParse(txtAxisValue.Text, out QtyChk);

            if (!isNum)
            {
                MPCF.ShowMsgBox("is Not Number (숫자만 입력 가능합니다.)");
                txtAxisValue.Text = "";
            }
        }

        #endregion
    }
}
