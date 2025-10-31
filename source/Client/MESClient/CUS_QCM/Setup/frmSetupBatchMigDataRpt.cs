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

namespace CUS_QCM
{
    public partial class frmSetupBatchMigDataRpt : frmTranForm02
    {
        public frmSetupBatchMigDataRpt()
        {
            InitializeComponent();
            InitControl();
        }

        #region " Constant Definition "


        #endregion

        #region " Variable Definition "

        #endregion

        #region " Function Defintion "

        private void InitControl()
        {
            try
            {
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void ClearList(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "PROCESS":
                        break;

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
                switch (CHECK)
                {

                    case CSGC.CHECK.SAVE:
                        //기간 필수 입력
                        //if (MPCF.Trim(cdvDept.Text) == "")
                        //{
                        //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                        //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                        //    cdvDept.Focus();
                        //    return false;
                        //}
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


        #endregion

        #region " Event Defintion "
        private void frmSetupBatchMigDataRpt_Load(object sender, EventArgs e)
        {
            try
            {
                MPCF.FieldClear(pnlStsCond);

                dtpToDate.Text = DateTime.Now.ToShortDateString();
                dtpFromDate.Text = DateTime.Now.AddDays(-5).ToShortDateString();

                cdvInspReprocFlag.Text = "N";           //N:이관되지 않은 것만 가지고와서 덮어쓰기, Y:전체
                cdvInspReprocFlag.DisplayText = "N";

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatId_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatId.DisplayText == "")
                cdvMatId.Text = "";
        }
        private void cdvInspReprocFlag_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvInspReprocFlag.Init();
                MPCF.InitListView(cdvInspReprocFlag.GetListView);
                cdvInspReprocFlag.Columns.Add("Type", 50, HorizontalAlignment.Left);
                //cdvInspReprocFlag.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvInspReprocFlag.SelectedSubItemIndex = 0;
                //cdvInspReprocFlag.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvInspReprocFlag.GetListView, '1', MPGC.MP_GCM_YESNO) == false)
                {
                    return;
                }

                //cdvInspReprocFlag.InsertEmptyRow(0, 1);
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
                DialogResult dr = MessageBox.Show(MPCF.GetMessage(499), "Info", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
                if (dr == DialogResult.No || dr == DialogResult.Cancel)
                {
                    return;
                }
                if (!CheckCondition(CSGC.CHECK.SAVE))
                    return;

                txtResult.Text = "";
                txtResultCode.Text = "";
                txtResultMessage.Text = "";

                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                in_node.AddString("AREA", cdvDept.Text);
                in_node.AddString("QCM_INSP_TYPE", cdvInspectionType.Text);
                in_node.AddString("INSP_FROM_DATE", dtpFromDate.Text.Replace("-", ""));
                in_node.AddString("INSP_TO_DATE", dtpToDate.Text.Replace("-", ""));
                in_node.AddString("INSP_REPROC_FLAG", cdvInspReprocFlag.Text);
                in_node.AddString("MAT_CODE", cdvMatId.Text);
                in_node.AddString("REPORT_NO", txtShipReportNo.Text);

                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Batch_Mig_Data_Prt", in_node, ref out_node) == false)
                {
                    txtResult.Text = out_node.GetChar("OUT_ERR_CODE").ToString();
                    txtResultCode.Text = out_node.GetString("OUT_MSG_CODE");
                    txtResultMessage.Text = out_node.GetString("OUT_MSG_REP_WORD");

                    return;
                }

                txtResult.Text = out_node.GetChar("OUT_ERR_CODE").ToString();
                txtResultCode.Text = out_node.GetString("OUT_MSG_CODE");
                txtResultMessage.Text = out_node.GetString("OUT_MSG_REP_WORD");

                MPCR.ShowSuccessMsg(out_node);

                return;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatId_ButtonPress(object sender, EventArgs e)
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

                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMatId.Text = popup.sMat_id;
                    popup = null;
                }
                else
                {
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvInspectionType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvInspectionType.Init();
                MPCF.InitListView(cdvInspectionType.GetListView);
                cdvInspectionType.Columns.Add("Type", 50, HorizontalAlignment.Left);
                cdvInspectionType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvInspectionType.SelectedSubItemIndex = 0;
                cdvInspectionType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvInspectionType.GetListView, '1', MPGC.MP_QCM_INSP_TYPE) == false)
                {
                    return;
                }

                //cdvInspReprocFlag.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        #endregion


    }
}
