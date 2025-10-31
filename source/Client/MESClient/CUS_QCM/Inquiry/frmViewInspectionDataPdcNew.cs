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
    public partial class frmViewInspectionDataPdcNew : CUS_COM.frmViewForm01
    {
        public frmViewInspectionDataPdcNew()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "
        private enum LOT_INFO
        {
            INSP_ID,
            INSP_REQ_TIME,
            INSP_JUDGE_TIME,
            LOT_ID,
            MAT_ID,
            MAT_DESC,
            INSP_OPER,
            OPER_DESC,
            INSP_COMMENT,
            INSP_QTY,
            PASS_QTY,
            LOSS_QTY,
            REWORK_QTY,
            PASS_RATE,
            REWORK_RATE,
            LOSS_PBAD049,
            LOSS_PBAD053,
            LOSS_PBAD054,
            LOSS_PBAD055,
            LOSS_PBAD056,
            LOSS_PBAD057,
            LOSS_PBAD058,
            LOSS_PBAD059,
            LOSS_PBAD060,
            LOSS_PBAD061,
            LOSS_PBAD062,
            LOSS_PBAD063,
            LOSS_PBAD064,
            LOSS_PBAD065,
            LOSS_PBAD066,
            LOSS_PBAD067,
            LOSS_PBAD068,
            LOSS_PBAD069,
            LOSS_PBAD070,
            LOSS_PBAD071,
            LOSS_PBAD073,
            LOSS_PBAD074,
            LOSS_PBAD075,
            LOSS_PBAD076,
            LOSS_PBAD077,
            LOSS_PBAD078,
            LOSS_PBAD079,
            LOSS_PBAD080,
            LOSS_PBAD081,
        }
        #endregion

        #region " Function Definition"
        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnFileManager.Anchor = AnchorStyles.Top | AnchorStyles.Right;



                //20210723 베트남 음성 둘다 조회가능하도록 수정
                if (MPGV.gsFactory == "IJDK1")
                {
                    rdIJDK1.Checked = true;


                }
                else if (MPGV.gsFactory == "IJDV1")
                {
                    rdIJDV1.Checked = true;
                }

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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[7];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                string sViewID = "";
                string sLink = "";

                // string s_insp_oper = "";

                //20210723 베트남 음성 둘다 조회가능하도록 수정
                if (rdIJDK1.Checked)
                {
                    dvcArgu[0].sCondition_ID = "FACTORY";
                    dvcArgu[0].sCondition_Value = "IJDK1";  //rdIJDK1.Text;

                    if (MPGV.gsFactory == "IJDK1")
                    {
                        sViewID = "CQCM3004-002";
                    }
                    else
                    {
                        sViewID = "CQCM3004-003";
                    }

                }
                else if (rdIJDV1.Checked)
                {
                    dvcArgu[0].sCondition_ID = "FACTORY";
                    dvcArgu[0].sCondition_Value = "IJDV1";
                    if (MPGV.gsFactory == "IJDV1")
                    {
                        sViewID = "CQCM3004-002";
                    }
                    else
                    {
                        sViewID = "CQCM3004-003";
                    }
                }




                dvcArgu[1].sCondition_ID = "FROM_DATE";
                dvcArgu[1].sCondition_Value = dtpFromJudgeDate.Text.Replace("-", "");

                dvcArgu[2].sCondition_ID = "TO_DATE";
                dvcArgu[2].sCondition_Value = dtpToJudgeDate.Text.Replace("-", "");

                dvcArgu[3].sCondition_ID = "MAT_ID";
                dvcArgu[3].sCondition_Value = cdvMat.Text + "%";

                dvcArgu[4].sCondition_ID = "LOT_ID";
                dvcArgu[4].sCondition_Value = txtLotID.Text + "%";

                dvcArgu[5].sCondition_ID = "CREATE_CODE";
                dvcArgu[5].sCondition_Value = cdvOrderType.Text + "%";


                viewDbLink(ref sLink);

                dvcArgu[6].sCondition_ID = "DB_LINK";
                dvcArgu[6].sCondition_Value = sLink;
                dvcArgu[6].sCondition_Type = "TEXT";






                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
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

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_ID].Value = dt.Rows[i]["INSP_ID"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_REQ_TIME].Value = dt.Rows[i]["INSP_REQ_TIME"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_JUDGE_TIME].Value = dt.Rows[i]["INSP_JUDGE_TIME"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_OPER].Value = dt.Rows[i]["INSP_OPER"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_COMMENT].Value = dt.Rows[i]["INSP_COMMENT"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_QTY].Value = dt.Rows[i]["INSP_QTY"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.PASS_QTY].Value = dt.Rows[i]["PASS_QTY"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_QTY].Value = dt.Rows[i]["LOSS_QTY"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.REWORK_QTY].Value = dt.Rows[i]["REWORK_QTY"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.PASS_RATE].Value = dt.Rows[i]["PASS_RATE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.REWORK_RATE].Value = dt.Rows[i]["REWORK_RATE"];





                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD049].Value = dt.Rows[i]["LOSS_PBAD049"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD053].Value = dt.Rows[i]["LOSS_PBAD053"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD054].Value = dt.Rows[i]["LOSS_PBAD054"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD055].Value = dt.Rows[i]["LOSS_PBAD055"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD056].Value = dt.Rows[i]["LOSS_PBAD056"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD057].Value = dt.Rows[i]["LOSS_PBAD057"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD058].Value = dt.Rows[i]["LOSS_PBAD058"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD059].Value = dt.Rows[i]["LOSS_PBAD059"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD060].Value = dt.Rows[i]["LOSS_PBAD060"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD061].Value = dt.Rows[i]["LOSS_PBAD061"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD062].Value = dt.Rows[i]["LOSS_PBAD062"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD063].Value = dt.Rows[i]["LOSS_PBAD063"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD064].Value = dt.Rows[i]["LOSS_PBAD064"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD065].Value = dt.Rows[i]["LOSS_PBAD065"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD066].Value = dt.Rows[i]["LOSS_PBAD066"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD067].Value = dt.Rows[i]["LOSS_PBAD067"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD068].Value = dt.Rows[i]["LOSS_PBAD068"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD069].Value = dt.Rows[i]["LOSS_PBAD069"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD070].Value = dt.Rows[i]["LOSS_PBAD070"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD071].Value = dt.Rows[i]["LOSS_PBAD071"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD073].Value = dt.Rows[i]["LOSS_PBAD073"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD074].Value = dt.Rows[i]["LOSS_PBAD074"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD075].Value = dt.Rows[i]["LOSS_PBAD075"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD076].Value = dt.Rows[i]["LOSS_PBAD076"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD077].Value = dt.Rows[i]["LOSS_PBAD077"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD078].Value = dt.Rows[i]["LOSS_PBAD078"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD079].Value = dt.Rows[i]["LOSS_PBAD079"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD080].Value = dt.Rows[i]["LOSS_PBAD080"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_PBAD081].Value = dt.Rows[i]["LOSS_PBAD081"];







                }
                //MPCF.FitColumnHeader(spdInspectionData);

                return;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void viewDbLink(ref string sDbLink)
        {

            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
            DataTable dt = null;
            string sSql = "";

            dvcArgu[0].sCondition_ID = "FACTORY";
            dvcArgu[0].sCondition_Value = MPGV.gsFactory;

            dvcArgu[1].sCondition_ID = "TABLE_NAME";
            dvcArgu[1].sCondition_Value = "C_DB_LINK";

            dvcArgu[2].sCondition_ID = "KEY_1";
            dvcArgu[2].sCondition_Value = MPGV.gsFactory;

            if (TPDR.GetDataOne("", ref dt, "BAS-02", dvcArgu, false, false, ref sSql) == false)
            {
                if (dt != null)
                    dt.Dispose();

                GC.Collect();

                return;
            }

            sDbLink = dt.Rows[0]["DATA_1"].ToString();

            return;
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
        #endregion

        #region " Event Definition"
        private void frmViewInspectionDataPdcNew_Load(object sender, EventArgs e)
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
                EXTFUC.SaveExcel(spdInspectionData, "InspectionData(PDC)");

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
        private void cdvOrderType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvOrderType.Init();
                MPCF.InitListView(cdvOrderType.GetListView);
                cdvOrderType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOrderType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOrderType.SelectedSubItemIndex = 0;
                cdvOrderType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvOrderType.GetListView, '1', MPGC.MP_WIP_LOT_TYPE) == false)
                    return;



                //다이아에서 실제 쓰는거 뺴고는 뺀다..
                for (int i = cdvOrderType.GetListView.Items.Count; i > 0; i--)
                {
                    switch(cdvOrderType.GetListView.Items[i - 1].SubItems[0].Text)
                    {
                        case "D":
                        case "E":
                        case "M":
                            cdvOrderType.GetListView.Items[i - 1].Remove();
                            break;
                    }

                }


                cdvOrderType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
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
                popup.g_SearchType = "B";

                if (rdIJDK1.Checked)
                {
                    popup.g_Area_Id = "CTM";
                }
                else
                {
                    popup.g_Area_Id = "CTV";
                }



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
