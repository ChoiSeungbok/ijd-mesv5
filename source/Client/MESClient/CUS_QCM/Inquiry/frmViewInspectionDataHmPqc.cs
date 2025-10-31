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
using FarPoint.Win.Spread;
namespace CUS_QCM
{
    public partial class frmViewInspectionDataHmPqc : CUS_COM.frmViewForm01
    {
        public frmViewInspectionDataHmPqc()
        {
            InitializeComponent();

            InitControl();
        }
        #region " Constant Definition "
        private enum LOT_INFO
        {
            INSP_JUDGE_TIME,
            INSP_ID,
            INSP_JUDGE,
            LOT_ID,
            MAT_ID,
            MAT_DESC,

            SG_MIN_VAL,
            SG_MAX_VAL,
            SG_AVG,
            MS_MIN_VAL,
            MS_MAX_VAL,
            MS_AVG,
            HC_MIN_VAL,
            HC_MAX_VAL,
            HC_AVG,
            HV_MIN_VAL,
            HV_MAX_VAL,
            HV_AVG,
            TRS_MIN_VAL,
            TRS_MAX_VAL,
            TRS_AVG,
            K1C_MIN_VAL,
            K1C_MAX_VAL,
            K1C_AVG,
            HRA_MIN_VAL,
            HRA_MAX_VAL,
            HRA_AVG,

            INSP_COMMENT

        }
        #endregion

        #region " Function  Definition"
        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnFileManager.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void ViewInspectionDataList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                // string s_insp_oper = "";


                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "FROM_DATE";
                dvcArgu[1].sCondition_Value = dtpFromJudgeDate.Text.Replace("-", "");

                dvcArgu[2].sCondition_ID = "TO_DATE";
                dvcArgu[2].sCondition_Value = dtpToJudgeDate.Text.Replace("-", "");

                dvcArgu[3].sCondition_ID = "MAT_ID";
                dvcArgu[3].sCondition_Value = cdvMat.Text + "%";

                dvcArgu[4].sCondition_ID = "LOT_ID";
                dvcArgu[4].sCondition_Value = txtLotID.Text + "%";



                if (TPDR.GetDataOne("", ref dt, "CQCM3005-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdInspectionData);
                    return;
                }

                MPCF.ClearList(spdInspectionData);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdInspectionData.ActiveSheet.RowCount++;

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_JUDGE_TIME].Value = dt.Rows[i]["INSP_JUDGE_TIME"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_ID].Value = dt.Rows[i]["INSP_ID"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_JUDGE].Value = dt.Rows[i]["INSP_JUDGE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SG_MIN_VAL].Value = dt.Rows[i]["SG_MIN_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SG_MAX_VAL].Value = dt.Rows[i]["SG_MAX_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SG_AVG].Value = dt.Rows[i]["SG_AVG"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MS_MIN_VAL].Value = dt.Rows[i]["MS_MIN_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MS_MAX_VAL].Value = dt.Rows[i]["MS_MAX_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MS_AVG].Value = dt.Rows[i]["MS_AVG"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.HC_MIN_VAL].Value = dt.Rows[i]["HC_MIN_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.HC_MAX_VAL].Value = dt.Rows[i]["HC_MAX_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.HC_AVG].Value = dt.Rows[i]["HC_AVG"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.HV_MIN_VAL].Value = dt.Rows[i]["HV_MIN_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.HV_MAX_VAL].Value = dt.Rows[i]["HV_MAX_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.HV_AVG].Value = dt.Rows[i]["HV_AVG"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.TRS_MIN_VAL].Value = dt.Rows[i]["TRS_MIN_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.TRS_MAX_VAL].Value = dt.Rows[i]["TRS_MAX_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.TRS_AVG].Value = dt.Rows[i]["TRS_AVG"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.K1C_MIN_VAL].Value = dt.Rows[i]["K1C_MIN_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.K1C_MAX_VAL].Value = dt.Rows[i]["K1C_MAX_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.K1C_AVG].Value = dt.Rows[i]["K1C_AVG"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.HRA_MIN_VAL].Value = dt.Rows[i]["HRA_MIN_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.HRA_MAX_VAL].Value = dt.Rows[i]["HRA_MAX_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.HRA_AVG].Value = dt.Rows[i]["HRA_AVG"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_COMMENT].Value = dt.Rows[i]["INSP_COMMENT"];



                }
                //MPCF.FitColumnHeader(spdInspectionData);

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

                //if (MPCF.Trim(cdvWorkPlace.Text) == "")
                //{
                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                //    cdvWorkPlace.Focus();
                //    return false;
                //}

                //if (MPCF.Trim(cdvOper.Text) == "")
                //{
                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                //    cdvOper.Focus();
                //    return false;
                //}

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

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
        private void frmViewInspectionDataHmPqc_Load(object sender, EventArgs e)
        {
            try
            {

                this.dtpToJudgeDate.Value = DateTime.Now;
                this.dtpFromJudgeDate.Value = dtpToJudgeDate.Value.AddDays(-7);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        #endregion

        #region " Event Definition"
        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewInspectionDataList();
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
                EXTFUC.SaveExcel(spdInspectionData, "InspectionData(HM)");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }
        private void cdvMat_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvMat.Text = popup.sMat_id;
                    cdvMat.DisplayText = popup.sMat_Desc;
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
        private void cdvMat_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMat.DisplayText == "")
                cdvMat.Text = "";
        }
        private void btnFileManager_Click(object sender, EventArgs e)
        {
            if (spdInspectionData.ActiveSheet.RowCount != 0)
            {




                frmPopFtpUpDown popup = new frmPopFtpUpDown();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.g_PopYn = "Y";
                popup.g_LotId = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text;
                popup.g_Mat_id = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.MAT_ID].Text;
                popup.g_Mat_Desc = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.MAT_DESC].Text;
                popup.g_Area_Id = CSGC.CP_AREA_HM;
                popup.g_SearchType = "B";

                if (popup.ShowDialog() == DialogResult.OK)
                {

                    popup = null;
                }
                else
                {
                    return;
                }


            }
        }
        #endregion
    }
}
