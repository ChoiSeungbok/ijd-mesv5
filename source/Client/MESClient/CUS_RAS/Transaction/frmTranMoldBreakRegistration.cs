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

//CRAS2009
namespace CUS_RAS
{
    public partial class frmTranMoldBreakRegistration : CUS_COM.frmTranForm05
    {
        public frmTranMoldBreakRegistration()
        {
            InitializeComponent();
            InitControl();
        }

        #region " Constant Definition "

        private enum MOLD_INFO : int
        {
            CHK,
            TOOL_ID,
            MAT_ID,
            MAT_DESC,
            MOLD_MODEL,
            MOLD_TYPE,
            AREA_ID,
            AREA_DESC,
            OPER, 
            OPER_DESC,
            BREAK_DATE,
            BREAK_YYYY,
            BREAK_MM,
            BREAK_DD,
            BREAK_WEEK,
            TOOL_KIND,
            TOOL_KIND_DESC,
            OCCUR_TIME,
            RES_ID,
            RES_DESC,
            CAR,
            HOGI_CAR,
            WORKER_ID,
            WORKER_DESC,
            TOP_BASE,
            TOP_BASE_DESC,
            USE_COUNT,
            ISSUE_COMMENT,
            ISSUE_TYPE,
            ISSUE_TYPE_DESC,
            BREAK_CAUSE,
            ACTION_COMMENT,
            BO_SEC,
            BREAK_PATTERN,
            BREAK_PATTERN_DESC,
            CROWN_NO,
            CARBIDE_LOT,
            SIZE_1,
            SIZE_2,
            SIZE_3,
            C_SCAN,
            C_SCAN_DESC,
            BREAK_TYPE,
            BREAK_TYPE_DESC,
            VENDOR_LOT_ID,
            MAT_TYPE,
            MAT_TYPE_DESC,
            GRADE,
            GRADE_DESC,
            BO_DIE_NO,
            D10_TYPE,
            D10_TYPE_DESC,
            D10_CREATE_TIME,
            D10_WEIGHT,
            D10_HEIGHT,
            M15_LOT_ID,
            M13_LOT_ID,
            REMARK,
            BK_TYPE,
        }

        #endregion

        #region " Variable Definition "

        private string preText;

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnRequest.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //공정 조회
        public bool ViewToolOper(Control control, string sArea_id)
        {
            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sArea_id;

                if (TPDR.GetDataOne("", ref dt, "CRAS2009-002", dvcArgu, false, false, ref sSql) == false)
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

        public bool ViewMatType(Control control, string sArea_id)
        {
            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sArea_id;

                if (TPDR.GetDataOne("", ref dt, "CRAS2009-004", dvcArgu, false, false, ref sSql) == false)
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
                        itmX = new ListViewItem(row["MAT_TYPE"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["MAT_TYPE"].ToString());
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

        private void ViewToolInfo()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text + "%";

                dvcArgu[3].sCondition_ID = "TOOL_GRP";
                dvcArgu[3].sCondition_Value = cdvModel.Text + "%";

                dvcArgu[4].sCondition_ID = "TOOL_TYPE";
                dvcArgu[4].sCondition_Value = cdvToolType.Text + "%";

                dvcArgu[5].sCondition_ID = "TOOL_ID";
                dvcArgu[5].sCondition_Value = txtToolId.Text + "%";

                if (TPDR.GetDataOne("", ref dt, "CRAS2009-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    MPCF.ClearList(spdToolList);

                    return;
                }

                MPCF.ClearList(spdToolList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdToolList.ActiveSheet.RowCount++;

                    spdToolList.ActiveSheet.SetValue(i, (int)MOLD_INFO.CHK, false);
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.TOOL_ID].Value = dt.Rows[i]["TOOL_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MOLD_MODEL].Value = dt.Rows[i]["MOLD_MODEL"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MOLD_TYPE].Value = dt.Rows[i]["MOLD_TYPE"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BREAK_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["BREAK_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BREAK_YYYY].Value = dt.Rows[i]["BREAK_YYYY"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BREAK_MM].Value = dt.Rows[i]["BREAK_MM"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BREAK_DD].Value = dt.Rows[i]["BREAK_DD"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BREAK_WEEK].Value = dt.Rows[i]["BREAK_WEEK"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.TOOL_KIND].Value = dt.Rows[i]["TOOL_KIND"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.TOOL_KIND_DESC].Value = dt.Rows[i]["TOOL_KIND_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.OCCUR_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["OCCUR_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.RES_ID].Value = dt.Rows[i]["RES_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.RES_DESC].Value = dt.Rows[i]["RES_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.CAR].Value = dt.Rows[i]["CAR"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.HOGI_CAR].Value = dt.Rows[i]["HOGI_CAR"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.WORKER_ID].Value = dt.Rows[i]["WORKER_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.WORKER_DESC].Value = dt.Rows[i]["WORKER_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.TOP_BASE].Value = dt.Rows[i]["TOP_BASE"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.TOP_BASE_DESC].Value = dt.Rows[i]["TOP_BASE_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.USE_COUNT].Value = dt.Rows[i]["USE_COUNT"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.ISSUE_COMMENT].Value = dt.Rows[i]["ISSUE_COMMENT"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.ISSUE_TYPE].Value = dt.Rows[i]["ISSUE_TYPE"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.ISSUE_TYPE_DESC].Value = dt.Rows[i]["ISSUE_TYPE_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BREAK_CAUSE].Value = dt.Rows[i]["BREAK_CAUSE"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.ACTION_COMMENT].Value = dt.Rows[i]["ACTION_COMMENT"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BO_SEC].Value = dt.Rows[i]["BO_TIME"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BREAK_PATTERN].Value = dt.Rows[i]["BREAK_PATTERN"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BREAK_PATTERN_DESC].Value = dt.Rows[i]["BREAK_PATTERN_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.CROWN_NO].Value = dt.Rows[i]["CROWN_NO"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.CARBIDE_LOT].Value = dt.Rows[i]["CARBIDE_LOT"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.SIZE_1].Value = dt.Rows[i]["SIZE_1"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.SIZE_2].Value = dt.Rows[i]["SIZE_2"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.SIZE_3].Value = dt.Rows[i]["SIZE_3"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.C_SCAN].Value = dt.Rows[i]["C_SCAN"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.C_SCAN_DESC].Value = dt.Rows[i]["C_SCAN_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BREAK_TYPE].Value = dt.Rows[i]["BREAK_TYPE"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BREAK_TYPE_DESC].Value = dt.Rows[i]["BREAK_TYPE_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MAT_TYPE].Value = dt.Rows[i]["MAT_TYPE"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MAT_TYPE_DESC].Value = dt.Rows[i]["MAT_TYPE_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.GRADE].Value = dt.Rows[i]["GRADE"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.GRADE_DESC].Value = dt.Rows[i]["GRADE_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BO_DIE_NO].Value = dt.Rows[i]["BO_DIE_NO"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.D10_TYPE].Value = dt.Rows[i]["D10_TYPE"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.D10_TYPE_DESC].Value = dt.Rows[i]["D10_TYPE_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.D10_CREATE_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["D10_CREATE_TIME"].ToString(), DATE_TIME_FORMAT.TIME);
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.D10_WEIGHT].Value = dt.Rows[i]["D10_WEIGHT"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.D10_HEIGHT].Value = dt.Rows[i]["D10_HEIGHT"];                    
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.M15_LOT_ID].Value = dt.Rows[i]["M15_LOT_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.M13_LOT_ID].Value = dt.Rows[i]["M13_LOT_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.REMARK].Value = dt.Rows[i]["REMARK"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.BK_TYPE].Value = dt.Rows[i]["BK_TYPE"];

                }

                MPCF.FitColumnHeader(spdToolList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool SaveData()
        {
            try
            {
                TRSNode in_node = new TRSNode("Tool_Code_In");
                TRSNode out_node = new TRSNode("Tool_Code_Out");
                TRSNode tool_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("AREA_ID", cdvDept.Text);

                for (int i = 0; i < spdToolList.ActiveSheet.RowCount; i++)
                {
                    if (spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        tool_list = in_node.AddNode("TOOL_TBL");
                        tool_list.AddString("TOOL_ID", spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.TOOL_ID].Text);
                    }
                }

                in_node.AddString("BREAK_DATE", dtpWorkDate.Text.Replace("-", "").Replace(":", ""));
                in_node.AddString("OCCUR_TIME", dtpOccurDate.Text.Replace("-", "").Replace(":", "") + dtpOccurTime.Value.Hour.ToString() + dtpOccurTime.Value.Minute.ToString() + dtpOccurTime.Value.Second.ToString());
                in_node.AddString("TOOL_KIND", cdvMoldKind.Text);
                in_node.AddString("WORKER_ID", cdvWorker.Text);
                in_node.AddString("ISSUE_TYPE", cdvIssueType.Text);
                in_node.AddString("ISSUE_COMMENT", txtIssueComment.Text);
                in_node.AddString("BREAK_CAUSE", txtBreakCause.Text);
                in_node.AddString("ACTION_COMMENT", txtActionComment.Text);
                in_node.AddString("BO_TIME", txtBosec.Text);
                in_node.AddString("BREAK_PATTERN", cdvBreakPattern.Text);
                in_node.AddString("CROWN_NO", txtCrownNo.Text);
                in_node.AddString("CARBIDE_LOT", txtCarbideLot.Text);
                in_node.AddDouble("SIZE_1", MPCF.ToDbl(txtSize1.Text));
                in_node.AddDouble("SIZE_2", MPCF.ToDbl(txtSize2.Text));
                in_node.AddDouble("SIZE_3", MPCF.ToDbl(txtSize3.Text));
                in_node.AddString("C_SCAN", cdvCscan.Text);
                in_node.AddString("BREAK_TYPE", cdvBreakType.Text);
                in_node.AddString("MAT_TYPE", cdvMaterialType.Text);
                in_node.AddString("GRADE", cdvGrade.Text);
                in_node.AddString("BO_DIE_NO", txtBoDieNo.Text);
                in_node.AddString("D10_TYPE", cdvD10Type.Text);
                in_node.AddString("D10_CREATE_TIME", dtpD10CreateDate.Text.Replace("-", "").Replace(":", "") + "000000");
                in_node.AddDouble("D10_WEIGHT", MPCF.ToDbl(txtD10Weight.Text));
                in_node.AddDouble("D10_HEIGHT", MPCF.ToDbl(txtD10Height.Text));
                in_node.AddString("M15_LOT_ID", txtM15Lot.Text);
                in_node.AddString("M13_LOT_ID", txtM13Lot.Text);
                in_node.AddString("REMARK", txtRemark.Text);


                //일단 입력 안하면  PROD 값 양산으로
                if (cdvBkType.Text == "")
                {
                    in_node.AddString("CMF_1", "PROD");
                }
                else
                {
                    in_node.AddString("CMF_1", cdvBkType.Text);
                }


                if (MPCR.CallService("CUS_RAS", "CUS_RAS_Mold_Break_Registration", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool RequestData()
        {
            try
            {
                TRSNode in_node = new TRSNode("Tool_Code_In");
                TRSNode out_node = new TRSNode("Tool_Code_Out");
                TRSNode tool_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
                in_node.AddString("AREA_ID", cdvDept.Text);

                for (int i = 0; i < spdToolList.ActiveSheet.RowCount; i++)
                {
                    if (spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        tool_list = in_node.AddNode("TOOL_TBL");
                        tool_list.AddString("TOOL_ID", spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.TOOL_ID].Text);
                    }
                }

                if (MPCR.CallService("CUS_RAS", "CUS_RAS_Mold_Break_Registration", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            int iLotCount = 0;

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

                        break;

                    case CSGC.CHECK.SAVE:

                        for (int i = 0; i < spdToolList.ActiveSheet.RowCount; i++)
                        {
                            if (spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                                iLotCount++;
                        }

                        if (iLotCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(305));
                            return false;
                        }

                        break;

                    case CSGC.CHECK.CONFIRM:

                        for (int i = 0; i < spdToolList.ActiveSheet.RowCount; i++)
                        {
                            if (spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                                iLotCount++;
                        }

                        if (iLotCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(305));
                            return false;
                        }

                        //CMN462 INFO -진짜 폐기처리 하시겠습니까?
                        if (MPCF.ShowMsgBox(MPCF.GetMessage(462), MessageBoxButtons.YesNo, 1) == DialogResult.No)
                        {
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

        private void ClearData(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "ALL":

                        MPCF.ClearList(spdToolList);
                        MPCF.FieldClear(panBeakInfo);

                        txtUseCount.Text = "0";
                        txtSize1.Text = "0";
                        txtSize2.Text = "0";
                        txtSize3.Text = "0";
                        txtD10Weight.Text = "0";
                        txtD10Height.Text = "0";

                        break;

                    case "INFO":

                        MPCF.FieldClear(panBeakInfo);

                        txtUseCount.Text = "0";
                        txtSize1.Text = "0";
                        txtSize2.Text = "0";
                        txtSize3.Text = "0";
                        txtD10Weight.Text = "0";
                        txtD10Height.Text = "0";

                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        protected string CheckTextNumeric(string text)
        {
            double var = 0.0;
            bool change = double.TryParse(text, out var);

            try
            {               
                if (preText != null)
                {
                    //다 지웠을때 0으로 넣어줌
                    if (text.Equals(""))
                    {
                        change = true;
                        text = "";
                    }
                    //숫자가 아니면 이전 텍스트를 보여준다
                    if (!change)
                    {
                        if (text.Equals("-"))
                        {
                            text = "-0";
                        }
                        else
                        {
                            text = preText;
                        }
                    }
                    //숫자인 경우 0 관련 처리
                    else if (this.Text.Length > 1 && !this.Text.Contains("."))
                    {
                        if (this.Text.StartsWith("0"))
                        {
                            text = this.Text.Remove(0, 1);
                        }
                        else if (this.Text.StartsWith("-0") && this.Text.Length > 2)
                        {
                            text = this.Text.Remove(1, 1);
                        }
                    }
                }

                return text;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return text;
            }
        }
        
        #endregion

        #region " Event Definition "

        private void frmTranMoldBreakRegistration_Load(object sender, EventArgs e)
        {
            try
            {

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvBkType_ButtonPress(object sender, EventArgs e)
        {
            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(cdvBkType.GetListView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';


            in_node.AddString("SQL", "SELECT 'PROD' AS CODE, 'Product(양산)' AS VALUE FROM DUAL UNION ALL "
            + "   SELECT 'RND' AS CODE, 'R&D(개발)' AS VALUE FROM DUAL  ");


            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return;
                }

                MPCR.FillDataView(cdvBkType.GetListView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);


            return;
        }
        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                ClearData("ALL");
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

                if (ViewToolOper(cdvOper.GetListView, cdvDept.Text) == false)
                {
                    return;
                }

                cdvOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvModel_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvModel.Init();
                MPCF.InitListView(cdvModel.GetListView);
                cdvModel.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvModel.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvModel.SelectedSubItemIndex = 0;
                cdvModel.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvModel.GetListView, '1', MPGC.MP_RAS_TOOL_GRP) == false)
                {
                    return;
                }

                cdvModel.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvToolType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvToolType.Init();
                MPCF.InitListView(cdvToolType.GetListView);
                cdvToolType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvToolType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToolType.SelectedSubItemIndex = 0;
                cdvToolType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvToolType.GetListView, '1', CSGC.CP_GCM_MOLD_TYPE) == false)
                {
                    return;
                }

                cdvToolType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMoldKind_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvMoldKind.Init();
                MPCF.InitListView(cdvMoldKind.GetListView);
                cdvMoldKind.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvMoldKind.Columns.Add("Desc", 0, HorizontalAlignment.Left);
                cdvMoldKind.SelectedSubItemIndex = 0;
                cdvMoldKind.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvMoldKind.GetListView, '1', "C_MOLD_KIND") == false)
                {
                    return;
                }

                cdvMoldKind.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorker_ButtonPress(object sender, EventArgs e)
        {
            string sViewID = "";
            try
            {
                sViewID = "CRAS2009-003";

                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }

                cdvWorker.Init();
                MPCF.InitListView(cdvWorker.GetListView);
                cdvWorker.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWorker.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWorker.SelectedSubItemIndex = 0;
                cdvWorker.DisplaySubItemIndex = 1;

                //요청자 호출 (Sub Area 는 넣지 않음)
                if (COM_LIST.ViewWorkerList(cdvWorker.GetListView, sViewID, cdvDept.Text, "") == false)
                {
                    return;
                }

                cdvWorker.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvIssueType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvIssueType.Init();
                MPCF.InitListView(cdvIssueType.GetListView);
                cdvIssueType.Columns.Add("Operation", 0, HorizontalAlignment.Left);
                cdvIssueType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvIssueType.SelectedSubItemIndex = 0;
                cdvIssueType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvIssueType.GetListView, '1', "C_ISSUE_TYPE") == false)
                {
                    return;
                }

                cdvIssueType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvBreakPattern_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvBreakPattern.Init();
                MPCF.InitListView(cdvBreakPattern.GetListView);
                cdvBreakPattern.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvBreakPattern.Columns.Add("Desc", 50, HorizontalAlignment.Left);
                cdvBreakPattern.SelectedSubItemIndex = 0;
                cdvBreakPattern.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvBreakPattern.GetListView, '1', "C_BREAK_PATTERN") == false)
                {
                    return;
                }

                cdvBreakPattern.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvCscan_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvCscan.Init();
                MPCF.InitListView(cdvCscan.GetListView);
                cdvCscan.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvCscan.Columns.Add("Desc", 50, HorizontalAlignment.Left);
                cdvCscan.SelectedSubItemIndex = 0;
                cdvCscan.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvCscan.GetListView, '1', "C_CSCAN") == false)
                {
                    return;
                }
                 
                cdvCscan.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvBreakType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvBreakType.Init();
                MPCF.InitListView(cdvBreakType.GetListView);
                cdvBreakType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvBreakType.Columns.Add("Desc", 0, HorizontalAlignment.Left);
                cdvBreakType.SelectedSubItemIndex = 0;
                cdvBreakType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvBreakType.GetListView, '1', "C_MOLD_BREAK_TYPE") == false)
                {
                    return;
                }

                cdvBreakType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMaterialType_ButtonPress(object sender, EventArgs e)
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

                cdvMaterialType.Init();
                MPCF.InitListView(cdvMaterialType.GetListView);
                cdvMaterialType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                //cdvMaterialType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvMaterialType.SelectedSubItemIndex = 0;
                cdvMaterialType.DisplaySubItemIndex = 0;

                if (ViewMatType(cdvMaterialType.GetListView, cdvDept.Text) == false)
                {
                    return;
                }

                cdvMaterialType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvGrade_ButtonPress(object sender, EventArgs e)
        {
            string sGCMCode = "";

            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }

                if (cdvDept.Text == CSGV.gs_area_grit)
                    sGCMCode = "C_GRIT_MAT_GROUP";
                else 
                    sGCMCode = "C_CTM_MAT_GROUP";
                
                cdvGrade.Init();
                MPCF.InitListView(cdvGrade.GetListView);
                cdvGrade.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                //cdvBreakType.Columns.Add("Desc", 0, HorizontalAlignment.Left);
                cdvGrade.SelectedSubItemIndex = 0;
                cdvGrade.DisplaySubItemIndex = 0;

                if (BASLIST.ViewGCMDataList(cdvGrade.GetListView, '1', sGCMCode) == false)
                {
                    return;
                }

                cdvGrade.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvD10Type_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvD10Type.Init();
                MPCF.InitListView(cdvD10Type.GetListView);
                cdvD10Type.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                //cdvD10Type.Columns.Add("Desc", 0, HorizontalAlignment.Left);
                cdvD10Type.SelectedSubItemIndex = 0;
                cdvD10Type.DisplaySubItemIndex = 0;

                if (BASLIST.ViewGCMDataList(cdvD10Type.GetListView, '1', "C_D10_TYPE") == false)
                {
                    return;
                }

                cdvD10Type.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdToolList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)MOLD_INFO.CHK)
                    {
                        CSCF.CheckSpreadCell(spdToolList, 0, 0, true, true);
                    }
                }
                else
                {
                    for (int i = 0; i < spdToolList.ActiveSheet.RowCount; i++)
                    {
                        spdToolList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                    }

                    spdToolList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                    //정보 고정이 체크되어 있지 않는 경우
                    if (chkHold.Checked == false)
                    {
                        //시간 컨트롤
                        dtpWorkDate.Text = MPCF.MakeDateFormat(spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.BREAK_DATE].Text.Replace("-", "").Replace(":", ""), DATE_TIME_FORMAT.DATE);

                        if (spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.OCCUR_TIME].Text != "")
                        {
                            dtpOccurDate.Text = MPCF.MakeDateFormat(spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.OCCUR_TIME].Text.Replace("-", "").Replace(":", "").Replace(" ", ""), DATE_TIME_FORMAT.DATE);
                            dtpOccurTime.Text = MPCF.MakeDateFormat(spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.OCCUR_TIME].Text.Replace("-", "").Replace(":", "").Replace(" ", "").Substring(8, 6), DATE_TIME_FORMAT.TIME);
                        }
                        else
                        {
                            dtpOccurDate.Text = "";
                            dtpOccurTime.Text = "";
                        }

                        dtpD10CreateDate.Text = MPCF.MakeDateFormat(spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.D10_CREATE_TIME].Text.Replace("-", "").Replace(":", ""), DATE_TIME_FORMAT.DATETIME);

                        //그외
                        cdvMoldKind.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_KIND].Text;
                        cdvMoldKind.DisplayText = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_KIND_DESC].Text;
                        cdvWorker.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.WORKER_ID].Text;
                        cdvWorker.DisplayText = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.WORKER_DESC].Text;
                        txtCar.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.CAR].Text;
                        txtTopBase.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOP_BASE_DESC].Text;

                        if (MPCF.Trim(spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.USE_COUNT].Text) != "")
                            txtUseCount.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.USE_COUNT].Text;
                        else
                            txtUseCount.Text = "0";

                        cdvIssueType.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.ISSUE_TYPE].Text;
                        cdvIssueType.DisplayText = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.ISSUE_TYPE_DESC].Text;
                        txtIssueComment.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.ISSUE_COMMENT].Text;
                        txtBreakCause.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.BREAK_CAUSE].Text;
                        txtActionComment.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.ACTION_COMMENT].Text;
                        txtBosec.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.BO_SEC].Text;
                        cdvBreakPattern.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.BREAK_PATTERN].Text;
                        cdvBreakPattern.DisplayText = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.BREAK_PATTERN_DESC].Text;
                        txtCrownNo.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.CROWN_NO].Text;

                        if(MPCF.Trim(spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.CARBIDE_LOT].Text) != "")
                            txtCarbideLot.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.CARBIDE_LOT].Text;
                        else
                            txtCarbideLot.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text;

                        if (MPCF.Trim(spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.SIZE_1].Text) != "")
                            txtSize1.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.SIZE_1].Text;
                        else
                            txtSize1.Text = "0";

                        if (MPCF.Trim(spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.SIZE_2].Text) != "")
                            txtSize2.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.SIZE_2].Text;
                        else
                            txtSize2.Text = "0";

                        if (MPCF.Trim(spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.SIZE_3].Text) != "")
                            txtSize3.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.SIZE_3].Text;
                        else
                            txtSize3.Text = "0";

                        cdvCscan.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.C_SCAN].Text;
                        cdvCscan.DisplayText = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.C_SCAN_DESC].Text;
                        cdvBreakType.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.BREAK_TYPE].Text;
                        cdvBreakType.DisplayText = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.BREAK_TYPE_DESC].Text;
                        txtVendorLot.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.VENDOR_LOT_ID].Text;
                        cdvMaterialType.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.MAT_TYPE].Text;
                        cdvMaterialType.DisplayText = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.MAT_TYPE_DESC].Text;
                        cdvGrade.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.GRADE].Text;
                        cdvGrade.DisplayText = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.GRADE_DESC].Text;
                        txtBoDieNo.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.BO_DIE_NO].Text;
                        cdvD10Type.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.D10_TYPE].Text;
                        cdvD10Type.DisplayText = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.D10_TYPE_DESC].Text;

                        if (MPCF.Trim(spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.D10_WEIGHT].Text) != "")
                            txtD10Weight.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.D10_WEIGHT].Text;
                        else
                            txtD10Weight.Text = "0";

                        if (MPCF.Trim(spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.D10_HEIGHT].Text) != "")
                            txtD10Height.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.D10_HEIGHT].Text;
                        else
                            txtD10Height.Text = "0";

                        txtM13Lot.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.M13_LOT_ID].Text;
                        txtM15Lot.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.M15_LOT_ID].Text;
                        txtRemark.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.REMARK].Text;
                        cdvBkType.Text = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.BK_TYPE].Text;
                    }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtSize1_KeyDown(object sender, KeyEventArgs e)
        {            
            preText = txtSize1.Text;           
        }

        private void txtSize1_TextChanged(object sender, EventArgs e)
        {
            int cPosition = txtSize1.SelectionStart;
            txtSize1.Text = CheckTextNumeric(txtSize1.Text);
            txtSize1.Select(cPosition, 0);
        }

        private void txtSize2_KeyDown(object sender, KeyEventArgs e)
        {
            preText = txtSize2.Text;
        }

        private void txtSize2_TextChanged(object sender, EventArgs e)
        {
            int cPosition = txtSize2.SelectionStart;
            txtSize2.Text = CheckTextNumeric(txtSize2.Text);
            txtSize2.Select(cPosition, 0);
        }

        private void txtSize3_KeyDown(object sender, KeyEventArgs e)
        {
            preText = txtSize3.Text;
        }

        private void txtSize3_TextChanged(object sender, EventArgs e)
        {
            int cPosition = txtSize3.SelectionStart;
            txtSize3.Text = CheckTextNumeric(txtSize3.Text);
            txtSize3.Select(cPosition, 0);

        }

        private void txtD10Weight_KeyDown(object sender, KeyEventArgs e)
        {
            preText = txtD10Weight.Text;
        }

        private void txtD10Weight_TextChanged(object sender, EventArgs e)
        {
            int cPosition = txtD10Weight.SelectionStart;
            txtD10Weight.Text = CheckTextNumeric(txtD10Weight.Text);
            txtD10Weight.Select(cPosition, 0);
        }

        private void txtD10Height_KeyDown(object sender, KeyEventArgs e)
        {
            preText = txtD10Height.Text;
        }

        private void txtD10Height_TextChanged(object sender, EventArgs e)
        {
            int cPosition = txtD10Height.SelectionStart;
            txtD10Height.Text = CheckTextNumeric(txtD10Height.Text);
            txtD10Height.Select(cPosition, 0);
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            string sFileName = "";

            try
            {
                sFileName = "MoldBreakRegistration";

                EXTFUC.SaveExcel(spdToolList, sFileName);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnInit_Click(object sender, EventArgs e)
        {
            try
            {
                ClearData("INFO");
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
                ClearData("ALL");
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

                ViewToolInfo();
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

                if (SaveData())
                {
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnRequest_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.CONFIRM) == false)
                    return;

                if (RequestData())
                {
                    btnView.PerformClick();
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

