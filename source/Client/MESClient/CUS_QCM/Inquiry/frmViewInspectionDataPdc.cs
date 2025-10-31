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
    public partial class frmViewInspectionDataPdc : CUS_COM.frmViewForm01
    {
        public frmViewInspectionDataPdc()
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
        private void ViewInspectionDataList2()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[8];
                DataTable dt = null;
                DataTable dt2 = null;
                string sSql = "";
                int i = 0;
                string sViewID = "";
                string sViewID2 = "";
                string sLink = "";
                string SSqlText = "";
                int iStColumnCount = 16;

                // string s_insp_oper = "";






                //20210723 베트남 음성 둘다 조회가능하도록 수정
                if (rdIJDK1.Checked)
                {
                    dvcArgu[0].sCondition_ID = "FACTORY";
                    dvcArgu[0].sCondition_Value = "IJDK1";  //rdIJDK1.Text;

                    if (MPGV.gsFactory == "IJDK1")
                    {
                        sViewID = "CQCM3004-005";
                        sViewID2 = "CQCM3004-007";
                    }
                    else
                    {
                        sViewID = "CQCM3004-006";
                        sViewID2 = "CQCM3004-008";
                    }

                }
                else if (rdIJDV1.Checked)
                {
                    dvcArgu[0].sCondition_ID = "FACTORY";
                    dvcArgu[0].sCondition_Value = "IJDV1";
                    if (MPGV.gsFactory == "IJDV1")
                    {
                        sViewID = "CQCM3004-005";
                        sViewID2 = "CQCM3004-007";
                    }
                    else
                    {
                        sViewID = "CQCM3004-006";
                        sViewID2 = "CQCM3004-008";
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

                dvcArgu[7].sCondition_ID = "SQLTEXT";
                dvcArgu[7].sCondition_Value = SSqlText;
                dvcArgu[7].sCondition_Type = "TEXT";


                if (TPDR.GetDataOne("", ref dt2, sViewID2, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt2 != null)
                        dt2.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdInspectionData);
                    return;
                }



                MPCF.ClearList(spdInspectionData);


                spdInspectionData.ActiveSheet.Columns.Count = 15;

                //  spdInspectionData_Sheet1.ColumnCount++;

                FarPoint.Win.Spread.CellType.NumberCellType numberCellType1 = new FarPoint.Win.Spread.CellType.NumberCellType();
                numberCellType1.DecimalPlaces = 3;

                for (int iRow = 0; iRow < dt2.Rows.Count; iRow++)
                {
                    spdInspectionData_Sheet1.ColumnCount++;
                    spdInspectionData_Sheet1.ColumnHeader.Cells.Get(0, iStColumnCount + iRow - 1).Value = dt2.Rows[iRow]["LOSS_DESC"];

                    spdInspectionData_Sheet1.Columns[iStColumnCount + iRow - 1].Width = 100;
                    spdInspectionData_Sheet1.Columns.Get(iStColumnCount + iRow - 1).CellType = numberCellType1;


                    SSqlText = SSqlText + ",SUM(CASE WHEN C.VALUE_1 = '" + dt2.Rows[iRow]["LOSS_CODE"] + "' THEN 1 END) AS LOSS_" + "" + dt2.Rows[iRow]["LOSS_CODE"] + "";


                }

                dvcArgu[7].sCondition_ID = "SQLTEXT";
                dvcArgu[7].sCondition_Value = SSqlText;
                dvcArgu[7].sCondition_Type = "TEXT";


                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdInspectionData);
                    return;
                }


                /*

                //쿼리 안나눠도 되기는 하는데..반영 시점떔시 오류날까봐 그냥 쿼리 나눔나중에 걍 조건절로 넣을것.
                if (cdvOrderType.Text == "")
                {


                    if (TPDR.GetDataOne("", ref dt, "CQCM3004-001", dvcArgu, false, false, ref sSql) == false)
                    {
                        if (dt != null)
                            dt.Dispose();

                        GC.Collect();

                        MPCF.ClearList(spdInspectionData);
                        return;
                    }
                }
                else
                {
                    if (TPDR.GetDataOne("", ref dt, "CQCM3004-002", dvcArgu, false, false, ref sSql) == false)
                    {
                        if (dt != null)
                            dt.Dispose();

                        GC.Collect();

                        MPCF.ClearList(spdInspectionData);
                        return;
                    }
                }
                */






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

                    for (int iCol = 15; iCol < dt.Columns.Count - 1; iCol++)
                    {
                        if (iCol == 78)
                        {
                            MPCF.ShowMsgBox("XX");
                        }

                        spdInspectionData.ActiveSheet.Cells[i, iCol].Value = dt.Rows[i][iCol + 1];

                    }




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
        private void frmViewInspectionDataPdc_Load(object sender, EventArgs e)
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

                //  ViewInspectionDataList();
                ViewInspectionDataList2();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        #endregion

        #region " Event Definition"
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
                    popup.g_Area_Id = "PDC";
                }
                else
                {
                    popup.g_Area_Id = "PDV";
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
