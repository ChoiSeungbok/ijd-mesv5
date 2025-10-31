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
//using Microsoft.Office.Interop.Excel;
//using Microsoft.Office.Interop.Excel;

namespace CUS_QCM
{
    public partial class frmTranShipReportRegistration_GRT_MP : frmTranForm05
    {
        public frmTranShipReportRegistration_GRT_MP()
        {
            InitializeComponent();

            InitControl();
        }

        private enum PACK_LOT
        {
            CHK,                     // 1 : CHECK
            PACK_ORDER_ID,
            LINE,
            PACK_LOT_ID,             // 2 : 검사 LOT ID ( 실제 검사에서 스캔된 랏을 의미)
            MAT_ID,
            MAT_DESC,
            GRADE,
            SIZES,
            WT,
            MEAN,
            SD,
            LP,
            ELEC_CONDUCTIVITY,
            VOL_STATIC01,
            VOL_STATIC02,
            VOL_STATIC03,
            VOL_STATIC04,
            VOL_STATIC05,
            VOL_STATIC06,
            VOL_STATIC07,
            VOL_STATIC08,
            VOL_STATIC09,

            IMAGE01,            //MP검사에서 등록한 이미지
            IMAGE02,
            IMAGE03,
            IMAGE04,
            IMAGE05,
            SUB_IMAGE01,    //SEM 이미지 (성적서에서 등록 할 이미지)
            SUB_IMAGE02,
            SUB_IMAGE03,
            SUB_IMAGE04,
            SUB_IMAGE05,
            SUB_IMAGE06,

            SHIP_NAME,
            REMARKS,
            ANALYZER,   //Default ' '   화면 입력값
            ANALYZER_DESC,

            WT_CHK,   //각 항목들 체크 값  ( -1 : 체크   0 : 미체크 )
            MEAN_CHK,
            SD_CHK,
            LP_CHK,
            ELEC_CONDUCTIVITY_CHK,
            VOL_STATIC01_CHK,
            VOL_STATIC02_CHK,
            VOL_STATIC03_CHK,
            VOL_STATIC04_CHK,
            VOL_STATIC05_CHK,
            VOL_STATIC06_CHK,
            VOL_STATIC07_CHK,
            VOL_STATIC08_CHK,
            VOL_STATIC09_CHK,

            IMAGE01_CHK,   //DEFAULT : -1    ( 5개 기본 이미지 체크여부   -1 => 체크 ,  0 => 미체크)  
            IMAGE02_CHK,   //DEFAULT : -1
            IMAGE03_CHK,   //DEFAULT : -1
            IMAGE04_CHK,   //DEFAULT : 0
            IMAGE05_CHK,   // DEFAULT : 0

            SPEC_VENDOR,  //  스펙 적용된 벤더 이름

            VOL_STATIC05_SPEC_MIN,
            VOL_STATIC05_SPEC_MAX,
            VOL_STATIC02_SPEC_MIN,
            VOL_STATIC02_SPEC_MAX,
            VOL_STATIC08_SPEC_MIN,
            VOL_STATIC08_SPEC_MAX,
            LP_SPEC_MIN,
            LP_SPEC_MAX,
            VOL_STATIC03_SPEC_MIN,
            VOL_STATIC03_SPEC_MAX,
            VOL_STATIC07_SPEC_MIN,
            VOL_STATIC07_SPEC_MAX,



            WT_SPEC_MIN,
            WT_SPEC_MAX,
            MEAN_SPEC_MIN,
            MEAN_SPEC_MAX,
            SD_SPEC_MIN,
            SD_SPEC_MAX



        }

        private enum PIVOT_LIST
        {
            CHK,
            ITEM_CODE,
            NAME,
            VALUE,
            IMAGE_01,
            IMAGE_02,
            IMAGE_03,
            LOWER,
            UPPER

        }

        //Pivot Grid
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

                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Left;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void initCombobox()
        {
            if (MPCF.Trim(cdvDept.Text) == "")
            {
                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                cdvDept.Focus();
                return;
            }

            try
            {
                cdvShipReportType.Init();
                MPCF.InitListView(cdvShipReportType.GetListView);
                cdvShipReportType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvShipReportType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvShipReportType.Columns.Add("Desc2", 100, HorizontalAlignment.Left);
                cdvShipReportType.SelectedSubItemIndex = 0;
                cdvShipReportType.DisplaySubItemIndex = 1;

                string[] key1 = new string[1];
                key1[0] = cdvDept.Text;
                if (BASLIST.ViewGCMDataList(cdvShipReportType.GetListView, '1', CSGC.CP_GCM_INSP_SHIP_REPORT, -1, null, "", true, -1, -1, null, key1) == false)
                {
                    return;
                }

                cdvShipReportType.InsertEmptyRow(0, 1);
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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "PACK_ORDER_ID";
                dvcArgu[1].sCondition_Value = packOrderId;

                dvcArgu[2].sCondition_ID = "PACK_LINE_NO";
                dvcArgu[2].sCondition_Value = packLineNo;


                if (TPDR.GetDataOne("", ref dt, "CQCM2103-001", dvcArgu, false, false, ref sSql) == false)
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
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.GRADE].Value = dt.Rows[i]["GRADE"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SIZES].Value = dt.Rows[i]["SIZES"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.WT].Value = dt.Rows[i]["WT"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.MEAN].Value = dt.Rows[i]["MEAN"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SD].Value = dt.Rows[i]["SD"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.LP].Value = dt.Rows[i]["LP"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ELEC_CONDUCTIVITY].Value = dt.Rows[i]["ELEC_CONDUCTIVITY"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC01].Value = dt.Rows[i]["VOL_STATIC01"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC02].Value = dt.Rows[i]["VOL_STATIC02"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC03].Value = dt.Rows[i]["VOL_STATIC03"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC04].Value = dt.Rows[i]["VOL_STATIC04"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC05].Value = dt.Rows[i]["VOL_STATIC05"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC06].Value = dt.Rows[i]["VOL_STATIC06"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC07].Value = dt.Rows[i]["VOL_STATIC07"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC08].Value = dt.Rows[i]["VOL_STATIC08"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC09].Value = dt.Rows[i]["VOL_STATIC09"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE01].Value = dt.Rows[i]["IMAGE01"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE02].Value = dt.Rows[i]["IMAGE02"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE03].Value = dt.Rows[i]["IMAGE03"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE04].Value = dt.Rows[i]["IMAGE04"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE05].Value = dt.Rows[i]["IMAGE05"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SUB_IMAGE01].Value = dt.Rows[i]["SUB_IMAGE01"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SUB_IMAGE02].Value = dt.Rows[i]["SUB_IMAGE02"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SUB_IMAGE03].Value = dt.Rows[i]["SUB_IMAGE03"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SUB_IMAGE04].Value = dt.Rows[i]["SUB_IMAGE04"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SUB_IMAGE05].Value = dt.Rows[i]["SUB_IMAGE05"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SUB_IMAGE06].Value = dt.Rows[i]["SUB_IMAGE06"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_NAME].Value = dt.Rows[i]["SHIP_NAME"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.REMARKS].Value = dt.Rows[i]["REMARKS"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ANALYZER].Value = dt.Rows[i]["ANALYZER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ANALYZER_DESC].Value = dt.Rows[i]["ANALYZER_DESC"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.WT_CHK].Value = dt.Rows[i]["WT_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.MEAN_CHK].Value = dt.Rows[i]["MEAN_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SD_CHK].Value = dt.Rows[i]["SD_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.LP_CHK].Value = dt.Rows[i]["LP_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ELEC_CONDUCTIVITY_CHK].Value = dt.Rows[i]["ELEC_CONDUCTIVITY_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC01_CHK].Value = dt.Rows[i]["VOL_STATIC01_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC02_CHK].Value = dt.Rows[i]["VOL_STATIC02_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC03_CHK].Value = dt.Rows[i]["VOL_STATIC03_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC04_CHK].Value = dt.Rows[i]["VOL_STATIC04_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC05_CHK].Value = dt.Rows[i]["VOL_STATIC05_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC06_CHK].Value = dt.Rows[i]["VOL_STATIC06_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC07_CHK].Value = dt.Rows[i]["VOL_STATIC07_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC08_CHK].Value = dt.Rows[i]["VOL_STATIC08_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC09_CHK].Value = dt.Rows[i]["VOL_STATIC09_CHK"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE01_CHK].Value = dt.Rows[i]["IMAGE01_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE02_CHK].Value = dt.Rows[i]["IMAGE02_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE03_CHK].Value = dt.Rows[i]["IMAGE03_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE04_CHK].Value = dt.Rows[i]["IMAGE04_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE05_CHK].Value = dt.Rows[i]["IMAGE05_CHK"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SPEC_VENDOR].Value = dt.Rows[i]["SPEC_VENDOR"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC05_SPEC_MIN].Value = dt.Rows[i]["VOL_STATIC05_SPEC_MIN"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC05_SPEC_MAX].Value = dt.Rows[i]["VOL_STATIC05_SPEC_MAX"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC02_SPEC_MIN].Value = dt.Rows[i]["VOL_STATIC02_SPEC_MIN"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC02_SPEC_MAX].Value = dt.Rows[i]["VOL_STATIC02_SPEC_MAX"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC08_SPEC_MIN].Value = dt.Rows[i]["VOL_STATIC08_SPEC_MIN"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC08_SPEC_MAX].Value = dt.Rows[i]["VOL_STATIC08_SPEC_MAX"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.LP_SPEC_MIN].Value = dt.Rows[i]["LP_SPEC_MIN"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.LP_SPEC_MAX].Value = dt.Rows[i]["LP_SPEC_MAX"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC03_SPEC_MIN].Value = dt.Rows[i]["VOL_STATIC03_SPEC_MIN"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC03_SPEC_MAX].Value = dt.Rows[i]["VOL_STATIC03_SPEC_MAX"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC07_SPEC_MIN].Value = dt.Rows[i]["VOL_STATIC07_SPEC_MIN"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC07_SPEC_MAX].Value = dt.Rows[i]["VOL_STATIC07_SPEC_MAX"];




                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.WT_SPEC_MIN].Value = dt.Rows[i]["WT_SPEC_MIN"];
                   spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.WT_SPEC_MAX].Value = dt.Rows[i]["WT_SPEC_MAX"];
                   spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.MEAN_SPEC_MIN].Value = dt.Rows[i]["MEAN_SPEC_MIN"];
                   spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.MEAN_SPEC_MAX].Value = dt.Rows[i]["MEAN_SPEC_MAX"];
                   spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SD_SPEC_MIN].Value = dt.Rows[i]["SD_SPEC_MIN"];
                   spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SD_SPEC_MAX].Value = dt.Rows[i]["SD_SPEC_MAX"];


                }
                //MPCF.FitColumnHeader(spdPackingLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewPivotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;



                if (TPDR.GetDataOne("", ref dt, "CQCM2103-002", dvcArgu, false, false, ref sSql) == false)
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

                    spdPivotList.ActiveSheet.SetValue(i, (int)PIVOT_LIST.CHK, false);

                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.ITEM_CODE].Value = dt.Rows[i]["ITEM_CODE"];
                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.NAME].Value = dt.Rows[i]["NAME"];
                    spdPivotList.ActiveSheet.Cells[i, (int)PIVOT_LIST.VALUE].Value = dt.Rows[i]["VALUE"];


                }
                //MPCF.FitColumnHeader(spdPackingLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
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
                        txtShipName.Text = popup.s_delivery_name;
                        //txtMatID.Text = popup.s_mat_id;
                        //txtMatDesc.Text = popup.s_mat_desc;
                       // txtGrade.Text = popup.s_grade;
                       // txtType.Text = popup.s_types;

                        cdvReportNo.Text = "";
                        txtRemarks.Text = "";

                        if (MPCF.Trim(cdvPackOrderNo.Text) != "")
                        {
                            //기본 스펙, 값 정보
                            ViewPackingLotList(cdvPackOrderNo.Text, txtLineNo.Text);

                            //피벗 틀 정보
                            ViewPivotList();

                            //Focused Cell 바인딩
                            fnSelectionChanged();
                            //ICP 정보
                            ViewIcptList(cdvReportNo.Text);


                        }

                        
                       // pictureBox1.Image = null;
                       // pictureBox2.Image = null;
                       // pictureBox3.Image = null;


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
                                                + "   AND DATA_3 = 'Y'" );
            

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



                if (TPDR.GetDataOne("", ref dt, "CQCM2103-005", dvcArgu, false, false, ref sSql) == false)
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


                    spdPackingLotList.ActiveSheet.SetValue(i, (int)PACK_LOT.CHK, true);

                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LINE].Value = dt.Rows[i]["LINE"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Value = dt.Rows[i]["PACK_LOT_ID"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.GRADE].Value = dt.Rows[i]["GRADE"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SIZES].Value = dt.Rows[i]["SIZES"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.WT].Value = dt.Rows[i]["WT"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.MEAN].Value = dt.Rows[i]["MEAN"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SD].Value = dt.Rows[i]["SD"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.LP].Value = dt.Rows[i]["LP"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ELEC_CONDUCTIVITY].Value = dt.Rows[i]["ELEC_CONDUCTIVITY"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC01].Value = dt.Rows[i]["VOL_STATIC01"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC02].Value = dt.Rows[i]["VOL_STATIC02"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC03].Value = dt.Rows[i]["VOL_STATIC03"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC04].Value = dt.Rows[i]["VOL_STATIC04"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC05].Value = dt.Rows[i]["VOL_STATIC05"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC06].Value = dt.Rows[i]["VOL_STATIC06"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC07].Value = dt.Rows[i]["VOL_STATIC07"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC08].Value = dt.Rows[i]["VOL_STATIC08"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC09].Value = dt.Rows[i]["VOL_STATIC09"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE01].Value = dt.Rows[i]["IMAGE01"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE02].Value = dt.Rows[i]["IMAGE02"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE03].Value = dt.Rows[i]["IMAGE03"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE04].Value = dt.Rows[i]["IMAGE04"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE05].Value = dt.Rows[i]["IMAGE05"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SUB_IMAGE01].Value = dt.Rows[i]["SUB_IMAGE01"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SUB_IMAGE02].Value = dt.Rows[i]["SUB_IMAGE02"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SUB_IMAGE03].Value = dt.Rows[i]["SUB_IMAGE03"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SUB_IMAGE04].Value = dt.Rows[i]["SUB_IMAGE04"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SUB_IMAGE05].Value = dt.Rows[i]["SUB_IMAGE05"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SUB_IMAGE06].Value = dt.Rows[i]["SUB_IMAGE06"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_NAME].Value = dt.Rows[i]["SHIP_NAME"];
                    if (i == 0)
                    {
                        txtShipName.Text = dt.Rows[i]["SHIP_NAME"].ToString();
                    }
                    
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.REMARKS].Value = dt.Rows[i]["REMARKS"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ANALYZER].Value = dt.Rows[i]["ANALYZER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ANALYZER_DESC].Value = dt.Rows[i]["ANALYZER_DESC"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.WT_CHK].Value = dt.Rows[i]["WT_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.MEAN_CHK].Value = dt.Rows[i]["MEAN_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SD_CHK].Value = dt.Rows[i]["SD_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.LP_CHK].Value = dt.Rows[i]["LP_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ELEC_CONDUCTIVITY_CHK].Value = dt.Rows[i]["ELEC_CONDUCTIVITY_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC01_CHK].Value = dt.Rows[i]["VOL_STATIC01_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC02_CHK].Value = dt.Rows[i]["VOL_STATIC02_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC03_CHK].Value = dt.Rows[i]["VOL_STATIC03_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC04_CHK].Value = dt.Rows[i]["VOL_STATIC04_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC05_CHK].Value = dt.Rows[i]["VOL_STATIC05_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC06_CHK].Value = dt.Rows[i]["VOL_STATIC06_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC07_CHK].Value = dt.Rows[i]["VOL_STATIC07_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC08_CHK].Value = dt.Rows[i]["VOL_STATIC08_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC09_CHK].Value = dt.Rows[i]["VOL_STATIC09_CHK"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE01_CHK].Value = dt.Rows[i]["IMAGE01_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE02_CHK].Value = dt.Rows[i]["IMAGE02_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE03_CHK].Value = dt.Rows[i]["IMAGE03_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE04_CHK].Value = dt.Rows[i]["IMAGE04_CHK"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.IMAGE05_CHK].Value = dt.Rows[i]["IMAGE05_CHK"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SPEC_VENDOR].Value = dt.Rows[i]["SPEC_VENDOR"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC05_SPEC_MIN].Value = dt.Rows[i]["VOL_STATIC05_SPEC_MIN"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC05_SPEC_MAX].Value = dt.Rows[i]["VOL_STATIC05_SPEC_MAX"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC02_SPEC_MIN].Value = dt.Rows[i]["VOL_STATIC02_SPEC_MIN"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC02_SPEC_MAX].Value = dt.Rows[i]["VOL_STATIC02_SPEC_MAX"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC08_SPEC_MIN].Value = dt.Rows[i]["VOL_STATIC08_SPEC_MIN"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC08_SPEC_MAX].Value = dt.Rows[i]["VOL_STATIC08_SPEC_MAX"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.LP_SPEC_MIN].Value = dt.Rows[i]["LP_SPEC_MIN"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.LP_SPEC_MAX].Value = dt.Rows[i]["LP_SPEC_MAX"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC03_SPEC_MIN].Value = dt.Rows[i]["VOL_STATIC03_SPEC_MIN"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC03_SPEC_MAX].Value = dt.Rows[i]["VOL_STATIC03_SPEC_MAX"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC07_SPEC_MIN].Value = dt.Rows[i]["VOL_STATIC07_SPEC_MIN"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.VOL_STATIC07_SPEC_MAX].Value = dt.Rows[i]["VOL_STATIC07_SPEC_MAX"];



                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.WT_SPEC_MIN].Value = dt.Rows[i]["WT_SPEC_MIN"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.WT_SPEC_MAX].Value = dt.Rows[i]["WT_SPEC_MAX"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.MEAN_SPEC_MIN].Value = dt.Rows[i]["MEAN_SPEC_MIN"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.MEAN_SPEC_MAX].Value = dt.Rows[i]["MEAN_SPEC_MAX"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SD_SPEC_MIN].Value = dt.Rows[i]["SD_SPEC_MIN"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SD_SPEC_MAX].Value = dt.Rows[i]["SD_SPEC_MAX"];









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
                in_node.ProcStep = '4'; //GRIT(MP)  발번
                in_node.AddString("AREA_ID", cdvDept.Text);



                //기본 포장 lot정보 (스펙,  값)
                for (int i = 0; i < spdPackingLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        data_list = in_node.AddNode("DATA_LIST");

                        data_list.AddString("HEADER_ID", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_ORDER_ID].Text);
                        data_list.AddInt("LINE_NUMBER", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LINE].Value);

                        data_list.AddString("PACK_LOT_ID", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text);
                        data_list.AddString("ITEM_CODE", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.MAT_ID].Text);
                        data_list.AddString("GRADE", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.GRADE].Text);
                        data_list.AddString("SIZES", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SIZES].Text);
                        data_list.AddString("INSP_VALUE", txtJudgeResult.Text);
                        // data_list.AddString("SHIP_NAME", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SHIP_NAME].Text);
                        data_list.AddString("SHIP_NAME", txtShipName.Text);

                        data_list.AddString("WT", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.WT].Text);
                        data_list.AddString("MEAN", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.MEAN].Text);
                        data_list.AddString("SD", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SD].Text);
                        data_list.AddString("LP", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LP].Text);
                        data_list.AddString("ELEC_CONDUCTIVITY", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.ELEC_CONDUCTIVITY].Text);
                        data_list.AddString("VOL_STATIC01", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC01].Text);
                        data_list.AddString("VOL_STATIC02", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC02].Text);
                        data_list.AddString("VOL_STATIC03", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC03].Text);
                        data_list.AddString("VOL_STATIC04", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC04].Text);
                        data_list.AddString("VOL_STATIC05", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC05].Text);
                        data_list.AddString("VOL_STATIC06", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC06].Text);
                        data_list.AddString("VOL_STATIC07", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC07].Text);
                        data_list.AddString("VOL_STATIC08", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC08].Text);
                        data_list.AddString("VOL_STATIC09", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC09].Text);

                        data_list.AddString("IMAGE01", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE01].Text);
                        data_list.AddString("IMAGE02", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE02].Text);
                        data_list.AddString("IMAGE03", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE03].Text);
                        data_list.AddString("IMAGE04", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE04].Text);
                        data_list.AddString("IMAGE05", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE05].Text);

                        data_list.AddString("ANALYZER", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.ANALYZER].Text);

                        data_list.AddString("WT_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.WT_CHK].Text);
                        data_list.AddString("MEAN_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.MEAN_CHK].Text);
                        data_list.AddString("SD_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SD_CHK].Text);
                        data_list.AddString("LP_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LP_CHK].Text);
                        data_list.AddString("ELEC_CONDUCTIVITY_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.ELEC_CONDUCTIVITY_CHK].Text);
                        data_list.AddString("VOL_STATIC01_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC01_CHK].Text);
                        data_list.AddString("VOL_STATIC02_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC02_CHK].Text);
                        data_list.AddString("VOL_STATIC03_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC03_CHK].Text);
                        data_list.AddString("VOL_STATIC04_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC04_CHK].Text);
                        data_list.AddString("VOL_STATIC05_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC05_CHK].Text);
                        data_list.AddString("VOL_STATIC06_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC06_CHK].Text);
                        data_list.AddString("VOL_STATIC07_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC07_CHK].Text);
                        data_list.AddString("VOL_STATIC08_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC08_CHK].Text);
                        data_list.AddString("VOL_STATIC09_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC09_CHK].Text);

                        data_list.AddString("IMAGE01_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE01_CHK].Text);
                        data_list.AddString("IMAGE02_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE02_CHK].Text);
                        data_list.AddString("IMAGE03_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE03_CHK].Text);
                        data_list.AddString("IMAGE04_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE04_CHK].Text);
                        data_list.AddString("IMAGE05_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE05_CHK].Text);

                        data_list.AddString("REMARKS", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.REMARKS].Text);  //추가필요

                        data_list.AddString("SUB_IMAGE01", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SUB_IMAGE01].Text);
                        data_list.AddString("SUB_IMAGE02", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SUB_IMAGE02].Text);
                        data_list.AddString("SUB_IMAGE03", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SUB_IMAGE03].Text);
                        data_list.AddString("SUB_IMAGE04", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SUB_IMAGE04].Text);
                        data_list.AddString("SUB_IMAGE05", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SUB_IMAGE05].Text);
                        data_list.AddString("SUB_IMAGE06", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SUB_IMAGE06].Text);


                        ichk++;
                    }
                    
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

                if (ichk == 0)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(491));
                    return false;
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
                in_node.ProcStep = '4'; // GRIT MP 성적서 저장

                in_node.AddString("REPORT_NO", cdvReportNo.Text);



                //1번 테이블 저장
                //기본 포장 lot정보 (스펙,  값)
                for (int i = 0; i < spdPackingLotList.ActiveSheet.RowCount; i++)
                {

                        data_list = in_node.AddNode("DATA_LIST");

                        data_list.AddString("HEADER_ID", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_ORDER_ID].Text);
                    data_list.AddInt("LINE_NUMBER", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LINE].Value);
                    data_list.AddString("PACK_LOT_ID", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text);
                        data_list.AddString("ITEM_CODE", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.MAT_ID].Text);
                        data_list.AddString("GRADE", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.GRADE].Text);
                        data_list.AddString("SIZES", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SIZES].Text);
                        data_list.AddString("INSP_VALUE", txtJudgeResult.Text);
                    // data_list.AddString("SHIP_NAME", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SHIP_NAME].Text);
                    data_list.AddString("SHIP_NAME", txtShipName.Text);

                    data_list.AddString("WT", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.WT].Text);
                    data_list.AddString("MEAN", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.MEAN].Text);
                    data_list.AddString("SD", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SD].Text);
                    data_list.AddString("LP", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LP].Text);
                    data_list.AddString("ELEC_CONDUCTIVITY", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.ELEC_CONDUCTIVITY].Text);
                    data_list.AddString("VOL_STATIC01", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC01].Text);
                    data_list.AddString("VOL_STATIC02", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC02].Text);
                    data_list.AddString("VOL_STATIC03", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC03].Text);
                    data_list.AddString("VOL_STATIC04", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC04].Text);
                    data_list.AddString("VOL_STATIC05", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC05].Text);
                    data_list.AddString("VOL_STATIC06", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC06].Text);
                    data_list.AddString("VOL_STATIC07", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC07].Text);
                    data_list.AddString("VOL_STATIC08", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC08].Text);
                    data_list.AddString("VOL_STATIC09", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC09].Text);

                    data_list.AddString("IMAGE01", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE01].Text);
                    data_list.AddString("IMAGE02", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE02].Text);
                    data_list.AddString("IMAGE03", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE03].Text);
                    data_list.AddString("IMAGE04", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE04].Text);
                    data_list.AddString("IMAGE05", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE05].Text);

                    data_list.AddString("ANALYZER", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.ANALYZER].Text);

                    data_list.AddString("WT_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.WT_CHK].Text);
                    data_list.AddString("MEAN_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.MEAN_CHK].Text);
                    data_list.AddString("SD_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SD_CHK].Text);
                    data_list.AddString("LP_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LP_CHK].Text);
                    data_list.AddString("ELEC_CONDUCTIVITY_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.ELEC_CONDUCTIVITY_CHK].Text);
                    data_list.AddString("VOL_STATIC01_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC01_CHK].Text);
                    data_list.AddString("VOL_STATIC02_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC02_CHK].Text);
                    data_list.AddString("VOL_STATIC03_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC03_CHK].Text);
                    data_list.AddString("VOL_STATIC04_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC04_CHK].Text);
                    data_list.AddString("VOL_STATIC05_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC05_CHK].Text);
                    data_list.AddString("VOL_STATIC06_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC06_CHK].Text);
                    data_list.AddString("VOL_STATIC07_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC07_CHK].Text);
                    data_list.AddString("VOL_STATIC08_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC08_CHK].Text);
                    data_list.AddString("VOL_STATIC09_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC09_CHK].Text);

                    data_list.AddString("IMAGE01_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE01_CHK].Text);
                    data_list.AddString("IMAGE02_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE02_CHK].Text);
                    data_list.AddString("IMAGE03_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE03_CHK].Text);
                    data_list.AddString("IMAGE04_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE04_CHK].Text);
                    data_list.AddString("IMAGE05_CHK", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.IMAGE05_CHK].Text);

                    data_list.AddString("REMARKS", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.REMARKS].Text);

                    data_list.AddString("SUB_IMAGE01", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SUB_IMAGE01].Text);
                    data_list.AddString("SUB_IMAGE02", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SUB_IMAGE02].Text);
                    data_list.AddString("SUB_IMAGE03", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SUB_IMAGE03].Text);
                    data_list.AddString("SUB_IMAGE04", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SUB_IMAGE04].Text);
                    data_list.AddString("SUB_IMAGE05", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SUB_IMAGE05].Text);
                    data_list.AddString("SUB_IMAGE06", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SUB_IMAGE06].Text);


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

                //피벗 틀 정보
                ViewPivotList();

                //Focused Cell 바인딩
                fnSelectionChanged();


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

        private void fnPrintShipReport(string sViewID, string sFileName)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                // int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "REPORT_NO";
                dvcArgu[1].sCondition_Value = cdvReportNo.Text;

                dvcArgu[2].sCondition_ID = "PRINT_USER";
                dvcArgu[2].sCondition_Value = txtPrintUser.Text;

               // dvcArgu[2].sCondition_ID = "INSP_RESULT";
               // dvcArgu[2].sCondition_Value = txtJudgeResult.Text;


                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                //일반성적서 pip510p

                DevReport.PreviewXtraReport(dt, sFileName);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
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

        private void btnPrint_Click(object sender, EventArgs e)
        {
            //성적서 바인딩확인
            if (CheckCondition("PRINT") == false)
            {
                return;
            }

            if (cdvShipReportType.Text == "GRT_MP_01") // MP 기본성적서
            {
                fnPrintShipReport("CQCM2103-010", "pip525p");
            }
            else if (cdvShipReportType.Text == "GRT_MP_02") //MP 기본성적서 ( SPEC 포함)
            {
                fnPrintShipReport("CQCM2103-011", "pip525p_4");
            }
            else if (cdvShipReportType.Text == "GRT_MP_03") //MP 기본성적서 2
            {
                fnPrintShipReport("CQCM2103-012", "pip525p_2");
            }
            else if (cdvShipReportType.Text == "GRT_MP_04") // MP 기본성적서 2 (SPEC 포함)
            {
                fnPrintShipReport("CQCM2103-013", "pip525p_5");
            }
            else if (cdvShipReportType.Text == "GRT_MP_05") // 기본성적서 ( SEM 1 포함)
            {
                fnPrintShipReport("CQCM2103-014", "pip525p_8");
            }
            else if (cdvShipReportType.Text == "GRT_MP_06") // 기본성적서 ( SEM 2 포함)
            {
                fnPrintShipReport("CQCM2103-014", "pip525p_9");
            }
            else if (cdvShipReportType.Text == "GRT_MP_07") // MP ICP성적서
            {
                fnPrintShipReport("CQCM2103-016", "pip525p_10");
            }
            else if (cdvShipReportType.Text == "GRT_MP_08") // MP MMC성적서
            {
                fnPrintShipReport("CQCM2103-010", "pip525p_11");
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
                popup.b_mp_yn = true;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    if (popup.s_report_no != "")
                    {
                        cdvReportNo.Text = popup.s_report_no;

                        if (MPCF.Trim(cdvReportNo.Text) != "")
                        {

                            cdvPackOrderNo.Text = "";
                            txtCustomerDesc.Text = "";
                            txtShipName.Text = "";
                            txtLineNo.Text = "";

                            // 성적서 조회
                            fnviewReport_1(cdvReportNo.Text);
                            fnviewReport_4(cdvReportNo.Text);

                            //피벗 틀 정보
                            ViewPivotList();

                            //Focused Cell 바인딩
                            fnSelectionChanged();

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

        private void frmTranShipReportRegistration_GRT_MP_Load(object sender, EventArgs e)
        {
            fnGetUserDesc();
            txtJudgeResult.Text = "ACCEPTED";
        }

        public static Image ByteArrayToImage(byte[] b)
        {
            TypeConverter tc = TypeDescriptor.GetConverter(typeof(Bitmap));
            ImageConverter imgcvt = new ImageConverter();
            
            
            

            Image img = (Image)imgcvt.ConvertFrom(b);
            return img;
        }

        private void ultraButton1_Click(object sender, EventArgs e)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
                DataTable dt = null;
                string sSql = "";
               // int i = 0;
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

        private void fnRegistrationFile(FileInfo _fileInfo, int iTargetRowIndex, int iTargetColumnIndex)
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

            spdPackingLotList.ActiveSheet.Cells[iTargetRowIndex, iTargetColumnIndex].Value = s_File_no;

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

                fnRegistrationFile(finfo,iActiveRow, (int)PACK_LOT.IMAGE01);

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

                fnRegistrationFile(finfo, iActiveRow, (int)PACK_LOT.IMAGE02);

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

                fnRegistrationFile(finfo, iActiveRow, (int)PACK_LOT.IMAGE03);

            }
        }


        private void ViewImageFile(string _image1, string _image2, string _image3, string _image4, string _image5)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
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

                dvcArgu[4].sCondition_ID = "IMAGE_4";
                dvcArgu[4].sCondition_Value = _image4;

                dvcArgu[5].sCondition_ID = "IMAGE_5";
                dvcArgu[5].sCondition_Value = _image5;



                if (TPDR.GetDataOne("", ref dt, "CQCM2103-003", dvcArgu, false, false, ref sSql) == false)
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

                    if (dt.Rows[i]["FILE_NO"].ToString() == _image4)
                    {
                        pictureBox4.Image = ByteArrayToImage((byte[])dt.Rows[i]["IMAGE_DATA"]);
                    }

                    if (dt.Rows[i]["FILE_NO"].ToString() == _image5)
                    {
                        pictureBox5.Image = ByteArrayToImage((byte[])dt.Rows[i]["IMAGE_DATA"]);
                    }

                }


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewSubImageFile(string _image1, string _image2, string _image3, string _image4, string _image5, string _image6)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[7];
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

                dvcArgu[4].sCondition_ID = "IMAGE_4";
                dvcArgu[4].sCondition_Value = _image4;

                dvcArgu[5].sCondition_ID = "IMAGE_5";
                dvcArgu[5].sCondition_Value = _image5;

                dvcArgu[6].sCondition_ID = "IMAGE_6";
                dvcArgu[6].sCondition_Value = _image6;



                if (TPDR.GetDataOne("", ref dt, "CQCM2103-004", dvcArgu, false, false, ref sSql) == false)
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
                        picSubImage1.Image = ByteArrayToImage((byte[])dt.Rows[i]["IMAGE_DATA"]);
                    }

                    if (dt.Rows[i]["FILE_NO"].ToString() == _image2)
                    {
                        picSubImage2.Image = ByteArrayToImage((byte[])dt.Rows[i]["IMAGE_DATA"]);
                    }

                    if (dt.Rows[i]["FILE_NO"].ToString() == _image3)
                    {
                        picSubImage3.Image = ByteArrayToImage((byte[])dt.Rows[i]["IMAGE_DATA"]);
                    }

                    if (dt.Rows[i]["FILE_NO"].ToString() == _image4)
                    {
                        picSubImage4.Image = ByteArrayToImage((byte[])dt.Rows[i]["IMAGE_DATA"]);
                    }

                    if (dt.Rows[i]["FILE_NO"].ToString() == _image5)
                    {
                        picSubImage5.Image = ByteArrayToImage((byte[])dt.Rows[i]["IMAGE_DATA"]);
                    }

                    if (dt.Rows[i]["FILE_NO"].ToString() == _image6)
                    {
                        picSubImage6.Image = ByteArrayToImage((byte[])dt.Rows[i]["IMAGE_DATA"]);
                    }

                }


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdPackingLotList_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            fnSelectionChanged();
        }

        private void fnSelectionChanged()
        {
            if (spdPackingLotList.ActiveSheet.ActiveRowIndex < 0)
                return;

            int iActiveRow = spdPackingLotList.ActiveSheet.ActiveRowIndex;


            string s_wt = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.WT].Value.ToString();
            string s_mean = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.MEAN].Value.ToString();
            string s_sd = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.SD].Value.ToString();
            string s_lp = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.LP].Value.ToString();
            string s_elec = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.ELEC_CONDUCTIVITY].Value.ToString();



            string s_vol_static01 = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC01].Value.ToString();
            string s_vol_static02 = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC02].Value.ToString();
            string s_vol_static03 = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC03].Value.ToString();
            string s_vol_static04 = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC04].Value.ToString();
            string s_vol_static05 = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC05].Value.ToString();
            string s_vol_static06 = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC06].Value.ToString();
            string s_vol_static07 = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC07].Value.ToString();
            string s_vol_static08 = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC08].Value.ToString();





            string s_wt_lower = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.WT_SPEC_MIN].Value.ToString();
            string s_mean_lower = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.MEAN_SPEC_MIN].Value.ToString();
            string s_sd_lower = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.SD_SPEC_MIN].Value.ToString();
            string s_lp_lower = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.LP_SPEC_MIN].Value.ToString();
            string s_vol_static02_lower = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC02_SPEC_MIN].Value.ToString();
            string s_vol_static05_lower = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC05_SPEC_MIN].Value.ToString();
            string s_vol_static08_lower = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC08_SPEC_MIN].Value.ToString();
            string s_vol_static03_lower = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC03_SPEC_MIN].Value.ToString();
            string s_vol_static07_lower = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC07_SPEC_MIN].Value.ToString();


            string s_wt_Upper = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.WT_SPEC_MAX].Value.ToString();
            string s_mean_Upper = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.MEAN_SPEC_MAX].Value.ToString();
            string s_sd_Upper = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.SD_SPEC_MAX].Value.ToString();
            string s_lp_Upper = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.LP_SPEC_MAX].Value.ToString();
            string s_vol_static02_Upper = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC02_SPEC_MAX].Value.ToString();
            string s_vol_static05_Upper = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC05_SPEC_MAX].Value.ToString();
            string s_vol_static08_Upper = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC08_SPEC_MAX].Value.ToString();
            string s_vol_static03_Upper = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC03_SPEC_MAX].Value.ToString();
            string s_vol_static07_Upper = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC07_SPEC_MAX].Value.ToString();


            string s_wt_chk = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.WT_CHK].Value.ToString();
            string s_mean_chk = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.MEAN_CHK].Value.ToString();
            string s_sd_chk = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.SD_CHK].Value.ToString();
            string s_lp_chk = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.LP_CHK].Value.ToString();
            string s_elec_chk = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.ELEC_CONDUCTIVITY_CHK].Value.ToString();

            string s_vol_static01_chk = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC01_CHK].Value.ToString();
            string s_vol_static02_chk = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC02_CHK].Value.ToString();
            string s_vol_static03_chk = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC03_CHK].Value.ToString();
            string s_vol_static04_chk = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC04_CHK].Value.ToString();
            string s_vol_static05_chk = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC05_CHK].Value.ToString();
            string s_vol_static06_chk = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC06_CHK].Value.ToString();
            string s_vol_static07_chk = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC07_CHK].Value.ToString();
            string s_vol_static08_chk = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.VOL_STATIC08_CHK].Value.ToString();

            string s_image01_chk = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.IMAGE01_CHK].Value.ToString();
            string s_image02_chk = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.IMAGE02_CHK].Value.ToString();
            string s_image03_chk = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.IMAGE03_CHK].Value.ToString();
            string s_image04_chk = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.IMAGE04_CHK].Value.ToString();
            string s_image05_chk = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.IMAGE05_CHK].Value.ToString();

            string s_analyzer = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.ANALYZER].Value.ToString();
            string s_analyzer_desc = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.ANALYZER_DESC].Value.ToString();
            string s_remarks = spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.REMARKS].Value.ToString();


            // 바인딩
            cdvAnalyzer.Text = s_analyzer;
            cdvAnalyzer.DisplayText = s_analyzer_desc;
            txtRemarks.Text = s_remarks;

            for (int i_pivot = 0; i_pivot < spdPivotList.ActiveSheet.RowCount; i_pivot++)
            {

                if (spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.ITEM_CODE].Value.ToString() == "WT")
                {
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.CHK].Value = s_wt_chk == "-1" ? true : false;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.VALUE].Value = s_wt;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.LOWER].Value = s_wt_lower;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.UPPER].Value = s_wt_Upper;

                    SpecSearch(i_pivot, (int)PIVOT_LIST.VALUE);
                }
                else if (spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.ITEM_CODE].Value.ToString() == "MEAN")
                {
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.CHK].Value = s_mean_chk == "-1" ? true : false;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.VALUE].Value = s_mean;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.LOWER].Value = s_mean_lower;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.UPPER].Value = s_mean_Upper;
                    SpecSearch(i_pivot, (int)PIVOT_LIST.VALUE);
                }
                else if (spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.ITEM_CODE].Value.ToString() == "SD")
                {
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.CHK].Value = s_sd_chk == "-1" ? true : false;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.VALUE].Value = s_sd;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.LOWER].Value = s_sd_lower;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.UPPER].Value = s_sd_Upper;
                    SpecSearch(i_pivot, (int)PIVOT_LIST.VALUE);
                }
                else if (spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.ITEM_CODE].Value.ToString() == "LP")
                {
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.CHK].Value = s_lp_chk == "-1" ? true : false;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.VALUE].Value = s_lp;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.LOWER].Value = s_lp_lower;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.UPPER].Value = s_lp_Upper;
                    SpecSearch(i_pivot, (int)PIVOT_LIST.VALUE);
                }
                else if (spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.ITEM_CODE].Value.ToString() == "ELEC_CONDUCTIVITY")
                {
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.CHK].Value = s_elec_chk == "-1" ? true : false;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.VALUE].Value = s_elec;
                }
                else if (spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.ITEM_CODE].Value.ToString() == "VOL_STATIC01")
                {
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.CHK].Value = s_vol_static01_chk == "-1" ? true : false;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.VALUE].Value = s_vol_static01;
                }
                else if (spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.ITEM_CODE].Value.ToString() == "VOL_STATIC02")
                {
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.CHK].Value = s_vol_static02_chk == "-1" ? true : false;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.VALUE].Value = s_vol_static02;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.LOWER].Value = s_vol_static02_lower;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.UPPER].Value = s_vol_static02_Upper;
                    SpecSearch(i_pivot, (int)PIVOT_LIST.VALUE);
                }
                else if (spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.ITEM_CODE].Value.ToString() == "VOL_STATIC03")
                {
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.CHK].Value = s_vol_static03_chk == "-1" ? true : false;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.VALUE].Value = s_vol_static03;
                }
                else if (spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.ITEM_CODE].Value.ToString() == "VOL_STATIC04")
                {
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.CHK].Value = s_vol_static04_chk == "-1" ? true : false;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.VALUE].Value = s_vol_static04;
                }
                else if (spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.ITEM_CODE].Value.ToString() == "VOL_STATIC05")
                {
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.CHK].Value = s_vol_static05_chk == "-1" ? true : false;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.VALUE].Value = s_vol_static05;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.LOWER].Value = s_vol_static05_lower;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.UPPER].Value = s_vol_static05_Upper;
                    SpecSearch(i_pivot, (int)PIVOT_LIST.VALUE);
                }
                else if (spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.ITEM_CODE].Value.ToString() == "VOL_STATIC06")
                {
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.CHK].Value = s_vol_static06_chk == "-1" ? true : false;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.VALUE].Value = s_vol_static06;
                }
                else if (spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.ITEM_CODE].Value.ToString() == "VOL_STATIC07")
                {
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.CHK].Value = s_vol_static07_chk == "-1" ? true : false;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.VALUE].Value = s_vol_static07;
                }
                else if (spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.ITEM_CODE].Value.ToString() == "VOL_STATIC08")
                {
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.CHK].Value = s_vol_static08_chk == "-1" ? true : false;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.VALUE].Value = s_vol_static08;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.LOWER].Value = s_vol_static08_lower;
                    spdPivotList.ActiveSheet.Cells[i_pivot, (int)PIVOT_LIST.UPPER].Value = s_vol_static08_Upper;
                    SpecSearch(i_pivot, (int)PIVOT_LIST.VALUE);
                }






            }

            chkReport1.Checked = s_image01_chk == "-1" ? true : false;
            chkReport2.Checked = s_image02_chk == "-1" ? true : false;
            chkReport3.Checked = s_image03_chk == "-1" ? true : false;
            chkReport4.Checked = s_image04_chk == "-1" ? true : false;
            chkReport5.Checked = s_image05_chk == "-1" ? true : false;



            pictureBox1.Image = null;
            pictureBox2.Image = null;
            pictureBox3.Image = null;
            pictureBox4.Image = null;
            pictureBox5.Image = null;

            string s_image_1 = MPCF.Trim(spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.IMAGE01].Value.ToString());
            string s_image_2 = MPCF.Trim(spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.IMAGE02].Value.ToString());
            string s_image_3 = MPCF.Trim(spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.IMAGE03].Value.ToString());
            string s_image_4 = MPCF.Trim(spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.IMAGE04].Value.ToString());
            string s_image_5 = MPCF.Trim(spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.IMAGE05].Value.ToString());


            ViewImageFile(s_image_1, s_image_2, s_image_3, s_image_4, s_image_5);
        }

        private void btnApply_Click(object sender, EventArgs e)
        {



        }

        private void spdPivotList_Change(object sender, ChangeEventArgs e)
        {
            if (spdPackingLotList.ActiveSheet.ActiveRowIndex < 0)
                return;

            if (spdPivotList.ActiveSheet.ActiveRowIndex < 0)
                return;


            int iLotActiveRow = spdPackingLotList.ActiveSheet.ActiveRowIndex;
            string sItemCode;
            string sValue;

            int iRow = e.Row;
            int iCol = e.Column;



            try
            {
                // Value 수정시 기본 그리드 UPDATE
                if (e.Column == (int)PIVOT_LIST.VALUE)
                {
                    //변경된 값의 항목코드 값
                    sItemCode = spdPivotList.ActiveSheet.Cells[e.Row, (int)PIVOT_LIST.ITEM_CODE].Value.ToString();
                    sValue = spdPivotList.ActiveSheet.Cells[e.Row, e.Column].Text;

                    for ( iCol = 0; iCol < spdPackingLotList.ActiveSheet.Columns.Count; iCol++)
                    {
                        if (Convert.ToString(spdPackingLotList.ActiveSheet.Columns[iCol].Tag) == sItemCode)
                        {
                            spdPackingLotList.ActiveSheet.Cells[iLotActiveRow, iCol].Value = sValue;
                        }
                    }

                    SpecSearch(iRow, iCol);
                }

                string bCheck;


                if (e.Column == (int)PIVOT_LIST.CHK)
                {

                    bCheck = spdPivotList.ActiveSheet.Cells[e.Row, e.Column].Value.ToString().ToUpper();
                    sItemCode = spdPivotList.ActiveSheet.Cells[e.Row, (int)PIVOT_LIST.ITEM_CODE].Value.ToString();

                    for ( iCol = 0; iCol < spdPackingLotList.ActiveSheet.Columns.Count; iCol++)
                    {

                        if (Convert.ToString(spdPackingLotList.ActiveSheet.Columns[iCol].Tag) == sItemCode + "_CHK")
                        {
                            spdPackingLotList.ActiveSheet.Cells[iLotActiveRow, iCol].Value = bCheck == "TRUE" ? "-1" : "0";
       
                        }
                    }

                }



            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

            

        }

        private void spdPivotList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            if (e.Row < 0)
                return;

            if (spdPackingLotList.ActiveSheet.ActiveRowIndex < 0)
                return;


            int iLotActiveRow = spdPackingLotList.ActiveSheet.ActiveRowIndex;
            string bCheck;
            string sItemCode;

            if (e.Column == (int)PIVOT_LIST.CHK)
            {

                bCheck = spdPivotList.ActiveSheet.Cells[e.Row, e.Column].Value.ToString().ToUpper();
                sItemCode = spdPivotList.ActiveSheet.Cells[e.Row, (int)PIVOT_LIST.ITEM_CODE].Value.ToString();

                for (int iCol = 0; iCol < spdPackingLotList.ActiveSheet.Columns.Count; iCol++)
                {

                    if (Convert.ToString(spdPackingLotList.ActiveSheet.Columns[iCol].Tag) == sItemCode + "_CHK")
                    {
                        spdPackingLotList.ActiveSheet.Cells[iLotActiveRow, iCol].Value = bCheck == "TRUE" ? "-1" : "0";
                    }
                }

            }
            

        }

        private void button1_Click(object sender, EventArgs e)
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
                pictureBox4.Image = Image.FromFile(openFileDialog1.FileName);

                finfo = new FileInfo(fullPath);

                fnRegistrationFile(finfo, iActiveRow, (int)PACK_LOT.IMAGE04);

            }
        }

        private void button2_Click(object sender, EventArgs e)
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
                pictureBox5.Image = Image.FromFile(openFileDialog1.FileName);

                finfo = new FileInfo(fullPath);

                fnRegistrationFile(finfo, iActiveRow, (int)PACK_LOT.IMAGE05);

            }
        }

        private void chkReport1_CheckedChanged(object sender, EventArgs e)
        {
            if (spdPackingLotList.ActiveSheet.ActiveRowIndex < 0)
                return;


            int iRowIndex = spdPackingLotList.ActiveSheet.ActiveRowIndex;

            spdPackingLotList.ActiveSheet.Cells[iRowIndex, (int)PACK_LOT.IMAGE01_CHK].Value = chkReport1.Checked == true ? "-1" : "0"; 
        }

        private void chkReport2_CheckedChanged(object sender, EventArgs e)
        {
            if (spdPackingLotList.ActiveSheet.ActiveRowIndex < 0)
                return;


            int iRowIndex = spdPackingLotList.ActiveSheet.ActiveRowIndex;

            spdPackingLotList.ActiveSheet.Cells[iRowIndex, (int)PACK_LOT.IMAGE02_CHK].Value = chkReport2.Checked == true ? "-1" : "0";
        }

        private void chkReport3_CheckedChanged(object sender, EventArgs e)
        {
            if (spdPackingLotList.ActiveSheet.ActiveRowIndex < 0)
                return;


            int iRowIndex = spdPackingLotList.ActiveSheet.ActiveRowIndex;

            spdPackingLotList.ActiveSheet.Cells[iRowIndex, (int)PACK_LOT.IMAGE03_CHK].Value = chkReport3.Checked == true ? "-1" : "0";
        }

        private void chkReport4_CheckedChanged(object sender, EventArgs e)
        {
            if (spdPackingLotList.ActiveSheet.ActiveRowIndex < 0)
                return;


            int iRowIndex = spdPackingLotList.ActiveSheet.ActiveRowIndex;

            spdPackingLotList.ActiveSheet.Cells[iRowIndex, (int)PACK_LOT.IMAGE04_CHK].Value = chkReport4.Checked == true ? "-1" : "0";
        }

        private void chkReport5_CheckedChanged(object sender, EventArgs e)
        {
            if (spdPackingLotList.ActiveSheet.ActiveRowIndex < 0)
                return;


            int iRowIndex = spdPackingLotList.ActiveSheet.ActiveRowIndex;

            spdPackingLotList.ActiveSheet.Cells[iRowIndex, (int)PACK_LOT.IMAGE05_CHK].Value = chkReport5.Checked == true ? "-1" : "0";
        }

        private void btnSubImage1_Click(object sender, EventArgs e)
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
                picSubImage1.Image = Image.FromFile(openFileDialog1.FileName);

                finfo = new FileInfo(fullPath);

                fnRegistrationFile(finfo, iActiveRow, (int)PACK_LOT.SUB_IMAGE01);

            }
        }

        private void btnSubImage2_Click(object sender, EventArgs e)
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
                picSubImage2.Image = Image.FromFile(openFileDialog1.FileName);

                finfo = new FileInfo(fullPath);

                fnRegistrationFile(finfo, iActiveRow, (int)PACK_LOT.SUB_IMAGE02);

            }
        }

        private void btnSubImage3_Click(object sender, EventArgs e)
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
                picSubImage3.Image = Image.FromFile(openFileDialog1.FileName);

                finfo = new FileInfo(fullPath);

                fnRegistrationFile(finfo, iActiveRow, (int)PACK_LOT.SUB_IMAGE03);

            }
        }

        private void btnSubImage4_Click(object sender, EventArgs e)
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
                picSubImage4.Image = Image.FromFile(openFileDialog1.FileName);

                finfo = new FileInfo(fullPath);

                fnRegistrationFile(finfo, iActiveRow, (int)PACK_LOT.SUB_IMAGE04);

            }
        }

        private void btnSubImage5_Click(object sender, EventArgs e)
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
                picSubImage5.Image = Image.FromFile(openFileDialog1.FileName);

                finfo = new FileInfo(fullPath);

                fnRegistrationFile(finfo, iActiveRow, (int)PACK_LOT.SUB_IMAGE05);

            }
        }

        private void btnSubImage6_Click(object sender, EventArgs e)
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
                picSubImage6.Image = Image.FromFile(openFileDialog1.FileName);

                finfo = new FileInfo(fullPath);

                fnRegistrationFile(finfo, iActiveRow, (int)PACK_LOT.SUB_IMAGE06);

            }
        }

        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (tabControl1.SelectedTab.Name == "tpgSEM")
            {
                picSubImage1.Image = null;
                picSubImage2.Image = null;
                picSubImage3.Image = null;
                picSubImage4.Image = null;
                picSubImage5.Image = null;
                picSubImage6.Image = null;


                if (spdPackingLotList.ActiveSheet.ActiveRowIndex < 0)
                    return;

                int iActiveRow = spdPackingLotList.ActiveSheet.ActiveRowIndex;

                string s_sub_image_1 = MPCF.Trim(spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.SUB_IMAGE01].Value.ToString());
                string s_sub_image_2 = MPCF.Trim(spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.SUB_IMAGE02].Value.ToString());
                string s_sub_image_3 = MPCF.Trim(spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.SUB_IMAGE03].Value.ToString());
                string s_sub_image_4 = MPCF.Trim(spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.SUB_IMAGE04].Value.ToString());
                string s_sub_image_5 = MPCF.Trim(spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.SUB_IMAGE05].Value.ToString());
                string s_sub_image_6 = MPCF.Trim(spdPackingLotList.ActiveSheet.Cells[iActiveRow, (int)PACK_LOT.SUB_IMAGE06].Value.ToString());

                ViewSubImageFile(s_sub_image_1, s_sub_image_2, s_sub_image_3, s_sub_image_4, s_sub_image_5, s_sub_image_6);

            }
        }

        private void cdvAnalyzer_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvAnalyzer.Init();
                MPCF.InitListView(cdvAnalyzer.GetListView);
                cdvAnalyzer.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvAnalyzer.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvAnalyzer.SelectedSubItemIndex = 0;
                cdvAnalyzer.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvAnalyzer.GetListView, '1', CSGC.CP_GCM_INSP_ANALYZER) == false)
                {
                    return;
                }

                cdvAnalyzer.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvAnalyzer_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            if (spdPackingLotList.ActiveSheet.ActiveRowIndex < 0)
                return;

            int iLotActiveRow = spdPackingLotList.ActiveSheet.ActiveRowIndex;


            spdPackingLotList.ActiveSheet.Cells[iLotActiveRow, (int)PACK_LOT.ANALYZER].Value = cdvAnalyzer.Text;
            spdPackingLotList.ActiveSheet.Cells[iLotActiveRow, (int)PACK_LOT.ANALYZER_DESC].Value = cdvAnalyzer.DisplayText;


        }

        private void txtRemarks_TextChanged(object sender, EventArgs e)
        {
            if (spdPackingLotList.ActiveSheet.ActiveRowIndex < 0)
                return;

            int iLotActiveRow = spdPackingLotList.ActiveSheet.ActiveRowIndex;

            spdPackingLotList.ActiveSheet.Cells[iLotActiveRow, (int)PACK_LOT.REMARKS].Value = txtRemarks.Text;
        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {

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

        private void spdPivotList_Change_1(object sender, ChangeEventArgs e)
        {
            int iRow = e.Row;
            int iCol = e.Column;

            SpecSearch(iRow, iCol);
        }

        private void SpecSearch(int iRow, int iCol)
        {

            if (iRow < 0)
            {
                return;
            }


            //  int iRow = e.Row;
            //    int iCol = e.Column;

            string dinputValue = "";
            string sLowwerValue = "";
            string sUpperValue = "";




            int i = spdPackingLotList.ActiveSheet.ActiveRowIndex;


            if (MPCF.CheckNumeric(spdPivotList.ActiveSheet.Cells[iRow, iCol].Text) == true)
            {
                dinputValue = spdPivotList.ActiveSheet.Cells[iRow, iCol].Text;

                switch (spdPivotList.ActiveSheet.Cells[iRow, (int)PIVOT_LIST.NAME].Text)
                {
                    case "WT%":
                        sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.WT_SPEC_MIN].Text;
                        sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.WT_SPEC_MAX].Text;
                        break;
                    case "MEAN":
                        sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.MEAN_SPEC_MIN].Text;
                        sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.MEAN_SPEC_MAX].Text;
                        break;
                    case "S.D.":
                        sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SD_SPEC_MIN].Text;
                        sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.SD_SPEC_MAX].Text;
                        break;
                    case "L.P.":
                        sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LP_SPEC_MIN].Text;
                        sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LP_SPEC_MAX].Text;
                        break;
                    case "D5":
                        sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC02_SPEC_MIN].Text;
                        sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC02_SPEC_MAX].Text;
                        break;
                    case "D50":
                        sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC05_SPEC_MIN].Text;
                        sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC05_SPEC_MAX].Text;
                        break;
                    case "D95":
                        sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC08_SPEC_MIN].Text;
                        sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC08_SPEC_MAX].Text;
                        break;

                    case "D10":
                        sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC03_SPEC_MIN].Text;
                        sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC03_SPEC_MAX].Text;
                        break;
                    case "D90":
                        sLowwerValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC07_SPEC_MIN].Text;
                        sUpperValue = spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.VOL_STATIC07_SPEC_MAX].Text;
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

        private void btnCustomerSpec_Click(object sender, EventArgs e)
        {
            try
            {
                if (spdPackingLotList.ActiveSheet.RowCount == 0)
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
    }
}
