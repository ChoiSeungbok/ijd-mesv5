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
    public partial class frmViewInspectionDataCut : CUS_COM.frmViewForm01
    {

        public frmViewInspectionDataCut()
        {
            InitializeComponent();

            InitControl();
        }
        #region " Constant Definition "
        private enum LOT_INFO
        {
            ORDER_ID,
            JUDGE_DATE,
            JUDGE_TIME,
            LOT_ID,
            INV_LOT_ID,
            JUDGE,
            MAT_ID,
            MAT_DESC,
            USER_ID,
            USER_NAME,
            GRADE,

            UNIT_USE_QTY,
            UNIT_PROD_QTY,
            UNIT_PASS_QTY,
            INSP_QTY,
            PASS_QTY,
            LOSS_QTY,

            SPEC_ANGLE1_VALUE,
            SPEC_MIN_ANGLE1_VALUE,
            SPEC_MAX_ANGLE1_VALUE,

            SPEC_ANGLE2_VALUE,
            SPEC_MIN_ANGLE2_VALUE,
            SPEC_MAX_ANGLE2_VALUE,

            SPEC_LENG1_VALUE,
            SPEC_MIN_LENG1_VALUE,
            SPEC_MAX_LENG1_VALUE,

            SPEC_LENG2_VALUE,
            SPEC_MIN_LENG2_VALUE,
            SPEC_MAX_LENG2_VALUE,

            SPEC_LENG3_VALUE,
            SPEC_MIN_LENG3_VALUE,
            SPEC_MAX_LENG3_VALUE,

            SPEC_UT_VALUE,
            SPEC_MIN_UT_VALUE,
            SPEC_MAX_UT_VALUE,

            SPEC_ALL_T_VALUE,
            SPEC_MIN_ALL_T_VALUE,
            SPEC_MAX_ALL_T_VALUE,

            ALL_T_VALUE_1,
            ALL_T_VALUE_2,
            ALL_T_VALUE_3,
            ALL_T_VALUE_4,
            ALL_T_VALUE_5,
            C_SCAN,
            DAMAGE,

            LOSS_CBAD003, // 박리
            LOSS_CBAD004, //변색
            LOSS_CBAD005, // 치핑
            LOSS_CBAD006, //크랙

            LOSS_CBAD007, //파손
            LOSS_CBAD008, //파임
            LOSS_CBAD013, //UT 불량
            LOSS_CBAD018, //가공불량
            LOSS_CBAD021, //소재불량
            LOSS_CBAD028, //치수불량
            LOSS_CBAD055, //절단띠 불량
            LOSS_CBAD070, //컵잔류
            LOSS_CBAD071, //Damage
            LOSS_CBAD072, //형상불량
            LOSS_CBAD999, //기타불량

            INSP_COMMENT

        }
        #endregion

        #region " Function Definition "
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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[7];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                //string s_insp_oper = "";



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

                dvcArgu[5].sCondition_ID = "CREATE_CODE";
                dvcArgu[5].sCondition_Value = cdvOrderType.Text + "%";


                dvcArgu[6].sCondition_ID = "ORDER_ID";
                dvcArgu[6].sCondition_Value = txtWo.Text + "%";



                if (TPDR.GetDataOne("", ref dt, "CQCM3008-002", dvcArgu, false, false, ref sSql) == false)
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

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.JUDGE_DATE].Value = dt.Rows[i]["INSP_JUDGE_DATE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.JUDGE_TIME].Value = dt.Rows[i]["INSP_JUDGE_TIME"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INV_LOT_ID].Value = dt.Rows[i]["INV_LOT_ID"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.JUDGE].Value = dt.Rows[i]["INSP_JUDGE_DESC"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.USER_ID].Value = dt.Rows[i]["USER_ID"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.USER_NAME].Value = dt.Rows[i]["USER_NAME"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.GRADE].Value = dt.Rows[i]["GRADE"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.UNIT_USE_QTY].Value = dt.Rows[i]["UNIT_USE_QTY"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.UNIT_PROD_QTY].Value = dt.Rows[i]["UNIT_PROD_QTY"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.UNIT_PASS_QTY].Value = dt.Rows[i]["UNIT_PASS_QTY"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_QTY].Value = dt.Rows[i]["INSP_QTY"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.PASS_QTY].Value = dt.Rows[i]["PASS_QTY"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_QTY].Value = dt.Rows[i]["LOSS_QTY"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_ANGLE1_VALUE].Value = dt.Rows[i]["SPEC_ANGLE1_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_MIN_ANGLE1_VALUE].Value = dt.Rows[i]["SPEC_MIN_ANGLE1_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_MAX_ANGLE1_VALUE].Value = dt.Rows[i]["SPEC_MAX_ANGLE1_VALUE"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_ANGLE2_VALUE].Value = dt.Rows[i]["SPEC_ANGLE2_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_MIN_ANGLE2_VALUE].Value = dt.Rows[i]["SPEC_MIN_ANGLE2_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_MAX_ANGLE2_VALUE].Value = dt.Rows[i]["SPEC_MAX_ANGLE2_VALUE"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_LENG1_VALUE].Value = dt.Rows[i]["SPEC_LENG1_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_MIN_LENG1_VALUE].Value = dt.Rows[i]["SPEC_MIN_LENG1_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_MAX_LENG1_VALUE].Value = dt.Rows[i]["SPEC_MAX_LENG1_VALUE"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_LENG2_VALUE].Value = dt.Rows[i]["SPEC_LENG2_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_MIN_LENG2_VALUE].Value = dt.Rows[i]["SPEC_MIN_LENG2_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_MAX_LENG2_VALUE].Value = dt.Rows[i]["SPEC_MAX_LENG2_VALUE"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_LENG3_VALUE].Value = dt.Rows[i]["SPEC_LENG3_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_MIN_LENG3_VALUE].Value = dt.Rows[i]["SPEC_MIN_LENG3_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_MAX_LENG3_VALUE].Value = dt.Rows[i]["SPEC_MAX_LENG3_VALUE"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_UT_VALUE].Value = dt.Rows[i]["SPEC_UT_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_MIN_UT_VALUE].Value = dt.Rows[i]["SPEC_MIN_UT_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_MAX_UT_VALUE].Value = dt.Rows[i]["SPEC_MAX_UT_VALUE"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_ALL_T_VALUE].Value = dt.Rows[i]["SPEC_ALL_T_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_MIN_ALL_T_VALUE].Value = dt.Rows[i]["SPEC_MIN_ALL_T_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SPEC_MAX_ALL_T_VALUE].Value = dt.Rows[i]["SPEC_MAX_ALL_T_VALUE"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.ALL_T_VALUE_1].Value = dt.Rows[i]["ALL_T_VALUE_1"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.ALL_T_VALUE_2].Value = dt.Rows[i]["ALL_T_VALUE_2"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.ALL_T_VALUE_3].Value = dt.Rows[i]["ALL_T_VALUE_3"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.ALL_T_VALUE_4].Value = dt.Rows[i]["ALL_T_VALUE_4"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.ALL_T_VALUE_5].Value = dt.Rows[i]["ALL_T_VALUE_5"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.C_SCAN].Value = dt.Rows[i]["C_SCAN"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.DAMAGE].Value = dt.Rows[i]["DAMAGE"];


                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_CBAD003].Value = dt.Rows[i]["LOSS_CBAD003"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_CBAD004].Value = dt.Rows[i]["LOSS_CBAD004"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_CBAD005].Value = dt.Rows[i]["LOSS_CBAD005"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_CBAD006].Value = dt.Rows[i]["LOSS_CBAD006"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_CBAD007].Value = dt.Rows[i]["LOSS_CBAD007"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_CBAD008].Value = dt.Rows[i]["LOSS_CBAD008"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_CBAD013].Value = dt.Rows[i]["LOSS_CBAD013"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_CBAD018].Value = dt.Rows[i]["LOSS_CBAD018"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_CBAD021].Value = dt.Rows[i]["LOSS_CBAD021"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_CBAD028].Value = dt.Rows[i]["LOSS_CBAD028"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_CBAD055].Value = dt.Rows[i]["LOSS_CBAD055"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_CBAD070].Value = dt.Rows[i]["LOSS_CBAD070"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_CBAD071].Value = dt.Rows[i]["LOSS_CBAD071"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_CBAD072].Value = dt.Rows[i]["LOSS_CBAD072"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_CBAD999].Value = dt.Rows[i]["LOSS_CBAD999"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_COMMENT].Value = dt.Rows[i]["INSP_COMMENT"];


                }
                // MPCF.FitColumnHeader(spdInspectionData);

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
        #endregion

        #region " Event Definition "
        private void frmViewInspectionDataCut_Load(object sender, EventArgs e)
        {
            try
            {
                

                this.dtpToJudgeDate.Value = DateTime.Now;
                this.dtpFromJudgeDate.Value = dtpToJudgeDate.Value.AddDays(-7);



                cdvOrderType.Text = "PROD";
                cdvOrderType.DisplayText = "Product Lot";
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
                EXTFUC.SaveExcel(spdInspectionData, "InspectionData(Cut)");

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

                if (BASLIST.ViewGCMDataList(cdvOrderType.GetListView, '1', MPGC.MP_WIP_CREATE_CODE) == false)
                    return;

                cdvOrderType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void label1_Click(object sender, EventArgs e)
        {

        }
        private void textBox1_TextChanged(object sender, EventArgs e)
        {

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
                popup.g_Area_Id = CSGC.CP_AREA_CTM;
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
