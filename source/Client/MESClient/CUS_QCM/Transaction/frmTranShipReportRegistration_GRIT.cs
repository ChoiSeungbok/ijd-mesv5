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
using Infragistics.Win;
using static DevExpress.Utils.Drawing.Helpers.NativeMethods;
using static DevExpress.Utils.Svg.CommonSvgImages;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.TextBox;
using Infragistics.Win.UltraWinProgressBar;
using FarPoint.Excel.EntityClassLibrary.DrawingEx;
//using Microsoft.Office.Interop.Excel;

namespace CUS_QCM
{
    public partial class frmTranShipReportRegistration_GRIT : frmTranForm05
    {
        public frmTranShipReportRegistration_GRIT()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum PACK_LOT
        {
            CHK,                  
            PACK_ORDER_ID,
            LINE,
            PACK_LOT_ID,             
            ORG_LOT_ID,              
            MAT_ID,
            GRADE,
            SIZES,
            INSP_JUDGE,
            INSP_COMMENT,

            TI_SPEC,
            TTI_SPEC,
            WT_SPEC,
            BD_SPEC,
            PSD_TS_SPEC,
            PSD_US_SPEC,
            PSD_OS_SPEC,
            PSD_SS_SPEC,
            PSD_LS_SPEC,
            PSD_FS_SPEC,
            HLT_TI_SPEC,

            TI_VAL,
            TTI_VAL,
            HLT_TI_VAL,
            WT_VAL,
            BD_VAL,
            CM_L_VAL,
            CM_A_VAL,
            CM_B_VAL,
            PSD_TS_VAL,
            PSD_US_VAL,
            PSD_OS_VAL,
            PSD_SS_VAL,
            PSD_LS_VAL,
            PSD_FS_VAL,
            SURFACE_B_VAL,

            REMARKS,

            IMAGE_1,
            IMAGE_2,
            IMAGE_3,

            TI_LOWWER,
            TI_UPPER,
            TTI_LOWWER,
            TTI_UPPER,
            HLT_TI_LOWWER,
            HLT_TI_UPPER,
            WT_LOWWER,
            WT_UPPER,
            BD_LOWWER,
            BD_UPPER,
            CM_L_LOWWER,
            CM_L_UPPER,
            CM_A_LOWWER,
            CM_A_UPPER,
            CM_B_LOWWER,
            CM_B_UPPER,
            PSD_TS_LOWWER,
            PSD_TS_UPPER,
            PSD_US_LOWWER,
            PSD_US_UPPER,
            PSD_OS_LOWWER,
            PSD_OS_UPPER,
                PSD_SS_LOWWER,
                PSD_SS_UPPER,
            PSD_LS_LOWWER,
            PSD_LS_UPPER,
            PSD_FS_LOWWER,
            PSD_FS_UPPER,
            SURFACE_B_LOWWER,
            SURFACE_B_UPPER,

        }

        private enum PIVOT_LIST
        {
            CHK,
            SEQ,
            ITEM,
            SPEC_VAL,
            LOT_01,
            LOT_02,
            LOT_03,
            LOT_04,
            LOT_05,
            LOT_06,
            LOT_07,
            IMAGE_1,
            IMAGE_2,
            IMAGE_3

        }

        #endregion

        #region " Variable Definition "
        private const int LOT_COL_START = 4;
        private const int LOT_COL_END = 11;


        private enum ASPECT_LIST
        {
            SORT_NO,
            QC_NAME,
            SPEC_VAL,
            VAL_01,
            VAL_02,
            VAL_03,
            VAL_04,
            VAL_05,
            VAL_06
        }
        private enum ICP_LIST
        {
            SORT_NO,
            QC_NAME,
            SPEC_VAL,
            VAL_01,
            VAL_02,
            VAL_03,
            VAL_04,
            VAL_05,
            VAL_06
        }

        #endregion

        #region " Function Definition "
        private void InitControl()
        {
            try
            {
                cdvDept.Text = CSGC.CP_AREA_GRT;

                fngetReportType(cdvShipReportType.GetListView);

                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnGenerateReport.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnGCM3.Anchor = AnchorStyles.Top | AnchorStyles.Right;



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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "PACK_ORDER_ID";
                dvcArgu[1].sCondition_Value = packOrderId;

                dvcArgu[2].sCondition_ID = "PACK_LINE_NO";
                dvcArgu[2].sCondition_Value = packLineNo;


                if(txtCustomerDesc.Text == "신한다이아몬드공업(주)")
                {
                    if (MPCF.ShowMsgBox("OS 와 SS의 측정값을 분할하시겠습니까? ", MessageBoxButtons.YesNo, 2) == System.Windows.Forms.DialogResult.Yes)
                    {
                        dvcArgu[3].sCondition_ID = "SS_VAL_SP";
                        dvcArgu[3].sCondition_Value = "Y";
                    }
                    else
                    {
                        dvcArgu[3].sCondition_ID = "SS_VAL_SP";
                        dvcArgu[3].sCondition_Value = "N";
                    }


                }
                else
                {
                    dvcArgu[3].sCondition_ID = "SS_VAL_SP";
                    dvcArgu[3].sCondition_Value = "N";
                }

                if (TPDR.GetDataOne("", ref dt, "CQCM2102-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdPackingLotList);
                    return;
                }

                MPCF.ClearList(spdPackingLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdPackingLotList_Sheet1.RowCount++;

                    spdPackingLotList_Sheet1.SetValue(i, (int)PACK_LOT.CHK, false);
                    
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.LINE].Value = dt.Rows[i]["LINE"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Value = dt.Rows[i]["PACK_LOT_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Value = dt.Rows[i]["ORG_LOT_ID"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.GRADE].Value = dt.Rows[i]["GRADE"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SIZES].Value = dt.Rows[i]["SIZES"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.INSP_JUDGE].Value = dt.Rows[i]["INSP_JUDGE"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.INSP_COMMENT].Value = dt.Rows[i]["INSP_COMMENT"];



                    //SPEC
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.TI_SPEC].Value = dt.Rows[i]["TI_SPEC"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.TTI_SPEC].Value = dt.Rows[i]["TTI_SPEC"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.HLT_TI_SPEC].Value = dt.Rows[i]["HLT_TI_SPEC"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.WT_SPEC].Value = dt.Rows[i]["WT_SPEC"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BD_SPEC].Value = dt.Rows[i]["BD_SPEC"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_TS_SPEC].Value = dt.Rows[i]["PSD_TS_SPEC"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_US_SPEC].Value = dt.Rows[i]["PSD_US_SPEC"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_OS_SPEC].Value = dt.Rows[i]["PSD_OS_SPEC"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_SS_SPEC].Value = dt.Rows[i]["PSD_SS_SPEC"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_LS_SPEC].Value = dt.Rows[i]["PSD_LS_SPEC"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_FS_SPEC].Value = dt.Rows[i]["PSD_FS_SPEC"];


                    //VALUE
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.TI_VAL].Value = dt.Rows[i]["TI_VAL"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.TTI_VAL].Value = dt.Rows[i]["TTI_VAL"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.HLT_TI_VAL].Value = dt.Rows[i]["HLT_TI_VAL"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.WT_VAL].Value = dt.Rows[i]["WT_VAL"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BD_VAL].Value = dt.Rows[i]["BD_VAL"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CM_L_VAL].Value = dt.Rows[i]["CM_L_VAL"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CM_A_VAL].Value = dt.Rows[i]["CM_A_VAL"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CM_B_VAL].Value = dt.Rows[i]["CM_B_VAL"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_TS_VAL].Value = dt.Rows[i]["PSD_TS_VAL"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_US_VAL].Value = dt.Rows[i]["PSD_US_VAL"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_OS_VAL].Value = dt.Rows[i]["PSD_OS_VAL"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_SS_VAL].Value = dt.Rows[i]["PSD_SS_VAL"];


                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_LS_VAL].Value = dt.Rows[i]["PSD_LS_VAL"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_FS_VAL].Value = dt.Rows[i]["PSD_FS_VAL"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SURFACE_B_VAL].Value = dt.Rows[i]["SURFACE_B_VAL"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.REMARKS].Value = dt.Rows[i]["REMARKS"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE_1].Value = dt.Rows[i]["IMAGE_1"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE_2].Value = dt.Rows[i]["IMAGE_2"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE_3].Value = dt.Rows[i]["IMAGE_3"];


                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.TI_LOWWER].Value = dt.Rows[i]["TI_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.TI_UPPER].Value = dt.Rows[i]["TI_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.TTI_LOWWER].Value = dt.Rows[i]["TTI_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.TTI_UPPER].Value = dt.Rows[i]["TTI_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.HLT_TI_LOWWER].Value = dt.Rows[i]["HLT_TI_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.HLT_TI_UPPER].Value = dt.Rows[i]["HLT_TI_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.WT_LOWWER].Value = dt.Rows[i]["WT_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.WT_UPPER].Value = dt.Rows[i]["WT_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BD_LOWWER].Value = dt.Rows[i]["BD_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BD_UPPER].Value = dt.Rows[i]["BD_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CM_L_LOWWER].Value = dt.Rows[i]["CM_L_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CM_L_UPPER].Value = dt.Rows[i]["CM_L_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CM_A_LOWWER].Value = dt.Rows[i]["CM_A_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CM_A_UPPER].Value = dt.Rows[i]["CM_A_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CM_B_LOWWER].Value = dt.Rows[i]["CM_B_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CM_B_UPPER].Value = dt.Rows[i]["CM_B_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_TS_LOWWER].Value = dt.Rows[i]["PSD_TS_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_TS_UPPER].Value = dt.Rows[i]["PSD_TS_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_US_LOWWER].Value = dt.Rows[i]["PSD_US_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_US_UPPER].Value = dt.Rows[i]["PSD_US_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_OS_LOWWER].Value = dt.Rows[i]["PSD_OS_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_OS_UPPER].Value = dt.Rows[i]["PSD_OS_UPPER"];
                        spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_SS_LOWWER].Value = dt.Rows[i]["PSD_OS_LOWWER"];
                        spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_SS_UPPER].Value = dt.Rows[i]["PSD_OS_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_LS_LOWWER].Value = dt.Rows[i]["PSD_LS_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_LS_UPPER].Value = dt.Rows[i]["PSD_LS_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_FS_LOWWER].Value = dt.Rows[i]["PSD_FS_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_FS_UPPER].Value = dt.Rows[i]["PSD_FS_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SURFACE_B_LOWWER].Value = dt.Rows[i]["SURFACE_B_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SURFACE_B_UPPER].Value = dt.Rows[i]["SURFACE_B_UPPER"];




                }
                //MPCF.FitColumnHeader(spdPackingLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void ViewPivotList(string ReportNo, string sMatID)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "REPORT_NO";
                dvcArgu[1].sCondition_Value = ReportNo;

                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = sMatID;


                if (TPDR.GetDataOne("", ref dt, "CQCM2102-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdPivotList);
                    return;
                }

                MPCF.ClearList(spdPivotList);


                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdPivotList.ActiveSheet.RowCount++;

                    //spdPivotList.ActiveSheet.SetValue(i, (int)PIVOT_LIST.CHK, false);

                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.CHK].Value = dt.Rows[i]["CHK"].ToString() == "Y" ? true : false;

                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.SEQ].Value = dt.Rows[i]["SEQ"];
                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.ITEM].Value = dt.Rows[i]["ITEM"];
                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.SPEC_VAL].Value = dt.Rows[i]["SPEC_VAL"];

                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_01].Value = dt.Rows[i]["LOT_01"];
                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_02].Value = dt.Rows[i]["LOT_02"];
                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_03].Value = dt.Rows[i]["LOT_03"];
                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_04].Value = dt.Rows[i]["LOT_04"];
                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_05].Value = dt.Rows[i]["LOT_05"];
                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_06].Value = dt.Rows[i]["LOT_06"];
                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_07].Value = dt.Rows[i]["LOT_07"];

                }
                //MPCF.FitColumnHeader(spdPackingLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void fnviewReport_2(string ReportNo)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                string s_image_1 = "";
                string s_image_2 = "";
                string s_image_3 = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "REPORT_NO";
                dvcArgu[1].sCondition_Value = ReportNo;


                if (TPDR.GetDataOne("", ref dt, "CQCM2102-007", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdPivotList);
                    return;
                }

                MPCF.ClearList(spdPivotList);


                for (i = 0; i < dt.Rows.Count; i++)
                {

                    if (i == 0)
                    {
                        //Grit 이미지  바인딩
                        pictureBox1.Image = null;
                        pictureBox2.Image = null;
                        pictureBox3.Image = null;

                        //txtRemarks.Text = dt.Rows[i]["REMARKS"].ToString();
                        //txtCustomerDesc.Text = dt.Rows[i]["CUST_NO"].ToString();

                        s_image_1 = dt.Rows[i]["IMAGE_NUM"].ToString();
                        s_image_2 = dt.Rows[i]["IMAGE_NUM2"].ToString();
                        s_image_3 = dt.Rows[i]["IMAGE_NUM3"].ToString();

                        ViewImageFile(s_image_1, s_image_2, s_image_3);

                    }
                    spdPivotList.ActiveSheet.RowCount++;

                    spdPivotList.ActiveSheet.SetValue(i, (int)PIVOT_LIST.CHK, dt.Rows[i]["USE_YN"].ToString() == "Y" ? true : false);

                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.SEQ].Value = dt.Rows[i]["SEQ"];
                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.ITEM].Value = dt.Rows[i]["ITEM"];
                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.SPEC_VAL].Value = dt.Rows[i]["SPEC_VAL"];

                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_01].Value = dt.Rows[i]["LOT_01"];
                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_02].Value = dt.Rows[i]["LOT_02"];
                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_03].Value = dt.Rows[i]["LOT_03"];
                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_04].Value = dt.Rows[i]["LOT_04"];
                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_05].Value = dt.Rows[i]["LOT_05"];
                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_06].Value = dt.Rows[i]["LOT_06"];
                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_07].Value = dt.Rows[i]["LOT_07"];

                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.IMAGE_1].Value = dt.Rows[i]["IMAGE_NUM"];
                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.IMAGE_2].Value = dt.Rows[i]["IMAGE_NUM2"];
                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.IMAGE_3].Value = dt.Rows[i]["IMAGE_NUM3"];



                    if (MPCF.ToDbl(spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.SEQ].Text) > 3)
                    {
                        for (int iCol = (int)PIVOT_LIST.LOT_01; iCol <= (int)PIVOT_LIST.LOT_07; iCol++)
                        {

                            if(spdPivotList.ActiveSheet.Cells[2, iCol].Text.Trim().Length > 0)
                            {
                                SpecSearch(i, iCol);
                            }
       
                        }

                    }

                }
                //MPCF.FitColumnHeader(spdPackingLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void ViewAspectList(string ReportNo)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "REPORT_NO";
                dvcArgu[1].sCondition_Value = ReportNo;


                if (TPDR.GetDataOne("", ref dt, "CQCM2102-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdAspectList);
                    return;
                }

                MPCF.ClearList(spdAspectList);


                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdAspectList.ActiveSheet.RowCount++;

                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.SORT_NO].Value = dt.Rows[i]["SORT_NO"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.QC_NAME].Value = dt.Rows[i]["QC_NAME"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.SPEC_VAL].Value = dt.Rows[i]["SPEC_VAL"];

                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_01].Value = dt.Rows[i]["VAL_01"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_02].Value = dt.Rows[i]["VAL_02"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_03].Value = dt.Rows[i]["VAL_03"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_04].Value = dt.Rows[i]["VAL_04"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_05].Value = dt.Rows[i]["VAL_05"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_06].Value = dt.Rows[i]["VAL_06"];

                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void ViewIcptList(string ReportNo)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "REPORT_NO";
                dvcArgu[1].sCondition_Value = ReportNo;


                if (TPDR.GetDataOne("", ref dt, "CQCM2102-013", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdIcpList);
                    return;
                }

                MPCF.ClearList(spdIcpList);


                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdIcpList.ActiveSheet.RowCount++;

                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.SORT_NO].Value = dt.Rows[i]["SORT_NO"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.QC_NAME].Value = dt.Rows[i]["QC_NAME"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.SPEC_VAL].Value = dt.Rows[i]["SPEC_VAL"];

                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_01].Value = dt.Rows[i]["VAL_01"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_02].Value = dt.Rows[i]["VAL_02"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_03].Value = dt.Rows[i]["VAL_03"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_04].Value = dt.Rows[i]["VAL_04"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_05].Value = dt.Rows[i]["VAL_05"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_06].Value = dt.Rows[i]["VAL_06"];

                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void fnviewReport_3(string ReportNo)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "REPORT_NO";
                dvcArgu[1].sCondition_Value = ReportNo;


                if (TPDR.GetDataOne("", ref dt, "CQCM2102-008", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdAspectList);
                    return;
                }

                MPCF.ClearList(spdAspectList);


                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdAspectList.ActiveSheet.RowCount++;

                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.SORT_NO].Value = dt.Rows[i]["SORT_NO"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.QC_NAME].Value = dt.Rows[i]["QC_NAME"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.SPEC_VAL].Value = dt.Rows[i]["SPEC_VAL"];

                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_01].Value = dt.Rows[i]["VAL_01"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_02].Value = dt.Rows[i]["VAL_02"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_03].Value = dt.Rows[i]["VAL_03"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_04].Value = dt.Rows[i]["VAL_04"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_05].Value = dt.Rows[i]["VAL_05"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_06].Value = dt.Rows[i]["VAL_06"];

                    
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void fnviewReport_4(string ReportNo)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "REPORT_NO";
                dvcArgu[1].sCondition_Value = ReportNo;


                if (TPDR.GetDataOne("", ref dt, "CQCM2102-014", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdIcpList);
                    return;
                }

                MPCF.ClearList(spdIcpList);


                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdIcpList.ActiveSheet.RowCount++;

                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.SORT_NO].Value = dt.Rows[i]["SORT_NO"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.QC_NAME].Value = dt.Rows[i]["QC_NAME"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.SPEC_VAL].Value = dt.Rows[i]["SPEC_VAL"];

                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_01].Value = dt.Rows[i]["VAL_01"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_02].Value = dt.Rows[i]["VAL_02"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_03].Value = dt.Rows[i]["VAL_03"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_04].Value = dt.Rows[i]["VAL_04"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_05].Value = dt.Rows[i]["VAL_05"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_06].Value = dt.Rows[i]["VAL_06"];


                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void fnviewReport_OP_ASPECT(string LOT_ID)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "LOT_ID";
                dvcArgu[1].sCondition_Value = LOT_ID;


                if (TPDR.GetDataOne("", ref dt, "CQCM2102-016", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdAspectList);
                    return;
                }

                MPCF.ClearList(spdAspectList);


                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdAspectList.ActiveSheet.RowCount++;

                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.SORT_NO].Value = dt.Rows[i]["SORT_NO"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.QC_NAME].Value = dt.Rows[i]["QC_NAME"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.SPEC_VAL].Value = dt.Rows[i]["SPEC_VAL"];

                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_01].Value = dt.Rows[i]["VAL_01"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_02].Value = dt.Rows[i]["VAL_02"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_03].Value = dt.Rows[i]["VAL_03"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_04].Value = dt.Rows[i]["VAL_04"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_05].Value = dt.Rows[i]["VAL_05"];
                    spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_06].Value = dt.Rows[i]["VAL_06"];


                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void fnviewReport_OP_ICP(string LOT_ID)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "LOT_ID";
                dvcArgu[1].sCondition_Value = LOT_ID;


                if (TPDR.GetDataOne("", ref dt, "CQCM2102-017", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdIcpList);
                    return;
                }

                MPCF.ClearList(spdIcpList);


                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdIcpList.ActiveSheet.RowCount++;

                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.SORT_NO].Value = dt.Rows[i]["SORT_NO"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.QC_NAME].Value = dt.Rows[i]["QC_NAME"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.SPEC_VAL].Value = dt.Rows[i]["SPEC_VAL"];

                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_01].Value = dt.Rows[i]["VAL_01"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_02].Value = dt.Rows[i]["VAL_02"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_03].Value = dt.Rows[i]["VAL_03"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_04].Value = dt.Rows[i]["VAL_04"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_05].Value = dt.Rows[i]["VAL_05"];
                    spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_06].Value = dt.Rows[i]["VAL_06"];


                }

                return;
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
                        //1 spdlotlist count > 0이상
                        if (spdPackingLotList.ActiveSheet.RowCount < 1)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(486));
                            return false;
                        }

                        //2 발번이 이미 되어있는지
                        if (cdvReportNo.Text != "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(487));
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
                       /* if (cdvReportNo.Text == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(489));
                            return false;
                        }*/

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

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

           // string s_flow = spdLotList.ActiveSheet.Cells[0, (int)LOT_INFO.FLOW].Value.ToString();

            in_node.AddString("SQL", "SELECT KEY_1 AS CODE,  "
                                                + "      DATA_1 AS VALUE    "
                                                + "  FROM MGCMTBLDAT  "
                                                + "  WHERE FACTORY = '" + MPGV.gsFactory + "' "
                                                + "   AND TABLE_NAME = 'C_INSP_SHIP_REPORT' "
                                                + "   AND DATA_2 = '" + CSGC.CP_AREA_GRT + "' "
                                                + "   AND DATA_3 = 'N'" );
            

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
        private void fnviewReport_1(string sReportNo)
        {
            //레포트 조회후 화면 바인딩

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
               // int ichk = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "REPORT_NO";
                dvcArgu[1].sCondition_Value = sReportNo;



                if (TPDR.GetDataOne("", ref dt, "CQCM2102-006", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdPackingLotList);
                    return;
                }

                MPCF.ClearList(spdPackingLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdPackingLotList.ActiveSheet.RowCount++;

                    if (i == 0)
                    {
                        //txtGrade.Text = dt.Rows[i]["GRADE"].ToString();
                        txtEndShipToName.Text = dt.Rows[i]["CUST_NO"].ToString();
                        txtRemarks.Text = dt.Rows[i]["REMARKS"].ToString();
                        
                    }


                    spdPackingLotList.ActiveSheet.SetValue(i, (int)PACK_LOT.CHK, false);

                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LINE].Value = dt.Rows[i]["LINE"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Value = dt.Rows[i]["PACK_LOT_ID"];

                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.GRADE].Value = dt.Rows[i]["GRADE"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SIZES].Value = dt.Rows[i]["SIZES"];




                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.TI_SPEC].Value = dt.Rows[i]["TI_SPEC"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.TTI_SPEC].Value = dt.Rows[i]["TTI_SPEC"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.WT_SPEC].Value = dt.Rows[i]["WT_SPEC"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.BD_SPEC].Value = dt.Rows[i]["BD_SPEC"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_TS_SPEC].Value = dt.Rows[i]["PSD_TS_SPEC"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_US_SPEC].Value = dt.Rows[i]["PSD_US_SPEC"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_OS_SPEC].Value = dt.Rows[i]["PSD_OS_SPEC"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_LS_SPEC].Value = dt.Rows[i]["PSD_LS_SPEC"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_FS_SPEC].Value = dt.Rows[i]["PSD_FS_SPEC"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.HLT_TI_SPEC].Value = dt.Rows[i]["HLT_TI_SPEC"];

                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.TI_VAL].Value = dt.Rows[i]["TI_VAL"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.TTI_VAL].Value = dt.Rows[i]["TTI_VAL"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.WT_VAL].Value = dt.Rows[i]["WT_VAL"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.BD_VAL].Value = dt.Rows[i]["BD_VAL"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_TS_VAL].Value = dt.Rows[i]["PSD_TS_VAL"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_US_VAL].Value = dt.Rows[i]["PSD_US_VAL"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_OS_VAL].Value = dt.Rows[i]["PSD_OS_VAL"];
                        spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_SS_VAL].Value = dt.Rows[i]["PSD_SS_VAL"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_LS_VAL].Value = dt.Rows[i]["PSD_LS_VAL"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_FS_VAL].Value = dt.Rows[i]["PSD_FS_VAL"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.HLT_TI_VAL].Value = dt.Rows[i]["HLT_TI_VAL"];

                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CM_L_VAL].Value = dt.Rows[i]["CM_L_VAL"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CM_A_VAL].Value = dt.Rows[i]["CM_A_VAL"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CM_B_VAL].Value = dt.Rows[i]["CM_B_VAL"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SURFACE_B_VAL].Value = dt.Rows[i]["SURFACE_B_VAL"];

                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE_1].Value = dt.Rows[i]["IMAGE_NUM"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE_2].Value = dt.Rows[i]["IMAGE_NUM2"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE_3].Value = dt.Rows[i]["IMAGE_NUM3"];


                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.INSP_JUDGE].Value = dt.Rows[i]["INSP_JUDGE"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.INSP_COMMENT].Value = dt.Rows[i]["INSP_COMMENT"];




                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.TI_LOWWER].Value = dt.Rows[i]["TI_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.TI_UPPER].Value = dt.Rows[i]["TI_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.TTI_LOWWER].Value = dt.Rows[i]["TTI_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.TTI_UPPER].Value = dt.Rows[i]["TTI_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.HLT_TI_LOWWER].Value = dt.Rows[i]["HLT_TI_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.HLT_TI_UPPER].Value = dt.Rows[i]["HLT_TI_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.WT_LOWWER].Value = dt.Rows[i]["WT_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.WT_UPPER].Value = dt.Rows[i]["WT_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BD_LOWWER].Value = dt.Rows[i]["BD_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BD_UPPER].Value = dt.Rows[i]["BD_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CM_L_LOWWER].Value = dt.Rows[i]["CM_L_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CM_L_UPPER].Value = dt.Rows[i]["CM_L_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CM_A_LOWWER].Value = dt.Rows[i]["CM_A_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CM_A_UPPER].Value = dt.Rows[i]["CM_A_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CM_B_LOWWER].Value = dt.Rows[i]["CM_B_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CM_B_UPPER].Value = dt.Rows[i]["CM_B_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_TS_LOWWER].Value = dt.Rows[i]["PSD_TS_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_TS_UPPER].Value = dt.Rows[i]["PSD_TS_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_US_LOWWER].Value = dt.Rows[i]["PSD_US_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_US_UPPER].Value = dt.Rows[i]["PSD_US_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_OS_LOWWER].Value = dt.Rows[i]["PSD_OS_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_OS_UPPER].Value = dt.Rows[i]["PSD_OS_UPPER"];
                        spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_SS_LOWWER].Value = dt.Rows[i]["PSD_OS_LOWWER"];
                        spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_SS_UPPER].Value = dt.Rows[i]["PSD_OS_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_LS_LOWWER].Value = dt.Rows[i]["PSD_LS_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_LS_UPPER].Value = dt.Rows[i]["PSD_LS_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_FS_LOWWER].Value = dt.Rows[i]["PSD_FS_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PSD_FS_UPPER].Value = dt.Rows[i]["PSD_FS_UPPER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SURFACE_B_LOWWER].Value = dt.Rows[i]["SURFACE_B_LOWWER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SURFACE_B_UPPER].Value = dt.Rows[i]["SURFACE_B_UPPER"];



                }
                // MPCF.FitColumnHeader(spdWorkerList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void fnviewPivotReport(string sReportNo)
        {
            //레포트 조회후 화면 바인딩

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                // int ichk = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "REPORT_NO";
                dvcArgu[1].sCondition_Value = sReportNo;



                if (TPDR.GetDataOne("", ref dt, "CQCM2102-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdPivotList);
                    return;
                }

                MPCF.ClearList(spdPivotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdPivotList.ActiveSheet.RowCount++;


                    spdPivotList.ActiveSheet.SetValue(i, (int)PACK_LOT.CHK, false);

                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LINE].Value = dt.Rows[i]["LINE"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Value = dt.Rows[i]["PACK_LOT_ID"];

                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.GRADE].Value = dt.Rows[i]["GRADE"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SIZES].Value = dt.Rows[i]["SIZES"];


                }
                // MPCF.FitColumnHeader(spdWorkerList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private bool fnGenerateReport()
        {

            if (CheckCondition("GENERATE") == false)
            {
                return false;
            }

            TRSNode in_node = new TRSNode("GENERATE_REPORT_IN");
            TRSNode out_node = new TRSNode("GENERATE_REPORT_OUT");
            TRSNode data_list;

            int ichk = 0;
           
            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '3'; //GRIT 발번
                in_node.AddString("AREA_ID", cdvDept.Text);

                //기본 포장 lot정보 (스펙,  값)
                for (int i = 0; i < spdPackingLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        data_list = in_node.AddNode("DATA_LIST");

                        data_list.AddString("HEADER_ID", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_ORDER_ID].Text);
                        data_list.AddString("LINE_NUMBER", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LINE].Text);
                        data_list.AddString("PACK_LOT_ID", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text);

                        data_list.AddString("GRADE", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.GRADE].Text);
                        data_list.AddString("SIZES", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SIZES].Text);

                        data_list.AddString("CUST_NO", MPCF.Trim(txtEndShipToName.Text));  //추가필요
                        data_list.AddString("REMARKS", MPCF.Trim(txtRemarks.Text));  //추가필요

                        data_list.AddString("TI_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.TI_SPEC].Text);
                        data_list.AddString("TTI_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.TTI_SPEC].Text);
                        data_list.AddString("WT_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.WT_SPEC].Text);
                        data_list.AddString("BD_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.BD_SPEC].Text);
                        data_list.AddString("PSD_TS_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_TS_SPEC].Text);
                        data_list.AddString("PSD_US_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_US_SPEC].Text);
                        data_list.AddString("PSD_OS_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_OS_SPEC].Text);
                            data_list.AddString("PSD_SS_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_OS_SPEC].Text);
                        data_list.AddString("PSD_LS_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_LS_SPEC].Text);
                        data_list.AddString("PSD_FS_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_FS_SPEC].Text);
                        data_list.AddString("HLT_TI_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.HLT_TI_SPEC].Text);

                        data_list.AddString("TI_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.TI_VAL].Text);
                        data_list.AddString("TTI_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.TTI_VAL].Text);
                        data_list.AddString("WT_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.WT_VAL].Text);
                        data_list.AddString("BD_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.BD_VAL].Text);
                        data_list.AddString("PSD_TS_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_TS_VAL].Text);
                        data_list.AddString("PSD_US_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_US_VAL].Text);
                        data_list.AddString("PSD_OS_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_OS_VAL].Text);
                            data_list.AddString("PSD_SS_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_OS_VAL].Text);
                        data_list.AddString("PSD_LS_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_LS_VAL].Text);
                        data_list.AddString("PSD_FS_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_FS_VAL].Text);
                        data_list.AddString("HLT_TI_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.HLT_TI_VAL].Text);
                        data_list.AddString("CM_L_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CM_L_VAL].Text);
                        data_list.AddString("CM_A_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CM_A_VAL].Text);
                        data_list.AddString("CM_B_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CM_B_VAL].Text);
                        data_list.AddString("SURFACE_B_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SURFACE_B_VAL].Text);

                        data_list.AddString("IMAGE_NUM", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE_1].Text);
                        data_list.AddString("IMAGE_NUM2", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE_2].Text);
                        data_list.AddString("IMAGE_NUM3", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE_3].Text);


                        ichk++;
                    }
                    
                }

                if (ichk == 0)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(491));
                    return false;
                }




                //피벗 변형 형태 저장
                for (int i = 0; i < spdPivotList.ActiveSheet.RowCount; i++)
                {

                        data_list = in_node.AddNode("PIVOT_LIST");
                        data_list.AddInt("SORT_NO", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.SEQ].Value);
                        data_list.AddString("QC_NAME", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.ITEM].Text);
                        data_list.AddString("SPEC_VAL", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.SPEC_VAL].Text);

                       data_list.AddString("CUST_NO", MPCF.Trim(txtEndShipToName.Text));  //추가필요
                       data_list.AddString("REMARKS", MPCF.Trim(txtRemarks.Text));

                        data_list.AddString("LOT_01", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_01].Text);
                        data_list.AddString("LOT_02", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_02].Text);
                        data_list.AddString("LOT_03", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_03].Text);
                        data_list.AddString("LOT_04", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_04].Text);
                        data_list.AddString("LOT_05", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_05].Text);
                        data_list.AddString("LOT_06", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_06].Text);
                        data_list.AddString("LOT_07", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_07].Text);

                    data_list.AddString("IMAGE_NUM", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.IMAGE_1].Text);
                    data_list.AddString("IMAGE_NUM2", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.IMAGE_2].Text);
                    data_list.AddString("IMAGE_NUM3", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.IMAGE_3].Text);


                    data_list.AddChar("USE_YN", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.CHK].Value.ToString().ToUpper() == "TRUE" ? 'Y' : 'N');
   
                }

                //ASPECT RATIO  저장
                for (int i = 0; i < spdAspectList.ActiveSheet.RowCount; i++)
                {

                    data_list = in_node.AddNode("ASPECT_LIST");
                    data_list.AddInt("SORT_NO", spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.SORT_NO].Value);
                    data_list.AddString("QC_NAME", spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.QC_NAME].Text);
                    data_list.AddString("SPEC_VAL", spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.SPEC_VAL].Text);
                    data_list.AddString("VAL_01", spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_01].Text);
                    data_list.AddString("VAL_02", spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_02].Text);
                    data_list.AddString("VAL_03", spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_03].Text);
                    data_list.AddString("VAL_04", spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_04].Text);
                    data_list.AddString("VAL_05", spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_05].Text);
                    data_list.AddString("VAL_06", spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_06].Text);

                }


                //ICP RATIO  저장
                for (int i = 0; i < spdIcpList.ActiveSheet.RowCount; i++)
                {

                    data_list = in_node.AddNode("ASPECT_LIST");
                    data_list.AddInt("SORT_NO", MPCF.ToInt(spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.SORT_NO].Text));
                    data_list.AddString("QC_NAME", spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.QC_NAME].Text);
                    data_list.AddString("SPEC_VAL", spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.SPEC_VAL].Text);
                    data_list.AddString("VAL_01", spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_01].Text);
                    data_list.AddString("VAL_02", spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_02].Text);
                    data_list.AddString("VAL_03", spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_03].Text);
                    data_list.AddString("VAL_04", spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_04].Text);
                    data_list.AddString("VAL_05", spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_05].Text);
                    data_list.AddString("VAL_06", spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_06].Text);

                }


                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Generate_Report", in_node, ref out_node, false) == false)
                {
                    return false;
                }
                else
                {
                    MPCR.ShowSuccessMsg(out_node);
                }

                

                if (out_node.GetString("REPORT_NO") != "")
                {
                    cdvReportNo.Text = out_node.GetString("REPORT_NO");

                    fnviewReport_1(cdvReportNo.Text);
                    fnviewReport_2(cdvReportNo.Text);
                    fnviewReport_3(cdvReportNo.Text);
                    fnviewReport_4(cdvReportNo.Text);

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


            TRSNode in_node = new TRSNode("SAVE_REPORT_IN");
            TRSNode out_node = new TRSNode("SAVE_REPORT_OUT");
            TRSNode data_list;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '3'; // GRIT 성적서 저장

                in_node.AddString("REPORT_NO", cdvReportNo.Text);



                //1번 테이블 저장
                //기본 포장 lot정보 (스펙,  값)
                for (int i = 0; i < spdPackingLotList.ActiveSheet.RowCount; i++)
                {

                        data_list = in_node.AddNode("DATA_LIST");

                        data_list.AddString("HEADER_ID", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_ORDER_ID].Text);
                        data_list.AddString("LINE_NUMBER", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LINE].Text);
                        data_list.AddString("PACK_LOT_ID", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text);

                        data_list.AddString("GRADE", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.GRADE].Text);
                        data_list.AddString("SIZES", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SIZES].Text);

                        data_list.AddString("CUST_NO", MPCF.Trim(txtEndShipToName.Text));  //추가필요
                    data_list.AddString("REMARKS", MPCF.Trim(txtRemarks.Text));  //추가필요

                    data_list.AddString("TI_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.TI_SPEC].Text);
                        data_list.AddString("TTI_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.TTI_SPEC].Text);
                        data_list.AddString("WT_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.WT_SPEC].Text);
                        data_list.AddString("BD_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.BD_SPEC].Text);
                        data_list.AddString("PSD_TS_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_TS_SPEC].Text);
                        data_list.AddString("PSD_US_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_US_SPEC].Text);
                        data_list.AddString("PSD_OS_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_OS_SPEC].Text);
                                            data_list.AddString("PSD_SS_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_OS_SPEC].Text);
                        data_list.AddString("PSD_LS_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_LS_SPEC].Text);
                        data_list.AddString("PSD_FS_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_FS_SPEC].Text);
                        data_list.AddString("HLT_TI_SPEC", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.HLT_TI_SPEC].Text);

                        data_list.AddString("TI_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.TI_VAL].Text);
                        data_list.AddString("TTI_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.TTI_VAL].Text);
                        data_list.AddString("WT_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.WT_VAL].Text);
                        data_list.AddString("BD_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.BD_VAL].Text);
                        data_list.AddString("PSD_TS_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_TS_VAL].Text);
                        data_list.AddString("PSD_US_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_US_VAL].Text);
                        data_list.AddString("PSD_OS_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_OS_VAL].Text);
                        data_list.AddString("PSD_LS_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_LS_VAL].Text);
                        data_list.AddString("PSD_FS_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_FS_VAL].Text);
                        data_list.AddString("HLT_TI_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.HLT_TI_VAL].Text);
                        data_list.AddString("CM_L_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CM_L_VAL].Text);
                        data_list.AddString("CM_A_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CM_A_VAL].Text);
                        data_list.AddString("CM_B_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CM_B_VAL].Text);
                        data_list.AddString("SURFACE_B_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SURFACE_B_VAL].Text);

                        data_list.AddString("IMAGE_NUM", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE_1].Text);
                        data_list.AddString("IMAGE_NUM2", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE_2].Text);
                        data_list.AddString("IMAGE_NUM3", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE_3].Text);


                }


                //피벗 변형 형태 저장
                for (int i = 0; i < spdPivotList.ActiveSheet.RowCount; i++)
                {

                        data_list = in_node.AddNode("PIVOT_LIST");
                        data_list.AddInt("SORT_NO", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.SEQ].Value);
                        data_list.AddString("QC_NAME", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.ITEM].Text);
                        data_list.AddString("SPEC_VAL", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.SPEC_VAL].Text);

                        data_list.AddString("REMARKS", MPCF.Trim(txtRemarks.Text));
                    data_list.AddString("CUST_NO", MPCF.Trim(txtEndShipToName.Text));  //추가필요

                    data_list.AddString("LOT_01", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_01].Text);
                        data_list.AddString("LOT_02", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_02].Text);
                        data_list.AddString("LOT_03", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_03].Text);
                        data_list.AddString("LOT_04", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_04].Text);
                        data_list.AddString("LOT_05", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_05].Text);
                        data_list.AddString("LOT_06", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_06].Text);
                        data_list.AddString("LOT_07", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.LOT_07].Text);

                       data_list.AddString("IMAGE_NUM", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.IMAGE_1].Text);
                       data_list.AddString("IMAGE_NUM2", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.IMAGE_2].Text);
                       data_list.AddString("IMAGE_NUM3", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.IMAGE_3].Text);

                    data_list.AddChar("USE_YN", spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.CHK].Value.ToString().ToUpper() == "TRUE" ? 'Y' : 'N');

                }

                //ASPECT RATIO  저장
                for (int i = 0; i < spdAspectList.ActiveSheet.RowCount; i++)
                {

                    data_list = in_node.AddNode("ASPECT_LIST");
                    data_list.AddInt("SORT_NO", spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.SORT_NO].Value);
                    data_list.AddString("QC_NAME", spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.QC_NAME].Text);
                    data_list.AddString("SPEC_VAL", spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.SPEC_VAL].Text);
                    data_list.AddString("VAL_01", spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_01].Text);
                    data_list.AddString("VAL_02", spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_02].Text);
                    data_list.AddString("VAL_03", spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_03].Text);
                    data_list.AddString("VAL_04", spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_04].Text);
                    data_list.AddString("VAL_05", spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_05].Text);
                    data_list.AddString("VAL_06", spdAspectList.ActiveSheet.Cells[i, (int)ASPECT_LIST.VAL_06].Text);

                }



                //ICP  저장
                for (int i = 0; i < spdIcpList.ActiveSheet.RowCount; i++)
                {

                    data_list = in_node.AddNode("ASPECT_LIST");
                    data_list.AddInt("SORT_NO", MPCF.ToInt(spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.SORT_NO].Text));
                    data_list.AddString("QC_NAME", spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.QC_NAME].Text);
                    data_list.AddString("SPEC_VAL", spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.SPEC_VAL].Text);
                    data_list.AddString("VAL_01", spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_01].Text);
                    data_list.AddString("VAL_02", spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_02].Text);
                    data_list.AddString("VAL_03", spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_03].Text);
                    data_list.AddString("VAL_04", spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_04].Text);
                    data_list.AddString("VAL_05", spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_05].Text);
                    data_list.AddString("VAL_06", spdIcpList.ActiveSheet.Cells[i, (int)ICP_LIST.VAL_06].Text);

                }



                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Save_Report", in_node, ref out_node, false) == false)
                {
                    return false;
                }
                else
                {
                    MPCR.ShowSuccessMsg(out_node);
                }


                fnviewReport_1(cdvReportNo.Text);
                fnviewReport_2(cdvReportNo.Text);
                fnviewReport_3(cdvReportNo.Text);
                fnviewReport_4(cdvReportNo.Text);


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

            TRSNode in_node = new TRSNode("USER_IN");
            TRSNode out_node = new TRSNode("USER_OUT");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1'; // CTM 성적서 저장

                in_node.AddString("USER_ID", MPGV.gsUserID);


                if (MPCR.CallService("SEC", "SEC_View_User", in_node, ref out_node, false) == false)
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
        private void fnPrintShipReport(string sViewID, string sFileName,string ReportType)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
               // int i = 0;

                dvcArgu[0].sCondition_ID = "REPORT_NO";
                dvcArgu[0].sCondition_Value = cdvReportNo.Text;

                dvcArgu[1].sCondition_ID = "PRINT_USER";
                dvcArgu[1].sCondition_Value = txtPrintUser.Text;

                dvcArgu[2].sCondition_ID = "INSP_RESULT";
                dvcArgu[2].sCondition_Value = txtJudgeResult.Text;


                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                //일반성적서 pip510p

                if(ReportType == "DEV")
                {
                    DevReport.PreviewXtraReport(dt, sFileName);
                }
                else
                {
                    EXTFUC.PreviewExcelReport(dt, sFileName);
                }



                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        public static Image ByteArrayToImage(byte[] b)
        {
            TypeConverter tc = TypeDescriptor.GetConverter(typeof(Bitmap));
            ImageConverter imgcvt = new ImageConverter();




            Image img = (Image)imgcvt.ConvertFrom(b);
            return img;
        }
        private void fnRegistrationFile(FileInfo _fileInfo, int grid_1_image_seq, int grid_2_image_seq)
        {
            //DB 저장
            TRSNode in_node = new TRSNode("Update_File_In");
            TRSNode out_node = new TRSNode("Update_File_Out");

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            string s_File_no = "";

            BinaryReader br;
            byte[] file_buffer;
            if (_fileInfo.Exists == true)
            {
                br = new BinaryReader(_fileInfo.OpenRead());
                file_buffer = br.ReadBytes((int)_fileInfo.Length);
                in_node.AddBlob(MPGC.MP_BIN_DATA_1, file_buffer);
                in_node.AddInt("IMAGE_SIZE", _fileInfo.Length);
                br.Close();
            }

            if (MPCR.CallService("CUS_QCM", "CUS_QCM_File_Attach", in_node, ref out_node) == false)
            {
                return;
            }

            s_File_no = out_node.GetString("FILE_NO");


            for (int i = 0; i < spdPackingLotList.ActiveSheet.RowCount; i++)
            {
                spdPackingLotList.ActiveSheet.Cells[i, grid_1_image_seq].Value = s_File_no;
            }

            for (int i = 0; i < spdPivotList.ActiveSheet.RowCount; i++)
            {
                spdPivotList.ActiveSheet.Cells[i, grid_2_image_seq].Value = s_File_no;
            }



            // spdPackingLotList.ActiveSheet.Cells[_Row, image_seq].Value = s_File_no;  //신규채번 FileNo 업데이트


        }
        private void SpecSearch(int iRow, int iCol)
        {

            if (iRow < 0)
            {
                return;
            }

            if ((int)PIVOT_LIST.LOT_01 > iCol || (int)PIVOT_LIST.LOT_07 < iCol)
            {
                return;
            }

            //  int iRow = e.Row;
            //    int iCol = e.Column;

            string dinputValue = "";
            string sLowwerValue = "";
            string sUpperValue = "";




            for (int i = 0; i < spdPackingLotList.ActiveSheet.RowCount; i++)
            {
                if (spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text == spdPivotList.ActiveSheet.Cells[2, iCol].Text)
                {

                    if (MPCF.CheckNumeric(spdPivotList.ActiveSheet.Cells[iRow, iCol].Text) == true)
                    {
                        dinputValue = spdPivotList.ActiveSheet.Cells[iRow, iCol].Text;

                        switch (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.ITEM].Text)
                        {
                            case "TI":
                                sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.TI_LOWWER].Text;
                                sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.TI_UPPER].Text;
                                break;
                            case "TTI":
                                sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.TTI_LOWWER].Text;
                                sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.TTI_UPPER].Text;
                                break;
                            case "HLT - TI":
                                sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.HLT_TI_LOWWER].Text;
                                sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.HLT_TI_UPPER].Text;
                                break;
                            case "Coating wt%":
                                sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.WT_LOWWER].Text;
                                sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.WT_UPPER].Text;
                                break;
                            case "Bulk Density":
                                sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.BD_LOWWER].Text;
                                sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.BD_UPPER].Text;
                                break;
                            case "L":
                                sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CM_L_LOWWER].Text;
                                sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CM_L_UPPER].Text;
                                break;
                            case "a":
                                sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CM_A_LOWWER].Text;
                                sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CM_A_UPPER].Text;
                                break;
                            case "b":
                                sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CM_B_LOWWER].Text;
                                sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CM_B_UPPER].Text;
                                break;
                            case "++":
                                sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_TS_LOWWER].Text;
                                sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_TS_UPPER].Text;
                                break;
                            case "+":
                                sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_US_LOWWER].Text;
                                sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_US_UPPER].Text;
                                break;
                            case "OS":
                                sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_OS_LOWWER].Text;
                                sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_OS_UPPER].Text;
                                break;
                            case "-":
                                sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_LS_LOWWER].Text;
                                sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_LS_UPPER].Text;
                                break;
                            case "PAN":
                                sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_FS_LOWWER].Text;
                                sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_FS_UPPER].Text;
                                break;
                            case "Boron":
                                sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SURFACE_B_LOWWER].Text;
                                sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SURFACE_B_UPPER].Text;
                                break;


                        }


                        if (MPCF.CheckNumeric(dinputValue) == true)
                        {
                            if (MPCF.CheckNumeric(sLowwerValue) == true || MPCF.CheckNumeric(sUpperValue) == true)
                            {
                                if (SpecCheck(MPCF.ToDbl(dinputValue), sLowwerValue, sUpperValue) == false)
                                {
                                    spdPivotList.ActiveSheet.Cells[iRow, iCol].BackColor = Color.Red;
                                }
                                else
                                {
                                    spdPivotList.ActiveSheet.Cells[iRow, iCol].BackColor = Color.White;
                                }
                            }
                        }





                    }



                }

            }









        }
        private bool SpecCheck(double dinputValue, string dLowwerValue, string dUpperValue)
        {


            //입력값(검사 결과값)이 숫자일 때
            if (MPCF.CheckNumeric(dinputValue) == true)
            {
                if (MPCF.CheckNumeric(MPCF.ToDbl(dLowwerValue)) == true)
                {
                    if (dinputValue < MPCF.ToDbl(dLowwerValue))
                    {
                        return false;
                    }
                }

                if (MPCF.CheckNumeric(dUpperValue) == true)
                {
                    if (dinputValue > MPCF.ToDbl(dUpperValue))
                    {
                        return false;
                    }
                }


            }


            return true;
        }
        private void PivotCalc()
        {

            string s_spec_ti;
            string s_spec_tti;
            string s_spec_hlt_ti;
            string s_spec_wt;
            string s_spec_bd;
            string s_spec_psd_ts;
            string s_spec_psd_us;
            string s_spec_psd_os;
            string s_spec_psd_ss;
            string s_spec_psd_ls;
            string s_spec_psd_fs;


            //INSP_PRT_PIVOT 정의
            string seq_1;  //Grade
            string seq_2;  //Size
            string seq_3;  //Lot No
            string seq_4;  //TI
            string seq_5;  //TTI
            string seq_6;  //HLT-TI
            string seq_7;  //Coating wt%
            string seq_8;  //Bulk Density
            string seq_9;  //L
            string seq_10;  //a
            string seq_11;  //b
            string seq_12;  // ++
            string seq_13;  // +
            string seq_14;  //OS
            string seq_15;  // -
            string seq_16;  // PAN
            string seq_17;  //Boron
            string seq_18; //18

            int i_spec_cols = LOT_COL_START - 1;
            int i_start_cols = LOT_COL_START;
            int i_end_cols = LOT_COL_END;

            int i_chk = 0;


            try
            {
                //Clear Spread
                for (int i_row = 0; i_row < spdPivotList.ActiveSheet.RowCount; i_row++)
                {
                    for (int i_col = i_spec_cols; i_col < i_end_cols; i_col++)
                    {
                        spdPivotList.ActiveSheet.Cells[i_row, i_col].Value = " ";
                    }
                }




                for (int i = 0; i < spdPackingLotList.ActiveSheet.RowCount; i++)
                {
                    //선택한 행
                    if (spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (i_chk == 0)
                        {
                            //선택한 한 행중에 첫 행
                            s_spec_ti = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.TI_SPEC].Value.ToString();             //4
                            s_spec_tti = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.TTI_SPEC].Value.ToString();          //5
                            s_spec_hlt_ti = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.HLT_TI_SPEC].Value.ToString();  //6
                            s_spec_wt = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.WT_SPEC].Value.ToString();       //7
                            s_spec_bd = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.BD_SPEC].Value.ToString();          //8
                            s_spec_psd_ts = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_TS_SPEC].Value.ToString();  //12
                            s_spec_psd_us = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_US_SPEC].Value.ToString();  //13
                            s_spec_psd_os = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_OS_SPEC].Value.ToString();  //14
                            s_spec_psd_ls = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_LS_SPEC].Value.ToString();   //15
                            s_spec_psd_fs = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_FS_SPEC].Value.ToString();   //16
                            s_spec_psd_ss = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_SS_SPEC].Value.ToString(); //18

                            for (int iRow = 0; iRow < spdPivotList.ActiveSheet.RowCount; iRow++)
                            {
                                if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "4") //TI
                                {
                                    spdPivotList.ActiveSheet.Cells[iRow, i_spec_cols].Value = s_spec_ti;
                                }
                                else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "5")
                                {
                                    spdPivotList.ActiveSheet.Cells[iRow, i_spec_cols].Value = s_spec_tti;
                                }
                                else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "6")
                                {
                                    spdPivotList.ActiveSheet.Cells[iRow, i_spec_cols].Value = s_spec_hlt_ti;
                                }
                                else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "7")  //wt
                                {
                                    spdPivotList.ActiveSheet.Cells[iRow, i_spec_cols].Value = s_spec_wt;
                                }
                                else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "8")  // bd
                                {
                                    spdPivotList.ActiveSheet.Cells[iRow, i_spec_cols].Value = s_spec_wt;
                                }
                                else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "12")  // ++
                                {
                                    spdPivotList.ActiveSheet.Cells[iRow, i_spec_cols].Value = s_spec_psd_ts;
                                }
                                else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "13")  // +
                                {
                                    spdPivotList.ActiveSheet.Cells[iRow, i_spec_cols].Value = s_spec_psd_us;
                                }
                                else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "14")  // OS
                                {
                                    spdPivotList.ActiveSheet.Cells[iRow, i_spec_cols].Value = s_spec_psd_os;
                                }
                                else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "15")  // -
                                {
                                    spdPivotList.ActiveSheet.Cells[iRow, i_spec_cols].Value = s_spec_psd_ls;
                                }
                                else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "16")  //PAN
                                {
                                    spdPivotList.ActiveSheet.Cells[iRow, i_spec_cols].Value = s_spec_psd_fs;
                                }
                                else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "18")  //PAN
                                {
                                    spdPivotList.ActiveSheet.Cells[iRow, i_spec_cols].Value = s_spec_psd_ss;
                                }
                            }

                        }

                        seq_1 = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.GRADE].Value.ToString();
                        seq_2 = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SIZES].Value.ToString();
                        seq_3 = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Value.ToString();
                        seq_4 = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.TI_VAL].Value.ToString();
                        seq_5 = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.TTI_VAL].Value.ToString();
                        seq_6 = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.HLT_TI_VAL].Value.ToString();
                        seq_7 = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.WT_VAL].Value.ToString();
                        seq_8 = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.BD_VAL].Value.ToString();
                        seq_9 = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CM_L_VAL].Value.ToString();
                        seq_10 = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CM_A_VAL].Value.ToString();
                        seq_11 = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CM_B_VAL].Value.ToString();
                        seq_12 = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_TS_VAL].Value.ToString();
                        seq_13 = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_US_VAL].Value.ToString();
                        seq_14 = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_OS_VAL].Value.ToString();
                        seq_15 = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_LS_VAL].Value.ToString();
                        seq_16 = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_FS_VAL].Value.ToString();
                        seq_17 = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SURFACE_B_VAL].Value.ToString();
                        seq_18 = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PSD_SS_VAL].Value.ToString();


                        for (int iRow = 0; iRow < spdPivotList.ActiveSheet.RowCount; iRow++)
                        {
                            if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "1")
                            {
                                spdPivotList.ActiveSheet.Cells[iRow, i_start_cols].Value = seq_1;
                            }
                            else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "2")
                            {
                                spdPivotList.ActiveSheet.Cells[iRow, i_start_cols].Value = seq_2;
                            }
                            else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "3")
                            {
                                spdPivotList.ActiveSheet.Cells[iRow, i_start_cols].Value = seq_3;
                            }
                            else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "4")
                            {
                                spdPivotList.ActiveSheet.Cells[iRow, i_start_cols].Value = seq_4;

                            }
                            else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "5")
                            {
                                spdPivotList.ActiveSheet.Cells[iRow, i_start_cols].Value = seq_5;
                            }
                            else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "6")
                            {
                                spdPivotList.ActiveSheet.Cells[iRow, i_start_cols].Value = seq_6;
                            }
                            else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "7")
                            {
                                spdPivotList.ActiveSheet.Cells[iRow, i_start_cols].Value = seq_7;
                            }
                            else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "8")
                            {
                                spdPivotList.ActiveSheet.Cells[iRow, i_start_cols].Value = seq_8;
                            }
                            else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "9")
                            {
                                spdPivotList.ActiveSheet.Cells[iRow, i_start_cols].Value = seq_9;
                            }
                            else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "10")
                            {
                                spdPivotList.ActiveSheet.Cells[iRow, i_start_cols].Value = seq_10;
                            }
                            else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "11")
                            {
                                spdPivotList.ActiveSheet.Cells[iRow, i_start_cols].Value = seq_11;
                            }
                            else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "12")
                            {
                                spdPivotList.ActiveSheet.Cells[iRow, i_start_cols].Value = seq_12;
                            }
                            else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "13")
                            {
                                spdPivotList.ActiveSheet.Cells[iRow, i_start_cols].Value = seq_13;
                            }
                            else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "14")
                            {
                                spdPivotList.ActiveSheet.Cells[iRow, i_start_cols].Value = seq_14;
                            }
                            else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "15")
                            {
                                spdPivotList.ActiveSheet.Cells[iRow, i_start_cols].Value = seq_15;
                            }
                            else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "16")
                            {
                                spdPivotList.ActiveSheet.Cells[iRow, i_start_cols].Value = seq_16;
                            }
                            else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "17")
                            {
                                spdPivotList.ActiveSheet.Cells[iRow, i_start_cols].Value = seq_17;
                            }

                            else if (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString() == "18")
                            {
                                spdPivotList.ActiveSheet.Cells[iRow, i_start_cols].Value = seq_18;
                            }


                            if (MPCF.ToDbl(spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.SEQ].Value.ToString()) > 3)
                            {
                                SpecSearch(iRow, i_start_cols);
                            }

                        }
                        i_start_cols++;
                        i_chk++;
                    }

                }



                fnviewReport_OP_ICP(spdPackingLotList.ActiveSheet.Cells[spdPackingLotList.ActiveSheet.ActiveRowIndex, (int)PACK_LOT.ORG_LOT_ID].Value.ToString());
                fnviewReport_OP_ASPECT(spdPackingLotList.ActiveSheet.Cells[spdPackingLotList.ActiveSheet.ActiveRowIndex, (int)PACK_LOT.ORG_LOT_ID].Value.ToString());

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

        }
        private void ViewImageFile(string _image1, string _image2, string _image3)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "IMAGE_1";
                dvcArgu[1].sCondition_Value = _image1;

                dvcArgu[2].sCondition_ID = "IMAGE_2";
                dvcArgu[2].sCondition_Value = _image2;

                dvcArgu[3].sCondition_ID = "IMAGE_3";
                dvcArgu[3].sCondition_Value = _image3;



                if (TPDR.GetDataOne("", ref dt, "CQCM2102-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

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

                    if (dt.Rows[i]["FILE_NO"].ToString() == _image3)
                    {
                        pictureBox3.Image = ByteArrayToImage((byte[])dt.Rows[i]["IMAGE_DATA"]);
                    }

                }


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void btnGenerateReport_Click(object sender, EventArgs e)
        {
            //CUS_QCM_Generate_Report
            if (!fnGenerateReport())
            {
                return;
            }

            // 성적서 재조회
           // fnviewReport_1(cdvReportNo.Text);
           // fnviewReport_2(cdvReportNo.Text);
           // fnviewReport_3(cdvReportNo.Text);

        }
        private void btnView_Click(object sender, EventArgs e)
        {

        }
        private void cdvPackOrderNo_ButtonPress(object sender, EventArgs e)
        {
            try
            {

                frmPopPackingOrderList popup = new frmPopPackingOrderList();
                popup.StartPosition = FormStartPosition.CenterParent;


                if (popup.ShowDialog() == DialogResult.OK)
                {
                    if (popup.s_pack_order_id != "")
                    {
                        cdvPackOrderNo.Text = popup.s_pack_order_id;
                        txtLineNo.Text = popup.s_pack_line_no;
                        txtCustomerDesc.Text = popup.s_customer_desc;
                        txtEndShipToName.Text = popup.s_delivery_name;
                        //txtMatID.Text = popup.s_mat_id;
                        txtMatDesc.Text = popup.s_mat_desc;
                        txtGrade.Text = popup.s_grade;
                        txtType.Text = popup.s_types;

                        cdvReportNo.Text = "";
                        txtRemarks.Text = "";

                        if (MPCF.Trim(cdvPackOrderNo.Text) != "")
                        {
                            //기본 스펙, 값 정보
                            ViewPackingLotList(cdvPackOrderNo.Text, txtLineNo.Text);

                            //피벗 틀 정보
                            ViewPivotList(cdvReportNo.Text, popup.s_mat_id);

                            //Aspect 정보
                            ViewAspectList(cdvReportNo.Text);

                            //ICP 정보
                            ViewIcptList(cdvReportNo.Text);
                        }


                        pictureBox1.Image = null;
                        pictureBox2.Image = null;
                        pictureBox3.Image = null;

                        //DataTable dt = new DataTable();
                        // dt.Columns.Add("dfdf", typeof(byte[]));

                    }

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
        private void btnPrint_Click(object sender, EventArgs e)
        {
            //성적서 바인딩확인
            if (CheckCondition("PRINT") == false)
            {
                return;
            }

            if (cdvShipReportType.Text == "GRT_01") //SPEC 성적서  (O)
            {
                fnPrintShipReport("CQCM2102-010", "pip501p","DEV");
            }
            else if (cdvShipReportType.Text == "GRT_02") //일반 성적서  (O)
            {
                fnPrintShipReport("CQCM2102-010", "pip502p", "DEV");
            }
            else if (cdvShipReportType.Text == "GRT_03") //HLT-TI성적서 (O)
            {
                fnPrintShipReport("CQCM2102-010", "pip503p", "DEV");
            }
            else if (cdvShipReportType.Text == "GRT_04") // IMAGE 성적서
            {
                fnPrintShipReport("CQCM2102-011", "pip504p", "DEV");
            }
            else if (cdvShipReportType.Text == "GRT_05") // IMAGE성적서 (SPEC포함)
            {
                fnPrintShipReport("CQCM2102-011", "pip509p", "DEV");
            }
            else if (cdvShipReportType.Text == "GRT_06") //IMAGE성적서 (TTI 무)
            {
                fnPrintShipReport("CQCM2102-011", "pip508p", "DEV");
            }
            else if (cdvShipReportType.Text == "GRT_07") // SPEC성적서 (형상)
            {
                fnPrintShipReport("CQCM2102-012", "pip505p", "DEV");
            }
            else if (cdvShipReportType.Text == "GRT_08") // Asahi C50 성적서 (O)
            {
                fnPrintShipReport("CQCM2102-010", "pip506p", "DEV");
            }
            else if (cdvShipReportType.Text == "GRT_09") // 신한 성적서
            {
                fnPrintShipReport("CQCM2102-015", "GRT_SAL_QC_REPORT_01", "EXL");
            }
        }
        private void btnProcess_Click(object sender, EventArgs e)
        {
            if (CheckCondition("SAVE") == false)
                return;

            if (!fnSaveReport())
                return;



        }
        private void cdvReportNo_ButtonPress(object sender, EventArgs e)
        {
            try
            {

                frmPopShipReportList popup = new frmPopShipReportList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.s_area_id = cdvDept.Text;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    if (popup.s_report_no != "")
                    {
                        cdvReportNo.Text = popup.s_report_no;

                        if (MPCF.Trim(cdvReportNo.Text) != "")
                        {
                            //Clear
                            cdvPackOrderNo.Text = "";
                            txtLineNo.Text = "";
                            txtMatDesc.Text = "";
                            txtCustomerDesc.Text = "";

                            // 성적서 조회
                            fnviewReport_1(cdvReportNo.Text);
                            fnviewReport_2(cdvReportNo.Text);
                            fnviewReport_3(cdvReportNo.Text);
                            fnviewReport_4(cdvReportNo.Text);
                        }

                    }

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
        private void cdvReportNo_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {

        }
        private void frmTranShipReportRegistration_GRIT_Load(object sender, EventArgs e)
        {
            fnGetUserDesc();
            txtJudgeResult.Text = "ACCEPTED";
        }
        private void ultraButton1_Click(object sender, EventArgs e)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
                DataTable dt = null;
                string sSql = "";
                // int ichk = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;


                if (TPDR.GetDataOne("", ref dt, "CQCM9999-999", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                pictureBox3.Image = ByteArrayToImage((byte[])dt.Rows[0]["IMG"]);



                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnImage1_Click_1(object sender, EventArgs e)
        {
            string fullPath = "";
            FileInfo finfo;

            if (!CheckCondition("FILE_UPLOAD"))
            {
                return;
            }

            //Focused Row
            int iActiveRow = spdPackingLotList.ActiveSheet.ActiveRowIndex;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {

                fullPath = openFileDialog1.FileName;
                pictureBox1.Image = Image.FromFile(openFileDialog1.FileName);

                finfo = new FileInfo(fullPath);

                fnRegistrationFile(finfo,(int)PACK_LOT.IMAGE_1,(int)PIVOT_LIST.IMAGE_1);


            }

            









        }
        private void btnImage2_Click(object sender, EventArgs e)
        {
            string fullPath = "";
            FileInfo finfo;

            if (!CheckCondition("FILE_UPLOAD"))
            {
                return;
            }

            //Focused Row
            int iActiveRow = spdPackingLotList.ActiveSheet.ActiveRowIndex;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {

                fullPath = openFileDialog1.FileName;
                pictureBox2.Image = Image.FromFile(openFileDialog1.FileName);

                finfo = new FileInfo(fullPath);

                fnRegistrationFile(finfo, (int)PACK_LOT.IMAGE_2,(int)PIVOT_LIST.IMAGE_2);


            }
        }
        private void btnImage3_Click(object sender, EventArgs e)
        {
            string fullPath = "";
            FileInfo finfo;

            if (!CheckCondition("FILE_UPLOAD"))
            {
                return;
            }

            //Focused Row
            int iActiveRow = spdPackingLotList.ActiveSheet.ActiveRowIndex;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {

                fullPath = openFileDialog1.FileName;
                pictureBox3.Image = Image.FromFile(openFileDialog1.FileName);

                finfo = new FileInfo(fullPath);

                fnRegistrationFile(finfo, (int)PACK_LOT.IMAGE_3, (int)PIVOT_LIST.IMAGE_3);


            }
        }
        private void spdPackingLotList_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            /*
            if (spdPackingLotList.ActiveSheet.ActiveRowIndex < 0)
                return;

            int iRow = spdPackingLotList.ActiveSheet.ActiveRowIndex;


            pictureBox1.Image = null;
            pictureBox2.Image = null;
            pictureBox3.Image = null;

            string s_image_1 = MPCF.Trim(spdPackingLotList.ActiveSheet.Cells[iRow, (int)PACK_LOT.IMAGE_1].Value.ToString());
            string s_image_2 = MPCF.Trim(spdPackingLotList.ActiveSheet.Cells[iRow, (int)PACK_LOT.IMAGE_2].Value.ToString());
            string s_image_3 = MPCF.Trim(spdPackingLotList.ActiveSheet.Cells[iRow, (int)PACK_LOT.IMAGE_3].Value.ToString());


            ViewImageFile(s_image_1, s_image_2, s_image_3);
            */
            
        }
        private void btnApply_Click(object sender, EventArgs e)
        {
            PivotCalc();
        }
        private void pnlStsCond3_Paint(object sender, PaintEventArgs e)
        {

        }
        private void btnGCM3_Click(object sender, EventArgs e)
        {
            try
            {

                frmPopGcmData popup = new frmPopGcmData();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sTable_name = "C_INSP_GRIT_SLEVE";

                popup.sTable_name_desc = "Sleve Size";
                popup.sComment = "성적서에 표기될 Sleve Size 정보 등록";




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
        private void spdIcpList_CellClick(object sender, CellClickEventArgs e)
        {

        }
        private void tableLayoutPanel4_Paint(object sender, PaintEventArgs e)
        {

        }
        private void spdPivotList_Change(object sender, ChangeEventArgs e)
        {

            int iRow = e.Row;
            int iCol = e.Column;

            SpecSearch(iRow, iCol);
        }
        private void btnCustomerSpec_Click(object sender, EventArgs e)
        {
            try
            {
                if(spdPackingLotList.ActiveSheet.RowCount == 0)
                {
                    return;
                }

                frmTranShipReportSpecRegistrationByMat popup = new frmTranShipReportSpecRegistrationByMat();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.s_pop_arda_id = cdvDept.Text;
                popup.s_pop_insp_type = "OQC";
                popup.s_pop_insp_type_desc = "제품검사";
                popup.s_pop_mat_id = spdPackingLotList_Sheet1.Cells[0, (int)PACK_LOT.MAT_ID].Text;


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

        #endregion
    }
}
