using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using FarPoint.Win.Spread;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;
using CUS_QCM.Popup;
using CUS_COM.Reports;
using System.IO;
using DevExpress.Data.Linq.Helpers;
using DevExpress.XtraBars.Docking2010.Views.Widget;
using FarPoint.Win.Chart;
using Miracom.UI;

namespace CUS_QCM
{
    public partial class frmTranShipReportRegistration_HM : frmTranForm05
    {
        public frmTranShipReportRegistration_HM()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Variable Definition "
        int iFocusRow = -1;
        #endregion

        #region " Constant Definition "
        private enum PACK_LOT
        {
            CHK,
            PACK_ORDER_ID,
            PACK_LOT_ID,
            ORG_LOT_ID,
            MAT_ID,
            MAT_VER,
            DELIVERY_ID,
            DELIVERY_NAME,
            GRADE,
            TYPES,
            SPECIFIC_SPEC,
            LOT_QTY,
            LENGTH,
            OD_METER,
            ID_METER,
            HEIGHT,
            DENSITY,
            MAG_SAT,
            COER_FORCE,
            HARDNESS_HV20,
            TRS,
            GRAIN_SIZE,
            DENSITY_SPEC,
            MAG_SAT_SPEC,
            COER_FORCE_SPEC,
            HARDNESS_HV20_SPEC,
            TRS_SPEC,
            GRAIN_SIZE_SPEC,
            COMMENTS,
            REMARK,
            IMAGE_NUM1,
            IMAGE_NUM2,
            OUTSIDE_MIN,
            OUTSIDE_MAX,
            LENGTH_MIN,
            LENGTH_MAX,
            SG_MIN,
            SG_MAX,
            MS_MIN,
            MS_MAX,
            HC_MIN,
            HC_MAX,
            HV_MIN,
            HV_MAX,
            TRS_MIN,
            TRS_MAX,
            GRAIN_SIZE_MIN,
            GRAIN_SIZE_MAX
        }

        #endregion



        private void InitControl()
        {
            try
            {
                cdvDept.Text = "HM";
                fngetReportType(cdvShipReportType.GetListView);
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnGenerateReport.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Left;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewPackingLotList(string packOrderId, string packLineNo)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "PACK_ORDER_ID";
                array[1].sCondition_Value = packOrderId;
                if (!TPDR.GetDataOne("", ref dt, "CQCM2101-001", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdPackingLotList);
                    return;
                }
                MPCF.ClearList(spdPackingLotList);
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdPackingLotList_Sheet1.RowCount++;
                    spdPackingLotList_Sheet1.SetValue(num, 0, false);
                    spdPackingLotList_Sheet1.Cells[num, 1].Value = dt.Rows[num]["PACK_ORDER_ID"];
                    spdPackingLotList_Sheet1.Cells[num, 2].Value = dt.Rows[num]["PACK_LOT_ID"];
                    spdPackingLotList_Sheet1.Cells[num, 3].Value = dt.Rows[num]["ORG_LOT_ID"];
                    spdPackingLotList_Sheet1.Cells[num, 4].Value = dt.Rows[num]["MAT_ID"];
                    spdPackingLotList_Sheet1.Cells[num, 5].Value = dt.Rows[num]["MAT_VER"];
                    spdPackingLotList_Sheet1.Cells[num, 6].Value = dt.Rows[num]["DELIVERY_ID"];
                    spdPackingLotList_Sheet1.Cells[num, 7].Value = dt.Rows[num]["DELIVERY_NAME"];
                    spdPackingLotList_Sheet1.Cells[num, 8].Value = dt.Rows[num]["GRADE"];
                    spdPackingLotList_Sheet1.Cells[num, 9].Value = dt.Rows[num]["TYPES"];
                    spdPackingLotList_Sheet1.Cells[num, 10].Value = dt.Rows[num]["SPECIFIC_SPEC"];
                    spdPackingLotList_Sheet1.Cells[num, 11].Value = dt.Rows[num]["QTY"];
                    spdPackingLotList_Sheet1.Cells[num, 12].Value = dt.Rows[num]["LENGTH"];
                    spdPackingLotList_Sheet1.Cells[num, 13].Value = dt.Rows[num]["OD_METER"];
                    spdPackingLotList_Sheet1.Cells[num, 14].Value = dt.Rows[num]["ID_METER"];
                    spdPackingLotList_Sheet1.Cells[num, 15].Value = dt.Rows[num]["HEIGHT"];
                    spdPackingLotList_Sheet1.Cells[num, 16].Value = dt.Rows[num]["DENSITY"];
                    spdPackingLotList_Sheet1.Cells[num, 17].Value = dt.Rows[num]["MAG_SAT"];
                    spdPackingLotList_Sheet1.Cells[num, 18].Value = dt.Rows[num]["COER_FORCE"];
                    spdPackingLotList_Sheet1.Cells[num, 19].Value = dt.Rows[num]["HARDNESS_HV20"];
                    spdPackingLotList_Sheet1.Cells[num, 20].Value = dt.Rows[num]["TRS"];
                    spdPackingLotList_Sheet1.Cells[num, 28].Value = dt.Rows[num]["COMMENTS"];
                    spdPackingLotList_Sheet1.Cells[num, 30].Value = dt.Rows[num]["IMAGE_NUM1"];
                    spdPackingLotList_Sheet1.Cells[num, 31].Value = dt.Rows[num]["IMAGE_NUM2"];
                    spdPackingLotList_Sheet1.Cells[num, 32].Value = dt.Rows[num]["OUTSIDE_MIN"];
                    spdPackingLotList_Sheet1.Cells[num, 33].Value = dt.Rows[num]["OUTSIDE_MAX"];
                    spdPackingLotList_Sheet1.Cells[num, 34].Value = dt.Rows[num]["LENGTH_MIN"];
                    spdPackingLotList_Sheet1.Cells[num, 35].Value = dt.Rows[num]["LENGTH_MAX"];
                    spdPackingLotList_Sheet1.Cells[num, 36].Value = dt.Rows[num]["SG_MIN"];
                    spdPackingLotList_Sheet1.Cells[num, 37].Value = dt.Rows[num]["SG_MAX"];
                    spdPackingLotList_Sheet1.Cells[num, 38].Value = dt.Rows[num]["MS_MIN"];
                    spdPackingLotList_Sheet1.Cells[num, 39].Value = dt.Rows[num]["MS_MAX"];
                    spdPackingLotList_Sheet1.Cells[num, 40].Value = dt.Rows[num]["HC_MIN"];
                    spdPackingLotList_Sheet1.Cells[num, 41].Value = dt.Rows[num]["HC_MAX"];
                    spdPackingLotList_Sheet1.Cells[num, 42].Value = dt.Rows[num]["HV_MIN"];
                    spdPackingLotList_Sheet1.Cells[num, 43].Value = dt.Rows[num]["HV_MAX"];
                    spdPackingLotList_Sheet1.Cells[num, 44].Value = dt.Rows[num]["TRS_MIN"];
                    spdPackingLotList_Sheet1.Cells[num, 45].Value = dt.Rows[num]["TRS_MAX"];
                    spdPackingLotList_Sheet1.Cells[num, 44].Value = dt.Rows[num]["GRAIN_SIZE_MIN"];
                    spdPackingLotList_Sheet1.Cells[num, 45].Value = dt.Rows[num]["GRAIN_SIZE_MAX"];
                    spdPackingLotList_Sheet1.Cells[num, 21].Value = dt.Rows[num]["GRAIN_SIZE"];
                    spdPackingLotList_Sheet1.Cells[num, 22].Value = dt.Rows[num]["DENSITY_SPEC"];
                    spdPackingLotList_Sheet1.Cells[num, 23].Value = dt.Rows[num]["MAG_SAT_SPEC"];
                    spdPackingLotList_Sheet1.Cells[num, 24].Value = dt.Rows[num]["COER_FORCE_SPEC"];
                    spdPackingLotList_Sheet1.Cells[num, 25].Value = dt.Rows[num]["HARDNESS_HV20_SPEC"];
                    spdPackingLotList_Sheet1.Cells[num, 26].Value = dt.Rows[num]["TRS_SPEC"];
                    spdPackingLotList_Sheet1.Cells[num, 27].Value = dt.Rows[num]["GRAIN_SIZE_SPEC"];
                    spdPackingLotList_Sheet1.Cells[num, 46].Value = dt.Rows[num]["GRAIN_SIZE_MIN"];
                    spdPackingLotList_Sheet1.Cells[num, 47].Value = dt.Rows[num]["GRAIN_SIZE_MAX"];
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool CheckCondition(string _condition)
        {
            try
            {
                switch (_condition)
                {
                    case "GENERATE":
                        if (spdPackingLotList.ActiveSheet.RowCount < 1)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(486));
                            return false;
                        }
                        if (cdvReportNo.Text != "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(487));
                            return false;
                        }
                        if (cdvShipReportType.Text == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(490));
                            cdvShipReportType.Focus();
                            return false;
                        }
                        break;
                    case "PRINT":
                        if (cdvReportNo.Text == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(488));
                            return false;
                        }
                        if (cdvShipReportType.Text == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(490));
                            cdvShipReportType.Focus();
                            return false;
                        }
                        break;
                    case "SAVE":
                        if (cdvReportNo.Text == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(489));
                            return false;
                        }
                        break;
                    case "FILE_UPLOAD":
                        if (spdPackingLotList.ActiveSheet.ActiveRowIndex < 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(492));
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

        private bool fngetReportType(ListView listView)
        {
            TRSNode tRSNode = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            MPCF.InitListView(listView);
            MPCR.SetInMsg(tRSNode);
            tRSNode.ProcStep = '1';
            tRSNode.AddString("SQL", "SELECT KEY_1 AS CODE,        DATA_1 AS VALUE      FROM MGCMTBLDAT    WHERE FACTORY = '" + MPGV.gsFactory + "'    AND TABLE_NAME = 'C_INSP_SHIP_REPORT'    AND DATA_2 = 'HM' ");
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

        private void fnviewReport(string sReportNo)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "REPORT_NO";
                array[1].sCondition_Value = sReportNo;
                if (!TPDR.GetDataOne("", ref dt, "CQCM2101-002", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdPackingLotList);
                    return;
                }
                MPCF.ClearList(spdPackingLotList);
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdPackingLotList.ActiveSheet.RowCount++;
                    if (num == 0)
                    {
                        txtGrade.Text = dt.Rows[num]["GRADE"].ToString();
                        txtType.Text = dt.Rows[num]["TYPES"].ToString();
                        txtCustomerDesc.Text = dt.Rows[num]["DELIVERY_NAME"].ToString();
                    }
                    spdPackingLotList.ActiveSheet.SetValue(num, 0, false);
                    spdPackingLotList.ActiveSheet.Cells[num, 2].Value = dt.Rows[num]["PACK_LOT_ID"];
                    spdPackingLotList.ActiveSheet.Cells[num, 3].Value = dt.Rows[num]["ORG_LOT_ID"];
                    spdPackingLotList.ActiveSheet.Cells[num, 1].Value = dt.Rows[num]["PACK_ORDER_ID"];
                    spdPackingLotList.ActiveSheet.Cells[num, 8].Value = dt.Rows[num]["GRADE"];
                    spdPackingLotList.ActiveSheet.Cells[num, 9].Value = dt.Rows[num]["TYPES"];
                    spdPackingLotList.ActiveSheet.Cells[num, 6].Value = dt.Rows[num]["DELIVERY_ID"];
                    spdPackingLotList.ActiveSheet.Cells[num, 7].Value = dt.Rows[num]["DELIVERY_NAME"];
                    spdPackingLotList.ActiveSheet.Cells[num, 11].Value = dt.Rows[num]["LOT_QTY"].ToString();
                    spdPackingLotList.ActiveSheet.Cells[num, 13].Value = dt.Rows[num]["OD_METER"];
                    spdPackingLotList.ActiveSheet.Cells[num, 14].Value = dt.Rows[num]["ID_METER"];
                    spdPackingLotList.ActiveSheet.Cells[num, 15].Value = dt.Rows[num]["HEIGHT"];
                    spdPackingLotList.ActiveSheet.Cells[num, 12].Value = dt.Rows[num]["LENGTH"];
                    spdPackingLotList.ActiveSheet.Cells[num, 16].Value = dt.Rows[num]["DENSITY"];
                    spdPackingLotList.ActiveSheet.Cells[num, 17].Value = dt.Rows[num]["MAG_SAT"];
                    spdPackingLotList.ActiveSheet.Cells[num, 18].Value = dt.Rows[num]["COER_FORCE"];
                    spdPackingLotList.ActiveSheet.Cells[num, 19].Value = dt.Rows[num]["HARDNESS_HV20"];
                    spdPackingLotList.ActiveSheet.Cells[num, 20].Value = dt.Rows[num]["TRS"];
                    spdPackingLotList.ActiveSheet.Cells[num, 28].Value = dt.Rows[num]["COMMENTS"].ToString();
                    spdPackingLotList.ActiveSheet.Cells[num, 29].Value = dt.Rows[num]["REMARK"].ToString();
                    spdPackingLotList.ActiveSheet.Cells[num, 30].Value = dt.Rows[num]["IMAGE_NUM1"];
                    spdPackingLotList.ActiveSheet.Cells[num, 31].Value = dt.Rows[num]["IMAGE_NUM2"];

                    spdPackingLotList_Sheet1.Cells[num, 21].Value = dt.Rows[num]["GRAIN_SIZE"];
                    spdPackingLotList_Sheet1.Cells[num, 22].Value = dt.Rows[num]["DENSITY_SPEC"];
                    spdPackingLotList_Sheet1.Cells[num, 23].Value = dt.Rows[num]["MAG_SAT_SPEC"];
                    spdPackingLotList_Sheet1.Cells[num, 24].Value = dt.Rows[num]["COER_FORCE_SPEC"];
                    spdPackingLotList_Sheet1.Cells[num, 25].Value = dt.Rows[num]["HARDNESS_HV20_SPEC"];
                    spdPackingLotList_Sheet1.Cells[num, 26].Value = dt.Rows[num]["TRS_SPEC"];
                    spdPackingLotList_Sheet1.Cells[num, 27].Value = dt.Rows[num]["GRAIN_SIZE_SPEC"];
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool fnGenerateReport()
        {
            if (!CheckCondition("GENERATE"))
            {
                return false;
            }
            TRSNode tRSNode = new TRSNode("GENERATE_REPORT_IN");
            TRSNode out_node = new TRSNode("GENERATE_REPORT_OUT");
            int num = 0;
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '2';
                tRSNode.AddString("AREA_ID", cdvDept.Text);
                for (int i = 0; i < spdPackingLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdPackingLotList.ActiveSheet.Cells[i, 0].Value.ToString().ToUpper() == "TRUE")
                    {
                        TRSNode tRSNode2 = tRSNode.AddNode("DATA_LIST");
                        tRSNode2.AddString("PACK_LOT_ID", spdPackingLotList.ActiveSheet.Cells[i, 2].Text);
                        tRSNode2.AddString("ORG_LOT_ID", spdPackingLotList.ActiveSheet.Cells[i, 3].Text);
                        tRSNode2.AddString("GRADE", spdPackingLotList.ActiveSheet.Cells[i, 8].Text);
                        tRSNode2.AddString("TYPES", spdPackingLotList.ActiveSheet.Cells[i, 9].Text);
                        tRSNode2.AddString("PACK_ORDER_ID", spdPackingLotList.ActiveSheet.Cells[i, 1].Text);
                        tRSNode2.AddString("CUSTOMER_ID", spdPackingLotList.ActiveSheet.Cells[i, 6].Text);
                        tRSNode2.AddString("PACK_ORDER_ID", spdPackingLotList.ActiveSheet.Cells[i, 1].Text);
                        tRSNode2.AddDouble("LOT_QTY", spdPackingLotList.ActiveSheet.Cells[i, 11].Value);
                        tRSNode2.AddString("OD_METER", spdPackingLotList.ActiveSheet.Cells[i, 13].Text);
                        tRSNode2.AddString("ID_METER", spdPackingLotList.ActiveSheet.Cells[i, 14].Text);
                        tRSNode2.AddString("HEIGHT", spdPackingLotList.ActiveSheet.Cells[i, 15].Text);
                        tRSNode2.AddString("LENGTH", spdPackingLotList.ActiveSheet.Cells[i, 12].Text);
                        tRSNode2.AddString("DENSITY", spdPackingLotList.ActiveSheet.Cells[i, 16].Text);
                        tRSNode2.AddString("MAG_SAT", spdPackingLotList.ActiveSheet.Cells[i, 17].Text);
                        tRSNode2.AddString("COER_FORCE", spdPackingLotList.ActiveSheet.Cells[i, 18].Text);
                        tRSNode2.AddString("HARDNESS_HV20", spdPackingLotList.ActiveSheet.Cells[i, 19].Text);
                        tRSNode2.AddString("TRS", spdPackingLotList.ActiveSheet.Cells[i, 20].Text);
                        tRSNode2.AddString("GRAIN_SIZE", spdPackingLotList.ActiveSheet.Cells[i, 21].Text);
                        tRSNode2.AddString("COMMENTS", spdPackingLotList.ActiveSheet.Cells[i, 28].Text);
                        tRSNode2.AddString("REMARK", spdPackingLotList.ActiveSheet.Cells[i, 29].Text);
                        tRSNode2.AddString("ATTRIBUTE02", cdvShipReportType.Text);
                        tRSNode2.AddString("IMAGE_NUM1", spdPackingLotList.ActiveSheet.Cells[i, 30].Text);
                        tRSNode2.AddString("IMAGE_NUM2", spdPackingLotList.ActiveSheet.Cells[i, 31].Text);
                        tRSNode2.AddString("DENSITY_SPEC", spdPackingLotList.ActiveSheet.Cells[i, 22].Text);
                        tRSNode2.AddString("MAG_SAT_SPEC", spdPackingLotList.ActiveSheet.Cells[i, 23].Text);
                        tRSNode2.AddString("COER_FORCE_SPEC", spdPackingLotList.ActiveSheet.Cells[i, 24].Text);
                        tRSNode2.AddString("HARDNESS_HV20_SPEC", spdPackingLotList.ActiveSheet.Cells[i, 25].Text);
                        tRSNode2.AddString("TRS_SPEC", spdPackingLotList.ActiveSheet.Cells[i, 26].Text);
                        tRSNode2.AddString("GRAIN_SIZE_SPEC", spdPackingLotList.ActiveSheet.Cells[i, 27].Text);
                        num++;
                    }
                }
                if (num == 0)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(491));
                    return false;
                }
                if (!MPCR.CallService("CUS_QCM", "CUS_QCM_Generate_Report", tRSNode, ref out_node, b_ignore_message: false))
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);
                if (out_node.GetString("REPORT_NO") != "")
                {
                    cdvReportNo.Text = out_node.GetString("REPORT_NO");
                    fnviewReport(out_node.GetString("REPORT_NO"));
                }
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool fnSaveReport()
        {
            TRSNode tRSNode = new TRSNode("SAVE_REPORT_IN");
            TRSNode out_node = new TRSNode("SAVE_REPORT_OUT");
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '2';
                tRSNode.AddString("REPORT_NO", cdvReportNo.Text);

                for (int i = 0; i < spdPackingLotList.ActiveSheet.RowCount; i++)
                {
                    TRSNode tRSNode2 = tRSNode.AddNode("DATA_LIST");
                    tRSNode2.AddString("PACK_LOT_ID", spdPackingLotList.ActiveSheet.Cells[i, 2].Text);
                    tRSNode2.AddString("ORG_LOT_ID", spdPackingLotList.ActiveSheet.Cells[i, 3].Text);
                    tRSNode2.AddString("GRADE", spdPackingLotList.ActiveSheet.Cells[i, 8].Text);
                    tRSNode2.AddString("TYPES", spdPackingLotList.ActiveSheet.Cells[i, 9].Text);
                    tRSNode2.AddString("PACK_ORDER_ID", spdPackingLotList.ActiveSheet.Cells[i, 1].Text);
                    tRSNode2.AddString("CUSTOMER_ID", spdPackingLotList.ActiveSheet.Cells[i, 6].Text);
                    tRSNode2.AddDouble("LOT_QTY", spdPackingLotList.ActiveSheet.Cells[i, 11].Text);
                    tRSNode2.AddString("LENGTH", spdPackingLotList.ActiveSheet.Cells[i, 12].Text);
                    tRSNode2.AddString("OD_METER", spdPackingLotList.ActiveSheet.Cells[i, 13].Text);
                    tRSNode2.AddString("ID_METER", spdPackingLotList.ActiveSheet.Cells[i, 14].Text);
                    tRSNode2.AddString("HEIGHT", spdPackingLotList.ActiveSheet.Cells[i, 15].Text);
                    tRSNode2.AddString("DENSITY", spdPackingLotList.ActiveSheet.Cells[i, 16].Text);
                    tRSNode2.AddString("MAG_SAT", spdPackingLotList.ActiveSheet.Cells[i, 17].Text);
                    tRSNode2.AddString("COER_FORCE", spdPackingLotList.ActiveSheet.Cells[i, 18].Text);
                    tRSNode2.AddString("HARDNESS_HV20", spdPackingLotList.ActiveSheet.Cells[i, 19].Text);
                    tRSNode2.AddString("TRS", spdPackingLotList.ActiveSheet.Cells[i, 20].Text);
                    tRSNode2.AddString("COMMENTS", spdPackingLotList.ActiveSheet.Cells[i, 28].Text);
                    tRSNode2.AddString("REMARK", spdPackingLotList.ActiveSheet.Cells[i, 29].Text);
                    tRSNode2.AddString("IMAGE_NUM1", spdPackingLotList.ActiveSheet.Cells[i, 30].Text);
                    tRSNode2.AddString("IMAGE_NUM2", spdPackingLotList.ActiveSheet.Cells[i, 31].Text);
                    tRSNode2.AddString("GRAIN_SIZE", spdPackingLotList.ActiveSheet.Cells[i, 21].Text);
                    tRSNode2.AddString("DENSITY_SPEC", spdPackingLotList.ActiveSheet.Cells[i, 22].Text);
                    tRSNode2.AddString("MAG_SAT_SPEC", spdPackingLotList.ActiveSheet.Cells[i, 23].Text);
                    tRSNode2.AddString("COER_FORCE_SPEC", spdPackingLotList.ActiveSheet.Cells[i, 24].Text);
                    tRSNode2.AddString("HARDNESS_HV20_SPEC", spdPackingLotList.ActiveSheet.Cells[i, 25].Text);
                    tRSNode2.AddString("TRS_SPEC", spdPackingLotList.ActiveSheet.Cells[i, 26].Text);
                    tRSNode2.AddString("GRAIN_SIZE_SPEC", spdPackingLotList.ActiveSheet.Cells[i, 27].Text);
                    tRSNode2.AddString("ATTRIBUTE02", cdvShipReportType.Text); 
                }
                if (!MPCR.CallService("CUS_QCM", "CUS_QCM_Save_Report", tRSNode, ref out_node, b_ignore_message: false))
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);
                fnviewReport(cdvReportNo.Text);
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool fnGetUserDesc()
        {
            TRSNode tRSNode = new TRSNode("USER_IN");
            TRSNode out_node = new TRSNode("USER_OUT");
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("USER_ID", MPGV.gsUserID);
                if (!MPCR.CallService("SEC", "SEC_View_User", tRSNode, ref out_node, b_ignore_message: false))
                {
                    return false;
                }
                if (out_node.GetString("USER_DESC") != "")
                {
                    txtPrintUser.Text = out_node.GetString("USER_DESC");
                }
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        public static Image ByteArrayToImage(byte[] b)
        {
            ImageConverter imageConverter = new ImageConverter();
            return (Image)imageConverter.ConvertFrom(b);
        }

        private void ViewImageFile(string _image1, string _image2)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "IMAGE_1";
                array[1].sCondition_Value = _image1;
                array[2].sCondition_ID = "IMAGE_2";
                array[2].sCondition_Value = _image2;
                if (!TPDR.GetDataOne("", ref dt, "CQCM2101-003", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    return;
                }
                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    if (dt.Rows[i]["FILE_NO"].ToString() == _image1)
                    {
                        pictureBox1.Image = ByteArrayToImage((byte[])dt.Rows[i]["IMAGE_DATA"]);
                    }
                    if (dt.Rows[i]["FILE_NO"].ToString() == _image2)
                    {
                        pictureBox2.Image = ByteArrayToImage((byte[])dt.Rows[i]["IMAGE_DATA"]);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void fnRegistrationFile(FileInfo _fileInfo, int image_seq, int _Row)
        {
            TRSNode tRSNode = new TRSNode("Update_File_In");
            TRSNode out_node = new TRSNode("Update_File_Out");
            MPCR.SetInMsg(tRSNode);
            tRSNode.ProcStep = '1';
            string text = "";
            if (_fileInfo.Exists)
            {
                BinaryReader binaryReader = new BinaryReader(_fileInfo.OpenRead());
                byte[] value = binaryReader.ReadBytes((int)_fileInfo.Length);
                tRSNode.AddBlob("__BIN_DATA_1", value);
                tRSNode.AddInt("IMAGE_SIZE", _fileInfo.Length);
                binaryReader.Close();
            }
            if (MPCR.CallService("CUS_QCM", "CUS_QCM_File_Attach", tRSNode, ref out_node))
            {
                text = out_node.GetString("FILE_NO");
                spdPackingLotList.ActiveSheet.Cells[_Row, image_seq].Value = text;
            }
        }

        private void fnPrintShipReport(string sViewID, string sFileName)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "REPORT_NO";
                array[1].sCondition_Value = cdvReportNo.Text;
                if (!TPDR.GetDataOne("", ref dt, sViewID, array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    return;
                }
                dt.Columns.Add("IMAGE_A", typeof(byte[]));
                dt.Columns.Add("IMAGE_B", typeof(byte[]));
                num = dt.Rows.Count;
                for (int i = 0; i < num; i++)
                {
                    string sCondition_Value = dt.Rows[i]["REPORT_NO"].ToString();
                    string sCondition_Value2 = dt.Rows[i]["IMAGE_LOT_ID"].ToString();
                    TPDR.DirectViewCond[] array2 = new TPDR.DirectViewCond[3];
                    DataTable dt2 = null;
                    array2[0].sCondition_ID = "FACTORY";
                    array2[0].sCondition_Value = MPGV.gsFactory;
                    array2[1].sCondition_ID = "REPORT_NO";
                    array2[1].sCondition_Value = sCondition_Value;
                    array2[2].sCondition_ID = "LOT_ID";
                    array2[2].sCondition_Value = sCondition_Value2;
                    if (!TPDR.GetDataOne("", ref dt2, "CQCM2101-010", array2, bIcon: false, bBGColor: false, ref sSql))
                    {
                        dt2?.Dispose();
                        GC.Collect();
                        return;
                    }
                    dt.Rows[i]["IMAGE_A"] = dt2.Rows[0]["IMAGE_A"];
                    dt.Rows[i]["IMAGE_B"] = dt2.Rows[0]["IMAGE_B"];
                }
                DevReport.PreviewXtraReport(dt, sFileName);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnGenerateReport_Click(object sender, EventArgs e)
        {
            if (fnGenerateReport())
            {           
                fnviewReport(cdvReportNo.Text);
            }
        }

        private void mcCodeView1_ButtonPress(object sender, EventArgs e)
        {
        }

        private void btnPrint_Click(object sender, EventArgs e)
        {
            if (CheckCondition("PRINT"))
            {
                if (cdvShipReportType.Text == "HM_01")
                {
                    fnPrintShipReport("CQCM2101-006", "pip520pa");
                }
                else if (cdvShipReportType.Text == "HM_02")
                {
                    fnPrintShipReport("CQCM2101-007", "pip520pb");
                }
                else if (cdvShipReportType.Text == "HM_03")
                {
                    fnPrintShipReport("CQCM2101-011", "pip520pc");
                }
                else if (cdvShipReportType.Text == "HM_04")
                {
                    fnPrintShipReport("CQCM2105-003", "pip520pd"); 
                }
            }
        }

        private void btnProcess_Click(object sender, EventArgs e)
        {
            if (CheckCondition("SAVE") && fnSaveReport())
            {
            }
        }

        private void btnView_Click(object sender, EventArgs e)
        {
        }

        private void cdvPackOrderNo_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopPackingOrderList frmPopPackingOrderList = new frmPopPackingOrderList();
                frmPopPackingOrderList.StartPosition = FormStartPosition.CenterParent;
                if (frmPopPackingOrderList.ShowDialog() != DialogResult.OK)
                {
                    return;
                }
                if (frmPopPackingOrderList.s_pack_order_id != "")
                {
                    cdvPackOrderNo.Text = frmPopPackingOrderList.s_pack_order_id;
                    txtLineNo.Text = frmPopPackingOrderList.s_pack_line_no;
                    txtCustomerDesc.Text = frmPopPackingOrderList.s_customer_desc;
                    txtMatDesc.Text = frmPopPackingOrderList.s_mat_desc;
                    txtGrade.Text = frmPopPackingOrderList.s_grade;
                    txtType.Text = frmPopPackingOrderList.s_types;
                    if (MPCF.Trim(cdvPackOrderNo.Text) != "")
                    {
                        ViewPackingLotList(cdvPackOrderNo.Text, txtLineNo.Text);
                        if (spdPackingLotList.ActiveSheet.Rows.Count > 0)
                        {
                            txtGrade.Text = spdPackingLotList.ActiveSheet.Cells[0, 8].Text;
                            txtType.Text = spdPackingLotList.ActiveSheet.Cells[0, 9].Text;
                            txtEndShipToName.Text = spdPackingLotList.ActiveSheet.Cells[0, 7].Text;
                            txtRemark.Text = spdPackingLotList.ActiveSheet.Cells[0, 29].Text;
                        }
                    }
                    cdvReportNo.Text = "";
                }
                frmPopPackingOrderList = null;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvReportNo_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopShipReportList frmPopShipReportList = new frmPopShipReportList();
                frmPopShipReportList.StartPosition = FormStartPosition.CenterParent;
                frmPopShipReportList.s_area_id = cdvDept.Text;
                if (frmPopShipReportList.ShowDialog() != DialogResult.OK)
                {
                    return;
                }
                if (frmPopShipReportList.s_report_no != "")
                {
                    cdvReportNo.Text = frmPopShipReportList.s_report_no;
                    if (MPCF.Trim(cdvReportNo.Text) != "")
                    {
                        fnviewReport(cdvReportNo.Text);
                    }
                }
                frmPopShipReportList = null;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvReportNo_SelectedItemChanged(object sender, MCCodeViewSelChanged_EventArgs e)
        {
        }

        private void frmTranShipReportRegistration_HM_Load(object sender, EventArgs e)
        {
            fnGetUserDesc();
        }

        private void ultraButton1_Click(object sender, EventArgs e)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[1];
                DataTable dt = null;
                string sSql = "";
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                if (!TPDR.GetDataOne("", ref dt, "CQCM9999-999", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                }
                else
                {
                    pictureBox1.Image = ByteArrayToImage((byte[])dt.Rows[0]["IMG"]);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdPackingLotList_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (spdPackingLotList.ActiveSheet.ActiveRowIndex >= 0)
            {
                if (spdPackingLotList.ActiveSheet.ActiveRowIndex == iFocusRow)
                {
                    iFocusRow = spdPackingLotList.ActiveSheet.ActiveRowIndex;
                    return;
                }
                int activeRowIndex = spdPackingLotList.ActiveSheet.ActiveRowIndex;
                pictureBox1.Image = null;
                pictureBox2.Image = null;
                string image = MPCF.Trim(spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 30].Value.ToString());
                string image2 = MPCF.Trim(spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 31].Value.ToString());
                ViewImageFile(image, image2);
                txtLengthSpecMIN.Text = spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 34].Text;
                txtLengthSpecMAX.Text = spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 35].Text;
                txtODMeterMIN.Text = spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 32].Text;
                txtODMeterMAX.Text = spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 33].Text;
                txtSGMIN.Text = spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 36].Text;
                txtSGMAX.Text = spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 37].Text;
                txtMSMIN.Text = spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 38].Text;
                txtMSMAX.Text = spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 39].Text;
                txtHCMIN.Text = spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 40].Text;
                txtHCMAX.Text = spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 41].Text;
                txtHVMIN.Text = spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 42].Text;
                txtHVMAX.Text = spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 43].Text;
                txtTRSMIN.Text = spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 44].Text;
                txtTRSMAX.Text = spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 45].Text;
                txtGRAINSIZEMIN.Text = spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 46].Text;
                txtGRAINSIZEMAX.Text = spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 47].Text;
                txtGrade.Text = spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 8].Text;
                txtType.Text = spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 9].Text;
                txtEndShipToName.Text = spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 7].Text;
                txtRemark.Text = spdPackingLotList.ActiveSheet.Cells[activeRowIndex, 29].Text;
                iFocusRow = spdPackingLotList.ActiveSheet.ActiveRowIndex;
            }
        }

        private void btnImage1_Click(object sender, EventArgs e)
        {
            string text = "";
            if (CheckCondition("FILE_UPLOAD"))
            {
                int activeRowIndex = spdPackingLotList.ActiveSheet.ActiveRowIndex;
                if (openFileDialog1.ShowDialog() == DialogResult.OK)
                {
                    text = openFileDialog1.FileName;
                    pictureBox1.Image = Image.FromFile(openFileDialog1.FileName);
                    FileInfo fileInfo = new FileInfo(text);
                    fnRegistrationFile(fileInfo, 30, activeRowIndex);
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string text = "";
            if (CheckCondition("FILE_UPLOAD"))
            {
                int activeRowIndex = spdPackingLotList.ActiveSheet.ActiveRowIndex;
                if (openFileDialog1.ShowDialog() == DialogResult.OK)
                {
                    text = openFileDialog1.FileName;
                    pictureBox2.Image = Image.FromFile(openFileDialog1.FileName);
                    FileInfo fileInfo = new FileInfo(text);
                    fnRegistrationFile(fileInfo, 31, activeRowIndex);
                }
            }
        }
    }
}
