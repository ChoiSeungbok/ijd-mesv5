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

namespace CUS_QCM
{
    public partial class frmTranShipReportRegistration_CTM : frmTranForm05
    {
        public frmTranShipReportRegistration_CTM()
        {
            InitializeComponent();

            InitControl();
        }
        #region " Constant Definition "
        private enum PACK_LOT
        {
            CHK,                     // 1 : CHECK
            PACK_ORDER_ID,
            PACK_LOT_ID,             // 2 : 포장 LOT ID
            ORG_LOT_ID,              // 3 : 공정 LOT ID

            OD_MIN_VAL,      // OUT-DIAMETER  MIN값  (최대직경)
            OD_MAX_VAL,     // OUT_DIAMETER MAX값   (최대직경)
            AT_MIN_VAL,       //  TOTAL THICKNESS (총두께)
            AT_MAX_VAL,       //  TOTAL THICKNESS (총두께)
            GT_MIN_VAL,      //UT
            GT_MAX_VAL,     //UT
            LEN_MIN_VAL01,  // 변길이1 MIN
            LEN_MAX_VAL01,  // 변길이1 MAX
            LEN_MIN_VAL02,  // 변길이2 MIN
            LEN_MAX_VAL02,  // 변길이2 MAX
            DMG_MIN_VAL,
            DMG_MAX_VAL,
            FIT_MIN_VAL,
            FIT_MAX_VAL,
            COMMENT
        }
        #endregion

        #region " Function Definition "
        private void InitControl()
        {
            try
            {


                //레지스트리로 사업부 고정한거 변경(베트남 음성 같이쓰는사람 문제됨) 21/07/06 
                if (MPGV.gsFactory == "IJDK1")
                {
                    cdvDept.Text = "CTM";
                    cdvDept.DisplayText = "CTM";
                }
                else
                {
                    cdvDept.Text = "CTV";
                    cdvDept.DisplayText = "CTM";
                }

                //이거 필요없음.
                //cdvDept.Text = CSGV.gs_area_ctm;

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
        private void ViewSpecInfo(string packOrderId, string packLineNo)
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

                if (TPDR.GetDataOne("", ref dt, "CQCM2100-001-01", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                MPCF.ClearList(spdPackingLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdPackingLotList_Sheet1.RowCount++;

                    spdPackingLotList_Sheet1.SetValue(i, (int)PACK_LOT.CHK, false);

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Value = dt.Rows[i]["PACK_LOT_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Value = dt.Rows[i]["ORG_LOT_ID"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.OD_MIN_VAL].Value = dt.Rows[i]["OD_MIN_VAL"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.OD_MAX_VAL].Value = dt.Rows[i]["OD_MAX_VAL"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.AT_MIN_VAL].Value = dt.Rows[i]["AT_MIN_VAL"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.AT_MAX_VAL].Value = dt.Rows[i]["AT_MAX_VAL"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.GT_MIN_VAL].Value = dt.Rows[i]["GT_MIN_VAL"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.GT_MAX_VAL].Value = dt.Rows[i]["GT_MAX_VAL"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.LEN_MIN_VAL01].Value = dt.Rows[i]["LEN_MIN_VAL01"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.LEN_MAX_VAL01].Value = dt.Rows[i]["LEN_MAX_VAL01"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.LEN_MIN_VAL02].Value = dt.Rows[i]["LEN_MIN_VAL02"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.LEN_MAX_VAL02].Value = dt.Rows[i]["LEN_MAX_VAL02"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.DMG_MIN_VAL].Value = dt.Rows[i]["DMG_MIN_VAL"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.DMG_MAX_VAL].Value = dt.Rows[i]["DMG_MAX_VAL"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.FIT_MIN_VAL].Value = dt.Rows[i]["FIT_MIN_VAL"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.FIT_MAX_VAL].Value = dt.Rows[i]["FIT_MAX_VAL"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.COMMENT].Value = dt.Rows[i]["COMMENTS"];



                    if (i == 0)
                    {
                        txtODStandard.Text = dt.Rows[i]["OD_STANDARD"].ToString();
                        txtODSpec.Text = dt.Rows[i]["OD_SPEC"].ToString();


                        txtATStandard.Text = dt.Rows[i]["AT_STANDARD"].ToString();
                        txtATSpec.Text = dt.Rows[i]["AT_SPEC"].ToString();

                        txtGTStandard.Text = dt.Rows[i]["GT_STANDARD"].ToString();
                        txtGTSpec.Text = dt.Rows[i]["GT_SPEC"].ToString();

                        txtLength1Standard.Text = dt.Rows[i]["LEN01_STANDARD"].ToString();
                        txtLength1Spec.Text = dt.Rows[i]["LEN01_SPEC"].ToString();

                        txtLength2Standard.Text = dt.Rows[i]["LEN02_STANDARD"].ToString();
                        txtLength2Spec.Text = dt.Rows[i]["LEN02_SPEC"].ToString();

                        txtDMGStandard.Text = dt.Rows[i]["DMG_STANDARD"].ToString();
                        txtDMGSpec.Text = dt.Rows[i]["DMG_SPEC"].ToString();

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
        private void initSpec()
        {
            txtODStandard.Text = "";
            txtODSpec.Text = "";

            txtATStandard.Text = "";
            txtATSpec.Text = "";

            txtGTStandard.Text = "";
            txtGTSpec.Text = "";

            txtLength1Standard.Text = "";
            txtLength1Spec.Text = "";

            txtLength2Standard.Text = "";
            txtLength2Spec.Text = "";

            txtDMGStandard.Text = "";
            txtDMGSpec.Text = "";
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

                if (TPDR.GetDataOne("", ref dt, "CQCM2100-001", dvcArgu, false, false, ref sSql) == false)
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
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Value = dt.Rows[i]["PACK_LOT_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Value = dt.Rows[i]["ORG_LOT_ID"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.OD_MIN_VAL].Value = dt.Rows[i]["OD_MIN_VAL"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.OD_MAX_VAL].Value = dt.Rows[i]["OD_MAX_VAL"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.AT_MIN_VAL].Value = dt.Rows[i]["AT_MIN_VAL"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.AT_MAX_VAL].Value = dt.Rows[i]["AT_MAX_VAL"];
                    
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.GT_MIN_VAL].Value = dt.Rows[i]["GT_MIN_VAL"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.GT_MAX_VAL].Value = dt.Rows[i]["GT_MAX_VAL"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.LEN_MIN_VAL01].Value = dt.Rows[i]["LEN_MIN_VAL01"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.LEN_MAX_VAL01].Value = dt.Rows[i]["LEN_MAX_VAL01"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.LEN_MIN_VAL02].Value = dt.Rows[i]["LEN_MIN_VAL02"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.LEN_MAX_VAL02].Value = dt.Rows[i]["LEN_MAX_VAL02"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.DMG_MIN_VAL].Value = dt.Rows[i]["DMG_MIN_VAL"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.DMG_MAX_VAL].Value = dt.Rows[i]["DMG_MAX_VAL"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.FIT_MIN_VAL].Value = dt.Rows[i]["FIT_MIN_VAL"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.FIT_MAX_VAL].Value = dt.Rows[i]["FIT_MAX_VAL"];

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.COMMENT].Value = dt.Rows[i]["COMMENTS"];


                }
                //MPCF.FitColumnHeader(spdPackingLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void ViewSpec(string packOrderId, string packLineNo)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "PACK_ORDER_ID";
                dvcArgu[1].sCondition_Value = packOrderId;

                dvcArgu[2].sCondition_ID = "PACK_LINE_NO";
                dvcArgu[2].sCondition_Value = packLineNo;

                if (TPDR.GetDataOne("", ref dt, "CQCM2100-001-01", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    initSpec();
                    return;
                }

                initSpec();


                txtODStandard.Text = dt.Rows[0]["OD_STANDARD"].ToString();
                txtODSpec.Text = dt.Rows[0]["OD_SPEC"].ToString();


                txtATStandard.Text = dt.Rows[0]["AT_STANDARD"].ToString();
                txtATSpec.Text = dt.Rows[0]["AT_SPEC"].ToString();

                txtGTStandard.Text = dt.Rows[0]["GT_STANDARD"].ToString();
                txtGTSpec.Text = dt.Rows[0]["GT_SPEC"].ToString();

                txtLength1Standard.Text = dt.Rows[0]["LEN01_STANDARD"].ToString();
                txtLength1Spec.Text = dt.Rows[0]["LEN01_SPEC"].ToString();

                txtLength2Standard.Text = dt.Rows[0]["LEN02_STANDARD"].ToString();
                txtLength2Spec.Text = dt.Rows[0]["LEN02_SPEC"].ToString();

                txtDMGStandard.Text = dt.Rows[0]["DMG_STANDARD"].ToString();
                txtDMGSpec.Text = dt.Rows[0]["DMG_SPEC"].ToString();


                /*
                txtFlatnessStandard.Text = dt.Rows[0]["FIT_STANDARD"].ToString();
                txtFlatnessSpec.Text = dt.Rows[0]["FIT_SPEC"].ToString();
                */

                //20240805 평탄도 고정요청
                txtFlatnessStandard.Text = "0";
                txtFlatnessSpec.Text = "±0.15";

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
                                                + "   AND DATA_2 = '" + CSGV.gs_area_ctm + "' ");
            

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
        private void fnviewReport(string sReportNo)
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



                if (TPDR.GetDataOne("", ref dt, "CQCM2100-002", dvcArgu, false, false, ref sSql) == false)
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
                        txtGrade.Text = dt.Rows[i]["GRADE"].ToString();
                        txtType.Text = dt.Rows[i]["TYPES"].ToString();
                        txtEndShipToName.Text = dt.Rows[i]["CUSTOMER_ID"].ToString();

                        txtODStandard.Text = dt.Rows[i]["OD_STANDARD"].ToString();
                        txtODSpec.Text = dt.Rows[i]["OD_SPEC"].ToString();

                        txtATStandard.Text = dt.Rows[i]["AT_STANDARD"].ToString();
                        txtATSpec.Text = dt.Rows[i]["AT_SPEC"].ToString();

                        txtGTStandard.Text = dt.Rows[i]["GT_STANDARD"].ToString();
                        txtGTSpec.Text = dt.Rows[i]["GT_SPEC"].ToString();

                        txtLength1Standard.Text = dt.Rows[i]["LEN01_STANDARD"].ToString();
                        txtLength1Spec.Text = dt.Rows[i]["LEN01_SPEC"].ToString();

                        txtLength2Standard.Text = dt.Rows[i]["LEN02_STANDARD"].ToString();
                        txtLength2Spec.Text = dt.Rows[i]["LEN02_SPEC"].ToString();

                        txtDMGStandard.Text = dt.Rows[i]["DMG_STANDARD"].ToString();
                        txtDMGSpec.Text = dt.Rows[i]["DMG_SPEC"].ToString();

                        /*
                       txtFlatnessStandard.Text = dt.Rows[i]["FIT_STANDARD"].ToString();
                       txtFlatnessSpec.Text = dt.Rows[i]["FIT_SPEC"].ToString();
                        */

                        //20240805 평탄도 고정요청
                        txtFlatnessStandard.Text = "0";
                        txtFlatnessSpec.Text = "±0.15";




                        txtComments.Text = dt.Rows[i]["COMMENTS"].ToString();
                    }


                    spdPackingLotList.ActiveSheet.SetValue(i, (int)PACK_LOT.CHK, false);
                    
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Value = dt.Rows[i]["PACK_LOT_ID"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Value = dt.Rows[i]["ORG_LOT_ID"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];

                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.OD_MIN_VAL].Value = dt.Rows[i]["OD_MIN_VAL"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.OD_MAX_VAL].Value = dt.Rows[i]["OD_MAX_VAL"];

                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.AT_MIN_VAL].Value = dt.Rows[i]["AT_MIN_VAL"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.AT_MAX_VAL].Value = dt.Rows[i]["AT_MAX_VAL"];

                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.GT_MIN_VAL].Value = dt.Rows[i]["GT_MIN_VAL"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.GT_MAX_VAL].Value = dt.Rows[i]["GT_MAX_VAL"];

                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LEN_MIN_VAL01].Value = dt.Rows[i]["LEN_MIN_VAL01"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LEN_MAX_VAL01].Value = dt.Rows[i]["LEN_MAX_VAL01"];

                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LEN_MIN_VAL02].Value = dt.Rows[i]["LEN_MIN_VAL02"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LEN_MAX_VAL02].Value = dt.Rows[i]["LEN_MAX_VAL02"];

                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.DMG_MIN_VAL].Value = dt.Rows[i]["DMG_MIN_VAL"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.DMG_MAX_VAL].Value = dt.Rows[i]["DMG_MAX_VAL"];

                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.FIT_MIN_VAL].Value = dt.Rows[i]["FIT_MIN_VAL"];
                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.FIT_MAX_VAL].Value = dt.Rows[i]["FIT_MAX_VAL"];

                    spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.COMMENT].Value = dt.Rows[i]["COMMENTS"].ToString();

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
                in_node.ProcStep = '1'; //CTM 발번
                in_node.AddString("AREA_ID", cdvDept.Text);


                for (int i = 0; i < spdPackingLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        data_list = in_node.AddNode("DATA_LIST");

                        data_list.AddString("PACK_LOT_ID", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text);
                        data_list.AddString("ORG_LOT_ID", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Text);
                        data_list.AddString("GRADE", MPCF.Trim(txtGrade.Text)); //추가필요
                        data_list.AddString("TYPES", MPCF.Trim(txtType.Text));  //추가필요
                        data_list.AddString("PACK_ORDER_ID", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_ORDER_ID].Text);
                        data_list.AddString("CUSTOMER_ID", MPCF.Trim(txtEndShipToName.Text));  //추가필요

                        data_list.AddString("OD_STANDARD", MPCF.Trim(txtODStandard.Text));  //추가필요
                        data_list.AddString("OD_SPEC", MPCF.Trim(txtODSpec.Text));  //추가필요
                        data_list.AddString("OD_MIN_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.OD_MIN_VAL].Text);
                        data_list.AddString("OD_MAX_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.OD_MAX_VAL].Text);

                        data_list.AddString("AT_STANDARD", MPCF.Trim(txtATStandard.Text));  //추가필요
                        data_list.AddString("AT_SPEC", MPCF.Trim(txtATSpec.Text));  //추가필요
                        data_list.AddString("AT_MIN_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.AT_MIN_VAL].Text);
                        data_list.AddString("AT_MAX_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.AT_MAX_VAL].Text);

                        data_list.AddString("GT_STANDARD", MPCF.Trim(txtGTStandard.Text));  //추가필요
                        data_list.AddString("GT_SPEC", MPCF.Trim(txtGTSpec.Text));  //추가필요
                        data_list.AddString("GT_MIN_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.GT_MIN_VAL].Text);
                        data_list.AddString("GT_MAX_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.GT_MAX_VAL].Text);

                        data_list.AddString("LEN01_STANDARD", MPCF.Trim(txtLength1Standard.Text));  //추가필요
                        data_list.AddString("LEN01_SPEC", MPCF.Trim(txtLength1Spec.Text));  //추가필요
                        data_list.AddString("LEN_MIN_VAL01", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LEN_MIN_VAL01].Text);
                        data_list.AddString("LEN_MAX_VAL01", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LEN_MAX_VAL01].Text);

                        data_list.AddString("LEN02_STANDARD", MPCF.Trim(txtLength2Standard.Text));  //추가필요
                        data_list.AddString("LEN02_SPEC", MPCF.Trim(txtLength2Spec.Text));  //추가필요
                        data_list.AddString("LEN_MIN_VAL02", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LEN_MIN_VAL02].Text);
                        data_list.AddString("LEN_MAX_VAL02", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LEN_MAX_VAL02].Text);

                        data_list.AddString("DMG_STANDARD", MPCF.Trim(txtDMGStandard.Text));  //추가필요
                        data_list.AddString("DMG_SPEC", MPCF.Trim(txtDMGSpec.Text));  //추가필요
                        data_list.AddString("DMG_MIN_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.DMG_MIN_VAL].Text);
                        data_list.AddString("DMG_MAX_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.DMG_MAX_VAL].Text);


                        data_list.AddString("FIT_STANDARD", MPCF.Trim(txtFlatnessStandard.Text));  //추가필요
                        data_list.AddString("FIT_SPEC", MPCF.Trim(txtFlatnessSpec.Text));  //추가필요
                        data_list.AddString("FIT_MIN_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.FIT_MIN_VAL].Text);
                        data_list.AddString("FIT_MAX_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.FIT_MAX_VAL].Text);



                        data_list.AddString("COMMENTS", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.COMMENT].Text);

                        ichk++;
                    }
                    
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


            TRSNode in_node = new TRSNode("SAVE_REPORT_IN");
            TRSNode out_node = new TRSNode("SAVE_REPORT_OUT");
            TRSNode data_list;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1'; // CTM 성적서 저장

                in_node.AddString("REPORT_NO", cdvReportNo.Text);
                

                for (int i = 0; i < spdPackingLotList.ActiveSheet.RowCount; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");

                    data_list.AddString("PACK_LOT_ID", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text);
                    data_list.AddString("ORG_LOT_ID", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Text);
                    data_list.AddString("GRADE", MPCF.Trim(txtGrade.Text));  //Grade
                    data_list.AddString("TYPES", MPCF.Trim(txtType.Text));   //Type
                    data_list.AddString("PACK_ORDER_ID", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PACK_ORDER_ID].Text);
                    data_list.AddString("CUSTOMER_ID", MPCF.Trim(txtEndShipToName.Text));  //Customer

                    data_list.AddString("OD_STANDARD", MPCF.Trim(txtODStandard.Text));  
                    data_list.AddString("OD_SPEC", MPCF.Trim(txtODSpec.Text));  
                    data_list.AddString("OD_MIN_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.OD_MIN_VAL].Text);
                    data_list.AddString("OD_MAX_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.OD_MAX_VAL].Text);

                    data_list.AddString("AT_STANDARD", MPCF.Trim(txtATStandard.Text));  
                    data_list.AddString("AT_SPEC", MPCF.Trim(txtATSpec.Text));  
                    data_list.AddString("AT_MIN_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.AT_MIN_VAL].Text);
                    data_list.AddString("AT_MAX_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.AT_MAX_VAL].Text);

                    data_list.AddString("GT_STANDARD", MPCF.Trim(txtGTStandard.Text));  
                    data_list.AddString("GT_SPEC", MPCF.Trim(txtGTSpec.Text));  
                    data_list.AddString("GT_MIN_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.GT_MIN_VAL].Text);
                    data_list.AddString("GT_MAX_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.GT_MAX_VAL].Text);

                    data_list.AddString("LEN01_STANDARD", MPCF.Trim(txtLength1Standard.Text)); 
                    data_list.AddString("LEN01_SPEC", MPCF.Trim(txtLength1Spec.Text)); 
                    data_list.AddString("LEN_MIN_VAL01", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LEN_MIN_VAL01].Text);
                    data_list.AddString("LEN_MAX_VAL01", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LEN_MAX_VAL01].Text);

                    data_list.AddString("LEN02_STANDARD", MPCF.Trim(txtLength2Standard.Text)); 
                    data_list.AddString("LEN02_SPEC", MPCF.Trim(txtLength2Spec.Text));  
                    data_list.AddString("LEN_MIN_VAL02", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LEN_MIN_VAL02].Text);
                    data_list.AddString("LEN_MAX_VAL02", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.LEN_MAX_VAL02].Text);

                    data_list.AddString("DMG_STANDARD", MPCF.Trim(txtDMGStandard.Text));  
                    data_list.AddString("DMG_SPEC", MPCF.Trim(txtDMGSpec.Text)); 
                    data_list.AddString("DMG_MIN_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.DMG_MIN_VAL].Text);
                    data_list.AddString("DMG_MAX_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.DMG_MAX_VAL].Text);

                    data_list.AddString("FIT_STANDARD", MPCF.Trim(txtDMGStandard.Text));
                    data_list.AddString("FIT_SPEC", MPCF.Trim(txtDMGSpec.Text));
                    data_list.AddString("FIT_MIN_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.DMG_MIN_VAL].Text);
                    data_list.AddString("FIT_MAX_VAL", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.DMG_MAX_VAL].Text);



                    data_list.AddString("COMMENTS", spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.COMMENT].Value);


                }
                
                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Save_Report", in_node, ref out_node, false) == false)
                {
                    return false;
                }
                else
                {
                    MPCR.ShowSuccessMsg(out_node);
                }


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

                dvcArgu[2].sCondition_ID = "USER_NAME";
                dvcArgu[2].sCondition_Value = txtPrintUser.Text;

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
            fnviewReport(cdvReportNo.Text);

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


                        if (MPCF.Trim(cdvPackOrderNo.Text) != "")
                        {
                            //Spec정보, Data 조회 분리


                            //Spec정보 조회
                            ViewSpec(cdvPackOrderNo.Text, txtLineNo.Text);

                            //Data 조회
                            ViewPackingLotList(cdvPackOrderNo.Text, txtLineNo.Text);
                        }

                        cdvReportNo.Text = "";
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
        private void mcCodeView1_ButtonPress(object sender, EventArgs e)
        {
            

        }
        private void btnPrint_Click(object sender, EventArgs e)
        {
            //성적서 바인딩확인
            if (CheckCondition("PRINT") == false)
            {
                return;
            }

            if (cdvShipReportType.Text == "CTM_01") //일반
            {
                fnPrintShipReport("CQCM2100-004", "pip510p");    
            }
            else if (cdvShipReportType.Text == "CTM_02") //절단
            {
                fnPrintShipReport("CQCM2100-005", "pip511p");
            }
            else if (cdvShipReportType.Text == "CTM_03") //MAPAL
            {
                fnPrintShipReport("CQCM2100-006", "pip512p");
            }
            else if (cdvShipReportType.Text == "CTM_04") //상해이화
            {
                fnPrintShipReport("CQCM2100-007", "pip513p");
            }
            else if (cdvShipReportType.Text == "CTM_05") //TUNGALOY(일반)
            {
                fnPrintShipReport("CQCM2100-008", "pip514p");
            }
            else if (cdvShipReportType.Text == "CTM_06") //TUNGALOY (절단)
            {
                fnPrintShipReport("CQCM2100-009", "pip515p");
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
                            // 성적서 조회
                            fnviewReport(cdvReportNo.Text);
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
        private void frmTranShipReportRegistration_CTM_Load(object sender, EventArgs e)
        {
            fnGetUserDesc();
        }
        private void spdPackingLotList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                {
                    if (spdPackingLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdPackingLotList, e.Row, e.Column, true, true, false);
                    }
                }
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdPackingLotList, e.Row);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message); 
            }
        }

        #endregion
    }
}
