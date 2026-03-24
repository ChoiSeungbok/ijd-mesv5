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

using System.Threading;
using System.Collections;
using FarPoint.Win.Spread.Model;
using System.IO;
using System.IO.Ports;
using FarPoint.Excel.EntityClassLibrary.DrawingML;
using DevExpress.XtraRichEdit.Commands.Internal;
using DevExpress.Entity.Model.Metadata;
using System.Net.Http;
using System.Diagnostics;
using System.Runtime.Remoting.Metadata.W3cXsd2001;
using FarPoint.Win.Spread.CellType;
using Miracom.UI;

namespace CUS_QCM
{
    public partial class frmTranInspectionRegistration : CUS_COM.frmTranForm06
    {

        #region " Variable Definition "
        public frmTranInspectionRegistration()
        {
            InitializeComponent();

            InitControl();
        }

        string sJudgeCodeMaintain = "";
        string sCommentMaintain = "";
        Hashtable hashJudgeList;


        private const int DEFAULT_COL_COUNT = 17;
        private clsDerivedCharList cls_derived_char_list;

        private const int MAX_DATA_COUNT = 5000;

        DefaultSheetDataModel defModelData;
        DefaultSheetDataModel defModelDataLoss;

        bool b_allow_changed;

        double d_real_d_ref;

        int iRowHBAD997;


        public delegate void ReceivedHandler(string sText);
        ReceivedHandler rh_Sanner;


        #endregion

        #region " Constant Definition "
        private enum LOT_INFO
        {
            LOT_ID,                 // 1 : LOT ID
            MAT_ID,                 // 2 : 제품코드
            MAT_DESC,               // 3 : 제품명         
            FLOW,
            CREATE_DATE,            // 4 : 생성일자   
            INSP_QTY,                       // 5 : 요청수량
            UNIT_1,
            ORDER_ID                  // 작업지시

        }

        private enum COLLECTION_DATA
        {
            CHAR_COL,
            CHAR_DESC_COL,
            CHAR_SEQ,
            LOWER_SPEC_LIMIT,
            TARGET_VALUE,
            UPPER_SPEC_LIMIT,
            SPEC_COL,
            OPT_INPUT_COL,
            VALUE_TYPE_COL,
            VALUE_COUNT_COL,
            DEF_UNIT_FLAG_COL,
            DEF_UNIT_OVR_FLAG_COL,
            DEF_VALUE_COL,
            UNIT_TBL_COL,
            VALUE_TBL_COL,
            UNIT_SEQ_COL,
            UNIT_COL,
            VALUE_START_COL
        }

        private enum FILEUPLOAD
        {
            FILE_NO,               // 1 : 파일번호 
            TITLE,                   // 2 파일타이틀
            NAME,                  //  3. 이미지 SEQ 이름
            REGIST,                 // 4. 파일 등록
            DELETE                // 5. 파일 삭제

        }

        private enum LOSS_INFO
        {
            LOSS_CODE,
            LOSS_DESC,
            HM_INPUT_QTY,
            LOSS_QTY,
            ADD_BUTTON,
            MAIN_YN
        }

        private enum WORKER_INFO
        {
            WORKER_ID,                 // 1 : 이름
            WORKER_DESC,               // 2 : 사번
            WORK_TYPE         // 3: 타입
        }



        private enum COLLECTION_DATA_ASPECT
        {
            INSP_SEQ,    // INSP_SEQ
            QC_NAME,    // 명칭
            SPEC_VAL,
            VAL_1,          //MEAN
            VAL_2,          //D10
            VAL_3,          //D25
            VAL_4,          //D50
            VAL_5,          //D75
            VAL_6,          //D90
        }

        #endregion

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnJudge.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnHold.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnGCM.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                btnSpec.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                lblLastSpecTime.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                txtLastSpecTime.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                brnReturn.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnColSetId.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnFileManager.Visible = true;
                btnFileManager.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                AllowDrop = true;
                chkAutoRefresh.Checked = false;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ClearList(string sType)
        {
            switch (sType)
            {
                case "LOT_INFO":
                    MPCF.FieldClear(panLotInfo, txtLotID);
                    MPCF.ClearList(spdLotList);
                    MPCF.FieldClear(panJudgeResult, chkJudgeMaintain, chkCommentMaintain);
                    MPCF.FieldClear(panFileRegistration);
                    MPCF.ClearList(spdFileRegistration);
                    MPCF.FieldClear(panDataCollection);
                    MPCF.ClearList(spdDataCollection);
                    break;
                case "COL_SET_CHANGED":
                    MPCF.ClearList(spdDataCollection);
                    txtColSetVer.Text = "";
                    spdDataCollection.ActiveSheet.ColumnCount = 17;
                    break;
                case "COPY_LOT_INFO":
                    MPCF.ClearList(spdDataCollection);
                    break;
            }
        }

        public void ViewLotInfo(string sLot_ID)
        {
            try
            {
                if (!ViewColsetIdCheck(sLot_ID))
                {
                    return;
                }
                AutoScroll = true;
                b_allow_changed = false;
                TRSNode tRSNode = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                MPCR.SetInMsg(tRSNode);
                MPCF.ClearList(spdLotList);
                hashJudgeList = new Hashtable();
                tRSNode.ProcStep = '1';
                tRSNode.AddString("LOT_ID", sLot_ID);
                tRSNode.AddString("AREA_ID", cdvDept.Text);
                tRSNode.AddString("OPER", cdvOper.Text);
                tRSNode.AddString("INSP_TYPE", cdvInspectionType.Text);
                if (!MPCR.CallService("CUS_QCM", "CUS_QCM_View_Lot_Info", tRSNode, ref out_node))
                {
                    return;
                }
                spdLotList.ActiveSheet.RowCount++;
                spdLotList.ActiveSheet.SetValue(0, 0, out_node.GetString("LOT_ID"));
                spdLotList.ActiveSheet.SetValue(0, 1, out_node.GetString("MAT_ID"));
                spdLotList.ActiveSheet.SetValue(0, 2, out_node.GetString("MAT_DESC"));
                spdLotList.ActiveSheet.SetValue(0, 3, out_node.GetString("FLOW"));
                spdLotList.ActiveSheet.SetValue(0, 4, out_node.GetString("CREATE_TIME"));
                spdLotList.ActiveSheet.SetValue(0, 5, out_node.GetDouble("INSP_QTY"));
                spdLotList.ActiveSheet.SetValue(0, 6, out_node.GetString("UNIT_1"));
                spdLotList.ActiveSheet.SetValue(0, 7, out_node.GetString("ORDER_ID"));
                MPCF.FitColumnHeader(spdLotList);
                d_real_d_ref = out_node.GetDouble("REAL_D_REF");
                txtMatID.Text = out_node.GetString("MAT_ID");
                txtMatDesc.Text = out_node.GetString("MAT_DESC");
                txtMatVer.Text = Convert.ToString(out_node.GetInt("MAT_VER"));
                txtInspID.Text = out_node.GetString("INSP_ID");
                cdvInspOper.Text = out_node.GetString("INSP_OPER");
                cdvInspOper.DisplayText = out_node.GetString("INSP_OPER_DESC");
                cdvDept.Text = out_node.GetString("AREA_ID");
                cdvDept.DisplayText = out_node.GetString("AREA_DESC");
                txtInspectionStatus.Text = out_node.GetChar("INSP_STATUS").ToString();
                txtInspectionStatusDesc.Text = out_node.GetString("INSP_STATUS_DESC").ToString();
                cdvInspectionJudgeFlag.Text = out_node.GetChar("INSP_JUDGE_FLAG").ToString();
                cdvInspectionJudgeFlag.DisplayText = out_node.GetString("INSP_JUDGE_DESC");
                cdvInspectionJudgeChange.Text = out_node.GetChar("INSP_JUDGE_FLAG").ToString();
                cdvInspectionJudgeChange.DisplayText = out_node.GetString("INSP_JUDGE_DESC");
                cdvReworkOper.Text = out_node.GetString("RWK_OPER");
                cdvReworkOper.DisplayText = out_node.GetString("RWK_OPER_DESC");
                txtComment.Text = out_node.GetString("INSP_COMMENT");
                cdvColSetID.Text = out_node.GetString("COL_SET_ID");
                cdvColSetID.DisplayText = out_node.GetString("COL_SET_DESC");
                txtChangeRatio.Text = out_node.GetString("MAT_CMF_6");
                if (out_node.GetString("MAT_GRP_1") == "HM")
                {
                    panLotInfo.Visible = true;
                    spdLossInfo.ActiveSheet.Columns[2].Visible = true;
                }
                else
                {
                    panLotInfo.Visible = false;
                    spdLossInfo.ActiveSheet.Columns[2].Visible = false;
                }
                GetJudgeFlagByArea(cdvInspectionJudgeFlag.GetListView, cdvInspOper.Text, cdvInspectionType.Text);
                cdvInspectionJudgeFlag.InsertEmptyRow(0, 1);
                GetJudgeChangeByArea(cdvInspectionJudgeChange.GetListView, cdvInspOper.Text, cdvInspectionType.Text);
                cdvInspectionJudgeChange.InsertEmptyRow(0, 1);
                if (txtInspectionStatus.Text != "S")
                {
                    if (sJudgeCodeMaintain != "" && hashJudgeList.Contains(sJudgeCodeMaintain))
                    {
                        cdvInspectionJudgeFlag.Text = sJudgeCodeMaintain;
                        cdvInspectionJudgeFlag.DisplayText = hashJudgeList[sJudgeCodeMaintain].ToString();
                        cdvInspectionJudgeChange.Visible = false;
                        lblJudgeChange.Visible = false;
                        btnInspectionJudgeChange.Visible = false;
                    }
                    if (sCommentMaintain != "")
                    {
                        txtComment.Text = sCommentMaintain;
                    }
                }
                else if (cdvDept.Text == CSGV.gs_area_ctm)
                {
                    cdvInspectionJudgeChange.Visible = false;
                    lblJudgeChange.Visible = false;
                    btnInspectionJudgeChange.Visible = false;
                }
                else
                {
                    cdvInspectionJudgeChange.Visible = false;
                    lblJudgeChange.Visible = false;
                    btnInspectionJudgeChange.Visible = false;
                }
                initReworkOperList(cdvReworkOper.GetListView);
                ViewInspectionFile(txtInspID.Text);
                ViewInspectionLossInfo(txtInspID.Text, cdvInspOper.Text);
                ViewPathData();
                ViewWorkerList();
                SelectedItemChangedByColSet();
                if (out_node.GetString("MAT_GRP_1") == "HM")
                {
                    Sumtotalqty("SEARCH");
                }
                ViewSpecLastEditTime(txtMatID.Text, cdvInspOper.Text);
                b_allow_changed = true;
                if (cdvDept.Text == "GRT")
                {
                    ViewInspectionGritISP(txtInspID.Text);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private async System.Threading.Tasks.Task<bool> FileExistsOnWeb(string url)
        {
            try
            {
                using (HttpClient client = new HttpClient())
                {
                    // HTTP 요청을 보낸 후 파일이 있는지 확인
                    var response = await client.GetAsync(url);
                    return response.IsSuccessStatusCode; // 상태 코드 200 OK인 경우 true
                }
            }
            catch
            {
                return false; // 예외 발생 시 파일이 없는 것으로 간주
            }
        }

        private async void ViewPathData()
        {
            try
            {
                if (txtMatID.Text == "")
                {
                    return;
                }
                TRSNode in_node = new TRSNode("SQL_IN");
                TRSNode out_node = new TRSNode("SQL_OUT");
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("SQL", "SELECT  KEY_1 AS CODE_DATA,        DATA_1 || DATA_2  AS VALUE_DATA,    (SELECT RECIPE_NO FROM CWIPRCPDEF WHERE FACTORY ='" + MPGV.gsFactory + "' AND AREA_ID = '" + cdvDept.Text + "' AND MAT_ID = '" + txtMatID.Text + "'  AND OPER = '" + cdvOper.Text + "' ) AS RECIPE_NO  FROM MGCMTBLDAT A    WHERE FACTORY = '" + MPGV.gsFactory + "'    AND TABLE_NAME = 'C_INSP_ROUND_PATH' ");
                if (!MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) || out_node.GetList("ROWS").Count <= 0)
                {
                    return;
                }
                for (int i = 0; i < out_node.GetList("ROWS").Count; i++)
                {
                    string text = out_node.GetList("ROWS")[i].GetList("COLS")[0].GetString("DATA");
                    string text2 = text;
                    string text3 = text2;
                    if (!(text3 == "DRAWING_FILE PATH"))
                    {
                        if (text3 == "ROUND_AUTO_MACHINE")
                        {
                            txtRdIfPath.Text = out_node.GetList("ROWS")[i].GetList("COLS")[1].GetString("DATA");
                            txtRdIfRecipe.Text = out_node.GetList("ROWS")[i].GetList("COLS")[2].GetString("DATA");
                        }
                        continue;
                    }
                    BrwDrawing.Navigate("about:blank");
                    string sfilePath = out_node.GetList("ROWS")[i].GetList("COLS")[1].GetString("DATA") + "/" + MPCF.Trim(txtMatID.Text) + ".PDF";
                    txtDrawingPath.Text = out_node.GetList("ROWS")[i].GetList("COLS")[1].GetString("DATA") + "/" + MPCF.Trim(txtMatID.Text) + ".PDF";
                    if (await FileExistsOnWeb(sfilePath))
                    {
                        BrwDrawing.Navigate(sfilePath);
                    }
                    else
                    {
                        BrwDrawing.DocumentText = "";
                    }
                }
            }
            catch (Exception ex)
            {
                Exception ex2 = ex;
                MPCF.ShowMsgBox(ex2.Message);
            }
        }

        private bool initReworkOperList(ListView listView)
        {
            TRSNode tRSNode = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            MPCF.InitListView(listView);
            MPCR.SetInMsg(tRSNode);
            tRSNode.ProcStep = '1';
            string text = spdLotList.ActiveSheet.Cells[0, 3].Value.ToString();
            tRSNode.AddString("SQL", "SELECT A.OPER AS CODE,            B.OPER_DESC AS OPER_DESC          FROM MWIPFLWOPR A INNER JOIN MWIPOPRDEF B                                    ON A.FACTORY = B.FACTORY                                   AND A.OPER = B.OPER        WHERE A.FACTORY = '" + MPGV.gsFactory + "'           AND A.FLOW = '" + text + "'           AND A.SEQ_NUM < (SELECT SEQ_NUM FROM MWIPFLWOPR                            WHERE FACTORY = '" + MPGV.gsFactory + "'                              AND FLOW = '" + text + "'                              AND OPER = '" + MPCF.Trim(cdvInspOper.Text) + "'                            )        ORDER BY SEQ_NUM");
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

        private bool viewOperList(ListView listView)
        {
            TRSNode tRSNode = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            MPCF.InitListView(listView);
            MPCR.SetInMsg(tRSNode);
            tRSNode.ProcStep = '1';
            tRSNode.AddString("SQL", "SELECT OPER AS CODE,                OPER_DESC AS NAME          FROM MWIPOPRDEF         WHERE AREA_ID = '" + cdvDept.Text + "'           AND OPER_GRP_2 <> 'NONE'          AND OPER_GRP_2 > ' '         ORDER BY OPER");
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

        private bool GetJudgeFlagByArea(ListView listView, string insp_oper, string insp_type)
        {
            TRSNode tRSNode = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            string text = "";
            string text2 = "";
            MPCF.InitListView(listView);
            MPCR.SetInMsg(tRSNode);
            tRSNode.ProcStep = '1';
            tRSNode.AddString("SQL", "SELECT KEY_2 AS CODE,        DATA_1 AS VALUE   FROM MGCMTBLDAT A   WHERE FACTORY = '" + MPGV.gsFactory + "'    AND TABLE_NAME = 'C_INSP_JUDGE'    AND KEY_1 = '" + insp_oper + "' ORDER BY DATA_2");
            do
            {
                if (!MPCR.CallService("BAS", "BAS_SQL_Query", tRSNode, ref out_node))
                {
                    return false;
                }
                if (out_node.GetList("ROWS").Count > 0)
                {
                    for (int i = 0; i < out_node.GetList("ROWS").Count; i++)
                    {
                        text = out_node.GetList("ROWS")[i].GetList("COLS")[0].GetString("DATA");
                        text2 = out_node.GetList("ROWS")[i].GetList("COLS")[1].GetString("DATA");
                        hashJudgeList.Add(text, text2);
                    }
                }
                MPCR.FillDataView(listView, out_node);
                tRSNode.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            }
            while (out_node.GetInt("NEXT_ROW") > 0);
            return true;
        }

        private bool GetJudgeChangeByArea(ListView listView, string insp_oper, string insp_type)
        {
            TRSNode tRSNode = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            string text = "";
            string text2 = "";
            MPCF.InitListView(listView);
            MPCR.SetInMsg(tRSNode);
            tRSNode.ProcStep = '1';
            tRSNode.AddString("SQL", "SELECT KEY_2 AS CODE,        DATA_1 AS VALUE   FROM MGCMTBLDAT A   WHERE FACTORY = '" + MPGV.gsFactory + "'    AND TABLE_NAME = 'C_INSP_JUDGE'    AND KEY_1 = '" + insp_oper + "' ORDER BY DATA_2");
            do
            {
                if (!MPCR.CallService("BAS", "BAS_SQL_Query", tRSNode, ref out_node))
                {
                    return false;
                }
                if (out_node.GetList("ROWS").Count > 0)
                {
                    for (int i = 0; i < out_node.GetList("ROWS").Count; i++)
                    {
                        text = out_node.GetList("ROWS")[i].GetList("COLS")[0].GetString("DATA");
                        text2 = out_node.GetList("ROWS")[i].GetList("COLS")[1].GetString("DATA");
                    }
                }
                MPCR.FillDataView(listView, out_node);
                tRSNode.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            }
            while (out_node.GetInt("NEXT_ROW") > 0);
            return true;
        }

        private void ViewInspectionFile(string inspID)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "INSP_ID";
                array[1].sCondition_Value = inspID;
                if (!TPDR.GetDataOne("", ref dt, "CQCM2001-002", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdFileRegistration);
                    return;
                }
                MPCF.ClearList(spdFileRegistration);
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdFileRegistration.ActiveSheet.RowCount++;
                    spdFileRegistration.ActiveSheet.Cells[num, 0].Value = dt.Rows[num]["FILE_NO"];
                    spdFileRegistration.ActiveSheet.Cells[num, 1].Value = dt.Rows[num]["TITLE"];
                    spdFileRegistration.ActiveSheet.Cells[num, 2].Value = dt.Rows[num]["NAME"];
                    if (cdvOper.Text == "OC06020" && dt.Rows[num]["TITLE"].ToString() == "DRAWING")
                    {
                        spdFileRegistration.ActiveSheet.Columns[3].Visible = false;
                        spdFileRegistration.ActiveSheet.Columns[4].Visible = false;
                    }
                    else
                    {
                        spdFileRegistration.ActiveSheet.Columns[3].Visible = true;
                        spdFileRegistration.ActiveSheet.Columns[4].Visible = true;
                    }
                }
                MPCF.FitColumnHeader(spdFileRegistration);
                pictureBox1.Image = null;
                spdFileRegistration.ActiveSheet.ActiveRowIndex = 0;
                fnFileSelectionChagned();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewInspectionLossInfo(string inspID, string oper)
        {
            try
            {
                b_allow_changed = false;
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "INSP_ID";
                array[1].sCondition_Value = inspID;
                array[2].sCondition_ID = "OPER";
                array[2].sCondition_Value = oper;
                if (!TPDR.GetDataOne("", ref dt, "CQCM2001-003", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdLossInfo);
                    return;
                }
                MPCF.ClearList(spdLossInfo);
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdLossInfo.ActiveSheet.RowCount++;
                    spdLossInfo.ActiveSheet.Cells[num, 0].Value = dt.Rows[num]["LOSS_CODE"];
                    spdLossInfo.ActiveSheet.Cells[num, 1].Value = dt.Rows[num]["LOSS_DESC"];
                    spdLossInfo.ActiveSheet.Cells[num, 2].Text = (MPCF.ToDbl(dt.Rows[num]["HM_INPUT_QTY"].ToString()) / MPCF.ToDbl(txtChangeRatio.Text)).ToString();
                    spdLossInfo.ActiveSheet.Cells[num, 3].Value = dt.Rows[num]["LOSS_QTY"];
                    spdLossInfo.ActiveSheet.Cells[num, 5].Value = dt.Rows[num]["MAIN_YN"].ToString() == "Y";
                    if (spdLossInfo.ActiveSheet.Cells[num, 0].Text == "HBAD997")
                    {
                        iRowHBAD997 = num;
                    }
                }
                MPCF.FitColumnHeader(spdLossInfo);
                b_allow_changed = true;
            }
            catch (Exception ex)
            {
                b_allow_changed = true;
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void fnLotKeyPress()
        {
            if (!(MPCF.Trim(txtLotID.Text) == ""))
            {
                txtLotID.Text = MPCF.Trim(txtLotID.Text).ToUpper();
                if (CheckCondition(CSGC.CHECK.VIEW))
                {
                    ClearList("LOT_INFO");
                    ViewLotInfo(txtLotID.Text);
                }
            }
        }

        private void FindColSetVersion(string sColSetID, string sLotID, string sMatID, int iMatVer, string sOper)
        {
            try
            {
                TRSNode tRSNode = new TRSNode("FIND_COL_SET_VERSION_IN");
                TRSNode out_node = new TRSNode("FIND_COL_SET_VERSION_OUT");
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("MAT_ID", sMatID);
                tRSNode.AddInt("MAT_VER", iMatVer);
                tRSNode.AddString("OPER", sOper);
                tRSNode.AddString("EVENT_ID", "");
                tRSNode.AddString("COL_SET_ID", sColSetID);
                tRSNode.AddChar("LOT_OR_RES_FLAG", 'L');
                if (MPCR.CallService("EDC", "EDC_Find_Col_Set_Version", tRSNode, ref out_node, b_ignore_message: false))
                {
                    txtColSetVer.Text = out_node.GetInt("COL_SET_VERSION").ToString();
                    cls_derived_char_list = new clsDerivedCharList();
                    cls_derived_char_list.GetDerivedInfo(sColSetID, Convert.ToInt32(txtColSetVer.Text), sLotID, "", "", "");
                    if (ViewCharacterList(spdDataCollection, '5', sColSetID, Convert.ToInt32(txtColSetVer.Text), 'Y', cls_derived_char_list, sLotID, sMatID, iMatVer, sOper) && !ViewInspData2())
                    {
                        CSCF.ClearSpread(spdDataCollection, 0, 17, "");
                    }
                }
            }
            catch
            {
            }
        }

        private bool ViewInspData2()
        {
            int num = 0;
            int row = 0;
            try
            {
                TRSNode tRSNode = new TRSNode("view_lot_data_In");
                TRSNode out_node = new TRSNode("view_lot_data_Out");
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("INSP_ID", txtInspID.Text);
                tRSNode.AddString("COL_SET_ID", cdvColSetID.Text);
                tRSNode.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[0, 0].Value.ToString());
                if (!MPCR.CallService("CUS_QCM", "CUS_QCM_View_Lot_Inspection_Data", tRSNode, ref out_node))
                {
                    return false;
                }
                for (int i = 0; i < out_node.GetList(0).Count; i++)
                {
                    for (int j = 0; j < spdDataCollection.ActiveSheet.RowCount; j++)
                    {
                        if (spdDataCollection.ActiveSheet.Cells[j, 0].Text == out_node.GetList(0)[i].GetString("CHAR_ID") && spdDataCollection.ActiveSheet.Cells[j, 15].Text == out_node.GetList(0)[i].GetInt("UNIT_SEQ").ToString())
                        {
                            row = j;
                            break;
                        }
                    }
                    num = out_node.GetList(0)[i].GetInt("VALUE_COUNT");
                    if (num > 25)
                    {
                        num = 25;
                    }
                    for (int k = 1; k <= num; k++)
                    {
                        string name = "VALUE_" + k;
                        if (out_node.GetList(0)[i].GetChar("VALUE_TYPE") == 'N')
                        {
                            if (out_node.GetList(0)[i].GetString(name) != "")
                            {
                                spdDataCollection.ActiveSheet.Cells[row, 17 + (k - 1)].Value = out_node.GetList(0)[i].GetString(name);
                            }
                        }
                        else
                        {
                            spdDataCollection.ActiveSheet.Cells[row, 17 + (k - 1)].Value = out_node.GetList(0)[i].GetString(name);
                        }
                    }
                }
                ApplyColorBySpecOut();
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void ApplyColorBySpecOut()
        {
            if (spdDataCollection.ActiveSheet.RowCount < 1)
            {
                return;
            }
            try
            {
                for (int i = 0; i < spdDataCollection.ActiveSheet.RowCount; i++)
                {
                    for (int j = 17; j < spdDataCollection.ActiveSheet.ColumnCount; j++)
                    {
                        bool flag = false;
                        if (!(spdDataCollection.ActiveSheet.Cells[i, 8].Value.ToString() == "N"))
                        {
                            continue;
                        }
                        if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[i, j].Value))
                        {
                            if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[i, 3].Value) && MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[i, j].Value) < MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[i, 3].Value))
                            {
                                flag = true;
                            }
                            if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[i, 5].Value) && MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[i, j].Value) > MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[i, 5].Value))
                            {
                                flag = true;
                            }
                            if (flag)
                            {
                                spdDataCollection.ActiveSheet.Cells[i, j].BackColor = Color.Red;
                            }
                            else
                            {
                                spdDataCollection.ActiveSheet.Cells[i, j].BackColor = Color.White;
                            }
                        }
                        else
                        {
                            spdDataCollection.ActiveSheet.Cells[i, j].BackColor = Color.White;
                        }
                    }
                }
                minmaxdata();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewInspSpec(string sCharid, ref string sTartet, ref string sUpper, ref string sLower)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "MAT_ID";
                array[1].sCondition_Value = txtMatID.Text;
                array[2].sCondition_ID = "OPER";
                array[2].sCondition_Value = cdvInspOper.Text;
                array[3].sCondition_ID = "CHAR_ID";
                array[3].sCondition_Value = sCharid;
                if (!TPDR.GetDataOne("", ref dt, "CQCM2001-007", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                }
                else
                {
                    sTartet = dt.Rows[0]["CUST_TARGET_VALUE"].ToString();
                    sUpper = dt.Rows[0]["CUST_UPPER_SPEC_LIMIT"].ToString();
                    sLower = dt.Rows[0]["CUST_LOWER_SPEC_LIMIT"].ToString();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        public bool ViewCharacterList(Control control, char ProcStep, string ColSetID, int ColSetVersion, char cIncludeUnitID, clsDerivedCharList cls_derived_char_list, string LotID, string sMatID, int iMatVer, string sOper)
        {
            int num = 0;
            int num2 = 0;
            int num3 = 0;
            int num4 = 0;
            int num5 = 0;
            int num6 = 0;
            ComboBoxCellType comboBoxCellType = null;
            ComboBoxCellType comboBoxCellType2 = null;
            TRSNode tRSNode = new TRSNode("VIEW_ATTACH_CHARACTER_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_ATTACH_CHARACTER_LIST_OUT");
            try
            {
                spdDataCollection.SuspendLayout();
                spdDataCollection.ActiveSheet.RowCount = 0;
                spdDataCollection.ActiveSheet.ColumnCount = 17;
                spdDataCollection.ResumeLayout();
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = ProcStep;
                tRSNode.AddChar("INCLUDE_UNIT_ID", cIncludeUnitID);
                tRSNode.AddString("COL_SET_ID", ColSetID);
                tRSNode.AddInt("COL_SET_VERSION", ColSetVersion);
                tRSNode.AddString("MAT_ID", sMatID);
                tRSNode.AddInt("MAT_VER", iMatVer);
                tRSNode.AddString("OPER", sOper);
                do
                {
                    if (!MPCR.CallService("EDC", "EDC_View_Attach_Character_List", tRSNode, ref out_node))
                    {
                        return false;
                    }
                    for (int i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        num6 = 0;
                        num3 = out_node.GetList(0)[i].GetInt("VALUE_COUNT");
                        num6 = ((num3 <= 0) ? 17 : (17 + num3));
                        if (num6 > num5)
                        {
                            num5 = num6;
                        }
                    }
                    for (int i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        SheetView activeSheet = spdDataCollection.ActiveSheet;
                        num = activeSheet.RowCount - 1;
                        num2 = out_node.GetList(0)[i].GetInt("UNIT_COUNT");
                        num3 = out_node.GetList(0)[i].GetInt("VALUE_COUNT");
                        comboBoxCellType = null;
                        comboBoxCellType2 = null;
                        string sTartet = null;
                        string sUpper = null;
                        string sLower = null;
                        activeSheet.Columns[MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].Width = 50f;
                        activeSheet.RowCount += num2;
                        if (activeSheet.ColumnCount < 17 + num3)
                        {
                            activeSheet.ColumnCount = 17 + num3;
                        }
                        string text = out_node.GetList(0)[i].GetString("DEF_VALUE");
                        string text2 = out_node.GetList(0)[i].GetString("UNIT_TBL");
                        string text3 = out_node.GetList(0)[i].GetString("VALUE_TBL");
                        char c = out_node.GetList(0)[i].GetChar("DEF_UNIT_FLAG");
                        char c2 = out_node.GetList(0)[i].GetChar("DEF_UNIT_OVR_FLAG");
                        num4 = 0;
                        for (int j = num + 1; j < activeSheet.RowCount; j++)
                        {
                            num4++;
                            activeSheet.SetValue(j, 0, out_node.GetList(0)[i].GetString("CHAR_ID"));
                            activeSheet.SetValue(j, 1, out_node.GetList(0)[i].GetString("CHAR_DESC"));
                            activeSheet.SetValue(j, 2, out_node.GetList(0)[i].GetInt("SEQ_NUM"));
                            if (rdoStSpec.Checked)
                            {
                                activeSheet.SetValue(j, 3, out_node.GetList(0)[i].GetString("LOWER_SPEC_LIMIT"));
                                activeSheet.SetValue(j, 4, out_node.GetList(0)[i].GetString("TARGET_VALUE"));
                                activeSheet.SetValue(j, 5, out_node.GetList(0)[i].GetString("UPPER_SPEC_LIMIT"));
                                activeSheet.SetValue(j, 6, MPCF.GetSpecInfo(out_node.GetList(0)[i].GetString("UPPER_SPEC_LIMIT"), out_node.GetList(0)[i].GetString("LOWER_SPEC_LIMIT"), out_node.GetList(0)[i].GetString("TARGET_VALUE")));
                            }
                            else
                            {
                                ViewInspSpec(out_node.GetList(0)[i].GetString("CHAR_ID"), ref sTartet, ref sUpper, ref sLower);
                                activeSheet.SetValue(j, 3, sLower);
                                activeSheet.SetValue(j, 4, sTartet);
                                activeSheet.SetValue(j, 5, sUpper);
                                activeSheet.SetValue(j, 6, MPCF.GetSpecInfo(sUpper, sLower, sTartet));
                            }
                            activeSheet.SetValue(j, 7, out_node.GetList(0)[i].GetChar("OPT_INPUT_FLAG"));
                            activeSheet.SetValue(j, 8, out_node.GetList(0)[i].GetChar("VALUE_TYPE"));
                            activeSheet.SetValue(j, 9, out_node.GetList(0)[i].GetInt("VALUE_COUNT"));
                            activeSheet.SetValue(j, 11, out_node.GetList(0)[i].GetChar("DEF_UNIT_OVR_FLAG"));
                            activeSheet.SetValue(j, 12, out_node.GetList(0)[i].GetString("DEF_VALUE"));
                            activeSheet.SetValue(j, 13, out_node.GetList(0)[i].GetString("UNIT_TBL"));
                            activeSheet.SetValue(j, 14, out_node.GetList(0)[i].GetString("VALUE_TBL"));
                            activeSheet.SetValue(j, 15, num4);
                        }
                        int num7 = 0;
                        for (int j = 17; j < 17 + num3; j++)
                        {
                            for (int k = num + 1; k < activeSheet.RowCount; k++)
                            {
                                if (out_node.GetList(0)[i].GetChar("VALUE_TYPE") == 'N')
                                {
                                    MPCR.SetNumberCell(activeSheet.Cells[k, j]);
                                }
                                else
                                {
                                    MPCR.SetAsciiCell(activeSheet.Cells[k, j]);
                                }
                                if (cls_derived_char_list != null && out_node.GetList(0)[i].GetChar("DERIVED_PARAM_FLAG") == 'Y')
                                {
                                    activeSheet.Cells[k, j].Locked = true;
                                    activeSheet.Cells[k, j].BackColor = Color.Cyan;
                                    activeSheet.Rows[k].Tag = "AUTO";
                                    cls_derived_char_list.SetCharLocation(out_node.GetList(0)[i].GetString("CHAR_ID"), activeSheet, num7, k, j);
                                }
                            }
                            num7++;
                        }
                        List<TRSNode> list = out_node.GetList(0)[i].GetList("UNIT_LIST");
                        if (list.Count < 1)
                        {
                            switch (c)
                            {
                                case 'C':
                                    {
                                        for (int l = 0; l < num2; l++)
                                        {
                                            activeSheet.Cells[num + 1 + l, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].Locked = true;
                                            activeSheet.Cells[num + 1 + l, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].BackColor = Color.WhiteSmoke;
                                            activeSheet.SetValue(num + 1 + l, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), out_node.GetList(0)[i].GetString("UNIT"));
                                            if (out_node.GetList(0)[i].GetString("UNIT") == "")
                                            {
                                                activeSheet.SetValue(num + 1 + l, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), "*");
                                            }
                                            activeSheet.SetTag(num + 1 + l, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), "CHARACTER");
                                        }
                                        break;
                                    }
                                case 'E':
                                    {
                                        for (int l = 0; l < num2; l++)
                                        {
                                            activeSheet.Cells[num + 1 + l, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].Locked = false;
                                            activeSheet.Cells[num + 1 + l, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].BackColor = Color.White;
                                            activeSheet.SetTag(num + 1 + l, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), "NULL");
                                        }
                                        break;
                                    }
                                default:
                                    {
                                        for (int l = 0; l < num2; l++)
                                        {
                                            activeSheet.Cells[num + 1 + l, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].Locked = false;
                                            activeSheet.Cells[num + 1 + l, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].BackColor = Color.White;
                                        }
                                        break;
                                    }
                            }
                        }
                        else
                        {
                            if (c == 'Y')
                            {
                                for (int l = 0; l < list.Count && l <= num2 - 1; l++)
                                {
                                    if (list[l].GetChar("NULL_FLAG") == 'Y')
                                    {
                                        activeSheet.SetTag(num + 1 + l, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), "NULL");
                                    }
                                    else
                                    {
                                        activeSheet.SetValue(num + 1 + l, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), list[l].GetString("DEF_UNIT_ID"));
                                    }
                                    if (out_node.GetList(0)[i].GetChar("DEF_UNIT_OVR_FLAG") != 'Y')
                                    {
                                        activeSheet.Cells[num + 1 + l, 16].Locked = true;
                                        activeSheet.Cells[num + 1 + l, 16].BackColor = Color.WhiteSmoke;
                                    }
                                }
                            }
                            if ((c == 'Y' && c2 == 'Y' && text2 != "") || (c == ' ' && text2 != ""))
                            {
                                for (int j = num + 1; j <= activeSheet.RowCount - 1; j++)
                                {
                                    if (comboBoxCellType == null)
                                    {
                                        if (!BASLIST.ViewGCMDataList(control, '1', text2, -1, null, "", bIgnoreError: false, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), j, null))
                                        {
                                            return false;
                                        }
                                        comboBoxCellType = (ComboBoxCellType)activeSheet.Cells[j, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].CellType;
                                        activeSheet.Columns[MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].Width = 50f;
                                    }
                                    else
                                    {
                                        activeSheet.Cells[j, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].CellType = comboBoxCellType;
                                    }
                                }
                            }
                        }
                        for (int j = 17; j <= num3 + 17 - 1; j++)
                        {
                            for (int k = num + 1; k <= activeSheet.RowCount - 1; k++)
                            {
                                if (text != "")
                                {
                                    activeSheet.SetValue(k, j, text);
                                }
                                if (!(text3 != ""))
                                {
                                    continue;
                                }
                                if (comboBoxCellType2 == null)
                                {
                                    if (!BASLIST.ViewGCMDataList(control, '1', text3, -1, null, "", bIgnoreError: false, j, k, null))
                                    {
                                        return false;
                                    }
                                    comboBoxCellType2 = (ComboBoxCellType)activeSheet.Cells[k, j].CellType;
                                }
                                else
                                {
                                    activeSheet.Cells[k, j].CellType = comboBoxCellType2;
                                }
                            }
                        }
                        activeSheet.ColumnCount = num5;
                        for (int j = num3 + 17; j < activeSheet.ColumnCount; j++)
                        {
                            for (int k = num + 1; k < activeSheet.RowCount; k++)
                            {
                                activeSheet.Cells[k, j].Locked = true;
                                activeSheet.Cells[k, j].LockBackColor = Color.WhiteSmoke;
                            }
                        }
                    }
                    tRSNode.SetString("NEXT_CHAR_ID", out_node.GetString("NEXT_CHAR_ID"));
                }
                while (tRSNode.GetString("NEXT_CHAR_ID") != "");
                SheetView activeSheet2 = spdDataCollection.ActiveSheet;
                int num8 = 0;
                if (activeSheet2.ColumnCount > 17)
                {
                    activeSheet2.ColumnHeader.Cells.Get(0, 17).ColumnSpan = activeSheet2.ColumnCount - 17;
                    for (int i = 17; i < activeSheet2.ColumnCount; i++)
                    {
                        num8++;
                        activeSheet2.ColumnHeader.Cells.Get(1, i).Value = num8;
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
            return true;
        }

        private void SelectedItemChangedByColSet()
        {
            try
            {
                b_allow_changed = false;
                string sOper = cdvInspOper.Text;
                string sMatID = txtMatID.Text;
                int iMatVer = Convert.ToInt32(txtMatVer.Text);
                string sLotID = spdLotList.ActiveSheet.Cells[0, 0].Value.ToString();
                MPCF.ClearList(spdDataCollection, ComboBoxSpaceAddFlag: true);
                if (MPCF.Trim(cdvColSetID.Text) != "")
                {
                    FindColSetVersion(cdvColSetID.Text, sLotID, sMatID, iMatVer, sOper);
                }
                else
                {
                    ClearList("COL_SET_CHANGED");
                }
                b_allow_changed = true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            string text = "N";
            try
            {
                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        if (MPCF.Trim(cdvDept.Text) == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
                            return false;
                        }
                        if (MPCF.Trim(cdvOper.Text) == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvOper.Focus();
                            return false;
                        }
                        break;
                    case CSGC.CHECK.SAVE:
                        {
                            if (MPCF.Trim(txtInspID.Text) == "")
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(478));
                                cdvDept.Focus();
                                return false;
                            }
                            if (spdDataCollection.ActiveSheet.RowCount == 0)
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(107));
                                spdDataCollection.Select();
                                return false;
                            }
                            if (MPCF.Trim(cdvColSetID.Text) == "")
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblColSetID.Text + "]");
                                cdvInspectionType.Focus();
                                return false;
                            }
                            for (int i = 0; i < spdDataCollection.ActiveSheet.RowCount; i++)
                            {
                                if (MPCF.Trim(spdDataCollection.ActiveSheet.GetValue(i, 0)) == "")
                                {
                                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                    spdDataCollection.ActiveSheet.SetActiveCell(i, 0);
                                    spdDataCollection.Select();
                                    return false;
                                }

                                // 2025-10-23(BOK)
                                // 한국&베트남 공용 사용으로 조건 주석 처리
                                // if (MPGV.gsFactory == "IJDK1") {
                                for (int j = 16; j <= 16 + MPCF.ToInt(spdDataCollection.ActiveSheet.GetValue(i, 9)); j++)
                                    {
                                        if (MPCF.Trim(spdDataCollection.ActiveSheet.GetTag(i, j)) != "NULL" && MPCF.Trim(spdDataCollection.ActiveSheet.GetValue(i, j)) == "" && !spdDataCollection.ActiveSheet.Cells[i, j].Locked)
                                        {
                                            text = "Y";
                                        }
                                    }
                                // }

                                if (!(MPCF.Trim(spdDataCollection.ActiveSheet.GetValue(i, 8)) == "N"))
                                {
                                    continue;
                                }
                                for (int k = 17; k < 17 + MPCF.ToInt(spdDataCollection.ActiveSheet.GetValue(i, 9)); k++)
                                {
                                    if (MPCF.Trim(spdDataCollection.ActiveSheet.GetValue(i, k)) != "" && !MPCF.CheckNumeric(spdDataCollection.ActiveSheet.GetValue(i, k)))
                                    {
                                        MPCF.ShowMsgBox(MPCF.GetMessage(116));
                                        spdDataCollection.ActiveSheet.SetActiveCell(i, k);
                                        spdDataCollection.Select();
                                        return false;
                                    }
                                }
                            }
                            if (text == "Y")
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(564));
                            }
                            break;
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

        private bool Collect_Inspection_Data()
        {
            if (!CheckCondition(CSGC.CHECK.SAVE))
            {
                return false;
            }
            TRSNode tRSNode = new TRSNode("COLLECT_LOT_DATA_IN");
            TRSNode out_node = new TRSNode("COLLECT_LOT_DATA_OUT");
            int num = 0;
            int num2 = 0;
            int num3 = 17;
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("LOT_ID", MPCF.Trim(txtLotID.Text));
                tRSNode.AddString("MAT_ID", MPCF.Trim(txtMatID.Text));
                tRSNode.AddInt("MAT_VER", MPCF.ToInt(txtMatVer.Text));
                tRSNode.AddString("COL_SET_ID", MPCF.Trim(cdvColSetID.Text));
                tRSNode.AddInt("COL_SET_VERSION", MPCF.ToInt(txtColSetVer.Text));
                tRSNode.AddString("INSP_ID", MPCF.Trim(txtInspID.Text));
                tRSNode.AddInt("INSP_SEQ", 1);
                if (cdvInspectionJudgeFlag.Text != "")
                {
                    tRSNode.AddChar("INSP_JUDGE_FLAG", MPCF.ToChar(cdvInspectionJudgeFlag.Text));
                }
                tRSNode.AddString("RWK_OPER", cdvReworkOper.Text);
                tRSNode.AddString("INSP_COMMENT", txtComment.Text);
                for (num = 0; num < spdDataCollection.ActiveSheet.RowCount; num++)
                {
                    TRSNode tRSNode2 = tRSNode.AddNode("DATA_LIST");
                    tRSNode2.AddString("CHAR_ID", spdDataCollection.ActiveSheet.Cells[num, 0].Value);
                    tRSNode2.AddInt("CHAR_SEQ", spdDataCollection.ActiveSheet.Cells[num, 2].Value);
                    tRSNode2.AddInt("UNIT_SEQ", spdDataCollection.ActiveSheet.Cells[num, 15].Value);
                    tRSNode2.AddInt("VALUE_SEQ", 1);
                    tRSNode2.AddString("UNIT_ID", spdDataCollection.ActiveSheet.Cells[num, 16].Value);
                    tRSNode2.AddChar("VALUE_TYPE", spdDataCollection.ActiveSheet.Cells[num, 8].Value);
                    tRSNode2.AddInt("VALUE_COUNT", spdDataCollection.ActiveSheet.Cells[num, 9].Value);
                    for (int i = 1; i - 1 + num3 < spdDataCollection.ActiveSheet.ColumnCount && i <= 26; i++)
                    {
                        tRSNode2.AddString("VALUE_" + i, spdDataCollection.ActiveSheet.Cells[num, i - 1 + num3].Value);
                    }
                }
                for (num2 = 0; num2 < spdLossInfo.ActiveSheet.RowCount; num2++)
                {
                    if (MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[num2, 3].Value) > 0.0)
                    {
                        TRSNode tRSNode3 = tRSNode.AddNode("LOSS_LIST");
                        tRSNode3.AddString("LOSS_CODE", spdLossInfo.ActiveSheet.Cells[num2, 0].Value);
                        tRSNode3.AddDouble("LOSS_QTY", MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[num2, 3].Value));
                        if (spdLossInfo.ActiveSheet.Cells[num2, 5].Value.ToString().ToUpper() == "TRUE")
                        {
                            tRSNode3.AddChar("MAIN_FLAG", 'Y');
                        }
                        else
                        {
                            tRSNode3.AddChar("MAIN_FLAG", 'N');
                        }
                    }
                }
                if (!MPCR.CallService("CUS_QCM", "CUS_QCM_Collect_Inspection_Data", tRSNode, ref out_node, b_ignore_message: false))
                {
                    return false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
            return true;
        }

        private bool Inspection_Judge()
        {
            if (!VaildationCheckJudge())
            {
                return false;
            }
            TRSNode tRSNode = new TRSNode("INSPECTION_JUDGE_IN");
            TRSNode out_node = new TRSNode("INSPECTION_JUDGE_OUT");
            int num = 0;
            int num2 = 0;
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                string value = spdLotList.ActiveSheet.GetValue(0, 0).ToString();
                tRSNode.AddString("INSP_ID", MPCF.Trim(txtInspID.Text));
                tRSNode.AddString("LOT_ID", value);
                tRSNode.AddString("COL_SET_ID", MPCF.Trim(cdvColSetID.Text));
                tRSNode.AddInt("COL_SET_VERSION", MPCF.ToInt(txtColSetVer.Text));
                tRSNode.AddChar("INSP_JUDGE_FLAG", MPCF.Trim(cdvInspectionJudgeFlag.Text));
                tRSNode.AddString("TO_FLOW", MPCF.Trim(spdLotList.ActiveSheet.Cells[0, 3].Value.ToString()));
                tRSNode.AddString("TO_OPER", MPCF.Trim(cdvReworkOper.Text));
                tRSNode.AddString("INSP_COMMENT", MPCF.Trim(txtComment.Text));
                for (num = 0; num < spdLossInfo.ActiveSheet.RowCount; num++)
                {
                    if (MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[num, 3].Value) > 0.0)
                    {
                        TRSNode tRSNode2 = tRSNode.AddNode("LOSS_LIST");
                        tRSNode2.AddString("LOSS_CODE", spdLossInfo.ActiveSheet.Cells[num, 0].Value);
                        tRSNode2.AddDouble("LOSS_QTY", MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[num, 3].Value));
                        if (spdLossInfo.ActiveSheet.Cells[num, 5].Value.ToString().ToUpper() == "TRUE")
                        {
                            tRSNode2.AddChar("MAIN_FLAG", 'Y');
                        }
                        else
                        {
                            tRSNode2.AddChar("MAIN_FLAG", 'N');
                        }
                    }
                }
                if (cdvDept.Text == "HM" && MPCF.ToDbl(txtWeightDiff.Text) < 0.0)
                {
                    tRSNode.AddChar("OVER_QTY_FLAG", 'Y');
                    tRSNode.AddDouble("OVER_QTY", MPCF.ToDbl(txtTotalQty.Text));
                }
                for (num2 = 0; num2 < spdWorkerList.ActiveSheet.RowCount; num2++)
                {
                    TRSNode tRSNode3 = tRSNode.AddNode("WORKER_LIST");
                    tRSNode3.AddString("WORKER_ID", spdWorkerList.ActiveSheet.Cells[num2, 0].Value);
                    tRSNode3.AddString("WORKER_DESC", spdWorkerList.ActiveSheet.Cells[num2, 1].Value);
                    tRSNode3.AddString("WORK_TYPE", spdWorkerList.ActiveSheet.Cells[num2, 2].Value);
                }
                if (!MPCR.CallService("CUS_QCM", "CUS_QCM_Inspection_Judge", tRSNode, ref out_node, b_ignore_message: false))
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
            return true;
        }

        private bool VaildationCheckJudge()
        {
            try
            {
                if (txtInspID.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(478));
                    txtLotID.Focus();
                    return false;
                }
                if (MPCF.Trim(cdvInspectionJudgeFlag.Text) == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblJudge.Text + "]");
                    cdvInspectionJudgeFlag.Focus();
                    return false;
                }
                if (MPCF.ToDbl(txtWeightDiff.Text) < 0.0 && MPCF.ShowMsgBox(MPCF.GetMessage(558) + " QTY: " + MPCF.ToDbl(txtWeightDiff.Text) * -1.0, MessageBoxButtons.YesNo, 1) != DialogResult.Yes)
                {
                    return false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
            return true;
        }

        private bool VaildationCheckHold()
        {
            try
            {
                if (txtInspID.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(478));
                    txtLotID.Focus();
                    return false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
            return true;
        }

        private void ViewWorkerList()
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "OPER";
                array[1].sCondition_Value = cdvInspOper.Text;
                array[2].sCondition_ID = "GROUP_ID";
                array[2].sCondition_Value = cdvWorkGroup.Text;
                if (!TPDR.GetDataOne("", ref dt, "CQCM2001-004", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdWorkerList);
                    return;
                }
                MPCF.ClearList(spdWorkerList);
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdWorkerList_Sheet1.RowCount++;
                    spdWorkerList_Sheet1.Cells[num, 0].Value = dt.Rows[num]["WORKER_ID"];
                    spdWorkerList_Sheet1.Cells[num, 1].Value = dt.Rows[num]["WORKER_DESC"];
                    spdWorkerList_Sheet1.Cells[num, 2].Value = dt.Rows[num]["WORK_TYPE"];
                }
                MPCF.FitColumnHeader(spdWorkerList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool Update_Inspection_Status()
        {
            TRSNode tRSNode = new TRSNode("UPDATE_INSPECTION_STATUS_IN");
            TRSNode out_node = new TRSNode("UPDATE_INSPECTION_STATUS_OUT");
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '2';
                tRSNode.AddString("INSP_ID", MPCF.Trim(txtInspID.Text));
                if (!MPCR.CallService("CUS_QCM", "CUS_QCM_Update_Inspection_Status", tRSNode, ref out_node, b_ignore_message: false))
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
            return true;
        }

        private void fnRegistrationFile(FileInfo _fileInfo, string FileNo, string Image_code, string InspID, string FilePath)
        {
            TRSNode tRSNode = new TRSNode("Update_File_In");
            TRSNode out_node = new TRSNode("Update_File_Out");
            MPCR.SetInMsg(tRSNode);
            tRSNode.ProcStep = '2';
            string value = Path.GetExtension(FilePath).Replace(".", "");
            tRSNode.AddString("FILE_NO", FileNo);
            tRSNode.AddString("IMAGE_CODE", Image_code);
            tRSNode.AddString("INSP_ID", InspID);
            tRSNode.AddString("FILE_TYPE", value);
            if (_fileInfo.Exists)
            {
                BinaryReader binaryReader = new BinaryReader(_fileInfo.OpenRead());
                byte[] value2 = binaryReader.ReadBytes((int)_fileInfo.Length);
                tRSNode.AddBlob("__BIN_DATA_1", value2);
                tRSNode.AddInt("IMAGE_SIZE", _fileInfo.Length);
                binaryReader.Close();
            }
            if (MPCR.CallService("CUS_QCM", "CUS_QCM_File_Attach", tRSNode, ref out_node))
            {
            }
        }

        private void fnDeleteFile(string FileNo)
        {
            TRSNode tRSNode = new TRSNode("Update_File_In");
            TRSNode out_node = new TRSNode("Update_File_Out");
            MPCR.SetInMsg(tRSNode);
            tRSNode.ProcStep = '3';
            tRSNode.AddString("FILE_NO", FileNo);
            if (MPCR.CallService("CUS_QCM", "CUS_QCM_File_Attach", tRSNode, ref out_node))
            {
            }
        }

        private async void fnFileSelectionChagned()
        {
            if (spdFileRegistration.ActiveSheet.ActiveRowIndex < 0)
            {
                return;
            }
            int iRow = spdFileRegistration.ActiveSheet.ActiveRowIndex;
            if (cdvOper.Text == "OC06020" && MPCF.Trim(spdFileRegistration.ActiveSheet.Cells[iRow, 1].Value.ToString()) == "DRAWING")
            {
                pictureBox1.Image = null;
                Brwpdf.Navigate("about:blank");
                pictureBox1.Visible = false;
                Brwpdf.Visible = true;
                string sfilePath = txtDrawingPath.Text;
                if (await FileExistsOnWeb(sfilePath))
                {
                    BrwDrawing.Navigate(sfilePath);
                }
                else
                {
                    BrwDrawing.DocumentText = "";
                }
                Brwpdf.Navigate(sfilePath);
            }
            else
            {
                pictureBox1.Image = null;
                Brwpdf.Navigate("about:blank");
                pictureBox1.Visible = true;
                Brwpdf.Visible = false;
                string s_FileNo = MPCF.Trim(spdFileRegistration.ActiveSheet.Cells[iRow, 0].Value.ToString());
                if (!(s_FileNo == ""))
                {
                    ViewImageFile(s_FileNo);
                }
            }
        }

        private void ViewImageFile(string _FileNo)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "FILE_NO";
                array[1].sCondition_Value = _FileNo;
                if (!TPDR.GetDataOne("", ref dt, "CQCM2001-005", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                }
                else if (dt.Rows[0]["FILE_TYPE"].ToString() == "pdf")
                {
                    ByteArrayToPdf((byte[])dt.Rows[0]["IMAGE_DATA"]);
                    pictureBox1.Visible = false;
                    Brwpdf.Visible = true;
                }
                else
                {
                    pictureBox1.Image = ByteArrayToImage((byte[])dt.Rows[0]["IMAGE_DATA"]);
                    pictureBox1.Visible = true;
                    Brwpdf.Visible = false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        public static Image ByteArrayToImage(byte[] b)
        {
            TypeConverter converter = TypeDescriptor.GetConverter(typeof(Bitmap));
            ImageConverter imageConverter = new ImageConverter();
            return (Image)imageConverter.ConvertFrom(b);
        }

        private void ByteArrayToPdf(byte[] b)
        {
            try
            {
                string text = Environment.GetEnvironmentVariable("TEMP") + "\\" + DateTime.Now.ToString("yyyyMMddHHmmss") + ".pdf";
                FileStream output = File.Open(text, FileMode.Create);
                BinaryWriter binaryWriter = new BinaryWriter(output);
                binaryWriter.Write(b, 0, b.Length);
                binaryWriter.Close();
                Brwpdf.Navigate(text);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void minmaxdata()
        {
            string text = "";
            int num = 0;
            int num2 = 0;
            int num3 = 17;
            double num4 = 0.0;
            double num5 = 0.0;
            for (num = 0; num < spdDataCollection.ActiveSheet.RowCount; num++)
            {
                if (!MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[num, num3].Value))
                {
                    continue;
                }
                for (num2 = num3; num2 < spdDataCollection.ActiveSheet.ColumnCount && num2 <= 40; num2++)
                {
                    if (num2 == num3)
                    {
                        text = text + "  " + spdDataCollection.ActiveSheet.Cells[num, 1].Text;
                        num4 = MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[num, num2].Value);
                        num5 = MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[num, num2].Value);
                    }
                    if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[num, num2].Value))
                    {
                        if (num4 < MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[num, num2].Value))
                        {
                            num4 = MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[num, num2].Value);
                        }
                        if (num5 > MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[num, num2].Value))
                        {
                            num5 = MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[num, num2].Value);
                        }
                    }
                }
                text = text + "(" + num5 + " ~ " + num4 + ") ";
            }
            lblMinMax.Text = text;
        }

        private void Open_Port(string s_port, char c_MsgYN)
        {
            try
            {
                if (spScanner.IsOpen)
                {
                    spScanner.Close();
                }
                spScanner.PortName = s_port;
                spScanner.BaudRate = 9600;
                spScanner.DataBits = 8;
                spScanner.Parity = Parity.None;
                spScanner.StopBits = StopBits.One;
                spScanner.Handshake = Handshake.None;
                spScanner.RtsEnable = false;
                spScanner.DtrEnable = false;
                spScanner.Open();
                if (spScanner.IsOpen && c_MsgYN == 'Y')
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(500));
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void SpecPopUp()
        {
            try
            {
                if (cdvOper.Text == "")
                {
                    MPCF.ShowMsgBox("공정입력바랍니다.(Input Operation Please)");
                    return;
                }
                if (txtMatID.Text == "")
                {
                    MPCF.ShowMsgBox("품목입력바랍니다.(Input Material Please)");
                    return;
                }
                frmPopSpecList frmPopSpecList2 = new frmPopSpecList();
                frmPopSpecList2.StartPosition = FormStartPosition.CenterParent;
                frmPopSpecList2.sArea_id = cdvDept.Text;
                frmPopSpecList2.sArea_desc = cdvDept.DisplayText;
                frmPopSpecList2.sOper_id = cdvOper.Text;
                frmPopSpecList2.sOper_desc = cdvOper.DisplayText;
                frmPopSpecList2.sMat_id = txtMatID.Text;
                frmPopSpecList2.sMat_desc = txtMatDesc.Text;
                if (frmPopSpecList2.ShowDialog() == DialogResult.OK)
                {
                    frmPopSpecList2 = null;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void LossQtySum()
        {
            try
            {
                double num = 0.0;
                double num2 = 0.0;
                if (spdLossInfo.ActiveSheet.RowCount == 0)
                {
                    return;
                }
                for (int i = 0; i < spdLossInfo.ActiveSheet.RowCount; i++)
                {
                    if (MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[i, 3].Value) > 0.0)
                    {
                        if (spdLossInfo.ActiveSheet.Cells[i, 0].Text == "HBAD997")
                        {
                            num2 = MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[i, 3].Value);
                            iRowHBAD997 = i;
                        }
                        else
                        {
                            num += MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[i, 3].Value);
                        }
                    }
                }
                txtLossKg.Text = num.ToString();
                txtWeightDiff.Text = num2.ToString();
                txtLossEa.Text = Math.Round(num / MPCF.ToDbl(txtChangeRatio.Text), 5, MidpointRounding.AwayFromZero).ToString();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool DeleteLotHistiry(string sLotId)
        {
            try
            {
                TRSNode tRSNode = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '2';
                tRSNode.AddString("LOT_ID", sLotId);
                if (!MPCR.CallService("CUS_WIP", "CUS_WIP_Delete_Lot_History", tRSNode, ref out_node))
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);
                txtLotID.Text = sLotId;
                ViewLotInfo(sLotId);
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool ViewColsetIdCheck(string sLotId)
        {
            bool flag = false;
            string text = "";
            string text2 = "";
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "OPER";
                array[1].sCondition_Value = cdvOper.Text;
                array[2].sCondition_ID = "LOT_ID";
                array[2].sCondition_Value = sLotId;
                if (!TPDR.GetDataOne("", ref dt, "CQCM0001-002", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    return false;
                }
                if (dt.Rows[0]["COL_SET_ID"].ToString() == "X")
                {
                    if (MPCF.ShowMsgBox(MPCF.GetMessage(563), MessageBoxButtons.YesNo, 2) == DialogResult.Yes)
                    {
                        if (dt.Rows[0]["A_COL_SET_ID"].ToString().Trim() != "")
                        {
                            text = dt.Rows[0]["MAT_ID"].ToString();
                            text2 = dt.Rows[0]["A_COL_SET_ID"].ToString().Trim();
                            if (Update_MFO_ColSet_List(text, text2))
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(556));
                                flag = true;
                            }
                        }
                        else
                        {
                            frmPopCollectionSetOper frmPopCollectionSetOper2 = new frmPopCollectionSetOper();
                            frmPopCollectionSetOper2.sArea_id = cdvDept.Text;
                            frmPopCollectionSetOper2.sArea_desc = cdvDept.DisplayText;
                            frmPopCollectionSetOper2.sOper_id = cdvOper.Text;
                            frmPopCollectionSetOper2.sOper_desc = cdvOper.DisplayText;
                            frmPopCollectionSetOper2.sMat_id = dt.Rows[0]["MAT_ID"].ToString();
                            frmPopCollectionSetOper2.sMat_desc = dt.Rows[0]["MAT_DESC"].ToString();
                            if (frmPopCollectionSetOper2.ShowDialog() == DialogResult.OK)
                            {
                                frmPopCollectionSetOper2 = null;
                            }
                        }
                    }
                    flag = false;
                }
                else
                {
                    flag = true;
                }
                return flag;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool Update_MFO_ColSet_List(string sMatId, string sColSetId)
        {
            TRSNode tRSNode = new TRSNode("UPDATE_MFO_COLSET_LIST_IN");
            TRSNode out_node = new TRSNode("CMN_OUT");
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = 'U';
                tRSNode.AddChar("OPT_LEVEL", '4');
                TRSNode tRSNode2 = tRSNode.AddNode("COLSET_LIST");
                tRSNode2.AddString("MAT_ID", MPCF.Trim(sMatId));
                tRSNode2.AddInt("MAT_VER", 1);
                tRSNode2.AddChar("COLLECTION_MODE", 'M');
                tRSNode2.AddString("OPER", MPCF.Trim(cdvOper.Text));
                tRSNode2.AddString("COL_SET_ID", sColSetId);
                tRSNode2.AddChar("DEFAULT_FLAG", 'N');
                tRSNode2.AddChar("DISABLE_FLAG", 'N');
                if (!MPCR.CallService("EDC", "EDC_Update_MFO_ColSet_List", tRSNode, ref out_node))
                {
                    return false;
                }
                cdvColSetID.Text = sColSetId;
                cdvColSetID.DisplayText = sColSetId;
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void ViewInspectionGritISP(string inspID)
        {
            try
            {
                b_allow_changed = false;
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "INSP_ID";
                array[1].sCondition_Value = inspID;
                if (!TPDR.GetDataOne("", ref dt, "CQCM2004-011", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdDataCollectionISP);
                    return;
                }
                MPCF.ClearList(spdDataCollectionISP);
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdDataCollectionISP.ActiveSheet.RowCount++;
                    spdDataCollectionISP.ActiveSheet.Cells[num, 0].Value = dt.Rows[num]["INSP_SEQ"];
                    spdDataCollectionISP.ActiveSheet.Cells[num, 1].Value = dt.Rows[num]["QC_NAME"];
                    spdDataCollectionISP.ActiveSheet.Cells[num, 2].Value = dt.Rows[num]["SPEC_VAL"];
                    spdDataCollectionISP.ActiveSheet.Cells[num, 3].Value = dt.Rows[num]["VAL_1"];
                    spdDataCollectionISP.ActiveSheet.Cells[num, 4].Value = dt.Rows[num]["VAL_2"];
                    spdDataCollectionISP.ActiveSheet.Cells[num, 5].Value = dt.Rows[num]["VAL_3"];
                    spdDataCollectionISP.ActiveSheet.Cells[num, 6].Value = dt.Rows[num]["VAL_4"];
                    spdDataCollectionISP.ActiveSheet.Cells[num, 7].Value = dt.Rows[num]["VAL_5"];
                    spdDataCollectionISP.ActiveSheet.Cells[num, 8].Value = dt.Rows[num]["VAL_6"];
                }
                b_allow_changed = true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool Collect_Data_ISP()
        {
            TRSNode tRSNode = new TRSNode("COLLECTION_DATA_ASPECT_IN");
            TRSNode out_node = new TRSNode("COLLECTION_DATA_ASPECT_OUT");
            int num = 0;
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '7';
                string value = spdLotList.ActiveSheet.GetValue(0, 0).ToString();
                tRSNode.AddString("INSP_ID", MPCF.Trim(txtInspID.Text));
                tRSNode.AddString("LOT_ID", value);
                tRSNode.AddString("COL_SET_ID", cdvColSetID.Text);
                tRSNode.AddInt("COL_SET_VER", MPCF.ToInt(txtColSetVer.Text));
                tRSNode.AddString("INSP_DTL_TYPE", "ICP");
                for (num = 0; num < spdDataCollectionISP.ActiveSheet.RowCount; num++)
                {
                    TRSNode tRSNode2 = tRSNode.AddNode("DATA_LIST");
                    tRSNode2.AddInt("INSP_SEQ", spdDataCollectionISP.ActiveSheet.Cells[num, 0].Value);
                    tRSNode2.AddString("QC_NAME", spdDataCollectionISP.ActiveSheet.Cells[num, 1].Value);
                    tRSNode2.AddString("SPEC_VAL", spdDataCollectionISP.ActiveSheet.Cells[num, 2].Value);
                    tRSNode2.AddDouble("VAL_1", spdDataCollectionISP.ActiveSheet.Cells[num, 3].Value);
                    tRSNode2.AddDouble("VAL_2", spdDataCollectionISP.ActiveSheet.Cells[num, 4].Value);
                    tRSNode2.AddDouble("VAL_3", spdDataCollectionISP.ActiveSheet.Cells[num, 5].Value);
                    tRSNode2.AddDouble("VAL_4", spdDataCollectionISP.ActiveSheet.Cells[num, 6].Value);
                    tRSNode2.AddDouble("VAL_5", spdDataCollectionISP.ActiveSheet.Cells[num, 7].Value);
                    tRSNode2.AddDouble("VAL_6", spdDataCollectionISP.ActiveSheet.Cells[num, 8].Value);
                }
                if (!MPCR.CallService("CUS_QCM", "CUS_QCM_Collect_Inspection_Data_Grit", tRSNode, ref out_node, b_ignore_message: false))
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
            return true;
        }

        private void SaveIQcChange()
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[7];
                DataTable dt = null;
                string sSql = "";
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "INSP_ID";
                array[1].sCondition_Value = txtInspID.Text;
                array[2].sCondition_ID = "LOT_ID";
                array[2].sCondition_Value = spdLotList_Sheet1.Cells[spdLotList_Sheet1.ActiveRowIndex, 0].Text;
                array[3].sCondition_ID = "USER_ID";
                array[3].sCondition_Value = MPGV.gsUserID;
                array[4].sCondition_ID = "COMMENT";
                array[4].sCondition_Value = "Judge Change";
                array[5].sCondition_ID = "INSP_STATUS";
                array[5].sCondition_Value = txtInspectionStatus.Text;
                array[6].sCondition_ID = "INSP_RESULT_FLAG";
                array[6].sCondition_Value = cdvInspectionJudgeChange.Text;
                if (!TPDR.GetDataOne("", ref dt, "CQCM3001-010", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                }
                else
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(52));
                    ViewLotInfo(txtLotID.Text);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private async Task RoundInFileAutoWrite()
        {
            try
            {
                if (!(MPGV.gsFactory == "IJDK1"))
                {
                    return;
                }
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
                DataTable dt = null;
                string sSql = "";
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;
                if (!TPDR.GetDataOne("", ref dt, "CQCM1003-004", dvcArgu, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    return;
                }
                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    string sharedFolderPath = txtRdIfPath.Text + "\\INPUT\\";
                    string subFolder = "20" + dt.Rows[i]["LOT_ID"].ToString().Trim().Substring(1, 4);
                    string fileName = dt.Rows[i]["LOT_ID"].ToString().Trim().ToString() + ".csv";
                    string fullPath = Path.Combine(sharedFolderPath, subFolder, fileName);
                    string folderPath = Path.Combine(sharedFolderPath, subFolder);
                    if (!Directory.Exists(folderPath))
                    {
                        Directory.CreateDirectory(folderPath);
                    }
                    string tranTimeStr = dt.Rows[i]["LAST_TRAN_TIME"].ToString().Trim();
                    DateTime tranTime = DateTime.ParseExact(tranTimeStr, "yyyyMMddHHmmss", null);
                    bool shouldWriteFile = true;
                    if (File.Exists(fullPath))
                    {
                        DateTime fileWriteTime = File.GetLastWriteTime(fullPath);
                        if (fileWriteTime >= tranTime)
                        {
                            shouldWriteFile = false;
                        }
                    }
                    if (shouldWriteFile)
                    {
                        string[] lines = new string[4]
                        {
                        dt.Rows[i]["LOT_ID"].ToString().Trim(),
                        dt.Rows[i]["RECIPE_NO"].ToString().Trim(),
                        dt.Rows[i]["MAT_ID"].ToString().Trim(),
                        dt.Rows[i]["MAT_DESC"].ToString().Trim()
                        };
                        await Task.Run(delegate
                        {
                            File.WriteAllLines(fullPath, lines);
                        });
                    }
                }
            }
            catch (Exception ex)
            {
                Exception ex2 = ex;
                MPCF.ShowMsgBox(ex2.Message);
            }
        }

        private void RoundInFileWrite()
        {
            if (txtRdIfRecipe.Text.Trim() == "")
            {
                MPCF.ShowMsgBox(MPCF.GetMessage(350));
                frmSetupRecipeRegistration frmSetupRecipeRegistration2 = new frmSetupRecipeRegistration();
                frmSetupRecipeRegistration2.StartPosition = FormStartPosition.CenterParent;
                frmSetupRecipeRegistration2.cdvDept.Text = cdvDept.Text;
                frmSetupRecipeRegistration2.cdvOper.Text = cdvOper.Text;
                frmSetupRecipeRegistration2.cdvMatID.Text = txtMatID.Text;
                frmSetupRecipeRegistration2.txtMatDesc.Text = txtMatDesc.Text;
                if (frmSetupRecipeRegistration2.ShowDialog() != DialogResult.OK)
                {
                    return;
                }
                frmSetupRecipeRegistration2 = null;
                ViewLotInfo(txtLotID.Text);
            }
            string path = txtRdIfPath.Text + "\\INPUT\\";
            string path2 = "20" + txtLotID.Text.Trim().Substring(1, 4).ToString();
            string path3 = txtLotID.Text.Trim().ToString() + ".csv";
            string path4 = Path.Combine(path, path2, path3);
            try
            {
                string path5 = Path.Combine(path, path2);
                if (!Directory.Exists(path5))
                {
                    Directory.CreateDirectory(path5);
                }
                string[] contents = new string[4]
                {
                txtLotID.Text.Trim(),
                txtRdIfRecipe.Text.Trim(),
                txtMatID.Text,
                txtMatDesc.Text
                };
                File.WriteAllLines(path4, contents);
                MPCF.ShowMsgBox(MPCF.GetMessage(608));
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void RoundOutFileRead()
        {
            try
            {
                string path = txtRdIfPath.Text + "\\OUTPUT\\20" + txtLotID.Text.Substring(1, 4);
                string path2 = txtLotID.Text + ".csv";
                string path3 = Path.Combine(path, path2);
                if (!File.Exists(path3))
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(607));
                    return;
                }
                string[] array = File.ReadAllLines(path3);
                string[] array2 = new string[15];
                string[] array3 = new string[13];
                for (int i = 11; i <= 25; i++)
                {
                    if (i >= array.Length)
                    {
                        array2[i - 11] = "";
                        array3[i - 11] = "";
                        continue;
                    }
                    string text = array[i].Trim();
                    string[] array4 = text.Split('\t');
                    if (i == 11 || i == 12)
                    {
                        if (array4.Length != 0)
                        {
                            array2[i - 11] = array4[0];
                        }
                    }
                    else if (i >= 13 && i <= 25)
                    {
                        if (array4.Length > 1)
                        {
                            array2[i - 11] = array4[1];
                        }
                        if (array4.Length > 2)
                        {
                            array3[i - 13] = array4[2];
                        }
                    }
                }
                for (int j = 0; j < spdDataCollection.ActiveSheet.RowCount; j++)
                {
                    if (spdDataCollection.ActiveSheet.Cells[j, 0].Text == "MAX-D")
                    {
                        spdDataCollection.ActiveSheet.Cells[j, 17].Text = array2[1].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 18].Text = array2[0].Trim().ToString();
                    }
                    if (spdDataCollection.ActiveSheet.Cells[j, 0].Text == "ALL-T")
                    {
                        spdDataCollection.ActiveSheet.Cells[j, 17].Text = array2[2].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 18].Text = array2[3].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 19].Text = array2[4].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 20].Text = array2[5].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 21].Text = array2[6].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 22].Text = array2[7].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 23].Text = array2[8].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 24].Text = array2[9].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 25].Text = array2[10].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 26].Text = array2[11].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 27].Text = array2[12].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 28].Text = array2[13].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 29].Text = array2[14].Trim().ToString();
                    }
                    if (spdDataCollection.ActiveSheet.Cells[j, 0].Text == "FLAT")
                    {
                        spdDataCollection.ActiveSheet.Cells[j, 17].Text = array3[0].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 18].Text = array3[1].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 19].Text = array3[2].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 20].Text = array3[3].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 21].Text = array3[4].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 22].Text = array3[5].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 23].Text = array3[6].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 24].Text = array3[7].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 25].Text = array3[8].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 26].Text = array3[9].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 27].Text = array3[10].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 28].Text = array3[11].Trim().ToString();
                        spdDataCollection.ActiveSheet.Cells[j, 29].Text = array3[12].Trim().ToString();
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void Sumtotalqty(string sInputType)
        {
            try
            {
                LossQtySum();
                double result;
                switch (sInputType)
                {
                    case "KG":
                        if (double.TryParse(txtChangeRatio.Text, out result))
                        {
                            txtGoodEa.Text = Math.Round(MPCF.ToDbl(txtGoodKg.Text) / result, 5, MidpointRounding.AwayFromZero).ToString();
                            break;
                        }
                        MPCF.ShowMsgBox("환산비율이 올바르지 않습니다.");
                        txtGoodKg.Text = spdLotList.ActiveSheet.Cells[0, 5].Text;
                        txtGoodEa.Text = "0";
                        break;
                    case "EA":
                        if (double.TryParse(txtChangeRatio.Text, out result))
                        {
                            txtGoodKg.Text = (MPCF.ToDbl(txtGoodEa.Text) * result).ToString();
                            break;
                        }
                        MPCF.ShowMsgBox("환산비율이 올바르지 않습니다.");
                        txtGoodKg.Text = spdLotList.ActiveSheet.Cells[0, 5].Text;
                        txtGoodEa.Text = "0";
                        break;
                }
                if (sInputType == "SEARCH")
                {
                    txtTotalQty.Text = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[0, 5].Text).ToString();
                    txtGoodKg.Text = (MPCF.ToDbl(spdLotList.ActiveSheet.Cells[0, 5].Text) - MPCF.ToDbl(txtLossKg.Text) - MPCF.ToDbl(txtWeightDiff.Text)).ToString();
                    if (double.TryParse(txtChangeRatio.Text, out result))
                    {
                        txtGoodEa.Text = Math.Round(MPCF.ToDbl(txtGoodKg.Text) / result, 5, MidpointRounding.AwayFromZero).ToString();
                    }
                    else
                    {
                        txtGoodEa.Text = "0";
                    }
                }
                else
                {
                    txtWeightDiff.Text = Math.Round(MPCF.ToDbl(spdLotList.ActiveSheet.Cells[0, 5].Text) - MPCF.ToDbl(txtGoodKg.Text) - MPCF.ToDbl(txtLossKg.Text), 5, MidpointRounding.AwayFromZero).ToString();
                    spdLossInfo.ActiveSheet.Cells[iRowHBAD997, 3].Text = txtWeightDiff.Text;
                    if (MPCF.ToDbl(txtWeightDiff.Text) < 0.0)
                    {
                        txtTotalQty.Text = (MPCF.ToDbl(txtGoodKg.Text) + MPCF.ToDbl(txtLossKg.Text)).ToString();
                    }
                    else
                    {
                        txtTotalQty.Text = (MPCF.ToDbl(txtGoodKg.Text) + MPCF.ToDbl(txtLossKg.Text) + MPCF.ToDbl(txtWeightDiff.Text)).ToString();
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void rhText(string sText)
        {
            txtLotID.Text = sText;
            fnLotKeyPress();
        }

        private void frmTranInspectionRegistration_Load(object sender, EventArgs e)
        {
            bool flag = false;
            cdvWorkGroup.Text = "A";
            defModelData = new DefaultSheetDataModel(0, spdDataCollection.ActiveSheet.Columns.Count);
            spdDataCollection.ActiveSheet.Models.Data = defModelData;
            defModelData.Changed += defModelData_Changed;
            defModelDataLoss = new DefaultSheetDataModel(0, spdLossInfo.ActiveSheet.Columns.Count);
            spdLossInfo.ActiveSheet.Models.Data = defModelDataLoss;
            defModelDataLoss.Changed += defModelDataLoss_Changed;
            string[] portNames = SerialPort.GetPortNames();
            for (int i = 0; i < portNames.Length; i++)
            {
                flag = false;
                for (int j = 0; j < cboPort.Items.Count; j++)
                {
                    if (cboPort.Items[j].ToString() == portNames[i])
                    {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    cboPort.Items.Add(portNames[i]);
                }
            }
            cboPort.Items.Add("");
            rh_Sanner = rhText;
            if (cboPort.Text != "")
            {
                Open_Port(cboPort.Text, 'N');
            }
        }

        private void defModelDataLoss_Changed(object sender, SheetDataModelEventArgs e)
        {
            if (!b_allow_changed)
            {
                return;
            }
            try
            {
                if (e.Row < 0)
                {
                    return;
                }
                int row = e.Row;
                int column = e.Column;
                b_allow_changed = false;
                if (cdvDept.Text == "HM")
                {
                    double result;
                    if (e.Column == 2)
                    {
                        if (double.TryParse(txtChangeRatio.Text, out result))
                        {
                            spdLossInfo.ActiveSheet.Cells[row, 3].Value = MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[row, column].Value) * result;
                        }
                        else
                        {
                            spdLossInfo.ActiveSheet.Cells[row, 3].Value = 0;
                        }
                    }
                    else if (e.Column == 3)
                    {
                        if (double.TryParse(txtChangeRatio.Text, out result))
                        {
                            spdLossInfo.ActiveSheet.Cells[row, 2].Value = Math.Round(MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[row, column].Value) / result, 5, MidpointRounding.AwayFromZero);
                        }
                        else
                        {
                            spdLossInfo.ActiveSheet.Cells[row, 2].Value = 0;
                        }
                    }
                    Sumtotalqty("LOSS");
                }
                b_allow_changed = true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void defModelData_Changed(object sender, SheetDataModelEventArgs e)
        {
            if (!b_allow_changed || spdDataCollection.ActiveSheet.RowCount < 1)
            {
                return;
            }
            try
            {
                double num = 0.0;
                double num2 = 0.0;
                bool flag = false;
                int column = e.Column;
                int row = e.Row;
                if (column >= 17)
                {
                    if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[row, column].Value))
                    {
                        if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[row, 3].Value) && MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[row, column].Value) < MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[row, 3].Value))
                        {
                            flag = true;
                        }
                        if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[row, 5].Value) && MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[row, column].Value) > MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[row, 5].Value))
                        {
                            flag = true;
                        }
                        if (flag)
                        {
                            spdDataCollection.ActiveSheet.Cells[row, column].BackColor = Color.Red;
                        }
                        else
                        {
                            spdDataCollection.ActiveSheet.Cells[row, column].BackColor = Color.White;
                        }
                    }
                    else
                    {
                        spdDataCollection.ActiveSheet.Cells[row, column].BackColor = Color.White;
                    }
                }
                int num3 = 1;
                if (column < 17)
                {
                    return;
                }
                if (spdDataCollection.ActiveSheet.Cells[row, 0].Value.ToString() == "GRADE-T")
                {
                    num3 = MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[row, 9].Value);
                    for (int i = 17; i < 17 + num3; i++)
                    {
                        double num4 = ((spdDataCollection.ActiveSheet.Cells[row, i].Text == "") ? 0.0 : MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[row, i].Text));
                        if (i == 17)
                        {
                            num2 = num4;
                        }
                        if (num2 > num4)
                        {
                            num2 = num4;
                        }
                        if (num < num4)
                        {
                            num = num4;
                        }
                    }
                    for (int j = 0; j < spdDataCollection.ActiveSheet.RowCount; j++)
                    {
                        if (spdDataCollection.ActiveSheet.Cells[j, 0].Value.ToString() == "GRADE-DEV" && spdDataCollection.ActiveSheet.Cells[j, 9].Value.ToString() == "1")
                        {
                            spdDataCollection.ActiveSheet.Cells[j, 17].Value = Math.Round(num - num2, 2, MidpointRounding.AwayFromZero);
                        }
                    }
                }
                else
                {
                    if (!(spdDataCollection.ActiveSheet.Cells[row, 0].Value.ToString() == "MAX-D") || !MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[row, column].Value))
                    {
                        return;
                    }
                    double num5 = MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[row, column].Value);
                    for (int k = 0; k < spdDataCollection.ActiveSheet.RowCount; k++)
                    {
                        if (spdDataCollection.ActiveSheet.Cells[k, 0].Value.ToString() == "REAL-D")
                        {
                            spdDataCollection.ActiveSheet.Cells[k, column].Value = Math.Round(num5 - d_real_d_ref, 2, MidpointRounding.AwayFromZero);
                        }
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
                if (Collect_Inspection_Data() && (!(cdvDept.Text == "GRT") || Collect_Data_ISP()))
                {
                    SelectedItemChangedByColSet();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtInspectionStatus_TextChanged(object sender, EventArgs e)
        {
            if (txtInspectionStatus.Text == "")
            {
                return;
            }
            if (txtInspectionStatus.Text == "R" || txtInspectionStatus.Text == "H")
            {
                if (txtInspectionStatus.Text == "R")
                {
                    btnHold.Enabled = true;
                }
                else if (txtInspectionStatus.Text == "H")
                {
                    btnHold.Enabled = false;
                }
                cdvInspectionJudgeFlag.Enabled = true;
                txtGoodEa.Enabled = true;
                cdvReworkOper.Enabled = true;
                if (tabControl1.SelectedIndex == 0)
                {
                    btnJudge.Enabled = true;
                }
                else
                {
                    btnJudge.Enabled = false;
                }
                spdLossInfo.ActiveSheet.OperationMode = OperationMode.Normal;
                cdvColSetID.Enabled = true;
                spdDataCollectionISP.ActiveSheet.OperationMode = OperationMode.Normal;
            }
            else if (txtInspectionStatus.Text == "C" || txtInspectionStatus.Text == "S" || txtInspectionStatus.Text == "Q")
            {
                cdvInspectionJudgeFlag.Enabled = false;
                txtGoodEa.Enabled = false;
                cdvReworkOper.Enabled = false;
                btnJudge.Enabled = false;
                btnHold.Enabled = false;
                spdLossInfo.ActiveSheet.OperationMode = OperationMode.ReadOnly;
                spdDataCollectionISP.ActiveSheet.OperationMode = OperationMode.Normal;
                cdvColSetID.Enabled = false;
            }
        }

        private void tpgInspCommon_Click(object sender, EventArgs e)
        {
        }

        private void cdvInspectionType_ButtonPress(object sender, EventArgs e)
        {
            TRSNode tRSNode = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            MPCF.InitListView(cdvInspectionType.GetListView);
            MPCR.SetInMsg(tRSNode);
            tRSNode.ProcStep = '1';
            tRSNode.AddString("SQL", "SELECT KEY_1 AS CODE,          DATA_1 AS VALUE    FROM MGCMTBLDAT     WHERE FACTORY = '" + MPGV.gsFactory + "'   AND TABLE_NAME = 'C_INSP_TYPE'   AND KEY_1 != 'IQC'   ORDER BY DATA_2 ");
            while (MPCR.CallService("BAS", "BAS_SQL_Query", tRSNode, ref out_node))
            {
                MPCR.FillDataView(cdvInspectionType.GetListView, out_node);
                tRSNode.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
                if (out_node.GetInt("NEXT_ROW") <= 0)
                {
                    break;
                }
            }
        }

        private void txtLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == '\r')
                {
                    fnLotKeyPress();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvColSetID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                string text = "";
                string text2 = "";
                int num = 0;
                if (txtInspID.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(478));
                    txtLotID.Focus();
                    return;
                }
                text = cdvInspOper.Text;
                text2 = txtMatID.Text;
                num = Convert.ToInt32(txtMatVer.Text);
                cdvColSetID.Init();
                MPCF.InitListView(cdvColSetID.GetListView);
                cdvColSetID.Columns.Add("Collection Set", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvColSetID.Columns.Add("Description", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvColSetID.SelectedSubItemIndex = 0;
                if (EDCLIST.ViewMFOColSetList(cdvColSetID.GetListView, '2', null, "", '0', text2, num, null, text, 'M', ' ', 'N', -1, -1))
                {
                    cdvColSetID.InsertEmptyRow(0, 1);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvColSetID_SelectedItemChanged(object sender, MCCodeViewSelChanged_EventArgs e)
        {
            SelectedItemChangedByColSet();
        }

        private void cdvInspectionJudgeFlag_ButtonPress(object sender, EventArgs e)
        {
        }

        private void cdvInspectionJudgeFlag_SelectedItemChanged(object sender, MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvReworkOper.Text = "";
                if (chkJudgeMaintain.Checked)
                {
                    if (MPCF.Trim(cdvInspectionJudgeFlag.Text) != "")
                    {
                        sJudgeCodeMaintain = cdvInspectionJudgeFlag.Text;
                    }
                    else
                    {
                        sJudgeCodeMaintain = "";
                    }
                }
                else
                {
                    sJudgeCodeMaintain = "";
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvReworkOper_ButtonPress(object sender, EventArgs e)
        {
            if (MPCF.Trim(cdvInspectionJudgeFlag.Text) == "R")
            {
                initReworkOperList(cdvReworkOper.GetListView);
            }
            else
            {
                cdvReworkOper.Init();
            }
        }

        private void btnJudge_Click(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.ShowMsgBox(MPCF.GetMessage(503), MessageBoxButtons.YesNo, 1) == DialogResult.Yes && Collect_Inspection_Data() && Inspection_Judge())
                {
                    string sLot_ID = spdLotList.ActiveSheet.GetValue(0, 0).ToString();
                    ViewLotInfo(sLot_ID);
                    txtLotID.Focus();
                    txtLotID.SelectAll();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLossInfo_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            int row = e.Row;
            int column = e.Column;
            if (e.Column == 5)
            {
                bool flag = !(bool)spdLossInfo.ActiveSheet.Cells[row, column].Value;
                if (flag)
                {
                    return;
                }
                for (int i = 0; i < spdLossInfo.ActiveSheet.RowCount; i++)
                {
                    if (i != row)
                    {
                        spdLossInfo.ActiveSheet.Cells[i, column].Value = flag;
                    }
                }
            }
            else if (e.Column == 4)
            {
                spdLossInfo.ActiveSheet.Cells[row, 3].Value = MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[row, 3].Value) + 1.0;
            }
        }

        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (tabControl1.SelectedIndex == 0)
            {
                if (txtInspectionStatus.Text == "R" || txtInspectionStatus.Text == "H")
                {
                    if (txtInspectionStatus.Text == "R")
                    {
                        btnHold.Enabled = true;
                    }
                    else if (txtInspectionStatus.Text == "H")
                    {
                        btnHold.Enabled = false;
                    }
                    btnJudge.Enabled = true;
                }
                else if (txtInspectionStatus.Text == "Q" || txtInspectionStatus.Text == "S" || txtInspectionStatus.Text == "C")
                {
                    btnHold.Enabled = false;
                    btnJudge.Enabled = false;
                }
            }
            else
            {
                btnHold.Enabled = false;
                btnJudge.Enabled = false;
            }
        }

        private void spdDataCollection_Change(object sender, ChangeEventArgs e)
        {
            if (e.Row >= 0)
            {
                int row = e.Row;
            }
        }

        private void cdvWorkPlace_SelectedItemChanged(object sender, MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvOper.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorkGroup_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvWorkGroup.Init();
                MPCF.InitListView(cdvWorkGroup.GetListView);
                cdvWorkGroup.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvWorkGroup.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvWorkGroup.SelectedSubItemIndex = 0;
                cdvWorkGroup.DisplaySubItemIndex = 1;
                if (BASLIST.ViewGCMDataList(cdvWorkGroup.GetListView, '1', "C_WORKER_GROUP"))
                {
                    cdvWorkGroup.InsertEmptyRow(0, 1);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorkGroup_SelectedItemChanged(object sender, MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvWorkGroup.Text) != "")
                {
                    ViewWorkerList();
                }
                else
                {
                    MPCF.ClearList(spdWorkerList);
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
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                }
                else
                {
                    viewOperList(cdvOper.GetListView);
                    cdvOper.InsertEmptyRow(0, 1);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDept_SelectedItemChanged(object sender, MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvOper.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnHold_Click(object sender, EventArgs e)
        {
            try
            {
                if (VaildationCheckHold() && Update_Inspection_Status())
                {
                    string sLot_ID = spdLotList.ActiveSheet.GetValue(0, 0).ToString();
                    ViewLotInfo(sLot_ID);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnPop_Click(object sender, EventArgs e)
        {
            try
            {
                if (cdvOper.Text == "OC90030" || cdvOper.Text == "OG05260")
                {
                    frmPopSampleRndInspectionLotList frmPopSampleRndInspectionLotList2 = new frmPopSampleRndInspectionLotList();
                    frmPopSampleRndInspectionLotList2.StartPosition = FormStartPosition.CenterParent;
                    frmPopSampleRndInspectionLotList2.sArea_id = cdvDept.Text;
                    frmPopSampleRndInspectionLotList2.sArea_desc = cdvDept.DisplayText;
                    frmPopSampleRndInspectionLotList2.sOper_id = cdvOper.Text;
                    frmPopSampleRndInspectionLotList2.sOper_desc = cdvOper.DisplayText;
                    if (frmPopSampleRndInspectionLotList2.ShowDialog() != DialogResult.OK)
                    {
                        return;
                    }
                    if (frmPopSampleRndInspectionLotList2.sLot_id != "")
                    {
                        txtLotID.Text = frmPopSampleRndInspectionLotList2.sLot_id;
                        cdvOper.Text = frmPopSampleRndInspectionLotList2.sOper_id;
                        cdvOper.DisplayText = frmPopSampleRndInspectionLotList2.sOper_desc;
                        if (MPCF.Trim(txtLotID.Text) != "")
                        {
                            ViewLotInfo(txtLotID.Text);
                        }
                    }
                    frmPopSampleRndInspectionLotList2 = null;
                    return;
                }
                frmPopInspectionLotList frmPopInspectionLotList2 = new frmPopInspectionLotList();
                frmPopInspectionLotList2.StartPosition = FormStartPosition.CenterParent;
                frmPopInspectionLotList2.sArea_id = cdvDept.Text;
                frmPopInspectionLotList2.sArea_desc = cdvDept.DisplayText;
                frmPopInspectionLotList2.sOper_id = cdvOper.Text;
                frmPopInspectionLotList2.sOper_desc = cdvOper.DisplayText;
                if (frmPopInspectionLotList2.ShowDialog() != DialogResult.OK)
                {
                    return;
                }
                if (frmPopInspectionLotList2.sLot_id != "")
                {
                    txtLotID.Text = frmPopInspectionLotList2.sLot_id;
                    cdvOper.Text = frmPopInspectionLotList2.sOper_id;
                    cdvOper.DisplayText = frmPopInspectionLotList2.sOper_desc;
                    if (MPCF.Trim(txtLotID.Text) != "")
                    {
                        ViewLotInfo(txtLotID.Text);
                    }
                }
                frmPopInspectionLotList2 = null;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdFileRegistration_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            if (e.Column == 3)
            {
                if (txtInspID.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(478));
                    txtLotID.Focus();
                }
                else
                {
                    if (spdFileRegistration.ActiveSheet.ActiveRowIndex < 0)
                    {
                        return;
                    }
                    string text = "";
                    int activeRowIndex = spdFileRegistration.ActiveSheet.ActiveRowIndex;
                    string fileNo = MPCF.Trim(spdFileRegistration.ActiveSheet.Cells[activeRowIndex, 0].Value.ToString());
                    string image_code = MPCF.Trim(spdFileRegistration.ActiveSheet.Cells[activeRowIndex, 1].Value.ToString());
                    openFileDialog1.Reset();
                    openFileDialog1.Filter = "Images Files(*.jpg; *.jpeg; *.bmp; *.png; *.pdf)|*.jpg;*.jpeg;*.bmp;*.png;*.pdf";
                    openFileDialog1.DefaultExt = "jpg";
                    if (openFileDialog1.ShowDialog() == DialogResult.OK)
                    {
                        text = openFileDialog1.FileName;
                        FileInfo fileInfo = new FileInfo(text);
                        long num = fileInfo.Length / 1024;
                        if (num >= 2048)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(504));
                            return;
                        }
                        fnRegistrationFile(fileInfo, fileNo, image_code, txtInspID.Text, text);
                        ViewInspectionFile(txtInspID.Text);
                        spdFileRegistration.ActiveSheet.ActiveRowIndex = activeRowIndex;
                        fnFileSelectionChagned();
                    }
                }
            }
            else
            {
                if (e.Column != 4 || spdFileRegistration.ActiveSheet.ActiveRowIndex < 0)
                {
                    return;
                }
                if (txtInspID.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(478));
                    txtLotID.Focus();
                    return;
                }
                int activeRowIndex2 = spdFileRegistration.ActiveSheet.ActiveRowIndex;
                string text2 = MPCF.Trim(spdFileRegistration.ActiveSheet.Cells[activeRowIndex2, 0].Value.ToString());
                string text3 = MPCF.Trim(spdFileRegistration.ActiveSheet.Cells[activeRowIndex2, 1].Value.ToString());
                if (!(MPCF.Trim(text2) == ""))
                {
                    fnDeleteFile(text2);
                    ViewInspectionFile(txtInspID.Text);
                    spdFileRegistration.ActiveSheet.ActiveRowIndex = activeRowIndex2;
                    fnFileSelectionChagned();
                }
            }
        }

        private void spdFileRegistration_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            fnFileSelectionChagned();
        }

        private void spdLossInfo_Change(object sender, ChangeEventArgs e)
        {
        }

        private void frmTranInspectionRegistration_FormClosing(object sender, FormClosingEventArgs e)
        {
        }

        private void btnPrint_Click(object sender, EventArgs e)
        {
            try
            {
                Open_Port(cboPort.Text, 'Y');
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spScanner_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            Thread.Sleep(100);
            string text = "";
            try
            {
                text = spScanner.ReadExisting();
                if (!string.IsNullOrEmpty(text))
                {
                    string[] array = text.Split('\r');
                    IAsyncResult asyncResult = BeginInvoke(rh_Sanner, array[0]);
                    EndInvoke(asyncResult);
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void chkJudgeMaintain_CheckedChanged(object sender, EventArgs e)
        {
            if (chkJudgeMaintain.Checked)
            {
                sJudgeCodeMaintain = cdvInspectionJudgeFlag.Text;
            }
            else
            {
                sJudgeCodeMaintain = "";
            }
        }

        private void frmTranInspectionRegistration_FormClosed(object sender, FormClosedEventArgs e)
        {
            spScanner.Close();
            if (cboPort.SelectedIndex != -1)
            {
                MPCF.SaveRegSetting(Application.ProductName, base.Name, cboPort.Name, cboPort.SelectedItem.ToString());
            }
            else
            {
                MPCF.SaveRegSetting(Application.ProductName, base.Name, cboPort.Name, "");
            }
        }

        private void cboPort_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                if (cboPort.Text == "" && spScanner.IsOpen)
                {
                    spScanner.Close();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdDataCollection_EditModeOff(object sender, EventArgs e)
        {
            int activeRowIndex = spdDataCollection.ActiveSheet.ActiveRowIndex;
            int activeColumnIndex = spdDataCollection.ActiveSheet.ActiveColumnIndex;
            int rowCount = spdDataCollection.ActiveSheet.RowCount;
            int columnCount = spdDataCollection.ActiveSheet.ColumnCount;
            string text = "UT (";
            string text2 = "";
            int num = 0;
            int num2 = 0;
            int num3 = 17;
            double num4 = 0.0;
            double num5 = 0.0;
            try
            {
                if (activeColumnIndex >= 17)
                {
                    if (activeColumnIndex == columnCount - 1 || spdDataCollection.ActiveSheet.Cells[activeRowIndex, activeColumnIndex + 1].Locked)
                    {
                        if (activeRowIndex != rowCount - 1)
                        {
                            spdDataCollection.ActiveSheet.SetActiveCell(activeRowIndex + 1, 17);
                        }
                    }
                    else
                    {
                        spdDataCollection.ActiveSheet.SetActiveCell(activeRowIndex, activeColumnIndex + 1);
                    }
                }
                for (num = 0; num < spdDataCollection.ActiveSheet.RowCount; num++)
                {
                    if (!MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[num, num3].Value))
                    {
                        continue;
                    }
                    for (num2 = num3; num2 < spdDataCollection.ActiveSheet.ColumnCount && num2 <= 26; num2++)
                    {
                        if (num2 == num3)
                        {
                            text2 = text2 + "  " + spdDataCollection.ActiveSheet.Cells[num, 0].Text;
                            num4 = MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[num, num2].Value);
                            num5 = MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[num, num2].Value);
                        }
                        if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[num, num2].Value))
                        {
                            if (num4 < MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[num, num2].Value))
                            {
                                num4 = MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[num, num2].Value);
                            }
                            if (num5 > MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[num, num2].Value))
                            {
                                num5 = MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[num, num2].Value);
                            }
                        }
                    }
                    text2 = text2 + "(" + num5 + " ~ " + num4 + ") ";
                }
                lblMinMax.Text = text2;
                if ((!(cdvOper.Text == "OC04120") && !(cdvOper.Text == "OC04091")) || !chkUtcomm.Checked)
                {
                    return;
                }
                for (num = 0; num < spdDataCollection.ActiveSheet.RowCount; num++)
                {
                    if (spdDataCollection.ActiveSheet.Cells[num, 0].Text == "GRADE-T")
                    {
                        text = spdDataCollection.ActiveSheet.Cells[num, 0].Text + "(";
                        for (num2 = 1; num2 - 1 + num3 < spdDataCollection.ActiveSheet.ColumnCount && num2 <= 26; num2++)
                        {
                            text = text + " / " + spdDataCollection.ActiveSheet.Cells[num, num2 - 1 + num3].Text;
                        }
                        text += ")";
                    }
                }
                txtComment.Text = text;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnGCM_Click(object sender, EventArgs e)
        {
            try
            {
                frmPopGcmData frmPopGcmData = new frmPopGcmData();
                frmPopGcmData.StartPosition = FormStartPosition.CenterParent;
                frmPopGcmData.sTable_name = "C_ROUND_CAL";
                if (MPGV.gcLanguage == '2')
                {
                    frmPopGcmData.sTable_name_desc = "실제직경 예외처리";
                    frmPopGcmData.sComment = "아래 기본조건에서 예외조건 품목들은 해당 화면에 등록바랍니다.\r\nIPOL의 규격60.0, 60.5, 75.0 , 75.7 인경우 0.5 그외 0 / IBON의 규격 50.0, 55.0, 60.0 인경우 0 그외 1\r\nIBON,IPOL 아닌경우 0.5";
                }
                else
                {
                    frmPopGcmData.sTable_name_desc = "REAL-D Exclude Calc";
                    frmPopGcmData.sComment = "Please register the exceptional items on the screen below.\r\nIPOL's specifications of 60.0, 60.5, 75.0, 75.7 are zero other than 0.5 / IBON's specifications of 50.0, 55.0, 60.0 are 1 other than 0\r\nBesides that. 0";
                }
                if (frmPopGcmData.ShowDialog() == DialogResult.OK)
                {
                    frmPopGcmData = null;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOper_SelectedItemChanged(object sender, MCCodeViewSelChanged_EventArgs e)
        {
            pnlGCM.Visible = false;
            pnlUtComm.Visible = false;
            if (cdvOper.Text == "OC05060" || cdvOper.Text == "OC05070")
            {
                pnlGCM.Visible = true;
                //chkAutoRefresh.Checked = false;
                //tmrTimer.Stop();
            }
            else if (cdvOper.Text == "OC04120")
            {
                pnlUtComm.Visible = true;
                //chkAutoRefresh.Checked = false;
                //tmrTimer.Stop();
            }
        }

        private void btnSpec_Click(object sender, EventArgs e)
        {
            SpecPopUp();
        }

        private void txtLastSpecTime_Click(object sender, EventArgs e)
        {
            SpecPopUp();
        }

        private void ViewSpecLastEditTime(string matid, string oper)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "MAT_ID";
                array[1].sCondition_Value = matid;
                array[2].sCondition_ID = "OPER";
                array[2].sCondition_Value = oper;
                if (!TPDR.GetDataOne("", ref dt, "CQCM0001-001", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdLossInfo);
                }
                else
                {
                    txtLastSpecTime.Text = dt.Rows[0]["LAST_EDIT_TIME"].ToString();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtGoodEa_TextChanged(object sender, EventArgs e)
        {
            try
            {
                if (!(base.ActiveControl.Name != "txtGoodEa"))
                {
                    if (spdLotList.ActiveSheet.RowCount == 0)
                    {
                        txtGoodKg.Text = "0";
                        txtGoodEa.Text = "0";
                    }
                    else
                    {
                        Sumtotalqty("EA");
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtGoodKg_TextChanged(object sender, EventArgs e)
        {
            try
            {
                if (!(base.ActiveControl.Name != "txtGoodKg"))
                {
                    if (spdLotList.ActiveSheet.RowCount == 0)
                    {
                        txtGoodKg.Text = "0";
                        txtGoodEa.Text = "0";
                    }
                    else
                    {
                        Sumtotalqty("KG");
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtGoodEa_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsDigit(e.KeyChar) && e.KeyChar != Convert.ToChar(Keys.Back))
            {
                e.Handled = true;
            }
        }

        private void brnReturn_Click(object sender, EventArgs e)
        {
            if (spdLotList_Sheet1.RowCount != 0)
            {
                DeleteLotHistiry(spdLotList_Sheet1.Cells[spdLotList_Sheet1.ActiveRowIndex, 0].Text);
            }
        }

        private void btnColSetId_Click(object sender, EventArgs e)
        {
            try
            {
                if (cdvOper.Text == "")
                {
                    MPCF.ShowMsgBox("공정입력바랍니다.(Input Operation Please)");
                    return;
                }
                if (txtMatID.Text == "")
                {
                    MPCF.ShowMsgBox("품목입력바랍니다.(Input Material Please)");
                    return;
                }
                frmPopCollectionSetOper frmPopCollectionSetOper2 = new frmPopCollectionSetOper();
                frmPopCollectionSetOper2.sArea_id = cdvDept.Text;
                frmPopCollectionSetOper2.sArea_desc = cdvDept.DisplayText;
                frmPopCollectionSetOper2.sOper_id = cdvOper.Text;
                frmPopCollectionSetOper2.sOper_desc = cdvOper.DisplayText;
                frmPopCollectionSetOper2.sMat_id = txtMatID.Text;
                frmPopCollectionSetOper2.sMat_desc = txtMatDesc.Text;
                if (frmPopCollectionSetOper2.ShowDialog() == DialogResult.OK)
                {
                    frmPopCollectionSetOper2 = null;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdDataCollection_CellClick(object sender, CellClickEventArgs e)
        {
        }

        private void btnGCM3_Click_1(object sender, EventArgs e)
        {
            try
            {
                frmPopGcmData frmPopGcmData = new frmPopGcmData();
                frmPopGcmData.StartPosition = FormStartPosition.CenterParent;
                frmPopGcmData.sTable_name = "C_INSP_GRIT_SLEVE";
                frmPopGcmData.sTable_name_desc = "Sleve Size";
                frmPopGcmData.sComment = "성적서에 표기될 Sleve Size 정보 등록";
                if (frmPopGcmData.ShowDialog() == DialogResult.OK)
                {
                    frmPopGcmData = null;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdDataCollectionISP_Change(object sender, ChangeEventArgs e)
        {
            try
            {
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ultraButton1_Click(object sender, EventArgs e)
        {
            if (txtInspectionStatus.Text != "S")
            {
                cdvInspectionJudgeChange.Text = "";
                cdvInspectionJudgeChange.DisplayText = "";
                return;
            }
            switch (cdvInspectionJudgeFlag.Text)
            {
                case "P":
                case "U":
                case "Z":
                    if (cdvInspectionJudgeChange.Text == "P" || cdvInspectionJudgeChange.Text == "U" || cdvInspectionJudgeChange.Text == "Z")
                    {
                        if (MPCF.ShowMsgBox(MPCF.GetMessage(567), MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                        {
                            SaveIQcChange();
                        }
                    }
                    else
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(573));
                    }
                    break;
            }
        }

        private void cdvPdfOpen_Click(object sender, EventArgs e)
        {
            try
            {
                frmViewPDF frmViewPDF = new frmViewPDF();
                frmViewPDF.StartPosition = FormStartPosition.CenterParent;
                if (frmViewPDF.ShowDialog() == DialogResult.OK)
                {
                    frmViewPDF = null;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void rdoDualSpec_CheckedChanged(object sender, EventArgs e)
        {
            ViewLotInfo(txtLotID.Text);
        }

        private void rdoStSpec_CheckedChanged(object sender, EventArgs e)
        {
        }

        private void chkCommentMaintain_CheckedChanged(object sender, EventArgs e)
        {
            if (chkCommentMaintain.Checked)
            {
                sCommentMaintain = txtComment.Text;
            }
            else
            {
                sCommentMaintain = "";
            }
        }

        private void txtComment_TextChanged(object sender, EventArgs e)
        {
            try
            {
                if (chkCommentMaintain.Checked)
                {
                    if (MPCF.Trim(txtComment.Text) != "")
                    {
                        sCommentMaintain = txtComment.Text;
                    }
                }
                else
                {
                    sCommentMaintain = "";
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmTranInspectionRegistration_DragDrop(object sender, DragEventArgs e)
        {
            string[] array = (string[])e.Data.GetData(DataFormats.FileDrop);
            if (array.Length == 0)
            {
                return;
            }
            string text = array[0];
            if (txtInspID.Text == "")
            {
                MPCF.ShowMsgBox(MPCF.GetMessage(478));
                txtLotID.Focus();
            }
            else if (spdFileRegistration.ActiveSheet.ActiveRowIndex >= 0)
            {
                int activeRowIndex = spdFileRegistration.ActiveSheet.ActiveRowIndex;
                string fileNo = MPCF.Trim(spdFileRegistration.ActiveSheet.Cells[activeRowIndex, 0].Value.ToString());
                string image_code = MPCF.Trim(spdFileRegistration.ActiveSheet.Cells[activeRowIndex, 1].Value.ToString());
                FileInfo fileInfo = new FileInfo(text);
                long num = fileInfo.Length / 1024;
                if (num >= 2048)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(504));
                    return;
                }
                fnRegistrationFile(fileInfo, fileNo, image_code, txtInspID.Text, text);
                ViewInspectionFile(txtInspID.Text);
                spdFileRegistration.ActiveSheet.ActiveRowIndex = activeRowIndex;
                fnFileSelectionChagned();
            }
        }

        private void frmTranInspectionRegistration_DragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                e.Effect = DragDropEffects.Copy;
            }
            else
            {
                e.Effect = DragDropEffects.None;
            }
        }

        private void btnDrawingpage_Click(object sender, EventArgs e)
        {
            string fileName = txtDrawingPath.Text + " / " + MPCF.Trim(txtMatID.Text) + ".PDF";
            Process.Start(new ProcessStartInfo(fileName)
            {
                UseShellExecute = true
            });
        }

        private void btnadobeDown_Click(object sender, EventArgs e)
        {
            if (MPCF.ShowMsgBox("Adobe 공식사이트에서 다운로드는 Yes, 인트라넷에서 다운로드는 NO 클릭", MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
            {
                string fileName = "https://get.adobe.com/reader/";
                Process.Start(new ProcessStartInfo(fileName)
                {
                    UseShellExecute = true
                });
            }
            else
            {
                string fileName2 = txtDrawingPath.Text + " / " + MPCF.Trim(txtMatID.Text) + ".PDF";
                Process.Start(new ProcessStartInfo(fileName2)
                {
                    UseShellExecute = true
                });
            }
        }

        private void btnFileManager_Click(object sender, EventArgs e)
        {
            if (txtLotID.Text.Trim().Length != 0)
            {
                frmPopFtpUpDown frmPopFtpUpDown = new frmPopFtpUpDown();
                frmPopFtpUpDown.StartPosition = FormStartPosition.CenterParent;
                frmPopFtpUpDown.g_PopYn = "Y";
                frmPopFtpUpDown.g_LotId = txtLotID.Text;
                frmPopFtpUpDown.g_Mat_id = txtMatID.Text;
                frmPopFtpUpDown.g_Mat_Desc = txtMatDesc.Text;
                frmPopFtpUpDown.g_Area_Id = cdvDept.Text;
                frmPopFtpUpDown.g_SearchType = "B";
                if (frmPopFtpUpDown.ShowDialog() == DialogResult.OK)
                {
                    frmPopFtpUpDown = null;
                }
            }
        }

        private void pnlStsCond_Paint(object sender, PaintEventArgs e)
        {
        }

        private void btnRoundDataRead_Click(object sender, EventArgs e)
        {
            RoundOutFileRead();
        }

        private void btnRoundLotWrite_Click(object sender, EventArgs e)
        {
            RoundInFileWrite();
        }

        private void chkAutoRefresh_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void numRefreshSec_ValueChanged(object sender, EventArgs e)
        {
            if (chkAutoRefresh.Checked)
            {
                tmrTimer.Interval = (int)numRefreshSec.Value * 1000;
                tmrTimer.Start();
            }
            else
            {
                tmrTimer.Stop();
            }
        }

        private async void tmrTimer_Tick(object sender, EventArgs e)
        {

        }
    }

}
