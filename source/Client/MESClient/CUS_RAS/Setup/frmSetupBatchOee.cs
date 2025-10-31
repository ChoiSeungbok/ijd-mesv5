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


namespace CUS_RAS
{
    public partial class frmSetupBatchOee : frmTranForm02
    {
        public frmSetupBatchOee()
        {
            InitializeComponent();
            InitControl();
        }
        #region " Constant Definition "


        #endregion

        #region " Variable Definition "

        private enum RUNLOG
        {
            NO,                         // 1 : No.
            RUN_KEY,                    // 2 : Key No.
            START_TIME,                 // 3 : 시작시간
            END_TIME,                   // 4 : 종료시간
            RUN_MIN                     // 5 : 수행시간
        }

        private enum ERRLOG
        {
            NO,                         // 1 : No.
            ERR_DATE,                   // 2 : 발행일시
            RUN_KEY,                    // 3 : Key No.
            PROC_NAME,                  // 4 : Proc Name
            FLAG,                       // 4 : Flag
            ERR_CODE,                   // 5 : 에러 코드
            ERR_MSG                     // 6 : 에러 메시지
        }

        #endregion

        #region " Function Defintion "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
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
             

                switch (CHECK)
                {

                    case CSGC.CHECK.SAVE:
                        if (MPCF.Trim(cdvDept.Text) == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvWorkPlace.Text) == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                            cdvDept.Focus();
                            return false;
                        }
                        if (MPCF.Trim(cdvOper.Text) == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvDept.Focus();
                            return false;
                        }
                        if (MPCF.Trim(cdvOper.Text) == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvDept.Focus();
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

        private void ViewRunList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;
             
                dvcArgu[1].sCondition_ID = "START_TIME";
                dvcArgu[1].sCondition_Value = dtpFromDate.Text.Replace("-", "");

                dvcArgu[2].sCondition_ID = "END_TIME";
                dvcArgu[2].sCondition_Value = dtpToDate.Text.Replace("-", "");

                if (TPDR.GetDataOne("", ref dt, "CRAS1001-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdRunLog);
                    return;
                }

                MPCF.ClearList(spdRunLog);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdRunLog.ActiveSheet.RowCount++;

                    spdRunLog.ActiveSheet.SetValue(i, (int)RUNLOG.NO, (i+1));
                    spdRunLog.ActiveSheet.Cells[i, (int)RUNLOG.RUN_KEY].Value = dt.Rows[i]["RUN_KEY"];
                    spdRunLog.ActiveSheet.Cells[i, (int)RUNLOG.START_TIME].Value = dt.Rows[i]["START_TIME"];
                    spdRunLog.ActiveSheet.Cells[i, (int)RUNLOG.END_TIME].Value = dt.Rows[i]["END_TIME"]; 
                    spdRunLog.ActiveSheet.Cells[i, (int)RUNLOG.RUN_MIN].Value = dt.Rows[i]["RUN_MIN"];

                }

                return;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewErrList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                
                dvcArgu[0].sCondition_ID = "START_TIME";
                dvcArgu[0].sCondition_Value = dtpFromDate.Text.Replace("-", "");

                dvcArgu[1].sCondition_ID = "END_TIME";
                dvcArgu[1].sCondition_Value = dtpToDate.Text.Replace("-", "");

                if (TPDR.GetDataOne("", ref dt, "CRAS1001-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdErrLog);
                    return;
                }

                MPCF.ClearList(spdErrLog);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdErrLog.ActiveSheet.RowCount++;

                    spdErrLog.ActiveSheet.SetValue(i, (int)ERRLOG.NO, (i + 1));
                    spdErrLog.ActiveSheet.Cells[i, (int)ERRLOG.ERR_DATE].Value = dt.Rows[i]["ERR_DATE"]; 
                    spdErrLog.ActiveSheet.Cells[i, (int)ERRLOG.RUN_KEY].Value = dt.Rows[i]["RUN_KEY"];
                    spdErrLog.ActiveSheet.Cells[i, (int)ERRLOG.PROC_NAME].Value = dt.Rows[i]["PROC_NAME"];
                    spdErrLog.ActiveSheet.Cells[i, (int)ERRLOG.FLAG].Value = dt.Rows[i]["FLAG"];
                    spdErrLog.ActiveSheet.Cells[i, (int)ERRLOG.ERR_CODE].Value = dt.Rows[i]["ERR_CODE"];
                    spdErrLog.ActiveSheet.Cells[i, (int)ERRLOG.ERR_MSG].Value = dt.Rows[i]["ERR_MESG"];
                }

                return;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        
        private bool ViewOperList(Control control, string sArea, string sSubAreaId)
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

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = sSubAreaId;

                if (TPDR.GetDataOne("", ref dt, "CRAS1001-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }

                foreach (DataRow row in dt.Rows)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(row["OPER_CODE"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            //   itmX.SubItems.Add(row["CODE"].ToString());
                            itmX.SubItems.Add(row["OPER_DESC"].ToString());
                        }
                       ((ListView)control).Items.Add(itmX);
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                throw ex;
            }
        }

        private bool ViewResList(Control control, string sArea, string sSubAreaId, string sOper)
        {
            try
            {
                ListViewItem itmX;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sArea;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = sSubAreaId;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = sOper;

                if (TPDR.GetDataOne("", ref dt, "CRAS1001-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }

                foreach (DataRow row in dt.Rows)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(row["RES_ID"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            //   itmX.SubItems.Add(row["CODE"].ToString());
                            itmX.SubItems.Add(row["RES_DESC"].ToString());
                        }
                       ((ListView)control).Items.Add(itmX);
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                throw ex;
            }
        }
        #endregion

        #region " Event Defintion "
        private void frmSetupBatchOee_Load(object sender, EventArgs e)
        {
            try
            {
                MPCF.FieldClear(pnlStsCond);

                dtpToDate.Text = DateTime.Now.AddDays(-1).ToShortDateString();
                dtpFromDate.Text = DateTime.Now.AddDays(-1).ToShortDateString();              

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

                ViewRunList();
                ViewErrList();

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
               // DialogResult dr = MessageBox.Show(MPCF.GetMessage(498), "Info", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
                //if (dr == DialogResult.No || dr == DialogResult.Cancel)
               // {
               //     return;
               // }

                if (!CheckCondition(CSGC.CHECK.SAVE))
                    return;
                                

                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';

                in_node.AddString("FLAG", "A");
                in_node.AddString("AREA_ID", string.IsNullOrEmpty(cdvDept.Text.Trim()) ? "%" : cdvDept.Text.Trim());
                in_node.AddString("SUB_AREA_ID", string.IsNullOrEmpty(cdvWorkPlace.Text.Trim()) ? "%" : cdvWorkPlace.Text.Trim());
                in_node.AddString("OPER", string.IsNullOrEmpty(cdvOper.Text.Trim()) ? "%" : cdvOper.Text.Trim());
                in_node.AddString("LINE_ID", "%");
                in_node.AddString("RES_ID", string.IsNullOrEmpty(cdvResId.Text.Trim()) ? "%" : cdvResId.Text.Trim());
                in_node.AddString("START_DATE", dtpFromDate.Text.Replace("-", ""));
                in_node.AddString("END_DATE", dtpToDate.Text.Replace("-", ""));                
                in_node.AddString("CMF_1", "%");
                in_node.AddString("CMF_2", "%");
                in_node.AddString("CMF_3", "%");
                in_node.AddString("CMF_4", "%");
                in_node.AddString("CMF_5", "%");

                if (MPCR.CallService("CUS_RAS", "CUS_RAS_Batch_Oee", in_node, ref out_node) == false)
                {
                   // txtResult.Text = out_node.GetChar("OUT_ERR_CODE").ToString();
                    //txtResultCode.Text = out_node.GetString("OUT_MSG_CODE");
                   // txtResultMessage.Text = out_node.GetString("OUT_MSG_REP_WORD");

                    return;
                }

                //txtResult.Text = out_node.GetChar("OUT_ERR_CODE").ToString();
               // txtResultCode.Text = out_node.GetString("OUT_MSG_CODE");
                //txtResultMessage.Text = out_node.GetString("OUT_MSG_REP_WORD");

                MPCR.ShowSuccessMsg(out_node);

                ViewRunList();
                ViewErrList();

                return;

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
                cdvResId.Init();
                MPCF.InitListView(cdvResId.GetListView);
                cdvResId.Columns.Add("RES_ID", 50, HorizontalAlignment.Left);
                cdvResId.Columns.Add("RED_DESC", 100, HorizontalAlignment.Left);
                cdvResId.DisplaySubItemIndex = 1;
                cdvResId.SelectedSubItemIndex = 0;

                if (ViewResList(cdvResId.GetListView, cdvDept.Text, cdvWorkPlace.Text, cdvOper.Text) == false)
                {
                    return;
                }
                cdvResId.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

            
        }

        private void cdvOper_ButtonPress(object sender, EventArgs e)
        {
            try
            {

                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("OPER_CODE", 50, HorizontalAlignment.Left);
                cdvOper.Columns.Add("OPER_DESC", 100, HorizontalAlignment.Left);
                cdvOper.DisplaySubItemIndex = 1;
                cdvOper.SelectedSubItemIndex = 0;

                if (ViewOperList(cdvOper.GetListView, cdvDept.Text, cdvWorkPlace.Text) == false)
                {
                    return;
                }
                cdvOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        #endregion


    }
}
