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

namespace CUS_RAS
{
    public partial class frmViewToolHistory : CUS_COM.frmViewForm01
    {
        public frmViewToolHistory()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum TOOL_INFO : int
        {
            TOOL_ID,
            HIST_SEQ,
            TOOL_DESC,
            TOOL_GRP,
            TOOL_TYPE,
            TOOL_EVENT_ID,
            TRAN_TIME,
            AREA_DESC,
            SUB_AREA_DESC,
            TOOL_STS_3,     //한계수명
            TOOL_STS_4,     //경고 타수
            TOOL_STS_5,     //타수
            CAR,            //CAR
            PAN,            //상/하판
            VENDOR_ID,
            TRAN_USER_ID,
            TRAN_COMMENT,  //비고
            HIST_DEL_FLAG,
            HIST_DEL_TIME,
            HIST_DEL_USER_ID,
            HIST_DEL_COMMENT
        }

        #endregion

        #region " Variable Definition "

        string cDeleteFlag = "";

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnExcel.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 초기화
        private void ClearData(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "VIEW":
                        cDeleteFlag = "";
                        MPCF.ClearList(spdToolHisList);
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //벨리데이션 체크
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        if (MPCF.Trim(cdvDept.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvToolType.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToolType.Text + "]");
                            cdvToolType.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvToolId.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToolId.Text + "]");
                            cdvToolId.Focus();
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

        // 툴 이력 조회
        private void ViewToolHistory()
        {
            string sView_Id = "";

            if (!chkDeleteFlag.Checked)
                cDeleteFlag = "Y";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CRAS3004-001";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "TOOL_ID";
                dvcArgu[2].sCondition_Value = cdvToolId.Text;

                dvcArgu[3].sCondition_ID = "FROM_DATE";
                dvcArgu[3].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromDate.Text.Trim()) ? "19000101" : dtpFromDate.Text.Replace("-", ""));

                dvcArgu[4].sCondition_ID = "TO_DATE";
                dvcArgu[4].sCondition_Value = dtpToDate.Text.Replace("-", "") + "235959";

                dvcArgu[5].sCondition_ID = "DELETE_FLAG";
                dvcArgu[5].sCondition_Value = cDeleteFlag;

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdToolHisList_Sheet1.RowCount++;

                    spdToolHisList_Sheet1.Cells[i, (int)TOOL_INFO.TOOL_ID].Value = dt.Rows[i]["TOOL_ID"];
                    spdToolHisList_Sheet1.Cells[i, (int)TOOL_INFO.HIST_SEQ].Value = dt.Rows[i]["HIST_SEQ"];
                    spdToolHisList_Sheet1.Cells[i, (int)TOOL_INFO.TOOL_DESC].Value = dt.Rows[i]["TOOL_DESC"];
                    spdToolHisList_Sheet1.Cells[i, (int)TOOL_INFO.TOOL_GRP].Value = dt.Rows[i]["TOOL_GRP"];
                    spdToolHisList_Sheet1.Cells[i, (int)TOOL_INFO.TOOL_TYPE].Value = dt.Rows[i]["TOOL_TYPE"];
                    spdToolHisList_Sheet1.Cells[i, (int)TOOL_INFO.TOOL_EVENT_ID].Value = dt.Rows[i]["TOOL_EVENT_ID"];
                    spdToolHisList_Sheet1.Cells[i, (int)TOOL_INFO.TRAN_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["TRAN_TIME"].ToString());
                    spdToolHisList_Sheet1.Cells[i, (int)TOOL_INFO.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                    spdToolHisList_Sheet1.Cells[i, (int)TOOL_INFO.SUB_AREA_DESC].Value = dt.Rows[i]["SUB_AREA_DESC"];
                    spdToolHisList_Sheet1.Cells[i, (int)TOOL_INFO.TOOL_STS_3].Value = dt.Rows[i]["TOOL_STS_3"];
                    spdToolHisList_Sheet1.Cells[i, (int)TOOL_INFO.TOOL_STS_4].Value = dt.Rows[i]["TOOL_STS_4"];
                    spdToolHisList_Sheet1.Cells[i, (int)TOOL_INFO.TOOL_STS_5].Value = dt.Rows[i]["TOOL_STS_5"];
                    spdToolHisList_Sheet1.Cells[i, (int)TOOL_INFO.CAR].Value = dt.Rows[i]["CAR"];
                    spdToolHisList_Sheet1.Cells[i, (int)TOOL_INFO.PAN].Value = dt.Rows[i]["PAN"];
                    spdToolHisList_Sheet1.Cells[i, (int)TOOL_INFO.VENDOR_ID].Value = dt.Rows[i]["VENDOR_ID"];
                    spdToolHisList_Sheet1.Cells[i, (int)TOOL_INFO.TRAN_USER_ID].Value = dt.Rows[i]["TRAN_USER_ID"];
                    spdToolHisList_Sheet1.Cells[i, (int)TOOL_INFO.TRAN_COMMENT].Value = dt.Rows[i]["TRAN_COMMENT"];
                    spdToolHisList_Sheet1.Cells[i, (int)TOOL_INFO.HIST_DEL_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["HIST_DEL_TIME"].ToString());
                    spdToolHisList_Sheet1.Cells[i, (int)TOOL_INFO.HIST_DEL_USER_ID].Value = dt.Rows[i]["HIST_DEL_USER_ID"];
                    spdToolHisList_Sheet1.Cells[i, (int)TOOL_INFO.HIST_DEL_COMMENT].Value = dt.Rows[i]["HIST_DEL_COMMENT"];
                }
                MPCF.FitColumnHeader(spdToolHisList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition"

        private void cdvDept_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Init();
                MPCF.InitListView(cdvDept.GetListView);
                cdvDept.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvDept.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvDept.SelectedSubItemIndex = 0;
                cdvDept.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvDept.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                {
                    return;
                }
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

                if (RASLIST.ViewToolTypeList(cdvToolType.GetListView, '1', ' ', ' ', null) == false)
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

        private void cdvToolId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvToolType.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToolType.Text + "]");
                    cdvToolType.Focus();
                    return;
                }

                cdvToolId.Init();
                MPCF.InitListView(cdvToolId.GetListView);
                cdvToolId.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvToolId.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToolId.SelectedSubItemIndex = 0;
                cdvToolId.DisplaySubItemIndex = 1;

                if (RASLIST.ViewToolList(cdvToolId.GetListView, '2', cdvToolType.Text, ' ', false, null) == false)
                {
                    return;
                }
                cdvToolId.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvToolType_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvToolId.Text = "";
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
                //MPCF.ExportToExcel(spdToolHisList, this.lblFormName.Text, "");
                EXTFUC.SaveExcel(spdToolHisList, "ToolHistory");
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

                ClearData("VIEW");

                ViewToolHistory();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmViewToolHistory_Load(object sender, EventArgs e)
        {
            try
            {
                dtpFromDate.Value = dtpToDate.Value.AddDays(-7);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void dtpFromDate_ValueChanged(object sender, EventArgs e)
        {
            dtpFromDate.CustomFormat = "yyyy-MM-dd";
        }

        private void dtpFromDate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Delete:
                    dtpFromDate.CustomFormat = " ";
                    break;
            }
        }

        private void spdToolHisList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdToolHisList, e.Row);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void dtpFromDate_CloseUp(object sender, EventArgs e)
        {
            dtpFromDate.CustomFormat = "yyyy-MM-dd";
        }

        #endregion
    }
}
